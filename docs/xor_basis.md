---
title: Basis of xor
documentation_of: //tools/xor_basis.hpp
---

```cpp
template <std::ranges::input_range R>
requires tools::integral<std::ranges::range_value_t<R>>
std::vector<std::ranges::range_value_t<R>> xor_basis(R&& a);
```

Given a sequence $a$ of non-negative integers, it returns a basis $B$ of the vector space spanned by $a$ over $\mathrm{GF}(2)$.
The returned basis has the following properties.

- The elements of $B$ are linearly independent over $\mathrm{GF}(2)$.
- Every element of $a$ can be represented as the XOR of some subset of $B$.
- $\|B\|$ is the dimension of the vector space, i.e., the minimum number of elements needed to represent all elements of $a$ by XOR.

### Constraints
- For all $i$ such that $0 \leq i < \|a\|$, $a_i \geq 0$.

### Time Complexity
- $O(\|a\| \cdot \min(\|a\|, w))$ where $w$ is `std::numeric_limits<std::ranges::range_value_t<R>>::digits`

### References
- [@noshi91 - Twitter](https://twitter.com/noshi91/status/1200702280128856064)

### License
- Unknown

### Author
- noshi91
