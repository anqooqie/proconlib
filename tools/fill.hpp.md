---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: tools/is_range.hpp
    title: Check whether T is a range type
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://koyumeishi.hatenablog.com/entry/2016/02/01/152426
  bundledCode: "#line 1 \"tools/fill.hpp\"\n\n\n\n#include <vector>\n#include <type_traits>\n\
    #include <algorithm>\n#include <iterator>\n#line 1 \"tools/is_range.hpp\"\n\n\n\
    \n#line 6 \"tools/is_range.hpp\"\n#include <utility>\n\nnamespace tools {\n  template\
    \ <typename T>\n  class is_range {\n  private:\n    template <typename U>\n  \
    \  static auto check(U x) -> decltype(::std::begin(x), ::std::end(x), ::std::true_type{});\n\
    \    static ::std::false_type check(...);\n\n  public:\n    static const bool\
    \ value = decltype(check(::std::declval<T>()))::value;\n  };\n}\n\n\n#line 9 \"\
    tools/fill.hpp\"\n\n// Source: https://koyumeishi.hatenablog.com/entry/2016/02/01/152426\n\
    // License: unknown\n// Author: koyumeishi\n\nnamespace tools {\n  template <class\
    \ T, class Allocator, typename V>\n  auto fill(::std::vector<T, Allocator>& vector,\
    \ const V& value) -> ::std::enable_if_t<!::tools::is_range<T>::value, void> {\n\
    \    ::std::fill(::std::begin(vector), ::std::end(vector), value);\n  }\n  template\
    \ <class T, class Allocator, typename V>\n  auto fill(::std::vector<T, Allocator>&\
    \ vector, const V& value) -> ::std::enable_if_t<::tools::is_range<T>::value, void>\
    \ {\n    for (auto& child : vector) {\n      ::tools::fill(child, value);\n  \
    \  }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FILL_HPP\n#define TOOLS_FILL_HPP\n\n#include <vector>\n#include\
    \ <type_traits>\n#include <algorithm>\n#include <iterator>\n#include \"tools/is_range.hpp\"\
    \n\n// Source: https://koyumeishi.hatenablog.com/entry/2016/02/01/152426\n// License:\
    \ unknown\n// Author: koyumeishi\n\nnamespace tools {\n  template <class T, class\
    \ Allocator, typename V>\n  auto fill(::std::vector<T, Allocator>& vector, const\
    \ V& value) -> ::std::enable_if_t<!::tools::is_range<T>::value, void> {\n    ::std::fill(::std::begin(vector),\
    \ ::std::end(vector), value);\n  }\n  template <class T, class Allocator, typename\
    \ V>\n  auto fill(::std::vector<T, Allocator>& vector, const V& value) -> ::std::enable_if_t<::tools::is_range<T>::value,\
    \ void> {\n    for (auto& child : vector) {\n      ::tools::fill(child, value);\n\
    \    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/is_range.hpp
  isVerificationFile: false
  path: tools/fill.hpp
  requiredBy:
  - tools/util.hpp
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/fill.hpp
layout: document
title: Fill a multi-dimensional vector
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
