#pragma once

#include "type.h"

#include "../parser/token.h"

namespace ast {
class param {
  public:
    param(type &&ptype, parser::token &&ident);

  private:
    type t;
    parser::token id;
};
} // namespace ast
