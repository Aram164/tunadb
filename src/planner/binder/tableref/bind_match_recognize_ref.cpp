#include "duckdb/planner/tableref/bound_match_recognize_ref.hpp"
#include "duckdb/planner/binder.hpp"
#include "duckdb/parser/tableref/match_recognize_ref.hpp"
#include "duckdb/planner/operator/logical_dummy_scan.hpp"

namespace duckdb {

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
    - Extrahierung der PATTERN-Variablen:
        - traversieren des AST's
        - verwendete Patternvariablen einsammeln, die auch für Validierung von DEFINE/MEASURES relevant sind
    - DEFINE validieren: für jedes DEFINE X AS ... überprüfen, ob X innerhalb des PATTERNs vorkommt -> sonst Fehler
        -  Wildcards sollen expliziert definiert werden
    - jede DEFINE Condition muss als boolscher Ausdruck gebunden werden
    - auch Referenzen der Form ,,var.col'' erlauben (z. B. A.val < B.val):
        - ,,var'' muss vorhandene PATTERN-Variable repräsentieren und ,,col'' tatsächliche Eingabespalte (Attribut)
    - PREV zunächst minimal unterstützen (nur PREV(col), col muss existieren, Typ übernehmen)
        - eigentliche Semantik kann später ergänzt werden
    - Für jede dieser Conditions muss Typ-Check stattfinden: liefert Ausdruck auch wirklich boolschen Wert zurück? 
    - darauf achten, dass jeder DEFINE Ausdruck auf korrekten Typ überprüft wird
    */


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
