---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  - icon: ':heavy_check_mark:'
    path: tools/fill.hpp
    title: Fill a multi-dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/is_range.hpp
    title: Check whether T is a range type
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':heavy_check_mark:'
    path: tools/range_of_digit_products.hpp
    title: Range of digit products
  - icon: ':heavy_check_mark:'
    path: tools/resize.hpp
    title: Resize a multi-dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':heavy_check_mark:'
    path: tools/upper_bound.hpp
    title: std::upper_bound, but returns index
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
  bundledCode: "#line 1 \"tests/range_of_digit_products.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc208/tasks/abc208_e\"\n\n#include <cstdint>\n\
    #include <iostream>\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    #include <iterator>\n#line 1 \"tools/range_of_digit_products.hpp\"\n\n\n\n#line\
    \ 5 \"tools/range_of_digit_products.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <array>\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace tools {\n\n  template <typename M,\
    \ typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M& lhs, const\
    \ N& rhs);\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs);\n  \n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> floor(const M& lhs, const N& rhs) {\n\
    \    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs / rhs :\n      lhs < 0\
    \ && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n      lhs >= 0 && rhs <\
    \ 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs, -rhs);\n\
    \  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\
    \n#line 10 \"tools/range_of_digit_products.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  ::std::vector<T> range_of_digit_products(const T n) {\n    assert(0\
    \ <= n && n <= ::std::numeric_limits<T>::digits10);\n\n    ::std::vector<T> range;\n\
    \    if (n == 0) return range;\n    if (n > 1) range.push_back(0);\n\n    ::std::array<T,\
    \ 5> left;\n    left[0] = n;\n    for (T a = 0, pow6 = 1; a <= left[0]; ++a, pow6\
    \ *= 6) {\n      left[1] = left[0] - a;\n      for (T b = 0, pow2 = 1; b <= 3\
    \ * left[1]; ++b, pow2 *= 2) {\n        left[2] = left[1] - ::tools::ceil(b, 3);\n\
    \        for (T c = 0, pow3 = 1; c <= 2 * left[2]; ++c, pow3 *= 3) {\n       \
    \   left[3] = left[2] - ::tools::ceil(c, 2);\n          for (T d = 0, pow5 = 1;\
    \ d <= left[3]; ++d, pow5 *= 5) {\n            left[4] = left[3] - d;\n      \
    \      for (T e = 0, pow7 = 1; e <= left[4]; ++e, pow7 *= 7) {\n             \
    \ range.push_back(pow6 * pow2 * pow3 * pow5 * pow7);\n            }\n        \
    \  }\n        }\n      }\n    }\n\n    ::std::sort(range.begin(), range.end());\n\
    \    range.erase(::std::unique(range.begin(), range.end()), range.end());\n\n\
    \    return range;\n  }\n}\n\n\n#line 1 \"tools/resize.hpp\"\n\n\n\n#line 5 \"\
    tools/resize.hpp\"\n\n// Source: https://koyumeishi.hatenablog.com/entry/2016/02/01/152426\n\
    // License: unknown\n// Author: koyumeishi\n\nnamespace tools {\n  template <class\
    \ T, class Allocator, typename Head>\n  void resize(::std::vector<T, Allocator>&\
    \ vector, const Head& head) {\n    vector.resize(head);\n  }\n  template <class\
    \ T, class Allocator, typename Head, typename... Tail>\n  void resize(::std::vector<T,\
    \ Allocator>& vector, const Head& head, const Tail&... tail) {\n    vector.resize(head);\n\
    \    for (auto& child : vector) {\n      ::tools::resize(child, tail...);\n  \
    \  }\n  }\n}\n\n\n#line 1 \"tools/fill.hpp\"\n\n\n\n#line 1 \"tools/is_range.hpp\"\
    \n\n\n\n#line 6 \"tools/is_range.hpp\"\n#include <utility>\n\nnamespace tools\
    \ {\n  template <typename T>\n  class is_range {\n  private:\n    template <typename\
    \ U>\n    static auto check(U x) -> decltype(::std::begin(x), ::std::end(x), ::std::true_type{});\n\
    \    static ::std::false_type check(...);\n\n  public:\n    static const bool\
    \ value = decltype(check(::std::declval<T>()))::value;\n  };\n}\n\n\n#line 9 \"\
    tools/fill.hpp\"\n\nnamespace tools {\n  template <class T, class Allocator, typename\
    \ V>\n  auto fill(::std::vector<T, Allocator>& vector, const V& value) -> ::std::enable_if_t<!::tools::is_range<T>::value,\
    \ void> {\n    ::std::fill(::std::begin(vector), ::std::end(vector), value);\n\
    \  }\n  template <class T, class Allocator, typename V>\n  auto fill(::std::vector<T,\
    \ Allocator>& vector, const V& value) -> ::std::enable_if_t<::tools::is_range<T>::value,\
    \ void> {\n    for (auto& child : vector) {\n      ::tools::fill(child, value);\n\
    \    }\n  }\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 5 \"tools/ssize.hpp\"\
    \n#include <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr\
    \ auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\
    \n#line 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template <class\
    \ ForwardIterator, class T>\n  auto lower_bound(ForwardIterator first, ForwardIterator\
    \ last, const T& value) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 1 \"tools/upper_bound.hpp\"\n\n\n\n\
    #line 6 \"tools/upper_bound.hpp\"\n\nnamespace tools {\n\n  template <class ForwardIterator,\
    \ class T>\n  auto upper_bound(ForwardIterator first, ForwardIterator last, const\
    \ T& value) {\n    return ::std::distance(first, ::std::upper_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto upper_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::upper_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 15 \"tests/range_of_digit_products.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  std::vector<i64> N;\n  {\n    i64\
    \ n;\n    std::cin >> n;\n    while (n > 0) {\n      N.push_back(n % 10);\n  \
    \    n /= 10;\n    }\n    std::reverse(N.begin(), N.end());\n  }\n\n  i64 K;\n\
    \  std::cin >> K;\n\n  std::vector<i64> possible_products = tools::range_of_digit_products<i64>(std::min<i64>(N.size(),\
    \ 18));\n\n  std::vector<std::vector<std::vector<i64>>> dp;\n  tools::resize(dp,\
    \ N.size(), 2, possible_products.size());\n  tools::fill(dp, 0);\n  const int\
    \ STRICT = 0;\n  const int LOOSE = 1;\n\n  dp[0][STRICT][N[0]] = 1;\n  for (i64\
    \ d = 1; d < N[0]; ++d) {\n    dp[0][LOOSE][d] = 1;\n  }\n  for (i64 i = 0; i\
    \ + 1 < tools::ssize(N); ++i) {\n    for (i64 j = 0; j < tools::ssize(possible_products);\
    \ ++j) {\n      if (dp[i][STRICT][j] > 0) {\n        dp[i + 1][STRICT][tools::lower_bound(possible_products.begin(),\
    \ possible_products.end(), possible_products[j] * N[i + 1])] += dp[i][STRICT][j];\n\
    \        for (i64 d = 0; d < N[i + 1]; ++d) {\n          dp[i + 1][LOOSE][tools::lower_bound(possible_products.begin(),\
    \ possible_products.end(), possible_products[j] * d)] += dp[i][STRICT][j];\n \
    \       }\n      }\n      if (dp[i][LOOSE][j] > 0) {\n        for (i64 d = 0;\
    \ d < 10; ++d) {\n          dp[i + 1][LOOSE][tools::lower_bound(possible_products.begin(),\
    \ possible_products.end(), possible_products[j] * d)] += dp[i][LOOSE][j];\n  \
    \      }\n      }\n    }\n    for (i64 j = 1; j < 10; ++j) {\n      ++dp[i + 1][LOOSE][j];\n\
    \    }\n  }\n\n  i64 answer = 0;\n  for (const auto& dp_i : dp.back()) {\n   \
    \ answer += std::accumulate(dp_i.begin(), std::next(dp_i.begin(), tools::upper_bound(possible_products.begin(),\
    \ possible_products.end(), K)), i64(0));\n  }\n  std::cout << answer << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc208/tasks/abc208_e\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <numeric>\n#include <iterator>\n#include \"tools/range_of_digit_products.hpp\"\
    \n#include \"tools/resize.hpp\"\n#include \"tools/fill.hpp\"\n#include \"tools/ssize.hpp\"\
    \n#include \"tools/lower_bound.hpp\"\n#include \"tools/upper_bound.hpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::vector<i64> N;\n  {\n    i64 n;\n    std::cin >> n;\n    while (n > 0)\
    \ {\n      N.push_back(n % 10);\n      n /= 10;\n    }\n    std::reverse(N.begin(),\
    \ N.end());\n  }\n\n  i64 K;\n  std::cin >> K;\n\n  std::vector<i64> possible_products\
    \ = tools::range_of_digit_products<i64>(std::min<i64>(N.size(), 18));\n\n  std::vector<std::vector<std::vector<i64>>>\
    \ dp;\n  tools::resize(dp, N.size(), 2, possible_products.size());\n  tools::fill(dp,\
    \ 0);\n  const int STRICT = 0;\n  const int LOOSE = 1;\n\n  dp[0][STRICT][N[0]]\
    \ = 1;\n  for (i64 d = 1; d < N[0]; ++d) {\n    dp[0][LOOSE][d] = 1;\n  }\n  for\
    \ (i64 i = 0; i + 1 < tools::ssize(N); ++i) {\n    for (i64 j = 0; j < tools::ssize(possible_products);\
    \ ++j) {\n      if (dp[i][STRICT][j] > 0) {\n        dp[i + 1][STRICT][tools::lower_bound(possible_products.begin(),\
    \ possible_products.end(), possible_products[j] * N[i + 1])] += dp[i][STRICT][j];\n\
    \        for (i64 d = 0; d < N[i + 1]; ++d) {\n          dp[i + 1][LOOSE][tools::lower_bound(possible_products.begin(),\
    \ possible_products.end(), possible_products[j] * d)] += dp[i][STRICT][j];\n \
    \       }\n      }\n      if (dp[i][LOOSE][j] > 0) {\n        for (i64 d = 0;\
    \ d < 10; ++d) {\n          dp[i + 1][LOOSE][tools::lower_bound(possible_products.begin(),\
    \ possible_products.end(), possible_products[j] * d)] += dp[i][LOOSE][j];\n  \
    \      }\n      }\n    }\n    for (i64 j = 1; j < 10; ++j) {\n      ++dp[i + 1][LOOSE][j];\n\
    \    }\n  }\n\n  i64 answer = 0;\n  for (const auto& dp_i : dp.back()) {\n   \
    \ answer += std::accumulate(dp_i.begin(), std::next(dp_i.begin(), tools::upper_bound(possible_products.begin(),\
    \ possible_products.end(), K)), i64(0));\n  }\n  std::cout << answer << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/range_of_digit_products.hpp
  - tools/ceil.hpp
  - tools/detail/ceil_and_floor.hpp
  - tools/resize.hpp
  - tools/fill.hpp
  - tools/is_range.hpp
  - tools/ssize.hpp
  - tools/lower_bound.hpp
  - tools/upper_bound.hpp
  isVerificationFile: true
  path: tests/range_of_digit_products.test.cpp
  requiredBy: []
  timestamp: '2022-05-30 15:17:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/range_of_digit_products.test.cpp
layout: document
redirect_from:
- /verify/tests/range_of_digit_products.test.cpp
- /verify/tests/range_of_digit_products.test.cpp.html
title: tests/range_of_digit_products.test.cpp
---