---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/uint128_t.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <sstream>\n#include <vector>\n#include <cstddef>\n\
    #include <functional>\n#include <algorithm>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/uint128_t.hpp\"\
    \n\n\n\n#line 5 \"tools/uint128_t.hpp\"\n#include <string>\n#include <cassert>\n\
    #line 1 \"tools/now.hpp\"\n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline\
    \ long long now() {\n    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
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
    }\n\n\n#line 11 \"tests/uint128_t.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  {\n    tools::uint128_t v;\n  \
    \  std::istringstream iss(\"0\");\n    iss >> v;\n    std::ostringstream oss;\n\
    \    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"+0\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"+1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"340282366920938463463374607431768211455\");\n\
    \    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"340282366920938463463374607431768211455\");\n  }\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"+340282366920938463463374607431768211455\"\
    );\n    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"340282366920938463463374607431768211455\");\n  }\n\n  {\n    std::vector<std::size_t>\
    \ v;\n    const std::hash<tools::uint128_t> hasher;\n    for (int i = 0; i < 1000000;\
    \ ++i) {\n      v.push_back(hasher(i));\n      assert_that(hasher(i) == v.back());\n\
    \    }\n\n    const auto old_size = v.size();\n    std::sort(v.begin(), v.end());\n\
    \    v.erase(std::unique(v.begin(), v.end()), v.end());\n    assert_that(v.size()\
    \ == old_size);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <sstream>\n#include <vector>\n#include <cstddef>\n\
    #include <functional>\n#include <algorithm>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/uint128_t.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  {\n    tools::uint128_t v;\n  \
    \  std::istringstream iss(\"0\");\n    iss >> v;\n    std::ostringstream oss;\n\
    \    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"+0\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"+1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"340282366920938463463374607431768211455\");\n\
    \    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"340282366920938463463374607431768211455\");\n  }\n  {\n    tools::uint128_t\
    \ v;\n    std::istringstream iss(\"+340282366920938463463374607431768211455\"\
    );\n    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"340282366920938463463374607431768211455\");\n  }\n\n  {\n    std::vector<std::size_t>\
    \ v;\n    const std::hash<tools::uint128_t> hasher;\n    for (int i = 0; i < 1000000;\
    \ ++i) {\n      v.push_back(hasher(i));\n      assert_that(hasher(i) == v.back());\n\
    \    }\n\n    const auto old_size = v.size();\n    std::sort(v.begin(), v.end());\n\
    \    v.erase(std::unique(v.begin(), v.end()), v.end());\n    assert_that(v.size()\
    \ == old_size);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/uint128_t.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: true
  path: tests/uint128_t.test.cpp
  requiredBy: []
  timestamp: '2022-11-20 20:53:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/uint128_t.test.cpp
layout: document
redirect_from:
- /verify/tests/uint128_t.test.cpp
- /verify/tests/uint128_t.test.cpp.html
title: tests/uint128_t.test.cpp
---
