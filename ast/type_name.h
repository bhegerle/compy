#pragma once

#include "expr.h"
#include "type.h"

namespace ast {
class type_name : public type {
  public:
    explicit type_name(expr &&expr);

  private:
    expr x;
};
} // namespace ast