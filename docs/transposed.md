---
title: Transposition
documentation_of: //tools/transposed.hpp
---

```cpp
(1)
template <typename T, std::size_t N, std::size_t M>
std::array<std::array<T, N>, M> transposed(std::array<std::array<T, M>, N> A);

(2)
template <typename T>
std::vector<std::vector<T>> transposed(std::vector<std::vector<T>> A);

(3)
std::vector<std::string> transposed(std::vector<std::string> A);
```

Given a $N \times M$ matrix $A$, it returns a $M \times N$ matrix $A^\mathsf{T}$.

### Constraints
- (2), (3)
    - The following conditions hold where $N$ is `A.size()` and $M$ is `A[0].size()`.
        - $N \geq 1$
        - $M \geq 1$
        - For all $r$ such that $1 \leq r < N$, `A[r].size()` equals $M$.

### Time Complexity
- $O(NM)$

### License
- CC0

### Author
- anqooqie
