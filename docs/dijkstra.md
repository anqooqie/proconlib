---
title: Dijkstra's algorithm
documentation_of: //tools/dijkstra.hpp
---

It is Dijkstra's algorithm.

## Usage
```cpp
tools::dijkstra<int> dijkstra(node_count);
dijkstra.add_edge(from_node, to_node, cost);
const tools::dijkstra<int>::result result = dijkstra.query(start_node);
for (const int& distance : result.distances) {
  // ...
}
```

The type parameter `<T>` is the type of weight of edges.

## License
- CC0

## Author
- anqooqie
