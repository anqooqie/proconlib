---
title: Longest increasing subsequence
documentation_of: //tools/lis.hpp
---

## (1)
```cpp
int lis::segtree<true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::segtree<true, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<true, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the length of the longest increasing subsequence.
The relationship $a_i < a_j$ is defined by $\mathrm{comp}(a_i, a_j)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
In the `segtree` function, it speeds up the DP of $O(N^2)$ time, which maximizes the length of the increasing subsequence when the last element of the increasing subsequence is $a_i$, to $O(N \log N)$ time using a segment tree.
In the `bisect` function, it sppeds up the DP of $O(N^2)$ time, which minimizes the last element of the increasing subsequence when the length of the increasing subsequence is $l$, to $O(N \log N)$ time using binary search.

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
int lis::segtree<false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::segtree<false, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<false, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the length of the longest non-decreasing subsequence.
The relationship $a_i \leq a_j$ is defined by $\lnot \mathrm{comp}(a_j, a_i)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
See (1).

### License
- CC0

### Author
- anqooqie

## (3)
```cpp
std::vector<int> lis::segtree<true, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
std::vector<int> lis::bisect<true, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the indices of the longest increasing subsequence.
Since there can be multiple longest increasing subsequences, the one with the smallest index sequence in lexicographic order is returned.

Formally speaking, it returns the smallest integer sequence $(i_0, i_1, \ldots, i_{k - 1})$ in lexicographic order that satisfy the following conditions:

$$\begin{align*}
i_0 < i_1 < \cdots < l_{k - 1}\\
a_{i_0} < a_{i_1} < \cdots < a_{i_{k - 1}}
\end{align*}$$

where $k$ is the length of the longest increasing subsequence, and the relationship $a_i < a_j$ is defined by $\mathrm{comp}(a_i, a_j)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
See (1).

### License
- CC0

### Author
- anqooqie

## (4)
```cpp
std::vector<int> lis::segtree<false, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
std::vector<int> lis::bisect<false, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the indices of the longest non-decreasing subsequence.
Since there can be multiple longest non-decreasing subsequences, the one with the smallest index sequence in lexicographic order is returned.

Formally speaking, it returns the smallest integer sequence $(i_0, i_1, \ldots, i_{k - 1})$ in lexicographic order that satisfy the following conditions:

$$\begin{align*}
i_0 < i_1 < \cdots < l_{k - 1}\\
a_{i_0} \leq a_{i_1} \leq \cdots \leq a_{i_{k - 1}}
\end{align*}$$

where $k$ is the length of the longest non-decreasing subsequence, and the relationship $a_i \leq a_j$ is defined by $\lnot \mathrm{comp}(a_j, a_i)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
See (1).

### License
- CC0

### Author
- anqooqie
