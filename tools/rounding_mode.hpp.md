---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/divides.test.cpp
    title: tests/bigdecimal/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/minus.test.cpp
    title: tests/bigdecimal/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/multiplies.test.cpp
    title: tests/bigdecimal/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/plus.test.cpp
    title: tests/bigdecimal/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/random.test.cpp
    title: tests/bigdecimal/random.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/rounding_mode.hpp\"\n\n\n\nnamespace tools {\n  enum\
    \ class rounding_mode {\n    ceiling,\n    down,\n    floor,\n    half_down,\n\
    \    half_even,\n    half_up,\n    up\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_ROUNDING_MODE_HPP\n#define TOOLS_ROUNDING_MODE_HPP\n\nnamespace\
    \ tools {\n  enum class rounding_mode {\n    ceiling,\n    down,\n    floor,\n\
    \    half_down,\n    half_even,\n    half_up,\n    up\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/rounding_mode.hpp
  requiredBy:
  - tools/bigdecimal.hpp
  timestamp: '2022-01-25 13:00:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/plus.test.cpp
documentation_of: tools/rounding_mode.hpp
layout: document
redirect_from:
- /library/tools/rounding_mode.hpp
- /library/tools/rounding_mode.hpp.html
title: tools/rounding_mode.hpp
---
