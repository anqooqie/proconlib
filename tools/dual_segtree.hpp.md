---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dual_segtree.test.cpp
    title: tests/dual_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dual_segtree.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <cstdint>\n\n// Source:\
    \ https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  inline std::uint32_t\
    \ ceil_log2(std::uint32_t x) {\n    static const ::std::uint32_t t[6] = {\n  \
    \    0xFFFF0000u,\n      0x0000FF00u,\n      0x000000F0u,\n      0x0000000Cu,\n\
    \      0x00000002u\n    };\n\n    ::std::uint32_t y = (((x & (x - 1)) == 0) ?\
    \ 0 : 1);\n    ::std::uint32_t j = 16;\n\n    for (const ::std::uint32_t& t_i\
    \ : t) {\n      ::std::uint32_t k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n\
    \      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::uint64_t\
    \ ceil_log2(::std::uint64_t x) {\n    static const ::std::uint64_t t[6] = {\n\
    \      0xFFFFFFFF00000000u,\n      0x00000000FFFF0000u,\n      0x000000000000FF00u,\n\
    \      0x00000000000000F0u,\n      0x000000000000000Cu,\n      0x0000000000000002u\n\
    \    };\n\n    ::std::uint64_t y = (((x & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint64_t\
    \ j = 32;\n\n    for (const ::std::uint64_t& t_i : t) {\n      ::std::uint64_t\
    \ k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n      x >>= k;\n      j >>=\
    \ 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::int32_t ceil_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t ceil_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 8 \"tools/dual_segtree.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M>\n  class dual_segtree {\n  private:\n\
    \    using T = typename M::T;\n    ::std::size_t height;\n    ::std::vector<T>\
    \ lazy;\n\n    void propagate(const ::std::size_t node_id) {\n      if(this->lazy[node_id]\
    \ == M::e()) return;\n      this->lazy[(node_id << 1) | 0] = M::op(this->lazy[node_id],\
    \ this->lazy[(node_id << 1) | 0]);\n      this->lazy[(node_id << 1) | 1] = M::op(this->lazy[node_id],\
    \ this->lazy[(node_id << 1) | 1]);\n      this->lazy[node_id] = M::e();\n    }\n\
    \n    void thrust(const ::std::size_t node_id) {\n      for (::std::size_t h =\
    \ this->height; h > 0; --h) {\n        this->propagate(node_id >> h);\n      }\n\
    \    }\n\n    ::std::size_t capacity() const {\n      return this->lazy.size()\
    \ / 2;\n    }\n\n  public:\n    dual_segtree(const ::std::size_t& n) :\n     \
    \ height(::tools::ceil_log2(n)),\n      lazy(::tools::pow2(this->height + 1),\
    \ M::e()) {\n    }\n\n    void apply(const ::std::size_t a, const ::std::size_t\
    \ b, const T& x) {\n      if(a >= b) return;\n\n      const ::std::size_t a_id\
    \ = a + this->capacity();\n      const ::std::size_t b_id = b + this->capacity()\
    \ - 1;\n\n      this->thrust(a_id);\n      this->thrust(b_id);\n\n      for (::std::size_t\
    \ l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {\n        if (l & 1) {\n \
    \         this->lazy[l] = M::op(x, this->lazy[l]);\n          ++l;\n        }\n\
    \        if (r & 1) {\n          --r;\n          this->lazy[r] = M::op(x, this->lazy[r]);\n\
    \        }\n      }\n    }\n\n    T get(const ::std::size_t a) {\n      const\
    \ ::std::size_t node_id = a + this->capacity();\n      this->thrust(node_id);\n\
    \      return this->lazy[node_id];\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DUAL_SEGTREE_HPP\n#define TOOLS_DUAL_SEGTREE_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include \"tools/ceil_log2.hpp\"\n#include \"\
    tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename M>\n  class dual_segtree\
    \ {\n  private:\n    using T = typename M::T;\n    ::std::size_t height;\n   \
    \ ::std::vector<T> lazy;\n\n    void propagate(const ::std::size_t node_id) {\n\
    \      if(this->lazy[node_id] == M::e()) return;\n      this->lazy[(node_id <<\
    \ 1) | 0] = M::op(this->lazy[node_id], this->lazy[(node_id << 1) | 0]);\n    \
    \  this->lazy[(node_id << 1) | 1] = M::op(this->lazy[node_id], this->lazy[(node_id\
    \ << 1) | 1]);\n      this->lazy[node_id] = M::e();\n    }\n\n    void thrust(const\
    \ ::std::size_t node_id) {\n      for (::std::size_t h = this->height; h > 0;\
    \ --h) {\n        this->propagate(node_id >> h);\n      }\n    }\n\n    ::std::size_t\
    \ capacity() const {\n      return this->lazy.size() / 2;\n    }\n\n  public:\n\
    \    dual_segtree(const ::std::size_t& n) :\n      height(::tools::ceil_log2(n)),\n\
    \      lazy(::tools::pow2(this->height + 1), M::e()) {\n    }\n\n    void apply(const\
    \ ::std::size_t a, const ::std::size_t b, const T& x) {\n      if(a >= b) return;\n\
    \n      const ::std::size_t a_id = a + this->capacity();\n      const ::std::size_t\
    \ b_id = b + this->capacity() - 1;\n\n      this->thrust(a_id);\n      this->thrust(b_id);\n\
    \n      for (::std::size_t l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {\n\
    \        if (l & 1) {\n          this->lazy[l] = M::op(x, this->lazy[l]);\n  \
    \        ++l;\n        }\n        if (r & 1) {\n          --r;\n          this->lazy[r]\
    \ = M::op(x, this->lazy[r]);\n        }\n      }\n    }\n\n    T get(const ::std::size_t\
    \ a) {\n      const ::std::size_t node_id = a + this->capacity();\n      this->thrust(node_id);\n\
    \      return this->lazy[node_id];\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/dual_segtree.hpp
  requiredBy: []
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dual_segtree.test.cpp
documentation_of: tools/dual_segtree.hpp
layout: document
title: Dual segment tree
---

It is a pair of a monoid $(S, \cdot, e)$ and a sequence $(a_0, a_1, \ldots, a_{n - 1})$ on $S$.
It provides the following operations.

- It can update $a_i$ to $x \cdot a_i$ for all $i$ such that $l \leq i < r$, in $O(\log n)$ time.
- It can access $a_i$ in $O(\log n)$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
dual_segtree<M> a(std::size_t n);
```

It creates a sequence $(a_0, a_1, \ldots, a_{n - 1})$ filled in `M::e()`.

### Constraints
- For all $x$ in `typename M::T`, $y$ in `typename M::T` and $z$ in `typename M::T`, `M::op(M::op(x, y), z)` $=$ `M::op(x, M::op(y, z))`.
- For all $x$ in `typename M::T`, `M::op(M::e(), x)` $=$ `M::op(x, M::e())` $=$ `x`.

### Time Complexity
- $O(n)$

## apply
```cpp
void a.apply(std::size_t l, std::size_t r, typename M::T x);
```

For all $i$ such that $l \leq i < r$, it updates $a_i$ to `M::op`$(x, a_i)$.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O(\log n)$

## get
```cpp
typename M::T a.get(std::size_t i);
```

It returns $a_i$.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(\log n)$
