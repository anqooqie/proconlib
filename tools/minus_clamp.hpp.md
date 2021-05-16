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
  bundledCode: "#line 1 \"tools/minus_clamp.hpp\"\n\n\n\n#include <limits>\n#include\
    \ <algorithm>\n\nnamespace tools {\n\n  template <typename T>\n  constexpr T minus_clamp(const\
    \ T& lhs, const T& rhs, const T& min = ::std::numeric_limits<T>::min(), const\
    \ T& max = ::std::numeric_limits<T>::max()) {\n    T result;\n    if (rhs < 0\
    \ && lhs > ::std::numeric_limits<T>::max() - rhs) {\n      result = ::std::numeric_limits<T>::max();\n\
    \    } else if (rhs > 0 && lhs < ::std::numeric_limits<T>::min() - rhs) {\n  \
    \    result = ::std::numeric_limits<T>::min();\n    } else {\n      result = lhs\
    \ - rhs;\n    }\n    return ::std::clamp(result, min, max);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MINUS_CLAMP_HPP\n#define TOOLS_MINUS_CLAMP_HPP\n\n#include\
    \ <limits>\n#include <algorithm>\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  constexpr T minus_clamp(const T& lhs, const T& rhs, const T& min = ::std::numeric_limits<T>::min(),\
    \ const T& max = ::std::numeric_limits<T>::max()) {\n    T result;\n    if (rhs\
    \ < 0 && lhs > ::std::numeric_limits<T>::max() - rhs) {\n      result = ::std::numeric_limits<T>::max();\n\
    \    } else if (rhs > 0 && lhs < ::std::numeric_limits<T>::min() - rhs) {\n  \
    \    result = ::std::numeric_limits<T>::min();\n    } else {\n      result = lhs\
    \ - rhs;\n    }\n    return ::std::clamp(result, min, max);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/minus_clamp.hpp
  requiredBy: []
  timestamp: '2021-05-16 21:52:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/minus_clamp.hpp
layout: document
title: $\min(\max(x - y, \text{lower_bound}), \text{upper_bound})$ without overflow
---

```cpp
template <typename T>
T minus_clamp(T x, T y, T lower_bound = std::numeric_limits<T>::min(), T upper_bound = std::numeric_limits<T>::max());
```

It returns $\min(\max(x - y, \text{lower_bound}), \text{upper_bound})$ without overflow.

## License
- CC0

## Author
- anqooqie
