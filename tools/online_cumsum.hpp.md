---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':heavy_check_mark:'
    path: tools/is_group.hpp
    title: Check whether T is a group
  - icon: ':heavy_check_mark:'
    path: tools/is_monoid.hpp
    title: Check whether T is a monoid
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
  - icon: ':heavy_check_mark:'
    path: tools/sample_point_shift.hpp
    title: Shift of sampling points of polynomial
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/binomial.test.cpp
    title: tests/large_fact_mod_cache/binomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/fact.test.cpp
    title: tests/large_fact_mod_cache/fact.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/online_cumsum.test.cpp
    title: tests/online_cumsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sample_point_shift.test.cpp
    title: tests/sample_point_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/online_cumsum.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <cstddef>\n#include <cassert>\n#line 1 \"tools/is_monoid.hpp\"\
    \n\n\n\n#line 5 \"tools/is_monoid.hpp\"\n#include <utility>\n\nnamespace tools\
    \ {\n\n  template <typename M, typename = void>\n  struct is_monoid : ::std::false_type\
    \ {};\n\n  template <typename M>\n  struct is_monoid<M, ::std::enable_if_t<\n\
    \    ::std::is_same_v<typename M::T, decltype(M::op(::std::declval<typename M::T>(),\
    \ ::std::declval<typename M::T>()))> &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n\
    \  , void>> : ::std::true_type {};\n\n  template <typename M>\n  inline constexpr\
    \ bool is_monoid_v = ::tools::is_monoid<M>::value;\n}\n\n\n#line 1 \"tools/group.hpp\"\
    \n\n\n\nnamespace tools {\n  namespace group {\n    template <typename G>\n  \
    \  struct plus {\n      using T = G;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return lhs + rhs;\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n      static T inv(const T& v) {\n        return -v;\n     \
    \ }\n    };\n\n    template <typename G>\n    struct multiplies {\n      using\
    \ T = G;\n      static T op(const T& lhs, const T& rhs) {\n        return lhs\
    \ * rhs;\n      }\n      static T e() {\n        return T(1);\n      }\n     \
    \ static T inv(const T& v) {\n        return e() / v;\n      }\n    };\n\n   \
    \ template <typename G>\n    struct bit_xor {\n      using T = G;\n      static\
    \ T op(const T& lhs, const T& rhs) {\n        return lhs ^ rhs;\n      }\n   \
    \   static T e() {\n        return T(0);\n      }\n      static T inv(const T&\
    \ v) {\n        return v;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/is_group.hpp\"\
    \n\n\n\n#line 6 \"tools/is_group.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ G, typename = void>\n  struct is_group : ::std::false_type {};\n\n  template\
    \ <typename G>\n  struct is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename\
    \ G::T>()))> &&\n    ::std::is_same_v<typename G::T, decltype(G::e())> &&\n  \
    \  ::std::is_same_v<typename G::T, decltype(G::inv(::std::declval<typename G::T>()))>\n\
    \  , void>> : ::std::true_type {};\n\n  template <typename G>\n  inline constexpr\
    \ bool is_group_v = ::tools::is_group<G>::value;\n}\n\n\n#line 11 \"tools/online_cumsum.hpp\"\
    \n\nnamespace tools {\n  template <typename X, bool Forward = true>\n  class online_cumsum\
    \ {\n    using M = ::std::conditional_t<::tools::is_monoid_v<X>, X, ::tools::group::plus<X>>;\n\
    \    using T = typename M::T;\n    ::std::vector<T> m_vector;\n    ::std::vector<T>\
    \ m_cumsum;\n    ::std::size_t m_processed;\n\n  public:\n    online_cumsum()\
    \ : online_cumsum(0) {\n    }\n    online_cumsum(const ::std::size_t n) : m_vector(n,\
    \ M::e()), m_cumsum(n + 1, M::e()), m_processed(Forward ? 0 : n) {\n    }\n\n\
    \    ::std::size_t size() const {\n      return this->m_vector.size();\n    }\n\
    \    T& operator[](const ::std::size_t i) {\n      assert(i < this->size());\n\
    \      return this->m_vector[i];\n    }\n    T prod(const ::std::size_t l, const\
    \ ::std::size_t r) {\n      assert(l <= r && r <= this->size());\n      if constexpr\
    \ (Forward) {\n        for (; this->m_processed < r; ++this->m_processed) {\n\
    \          this->m_cumsum[this->m_processed + 1] = M::op(this->m_cumsum[this->m_processed],\
    \ this->m_vector[this->m_processed]);\n        }\n        if constexpr (::tools::is_group_v<M>)\
    \ {\n          return M::op(M::inv(this->m_cumsum[l]), this->m_cumsum[r]);\n \
    \       } else {\n          assert(l == 0);\n          return this->m_cumsum[r];\n\
    \        }\n      } else {\n        for (; this->m_processed > l; --this->m_processed)\
    \ {\n          this->m_cumsum[this->m_processed - 1] = M::op(this->m_vector[this->m_processed\
    \ - 1], this->m_cumsum[this->m_processed]);\n        }\n        if constexpr (::tools::is_group_v<M>)\
    \ {\n          return M::op(this->m_cumsum[l], M::inv(this->m_cumsum[r]));\n \
    \       } else {\n          assert(r == this->size());\n          return this->m_cumsum[l];\n\
    \        }\n      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_ONLINE_CUMSUM_HPP\n#define TOOLS_ONLINE_CUMSUM_HPP\n\n#include\
    \ <type_traits>\n#include <vector>\n#include <cstddef>\n#include <cassert>\n#include\
    \ \"tools/is_monoid.hpp\"\n#include \"tools/group.hpp\"\n#include \"tools/is_group.hpp\"\
    \n\nnamespace tools {\n  template <typename X, bool Forward = true>\n  class online_cumsum\
    \ {\n    using M = ::std::conditional_t<::tools::is_monoid_v<X>, X, ::tools::group::plus<X>>;\n\
    \    using T = typename M::T;\n    ::std::vector<T> m_vector;\n    ::std::vector<T>\
    \ m_cumsum;\n    ::std::size_t m_processed;\n\n  public:\n    online_cumsum()\
    \ : online_cumsum(0) {\n    }\n    online_cumsum(const ::std::size_t n) : m_vector(n,\
    \ M::e()), m_cumsum(n + 1, M::e()), m_processed(Forward ? 0 : n) {\n    }\n\n\
    \    ::std::size_t size() const {\n      return this->m_vector.size();\n    }\n\
    \    T& operator[](const ::std::size_t i) {\n      assert(i < this->size());\n\
    \      return this->m_vector[i];\n    }\n    T prod(const ::std::size_t l, const\
    \ ::std::size_t r) {\n      assert(l <= r && r <= this->size());\n      if constexpr\
    \ (Forward) {\n        for (; this->m_processed < r; ++this->m_processed) {\n\
    \          this->m_cumsum[this->m_processed + 1] = M::op(this->m_cumsum[this->m_processed],\
    \ this->m_vector[this->m_processed]);\n        }\n        if constexpr (::tools::is_group_v<M>)\
    \ {\n          return M::op(M::inv(this->m_cumsum[l]), this->m_cumsum[r]);\n \
    \       } else {\n          assert(l == 0);\n          return this->m_cumsum[r];\n\
    \        }\n      } else {\n        for (; this->m_processed > l; --this->m_processed)\
    \ {\n          this->m_cumsum[this->m_processed - 1] = M::op(this->m_vector[this->m_processed\
    \ - 1], this->m_cumsum[this->m_processed]);\n        }\n        if constexpr (::tools::is_group_v<M>)\
    \ {\n          return M::op(this->m_cumsum[l], M::inv(this->m_cumsum[r]));\n \
    \       } else {\n          assert(r == this->size());\n          return this->m_cumsum[l];\n\
    \        }\n      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/is_monoid.hpp
  - tools/group.hpp
  - tools/is_group.hpp
  isVerificationFile: false
  path: tools/online_cumsum.hpp
  requiredBy:
  - tools/sample_point_shift.hpp
  - tools/large_fact_mod_cache.hpp
  timestamp: '2024-03-24 22:45:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/online_cumsum.test.cpp
  - tests/sample_point_shift.test.cpp
  - tests/large_fact_mod_cache/binomial.test.cpp
  - tests/large_fact_mod_cache/fact.test.cpp
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
(1) online_cumsum<T, Forward = true> a(std::size_t n = 0);
(2) online_cumsum<M, Forward = true> a(std::size_t n = 0);
(3) online_cumsum<G, Forward = true> a(std::size_t n = 0);
```

- (1)
    - It is identical to `online_cumsum<tools::group::plus<T>, Forward> a(n);`
- (2)
    - Given a monoid `M`, it creates an array of type `typename M::T` and length $n$ filled with indeterminate values.
    - In $a$, multiplication is defined by `M`. In other words, $x \cdot y$ is defined by `M::op(x, y)` and the identity is defined by `M::e()`.
    - If `Forward` is `true`, you can set $a_i$ in the order $i = 0, 1, \cdots, {n - 1}$.
    - If `Forward` is `false`, you can set $a_i$ in the order $i = n - 1, n - 2, \cdots, 0$.
- (3)
    - Given a group `G`, it creates an array of type `typename G::T` and length $n$ filled with indeterminate values.
    - In $a$, multiplication is defined by `G`. In other words, $x \cdot y$ is defined by `G::op(x, y)`, the identity is defined by `G::e()` and $x^{-1}$ is defined by `G::inv(x)`.
    - If `Forward` is `true`, you can set $a_i$ in the order $i = 0, 1, \cdots, {n - 1}$.
    - If `Forward` is `false`, you can set $a_i$ in the order $i = n - 1, n - 2, \cdots, 0$.

### Constraints
- (1)
    - `tools::is_monoid_v<T>` does not hold.
- (2)
    - `tools::is_monoid_v<M>` holds, but `tools::is_group_v<M>` does not hold.
    - For all $x$ in `typename M::T`, $y$ in `typename M::T` and $z$ in `typename M::T`, `M::op(M::op(x, y), z)` $=$ `M::op(x, M::op(y, z))`.
    - For all $x$ in `typename M::T`, `M::op(M::e(), x)` $=$ `M::op(x, M::e())` $= x$.
- (3)
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
(see below) a.operator[](std::size_t i);
```

It returns the reference to $a_i$.

The return type is as follows.

- (`a` is constructed by the constructor (1)): `T&`
- (`a` is constructed by the constructor (2)): `typename M::T&`
- (`a` is constructed by the constructor (3)): `typename G::T&`

### Constraints
- (Read):
    - $0 \leq i < n$
    - $a_i$ is not indeterminate.
- (Write):
    - (`Forward` is `true`): $r^\ast \leq i < n$ where $r^\ast$ is the largest $r$ in `a.sum(l, r)` called so far or $0$ (if you have not called it so far).
    - (`Forward` is `false`): $0 \leq i < l^\ast$ where $l^\ast$ is the smallest $l$ in `a.sum(l, r)` called so far or $n$ (if you have not called it so far).

### Time Complexity
- $O(1)$

## prod
```cpp
(see below) a.prod(std::size_t l, std::size_t r);
```

It returns $a_l \cdot a_{l + 1} \cdot \cdots \cdot a_{r - 1}$.
Note that the multiplication is defined by the template parameter.

The return type is as follows.

- (`a` is constructed by the constructor (1)): `T`
- (`a` is constructed by the constructor (2)): `typename M::T`
- (`a` is constructed by the constructor (3)): `typename G::T`

### Constraints
- $0 \leq l \leq r \leq n$
- (`Forward` is `true`): For all $0 \leq i < r$, $a_i$ is not indeterminate.
- (`Forward` is `false`): For all $l \leq i < n$, $a_i$ is not indeterminate.
- (`a` is constructed by the constructor (2) and `Forward` is `true`): $l = 0$
- (`a` is constructed by the constructor (2) and `Forward` is `false`): $r = n$

### Time Complexity
- $O(1)$ amortized
