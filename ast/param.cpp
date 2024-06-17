#include "param.h"

using namespace parser;

namespace ast {
param::param(ast::type &&ptype, token &&ident) : t(ptype), id(ident) {}
} // namespace ast