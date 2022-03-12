---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/parse_fixed_point_number.test.cpp
    title: tests/parse_fixed_point_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/parse_fixed_point_number.hpp\"\n\n\n\n#include <cstdint>\n\
    #include <string>\n#include <algorithm>\n\nnamespace tools {\n\n  inline ::std::int_fast64_t\
    \ parse_fixed_point_number(::std::string s, const int scale) {\n    const auto\
    \ pos = s.find('.');\n    if (pos != ::std::string::npos) {\n      const int real_scale\
    \ = s.size() - (pos + 1);\n      if (real_scale <= scale) {\n        s += ::std::string(scale\
    \ - real_scale, '0');\n      } else {\n        s.resize(pos + 1 + scale);\n  \
    \    }\n    } else {\n      s.push_back('.');\n      s += ::std::string(scale,\
    \ '0');\n    }\n    s.erase(::std::remove(s.begin(), s.end(), '.'), s.end());\n\
    \    return ::std::stoll(s);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_PARSE_FIXED_POINT_NUMBER\n#define TOOLS_PARSE_FIXED_POINT_NUMBER\n\
    \n#include <cstdint>\n#include <string>\n#include <algorithm>\n\nnamespace tools\
    \ {\n\n  inline ::std::int_fast64_t parse_fixed_point_number(::std::string s,\
    \ const int scale) {\n    const auto pos = s.find('.');\n    if (pos != ::std::string::npos)\
    \ {\n      const int real_scale = s.size() - (pos + 1);\n      if (real_scale\
    \ <= scale) {\n        s += ::std::string(scale - real_scale, '0');\n      } else\
    \ {\n        s.resize(pos + 1 + scale);\n      }\n    } else {\n      s.push_back('.');\n\
    \      s += ::std::string(scale, '0');\n    }\n    s.erase(::std::remove(s.begin(),\
    \ s.end(), '.'), s.end());\n    return ::std::stoll(s);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/parse_fixed_point_number.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/parse_fixed_point_number.test.cpp
documentation_of: tools/parse_fixed_point_number.hpp
layout: document
title: Parse fixed point number
---

```cpp
std::int_fast64_t parse_fixed_point_number(std::string s, int scale);
```
It parses a string as a fixed point number.
It returns $s * 10^{\mathrm{scale}}$.

## License
- CC0

## Author
- anqooqie
