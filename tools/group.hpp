#ifndef TOOLS_GROUP_HPP
#define TOOLS_GROUP_HPP

namespace tools {
  namespace group {
    template <typename Type>
    struct plus {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return lhs + rhs;
      }
      static T e() {
        return T(0);
      }
      static T inv(const T v) {
        return -v;
      }
    };

    template <typename Type>
    struct bit_xor {
      using T = Type;
      static T op(const T lhs, const T rhs) {
        return lhs ^ rhs;
      }
      static T e() {
        return T(0);
      }
      static T inv(const T v) {
        return v;
      }
    };
  }
}

#endif
