---
title: Rational binary search
documentation_of: //tools/rational_binary_search.hpp
---

```cpp
template <typename T, typename F>
std::tuple<T, T, T, T> rational_binary_search(T p1, T q1, T p2, T q2, F f, T n);
```

Let $S$ be the set of irreducible fractions whose denominator is a positive integer less than or equal to $n$.
It returns $(p_3, q_3, p_4, q_4)$.
$\frac{p_3}{q_3}$ is the maximum $\frac{p}{q}$ such that $\frac{p}{q} \in S$ and $f\left(\frac{p}{q}\right) = f\left(\frac{p_1}{q_1}\right)$.
$\frac{p_4}{q_4}$ is the minimum $\frac{p}{q}$ such that $\frac{p}{q} \in S$ and $f\left(\frac{p}{q}\right) = f\left(\frac{p_2}{q_2}\right)$.

### Constraints
- `<T>` is an integral type.
- $q_1 \geq 0$
- $q_2 \geq 0$
- $\frac{p_1}{q_1} < \frac{p_2}{q_2}$
- $f$ takes a numerator and a denominator as two integer parameters and returns `bool`.
- $f\left(\frac{p_1}{q_1}\right) \neq f\left(\frac{p_2}{q_2}\right)$
- $\exists \frac{p^\ast}{q^\ast} \in \mathbb{Q}. \left( \left( \forall \frac{p}{q} \in \mathbb{Q}. \frac{p_1}{q_1} \leq \frac{p}{q} \leq \frac{p^\ast}{q^\ast} \Rightarrow f\left(\frac{p}{q}\right) = f\left(\frac{p_1}{q_1}\right) \right) \land \left( \forall \frac{p}{q} \in \mathbb{Q}. \frac{p^\ast}{q^\ast} < \frac{p}{q} \leq \frac{p_2}{q_2} \Rightarrow f\left(\frac{p}{q}\right) = f\left(\frac{p_2}{q_2}\right) \right) \right)$
- $n > 0$

### Time Complexity
- $O(\log n)$

### License
- CC0

### Author
- anqooqie
