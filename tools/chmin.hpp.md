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
  bundledCode: "#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CHMIN_HPP\n#define TOOLS_CHMIN_HPP\n\n#include <algorithm>\n\
    \nnamespace tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs,\
    \ const N& rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs =\
    \ rhs;\n    return updated;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/chmin.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/chmin.hpp
layout: document
title: chmin function
---

```cpp
template <typename M, typename N>
bool chmin(M& lhs, N rhs);
```

It runs `lhs = std::min(lhs, rhs);`.
It returns `true` if `lhs` has been updated, `false` otherwise.

## License
- CC0

## Author
- anqooqie
