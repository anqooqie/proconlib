---
title: Number of trailing zeros
documentation_of: //tools/countr_zero.hpp
---

```cpp
constexpr int countr_zero(auto&& x);
```

It returns the number of trailing zeros. (e.g., `countr_zero(0b10100)` is $2$)
If $x$ is $0$, it returns `std::numeric_limits<std::remove_cvref_t<decltype(x)>>::digits`.

### Constraints
- `tools::non_bool_integral<std::remove_cvref_t<decltype(x)>>` holds.
- $x \geq 0$

### Time Complexity
- $O(1)$

### References
- [C++11で実装するNTZとNLZ](https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6)

### License
- CC0

### Author
- anqooqie
