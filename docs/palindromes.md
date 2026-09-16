---
title: Enumerate palindromes
documentation_of: //tools/palindromes.hpp
---

It enumerates the palindromes in a half-open interval in ascending order, where a palindrome is a non-negative integer whose decimal representation is equal to its reverse.
Note that $0$ is a palindrome.

There are $\Theta(\sqrt{b})$ palindromes less than $b$, which is about $2 \times 10^9$ for $b = 10^{18}$, so they are not materialized.
The returned view keeps nothing but the ranks of the first and the last palindrome, and builds each palindrome from its rank on demand.

### License
- CC0

### Author
- anqooqie

## palindromes
```cpp
template <tools::non_bool_integral M, tools::non_bool_integral N>
tools::palindrome_view<std::common_type_t<M, N>> palindromes(M a, N b);
```

It returns a view which enumerates the palindromes $x$ such that $a \leq x < b$ in ascending order.

The view is a random access range, a common range, a sized range and a borrowed range.
Since it is borrowed, an iterator obtained from a temporary view stays valid.

### Constraints
- $0 \leq a \leq b$

### Time Complexity
- $O(\log b)$

## begin, end
```cpp
tools::palindrome_view<T>::iterator r.begin();
tools::palindrome_view<T>::iterator r.end();
```

It returns the iterator pointing to the first palindrome in the interval, or the one past the last palindrome in the interval, respectively.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::conditional_t<(sizeof(T) <= 8), std::ptrdiff_t, tools::int128_t> r.size();
```

It returns the number of the palindromes in the interval.

The return type is the difference type of the iterator.
It is signed, and neither `int` nor `std::size_t` is wide enough for every `<T>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
T r.operator[](std::conditional_t<(sizeof(T) <= 8), std::ptrdiff_t, tools::int128_t> i);
```

It returns the $i$-th smallest palindrome in the interval, where $i$ is $0$-indexed.

### Constraints
- $0 \leq i < $ `r.size()`

### Time Complexity
- $O(\log b)$

## Iterator operations
```cpp
T it.operator*(); // and the other operations of a random access iterator
```

The iterator is a random access iterator whose difference type is `std::conditional_t<(sizeof(T) <= 8), std::ptrdiff_t, tools::int128_t>`.
It never refers to the view it came from, so iterators obtained from different views of the same `<T>` are comparable, and they compare equal if and only if they point to the same palindrome.

Dereferencing it builds a palindrome from a rank, which takes $O(\log b)$ time.
The remaining operations, including advancing the iterator and taking the distance between two iterators, take $O(1)$ time.

### Constraints
- None

### Time Complexity
- $O(\log b)$ for `*it` and `it[n]`
- $O(1)$ for the others
