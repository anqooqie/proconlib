#ifndef TOOLS_MONOID_HPP
#define TOOLS_MONOID_HPP

#include <type_traits>
#include <algorithm>
#include <limits>
#include <cassert>
#include "tools/gcd.hpp"

namespace tools {
  namespace monoid {
    template <typename M, M ...dummy>
    struct max;

    template <typename M>
    struct max<M> {
      static_assert(::std::is_arithmetic_v<M>, "M must be a built-in arithmetic type.");

      using T = M;
      static T op(const T lhs, const T rhs) {
        return ::std::max(lhs, rhs);
      }
      static T e() {
        if constexpr (::std::is_integral_v<M>) {
          return ::std::numeric_limits<M>::min();
        } else {
          return -::std::numeric_limits<M>::infinity();
        }
      }
    };

    template <typename M, M E>
    struct max<M, E> {
      static_assert(::std::is_integral_v<M>, "M must be a built-in integral type.");

      using T = M;
      static T op(const T lhs, const T rhs) {
        assert(E <= lhs);
        assert(E <= rhs);
        return ::std::max(lhs, rhs);
      }
      static T e() {
        return E;
      }
    };

    template <typename M, M ...dummy>
    struct min;

    template <typename M>
    struct min<M> {
      static_assert(::std::is_arithmetic_v<M>, "M must be a built-in arithmetic type.");

      using T = M;
      static T op(const T lhs, const T rhs) {
        return ::std::min(lhs, rhs);
      }
      static T e() {
        if constexpr (::std::is_integral_v<M>) {
          return ::std::numeric_limits<M>::max();
        } else {
          return ::std::numeric_limits<M>::infinity();
        }
      }
    };

    template <typename M, M E>
    struct min<M, E> {
      static_assert(::std::is_integral_v<M>, "M must be a built-in integral type.");

      using T = M;
      static T op(const T lhs, const T rhs) {
        assert(lhs <= E);
        assert(rhs <= E);
        return ::std::min(lhs, rhs);
      }
      static T e() {
        return E;
      }
    };

    template <typename M>
    struct multiplies {
    private:
      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>, const M, const M&>;

    public:
      using T = M;
      static T op(VR lhs, VR rhs) {
        return lhs * rhs;
      }
      static T e() {
        return T(1);
      }
    };

    template <>
    struct multiplies<bool> {
      using T = bool;
      static T op(const bool lhs, const bool rhs) {
        return lhs && rhs;
      }
      static T e() {
        return true;
      }
    };

    template <typename M>
    struct gcd {
    private:
      static_assert(!::std::is_arithmetic_v<M> || (::std::is_integral_v<M> && !::std::is_same_v<M, bool>), "If M is a built-in arithmetic type, it must be integral except for bool.");
      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>, const M, const M&>;

    public:
      using T = M;
      static T op(VR lhs, VR rhs) {
        return ::tools::gcd(lhs, rhs);
      }
      static T e() {
        return T(0);
      }
    };

    template <typename M, M E>
    struct update {
      static_assert(::std::is_integral_v<M>, "M must be a built-in integral type.");

      using T = M;
      static T op(const T lhs, const T rhs) {
        return lhs == E ? rhs : lhs;
      }
      static T e() {
        return E;
      }
    };
  }
}

#endif
