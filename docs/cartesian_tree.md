---
title: Cartesian tree
documentation_of: //tools/cartesian_tree.hpp
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
template <std::ranges::input_range R, typename Compare = std::ranges::less>
requires std::indirect_strict_weak_order<Compare, typename std::vector<std::ranges::range_value_t<R>>::iterator>
cartesian_tree ct(R&& a, Compare comp = {});
```

It constructs the Cartesian tree derived from $a$.

### Constraints
- None

### Time Complexity
- $O(N)$

## size
```cpp
int ct.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## get_vertex
```cpp
struct vertex {
  int parent;
  int left;
  int right;
  std::pair<int, int> interval;
};
const vertex& ct.get_vertex(int i);
```

It returns the information about $a_i$.

- `parent`: the parent node of $a_i$ (or $-1$ if it does not exist)
- `left`: the left child node of $a_i$ (or $-1$ if it does not exist)
- `right`: the right child node of $a_i$ (or $-1$ if it does not exist)
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
