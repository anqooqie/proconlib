---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':heavy_check_mark:'
    path: tools/tsp.hpp
    title: Traveling salesman problem
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A
  bundledCode: "#line 1 \"tests/tsp.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#line 1 \"tools/tsp.hpp\"\n\n\n\n\
    #include <cstddef>\n#include <vector>\n#include <limits>\n#line 8 \"tools/tsp.hpp\"\
    \n#include <utility>\n#include <algorithm>\n#include <optional>\n#include <tuple>\n\
    #line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/pow2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\
    \n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool updated\
    \ = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 14 \"tools/tsp.hpp\"\n\nnamespace tools {\n\n  template <bool Directed,\
    \ typename T>\n  class tsp {\n  public:\n    struct edge {\n      ::std::size_t\
    \ id;\n      ::std::size_t from;\n      ::std::size_t to;\n      T cost;\n   \
    \ };\n\n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    tsp() = default;\n    tsp(const ::tools::tsp<Directed,\
    \ T>&) = default;\n    tsp(::tools::tsp<Directed, T>&&) = default;\n    ~tsp()\
    \ = default;\n    ::tools::tsp<Directed, T>& operator=(const ::tools::tsp<Directed,\
    \ T>&) = default;\n    ::tools::tsp<Directed, T>& operator=(::tools::tsp<Directed,\
    \ T>&&) = default;\n\n    explicit tsp(const ::std::size_t n) : m_graph(n, ::std::vector<::std::size_t>(n,\
    \ ::std::numeric_limits<::std::size_t>::max())) {\n      assert(n >= 2);\n   \
    \ }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T&\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   if constexpr (!Directed) {\n        ::std::tie(u, v) = ::std::minmax({u, v});\n\
    \      }\n      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));\n\
    \      if (this->m_graph[u][v] == ::std::numeric_limits<::std::size_t>::max()\
    \ || w < this->m_edges[this->m_graph[u][v]].cost) {\n        this->m_graph[u][v]\
    \ = this->m_edges.size() - 1;\n      }\n      if constexpr (!Directed) {\n   \
    \     if (this->m_graph[v][u] == ::std::numeric_limits<::std::size_t>::max() ||\
    \ w < this->m_edges[this->m_graph[v][u]].cost) {\n          this->m_graph[v][u]\
    \ = this->m_edges.size() - 1;\n        }\n      }\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::optional<::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>>>\
    \ query() const {\n      auto dp = ::std::vector(::tools::pow2(this->size()),\
    \ ::std::vector(this->size(), ::std::numeric_limits<T>::max()));\n      dp[0][0]\
    \ = 0;\n      for (::std::size_t state = 1; state < ::tools::pow2(this->size());\
    \ ++state) {\n        for (::std::size_t v = 0; v < this->size(); ++v) {\n   \
    \       if ((static_cast<::std::size_t>(1) << v) & state) {\n            const\
    \ auto prev_state = state & ~(static_cast<::std::size_t>(1) << v);\n         \
    \   for (::std::size_t u = 0; u < this->size(); ++u) {\n              if (this->m_graph[u][v]\
    \ < ::std::numeric_limits<::std::size_t>::max()) {\n                if (dp[prev_state][u]\
    \ < ::std::numeric_limits<T>::max()) {\n                  ::tools::chmin(dp[state][v],\
    \ dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost);\n            \
    \    }\n              }\n            }\n          }\n        }\n      }\n\n  \
    \    ::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>>\
    \ res;\n      auto& [total_cost, vids, eids] = res;\n\n      total_cost = dp[::tools::pow2(this->size())\
    \ - 1][0];\n      if (total_cost == ::std::numeric_limits<T>::max()) return ::std::nullopt;\n\
    \n      ::std::size_t state = ::tools::pow2(this->size()) - 1;\n      ::std::size_t\
    \ v = 0;\n      while (state > 0) {\n        const auto prev_state = state & ~(static_cast<::std::size_t>(1)\
    \ << v);\n        for (::std::size_t u = 0; u < this->size(); ++u) {\n       \
    \   if (this->m_graph[u][v] < ::std::numeric_limits<::std::size_t>::max()) {\n\
    \            if (dp[prev_state][u] < ::std::numeric_limits<T>::max() && dp[state][v]\
    \ == dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost) {\n        \
    \      vids.push_back(u);\n              eids.push_back(this->m_graph[u][v]);\n\
    \              state = prev_state;\n              v = u;\n              break;\n\
    \            }\n          }\n        }\n      }\n\n      ::std::reverse(vids.begin(),\
    \ vids.end());\n      ::std::reverse(eids.begin(), eids.end());\n\n      return\
    \ res;\n    }\n  };\n}\n\n\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"\
    tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond) do {\\\
    \n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \"\
    \ << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n   \
    \ ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/ssize.hpp\"\
    \n\n\n\n#line 6 \"tools/ssize.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 8 \"tests/tsp.test.cpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll V, E;\n  std::cin >> V >> E;\n\
    \  tools::tsp<true, ll> graph(V);\n  for (ll i = 0; i < E; ++i) {\n    ll s, t,\
    \ d;\n    std::cin >> s >> t >> d;\n    graph.add_edge(s, t, d);\n  }\n\n  const\
    \ auto res = graph.query();\n  if (res) {\n    const auto& [answer, vids, eids]\
    \ = *res;\n    assert_that(tools::ssize(vids) == V);\n    assert_that(tools::ssize(eids)\
    \ == V);\n    ll sum = 0;\n    for (ll i = 0; i < V; ++i) {\n      assert_that(graph.get_edge(eids[i]).from\
    \ == vids[i]);\n      assert_that(graph.get_edge(eids[i]).to == vids[(i + 1) %\
    \ V]);\n      sum += graph.get_edge(eids[i]).cost;\n    }\n    assert_that(answer\
    \ == sum);\n    std::cout << answer << '\\n';\n  } else {\n    std::cout << -1\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A\"\n\n\
    #include <iostream>\n#include <cassert>\n#include \"tools/tsp.hpp\"\n#include\
    \ \"tools/assert_that.hpp\"\n#include \"tools/ssize.hpp\"\n\nusing ll = long long;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll V, E;\n  std::cin >> V >> E;\n  tools::tsp<true, ll> graph(V);\n  for (ll\
    \ i = 0; i < E; ++i) {\n    ll s, t, d;\n    std::cin >> s >> t >> d;\n    graph.add_edge(s,\
    \ t, d);\n  }\n\n  const auto res = graph.query();\n  if (res) {\n    const auto&\
    \ [answer, vids, eids] = *res;\n    assert_that(tools::ssize(vids) == V);\n  \
    \  assert_that(tools::ssize(eids) == V);\n    ll sum = 0;\n    for (ll i = 0;\
    \ i < V; ++i) {\n      assert_that(graph.get_edge(eids[i]).from == vids[i]);\n\
    \      assert_that(graph.get_edge(eids[i]).to == vids[(i + 1) % V]);\n      sum\
    \ += graph.get_edge(eids[i]).cost;\n    }\n    assert_that(answer == sum);\n \
    \   std::cout << answer << '\\n';\n  } else {\n    std::cout << -1 << '\\n';\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/tsp.hpp
  - tools/pow2.hpp
  - tools/chmin.hpp
  - tools/assert_that.hpp
  - tools/ssize.hpp
  isVerificationFile: true
  path: tests/tsp.test.cpp
  requiredBy: []
  timestamp: '2022-10-15 15:02:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tsp.test.cpp
layout: document
redirect_from:
- /verify/tests/tsp.test.cpp
- /verify/tests/tsp.test.cpp.html
title: tests/tsp.test.cpp
---
