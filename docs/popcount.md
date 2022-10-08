---
title: Popcount
documentation_of: //tools/popcount.hpp
---

```cpp
template <typename T>
T popcount(T x);
```

It returns the number of 1 bits in the value of $x$.

## Constraints
- $x \geq 0$
- `std::numeric_limits<T>::digits` is $8$, $16$, $32$ or $64$.

## Time Complexity
- $O(\log\log x)$

## References
- Henry S. Warren Jr. (2013). "Hacker's Delight (2nd edition)"

## License
- CC0

## Author
- anqooqie
