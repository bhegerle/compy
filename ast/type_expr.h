#pragma once

#include "expr.h"
#include "type.h"

namespace ast {
class type_expr : public type {
  public:
    explicit type_expr(expr &&expr);

  private:
    expr x;
};
} // namespace ast