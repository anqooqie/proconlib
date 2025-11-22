#ifndef TOOLS_LESS_BY_ARG_HPP
#define TOOLS_LESS_BY_ARG_HPP

#include <cassert>
#include "tools/vector2.hpp"
#include "tools/ccw.hpp"

namespace tools {

  template <typename T>
  class less_by_arg {
    ::tools::vector2<T> o;
    ::tools::vector2<T> d;

    int where(const ::tools::vector2<T>& p) const {
      assert(p != this->o);
      const auto ccw = ::tools::ccw(this->o, this->d, p);
      if (ccw == +1) return 1;
      if (ccw == -1) return 3;
      if (ccw == +2) return 2;
      return 0;
    }

  public:
    less_by_arg() = default;
    less_by_arg(const ::tools::vector2<T>& o, const ::tools::vector2<T>& d) : o(o), d(d) {
      assert(d != o);
    }

    bool operator()(const ::tools::vector2<T>& a, const ::tools::vector2<T>& b) const {
      if (const auto wa = this->where(a), wb = this->where(b); wa != wb) return wa < wb;
      return (a - this->o).outer_product(b - this->o) > T(0);
    }
  };
}

#endif
