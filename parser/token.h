#pragma once

#include "txt_loc.h"

#include <format>

namespace parser {
enum class token_type { ident };

class token {
  public:
    token(token_type type, std::string_view text, txt_loc tl)
        : ty(type), txt(text), tl(tl) {}

    token_type type() const { return ty; }
    std::string_view text() const { return txt; }
    txt_loc loc() const { return tl; }

  private:
    token_type ty;
    std::string_view txt;
    txt_loc tl;
};
} // namespace parser
