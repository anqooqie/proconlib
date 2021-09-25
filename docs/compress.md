---
title: Compress values
documentation_of: //tools/compress.hpp
---

## (1)

```cpp
template <typename InputIterator>
std::pair<std::map<typename std::iterator_traits<InputIterator>::value_type, typename std::iterator_traits<InputIterator>::value_type>, std::vector<typename std::iterator_traits<InputIterator>::value_type>> compress(InputIterator begin, InputIterator end);
```

It maps the $i$-th least integer in a given integer set to $i - 1$ and returns the mapping and the inverse mapping.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie

## (2)

```cpp
template <typename InputIterator, typename OutputIterator>
void compress(InputIterator begin, InputIterator end, OutputIterator result);
```

It maps the $i$-th least integer in a given integer sequence from `begin` to `end` to $i - 1$ and returns the mapped integer sequence.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie
