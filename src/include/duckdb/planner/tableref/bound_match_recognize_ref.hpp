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

struct BoundDefine {
	string variable_name;
	unique_ptr<Expression> condition;

	BoundDefine() = default;
	BoundDefine(string variable_name, unique_ptr<Expression> condition)
		: variable_name(std::move(variable_name)), condition(std::move(condition)) {
	}
};
	

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
	//! The bound DEFINE entries
	vector<BoundDefine> defines;
	//! The output schema for matches: ONE ROW PER MATCH or ALL ROWS PER MATCH
	bool one_row_per_match = true;
	//! The skip logic: AFTER MATCH SKIP PAST LAST ROW or TO NEXT ROW
	bool skip_to_next_row = false;
	//! The pattern string
	string pattern;
	//! The schema currently exported by the relation
	vector<string> names;
	vector<LogicalType> types;
};

} // namespace duckdb
