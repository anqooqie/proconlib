---
title: Eight directions in a 2D grid
documentation_of: //tools/eight_directions.hpp
---

```cpp
template <tools::signed_integral T>
constexpr const std::array<std::pair<T, T>, 8>& eight_directions();
```

It returns the eight adjacent directions in a 2D grid as offsets $(dr, dc)$, where $dr$ and $dc$ are the deltas of the row and the column respectively.
The directions are listed in clockwise order starting from $(0, 1)$:

$$((0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1))$$

The $(dr, dc)$ ordering matches the convention used in recent AtCoder grid problems.

If you would like to use `tools::vector2<T>` instead of `std::pair<T, T>`, see `tools::vector2<T>::eight_directions()`.
Note that its enumeration order differs from this header.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
