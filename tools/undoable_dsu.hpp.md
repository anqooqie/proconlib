---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/undoable_dsu.test.cpp
    title: tests/undoable_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/undoable_dsu.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <stack>\n#include <tuple>\n#include <cassert>\n#include <utility>\n#include\
    \ <algorithm>\n\nnamespace tools {\n  class undoable_dsu {\n  private:\n    ::std::vector<int>\
    \ m_data;\n    ::std::stack<::std::tuple<int, int, int, int>> m_history;\n\n \
    \   int size() const {\n      return this->m_data.size();\n    }\n\n  public:\n\
    \    undoable_dsu() = default;\n    undoable_dsu(const ::tools::undoable_dsu&)\
    \ = default;\n    undoable_dsu(::tools::undoable_dsu&&) = default;\n    ~undoable_dsu()\
    \ = default;\n    ::tools::undoable_dsu& operator=(const ::tools::undoable_dsu&)\
    \ = default;\n    ::tools::undoable_dsu& operator=(::tools::undoable_dsu&&) =\
    \ default;\n\n    explicit undoable_dsu(const int n) : m_data(n, -1) {\n    }\n\
    \n    int leader(const int x) const {\n      assert(0 <= x && x < this->size());\n\
    \n      return this->m_data[x] < 0 ? x : this->leader(this->m_data[x]);\n    }\n\
    \n    bool same(const int x, const int y) const {\n      assert(0 <= x && x <\
    \ this->size());\n      assert(0 <= y && y < this->size());\n\n      return this->leader(x)\
    \ == this->leader(y);\n    }\n\n    int merge(int x, int y) {\n      assert(0\
    \ <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\n  \
    \    x = this->leader(x);\n      y = this->leader(y);\n      if (this->m_data[x]\
    \ > this->m_data[y]) ::std::swap(x, y);\n      this->m_history.emplace(x, y, this->m_data[x],\
    \ this->m_data[y]);\n\n      if (x == y) return x;\n\n      this->m_data[x] +=\
    \ this->m_data[y];\n      this->m_data[y] = x;\n\n      return x;\n    }\n\n \
    \   int size(const int x) const {\n      assert(0 <= x && x < this->size());\n\
    \n      return -this->m_data[this->leader(x)];\n    }\n\n    void undo() {\n \
    \     assert(!this->m_history.empty());\n\n      const auto [x, y, dx, dy] = this->m_history.top();\n\
    \      this->m_history.pop();\n\n      this->m_data[x] = dx;\n      this->m_data[y]\
    \ = dy;\n    }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<::std::vector<int>>\
    \ res(this->size());\n      for (int i = 0; i < this->size(); ++i) {\n       \
    \ res[this->leader(i)].push_back(i);\n      }\n      res.erase(::std::remove_if(res.begin(),\
    \ res.end(), [](const auto& group) { return group.empty(); }), res.end());\n \
    \     return res;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_UNDOABLE_DSU_HPP\n#define TOOLS_UNDOABLE_DSU_HPP\n\n#include\
    \ <vector>\n#include <stack>\n#include <tuple>\n#include <cassert>\n#include <utility>\n\
    #include <algorithm>\n\nnamespace tools {\n  class undoable_dsu {\n  private:\n\
    \    ::std::vector<int> m_data;\n    ::std::stack<::std::tuple<int, int, int,\
    \ int>> m_history;\n\n    int size() const {\n      return this->m_data.size();\n\
    \    }\n\n  public:\n    undoable_dsu() = default;\n    undoable_dsu(const ::tools::undoable_dsu&)\
    \ = default;\n    undoable_dsu(::tools::undoable_dsu&&) = default;\n    ~undoable_dsu()\
    \ = default;\n    ::tools::undoable_dsu& operator=(const ::tools::undoable_dsu&)\
    \ = default;\n    ::tools::undoable_dsu& operator=(::tools::undoable_dsu&&) =\
    \ default;\n\n    explicit undoable_dsu(const int n) : m_data(n, -1) {\n    }\n\
    \n    int leader(const int x) const {\n      assert(0 <= x && x < this->size());\n\
    \n      return this->m_data[x] < 0 ? x : this->leader(this->m_data[x]);\n    }\n\
    \n    bool same(const int x, const int y) const {\n      assert(0 <= x && x <\
    \ this->size());\n      assert(0 <= y && y < this->size());\n\n      return this->leader(x)\
    \ == this->leader(y);\n    }\n\n    int merge(int x, int y) {\n      assert(0\
    \ <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\n  \
    \    x = this->leader(x);\n      y = this->leader(y);\n      if (this->m_data[x]\
    \ > this->m_data[y]) ::std::swap(x, y);\n      this->m_history.emplace(x, y, this->m_data[x],\
    \ this->m_data[y]);\n\n      if (x == y) return x;\n\n      this->m_data[x] +=\
    \ this->m_data[y];\n      this->m_data[y] = x;\n\n      return x;\n    }\n\n \
    \   int size(const int x) const {\n      assert(0 <= x && x < this->size());\n\
    \n      return -this->m_data[this->leader(x)];\n    }\n\n    void undo() {\n \
    \     assert(!this->m_history.empty());\n\n      const auto [x, y, dx, dy] = this->m_history.top();\n\
    \      this->m_history.pop();\n\n      this->m_data[x] = dx;\n      this->m_data[y]\
    \ = dy;\n    }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<::std::vector<int>>\
    \ res(this->size());\n      for (int i = 0; i < this->size(); ++i) {\n       \
    \ res[this->leader(i)].push_back(i);\n      }\n      res.erase(::std::remove_if(res.begin(),\
    \ res.end(), [](const auto& group) { return group.empty(); }), res.end());\n \
    \     return res;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/undoable_dsu.hpp
  requiredBy: []
  timestamp: '2023-08-05 18:58:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/undoable_dsu.test.cpp
documentation_of: tools/undoable_dsu.hpp
layout: document
title: Undoable disjoint set union
---

Given an undirected graph, it processes the following queries in $O(\log n)$ time.

- Edge addition
- Deciding whether given two vertices are in the same connected component
- Rollback edge addition

Each connected component internally has a representative vertex.

When two connected components are merged by edge addition, the representative of the larger connected component becomes the representative of the new connected component.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
undoable_dsu d(int n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(n)$

## merge
```cpp
int d.merge(int a, int b);
```

It adds an edge $(a, b)$.

If the vertices $a$ and $b$ were in the same connected component, it returns the representative of the connected component.
Otherwise, the representative of the larger (or former when the two have the same size) connected component becomes the representative of the new connected component, and it returns the new representative.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\log n)$

## same
```cpp
bool d.same(int a, int b);
```

It returns whether the vertices $a$ and $b$ are in the same connected component.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\log n)$

## leader
```cpp
int d.leader(int a);
```

It returns the representative of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\log n)$

## size
```cpp
int d.size(int a);
```

It returns the size of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\log n)$

## undo
```cpp
void d.undo();
```

It rollbacks the last edge addition.

### Constraints
- The graph has at least one edge.

### Time Complexity
- $O(1)$

## groups
```cpp
std::vector<std::vector<int>> d.groups();
```

It divides the graph into connected components and returns the list of them.

More precisely, it returns the list of the "list of the vertices in a connected component".
Both of the orders of the connected components and the vertices are undefined.

### Constraints
- None

### Time Complexity
- $O(n)$
