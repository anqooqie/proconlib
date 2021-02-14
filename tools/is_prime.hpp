#ifndef TOOLS_IS_PRIME_H
#define TOOLS_IS_PRIME_H

#include <cstdint>
#include <limits>

namespace tools {
  namespace detail {
    namespace is_prime {
      constexpr ::std::uint_fast32_t mid(const ::std::uint_fast32_t low, const ::std::uint_fast32_t high) {
        return (low + high) / 2;
      }

      // precondition: low*low <= n, high*high > n.
      constexpr ::std::uint_fast32_t ceilsqrt(const ::std::uint_fast32_t n, const ::std::uint_fast32_t low, const ::std::uint_fast32_t high) {
        return low + 1 >= high
          ? high
          : (::tools::detail::is_prime::mid(low, high) * ::tools::detail::is_prime::mid(low, high) == n)
          ? ::tools::detail::is_prime::mid(low, high)
          : (::tools::detail::is_prime::mid(low, high) * ::tools::detail::is_prime::mid(low, high) <  n)
          ? ::tools::detail::is_prime::ceilsqrt(n, ::tools::detail::is_prime::mid(low, high), high)
          : ::tools::detail::is_prime::ceilsqrt(n, low, ::tools::detail::is_prime::mid(low, high));
      }

      // returns ceiling(sqrt(n))
      constexpr ::std::uint_fast32_t ceilsqrt(const ::std::uint_fast32_t n) {
        return n < 3
          ? n
          : ::tools::detail::is_prime::ceilsqrt(n, 1, ::std::uint_fast32_t(1) << (::std::numeric_limits<std::uint_fast32_t>::digits / 2));
      }

      // returns true if n is divisible by an odd integer in
      // [2 * low + 1, 2 * high + 1).
      constexpr bool find_factor(const ::std::uint_fast32_t n, const ::std::uint_fast32_t low, const ::std::uint_fast32_t high) {
        return low + 1 >= high
          ? (n % (2 * low + 1)) == 0
          : (::tools::detail::is_prime::find_factor(n, low, ::tools::detail::is_prime::mid(low, high)) || ::tools::detail::is_prime::find_factor(n, ::tools::detail::is_prime::mid(low, high), high));
      }
    }
  }

  /**
   * check whether $n$ is a prime or not
   * License: CC BY-SA 3.0
   * Reference: Stack Overflow ( https://stackoverflow.com/questions/18303632/compile-time-prime-checking/18306693#18306693 )
   *
   * Usage:
   * ```
   * static_assert(tools::is_prime(P), "P must be prime.");
   * ```
   *
   * @author Casey ( https://stackoverflow.com/users/923854/casey )
   * @param n input
   * @return `true` if $n$ is a prime, and `false` if $n$ is not a prime
   */
  constexpr bool is_prime(const ::std::uint_fast32_t n) {
    return n > 1
      && (n == 2
        || (n % 2 == 1
          && (n == 3
            || !::tools::detail::is_prime::find_factor(n, 1, (::tools::detail::is_prime::ceilsqrt(n) + 1) / 2))));
  }
}

#endif
