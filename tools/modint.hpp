#ifndef TOOLS_MODINT_HPP
#define TOOLS_MODINT_HPP

#include <concepts>
#include "tools/modint_compatible.hpp"

namespace tools {
  template <typename T>
  concept modint = tools::modint_compatible<T>
    && requires(T a) {
      { T::mod() } -> std::same_as<int>;
      { a.val() } -> std::same_as<int>;
    };
}

#endif
