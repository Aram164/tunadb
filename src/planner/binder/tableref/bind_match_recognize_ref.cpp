#include "duckdb/planner/tableref/bound_match_recognize_ref.hpp"
#include "duckdb/planner/binder.hpp"
#include "duckdb/parser/tableref/match_recognize_ref.hpp"
#include "duckdb/planner/operator/logical_dummy_scan.hpp"

namespace duckdb {

unordered_set<string> ExtractPatternVars(string pattern) {
    unordered_set<string> pattern_vars;
    string var;  
    for (auto c : pattern) {
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
}

BoundStatement Binder::Bind(MatchRecognizeRef &ref) {
    // bind the child table in a child binder
	BoundMatchRecognizeRef result;
	result.bind_index = GenerateTableIndex();
	result.child_binder = Binder::CreateBinder(context, this);
	result.child = result.child_binder->Bind(*ref.source);

    // bind PARTITION BY
    ExpressionBinder expr_binder(*result.child_binder, context);

    for (auto &expr : ref.partition_by) {
        auto bound_expr = expr_binder.Bind(expr);
        if (!bound_expr) {
            throw BinderException("Unknown column in PARTITION BY: %s", expr->ToString());
        }
        result.partition_by.push_back(std::move(bound_expr));
    }
   
    // bind ORDER BY
    for (auto &order : ref.order_by) {
        auto bound_expr = expr_binder.Bind(order.expression);
        if (!bound_expr) {
            throw BinderException("Unknown column in ORDER BY: %s", order.expression->ToString());
        }
        result.order_by.emplace_back(order.type, order.null_order, std::move(bound_expr));
    }

    // create Node for exporting MEASURES
    auto names = result.child.names;
	auto types = result.child.types;
	auto alias = ref.alias.empty() ? "__unnamed_match_recognize" : ref.alias;
	
    bind_context.AddGenericBinding(result.bind_index, alias, names, types);
	MoveCorrelatedExpressions(*result.child_binder);

    /* 
    BIN2: Binden der DEFINE-Klausel: 
    TODO: 
    - auch Referenzen der Form ,,var.col'' erlauben (z.B. A.val < B.val):
        - ,,var'' muss vorhandene PATTERN-Variable repräsentieren und ,,col'' tatsächliche Eingabespalte (Attribut)
    - PREV zunächst minimal unterstützen (nur PREV(col), col muss existieren, Typ übernehmen)
        - Semantik kann später ergänzt werden
    */

    // extract all variables from PATTERN
    unordered_set<string> pattern_vars = ExtractPatternVars(ref.pattern);

    // bind DEFINE
    for (auto &define : ref.define) {
        // Validate DEFINE: for each 'DEFINE X AS …', check if X is contained in PATTERN
        const auto &var = define.variable_name;
        if (!pattern_vars.count(define.variable_name)) {
            throw BinderException("DEFINE variable '%s' does not appear in PATTERN", var);
        }

        auto bound_expr = expr_binder.Bind(define.condition);
        if (!bound_expr) {
            throw BinderException("Invalid DEFINE condition for variable '%s': %s", define.variable_name.c_str(), define.condition->ToString());
        }

        // type check: each DEFINE condition must be a boolean expression
        if (bound_expr->return_type != LogicalType::BOOLEAN) {
            throw BinderException("DEFINE condition for '%s' must return BOOLEAN, got %s", define.variable_name.c_str(), bound_expr->return_type.ToString());
        }

        result.defines.emplace_back(define.variable_name, std::move(bound_expr));
    }

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
