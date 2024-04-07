---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/greater_by.hpp
    title: std::greater by key
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/polynomial_product.test.cpp
    title: tests/polynomial_product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/polynomial_product.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <iterator>\n#include <vector>\n#include <queue>\n#include <utility>\n\
    #include <cstddef>\n#include <initializer_list>\n#line 1 \"tools/greater_by.hpp\"\
    \n\n\n\nnamespace tools {\n\n  template <class F>\n  class greater_by {\n  private:\n\
    \    F selector;\n\n  public:\n    greater_by(const F& selector) : selector(selector)\
    \ {\n    }\n\n    template <class T>\n    bool operator()(const T& x, const T&\
    \ y) const {\n      return selector(x) > selector(y);\n    }\n  };\n}\n\n\n#line\
    \ 12 \"tools/polynomial_product.hpp\"\n\nnamespace tools {\n  template <typename\
    \ RandomAccessIterator>\n  ::std::enable_if_t<\n    ::std::is_base_of_v<\n   \
    \   ::std::random_access_iterator_tag,\n      typename ::std::iterator_traits<RandomAccessIterator>::iterator_category\n\
    \    >,\n    typename ::std::iterator_traits<RandomAccessIterator>::value_type\n\
    \  > polynomial_product(const RandomAccessIterator begin, const RandomAccessIterator\
    \ end) {\n    using P = typename ::std::iterator_traits<RandomAccessIterator>::value_type;\n\
    \n    if (begin == end) return ++P{};\n\n    ::std::vector<P> cache;\n    const\
    \ auto get_polynomial = [&](const bool is_cache, const ::std::size_t i) -> const\
    \ P& { return is_cache ? cache[i] : begin[i]; };\n    const auto greater_by_size\
    \ = ::tools::greater_by([&](const auto& pair) { return get_polynomial(pair.first,\
    \ pair.second).size(); });\n    ::std::priority_queue<::std::pair<bool, ::std::size_t>,\
    \ ::std::vector<::std::pair<bool, ::std::size_t>>, decltype(greater_by_size)>\
    \ pq(greater_by_size);\n    for (auto it = begin; it != end; ++it) {\n      pq.emplace(false,\
    \ ::std::distance(begin, it));\n    }\n\n    while (pq.size() > 1) {\n      const\
    \ auto [p, i] = pq.top();\n      pq.pop();\n      const auto [q, j] = pq.top();\n\
    \      pq.pop();\n      cache.push_back(get_polynomial(p, i) * get_polynomial(q,\
    \ j));\n      pq.emplace(true, cache.size() - 1);\n    }\n\n    return get_polynomial(pq.top().first,\
    \ pq.top().second);\n  }\n\n  template <typename InputIterator>\n  ::std::enable_if_t<\n\
    \    !::std::is_base_of_v<\n      ::std::random_access_iterator_tag,\n      typename\
    \ ::std::iterator_traits<InputIterator>::iterator_category\n    >,\n    typename\
    \ ::std::iterator_traits<InputIterator>::value_type\n  > polynomial_product(const\
    \ InputIterator begin, const InputIterator end) {\n    using P = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    const ::std::vector<P> polynomials(begin, end);\n    return polynomial_product(polynomials.begin(),\
    \ polynomials.end());\n  }\n\n  template <typename P>\n  P polynomial_product(const\
    \ ::std::initializer_list<P> il) {\n    return polynomial_product(il.begin(),\
    \ il.end());\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_POLYNOMIAL_PRODUCT_HPP\n#define TOOLS_POLYNOMIAL_PRODUCT_HPP\n\
    \n#include <type_traits>\n#include <iterator>\n#include <vector>\n#include <queue>\n\
    #include <utility>\n#include <cstddef>\n#include <initializer_list>\n#include\
    \ \"tools/greater_by.hpp\"\n\nnamespace tools {\n  template <typename RandomAccessIterator>\n\
    \  ::std::enable_if_t<\n    ::std::is_base_of_v<\n      ::std::random_access_iterator_tag,\n\
    \      typename ::std::iterator_traits<RandomAccessIterator>::iterator_category\n\
    \    >,\n    typename ::std::iterator_traits<RandomAccessIterator>::value_type\n\
    \  > polynomial_product(const RandomAccessIterator begin, const RandomAccessIterator\
    \ end) {\n    using P = typename ::std::iterator_traits<RandomAccessIterator>::value_type;\n\
    \n    if (begin == end) return ++P{};\n\n    ::std::vector<P> cache;\n    const\
    \ auto get_polynomial = [&](const bool is_cache, const ::std::size_t i) -> const\
    \ P& { return is_cache ? cache[i] : begin[i]; };\n    const auto greater_by_size\
    \ = ::tools::greater_by([&](const auto& pair) { return get_polynomial(pair.first,\
    \ pair.second).size(); });\n    ::std::priority_queue<::std::pair<bool, ::std::size_t>,\
    \ ::std::vector<::std::pair<bool, ::std::size_t>>, decltype(greater_by_size)>\
    \ pq(greater_by_size);\n    for (auto it = begin; it != end; ++it) {\n      pq.emplace(false,\
    \ ::std::distance(begin, it));\n    }\n\n    while (pq.size() > 1) {\n      const\
    \ auto [p, i] = pq.top();\n      pq.pop();\n      const auto [q, j] = pq.top();\n\
    \      pq.pop();\n      cache.push_back(get_polynomial(p, i) * get_polynomial(q,\
    \ j));\n      pq.emplace(true, cache.size() - 1);\n    }\n\n    return get_polynomial(pq.top().first,\
    \ pq.top().second);\n  }\n\n  template <typename InputIterator>\n  ::std::enable_if_t<\n\
    \    !::std::is_base_of_v<\n      ::std::random_access_iterator_tag,\n      typename\
    \ ::std::iterator_traits<InputIterator>::iterator_category\n    >,\n    typename\
    \ ::std::iterator_traits<InputIterator>::value_type\n  > polynomial_product(const\
    \ InputIterator begin, const InputIterator end) {\n    using P = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    const ::std::vector<P> polynomials(begin, end);\n    return polynomial_product(polynomials.begin(),\
    \ polynomials.end());\n  }\n\n  template <typename P>\n  P polynomial_product(const\
    \ ::std::initializer_list<P> il) {\n    return polynomial_product(il.begin(),\
    \ il.end());\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/greater_by.hpp
  isVerificationFile: false
  path: tools/polynomial_product.hpp
  requiredBy: []
  timestamp: '2024-04-06 03:06:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/polynomial_product.test.cpp
documentation_of: tools/polynomial_product.hpp
layout: document
title: Product of polynomials
---

```cpp
(1)
template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type polynomial_product(InputIterator begin, InputIterator end);

(2)
template <typename P>
P polynomial_product(std::initializer_list<P> il);
```

Given $N$ polynomials $f_0(x), \cdots, f_{N - 1}(x)$, it returns $\prod_{i = 0}^{N - 1} f_i(x)$.
Note that it returns $1$ if $N = 0$.

### Constraints
- (1)
    - `typename std::iterator_traits<InputIterator>::value_type` is `tools::polynomial`.
- (2)
    - `P` is `tools::polynomial`.

### Time Complexity
- $O\left(D (\log D)^2\right)$ where $D$ is $\sum_{i = 0}^{N - 1} \mathrm{deg}(f_i)$

### License
- CC0

### Author
- anqooqie
