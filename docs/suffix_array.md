---
title: Wrapper of atcoder::suffix_array and atcoder::lcp_array
documentation_of: //tools/suffix_array.hpp
---

It is a wrapper of `atcoder::suffix_array` and `atcoder::lcp_array` with additional useful features.

It takes $n$ strings $s_0, s_1, \cdots, s_{n - 1}$.
We denote the substring of $s_i$ between $a$-th and $b - 1$-th character by `s[i][a..b)`.
Also, we denote $\|s_i\|$ by `|s[i]|` and $\sum_{i = 0}^{n - 1} \|s_i\|$ by $S$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
template <typename InputIterator>
suffix_array wrapper(InputIterator begin, InputIterator end);

(2)
template <typename Container>
suffix_array wrapper(std::initializer_list<Container> il);
```

- (1)
    - It takes $n$ strings and creates `wrapper.sa` and `wrapper.lcpa`.
- (2)
    - It is identical to `suffix_array wrapper(il.begin(), il.end())`.

### Constraints
- (1)
    - `typename InputIterator::value_type` is either of `std::string`, `std::vector<int>`, `std::vector<unsigned int>`, `std::vector<long long>` or `std::vector<unsigned long long>`.
    - $S + n \leq 10^8$
- (2)
    - `Container` is either of `std::string`, `std::vector<int>`, `std::vector<unsigned int>`, `std::vector<long long>` or `std::vector<unsigned long long>`.
    - $S + n \leq 10^8$

### Time Complexity
- (1)
    - $O(S)$ (if `typename InputIterator::value_type` is `std::string`)
    - $O(S \log S)$ (otherwise)
- (2)
    - $O(S)$ (if `Container` is `std::string`)
    - $O(S \log S)$ (otherwise)

## sa
```cpp
std::vector<std::pair<int, int>> wrapper.sa;
```

It is the suffix array of the given strings $s_0, s_1, \cdots, s_{n - 1}$.
Here, the suffix array `sa` is a permutation of $(0, 0), \cdots, (0, \|s_0\| - 1), \cdots, (n - 1, 0), \cdots, (n - 1, \|s_{n - 1}\| - 1)$ such that `s[sa[i].first][sa[i].second .. |s[sa[i].first]|) <= s[sa[i + 1].first][sa[i + 1].second .. |s[sa[i + 1].first]|)` holds for all $i = 0, 1, \cdots, S - 2$.

## lcpa
```cpp
std::vector<int> wrapper.lcpa;
```

It is the LCP array of the given strings $s_0, s_1, \cdots, s_{n - 1}$.
Here, the LCP array is the array of length $\max(0, S - 1)$, such that $i$-th element is the length of the LCP (Longest Common Prefix) of `s[sa[i].first][sa[i].second .. |s[sa[i].first]|)` and `s[sa[i + 1].first][sa[i + 1].second .. |s[sa[i + 1].first]|)`.

## erase_if
```cpp
template <typename Predicate>
std::size_t wrapper.erase_if(Predicate cond);
```

It removes the $i$-th element of `sa` such that `cond(sa[i].first, sa[i].second)` holds, recalculate `lcpa`, and returns the number of removed elements of `sa`.

### Constraints
- `cond` takes two integer parameters and returns `bool`.

### Time Complexity
- $O(S)$
