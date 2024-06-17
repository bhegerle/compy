#include "func.h"
#include "ident.h"

using namespace utils;
using namespace parser;
using namespace std;

namespace ast {
func::func(type &&return_type, token &&ident, vector<param> &&params,
           block &&body)
    : rt(return_type), id(ident), p(params), b(body) {}
} // namespace ast