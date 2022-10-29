---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/logn_integer_partition.hpp
    title: Multiset $S$ such that $\{S' \subseteq S | \sum_{x \in S'} x\} = \{0, 1,
      \ldots, N\}$ and $|S| = O(\log N)$
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
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
  bundledCode: "#line 1 \"tests/logn_integer_partition.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n#include <iostream>\n\
    #include <vector>\n#include <cstddef>\n#include <algorithm>\n#include <numeric>\n\
    #line 1 \"tools/logn_integer_partition.hpp\"\n\n\n\n#line 5 \"tools/logn_integer_partition.hpp\"\
    \n#include <cassert>\n\nnamespace tools {\n  template <typename T>\n  ::std::vector<T>\
    \ logn_integer_partition(T n) {\n    assert(n >= 0);\n    ::std::vector<T> res;\n\
    \    for (T pow2 = 1; pow2 < n; n -= pow2, pow2 *= 2) {\n      res.push_back(pow2);\n\
    \    }\n    if (n > 0) res.push_back(n);\n    return res;\n  }\n}\n\n\n#line 1\
    \ \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/pow2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 11 \"tests/logn_integer_partition.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  for (int n = 0; n < 32; ++n) {\n    const auto parts = tools::logn_integer_partition(n);\n\
    \n    std::vector<int> sumset;\n    for (std::size_t state = 0; state < tools::pow2(parts.size());\
    \ ++state) {\n      int sum = 0;\n      for (std::size_t i = 0; i < parts.size();\
    \ ++i) {\n        if (state & (1 << i)) {\n          sum += parts[i];\n      \
    \  }\n      }\n      sumset.push_back(sum);\n    }\n    std::sort(sumset.begin(),\
    \ sumset.end());\n    sumset.erase(std::unique(sumset.begin(), sumset.end()),\
    \ sumset.end());\n\n    std::vector<int> expected(n + 1);\n    std::iota(expected.begin(),\
    \ expected.end(), 0);\n\n    assert_that(sumset == expected);\n  }\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <cstddef>\n#include <algorithm>\n\
    #include <numeric>\n#include \"tools/logn_integer_partition.hpp\"\n#include \"\
    tools/pow2.hpp\"\n#include \"tools/assert_that.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  for (int n = 0; n < 32; ++n) {\n\
    \    const auto parts = tools::logn_integer_partition(n);\n\n    std::vector<int>\
    \ sumset;\n    for (std::size_t state = 0; state < tools::pow2(parts.size());\
    \ ++state) {\n      int sum = 0;\n      for (std::size_t i = 0; i < parts.size();\
    \ ++i) {\n        if (state & (1 << i)) {\n          sum += parts[i];\n      \
    \  }\n      }\n      sumset.push_back(sum);\n    }\n    std::sort(sumset.begin(),\
    \ sumset.end());\n    sumset.erase(std::unique(sumset.begin(), sumset.end()),\
    \ sumset.end());\n\n    std::vector<int> expected(n + 1);\n    std::iota(expected.begin(),\
    \ expected.end(), 0);\n\n    assert_that(sumset == expected);\n  }\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/logn_integer_partition.hpp
  - tools/pow2.hpp
  - tools/assert_that.hpp
  isVerificationFile: true
  path: tests/logn_integer_partition.test.cpp
  requiredBy: []
  timestamp: '2022-10-15 20:30:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/logn_integer_partition.test.cpp
layout: document
redirect_from:
- /verify/tests/logn_integer_partition.test.cpp
- /verify/tests/logn_integer_partition.test.cpp.html
title: tests/logn_integer_partition.test.cpp
---
