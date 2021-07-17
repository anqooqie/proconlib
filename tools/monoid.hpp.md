---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dual_segtree.test.cpp
    title: tests/dual_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid {\n  \
    \  template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n   \
    \ struct max {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>\n\
    \    struct min {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type>\n    struct\
    \ multiplies {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n        return\
    \ T(1);\n      }\n    };\n\n    template <typename Type>\n    struct gcd {\n \
    \     using T = Type;\n      static T op(const T lhs, const T rhs) {\n       \
    \ return ::std::gcd(lhs, rhs);\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n    };\n\n    template <typename Type, Type E>\n    struct update\
    \ {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n  \
    \      return lhs == E ? rhs : lhs;\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MONOID_HPP\n#define TOOLS_MONOID_HPP\n\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid\
    \ {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
    \    struct max {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::max()>\n    struct min {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::min(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type>\n    struct multiplies {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs * rhs;\n  \
    \    }\n      static T e() {\n        return T(1);\n      }\n    };\n\n    template\
    \ <typename Type>\n    struct gcd {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::gcd(lhs, rhs);\n      }\n     \
    \ static T e() {\n        return T(0);\n      }\n    };\n\n    template <typename\
    \ Type, Type E>\n    struct update {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n      }\n     \
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/monoid.hpp
  requiredBy:
  - tools/totient.hpp
  - tools/square.hpp
  - tools/pow.hpp
  timestamp: '2021-06-27 14:42:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/totient.test.cpp
  - tests/dual_segtree.test.cpp
documentation_of: tools/monoid.hpp
layout: document
title: Typical monoids
---

```cpp
namespace monoid {

  template <typename Type, Type E = std::numeric_limits<Type>::min()>
  struct max {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type, Type E = std::numeric_limits<Type>::max()>
  struct min {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type>
  struct multiplies {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type>
  struct gcd {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };

  template <typename Type, Type E>
  struct update {
    using T = Type;
    static T op(T x, T y);
    static T e();
  };
};
```

They are typical monoids.

## License
- CC0

## Author
- anqooqie
