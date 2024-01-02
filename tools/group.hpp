#ifndef TOOLS_GROUP_HPP
#define TOOLS_GROUP_HPP

namespace tools {
  namespace group {
    template <typename G>
    struct plus {
      using T = G;
      static T op(const T& lhs, const T& rhs) {
        return lhs + rhs;
      }
      static T e() {
        return T(0);
      }
      static T inv(const T& v) {
        return -v;
      }
    };

    template <typename G>
    struct multiplies {
      using T = G;
      static T op(const T& lhs, const T& rhs) {
        return lhs * rhs;
      }
      static T e() {
        return T(1);
      }
      static T inv(const T& v) {
        return e() / v;
      }
    };

    template <typename G>
    struct bit_xor {
      using T = G;
      static T op(const T& lhs, const T& rhs) {
        return lhs ^ rhs;
      }
      static T e() {
        return T(0);
      }
      static T inv(const T& v) {
        return v;
      }
    };
  }
}

#endif
