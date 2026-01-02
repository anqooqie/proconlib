---
title: $\mathrm{ord}(x)$ for $x \in (\mathbb{Z}/p\mathbb{Z})^\times$
documentation_of: //tools/ord_mod.hpp
---

For a fixed prime $p$, it returns the minimum positive integer $k$ such that $x^k \equiv 1 \pmod{p}$ in $\left\langle O\left(p^\frac{1}{4}\right), O\left((\log p)(\log \log p)\right) \right\rangle$ time.

### References
- [解説 - AtCoder Beginner Contest 335（Sponsored by Mynavi）](https://atcoder.jp/contests/abc335/editorial/9045)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <std::integral T>
ord_mod<T> ord(T p);
```

It constructs a data structure that allows $\mathrm{ord}(x)$ to be returned in $O((\log p)(\log \log p))$ time.

### Constraints
- $p$ is a prime.

### Time Complexity
- Supposed to be $O\left(p^\frac{1}{4}\right)$ expected

## query
```cpp
T ord.query(T x);
```

It returns $\mathrm{ord}(x)$, the minimum positive integer $k$ such that $x^k \equiv 1 \pmod{p}$.

### Constraints
- $1 \leq x < p$

### Time Complexity
- $O((\log p)(\log \log p))$

## count
```cpp
std::map<T, T> ord.count();
```

It returns pairs of two integers $(k, v)$ such that

$$\begin{align*}
\left\{\begin{array}{l}
v = |\{x \in \mathbb{N} \mid 1 \leq x < p \land \mathrm{ord}(x) = k\}|\\
v > 0
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O\left(2^\frac{\log p}{\log \log p} \frac{\log p}{\log \log p}\right)$
