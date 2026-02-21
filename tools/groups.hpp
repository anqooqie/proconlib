#ifndef TOOLS_GROUPS_HPP
#define TOOLS_GROUPS_HPP

#include <cstddef>
#include <type_traits>
#include "tools/arithmetic.hpp"

namespace tools {
  namespace groups {
    template <typename G>
    struct bit_xor {
      using T = G;
      static T op(const T& x, const T& y) {
        return x ^ y;
      }
      static T e() {
        return T(0);
      }
      static T inv(const T& x) {
        return x;
      }
    };

    template <typename G>
    struct multiplies {
      using T = G;
      static T op(const T& x, const T& y) {
        return x * y;
      }
      static T e() {
        return T(1);
      }
      static T inv(const T& x) {
        return e() / x;
      }
    };

    template <typename G>
    struct plus {
      using T = G;
      static T op(const T& x, const T& y) {
        return x + y;
      }
      static T e() {
        return T(0);
      }
      static T inv(const T& x) {
        return -x;
      }
    };
  }
}

#endif
