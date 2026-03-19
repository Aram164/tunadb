#include "duckdb/planner/tableref/bound_match_recognize_ref.hpp"
#include "duckdb/planner/binder.hpp"
#include "duckdb/parser/tableref/match_recognize_ref.hpp"
#include "duckdb/parser/parsed_expression_iterator.hpp"
#include "duckdb/parser/expression/function_expression.hpp"
#include "duckdb/planner/operator/logical_dummy_scan.hpp"

namespace duckdb {

unordered_set<string> ExtractPatternVars(string pattern) {
    unordered_set<string> pattern_vars;
    string var;  
    for (auto c : pattern) {
        // restrict pattern variables to alphabetic characters
        if (isalpha(c)) {
            var += c;
        } 
        else if (c == '*' || c == '+' || c == '?' || c == '|' || c == '(' || c == ')' || c == ' ' ) {
            if (!var.empty()) {
                pattern_vars.insert(var);
                var.clear();
            }
        } 
        else {
            throw SyntaxException("Invalid character '%c' in PATTERN", c);
        }
    }
    if (!var.empty()) {
        pattern_vars.insert(var);
    }

    return pattern_vars;
}

// Recursively walk a parsed expression tree.
// If a node is a two-part column reference like A.val where A is a pattern
// variable and val is a source column, strip the variable prefix so it becomes
// just val (which the binder can resolve against the source table).
void ValidateAndRewriteVarCol(unique_ptr<ParsedExpression> &expr, const unordered_set<string> &pattern_vars, const vector<string> &source_columns) {
    // first recurse into all children
    ParsedExpressionIterator::EnumerateChildren(*expr, [&](unique_ptr<ParsedExpression> &child) {
        ValidateAndRewriteVarCol(child, pattern_vars, source_columns);
    });

    // then look for var.col expressions
    if (expr->type == ExpressionType::COLUMN_REF) {
        auto &col_ref = expr->Cast<ColumnRefExpression>();
        // column_names.size() == 2 if reference looks like 'var.col'
        if (col_ref.column_names.size() == 2) {
            const auto &var_name = col_ref.column_names[0];
            const auto &col_name = col_ref.column_names[1];
        
            // Validate that var_name is valid PATTERN variable 
            if (!pattern_vars.count(var_name)) {
                throw BinderException("Unknown pattern variable '%s' in expression", var_name);
            }

            // Validate that the column exists in the source table
            bool found = false;
            for (const auto &src_col : source_columns) {
                if (StringUtil::CIEquals(src_col, col_name)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                throw BinderException("Column '%s' referenced in '%s.%s' does not exist in source table", col_name, var_name, col_name);
            }

            // Replace A.val with just val
            expr = make_uniq<ColumnRefExpression>(col_name);
        }
    }
}

// Recursively walk a parsed expression tree.
// If a node is PREV(col), validate that the argument is a column reference,
// then replace the PREV(col) node with just col.
void ValidateAndRewritePrev(unique_ptr<ParsedExpression> &expr) {
    // first recurse into all children
    ParsedExpressionIterator::EnumerateChildren(*expr, [&](unique_ptr<ParsedExpression> &child) {
        ValidateAndRewritePrev(child);
    });

    // then check if this node itself is PREV(...)
    if (expr->type == ExpressionType::FUNCTION) {
        auto &func = expr->Cast<FunctionExpression>(); 
        if (StringUtil::Lower(func.function_name) == "prev") {
            if (func.children.size() != 1) {
                throw BinderException("PREV() requires exactly one argument");
            }
            if (func.children[0]->type != ExpressionType::COLUMN_REF) {
                throw BinderException("PREV() argument must be a column reference");
            }
            expr = std::move(func.children[0]);
        }
    }
}

BoundStatement Binder::Bind(MatchRecognizeRef &ref) {
    // bind the child table in a child binder
	BoundMatchRecognizeRef result;
	result.bind_index = GenerateTableIndex();
	result.child_binder = Binder::CreateBinder(context, this);
	result.child = result.child_binder->Bind(*ref.source);

    // bind rows per match, skip logic, pattern
    result.one_row_per_match = (ref.rows_per_match == RowsPerMatchType::ONE_ROW_PER_MATCH);
    result.skip_to_next_row = (ref.after_match_skip == AfterMatchSkipType::SKIP_TO_NEXT_ROW);
	result.pattern = ref.pattern;

    // bind PARTITION BY
    ExpressionBinder expr_binder(*result.child_binder, context);

    for (auto &expr : ref.partition_by) {
        unique_ptr<Expression> bound_expr;
        try {
            bound_expr = expr_binder.Bind(expr);
        } catch (const Exception &ex) {
            throw BinderException("Unknown column %s in PARTITION BY: %s", expr->ToString(), ex.what());
        }
        result.partition_by.push_back(std::move(bound_expr));
    }
   
    // bind ORDER BY
    for (auto &order : ref.order_by) {
        unique_ptr<Expression> bound_expr;
        try {
            bound_expr = expr_binder.Bind(order.expression);
        } catch (const Exception &ex) {
            throw BinderException("Unknown column %s in ORDER BY: %s", order.expression->ToString(), ex.what());
        }
        result.order_by.emplace_back(order.type, order.null_order, std::move(bound_expr));
    }

    // extract all variables from PATTERN
    unordered_set<string> pattern_vars = ExtractPatternVars(ref.pattern);

    // bind DEFINE
    for (auto &define : ref.define) {
        // Validate DEFINE: for each 'DEFINE X AS …', check if X is contained in PATTERN
        const auto &var = define.variable_name;
        if (!pattern_vars.count(define.variable_name)) {
            throw BinderException("DEFINE variable '%s' does not appear in PATTERN", var);
        }

        // validate and rewrite references like 'var.col' (e.g. A.val → val)  before binding
        ValidateAndRewriteVarCol(define.condition, pattern_vars, result.child.names);

        // validate and rewrite PREV(col) → col before binding
        ValidateAndRewritePrev(define.condition);

        unique_ptr<Expression> bound_expr;
        try {
            bound_expr = expr_binder.Bind(define.condition);
        } catch (const Exception &ex) {
            throw BinderException("Invalid DEFINE condition '%s' for variable '%s': %s", define.condition->ToString(), define.variable_name.c_str(), ex.what());
        }

        // type check: each DEFINE condition must be a boolean expression
        if (bound_expr->return_type != LogicalType::BOOLEAN) {
            throw BinderException("DEFINE condition for '%s' must return BOOLEAN, got %s", define.variable_name.c_str(), bound_expr->return_type.ToString());
        }

        result.defines.emplace_back(define.variable_name, std::move(bound_expr));
    }

     // create Node for exporting MEASURES
    auto names = result.child.names;
	auto types = result.child.types;
	auto alias = ref.alias.empty() ? "__unnamed_match_recognize" : ref.alias;
	
    bind_context.AddGenericBinding(result.bind_index, alias, names, types);
	MoveCorrelatedExpressions(*result.child_binder);

    /* 
    BIN3: Binden von MEASURES und dazugehöriges Ausgabeschema:
    - Funktionen FIRST, LAST, COUNT, MIN, MAX, SUM, AVG unterstützen
    - unbekannte Funktionalität aufgerufen -> Fehler auswerfen
    - Ausdrücke wie ,,var.col'' auflösen: 
        - ,,var'' muss vorhandene PATTERN-Variable repräsentieren
        - ,,col'' tatsächliche Spalte (Attribut)
    - Zuordnung von Typen für Funktionen:
        - z.B. COUNT -> BIGINT, SUM -> DOUBLE, AVG -> DOUBLE
        - FIRST/LAST/MIN/MAX -> selber Typ, wie dazugehöriges Attribut (Spalte))
    - Ausgabeschema der Query: alle MEASURES Spalten (inkl deren Namen) auflisten
    - gebundener Knoten für MEASURES soll enthalten: 
        - Funktionen (FIRST/LAST/..)
        - welche dazugehörigen PATTERN-Variablen referenziert werden
        - welchen Typ Eingabespalte hat
        - Ausgabenamen + Ausgabetyp
    */

	BoundStatement result_statement;
    result_statement.names = std::move(names);
	result_statement.types = std::move(types);
	result_statement.plan =
	    make_uniq<LogicalDummyScan>(result.bind_index);
	return result_statement; 
}

} // namespace duckdb
