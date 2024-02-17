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

## Constraints
- `<T>` is an integral type.
- If `<T>` is signed, `std::numeric_limits<T>::digits` is $7$, $15$, $31$ or $63$.
- If `<T>` is unsigned, `std::numeric_limits<T>::digits` is $1$, $8$, $16$, $32$ or $64$.
- $x \geq 0$

## Time Complexity
- $O(1)$

## References
- [C++11で実装するNTZとNLZ](https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6)

## License
- unknown

## Author
- 白山 風露
