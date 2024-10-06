---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/subset_moebius.test.cpp
    title: tests/subset_moebius.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/subset_moebius.hpp\"\n\n\n\n#include <iterator>\n\
    #include <vector>\n#include <algorithm>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#include <cstddef>\n\nnamespace tools {\n\n  template <typename\
    \ T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n  constexpr T pow2(const T x) {\n    return static_cast<T>(1) <<\
    \ x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
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
    \    ::std::move(b.begin(), b.end(), result);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SUBSET_MOEBIUS_HPP\n#define TOOLS_SUBSET_MOEBIUS_HPP\n\n#include\
    \ <iterator>\n#include <vector>\n#include <algorithm>\n#include \"tools/pow2.hpp\"\
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
    \    ::std::move(b.begin(), b.end(), result);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/subset_moebius.hpp
  requiredBy: []
  timestamp: '2024-10-07 00:03:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/subset_moebius.test.cpp
documentation_of: tools/subset_moebius.hpp
layout: document
redirect_from:
- /library/tools/subset_moebius.hpp
- /library/tools/subset_moebius.hpp.html
title: tools/subset_moebius.hpp
---
