---
title: Extended Euclidean algorithm
documentation_of: //tools/extgcd.hpp
---

```cpp
template <typename T>
std::tuple<T, T, T> extgcd(T a, T b);
```

It returns $(x_0, y_0, \gcd(a, b))$ which satisfies $a \cdot x_0 + b \cdot y_0 = \gcd(a, b)$.
In this function, we define $\gcd(a, 0) = a$, $\gcd(0, b) = b$ and $\gcd(0, 0) = 0$.

## Constraints
- None

## Time Complexity
- $O(\log(\min(\|a\|, \|b\|)))$

## License
- CC0

## Author
- anqooqie
