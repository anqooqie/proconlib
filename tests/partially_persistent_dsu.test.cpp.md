---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':heavy_check_mark:'
    path: tools/partially_persistent_dsu.hpp
    title: Partially persistent disjoint set union
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/agc002/tasks/agc002_d
    links:
    - https://atcoder.jp/contests/agc002/tasks/agc002_d
  bundledCode: "#line 1 \"tests/partially_persistent_dsu.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\n\n#include <iostream>\n\
    #line 1 \"tools/partially_persistent_dsu.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <utility>\n#include <limits>\n#include <cassert>\n#include <algorithm>\n#include\
    \ <queue>\n#line 1 \"tools/less_by_first.hpp\"\n\n\n\n#line 5 \"tools/less_by_first.hpp\"\
    \n\nnamespace tools {\n\n  class less_by_first {\n  public:\n    template <class\
    \ T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.first < y.first;\n    }\n  };\n}\n\n\n#line\
    \ 11 \"tools/partially_persistent_dsu.hpp\"\n\nnamespace tools {\n  class partially_persistent_dsu\
    \ {\n  private:\n    int m_now;\n    ::std::vector<::std::pair<int, int>> m_parents;\n\
    \    ::std::vector<int> m_ranks;\n    ::std::vector<::std::vector<::std::pair<int,\
    \ int>>> m_sizes;\n\n    int size() const {\n      return this->m_parents.size();\n\
    \    }\n\n  public:\n    partially_persistent_dsu() = default;\n    partially_persistent_dsu(const\
    \ ::tools::partially_persistent_dsu&) = default;\n    partially_persistent_dsu(::tools::partially_persistent_dsu&&)\
    \ = default;\n    ~partially_persistent_dsu() = default;\n    ::tools::partially_persistent_dsu&\
    \ operator=(const ::tools::partially_persistent_dsu&) = default;\n    ::tools::partially_persistent_dsu&\
    \ operator=(::tools::partially_persistent_dsu&&) = default;\n\n    explicit partially_persistent_dsu(const\
    \ int n) :\n      m_now(0),\n      m_parents(n, ::std::make_pair(::std::numeric_limits<int>::max(),\
    \ -1)),\n      m_ranks(n, 0),\n      m_sizes(n, ::std::vector<::std::pair<int,\
    \ int>>{::std::make_pair(0, 1)}) {\n    }\n\n    int now() const {\n      return\
    \ this->m_now;\n    }\n\n    int leader(const int t, const int x) const {\n  \
    \    assert(0 <= t && t <= this->m_now);\n      assert(0 <= x && x < this->size());\n\
    \n      return t < this->m_parents[x].first ? x : this->leader(t, this->m_parents[x].second);\n\
    \    }\n\n    bool same(const int t, const int x, const int y) const {\n     \
    \ assert(0 <= t && t <= this->m_now);\n      assert(0 <= x && x < this->size());\n\
    \      assert(0 <= y && y < this->size());\n\n      return this->leader(t, x)\
    \ == this->leader(t, y);\n    }\n\n    int merge(int x, int y) {\n      assert(0\
    \ <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\n  \
    \    ++this->m_now;\n\n      x = this->leader(this->m_now, x);\n      y = this->leader(this->m_now,\
    \ y);\n      if (x == y) return x;\n\n      if (this->m_ranks[x] < this->m_ranks[y])\
    \ ::std::swap(x, y);\n\n      this->m_parents[y] = ::std::make_pair(this->m_now,\
    \ x);\n      if (this->m_ranks[x] == this->m_ranks[y]) ++this->m_ranks[x];\n \
    \     this->m_sizes[x].emplace_back(this->m_now, this->m_sizes[x].back().second\
    \ + this->m_sizes[y].back().second);\n\n      return x;\n    }\n\n    int size(const\
    \ int t, int x) const {\n      assert(0 <= t && t <= this->m_now);\n      assert(0\
    \ <= x && x < this->size());\n\n      x = this->leader(t, x);\n      auto it =\
    \ ::std::upper_bound(this->m_sizes[x].begin(), this->m_sizes[x].end(), ::std::make_pair(t,\
    \ 0), ::tools::less_by_first());\n      --it;\n      return it->second;\n    }\n\
    \n    ::std::vector<::std::vector<int>> groups(const int t) const {\n      assert(0\
    \ <= t && t <= this->m_now);\n\n      ::std::vector<::std::vector<int>> graph(this->size());\n\
    \      for (int i = 0; i < this->size(); ++i) {\n        if (this->m_parents[i].first\
    \ <= t) graph[this->m_parents[i].second].push_back(i);\n      }\n\n      ::std::vector<::std::vector<int>>\
    \ res(this->size());\n      for (int root = 0; root < this->size(); ++root) {\n\
    \        if (t < this->m_parents[root].first) {\n          ::std::queue<int> queue({root});\n\
    \          while (!queue.empty()) {\n            const auto here = queue.front();\n\
    \            queue.pop();\n            res[root].push_back(here);\n          \
    \  for (const auto next : graph[here]) {\n              queue.push(next);\n  \
    \          }\n          }\n        }\n      }\n\n      res.erase(::std::remove_if(res.begin(),\
    \ res.end(), [](const auto& group) { return group.empty(); }), res.end());\n \
    \     return res;\n    }\n  };\n}\n\n\n#line 5 \"tests/partially_persistent_dsu.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, M;\n  std::cin >> N >> M;\n  tools::partially_persistent_dsu dsu(N);\n\
    \  for (int i = 0; i < M; ++i) {\n    int a, b;\n    std::cin >> a >> b;\n   \
    \ --a, --b;\n    dsu.merge(a, b);\n  }\n\n  int Q;\n  std::cin >> Q;\n  for (int\
    \ q = 0; q < Q; ++q) {\n    int x, y, z;\n    std::cin >> x >> y >> z;\n    --x,\
    \ --y;\n\n    int ng = 0;\n    int ok = M;\n    while (ok - ng > 1) {\n      const\
    \ auto t = (ng + ok) / 2;\n      if (z <= dsu.size(t, x) + (dsu.same(t, x, y)\
    \ ? 0 : dsu.size(t, y))) {\n        ok = t;\n      } else {\n        ng = t;\n\
    \      }\n    }\n\n    std::cout << ok << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\n\n\
    #include <iostream>\n#include \"tools/partially_persistent_dsu.hpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  int\
    \ N, M;\n  std::cin >> N >> M;\n  tools::partially_persistent_dsu dsu(N);\n  for\
    \ (int i = 0; i < M; ++i) {\n    int a, b;\n    std::cin >> a >> b;\n    --a,\
    \ --b;\n    dsu.merge(a, b);\n  }\n\n  int Q;\n  std::cin >> Q;\n  for (int q\
    \ = 0; q < Q; ++q) {\n    int x, y, z;\n    std::cin >> x >> y >> z;\n    --x,\
    \ --y;\n\n    int ng = 0;\n    int ok = M;\n    while (ok - ng > 1) {\n      const\
    \ auto t = (ng + ok) / 2;\n      if (z <= dsu.size(t, x) + (dsu.same(t, x, y)\
    \ ? 0 : dsu.size(t, y))) {\n        ok = t;\n      } else {\n        ng = t;\n\
    \      }\n    }\n\n    std::cout << ok << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/partially_persistent_dsu.hpp
  - tools/less_by_first.hpp
  isVerificationFile: true
  path: tests/partially_persistent_dsu.test.cpp
  requiredBy: []
  timestamp: '2023-01-28 13:52:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/partially_persistent_dsu.test.cpp
layout: document
redirect_from:
- /verify/tests/partially_persistent_dsu.test.cpp
- /verify/tests/partially_persistent_dsu.test.cpp.html
title: tests/partially_persistent_dsu.test.cpp
---
