---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/log.hpp\"\n\n\n\n#include <cmath>\n\nnamespace tools\
    \ {\n  template <typename T>\n  auto log(const T x) {\n    return ::std::log(x);\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_LOG_HPP\n#define TOOLS_LOG_HPP\n\n#include <cmath>\n\nnamespace\
    \ tools {\n  template <typename T>\n  auto log(const T x) {\n    return ::std::log(x);\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/log.hpp
  requiredBy:
  - tools/quaternion.hpp
  timestamp: '2022-11-03 23:21:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/look_rotation.test.cpp
documentation_of: tools/log.hpp
layout: document
title: std::log(x) extended for my library
---

```cpp
template <typename T>
auto log(T x) -> decltype(std::log(x));
```

If `std::log(x)` is available, it returns `std::log(x)`.

`tools::log(x)` will be extended by other header files in my library.
For example, `tools::log(tools::quaternion<T>)` gets available if you include `tools/quaternion.hpp`.

## Constraints
- See the standard or the explanation of the corresponding header file.

## Time Complexity
- See the standard or the explanation of the corresponding header file.

## License
- CC0

## Author
- anqooqie
