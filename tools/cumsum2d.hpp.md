---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':heavy_check_mark:'
    path: tools/is_group.hpp
    title: Check whether T is a group
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
  bundledCode: "#line 1 \"tools/cumsum2d.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n#include <vector>\n#include <iterator>\n#include <algorithm>\n#include\
    \ <cassert>\n#line 1 \"tools/is_group.hpp\"\n\n\n\n#line 5 \"tools/is_group.hpp\"\
    \n#include <utility>\n\nnamespace tools {\n\n  template <typename G, typename\
    \ = void>\n  struct is_group : ::std::false_type {};\n\n  template <typename G>\n\
    \  struct is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename G::T,\
    \ decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename G::T>()))>\
    \ &&\n    ::std::is_same_v<typename G::T, decltype(G::e())> &&\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::inv(::std::declval<typename G::T>()))>\n  , void>> : ::std::true_type\
    \ {};\n\n  template <typename G>\n  inline constexpr bool is_group_v = ::tools::is_group<G>::value;\n\
    }\n\n\n#line 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace group\
    \ {\n    template <typename G>\n    struct plus {\n      using T = G;\n      static\
    \ T op(const T& lhs, const T& rhs) {\n        return lhs + rhs;\n      }\n   \
    \   static T e() {\n        return T(0);\n      }\n      static T inv(const T&\
    \ v) {\n        return -v;\n      }\n    };\n\n    template <typename G>\n   \
    \ struct multiplies {\n      using T = G;\n      static T op(const T& lhs, const\
    \ T& rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n      \
    \  return T(1);\n      }\n      static T inv(const T& v) {\n        return e()\
    \ / v;\n      }\n    };\n\n    template <typename G>\n    struct bit_xor {\n \
    \     using T = G;\n      static T op(const T& lhs, const T& rhs) {\n        return\
    \ lhs ^ rhs;\n      }\n      static T e() {\n        return T(0);\n      }\n \
    \     static T inv(const T& v) {\n        return v;\n      }\n    };\n  }\n}\n\
    \n\n#line 12 \"tools/cumsum2d.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ X>\n  class cumsum2d {\n  private:\n    using G = ::std::conditional_t<::tools::is_group_v<X>,\
    \ X, tools::group::plus<X>>;\n    using T = typename G::T;\n    ::std::size_t\
    \ height;\n    ::std::size_t width;\n    ::std::vector<T> preprocessed;\n\n  public:\n\
    \    template <typename Range>\n    explicit cumsum2d(const Range& range) {\n\
    \      const auto begin = ::std::begin(range);\n      const auto end = ::std::end(range);\n\
    \      this->height = ::std::distance(begin, end);\n      this->width = this->height\
    \ == 0 ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin));\n    \
    \  this->preprocessed.reserve((this->height + 1) * (this->width + 1));\n     \
    \ ::std::fill_n(::std::back_inserter(this->preprocessed), (this->height + 1) *\
    \ (this->width + 1), G::e());\n\n      {\n        auto it1 = begin;\n        for\
    \ (::std::size_t y = 0; y < this->height; ++y, ++it1) {\n          auto it2 =\
    \ ::std::begin(*it1);\n          for (::std::size_t x = 0; x < this->width; ++x,\
    \ ++it2) {\n            this->preprocessed[(y + 1) * (this->width + 1) + (x +\
    \ 1)] = G::op(this->preprocessed[(y + 1) * (this->width + 1) + x], *it2);\n  \
    \        }\n        }\n      }\n      for (::std::size_t x = 0; x < this->width;\
    \ ++x) {\n        for (::std::size_t y = 0; y < this->height; ++y) {\n       \
    \   this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)] = G::op(this->preprocessed[y\
    \ * (this->width + 1) + (x + 1)], this->preprocessed[(y + 1) * (this->width +\
    \ 1) + (x + 1)]);\n        }\n      }\n    }\n\n    T query(const ::std::size_t\
    \ y1, const ::std::size_t y2, const ::std::size_t x1, const ::std::size_t x2)\
    \ const {\n      assert(y1 <= y2 && y2 <= this->height);\n      assert(x1 <= x2\
    \ && x2 <= this->width);\n      return G::op(\n        G::op(\n          G::op(\n\
    \            this->preprocessed[y2 * (this->width + 1) + x2],\n            G::inv(this->preprocessed[y2\
    \ * (this->width + 1) + x1])\n          ),\n          G::inv(this->preprocessed[y1\
    \ * (this->width + 1) + x2])\n        ),\n        this->preprocessed[y1 * (this->width\
    \ + 1) + x1]\n      );\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_CUMSUM2D_HPP\n#define TOOLS_CUMSUM2D_HPP\n\n#include <type_traits>\n\
    #include <cstddef>\n#include <vector>\n#include <iterator>\n#include <algorithm>\n\
    #include <cassert>\n#include \"tools/is_group.hpp\"\n#include \"tools/group.hpp\"\
    \n\nnamespace tools {\n\n  template <typename X>\n  class cumsum2d {\n  private:\n\
    \    using G = ::std::conditional_t<::tools::is_group_v<X>, X, tools::group::plus<X>>;\n\
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
  dependsOn:
  - tools/is_group.hpp
  - tools/group.hpp
  isVerificationFile: false
  path: tools/cumsum2d.hpp
  requiredBy: []
  timestamp: '2024-10-05 00:25:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/cartesian_tree/interval.test.cpp
  - tests/cumsum2d.test.cpp
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
(1)
template <typename Range>
cumsum2d<T> cumsum(Range A);

(2)
template <typename Range>
cumsum2d<G> cumsum(Range A);
```

- (1)
    - It is identical to `cumsum2d<tools::group::plus<T>> cumsum(A);`.
- (2)
    - It constructs a data structure which can return $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$ for a given $r_1, r_2, c_1, c_2$ in $\langle O(HW), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

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
