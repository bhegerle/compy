#include "ident.h"

#include "../parser/fmt.h"
#include "../utils/dassert.h"

using namespace utils;
using namespace parser;

namespace ast {
ident::ident(token_ptr ident) {
    dynamic_assert(ident->type() == token_type::ident,
                   "invalid token type {} in ident", ident->type());
}
} // namespace ast