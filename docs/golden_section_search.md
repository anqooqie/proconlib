---
title: Golden section search
documentation_of: //tools/golden_section_search.hpp
---

```cpp
template <typename T, typename F>
auto golden_section_search(T l, T r, F f, bool search_maximum) -> std::pair<T, std::decay_t<decltype(f(std::declval<T>()))>>;
```

It returns $(x, f(x))$ such that $f(x)$ is maximum or minimum in $l \leq x \leq r$.

### Constraints
- `<T>` is any one of `float`, `double` or `long double`.
- $l \leq r$
- If `search_maximum` is `true`, $\exists x. (\forall i. \forall j. l \leq i < j \leq x \Rightarrow f(i) < f(j)) \land (\forall i. \forall j. x \leq i < j \leq r \Rightarrow f(i) > f(j))$
- If `search_maximum` is `false`, $\exists x. (\forall i. \forall j. l \leq i < j \leq x \Rightarrow f(i) > f(j)) \land (\forall i. \forall j. x \leq i < j \leq r \Rightarrow f(i) < f(j))$

### Time Complexity
- It calls `f`, $\left( \left\lceil \frac{d}{\log_2 \frac{1 + \sqrt{5}}{2}} \right\rceil + 2 \right)$ times where $d$ is `std::numeric_limits<T>::digits`. (In most implementations, `float`: $37$ times / `double`: $79$ times / `long double`: $95$ times)

### License
- CC0

### Author
- anqooqie
