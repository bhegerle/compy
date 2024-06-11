#pragma once

#include "func.h"
#include "visitor.h"

#include <vector>

namespace ast {
template <typename F> class module {
  public:
    explicit module(std::string name) : n(name) {}

    const std::string &name() const { return n; }

    template <visitor<module, F> V> void accept(V &&v) const {
        v.visit(*this);
        for (auto &f : funcs)
            f->accept(v);
    }

  private:
    std::string n;
    std::vector<std::shared_ptr<F>> funcs;
};
} // namespace ast
