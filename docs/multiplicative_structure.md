---
title: Automatically deduced multiplicative structure
documentation_of: //tools/multiplicative_structure.hpp
---

```cpp
template <typename T>
using multiplicative_structure = /* tools::monoids::multiplies<T> or tools::groups::multiplies<T> */;
```

It automatically selects either `tools::monoids::multiplies<T>` or `tools::groups::multiplies<T>` based on `T`.

### Example

|`T`|`tools::multiplicative_structure<T>`|
|---|---|
|`int`|`tools::monoids::multiplies<int>`|
|`double`|`tools::groups::multiplies<double>`|
|`std::complex<double>`|`tools::groups::multiplies<std::complex<double>>`|
|`atcoder::modint998244353`|`tools::groups::multiplies<atcoder::modint998244353>`|
|`atcoder::static_modint<4>`|`tools::monoids::multiplies<atcoder::static_modint<4>>`|
|`atcoder::modint`|`tools::groups::multiplies<atcoder::modint>`|
|`tools::fps<atcoder::modint998244353>`|`tools::groups::multiplies<tools::fps<atcoder::modint998244353>>`|
|`tools::permutation<int>`|`tools::monoids::multiplies<tools::permutation<int>>`|

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
