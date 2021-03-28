---
title: 01-BFS
documentation_of: //tools/zero_one_bfs.hpp
---

It is 01-BFS.

## Usage
```cpp
tools::zero_one_bfs<int> bfs(node_count);
bfs.add_edge(from_node, to_node, cost);
const tools::zero_one_bfs<int>::result result = bfs.query(start_node);
for (const int& distance : result.distances) {
  // ...
}
```

The type parameter `<T>` is the type of weight of edges.

## License
- CC0

## Author
- anqooqie
