---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/range_of_digit_products.test.cpp
    title: tests/range_of_digit_products.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/range_of_digit_products.hpp\"\n\n\n\n#include <vector>\n\
    #include <cassert>\n#include <limits>\n#include <array>\n#include <algorithm>\n\
    #line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/ceil.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    assert(rhs != 0);\n    return lhs /\
    \ rhs + (((lhs > 0 && rhs > 0) || (lhs < 0 && rhs < 0)) && lhs % rhs);\n  }\n\
    }\n\n\n#line 10 \"tools/range_of_digit_products.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename T>\n  ::std::vector<T> range_of_digit_products(const T n)\
    \ {\n    assert(0 <= n && n <= ::std::numeric_limits<T>::digits10);\n\n    ::std::vector<T>\
    \ range;\n    if (n == 0) return range;\n    if (n > 1) range.push_back(0);\n\n\
    \    ::std::array<T, 5> left;\n    left[0] = n;\n    for (T a = 0, pow6 = 1; a\
    \ <= left[0]; ++a, pow6 *= 6) {\n      left[1] = left[0] - a;\n      for (T b\
    \ = 0, pow2 = 1; b <= 3 * left[1]; ++b, pow2 *= 2) {\n        left[2] = left[1]\
    \ - ::tools::ceil(b, 3);\n        for (T c = 0, pow3 = 1; c <= 2 * left[2]; ++c,\
    \ pow3 *= 3) {\n          left[3] = left[2] - ::tools::ceil(c, 2);\n         \
    \ for (T d = 0, pow5 = 1; d <= left[3]; ++d, pow5 *= 5) {\n            left[4]\
    \ = left[3] - d;\n            for (T e = 0, pow7 = 1; e <= left[4]; ++e, pow7\
    \ *= 7) {\n              range.push_back(pow6 * pow2 * pow3 * pow5 * pow7);\n\
    \            }\n          }\n        }\n      }\n    }\n\n    ::std::sort(range.begin(),\
    \ range.end());\n    range.erase(::std::unique(range.begin(), range.end()), range.end());\n\
    \n    return range;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_RANGE_OF_DIGIT_PRODUCTS_HPP\n#define TOOLS_RANGE_OF_DIGIT_PRODUCTS_HPP\n\
    \n#include <vector>\n#include <cassert>\n#include <limits>\n#include <array>\n\
    #include <algorithm>\n#include \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  ::std::vector<T> range_of_digit_products(const T n) {\n    assert(0\
    \ <= n && n <= ::std::numeric_limits<T>::digits10);\n\n    ::std::vector<T> range;\n\
    \    if (n == 0) return range;\n    if (n > 1) range.push_back(0);\n\n    ::std::array<T,\
    \ 5> left;\n    left[0] = n;\n    for (T a = 0, pow6 = 1; a <= left[0]; ++a, pow6\
    \ *= 6) {\n      left[1] = left[0] - a;\n      for (T b = 0, pow2 = 1; b <= 3\
    \ * left[1]; ++b, pow2 *= 2) {\n        left[2] = left[1] - ::tools::ceil(b, 3);\n\
    \        for (T c = 0, pow3 = 1; c <= 2 * left[2]; ++c, pow3 *= 3) {\n       \
    \   left[3] = left[2] - ::tools::ceil(c, 2);\n          for (T d = 0, pow5 = 1;\
    \ d <= left[3]; ++d, pow5 *= 5) {\n            left[4] = left[3] - d;\n      \
    \      for (T e = 0, pow7 = 1; e <= left[4]; ++e, pow7 *= 7) {\n             \
    \ range.push_back(pow6 * pow2 * pow3 * pow5 * pow7);\n            }\n        \
    \  }\n        }\n      }\n    }\n\n    ::std::sort(range.begin(), range.end());\n\
    \    range.erase(::std::unique(range.begin(), range.end()), range.end());\n\n\
    \    return range;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil.hpp
  isVerificationFile: false
  path: tools/range_of_digit_products.hpp
  requiredBy: []
  timestamp: '2022-07-02 14:04:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/range_of_digit_products.test.cpp
documentation_of: tools/range_of_digit_products.hpp
layout: document
title: Range of digit products
---

```cpp
template <typename T>
T range_of_digit_products(T n);
```

Let $f(x)$ be the product of the digits of $x$.
It returns $\\{y \in \mathbb{Z} \| \exists x \in \mathbb{Z}. (1 \leq x < 10^n \land f(x) = y) \\}$.

## Constraints
- $0 \leq n \leq$ `std::numeric_limits<T>::digits10`

## Time Complexity
- $O\left(n^5 \log n\right)$

## License
- CC0

## Author
- anqooqie
