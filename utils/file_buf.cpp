#include "file_buf.h"

#include "dassert.h"

using namespace std;

namespace utils {
file_buf::file_buf(filesystem::path path, string text) : p(path), s(text) {}

string_view file_buf::line(uint32_t n) {
    if (breaks.empty()) {
        size_t start = 0;
        size_t i;
        for (i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (c == '\n') {
                auto end = i;
                if (i > start && s[i - 1] == '\r')
                    end = i - 1;

                breaks.push_back(make_pair(start, end));

                start = i + 1;
            }
        }

        breaks.push_back(make_pair(start, s.size()));
    }

    n--;

    dynamic_assert(0 <= n && n < breaks.size(), "line {} out of bounds for {}",
                   n, path().string());

    auto [start, end] = breaks[n];
    return text().substr(start, end - start);
}
} // namespace utils