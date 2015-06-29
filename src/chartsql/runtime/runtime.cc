/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <chartsql/runtime/runtime.h>
#include <chartsql/runtime/resultlist.h>
#include <chartsql/backends/csv/csvbackend.h>

namespace csql {

Runtime::Runtime() :
    compiler_(&symbol_table_) {}

QueryPlanBuilder* Runtime::queryPlanBuilder() {
  RAISE(kNotImplementedError);
}

void Runtime::addBackend(std::unique_ptr<Backend> backend) {
  backends_.emplace_back(std::move(backend));
}

const std::vector<std::unique_ptr<Backend>>& Runtime::backends() {
  return backends_;
}

ValueExpressionBuilder* Runtime::compiler() {
  return &compiler_;
}

Parser* Runtime::parser() {
  return &parser_;
}

}
