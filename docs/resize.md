---
title: Resize a multi-dimensional vector
documentation_of: //tools/resize.hpp
---

```cpp
template <class T, class Allocator, typename Head>
void resize(std::vector<T, Allocator>& vector, const Head& head);

template <class T, class Allocator, typename Head, typename... Tail>
void resize(std::vector<T, Allocator>& vector, const Head& head, const Tail&... tail);
```

It resizes each dimension of a multi-dimensional vector at once.

## Example
Let us assume that the type of `v` is `std::vector<std::vector<std::vector<int>>>`.
After calling `tools::resize(v, 3, 4, 5);`, `v[x][y][z]` for $0 \leq x < 3$, $0 \leq y < 4$ and $0 \leq z < 5$ will be available.

## Constraints
- None

## Time Complexity
- $O(N)$ where N is the product of the size of all dimensions

## References
- [C++ の 再帰template を使ったあまり使えない競プロ用 std::vector 操作テク - koyumeishiのブログ](https://koyumeishi.hatenablog.com/entry/2016/02/01/152426)

## License
- CC0

## Author
- anqooqie
