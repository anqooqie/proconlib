---
title: $\left\lceil \log_2(x) \right\rceil$
documentation_of: //tools/ceil_log2.hpp
---

```cpp
std::int32_t ceil_log2(std::int32_t x);
std::uint32_t ceil_log2(std::uint32_t x);
std::int64_t ceil_log2(std::int64_t x);
std::uint64_t ceil_log2(std::uint64_t x);
```

It returns $\left\lceil \log_2(x) \right\rceil$.

## Constraints
- $x \geq 1$

## Time Complexity
- $O(\log\log x)$

## References
- [Stack Overflow](https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567)

## License
- CC BY-SA 3.0

## Author
- [dgobbi](https://stackoverflow.com/users/2154690/dgobbi)
