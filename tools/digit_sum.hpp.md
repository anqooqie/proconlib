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
  bundledCode: "#line 1 \"tools/digit_sum.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  T digit_sum(T n) {\n    T sum = 0;\n    for (; n > 0; n /= 10)\
    \ {\n      sum += n % 10;\n    }\n    return sum;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_DIGIT_SUM_HPP\n#define TOOLS_DIGIT_SUM_HPP\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  T digit_sum(T n) {\n    T sum = 0;\n    for\
    \ (; n > 0; n /= 10) {\n      sum += n % 10;\n    }\n    return sum;\n  }\n}\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/digit_sum.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/digit_sum.hpp
layout: document
title: Sum of digits
---

```cpp
template <typename T>
T digit_sum(T n);
```

It returns sum of digits.

## License
- CC0

## Author
- anqooqie
