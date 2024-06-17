#pragma once

#include "block.h"
#include "expr.h"
#include "param.h"
#include "type.h"

#include <vector>

namespace ast {
class func {
  public:
    func(type &&return_type, parser::token &&ident, std::vector<param> &&params,
         block &&body);

    void return_type() {}
    const parser::token &ident() const { return id; }
    const std::string_view &name() const { return ident().text(); }
    void params() {}
    block &body() {}

  private:
    type rt;
    parser::token id;
    std::vector<param> p;
    block b;
};
} // namespace ast
