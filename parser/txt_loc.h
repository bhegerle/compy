#pragma once

#include <filesystem>
#include <string>

namespace parser {
class txt_loc {
  public:
    txt_loc(std::filesystem::path filename, uint32_t line, uint32_t col)
        : f(filename), n(line), c(col) {}

    uint32_t line() const { return n; }
    uint32_t col() const { return c; }

  private:
    std::filesystem::path f;
    uint32_t n, c;
};
} // namespace parser
