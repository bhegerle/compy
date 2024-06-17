#pragma once

#include "expr.h"

#include "../parser/token.h"

namespace ast {
class ident : public expr {
  public:
    explicit ident(parser::token &&);
};
} // namespace ast
