---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/alphabetical_order.test.cpp
    title: tests/alphabetical_order.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log.test.cpp
    title: tests/ceil_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log2.test.cpp
    title: tests/ceil_log2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fill.test.cpp
    title: tests/fill.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fix.test.cpp
    title: tests/fix.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_log.test.cpp
    title: tests/floor_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_log2.test.cpp
    title: tests/floor_log2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/median_solver.test.cpp
    title: tests/median_solver.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/mex.test.cpp
    title: tests/mex.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/resize.test.cpp
    title: tests/resize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/run_length.test.cpp
    title: tests/run_length.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/safe_int.test.cpp
    title: tests/safe_int.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ssize.test.cpp
    title: tests/ssize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tsort.test.cpp
    title: tests/tsort.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/xor_basis.test.cpp
    title: tests/xor_basis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tests/assert_that.hpp\"\n\n\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n"
  code: "#ifndef TESTS_ASSERT_THAT_HPP\n#define TESTS_ASSERT_THAT_HPP\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tests/assert_that.hpp
  requiredBy: []
  timestamp: '2021-09-25 15:53:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/median_solver.test.cpp
  - tests/run_length.test.cpp
  - tests/tsort.test.cpp
  - tests/permutation.test.cpp
  - tests/fill.test.cpp
  - tests/floor_log.test.cpp
  - tests/ceil_log2.test.cpp
  - tests/resize.test.cpp
  - tests/segmented_sieve.test.cpp
  - tests/safe_int.test.cpp
  - tests/fix.test.cpp
  - tests/alphabetical_order.test.cpp
  - tests/ssize.test.cpp
  - tests/mex.test.cpp
  - tests/ceil_log.test.cpp
  - tests/xor_basis.test.cpp
  - tests/floor_log2.test.cpp
documentation_of: tests/assert_that.hpp
layout: document
redirect_from:
- /library/tests/assert_that.hpp
- /library/tests/assert_that.hpp.html
title: tests/assert_that.hpp
---
