---
title: Fill a multi-dimensional vector
documentation_of: //tools/fill.hpp
---

```cpp
template <class T, class Allocator, typename V>
void fill(std::vector<T, Allocator>& vector, const V& value);
```

It fills all the elements of a multi-dimensional vector at once.

## Example
Let us assume that the type of `v` is `std::vector<std::vector<std::vector<int>>>`.
After calling `tools::fill(v, -1);`, all of `v[x][y][z]` will be $-1$.

## Constraints
- None

## Time Complexity
- $O(N)$ where N is the product of the size of all dimensions

## References
- [C++ の 再帰template を使ったあまり使えない競プロ用 std::vector 操作テク - koyumeishiのブログ](https://koyumeishi.hatenablog.com/entry/2016/02/01/152426)

## License
- Unknown

## Author
- koyumeishi
