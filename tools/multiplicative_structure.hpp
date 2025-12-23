#ifndef TOOLS_MULTIPLICATIVE_STRUCTURE_HPP
#define TOOLS_MULTIPLICATIVE_STRUCTURE_HPP

#include <concepts>
#include <type_traits>
#include "atcoder/modint.hpp"
#include "tools/complex.hpp"
#include "tools/groups.hpp"
#include "tools/integral.hpp"
#include "tools/is_prime.hpp"
#include "tools/monoids.hpp"
#include "tools/prime_static_modint.hpp"

namespace tools {
  template <typename T>
  using multiplicative_structure = std::conditional_t<
    tools::complex<T> || std::floating_point<T> || tools::prime_static_modint<T> || atcoder::internal::is_dynamic_modint<T>::value,
      tools::groups::multiplies<T>,
      std::conditional_t<
        tools::integral<T> || atcoder::internal::is_static_modint<T>::value,
          tools::monoids::multiplies<T>,
          std::conditional_t<
            requires(T a, T b) { { a / b } -> std::same_as<T>; },
              tools::groups::multiplies<T>,
              tools::monoids::multiplies<T>
          >
      >
  >;
}

#endif
