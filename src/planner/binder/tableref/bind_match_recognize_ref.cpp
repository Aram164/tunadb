#include "duckdb/planner/tableref/bound_match_recognize_ref.hpp"
#include "duckdb/planner/binder.hpp"
#include "duckdb/parser/tableref/match_recognize_ref.hpp"
#include "duckdb/planner/operator/logical_dummy_scan.hpp"

namespace duckdb {

/* gebundenen Table-Ref Node (z. B. BoundMatchRecognizeRef) auf Basis des MatchRecognizeRef Nodes produzieren:
- die gebundene Eingabetabelle
- die gebundenen Ausdrücke für PARTITION BY und ORDER BY
- die Menge von PATTERN-Variablen aus der PATTERN-Klausel (z. B. A, B, C)
- die dazugehörigen gebundenen boolschen Ausdrücke aus DEFINE 
- die gebundenen Informationen für MEASURES (Funktionen + Variablen + Spalten)
- das Ausgabeschema für MATCH_RECOGNIZE (Namen + Typen aus MEASURES) 
*/


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

	BoundStatement result_statement;
    result_statement.names = std::move(names);
	result_statement.types = std::move(types);
	result_statement.plan =
	    make_uniq<LogicalDummyScan>(result.bind_index);
	return result_statement; 
}

} // namespace duckdb
