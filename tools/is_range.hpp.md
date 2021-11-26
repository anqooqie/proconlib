---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/fill.hpp
    title: Fill a multi-dimensional vector
  - icon: ':warning:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/is_range.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <type_traits>\n#include <utility>\n\nnamespace tools {\n  template <typename\
    \ T>\n  class is_range {\n  private:\n    template <typename U>\n    static auto\
    \ check(U x) -> decltype(::std::begin(x), ::std::end(x), ::std::true_type{});\n\
    \    static ::std::false_type check(...);\n\n  public:\n    static const bool\
    \ value = decltype(check(::std::declval<T>()))::value;\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_IS_RANGE_HPP\n#define TOOLS_IS_RANGE_HPP\n\n#include <iterator>\n\
    #include <type_traits>\n#include <utility>\n\nnamespace tools {\n  template <typename\
    \ T>\n  class is_range {\n  private:\n    template <typename U>\n    static auto\
    \ check(U x) -> decltype(::std::begin(x), ::std::end(x), ::std::true_type{});\n\
    \    static ::std::false_type check(...);\n\n  public:\n    static const bool\
    \ value = decltype(check(::std::declval<T>()))::value;\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/is_range.hpp
  requiredBy:
  - tools/util.hpp
  - tools/fill.hpp
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/is_range.hpp
layout: document
title: Check whether T is a range type
---

```cpp
template <typename T>
struct is_range {
  static const bool value;
};
```

`tools::is_range<T>::value` will be `true` if and only if an instance of `T` can be passed to `std::begin` and `std::end`.
Otherwise, it will be `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
