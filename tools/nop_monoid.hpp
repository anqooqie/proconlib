#ifndef TOOLS_NOP_MONOID_HPP
#define TOOLS_NOP_MONOID_HPP

#include <variant>

namespace tools {
  struct nop_monoid {
    using T = ::std::monostate;
    static T op(T, T) {
      return {};
    }
    static T e() {
      return {};
    }
  };
}

#endif
