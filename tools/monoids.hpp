#ifndef TOOLS_MONOIDS_HPP
#define TOOLS_MONOIDS_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <cstddef>
#include <limits>
#include <type_traits>
#include "tools/arithmetic.hpp"
#include "tools/gcd.hpp"
#include "tools/integral.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  namespace monoids {
    template <typename M>
    struct bit_and {
      using T = M;
      static T op(const T& x, const T& y) {
        return x & y;
      }
      static T e() {
        return std::numeric_limits<T>::max();
      }
    };

    template <typename M>
    struct bit_or {
      using T = M;
      static T op(const T& x, const T& y) {
        return x | y;
      }
      static T e() {
        return T(0);
      }
    };

    template <typename M>
    requires requires (M x, M y) {
      {tools::gcd(x, y)} -> std::convertible_to<M>;
    }
    struct gcd {
      using T = M;
      static T op(const T& x, const T& y) {
        return tools::gcd(x, y);
      }
      static T e() {
        return T(0);
      }
    };

    template <typename M, M ...dummy>
    struct max;

    template <tools::arithmetic M>
    struct max<M> {
      using T = M;
      static T op(const T& x, const T& y) {
        return std::max(x, y);
      }
      static T e() {
        if constexpr (tools::integral<M>) {
          return std::numeric_limits<M>::min();
        } else {
          return -std::numeric_limits<M>::infinity();
        }
      }
    };

    template <std::totally_ordered M, M E>
    struct max<M, E> {
      using T = M;
      static T op(const T& x, const T& y) {
        assert(E <= x);
        assert(E <= y);
        return std::max(x, y);
      }
      static T e() {
        return E;
      }
    };

    template <typename M, M ...dummy>
    struct min;

    template <tools::arithmetic M>
    struct min<M> {
      using T = M;
      static T op(const T& x, const T& y) {
        return std::min(x, y);
      }
      static T e() {
        if constexpr (tools::integral<M>) {
          return std::numeric_limits<M>::max();
        } else {
          return std::numeric_limits<M>::infinity();
        }
      }
    };

    template <std::totally_ordered M, M E>
    struct min<M, E> {
      using T = M;
      static T op(const T& x, const T& y) {
        assert(x <= E);
        assert(y <= E);
        return std::min(x, y);
      }
      static T e() {
        return E;
      }
    };

    template <typename M>
    struct multiplies {
      using T = M;
      static T op(const T& x, const T& y) {
        return x * y;
      }
      static T e() {
        return T(1);
      }
    };

    template <>
    struct multiplies<bool> {
      using T = bool;
      static T op(const bool x, const bool y) {
        return x && y;
      }
      static T e() {
        return true;
      }
    };

    template <typename M, M E>
    struct update {
      using T = M;
      static T op(const T& x, const T& y) {
        return x == E ? y : x;
      }
      static T e() {
        return E;
      }
    };
  }
}

#endif
