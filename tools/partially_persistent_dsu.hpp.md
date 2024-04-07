---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/less_by_first.hpp
    title: std::less by first
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/partially_persistent_dsu.test.cpp
    title: tests/partially_persistent_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/partially_persistent_dsu.hpp\"\n\n\n\n#include <vector>\n\
    #include <utility>\n#include <limits>\n#include <cassert>\n#include <algorithm>\n\
    #include <queue>\n#line 1 \"tools/less_by_first.hpp\"\n\n\n\n#line 5 \"tools/less_by_first.hpp\"\
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
    \     return res;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PARTIALLY_PERSISTENT_DSU_HPP\n#define TOOLS_PARTIALLY_PERSISTENT_DSU_HPP\n\
    \n#include <vector>\n#include <utility>\n#include <limits>\n#include <cassert>\n\
    #include <algorithm>\n#include <queue>\n#include \"tools/less_by_first.hpp\"\n\
    \nnamespace tools {\n  class partially_persistent_dsu {\n  private:\n    int m_now;\n\
    \    ::std::vector<::std::pair<int, int>> m_parents;\n    ::std::vector<int> m_ranks;\n\
    \    ::std::vector<::std::vector<::std::pair<int, int>>> m_sizes;\n\n    int size()\
    \ const {\n      return this->m_parents.size();\n    }\n\n  public:\n    partially_persistent_dsu()\
    \ = default;\n    partially_persistent_dsu(const ::tools::partially_persistent_dsu&)\
    \ = default;\n    partially_persistent_dsu(::tools::partially_persistent_dsu&&)\
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
    \     return res;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/less_by_first.hpp
  isVerificationFile: false
  path: tools/partially_persistent_dsu.hpp
  requiredBy: []
  timestamp: '2023-01-28 13:52:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/partially_persistent_dsu.test.cpp
documentation_of: tools/partially_persistent_dsu.hpp
layout: document
title: Partially persistent disjoint set union
---

Given an undirected graph, it processes the following queries in $O(\log(n))$ time.

- Edge addition
- Deciding whether given two vertices were in the same connected component at the specified time

Each connected component internally has a representative vertex.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
partially_persistent_dsu d(int n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## now
```cpp
int d.now();
```

It returns the number of times that `d.merge` has been called so far.

### Constraints
- None

### Time Complexity
- $O(1)$

## merge
```cpp
int d.merge(int a, int b);
```

It adds an edge $(a, b)$.

If the vertices $a$ and $b$ were in the same connected component, it returns the representative of this connected component.
Otherwise, it returns the representative of the new connected component.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\log n)$

## same
```cpp
bool d.same(int t, int a, int b);
```

It returns whether the vertices $a$ and $b$ were in the same connected component at the time when `d.now() == t`.

### Constraints
- $0 \leq t \leq$ `d.now()`
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\log n)$

## leader
```cpp
int d.leader(int t, int a);
```

It returns the representative of the connected component that contained the vertex $a$ at the time when `d.now() == t`.

### Constraints
- $0 \leq t \leq$ `d.now()`
- $0 \leq a < n$

### Time Complexity
- $O(\log n)$

## size
```cpp
int d.size(int t, int a);
```

It returns the size of the connected component that contained the vertex $a$ at the time when `d.now() == t`.

### Constraints
- $0 \leq t \leq$ `d.now()`
- $0 \leq a < n$

### Time Complexity
- $O(\log n)$

## groups
```cpp
std::vector<std::vector<int>> d.groups(int t);
```

It divides the graph at the time when `d.now() == t` into connected components and returns the list of them.

More precisely, it returns the list of the "list of the vertices in a connected component".
Both of the orders of the connected components and the vertices are undefined.

### Constraints
- $0 \leq t \leq$ `d.now()`

### Time Complexity
- $O(n)$
