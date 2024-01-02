---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/cast_to_long_long.test.cpp
    title: tests/bigdecimal/cast_to_long_long.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/cartesian_tree/interval.test.cpp
    title: tests/cartesian_tree/interval.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/cumsum2d.test.cpp
    title: tests/cumsum2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/cumsum2d.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <iterator>\n#include <algorithm>\n#include <cassert>\n\n\
    namespace tools {\n\n  template <typename G>\n  class cumsum2d {\n  private:\n\
    \    using T = typename G::T;\n    ::std::size_t height;\n    ::std::size_t width;\n\
    \    ::std::vector<T> preprocessed;\n\n  public:\n    template <typename Range>\n\
    \    explicit cumsum2d(const Range& range) {\n      const auto begin = ::std::begin(range);\n\
    \      const auto end = ::std::end(range);\n      this->height = ::std::distance(begin,\
    \ end);\n      this->width = this->height == 0 ? 0 : ::std::distance(::std::begin(*begin),\
    \ ::std::end(*begin));\n      this->preprocessed.reserve((this->height + 1) *\
    \ (this->width + 1));\n      ::std::fill_n(::std::back_inserter(this->preprocessed),\
    \ (this->height + 1) * (this->width + 1), G::e());\n\n      {\n        auto it1\
    \ = begin;\n        for (::std::size_t y = 0; y < this->height; ++y, ++it1) {\n\
    \          auto it2 = ::std::begin(*it1);\n          for (::std::size_t x = 0;\
    \ x < this->width; ++x, ++it2) {\n            this->preprocessed[(y + 1) * (this->width\
    \ + 1) + (x + 1)] = G::op(this->preprocessed[(y + 1) * (this->width + 1) + x],\
    \ *it2);\n          }\n        }\n      }\n      for (::std::size_t x = 0; x <\
    \ this->width; ++x) {\n        for (::std::size_t y = 0; y < this->height; ++y)\
    \ {\n          this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)] = G::op(this->preprocessed[y\
    \ * (this->width + 1) + (x + 1)], this->preprocessed[(y + 1) * (this->width +\
    \ 1) + (x + 1)]);\n        }\n      }\n    }\n\n    T query(const ::std::size_t\
    \ y1, const ::std::size_t y2, const ::std::size_t x1, const ::std::size_t x2)\
    \ const {\n      assert(y1 <= y2 && y2 <= this->height);\n      assert(x1 <= x2\
    \ && x2 <= this->width);\n      return G::op(\n        G::op(\n          G::op(\n\
    \            this->preprocessed[y2 * (this->width + 1) + x2],\n            G::inv(this->preprocessed[y2\
    \ * (this->width + 1) + x1])\n          ),\n          G::inv(this->preprocessed[y1\
    \ * (this->width + 1) + x2])\n        ),\n        this->preprocessed[y1 * (this->width\
    \ + 1) + x1]\n      );\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_CUMSUM2D_HPP\n#define TOOLS_CUMSUM2D_HPP\n\n#include <cstddef>\n\
    #include <vector>\n#include <iterator>\n#include <algorithm>\n#include <cassert>\n\
    \nnamespace tools {\n\n  template <typename G>\n  class cumsum2d {\n  private:\n\
    \    using T = typename G::T;\n    ::std::size_t height;\n    ::std::size_t width;\n\
    \    ::std::vector<T> preprocessed;\n\n  public:\n    template <typename Range>\n\
    \    explicit cumsum2d(const Range& range) {\n      const auto begin = ::std::begin(range);\n\
    \      const auto end = ::std::end(range);\n      this->height = ::std::distance(begin,\
    \ end);\n      this->width = this->height == 0 ? 0 : ::std::distance(::std::begin(*begin),\
    \ ::std::end(*begin));\n      this->preprocessed.reserve((this->height + 1) *\
    \ (this->width + 1));\n      ::std::fill_n(::std::back_inserter(this->preprocessed),\
    \ (this->height + 1) * (this->width + 1), G::e());\n\n      {\n        auto it1\
    \ = begin;\n        for (::std::size_t y = 0; y < this->height; ++y, ++it1) {\n\
    \          auto it2 = ::std::begin(*it1);\n          for (::std::size_t x = 0;\
    \ x < this->width; ++x, ++it2) {\n            this->preprocessed[(y + 1) * (this->width\
    \ + 1) + (x + 1)] = G::op(this->preprocessed[(y + 1) * (this->width + 1) + x],\
    \ *it2);\n          }\n        }\n      }\n      for (::std::size_t x = 0; x <\
    \ this->width; ++x) {\n        for (::std::size_t y = 0; y < this->height; ++y)\
    \ {\n          this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)] = G::op(this->preprocessed[y\
    \ * (this->width + 1) + (x + 1)], this->preprocessed[(y + 1) * (this->width +\
    \ 1) + (x + 1)]);\n        }\n      }\n    }\n\n    T query(const ::std::size_t\
    \ y1, const ::std::size_t y2, const ::std::size_t x1, const ::std::size_t x2)\
    \ const {\n      assert(y1 <= y2 && y2 <= this->height);\n      assert(x1 <= x2\
    \ && x2 <= this->width);\n      return G::op(\n        G::op(\n          G::op(\n\
    \            this->preprocessed[y2 * (this->width + 1) + x2],\n            G::inv(this->preprocessed[y2\
    \ * (this->width + 1) + x1])\n          ),\n          G::inv(this->preprocessed[y1\
    \ * (this->width + 1) + x2])\n        ),\n        this->preprocessed[y1 * (this->width\
    \ + 1) + x1]\n      );\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cumsum2d.hpp
  requiredBy: []
  timestamp: '2021-12-18 13:17:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cumsum2d.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/cartesian_tree/interval.test.cpp
documentation_of: tools/cumsum2d.hpp
layout: document
title: 2D cumulative sum
---

It is a data structure which can return $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$ for given $r_1, r_2, c_1, c_2$ in $\langle O(HW), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename Range>
cumsum2d<G> cumsum(Range A);
```

It constructs a data structure which can return $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$ for a given $r_1, r_2, c_1, c_2$ in $\langle O(HW), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### Constraints
- `std::begin(range)` and `std::end(range)` are compilable and has the same type.
- `std::begin(*std::begin(range))` and `std::end(*std::begin(range))` are compilable and has the same type.
- The type of `*std::begin(*std::begin(range))` is `typename G::T`.
- For all $a$ in `typename G::T`, $b$ in `typename G::T` and $c$ in `typename G::T`, `G::op(G::op(a, b), c)` $=$ `G::op(a, G::op(b, c))`.
- For all $a$ in `typename G::T`, `G::op(G::e(), a)` $=$ `G::op(a, G::e())` $=$ `a`.
- For all $a$ in `typename G::T`, `G::op(G::inv(a), a)` $=$ `G::op(a, G::inv(a))` $=$ `G::e()`.

### Time Complexity
- $O(HW)$ where $H$ is the number of rows of $A$ and $W$ is the number of columns of $A$

## query
```cpp
typename G::T cumsum.query(std::size_t r1, std::size_t r2, std::size_t c1, std::size_t c2);
```

It returns $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$.

### Constraints
- $0 \leq r_1 \leq r_2 \leq H$
- $0 \leq c_1 \leq c_2 \leq W$

### Time Complexity
- $O(1)$
