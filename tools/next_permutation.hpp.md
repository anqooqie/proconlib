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
  bundledCode: "#line 1 \"tools/next_permutation.hpp\"\n\n\n\n#include <algorithm>\n\
    \nnamespace tools {\n\n  template <typename Iterator>\n  bool next_permutation(const\
    \ Iterator first, const Iterator k, const Iterator last) {\n    ::std::reverse(k,\
    \ last);\n    return ::std::next_permutation(first, last);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_NEXT_PERMUTATION_HPP\n#define TOOLS_NEXT_PERMUTATION_HPP\n\n\
    #include <algorithm>\n\nnamespace tools {\n\n  template <typename Iterator>\n\
    \  bool next_permutation(const Iterator first, const Iterator k, const Iterator\
    \ last) {\n    ::std::reverse(k, last);\n    return ::std::next_permutation(first,\
    \ last);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/next_permutation.hpp
  requiredBy: []
  timestamp: '2021-06-13 13:30:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/next_permutation.hpp
layout: document
title: Next permutation as n-choose-r
---

```cpp
template <typename Iterator>
bool next_permutation(Iterator first, Iterator k, Iterator last);
```

It generates the next permutation as n-choose-r.
It returns `true` if the next permutation exists, `false` otherwise.

### Usage
```cpp
// 9-choose-3
int k = 3;
do {
  std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;
} while (tools::next_permutation(s.begin(), std::next(s.begin(), k), s.end()));
```

### Constraints
- `first` $\leq$ `k` $\leq$ `last`

### Time Complexity
- $O(\text{last} - \text{first})$

### License
- CC0

### Author
- anqooqie
