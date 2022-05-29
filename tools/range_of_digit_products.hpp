#ifndef TOOLS_RANGE_OF_DIGIT_PRODUCTS_HPP
#define TOOLS_RANGE_OF_DIGIT_PRODUCTS_HPP

#include <vector>
#include <cassert>
#include <limits>
#include <array>
#include <algorithm>
#include "tools/ceil.hpp"

namespace tools {

  template <typename T>
  ::std::vector<T> range_of_digit_products(const T n) {
    assert(0 <= n && n <= ::std::numeric_limits<T>::digits10);

    ::std::vector<T> range;
    if (n == 0) return range;
    if (n > 1) range.push_back(0);

    ::std::array<T, 5> left;
    left[0] = n;
    for (T a = 0, pow6 = 1; a <= left[0]; ++a, pow6 *= 6) {
      left[1] = left[0] - a;
      for (T b = 0, pow2 = 1; b <= 3 * left[1]; ++b, pow2 *= 2) {
        left[2] = left[1] - ::tools::ceil(b, 3);
        for (T c = 0, pow3 = 1; c <= 2 * left[2]; ++c, pow3 *= 3) {
          left[3] = left[2] - ::tools::ceil(c, 2);
          for (T d = 0, pow5 = 1; d <= left[3]; ++d, pow5 *= 5) {
            left[4] = left[3] - d;
            for (T e = 0, pow7 = 1; e <= left[4]; ++e, pow7 *= 7) {
              range.push_back(pow6 * pow2 * pow3 * pow5 * pow7);
            }
          }
        }
      }
    }

    ::std::sort(range.begin(), range.end());
    range.erase(::std::unique(range.begin(), range.end()), range.end());

    return range;
  }
}

#endif
