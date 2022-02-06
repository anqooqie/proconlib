---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bipartite_matching.test.cpp
    title: tests/bipartite_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/bipartite_matching.hpp\"\n#include <cstddef>\n#include\
    \ <vector>\n#line 1 \"lib/ac-library/atcoder/maxflow.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#line 9 \"lib/ac-library/atcoder/maxflow.hpp\"\
    \n\n#line 1 \"lib/ac-library/atcoder/internal_queue.hpp\"\n\n\n\n#line 5 \"lib/ac-library/atcoder/internal_queue.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class T> struct simple_queue\
    \ {\n    std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) {\
    \ payload.reserve(n); }\n    int size() const { return int(payload.size()) - pos;\
    \ }\n    bool empty() const { return pos == int(payload.size()); }\n    void push(const\
    \ T& t) { payload.push_back(t); }\n    T& front() { return payload[pos]; }\n \
    \   void clear() {\n        payload.clear();\n        pos = 0;\n    }\n    void\
    \ pop() { pos++; }\n};\n\n}  // namespace internal\n\n}  // namespace atcoder\n\
    \n\n#line 11 \"lib/ac-library/atcoder/maxflow.hpp\"\n\nnamespace atcoder {\n\n\
    template <class Cap> struct mf_graph {\n  public:\n    mf_graph() : _n(0) {}\n\
    \    explicit mf_graph(int n) : _n(n), g(n) {}\n\n    int add_edge(int from, int\
    \ to, Cap cap) {\n        assert(0 <= from && from < _n);\n        assert(0 <=\
    \ to && to < _n);\n        assert(0 <= cap);\n        int m = int(pos.size());\n\
    \        pos.push_back({from, int(g[from].size())});\n        int from_id = int(g[from].size());\n\
    \        int to_id = int(g[to].size());\n        if (from == to) to_id++;\n  \
    \      g[from].push_back(_edge{to, to_id, cap});\n        g[to].push_back(_edge{from,\
    \ from_id, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int\
    \ m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) return res;\n            }\n  \
    \          level[v] = _n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n  private:\n    int _n;\n    struct _edge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 4 \"tools/bipartite_matching.hpp\"\n\nnamespace tools {\n  template\
    \ <typename E>\n  class bipartite_matching {\n  public:\n    struct edge {\n \
    \     ::std::size_t from;\n      ::std::size_t to;\n      E attribute;\n     \
    \ edge() = default;\n      edge(const ::tools::bipartite_matching<E>::edge&) =\
    \ default;\n      edge(::tools::bipartite_matching<E>::edge&&) = default;\n  \
    \    ~edge() = default;\n      ::tools::bipartite_matching<E>::edge& operator=(const\
    \ ::tools::bipartite_matching<E>::edge&) = default;\n      ::tools::bipartite_matching<E>::edge&\
    \ operator=(::tools::bipartite_matching<E>::edge&&) = default;\n      edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const E& attribute) :\n      \
    \  from(from), to(to), attribute(attribute) {\n      }\n    };\n\n  private:\n\
    \    ::std::size_t m_size1;\n    ::std::size_t m_size2;\n    ::atcoder::mf_graph<int>\
    \ m_graph;\n    ::std::vector<::tools::bipartite_matching<E>::edge> m_edges;\n\
    \n  public:\n    bipartite_matching() = default;\n    bipartite_matching(const\
    \ ::tools::bipartite_matching<E>&) = default;\n    bipartite_matching(::tools::bipartite_matching<E>&&)\
    \ = default;\n    ~bipartite_matching() = default;\n    ::tools::bipartite_matching<E>&\
    \ operator=(const ::tools::bipartite_matching<E>&) = default;\n    ::tools::bipartite_matching<E>&\
    \ operator=(::tools::bipartite_matching<E>&&) = default;\n\n    bipartite_matching(const\
    \ ::std::size_t& size1, const ::std::size_t& size2) :\n      m_size1(size1), m_size2(size2),\
    \ m_graph(size1 + size2 + 2) {\n      for (::std::size_t i = 0; i < size1; ++i)\
    \ {\n        this->m_graph.add_edge(size1 + size2, i, 1);\n      }\n      for\
    \ (::std::size_t i = 0; i < size2; ++i) {\n        this->m_graph.add_edge(size1\
    \ + i, size1 + size2 + 1, 1);\n      }\n    }\n\n    ::std::size_t size1() const\
    \ {\n      return this->m_size1;\n    }\n\n    ::std::size_t size2() const {\n\
    \      return this->m_size2;\n    }\n\n    void add_edge(const ::std::size_t&\
    \ i, const ::std::size_t& j, const E& e) {\n      this->m_graph.add_edge(i, this->m_size1\
    \ + j, 1);\n      this->m_edges.emplace_back(i, j, e);\n    }\n\n    ::std::vector<::tools::bipartite_matching<E>::edge>\
    \ query() {\n      ::std::vector<::tools::bipartite_matching<E>::edge> edges;\n\
    \n      this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2\
    \ + 1);\n      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {\n  \
    \      if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1)\
    \ {\n          edges.push_back(this->m_edges[i]);\n        }\n      }\n\n    \
    \  return edges;\n    }\n  };\n}\n"
  code: "#include <cstddef>\n#include <vector>\n#include \"atcoder/maxflow.hpp\"\n\
    \nnamespace tools {\n  template <typename E>\n  class bipartite_matching {\n \
    \ public:\n    struct edge {\n      ::std::size_t from;\n      ::std::size_t to;\n\
    \      E attribute;\n      edge() = default;\n      edge(const ::tools::bipartite_matching<E>::edge&)\
    \ = default;\n      edge(::tools::bipartite_matching<E>::edge&&) = default;\n\
    \      ~edge() = default;\n      ::tools::bipartite_matching<E>::edge& operator=(const\
    \ ::tools::bipartite_matching<E>::edge&) = default;\n      ::tools::bipartite_matching<E>::edge&\
    \ operator=(::tools::bipartite_matching<E>::edge&&) = default;\n      edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const E& attribute) :\n      \
    \  from(from), to(to), attribute(attribute) {\n      }\n    };\n\n  private:\n\
    \    ::std::size_t m_size1;\n    ::std::size_t m_size2;\n    ::atcoder::mf_graph<int>\
    \ m_graph;\n    ::std::vector<::tools::bipartite_matching<E>::edge> m_edges;\n\
    \n  public:\n    bipartite_matching() = default;\n    bipartite_matching(const\
    \ ::tools::bipartite_matching<E>&) = default;\n    bipartite_matching(::tools::bipartite_matching<E>&&)\
    \ = default;\n    ~bipartite_matching() = default;\n    ::tools::bipartite_matching<E>&\
    \ operator=(const ::tools::bipartite_matching<E>&) = default;\n    ::tools::bipartite_matching<E>&\
    \ operator=(::tools::bipartite_matching<E>&&) = default;\n\n    bipartite_matching(const\
    \ ::std::size_t& size1, const ::std::size_t& size2) :\n      m_size1(size1), m_size2(size2),\
    \ m_graph(size1 + size2 + 2) {\n      for (::std::size_t i = 0; i < size1; ++i)\
    \ {\n        this->m_graph.add_edge(size1 + size2, i, 1);\n      }\n      for\
    \ (::std::size_t i = 0; i < size2; ++i) {\n        this->m_graph.add_edge(size1\
    \ + i, size1 + size2 + 1, 1);\n      }\n    }\n\n    ::std::size_t size1() const\
    \ {\n      return this->m_size1;\n    }\n\n    ::std::size_t size2() const {\n\
    \      return this->m_size2;\n    }\n\n    void add_edge(const ::std::size_t&\
    \ i, const ::std::size_t& j, const E& e) {\n      this->m_graph.add_edge(i, this->m_size1\
    \ + j, 1);\n      this->m_edges.emplace_back(i, j, e);\n    }\n\n    ::std::vector<::tools::bipartite_matching<E>::edge>\
    \ query() {\n      ::std::vector<::tools::bipartite_matching<E>::edge> edges;\n\
    \n      this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2\
    \ + 1);\n      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {\n  \
    \      if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1)\
    \ {\n          edges.push_back(this->m_edges[i]);\n        }\n      }\n\n    \
    \  return edges;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2021-12-04 01:06:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bipartite_matching.test.cpp
documentation_of: tools/bipartite_matching.hpp
layout: document
title: Matching on bipartite graph
---

It calculates the maximum matching on a given bipartite graph.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
bipartite_matching<E> graph(::std::size_t n1, ::std::size_t n2);
```

It creates an bipartite graph with $0$ edges.
Vertices of the graph can be divided into two disjoint and independent sets $U$ and $V$.
$U$ consists of $n_1$ vertices and $V$ consists of $n_2$ vertices.

The type parameter `<E>` represents the type of the attribute of edges.

### Constraints
- None

### Time Complexity
- $O(n_1 + n_2)$

## size1
```cpp
std::size_t graph.size1();
```

It returns $n_1$.

### Constraints
- None

### Time Complexity
- $O(1)$

## size2
```cpp
std::size_t graph.size2();
```

It returns $n_2$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
void graph.add_edge(::std::size_t a, ::std::size_t b, E e);
```

It adds an edge from $a \in U$ to $b \in V$ with the attribute `e`.

### Constraints
- $0 \leq a < n_1$
- $0 \leq b < n_2$

### Time Complexity
- amortized $O(1)$

## query
```cpp
std::vector<struct {
  std::size_t from;
  std::size_t to;
  E attribute;
}> graph.query();
```

It returns edges which can reach the maximum matching. 

### Constraints
- None

### Time Complexity
- $O\left((n_1 + n_2)^\frac{3}{2} + \min\left((n_1 + n_2)^\frac{2}{3} m, m^\frac{3}{2}\right)\right)$ where $m$ is the number of edges