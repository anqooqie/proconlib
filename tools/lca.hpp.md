---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/disjoint_sparse_table.hpp
    title: Disjoint sparse table
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/lca.test.cpp
    title: tests/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/lca.hpp\"\n\n\n\n#include <utility>\n#include <cstddef>\n\
    #include <limits>\n#include <vector>\n#include <cassert>\n#include <numeric>\n\
    #include <stack>\n#include <tuple>\n#line 1 \"tools/disjoint_sparse_table.hpp\"\
    \n\n\n\n#line 6 \"tools/disjoint_sparse_table.hpp\"\n#include <algorithm>\n#include\
    \ <iterator>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 8 \"tools/ceil_log2.hpp\"\n#include <array>\n#include <cstdint>\n\n// Source:\
    \ https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  template <typename T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      if constexpr (::std::numeric_limits<T>::digits == 8) {\n   \
    \     x = (x & UINT8_C(0x55)) + (x >> 1 & UINT8_C(0x55));\n        x = (x & UINT8_C(0x33))\
    \ + (x >> 2 & UINT8_C(0x33));\n        x = (x & UINT8_C(0x0f)) + (x >> 4 & UINT8_C(0x0f));\n\
    \      } else if constexpr (::std::numeric_limits<T>::digits == 16) {\n      \
    \  x = (x & UINT16_C(0x5555)) + (x >> 1 & UINT16_C(0x5555));\n        x = (x &\
    \ UINT16_C(0x3333)) + (x >> 2 & UINT16_C(0x3333));\n        x = (x & UINT16_C(0x0f0f))\
    \ + (x >> 4 & UINT16_C(0x0f0f));\n        x = (x & UINT16_C(0x00ff)) + (x >> 8\
    \ & UINT16_C(0x00ff));\n      } else if constexpr (::std::numeric_limits<T>::digits\
    \ == 32) {\n        x = (x & UINT32_C(0x55555555)) + (x >> 1 & UINT32_C(0x55555555));\n\
    \        x = (x & UINT32_C(0x33333333)) + (x >> 2 & UINT32_C(0x33333333));\n \
    \       x = (x & UINT32_C(0x0f0f0f0f)) + (x >> 4 & UINT32_C(0x0f0f0f0f));\n  \
    \      x = (x & UINT32_C(0x00ff00ff)) + (x >> 8 & UINT32_C(0x00ff00ff));\n   \
    \     x = (x & UINT32_C(0x0000ffff)) + (x >> 16 & UINT32_C(0x0000ffff));\n   \
    \   } else if constexpr (::std::numeric_limits<T>::digits == 64) {\n        x\
    \ = (x & UINT64_C(0x5555555555555555)) + (x >> 1 & UINT64_C(0x5555555555555555));\n\
    \        x = (x & UINT64_C(0x3333333333333333)) + (x >> 2 & UINT64_C(0x3333333333333333));\n\
    \        x = (x & UINT64_C(0x0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT64_C(0x0f0f0f0f0f0f0f0f));\n\
    \        x = (x & UINT64_C(0x00ff00ff00ff00ff)) + (x >> 8 & UINT64_C(0x00ff00ff00ff00ff));\n\
    \        x = (x & UINT64_C(0x0000ffff0000ffff)) + (x >> 16 & UINT64_C(0x0000ffff0000ffff));\n\
    \        x = (x & UINT64_C(0x00000000ffffffff)) + (x >> 32 & UINT64_C(0x00000000ffffffff));\n\
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 8 \"tools/floor_log2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  T floor_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::floor_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      x |= (x >> 1);\n      x |= (x >> 2);\n      x |= (x >> 4);\n\
    \      if constexpr (::std::numeric_limits<T>::digits > 8) x |= (x >> 8);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 16) x |= (x >> 16);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 32) x |= (x >> 32);\n  \
    \    return ::tools::popcount(x) - static_cast<T>(1);\n    }\n  }\n}\n\n\n#line\
    \ 12 \"tools/disjoint_sparse_table.hpp\"\n\nnamespace tools {\n  template <typename\
    \ M>\n  class disjoint_sparse_table {\n  private:\n    using T = typename M::T;\n\
    \    ::std::vector<T> m_value;\n    ::std::size_t m_size;\n    ::std::size_t m_capacity;\n\
    \    ::std::size_t m_height;\n\n  public:\n    disjoint_sparse_table() = default;\n\
    \    disjoint_sparse_table(const ::tools::disjoint_sparse_table<M>&) = default;\n\
    \    disjoint_sparse_table(::tools::disjoint_sparse_table<M>&&) = default;\n \
    \   ~disjoint_sparse_table() = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(const ::tools::disjoint_sparse_table<M>&) = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(::tools::disjoint_sparse_table<M>&&) = default;\n\n    template <typename\
    \ InputIterator>\n    disjoint_sparse_table(const InputIterator& begin, const\
    \ InputIterator& end) {\n      ::std::copy(begin, end, ::std::back_inserter(this->m_value));\n\
    \      this->m_size = this->m_value.size();\n      this->m_height = this->m_size\
    \ <= 1 ? this->m_size : ::tools::ceil_log2(this->m_size);\n      this->m_capacity\
    \ = this->m_size <= 1 ? this->m_size : ::tools::pow2(this->m_height);\n      this->m_value.resize(this->m_height\
    \ * this->m_capacity);\n      ::std::fill(this->m_value.begin() + this->m_size,\
    \ this->m_value.begin() + this->m_capacity, M::e());\n\n      for (::std::size_t\
    \ d = 1; d < this->m_height; ++d) {\n        const ::std::size_t offset = d *\
    \ this->m_capacity;\n        for (::std::size_t m = ::tools::pow2(d); m < this->m_capacity;\
    \ m += ::tools::pow2(d + 1)) {\n          this->m_value[offset + (m - 1)] = this->m_value[m\
    \ - 1];\n          this->m_value[offset + m] = this->m_value[m];\n          for\
    \ (::std::size_t l = m - 1; l --> m - ::tools::pow2(d);) {\n            this->m_value[offset\
    \ + l] = M::op(this->m_value[l], this->m_value[offset + (l + 1)]);\n         \
    \ }\n          for (::std::size_t r = m + 2; r <= m + ::tools::pow2(d); ++r) {\n\
    \            this->m_value[offset + (r - 1)] = M::op(this->m_value[offset + (r\
    \ - 2)], this->m_value[r - 1]);\n          }\n        }\n      }\n    }\n\n  \
    \  ::std::size_t size() const {\n      return this->m_size;\n    }\n\n    T prod(const\
    \ ::std::size_t l, const ::std::size_t r) const {\n      assert(l <= r && r <=\
    \ this->m_size);\n      if (r - l == 0) {\n        return M::e();\n      } else\
    \ if (r - l == 1) {\n        return this->m_value[l];\n      } else {\n      \
    \  const ::std::size_t offset = ::tools::floor_log2(l ^ (r - 1)) * this->m_capacity;\n\
    \        return M::op(this->m_value[offset + l], this->m_value[offset + (r - 1)]);\n\
    \      }\n    }\n  };\n}\n\n\n#line 13 \"tools/lca.hpp\"\n\nnamespace tools {\n\
    \  class lca {\n  private:\n    struct monoid {\n      using T = ::std::pair<::std::size_t,\
    \ ::std::size_t>;\n      static T op(const T& x, const T& y) {\n        return\
    \ x.second <= y.second ? T(x.first, x.second) : T(y.first, y.second);\n      }\n\
    \      static T e() {\n        return T(::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      }\n    };\n\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_edges;\n    ::std::vector<::std::size_t> m_in;\n    ::tools::disjoint_sparse_table<monoid>\
    \ m_dst;\n\n  public:\n\n    lca() = default;\n    lca(const ::tools::lca&) =\
    \ default;\n    lca(::tools::lca&&) = default;\n    ~lca() = default;\n    ::tools::lca&\
    \ operator=(const ::tools::lca&) = default;\n    ::tools::lca& operator=(::tools::lca&&)\
    \ = default;\n\n    lca(const ::std::size_t n) : m_edges(n), m_in(n) {\n     \
    \ assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return this->m_edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t u, const ::std::size_t v) {\n\
    \      assert(u < this->size());\n      assert(v < this->size());\n      assert(u\
    \ != v);\n      this->m_edges[u].push_back(v);\n      this->m_edges[v].push_back(u);\n\
    \    }\n\n    void build(const ::std::size_t root) {\n      assert(::std::accumulate(this->m_edges.begin(),\
    \ this->m_edges.end(), ::std::size_t(0), [](const ::std::size_t sum, const auto&\
    \ edges) { return sum + edges.size(); }) == 2 * (this->size() - 1));\n\n     \
    \ ::std::size_t t = 0;\n      ::std::vector<::std::pair<::std::size_t, ::std::size_t>>\
    \ tour(2 * this->size() - 1);\n\n      ::std::stack<::std::tuple<bool, ::std::size_t,\
    \ ::std::size_t>> stack;\n      stack.emplace(true, root, 0);\n      ::std::vector<bool>\
    \ will_visit(this->size(), false);\n      will_visit[root] = true;\n      while\
    \ (!stack.empty()) {\n        const auto [pre, here, depth] = stack.top();\n \
    \       stack.pop();\n        tour[t].first = here;\n        tour[t].second =\
    \ depth;\n        if (pre) {\n          this->m_in[here] = t;\n          for (const\
    \ ::std::size_t next : this->m_edges[here]) {\n            if (!will_visit[next])\
    \ {\n              stack.emplace(false, here, depth);\n              stack.emplace(true,\
    \ next, depth + 1);\n              will_visit[next] = true;\n            }\n \
    \         }\n        }\n        ++t;\n      }\n\n      if (this->size() > 1) {\n\
    \        tour.pop_back();\n      }\n      this->m_dst = ::tools::disjoint_sparse_table<monoid>(tour.begin(),\
    \ tour.end());\n    }\n\n    ::std::size_t query(::std::size_t u, ::std::size_t\
    \ v) const {\n      assert(u < this->size());\n      assert(v < this->size());\n\
    \n      if (this->m_in[v] < this->m_in[u]) {\n        ::std::swap(u, v);\n   \
    \   }\n\n      return this->m_dst.prod(this->m_in[u], this->m_in[v] + 1).first;\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LCA_HPP\n#define TOOLS_LCA_HPP\n\n#include <utility>\n#include\
    \ <cstddef>\n#include <limits>\n#include <vector>\n#include <cassert>\n#include\
    \ <numeric>\n#include <stack>\n#include <tuple>\n#include \"tools/disjoint_sparse_table.hpp\"\
    \n\nnamespace tools {\n  class lca {\n  private:\n    struct monoid {\n      using\
    \ T = ::std::pair<::std::size_t, ::std::size_t>;\n      static T op(const T& x,\
    \ const T& y) {\n        return x.second <= y.second ? T(x.first, x.second) :\
    \ T(y.first, y.second);\n      }\n      static T e() {\n        return T(::std::numeric_limits<::std::size_t>::max(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      }\n    };\n\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_edges;\n    ::std::vector<::std::size_t> m_in;\n    ::tools::disjoint_sparse_table<monoid>\
    \ m_dst;\n\n  public:\n\n    lca() = default;\n    lca(const ::tools::lca&) =\
    \ default;\n    lca(::tools::lca&&) = default;\n    ~lca() = default;\n    ::tools::lca&\
    \ operator=(const ::tools::lca&) = default;\n    ::tools::lca& operator=(::tools::lca&&)\
    \ = default;\n\n    lca(const ::std::size_t n) : m_edges(n), m_in(n) {\n     \
    \ assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return this->m_edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t u, const ::std::size_t v) {\n\
    \      assert(u < this->size());\n      assert(v < this->size());\n      assert(u\
    \ != v);\n      this->m_edges[u].push_back(v);\n      this->m_edges[v].push_back(u);\n\
    \    }\n\n    void build(const ::std::size_t root) {\n      assert(::std::accumulate(this->m_edges.begin(),\
    \ this->m_edges.end(), ::std::size_t(0), [](const ::std::size_t sum, const auto&\
    \ edges) { return sum + edges.size(); }) == 2 * (this->size() - 1));\n\n     \
    \ ::std::size_t t = 0;\n      ::std::vector<::std::pair<::std::size_t, ::std::size_t>>\
    \ tour(2 * this->size() - 1);\n\n      ::std::stack<::std::tuple<bool, ::std::size_t,\
    \ ::std::size_t>> stack;\n      stack.emplace(true, root, 0);\n      ::std::vector<bool>\
    \ will_visit(this->size(), false);\n      will_visit[root] = true;\n      while\
    \ (!stack.empty()) {\n        const auto [pre, here, depth] = stack.top();\n \
    \       stack.pop();\n        tour[t].first = here;\n        tour[t].second =\
    \ depth;\n        if (pre) {\n          this->m_in[here] = t;\n          for (const\
    \ ::std::size_t next : this->m_edges[here]) {\n            if (!will_visit[next])\
    \ {\n              stack.emplace(false, here, depth);\n              stack.emplace(true,\
    \ next, depth + 1);\n              will_visit[next] = true;\n            }\n \
    \         }\n        }\n        ++t;\n      }\n\n      if (this->size() > 1) {\n\
    \        tour.pop_back();\n      }\n      this->m_dst = ::tools::disjoint_sparse_table<monoid>(tour.begin(),\
    \ tour.end());\n    }\n\n    ::std::size_t query(::std::size_t u, ::std::size_t\
    \ v) const {\n      assert(u < this->size());\n      assert(v < this->size());\n\
    \n      if (this->m_in[v] < this->m_in[u]) {\n        ::std::swap(u, v);\n   \
    \   }\n\n      return this->m_dst.prod(this->m_in[u], this->m_in[v] + 1).first;\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/disjoint_sparse_table.hpp
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/lca.hpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lca.test.cpp
documentation_of: tools/lca.hpp
layout: document
title: Lowest common ancestor
---

It is a data structure which can return the lowest common ancestor of two vertices in a given tree.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
lca lca(::std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void lca.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting $u$ and $v$ to the graph.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$
- $u \neq v$

### Time Complexity
- Amortized $O(1)$

## build
```cpp
void lca.build(std::size_t r);
```

It internally creates a data structure which can return the lowest common ancestor of two vertices in the rooted tree whose root is $r$.

### Constraints
- The graph is a tree.
- $0 \leq r < n$

### Time Complexity
- $O(n \log n)$

## query
```cpp
void lca.query(std::size_t u, std::size_t v);
```

It returns the lowest common ancestor of two vertices $u$ and $v$.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$
