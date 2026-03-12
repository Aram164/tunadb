#include "duckdb/parser/tableref/match_recognize_ref.hpp"
#include "duckdb/common/exception/parser_exception.hpp"
#include "duckdb/parser/transformer.hpp"

namespace duckdb {

unique_ptr<TableRef> Transformer::TransformMatchRecognize(duckdb_libpgquery::PGMatchRecognize &root) {
	auto result = make_uniq<MatchRecognizeRef>();
	result->source = TransformTableRefNode(*root.source);

	if (root.partition) {
		TransformExpressionList(*root.partition, result->partition_by);
	}
	TransformOrderBy(root.order, result->order_by);

	if (root.measures) {
		for (auto node = root.measures->head; node != nullptr; node = node->next) {
			auto raw_node = PGPointerCast<duckdb_libpgquery::PGNode>(node->data.ptr_value);
			if (raw_node->type != duckdb_libpgquery::T_PGResTarget) {
				throw ParserException("MATCH_RECOGNIZE MEASURES: expected ResTarget node");
			}
			auto &target = PGCast<duckdb_libpgquery::PGResTarget>(*raw_node);
			MeasureDefinition entry;
			entry.expression = TransformExpression(PGPointerCast<duckdb_libpgquery::PGNode>(target.val));
			if (target.name) {
				entry.alias = target.name;
			}
			result->measures.push_back(std::move(entry));
		}
	}

	if (root.define) {
		for (auto node = root.define->head; node != nullptr; node = node->next) {
			auto raw_node = PGPointerCast<duckdb_libpgquery::PGNode>(node->data.ptr_value);
			if (raw_node->type != duckdb_libpgquery::T_PGResTarget) {
				throw ParserException("MATCH_RECOGNIZE DEFINE: expected ResTarget node");
			}
			auto &target = PGCast<duckdb_libpgquery::PGResTarget>(*raw_node);
			VariableDefinition entry;
			if (target.name) {
				entry.variable_name = target.name;
			}
			entry.condition = TransformExpression(PGPointerCast<duckdb_libpgquery::PGNode>(target.val));
			result->define.push_back(std::move(entry));
		}
	}

	result->rows_per_match =
	    root.one_row_per_match ? RowsPerMatchType::ONE_ROW_PER_MATCH : RowsPerMatchType::ALL_ROWS_PER_MATCH;
	result->after_match_skip = root.skip_to_next_row ? AfterMatchSkipType::SKIP_TO_NEXT_ROW
	                                                  : AfterMatchSkipType::SKIP_PAST_LAST_ROW;

	if (root.pattern) {
		result->pattern = root.pattern;
	}

	return std::move(result);
}

} // namespace duckdb
