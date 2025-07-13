---
title: Sort multiple arrays at once
documentation_of: //tools/multisort.hpp
---

```cpp
(1)
template <std::ranges::random_access_range R1, std::ranges::random_access_range R2, typename Comp>
requires std::sortable<std::vector<int>::iterator, Comp>
void multisort(R1&& a, R2&& b, Comp comp);

(2)
template <std::ranges::random_access_range R1, std::ranges::random_access_range R2, std::ranges::random_access_range R3, typename Comp>
requires std::sortable<std::vector<int>::iterator, Comp>
void multisort(R1&& a, R2&& b, R3&& c, Comp comp);

(3)
template <std::ranges::random_access_range R1, std::ranges::random_access_range R2, std::ranges::random_access_range R3, std::ranges::random_access_range R4, typename Comp>
requires std::sortable<std::vector<int>::iterator, Comp>
void multisort(R1&& a, R2&& b, R3&& c, R4&& d, Comp comp);

(4)
template <std::ranges::random_access_range R1, std::ranges::random_access_range R2, std::ranges::random_access_range R3, std::ranges::random_access_range R4, std::ranges::random_access_range R5, typename Comp>
requires std::sortable<std::vector<int>::iterator, Comp>
void multisort(R1&& a, R2&& b, R3&& c, R4&& d, R5&& e, Comp comp);
```

It sorts multiple arrays at once by the same criteria.
Strictly speaking, it calculates $p$, the permutation of $(0, 1, \ldots, n - 1)$ such that $p_0 \leq p_1 \leq \cdots \leq p_{n - 1}$ where $x \leq y$ is defined by `!comp(y, x)`, and runs the following operations at once.

$$\begin{align*}
\left\{\begin{array}{ll}
a_0 & \leftarrow a_{p_0}\\
a_1 & \leftarrow a_{p_1}\\
\vdots &\\
a_{n - 1} & \leftarrow a_{p_{n - 1}}\\
b_0 & \leftarrow b_{p_0}\\
b_1 & \leftarrow b_{p_1}\\
\vdots &\\
b_{n - 1} & \leftarrow b_{p_{n - 1}}\\
\vdots &
\end{array}\right.&
\end{align*}$$

### Constraints
- (1)
    - $\|a\| = \|b\|$
- (2)
    - $\|a\| = \|b\| = \|c\|$
- (3)
    - $\|a\| = \|b\| = \|c\| = \|d\|$
- (4)
    - $\|a\| = \|b\| = \|c\| = \|d\| = \|e\|$

### Time Complexity
- $O(n \log n)$

### License
- CC0

### Author
- anqooqie
