---
title: Enumerate the range of $\left\lfloor \frac{A}{x} \right\rfloor$
documentation_of: //tools/floor_quotients.hpp
---

```cpp
template <typename T>
std::vector<std::tuple<T, T, T>> floor_quotients(T A);
```

It returns the tuples such that the $i$-th tuple $(l_i, r_i, q_i)$ satisfies $l_i \leq x < r_i \Rightarrow \left\lfloor \frac{A}{x} \right\rfloor = q_i$, in ascending order of $l_i$.
The last tuple would be $(A + 1, \infty, 0)$ mathematically, but it actually returns `std::numeric_limits<T>::max()` instead of $\infty$ since a integral type `<T>` cannot represent infinity.

## Constraints
- `<T>` is a built-in integral type.
- $A \geq 0$

## Time Complexity
- $O(\sqrt{x})$

## License
- CC0

## Author
- anqooqie
