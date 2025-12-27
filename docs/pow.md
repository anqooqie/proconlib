---
title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
documentation_of: //tools/pow.hpp
---

## (1)
```cpp
template <tools::group G>
typename G::T pow(typename G::T b, tools::integral auto n);
```

It returns $b^n$ under a given group $G$.

### Constraints
- None

### Time Complexity
- $O(\log \|n\|)$ if it takes $O(1)$ time to compute `G::op(b, b)`

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <tools::monoid M>
requires (!tools::group<M>)
typename M::T pow(typename M::T b, tools::integral auto n);
```

It returns $b^n$ under a given monoid $M$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(\log n)$ if it takes $O(1)$ time to compute `M::op(b, b)`

### License
- CC0

### Author
- anqooqie

## (3)
```cpp
auto pow(auto b, tools::integral auto n) -> decltype(b);
```

It returns `tools::pow<tools::multiplicative_structure<decltype(b)>>(b, n)`.

### Constraints
- If `tools::multiplicative_structure<decltype(b)>` is `tools::monoids::multiplies<decltype(b)>`, then $n \geq 0$.

### Time Complexity
- $O(\log \|n\|)$ if it takes $O(1)$ time to compute `b * b`

### License
- CC0

### Author
- anqooqie

## (4)
```cpp
auto pow(auto b, auto n) -> decltype(std::pow(b, n))
requires (!tools::integral<decltype(n)>);
```

If `std::pow(b, n)` is available, it returns `std::pow(b, n)`.

`tools::pow(b, n)` will be extended by other header files in my library.
For example, `tools::pow(tools::quaternion<T>, T)` gets available if you include `tools/quaternion.hpp`.

### Constraints
- See the standard or the documentation page for each arguments.

### Time Complexity
- See the standard or the documentation page for each arguments.

### License
- CC0

### Author
- anqooqie
