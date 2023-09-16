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
