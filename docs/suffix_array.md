---
title: Wrapper of atcoder::suffix_array and atcoder::lcp_array
documentation_of: //tools/suffix_array.hpp
---

It is a wrapper of `atcoder::suffix_array` and `atcoder::lcp_array` with additional useful features.

It takes $n$ strings $s_0, s_1, \cdots, s_{n - 1}$.
We denote the substring of $s_i$ starting from the $a$-th character to the end by `s[i][a..)`.
Also, we denote $\sum_{i = 0}^{n - 1} \|s_i\|$ by $S$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
template <std::ranges::input_range R>
requires std::ranges::input_range<std::ranges::range_value_t<R>>
      && (
        std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, char>
        || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, int>
        || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, unsigned int>
        || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, long long>
        || std::same_as<std::ranges::range_value_t<std::ranges::range_value_t<R>>, unsigned long long>
      )
suffix_array wrapper(R&& r);

(2)
template <std::ranges::input_range Container>
requires std::same_as<std::ranges::range_value_t<Container>, char>
      || std::same_as<std::ranges::range_value_t<Container>, int>
      || std::same_as<std::ranges::range_value_t<Container>, unsigned int>
      || std::same_as<std::ranges::range_value_t<Container>, long long>
      || std::same_as<std::ranges::range_value_t<Container>, unsigned long long>
suffix_array wrapper(std::initializer_list<Container> il);
```

- (1)
    - It takes $n$ strings and creates `wrapper.sa` and `wrapper.lcpa`.
- (2)
    - It is identical to `suffix_array wrapper(std::views::all(il))`.

### Constraints
- (1)
    - $S + n \leq 10^8$
- (2)
    - $S + n \leq 10^8$

### Time Complexity
- (1)
    - (`std::ranges::range_value_t<std::ranges::range_value_t<R>>` is `char`): $O(S)$
    - (Otherwise): $O(S \log S)$
- (2)
    - (`std::ranges::range_value_t<Container>` is `char`): $O(S)$
    - (Otherwise): $O(S \log S)$

## sa
```cpp
std::vector<std::pair<int, int>> wrapper.sa;
```

It is the suffix array of the given strings $s_0, s_1, \cdots, s_{n - 1}$.
Here, the suffix array `sa` is a permutation of $(0, 0), \cdots, (0, \|s_0\| - 1), \cdots, (n - 1, 0), \cdots, (n - 1, \|s_{n - 1}\| - 1)$ such that `s[sa[i].first][sa[i].second ..) <= s[sa[i + 1].first][sa[i + 1].second ..)` holds for all $i = 0, 1, \cdots, S - 2$.

## lcpa
```cpp
std::vector<int> wrapper.lcpa;
```

It is the LCP array of the given strings $s_0, s_1, \cdots, s_{n - 1}$.
Here, the LCP array is the array of length $\max(0, S - 1)$, such that $i$-th element is the length of the LCP (Longest Common Prefix) of `s[sa[i].first][sa[i].second ..)` and `s[sa[i + 1].first][sa[i + 1].second ..)`.

## erase_if
```cpp
int wrapper.erase_if(std::predicate<int, int> auto&& pred);
```

It removes the $i$-th element of `sa` such that `std::invoke(pred, sa[i].first, sa[i].second)` holds, recalculate `lcpa`, and returns the number of removed elements of `sa`.

### Constraints
- None

### Time Complexity
- $O(S)$
