---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':heavy_check_mark:'
    path: tools/largest_rectangle_in_histogram.hpp
    title: Largest rectangle in histogram
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C
  bundledCode: "#line 1 \"tests/largest_rectangle_in_histogram.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C\"\n\n#include <iostream>\n\
    #include <vector>\n#line 1 \"tools/largest_rectangle_in_histogram.hpp\"\n\n\n\n\
    #include <iterator>\n#include <stack>\n#include <utility>\n#include <tuple>\n\
    #line 1 \"tools/chmax.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace tools {\n\
    \n  template <typename M, typename N>\n  bool chmax(M& lhs, const N& rhs) {\n\
    \    const bool updated = lhs < rhs;\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n\n#line 9 \"tools/largest_rectangle_in_histogram.hpp\"\n\
    \nnamespace tools {\n  template <typename InputIterator>\n  typename ::std::iterator_traits<InputIterator>::value_type\
    \ largest_rectangle_in_histogram(const InputIterator& begin, const InputIterator&\
    \ end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \n    T result = 0;\n    ::std::stack<::std::pair<T, T>> dp;\n    for (auto [i,\
    \ it, breaks] = ::std::make_tuple(0, begin, false); !breaks; ++i, breaks = it\
    \ == end, it = ::std::next(it, breaks ? 0 : 1)) {\n      const T v = it != end\
    \ ? *it : 0;\n      if (dp.empty() || dp.top().second < v) {\n        dp.emplace(i,\
    \ v);\n      } else if (dp.top().second > v) {\n        T leftmost;\n        while\
    \ (!dp.empty() && dp.top().second > v) {\n          leftmost = dp.top().first;\n\
    \          ::tools::chmax(result, dp.top().second * (i - dp.top().first));\n \
    \         dp.pop();\n        }\n        if (dp.empty() || dp.top().second < v)\
    \ {\n          dp.emplace(leftmost, v);\n        }\n      }\n    }\n\n    return\
    \ result;\n  }\n}\n\n\n#line 6 \"tests/largest_rectangle_in_histogram.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n  std::vector<ll> h(N);\n  for (ll& h_i : h) std::cin\
    \ >> h_i;\n  std::cout << tools::largest_rectangle_in_histogram(h.begin(), h.end())\
    \ << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"tools/largest_rectangle_in_histogram.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n  std::vector<ll> h(N);\n  for (ll& h_i : h) std::cin\
    \ >> h_i;\n  std::cout << tools::largest_rectangle_in_histogram(h.begin(), h.end())\
    \ << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/largest_rectangle_in_histogram.hpp
  - tools/chmax.hpp
  isVerificationFile: true
  path: tests/largest_rectangle_in_histogram.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/largest_rectangle_in_histogram.test.cpp
layout: document
redirect_from:
- /verify/tests/largest_rectangle_in_histogram.test.cpp
- /verify/tests/largest_rectangle_in_histogram.test.cpp.html
title: tests/largest_rectangle_in_histogram.test.cpp
---
