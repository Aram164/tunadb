//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/planner/operator/logical_match_recognize.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/planner/logical_operator.hpp"
#include "duckdb/parser/tableref/match_recognize_ref.hpp"
#include "duckdb/planner/tableref/bound_match_recognize_ref.hpp"

namespace duckdb {

class LogicalMatchRecognize : public LogicalOperator {
public:
	static constexpr const LogicalOperatorType TYPE = LogicalOperatorType::LOGICAL_MATCH_RECOGNIZE;

public:
	LogicalMatchRecognize(idx_t bind_index, unique_ptr<LogicalOperator> plan, BoundMatchRecognizeInfo info);
	LogicalMatchRecognize(idx_t bind_index, const BoundMatchRecognizeInfo &info);

	idx_t bind_index;
	//! The bound match recognize info
	BoundMatchRecognizeInfo bound_mr;

public:
	vector<ColumnBinding> GetColumnBindings() override;

	void Serialize(Serializer &serializer) const override;
	static unique_ptr<LogicalOperator> Deserialize(Deserializer &deserializer);
	vector<idx_t> GetTableIndex() const override;
	string GetName() const override;

	unique_ptr<LogicalOperator> Copy(ClientContext &context) const override;
	InsertionOrderPreservingMap<string> ParamsToString() const override;

protected:
	void ResolveTypes() override;

private:
	LogicalMatchRecognize();
};
} // namespace duckdb