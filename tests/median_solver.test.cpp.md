---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tests/assert_that.hpp
    title: tests/assert_that.hpp
  - icon: ':heavy_check_mark:'
    path: tools/median_solver.hpp
    title: Median solver
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
  bundledCode: "#line 1 \"tests/median_solver.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#line 1 \"tests/assert_that.hpp\"\
    \n\n\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    std::cerr <<\
    \ __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" << #cond\
    \ << \"' failed.\" << '\\n';\\\n    std::exit(EXIT_FAILURE);\\\n  }\\\n} while\
    \ (false)\n\n\n#line 1 \"tools/median_solver.hpp\"\n\n\n\n#include <queue>\n#include\
    \ <vector>\n#include <functional>\n#include <cstddef>\n#include <cassert>\n\n\
    namespace tools {\n\n  template <typename T>\n  class median_solver {\n  private:\n\
    \    ::std::priority_queue<T, ::std::vector<T>, ::std::less<T>> pq1;\n    ::std::priority_queue<T,\
    \ ::std::vector<T>, ::std::greater<T>> pq2;\n\n  public:\n    median_solver()\
    \ = default;\n    median_solver(const median_solver&) = default;\n    median_solver(median_solver&&)\
    \ = default;\n    ~median_solver() = default;\n    median_solver& operator=(const\
    \ median_solver&) = default;\n    median_solver& operator=(median_solver&&) =\
    \ default;\n\n    void push(const T& v) {\n      if (this->pq1.size() == this->pq2.size())\
    \ {\n        if (!this->pq2.empty() && v > this->pq2.top()) {\n          this->pq1.push(this->pq2.top());\n\
    \          this->pq2.pop();\n          this->pq2.push(v);\n        } else {\n\
    \          this->pq1.push(v);\n        }\n      } else {\n        if (v < this->pq1.top())\
    \ {\n          this->pq2.push(this->pq1.top());\n          this->pq1.pop();\n\
    \          this->pq1.push(v);\n        } else {\n          this->pq2.push(v);\n\
    \        }\n      }\n    }\n\n    ::std::size_t size() const {\n      return this->pq1.size()\
    \ + this->pq2.size();\n    }\n\n    bool empty() const {\n      return this->pq1.empty()\
    \ && this->pq2.empty();\n    }\n\n    T lesser() const {\n      assert(!this->empty());\n\
    \      return this->pq1.top();\n    }\n\n    T greater() const {\n      assert(!this->empty());\n\
    \      return this->pq1.size() == this->pq2.size() ? this->pq2.top() : this->pq1.top();\n\
    \    }\n  };\n}\n\n\n#line 7 \"tests/median_solver.test.cpp\"\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  tools::median_solver<std::int_fast64_t>\
    \ median;\n  median.push(2);\n  assert_that(median.lesser() == 2);\n  assert_that(median.greater()\
    \ == 2);\n  median.push(1);\n  assert_that(median.lesser() == 1);\n  assert_that(median.greater()\
    \ == 2);\n  median.push(3);\n  assert_that(median.lesser() == 2);\n  assert_that(median.greater()\
    \ == 2);\n  median.push(4);\n  assert_that(median.lesser() == 2);\n  assert_that(median.greater()\
    \ == 3);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include \"tests/assert_that.hpp\"\n\
    #include \"tools/median_solver.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  tools::median_solver<std::int_fast64_t>\
    \ median;\n  median.push(2);\n  assert_that(median.lesser() == 2);\n  assert_that(median.greater()\
    \ == 2);\n  median.push(1);\n  assert_that(median.lesser() == 1);\n  assert_that(median.greater()\
    \ == 2);\n  median.push(3);\n  assert_that(median.lesser() == 2);\n  assert_that(median.greater()\
    \ == 2);\n  median.push(4);\n  assert_that(median.lesser() == 2);\n  assert_that(median.greater()\
    \ == 3);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tests/assert_that.hpp
  - tools/median_solver.hpp
  isVerificationFile: true
  path: tests/median_solver.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 21:37:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/median_solver.test.cpp
layout: document
redirect_from:
- /verify/tests/median_solver.test.cpp
- /verify/tests/median_solver.test.cpp.html
title: tests/median_solver.test.cpp
---
