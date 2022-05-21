---
title: Rolling hash
documentation_of: //tools/rolling_hash.hpp
---

It calculates hash values for any subsequences of a given sequence.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
rolling_hash hash(InputIterator begin, InputIterator end);
```

It calculates hash values for any subsequences of a given sequence.

### Constraints
- None of the elements in a given sequence are $0$.

### Time Complexity
- $O(n)$ where $n$ is `end` $-$ `begin`

## slice
```cpp
tools::modint_for_rolling_hash hash.slice(std::size_t l, std::size_t r);
```

It returns $\sum_{i = l}^{r - 1} s_i b^{r - 1 - i} \pmod{2^{61} - 1}$ where $s_i$ is the $i$-th element of the given sequence and $b$ is the integer randomly determined immediately after startup of the program.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O(1)$
