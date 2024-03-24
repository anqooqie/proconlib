---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':question:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/next_matching.hpp
    title: Enumerate all matchings
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc236/tasks/abc236_d
    links:
    - https://atcoder.jp/contests/abc236/tasks/abc236_d
  bundledCode: "#line 1 \"tests/next_matching.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_d\"\
    \n\n#include <iostream>\n#include <vector>\n#include <numeric>\n#include <limits>\n\
    #line 1 \"tools/chmax.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/cmp_less.hpp\"\
    \n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T, typename U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n\
    \    using UT = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n\
    \    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/chmax.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmax(M& lhs, const N& rhs) {\n    bool updated;\n\
    \    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>) {\n   \
    \   updated = ::tools::cmp_less(lhs, rhs);\n    } else {\n      updated = lhs\
    \ < rhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 1 \"tools/next_matching.hpp\"\n\n\n\n#include <iterator>\n#include <cassert>\n\
    #include <algorithm>\n\nnamespace tools {\n  template <typename RandomAccessIterator>\n\
    \  bool next_matching(RandomAccessIterator begin, RandomAccessIterator end) {\n\
    \    const auto N = ::std::distance(begin, end);\n    // assert(::tools::mex(begin,\
    \ end) == N);\n    if (N <= 2) return false;\n\n    auto l = (N - 2) / 2 * 2;\n\
    \    for (; l > 0 && begin[l - 1] > begin[l + 1]; l -= 2);\n    ::std::sort(::std::next(begin,\
    \ l), ::std::prev(end, N % 2));\n\n    if (l == 0) {\n      if (N % 2 == 0) return\
    \ false;\n      if (begin[N - 1] == 0) {\n        ::std::rotate(begin, ::std::prev(end),\
    \ end);\n        return false;\n      }\n      ::std::iter_swap(::std::next(begin,\
    \ begin[N - 1] - 1), ::std::prev(end));\n      return true;\n    }\n\n    ::std::iter_swap(::std::next(begin,\
    \ l - 1), ::std::upper_bound(::std::next(begin, l), ::std::prev(end, N % 2), begin[l\
    \ - 1]));\n    return true;\n  }\n}\n\n\n#line 9 \"tests/next_matching.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n\n  auto A = std::vector(2 * N, std::vector<ll>(2\
    \ * N));\n  for (ll i = 0; i < 2 * N; ++i) {\n    for (ll j = i + 1; j < 2 * N;\
    \ ++j) {\n      std::cin >> A[i][j];\n      A[j][i] = A[i][j];\n    }\n  }\n\n\
    \  std::vector<ll> pattern(2 * N);\n  std::iota(pattern.begin(), pattern.end(),\
    \ 0);\n\n  ll answer = std::numeric_limits<int>::min();\n  do {\n    ll possible_answer\
    \ = 0;\n    for (ll i = 0; i < 2 * N; i += 2) {\n      possible_answer ^= A[pattern[i]][pattern[i\
    \ + 1]];\n    }\n    tools::chmax(answer, possible_answer);\n  } while (tools::next_matching(pattern.begin(),\
    \ pattern.end()));\n\n  std::cout << answer << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_d\"\n\n\
    #include <iostream>\n#include <vector>\n#include <numeric>\n#include <limits>\n\
    #include \"tools/chmax.hpp\"\n#include \"tools/next_matching.hpp\"\n\nusing ll\
    \ = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n\n  auto A = std::vector(2 * N, std::vector<ll>(2\
    \ * N));\n  for (ll i = 0; i < 2 * N; ++i) {\n    for (ll j = i + 1; j < 2 * N;\
    \ ++j) {\n      std::cin >> A[i][j];\n      A[j][i] = A[i][j];\n    }\n  }\n\n\
    \  std::vector<ll> pattern(2 * N);\n  std::iota(pattern.begin(), pattern.end(),\
    \ 0);\n\n  ll answer = std::numeric_limits<int>::min();\n  do {\n    ll possible_answer\
    \ = 0;\n    for (ll i = 0; i < 2 * N; i += 2) {\n      possible_answer ^= A[pattern[i]][pattern[i\
    \ + 1]];\n    }\n    tools::chmax(answer, possible_answer);\n  } while (tools::next_matching(pattern.begin(),\
    \ pattern.end()));\n\n  std::cout << answer << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/chmax.hpp
  - tools/cmp_less.hpp
  - tools/next_matching.hpp
  isVerificationFile: true
  path: tests/next_matching.test.cpp
  requiredBy: []
  timestamp: '2024-03-24 19:16:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/next_matching.test.cpp
layout: document
redirect_from:
- /verify/tests/next_matching.test.cpp
- /verify/tests/next_matching.test.cpp.html
title: tests/next_matching.test.cpp
---
