---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/rational_binary_search.hpp
    title: Rational binary search
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rational_approximation
    links:
    - https://judge.yosupo.jp/problem/rational_approximation
  bundledCode: "#line 1 \"tests/rational_binary_search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rational_approximation\"\n\n#include <iostream>\n\
    #include <tuple>\n#include <utility>\n#line 1 \"tools/rational_binary_search.hpp\"\
    \n\n\n\n#line 5 \"tools/rational_binary_search.hpp\"\n#include <cassert>\n\nnamespace\
    \ tools {\n  template <typename T, typename F>\n  ::std::tuple<T, T, T, T> rational_binary_search(const\
    \ T& p1, const T& q1, const T& p2, const T& q2, const F& f, const T& N) {\n  \
    \  assert(q1 >= T(0));\n    assert(q2 >= T(0));\n    assert(N > T(0));\n    assert(p1\
    \ * q2 < p2 * q1);\n    const bool f1 = f(p1, q1);\n    const bool f2 = f(p2,\
    \ q2);\n    assert(f1 != f2);\n    const auto g = [&](const T& p, const T& q)\
    \ {\n      assert(q > T(0));\n      if (p * q1 < p1 * q) return f1;\n      if\
    \ (p2 * q < p * q2) return f2;\n      return f(p, q);\n    };\n\n    bool d =\
    \ g(T(0), T(1)) == f1;\n    T p3, q3, p4, q4;\n    if (d) {\n      p3 = T(0);\n\
    \      q3 = T(1);\n      p4 = T(1);\n      q4 = T(0);\n    } else {\n      p3\
    \ = T(-1);\n      q3 = T(0);\n      p4 = T(0);\n      q4 = T(1);\n    }\n\n  \
    \  while (q3 <= N - q4) {\n      if (d) {\n        T ng(1);\n        if (q4 ==\
    \ T(0)) {\n          for (; g(p3 + ng * p4, q3) == f1; ng *= T(2));\n        }\
    \ else {\n          const T max = (N - q3) / q4;\n          for (; ng <= max &&\
    \ g(p3 + ng * p4, q3 + ng * q4) == f1; ng = (ng == max ? ng + T(1) : ng <= max\
    \ / T(2) ? T(2) * ng : max));\n          if (ng == max + T(1)) {\n           \
    \ --ng;\n            p3 += ng * p4;\n            q3 += ng * q4;\n            break;\n\
    \          }\n        }\n        T ok(0);\n        while (ng - ok > T(1)) {\n\
    \          const auto mid = ok + (ng - ok) / T(2);\n          if (g(p3 + mid *\
    \ p4, q3 + mid * q4) == f1) {\n            ok = mid;\n          } else {\n   \
    \         ng = mid;\n          }\n        }\n        ::std::tie(p3, q3, p4, q4)\
    \ = ::std::make_tuple(p3 + ok * p4, q3 + ok * q4, p3 + ng * p4, q3 + ng * q4);\n\
    \      } else {\n        T ng(1);\n        if (q3 == T(0)) {\n          for (;\
    \ g(ng * p3 + p4, q4) == f2; ng *= T(2));\n        } else {\n          const T\
    \ max = (N - q4) / q3;\n          for (; ng <= max && g(ng * p3 + p4, ng * q3\
    \ + q4) == f2; ng = (ng == max ? ng + T(1) : ng <= max / T(2) ? T(2) * ng : max));\n\
    \          if (ng == max + T(1)) {\n            --ng;\n            p4 += ng *\
    \ p3;\n            q4 += ng * q3;\n            break;\n          }\n        }\n\
    \        T ok(0);\n        while (ng - ok > T(1)) {\n          const auto mid\
    \ = ok + (ng - ok) / T(2);\n          if (g(mid * p3 + p4, mid * q3 + q4) == f2)\
    \ {\n            ok = mid;\n          } else {\n            ng = mid;\n      \
    \    }\n        }\n        ::std::tie(p3, q3, p4, q4) = ::std::make_tuple(ng *\
    \ p3 + p4, ng * q3 + q4, ok * p3 + p4, ok * q3 + q4);\n      }\n      d = !d;\n\
    \    }\n\n    return ::std::make_tuple(p3, q3, p4, q4);\n  }\n}\n\n\n#line 7 \"\
    tests/rational_binary_search.test.cpp\"\n\nusing ll = long long;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  int\
    \ T;\n  std::cin >> T;\n  for (int t = 0; t < T; ++t) {\n    ll N, x, y;\n   \
    \ std::cin >> N >> x >> y;\n    if (x < y) {\n      auto [p1, q1, p2, q2] = tools::rational_binary_search(0LL,\
    \ 1LL, 1LL, 0LL, [&](const auto& p, const auto& q) { return p * y <= x * q; },\
    \ N);\n      if (p1 * y == x * q1) std::tie(p2, q2) = std::make_pair(p1, q1);\n\
    \      std::cout << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << '\\n';\n    }\
    \ else {\n      auto [q2, p2, q1, p1] = tools::rational_binary_search(0LL, 1LL,\
    \ 1LL, 0LL, [&](const auto& q, const auto& p) { return q * x <= y * p; }, N);\n\
    \      if (q2 * x == y * p2) std::tie(p1, q1) = std::make_pair(p2, q2);\n    \
    \  std::cout << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << '\\n';\n    }\n \
    \ }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rational_approximation\"\
    \n\n#include <iostream>\n#include <tuple>\n#include <utility>\n#include \"tools/rational_binary_search.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int T;\n  std::cin >> T;\n  for (int t = 0; t < T; ++t) {\n    ll N, x, y;\n\
    \    std::cin >> N >> x >> y;\n    if (x < y) {\n      auto [p1, q1, p2, q2] =\
    \ tools::rational_binary_search(0LL, 1LL, 1LL, 0LL, [&](const auto& p, const auto&\
    \ q) { return p * y <= x * q; }, N);\n      if (p1 * y == x * q1) std::tie(p2,\
    \ q2) = std::make_pair(p1, q1);\n      std::cout << p1 << ' ' << q1 << ' ' <<\
    \ p2 << ' ' << q2 << '\\n';\n    } else {\n      auto [q2, p2, q1, p1] = tools::rational_binary_search(0LL,\
    \ 1LL, 1LL, 0LL, [&](const auto& q, const auto& p) { return q * x <= y * p; },\
    \ N);\n      if (q2 * x == y * p2) std::tie(p1, q1) = std::make_pair(p2, q2);\n\
    \      std::cout << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << '\\n';\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/rational_binary_search.hpp
  isVerificationFile: true
  path: tests/rational_binary_search.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 15:33:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/rational_binary_search.test.cpp
layout: document
redirect_from:
- /verify/tests/rational_binary_search.test.cpp
- /verify/tests/rational_binary_search.test.cpp.html
title: tests/rational_binary_search.test.cpp
---
