---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
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
  bundledCode: "#line 1 \"tools/square.hpp\"\n\n\n\n#line 1 \"tools/monoid.hpp\"\n\
    \n\n\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\nnamespace\
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
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line 5 \"tools/square.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M>\n  typename M::T square(const\
    \ typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n\
    \  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_SQUARE_HPP\n#define TOOLS_SQUARE_HPP\n\n#include \"tools/monoid.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M>\n  typename M::T square(const\
    \ typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n\
    \  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n#endif\n"
  dependsOn:
  - tools/monoid.hpp
  isVerificationFile: false
  path: tools/square.hpp
  requiredBy:
  - tools/pow.hpp
  - tools/tetration_mod.hpp
  - tools/totient.hpp
  timestamp: '2021-06-27 14:42:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/totient.test.cpp
  - tests/tetration_mod.test.cpp
documentation_of: tools/square.hpp
layout: document
title: $x^2$ under a given monoid
---

```cpp
template <typename M>
typename M::T square(typename M::T x);

template <typename T>
T square(T x);
```

It returns $x^2$ under a given monoid.
The default monoid is $(\mathbb{Z}, \times)$.

## License
- CC0

## Author
- anqooqie
