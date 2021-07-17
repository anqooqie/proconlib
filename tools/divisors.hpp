#ifndef TOOLS_DIVISORS_HPP
#define TOOLS_DIVISORS_HPP

#include <vector>
#include <map>
#include <deque>
#include <cstddef>
#include <algorithm>
#include "tools/prime_factorization.hpp"

namespace tools {

  template <typename T>
  ::std::vector<T> divisors(const T& n) {
    const ::std::map<T, T> prime_factors = tools::prime_factorization(n);
    ::std::deque<T> deque({1});
    for (const auto& [distinct_prime_factor, exponent] : tools::prime_factorization(n)) {
      const ::std::size_t prev_size = deque.size();
      for (::std::size_t i = 0; i < prev_size; ++i) {
        const T prev = deque.front();
        deque.pop_front();
        for (T e = 0, next = 1; e <= exponent; ++e, next *= distinct_prime_factor) {
          deque.push_back(prev * next);
        }
      }
    }
    ::std::sort(deque.begin(), deque.end());
    return ::std::vector<T>(deque.begin(), deque.end());
  }
}

#endif
