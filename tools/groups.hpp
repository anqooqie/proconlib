#ifndef TOOLS_GROUPS_HPP
#define TOOLS_GROUPS_HPP

#include <cstddef>
#include <type_traits>
#include "tools/is_arithmetic.hpp"

namespace tools {
  namespace groups {
    template <typename G>
    class bit_xor {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<G> && sizeof(G) <= sizeof(::std::size_t), const G, const G&>;

    public:
      using T = G;
      static T op(VR x, VR y) {
        return x ^ y;
      }
      static T e() {
        return T(0);
      }
      static T inv(VR x) {
        return x;
      }
    };

    template <typename G>
    class multiplies {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<G> && sizeof(G) <= sizeof(::std::size_t), const G, const G&>;

    public:
      using T = G;
      static T op(VR x, VR y) {
        return x * y;
      }
      static T e() {
        return T(1);
      }
      static T inv(VR x) {
        return e() / x;
      }
    };

    template <typename G>
    class plus {
      using VR = ::std::conditional_t<::tools::is_arithmetic_v<G> && sizeof(G) <= sizeof(::std::size_t), const G, const G&>;

    public:
      using T = G;
      static T op(VR x, VR y) {
        return x + y;
      }
      static T e() {
        return T(0);
      }
      static T inv(VR x) {
        return -x;
      }
    };
  }
}

#endif
