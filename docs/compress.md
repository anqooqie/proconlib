---
title: Compress values
documentation_of: //tools/compress.hpp
---

```cpp
(1)
template <std::ranges::range R, std::output_iterator<int> O>
void compress(R&& a, O result);

(2)
template <std::input_iterator I, std::sentinel_for<I> S, std::output_iterator<int> O>
void compress(I begin, S end, O result);

(3)
template <std::ranges::random_access_range R>
requires std::indirectly_writable<std::ranges::iterator_t<R>, int>
void compress(R&& a);

(4)
template <std::random_access_iterator I, std::sentinel_for<I> S>
requires std::indirectly_writable<I, int>
void compress(I begin, S end);
```

- (1)
    - Given a sequence $(a_0, a_1, \ldots, a_{n - 1})$, it stores the integer sequence $(b_0, b_1, \ldots, b_{n - 1})$ to `result` where $b_i$ is the number of distinct elements in $a$ less than $a_i$.
- (2)
    - It is equivalent to `compress(std::ranges::subrange(begin, end), result)`.
- (3)
    - It is equivalent to `compress(a, std::ranges::begin(a))`.
- (4)
    - It is equivalent to `compress(std::ranges::subrange(begin, end), begin)`.

### Constraints
- For any integer pairs $(l, r)$ such that $0 \leq l < r < n$, $a_i < a_j$ is defined.

### Time Complexity
- $O(n \log n)$

### License
- CC0

### Author
- anqooqie
