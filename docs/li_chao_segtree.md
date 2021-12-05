---
title: Li Chao segment tree
documentation_of: //tools/li_chao_segtree.hpp
---

It is a data structure which supports the following operations.

- Add a straight line $y = ax + b$.
- Find the maximal $y$ at given $x$.

It is required to give a predefined list of possible $x$s to a constructor.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename Iterator>
li_chao_segtree<T, Compare = std::less<T>> segtree(Iterator begin, Iterator end);

template <typename Iterator>
li_chao_segtree<T, Compare = std::less<T>> segtree(Iterator begin, Iterator end, Compare comp);
```

It creates an empty set of straight lines.
$\[\mathrm{begin}, \mathrm{end})$ represents a list of possible $x$s.
If `std::greater<T>()` are given as `comp`, it will be able to find the minimal $y$ instead of the maximal.

### Constraints
- $\mathrm{end} - \mathrm{begin} \geq 1$
- $\[\mathrm{begin}, \mathrm{end})$ are sorted.

### Time Complexity
- $O(n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$

## add
```cpp
void segtree.add(T a, T b);
```

It adds a straight line $y = ax + b$ to the set.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$

## query
```cpp
T segtree.query(T x);
```

It returns the maximal $y$ at given $x$.

### Constraints
- $x$ is in the predefined list of possible parameters.

### Time Complexity
- $O(\log n)$ where $n$ is $\mathrm{end} - \mathrm{begin}$
