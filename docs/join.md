---
title: Join elements with delimiter
documentation_of: //tools/join.hpp
---

## (1)
```cpp
template <typename Iterator>
std::string join(Iterator begin, Iterator end, std::string d);
```

Given $n$ elements $e_0, e_1, \cdots, e_{n - 1}$, it returns $e_0 + d + e_1 + d + \cdots + d + e_{n - 1}$ where $+$ is string concatenation.
Note that it returns an empty string if $n = 0$.

### Constraints
- `operator<<` for `std::ostream` and `typename std::iterator_traits<Iterator>::value_type` is defined.

### Time Complexity
- $\sum_{i = 0}^{n - 1} \|e_i\| + n \|d\|$

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename Iterator, typename F>
std::string join(Iterator begin, Iterator end, F f, std::string d);
```

Given $n$ elements $e_0, e_1, \cdots, e_{n - 1}$, it returns $f(e_0) + d + f(e_1) + d + \cdots + d + f(e_{n - 1})$ where $+$ is string concatenation.
Note that it returns an empty string if $n = 0$.

### Constraints
- `operator<<` for `std::ostream` and `decltype(f(std::declval<typename std::iterator_traits<Iterator>::value_type>()))` is defined.

### Time Complexity
- $\sum_{i = 0}^{n - 1} t(e_i) + n \|d\|$ where it takes $t(x)$ time to get $f(x)$

### License
- CC0

### Author
- anqooqie
