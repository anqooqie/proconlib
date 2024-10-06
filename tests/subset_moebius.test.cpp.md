---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':heavy_check_mark:'
    path: tools/subset_moebius.hpp
    title: tools/subset_moebius.hpp
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
  bundledCode: "#line 1 \"tests/subset_moebius.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <iterator>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that_impl(cond,\
    \ file, line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' <<\
    \ line << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\\
    n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/subset_moebius.hpp\"\n\n\n\n#line 6 \"tools/subset_moebius.hpp\"\n#include\
    \ <algorithm>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 8 \"tools/subset_moebius.hpp\"\
    \n\nnamespace tools {\n  template <typename RandomAccessIterator>\n  void subset_moebius(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end) {\n    const int\
    \ N = end - begin;\n\n    for (int w = 0; ::tools::pow2(w) < N; ++w) {\n     \
    \ for (int i = 0; ; i += ::tools::pow2(w)) {\n        for (; !((i >> w) & 1);\
    \ ++i) {\n          if (!(i + ::tools::pow2(w) < N)) goto NEXT_W;\n          begin[i\
    \ + ::tools::pow2(w)] -= begin[i];\n        }\n      }\n    NEXT_W:\n      ;\n\
    \    }\n  }\n\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void subset_moebius(const InputIterator begin, const InputIterator end, const\
    \ OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> b(begin, end);\n    ::tools::subset_moebius(b.begin(), b.end());\n\
    \    ::std::move(b.begin(), b.end(), result);\n  }\n}\n\n\n#line 8 \"tests/subset_moebius.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  for (int N = 0; N <= 20; ++N) {\n    std::vector<int> a(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n      a[i] = 1 << i;\n    }\n\n    std::vector<int> b(N,\
    \ 0);\n    for (int i = 0; i < N; ++i) {\n      for (int j = 0; j < N; ++j) {\n\
    \        if ((i | j) == i) b[i] += a[j];\n      }\n    }\n\n    std::vector<int>\
    \ actual_a;\n    tools::subset_moebius(b.begin(), b.end(), std::back_inserter(actual_a));\n\
    \    assert_that(actual_a == a);\n\n    tools::subset_moebius(b.begin(), b.end());\n\
    \    assert_that(b == a);\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <iterator>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/subset_moebius.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  for (int N = 0; N <= 20; ++N) {\n\
    \    std::vector<int> a(N);\n    for (int i = 0; i < N; ++i) {\n      a[i] = 1\
    \ << i;\n    }\n\n    std::vector<int> b(N, 0);\n    for (int i = 0; i < N; ++i)\
    \ {\n      for (int j = 0; j < N; ++j) {\n        if ((i | j) == i) b[i] += a[j];\n\
    \      }\n    }\n\n    std::vector<int> actual_a;\n    tools::subset_moebius(b.begin(),\
    \ b.end(), std::back_inserter(actual_a));\n    assert_that(actual_a == a);\n\n\
    \    tools::subset_moebius(b.begin(), b.end());\n    assert_that(b == a);\n  }\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/subset_moebius.hpp
  - tools/pow2.hpp
  isVerificationFile: true
  path: tests/subset_moebius.test.cpp
  requiredBy: []
  timestamp: '2024-10-07 00:03:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/subset_moebius.test.cpp
layout: document
redirect_from:
- /verify/tests/subset_moebius.test.cpp
- /verify/tests/subset_moebius.test.cpp.html
title: tests/subset_moebius.test.cpp
---
