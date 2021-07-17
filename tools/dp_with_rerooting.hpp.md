---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dp_with_rerooting.test.cpp
    title: tests/dp_with_rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dp_with_rerooting.hpp\"\n\n\n\n#include <cstddef>\n\
    #include <vector>\n#include <limits>\n#include <stack>\n#include <tuple>\n#include\
    \ <algorithm>\n\nnamespace tools {\n  template <typename V, typename E, typename\
    \ R, typename M, typename M::T (*f_ve)(E, R), R (*f_ev)(V, typename M::T)>\n \
    \ class dp_with_rerooting {\n  private:\n    class adjacency {\n    public:\n\
    \      ::std::size_t to;\n      E attribute;\n\n      adjacency() = default;\n\
    \      adjacency(const adjacency&) = default;\n      adjacency(adjacency&&) =\
    \ default;\n      ~adjacency() = default;\n      adjacency& operator=(const adjacency&)\
    \ = default;\n      adjacency& operator=(adjacency&&) = default;\n\n      adjacency(const\
    \ ::std::size_t to, const E& attribute) :\n        to(to), attribute(attribute)\
    \ {\n      }\n    };\n\n    ::std::vector<V> vertex_attributes;\n    ::std::vector<::std::vector<adjacency>>\
    \ adjacency_list;\n\n    class vertex {\n    private:\n      const ::tools::dp_with_rerooting<V,\
    \ E, R, M, f_ve, f_ev> *self;\n\n    public:\n      ::std::size_t id;\n      ::std::size_t\
    \ parent_adjacency_id;\n      ::std::vector<::std::size_t> child_adjacency_ids;\n\
    \      typename M::T parent_dp;\n      ::std::vector<typename M::T> children_dp;\n\
    \      ::std::vector<typename M::T> children_dp_cumsum1;\n      ::std::vector<typename\
    \ M::T> children_dp_cumsum2;\n\n      vertex() = default;\n      vertex(const\
    \ vertex&) = default;\n      vertex(vertex&&) = default;\n      ~vertex() = default;\n\
    \      vertex& operator=(const vertex&) = default;\n      vertex& operator=(vertex&&)\
    \ = default;\n\n      explicit vertex(const ::tools::dp_with_rerooting<V, E, R,\
    \ M, f_ve, f_ev> * const self, const ::std::size_t id) :\n        self(self),\
    \ id(id), parent_dp(M::e()) {\n      }\n\n      V attribute() const {\n      \
    \  return self->vertex_attributes[this->id];\n      }\n      ::std::size_t parent_vertex_id()\
    \ const {\n        return self->adjacency_list[this->id][this->parent_adjacency_id].to;\n\
    \      }\n      E parent_edge_attribute() const {\n        return self->adjacency_list[this->id][this->parent_adjacency_id].attribute;\n\
    \      }\n      ::std::size_t child_size() const {\n        return this->child_adjacency_ids.size();\n\
    \      }\n      ::std::size_t child_vertex_id(const ::std::size_t child_edge_id)\
    \ const {\n        return self->adjacency_list[this->id][this->child_adjacency_ids[child_edge_id]].to;\n\
    \      }\n      E child_edge_attribute(const ::std::size_t child_edge_id) const\
    \ {\n        return self->adjacency_list[this->id][this->child_adjacency_ids[child_edge_id]].attribute;\n\
    \      }\n      R dp_as_root() const {\n        return f_ev(this->attribute(),\
    \ M::op(this->parent_dp, this->children_dp_cumsum1.back()));\n      }\n      R\
    \ dp_excluding_parent() const {\n        return f_ev(this->attribute(), this->children_dp_cumsum1.back());\n\
    \      }\n      R dp_excluding_child(const ::std::size_t excluded_child_edge_id)\
    \ const {\n        return f_ev(this->attribute(), M::op(this->parent_dp, M::op(this->children_dp_cumsum1[excluded_child_edge_id],\
    \ this->children_dp_cumsum2[excluded_child_edge_id + 1])));\n      }\n    };\n\
    \n  public:\n    dp_with_rerooting() = default;\n    dp_with_rerooting(const ::tools::dp_with_rerooting<V,\
    \ E, R, M, f_ve, f_ev>&) = default;\n    dp_with_rerooting(::tools::dp_with_rerooting<V,\
    \ E, R, M, f_ve, f_ev>&&) = default;\n    ~dp_with_rerooting() = default;\n  \
    \  ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>& operator=(const ::tools::dp_with_rerooting<V,\
    \ E, R, M, f_ve, f_ev>&) = default;\n    ::tools::dp_with_rerooting<V, E, R, M,\
    \ f_ve, f_ev>& operator=(::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>&&)\
    \ = default;\n\n    void add_vertex(const V& vertex_attribute) {\n      this->vertex_attributes.push_back(vertex_attribute);\n\
    \      this->adjacency_list.emplace_back();\n    }\n\n    void add_edge(const\
    \ ::std::size_t a, const ::std::size_t b, const E& edge_attribute) {\n      this->adjacency_list[a].emplace_back(b,\
    \ edge_attribute);\n      this->adjacency_list[b].emplace_back(a, edge_attribute);\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->vertex_attributes.size();\n\
    \    }\n\n    ::std::vector<R> query() const {\n      const int PRE_VERTEX = 1;\n\
    \      const int POST_EDGE = 2;\n      const int POST_VERTEX = 3;\n      const\
    \ ::std::size_t INVALID = ::std::numeric_limits<::std::size_t>::max();\n\n   \
    \   ::std::vector<vertex> vertices;\n      for (::std::size_t i = 0; i < this->size();\
    \ ++i) {\n        vertices.emplace_back(this, i);\n      }\n\n      ::std::stack<::std::tuple<int,\
    \ ::std::size_t, ::std::size_t>> stack;\n      ::std::vector<bool> will_visit(this->size(),\
    \ false);\n      stack.emplace(PRE_VERTEX, 0, INVALID);\n      will_visit[0] =\
    \ true;\n      while (!stack.empty()) {\n        const int type = ::std::get<0>(stack.top());\n\
    \        if (type == PRE_VERTEX) {\n\n          const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n          stack.pop();\n\n          vertex& v\
    \ = vertices[vertex_id];\n          stack.emplace(POST_VERTEX, vertex_id, INVALID);\n\
    \          for (::std::size_t adjacency_id = 0; adjacency_id < this->adjacency_list[vertex_id].size();\
    \ ++adjacency_id) {\n            const ::std::size_t child_id = this->adjacency_list[vertex_id][adjacency_id].to;\n\
    \            if (will_visit[child_id]) {\n              v.parent_adjacency_id\
    \ = adjacency_id;\n            } else {\n              v.child_adjacency_ids.push_back(adjacency_id);\n\
    \              stack.emplace(POST_EDGE, vertex_id, v.child_size() - 1);\n    \
    \          stack.emplace(PRE_VERTEX, child_id, INVALID);\n              will_visit[child_id]\
    \ = true;\n            }\n          }\n          v.children_dp.resize(v.child_size());\n\
    \n        } else if (type == POST_EDGE) {\n\n          const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n          const ::std::size_t edge_id = ::std::get<2>(stack.top());\n\
    \          stack.pop();\n\n          vertex& v = vertices[vertex_id];\n      \
    \    const vertex& c = vertices[v.child_vertex_id(edge_id)];\n          v.children_dp[edge_id]\
    \ = f_ve(v.child_edge_attribute(edge_id), c.dp_excluding_parent());\n\n      \
    \  } else { // POST_VERTEX\n\n          const ::std::size_t vertex_id = ::std::get<1>(stack.top());\n\
    \          stack.pop();\n\n          vertex& v = vertices[vertex_id];\n\n    \
    \      v.children_dp_cumsum1.reserve(v.child_size() + 1);\n          v.children_dp_cumsum1.push_back(M::e());\n\
    \          for (::std::size_t edge_id = 0; edge_id < v.child_size(); ++edge_id)\
    \ {\n            v.children_dp_cumsum1.push_back(M::op(v.children_dp_cumsum1.back(),\
    \ v.children_dp[edge_id]));\n          }\n\n          v.children_dp_cumsum2.reserve(v.child_size()\
    \ + 1);\n          v.children_dp_cumsum2.push_back(M::e());\n          for (::std::size_t\
    \ edge_id = v.child_size(); edge_id --> 0;) {\n            v.children_dp_cumsum2.push_back(M::op(v.children_dp[edge_id],\
    \ v.children_dp_cumsum2.back()));\n          }\n          ::std::reverse(v.children_dp_cumsum2.begin(),\
    \ v.children_dp_cumsum2.end());\n\n        }\n      }\n\n      stack.emplace(PRE_VERTEX,\
    \ 0, INVALID);\n      while (!stack.empty()) {\n        const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n        stack.pop();\n\n        const vertex&\
    \ v = vertices[vertex_id];\n        for (::std::size_t edge_id = 0; edge_id <\
    \ v.child_size(); ++edge_id) {\n          vertex& c = vertices[v.child_vertex_id(edge_id)];\n\
    \          c.parent_dp = f_ve(c.parent_edge_attribute(), v.dp_excluding_child(edge_id));\n\
    \          stack.emplace(PRE_VERTEX, c.id, INVALID);\n        }\n      }\n\n \
    \     ::std::vector<R> result;\n      result.reserve(this->size());\n      for\
    \ (const vertex& v : vertices) {\n        result.push_back(v.dp_as_root());\n\
    \      }\n      return result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DP_WITH_REROOTING_HPP\n#define TOOLS_DP_WITH_REROOTING_HPP\n\
    \n#include <cstddef>\n#include <vector>\n#include <limits>\n#include <stack>\n\
    #include <tuple>\n#include <algorithm>\n\nnamespace tools {\n  template <typename\
    \ V, typename E, typename R, typename M, typename M::T (*f_ve)(E, R), R (*f_ev)(V,\
    \ typename M::T)>\n  class dp_with_rerooting {\n  private:\n    class adjacency\
    \ {\n    public:\n      ::std::size_t to;\n      E attribute;\n\n      adjacency()\
    \ = default;\n      adjacency(const adjacency&) = default;\n      adjacency(adjacency&&)\
    \ = default;\n      ~adjacency() = default;\n      adjacency& operator=(const\
    \ adjacency&) = default;\n      adjacency& operator=(adjacency&&) = default;\n\
    \n      adjacency(const ::std::size_t to, const E& attribute) :\n        to(to),\
    \ attribute(attribute) {\n      }\n    };\n\n    ::std::vector<V> vertex_attributes;\n\
    \    ::std::vector<::std::vector<adjacency>> adjacency_list;\n\n    class vertex\
    \ {\n    private:\n      const ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>\
    \ *self;\n\n    public:\n      ::std::size_t id;\n      ::std::size_t parent_adjacency_id;\n\
    \      ::std::vector<::std::size_t> child_adjacency_ids;\n      typename M::T\
    \ parent_dp;\n      ::std::vector<typename M::T> children_dp;\n      ::std::vector<typename\
    \ M::T> children_dp_cumsum1;\n      ::std::vector<typename M::T> children_dp_cumsum2;\n\
    \n      vertex() = default;\n      vertex(const vertex&) = default;\n      vertex(vertex&&)\
    \ = default;\n      ~vertex() = default;\n      vertex& operator=(const vertex&)\
    \ = default;\n      vertex& operator=(vertex&&) = default;\n\n      explicit vertex(const\
    \ ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev> * const self, const ::std::size_t\
    \ id) :\n        self(self), id(id), parent_dp(M::e()) {\n      }\n\n      V attribute()\
    \ const {\n        return self->vertex_attributes[this->id];\n      }\n      ::std::size_t\
    \ parent_vertex_id() const {\n        return self->adjacency_list[this->id][this->parent_adjacency_id].to;\n\
    \      }\n      E parent_edge_attribute() const {\n        return self->adjacency_list[this->id][this->parent_adjacency_id].attribute;\n\
    \      }\n      ::std::size_t child_size() const {\n        return this->child_adjacency_ids.size();\n\
    \      }\n      ::std::size_t child_vertex_id(const ::std::size_t child_edge_id)\
    \ const {\n        return self->adjacency_list[this->id][this->child_adjacency_ids[child_edge_id]].to;\n\
    \      }\n      E child_edge_attribute(const ::std::size_t child_edge_id) const\
    \ {\n        return self->adjacency_list[this->id][this->child_adjacency_ids[child_edge_id]].attribute;\n\
    \      }\n      R dp_as_root() const {\n        return f_ev(this->attribute(),\
    \ M::op(this->parent_dp, this->children_dp_cumsum1.back()));\n      }\n      R\
    \ dp_excluding_parent() const {\n        return f_ev(this->attribute(), this->children_dp_cumsum1.back());\n\
    \      }\n      R dp_excluding_child(const ::std::size_t excluded_child_edge_id)\
    \ const {\n        return f_ev(this->attribute(), M::op(this->parent_dp, M::op(this->children_dp_cumsum1[excluded_child_edge_id],\
    \ this->children_dp_cumsum2[excluded_child_edge_id + 1])));\n      }\n    };\n\
    \n  public:\n    dp_with_rerooting() = default;\n    dp_with_rerooting(const ::tools::dp_with_rerooting<V,\
    \ E, R, M, f_ve, f_ev>&) = default;\n    dp_with_rerooting(::tools::dp_with_rerooting<V,\
    \ E, R, M, f_ve, f_ev>&&) = default;\n    ~dp_with_rerooting() = default;\n  \
    \  ::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>& operator=(const ::tools::dp_with_rerooting<V,\
    \ E, R, M, f_ve, f_ev>&) = default;\n    ::tools::dp_with_rerooting<V, E, R, M,\
    \ f_ve, f_ev>& operator=(::tools::dp_with_rerooting<V, E, R, M, f_ve, f_ev>&&)\
    \ = default;\n\n    void add_vertex(const V& vertex_attribute) {\n      this->vertex_attributes.push_back(vertex_attribute);\n\
    \      this->adjacency_list.emplace_back();\n    }\n\n    void add_edge(const\
    \ ::std::size_t a, const ::std::size_t b, const E& edge_attribute) {\n      this->adjacency_list[a].emplace_back(b,\
    \ edge_attribute);\n      this->adjacency_list[b].emplace_back(a, edge_attribute);\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->vertex_attributes.size();\n\
    \    }\n\n    ::std::vector<R> query() const {\n      const int PRE_VERTEX = 1;\n\
    \      const int POST_EDGE = 2;\n      const int POST_VERTEX = 3;\n      const\
    \ ::std::size_t INVALID = ::std::numeric_limits<::std::size_t>::max();\n\n   \
    \   ::std::vector<vertex> vertices;\n      for (::std::size_t i = 0; i < this->size();\
    \ ++i) {\n        vertices.emplace_back(this, i);\n      }\n\n      ::std::stack<::std::tuple<int,\
    \ ::std::size_t, ::std::size_t>> stack;\n      ::std::vector<bool> will_visit(this->size(),\
    \ false);\n      stack.emplace(PRE_VERTEX, 0, INVALID);\n      will_visit[0] =\
    \ true;\n      while (!stack.empty()) {\n        const int type = ::std::get<0>(stack.top());\n\
    \        if (type == PRE_VERTEX) {\n\n          const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n          stack.pop();\n\n          vertex& v\
    \ = vertices[vertex_id];\n          stack.emplace(POST_VERTEX, vertex_id, INVALID);\n\
    \          for (::std::size_t adjacency_id = 0; adjacency_id < this->adjacency_list[vertex_id].size();\
    \ ++adjacency_id) {\n            const ::std::size_t child_id = this->adjacency_list[vertex_id][adjacency_id].to;\n\
    \            if (will_visit[child_id]) {\n              v.parent_adjacency_id\
    \ = adjacency_id;\n            } else {\n              v.child_adjacency_ids.push_back(adjacency_id);\n\
    \              stack.emplace(POST_EDGE, vertex_id, v.child_size() - 1);\n    \
    \          stack.emplace(PRE_VERTEX, child_id, INVALID);\n              will_visit[child_id]\
    \ = true;\n            }\n          }\n          v.children_dp.resize(v.child_size());\n\
    \n        } else if (type == POST_EDGE) {\n\n          const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n          const ::std::size_t edge_id = ::std::get<2>(stack.top());\n\
    \          stack.pop();\n\n          vertex& v = vertices[vertex_id];\n      \
    \    const vertex& c = vertices[v.child_vertex_id(edge_id)];\n          v.children_dp[edge_id]\
    \ = f_ve(v.child_edge_attribute(edge_id), c.dp_excluding_parent());\n\n      \
    \  } else { // POST_VERTEX\n\n          const ::std::size_t vertex_id = ::std::get<1>(stack.top());\n\
    \          stack.pop();\n\n          vertex& v = vertices[vertex_id];\n\n    \
    \      v.children_dp_cumsum1.reserve(v.child_size() + 1);\n          v.children_dp_cumsum1.push_back(M::e());\n\
    \          for (::std::size_t edge_id = 0; edge_id < v.child_size(); ++edge_id)\
    \ {\n            v.children_dp_cumsum1.push_back(M::op(v.children_dp_cumsum1.back(),\
    \ v.children_dp[edge_id]));\n          }\n\n          v.children_dp_cumsum2.reserve(v.child_size()\
    \ + 1);\n          v.children_dp_cumsum2.push_back(M::e());\n          for (::std::size_t\
    \ edge_id = v.child_size(); edge_id --> 0;) {\n            v.children_dp_cumsum2.push_back(M::op(v.children_dp[edge_id],\
    \ v.children_dp_cumsum2.back()));\n          }\n          ::std::reverse(v.children_dp_cumsum2.begin(),\
    \ v.children_dp_cumsum2.end());\n\n        }\n      }\n\n      stack.emplace(PRE_VERTEX,\
    \ 0, INVALID);\n      while (!stack.empty()) {\n        const ::std::size_t vertex_id\
    \ = ::std::get<1>(stack.top());\n        stack.pop();\n\n        const vertex&\
    \ v = vertices[vertex_id];\n        for (::std::size_t edge_id = 0; edge_id <\
    \ v.child_size(); ++edge_id) {\n          vertex& c = vertices[v.child_vertex_id(edge_id)];\n\
    \          c.parent_dp = f_ve(c.parent_edge_attribute(), v.dp_excluding_child(edge_id));\n\
    \          stack.emplace(PRE_VERTEX, c.id, INVALID);\n        }\n      }\n\n \
    \     ::std::vector<R> result;\n      result.reserve(this->size());\n      for\
    \ (const vertex& v : vertices) {\n        result.push_back(v.dp_as_root());\n\
    \      }\n      return result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/dp_with_rerooting.hpp
  requiredBy: []
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dp_with_rerooting.test.cpp
documentation_of: tools/dp_with_rerooting.hpp
layout: document
title: DP with rerooting
---

It is an abstract algorithm for DP on a tree with rerooting.

## Example
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

int f_ve(const int w, const int vertex) {
  return w + vertex;
}
int f_ev(std::monostate, const int edge) {
  return edge;
}

int main() {
  int n;
  std::cin >> n;

  tools::dp_with_rerooting<std::monostate, int, int, monoid, f_ve, f_ev> dp;
  for (int i = 0; i < n; ++i) {
    dp.add_vertex(std::monostate());
  }
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    dp.add_edge(s, t, w);
  }

  const std::vector<int> result = dp.query();
  std::cout << *std::max_element(result.begin(), result.end()) << '\n';
  return 0;
}
```

## License
- CC0

## Author
- anqooqie
