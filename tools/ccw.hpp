#ifndef TOOLS_CCW_HPP
#define TOOLS_CCW_HPP

#include "tools/vector2.hpp"

namespace tools {
  template <typename T>
  int ccw(const ::tools::vector2<T>& a, ::tools::vector2<T> b, ::tools::vector2<T> c) {
    b -= a;
    c -= a;
    if (b.outer_product(c) > T(0)) return +1;
    if (b.outer_product(c) < T(0)) return -1;
    if (b.inner_product(c) < T(0)) return +2;
    if (b.squared_l2_norm() < c.squared_l2_norm()) return -2;
    return 0;
  }
}

#endif
