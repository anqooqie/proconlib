---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/greater_by.hpp
    title: std::greater by key
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/prim.hpp
    title: Prim's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc270/tasks/abc270_f
    links:
    - https://atcoder.jp/contests/abc270/tasks/abc270_f
  bundledCode: "#line 1 \"tests/prim/unconnected.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc270/tasks/abc270_f\"\
    \n\n#include <iostream>\n#include <vector>\n#include <limits>\n#line 1 \"tools/prim.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 6 \"tools/prim.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <algorithm>\n#line 10 \"tools/prim.hpp\"\n#include <queue>\n\
    #line 1 \"tools/greater_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class greater_by {\n  private:\n    F selector;\n\n  public:\n    greater_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) > selector(y);\n\
    \    }\n  };\n}\n\n\n#line 12 \"tools/prim.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  class prim {\n  public:\n    struct edge {\n      ::std::size_t\
    \ id;\n      ::std::size_t from;\n      ::std::size_t to;\n      T cost;\n   \
    \ };\n\n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    prim() = default;\n    prim(const ::tools::prim<T>&)\
    \ = default;\n    prim(::tools::prim<T>&&) = default;\n    ~prim() = default;\n\
    \    ::tools::prim<T>& operator=(const ::tools::prim<T>&) = default;\n    ::tools::prim<T>&\
    \ operator=(::tools::prim<T>&&) = default;\n\n    explicit prim(const ::std::size_t\
    \ n) : m_graph(n) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   ::std::tie(u, v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n \
    \     this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::pair<::std::vector<::std::pair<T, ::std::vector<::std::size_t>>>,\
    \ ::std::vector<::std::size_t>> query() const {\n      ::std::pair<::std::vector<::std::pair<T,\
    \ ::std::vector<::std::size_t>>>, ::std::vector<::std::size_t>> res;\n      auto&\
    \ [groups, belongs_to] = res;\n      belongs_to.resize(this->size());\n      ::std::fill(belongs_to.begin(),\
    \ belongs_to.end(), ::std::numeric_limits<::std::size_t>::max());\n\n      for\
    \ (::std::size_t root = 0; root < this->size(); ++root) {\n        if (belongs_to[root]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n        const auto\
    \ greater_by_cost = ::tools::greater_by([&](const auto& pair) { return this->m_edges[pair.first].cost;\
    \ });\n        ::std::priority_queue<::std::pair<::std::size_t, ::std::size_t>,\
    \ ::std::vector<::std::pair<::std::size_t, ::std::size_t>>, decltype(greater_by_cost)>\
    \ pq(greater_by_cost);\n        groups.emplace_back(0, ::std::vector<::std::size_t>());\n\
    \        auto& [total_cost, edge_ids] = groups.back();\n\n        belongs_to[root]\
    \ = groups.size() - 1;\n        for (const auto e : this->m_graph[root]) {\n \
    \         const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ root;\n\
    \          if (belongs_to[next] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          pq.emplace(e, next);\n        }\n\n        while (!pq.empty())\
    \ {\n          const auto [from_edge_id, here] = pq.top();\n          pq.pop();\n\
    \n          if (belongs_to[here] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          belongs_to[here] = belongs_to[root];\n          total_cost\
    \ += this->m_edges[from_edge_id].cost;\n          edge_ids.push_back(from_edge_id);\n\
    \          for (const auto e : this->m_graph[here]) {\n            const auto\
    \ next = this->m_edges[e].from ^ this->m_edges[e].to ^ here;\n            if (belongs_to[next]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n            pq.emplace(e,\
    \ next);\n          }\n        }\n      }\n\n      return res;\n    }\n  };\n\
    }\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#include <type_traits>\n#line 7 \"\
    tools/popcount.hpp\"\n#include <cstdint>\n\nnamespace tools {\n\n  template <typename\
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
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\
    \n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = ::tools::cmp_less(rhs, lhs);\n    if (updated)\
    \ lhs = rhs;\n    return updated;\n  }\n}\n\n\n#line 9 \"tests/prim/unconnected.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M;\n  std::cin >> N >> M;\n  std::vector<ll> X(N), Y(N);\n  for (auto&\
    \ X_i : X) std::cin >> X_i;\n  for (auto& Y_i : Y) std::cin >> Y_i;\n  std::vector<ll>\
    \ A(M), B(M), Z(M);\n  for (ll i = 0; i < M; ++i) {\n    std::cin >> A[i] >> B[i]\
    \ >> Z[i];\n    --A[i], --B[i];\n  }\n\n  ll answer = std::numeric_limits<ll>::max();\n\
    \  for (ll state = 0; state < 4; ++state) {\n    tools::prim<ll> graph(N + tools::popcount(state));\n\
    \    if (state & 1) {\n      for (ll i = 0; i < N; ++i) {\n        graph.add_edge(i,\
    \ N, X[i]);\n      }\n    }\n    if (state & 2) {\n      for (ll i = 0; i < N;\
    \ ++i) {\n        graph.add_edge(i, N + (state & 1), Y[i]);\n      }\n    }\n\
    \    for (ll i = 0; i < M; ++i) {\n      graph.add_edge(A[i], B[i], Z[i]);\n \
    \   }\n    if (const auto groups = graph.query().first; groups.size() == 1) {\n\
    \      tools::chmin(answer, groups[0].first);\n    }\n  }\n\n  std::cout << answer\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc270/tasks/abc270_f\"\n\n\
    #include <iostream>\n#include <vector>\n#include <limits>\n#include \"tools/prim.hpp\"\
    \n#include \"tools/popcount.hpp\"\n#include \"tools/chmin.hpp\"\n\nusing ll =\
    \ long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M;\n  std::cin >> N >> M;\n  std::vector<ll> X(N), Y(N);\n  for (auto&\
    \ X_i : X) std::cin >> X_i;\n  for (auto& Y_i : Y) std::cin >> Y_i;\n  std::vector<ll>\
    \ A(M), B(M), Z(M);\n  for (ll i = 0; i < M; ++i) {\n    std::cin >> A[i] >> B[i]\
    \ >> Z[i];\n    --A[i], --B[i];\n  }\n\n  ll answer = std::numeric_limits<ll>::max();\n\
    \  for (ll state = 0; state < 4; ++state) {\n    tools::prim<ll> graph(N + tools::popcount(state));\n\
    \    if (state & 1) {\n      for (ll i = 0; i < N; ++i) {\n        graph.add_edge(i,\
    \ N, X[i]);\n      }\n    }\n    if (state & 2) {\n      for (ll i = 0; i < N;\
    \ ++i) {\n        graph.add_edge(i, N + (state & 1), Y[i]);\n      }\n    }\n\
    \    for (ll i = 0; i < M; ++i) {\n      graph.add_edge(A[i], B[i], Z[i]);\n \
    \   }\n    if (const auto groups = graph.query().first; groups.size() == 1) {\n\
    \      tools::chmin(answer, groups[0].first);\n    }\n  }\n\n  std::cout << answer\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/prim.hpp
  - tools/greater_by.hpp
  - tools/popcount.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  isVerificationFile: true
  path: tests/prim/unconnected.test.cpp
  requiredBy: []
  timestamp: '2024-03-20 23:37:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/prim/unconnected.test.cpp
layout: document
redirect_from:
- /verify/tests/prim/unconnected.test.cpp
- /verify/tests/prim/unconnected.test.cpp.html
title: tests/prim/unconnected.test.cpp
---
