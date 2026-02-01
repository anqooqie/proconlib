---
title: Stern–Brocot tree
documentation_of: //tools/stern_brocot_tree.hpp
---

It is the Stern–Brocot tree.

### License
- CC0

### Author
- anqooqie

## Class declaration
```cpp
template <tools::non_bool_integral T>
requires tools::non_bool_integral<tools::make_wider_t<tools::make_unsigned_t<T>>>
class stern_brocot_tree;
```

It is the Stern–Brocot tree (SBT) capable of handling queries for irreducible fractions $\displaystyle \frac{p}{q}$, where $p$ and $q$ are positive integers expressible in `T`.
All member functions are static, and there is no constructor.

### Constraints
- None

### Time Complexity
- Not applicable

## encode_path
```cpp
std::vector<std::pair<char, T>> stern_brocot_tree<T>::encode_path(T p, T q);
```

Let $P$ be the path from $\displaystyle \frac{1}{1}$ to $\displaystyle \frac{p}{q}$ in SBT as a string, using `L` for leftward move and `R` for rightward move.
It returns run-length encoded $P$ in the format $((c_0, n_0), (c_1, n_1), \ldots, (c_{k - 1}, n_{k - 1}))$ where $c_i$ is `L` or `R`, and $n_i$ is a positive integer representing the number of consecutive $c_i$s.

### Constraints
- $p > 0$
- $q > 0$
- $\gcd(p, q) = 1$

### Time Complexity
- $O(\log(\max(p, q)))$

## decode_path
```cpp
template <std::ranges::input_range R>
requires std::same_as<std::remove_cvref_t<std::tuple_element_t<0, std::ranges::range_value_t<R>>>, char>
      && tools::non_bool_integral<std::tuple_element_t<1, std::ranges::range_value_t<R>>>
std::pair<T, T> stern_brocot_tree<T>::decode_path(R&& path);
```

Given the path from $\displaystyle \frac{1}{1}$ to $\displaystyle \frac{p}{q}$ in the format of `encode_path`, it returns $(p, q)$.

### Constraints
- $c_i$ is `L` or `R`
- $n_i > 0$
- $p$ is expressible in `T`.
- $q$ is expressible in `T`.

### Time Complexity
- $O(\|\mathrm{path}\|)$

## lca
```cpp
std::pair<T, T> stern_brocot_tree<T>::lca(T p, T q, T r, T s);
```

It returns $(f, g)$ such that $\displaystyle \frac{f}{g}$ is the LCA of $\displaystyle \frac{p}{q}$ and $\displaystyle \frac{r}{s}$ in SBT.

### Constraints
- $p > 0$
- $q > 0$
- $\gcd(p, q) = 1$
- $r > 0$
- $s > 0$
- $\gcd(r, s) = 1$

### Time Complexity
- $O(\log(\max(p, q)) + \log(\max(r, s)))$

## ancestor
```cpp
std::optional<std::pair<T, T>> stern_brocot_tree<T>::ancestor(T d, T p, T q);
```

It returns $(f, g)$ such that $\displaystyle \frac{f}{g}$ is the ancestor of $\displaystyle \frac{p}{q}$ with depth $d$ in SBT.
If such the irreducible fraction does not exist, it returns `std::nullopt`.

### Constraints
- $d \geq 0$
- $p > 0$
- $q > 0$
- $\gcd(p, q) = 1$

### Time Complexity
- $O(\log(\max(p, q)))$

## range
```cpp
std::tuple<T, T, T, T> stern_brocot_tree<T>::range(T p, T q);
```

The set of descendants of $\displaystyle \frac{p}{q}$ forms an open interval of rational numbers.
It returns $(f, g, h, k)$ such that $\displaystyle \frac{f}{g}$ is the infimum of the interval and $\displaystyle \frac{h}{k}$ is the supremum of the interval.
As an exception, when the infimum is $0$, $(f, g)$ becomes $(0, 1)$, and when the supremum is $\infty$, $(h, k)$ becomes $(1, 0)$.

### Constraints
- $p > 0$
- $q > 0$
- $\gcd(p, q) = 1$

### Time Complexity
- $O(\log(\max(p, q)))$
