---
title: $\left\lceil \log_2(x) \right\rceil$
documentation_of: //tools/ceil_log2.hpp
---

```cpp
template <typename T>
T ceil_log2(T x);
```

It returns $\left\lceil \log_2(x) \right\rceil$.

## Constraints
- $x > 0$
- `std::numeric_limits<T>::digits` is $8$, $16$, $32$ or $64$.

## Time Complexity
- $O(\log\log x)$

## References
- [Stack Overflow](https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567)

## License
- CC BY-SA 3.0

## Author
- [dgobbi](https://stackoverflow.com/users/2154690/dgobbi)
