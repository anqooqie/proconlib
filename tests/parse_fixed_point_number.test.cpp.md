---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cumsum2d.hpp
    title: 2D cumulative sum
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':heavy_check_mark:'
    path: tools/parse_fixed_point_number.hpp
    title: Parse fixed point number
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/agc047/tasks/agc047_a
    links:
    - https://atcoder.jp/contests/agc047/tasks/agc047_a
  bundledCode: "#line 1 \"tests/parse_fixed_point_number.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/agc047/tasks/agc047_a\"\n\n#include <cstdint>\n\
    #include <iostream>\n#include <vector>\n#include <string>\n#include <array>\n\
    #line 1 \"tools/parse_fixed_point_number.hpp\"\n\n\n\n#line 6 \"tools/parse_fixed_point_number.hpp\"\
    \n#include <algorithm>\n\nnamespace tools {\n\n  inline ::std::int_fast64_t parse_fixed_point_number(::std::string\
    \ s, const int scale) {\n    const auto pos = s.find('.');\n    if (pos != ::std::string::npos)\
    \ {\n      const int real_scale = s.size() - (pos + 1);\n      if (real_scale\
    \ <= scale) {\n        s += ::std::string(scale - real_scale, '0');\n      } else\
    \ {\n        s.resize(pos + 1 + scale);\n      }\n    } else {\n      s.push_back('.');\n\
    \      s += ::std::string(scale, '0');\n    }\n    s.erase(::std::remove(s.begin(),\
    \ s.end(), '.'), s.end());\n    return ::std::stoll(s);\n  }\n}\n\n\n#line 1 \"\
    tools/cumsum2d.hpp\"\n\n\n\n#include <cstddef>\n#line 6 \"tools/cumsum2d.hpp\"\
    \n#include <iterator>\n#line 8 \"tools/cumsum2d.hpp\"\n#include <cassert>\n\n\
    namespace tools {\n\n  template <typename G>\n  class cumsum2d {\n  private:\n\
    \    using T = typename G::T;\n    ::std::size_t height;\n    ::std::size_t width;\n\
    \    ::std::vector<T> preprocessed;\n\n  public:\n    template <typename Range>\n\
    \    explicit cumsum2d(const Range& range) {\n      const auto begin = ::std::begin(range);\n\
    \      const auto end = ::std::end(range);\n      this->height = ::std::distance(begin,\
    \ end);\n      this->width = this->height == 0 ? 0 : ::std::distance(::std::begin(*begin),\
    \ ::std::end(*begin));\n      this->preprocessed.reserve((this->height + 1) *\
    \ (this->width + 1));\n      ::std::fill_n(::std::back_inserter(this->preprocessed),\
    \ (this->height + 1) * (this->width + 1), G::e());\n\n      {\n        auto it1\
    \ = begin;\n        for (::std::size_t y = 0; y < this->height; ++y, ++it1) {\n\
    \          auto it2 = ::std::begin(*it1);\n          for (::std::size_t x = 0;\
    \ x < this->width; ++x, ++it2) {\n            this->preprocessed[(y + 1) * (this->width\
    \ + 1) + (x + 1)] = G::op(this->preprocessed[(y + 1) * (this->width + 1) + x],\
    \ *it2);\n          }\n        }\n      }\n      for (::std::size_t x = 0; x <\
    \ this->width; ++x) {\n        for (::std::size_t y = 0; y < this->height; ++y)\
    \ {\n          this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)] = G::op(this->preprocessed[y\
    \ * (this->width + 1) + (x + 1)], this->preprocessed[(y + 1) * (this->width +\
    \ 1) + (x + 1)]);\n        }\n      }\n    }\n\n    T query(const ::std::size_t\
    \ y1, const ::std::size_t y2, const ::std::size_t x1, const ::std::size_t x2)\
    \ const {\n      assert(y1 <= y2 && y2 <= this->height);\n      assert(x1 <= x2\
    \ && x2 <= this->width);\n      return G::op(\n        G::op(\n          G::op(\n\
    \            this->preprocessed[y2 * (this->width + 1) + x2],\n            G::inv(this->preprocessed[y2\
    \ * (this->width + 1) + x1])\n          ),\n          G::inv(this->preprocessed[y1\
    \ * (this->width + 1) + x2])\n        ),\n        this->preprocessed[y1 * (this->width\
    \ + 1) + x1]\n      );\n    }\n  };\n}\n\n\n#line 1 \"tools/group.hpp\"\n\n\n\n\
    namespace tools {\n  namespace group {\n    template <typename Type>\n    struct\
    \ plus {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n\
    \        return lhs + rhs;\n      }\n      static T e() {\n        return T(0);\n\
    \      }\n      static T inv(const T v) {\n        return -v;\n      }\n    };\n\
    \n    template <typename Type>\n    struct bit_xor {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs ^ rhs;\n  \
    \    }\n      static T e() {\n        return T(0);\n      }\n      static T inv(const\
    \ T v) {\n        return v;\n      }\n    };\n  }\n}\n\n\n#line 11 \"tests/parse_fixed_point_number.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N;\n  std::cin >> N;\n  std::vector<std::string>\
    \ A(N);\n  for (auto& A_i : A) std::cin >> A_i;\n\n  std::array<std::array<i64,\
    \ 19>, 19> matrix({{}});\n  for (const auto& A_i : A) {\n    i64 A_i_i64 = tools::parse_fixed_point_number(A_i,\
    \ 9);\n    i64 y;\n    for (y = 0; y < 18 && A_i_i64 % 2 == 0; ++y, A_i_i64 /=\
    \ 2);\n    i64 x;\n    for (x = 0; x < 18 && A_i_i64 % 5 == 0; ++x, A_i_i64 /=\
    \ 5);\n \n    ++matrix[y][x];\n  }\n\n  const auto cumsum = tools::cumsum2d<tools::group::plus<i64>>(matrix);\n\
    \  i64 answer = 0;\n  for (i64 y = 0; y <= 18; ++y) {\n    for (i64 x = 0; x <=\
    \ 18; ++x) {\n      answer += matrix[y][x] * cumsum.query(18 - y, 19, 18 - x,\
    \ 19);\n    }\n  }\n  answer -= cumsum.query(9, 19, 9, 19);\n  answer /= 2;\n\
    \  std::cout << answer << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc047/tasks/agc047_a\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n#include <string>\n\
    #include <array>\n#include \"tools/parse_fixed_point_number.hpp\"\n#include \"\
    tools/cumsum2d.hpp\"\n#include \"tools/group.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N;\n  std::cin >> N;\n  std::vector<std::string> A(N);\n  for (auto& A_i\
    \ : A) std::cin >> A_i;\n\n  std::array<std::array<i64, 19>, 19> matrix({{}});\n\
    \  for (const auto& A_i : A) {\n    i64 A_i_i64 = tools::parse_fixed_point_number(A_i,\
    \ 9);\n    i64 y;\n    for (y = 0; y < 18 && A_i_i64 % 2 == 0; ++y, A_i_i64 /=\
    \ 2);\n    i64 x;\n    for (x = 0; x < 18 && A_i_i64 % 5 == 0; ++x, A_i_i64 /=\
    \ 5);\n \n    ++matrix[y][x];\n  }\n\n  const auto cumsum = tools::cumsum2d<tools::group::plus<i64>>(matrix);\n\
    \  i64 answer = 0;\n  for (i64 y = 0; y <= 18; ++y) {\n    for (i64 x = 0; x <=\
    \ 18; ++x) {\n      answer += matrix[y][x] * cumsum.query(18 - y, 19, 18 - x,\
    \ 19);\n    }\n  }\n  answer -= cumsum.query(9, 19, 9, 19);\n  answer /= 2;\n\
    \  std::cout << answer << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - tools/parse_fixed_point_number.hpp
  - tools/cumsum2d.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/parse_fixed_point_number.test.cpp
  requiredBy: []
  timestamp: '2022-03-12 16:17:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/parse_fixed_point_number.test.cpp
layout: document
redirect_from:
- /verify/tests/parse_fixed_point_number.test.cpp
- /verify/tests/parse_fixed_point_number.test.cpp.html
title: tests/parse_fixed_point_number.test.cpp
---
