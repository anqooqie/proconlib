---
title: Prim's algorithm
documentation_of: //tools/prim.hpp
---

It is Prim's algorithm.

## Usage
```cpp
tools::prim<int> prim(node_count);
prim.add_edge(from_node, to_node, cost);
const tools::prim<int>::result result = prim.query();
result.total_distance;
```

The type parameter `<T>` is the type of weight of edges.

## License
- CC0

## Author
- anqooqie
