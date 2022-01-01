---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/rational.hpp
    title: tools/rational.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/signum.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  constexpr int signum(const T x) noexcept\
    \ {\n    if constexpr (::std::is_signed_v<T>) {\n      return (T(0) < x) - (x\
    \ < T(0));\n    } else {\n      return T(0) < x;\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SIGNUM_HPP\n#define TOOLS_SIGNUM_HPP\n\n#include <type_traits>\n\
    \nnamespace tools {\n\n  template <typename T>\n  constexpr int signum(const T\
    \ x) noexcept {\n    if constexpr (::std::is_signed_v<T>) {\n      return (T(0)\
    \ < x) - (x < T(0));\n    } else {\n      return T(0) < x;\n    }\n  }\n}\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/signum.hpp
  requiredBy:
  - tools/rational.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/signum.hpp
layout: document
title: Sign function
---

```cpp
template <typename T>
constexpr int signum(T x) noexcept;
```

It returns $-1$ if $x$ is negative, $1$ if $x$ is positive, $0$ if $x$ is zero.

## License
- CC0

## Author
- anqooqie
