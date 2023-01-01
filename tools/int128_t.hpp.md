---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/int128_t.test.cpp
    title: tests/int128_t.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/int128_t.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <string>\n#include <cassert>\n#include <cstddef>\n#include <algorithm>\n#line\
    \ 1 \"tools/uint128_t.hpp\"\n\n\n\n#line 9 \"tools/uint128_t.hpp\"\n\nnamespace\
    \ tools {\n  using uint128_t = unsigned __int128;\n}\n\n::std::istream& operator>>(::std::istream&\
    \ is, ::tools::uint128_t& x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\
    \n  x = 0;\n  for (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0'\
    \ <= s[i] && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n\
    }\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n\
    \  if (x == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n  \
    \  s.push_back('0' + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(),\
    \ s.end());\n\n  return os << s;\n}\n\n\n#line 10 \"tools/int128_t.hpp\"\n\nnamespace\
    \ tools {\n  using int128_t = __int128;\n}\n\n::std::istream& operator>>(::std::istream&\
    \ is, ::tools::int128_t& x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\
    \n  if (s == \"-170141183460469231731687303715884105728\") {\n    x = -::tools::int128_t((::tools::uint128_t(1)\
    \ << 127) - 1) - 1;\n    return is;\n  }\n\n  x = 0;\n  for (::std::size_t i =\
    \ s[0] == '+' || s[0] == '-'; i < s.size(); ++i) {\n    assert('0' <= s[i] &&\
    \ s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  if (s[0] == '-') x =\
    \ -x;\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::int128_t\
    \ x) {\n  if (x == 0) return os << '0';\n  if (x == -::tools::int128_t((::tools::uint128_t(1)\
    \ << 127) - 1) - 1) return os << \"-170141183460469231731687303715884105728\"\
    ;\n\n  ::std::string s;\n  const bool negative = x < 0;\n\n  if (negative) x =\
    \ -x;\n  while (x > 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n\n\
    \  if (negative) s.push_back('-');\n  ::std::reverse(s.begin(), s.end());\n  return\
    \ os << s;\n}\n\n\n"
  code: "#ifndef TOOLS_INT128_T_HPP\n#define TOOLS_INT128_T_HPP\n\n#include <iostream>\n\
    #include <string>\n#include <cassert>\n#include <cstddef>\n#include <algorithm>\n\
    #include \"tools/uint128_t.hpp\"\n\nnamespace tools {\n  using int128_t = __int128;\n\
    }\n\n::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {\n\
    \  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  if (s == \"-170141183460469231731687303715884105728\"\
    ) {\n    x = -::tools::int128_t((::tools::uint128_t(1) << 127) - 1) - 1;\n   \
    \ return is;\n  }\n\n  x = 0;\n  for (::std::size_t i = s[0] == '+' || s[0] ==\
    \ '-'; i < s.size(); ++i) {\n    assert('0' <= s[i] && s[i] <= '9');\n    x =\
    \ 10 * x + (s[i] - '0');\n  }\n\n  if (s[0] == '-') x = -x;\n\n  return is;\n\
    }\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::int128_t x) {\n \
    \ if (x == 0) return os << '0';\n  if (x == -::tools::int128_t((::tools::uint128_t(1)\
    \ << 127) - 1) - 1) return os << \"-170141183460469231731687303715884105728\"\
    ;\n\n  ::std::string s;\n  const bool negative = x < 0;\n\n  if (negative) x =\
    \ -x;\n  while (x > 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n\n\
    \  if (negative) s.push_back('-');\n  ::std::reverse(s.begin(), s.end());\n  return\
    \ os << s;\n}\n\n#endif\n"
  dependsOn:
  - tools/uint128_t.hpp
  isVerificationFile: false
  path: tools/int128_t.hpp
  requiredBy: []
  timestamp: '2022-11-23 11:49:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/int128_t.test.cpp
documentation_of: tools/int128_t.hpp
layout: document
title: 128 bit signed integer
---

```cpp
using int128_t = __int128;

std::istream& operator>>(std::istream& is, int128_t& x);
std::ostream& operator<<(std::ostream& is, int128_t x);

namespace std {
  template <>
  struct hash<int128_t> {
    std::size_t operator()(int128_t key) const;
  };
}
```

It is an alias for `__int128`.
Also, this header file adds some functions for `__int128`.

## Constraints
- It requires GCC or clang.

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
