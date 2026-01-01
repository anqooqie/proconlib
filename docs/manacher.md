---
title: Manacher
documentation_of: //tools/manacher.hpp
---

Given an integer sequence $(a_0, a_1, \ldots, a_{n - 1})$, it calculates the longest palindrome centered on $a_i$ for each $i = 0, 1, \ldots, n - 1$ and the longest palindrome centered on the $i$-th one of the $n + 1$ boundaries between the integers for each $i = 0, 1, \ldots, n$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <std::ranges::input_range R>
requires tools::integral<std::ranges::range_value_t<R>>
manacher a(R&& r);
```

Given an integer sequence, it calculates the longest palindromes.

### Constraints
- None

### Time Complexity
- $O(n)$

## size
```cpp
int a.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## odd_length
```cpp
(1) int a.odd_length(int i);
(2) int a.odd_length<false>(int i);
(3) std::pair<int, int> a.odd_length<true>(int i);
```

- (1), (2)
    - It returns the length of the longest palindrome centered on $a_i$.
- (3)
    - It returns the integer pair $(l, r)$ such that $(a_l, a_{l + 1}, \ldots, a_{r - 1})$ is the longest palindrome centered on $a_i$.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$

## even_length
```cpp
(1) int a.even_length(int i);
(2) int a.even_length<false>(int i);
(3) std::pair<int, int> a.even_length<true>(int i);
```

- (1), (2)
    - It returns the length of the longest palindrome centered on the $i$-th one of the $n + 1$ boundaries between the integers.
- (3)
    - It returns the integer pair $(l, r)$ such that $(a_l, a_{l + 1}, \ldots, a_{r - 1})$ is the longest palindrome centered on the $i$-th one of the $n + 1$ boundaries between the integers.

### Constraints
- $0 \leq i \leq n$

### Time Complexity
- $O(1)$
