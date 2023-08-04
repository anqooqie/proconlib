---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':question:'
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
    \ <vector>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n#include <limits>\n#include <tuple>\n#include <array>\n#include <cstdint>\n\
    \n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  T ceil_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ceil_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      constexpr auto t = ::std::make_tuple(\n        ::std::array<::std::uint8_t,\
    \ 3>({\n          UINT8_C(0xf0),\n          UINT8_C(0x0c),\n          UINT8_C(0x02)\n\
    \        }),\n        ::std::array<::std::uint16_t, 4>({\n          UINT16_C(0xff00),\n\
    \          UINT16_C(0x00f0),\n          UINT16_C(0x000c),\n          UINT16_C(0x0002)\n\
    \        }),\n        ::std::array<::std::uint32_t, 5>({\n          UINT32_C(0xffff0000),\n\
    \          UINT32_C(0x0000ff00),\n          UINT32_C(0x000000f0),\n          UINT32_C(0x0000000c),\n\
    \          UINT32_C(0x00000002)\n        }),\n        ::std::array<::std::uint64_t,\
    \ 6>({\n          UINT64_C(0xffffffff00000000),\n          UINT64_C(0x00000000ffff0000),\n\
    \          UINT64_C(0x000000000000ff00),\n          UINT64_C(0x00000000000000f0),\n\
    \          UINT64_C(0x000000000000000c),\n          UINT64_C(0x0000000000000002)\n\
    \        })\n      );\n\n      T y = (((x & (x - 1)) == 0) ? 0 : 1);\n      T\
    \ j = ::std::numeric_limits<T>::digits / 2;\n\n      for (const auto t_i : ::std::get<log2(::std::numeric_limits<T>::digits)\
    \ - 3>(t)) {\n        T k = (((x & t_i) == 0) ? 0 : j);\n        y += k;\n   \
    \     x >>= k;\n        j >>= 1;\n      }\n\n      return y;\n    }\n  }\n}\n\n\
    \n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
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
  timestamp: '2022-10-08 19:22:04+09:00'
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
