---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor_kth_root.hpp
    title: $\left\lfloor x^\frac{1}{k} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/lis.hpp
    title: Longest increasing subsequence
  - icon: ':warning:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_kth_root.test.cpp
    title: tests/ceil_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/disjoint_sparse_table.test.cpp
    title: tests/disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dual_segtree.test.cpp
    title: tests/dual_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_kth_root.test.cpp
    title: tests/floor_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lis.test.cpp
    title: tests/lis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
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
  - tools/square.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/ceil_kth_root.hpp
  - tools/lis.hpp
  - tools/floor_kth_root.hpp
  - tools/totient.hpp
  - tools/tetration_mod.hpp
  - tools/pow.hpp
  - tools/detail/rolling_hash.hpp
  - tools/rolling_hash.hpp
  timestamp: '2021-06-27 14:42:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/totient.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/dual_segtree.test.cpp
  - tests/permutation.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/ceil_kth_root.test.cpp
  - tests/disjoint_sparse_table.test.cpp
  - tests/lis.test.cpp
  - tests/floor_kth_root.test.cpp
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
