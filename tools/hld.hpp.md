---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/hld.test.cpp
    title: tests/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/hld.hpp\"\n\n\n\n#include <vector>\n#include <cstddef>\n\
    #include <cassert>\n#include <algorithm>\n#include <limits>\n#include <stack>\n\
    #include <utility>\n#include <iterator>\n#line 1 \"lib/ac-library/atcoder/dsu.hpp\"\
    \n\n\n\n#line 7 \"lib/ac-library/atcoder/dsu.hpp\"\n\nnamespace atcoder {\n\n\
    // Implement (union by size) + (path compression)\n// Reference:\n// Zvi Galil\
    \ and Giuseppe F. Italiano,\n// Data structures and algorithms for disjoint set\
    \ union problems\nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n    explicit\
    \ dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\n    int merge(int a, int b)\
    \ {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n  \
    \      int x = leader(a), y = leader(b);\n        if (x == y) return x;\n    \
    \    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return x;\n \
    \   }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n  \
    \      assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n   \
    \ }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n\
    \    }\n\n    int size(int a) {\n        assert(0 <= a && a < _n);\n        return\
    \ -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 14 \"tools/hld.hpp\"\n\nnamespace tools {\n  class\
    \ hld {\n  private:\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\
    \    ::std::vector<::std::size_t> m_parent;\n    ::std::vector<::std::size_t>\
    \ m_depth;\n    ::atcoder::dsu m_dsu;\n    ::std::vector<::std::size_t> m_idx2dfs;\n\
    \    ::std::vector<::std::size_t> m_dfs2idx;\n\n  public:\n    hld() = default;\n\
    \    hld(const ::tools::hld&) = default;\n    hld(::tools::hld&&) = default;\n\
    \    ~hld() = default;\n    ::tools::hld& operator=(const ::tools::hld&) = default;\n\
    \    ::tools::hld& operator=(::tools::hld&&) = default;\n\n    explicit hld(const\
    \ ::std::size_t n) : m_graph(n), m_parent(n), m_depth(n), m_idx2dfs(n), m_dfs2idx(n)\
    \ {\n      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n    const ::std::vector<::std::size_t>& idx2dfs()\
    \ const {\n      return this->m_idx2dfs;\n    }\n    const ::std::vector<::std::size_t>&\
    \ dfs2idx() const {\n      return this->m_dfs2idx;\n    }\n\n    void add_edge(const\
    \ ::std::size_t u, const ::std::size_t v) {\n      assert(u < this->size());\n\
    \      assert(v < this->size());\n      this->m_graph[u].push_back(v);\n     \
    \ this->m_graph[v].push_back(u);\n    }\n\n    void build(const ::std::size_t\
    \ root) {\n      assert(root < this->size());\n\n      ::std::vector<::std::size_t>\
    \ subtree_size(this->size());\n      ::std::fill(this->m_parent.begin(), this->m_parent.end(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      this->m_depth[root] = 0;\n\
    \      {\n        ::std::stack<::std::pair<::std::size_t, bool>> stack;\n    \
    \    stack.emplace(root, false);\n        stack.emplace(root, true);\n       \
    \ while (!stack.empty()) {\n          const auto [here, pre] = stack.top();\n\
    \          stack.pop();\n          if (pre) {\n            for (const auto next\
    \ : this->m_graph[here]) {\n              if (next != this->m_parent[here]) {\n\
    \                this->m_parent[next] = here;\n                this->m_depth[next]\
    \ = this->m_depth[here] + 1;\n                stack.emplace(next, false);\n  \
    \              stack.emplace(next, true);\n              }\n            }\n  \
    \        } else {\n            subtree_size[here] = 1;\n            for (const\
    \ auto child : this->m_graph[here]) {\n              if (child != this->m_parent[here])\
    \ {\n                subtree_size[here] += subtree_size[child];\n            \
    \  }\n            }\n          }\n        }\n      }\n\n      for (::std::size_t\
    \ v = 0; v < this->size(); ++v) {\n        if (v != root) {\n          ::std::iter_swap(\n\
    \            ::std::prev(this->m_graph[v].end()),\n            ::std::find(this->m_graph[v].begin(),\
    \ this->m_graph[v].end(), this->m_parent[v])\n          );\n        }\n      \
    \  ::std::iter_swap(\n          this->m_graph[v].begin(),\n          ::std::max_element(\n\
    \            this->m_graph[v].begin(),\n            ::std::prev(this->m_graph[v].end(),\
    \ v == root ? 0 : 1),\n            ::tools::less_by([&](const ::std::size_t v)\
    \ { return subtree_size[v]; })\n          )\n        );\n      }\n\n      ::std::size_t\
    \ dfs_order = 0;\n      this->m_dsu = ::atcoder::dsu(this->size());\n      {\n\
    \        ::std::stack<::std::size_t> stack;\n        stack.push(root);\n     \
    \   while (!stack.empty()) {\n          const auto here = stack.top();\n     \
    \     stack.pop();\n\n          this->m_idx2dfs[here] = dfs_order;\n         \
    \ this->m_dfs2idx[dfs_order] = here;\n          ++dfs_order;\n\n          if (this->m_graph[here].size()\
    \ > (here == root ? 0 : 1)) {\n            this->m_dsu.merge(here, this->m_graph[here][0]);\n\
    \          }\n          for (auto it = ::std::next(this->m_graph[here].rbegin(),\
    \ here == root ? 0 : 1); it != this->m_graph[here].rend(); ++it) {\n         \
    \   stack.push(*it);\n          }\n        }\n      }\n    }\n    void build()\
    \ {\n      this->build(0);\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> query(::std::size_t u, ::std::size_t v) {\n      assert(u <\
    \ this->size());\n      assert(v < this->size());\n\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> head, tail;\n      while (!this->m_dsu.same(u, v)) {\n     \
    \   if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)])\
    \ {\n          head.emplace_back(this->m_idx2dfs[u] + 1, this->m_idx2dfs[this->m_dsu.leader(u)]);\n\
    \          u = this->m_parent[this->m_dsu.leader(u)];\n        } else {\n    \
    \      tail.emplace_back(this->m_idx2dfs[this->m_dsu.leader(v)], this->m_idx2dfs[v]\
    \ + 1);\n          v = this->m_parent[this->m_dsu.leader(v)];\n        }\n   \
    \   }\n      if (this->m_depth[u] >= this->m_depth[v]) {\n        head.emplace_back(this->m_idx2dfs[u]\
    \ + 1, this->m_idx2dfs[v]);\n      } else {\n        head.emplace_back(this->m_idx2dfs[u],\
    \ this->m_idx2dfs[v] + 1);\n      }\n\n      ::std::copy(tail.rbegin(), tail.rend(),\
    \ ::std::back_inserter(head));\n      return head;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_HLD_HPP\n#define TOOLS_HLD_HPP\n\n#include <vector>\n#include\
    \ <cstddef>\n#include <cassert>\n#include <algorithm>\n#include <limits>\n#include\
    \ <stack>\n#include <utility>\n#include <iterator>\n#include \"atcoder/dsu.hpp\"\
    \n#include \"tools/less_by.hpp\"\n\nnamespace tools {\n  class hld {\n  private:\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_graph;\n    ::std::vector<::std::size_t>\
    \ m_parent;\n    ::std::vector<::std::size_t> m_depth;\n    ::atcoder::dsu m_dsu;\n\
    \    ::std::vector<::std::size_t> m_idx2dfs;\n    ::std::vector<::std::size_t>\
    \ m_dfs2idx;\n\n  public:\n    hld() = default;\n    hld(const ::tools::hld&)\
    \ = default;\n    hld(::tools::hld&&) = default;\n    ~hld() = default;\n    ::tools::hld&\
    \ operator=(const ::tools::hld&) = default;\n    ::tools::hld& operator=(::tools::hld&&)\
    \ = default;\n\n    explicit hld(const ::std::size_t n) : m_graph(n), m_parent(n),\
    \ m_depth(n), m_idx2dfs(n), m_dfs2idx(n) {\n      assert(n >= 1);\n    }\n\n \
    \   ::std::size_t size() const {\n      return this->m_graph.size();\n    }\n\
    \    const ::std::vector<::std::size_t>& idx2dfs() const {\n      return this->m_idx2dfs;\n\
    \    }\n    const ::std::vector<::std::size_t>& dfs2idx() const {\n      return\
    \ this->m_dfs2idx;\n    }\n\n    void add_edge(const ::std::size_t u, const ::std::size_t\
    \ v) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   this->m_graph[u].push_back(v);\n      this->m_graph[v].push_back(u);\n   \
    \ }\n\n    void build(const ::std::size_t root) {\n      assert(root < this->size());\n\
    \n      ::std::vector<::std::size_t> subtree_size(this->size());\n      ::std::fill(this->m_parent.begin(),\
    \ this->m_parent.end(), ::std::numeric_limits<::std::size_t>::max());\n      this->m_depth[root]\
    \ = 0;\n      {\n        ::std::stack<::std::pair<::std::size_t, bool>> stack;\n\
    \        stack.emplace(root, false);\n        stack.emplace(root, true);\n   \
    \     while (!stack.empty()) {\n          const auto [here, pre] = stack.top();\n\
    \          stack.pop();\n          if (pre) {\n            for (const auto next\
    \ : this->m_graph[here]) {\n              if (next != this->m_parent[here]) {\n\
    \                this->m_parent[next] = here;\n                this->m_depth[next]\
    \ = this->m_depth[here] + 1;\n                stack.emplace(next, false);\n  \
    \              stack.emplace(next, true);\n              }\n            }\n  \
    \        } else {\n            subtree_size[here] = 1;\n            for (const\
    \ auto child : this->m_graph[here]) {\n              if (child != this->m_parent[here])\
    \ {\n                subtree_size[here] += subtree_size[child];\n            \
    \  }\n            }\n          }\n        }\n      }\n\n      for (::std::size_t\
    \ v = 0; v < this->size(); ++v) {\n        if (v != root) {\n          ::std::iter_swap(\n\
    \            ::std::prev(this->m_graph[v].end()),\n            ::std::find(this->m_graph[v].begin(),\
    \ this->m_graph[v].end(), this->m_parent[v])\n          );\n        }\n      \
    \  ::std::iter_swap(\n          this->m_graph[v].begin(),\n          ::std::max_element(\n\
    \            this->m_graph[v].begin(),\n            ::std::prev(this->m_graph[v].end(),\
    \ v == root ? 0 : 1),\n            ::tools::less_by([&](const ::std::size_t v)\
    \ { return subtree_size[v]; })\n          )\n        );\n      }\n\n      ::std::size_t\
    \ dfs_order = 0;\n      this->m_dsu = ::atcoder::dsu(this->size());\n      {\n\
    \        ::std::stack<::std::size_t> stack;\n        stack.push(root);\n     \
    \   while (!stack.empty()) {\n          const auto here = stack.top();\n     \
    \     stack.pop();\n\n          this->m_idx2dfs[here] = dfs_order;\n         \
    \ this->m_dfs2idx[dfs_order] = here;\n          ++dfs_order;\n\n          if (this->m_graph[here].size()\
    \ > (here == root ? 0 : 1)) {\n            this->m_dsu.merge(here, this->m_graph[here][0]);\n\
    \          }\n          for (auto it = ::std::next(this->m_graph[here].rbegin(),\
    \ here == root ? 0 : 1); it != this->m_graph[here].rend(); ++it) {\n         \
    \   stack.push(*it);\n          }\n        }\n      }\n    }\n    void build()\
    \ {\n      this->build(0);\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> query(::std::size_t u, ::std::size_t v) {\n      assert(u <\
    \ this->size());\n      assert(v < this->size());\n\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> head, tail;\n      while (!this->m_dsu.same(u, v)) {\n     \
    \   if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)])\
    \ {\n          head.emplace_back(this->m_idx2dfs[u] + 1, this->m_idx2dfs[this->m_dsu.leader(u)]);\n\
    \          u = this->m_parent[this->m_dsu.leader(u)];\n        } else {\n    \
    \      tail.emplace_back(this->m_idx2dfs[this->m_dsu.leader(v)], this->m_idx2dfs[v]\
    \ + 1);\n          v = this->m_parent[this->m_dsu.leader(v)];\n        }\n   \
    \   }\n      if (this->m_depth[u] >= this->m_depth[v]) {\n        head.emplace_back(this->m_idx2dfs[u]\
    \ + 1, this->m_idx2dfs[v]);\n      } else {\n        head.emplace_back(this->m_idx2dfs[u],\
    \ this->m_idx2dfs[v] + 1);\n      }\n\n      ::std::copy(tail.rbegin(), tail.rend(),\
    \ ::std::back_inserter(head));\n      return head;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/less_by.hpp
  isVerificationFile: false
  path: tools/hld.hpp
  requiredBy: []
  timestamp: '2022-04-23 16:47:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/hld.test.cpp
documentation_of: tools/hld.hpp
layout: document
title: Heavy-light decomposition
---

As a preprecessing, it takes a tree with $n$ vertices as input, and assigns a dfs-ordered index to each vertex in the tree.
Given a path from $u$ to $v$, it can return some intervals of the dfs-ordered indices.
It is guaranteed that the number of the intervals is $O(\log n)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
hld hld(std::size_t n);
```

It creates a buffer for a tree with $n$ vertices.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t hld.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## idx2dfs
```cpp
const std::vector<std::size_t>& hld.idx2dfs();
```

It returns the mapping from vertex indices to dfs-ordered indices.

### Constraints
- None

### Time Complexity
- $O(1)$

## dfs2idx
```cpp
const std::vector<std::size_t>& hld.dfs2idx();
```

It returns the mapping from dfs-ordered indices to vertex indices.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
void hld.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge connecting $u$ and $v$ to the tree.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## build
```cpp
void hld.build(std::size_t r = 0);
```

It assigns a dfs-ordered index to each vertex in the tree.
The root is $r$.

### Constraints
- $0 \leq r < n$

### Time Complexity
- $O(n)$

## query
```cpp
std::vector<std::pair<std::size_t, std::size_t>> hld.query(std::size_t u, std::size_t v);
```

Given a path from $u$ to $v$, it returns some intervals of the dfs-ordered indices.
It is guaranteed that the number of the intervals is $O(\log n)$.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(\log n)$
