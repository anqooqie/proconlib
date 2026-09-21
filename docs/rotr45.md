---
title: Rotate a given matrix 45 degrees to the right
documentation_of: //tools/rotr45.hpp
---

It rotates a given $N \times M$ matrix $A$, $45$ degrees to the right, and returns the resulting $(N + M - 1) \times (N + M - 1)$ matrix $B$.
Precisely, $B[i + j][j - i + N - 1] = A[i][j]$ holds for all $0 \leq i < N$ and $0 \leq j < M$, and the other cells of $B$ are filled with `default_value`.
The cells of $B$ which are not filled with `default_value` are exactly the ones whose indices sum to $N - 1$ modulo $2$.

Since a $45$ degree rotation does not map the integer lattice to itself, $B$ is the image of $A$ under the rotation scaled by $\sqrt{2}$, that is, the map $(i, j) \mapsto (i + j, j - i)$ up to translation.
As a result, applying it twice is not the same as `tools::rotr`.

### Example
```
A =  1 2 3            tools::rotr45(A, 0) =  0 1 0 0
     4 5 6                                   4 0 2 0
                                             0 5 0 3
                                             0 0 6 0
```

### License
- CC0

### Author
- anqooqie

## (1)
```cpp
template <typename T, std::size_t N, std::size_t M>
std::array<std::array<T, N + M - 1>, N + M - 1> rotr45(const std::array<std::array<T, M>, N>& A, std::type_identity_t<T> default_value);
```

### Constraints
- None

### Time Complexity
- $O((N + M)^2)$

## (2)
```cpp
template <typename T>
std::vector<std::vector<T>> rotr45(const std::vector<std::vector<T>>& A, std::type_identity_t<T> default_value);
```

### Constraints
- The following conditions hold where $N$ is `A.size()` and $M$ is `A[0].size()`.
    - $N \geq 1$
    - $M \geq 1$
    - For all $i$ such that $1 \leq i < N$, `A[i].size()` equals $M$.

### Time Complexity
- $O((N + M)^2)$

## (3)
```cpp
std::vector<std::string> rotr45(const std::vector<std::string>& A, char default_value);
```

### Constraints
- The following conditions hold where $N$ is `A.size()` and $M$ is `A[0].size()`.
    - $N \geq 1$
    - $M \geq 1$
    - For all $i$ such that $1 \leq i < N$, `A[i].size()` equals $M$.

### Time Complexity
- $O((N + M)^2)$
