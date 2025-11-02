---
title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
documentation_of: //tools/pow.hpp
---

## (1)
```cpp
template <typename M, typename E>
typename M::T pow(typename M::T b, E n);

template <typename T, typename E>
T pow(T b, E n);
```

It returns $b^n$ under a given monoid $M$.
If $M$ is not given, `tools::monoids::multiplies<T>` will be used.

### Constraints
- `std::is_integral_v<E>` is `true`.
- $n \geq 0$

### Time Complexity
- $O(\log n)$ if `M::op(b, b)` takes $O(1)$ time

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename T, typename E>
T pow(T b, E n);
```

If `std::pow(b, n)` is available, it returns `std::pow(b, n)`.

`tools::pow(b, n)` will be extended by other header files in my library.
For example, `tools::pow(tools::quaternion<T>, T)` gets available if you include `tools/quaternion.hpp`.

### Constraints
- `std::is_integral_v<E>` is `false`.
- See the standard or the explanation of the corresponding header file.

### Time Complexity
- See the standard or the explanation of the corresponding header file.

### License
- CC0

### Author
- anqooqie
