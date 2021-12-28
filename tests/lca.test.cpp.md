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
    path: tools/lca.hpp
    title: Lowest common ancestor
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
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/lca.hpp\"\n\n\n\n\
    #include <utility>\n#include <cstddef>\n#include <limits>\n#include <vector>\n\
    #include <cassert>\n#include <numeric>\n#include <stack>\n#include <tuple>\n#line\
    \ 1 \"tools/disjoint_sparse_table.hpp\"\n\n\n\n#line 6 \"tools/disjoint_sparse_table.hpp\"\
    \n#include <algorithm>\n#include <iterator>\n#line 1 \"tools/ceil_log2.hpp\"\n\
    \n\n\n#line 5 \"tools/ceil_log2.hpp\"\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n\
    \    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  inline ::std::uint64_t\
    \ popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 6 \"tools/floor_log2.hpp\"\n\nnamespace tools {\n\n  inline\
    \ ::std::uint32_t floor_log2(::std::uint32_t x) {\n    x |= (x >> static_cast<::std::uint32_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(2));\n    x |= (x >> static_cast<::std::uint32_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(8));\n    x |= (x >> static_cast<::std::uint32_t>(16));\n\
    \    return ::tools::popcount(x) - static_cast<::std::uint32_t>(1);\n  }\n\n \
    \ inline ::std::uint64_t floor_log2(::std::uint64_t x) {\n    x |= (x >> static_cast<::std::uint64_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(2));\n    x |= (x >> static_cast<::std::uint64_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(8));\n    x |= (x >> static_cast<::std::uint64_t>(16));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(32));\n    return ::tools::popcount(x)\
    \ - static_cast<::std::uint64_t>(1);\n  }\n\n  inline ::std::int32_t floor_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t floor_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 12 \"tools/disjoint_sparse_table.hpp\"\n\nnamespace tools {\n\
    \  template <typename M>\n  class disjoint_sparse_table {\n  private:\n    using\
    \ T = typename M::T;\n    ::std::vector<T> m_value;\n    ::std::size_t m_size;\n\
    \    ::std::size_t m_capacity;\n    ::std::size_t m_height;\n\n  public:\n   \
    \ disjoint_sparse_table() = default;\n    disjoint_sparse_table(const ::tools::disjoint_sparse_table<M>&)\
    \ = default;\n    disjoint_sparse_table(::tools::disjoint_sparse_table<M>&&) =\
    \ default;\n    ~disjoint_sparse_table() = default;\n    ::tools::disjoint_sparse_table<M>&\
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
    \         }\n        }\n        ++t;\n      }\n\n      tour.pop_back();\n    \
    \  this->m_dst = ::tools::disjoint_sparse_table<monoid>(tour.begin(), tour.end());\n\
    \    }\n\n    ::std::size_t query(::std::size_t u, ::std::size_t v) const {\n\
    \      assert(u < this->size());\n      assert(v < this->size());\n\n      if\
    \ (this->m_in[v] < this->m_in[u]) {\n        ::std::swap(u, v);\n      }\n\n \
    \     return this->m_dst.prod(this->m_in[u], this->m_in[v] + 1).first;\n    }\n\
    \  };\n}\n\n\n#line 6 \"tests/lca.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N, Q;\n  std::cin >> N >> Q;\n  ::tools::lca lca(N);\n  for (i64 i = 1;\
    \ i <= N - 1; ++i) {\n    i64 p;\n    std::cin >> p;\n    lca.add_edge(i, p);\n\
    \  }\n  lca.build(0);\n\n  for (i64 q = 0; q < Q; ++q) {\n    i64 u, v;\n    std::cin\
    \ >> u >> v;\n    std::cout << lca.query(u, v) << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <cstdint>\n\
    #include <iostream>\n#include \"tools/lca.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N, Q;\n  std::cin >> N >> Q;\n  ::tools::lca lca(N);\n  for (i64 i = 1;\
    \ i <= N - 1; ++i) {\n    i64 p;\n    std::cin >> p;\n    lca.add_edge(i, p);\n\
    \  }\n  lca.build(0);\n\n  for (i64 q = 0; q < Q; ++q) {\n    i64 u, v;\n    std::cin\
    \ >> u >> v;\n    std::cout << lca.query(u, v) << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/lca.hpp
  - tools/disjoint_sparse_table.hpp
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/lca.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 06:01:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lca.test.cpp
layout: document
redirect_from:
- /verify/tests/lca.test.cpp
- /verify/tests/lca.test.cpp.html
title: tests/lca.test.cpp
---
