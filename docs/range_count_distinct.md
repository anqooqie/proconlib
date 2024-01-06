---
title: Range count distinct
documentation_of: //tools/range_count_distinct.hpp
---

It takes an integer sequence $(a_0, a_1, \ldots, a_{N - 1})$ as input and can answer the number of distinct integers occured in $(a_l, a_{l + 1}, \ldots, a_{r - 1})$ in $\langle O(N \log N), O(\log N) \rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
range_count_distinct a(InputIterator begin, InputIterator end);
```

It takes an integer sequence $(a_0, a_1, \ldots, a_{N - 1})$ as input.

### Constraints
- `begin` $\leq$ `end`
- `std::decay_t<decltype(*std::declval<InputIterator>())>` is one of integral types.

### Time Complexity
- $O(N \log N)$

## size
```cpp
std::size_t a.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
std::size_t a.query(std::size_t l, std::size_t r);
```

It returns the number of distinct integers occured in $(a_l, a_{l + 1}, \ldots, a_{r - 1})$.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(\log N)$
