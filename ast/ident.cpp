#include "ident.h"

#include "../parser/fmt.h"

using namespace utils;
using namespace parser;

namespace ast {
void ident::add(token_ptr ident) {
    dynamic_assert(ident->type() == token_type::ident,
                   "invalid token type {} in ident", ident->type());
    v.push_back(ident);
}
} // namespace ast