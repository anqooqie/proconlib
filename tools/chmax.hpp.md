---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/largest_rectangle_in_histogram.hpp
    title: Largest rectangle in histogram
  - icon: ':heavy_check_mark:'
    path: tools/longest_common_substring.hpp
    title: Longest common substring
  - icon: ':heavy_check_mark:'
    path: tools/suffix_array.hpp
    title: Wrapper of atcoder::suffix_array and atcoder::lcp_array
  - icon: ':heavy_check_mark:'
    path: tools/zero_one_knapsack.hpp
    title: 0-1 knapsack problem
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cartesian_tree/interval.test.cpp
    title: tests/cartesian_tree/interval.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/largest_rectangle_in_histogram.test.cpp
    title: tests/largest_rectangle_in_histogram.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/longest_common_substring.test.cpp
    title: tests/longest_common_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/next_matching.test.cpp
    title: tests/next_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/suffix_array.test.cpp
    title: tests/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
    title: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
    title: tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
    title: tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/chmax.hpp\"\n\n\n\n#include <type_traits>\n#line 1\
    \ \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const T t,\
    \ const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 6 \"tools/chmax.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmax(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(lhs, rhs);\n    } else {\n      updated\
    \ = lhs < rhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n"
  code: "#ifndef TOOLS_CHMAX_HPP\n#define TOOLS_CHMAX_HPP\n\n#include <type_traits>\n\
    #include \"tools/cmp_less.hpp\"\n\nnamespace tools {\n\n  template <typename M,\
    \ typename N>\n  bool chmax(M& lhs, const N& rhs) {\n    bool updated;\n    if\
    \ constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>) {\n      updated\
    \ = ::tools::cmp_less(lhs, rhs);\n    } else {\n      updated = lhs < rhs;\n \
    \   }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/cmp_less.hpp
  isVerificationFile: false
  path: tools/chmax.hpp
  requiredBy:
  - tools/largest_rectangle_in_histogram.hpp
  - tools/suffix_array.hpp
  - tools/longest_common_substring.hpp
  - tools/zero_one_knapsack.hpp
  timestamp: '2024-03-24 19:16:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cartesian_tree/interval.test.cpp
  - tests/next_matching.test.cpp
  - tests/longest_common_substring.test.cpp
  - tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  - tests/largest_rectangle_in_histogram.test.cpp
  - tests/suffix_array.test.cpp
  - tests/rolling_hash.test.cpp
documentation_of: tools/chmax.hpp
layout: document
title: chmax function
---

```cpp
template <typename M, typename N>
bool chmax(M& lhs, N rhs);
```

It runs `lhs = std::max(lhs, rhs);`.
It returns `true` if `lhs` has been updated.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
