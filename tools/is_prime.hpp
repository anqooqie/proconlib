#ifndef TOOLS_IS_PRIME_HPP
#define TOOLS_IS_PRIME_HPP

#include <cstdint>
#include <array>
#include "tools/prod_mod.hpp"
#include "tools/pow_mod.hpp"

namespace tools {

  /**
   * check whether $n$ is a prime or not
   * License: CC0
   * References:
   * ミラー-ラビン素数判定法 - Wikipedia ( https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95 )
   * Deterministic variants of the Miller-Rabin primality test. Miller-Rabin SPRP bases records ( http://miller-rabin.appspot.com/ )
   *
   * Usage:
   * ```
   * static_assert(tools::is_prime(P), "P must be prime.");
   * ```
   *
   * @author anqooqie
   * @param n input
   * @return `true` if $n$ is a prime, and `false` if $n$ is not a prime
   */
  constexpr bool is_prime(const ::std::uint_fast64_t n) {
    constexpr ::std::array<::std::uint_fast64_t, 7> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    ::std::uint_fast64_t d = n - 1;
    for (; d % 2 == 0; d /= 2);

    for (const ::std::uint_fast64_t a : bases) {
      if (a % n == 0) return true;

      ::std::uint_fast64_t power = d;
      ::std::uint_fast64_t target = ::tools::pow_mod(a, power, n);

      bool is_composite = true;
      if (target == 1) is_composite = false;
      for (; is_composite && power != n - 1; power *= 2, target = ::tools::prod_mod(target, target, n)) {
        if (target == n - 1) is_composite = false;
      }

      if (is_composite) {
        return false;
      }
    }

    return true;
  }
}

#endif
