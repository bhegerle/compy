#include "token.h"

using namespace utils;
using namespace std;

namespace parser {
bool has_text(token_type t) { return static_cast<uint64_t>(t) < 0x1000; }

token::token(token_type type, shared_ptr<file_buf> file, string_view text,
             uint32_t line, uint32_t col)
    : ty(type), f(file), v(text), n(line), c(col) {}
} // namespace parser