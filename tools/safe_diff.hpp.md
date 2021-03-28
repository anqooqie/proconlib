---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/safe_diff.hpp\"\n\n\n\n#include <limits>\n#include\
    \ <stdexcept>\n\nnamespace tools {\n\n  template <typename T>\n  T safe_diff(const\
    \ T& lhs, const T& rhs) {\n    if (lhs == ::std::numeric_limits<T>::max() && rhs\
    \ == ::std::numeric_limits<T>::max()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::min())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::min()) return ::std::numeric_limits<T>::max();\n\
    \    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::max())\
    \ return ::std::numeric_limits<T>::min();\n    return lhs - rhs;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SAFE_DIFF_HPP\n#define TOOLS_SAFE_DIFF_HPP\n\n#include <limits>\n\
    #include <stdexcept>\n\nnamespace tools {\n\n  template <typename T>\n  T safe_diff(const\
    \ T& lhs, const T& rhs) {\n    if (lhs == ::std::numeric_limits<T>::max() && rhs\
    \ == ::std::numeric_limits<T>::max()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::min())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::min()) return ::std::numeric_limits<T>::max();\n\
    \    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::max())\
    \ return ::std::numeric_limits<T>::min();\n    return lhs - rhs;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/safe_diff.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/safe_diff.hpp
layout: document
title: $A - B$ but not causing overflow
---

```cpp
template <typename T>
T safe_diff(T x, T y);
```

It returns $x - y$ when we regard `std::numeric_limits<T>::max()` as $\infty$ and `std::numeric_limits<T>::min()` as $-\infty$.

## License
- CC0

## Author
- anqooqie
