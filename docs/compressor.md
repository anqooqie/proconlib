---
title: Compress values (for more complicated cases)
documentation_of: //tools/compressor.hpp
---

It provides the mapping which maps the $i$-th ($0$-indexed) least integer in a given integer set to $i$, and the inverse mapping of it.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
template <typename InputIterator>
compressor<T> cp(InputIterator begin, InputIterator end);

(2)
compressor<T> cp(std::ranges::range range);
```

It creates an integer set initialized with a given integer range.

### Constraints
- None

### Time Complexity
- (1)
    - $O(n \log n)$ where $n$ is `std::distance(begin, end)`
- (2)
    - $O(n \log n)$ where $n$ is `std::ranges::distance(range)`

## size
```cpp
T cp.size();
```

It returns the number of distinct integers in the set.

### Constraints
- None

### Time Complexity
- $O(1)$

## compress
```cpp
T cp.compress(T x);
```

It returns $i$ such that the $i$-th ($0$-indexed) least integer in the set is $x$.

### Constraints
- The set contains $x$.

### Time Complexity
- $O(\log n)$ where $n$ is `cp.size()`

## decompress
```cpp
T cp.decompress(T i);
```

It returns the $i$-th ($0$-indexed) least integer in the set.

### Constraints
- $0 \leq i < $ `cp.size()`

### Time Complexity
- $O(1)$

## contains
```cpp
bool cp.contains(T x);
```

It returns whether the set contains $x$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is `cp.size()`

## begin
```cpp
typename std::vector<T>::const_iterator cp.begin();
```

It returns the iterator pointing to the least integer in the set.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
typename std::vector<T>::const_iterator cp.end();
```

It returns the iterator pointing to the integer which would follow the largest integer in the set.

### Constraints
- None

### Time Complexity
- $O(1)$
