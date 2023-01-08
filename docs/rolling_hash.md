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

## pow_base
```cpp
tools::modint_for_rolling_hash hash.pow_base(std::size_t i);
```

It returns $b^{i} \pmod{2^{61} - 1}$ where $b$ is the integer randomly determined immediately after startup of the program.

### Constraints
- None

### Time Complexity
- (first call): $O(i)$
- (second call or later): $O(i - i^\ast)$ where $i^\ast$ is the largest $i$ in the `pow_base` calls so far

## slice
```cpp
tools::modint_for_rolling_hash hash.slice(std::size_t l, std::size_t r);
```

It returns $\sum_{i = l}^{r - 1} s_i b^{r - 1 - i} \pmod{2^{61} - 1}$ where $s_i$ is the $i$-th element of the given sequence.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O(1)$
