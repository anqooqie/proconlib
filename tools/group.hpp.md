---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cumsum2d.test.cpp
    title: tests/cumsum2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace\
    \ group {\n    template <typename Type>\n    struct plus {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs + rhs;\n  \
    \    }\n      static T e() {\n        return T(0);\n      }\n      static T inv(const\
    \ T v) {\n        return -v;\n      }\n    };\n\n    template <typename Type>\n\
    \    struct bit_xor {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return lhs ^ rhs;\n      }\n      static T e() {\n       \
    \ return T(0);\n      }\n      static T inv(const T v) {\n        return v;\n\
    \      }\n    };\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_GROUP_HPP\n#define TOOLS_GROUP_HPP\n\nnamespace tools {\n \
    \ namespace group {\n    template <typename Type>\n    struct plus {\n      using\
    \ T = Type;\n      static T op(const T lhs, const T rhs) {\n        return lhs\
    \ + rhs;\n      }\n      static T e() {\n        return T(0);\n      }\n     \
    \ static T inv(const T v) {\n        return -v;\n      }\n    };\n\n    template\
    \ <typename Type>\n    struct bit_xor {\n      using T = Type;\n      static T\
    \ op(const T lhs, const T rhs) {\n        return lhs ^ rhs;\n      }\n      static\
    \ T e() {\n        return T(0);\n      }\n      static T inv(const T v) {\n  \
    \      return v;\n      }\n    };\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/group.hpp
  requiredBy: []
  timestamp: '2021-11-12 22:35:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cumsum2d.test.cpp
documentation_of: tools/group.hpp
layout: document
title: Typical groups
---

```cpp
namespace group {

  template <typename Type>
  struct plus {
    using T = Type;
    static T op(T x, T y);
    static T e();
    static T inv(T x);
  };

  template <typename Type>
  struct bit_xor {
    using T = Type;
    static T op(T x, T y);
    static T e();
    static T inv(T x);
  };
};
```

They are typical groups.

## License
- CC0

## Author
- anqooqie
