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
(1) permutation<T> p(std::size_t n);
(2) template <typename Iterator> permutation<T> p(Iterator begin, Iterator end);
```

It creates an identity permutation of $n$ elements.
The type parameter `<T>` represents the type of the elements.

### Constraints
- (1)
    - None
- (2)
    - All elements of $\[\mathrm{begin}, \mathrm{end})$ are unique.
    - All elements of $\[\mathrm{begin}, \mathrm{end})$ are $0$ or more.
    - All elements of $\[\mathrm{begin}, \mathrm{end})$ are less than $\mathrm{end} - \mathrm{begin}$.

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

It returns $p^{-1}$.
$p^{-1}$ maps the `p[i]`-th element to the $i$-th element.

### Constraints
- None

### Time Complexity
- $O(n)$

## operator*
```cpp
tools::permutation<T> p2 * p1;
```

It returns the merged permutation $p_3 = p_2 \circ p_1$.
$p_3$ maps the $i$-th element to the `p2[p1[i]]`-th element.

### Constraints
- `p1.size() == p2.size()`

### Time Complexity
- $O(n)$
