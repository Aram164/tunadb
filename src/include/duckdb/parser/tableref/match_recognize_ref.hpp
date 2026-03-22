
//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/tableref/match_recognize_ref.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/result_modifier.hpp"
#include "duckdb/parser/tableref.hpp"

namespace duckdb {

enum class RowsPerMatchType : uint8_t {
	ONE_ROW_PER_MATCH = 0,
	ALL_ROWS_PER_MATCH = 1
};

enum class AfterMatchSkipType : uint8_t {
	SKIP_PAST_LAST_ROW = 0,
	SKIP_TO_NEXT_ROW = 1
};

struct MeasureDefinition {
	unique_ptr<ParsedExpression> expression;
	string alias;

	MeasureDefinition Copy() const;
	bool Equals(const MeasureDefinition &other) const;
};

struct VariableDefinition {
	string variable_name;
	unique_ptr<ParsedExpression> condition;

	VariableDefinition Copy() const;
	bool Equals(const VariableDefinition &other) const;
};

//! Represents a MATCH_RECOGNIZE clause attached to a table source
class MatchRecognizeRef : public TableRef {
public:
	static constexpr const TableReferenceType TYPE = TableReferenceType::MATCH_RECOGNIZE;

public:
	MatchRecognizeRef() : TableRef(TableReferenceType::MATCH_RECOGNIZE) {
	}

	//! Source table/subquery the clause is attached to
	unique_ptr<TableRef> source;
	//! PARTITION BY expressions
	vector<unique_ptr<ParsedExpression>> partition_by;
	//! ORDER BY expressions
	vector<OrderByNode> order_by;
	//! MEASURES definitions
	vector<MeasureDefinition> measures;
	//! ROWS PER MATCH behavior
	RowsPerMatchType rows_per_match = RowsPerMatchType::ONE_ROW_PER_MATCH;
	//! AFTER MATCH SKIP behavior
	AfterMatchSkipType after_match_skip = AfterMatchSkipType::SKIP_PAST_LAST_ROW;
	//! PATTERN text
	string pattern;
	//! DEFINE definitions
	vector<VariableDefinition> define;

public:
	string ToString() const override;
	bool Equals(const TableRef &other_p) const override;
	unique_ptr<TableRef> Copy() override;

	void Serialize(Serializer &serializer) const override;
	static unique_ptr<TableRef> Deserialize(Deserializer &deserializer);
};

} // namespace duckdb
