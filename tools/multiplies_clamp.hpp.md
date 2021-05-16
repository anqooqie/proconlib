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
  bundledCode: "#line 1 \"tools/multiplies_clamp.hpp\"\n\n\n\n#include <limits>\n\
    #include <algorithm>\n\nnamespace tools {\n\n  template <typename T>\n  constexpr\
    \ T multiplies_clamp(const T& lhs, const T& rhs, const T& min = ::std::numeric_limits<T>::min(),\
    \ const T& max = ::std::numeric_limits<T>::max()) {\n    return std::clamp([&]()\
    \ {\n      if (lhs > 0) {\n        if (rhs > 0) {\n          if (lhs > ::std::numeric_limits<T>::max()\
    \ / rhs) {\n            return ::std::numeric_limits<T>::max();\n          }\n\
    \        } else {\n          if (rhs < ::std::numeric_limits<T>::min() / lhs)\
    \ {\n            return ::std::numeric_limits<T>::min();\n          }\n      \
    \  }\n      } else {\n        if (rhs > 0) {\n          if (lhs < ::std::numeric_limits<T>::min()\
    \ / rhs) {\n            return ::std::numeric_limits<T>::min();\n          }\n\
    \        } else {\n          if (lhs != 0 && rhs < ::std::numeric_limits<T>::max()\
    \ / lhs) {\n            return ::std::numeric_limits<T>::max();\n          }\n\
    \        }\n      }\n      return lhs * rhs;\n    }(), min, max);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MULTIPLIES_CLAMP_HPP\n#define TOOLS_MULTIPLIES_CLAMP_HPP\n\n\
    #include <limits>\n#include <algorithm>\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  constexpr T multiplies_clamp(const T& lhs, const T& rhs, const T& min\
    \ = ::std::numeric_limits<T>::min(), const T& max = ::std::numeric_limits<T>::max())\
    \ {\n    return std::clamp([&]() {\n      if (lhs > 0) {\n        if (rhs > 0)\
    \ {\n          if (lhs > ::std::numeric_limits<T>::max() / rhs) {\n          \
    \  return ::std::numeric_limits<T>::max();\n          }\n        } else {\n  \
    \        if (rhs < ::std::numeric_limits<T>::min() / lhs) {\n            return\
    \ ::std::numeric_limits<T>::min();\n          }\n        }\n      } else {\n \
    \       if (rhs > 0) {\n          if (lhs < ::std::numeric_limits<T>::min() /\
    \ rhs) {\n            return ::std::numeric_limits<T>::min();\n          }\n \
    \       } else {\n          if (lhs != 0 && rhs < ::std::numeric_limits<T>::max()\
    \ / lhs) {\n            return ::std::numeric_limits<T>::max();\n          }\n\
    \        }\n      }\n      return lhs * rhs;\n    }(), min, max);\n  }\n}\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/multiplies_clamp.hpp
  requiredBy: []
  timestamp: '2021-05-16 21:52:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/multiplies_clamp.hpp
layout: document
title: $\min(\max(x \cdot y, \text{lower_bound}), \text{upper_bound})$ without overflow
---

```cpp
template <typename T>
T multiplies_clamp(T x, T y, T lower_bound = std::numeric_limits<T>::min(), T upper_bound = std::numeric_limits<T>::max());
```

It returns $\min(\max(x \cdot y, \text{lower_bound}), \text{upper_bound})$ without overflow.

## License
- CC0

## Author
- anqooqie
