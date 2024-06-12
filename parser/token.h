#pragma once

#include "../utils/file_buf.h"

#include <format>

namespace parser {
enum class token_type { ws, ident };

class token {
  public:
    token(token_type type, std::shared_ptr<utils::file_buf> file,
          std::string_view text, uint32_t line, uint32_t col);

    token_type type() const { return ty; }
    std::string_view text() const { return v; }
    uint32_t line() const { return n; }
    uint32_t col() const { return c; }

  private:
    token_type ty;
    std::shared_ptr<utils::file_buf> f;
    std::string_view v;
    uint32_t n, c;
};
} // namespace parser
