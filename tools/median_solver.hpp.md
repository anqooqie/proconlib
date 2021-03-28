---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/median_solver.hpp\"\n\n\n\n#include <queue>\n#include\
    \ <vector>\n#include <functional>\n#include <cstddef>\n#include <cassert>\n\n\
    namespace tools {\n\n  template <typename T>\n  class median_solver {\n  private:\n\
    \    ::std::priority_queue<T, ::std::vector<T>, ::std::less<T>> pq1;\n    ::std::priority_queue<T,\
    \ ::std::vector<T>, ::std::greater<T>> pq2;\n\n  public:\n    median_solver()\
    \ = default;\n    median_solver(const median_solver&) = default;\n    median_solver(median_solver&&)\
    \ = default;\n    ~median_solver() = default;\n    median_solver& operator=(const\
    \ median_solver&) = default;\n    median_solver& operator=(median_solver&&) =\
    \ default;\n\n    void push(const T& v) {\n      if ((this->pq1.size() + this->pq2.size())\
    \ % 2 == 0) {\n        if (!this->pq2.empty() && v > this->pq2.top()) {\n    \
    \      this->pq1.push(this->pq2.top());\n          this->pq2.pop();\n        \
    \  this->pq2.push(v);\n        } else {\n          this->pq1.push(v);\n      \
    \  }\n      } else {\n        if (v < this->pq1.top()) {\n          this->pq2.push(this->pq1.top());\n\
    \          this->pq1.pop();\n          this->pq1.push(v);\n        } else {\n\
    \          this->pq2.push(v);\n        }\n      }\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->pq1.size() + this->pq2.size();\n    }\n\n\
    \    bool empty() const {\n      return this->pq1.empty() && this->pq2.empty();\n\
    \    }\n\n    T query() const {\n      assert(!this->empty());\n      return this->pq1.top();\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_MEDIAN_SOLVER_HPP\n#define TOOLS_MEDIAN_SOLVER_HPP\n\n#include\
    \ <queue>\n#include <vector>\n#include <functional>\n#include <cstddef>\n#include\
    \ <cassert>\n\nnamespace tools {\n\n  template <typename T>\n  class median_solver\
    \ {\n  private:\n    ::std::priority_queue<T, ::std::vector<T>, ::std::less<T>>\
    \ pq1;\n    ::std::priority_queue<T, ::std::vector<T>, ::std::greater<T>> pq2;\n\
    \n  public:\n    median_solver() = default;\n    median_solver(const median_solver&)\
    \ = default;\n    median_solver(median_solver&&) = default;\n    ~median_solver()\
    \ = default;\n    median_solver& operator=(const median_solver&) = default;\n\
    \    median_solver& operator=(median_solver&&) = default;\n\n    void push(const\
    \ T& v) {\n      if ((this->pq1.size() + this->pq2.size()) % 2 == 0) {\n     \
    \   if (!this->pq2.empty() && v > this->pq2.top()) {\n          this->pq1.push(this->pq2.top());\n\
    \          this->pq2.pop();\n          this->pq2.push(v);\n        } else {\n\
    \          this->pq1.push(v);\n        }\n      } else {\n        if (v < this->pq1.top())\
    \ {\n          this->pq2.push(this->pq1.top());\n          this->pq1.pop();\n\
    \          this->pq1.push(v);\n        } else {\n          this->pq2.push(v);\n\
    \        }\n      }\n    }\n\n    ::std::size_t size() const {\n      return this->pq1.size()\
    \ + this->pq2.size();\n    }\n\n    bool empty() const {\n      return this->pq1.empty()\
    \ && this->pq2.empty();\n    }\n\n    T query() const {\n      assert(!this->empty());\n\
    \      return this->pq1.top();\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/median_solver.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/median_solver.hpp
layout: document
title: Median solver
---

It calculates the median of an array.
It also allows you to dynamically add values to the array.

## Usage
```cpp
tools::median_solver<int> median;
median.push(5);
median.push(3);
median.push(7);
median.push(6);
median.query(); // => 5
```

## License
- CC0

## Author
- anqooqie
