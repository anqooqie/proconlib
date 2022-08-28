---
title: Convex hull
documentation_of: //tools/convex_hull.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void convex_hull(InputIterator begin, InputIterator end, bool minimum, OutputIterator result);
```

It stores the indices of vertices or the vertices themselves which are on the edge of the convex hull of a given polygon to `result`.
If `minimum` is `true`, only the minimal vertices required for the convex hull will be stored.
On the other hand, if `minimum` is `false`, all the vertices on the edge of the convex hull will be stored.

The vertices will be stored counterclockwisely.
The first sroted vertex will be the leftmost vertex.
If the number of the leftmost vertices is more than one, the first stored vertex will be the lowermost vertex in them.

## Constraints
- `begin` $\leq$ `end`
- The type of `*begin` is `tools::vector2<T>`.
- Either `std::size_t` or `tools::vector2<T>` is assignable to `*result`.

## Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
