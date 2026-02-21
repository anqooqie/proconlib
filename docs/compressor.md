---
title: Compress values (for more complicated cases)
documentation_of: //tools/compressor.hpp
---

Given a set of integers, it assigns each element a zero-indexed rank according to sorted order, and supports the inverse mapping from ranks back to values.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename T>
requires std::sortable<typename std::vector<T>::iterator>
      && std::equality_comparable<T>
template <std::ranges::input_range R>
requires std::constructible_from<T, std::ranges::range_reference_t<R>>
compressor<T> cp(R&& range);
```

It creates a compressor from the elements in `range`.
If `T` is not specified explicitly, it is deduced as `std::ranges::range_value_t<R>`.

### Constraints
- None

### Time Complexity
- $O(n \log n)$ where $n$ is `std::ranges::distance(range)`

## size
```cpp
int cp.size();
```

It returns the number of distinct values.

### Constraints
- None

### Time Complexity
- $O(1)$

## compress
```cpp
int cp.compress(T x);
```

It returns the zero-indexed rank of $x$ in sorted order.

### Constraints
- $x$ is present in the set.

### Time Complexity
- $O(\log n)$ where $n$ is `cp.size()`

## decompress
```cpp
T cp.decompress(int i);
```

It returns the value whose zero-indexed rank is $i$.

### Constraints
- $0 \leq i < $ `cp.size()`

### Time Complexity
- $O(1)$

## contains
```cpp
bool cp.contains(T x);
```

It returns whether $x$ is present in the set.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is `cp.size()`

## begin
```cpp
typename std::vector<T>::const_iterator cp.begin();
```

It returns an iterator to the smallest value in the set.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
typename std::vector<T>::const_iterator cp.end();
```

It returns a past-the-end iterator for the set.

### Constraints
- None

### Time Complexity
- $O(1)$
