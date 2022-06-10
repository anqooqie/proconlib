---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/rotate_left.test.cpp
    title: tests/rotate_left.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/rotate_left.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <limits>\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"\
    tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M\
    \ lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else\
    \ {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      }\
    \ else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\
    \n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n\
    \    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n   \
    \   return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs)\
    \ * rhs;\n    }\n  }\n}\n\n\n#line 7 \"tools/rotate_left.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename U>\n  constexpr T rotate_left(const T\
    \ x, const ::std::size_t n, U s) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    const T mask = (n == ::std::numeric_limits<T>::digits ? ::std::numeric_limits<T>::max()\
    \ : (T(1) << n) - 1);\n    assert(0 <= x && x <= mask);\n    s = ::tools::mod(s,\
    \ n);\n    return ((x << s) | (x >> ((n - s) % n))) & mask;\n  }\n\n  template\
    \ <typename T, typename U>\n  T rotate_left(const T& x, U s) {\n    s = ::tools::mod(s,\
    \ x.size());\n    return (x << s) | (x >> ((x.size() - s) % x.size()));\n  }\n\
    }\n\n\n"
  code: "#ifndef TOOLS_ROTATE_LEFT_HPP\n#define TOOLS_ROTATE_LEFT_HPP\n\n#include\
    \ <cassert>\n#include <limits>\n#include \"tools/mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename U>\n  constexpr T rotate_left(const T\
    \ x, const ::std::size_t n, U s) {\n    assert(n <= ::std::numeric_limits<T>::digits);\n\
    \    const T mask = (n == ::std::numeric_limits<T>::digits ? ::std::numeric_limits<T>::max()\
    \ : (T(1) << n) - 1);\n    assert(0 <= x && x <= mask);\n    s = ::tools::mod(s,\
    \ n);\n    return ((x << s) | (x >> ((n - s) % n))) & mask;\n  }\n\n  template\
    \ <typename T, typename U>\n  T rotate_left(const T& x, U s) {\n    s = ::tools::mod(s,\
    \ x.size());\n    return (x << s) | (x >> ((x.size() - s) % x.size()));\n  }\n\
    }\n\n#endif\n"
  dependsOn:
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/rotate_left.hpp
  requiredBy: []
  timestamp: '2022-06-11 02:40:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/rotate_left.test.cpp
documentation_of: tools/rotate_left.hpp
layout: document
title: Circular shift to the left
---

```cpp
(1)
template <typename T, typename U>
T rotate_left(T x, std::size_t n, U s);

(2)
template <typename T, typename U>
T rotate_left(T x, U s);
```

- (1)
    - It returns $r$ which satisfies the followings.
        - $0 \leq r < 2^n$
        - For all $i$ such that $0 \leq i < n$, the $(((i + s) \bmod n) + 1)$-th least bit of $r$ is equal to the $(i + 1)$-th least bit of $x$.
- (2)
    - It returns $r$ which satisfies the followings.
        - `r.size() == x.size()`
        - Let $n$ be `x.size()`. For all $0 \leq i < n$, the $(((i + s) \bmod n) + 1)$-th least bit of $r$ is equal to the $(i + 1)$-th least bit of $x$.

## Constraints
- (1)
    - `<T>` is a built-in integral type
    - `<U>` is a built-in integral type
    - $n \leq$ `std::numeric_limits<T>::digits`
    - $0 \leq x < 2^n$
- (2)
    - `<T>` is `std::bitset` or `tools::dynamic_bitset`
    - `<U>` is a built-in integral type

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
