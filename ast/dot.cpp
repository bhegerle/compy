#include "dot.h"

#include "../utils/dassert.h"

using namespace utils;
using namespace parser;

namespace ast {
dot::dot(token &&ident) {
    dynamic_assert(ident.type() == token_type::ident,
                   "invalid token type {} in ident", ident.type());
}
} // namespace ast