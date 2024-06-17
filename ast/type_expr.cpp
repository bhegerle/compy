#include "type_expr.h"

namespace ast {
type_expr::type_expr(expr &&expr) : x(expr) {}
} // namespace ast