---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/digit_product_frequency.hpp
    title: Frequency table of digit products
  - icon: ':question:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':heavy_check_mark:'
    path: tools/resize.hpp
    title: Resize a multi-dimensional vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc208/tasks/abc208_e
    links:
    - https://atcoder.jp/contests/abc208/tasks/abc208_e
  bundledCode: "#line 1 \"tests/digit_product_frequency.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc208/tasks/abc208_e\"\n\n#include <iostream>\n\
    #include <numeric>\n#line 1 \"tools/digit_product_frequency.hpp\"\n\n\n\n#include\
    \ <map>\n#include <vector>\n#include <tuple>\n#include <cstddef>\n#include <array>\n\
    #include <algorithm>\n#line 1 \"tools/resize.hpp\"\n\n\n\n#line 7 \"tools/resize.hpp\"\
    \n#include <cassert>\n\nnamespace tools {\n  template <class T, class Allocator,\
    \ typename Head>\n  void resize(::std::vector<T, Allocator>& vector, const Head&\
    \ head) {\n    vector.resize(head);\n  }\n  template <class T, ::std::size_t N,\
    \ typename Head>\n  void resize([[maybe_unused]] ::std::array<T, N>& array, [[maybe_unused]]\
    \ const Head& head) {\n    assert(array.size() == static_cast<::std::size_t>(head));\n\
    \  }\n\n  template <class T, class Allocator, typename Head, typename... Tail>\n\
    \  void resize(::std::vector<T, Allocator>& vector, const Head& head, const Tail&...\
    \ tail);\n  template <class T, ::std::size_t N, typename Head, typename... Tail>\n\
    \  void resize(::std::array<T, N>& array, const Head& head, const Tail&... tail);\n\
    \n  template <class T, class Allocator, typename Head, typename... Tail>\n  void\
    \ resize(::std::vector<T, Allocator>& vector, const Head& head, const Tail&...\
    \ tail) {\n    vector.resize(head);\n    for (auto& child : vector) {\n      ::tools::resize(child,\
    \ tail...);\n    }\n  }\n  template <class T, ::std::size_t N, typename Head,\
    \ typename... Tail>\n  void resize(::std::array<T, N>& array, [[maybe_unused]]\
    \ const Head& head, const Tail&... tail) {\n    assert(array.size() == static_cast<::std::size_t>(head));\n\
    \    for (auto& child : array) {\n      ::tools::resize(child, tail...);\n   \
    \ }\n  }\n}\n\n\n#line 1 \"tools/less_by_first.hpp\"\n\n\n\n#include <utility>\n\
    \nnamespace tools {\n\n  class less_by_first {\n  public:\n    template <class\
    \ T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.first < y.first;\n    }\n  };\n}\n\n\n#line\
    \ 13 \"tools/digit_product_frequency.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  ::std::map<T, T> digit_product_frequency(const T n) {\n    if\
    \ (n <= 0) return ::std::map<T, T>{};\n\n    ::std::vector<::std::size_t> n_digits;\n\
    \    for (auto tmp = n; tmp > 0; tmp /= 10) {\n      n_digits.push_back(tmp %\
    \ 10);\n    }\n\n    using tuple = ::std::tuple<::std::size_t, ::std::size_t,\
    \ ::std::size_t, ::std::size_t>;\n    constexpr ::std::array<tuple, 10> diff =\
    \ {\n      tuple(0, 0, 0, 0),\n      tuple(0, 0, 0, 0),\n      tuple(1, 0, 0,\
    \ 0),\n      tuple(0, 1, 0, 0),\n      tuple(2, 0, 0, 0),\n      tuple(0, 0, 1,\
    \ 0),\n      tuple(1, 1, 0, 0),\n      tuple(0, 0, 0, 1),\n      tuple(3, 0, 0,\
    \ 0),\n      tuple(0, 2, 0, 0),\n    };\n\n    static const auto safe_ref = [](::std::vector<::std::vector<::std::vector<::std::vector<T>>>>&\
    \ vector, const ::std::size_t e2, const ::std::size_t e3, const ::std::size_t\
    \ e5, const ::std::size_t e7) -> T& {\n      vector.resize(::std::max(vector.size(),\
    \ e2 + 1));\n      vector[e2].resize(::std::max(vector[e2].size(), e3 + 1));\n\
    \      vector[e2][e3].resize(::std::max(vector[e2][e3].size(), e5 + 1));\n   \
    \   vector[e2][e3][e5].resize(::std::max(vector[e2][e3][e5].size(), e7 + 1));\n\
    \      return vector[e2][e3][e5][e7];\n    };\n\n    ::std::vector<::std::array<::std::vector<::std::vector<::std::vector<::std::vector<T>>>>,\
    \ 2>> dp(n_digits.size() + 1);\n    ::tools::resize(dp[0], 2, 1, 1, 1, 1);\n \
    \   dp[0][true][0][0][0][0] = 1;\n    dp[0][false][0][0][0][0] = 1;\n    for (::std::size_t\
    \ i = 0; i < n_digits.size(); ++i) {\n      for (::std::size_t e2 = 0; e2 < dp[i][true].size();\
    \ ++e2) {\n        for (::std::size_t e3 = 0; e3 < dp[i][true][e2].size(); ++e3)\
    \ {\n          for (::std::size_t e5 = 0; e5 < dp[i][true][e2][e3].size(); ++e5)\
    \ {\n            for (::std::size_t e7 = 0; e7 < dp[i][true][e2][e3][e5].size();\
    \ ++e7) {\n              if (dp[i][true][e2][e3][e5][e7] > 0 && n_digits[i] >\
    \ 0) {\n                const auto& [d2, d3, d5, d7] = diff[n_digits[i]];\n  \
    \              safe_ref(dp[i + 1][true], e2 + d2, e3 + d3, e5 + d5, e7 + d7) +=\
    \ dp[i][true][e2][e3][e5][e7];\n              }\n            }\n          }\n\
    \        }\n      }\n      for (::std::size_t e2 = 0; e2 < dp[i][false].size();\
    \ ++e2) {\n        for (::std::size_t e3 = 0; e3 < dp[i][false][e2].size(); ++e3)\
    \ {\n          for (::std::size_t e5 = 0; e5 < dp[i][false][e2][e3].size(); ++e5)\
    \ {\n            for (::std::size_t e7 = 0; e7 < dp[i][false][e2][e3][e5].size();\
    \ ++e7) {\n              if (dp[i][false][e2][e3][e5][e7] > 0) {\n           \
    \     for (::std::size_t d = 1; d < n_digits[i]; ++d) {\n                  const\
    \ auto& [d2, d3, d5, d7] = diff[d];\n                  safe_ref(dp[i + 1][true],\
    \ e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][false][e2][e3][e5][e7];\n     \
    \           }\n                for (::std::size_t d = 1; d <= 9; ++d) {\n    \
    \              const auto& [d2, d3, d5, d7] = diff[d];\n                  safe_ref(dp[i\
    \ + 1][false], e2 + d2, e3 + d3, e5 + d5, e7 + d7) += dp[i][false][e2][e3][e5][e7];\n\
    \                }\n              }\n            }\n          }\n        }\n \
    \     }\n    }\n\n    ::std::vector<::std::vector<::std::vector<::std::vector<T>>>>\
    \ answer;\n    for (::std::size_t i = n_digits.size(); i >= 1; --i) {\n      for\
    \ (::std::size_t e2 = 0; e2 < dp[i][i == n_digits.size()].size(); ++e2) {\n  \
    \      for (::std::size_t e3 = 0; e3 < dp[i][i == n_digits.size()][e2].size();\
    \ ++e3) {\n          for (::std::size_t e5 = 0; e5 < dp[i][i == n_digits.size()][e2][e3].size();\
    \ ++e5) {\n            for (::std::size_t e7 = 0; e7 < dp[i][i == n_digits.size()][e2][e3][e5].size();\
    \ ++e7) {\n              if (dp[i][i == n_digits.size()][e2][e3][e5][e7] > 0)\
    \ {\n                safe_ref(answer, e2, e3, e5, e7) += dp[i][i == n_digits.size()][e2][e3][e5][e7];\n\
    \              }\n            }\n          }\n        }\n      }\n    }\n\n  \
    \  ::std::vector<::std::pair<T, T>> freq;\n    {\n      ::std::size_t e2, e3,\
    \ e5, e7;\n      T p2, p3, p5, p7;\n      for (e2 = 0, p2 = 1; e2 < answer.size();\
    \ ++e2, p2 *= 2) {\n        for (e3 = 0, p3 = 1; e3 < answer[e2].size(); ++e3,\
    \ p3 *= 3) {\n          for (e5 = 0, p5 = 1; e5 < answer[e2][e3].size(); ++e5,\
    \ p5 *= 5) {\n            for (e7 = 0, p7 = 1; e7 < answer[e2][e3][e5].size();\
    \ ++e7, p7 *= 7) {\n              if (answer[e2][e3][e5][e7] > 0) {\n        \
    \        freq.emplace_back(p2 * p3 * p5 * p7, answer[e2][e3][e5][e7]);\n     \
    \         }\n            }\n          }\n        }\n      }\n    }\n\n    if (const\
    \ auto sum_of_positives = ::std::accumulate(freq.begin(), freq.end(), T(0), [](const\
    \ auto sum, const auto& pair) { return sum + pair.second; }); sum_of_positives\
    \ < n) {\n      freq.emplace_back(0, n - sum_of_positives);\n    }\n\n    ::std::sort(freq.begin(),\
    \ freq.end(), ::tools::less_by_first{});\n    return ::std::map<T, T>(freq.begin(),\
    \ freq.end());\n  }\n}\n\n\n#line 6 \"tests/digit_product_frequency.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, K;\n  std::cin >> N >> K;\n\n  const auto freq = tools::digit_product_frequency(N);\n\
    \  std::cout << ::std::accumulate(freq.begin(), freq.upper_bound(K), 0LL, [](const\
    \ auto sum, const auto& pair) { return sum + pair.second; }) << '\\n';\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc208/tasks/abc208_e\"\n\n\
    #include <iostream>\n#include <numeric>\n#include \"tools/digit_product_frequency.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, K;\n  std::cin >> N >> K;\n\n  const auto freq = tools::digit_product_frequency(N);\n\
    \  std::cout << ::std::accumulate(freq.begin(), freq.upper_bound(K), 0LL, [](const\
    \ auto sum, const auto& pair) { return sum + pair.second; }) << '\\n';\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/digit_product_frequency.hpp
  - tools/resize.hpp
  - tools/less_by_first.hpp
  isVerificationFile: true
  path: tests/digit_product_frequency.test.cpp
  requiredBy: []
  timestamp: '2024-03-20 00:34:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/digit_product_frequency.test.cpp
layout: document
redirect_from:
- /verify/tests/digit_product_frequency.test.cpp
- /verify/tests/digit_product_frequency.test.cpp.html
title: tests/digit_product_frequency.test.cpp
---
