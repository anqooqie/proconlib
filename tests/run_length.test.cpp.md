---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/run_length.hpp
    title: Run-length encoding
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/run_length.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <vector>\n#include <cstdint>\n\
    #include <iterator>\n#line 1 \"tools/run_length.hpp\"\n\n\n\n#line 5 \"tools/run_length.hpp\"\
    \n#include <utility>\n#line 7 \"tools/run_length.hpp\"\n\nnamespace tools {\n\
    \  template <typename InputIterator, typename OutputIterator>\n  void run_length(const\
    \ InputIterator& begin, const InputIterator& end, OutputIterator result) {\n \
    \   using T = typename ::std::iterator_traits<InputIterator>::value_type;\n  \
    \  if (begin == end) return;\n\n    ::std::pair<T, ::std::int_fast64_t> prev;\n\
    \    for (auto [it, breaks] = ::std::make_pair(begin, false); !breaks; breaks\
    \ = it == end, it = ::std::next(it, breaks ? 0 : 1)) {\n      const auto [flg1,\
    \ flg2] = [&]() {\n        if (it == begin) return ::std::make_pair(false, true);\n\
    \        if (it == end) return ::std::make_pair(true, false);\n        if (*it\
    \ != prev.first) return ::std::make_pair(true, true);\n        return ::std::make_pair(false,\
    \ false);\n      }();\n      if (flg1 || flg2) {\n        if (flg1) {\n      \
    \    *result = prev;\n          ++result;\n        }\n        if (flg2) {\n  \
    \        prev.first = *it;\n          prev.second = 1;\n        }\n      } else\
    \ {\n        ++prev.second;\n      }\n    }\n  }\n}\n\n\n#line 9 \"tests/run_length.test.cpp\"\
    \n\nvoid assert_that(const bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n\
    \  }\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::string s;\n  std::vector<std::pair<char, std::int_fast64_t>> v;\n\n \
    \ s = \"ABBCCC\";\n  v.clear();\n  tools::run_length(s.begin(), s.end(), std::back_inserter(v));\n\
    \  assert_that(v.size() == 3);\n  assert_that(v[0].first == 'A');\n  assert_that(v[0].second\
    \ == 1);\n  assert_that(v[1].first == 'B');\n  assert_that(v[1].second == 2);\n\
    \  assert_that(v[2].first == 'C');\n  assert_that(v[2].second == 3);\n\n  s =\
    \ \"AAABBC\";\n  v.clear();\n  tools::run_length(s.begin(), s.end(), std::back_inserter(v));\n\
    \  assert_that(v.size() == 3);\n  assert_that(v[0].first == 'A');\n  assert_that(v[0].second\
    \ == 3);\n  assert_that(v[1].first == 'B');\n  assert_that(v[1].second == 2);\n\
    \  assert_that(v[2].first == 'C');\n  assert_that(v[2].second == 1);\n\n  s =\
    \ \"\";\n  v.clear();\n  tools::run_length(s.begin(), s.end(), std::back_inserter(v));\n\
    \  assert_that(v.size() == 0);\n\n  s = \"A\";\n  v.clear();\n  tools::run_length(s.begin(),\
    \ s.end(), std::back_inserter(v));\n  assert_that(v.size() == 1);\n  assert_that(v[0].first\
    \ == 'A');\n  assert_that(v[0].second == 1);\n\n  std::cout << \"Hello World\"\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include <vector>\n#include <cstdint>\n\
    #include <iterator>\n#include \"tools/run_length.hpp\"\n\nvoid assert_that(const\
    \ bool cond) {\n  if (!cond) {\n    std::exit(EXIT_FAILURE);\n  }\n}\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  std::string\
    \ s;\n  std::vector<std::pair<char, std::int_fast64_t>> v;\n\n  s = \"ABBCCC\"\
    ;\n  v.clear();\n  tools::run_length(s.begin(), s.end(), std::back_inserter(v));\n\
    \  assert_that(v.size() == 3);\n  assert_that(v[0].first == 'A');\n  assert_that(v[0].second\
    \ == 1);\n  assert_that(v[1].first == 'B');\n  assert_that(v[1].second == 2);\n\
    \  assert_that(v[2].first == 'C');\n  assert_that(v[2].second == 3);\n\n  s =\
    \ \"AAABBC\";\n  v.clear();\n  tools::run_length(s.begin(), s.end(), std::back_inserter(v));\n\
    \  assert_that(v.size() == 3);\n  assert_that(v[0].first == 'A');\n  assert_that(v[0].second\
    \ == 3);\n  assert_that(v[1].first == 'B');\n  assert_that(v[1].second == 2);\n\
    \  assert_that(v[2].first == 'C');\n  assert_that(v[2].second == 1);\n\n  s =\
    \ \"\";\n  v.clear();\n  tools::run_length(s.begin(), s.end(), std::back_inserter(v));\n\
    \  assert_that(v.size() == 0);\n\n  s = \"A\";\n  v.clear();\n  tools::run_length(s.begin(),\
    \ s.end(), std::back_inserter(v));\n  assert_that(v.size() == 1);\n  assert_that(v[0].first\
    \ == 'A');\n  assert_that(v[0].second == 1);\n\n  std::cout << \"Hello World\"\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/run_length.hpp
  isVerificationFile: true
  path: tests/run_length.test.cpp
  requiredBy: []
  timestamp: '2021-07-25 08:29:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/run_length.test.cpp
layout: document
redirect_from:
- /verify/tests/run_length.test.cpp
- /verify/tests/run_length.test.cpp.html
title: tests/run_length.test.cpp
---
