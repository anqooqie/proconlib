---
title: Transposition
documentation_of: //tools/transposed.hpp
---

```cpp
template <typename T>
std::vector<std::vector<T>> transposed(std::vector<std::vector<T>> A);

template <typename T, std::size_t N>
std::vector<std::array<T, N>> transposed(std::array<std::vector<T>, N> A);

template <typename T, std::size_t M>
std::array<std::vector<T>, M> transposed(std::vector<std::array<T, M>> A);

template <typename T, std::size_t N, std::size_t M>
std::array<std::array<T, N>, M> transposed(std::array<std::array<T, M>, N> A);
```

Given a $N \times M$ matrix $A$, it returns a $M \times N$ matrix $A^\mathsf{T}$.
If $N = 0$ and a row is `std::vector<T>`, it assumes $M = 0$ since $M$ cannot be determined.

### Constraints
- For all $r$ such that $0 \leq r < N$, `A[r].size()` equals $M$.

### Time Complexity
- $O(NM)$

### License
- CC0

### Author
- anqooqie
