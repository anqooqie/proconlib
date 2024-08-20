---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/join.hpp
    title: Join elements with delimiter
  - icon: ':heavy_check_mark:'
    path: tools/tree_diameter.hpp
    title: Diameter of a tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"tests/tree_diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#line 1 \"tools/tree_diameter.hpp\"\
    \n\n\n\n#line 5 \"tools/tree_diameter.hpp\"\n#include <cstddef>\n#line 7 \"tools/tree_diameter.hpp\"\
    \n#include <cassert>\n#include <tuple>\n#include <limits>\n#include <queue>\n\
    #include <iterator>\n#include <algorithm>\n#line 1 \"tools/chmin.hpp\"\n\n\n\n\
    #include <type_traits>\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 6 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated\
    \ = rhs < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 14 \"tools/tree_diameter.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class tree_diameter {\n  private:\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    ::std::vector<::std::pair<::std::size_t, T>> m_edges;\n\n  public:\n\
    \    tree_diameter() = default;\n    tree_diameter(const ::tools::tree_diameter<T>&)\
    \ = default;\n    tree_diameter(::tools::tree_diameter<T>&&) = default;\n    ~tree_diameter()\
    \ = default;\n    ::tools::tree_diameter<T>& operator=(const ::tools::tree_diameter<T>&)\
    \ = default;\n    ::tools::tree_diameter<T>& operator=(::tools::tree_diameter<T>&&)\
    \ = default;\n\n    explicit tree_diameter(const ::std::size_t n) :\n      m_graph(n)\
    \ {\n      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(const ::std::size_t\
    \ u, const ::std::size_t v, const T& w) {\n      assert(u < this->size());\n \
    \     assert(v < this->size());\n\n      this->m_graph[u].push_back(this->m_edges.size());\n\
    \      this->m_graph[v].push_back(this->m_edges.size());\n      this->m_edges.emplace_back(u\
    \ ^ v, w);\n      return this->m_edges.size() - 1;\n    }\n\n    ::std::tuple<T,\
    \ ::std::vector<::std::size_t>, ::std::vector<::std::size_t>> query() const {\n\
    \      assert(this->m_edges.size() + 1 == this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[0] = 0;\n \
    \     ::std::queue<::std::size_t> queue({0});\n      while (!queue.empty()) {\n\
    \        const auto here = queue.front();\n        queue.pop();\n        for (const\
    \ auto eid : this->m_graph[here]) {\n          const auto next = this->m_edges[eid].first\
    \ ^ here;\n          const auto w = this->m_edges[eid].second;\n          if (::tools::chmin(dist[next],\
    \ dist[here] + w)) {\n            queue.push(next);\n          }\n        }\n\
    \      }\n\n      queue.push(::std::distance(dist.begin(), ::std::max_element(dist.begin(),\
    \ dist.end())));\n      ::std::fill(dist.begin(), dist.end(), ::std::numeric_limits<T>::max());\n\
    \      dist[queue.front()] = 0;\n      ::std::vector<::std::size_t> prev(this->size(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      while (!queue.empty())\
    \ {\n        const auto here = queue.front();\n        queue.pop();\n        for\
    \ (const auto eid : this->m_graph[here]) {\n          const auto next = this->m_edges[eid].first\
    \ ^ here;\n          const auto w = this->m_edges[eid].second;\n          if (::tools::chmin(dist[next],\
    \ dist[here] + w)) {\n            prev[next] = eid;\n            queue.push(next);\n\
    \          }\n        }\n      }\n\n      ::std::tuple<T, ::std::vector<::std::size_t>,\
    \ ::std::vector<::std::size_t>> result;\n      ::std::get<0>(result) = 0;\n  \
    \    ::std::size_t v;\n      for (v = ::std::distance(dist.begin(), ::std::max_element(dist.begin(),\
    \ dist.end())); prev[v] != ::std::numeric_limits<::std::size_t>::max(); v = this->m_edges[prev[v]].first\
    \ ^ v) {\n        ::std::get<0>(result) += this->m_edges[prev[v]].second;\n  \
    \      ::std::get<1>(result).push_back(v);\n        ::std::get<2>(result).push_back(prev[v]);\n\
    \      }\n      ::std::get<1>(result).push_back(v);\n      return result;\n  \
    \  }\n  };\n}\n\n\n#line 1 \"tools/join.hpp\"\n\n\n\n#include <string>\n#include\
    \ <sstream>\n#line 7 \"tools/join.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ Iterator>\n  ::std::string join(const Iterator begin, const Iterator end, const\
    \ ::std::string& delimiter) {\n    ::std::ostringstream ss;\n    if (begin !=\
    \ end) {\n      ss << *begin;\n      for (auto it = ::std::next(begin); it !=\
    \ end; ++it) {\n        ss << delimiter << *it;\n      }\n    }\n    return ss.str();\n\
    \  }\n\n  template <typename Iterator, typename F>\n  ::std::string join(const\
    \ Iterator begin, const Iterator end, const F& mapper, const ::std::string& delimiter)\
    \ {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss << mapper(*begin);\n\
    \      for (auto it = ::std::next(begin); it != end; ++it) {\n        ss << delimiter\
    \ << mapper(*it);\n      }\n    }\n    return ss.str();\n  }\n}\n\n\n#line 8 \"\
    tests/tree_diameter.test.cpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll N;\n  std::cin >> N;\n  tools::tree_diameter<ll>\
    \ tree(N);\n  std::vector<std::pair<ll, ll>> edges;\n  for (ll i = 0; i < N -\
    \ 1; ++i) {\n    ll a, b, c;\n    std::cin >> a >> b >> c;\n    tree.add_edge(a,\
    \ b, c);\n    edges.emplace_back(a, b);\n  }\n\n  const auto [X, u, unused] =\
    \ tree.query();\n  std::cout << X << ' ' << u.size() << '\\n';\n  std::cout <<\
    \ ::tools::join(u.begin(), u.end(), \" \") << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <utility>\n#include \"tools/tree_diameter.hpp\"\
    \n#include \"tools/join.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll N;\n  std::cin >> N;\n  tools::tree_diameter<ll>\
    \ tree(N);\n  std::vector<std::pair<ll, ll>> edges;\n  for (ll i = 0; i < N -\
    \ 1; ++i) {\n    ll a, b, c;\n    std::cin >> a >> b >> c;\n    tree.add_edge(a,\
    \ b, c);\n    edges.emplace_back(a, b);\n  }\n\n  const auto [X, u, unused] =\
    \ tree.query();\n  std::cout << X << ' ' << u.size() << '\\n';\n  std::cout <<\
    \ ::tools::join(u.begin(), u.end(), \" \") << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/tree_diameter.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/join.hpp
  isVerificationFile: true
  path: tests/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-04-06 03:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/tests/tree_diameter.test.cpp
- /verify/tests/tree_diameter.test.cpp.html
title: tests/tree_diameter.test.cpp
---
