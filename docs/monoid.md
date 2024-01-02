---
title: Typical monoids
documentation_of: //tools/monoid.hpp
---

They are typical monoids.

### License
- CC0

### Author
- anqooqie

## monoid::max
```cpp
namespace monoid {
  template <typename M, M E = std::numeric_limits<M>::lowest()>
  struct max {
    using T = M;
    static T op(const T& x, const T& y) {
      return std::max(x, y);
    }
    static T e() {
      return E;
    }
  };
}
```

It is a monoid $(M, \max, E)$.
If $E$ is not specified, then $E$ is `std::numeric_limits<M>::lowest()`.

### Constraints
- $M$ is comparable.
- If $E$ is not specified, $M$ is any of floating-point or integral types.
- For all $x$ in $M$, $y$ in $M$ and $z$ in $M$, $\max(\max(x, y), z) = \max(x, \max(y, z))$.
- For all $x$ in $M$, $\max(E, x) = \max(x, E) = x$.

### Time Complexity
- Not applicable

## monoid::min
```cpp
namespace monoid {
  template <typename M, M E = std::numeric_limits<M>::max()>
  struct min {
    using T = M;
    static T op(const T& x, const T& y) {
      return std::min(x, y);
    }
    static T e() {
      return E;
    }
  };
}
```

It is a monoid $(M, \min, E)$.
If $E$ is not specified, then $E$ is `std::numeric_limits<M>::max()`.

### Constraints
- $M$ is comparable.
- If $E$ is not specified, $M$ is any of floating-point or integral types.
- For all $x$ in $M$, $y$ in $M$ and $z$ in $M$, $\min(\min(x, y), z) = \min(x, \min(y, z))$.
- For all $x$ in $M$, $\min(E, x) = \min(x, E) = x$.

### Time Complexity
- Not applicable

## monoid::multiplies
```cpp
namespace monoid {
  template <typename M>
  struct multiplies {
    using T = M;
    static T op(const T& x, const T& y) {
      return x * y;
    }
    static T e() {
      return T(1);
    }
  };
}
```

It is a monoid $(M, \cdot, 1)$.

### Constraints
- `decltype(std::declval<M>() * std::declval<M>())` is `M`.
- For all $x$ in $M$, $y$ in $M$ and $z$ in $M$, $(x \cdot y) \cdot z = x \cdot (y \cdot z)$.
- For all $x$ in $M$, `M(1)` $\cdot x = x \cdot$ `M(1)` $= x$.

### Time Complexity
- Not applicable

## monoid::gcd
```cpp
namespace monoid {
  template <typename M>
  struct gcd {
    using T = M;
    static T op(const T& x, const T& y) {
      return std::gcd(x, y);
    }
    static T e() {
      return T(0);
    }
  };
}
```

It is a monoid $(M, \gcd, 0)$.

### Constraints
- $M$ is any of integral types.

### Time Complexity
- Not applicable

## monoid::update
```cpp
namespace monoid {
  template <typename M, M E>
  struct update {
    using T = M;
    static T op(const T& x, const T& y) {
      return x == E ? y : x;
    }
    static T e() {
      return E;
    }
  };
}
```

It is a monoid $(M, U, E)$ where

$$\begin{align*}
U(x, y) &= \left\{\begin{array}{ll}
y & \text{(if $x = E$)}\\
x & \text{(if $x \neq E$)}
\end{array}\right.
\end{align*}$$

### Constraints
- None

### Time Complexity
- Not applicable
