---
title: Typical groups
documentation_of: //tools/group.hpp
---

They are typical groups.

### License
- CC0

### Author
- anqooqie

## group::plus
```cpp
namespace group {
  template <typename G>
  struct plus {
    using T = G;
    static T op(const T& x, const T& y) {
      return x + y;
    }
    static T e() {
      return T(0);
    }
    static T inv(const T& x) {
      return -x;
    }
  };
}
```

It is a group $(G, +, 0)$.

### Constraints
- `decltype(std::declval<G>() + std::declval<G>())` is `G`.
- For all $x$ in $G$, $y$ in $G$ and $z$ in $G$, $(x + y) + z = x + (y + z)$.
- For all $x$ in $G$, `G(0)` $+ x = x +$ `G(0)` $= x$.
- For all $x$ in $G$, $(-x) + x = x + (-x) =$ `G(0)`.

### Time Complexity
- Not applicable

## group::multiplies
```cpp
namespace group {
  template <typename G>
  struct multiplies {
    using T = G;
    static T op(const T& x, const T& y) {
      return x * y;
    }
    static T e() {
      return T(1);
    }
    static T inv(const T& x) {
      return e() / x;
    }
  };
}
```

It is a group $(G, \cdot, 1)$.

### Constraints
- `decltype(std::declval<G>() * std::declval<G>())` is `G`.
- For all $x$ in $G$, $y$ in $G$ and $z$ in $G$, $(x \cdot y) \cdot z = x \cdot (y \cdot z)$.
- For all $x$ in $G$, `G(1)` $\cdot x = x \cdot$ `G(1)` $= x$.
- For all $x$ in $G$, $x^{-1} \cdot x = x \cdot x^{-1} =$ `G(1)` where $x^{-1}$ is `G(1) / x`.

### Time Complexity
- Not applicable

## group::bit_xor
```cpp
namespace group {
  template <typename G>
  struct bit_xor {
    using T = G;
    static T op(const T& x, const T& y) {
      return x ^ y;
    }
    static T e() {
      return T(0);
    }
    static T inv(const T& x) {
      return x;
    }
  };
}
```

It is a group $(G, \oplus, 0)$.

### Constraints
- $G$ is any of integral types.

### Time Complexity
- Not applicable
