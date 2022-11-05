---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
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
  bundledCode: "#line 1 \"tests/tuple_hash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/tuple_hash.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <tuple>\n#include <chrono>\n#include <functional>\n\
    \n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
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
    \ tools {\n  template <typename... Ts>\n  class tuple_hash {\n  public:\n    using\
    \ result_type = ::std::size_t;\n    using argument_type = ::std::tuple<Ts...>;\n\
    \n  private:\n    static constexpr result_type k_mul = 0x9ddfea08eb382d69ULL;\n\
    \n  public:\n    template <int I = int(sizeof...(Ts)) - 1>\n      result_type\
    \ operator()(const argument_type& key) const {\n      if constexpr (I == -1) {\n\
    \        static const result_type seed = ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \        return seed;\n      } else {\n        static const ::std::hash<::std::tuple_element_t<I,\
    \ argument_type>> hasher;\n        result_type seed = this->operator()<I - 1>(key);\n\
    \        result_type a = (hasher(::std::get<I>(key)) ^ seed) * k_mul;\n      \
    \  a ^= (a >> 47);\n        result_type b = (seed ^ a) * k_mul;\n        b ^=\
    \ (b >> 47);\n        seed = b * k_mul;\n        return seed;\n      }\n    }\n\
    \  };\n}\n\n\n#line 8 \"tests/tuple_hash.test.cpp\"\n\nusing ll = long long;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    std::vector<std::size_t> v;\n    const tools::tuple_hash<ll> hasher;\n\
    \    for (ll i = 0; i < 10000000; ++i) {\n      const auto tuple = std::make_tuple(i);\n\
    \      v.push_back(hasher(tuple));\n      assert_that(hasher(tuple) == v.back());\n\
    \    }\n\n    const auto old_size = v.size();\n    std::sort(v.begin(), v.end());\n\
    \    v.erase(std::unique(v.begin(), v.end()), v.end());\n    assert_that(v.size()\
    \ == old_size);\n  }\n\n  {\n    std::vector<std::size_t> v;\n    const tools::tuple_hash<ll,\
    \ ll> hasher;\n    for (ll i = 0; i < 3000; ++i) {\n      for (ll j = 0; j < 3000;\
    \ ++j) {\n        const auto tuple = std::make_tuple(i, j);\n        v.push_back(hasher(tuple));\n\
    \        assert_that(hasher(tuple) == v.back());\n      }\n    }\n\n    const\
    \ auto old_size = v.size();\n    std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n    assert_that(v.size() == old_size);\n  }\n\n  {\n  \
    \  std::vector<std::size_t> v;\n    const tools::tuple_hash<ll, ll, ll> hasher;\n\
    \    for (ll i = 0; i < 200; ++i) {\n      for (ll j = 0; j < 200; ++j) {\n  \
    \      for (ll k = 0; k < 200; ++k) {\n          const auto tuple = std::make_tuple(i,\
    \ j, k);\n          v.push_back(hasher(tuple));\n          assert_that(hasher(tuple)\
    \ == v.back());\n        }\n      }\n    }\n\n    const auto old_size = v.size();\n\
    \    std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(), v.end()),\
    \ v.end());\n    assert_that(v.size() == old_size);\n  }\n\n  {\n    std::vector<std::size_t>\
    \ v;\n    const tools::tuple_hash<ll, ll, ll, ll> hasher;\n    for (ll i = 0;\
    \ i < 60; ++i) {\n      for (ll j = 0; j < 60; ++j) {\n        for (ll k = 0;\
    \ k < 60; ++k) {\n          for (ll l = 0; l < 60; ++l) {\n            const auto\
    \ tuple = std::make_tuple(i, j, k, l);\n            v.push_back(hasher(tuple));\n\
    \            assert_that(hasher(tuple) == v.back());\n          }\n        }\n\
    \      }\n    }\n\n    const auto old_size = v.size();\n    std::sort(v.begin(),\
    \ v.end());\n    v.erase(std::unique(v.begin(), v.end()), v.end());\n    assert_that(v.size()\
    \ == old_size);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <algorithm>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/tuple_hash.hpp\"\n\nusing ll = long long;\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  {\n \
    \   std::vector<std::size_t> v;\n    const tools::tuple_hash<ll> hasher;\n   \
    \ for (ll i = 0; i < 10000000; ++i) {\n      const auto tuple = std::make_tuple(i);\n\
    \      v.push_back(hasher(tuple));\n      assert_that(hasher(tuple) == v.back());\n\
    \    }\n\n    const auto old_size = v.size();\n    std::sort(v.begin(), v.end());\n\
    \    v.erase(std::unique(v.begin(), v.end()), v.end());\n    assert_that(v.size()\
    \ == old_size);\n  }\n\n  {\n    std::vector<std::size_t> v;\n    const tools::tuple_hash<ll,\
    \ ll> hasher;\n    for (ll i = 0; i < 3000; ++i) {\n      for (ll j = 0; j < 3000;\
    \ ++j) {\n        const auto tuple = std::make_tuple(i, j);\n        v.push_back(hasher(tuple));\n\
    \        assert_that(hasher(tuple) == v.back());\n      }\n    }\n\n    const\
    \ auto old_size = v.size();\n    std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n    assert_that(v.size() == old_size);\n  }\n\n  {\n  \
    \  std::vector<std::size_t> v;\n    const tools::tuple_hash<ll, ll, ll> hasher;\n\
    \    for (ll i = 0; i < 200; ++i) {\n      for (ll j = 0; j < 200; ++j) {\n  \
    \      for (ll k = 0; k < 200; ++k) {\n          const auto tuple = std::make_tuple(i,\
    \ j, k);\n          v.push_back(hasher(tuple));\n          assert_that(hasher(tuple)\
    \ == v.back());\n        }\n      }\n    }\n\n    const auto old_size = v.size();\n\
    \    std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(), v.end()),\
    \ v.end());\n    assert_that(v.size() == old_size);\n  }\n\n  {\n    std::vector<std::size_t>\
    \ v;\n    const tools::tuple_hash<ll, ll, ll, ll> hasher;\n    for (ll i = 0;\
    \ i < 60; ++i) {\n      for (ll j = 0; j < 60; ++j) {\n        for (ll k = 0;\
    \ k < 60; ++k) {\n          for (ll l = 0; l < 60; ++l) {\n            const auto\
    \ tuple = std::make_tuple(i, j, k, l);\n            v.push_back(hasher(tuple));\n\
    \            assert_that(hasher(tuple) == v.back());\n          }\n        }\n\
    \      }\n    }\n\n    const auto old_size = v.size();\n    std::sort(v.begin(),\
    \ v.end());\n    v.erase(std::unique(v.begin(), v.end()), v.end());\n    assert_that(v.size()\
    \ == old_size);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/tuple_hash.hpp
  isVerificationFile: true
  path: tests/tuple_hash.test.cpp
  requiredBy: []
  timestamp: '2022-10-29 17:35:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tuple_hash.test.cpp
layout: document
redirect_from:
- /verify/tests/tuple_hash.test.cpp
- /verify/tests/tuple_hash.test.cpp.html
title: tests/tuple_hash.test.cpp
---