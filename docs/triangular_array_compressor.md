---
title: One-to-one mapping from a triangular array to a one-dimensional array
documentation_of: //tools/triangular_array_compressor.hpp
---

It is a one-to-one mapping $f: S \to T$ where $(S, T)$ is one of the following pairs.

- $S = \lbrace (i, j) \in \mathbb{N}^2 \mid 0 \leq i < j < n \rbrace, T = \left\lbrace k \in \mathbb{N} \mid 0 \leq k < \frac{n (n - 1)}{2} \right\rbrace$
- $S = \lbrace (i, j) \in \mathbb{N}^2 \mid 0 \leq i \leq j < n \rbrace, T = \left\lbrace k \in \mathbb{N} \mid 0 \leq k < \frac{n (n + 1)}{2} \right\rbrace$
- $S = \lbrace (i, j) \in \mathbb{N}^2 \mid 0 \leq j < i < n \rbrace, T = \left\lbrace k \in \mathbb{N} \mid 0 \leq k < \frac{n (n - 1)}{2} \right\rbrace$
- $S = \lbrace (i, j) \in \mathbb{N}^2 \mid 0 \leq j \leq i < n \rbrace, T = \left\lbrace k \in \mathbb{N} \mid 0 \leq k < \frac{n (n + 1)}{2} \right\rbrace$

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
triangular_array_compressor<Compare> f(int n);
```

It is a one-to-one mapping $f: S \to T$ where $S$ is $\lbrace (i, j) \in \mathbb{N}^2 \mid 0 \leq i < n \land 0 \leq j < n \land \mathrm{Compare}()(i, j) \rbrace$ and $T$ is $\left\lbrace k \in \mathbb{N} \mid 0 \leq k < \|S\| \right\rbrace$.

### Constraints
- $n \geq 0$
- `<Compare>` is any one of `std::less<int>`, `std::less_equal<int>`, `std::greater<int>` or `std::greater_equal<int>`.

### Time Complexity
- $O(1)$

## size
```cpp
int f.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## compress
```cpp
int f.compress(int i, int j);
```

It returns $f(i, j)$.

### Constraints
- $0 \leq i < n$
- $0 \leq j < n$
- `Compare()(i, j)`

### Time Complexity
- $O(1)$

## decompress
```cpp
std::pair<int, int> f.decompress(int k);
```

It returns $f^{-1}(k)$.

### Constraints
- (`<Compare>` is `std::less<int>` or `std::greater<int>`): $0 \leq k < \frac{n (n - 1)}{2}$
- (`<Compare>` is `std::less_equal<int>` or `std::greater_equal<int>`): $0 \leq k < \frac{n (n + 1)}{2}$

### Time Complexity
- $O(1)$
