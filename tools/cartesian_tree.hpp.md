---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cartesian_tree/interval.test.cpp
    title: tests/cartesian_tree/interval.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/cartesian_tree/parent.test.cpp
    title: tests/cartesian_tree/parent.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/cartesian_tree.hpp\"\n\n\n\n#include <functional>\n\
    #include <cstddef>\n#include <utility>\n#include <vector>\n#include <limits>\n\
    #include <stack>\n#include <cassert>\n\nnamespace tools {\n  template <typename\
    \ T, typename Compare = ::std::less<T>>\n  class cartesian_tree {\n  public:\n\
    \    struct vertex {\n      ::std::size_t parent;\n      ::std::size_t left;\n\
    \      ::std::size_t right;\n      ::std::pair<::std::size_t, ::std::size_t> interval;\n\
    \    };\n\n  private:\n    Compare m_comp;\n    ::std::vector<vertex> m_vertices;\n\
    \n  public:\n    cartesian_tree() = default;\n    cartesian_tree(const ::tools::cartesian_tree<T,\
    \ Compare>&) = default;\n    cartesian_tree(::tools::cartesian_tree<T, Compare>&&)\
    \ = default;\n    ~cartesian_tree() = default;\n    ::tools::cartesian_tree<T,\
    \ Compare>& operator=(const ::tools::cartesian_tree<T, Compare>&) = default;\n\
    \    ::tools::cartesian_tree<T, Compare>& operator=(::tools::cartesian_tree<T,\
    \ Compare>&&) = default;\n\n    explicit cartesian_tree(const ::std::vector<T>&\
    \ a, const Compare& comp = Compare()) : m_comp(comp), m_vertices(a.size()) {\n\
    \      const auto NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    \
    \  for (::std::size_t i = 0; i < a.size(); ++i) {\n        this->m_vertices[i].parent\
    \ = i ? i - 1 : NONE;\n        this->m_vertices[i].left = NONE;\n        this->m_vertices[i].right\
    \ = NONE;\n        auto c = NONE;\n        while (this->m_vertices[i].parent !=\
    \ NONE && this->m_comp(a[i], a[this->m_vertices[i].parent])) {\n          if (c\
    \ != NONE) {\n            this->m_vertices[c].parent = this->m_vertices[i].parent;\n\
    \          }\n          c = this->m_vertices[i].parent;\n\n          const auto\
    \ gp = this->m_vertices[this->m_vertices[i].parent].parent;\n          this->m_vertices[this->m_vertices[i].parent].parent\
    \ = i;\n          this->m_vertices[i].parent = gp;\n        }\n      }\n\n   \
    \   auto root = NONE;\n      for (::std::size_t i = 0; i < a.size(); ++i) {\n\
    \        const auto p = this->m_vertices[i].parent;\n        if (p == NONE) {\n\
    \          root = i;\n        } else {\n          if (p < i) {\n            this->m_vertices[p].right=\
    \ i;\n          } else {\n            this->m_vertices[p].left = i;\n        \
    \  }\n        }\n      }\n\n      ::std::vector<::std::size_t> strict_left(a.size());\n\
    \      strict_left[root] = 0;\n      this->m_vertices[root].interval = ::std::make_pair(0,\
    \ a.size());\n      ::std::stack<::std::size_t> stack;\n      stack.push(root);\n\
    \      while (!stack.empty()) {\n        const auto here = stack.top();\n    \
    \    stack.pop();\n        const auto& v = this->m_vertices[here];\n        if\
    \ (v.right != NONE) {\n          strict_left[v.right] = here + 1;\n          this->m_vertices[v.right].interval\
    \ = ::std::make_pair(\n            this->m_comp(a[here], a[v.right]) ? strict_left[v.right]\
    \ : this->m_vertices[here].interval.first,\n            this->m_vertices[here].interval.second\n\
    \          );\n          stack.push(v.right);\n        }\n        if (v.left !=\
    \ NONE) {\n          strict_left[v.left] = strict_left[here];\n          this->m_vertices[v.left].interval\
    \ = ::std::make_pair(strict_left[v.left], here);\n          stack.push(v.left);\n\
    \        }\n      }\n    }\n    template <typename InputIterator>\n    cartesian_tree(const\
    \ InputIterator begin, const InputIterator end, const Compare& comp = Compare())\
    \ : cartesian_tree(::std::vector<T>(begin, end), comp) {\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_vertices.size();\n    }\n    const vertex&\
    \ get_vertex(::std::size_t i) const {\n      assert(i < this->size());\n     \
    \ return this->m_vertices[i];\n    }\n    const ::std::vector<vertex>& vertices()\
    \ const {\n      return this->m_vertices;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_CARTESIAN_TREE_HPP\n#define TOOLS_CARTESIAN_TREE_HPP\n\n#include\
    \ <functional>\n#include <cstddef>\n#include <utility>\n#include <vector>\n#include\
    \ <limits>\n#include <stack>\n#include <cassert>\n\nnamespace tools {\n  template\
    \ <typename T, typename Compare = ::std::less<T>>\n  class cartesian_tree {\n\
    \  public:\n    struct vertex {\n      ::std::size_t parent;\n      ::std::size_t\
    \ left;\n      ::std::size_t right;\n      ::std::pair<::std::size_t, ::std::size_t>\
    \ interval;\n    };\n\n  private:\n    Compare m_comp;\n    ::std::vector<vertex>\
    \ m_vertices;\n\n  public:\n    cartesian_tree() = default;\n    cartesian_tree(const\
    \ ::tools::cartesian_tree<T, Compare>&) = default;\n    cartesian_tree(::tools::cartesian_tree<T,\
    \ Compare>&&) = default;\n    ~cartesian_tree() = default;\n    ::tools::cartesian_tree<T,\
    \ Compare>& operator=(const ::tools::cartesian_tree<T, Compare>&) = default;\n\
    \    ::tools::cartesian_tree<T, Compare>& operator=(::tools::cartesian_tree<T,\
    \ Compare>&&) = default;\n\n    explicit cartesian_tree(const ::std::vector<T>&\
    \ a, const Compare& comp = Compare()) : m_comp(comp), m_vertices(a.size()) {\n\
    \      const auto NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    \
    \  for (::std::size_t i = 0; i < a.size(); ++i) {\n        this->m_vertices[i].parent\
    \ = i ? i - 1 : NONE;\n        this->m_vertices[i].left = NONE;\n        this->m_vertices[i].right\
    \ = NONE;\n        auto c = NONE;\n        while (this->m_vertices[i].parent !=\
    \ NONE && this->m_comp(a[i], a[this->m_vertices[i].parent])) {\n          if (c\
    \ != NONE) {\n            this->m_vertices[c].parent = this->m_vertices[i].parent;\n\
    \          }\n          c = this->m_vertices[i].parent;\n\n          const auto\
    \ gp = this->m_vertices[this->m_vertices[i].parent].parent;\n          this->m_vertices[this->m_vertices[i].parent].parent\
    \ = i;\n          this->m_vertices[i].parent = gp;\n        }\n      }\n\n   \
    \   auto root = NONE;\n      for (::std::size_t i = 0; i < a.size(); ++i) {\n\
    \        const auto p = this->m_vertices[i].parent;\n        if (p == NONE) {\n\
    \          root = i;\n        } else {\n          if (p < i) {\n            this->m_vertices[p].right=\
    \ i;\n          } else {\n            this->m_vertices[p].left = i;\n        \
    \  }\n        }\n      }\n\n      ::std::vector<::std::size_t> strict_left(a.size());\n\
    \      strict_left[root] = 0;\n      this->m_vertices[root].interval = ::std::make_pair(0,\
    \ a.size());\n      ::std::stack<::std::size_t> stack;\n      stack.push(root);\n\
    \      while (!stack.empty()) {\n        const auto here = stack.top();\n    \
    \    stack.pop();\n        const auto& v = this->m_vertices[here];\n        if\
    \ (v.right != NONE) {\n          strict_left[v.right] = here + 1;\n          this->m_vertices[v.right].interval\
    \ = ::std::make_pair(\n            this->m_comp(a[here], a[v.right]) ? strict_left[v.right]\
    \ : this->m_vertices[here].interval.first,\n            this->m_vertices[here].interval.second\n\
    \          );\n          stack.push(v.right);\n        }\n        if (v.left !=\
    \ NONE) {\n          strict_left[v.left] = strict_left[here];\n          this->m_vertices[v.left].interval\
    \ = ::std::make_pair(strict_left[v.left], here);\n          stack.push(v.left);\n\
    \        }\n      }\n    }\n    template <typename InputIterator>\n    cartesian_tree(const\
    \ InputIterator begin, const InputIterator end, const Compare& comp = Compare())\
    \ : cartesian_tree(::std::vector<T>(begin, end), comp) {\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_vertices.size();\n    }\n    const vertex&\
    \ get_vertex(::std::size_t i) const {\n      assert(i < this->size());\n     \
    \ return this->m_vertices[i];\n    }\n    const ::std::vector<vertex>& vertices()\
    \ const {\n      return this->m_vertices;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cartesian_tree/parent.test.cpp
  - tests/cartesian_tree/interval.test.cpp
documentation_of: tools/cartesian_tree.hpp
layout: document
title: Cartesian tree
---

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, the Cartesian tree is the binary tree obtained by recursively repeating the following operations on the interval $[0, n)$.

- Given an interval $[l, r)$, let $m$ be the point among $i \in [l, r)$ with the smallest $a_i$ (or the point with the smallest $i$ if there is more than one).
- Return a tree with vertex $m$ as root, the binary tree obtained from the interval $[l, m)$ as left child and the binary tree obtained from the interval $[m + 1, r)$ as right child.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
cartesian_tree<T> ct(std::vector<T> a);

(2)
cartesian_tree<T, Compare> ct(std::vector<T> a, Compare comp = Compare());

(3)
template <typename InputIterator>
cartesian_tree<T> ct(InputIterator begin, InputIterator end);

(4)
template <typename InputIterator>
cartesian_tree<T, Compare> ct(InputIterator begin, InputIterator end, Compare comp = Compare());
```

- (1)
    - It is identical to `cartesian_tree<T, std::less<T>> ct(a, std::less<T>{});`
- (2)
    - It constructs the Cartesian tree derived from $a$.
- (3)
    - It is identical to `cartesian_tree<T, std::less<T>> ct(std::vector<T>(begin, end), std::less<T>{});`
- (4)
    - It is identical to `cartesian_tree<T, Compare> ct(std::vector<T>(begin, end), comp);`

### Constraints
- (3), (4)
    - `begin` $\leq$ `end`

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t ct.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## get_vertex
```cpp
struct vertex {
  std::size_t parent;
  std::size_t left;
  std::size_t right;
  std::pair<std::size_t, std::size_t> interval;
};
const vertex& ct.get_vertex(std::size_t i);
```

It returns the information about $a_i$.

- `parent`: the parent node of $a_i$ (or `std::numeric_limits<std::size_t>::max()` if it does not exist)
- `left`: the left child node of $a_i$ (or `std::numeric_limits<std::size_t>::max()` if it does not exist)
- `right`: the right child node of $a_i$ (or `std::numeric_limits<std::size_t>::max()` if it does not exist)
- `interval`: the longest interval $[l, r)$ such that $0 \leq l \leq i < r \leq N$ and $\forall j. l \leq j < r \Rightarrow a_j \geq a_i$

### Constraints
- $0 \leq i < N$

### Time Complexity
- $O(1)$

## vertices
```cpp
const std::vector<vertex>& ct.vertices();
```

It returns $($ `ct.get_vertex(0) ` $, $ `ct.get_vertex(1)` $, \ldots, $ `ct.get_vertex(ct.size() - 1)` $)$.

### Constraints
- None

### Time Complexity
- $O(1)$
