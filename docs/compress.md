---
title: Compress values
documentation_of: //tools/compress.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void compress(InputIterator begin, InputIterator end, OutputIterator result);
```

It maps the $i$-th ($0$-indexed) least integer in a given integer sequence from `begin` to `end` to $i$ and returns the mapped integer sequence.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie
