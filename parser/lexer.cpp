#include "lexer.h"

#include "../utils/dassert.h"

using namespace utils;
using namespace std;

namespace parser {
lexer_base::lexer_base(shared_ptr<file_buf> file)
    : f(file), ch(0), line(1), col(1) {}

bool lexer_base::eof() const { return ch >= f->text().size(); }

string_view lexer_base::view() { return string_view(f->text()).substr(ch); }

void lexer_base::skip(uint32_t len) { advance(len, "skip"); }

token lexer_base::take(uint32_t len, token_type type) {
    auto n = line, c = col;
    auto v = advance(len, "take");
    return token(type, f, v, n, c);
}

string_view lexer_base::advance(uint32_t len, string_view why) {
    auto v = view();
    dynamic_assert(len <= v.size(), "cannot {} {} of {}", why, len, f->path().string());

    v = v.substr(0, len);

    for (auto c : v) {
        ch++;

        if (c == '\n') {
            line++;
            col = 1;
        } else {
            col++;
        }
    }

    return v;
}
} // namespace parser