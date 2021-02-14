#ifndef TOOLS_DIVISORS_HPP
#define TOOLS_DIVISORS_HPP

#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

namespace tools {

  /**
   * gets all divisors
   * License: CC0
   * @author anqooqie
   * @param <T> type of input
   * @param n input
   * @return all divisors of $n$
   */
  template <typename T>
  ::std::vector<T> divisors(const T& n) {
    ::std::vector<T> head;
    ::std::vector<T> tail;

    T i;
    for (i = static_cast<T>(1); i * i < n; ++i) {
      if (n % i == static_cast<T>(0)) {
        head.push_back(i);
        tail.push_back(n / i);
      }
    }

    // if n is a square number
    if (i * i == n) {
      head.push_back(i);
    }

    ::std::copy(tail.rbegin(), tail.rend(), ::std::back_inserter(head));
    return head;
  }
}

#endif
