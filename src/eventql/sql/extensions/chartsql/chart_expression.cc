/**
 * Copyright (c) 2016 zScale Technology GmbH <legal@zscale.io>
 * Authors:
 *   - Paul Asmuth <paul@zscale.io>
 *   - Laura Schlimmer <laura@zscale.io>
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License ("the license") as
 * published by the Free Software Foundation, either version 3 of the License,
 * or any later version.
 *
 * In accordance with Section 7(e) of the license, the licensing of the Program
 * under the license does not imply a trademark license. Therefore any rights,
 * title and interest in our trademarks remain entirely with us.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You can be released from the requirements of the license by purchasing a
 * commercial license. Buying such a license is mandatory as soon as you develop
 * commercial activities involving this program without disclosing the source
 * code of your own applications
 */
#include <eventql/sql/extensions/chartsql/chart_expression.h>

namespace csql {

ChartExpression::ChartExpression(
    Transaction* txn,
    RefPtr<ChartStatementNode> qtree,
    Vector<ScopedPtr<TableExpression>> input_tables) :
    txn_(txn),
    qtree_(std::move(qtree)),
    input_tables_(std::move(input_tables)) {}

ScopedPtr<ResultCursor> ChartExpression::execute() {
  return mkScoped(
      new DefaultResultCursor(
          1,
          std::bind(
              &ChartExpression::next,
              this,
              std::placeholders::_1,
              std::placeholders::_2)));
}

size_t ChartExpression::getNumColumns() const {
  return 1;
}

bool ChartExpression::next(SValue* row, size_t row_len) {
  return false;
}

} //namespace csql
