---
title: Run-length encoding
documentation_of: //tools/run_length.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void run_length(InputIterator begin, InputIterator end, OutputIterator result);
```

It replaces consecutive elements to a pair of the element and the number of occurrences, and stores the pairs with such a format to `result`. 

## Constraints
- None

## Time Complexity
- $O(N)$ where $N$ is `end` - `begin`.

## License
- CC0

## Author
- anqooqie
