#ifndef TOOLS_PRIME_FACTORIZATION_HPP
#define TOOLS_PRIME_FACTORIZATION_HPP

#include <map>
#include <cmath>

namespace tools {

  /**
   * prime factorization
   * License: CC0
   * @author anqooqie
   * @param n input
   * @return map whose key is a disinct prime factor and value is the multiplicity.
   */
  template <typename T>
  ::std::map<T, T> prime_factorization(T n) {
    ::std::map<T, T> result;

    for (T i = static_cast<T>(2); i * i <= n; ++i) {
      while (n % i == static_cast<T>(0)) {
        ++result[i];
        n /= i;
      }
    }

    // if n is a prime
    if (n > static_cast<T>(1)) {
      ++result[n];
    }

    return result;
  }
}

#endif
