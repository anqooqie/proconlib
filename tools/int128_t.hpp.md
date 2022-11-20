---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':heavy_check_mark:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
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
    \ <string>\n#include <cassert>\n#include <cstddef>\n#include <algorithm>\n#include\
    \ <functional>\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\n#line 1 \"tools/now.hpp\"\
    \n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline long long now() {\n \
    \   return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \  }\n}\n\n\n#line 1 \"tools/hash_combine.hpp\"\n\n\n\n#line 6 \"tools/hash_combine.hpp\"\
    \n\n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
    // License: MIT\n// Author: Google Inc.\n\n// Copyright (c) 2011 Google, Inc.\n\
    //\n// Permission is hereby granted, free of charge, to any person obtaining a\
    \ copy\n// of this software and associated documentation files (the \"Software\"\
    ), to deal\n// in the Software without restriction, including without limitation\
    \ the rights\n// to use, copy, modify, merge, publish, distribute, sublicense,\
    \ and/or sell\n// copies of the Software, and to permit persons to whom the Software\
    \ is\n// furnished to do so, subject to the following conditions:\n//\n// The\
    \ above copyright notice and this permission notice shall be included in\n// all\
    \ copies or substantial portions of the Software.\n//\n// THE SOFTWARE IS PROVIDED\
    \ \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED, INCLUDING BUT\
    \ NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS FOR A PARTICULAR\
    \ PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS OR COPYRIGHT\
    \ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY, WHETHER IN\
    \ AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF OR IN CONNECTION\
    \ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n// THE SOFTWARE.\n\nnamespace\
    \ tools {\n  template <typename T>\n  void hash_combine(::std::size_t& seed, const\
    \ T& v) {\n    static const ::std::hash<T> hasher;\n    static constexpr ::std::size_t\
    \ k_mul = 0x9ddfea08eb382d69ULL;\n    ::std::size_t a = (hasher(v) ^ seed) * k_mul;\n\
    \    a ^= (a >> 47);\n    ::std::size_t b = (seed ^ a) * k_mul;\n    b ^= (b >>\
    \ 47);\n    seed = b * k_mul;\n  }\n}\n\n\n#line 12 \"tools/uint128_t.hpp\"\n\n\
    namespace tools {\n  using uint128_t = unsigned __int128;\n}\n\n::std::istream&\
    \ operator>>(::std::istream& is, ::tools::uint128_t& x) {\n  ::std::string s;\n\
    \  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for (::std::size_t i = s[0]\
    \ == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i] && s[i] <= '9');\n    x\
    \ = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream&\
    \ os, ::tools::uint128_t x) {\n  if (x == 0) return os << '0';\n\n  ::std::string\
    \ s;\n  while (x > 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n \
    \ ::std::reverse(s.begin(), s.end());\n\n  return os << s;\n}\n\nnamespace std\
    \ {\n  template <>\n  struct hash<::tools::uint128_t> {\n    ::std::size_t operator()(const\
    \ ::tools::uint128_t& key) const {\n      static const ::std::size_t seed = ::tools::now();\n\
    \n      ::std::size_t hash = seed;\n      ::tools::hash_combine(hash, static_cast<unsigned\
    \ long long>(key >> 64));\n      ::tools::hash_combine(hash, static_cast<unsigned\
    \ long long>(key & 0xFFFFFFFFFFFFFFFFULL));\n      return hash;\n    }\n  };\n\
    }\n\n\n#line 11 \"tools/int128_t.hpp\"\n\nnamespace tools {\n  using int128_t\
    \ = __int128;\n}\n\n::std::istream& operator>>(::std::istream& is, ::tools::int128_t&\
    \ x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  if (s == \"\
    -170141183460469231731687303715884105728\") {\n    x = -::tools::int128_t((::tools::uint128_t(1)\
    \ << 127) - 1) - 1;\n    return is;\n  }\n\n  x = 0;\n  for (::std::size_t i =\
    \ s[0] == '+' || s[0] == '-'; i < s.size(); ++i) {\n    assert('0' <= s[i] &&\
    \ s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  if (s[0] == '-') x =\
    \ -x;\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::int128_t\
    \ x) {\n  if (x == 0) return os << '0';\n  if (x == -::tools::int128_t((::tools::uint128_t(1)\
    \ << 127) - 1) - 1) return os << \"-170141183460469231731687303715884105728\"\
    ;\n\n  ::std::string s;\n  const bool negative = x < 0;\n\n  if (negative) x =\
    \ -x;\n  while (x > 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n\n\
    \  if (negative) s.push_back('-');\n  ::std::reverse(s.begin(), s.end());\n  return\
    \ os << s;\n}\n\nnamespace std {\n  template <>\n  struct hash<::tools::int128_t>\
    \ {\n    ::std::size_t operator()(const ::tools::int128_t& key) const {\n    \
    \  static ::std::hash<::tools::uint128_t> hasher;\n      return hasher(static_cast<::tools::uint128_t>(key));\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_INT128_T_HPP\n#define TOOLS_INT128_T_HPP\n\n#include <iostream>\n\
    #include <string>\n#include <cassert>\n#include <cstddef>\n#include <algorithm>\n\
    #include <functional>\n#include \"tools/uint128_t.hpp\"\n\nnamespace tools {\n\
    \  using int128_t = __int128;\n}\n\n::std::istream& operator>>(::std::istream&\
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
    \ os << s;\n}\n\nnamespace std {\n  template <>\n  struct hash<::tools::int128_t>\
    \ {\n    ::std::size_t operator()(const ::tools::int128_t& key) const {\n    \
    \  static ::std::hash<::tools::uint128_t> hasher;\n      return hasher(static_cast<::tools::uint128_t>(key));\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/uint128_t.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/int128_t.hpp
  requiredBy: []
  timestamp: '2022-11-20 20:53:03+09:00'
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
