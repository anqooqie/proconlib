---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cumsum2d.hpp
    title: 2D cumulative sum
  - icon: ':question:'
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
    \n\n#include <iostream>\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    #include <iterator>\n#line 1 \"tools/cumsum2d.hpp\"\n\n\n\n#include <cstddef>\n\
    #line 8 \"tools/cumsum2d.hpp\"\n#include <cassert>\n\nnamespace tools {\n\n  template\
    \ <typename G>\n  class cumsum2d {\n  private:\n    using T = typename G::T;\n\
    \    ::std::size_t height;\n    ::std::size_t width;\n    ::std::vector<T> preprocessed;\n\
    \n  public:\n    template <typename Range>\n    explicit cumsum2d(const Range&\
    \ range) {\n      const auto begin = ::std::begin(range);\n      const auto end\
    \ = ::std::end(range);\n      this->height = ::std::distance(begin, end);\n  \
    \    this->width = this->height == 0 ? 0 : ::std::distance(::std::begin(*begin),\
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
    namespace tools {\n  namespace group {\n    template <typename G>\n    struct\
    \ plus {\n      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n\
    \        return lhs + rhs;\n      }\n      static T e() {\n        return T(0);\n\
    \      }\n      static T inv(const T& v) {\n        return -v;\n      }\n    };\n\
    \n    template <typename G>\n    struct multiplies {\n      using T = G;\n   \
    \   static T op(const T& lhs, const T& rhs) {\n        return lhs * rhs;\n   \
    \   }\n      static T e() {\n        return T(1);\n      }\n      static T inv(const\
    \ T& v) {\n        return e() / v;\n      }\n    };\n\n    template <typename\
    \ G>\n    struct bit_xor {\n      using T = G;\n      static T op(const T& lhs,\
    \ const T& rhs) {\n        return lhs ^ rhs;\n      }\n      static T e() {\n\
    \        return T(0);\n      }\n      static T inv(const T& v) {\n        return\
    \ v;\n      }\n    };\n  }\n}\n\n\n#line 10 \"tests/cumsum2d.test.cpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll M, N, K;\n  std::cin >> M >> N >> K;\n  std::vector<std::string> map;\n\
    \  map.reserve(M);\n  std::copy_n(std::istream_iterator<std::string>(std::cin),\
    \ M, std::back_inserter(map));\n\n  std::vector<std::vector<ll>> J(M, std::vector<ll>(N,\
    \ 0));\n  std::vector<std::vector<ll>> O(M, std::vector<ll>(N, 0));\n  std::vector<std::vector<ll>>\
    \ I(M, std::vector<ll>(N, 0));\n  for (ll y = 0; y < M; ++y) {\n    for (ll x\
    \ = 0; x < N; ++x) {\n      switch (map[y][x]) {\n      case 'J':\n        ++J[y][x];\n\
    \        break;\n      case 'O':\n        ++O[y][x];\n        break;\n      case\
    \ 'I':\n        ++I[y][x];\n        break;\n      }\n    }\n  }\n\n  tools::cumsum2d<tools::group::plus<ll>>\
    \ J_cumsum(J);\n  tools::cumsum2d<tools::group::plus<ll>> O_cumsum(O);\n  tools::cumsum2d<tools::group::plus<ll>>\
    \ I_cumsum(I);\n\n  for (ll i = 0; i < K; ++i) {\n    ll a, b, c, d;\n    std::cin\
    \ >> a >> b >> c >> d;\n    --a;\n    --b;\n    std::cout << J_cumsum.query(a,\
    \ c, b, d) << ' ' << O_cumsum.query(a, c, b, d) << ' ' << I_cumsum.query(a, c,\
    \ b, d) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <string>\n#include <algorithm>\n#include\
    \ <iterator>\n#include \"tools/cumsum2d.hpp\"\n#include \"tools/group.hpp\"\n\n\
    using ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll M, N, K;\n  std::cin >> M >> N >> K;\n  std::vector<std::string> map;\n\
    \  map.reserve(M);\n  std::copy_n(std::istream_iterator<std::string>(std::cin),\
    \ M, std::back_inserter(map));\n\n  std::vector<std::vector<ll>> J(M, std::vector<ll>(N,\
    \ 0));\n  std::vector<std::vector<ll>> O(M, std::vector<ll>(N, 0));\n  std::vector<std::vector<ll>>\
    \ I(M, std::vector<ll>(N, 0));\n  for (ll y = 0; y < M; ++y) {\n    for (ll x\
    \ = 0; x < N; ++x) {\n      switch (map[y][x]) {\n      case 'J':\n        ++J[y][x];\n\
    \        break;\n      case 'O':\n        ++O[y][x];\n        break;\n      case\
    \ 'I':\n        ++I[y][x];\n        break;\n      }\n    }\n  }\n\n  tools::cumsum2d<tools::group::plus<ll>>\
    \ J_cumsum(J);\n  tools::cumsum2d<tools::group::plus<ll>> O_cumsum(O);\n  tools::cumsum2d<tools::group::plus<ll>>\
    \ I_cumsum(I);\n\n  for (ll i = 0; i < K; ++i) {\n    ll a, b, c, d;\n    std::cin\
    \ >> a >> b >> c >> d;\n    --a;\n    --b;\n    std::cout << J_cumsum.query(a,\
    \ c, b, d) << ' ' << O_cumsum.query(a, c, b, d) << ' ' << I_cumsum.query(a, c,\
    \ b, d) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/cumsum2d.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/cumsum2d.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cumsum2d.test.cpp
layout: document
redirect_from:
- /verify/tests/cumsum2d.test.cpp
- /verify/tests/cumsum2d.test.cpp.html
title: tests/cumsum2d.test.cpp
---
