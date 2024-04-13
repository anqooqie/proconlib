---
title: $x^2$ under a given monoid
documentation_of: //tools/square.hpp
---

```cpp
(1)
template <typename M>
typename M::T square(typename M::T x);

(2)
template <typename T>
T square(T x);
```

It returns $x^2$ under a given monoid.
The default monoid is $(\mathbb{Z}, \times)$.

### Constraints
- (1)
    - None
- (2)
    - `x * x` is defined.

### Time Complexity
- (1)
    - Same as that of `M::op(x, x)`
- (2)
    - Same as that of `x * x`

### License
- CC0

### Author
- anqooqie
