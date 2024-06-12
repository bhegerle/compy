#include "token.h"

namespace std {
template <> struct formatter<parser::token_type> {
    using token_type = parser::token_type;

    template <class ParseCtx> constexpr auto parse(ParseCtx &ctx) {
        return ctx.begin();
    }

    template <class FormatContext>
    auto format(token_type t, FormatContext &ctx) const {
        auto o = ctx.out();
        switch (t) {
        case token_type::ident:
            return format_to(o, "ident");
        default:
            return format_to(o, "<unknown>");
        }
    }
};

template <> struct formatter<parser::token> {
    using token = parser::token;

    template <class ParseCtx> constexpr auto parse(ParseCtx &ctx) {
        return ctx.begin();
    }

    template <class FormatContext>
    auto format(const parser::token &t, FormatContext &ctx) const {
        auto o = ctx.out();

        format_to(o, "{} ", t.type());

        if (!t.text().empty())
            format_to(o, "{} ", t.text());

        return format_to(o, "@{},{}", t.line(), t.col());
    }
};
} // namespace std
