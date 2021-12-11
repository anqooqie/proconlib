---
title: Convex hull
documentation_of: //tools/convex_hull.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void convex_hull(InputIterator begin, InputIterator end, bool minimum, OutputIterator result);
```

It stores the indices of vertices which are on the edge of the convex hull of a given polygon to `result`.
If `minimum` is `true`, only the minimal vertices required for the convex hull will be stored.
On the other hand, if `minimum` is `false`, all the vertices on the edge of the convex hull will be stored.

## Constraints
- `begin` $\leq$ `end`
- The type of `*begin` is `tools::vector2<T>`

## Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
