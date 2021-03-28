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
  bundledCode: "#line 1 \"tools/to_signed.hpp\"\n\n\n\n#include <type_traits>\n\n\
    namespace tools {\n\n  template <typename T>\n  constexpr typename ::std::make_signed<T>::type\
    \ to_signed(const T x) noexcept {\n    return x;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_TO_SIGNED_HPP\n#define TOOLS_TO_SIGNED_HPP\n\n#include <type_traits>\n\
    \nnamespace tools {\n\n  template <typename T>\n  constexpr typename ::std::make_signed<T>::type\
    \ to_signed(const T x) noexcept {\n    return x;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/to_signed.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/to_signed.hpp
layout: document
title: To signed value
---

```cpp
template <typename T>
constexpr typename ::std::make_signed<T>::type to_signed(T x) noexcept;
```

It converts an unsigned integer into signed one.

## Usage
```cpp
std::uint_fast64_t i;
decltype(tools::to_signed(i)) //=> std::int_fast64_t
```

## License
- CC0

## Author
- anqooqie
