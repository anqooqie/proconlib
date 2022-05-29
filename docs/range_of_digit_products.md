---
title: Range of digit products
documentation_of: //tools/range_of_digit_products.hpp
---

```cpp
template <typename T>
T range_of_digit_products(T n);
```

Let $f(x)$ be the product of the digits of $x$.
It returns $\\{y \in \mathbb{Z} \| \exists x \in \mathbb{Z}. (1 \leq x < 10^n \land f(x) = y) \\}$.

## Constraints
- $0 \leq n \leq$ `std::numeric_limits<T>::digits10`

## Time Complexity
- $O\left(n^5 \log n\right)$

## License
- CC0

## Author
- anqooqie
