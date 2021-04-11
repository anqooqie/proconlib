---
title: Topological sorting
documentation_of: //tools/tsort.hpp
---

It is topological sorting.

## Usage
```cpp
tools::tsort tsort(node_count);
tsort.add_edge(from_node, to_node);
std::vector<i64> result;
tsort.query(std::back_inserter(result));
```

## License
- CC0

## Author
- anqooqie
