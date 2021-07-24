#ifndef TOOLS_GREATER_BY_ARG_HPP
#define TOOLS_GREATER_BY_ARG_HPP

#include <cassert>
#include "tools/vector2.hpp"
#include "tools/ccw.hpp"

namespace tools {

  template <bool DEFAULT, typename T>
  class greater_by_arg {
  private:
    ::tools::vector2<T> d;

    template <typename U>
    int where(const ::tools::vector2<U>& p) const {
      if constexpr (DEFAULT) {
        return p.y > 0 || (p.y == 0 && p.x >= 0) ? 0 : 1;
      } else {
        if (this->d.x == 0 && this->d.y == 0) {
          return p.y > 0 || (p.y == 0 && p.x >= 0) ? 0 : 1;
        } else {
          if (p.x == 0 && p.y == 0) {
            const int ccw = ::tools::ccw(::tools::vector2<U>(0, 0), this->d, ::tools::vector2<U>(1, 0));
            if (ccw == -1) return 2;
            if (ccw == -2) return 4;
            if (ccw == +1) return 7;
            return 9;
          } else {
            if (this->d == p) return 0;
            const int ccw = ::tools::ccw(::tools::vector2<U>(0, 0), this->d, p);
            if (ccw == -2) return 0;
            if (ccw == +1) {
              const int ccw2 = ::tools::ccw(::tools::vector2<U>(0, 0), this->d, ::tools::vector2<U>(1, 0));
              if (ccw2 != +1) return 1;
              const int ccw3 = ::tools::ccw(::tools::vector2<U>(0, 0), ::tools::vector2<U>(1, 0), p);
              if (ccw3 == -1) return 1;
              return 3;
            }
            if (ccw == +2) return 5;
            if (ccw == -1) {
              const int ccw2 = ::tools::ccw(::tools::vector2<U>(0, 0), this->d, ::tools::vector2<U>(1, 0));
              if (ccw2 != -1) return 6;
              const int ccw3 = ::tools::ccw(::tools::vector2<U>(0, 0), ::tools::vector2<U>(1, 0), p);
              if (ccw3 == -1) return 6;
              return 8;
            }
            return 9;
          }
        }
      }
    }

  public:
    greater_by_arg() = default;

    template <typename U>
    explicit greater_by_arg(const ::tools::vector2<U>& d) : d(d) {
    }

    template <typename U>
    bool operator()(const ::tools::vector2<U>& a, const ::tools::vector2<U>& b) const {
      const int wa = this->where(a);
      const int wb = this->where(b);
      return wa == wb ? a.outer_product(b) < 0 || (a.outer_product(b) == 0 && a.squared_norm() > b.squared_norm()) : wa > wb;
    }
  };

  greater_by_arg() -> greater_by_arg<true, int>;

  template <typename U>
  greater_by_arg(const ::tools::vector2<U>&) -> greater_by_arg<false, U>;
}

#endif
