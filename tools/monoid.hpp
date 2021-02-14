#ifndef TOOLS_MONOID_HPP
#define TOOLS_MONOID_HPP

#include <algorithm>
#include <limits>
#include <numeric>

namespace tools {
  namespace monoid {
    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>
    struct max {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return ::std::max(lhs, rhs);
      }
      static T e() {
        return E;
      }
    };

    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>
    struct min {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return ::std::min(lhs, rhs);
      }
      static T e() {
        return E;
      }
    };

    template <typename Type>
    struct multiplies {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return lhs * rhs;
      }
      static T e() {
        return static_cast<T>(1);
      }
    };

    template <typename Type>
    struct gcd {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return ::std::gcd(lhs, rhs);
      }
      static T e() {
        return static_cast<T>(0);
      }
    };

    template <typename Type, Type E>
    struct update {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return rhs == E ? lhs : rhs;
      }
      static T e() {
        return E;
      }
    };
  }
}

#endif
