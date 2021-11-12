---
title: Permutation
documentation_of: //tools/permutation.hpp
---

It is a permutation of $n$ elements.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
permutation<T> p(std::size_t n);
```

It creates an identity permutation of $n$ elements.
The type parameter `<T>` represents the type of the elements.

### Constraints
- None

### Time Complexity
- $O(n)$

## operator[]
```cpp
T p[std::size_t i];
```

It returns the position to which the $i$-th element mapped by the permutation.
In other words, the permutation maps the $i$-th element to the `p[i]`-th element.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## begin
```cpp
typename std::vector<T>::const_iterator p.begin();
```

It returns the iterator pointing to the first element.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
typename std::vector<T>::const_iterator p.end();
```

It returns the iterator pointing to the element which would follow the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t p.size();
```

It returns the number of elements.

### Constraints
- None

### Time Complexity
- $O(1)$

## swap
```cpp
void p.swap(std::size_t i, std::size_t j);
```

It swaps the $i$-th element and the $j$-th element.

### Constraints
- $0 \leq i < n$
- $0 \leq j < n$

### Time Complexity
- $O(1)$

## inv
```cpp
tools::permutation<T> p.inv();
```

It returns the inversion of the permutation.

### Constraints
- None

### Time Complexity
- $O(n)$

## operator*
```cpp
tools::permutation<T> p1 * p2;
```

It merges two permutations, $p_2$ and $p_1$, and returns the merged permutation.

### Constraints
- `p1.size() == p2.size()`

### Time Complexity
- $O(n)$
