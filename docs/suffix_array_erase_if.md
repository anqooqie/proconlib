---
title: std::erase_if for suffix array and LCP array
documentation_of: //tools/suffix_array_erase_if.hpp
---

```cpp
template <typename RandomAccessIterator, typename Predicate>
std::pair<RandomAccessIterator, RandomAccessIterator> suffix_array_erase_if(RandomAccessIterator sa, RandomAccessIterator sa_end, RandomAccessIterator lcpa, RandomAccessIterator lcpa_end, Predicate pred);
```

Let us denote the first element of the returned pair by `sa_new_end`, and the second element by `lcpa_new_end`.
Also, let us denote `sa_end - sa` by $N$, and `sa_new_end - sa` by $N'$.

It executes `std::erase_if(sa, sa_end, pred)` and returns the return value of it as `sa_new_end`.
Also, it updates `lcpa[i]` to the length of the longest common prefix between `s[sa[i] .. N)` and `s[sa[i + 1] .. N)` for all $0 \leq i < \max(0, N' - 1)$, and returns `lcpa +` $\max(0, N' - 1)$ as `lcpa_new_end`, where $s$ is the source sequence of `sa`.

### Constraints
- $N \geq 1$
- `lcpa_end - lcpa_begin` $= N - 1$

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
