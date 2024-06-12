#pragma once

#include <string>

namespace utils {
class file_buf {
  public:
    file_buf(std::filesystem::path path, std::string text);

    const std::filesystem::path &path() const { return p; }
    std::string_view text() const { return s; }

    std::string_view line(uint32_t n);

  private:
    std::filesystem::path p;
    std::string s;
    std::vector<std::pair<size_t, size_t>> breaks;
};
} // namespace utils