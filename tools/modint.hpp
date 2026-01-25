#ifndef TOOLS_MODINT_HPP
#define TOOLS_MODINT_HPP

#include <concepts>
#include <type_traits>
#include "tools/modint_compatible.hpp"

namespace tools {
  template <typename T>
  concept modint = tools::modint_compatible<T>
    && requires(std::remove_cv_t<T> a) {
      { std::remove_cv_t<T>::mod() } -> std::same_as<int>;
      { a.val() } -> std::same_as<int>;
    };
}

#endif
