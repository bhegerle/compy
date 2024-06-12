#include "token.h"

using namespace utils;
using namespace std;

namespace parser {
token::token(token_type type, shared_ptr<file_buf> file, string_view text,
             uint32_t line, uint32_t col)
    : ty(type), f(file), v(text), n(line), c(col) {}
} // namespace parser