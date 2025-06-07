---
title: Triangular array
documentation_of: //tools/triangular_array.hpp
---

It is a memory-efficient doubly indexed sequence $a_{i, j}$ such that one of the following conditions holds.

- $0 \leq i < j < n$
- $0 \leq i \leq j < n$
- $0 \leq j < i < n$
- $0 \leq j \leq i < n$

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
triangular_array<T, Compare> a(int n);
```

It is a memory-efficient doubly indexed sequence $a_{i, j}$ such that $0 \leq i < n$, $0 \leq j < n$ and `Compare()(i, j)`.

### Constraints
- $n \geq 0$
- `<Compare>` is any one of `std::less<int>`, `std::less_equal<int>`, `std::greater<int>` or `std::greater_equal<int>`.

### Time Complexity
- $O(n^2)$

## size
```cpp
int a.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
T& a[i][j];
```

It is a reference to $a_{i, j}$.

### Constraints
- $0 \leq i < n$
- $0 \leq j < n$
- `Compare()(i, j)`

### Time Complexity
- $O(1)$

## operator&gt;&gt;
```cpp
std::istream& operator>>(std::istream& is, triangular_array<T, Compare>& a);
```

It reads $a_{i, j}$ from `is` in the lexicographic order of $(i, j)$.

### Constraints
- None

### Time Complexity
- $O(n^2)$
