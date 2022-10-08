---
title: Number of trailing zeros
documentation_of: //tools/ntz.hpp
---

```cpp
template <typename T>
T ntz(T x);
```

It returns the number of trailing zeros. (e.g., ntz(0b10100) = 2)

## Constraints
- $x > 0$
- `std::numeric_limits<T>::digits` is $8$, $16$, $32$ or $64$.

## Time Complexity
- $O(\log\log x)$

## License
- CC0

## Author
- anqooqie
