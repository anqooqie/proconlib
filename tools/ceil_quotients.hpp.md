---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_quotients.test.cpp
    title: tests/ceil_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ceil_quotients.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <tuple>\n#include <cassert>\n#include <limits>\n#line 1 \"tools/ceil.hpp\"\n\
    \n\n\n#include <type_traits>\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\
    \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N>\
    \ ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0))\
    \ || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 9 \"tools/ceil_quotients.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  ::std::vector<::std::tuple<T,\
    \ T, T>> ceil_quotients(const T A) {\n    assert(A >= 0);\n\n    ::std::vector<::std::tuple<T,\
    \ T, T>> res;\n    if (A == 0) {\n      res.emplace_back(1, ::std::numeric_limits<T>::max(),\
    \ 0);\n      return res;\n    }\n\n    T x;\n    for (x = 1; x * x < A; ++x) {\n\
    \      res.emplace_back(x, x + 1, ::tools::ceil(A, x));\n    }\n    for (T q =\
    \ ::tools::ceil(A, x); q > 1; --q) {\n      res.emplace_back((A - 1) / q + 1,\
    \ (A - 1) / (q - 1) + 1, q);\n    }\n    res.emplace_back(A, ::std::numeric_limits<T>::max(),\
    \ 1);\n\n    return res;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CEIL_QUOTIENTS_HPP\n#define TOOLS_CEIL_QUOTIENTS_HPP\n\n#include\
    \ <vector>\n#include <tuple>\n#include <cassert>\n#include <limits>\n#include\
    \ \"tools/ceil.hpp\"\n\nnamespace tools {\n  template <typename T>\n  ::std::vector<::std::tuple<T,\
    \ T, T>> ceil_quotients(const T A) {\n    assert(A >= 0);\n\n    ::std::vector<::std::tuple<T,\
    \ T, T>> res;\n    if (A == 0) {\n      res.emplace_back(1, ::std::numeric_limits<T>::max(),\
    \ 0);\n      return res;\n    }\n\n    T x;\n    for (x = 1; x * x < A; ++x) {\n\
    \      res.emplace_back(x, x + 1, ::tools::ceil(A, x));\n    }\n    for (T q =\
    \ ::tools::ceil(A, x); q > 1; --q) {\n      res.emplace_back((A - 1) / q + 1,\
    \ (A - 1) / (q - 1) + 1, q);\n    }\n    res.emplace_back(A, ::std::numeric_limits<T>::max(),\
    \ 1);\n\n    return res;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  isVerificationFile: false
  path: tools/ceil_quotients.hpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/ceil_quotients.test.cpp
documentation_of: tools/ceil_quotients.hpp
layout: document
title: Enumerate the range of $\left\lceil \frac{A}{x} \right\rceil$
---

```cpp
template <typename T>
std::vector<std::tuple<T, T, T>> ceil_quotients(T A);
```

It returns the tuples such that the $i$-th tuple $(l_i, r_i, q_i)$ satisfies $l_i \leq x < r_i \Rightarrow \left\lceil \frac{A}{x} \right\rceil = q_i$, in ascending order of $l_i$.
The last tuple would be

$$\begin{align*}
\left\{\begin{array}{ll}
(A, \infty, 1) & \text{(if $A > 0$)}\\
(1, \infty, 0) & \text{(if $A = 0$)}
\end{array}\right.&
\end{align*}$$

mathematically, but it actually returns `std::numeric_limits<T>::max()` instead of $\infty$ since a integral type `<T>` cannot represent infinity.

## Constraints
- `<T>` is a built-in integral type.
- $A \geq 0$

## Time Complexity
- $O(\sqrt{A})$

## License
- CC0

## Author
- anqooqie
