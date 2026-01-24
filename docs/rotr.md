---
title: Circular shift to the right / Rotate a given matrix 90 degrees to the right
documentation_of: //tools/rotr.hpp
---

## (1)
```cpp
template <tools::non_bool_integral T, tools::non_bool_integral S>
T rotr(T x, S s);
```

It returns `tools::rotr(x, std::numeric_limits<T>::digits, s)`.
Note that circular shift is performed excluding the sign bit.

### Constraints
- $x \geq 0$

### Time Complexity
- $O(1)$

### License
- CC0

## (2)
```cpp
template <tools::non_bool_integral T, tools::non_bool_integral S>
T rotr(T x, int n, S s);
```

It returns the following value where $y$ is `static_cast<tools::make_unsigned_t<T>>(x)`, `mask` is $2^n - 1$ and $r$ is `tools::mod(s, n)`.

- ($n = 0$): `x`
- ($n > 0$ and $r = 0$): `x`
- ($n > 0$ and $r > 0$): `((y << (n - r)) & mask) | (y >> r)`

### Constraints
- $0 \leq n \leq$ `std::numeric_limits<T>::digits`
- $0 \leq x < 2^n$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie

## (3)
```cpp
template <typename T, tools::non_bool_integral S>
requires requires(T x, T y, int s) {
  { x.size() } -> std::convertible_to<int>;
  { x << s } -> std::same_as<T>;
  { x >> s } -> std::same_as<T>;
  { x | y } -> std::same_as<T>;
}
T rotr(T x, S s);
```

It returns the following value where $n$ is `x.size()` and $r$ is `tools::mod(s, n)`.

- ($n = 0$): `x`
- ($n > 0$ and $r = 0$): `x`
- ($n > 0$ and $r > 0$): `(x << (n - r)) | (x >> r)`

### Constraints
- None

### Time Complexity
- $O(n)$

### License
- CC0

### Author
- anqooqie

## (4)
```cpp
template <typename T, std::size_t N, std::size_t M>
std::array<std::array<T, N>, M> rotr(std::array<std::array<T, M>, N> A);
```

It returns the matrix obtained by rotating $A$, $90$ degrees to the right.

### Example
```cpp
std::array<std::array<int, 3>, 2> A = {
  {1, 2, 3},
  {4, 5, 6},
};
std::array<std::array<int, 2>, 3> B = {
  {4, 1},
  {5, 2},
  {6, 3},
};
assert(tools::rotr(A) == B);
```

### Constraints
- None

### Time Complexity
- $O(NM)$

### License
- CC0

### Author
- anqooqie

## (5)
```cpp
template <typename T>
std::vector<std::vector<T>> rotr(std::vector<std::vector<T>> A);
```

It returns the matrix obtained by rotating $A$, $90$ degrees to the right.

### Constraints
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

## (6)
```cpp
std::vector<std::string> rotr(std::vector<std::string> A);
```

It returns the matrix obtained by rotating $A$, $90$ degrees to the right.

### Constraints
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
