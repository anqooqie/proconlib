---
title: Updatable priority queue
documentation_of: //tools/priority_queue.hpp
---

It is nearly `std::prirority_queue`, but allows you to update priority.

## Usage
```cpp
tools::priority_queue<std::string, int> pq;
pq.push(std::make_pair("abc", 5));
const std::pair<std::string, int> pair = pq.top();
pq.push(std::make_pair("abc", 7));
pq.erase("abc");
```

## License
- CC0

## Author
- anqooqie
