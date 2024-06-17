#pragma once

#include "expr.h"

namespace ast {
class dot : public expr {
  public:
    explicit dot(parser::token &&ident);
};
} // namespace ast
