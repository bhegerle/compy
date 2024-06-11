#pragma once

#include <format>
#include <stdexcept>

namespace utils {
template <typename... T>
constexpr void dynamic_assert(bool condition,
                              const std::format_string<T...> &msg_fmt,
                              T &&...args) {
    if (!condition) {
        auto msg = std::vformat(msg_fmt.get(), std::make_format_args(args...));
        throw std::runtime_error(msg);
    }
}
} // namespace utils