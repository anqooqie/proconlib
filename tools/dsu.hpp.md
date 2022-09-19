---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dsu.test.cpp
    title: tests/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dsu.hpp\"\n\n\n\n#include <vector>\n#include <cassert>\n\
    #include <utility>\n#include <algorithm>\n\nnamespace tools {\n  class dsu {\n\
    \  private:\n    ::std::vector<int> m_parents;\n    ::std::vector<int> m_sizes;\n\
    \n    int size() const {\n      return this->m_parents.size();\n    }\n\n  public:\n\
    \    dsu() = default;\n    dsu(const ::tools::dsu&) = default;\n    dsu(::tools::dsu&&)\
    \ = default;\n    ~dsu() = default;\n    ::tools::dsu& operator=(const ::tools::dsu&)\
    \ = default;\n    ::tools::dsu& operator=(::tools::dsu&&) = default;\n\n    explicit\
    \ dsu(const int n) :\n      m_parents(n),\n      m_sizes(n, 1) {\n      for (int\
    \ i = 0; i < n; ++i) {\n        this->m_parents[i] = i;\n      }\n    }\n\n  \
    \  int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\n  \
    \    return this->m_parents[x] == x ? x : (this->m_parents[x] = this->leader(this->m_parents[x]));\n\
    \    }\n\n    bool same(const int x, const int y) {\n      assert(0 <= x && x\
    \ < this->size());\n      assert(0 <= y && y < this->size());\n\n      return\
    \ this->leader(x) == this->leader(y);\n    }\n\n    int merge(int x, int y) {\n\
    \      assert(0 <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\
    \n      x = this->leader(x);\n      y = this->leader(y);\n      if (x == y) return\
    \ x;\n\n      if (this->m_sizes[x] < this->m_sizes[y]) ::std::swap(x, y);\n  \
    \    this->m_parents[y] = x;\n      this->m_sizes[x] += this->m_sizes[y];\n\n\
    \      return x;\n    }\n\n    int size(const int x) {\n      return this->m_sizes[this->leader(x)];\n\
    \    }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<::std::vector<int>>\
    \ res(this->size());\n      for (int i = 0; i < this->size(); ++i) {\n       \
    \ res[this->leader(i)].push_back(i);\n      }\n      res.erase(::std::remove_if(res.begin(),\
    \ res.end(), [](const auto& group) { return group.empty(); }), res.end());\n \
    \     return res;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DSU_HPP\n#define TOOLS_DSU_HPP\n\n#include <vector>\n#include\
    \ <cassert>\n#include <utility>\n#include <algorithm>\n\nnamespace tools {\n \
    \ class dsu {\n  private:\n    ::std::vector<int> m_parents;\n    ::std::vector<int>\
    \ m_sizes;\n\n    int size() const {\n      return this->m_parents.size();\n \
    \   }\n\n  public:\n    dsu() = default;\n    dsu(const ::tools::dsu&) = default;\n\
    \    dsu(::tools::dsu&&) = default;\n    ~dsu() = default;\n    ::tools::dsu&\
    \ operator=(const ::tools::dsu&) = default;\n    ::tools::dsu& operator=(::tools::dsu&&)\
    \ = default;\n\n    explicit dsu(const int n) :\n      m_parents(n),\n      m_sizes(n,\
    \ 1) {\n      for (int i = 0; i < n; ++i) {\n        this->m_parents[i] = i;\n\
    \      }\n    }\n\n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \n      return this->m_parents[x] == x ? x : (this->m_parents[x] = this->leader(this->m_parents[x]));\n\
    \    }\n\n    bool same(const int x, const int y) {\n      assert(0 <= x && x\
    \ < this->size());\n      assert(0 <= y && y < this->size());\n\n      return\
    \ this->leader(x) == this->leader(y);\n    }\n\n    int merge(int x, int y) {\n\
    \      assert(0 <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\
    \n      x = this->leader(x);\n      y = this->leader(y);\n      if (x == y) return\
    \ x;\n\n      if (this->m_sizes[x] < this->m_sizes[y]) ::std::swap(x, y);\n  \
    \    this->m_parents[y] = x;\n      this->m_sizes[x] += this->m_sizes[y];\n\n\
    \      return x;\n    }\n\n    int size(const int x) {\n      return this->m_sizes[this->leader(x)];\n\
    \    }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<::std::vector<int>>\
    \ res(this->size());\n      for (int i = 0; i < this->size(); ++i) {\n       \
    \ res[this->leader(i)].push_back(i);\n      }\n      res.erase(::std::remove_if(res.begin(),\
    \ res.end(), [](const auto& group) { return group.empty(); }), res.end());\n \
    \     return res;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/dsu.hpp
  requiredBy: []
  timestamp: '2022-09-19 16:01:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dsu.test.cpp
documentation_of: tools/dsu.hpp
layout: document
title: Disjoint set union
---

Given an undirected graph, it processes the following queries in $O(\alpha(n))$ time (amortized).

- Edge addition
- Deciding whether given two vertices are in the same connected component

Each connected component internally has a representative vertex.

When two connected components are merged by edge addition, the representative of the larger connected component becomes the representative of the new connected component.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
dsu d(int n);
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

If the vertices $a$ and $b$ were in the same connected component, it returns the representative of this connected component.
Otherwise, the representative of the larger (or former when the two have the same size) connected component becomes the representative of the new connected component, and it returns the new representative.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## same
```cpp
bool d.same(int a, int b);
```

It returns whether the vertices $a$ and $b$ are in the same connected component.

### Constraints
- $0 \leq a < n$
- $0 \leq b < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## leader
```cpp
int d.leader(int a);
```

It returns the representative of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## size
```cpp
int d.size(int a);
```

It returns the size of the connected component that contains the vertex $a$.

### Constraints
- $0 \leq a < n$

### Time Complexity
- $O(\alpha(n))$ amortized

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
