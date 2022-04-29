---
title: Diameter of a tree
documentation_of: //tools/tree_diameter.hpp
---

It returns the diameter of the given tree.

## License
- CC0

## Author
- anqooqie

## Constructor
```cpp
tree_diameter<T> tree(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.
The type parameter `<T>` is the type of the weight of edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t tree.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
std::size_t tree.add_edge(std::size_t u, std::size_t v, T w);
```

It adds an undirected edge connecting $u$ and $v$ with weight $w$ to the graph, and returns the index of the added edge.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## query
```cpp
std::tuple<T, std::vector<std::size_t>, std::vector<std::size_t>> tree.query();
```

It returns the distance of the path from $u$ to $v$ where $(u, v)$ is one of the farthest pairs in the tree.
Also, it returns the indices of the vertices which is contained in the path, and the indices of the edges which is contained in the path.

### Constraints
- The graph is a tree.

### Time Complexity
- $O(1)$ amortized
