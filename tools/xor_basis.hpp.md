---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/xor_basis.test.cpp
    title: tests/xor_basis.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://twitter.com/noshi91/status/1200702280128856064
  bundledCode: "#line 1 \"tools/xor_basis.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <vector>\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\n\
    \n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T, typename U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n\
    \    using UT = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n\
    \    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool\
    \ updated = ::tools::cmp_less(rhs, lhs);\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n\n#line 7 \"tools/xor_basis.hpp\"\n\n// Source: https://twitter.com/noshi91/status/1200702280128856064\n\
    // License: unknown\n// Author: noshi91\n\nnamespace tools {\n  template <typename\
    \ InputIterator, typename OutputIterator>\n  void xor_basis(const InputIterator&\
    \ begin, const InputIterator& end, OutputIterator result) {\n    using T = ::std::decay_t<decltype(*begin)>;\n\
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
  - tools/cmp_less.hpp
  isVerificationFile: false
  path: tools/xor_basis.hpp
  requiredBy: []
  timestamp: '2024-03-20 23:37:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
