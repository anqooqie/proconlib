---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/extended_garner.hpp
    title: Extended Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extended_garner.test.cpp
    title: tests/extended_garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/drken/items/ae02240cd1f8edfc86fd
  bundledCode: "#line 1 \"tools/garner.hpp\"\n\n\n\n#include <utility>\n#include <cstdint>\n\
    #include <vector>\n#include <cstddef>\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const M\
    \ lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/inv_mod.hpp\"\n\n\n\n#include\
    \ <cassert>\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#line 6 \"\
    tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T,\
    \ T, T> extgcd(T prev_r, T r) {\n    T prev_s = 1;\n    T prev_t = 0;\n    T s\
    \ = 0;\n    T t = 1;\n    while (r != 0) {\n      const T q = ::tools::quo(prev_r,\
    \ r);\n      const T next_r = prev_r - q * r;\n      prev_r = r;\n      r = next_r;\n\
    \      const T next_s = prev_s - q * s;\n      prev_s = s;\n      s = next_s;\n\
    \      const T next_t = prev_t - q * t;\n      prev_t = t;\n      t = next_t;\n\
    \    }\n\n    if (prev_r < T(0)) prev_r = -prev_r;\n    return {prev_s, prev_t,\
    \ prev_r};\n  }\n}\n\n\n#line 7 \"tools/inv_mod.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename T1, typename T2>\n  constexpr T2 inv_mod(const T1 x, const\
    \ T2 m) {\n    const auto [x0, y0, gcd] = ::tools::extgcd(x, m);\n    assert(gcd\
    \ == 1);\n    return ::tools::mod(x0, m);\n  }\n}\n\n\n#line 10 \"tools/garner.hpp\"\
    \n\n// Source: https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n// License:\
    \ unknown\n// Author: drken\n\nnamespace tools {\n\n  template <typename Iterator,\
    \ typename ModType>\n  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t> garner(const\
    \ Iterator& begin, const Iterator& end, const ModType& mod) {\n    ::std::vector<::std::int_fast64_t>\
    \ b, m;\n    for (auto it = begin; it != end; ++it) {\n      b.push_back(::tools::mod(it->first,\
    \ it->second));\n      m.push_back(it->second);\n    }\n\n    ::std::int_fast64_t\
    \ lcm = 1;\n    for (::std::size_t i = 0; i < b.size(); ++i) {\n      (lcm *=\
    \ m[i]) %= mod;\n    }\n\n    m.push_back(mod);\n    ::std::vector<::std::int_fast64_t>\
    \ coeffs(m.size(), 1);\n    ::std::vector<::std::int_fast64_t> constants(m.size(),\
    \ 0);\n    for (::std::size_t k = 0; k < b.size(); ++k) {\n      ::std::int_fast64_t\
    \ t = ::tools::mod((b[k] - constants[k]) * ::tools::inv_mod(coeffs[k], m[k]),\
    \ m[k]);\n      for (::std::size_t i = k + 1; i < m.size(); ++i) {\n        (constants[i]\
    \ += t * coeffs[i]) %= m[i];\n        (coeffs[i] *= m[k]) %= m[i];\n      }\n\
    \    }\n\n    return ::std::make_pair(constants.back(), lcm);\n  }\n\n  template\
    \ <typename M, typename Iterator>\n  ::std::pair<M, M> garner(const Iterator&\
    \ begin, const Iterator& end) {\n    const auto [y, z] = ::tools::garner(begin,\
    \ end, M::mod());\n    return ::std::make_pair(M::raw(y), M::raw(z));\n  }\n}\n\
    \n\n"
  code: "#ifndef TOOLS_GARNER_HPP\n#define TOOLS_GARNER_HPP\n\n#include <utility>\n\
    #include <cstdint>\n#include <vector>\n#include <cstddef>\n#include \"tools/mod.hpp\"\
    \n#include \"tools/inv_mod.hpp\"\n\n// Source: https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n\
    // License: unknown\n// Author: drken\n\nnamespace tools {\n\n  template <typename\
    \ Iterator, typename ModType>\n  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t>\
    \ garner(const Iterator& begin, const Iterator& end, const ModType& mod) {\n \
    \   ::std::vector<::std::int_fast64_t> b, m;\n    for (auto it = begin; it !=\
    \ end; ++it) {\n      b.push_back(::tools::mod(it->first, it->second));\n    \
    \  m.push_back(it->second);\n    }\n\n    ::std::int_fast64_t lcm = 1;\n    for\
    \ (::std::size_t i = 0; i < b.size(); ++i) {\n      (lcm *= m[i]) %= mod;\n  \
    \  }\n\n    m.push_back(mod);\n    ::std::vector<::std::int_fast64_t> coeffs(m.size(),\
    \ 1);\n    ::std::vector<::std::int_fast64_t> constants(m.size(), 0);\n    for\
    \ (::std::size_t k = 0; k < b.size(); ++k) {\n      ::std::int_fast64_t t = ::tools::mod((b[k]\
    \ - constants[k]) * ::tools::inv_mod(coeffs[k], m[k]), m[k]);\n      for (::std::size_t\
    \ i = k + 1; i < m.size(); ++i) {\n        (constants[i] += t * coeffs[i]) %=\
    \ m[i];\n        (coeffs[i] *= m[k]) %= m[i];\n      }\n    }\n\n    return ::std::make_pair(constants.back(),\
    \ lcm);\n  }\n\n  template <typename M, typename Iterator>\n  ::std::pair<M, M>\
    \ garner(const Iterator& begin, const Iterator& end) {\n    const auto [y, z]\
    \ = ::tools::garner(begin, end, M::mod());\n    return ::std::make_pair(M::raw(y),\
    \ M::raw(z));\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  isVerificationFile: false
  path: tools/garner.hpp
  requiredBy:
  - tools/extended_lucas.hpp
  - tools/extended_garner.hpp
  - tools/tetration_mod.hpp
  timestamp: '2021-08-22 01:33:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/extended_garner.test.cpp
  - tests/extended_lucas.test.cpp
  - tests/tetration_mod.test.cpp
documentation_of: tools/garner.hpp
layout: document
title: Garner's algorithm
---

```cpp
template <typename Iterator, typename ModType>
std::pair<std::int_fast64_t, std::int_fast64_t> garner(Iterator begin, Iterator end, ModType M);

template <typename M, typename Iterator>
std::pair<M, M> garner(Iterator begin, Iterator end);
```

Given an array of the pairs $(r_i, m_i)$ with length $n$, it solves the modular equation system

$$\begin{align*}
x \equiv r_i \pmod{m_i}, \forall i \in \{0, 1, \ldots, n - 1\}
\end{align*}$$

It requires $\forall i \in \\{0, 1, \ldots, n - 1\\}. \forall j \in \\{0, 1, \ldots, i - 1\\}. \gcd(m_i, m_j) = 1$.
Under the condition, all the solutions can be written as the form $x \equiv y \pmod{z}$, using integers $y, z \, (0 \leq y < z = \mathrm{lcm}(m_i))$.
It returns this $(y \pmod{m}, z \pmod{m})$ as a pair.
If $n = 0$, it returns $(0, 1)$.

## References
- [中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ - Qiita](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)

## Constraints
- $m_i \geq 1$
- $M \geq 1$
- $\forall i \in \\{0, 1, \ldots, n - 1\\}. \forall j \in \\{0, 1, \ldots, i - 1\\}. \gcd(m_i, m_j) = 1$

## Time Complexity
- $O(n (n + \log(\min(m_i))))$

## License
- unknown

## Author
- drken