---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/group.hpp
    title: Typical groups
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/pdsu.test.cpp
    title: tests/pdsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pdsu.hpp\"\n\n\n\n#include <vector>\n#include <cassert>\n\
    #include <numeric>\n#include <utility>\n#line 1 \"tools/group.hpp\"\n\n\n\nnamespace\
    \ tools {\n  namespace group {\n    template <typename G>\n    struct plus {\n\
    \      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n       \
    \ return lhs + rhs;\n      }\n      static T e() {\n        return T(0);\n   \
    \   }\n      static T inv(const T& v) {\n        return -v;\n      }\n    };\n\
    \n    template <typename G>\n    struct multiplies {\n      using T = G;\n   \
    \   static T op(const T& lhs, const T& rhs) {\n        return lhs * rhs;\n   \
    \   }\n      static T e() {\n        return T(1);\n      }\n      static T inv(const\
    \ T& v) {\n        return e() / v;\n      }\n    };\n\n    template <typename\
    \ G>\n    struct bit_xor {\n      using T = G;\n      static T op(const T& lhs,\
    \ const T& rhs) {\n        return lhs ^ rhs;\n      }\n      static T e() {\n\
    \        return T(0);\n      }\n      static T inv(const T& v) {\n        return\
    \ v;\n      }\n    };\n  }\n}\n\n\n#line 9 \"tools/pdsu.hpp\"\n\nnamespace tools\
    \ {\n  enum class pdsu_diff {\n    known,\n    unknown,\n    inconsistent\n  };\n\
    \n  template <typename G = ::tools::group::plus<long long>>\n  class pdsu {\n\
    \  private:\n    using T = typename G::T;\n\n    ::std::vector<int> m_parents;\n\
    \    ::std::vector<int> m_sizes;\n    ::std::vector<T> m_diffs;\n    ::std::vector<bool>\
    \ m_consistent;\n\n  public:\n    pdsu(const int n) :\n      m_parents(n),\n \
    \     m_sizes(n, 1),\n      m_diffs(n, G::e()),\n      m_consistent(n, true) {\n\
    \      assert(n >= 0);\n      ::std::iota(this->m_parents.begin(), this->m_parents.end(),\
    \ 0);\n    }\n\n    int size() const {\n      return this->m_parents.size();\n\
    \    }\n\n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      if (this->m_parents[x] == x) {\n        return x;\n      }\n      const\
    \ auto r = this->leader(this->m_parents[x]);\n      if (this->m_consistent[r])\
    \ {\n        this->m_diffs[x] = G::op(this->m_diffs[x], this->m_diffs[this->m_parents[x]]);\n\
    \      }\n      return this->m_parents[x] = r;\n    }\n\n    ::std::pair<::tools::pdsu_diff,\
    \ T> diff(const int x, const int y) {\n      assert(0 <= x && x < this->size());\n\
    \      assert(0 <= y && y < this->size());\n      const auto x_r = this->leader(x);\n\
    \      const auto y_r = this->leader(y);\n      if (x_r == y_r) {\n        if\
    \ (this->m_consistent[x_r]) {\n          return ::std::make_pair(::tools::pdsu_diff::known,\
    \ G::op(this->m_diffs[y], G::inv(this->m_diffs[x])));\n        } else {\n    \
    \      return ::std::make_pair(::tools::pdsu_diff::inconsistent, G::e());\n  \
    \      }\n      } else {\n        return ::std::make_pair(::tools::pdsu_diff::unknown,\
    \ G::e());\n      }\n    }\n\n    bool same(const int x, const int y) {\n    \
    \  assert(0 <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\
    \      return this->leader(x) == this->leader(y);\n    }\n\n    int merge(int\
    \ x, int y, T w) {\n      assert(0 <= x && x < this->size());\n      assert(0\
    \ <= y && y < this->size());\n\n      auto x_r = this->leader(x);\n      auto\
    \ y_r = this->leader(y);\n\n      if (x_r == y_r) {\n        this->m_consistent[x_r]\
    \ = (this->m_consistent[x_r] && G::op(this->m_diffs[x], w) == this->m_diffs[y]);\n\
    \        return x_r;\n      }\n\n      if (this->m_sizes[x_r] < this->m_sizes[y_r])\
    \ {\n        ::std::swap(x, y);\n        w = G::inv(w);\n        ::std::swap(x_r,\
    \ y_r);\n      }\n      this->m_parents[y_r] = x_r;\n      this->m_sizes[x_r]\
    \ += this->m_sizes[y_r];\n      if (this->m_consistent[x_r] = (this->m_consistent[x_r]\
    \ && this->m_consistent[y_r])) {\n        this->m_diffs[y_r] = G::op(G::op(w,\
    \ this->m_diffs[x]), G::inv(this->m_diffs[y]));\n      }\n      return x_r;\n\
    \    }\n\n    int size(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      return this->m_sizes[this->leader(x)];\n    }\n\n    ::std::vector<::std::vector<int>>\
    \ groups() {\n      ::std::vector<int> group_indices(this->size(), -1);\n    \
    \  int next_group_index = 0;\n      for (int i = 0; i < this->size(); ++i) {\n\
    \        if (group_indices[this->leader(i)] == -1) {\n          group_indices[this->leader(i)]\
    \ = next_group_index;\n          ++next_group_index;\n        }\n      }\n\n \
    \     ::std::vector<::std::vector<int>> groups(next_group_index);\n      for (int\
    \ i = 0; i < this->size(); ++i) {\n        groups[group_indices[this->leader(i)]].push_back(i);\n\
    \      }\n\n      return groups;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PDSU_HPP\n#define TOOLS_PDSU_HPP\n\n#include <vector>\n#include\
    \ <cassert>\n#include <numeric>\n#include <utility>\n#include \"tools/group.hpp\"\
    \n\nnamespace tools {\n  enum class pdsu_diff {\n    known,\n    unknown,\n  \
    \  inconsistent\n  };\n\n  template <typename G = ::tools::group::plus<long long>>\n\
    \  class pdsu {\n  private:\n    using T = typename G::T;\n\n    ::std::vector<int>\
    \ m_parents;\n    ::std::vector<int> m_sizes;\n    ::std::vector<T> m_diffs;\n\
    \    ::std::vector<bool> m_consistent;\n\n  public:\n    pdsu(const int n) :\n\
    \      m_parents(n),\n      m_sizes(n, 1),\n      m_diffs(n, G::e()),\n      m_consistent(n,\
    \ true) {\n      assert(n >= 0);\n      ::std::iota(this->m_parents.begin(), this->m_parents.end(),\
    \ 0);\n    }\n\n    int size() const {\n      return this->m_parents.size();\n\
    \    }\n\n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      if (this->m_parents[x] == x) {\n        return x;\n      }\n      const\
    \ auto r = this->leader(this->m_parents[x]);\n      if (this->m_consistent[r])\
    \ {\n        this->m_diffs[x] = G::op(this->m_diffs[x], this->m_diffs[this->m_parents[x]]);\n\
    \      }\n      return this->m_parents[x] = r;\n    }\n\n    ::std::pair<::tools::pdsu_diff,\
    \ T> diff(const int x, const int y) {\n      assert(0 <= x && x < this->size());\n\
    \      assert(0 <= y && y < this->size());\n      const auto x_r = this->leader(x);\n\
    \      const auto y_r = this->leader(y);\n      if (x_r == y_r) {\n        if\
    \ (this->m_consistent[x_r]) {\n          return ::std::make_pair(::tools::pdsu_diff::known,\
    \ G::op(this->m_diffs[y], G::inv(this->m_diffs[x])));\n        } else {\n    \
    \      return ::std::make_pair(::tools::pdsu_diff::inconsistent, G::e());\n  \
    \      }\n      } else {\n        return ::std::make_pair(::tools::pdsu_diff::unknown,\
    \ G::e());\n      }\n    }\n\n    bool same(const int x, const int y) {\n    \
    \  assert(0 <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\
    \      return this->leader(x) == this->leader(y);\n    }\n\n    int merge(int\
    \ x, int y, T w) {\n      assert(0 <= x && x < this->size());\n      assert(0\
    \ <= y && y < this->size());\n\n      auto x_r = this->leader(x);\n      auto\
    \ y_r = this->leader(y);\n\n      if (x_r == y_r) {\n        this->m_consistent[x_r]\
    \ = (this->m_consistent[x_r] && G::op(this->m_diffs[x], w) == this->m_diffs[y]);\n\
    \        return x_r;\n      }\n\n      if (this->m_sizes[x_r] < this->m_sizes[y_r])\
    \ {\n        ::std::swap(x, y);\n        w = G::inv(w);\n        ::std::swap(x_r,\
    \ y_r);\n      }\n      this->m_parents[y_r] = x_r;\n      this->m_sizes[x_r]\
    \ += this->m_sizes[y_r];\n      if (this->m_consistent[x_r] = (this->m_consistent[x_r]\
    \ && this->m_consistent[y_r])) {\n        this->m_diffs[y_r] = G::op(G::op(w,\
    \ this->m_diffs[x]), G::inv(this->m_diffs[y]));\n      }\n      return x_r;\n\
    \    }\n\n    int size(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      return this->m_sizes[this->leader(x)];\n    }\n\n    ::std::vector<::std::vector<int>>\
    \ groups() {\n      ::std::vector<int> group_indices(this->size(), -1);\n    \
    \  int next_group_index = 0;\n      for (int i = 0; i < this->size(); ++i) {\n\
    \        if (group_indices[this->leader(i)] == -1) {\n          group_indices[this->leader(i)]\
    \ = next_group_index;\n          ++next_group_index;\n        }\n      }\n\n \
    \     ::std::vector<::std::vector<int>> groups(next_group_index);\n      for (int\
    \ i = 0; i < this->size(); ++i) {\n        groups[group_indices[this->leader(i)]].push_back(i);\n\
    \      }\n\n      return groups;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/group.hpp
  isVerificationFile: false
  path: tools/pdsu.hpp
  requiredBy: []
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/pdsu.test.cpp
documentation_of: tools/pdsu.hpp
layout: document
title: Potentialized disjoint set union
---

Given an unknown integer sequence $a_0, a_1, \ldots, a_{n - 1}$ and an abelian group $G$, it processes the following queries in $O(\alpha(n))$ time (amortized).

- Accepting the information $a_y - a_x = w$ under the abelian group $G$
- Reporting $a_y - a_x$ under the abelian group $G$

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename G = tools::group::plus<long long>>
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

It accepts the information $a_y - a_x = w$.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## diff
```cpp
enum class pdsu_diff {
  known,
  unknown,
  inconsistent
};
std::pair<tools::pdsu_diff, typename G::T> d.diff(int x, int y);
```

If $a_y - a_x$ can be calculated consistently, it returns $(\mathrm{known}, a_y - a_x)$.
If $a_y - a_x$ is still unknown under the information accepted so far, it returns $(\mathrm{unknown}, e)$ where $e$ is `G::e()`.
If it turns out that the consistent value of $a_y - a_x$ cannot be obtained, it returns $(\mathrm{inconsistent}, e)$ where $e$ is `G::e()`.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## same
```cpp
bool d.same(int x, int y);
```

If $a_y - a_x$ is still unknown under the information accepted so far, it returns `false`.
Otherwise, it returns `true`.

### Constraints
- $0 \leq x < n$
- $0 \leq y < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## leader
```cpp
int d.leader(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if `same(y, z)` holds, the graph can be divided into some connected components.
It returns the reprensative vertex of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## size
```cpp
int d.size(int x);
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if `same(y, z)` holds, the graph can be divided into some connected components.
It returns the size of the connected component which contains $x$.

### Constraints
- $0 \leq x < n$

### Time Complexity
- $O(\alpha(n))$ amortized

## groups
```cpp
std::vector<std::vector<int>> d.groups();
```

If an undirected graph with $n$ vertices is given and we connect the vertices $y$ and $z$ if and only if `same(y, z)` holds, the graph can be divided into some connected components.
It returns the list of the connected components.

### Constraints
- None

### Time Complexity
- $O(n)$
