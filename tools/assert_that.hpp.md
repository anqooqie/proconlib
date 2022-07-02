---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/alphabetical_order.test.cpp
    title: tests/alphabetical_order.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/hand.test.cpp
    title: tests/bigdecimal/hand.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/random.test.cpp
    title: tests/bigdecimal/random.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil.test.cpp
    title: tests/ceil.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log.test.cpp
    title: tests/ceil_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_log2.test.cpp
    title: tests/ceil_log2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/ceil_sqrt.test.cpp
    title: tests/ceil_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/digit_sum.test.cpp
    title: tests/digit_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fill.test.cpp
    title: tests/fill.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/find_cycle.test.cpp
    title: tests/find_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fix.test.cpp
    title: tests/fix.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor.test.cpp
    title: tests/floor.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_log.test.cpp
    title: tests/floor_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_log2.test.cpp
    title: tests/floor_log2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_sqrt.test.cpp
    title: tests/floor_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/mex.test.cpp
    title: tests/mex.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/random.test.cpp
    title: tests/rational/random.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/resize.test.cpp
    title: tests/resize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rotate_left.test.cpp
    title: tests/rotate_left.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rotate_right.test.cpp
    title: tests/rotate_right.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/run_length.test.cpp
    title: tests/run_length.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/safe_int.test.cpp
    title: tests/safe_int.test.cpp
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
  bundledCode: "#line 1 \"tools/assert_that.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    ::std::cerr\
    \ << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" <<\
    \ #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n\
    } while (false)\n\n\n"
  code: "#ifndef TOOLS_ASSERT_THAT_HPP\n#define TOOLS_ASSERT_THAT_HPP\n\n#include\
    \ <iostream>\n#include <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond))\
    \ {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__ <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/assert_that.hpp
  requiredBy: []
  timestamp: '2022-06-17 23:50:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/floor_sqrt.test.cpp
  - tests/xor_basis.test.cpp
  - tests/permutation.test.cpp
  - tests/floor.test.cpp
  - tests/ssize.test.cpp
  - tests/find_cycle.test.cpp
  - tests/rational/random.test.cpp
  - tests/ceil.test.cpp
  - tests/ceil_sqrt.test.cpp
  - tests/ceil_log2.test.cpp
  - tests/floor_log2.test.cpp
  - tests/alphabetical_order.test.cpp
  - tests/run_length.test.cpp
  - tests/floor_log.test.cpp
  - tests/ceil_log.test.cpp
  - tests/rotate_left.test.cpp
  - tests/mex.test.cpp
  - tests/safe_int.test.cpp
  - tests/fill.test.cpp
  - tests/resize.test.cpp
  - tests/rotate_right.test.cpp
  - tests/tsort.test.cpp
  - tests/digit_sum.test.cpp
  - tests/fix.test.cpp
documentation_of: tools/assert_that.hpp
layout: document
title: Assertion macro
---

```cpp
#define assert_that(cond) do {\
  if (!(cond)) {\
    std::cerr << __FILE__ << ':' << __LINE__ << ": " << __func__ << ": Assertion `" << #cond << "' failed." << '\n';\
    std::exit(EXIT_FAILURE);\
  }\
} while (false)
```

It asserts that `cond` holds.
If `cond` is `false`, it outputs the debug information to `std::cerr` and terminates the program with exit status `EXIT_FAILURE`.

The macro is always enabled regardless of `NDEBUG` unlike `assert`.

## Constraints
- None

## Time Complexity
- Same as `cond`

## License
- CC0

## Author
- anqooqie
