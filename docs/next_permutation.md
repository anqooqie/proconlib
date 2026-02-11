---
title: Next permutation as n-choose-r
documentation_of: //tools/next_permutation.hpp
---

```cpp
template <std::random_access_iterator Iterator>
bool next_permutation(Iterator first, Iterator k, Iterator last);
```

It generates the next permutation as n-choose-r.
It returns `true` if the next permutation exists, `false` otherwise.

### Usage
```cpp
// 9-choose-3
int k = 3;
do {
  std::cout << std::string(s.begin(), s.begin() + k) << std::endl;
} while (tools::next_permutation(s.begin(), s.begin() + k, s.end()));
```

### Constraints
- `first` $\leq$ `k` $\leq$ `last`

### Time Complexity
Let $n$ be `last - first` and $r$ be `k - first`.

- $O(n)$ per call
- $\displaystyle O\left(\frac{n \cdot n!}{(n - r)!}\right)$ to enumerate all permutations

### License
- CC0

### Author
- anqooqie
