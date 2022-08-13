---
title: Enumerate all matchings
documentation_of: //tools/next_matching.hpp
---

```cpp
template <typename RandomAccessIterator>
bool next_matching(RandomAccessIterator begin, RandomAccessIterator end);
```

It enumerates all the ways to divide $\\{0, 1, \ldots, N - 1\\}$ into $\left\lfloor \frac{N}{2} \right\rfloor$ unordered pairs and at most one remainder.
It can be used as follows.

```cpp
std::vector<int> a(N);
std::iota(a.begin(), a.end(), 0);
do {
  // a[0] and a[1] are a pair, a[2] and a[3] are a pair, and so on.
} while (tools::next_matching(a.begin(), a.end()));
```

It returns `true` if the next way exists, `false` otherwise.

## Constraints
- The given sequence is a permutation of $(0, 1, \ldots, N - 1)$.

## Time Complexity
- $O(N \log N)$ worst
- $O(1)$ amortized
- Note: Since the number of ways is $\left(2 \left\lfloor \frac{N - 1}{2} \right\rfloor + 1\right)!!$, it takes $O\left(\left(2 \left\lfloor \frac{N - 1}{2} \right\rfloor + 1\right)!!\right)$ time totally if you enumerate all the ways.

## License
- CC0

## Author
- anqooqie
