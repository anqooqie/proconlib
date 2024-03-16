---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':question:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/round.hpp\"\n\n\n\n#include <cstdlib>\n#line 1 \"\
    tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#include <cassert>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0))\
    \ || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\
    \n\n\n\n#line 6 \"tools/floor.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs >\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 1\
    \ \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const\
    \ M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs\
    \ >= M(0)) {\n      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n\
    \        return -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return\
    \ (-lhs - T(1) + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 8 \"tools/round.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  constexpr T round(const T\
    \ lhs, const T rhs) {\n    return ::std::abs(rhs) % 2 == 0\n      ? ::tools::mod(lhs,\
    \ rhs) == ::std::abs(rhs) / 2\n        ? ::tools::floor(lhs, rhs) % 2 == 0\n \
    \         ? ::tools::floor(lhs, rhs)\n          : ::tools::ceil(lhs, rhs)\n  \
    \      : ::tools::mod(lhs, rhs) < ::std::abs(rhs) / 2\n          ? ::tools::floor(lhs,\
    \ rhs)\n          : ::tools::ceil(lhs, rhs)\n      : ::tools::mod(lhs, rhs) <=\
    \ ::std::abs(rhs) / 2\n        ? ::tools::floor(lhs, rhs)\n        : ::tools::ceil(lhs,\
    \ rhs);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ROUND_HPP\n#define TOOLS_ROUND_HPP\n\n#include <cstdlib>\n\
    #include \"tools/ceil.hpp\"\n#include \"tools/floor.hpp\"\n#include \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  constexpr T round(const T\
    \ lhs, const T rhs) {\n    return ::std::abs(rhs) % 2 == 0\n      ? ::tools::mod(lhs,\
    \ rhs) == ::std::abs(rhs) / 2\n        ? ::tools::floor(lhs, rhs) % 2 == 0\n \
    \         ? ::tools::floor(lhs, rhs)\n          : ::tools::ceil(lhs, rhs)\n  \
    \      : ::tools::mod(lhs, rhs) < ::std::abs(rhs) / 2\n          ? ::tools::floor(lhs,\
    \ rhs)\n          : ::tools::ceil(lhs, rhs)\n      : ::tools::mod(lhs, rhs) <=\
    \ ::std::abs(rhs) / 2\n        ? ::tools::floor(lhs, rhs)\n        : ::tools::ceil(lhs,\
    \ rhs);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  - tools/floor.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/round.hpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/round.hpp
layout: document
title: Apply banker's rounding to $\frac{x}{y}$
---

```cpp
template <typename T>
T round(T x, T y);
```

It returns a rounded value of $\frac{x}{y}$ in the manner of banker's rounding.

## Constraints
- $y \neq 0$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
