#ifndef TOOLS_PRIME_STATIC_MODINT_HPP
#define TOOLS_PRIME_STATIC_MODINT_HPP

#include "atcoder/modint.hpp"
#include "tools/is_prime.hpp"

namespace tools {
  template <typename T>
  concept prime_static_modint = atcoder::internal::is_static_modint<T>::value && tools::is_prime(T::mod());
}

#endif
