#include "duckdb/planner/binder.hpp"
#include "duckdb/parser/tableref/match_recognize_ref.hpp"
#include "duckdb/planner/operator/logical_dummy_scan.hpp"

namespace duckdb {

BoundStatement Binder::Bind(MatchRecognizeRef &ref) {
    auto bind_index = GenerateTableIndex();
    vector<string> names = {"parser_ok"};
    vector<LogicalType> types = {LogicalType::BOOLEAN};
    bind_context.AddGenericBinding(bind_index, "__mr_stub", names, types);
    BoundStatement bound_result;
    bound_result.names = names;
    bound_result.types = types;
    bound_result.plan = make_uniq<LogicalDummyScan>(bind_index);
    return bound_result;
}

} // namespace duckdb
