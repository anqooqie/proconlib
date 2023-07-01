---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/golden_section_search.test.cpp
    title: tests/golden_section_search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/golden_section_search.hpp\"\n\n\n\n#include <utility>\n\
    #include <type_traits>\n#include <cassert>\n#include <cmath>\n#include <limits>\n\
    #include <array>\n#include <algorithm>\n\nnamespace tools {\n  template <typename\
    \ T, typename F>\n  auto golden_section_search(const T l, const T r, const F&\
    \ f, const bool search_maximum) -> ::std::pair<T, ::std::decay_t<decltype(f(::std::declval<T>()))>>\
    \ {\n    assert(l <= r);\n\n    using V = ::std::decay_t<decltype(f(::std::declval<T>()))>;\n\
    \    const auto comp = [&](const V x, const V y) { return search_maximum ? x <\
    \ y : x > y; };\n    const T phi = (::std::sqrt(T(5)) + T(1)) / T(2);\n    const\
    \ T phi_inv = (::std::sqrt(T(5)) - T(1)) / T(2);\n    const int loop_count = static_cast<int>(::std::ceil(::std::numeric_limits<T>::digits\
    \ / ::std::log2(phi))) - 2;\n\n    ::std::array<::std::pair<T, V>, 4> search;\n\
    \    search[0] = ::std::make_pair(l, f(l));\n    search[3] = ::std::make_pair(r,\
    \ f(r));\n    T resolution = (r - l) * phi_inv;\n    search[2] = ::std::make_pair(l\
    \ + resolution, f(l + resolution));\n    resolution *= phi_inv;\n    search[1]\
    \ = ::std::make_pair(l + resolution, f(l + resolution));\n\n    for (int i = 0;\
    \ i < loop_count; ++i) {\n      if (comp(search[1].second, search[2].second))\
    \ {\n        search[0] = search[1];\n        search[1] = search[2];\n        resolution\
    \ *= phi_inv;\n        search[2] = ::std::make_pair(search[3].first - resolution,\
    \ f(search[3].first - resolution));\n      } else {\n        search[3] = search[2];\n\
    \        search[2] = search[1];\n        resolution *= phi_inv;\n        search[1]\
    \ = ::std::make_pair(search[0].first + resolution, f(search[0].first + resolution));\n\
    \      }\n    }\n\n    return *::std::max_element(search.begin(), search.end(),\
    \ [&](const auto& x, const auto& y) { return comp(x.second, y.second); });\n \
    \ }\n}\n\n\n"
  code: "#ifndef TOOLS_GOLDEN_SECTION_SEARCH_HPP\n#define TOOLS_GOLDEN_SECTION_SEARCH_HPP\n\
    \n#include <utility>\n#include <type_traits>\n#include <cassert>\n#include <cmath>\n\
    #include <limits>\n#include <array>\n#include <algorithm>\n\nnamespace tools {\n\
    \  template <typename T, typename F>\n  auto golden_section_search(const T l,\
    \ const T r, const F& f, const bool search_maximum) -> ::std::pair<T, ::std::decay_t<decltype(f(::std::declval<T>()))>>\
    \ {\n    assert(l <= r);\n\n    using V = ::std::decay_t<decltype(f(::std::declval<T>()))>;\n\
    \    const auto comp = [&](const V x, const V y) { return search_maximum ? x <\
    \ y : x > y; };\n    const T phi = (::std::sqrt(T(5)) + T(1)) / T(2);\n    const\
    \ T phi_inv = (::std::sqrt(T(5)) - T(1)) / T(2);\n    const int loop_count = static_cast<int>(::std::ceil(::std::numeric_limits<T>::digits\
    \ / ::std::log2(phi))) - 2;\n\n    ::std::array<::std::pair<T, V>, 4> search;\n\
    \    search[0] = ::std::make_pair(l, f(l));\n    search[3] = ::std::make_pair(r,\
    \ f(r));\n    T resolution = (r - l) * phi_inv;\n    search[2] = ::std::make_pair(l\
    \ + resolution, f(l + resolution));\n    resolution *= phi_inv;\n    search[1]\
    \ = ::std::make_pair(l + resolution, f(l + resolution));\n\n    for (int i = 0;\
    \ i < loop_count; ++i) {\n      if (comp(search[1].second, search[2].second))\
    \ {\n        search[0] = search[1];\n        search[1] = search[2];\n        resolution\
    \ *= phi_inv;\n        search[2] = ::std::make_pair(search[3].first - resolution,\
    \ f(search[3].first - resolution));\n      } else {\n        search[3] = search[2];\n\
    \        search[2] = search[1];\n        resolution *= phi_inv;\n        search[1]\
    \ = ::std::make_pair(search[0].first + resolution, f(search[0].first + resolution));\n\
    \      }\n    }\n\n    return *::std::max_element(search.begin(), search.end(),\
    \ [&](const auto& x, const auto& y) { return comp(x.second, y.second); });\n \
    \ }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/golden_section_search.hpp
  requiredBy: []
  timestamp: '2023-07-01 22:51:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/golden_section_search.test.cpp
documentation_of: tools/golden_section_search.hpp
layout: document
title: Golden section search
---

```cpp
template <typename T, typename F>
auto golden_section_search(T l, T r, F f, bool search_maximum) -> std::pair<T, std::decay_t<decltype(f(std::declval<T>()))>>;
```

It returns $(x, f(x))$ such that $f(x)$ is maximum or minimum in $l \leq x \leq r$.

### Constraints
- `<T>` is any one of `float`, `double` or `long double`.
- $l \leq r$
- If `search_maximum` is `true`, $\exists x. (\forall i. \forall j. l \leq i < j \leq x \Rightarrow f(i) < f(j)) \land (\forall i. \forall j. x \leq i < j \leq r \Rightarrow f(i) > f(j))$
- If `search_maximum` is `false`, $\exists x. (\forall i. \forall j. l \leq i < j \leq x \Rightarrow f(i) > f(j)) \land (\forall i. \forall j. x \leq i < j \leq r \Rightarrow f(i) < f(j))$

### Time Complexity
- It calls `f`, $\left( \left\lceil \frac{d}{\log_2 \frac{1 + \sqrt{5}}{2}} \right\rceil + 2 \right)$ times where $d$ is `std::numeric_limits<T>::digits`. (In most implementations, `float`: $37$ times / `double`: $79$ times / `long double`: $95$ times)

### License
- CC0

### Author
- anqooqie
