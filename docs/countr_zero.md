---
title: Number of trailing zeros
documentation_of: //tools/countr_zero.hpp
---

```cpp
template <typename T>
constexpr int countr_zero(T x) noexcept;
```

It returns the number of trailing zeros. (e.g., `countr_zero(0b10100)` is $2$)
If $x$ is $0$, it returns `std::numeric_limits<T>::digits`.

### Constraints
- `<T>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $x \geq 0$

### Time Complexity
- $O(1)$

### References
- [C++11で実装するNTZとNLZ](https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6)

### License
- CC0

### Author
- anqooqie
