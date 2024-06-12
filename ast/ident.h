#pragma once

#include "../parser/token.h"

namespace ast {
class ident {
  public:
    using token_ptr = std::shared_ptr<parser::token>;
    explicit ident(token_ptr ident);
};
} // namespace ast
