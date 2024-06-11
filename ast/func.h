#pragma once

namespace ast {
template <typename N> class func {
  public:
    func(N name) : n(name) {}

    void type_params() {}
    void return_type() {}
    const N &name() const { return n; }
    void params() {}
    void statements() {}

  private:
    N n;
};
} // namespace ast
