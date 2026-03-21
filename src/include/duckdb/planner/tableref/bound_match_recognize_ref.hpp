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
	BoundDefine Copy() const {
		return BoundDefine(variable_name, condition ? condition->Copy() : nullptr);
	}
};
	
struct BoundMeasure {
	//! Aggregate function name: FIRST, LAST, COUNT, MIN, MAX, SUM, AVG
	string function_name;
	//! The referenced PATTERN variable (e.g. "A", "B")
	string pattern_variable;
	//! The referenced source column name (e.g. "id", "price")
	string input_column;
	//! The type of the source column
	LogicalType input_type;
	//! The output column name (the AS alias)
	string output_name;
	//! The output type (COUNT→BIGINT, SUM/AVG→DOUBLE, FIRST/LAST/MIN/MAX→input type)
	LogicalType output_type;

	BoundMeasure() = default;
	BoundMeasure(string function_name, string pattern_variable, string input_column,
	             LogicalType input_type, string output_name, LogicalType output_type)
	    : function_name(std::move(function_name)), pattern_variable(std::move(pattern_variable)),
	      input_column(std::move(input_column)), input_type(std::move(input_type)),
	      output_name(std::move(output_name)), output_type(std::move(output_type)) {
	}
	BoundMeasure Copy() const {
		return *this;
	}
};

struct BoundMatchRecognizeInfo {
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
	//! The bound MEASURES entries
	vector<BoundMeasure> measures;
	//! The schema currently exported by the relation
	vector<string> names;
	vector<LogicalType> types;

	BoundMatchRecognizeInfo Copy() const {
		BoundMatchRecognizeInfo copy;
		for (auto &p : partition_by) {
			copy.partition_by.push_back(p ? p->Copy() : nullptr);
		}
		for (auto &o : order_by) {
			copy.order_by.push_back(o.Copy());
		}
		for (auto &d : defines) {
			copy.defines.push_back(d.Copy());
		}
		for (auto &m : measures) {
			copy.measures.push_back(m.Copy());
		}
		copy.one_row_per_match = one_row_per_match;
		copy.skip_to_next_row = skip_to_next_row;
		copy.pattern = pattern;
		copy.names = names;
		copy.types = types;
		return copy;
	}
	void Serialize(Serializer &serializer) const;
	static BoundMatchRecognizeInfo Deserialize(Deserializer &deserializer);
};

class BoundMatchRecognizeRef {
public:
	//! The bind index exported by the bound source relation
	idx_t bind_index;
	//! The binder used to bind the input relation and match-recognize keys
	shared_ptr<Binder> child_binder;
	//! The bound source relation
	BoundStatement child;
	//! The bound match recognize info
	BoundMatchRecognizeInfo bound_mr;
};

} // namespace duckdb
