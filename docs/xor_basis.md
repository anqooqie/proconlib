---
title: Basis of xor
documentation_of: //tools/xor_basis.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void xor_basis(InputIterator begin, InputIterator end, OutputIterator result);
```

It stores the basis of $\[\mathrm{begin}, \mathrm{end})$ to `result`.

### Constraints
- None

### Time Complexity
- $O(N^2)$ where $N$ is `end` - `begin`

### References
- [@noshi91 - Twitter](https://twitter.com/noshi91/status/1200702280128856064)

### License
- Unknown

### Author
- noshi91
