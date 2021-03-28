---
title: Bellman-Ford algorithm
documentation_of: //tools/bellman_ford.hpp
---

It is Bellman-Ford algorithm.

## Usage
```cpp
tools::bellman_ford<int> bf(node_count);
bf.add_edge(from_node, to_node, cost);
const tools::bellman_ford<int>::result result = bf.query(start_node);
for (const int& distance : result.distances) {
  // ...
}
```

The type parameter `<T>` is the type of weight of edges.

## License
- CC0

## Author
- anqooqie
