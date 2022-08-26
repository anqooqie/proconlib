---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/rerooting_dp.test.cpp
    title: tests/rerooting_dp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/rerooting_dp.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <cassert>\n#include <limits>\n#include <stack>\n#include\
    \ <tuple>\n#include <algorithm>\n\nnamespace tools {\n  template <typename R,\
    \ typename M, typename F_VE, typename F_EV>\n  class rerooting_dp {\n  private:\n\
    \    ::std::vector<::std::size_t> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    F_VE m_f_ve;\n    F_EV m_f_ev;\n\n    class vertex {\n    private:\n\
    \      const ::tools::rerooting_dp<R, M, F_VE, F_EV> *m_self;\n\n    public:\n\
    \      ::std::size_t id;\n      ::std::size_t neighbor_id_of_parent;\n      ::std::vector<::std::size_t>\
    \ neighbor_ids_of_children;\n      typename M::T parent_dp;\n      ::std::vector<typename\
    \ M::T> children_dp;\n      ::std::vector<typename M::T> children_dp_cumsum1;\n\
    \      ::std::vector<typename M::T> children_dp_cumsum2;\n\n      vertex() = default;\n\
    \      vertex(const vertex&) = default;\n      vertex(vertex&&) = default;\n \
    \     ~vertex() = default;\n      vertex& operator=(const vertex&) = default;\n\
    \      vertex& operator=(vertex&&) = default;\n\n      explicit vertex(const ::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV> * const self, const ::std::size_t id) :\n        m_self(self),\
    \ id(id), parent_dp(M::e()) {\n      }\n\n      ::std::size_t parent_edge_id()\
    \ const {\n        return this->m_self->m_graph[this->id][this->neighbor_id_of_parent];\n\
    \      }\n      ::std::size_t parent_vertex_id() const {\n        return this->m_self->m_edges[this->parent_edge_id()]\
    \ ^ this->id;\n      }\n      ::std::size_t child_size() const {\n        return\
    \ this->neighbor_ids_of_children.size();\n      }\n      ::std::size_t child_edge_id(const\
    \ ::std::size_t child_number) const {\n        return this->m_self->m_graph[this->id][this->neighbor_ids_of_children[child_number]];\n\
    \      }\n      ::std::size_t child_vertex_id(const ::std::size_t child_number)\
    \ const {\n        return this->m_self->m_edges[this->child_edge_id(child_number)]\
    \ ^ this->id;\n      }\n      R dp_as_root() const {\n        return this->m_self->m_f_ev(M::op(this->parent_dp,\
    \ this->children_dp_cumsum1.back()), this->id);\n      }\n      R dp_excluding_parent()\
    \ const {\n        return this->m_self->m_f_ev(this->children_dp_cumsum1.back(),\
    \ this->id);\n      }\n      R dp_excluding_child(const ::std::size_t excluded_child_number)\
    \ const {\n        return this->m_self->m_f_ev(M::op(this->parent_dp, M::op(this->children_dp_cumsum1[excluded_child_number],\
    \ this->children_dp_cumsum2[excluded_child_number + 1])), this->id);\n      }\n\
    \    };\n\n  public:\n    rerooting_dp() = default;\n    rerooting_dp(const ::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV>&) = default;\n    rerooting_dp(::tools::rerooting_dp<R, M, F_VE,\
    \ F_EV>&&) = default;\n    ~rerooting_dp() = default;\n    ::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV>& operator=(const ::tools::rerooting_dp<R, M, F_VE, F_EV>&) =\
    \ default;\n    ::tools::rerooting_dp<R, M, F_VE, F_EV>& operator=(::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV>&&) = default;\n\n    rerooting_dp(const ::std::size_t n, const\
    \ F_VE& f_ve, const F_EV& f_ev) : m_graph(n), m_f_ve(f_ve), m_f_ev(f_ev) {\n \
    \     assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(const ::std::size_t\
    \ u, const ::std::size_t v) {\n      this->m_graph[u].push_back(this->m_edges.size());\n\
    \      this->m_graph[v].push_back(this->m_edges.size());\n      this->m_edges.push_back(u\
    \ ^ v);\n      return this->m_edges.size() - 1;\n    }\n\n    ::std::vector<R>\
    \ query() const {\n      const int PRE_VERTEX = 1;\n      const int POST_EDGE\
    \ = 2;\n      const int POST_VERTEX = 3;\n      const ::std::size_t INVALID =\
    \ ::std::numeric_limits<::std::size_t>::max();\n\n      ::std::vector<vertex>\
    \ vertices;\n      for (::std::size_t i = 0; i < this->size(); ++i) {\n      \
    \  vertices.emplace_back(this, i);\n      }\n\n      ::std::stack<::std::tuple<int,\
    \ ::std::size_t, ::std::size_t>> stack;\n      ::std::vector<bool> will_visit(this->size(),\
    \ false);\n      stack.emplace(PRE_VERTEX, 0, INVALID);\n      will_visit[0] =\
    \ true;\n      while (!stack.empty()) {\n        const int type = ::std::get<0>(stack.top());\n\
    \        if (type == PRE_VERTEX) {\n\n          const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n          stack.pop();\n\n          vertex& v\
    \ = vertices[vertex_id];\n          stack.emplace(POST_VERTEX, vertex_id, INVALID);\n\
    \          for (::std::size_t neighbor_id = 0; neighbor_id < this->m_graph[vertex_id].size();\
    \ ++neighbor_id) {\n            const ::std::size_t child_vertex_id = this->m_edges[this->m_graph[vertex_id][neighbor_id]]\
    \ ^ vertex_id;\n            if (will_visit[child_vertex_id]) {\n             \
    \ v.neighbor_id_of_parent = neighbor_id;\n            } else {\n             \
    \ v.neighbor_ids_of_children.push_back(neighbor_id);\n              stack.emplace(POST_EDGE,\
    \ vertex_id, v.child_size() - 1);\n              stack.emplace(PRE_VERTEX, child_vertex_id,\
    \ INVALID);\n              will_visit[child_vertex_id] = true;\n            }\n\
    \          }\n          v.children_dp.resize(v.child_size());\n\n        } else\
    \ if (type == POST_EDGE) {\n\n          const ::std::size_t vertex_id = ::std::get<1>(stack.top());\n\
    \          const ::std::size_t child_number = ::std::get<2>(stack.top());\n  \
    \        stack.pop();\n\n          vertex& v = vertices[vertex_id];\n        \
    \  const vertex& c = vertices[v.child_vertex_id(child_number)];\n          v.children_dp[child_number]\
    \ = this->m_f_ve(c.dp_excluding_parent(), v.child_edge_id(child_number));\n\n\
    \        } else { // POST_VERTEX\n\n          const ::std::size_t vertex_id =\
    \ ::std::get<1>(stack.top());\n          stack.pop();\n\n          vertex& v =\
    \ vertices[vertex_id];\n\n          v.children_dp_cumsum1.reserve(v.child_size()\
    \ + 1);\n          v.children_dp_cumsum1.push_back(M::e());\n          for (::std::size_t\
    \ child_number = 0; child_number < v.child_size(); ++child_number) {\n       \
    \     v.children_dp_cumsum1.push_back(M::op(v.children_dp_cumsum1.back(), v.children_dp[child_number]));\n\
    \          }\n\n          v.children_dp_cumsum2.reserve(v.child_size() + 1);\n\
    \          v.children_dp_cumsum2.push_back(M::e());\n          for (::std::size_t\
    \ child_number = v.child_size(); child_number --> 0;) {\n            v.children_dp_cumsum2.push_back(M::op(v.children_dp[child_number],\
    \ v.children_dp_cumsum2.back()));\n          }\n          ::std::reverse(v.children_dp_cumsum2.begin(),\
    \ v.children_dp_cumsum2.end());\n\n        }\n      }\n\n      stack.emplace(PRE_VERTEX,\
    \ 0, INVALID);\n      while (!stack.empty()) {\n        const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n        stack.pop();\n\n        const vertex&\
    \ v = vertices[vertex_id];\n        for (::std::size_t child_number = 0; child_number\
    \ < v.child_size(); ++child_number) {\n          vertex& c = vertices[v.child_vertex_id(child_number)];\n\
    \          c.parent_dp = this->m_f_ve(v.dp_excluding_child(child_number), c.parent_edge_id());\n\
    \          stack.emplace(PRE_VERTEX, c.id, INVALID);\n        }\n      }\n\n \
    \     ::std::vector<R> result;\n      result.reserve(this->size());\n      for\
    \ (const vertex& v : vertices) {\n        result.push_back(v.dp_as_root());\n\
    \      }\n      return result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_REROOTING_DP_HPP\n#define TOOLS_REROOTING_DP_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <cassert>\n#include <limits>\n#include\
    \ <stack>\n#include <tuple>\n#include <algorithm>\n\nnamespace tools {\n  template\
    \ <typename R, typename M, typename F_VE, typename F_EV>\n  class rerooting_dp\
    \ {\n  private:\n    ::std::vector<::std::size_t> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    F_VE m_f_ve;\n    F_EV m_f_ev;\n\n    class vertex {\n    private:\n\
    \      const ::tools::rerooting_dp<R, M, F_VE, F_EV> *m_self;\n\n    public:\n\
    \      ::std::size_t id;\n      ::std::size_t neighbor_id_of_parent;\n      ::std::vector<::std::size_t>\
    \ neighbor_ids_of_children;\n      typename M::T parent_dp;\n      ::std::vector<typename\
    \ M::T> children_dp;\n      ::std::vector<typename M::T> children_dp_cumsum1;\n\
    \      ::std::vector<typename M::T> children_dp_cumsum2;\n\n      vertex() = default;\n\
    \      vertex(const vertex&) = default;\n      vertex(vertex&&) = default;\n \
    \     ~vertex() = default;\n      vertex& operator=(const vertex&) = default;\n\
    \      vertex& operator=(vertex&&) = default;\n\n      explicit vertex(const ::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV> * const self, const ::std::size_t id) :\n        m_self(self),\
    \ id(id), parent_dp(M::e()) {\n      }\n\n      ::std::size_t parent_edge_id()\
    \ const {\n        return this->m_self->m_graph[this->id][this->neighbor_id_of_parent];\n\
    \      }\n      ::std::size_t parent_vertex_id() const {\n        return this->m_self->m_edges[this->parent_edge_id()]\
    \ ^ this->id;\n      }\n      ::std::size_t child_size() const {\n        return\
    \ this->neighbor_ids_of_children.size();\n      }\n      ::std::size_t child_edge_id(const\
    \ ::std::size_t child_number) const {\n        return this->m_self->m_graph[this->id][this->neighbor_ids_of_children[child_number]];\n\
    \      }\n      ::std::size_t child_vertex_id(const ::std::size_t child_number)\
    \ const {\n        return this->m_self->m_edges[this->child_edge_id(child_number)]\
    \ ^ this->id;\n      }\n      R dp_as_root() const {\n        return this->m_self->m_f_ev(M::op(this->parent_dp,\
    \ this->children_dp_cumsum1.back()), this->id);\n      }\n      R dp_excluding_parent()\
    \ const {\n        return this->m_self->m_f_ev(this->children_dp_cumsum1.back(),\
    \ this->id);\n      }\n      R dp_excluding_child(const ::std::size_t excluded_child_number)\
    \ const {\n        return this->m_self->m_f_ev(M::op(this->parent_dp, M::op(this->children_dp_cumsum1[excluded_child_number],\
    \ this->children_dp_cumsum2[excluded_child_number + 1])), this->id);\n      }\n\
    \    };\n\n  public:\n    rerooting_dp() = default;\n    rerooting_dp(const ::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV>&) = default;\n    rerooting_dp(::tools::rerooting_dp<R, M, F_VE,\
    \ F_EV>&&) = default;\n    ~rerooting_dp() = default;\n    ::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV>& operator=(const ::tools::rerooting_dp<R, M, F_VE, F_EV>&) =\
    \ default;\n    ::tools::rerooting_dp<R, M, F_VE, F_EV>& operator=(::tools::rerooting_dp<R,\
    \ M, F_VE, F_EV>&&) = default;\n\n    rerooting_dp(const ::std::size_t n, const\
    \ F_VE& f_ve, const F_EV& f_ev) : m_graph(n), m_f_ve(f_ve), m_f_ev(f_ev) {\n \
    \     assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(const ::std::size_t\
    \ u, const ::std::size_t v) {\n      this->m_graph[u].push_back(this->m_edges.size());\n\
    \      this->m_graph[v].push_back(this->m_edges.size());\n      this->m_edges.push_back(u\
    \ ^ v);\n      return this->m_edges.size() - 1;\n    }\n\n    ::std::vector<R>\
    \ query() const {\n      const int PRE_VERTEX = 1;\n      const int POST_EDGE\
    \ = 2;\n      const int POST_VERTEX = 3;\n      const ::std::size_t INVALID =\
    \ ::std::numeric_limits<::std::size_t>::max();\n\n      ::std::vector<vertex>\
    \ vertices;\n      for (::std::size_t i = 0; i < this->size(); ++i) {\n      \
    \  vertices.emplace_back(this, i);\n      }\n\n      ::std::stack<::std::tuple<int,\
    \ ::std::size_t, ::std::size_t>> stack;\n      ::std::vector<bool> will_visit(this->size(),\
    \ false);\n      stack.emplace(PRE_VERTEX, 0, INVALID);\n      will_visit[0] =\
    \ true;\n      while (!stack.empty()) {\n        const int type = ::std::get<0>(stack.top());\n\
    \        if (type == PRE_VERTEX) {\n\n          const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n          stack.pop();\n\n          vertex& v\
    \ = vertices[vertex_id];\n          stack.emplace(POST_VERTEX, vertex_id, INVALID);\n\
    \          for (::std::size_t neighbor_id = 0; neighbor_id < this->m_graph[vertex_id].size();\
    \ ++neighbor_id) {\n            const ::std::size_t child_vertex_id = this->m_edges[this->m_graph[vertex_id][neighbor_id]]\
    \ ^ vertex_id;\n            if (will_visit[child_vertex_id]) {\n             \
    \ v.neighbor_id_of_parent = neighbor_id;\n            } else {\n             \
    \ v.neighbor_ids_of_children.push_back(neighbor_id);\n              stack.emplace(POST_EDGE,\
    \ vertex_id, v.child_size() - 1);\n              stack.emplace(PRE_VERTEX, child_vertex_id,\
    \ INVALID);\n              will_visit[child_vertex_id] = true;\n            }\n\
    \          }\n          v.children_dp.resize(v.child_size());\n\n        } else\
    \ if (type == POST_EDGE) {\n\n          const ::std::size_t vertex_id = ::std::get<1>(stack.top());\n\
    \          const ::std::size_t child_number = ::std::get<2>(stack.top());\n  \
    \        stack.pop();\n\n          vertex& v = vertices[vertex_id];\n        \
    \  const vertex& c = vertices[v.child_vertex_id(child_number)];\n          v.children_dp[child_number]\
    \ = this->m_f_ve(c.dp_excluding_parent(), v.child_edge_id(child_number));\n\n\
    \        } else { // POST_VERTEX\n\n          const ::std::size_t vertex_id =\
    \ ::std::get<1>(stack.top());\n          stack.pop();\n\n          vertex& v =\
    \ vertices[vertex_id];\n\n          v.children_dp_cumsum1.reserve(v.child_size()\
    \ + 1);\n          v.children_dp_cumsum1.push_back(M::e());\n          for (::std::size_t\
    \ child_number = 0; child_number < v.child_size(); ++child_number) {\n       \
    \     v.children_dp_cumsum1.push_back(M::op(v.children_dp_cumsum1.back(), v.children_dp[child_number]));\n\
    \          }\n\n          v.children_dp_cumsum2.reserve(v.child_size() + 1);\n\
    \          v.children_dp_cumsum2.push_back(M::e());\n          for (::std::size_t\
    \ child_number = v.child_size(); child_number --> 0;) {\n            v.children_dp_cumsum2.push_back(M::op(v.children_dp[child_number],\
    \ v.children_dp_cumsum2.back()));\n          }\n          ::std::reverse(v.children_dp_cumsum2.begin(),\
    \ v.children_dp_cumsum2.end());\n\n        }\n      }\n\n      stack.emplace(PRE_VERTEX,\
    \ 0, INVALID);\n      while (!stack.empty()) {\n        const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n        stack.pop();\n\n        const vertex&\
    \ v = vertices[vertex_id];\n        for (::std::size_t child_number = 0; child_number\
    \ < v.child_size(); ++child_number) {\n          vertex& c = vertices[v.child_vertex_id(child_number)];\n\
    \          c.parent_dp = this->m_f_ve(v.dp_excluding_child(child_number), c.parent_edge_id());\n\
    \          stack.emplace(PRE_VERTEX, c.id, INVALID);\n        }\n      }\n\n \
    \     ::std::vector<R> result;\n      result.reserve(this->size());\n      for\
    \ (const vertex& v : vertices) {\n        result.push_back(v.dp_as_root());\n\
    \      }\n      return result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/rerooting_dp.hpp
  requiredBy: []
  timestamp: '2022-08-26 16:40:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/rerooting_dp.test.cpp
documentation_of: tools/rerooting_dp.hpp
layout: document
title: Dynamic programming on trees with rerooting technique
---

It is an abstract framework for the dynamic programming on trees with rerooting technique.

### Example
It calculates the diameter of a given tree.

```cpp
struct monoid {
  using T = int;
  static T op(const T x, const T y) {
    return std::max(x, y);
  }
  static T e() {
    return 0;
  }
};

int main() {
  int n;
  std::cin >> n;

  std::vector<int> costs;
  const auto f_ve = [&](const int dist, const std::size_t edge_id) {
    return dist + costs[edge_id];
  };
  const auto f_ev = [](const int dist, std::size_t) {
    return dist;
  };

  tools::rerooting_dp<int, monoid, decltype(f_ve), decltype(f_ev)> graph(n, f_ve, f_ev);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    graph.add_edge(s, t);
    costs.push_back(w);
  }

  const std::vector<int> result = graph.query();
  std::cout << *std::max_element(result.begin(), result.end()) << '\n';
  return 0;
}
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
rerooting_dp<R, M, F_VE, F_EV> graph(std::size_t n, F_VE f_ve, F_EV f_ev);
```

It creates a graph with $n$ vertices and $0$ edges.
The meaning of each the type parameter is as follows.

- `R`
    - the type of aggregated vertex attributes representing the vertex and the subtree far from that
- `M`
    - the commutative monoid on the type of aggregated edge attributes representing the edge and the subtree far from that
- `f_ve`
    - the function which accepts an aggregated vertex attribute and the index of the edge adjacent to the subtree, and returns the aggregated edge attribute
- `f_ev`
    - the function which accepts the product of aggregated edge attributes and the index of the vertex adjacent to the subtrees, and returns the aggregated vertex attribute

### Constraints
- For all $a$ in `typename M::T` and $b$ in `typename M::T`, `M::op(a, b)` $=$ `M::op(b, a)`.
- For all $a$ in `typename M::T`, $b$ in `typename M::T` and $c$ in `typename M::T`, `M::op(M::op(a, b), c)` $=$ `M::op(a, M::op(b, c))`.
- For all $a$ in `typename M::T`, `M::op(M::e(), a)` $=$ `M::op(a, M::e())` $=$ `a`.
- `f_ve` is invocable.
- `f_ve` accepts two arguments, `R` and `std::size_t`.
- `f_ve` returns `typename M::T`.
- `f_ev` is invocable.
- `f_ev` accepts two arguments, `typename M::T` and `std::size_t`.
- `f_ev` returns `R`.

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t graph.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
std::size_t graph.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge between $u$ and $v$ to the graph.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## query
```cpp
std::vector<R> graph.query();
```

It returns aggregated vertex attributes.
The $i$-th element of the return value represents the rooted tree whose root is the vertex $i$.

### Constraints
- The graph is a tree.

### Time Complexity
- $O(n)$
