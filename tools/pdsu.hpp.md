---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/pdsu.test.cpp
    title: tests/pdsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pdsu.hpp\"\n\n\n\n#include <cstdint>\n#include <vector>\n\
    #include <cassert>\n#include <numeric>\n#include <utility>\n#line 1 \"tools/group.hpp\"\
    \n\n\n\nnamespace tools {\n  namespace group {\n    template <typename Type>\n\
    \    struct plus {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return lhs + rhs;\n      }\n      static T e() {\n       \
    \ return T(0);\n      }\n      static T inv(const T v) {\n        return -v;\n\
    \      }\n    };\n\n    template <typename Type>\n    struct bit_xor {\n     \
    \ using T = Type;\n      static T op(const T lhs, const T rhs) {\n        return\
    \ lhs ^ rhs;\n      }\n      static T e() {\n        return T(0);\n      }\n \
    \     static T inv(const T v) {\n        return v;\n      }\n    };\n  }\n}\n\n\
    \n#line 10 \"tools/pdsu.hpp\"\n\nnamespace tools {\n  template <typename G = ::tools::group::plus<::std::int_fast64_t>>\n\
    \  class pdsu {\n  private:\n    using T = typename G::T;\n    ::std::vector<int>\
    \ m_parents;\n    ::std::vector<int> m_sizes;\n    ::std::vector<T> m_diffs;\n\
    \n  public:\n    pdsu(const int n) :\n      m_parents(n),\n      m_sizes(n, 1),\n\
    \      m_diffs(n, 0) {\n      assert(n >= 0);\n      ::std::iota(this->m_parents.begin(),\
    \ this->m_parents.end(), 0);\n    }\n\n    int size() const {\n      return this->m_parents.size();\n\
    \    }\n\n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      if (this->m_parents[x] == x) {\n        return x;\n      }\n      const\
    \ auto r = this->leader(this->m_parents[x]);\n      this->m_diffs[x] = G::op(this->m_diffs[x],\
    \ this->m_diffs[this->m_parents[x]]);\n      return this->m_parents[x] = r;\n\
    \    }\n\n  private:\n    T potential(const int x) {\n      assert(0 <= x && x\
    \ < this->size());\n      this->leader(x);\n      return this->m_diffs[x];\n \
    \   }\n\n  public:\n    T diff(const int x, const int y) {\n      assert(0 <=\
    \ x && x < this->size());\n      assert(0 <= y && y < this->size());\n      assert(this->same(x,\
    \ y));\n      return G::op(this->potential(y), G::inv(this->potential(x)));\n\
    \    }\n\n    bool same(const int x, const int y) {\n      assert(0 <= x && x\
    \ < this->size());\n      assert(0 <= y && y < this->size());\n      return this->leader(x)\
    \ == this->leader(y);\n    }\n\n    int merge(int x, int y, T w) {\n      assert(0\
    \ <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n    \
    \  assert(!this->same(x, y));\n\n      w = G::op(G::op(w, this->potential(x)),\
    \ G::inv(this->potential(y)));\n      x = this->leader(x);\n      y = this->leader(y);\n\
    \      if (x == y) return x;\n\n      if (this->m_sizes[x] < this->m_sizes[y])\
    \ {\n        ::std::swap(x, y);\n        w = G::inv(w);\n      }\n      this->m_parents[y]\
    \ = x;\n      this->m_sizes[x] += this->m_sizes[y];\n\n      this->m_diffs[y]\
    \ = w;\n      return x;\n    }\n\n    int size(const int x) {\n      assert(0\
    \ <= x && x < this->size());\n      return this->m_sizes[this->leader(x)];\n \
    \   }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<int>\
    \ group_indices(this->size(), -1);\n      int next_group_index = 0;\n      for\
    \ (int i = 0; i < this->size(); ++i) {\n        if (group_indices[this->leader(i)]\
    \ == -1) {\n          group_indices[this->leader(i)] = next_group_index;\n   \
    \       ++next_group_index;\n        }\n      }\n\n      ::std::vector<::std::vector<int>>\
    \ groups(next_group_index);\n      for (int i = 0; i < this->size(); ++i) {\n\
    \        groups[group_indices[this->leader(i)]].push_back(i);\n      }\n\n   \
    \   return groups;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PDSU_HPP\n#define TOOLS_PDSU_HPP\n\n#include <cstdint>\n#include\
    \ <vector>\n#include <cassert>\n#include <numeric>\n#include <utility>\n#include\
    \ \"tools/group.hpp\"\n\nnamespace tools {\n  template <typename G = ::tools::group::plus<::std::int_fast64_t>>\n\
    \  class pdsu {\n  private:\n    using T = typename G::T;\n    ::std::vector<int>\
    \ m_parents;\n    ::std::vector<int> m_sizes;\n    ::std::vector<T> m_diffs;\n\
    \n  public:\n    pdsu(const int n) :\n      m_parents(n),\n      m_sizes(n, 1),\n\
    \      m_diffs(n, 0) {\n      assert(n >= 0);\n      ::std::iota(this->m_parents.begin(),\
    \ this->m_parents.end(), 0);\n    }\n\n    int size() const {\n      return this->m_parents.size();\n\
    \    }\n\n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      if (this->m_parents[x] == x) {\n        return x;\n      }\n      const\
    \ auto r = this->leader(this->m_parents[x]);\n      this->m_diffs[x] = G::op(this->m_diffs[x],\
    \ this->m_diffs[this->m_parents[x]]);\n      return this->m_parents[x] = r;\n\
    \    }\n\n  private:\n    T potential(const int x) {\n      assert(0 <= x && x\
    \ < this->size());\n      this->leader(x);\n      return this->m_diffs[x];\n \
    \   }\n\n  public:\n    T diff(const int x, const int y) {\n      assert(0 <=\
    \ x && x < this->size());\n      assert(0 <= y && y < this->size());\n      assert(this->same(x,\
    \ y));\n      return G::op(this->potential(y), G::inv(this->potential(x)));\n\
    \    }\n\n    bool same(const int x, const int y) {\n      assert(0 <= x && x\
    \ < this->size());\n      assert(0 <= y && y < this->size());\n      return this->leader(x)\
    \ == this->leader(y);\n    }\n\n    int merge(int x, int y, T w) {\n      assert(0\
    \ <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n    \
    \  assert(!this->same(x, y));\n\n      w = G::op(G::op(w, this->potential(x)),\
    \ G::inv(this->potential(y)));\n      x = this->leader(x);\n      y = this->leader(y);\n\
    \      if (x == y) return x;\n\n      if (this->m_sizes[x] < this->m_sizes[y])\
    \ {\n        ::std::swap(x, y);\n        w = G::inv(w);\n      }\n      this->m_parents[y]\
    \ = x;\n      this->m_sizes[x] += this->m_sizes[y];\n\n      this->m_diffs[y]\
    \ = w;\n      return x;\n    }\n\n    int size(const int x) {\n      assert(0\
    \ <= x && x < this->size());\n      return this->m_sizes[this->leader(x)];\n \
    \   }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<int>\
    \ group_indices(this->size(), -1);\n      int next_group_index = 0;\n      for\
    \ (int i = 0; i < this->size(); ++i) {\n        if (group_indices[this->leader(i)]\
    \ == -1) {\n          group_indices[this->leader(i)] = next_group_index;\n   \
    \       ++next_group_index;\n        }\n      }\n\n      ::std::vector<::std::vector<int>>\
    \ groups(next_group_index);\n      for (int i = 0; i < this->size(); ++i) {\n\
    \        groups[group_indices[this->leader(i)]].push_back(i);\n      }\n\n   \
    \   return groups;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/group.hpp
  isVerificationFile: false
  path: tools/pdsu.hpp
  requiredBy: []
  timestamp: '2022-02-19 06:09:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/pdsu.test.cpp
documentation_of: tools/pdsu.hpp
layout: document
title: Potentialized disjoint set union
---

Given an unknown integer sequence $a_0, a_1, \ldots, a_{n - 1}$ and an abelian group $G$, it processes the following queries in $O(\alpha(n))$ time (amortized).

- Receiving the information $a_y - a_x = w$ under the abelian group $G$
- Reporting $a_y - a_x$ under the abelian group $G$

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename G>
pdsu<G> d(int n);
```

It creates an unknown integer sequence $a_0, a_1, \ldots, a_{n - 1}$.

### Constraints
- $n \geq 0$
- For all $a$ in `typename G::T` and $b$ in `typename G::T`, `G::op(a, b)` $=$ `G::op(b, a)`.
- For all $a$ in `typename G::T`, $b$ in `typename G::T` and $c$ in `typename G::T`, `G::op(G::op(a, b), c)` $=$ `G::op(a, G::op(b, c))`.
- For all $a$ in `typename G::T`, `G::op(G::e(), a)` $=$ `G::op(a, G::e())` $=$ `a`.
- For all $a$ in `typename G::T`, `G::op(G::inv(a), a)` $=$ `G::op(a, G::inv(a))` $=$ `G::e()`.

### Time Complexity
- $O(n)$

## merge
```cpp
int d.merge(int x, int y, typename G::T w);
```

It receives the information $a_y - a_x = w$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$
- Before calling the function, $a_y - a_x$ is unknown

### Time Complexity
- amortized $O(\alpha(n))$

## diff
```cpp
typename G::T d.diff(int x, int y);
```

It returns $a_y - a_x$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$
- $a_y - a_x$ is known

### Time Complexity
- amortized $O(\alpha(n))$

## same
```cpp
bool d.same(int x, int y);
```

It returns whether $a_y - a_x$ is known or not.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- amortized $O(\alpha(n))$

## leader
```cpp
int d.leader(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if $a_z - a_y$ is known, the graph can be divided into some connected components.
It returns the reprensative vertex of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- amortized $O(\alpha(n))$

## size
```cpp
int d.size(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if $a_z - a_y$ is known, the graph can be divided into some connected components.
It returns the size of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- amortized $O(\alpha(n))$

## groups
```cpp
std::vector<std::vector<int>> d.groups();
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if $a_z - a_y$ is known, the graph can be divided into some connected components.
It returns the list of the connected components.

### Constraints
- None

### Time Complexity
- $O(n)$
