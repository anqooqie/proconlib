---
title: Manacher
documentation_of: //tools/manacher.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void manacher(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $((l_0, r_0), (l_1, r_1), \ldots, (l_{2N}, r_{2N}))$ to `result` where the output sequence represents the following facts.

Let $a[l, r)$ denote the continuous subsequence of $a$ created using $a_i$ such that $l \leq i < r$.
The longest palindrome centered on $a_i$ is $a[l_{2i + 1}, r_{2i + 1})$.
The longest palindrome centered on the $i$-th one of the $N + 1$ boundaries between the elements is $a[l_{2i}, r_{2i})$. (Note that $i$ is $0$-indexed.)

### Constraints
- An integer can be read from `<InputIterator>`.
- A pair of two integers can be written to `<OutputIterator>`.

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
