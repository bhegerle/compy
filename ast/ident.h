#pragma once

#include "../parser/token.h"

namespace ast {
class ident {
  public:
    explicit ident(std::shared_ptr<parser::token> start) { v.push_back(start); }

  private:
    std::vector<std::shared_ptr<parser::token>> v;
};
} // namespace ast
