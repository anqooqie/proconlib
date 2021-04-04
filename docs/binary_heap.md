---
title: Binary heap
documentation_of: //tools/binary_heap.hpp
---

It is nearly `std::prirority_queue`, but allows you to update priority.

## Usage
```cpp
tools::binary_heap<std::string, int> heap;
heap.push(std::make_pair("abc", 5));
const std::pair<std::string, int> pair = heap.top();
heap.push(std::make_pair("abc", 7));
heap.erase("abc");
```

## License
- CC0

## Author
- anqooqie
