---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/golden_section_search.hpp
    title: Golden section search
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-9
    PROBLEM: https://atcoder.jp/contests/abc292/tasks/abc292_f
    links:
    - https://atcoder.jp/contests/abc292/tasks/abc292_f
  bundledCode: "#line 1 \"tests/golden_section_search.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc292/tasks/abc292_f\"\n#define ERROR 1e-9\n\n\
    #include <iostream>\n#include <cmath>\n#include <algorithm>\n#include <iomanip>\n\
    #line 1 \"tools/golden_section_search.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <type_traits>\n#include <cassert>\n#line 8 \"tools/golden_section_search.hpp\"\
    \n#include <limits>\n#include <array>\n#line 11 \"tools/golden_section_search.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename F>\n  auto golden_section_search(const\
    \ T l, const T r, const F& f, const bool search_maximum) -> ::std::pair<T, ::std::decay_t<decltype(f(::std::declval<T>()))>>\
    \ {\n    assert(l <= r);\n\n    using V = ::std::decay_t<decltype(f(::std::declval<T>()))>;\n\
    \    const auto comp = [&](const V x, const V y) { return search_maximum ? x <\
    \ y : x > y; };\n    constexpr T phi = (::std::sqrt(T(5)) + T(1)) / T(2);\n  \
    \  constexpr T phi_inv = (::std::sqrt(T(5)) - T(1)) / T(2);\n    constexpr int\
    \ loop_count = static_cast<int>(::std::ceil(::std::numeric_limits<T>::digits /\
    \ ::std::log2(phi))) - 2;\n\n    ::std::array<::std::pair<T, V>, 4> search;\n\
    \    search[0] = ::std::make_pair(l, f(l));\n    search[3] = ::std::make_pair(r,\
    \ f(r));\n    T resolution = (r - l) * phi_inv;\n    search[2] = ::std::make_pair(l\
    \ + resolution, f(l + resolution));\n    resolution *= phi_inv;\n    search[1]\
    \ = ::std::make_pair(l + resolution, f(l + resolution));\n\n    for (int i = 0;\
    \ i < loop_count; ++i) {\n      if (comp(search[1].second, search[2].second))\
    \ {\n        search[0] = search[1];\n        search[1] = search[2];\n        resolution\
    \ *= phi_inv;\n        search[2] = ::std::make_pair(search[3].first - resolution,\
    \ f(search[3].first - resolution));\n      } else {\n        search[3] = search[2];\n\
    \        search[2] = search[1];\n        resolution *= phi_inv;\n        search[1]\
    \ = ::std::make_pair(search[0].first + resolution, f(search[0].first + resolution));\n\
    \      }\n    }\n\n    return *::std::max_element(search.begin(), search.end(),\
    \ [&](const auto& x, const auto& y) { return comp(x.second, y.second); });\n \
    \ }\n}\n\n\n#line 9 \"tests/golden_section_search.test.cpp\"\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  double\
    \ A, B;\n  std::cin >> A >> B;\n\n  constexpr auto pi = std::acos(-1);\n  static\
    \ const auto f = [&](const auto theta) { return std::min(B / std::cos(theta),\
    \ A / std::sin(pi / 3 + theta)); };\n\n  std::cout << std::fixed << std::setprecision(10)\
    \ << tools::golden_section_search(0.0, pi / 6, f, true).second << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc292/tasks/abc292_f\"\n#define\
    \ ERROR 1e-9\n\n#include <iostream>\n#include <cmath>\n#include <algorithm>\n\
    #include <iomanip>\n#include \"tools/golden_section_search.hpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  double\
    \ A, B;\n  std::cin >> A >> B;\n\n  constexpr auto pi = std::acos(-1);\n  static\
    \ const auto f = [&](const auto theta) { return std::min(B / std::cos(theta),\
    \ A / std::sin(pi / 3 + theta)); };\n\n  std::cout << std::fixed << std::setprecision(10)\
    \ << tools::golden_section_search(0.0, pi / 6, f, true).second << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/golden_section_search.hpp
  isVerificationFile: true
  path: tests/golden_section_search.test.cpp
  requiredBy: []
  timestamp: '2023-07-01 22:51:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/golden_section_search.test.cpp
layout: document
redirect_from:
- /verify/tests/golden_section_search.test.cpp
- /verify/tests/golden_section_search.test.cpp.html
title: tests/golden_section_search.test.cpp
---
