---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
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
  - icon: ':warning:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
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
    path: tests/floor_kth_root.test.cpp
    title: tests/floor_kth_root.test.cpp
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
  bundledCode: "#line 1 \"tools/pow.hpp\"\n\n\n\n#include <cstddef>\n#line 1 \"tools/monoid.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\nnamespace\
    \ tools {\n  namespace monoid {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
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
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\
    \n\n\n\n#line 5 \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T square(const typename M::T& x) {\n    return M::op(x, x);\n\
    \  }\n\n  template <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 7 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T pow(const typename M::T& base, const ::std::size_t& exponent)\
    \ {\n    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n   \
    \     ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T>\n  T pow(const T& base,\
    \ const ::std::size_t& exponent) {\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base,\
    \ exponent);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_POW_H\n#define TOOLS_POW_H\n\n#include <cstddef>\n#include\
    \ \"tools/monoid.hpp\"\n#include \"tools/square.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M>\n  typename M::T pow(const typename M::T& base, const\
    \ ::std::size_t& exponent) {\n    return exponent == 0\n      ? M::e()\n     \
    \ : exponent % 2 == 0\n        ? ::tools::square<M>(::tools::pow<M>(base, exponent\
    \ / 2))\n        : M::op(::tools::pow<M>(base, exponent - 1), base);\n  }\n\n\
    \  template <typename T>\n  T pow(const T& base, const ::std::size_t& exponent)\
    \ {\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);\n\
    \  }\n}\n\n#endif\n"
  dependsOn:
  - tools/monoid.hpp
  - tools/square.hpp
  isVerificationFile: false
  path: tools/pow.hpp
  requiredBy:
  - tools/detail/rolling_hash.hpp
  - tools/floor_kth_root.hpp
  - tools/ceil_kth_root.hpp
  - tools/tetration_mod.hpp
  - tools/rolling_hash.hpp
  - tools/totient.hpp
  - tools/modint_for_rolling_hash.hpp
  timestamp: '2021-06-27 14:42:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ceil_kth_root.test.cpp
  - tests/floor_kth_root.test.cpp
  - tests/totient.test.cpp
  - tests/permutation.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/tetration_mod.test.cpp
documentation_of: tools/pow.hpp
layout: document
title: $b^n$ under a given monoid
---

```cpp
template <typename M>
typename M::T pow(typename M::T b, std::size_t n);

template <typename T>
T pow(T b, ::std::size_t n);
```

It returns $b^n$ under a given monoid.
The default monoid is $(\mathbb{Z}, \times)$.

## License
- CC0

## Author
- anqooqie
