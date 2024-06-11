#pragma once

#include "../parser/token.h"
#include "../utils/dassert.h"

namespace ast {
class ident {
  public:
    using token_ptr = std::shared_ptr<parser::token>;

    explicit ident(token_ptr start) { add(start); }

    void add(token_ptr ident);

  private:
    std::vector<token_ptr> v;
};
} // namespace ast
