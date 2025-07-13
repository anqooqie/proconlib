---
title: std::ranges::upper_bound, but returns index
documentation_of: //tools/upper_bound.hpp
---

```cpp
(1)
template <
  std::random_access_iterator I,
  std::sentinel_for<I> S,
  typename Proj = std::identity,
  typename T = std::remove_cvref_t<std::invoke_result_t<Proj&, std::iter_value_t<I>&>>,
  std::indirect_strict_weak_order<const T*, std::projected<I, Proj>> Comp = std::ranges::less
>
constexpr std::iter_difference_t<I> upper_bound(I first, S last, T value, Comp comp = {}, Proj proj = {});

template <
  std::ranges::random_access_range R,
  typename Proj = std::identity,
  typename T = std::remove_cvref_t<std::invoke_result_t<Proj&, std::ranges::range_value_t<R>&>>,
  std::indirect_strict_weak_order<const T*, std::projected<std::ranges::iterator_t<R>, Proj>> Comp = std::ranges::less
>
constexpr std::ranges::range_difference_t<R> upper_bound(R&& r, T value, Comp comp = {}, Proj proj = {});
```

- (1)
    - It is identical to `std::ranges::distance(first, std::ranges::upper_bound(first, last, value, comp, proj));`.
- (2)
    - It is identical to `std::ranges::distance(std::ranges::begin(r), std::ranges::upper_bound(r, value, comp, proj))`.

### Constraints
- (1)
    - All elements $e$ in `[first, last)` such that `!std::invoke(comp, value, std::invoke(proj, e))` are to the left (closer to `first`) of all elements $f$ in `[first, last)` such that `std::invoke(comp, value, std::invoke(proj, f))`.
- (2)
    - All elements $e$ in `r` such that `!std::invoke(comp, value, std::invoke(proj, e))` are to the left (closer to `std::ranges::begin(r)`) of all elements $f$ in `r` such that `std::invoke(comp, value, std::invoke(proj, f))`.

### Time Complexity
- $O(\log n)$ where $n$ is `std::ranges::size(range)`

### License
- CC0

### Author
- anqooqie
