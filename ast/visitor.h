#pragma once

namespace ast {
template <typename V, typename T>
concept has_visitor_method = requires(V v, T x) {
    { v.visit(x) };
};

template <typename V, typename... T>
concept visitor = has_visitor_method<V, T...>;
} // namespace ast
