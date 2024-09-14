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
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tests/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#include <iostream>\n#line 1 \"tools/lca.hpp\"\n\n\n\n#include <cstdint>\n\
    #include <vector>\n#include <cstddef>\n#include <cassert>\n#include <numeric>\n\
    #include <limits>\n#include <stack>\n#include <utility>\n#include <algorithm>\n\
    #include <tuple>\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n#line\
    \ 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools\
    \ {\n\n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\n\
    \  public:\n    less_by(const F& selector) : selector(selector) {\n    }\n\n \
    \   template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
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
    \  return lca;\n    }\n  };\n}\n\n\n#line 5 \"tests/lca.test.cpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  int\
    \ N, Q;\n  std::cin >> N >> Q;\n  tools::lca lca(N);\n  for (int i = 1; i < N;\
    \ ++i) {\n    int p;\n    std::cin >> p;\n    lca.add_edge(i, p);\n  }\n  lca.build(0);\n\
    \n  for (int q = 0; q < Q; ++q) {\n    int u, v;\n    std::cin >> u >> v;\n  \
    \  std::cout << lca.query(u, v) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <iostream>\n\
    #include \"tools/lca.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n  tools::lca lca(N);\n  for (int i = 1;\
    \ i < N; ++i) {\n    int p;\n    std::cin >> p;\n    lca.add_edge(i, p);\n  }\n\
    \  lca.build(0);\n\n  for (int q = 0; q < Q; ++q) {\n    int u, v;\n    std::cin\
    \ >> u >> v;\n    std::cout << lca.query(u, v) << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/lca.hpp
  - tools/ceil.hpp
  - tools/less_by.hpp
  - tools/ceil_log2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/pow2.hpp
  isVerificationFile: true
  path: tests/lca.test.cpp
  requiredBy: []
  timestamp: '2024-09-15 05:25:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lca.test.cpp
layout: document
redirect_from:
- /verify/tests/lca.test.cpp
- /verify/tests/lca.test.cpp.html
title: tests/lca.test.cpp
---
