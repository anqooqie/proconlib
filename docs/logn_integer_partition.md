---
title: Multiset $S$ such that $\{\sum_{x \in S'} x | S' \subseteq S\} = \{0, 1, \ldots, N\}$ and $|S| = O(\log N)$
documentation_of: //tools/logn_integer_partition.hpp
---

```cpp
template <typename T>
std::vector<T> logn_integer_partition(T n);
```

It returns a multiset $S$ such that $\\{\sum_{x \in S'} x \| S' \subseteq S\\} = \\{0, 1, \ldots, N\\}$ and $\|S\| = O(\log N)$.

## Constraints
- $n \geq 0$

## Time Complexity
- $O(\log n)$

## License
- CC0

## Author
- anqooqie
