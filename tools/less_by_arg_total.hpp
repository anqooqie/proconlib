#ifndef TOOLS_LESS_BY_ARG_TOTAL_HPP
#define TOOLS_LESS_BY_ARG_TOTAL_HPP

#include "tools/vector2.hpp"
#include "tools/ccw.hpp"

namespace tools {

  template <typename T>
  class less_by_arg_total {
    ::tools::vector2<T> o;
    ::tools::vector2<T> d;

    int where(const ::tools::vector2<T>& p) const {
      static const ::tools::vector2<T> zero(T(0), T(0));
      static const ::tools::vector2<T> unit_x(T(1), T(0));
      if (this->d == zero) {
        return p.y > T(0) || (p.y == T(0) && p.x >= T(0)) ? 0 : 1;
      } else {
        if (p == zero) {
          const auto ccw = ::tools::ccw(zero, this->d, unit_x);
          if (ccw == +1) return 2;
          if (ccw == +2) return 4;
          if (ccw == -1) return 7;
          return 9;
        } else {
          if (this->d == p) {
            return 0;
          }
          const auto ccw = ::tools::ccw(zero, this->d, p);
          if (ccw == -2) {
            return 0;
          }
          if (ccw == +1) {
            if (::tools::ccw(zero, this->d, unit_x) != +1) return 1;
            if (::tools::ccw(zero, unit_x, p) == -1) return 1;
            return 3;
          }
          if (ccw == +2) {
            return 5;
          }
          if (ccw == -1) {
            if (::tools::ccw(zero, this->d, unit_x) != -1) return 6;
            if (::tools::ccw(zero, unit_x, p) == -1) return 6;
            return 8;
          }
          return 9;
        }
      }
    }

  public:
    less_by_arg_total() = default;
    less_by_arg_total(const ::tools::vector2<T>& o, const ::tools::vector2<T>& d) : o(o), d(d - o) {
    }

    bool operator()(::tools::vector2<T> a, ::tools::vector2<T> b) const {
      a -= this->o;
      b -= this->o;
      if (const auto wa = this->where(a), wb = this->where(b); wa != wb) return wa < wb;
      if (const auto ot = a.outer_product(b); ot != T(0)) return ot > T(0);
      return a.squared_l2_norm() < b.squared_l2_norm();
    }
  };
}

#endif
