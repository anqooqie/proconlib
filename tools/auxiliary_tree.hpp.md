---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/lca.hpp
    title: Lowest common ancestor
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/auxiliary_tree.test.cpp
    title: tests/auxiliary_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/auxiliary_tree.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <utility>\n#include <algorithm>\n#include <stack>\n#include\
    \ <limits>\n#include <iterator>\n#include <type_traits>\n#line 1 \"tools/lca.hpp\"\
    \n\n\n\n#include <cstdint>\n#line 7 \"tools/lca.hpp\"\n#include <cassert>\n#include\
    \ <numeric>\n#line 13 \"tools/lca.hpp\"\n#include <tuple>\n#line 1 \"tools/ceil.hpp\"\
    \n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs <\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace\
    \ tools {\n\n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\
    \n  public:\n    less_by(const F& selector) : selector(selector) {\n    }\n\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#line 8 \"tools/ceil_log2.hpp\"\n#include <array>\n#line 10 \"tools/ceil_log2.hpp\"\
    \n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \n#line 1 \"tools/floor_log2.hpp\"\n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\
    \n#line 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
    \ >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n\
    \    } else {\n      const auto log2 = [](const int w) {\n        if (w == 8)\
    \ return 3;\n        if (w == 16) return 4;\n        if (w == 32) return 5;\n\
    \        if (w == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
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
    \ 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 19 \"tools/lca.hpp\"\n\
    \nnamespace tools {\n  class lca {\n    using u32 = ::std::uint32_t;\n    ::std::vector<::std::vector<u32>>\
    \ m_graph;\n    ::std::vector<u32> m_depth;\n    ::std::vector<u32> m_tour;\n\
    \    ::std::vector<u32> m_in;\n    u32 m_block_size;\n    ::std::vector<::std::vector<u32>>\
    \ m_sparse_table;\n    ::std::vector<::std::vector<::std::vector<u32>>> m_lookup_table;\n\
    \    ::std::vector<u32> m_patterns;\n\n    bool built() const {\n      return\
    \ !this->m_depth.empty();\n    }\n\n    u32 nblocks() const {\n      return ::tools::ceil(this->m_tour.size(),\
    \ this->m_block_size);\n    }\n\n    auto less_by_depth() const {\n      return\
    \ ::tools::less_by([&](const auto v) { return this->m_depth[v]; });\n    }\n\n\
    \  public:\n    lca() = default;\n    explicit lca(const ::std::size_t n) : m_graph(n)\
    \ {\n      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n\n    void add_edge(const ::std::size_t u, const\
    \ ::std::size_t v) {\n      assert(!this->built());\n      assert(u < this->size());\n\
    \      assert(v < this->size());\n      assert(u != v);\n      this->m_graph[u].push_back(v);\n\
    \      this->m_graph[v].push_back(u);\n    }\n\n    void build(const ::std::size_t\
    \ r) {\n      assert(!this->built());\n      assert(::std::accumulate(this->m_graph.begin(),\
    \ this->m_graph.end(), static_cast<::std::size_t>(0), [](const auto sum, const\
    \ auto& neighbors) { return sum + neighbors.size(); }) == 2 * (this->size() -\
    \ 1));\n\n      this->m_depth.assign(this->size(), ::std::numeric_limits<u32>::max());\n\
    \      this->m_tour.resize(2 * this->size() - 1);\n      this->m_in.resize(this->size());\n\
    \n      u32 t = 0;\n      ::std::stack<::std::pair<u32, u32>> stack;\n      stack.emplace(r,\
    \ 0);\n      while (!stack.empty()) {\n        const auto [here, depth] = stack.top();\n\
    \        stack.pop();\n        this->m_tour[t] = here;\n        if (this->m_depth[here]\
    \ == ::std::numeric_limits<u32>::max()) {\n          this->m_depth[here] = depth;\n\
    \          this->m_in[here] = t;\n          for (const auto next : this->m_graph[here])\
    \ {\n            if (this->m_depth[next] == ::std::numeric_limits<u32>::max())\
    \ {\n              stack.emplace(here, depth);\n              stack.emplace(next,\
    \ depth + 1);\n            }\n          }\n        }\n        ++t;\n      }\n\n\
    \      if (this->size() > 1) {\n        this->m_tour.pop_back();\n      }\n\n\
    \      this->m_block_size = ::std::max<u32>(1, ::tools::ceil(::tools::ceil_log2(this->m_tour.size()),\
    \ 2));\n      this->m_sparse_table.resize(::tools::floor_log2(this->nblocks())\
    \ + 1);\n      this->m_sparse_table[0].resize(this->nblocks());\n      for (u32\
    \ b = 0; (b + 1) * this->m_block_size <= this->m_tour.size(); ++b) {\n       \
    \ const auto l = b * this->m_block_size;\n        const auto r = ::std::min<u32>(l\
    \ + this->m_block_size, this->m_tour.size());\n        this->m_sparse_table[0][b]\
    \ = *::std::min_element(this->m_tour.begin() + l, this->m_tour.begin() + r, this->less_by_depth());\n\
    \      }\n      for (u32 h = 1; h < this->m_sparse_table.size(); ++h) {\n    \
    \    this->m_sparse_table[h].resize(this->nblocks() + UINT32_C(1) - (UINT32_C(1)\
    \ << h));\n        for (u32 b = 0; b < this->m_sparse_table[h].size(); ++b) {\n\
    \          this->m_sparse_table[h][b] = ::std::min(this->m_sparse_table[h - 1][b],\
    \ this->m_sparse_table[h - 1][b + (UINT32_C(1) << (h - 1))], this->less_by_depth());\n\
    \        }\n      }\n\n      this->m_lookup_table.resize(::tools::pow2(this->m_block_size\
    \ - 1));\n      for (u32 p = 0; p < this->m_lookup_table.size(); ++p) {\n    \
    \    this->m_lookup_table[p].resize(this->m_block_size + 1);\n        for (u32\
    \ l = 0; l <= this->m_block_size; ++l) {\n          this->m_lookup_table[p][l].resize(this->m_block_size\
    \ + 1);\n        }\n\n        ::std::vector<u32> partial_sum(this->m_block_size);\n\
    \        partial_sum[0] = this->m_block_size;\n        for (u32 i = 1; i < this->m_block_size;\
    \ ++i) {\n          partial_sum[i] = partial_sum[i - 1] - UINT32_C(1) + (((p >>\
    \ (i - 1)) & UINT32_C(1)) << 1);\n        }\n\n        for (u32 l = 0; l < this->m_block_size;\
    \ ++l) {\n          this->m_lookup_table[p][l][l + 1] = l;\n          for (u32\
    \ r = l + 2; r <= this->m_block_size; ++r) {\n            this->m_lookup_table[p][l][r]\
    \ = ::std::min(this->m_lookup_table[p][l][r - 1], r - 1, ::tools::less_by([&](const\
    \ auto i) { return partial_sum[i]; }));\n          }\n        }\n      }\n\n \
    \     this->m_patterns.resize(this->nblocks());\n      for (u32 b = 0; b * this->m_block_size\
    \ < this->m_tour.size(); ++b) {\n        const auto l = b * this->m_block_size;\n\
    \        const auto r = ::std::min<u32>(l + this->m_block_size, this->m_tour.size());\n\
    \        this->m_patterns[b] = 0;\n        for (u32 i = l; i + 1 < r; ++i) {\n\
    \          this->m_patterns[b] |= static_cast<u32>(this->m_depth[this->m_tour[i]]\
    \ < this->m_depth[this->m_tour[i + 1]]) << (i - l);\n        }\n      }\n    }\n\
    \n    ::std::size_t depth(const ::std::size_t v) const {\n      assert(this->built());\n\
    \      assert(v < this->size());\n      return this->m_depth[v];\n    }\n\n  \
    \  ::std::size_t query(::std::size_t u, ::std::size_t v) const {\n      assert(this->built());\n\
    \      assert(u < this->size());\n      assert(v < this->size());\n\n      ::std::tie(u,\
    \ v) = ::std::minmax({u, v}, ::tools::less_by([&](const auto w) { return this->m_in[w];\
    \ }));\n\n      const auto l = this->m_in[u];\n      const auto r = this->m_in[v]\
    \ + UINT32_C(1);\n      const auto bl = ::tools::ceil(l, this->m_block_size);\n\
    \      const auto br = r / this->m_block_size;\n      u32 lca;\n      if (br <\
    \ bl) {\n        lca = this->m_tour[br * this->m_block_size + this->m_lookup_table[this->m_patterns[br]][l\
    \ % this->m_block_size][r % this->m_block_size]];\n      } else {\n        lca\
    \ = u;\n        if (bl < br) {\n          const auto h = ::tools::floor_log2(br\
    \ - bl);\n          lca = ::std::min(this->m_sparse_table[h][bl], this->m_sparse_table[h][br\
    \ - (UINT32_C(1) << h)], this->less_by_depth());\n        }\n        if (l < bl\
    \ * this->m_block_size) {\n          lca = ::std::min(lca, this->m_tour[(bl -\
    \ UINT32_C(1)) * this->m_block_size + this->m_lookup_table[this->m_patterns[bl\
    \ - 1]][l % this->m_block_size][this->m_block_size]], this->less_by_depth());\n\
    \        }\n        if (br * this->m_block_size < r) {\n          lca = ::std::min(lca,\
    \ this->m_tour[br * this->m_block_size + this->m_lookup_table[this->m_patterns[br]][0][r\
    \ % this->m_block_size]], this->less_by_depth());\n        }\n      }\n\n    \
    \  return lca;\n    }\n\n    // for tools::auxiliary_tree\n    ::std::size_t internal_in(const\
    \ ::std::size_t v) const {\n      assert(this->built());\n      assert(v < this->size());\n\
    \      return this->m_in[v];\n    }\n  };\n}\n\n\n#line 1 \"tools/less_by_first.hpp\"\
    \n\n\n\n#line 5 \"tools/less_by_first.hpp\"\n\nnamespace tools {\n\n  class less_by_first\
    \ {\n  public:\n    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.first < y.first;\n\
    \    }\n  };\n}\n\n\n#line 15 \"tools/auxiliary_tree.hpp\"\n\nnamespace tools\
    \ {\n  class auxiliary_tree {\n    ::tools::lca m_lca;\n\n  public:\n    auxiliary_tree()\
    \ = default;\n    explicit auxiliary_tree(const ::std::size_t n) : m_lca(n) {\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->m_lca.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t u, const ::std::size_t v) {\n\
    \      this->m_lca.add_edge(u, v);\n    }\n\n    void build(const ::std::size_t\
    \ r) {\n      this->m_lca.build(r);\n    }\n\n    ::std::size_t depth(const ::std::size_t\
    \ v) const {\n      return this->m_lca.depth(v);\n    }\n\n    ::std::size_t lca(const\
    \ ::std::size_t u, const ::std::size_t v) const {\n      return this->m_lca.query(u,\
    \ v);\n    }\n\n    class query_result {\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> m_parent;\n      ::std::vector<::std::vector<::std::size_t>>\
    \ m_children;\n      ::std::size_t m_root;\n\n      template <typename InputIterator>\n\
    \      query_result(const ::tools::auxiliary_tree& tree, const InputIterator begin,\
    \ const InputIterator end) {\n        ::std::vector<::std::size_t> X(begin, end);\n\
    \        assert(!X.empty());\n        ::std::sort(X.begin(), X.end(), ::tools::less_by([&](const\
    \ auto v) { return tree.m_lca.internal_in(v); }));\n\n        ::std::stack<::std::size_t>\
    \ stack;\n        auto it = X.begin();\n        stack.push(*(it++));\n       \
    \ for (; it != X.end(); ++it) {\n          const auto w = tree.lca(stack.top(),\
    \ *it);\n          while (!stack.empty() && tree.depth(w) < tree.depth(stack.top()))\
    \ {\n            const auto u = stack.top();\n            stack.pop();\n     \
    \       this->m_parent.emplace_back(u, w);\n            if (!stack.empty() &&\
    \ tree.depth(w) < tree.depth(stack.top())) {\n              this->m_parent.back().second\
    \ = stack.top();\n            }\n          }\n          if (stack.empty() || stack.top()\
    \ != w) {\n            stack.push(w);\n          }\n          stack.push(*it);\n\
    \        }\n        while (!stack.empty()) {\n          const auto u = stack.top();\n\
    \          stack.pop();\n          if (stack.empty()) {\n            this->m_parent.emplace_back(u,\
    \ ::std::numeric_limits<::std::size_t>::max());\n            this->m_root = u;\n\
    \          } else {\n            this->m_parent.emplace_back(u, stack.top());\n\
    \          }\n        }\n\n        ::std::sort(this->m_parent.begin(), this->m_parent.end(),\
    \ ::tools::less_by_first{});\n\n        this->m_children.resize(this->m_parent.size());\n\
    \        for (const auto& [v, p] : this->m_parent) {\n          if (v != this->m_root)\
    \ {\n            const auto it = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(),\
    \ ::std::make_pair(p, ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});\n\
    \            assert(it != this->m_parent.end());\n            assert(it->first\
    \ == p);\n            this->m_children[::std::distance(this->m_parent.begin(),\
    \ it)].push_back(v);\n          }\n        }\n      }\n\n    public:\n      class\
    \ vertices_iterable {\n        query_result const *m_qr;\n\n      public:\n  \
    \      class iterator {\n          query_result const *m_qr;\n          ::std::size_t\
    \ m_i;\n\n        public:\n          using difference_type = ::std::ptrdiff_t;\n\
    \          using value_type = ::std::size_t;\n          using reference = const\
    \ ::std::size_t&;\n          using pointer = const ::std::size_t*;\n         \
    \ using iterator_category = ::std::input_iterator_tag;\n\n          iterator()\
    \ = default;\n          iterator(query_result const * const qr, const ::std::size_t\
    \ i) : m_qr(qr), m_i(i) {\n          }\n\n          reference operator*() const\
    \ {\n            return this->m_qr->m_parent[this->m_i].first;\n          }\n\
    \          iterator& operator++() {\n            ++this->m_i;\n            return\
    \ *this;\n          }\n          iterator operator++(int) {\n            const\
    \ auto self = *this;\n            ++*this;\n            return self;\n       \
    \   }\n          friend bool operator==(const iterator& lhs, const iterator& rhs)\
    \ {\n            assert(lhs.m_qr == rhs.m_qr);\n            return lhs.m_i ==\
    \ rhs.m_i;\n          }\n          friend bool operator!=(const iterator& lhs,\
    \ const iterator& rhs) {\n            return !(lhs == rhs);\n          }\n   \
    \     };\n\n        vertices_iterable() = default;\n        vertices_iterable(query_result\
    \ const * const qr) : m_qr(qr) {\n        }\n\n        iterator begin() const\
    \ {\n          return iterator(this->m_qr, 0);\n        };\n        iterator end()\
    \ const {\n          return iterator(this->m_qr, this->m_qr->m_parent.size());\n\
    \        }\n      };\n\n      query_result() = default;\n\n      ::std::size_t\
    \ size() const {\n        return this->m_parent.size();\n      }\n\n      vertices_iterable\
    \ vertices() const {\n        return vertices_iterable(this);\n      }\n\n   \
    \   ::std::size_t root() const {\n        return this->m_root;\n      }\n\n  \
    \    ::std::size_t parent(const ::std::size_t v) const {\n        const auto it\
    \ = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(), ::std::make_pair(v,\
    \ ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});\n \
    \       assert(it != this->m_parent.end());\n        assert(it->first == v);\n\
    \        return it->second;\n      }\n\n      const ::std::vector<::std::size_t>&\
    \ children(const ::std::size_t v) const {\n        const auto it = ::std::lower_bound(this->m_parent.begin(),\
    \ this->m_parent.end(), ::std::make_pair(v, ::std::numeric_limits<::std::size_t>::max()),\
    \ ::tools::less_by_first{});\n        assert(it != this->m_parent.end());\n  \
    \      assert(it->first == v);\n        return this->m_children[::std::distance(this->m_parent.begin(),\
    \ it)];\n      }\n\n      friend ::tools::auxiliary_tree;\n    };\n\n    template\
    \ <typename InputIterator>\n    query_result query(const InputIterator begin,\
    \ const InputIterator end) const {\n      return query_result(*this, begin, end);\n\
    \    }\n\n    template <typename Z, ::std::enable_if_t<::std::is_integral_v<Z>,\
    \ ::std::nullptr_t> = nullptr>\n    query_result query(const ::std::vector<Z>&\
    \ X) const {\n      return this->query(X.begin(), X.end());\n    }\n  };\n}\n\n\
    \n"
  code: "#ifndef TOOLS_AUXILIARY_TREE_HPP\n#define TOOLS_AUXILIARY_TREE_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <utility>\n#include <algorithm>\n#include\
    \ <stack>\n#include <limits>\n#include <iterator>\n#include <type_traits>\n#include\
    \ \"tools/lca.hpp\"\n#include \"tools/less_by.hpp\"\n#include \"tools/less_by_first.hpp\"\
    \n\nnamespace tools {\n  class auxiliary_tree {\n    ::tools::lca m_lca;\n\n \
    \ public:\n    auxiliary_tree() = default;\n    explicit auxiliary_tree(const\
    \ ::std::size_t n) : m_lca(n) {\n    }\n\n    ::std::size_t size() const {\n \
    \     return this->m_lca.size();\n    }\n\n    void add_edge(const ::std::size_t\
    \ u, const ::std::size_t v) {\n      this->m_lca.add_edge(u, v);\n    }\n\n  \
    \  void build(const ::std::size_t r) {\n      this->m_lca.build(r);\n    }\n\n\
    \    ::std::size_t depth(const ::std::size_t v) const {\n      return this->m_lca.depth(v);\n\
    \    }\n\n    ::std::size_t lca(const ::std::size_t u, const ::std::size_t v)\
    \ const {\n      return this->m_lca.query(u, v);\n    }\n\n    class query_result\
    \ {\n      ::std::vector<::std::pair<::std::size_t, ::std::size_t>> m_parent;\n\
    \      ::std::vector<::std::vector<::std::size_t>> m_children;\n      ::std::size_t\
    \ m_root;\n\n      template <typename InputIterator>\n      query_result(const\
    \ ::tools::auxiliary_tree& tree, const InputIterator begin, const InputIterator\
    \ end) {\n        ::std::vector<::std::size_t> X(begin, end);\n        assert(!X.empty());\n\
    \        ::std::sort(X.begin(), X.end(), ::tools::less_by([&](const auto v) {\
    \ return tree.m_lca.internal_in(v); }));\n\n        ::std::stack<::std::size_t>\
    \ stack;\n        auto it = X.begin();\n        stack.push(*(it++));\n       \
    \ for (; it != X.end(); ++it) {\n          const auto w = tree.lca(stack.top(),\
    \ *it);\n          while (!stack.empty() && tree.depth(w) < tree.depth(stack.top()))\
    \ {\n            const auto u = stack.top();\n            stack.pop();\n     \
    \       this->m_parent.emplace_back(u, w);\n            if (!stack.empty() &&\
    \ tree.depth(w) < tree.depth(stack.top())) {\n              this->m_parent.back().second\
    \ = stack.top();\n            }\n          }\n          if (stack.empty() || stack.top()\
    \ != w) {\n            stack.push(w);\n          }\n          stack.push(*it);\n\
    \        }\n        while (!stack.empty()) {\n          const auto u = stack.top();\n\
    \          stack.pop();\n          if (stack.empty()) {\n            this->m_parent.emplace_back(u,\
    \ ::std::numeric_limits<::std::size_t>::max());\n            this->m_root = u;\n\
    \          } else {\n            this->m_parent.emplace_back(u, stack.top());\n\
    \          }\n        }\n\n        ::std::sort(this->m_parent.begin(), this->m_parent.end(),\
    \ ::tools::less_by_first{});\n\n        this->m_children.resize(this->m_parent.size());\n\
    \        for (const auto& [v, p] : this->m_parent) {\n          if (v != this->m_root)\
    \ {\n            const auto it = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(),\
    \ ::std::make_pair(p, ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});\n\
    \            assert(it != this->m_parent.end());\n            assert(it->first\
    \ == p);\n            this->m_children[::std::distance(this->m_parent.begin(),\
    \ it)].push_back(v);\n          }\n        }\n      }\n\n    public:\n      class\
    \ vertices_iterable {\n        query_result const *m_qr;\n\n      public:\n  \
    \      class iterator {\n          query_result const *m_qr;\n          ::std::size_t\
    \ m_i;\n\n        public:\n          using difference_type = ::std::ptrdiff_t;\n\
    \          using value_type = ::std::size_t;\n          using reference = const\
    \ ::std::size_t&;\n          using pointer = const ::std::size_t*;\n         \
    \ using iterator_category = ::std::input_iterator_tag;\n\n          iterator()\
    \ = default;\n          iterator(query_result const * const qr, const ::std::size_t\
    \ i) : m_qr(qr), m_i(i) {\n          }\n\n          reference operator*() const\
    \ {\n            return this->m_qr->m_parent[this->m_i].first;\n          }\n\
    \          iterator& operator++() {\n            ++this->m_i;\n            return\
    \ *this;\n          }\n          iterator operator++(int) {\n            const\
    \ auto self = *this;\n            ++*this;\n            return self;\n       \
    \   }\n          friend bool operator==(const iterator& lhs, const iterator& rhs)\
    \ {\n            assert(lhs.m_qr == rhs.m_qr);\n            return lhs.m_i ==\
    \ rhs.m_i;\n          }\n          friend bool operator!=(const iterator& lhs,\
    \ const iterator& rhs) {\n            return !(lhs == rhs);\n          }\n   \
    \     };\n\n        vertices_iterable() = default;\n        vertices_iterable(query_result\
    \ const * const qr) : m_qr(qr) {\n        }\n\n        iterator begin() const\
    \ {\n          return iterator(this->m_qr, 0);\n        };\n        iterator end()\
    \ const {\n          return iterator(this->m_qr, this->m_qr->m_parent.size());\n\
    \        }\n      };\n\n      query_result() = default;\n\n      ::std::size_t\
    \ size() const {\n        return this->m_parent.size();\n      }\n\n      vertices_iterable\
    \ vertices() const {\n        return vertices_iterable(this);\n      }\n\n   \
    \   ::std::size_t root() const {\n        return this->m_root;\n      }\n\n  \
    \    ::std::size_t parent(const ::std::size_t v) const {\n        const auto it\
    \ = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(), ::std::make_pair(v,\
    \ ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});\n \
    \       assert(it != this->m_parent.end());\n        assert(it->first == v);\n\
    \        return it->second;\n      }\n\n      const ::std::vector<::std::size_t>&\
    \ children(const ::std::size_t v) const {\n        const auto it = ::std::lower_bound(this->m_parent.begin(),\
    \ this->m_parent.end(), ::std::make_pair(v, ::std::numeric_limits<::std::size_t>::max()),\
    \ ::tools::less_by_first{});\n        assert(it != this->m_parent.end());\n  \
    \      assert(it->first == v);\n        return this->m_children[::std::distance(this->m_parent.begin(),\
    \ it)];\n      }\n\n      friend ::tools::auxiliary_tree;\n    };\n\n    template\
    \ <typename InputIterator>\n    query_result query(const InputIterator begin,\
    \ const InputIterator end) const {\n      return query_result(*this, begin, end);\n\
    \    }\n\n    template <typename Z, ::std::enable_if_t<::std::is_integral_v<Z>,\
    \ ::std::nullptr_t> = nullptr>\n    query_result query(const ::std::vector<Z>&\
    \ X) const {\n      return this->query(X.begin(), X.end());\n    }\n  };\n}\n\n\
    #endif\n"
  dependsOn:
  - tools/lca.hpp
  - tools/ceil.hpp
  - tools/less_by.hpp
  - tools/ceil_log2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/pow2.hpp
  - tools/less_by_first.hpp
  isVerificationFile: false
  path: tools/auxiliary_tree.hpp
  requiredBy: []
  timestamp: '2024-09-15 21:33:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/auxiliary_tree.test.cpp
documentation_of: tools/auxiliary_tree.hpp
layout: document
title: Auxiliary tree
---

It is an auxiliary tree obtained by compressing a tree so that LCA relations of specified vertices are preserved.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
auxiliary_tree graph(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void graph.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting $u$ and $v$ to the graph.

### Constraints
- `graph.build()` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$
- $u \neq v$

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void graph.build(std::size_t r);
```

It asserts that the graph is a rooted tree with root $r$.

### Constraints
- `graph.build()` has not been called ever.
- The graph is a tree.
- $0 \leq r < n$

### Time Complexity
- $O(n)$

## depth
```cpp
std::size_t graph.depth(std::size_t v);
```

It returns the number of edges between $r$ and $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## lca
```cpp
std::size_t graph.lca(std::size_t u, std::size_t v);
```

It returns the lowest common ancestor of two vertices $u$ and $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## query
```cpp
template <typename InputIterator>
query_result graph.query(InputIterator begin, InputIterator end);

template <typename Z>
query_result graph.query(std::vector<Z> X);
```

For a given rooted tree $T = (V, E; r)$ and a subset of its vertices $X \subseteq V$, it returns an auxiliary rooted tree $T'$ that can be obtained by compressing $T$ so that no descendant/ancestor relationship or least common ancestor relationship is lost between the vertices in $X$.
More precisely, for each vertex pair $(x, y) \in X^2$, we consider its least common ancestor $z = \mathrm{lca}(x, y)$.
The rooted tree $T' = (V', E'; r')$ is the one formed by edging such vertices $V' = \\{\mathrm{lca}(x, y) \mid (x, y) \in X^2\\}$ with descendant relations in the original tree $T$.

### Constraints
- `graph.build()` has been called ever.
- $X$ is a set of integers.
- $X \subseteq V$
- $X \neq \varnothing$

### Time Complexity
- $O(\|X\| \log \|X\|)$

## query_result::size
```cpp
std::size_t qr.size();
```

It returns $\|X'\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query_result::vertices
```cpp
struct vertices_iterable {
  struct iterator {
    std::size_t operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
vertices_iterable qr.vertices();
```

It returns $X'$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query_result::root
```cpp
std::size_t qr.root();
```

It returns $r'$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query_result::parent
```cpp
std::size_t qr.parent(std::size_t v);
```

It returns the parent of $v$ in $T'$.

### Constraints
- $v \in X'$
- $v \neq r'$

### Time Complexity
- $O(\log \|X\|)$

## query_result::children
```cpp
const std::vector<std::size_t>& qr.children(std::size_t v);
```

It returns the children of $v$ in $T'$.

### Constraints
- $v \in X'$

### Time Complexity
- $O(\log \|X\|)$
