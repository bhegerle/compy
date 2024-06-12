#pragma once

#include "token.h"

#include "../utils/file_buf.h"

namespace parser {
class lexer_base {
  public:
    explicit lexer_base(std::shared_ptr<utils::file_buf> file);

  protected:
    bool eof() const;

    std::string_view view();
    void skip(uint32_t len);
    token take(uint32_t len, token_type type);

  private:
    std::shared_ptr<utils::file_buf> f;
    std::vector<uint32_t> breaks;
    uint32_t ch, line, col;

    std::string_view advance(uint32_t len, std::string_view why);
};
} // namespace parser