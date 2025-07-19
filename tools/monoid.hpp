#ifndef TOOLS_MONOID_HPP
#define TOOLS_MONOID_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <limits>
#include <type_traits>
#include "tools/gcd.hpp"
#include "tools/is_arithmetic.hpp"
#include "tools/is_integral.hpp"

namespace tools {
  namespace monoid {
    template <typename M> requires (!::tools::is_arithmetic_v<M> || (::tools::is_integral_v<M> && !::std::is_same_v<M, bool>))
    class gcd {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<M> && sizeof(M) <= sizeof(::std::size_t), const M, const M&>;

    public:
      using T = M;
      static T op(VR x, VR y) {
        return ::tools::gcd(x, y);
      }
      static T e() {
        return T(0);
      }
    };

    template <typename M, M ...dummy>
    class max;

    template <typename M> requires (::tools::is_arithmetic_v<M>)
    class max<M> {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<M> && sizeof(M) <= sizeof(::std::size_t), const M, const M&>;

    public:
      using T = M;
      static T op(VR x, VR y) {
        return ::std::max(x, y);
      }
      static T e() {
        if constexpr (::tools::is_integral_v<M>) {
          return ::std::numeric_limits<M>::min();
        } else {
          return -::std::numeric_limits<M>::infinity();
        }
      }
    };

    template <typename M, M E>
    class max<M, E> {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<M> && sizeof(M) <= sizeof(::std::size_t), const M, const M&>;

    public:
      using T = M;
      static T op(VR x, VR y) {
        assert(E <= x);
        assert(E <= y);
        return ::std::max(x, y);
      }
      static T e() {
        return E;
      }
    };

    template <typename M, M ...dummy>
    class min;

    template <typename M> requires (::tools::is_arithmetic_v<M>)
    class min<M> {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<M> && sizeof(M) <= sizeof(::std::size_t), const M, const M&>;

    public:
      using T = M;
      static T op(VR x, VR y) {
        return ::std::min(x, y);
      }
      static T e() {
        if constexpr (::tools::is_integral_v<M>) {
          return ::std::numeric_limits<M>::max();
        } else {
          return ::std::numeric_limits<M>::infinity();
        }
      }
    };

    template <typename M, M E>
    class min<M, E> {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<M> && sizeof(M) <= sizeof(::std::size_t), const M, const M&>;

    public:
      using T = M;
      static T op(VR x, VR y) {
        assert(x <= E);
        assert(y <= E);
        return ::std::min(x, y);
      }
      static T e() {
        return E;
      }
    };

    template <typename M>
    class multiplies {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<M> && sizeof(M) <= sizeof(::std::size_t), const M, const M&>;

    public:
      using T = M;
      static T op(VR x, VR y) {
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
    class update {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<M> && sizeof(M) <= sizeof(::std::size_t), const M, const M&>;

    public:
      using T = M;
      static T op(VR x, VR y) {
        return x == E ? y : x;
      }
      static T e() {
        return E;
      }
    };
  }
}

#endif
