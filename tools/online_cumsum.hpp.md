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
    path: tests/online_cumsum.test.cpp
    title: tests/online_cumsum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/online_cumsum.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <cstddef>\n#include <cassert>\n#line 1 \"tools/is_group.hpp\"\
    \n\n\n\n#line 5 \"tools/is_group.hpp\"\n#include <utility>\n\nnamespace tools\
    \ {\n\n  template <typename G, typename = void>\n  struct is_group : ::std::false_type\
    \ {};\n\n  template <typename G>\n  struct is_group<G, ::std::enable_if_t<\n \
    \   ::std::is_same_v<typename G::T, decltype(G::op(::std::declval<typename G::T>(),\
    \ ::std::declval<typename G::T>()))> &&\n    ::std::is_same_v<typename G::T, decltype(G::e())>\
    \ &&\n    ::std::is_same_v<typename G::T, decltype(G::inv(::std::declval<typename\
    \ G::T>()))>\n  , void>> : ::std::true_type {};\n\n  template <typename G>\n \
    \ inline constexpr bool is_group_v = ::tools::is_group<G>::value;\n}\n\n\n#line\
    \ 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace group {\n    template\
    \ <typename G>\n    struct plus {\n      using T = G;\n      static T op(const\
    \ T& lhs, const T& rhs) {\n        return lhs + rhs;\n      }\n      static T\
    \ e() {\n        return T(0);\n      }\n      static T inv(const T& v) {\n   \
    \     return -v;\n      }\n    };\n\n    template <typename G>\n    struct multiplies\
    \ {\n      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n      static T inv(const T& v) {\n        return e() / v;\n      }\n\
    \    };\n\n    template <typename G>\n    struct bit_xor {\n      using T = G;\n\
    \      static T op(const T& lhs, const T& rhs) {\n        return lhs ^ rhs;\n\
    \      }\n      static T e() {\n        return T(0);\n      }\n      static T\
    \ inv(const T& v) {\n        return v;\n      }\n    };\n  }\n}\n\n\n#line 10\
    \ \"tools/online_cumsum.hpp\"\n\nnamespace tools {\n  template <typename GT, bool\
    \ Forward = true>\n  class online_cumsum {\n    using G = ::std::conditional_t<::tools::is_group_v<GT>,\
    \ GT, ::tools::group::plus<GT>>;\n    using T = typename G::T;\n    ::std::vector<T>\
    \ m_vector;\n    ::std::vector<T> m_cumsum;\n    ::std::size_t m_processed;\n\n\
    \  public:\n    online_cumsum() : online_cumsum(0) {\n    }\n    online_cumsum(const\
    \ ::std::size_t n) : m_vector(n, G::e()), m_cumsum(n + 1, G::e()), m_processed(Forward\
    \ ? 0 : n) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_vector.size();\n\
    \    }\n    T& operator[](const ::std::size_t i) {\n      return this->m_vector[i];\n\
    \    }\n    T sum(const ::std::size_t l, const ::std::size_t r) {\n      assert(l\
    \ <= r && r <= this->size());\n      if constexpr (Forward) {\n        for (;\
    \ this->m_processed < r; ++this->m_processed) {\n          this->m_cumsum[this->m_processed\
    \ + 1] = G::op(this->m_cumsum[this->m_processed], this->m_vector[this->m_processed]);\n\
    \        }\n        return G::op(G::inv(this->m_cumsum[l]), this->m_cumsum[r]);\n\
    \      } else {\n        for (; this->m_processed > l; --this->m_processed) {\n\
    \          this->m_cumsum[this->m_processed - 1] = G::op(this->m_vector[this->m_processed\
    \ - 1], this->m_cumsum[this->m_processed]);\n        }\n        return G::op(this->m_cumsum[l],\
    \ G::inv(this->m_cumsum[r]));\n      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_ONLINE_CUMSUM_HPP\n#define TOOLS_ONLINE_CUMSUM_HPP\n\n#include\
    \ <type_traits>\n#include <vector>\n#include <cstddef>\n#include <cassert>\n#include\
    \ \"tools/is_group.hpp\"\n#include \"tools/group.hpp\"\n\nnamespace tools {\n\
    \  template <typename GT, bool Forward = true>\n  class online_cumsum {\n    using\
    \ G = ::std::conditional_t<::tools::is_group_v<GT>, GT, ::tools::group::plus<GT>>;\n\
    \    using T = typename G::T;\n    ::std::vector<T> m_vector;\n    ::std::vector<T>\
    \ m_cumsum;\n    ::std::size_t m_processed;\n\n  public:\n    online_cumsum()\
    \ : online_cumsum(0) {\n    }\n    online_cumsum(const ::std::size_t n) : m_vector(n,\
    \ G::e()), m_cumsum(n + 1, G::e()), m_processed(Forward ? 0 : n) {\n    }\n\n\
    \    ::std::size_t size() const {\n      return this->m_vector.size();\n    }\n\
    \    T& operator[](const ::std::size_t i) {\n      return this->m_vector[i];\n\
    \    }\n    T sum(const ::std::size_t l, const ::std::size_t r) {\n      assert(l\
    \ <= r && r <= this->size());\n      if constexpr (Forward) {\n        for (;\
    \ this->m_processed < r; ++this->m_processed) {\n          this->m_cumsum[this->m_processed\
    \ + 1] = G::op(this->m_cumsum[this->m_processed], this->m_vector[this->m_processed]);\n\
    \        }\n        return G::op(G::inv(this->m_cumsum[l]), this->m_cumsum[r]);\n\
    \      } else {\n        for (; this->m_processed > l; --this->m_processed) {\n\
    \          this->m_cumsum[this->m_processed - 1] = G::op(this->m_vector[this->m_processed\
    \ - 1], this->m_cumsum[this->m_processed]);\n        }\n        return G::op(this->m_cumsum[l],\
    \ G::inv(this->m_cumsum[r]));\n      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/is_group.hpp
  - tools/group.hpp
  isVerificationFile: false
  path: tools/online_cumsum.hpp
  requiredBy: []
  timestamp: '2024-03-23 15:55:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/online_cumsum.test.cpp
documentation_of: tools/online_cumsum.hpp
layout: document
title: Online cumulative sum
---

It is a cumulative sum, but allows you to construct it by online.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) online_cumsum<T, Forward = true> a();
(2) online_cumsum<T, Forward = true> a(std::size_t n);
(3) online_cumsum<G, Forward = true> a();
(4) online_cumsum<G, Forward = true> a(std::size_t n);
```

- (1)
    - It is identical to `online_cumsum<tools::group::plus<T>, Forward> a(0);`.
- (2)
    - It is identical to `online_cumsum<tools::group::plus<T>, Forward> a(n);`
- (3)
    - It is identical to `online_cumsum<G, Forward> a(0);`.
- (4)
    - It creates an array of type `typename G::T` and length $n$ filled with indeterminate values.
    - In $a$, addition is defined by `G`. In other words, $x + y$ is defined by `G::op(x, y)`, the additive identity is defined by `G::e()` and $-x$ is defined by `G::inv(x)`.
    - If `Forward` is `true`, you can set $a_i$ in the order $i = 0, 1, \cdots, {n - 1}$.
    - If `Forward` is `false`, you can set $a_i$ in the order $i = n - 1, n - 2, \cdots, 0$.

### Constraints
- (1), (2)
    - `tools::is_group_v<T>` does not hold.
- (3), (4)
    - `tools::is_group_v<G>` holds.
    - For all $x$ in `typename G::T`, $y$ in `typename G::T` and $z$ in `typename G::T`, `G::op(G::op(x, y), z)` $=$ `G::op(x, G::op(y, z))`.
    - For all $x$ in `typename G::T`, `G::op(G::e(), x)` $=$ `G::op(x, G::e())` $= x$.
    - For all $x$ in `typename G::T`, `G::op(G::inv(x), x)` $=$ `G::op(x, G::inv(x))` $=$ `G::e()`.

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t a.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
typename G::T& a.operator[](std::size_t i);
```

It returns the reference to $a_i$.

### Constraints
- (Read):
    - $0 \leq i < n$
    - $a_i$ is not indeterminate.
- (Write):
    - (`Forward` is `true`): $r^\ast \leq i < n$ where $r^\ast$ is the largest $r$ in `a.sum(l, r)` called so far or $0$ (if you have not called it so far).
    - (`Forward` is `false`): $0 \leq i < l^\ast$ where $l^\ast$ is the smallest $l$ in `a.sum(l, r)` called so far or $n$ (if you have not called it so far).

### Time Complexity
- $O(1)$

## sum
```cpp
typename G::T a.sum(std::size_t l, std::size_t r);
```

It returns $a_l + a_{l + 1} + \cdots + a_{r - 1}$.
Note that the addition is defined by `G`.

### Constraints
- $0 \leq l \leq r \leq n$
- (`Forward` is `true`): For all $0 \leq i < r$, $a_i$ is not indeterminate.
- (`Forward` is `false`): For all $l \leq i < n$, $a_i$ is not indeterminate.

### Time Complexity
- $O(1)$ amortized
