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
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/slerp.test.cpp
    title: tests/quaternion/slerp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/exp.hpp\"\n\n\n\n#include <cmath>\n\nnamespace tools\
    \ {\n  template <typename T>\n  auto exp(const T x) {\n    return ::std::exp(x);\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_EXP_HPP\n#define TOOLS_EXP_HPP\n\n#include <cmath>\n\nnamespace\
    \ tools {\n  template <typename T>\n  auto exp(const T x) {\n    return ::std::exp(x);\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/exp.hpp
  requiredBy:
  - tools/quaternion.hpp
  timestamp: '2022-11-03 23:21:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/quaternion/dice_rotations.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/angle_axis.test.cpp
documentation_of: tools/exp.hpp
layout: document
title: std::exp(x) extended for my library
---

```cpp
template <typename T>
auto exp(T x) -> decltype(std::exp(x));
```

If `std::exp(x)` is available, it returns `std::exp(x)`.

`tools::exp(x)` will be extended by other header files in my library.
For example, `tools::exp(tools::quaternion<T>)` gets available if you include `tools/quaternion.hpp`.

## Constraints
- See the standard or the explanation of the corresponding header file.

## Time Complexity
- See the standard or the explanation of the corresponding header file.

## License
- CC0

## Author
- anqooqie
