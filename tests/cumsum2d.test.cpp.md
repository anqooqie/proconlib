---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cumsum2d.hpp
    title: 2D cumulative sum
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0560
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0560
  bundledCode: "#line 1 \"tests/cumsum2d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <string>\n\
    #include <algorithm>\n#include <iterator>\n#line 1 \"tools/cumsum2d.hpp\"\n\n\n\
    \n#line 6 \"tools/cumsum2d.hpp\"\n#include <cstddef>\n#include <utility>\n\nnamespace\
    \ tools {\n\n  template <typename G>\n  class cumsum2d {\n  private:\n    using\
    \ T = typename G::T;\n    ::std::vector<::std::vector<T>> preprocessed;\n\n  public:\n\
    \    template <typename OuterIterator>\n    cumsum2d(const OuterIterator& begin,\
    \ const OuterIterator& end) :\n      preprocessed(\n        ::std::distance(begin,\
    \ end) + 1,\n        ::std::vector<T>((begin == end ? 0 : ::std::distance(::std::begin(*begin),\
    \ ::std::end(*begin))) + 1, G::e())\n      )\n    {\n      const ::std::size_t\
    \ height = ::std::distance(begin, end);\n      const ::std::size_t width = begin\
    \ == end ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin));\n  \
    \    using InnerIterator = decltype(::std::begin(::std::declval<typename ::std::iterator_traits<OuterIterator>::value_type>()));\n\
    \n      {\n        OuterIterator it1 = begin;\n        for (::std::size_t y =\
    \ 0; y < height; ++y, ++it1) {\n          InnerIterator it2 = ::std::begin(*it1);\n\
    \          for (::std::size_t x = 0; x < width; ++x, ++it2) {\n            this->preprocessed[y\
    \ + 1][x + 1] = G::op(this->preprocessed[y + 1][x], *it2);\n          }\n    \
    \    }\n      }\n      for (::std::size_t x = 0; x < width; ++x) {\n        for\
    \ (::std::size_t y = 0; y < height; ++y) {\n          this->preprocessed[y + 1][x\
    \ + 1] = G::op(this->preprocessed[y][x + 1], this->preprocessed[y + 1][x + 1]);\n\
    \        }\n      }\n    }\n\n    T query(const ::std::size_t x1, const ::std::size_t\
    \ y1, const ::std::size_t x2, const ::std::size_t y2) const {\n      T tmp = G::op(this->preprocessed[y2][x2],\
    \ G::inv(this->preprocessed[y2][x1]));\n      tmp = G::op(tmp, G::inv(this->preprocessed[y1][x2]));\n\
    \      return G::op(tmp, this->preprocessed[y1][x1]);\n    }\n  };\n}\n\n\n#line\
    \ 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace group {\n    template\
    \ <typename Type>\n    struct plus {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return lhs + rhs;\n      }\n      static T e()\
    \ {\n        return T(0);\n      }\n      static T inv(const T v) {\n        return\
    \ -v;\n      }\n    };\n\n    template <typename Type>\n    struct bit_xor {\n\
    \      using T = Type;\n      static T op(const T lhs, const T rhs) {\n      \
    \  return lhs ^ rhs;\n      }\n      static T e() {\n        return T(0);\n  \
    \    }\n      static T inv(const T v) {\n        return v;\n      }\n    };\n\
    \  }\n}\n\n\n#line 11 \"tests/cumsum2d.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 M, N, K;\n  std::cin >> M >> N >> K;\n  std::vector<std::string> map;\n\
    \  map.reserve(M);\n  std::copy_n(std::istream_iterator<std::string>(std::cin),\
    \ M, std::back_inserter(map));\n\n  std::vector<std::vector<i64>> J(M, std::vector<i64>(N,\
    \ 0));\n  std::vector<std::vector<i64>> O(M, std::vector<i64>(N, 0));\n  std::vector<std::vector<i64>>\
    \ I(M, std::vector<i64>(N, 0));\n  for (i64 y = 0; y < M; ++y) {\n    for (i64\
    \ x = 0; x < N; ++x) {\n      switch (map[y][x]) {\n      case 'J':\n        ++J[y][x];\n\
    \        break;\n      case 'O':\n        ++O[y][x];\n        break;\n      case\
    \ 'I':\n        ++I[y][x];\n        break;\n      }\n    }\n  }\n\n  tools::cumsum2d<tools::group::plus<i64>>\
    \ J_cumsum(J.begin(), J.end());\n  tools::cumsum2d<tools::group::plus<i64>> O_cumsum(O.begin(),\
    \ O.end());\n  tools::cumsum2d<tools::group::plus<i64>> I_cumsum(I.begin(), I.end());\n\
    \n  for (i64 i = 0; i < K; ++i) {\n    i64 a, b, c, d;\n    std::cin >> a >> b\
    \ >> c >> d;\n    --a;\n    --b;\n    std::cout << J_cumsum.query(b, a, d, c)\
    \ << ' ' << O_cumsum.query(b, a, d, c) << ' ' << I_cumsum.query(b, a, d, c) <<\
    \ '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n#include <string>\n#include\
    \ <algorithm>\n#include <iterator>\n#include \"tools/cumsum2d.hpp\"\n#include\
    \ \"tools/group.hpp\"\n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 M, N, K;\n  std::cin >> M >>\
    \ N >> K;\n  std::vector<std::string> map;\n  map.reserve(M);\n  std::copy_n(std::istream_iterator<std::string>(std::cin),\
    \ M, std::back_inserter(map));\n\n  std::vector<std::vector<i64>> J(M, std::vector<i64>(N,\
    \ 0));\n  std::vector<std::vector<i64>> O(M, std::vector<i64>(N, 0));\n  std::vector<std::vector<i64>>\
    \ I(M, std::vector<i64>(N, 0));\n  for (i64 y = 0; y < M; ++y) {\n    for (i64\
    \ x = 0; x < N; ++x) {\n      switch (map[y][x]) {\n      case 'J':\n        ++J[y][x];\n\
    \        break;\n      case 'O':\n        ++O[y][x];\n        break;\n      case\
    \ 'I':\n        ++I[y][x];\n        break;\n      }\n    }\n  }\n\n  tools::cumsum2d<tools::group::plus<i64>>\
    \ J_cumsum(J.begin(), J.end());\n  tools::cumsum2d<tools::group::plus<i64>> O_cumsum(O.begin(),\
    \ O.end());\n  tools::cumsum2d<tools::group::plus<i64>> I_cumsum(I.begin(), I.end());\n\
    \n  for (i64 i = 0; i < K; ++i) {\n    i64 a, b, c, d;\n    std::cin >> a >> b\
    \ >> c >> d;\n    --a;\n    --b;\n    std::cout << J_cumsum.query(b, a, d, c)\
    \ << ' ' << O_cumsum.query(b, a, d, c) << ' ' << I_cumsum.query(b, a, d, c) <<\
    \ '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/cumsum2d.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/cumsum2d.test.cpp
  requiredBy: []
  timestamp: '2021-11-12 22:35:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cumsum2d.test.cpp
layout: document
redirect_from:
- /verify/tests/cumsum2d.test.cpp
- /verify/tests/cumsum2d.test.cpp.html
title: tests/cumsum2d.test.cpp
---
