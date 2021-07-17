---
title: Compress values
documentation_of: //tools/compress.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void compress(InputIterator begin, InputIterator end, OutputIterator result);
```

It compresses the values from `begin` to `end` while keeping its magnitude relationship.

## Constraints
- `begin` $\leq$ `end`

## Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
