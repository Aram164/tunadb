//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/planner/tableref/bound_match_recognize_ref.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/planner/binder.hpp"
#include "duckdb/planner/bound_result_modifier.hpp"
#include "duckdb/planner/expression.hpp"

namespace duckdb {

class BoundMatchRecognizeRef {
public:
	//! The bind index exported by the bound source relation
	idx_t bind_index;
	//! The binder used to bind the input relation and match-recognize keys
	shared_ptr<Binder> child_binder;
	//! The bound source relation
	BoundStatement child;
	//! The bound PARTITION BY keys
	vector<unique_ptr<Expression>> partition_by;
	//! The bound ORDER BY keys
	vector<BoundOrderByNode> order_by;
	//! The schema currently exported by the relation
	vector<string> names;
	vector<LogicalType> types;
};

} // namespace duckdb
