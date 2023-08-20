---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/xor_basis.test.cpp
    title: tests/xor_basis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://twitter.com/noshi91/status/1200702280128856064
  bundledCode: "#line 1 \"tools/xor_basis.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <vector>\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n#line 7 \"tools/xor_basis.hpp\"\n\n// Source:\
    \ https://twitter.com/noshi91/status/1200702280128856064\n// License: unknown\n\
    // Author: noshi91\n\nnamespace tools {\n  template <typename InputIterator, typename\
    \ OutputIterator>\n  void xor_basis(const InputIterator& begin, const InputIterator&\
    \ end, OutputIterator result) {\n    using T = ::std::decay_t<decltype(*begin)>;\n\
    \n    ::std::vector<T> basis;\n    for (auto it = begin; it != end; ++it) {\n\
    \      T e = *it;\n      for (const T& b : basis) {\n        ::tools::chmin(e,\
    \ e ^ b);\n      }\n      if (e != 0) {\n        basis.push_back(e);\n      }\n\
    \    }\n\n    for (const T& b : basis) {\n      *result = b;\n      ++result;\n\
    \    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_XOR_BASIS_HPP\n#define TOOLS_XOR_BASIS_HPP\n\n#include <type_traits>\n\
    #include <vector>\n#include \"tools/chmin.hpp\"\n\n// Source: https://twitter.com/noshi91/status/1200702280128856064\n\
    // License: unknown\n// Author: noshi91\n\nnamespace tools {\n  template <typename\
    \ InputIterator, typename OutputIterator>\n  void xor_basis(const InputIterator&\
    \ begin, const InputIterator& end, OutputIterator result) {\n    using T = ::std::decay_t<decltype(*begin)>;\n\
    \n    ::std::vector<T> basis;\n    for (auto it = begin; it != end; ++it) {\n\
    \      T e = *it;\n      for (const T& b : basis) {\n        ::tools::chmin(e,\
    \ e ^ b);\n      }\n      if (e != 0) {\n        basis.push_back(e);\n      }\n\
    \    }\n\n    for (const T& b : basis) {\n      *result = b;\n      ++result;\n\
    \    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/chmin.hpp
  isVerificationFile: false
  path: tools/xor_basis.hpp
  requiredBy: []
  timestamp: '2021-12-05 13:54:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/xor_basis.test.cpp
documentation_of: tools/xor_basis.hpp
layout: document
title: Basis of xor
---

```cpp
template <typename InputIterator, typename OutputIterator>
void xor_basis(InputIterator begin, InputIterator end, OutputIterator result);
```

It stores the basis of $\[\mathrm{begin}, \mathrm{end})$ to `result`.

## References
- [@noshi91 - Twitter](https://twitter.com/noshi91/status/1200702280128856064)

## Constraints
- None

## Time Complexity
- $O(N^2)$ where $N$ is `end` - `begin`

## License
- Unknown

## Author
- noshi91
