#ifndef TOOLS_MONOID_HPP
#define TOOLS_MONOID_HPP

#include <algorithm>
#include <limits>
#include <numeric>

namespace tools {
  namespace monoid {
    template <typename M, M E = ::std::numeric_limits<M>::lowest()>
    struct max {
      using T = M;
      static T op(const T& lhs, const T& rhs) {
        return ::std::max(lhs, rhs);
      }
      static T e() {
        return E;
      }
    };

    template <typename M, M E = ::std::numeric_limits<M>::max()>
    struct min {
      using T = M;
      static T op(const T& lhs, const T& rhs) {
        return ::std::min(lhs, rhs);
      }
      static T e() {
        return E;
      }
    };

    template <typename M>
    struct multiplies {
      using T = M;
      static T op(const T& lhs, const T& rhs) {
        return lhs * rhs;
      }
      static T e() {
        return T(1);
      }
    };

    template <typename M>
    struct gcd {
      using T = M;
      static T op(const T& lhs, const T& rhs) {
        return ::std::gcd(lhs, rhs);
      }
      static T e() {
        return T(0);
      }
    };

    template <typename M, M E>
    struct update {
      using T = M;
      static T op(const T& lhs, const T& rhs) {
        return lhs == E ? rhs : lhs;
      }
      static T e() {
        return E;
      }
    };
  }
}

#endif
