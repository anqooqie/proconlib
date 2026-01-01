---
title: Range count distinct
documentation_of: //tools/range_count_distinct.hpp
---

It takes a sequence $(a_0, a_1, \ldots, a_{N - 1})$ as input and can answer the number of distinct elements occured in $(a_l, a_{l + 1}, \ldots, a_{r - 1})$ in $\langle O(N \log N), O(\log N) \rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <std::ranges::input_range R>
requires std::totally_ordered<std::ranges::range_value_t<R>>
range_count_distinct a(R&& r);
```

It takes a sequence $(a_0, a_1, \ldots, a_{N - 1})$ as input.

### Constraints
- None

### Time Complexity
- $O(N \log N)$

## size
```cpp
int a.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
int a.query(int l, int r);
```

It returns the number of distinct elements occured in $(a_l, a_{l + 1}, \ldots, a_{r - 1})$.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(\log N)$
