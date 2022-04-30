---
title: Cycle detection on a directed graph
documentation_of: //tools/cycle_detection.hpp
---

It reports one of the cycles in a given directed graph if it exists.

## License
- CC0

## Author
- anqooqie

## Constructor
```cpp
cycle_detection graph(std::size_t n);
```

It creates a directed graph with $n$ vertices and $0$ edges.

### Constraints
- None

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t graph.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
std::size_t graph.add_edge(std::size_t u, std::size_t v);
```

It adds a directed edge from $u$ to $v$ to the graph, and returns the index of the added edge.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## query
```cpp
std::optional<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> graph.query();
```

It finds one of the cycles in a given directed graph.
If such the cycle does not exist, it returns `std::nullopt`.
If such the cycle exists, it returns the indices of the vertices which are contained in the cycle and the indices of the edges which are contained in the cycle.

### Constraints
- None

### Time Complexity
- $O(n)$
