---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/median_solver.test.cpp
    title: tests/median_solver.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ T& v) {\n      if (this->pq1.size() == this->pq2.size()) {\n        if (!this->pq2.empty()\
    \ && v > this->pq2.top()) {\n          this->pq1.push(this->pq2.top());\n    \
    \      this->pq2.pop();\n          this->pq2.push(v);\n        } else {\n    \
    \      this->pq1.push(v);\n        }\n      } else {\n        if (v < this->pq1.top())\
    \ {\n          this->pq2.push(this->pq1.top());\n          this->pq1.pop();\n\
    \          this->pq1.push(v);\n        } else {\n          this->pq2.push(v);\n\
    \        }\n      }\n    }\n\n    ::std::size_t size() const {\n      return this->pq1.size()\
    \ + this->pq2.size();\n    }\n\n    bool empty() const {\n      return this->pq1.empty()\
    \ && this->pq2.empty();\n    }\n\n    T lesser() const {\n      assert(!this->empty());\n\
    \      return this->pq1.top();\n    }\n\n    T greater() const {\n      assert(!this->empty());\n\
    \      return this->pq1.size() == this->pq2.size() ? this->pq2.top() : this->pq1.top();\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/median_solver.hpp
  requiredBy: []
  timestamp: '2021-10-03 21:37:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/median_solver.test.cpp
documentation_of: tools/median_solver.hpp
layout: document
title: Median solver
---

It calculates the median of an array.
It also allows you to dynamically add values to the array.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
median_solver<T> median();
```

It creates an empty array.

### Constraints
- None

### Time Complexity
- $O(1)$

## push
```cpp
void median.push(T x);
```

It adds $x$ to the array.

### Constraints
- None

### Time Complexity
- $O(\log N)$ where $N$ is the number of elements in the array

## size
```cpp
std::size_t median.size();
```

It returns the number of elements in the array.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool median.empty();
```

It returns whether the array is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## lesser
```cpp
T median.lesser();
```

It returns the $\left\lfloor\frac{N + 1}{2}\right\rfloor$-th smallest element in the array.

### Constraints
- The array is not empty.

### Time Complexity
- $O(1)$

## greater
```cpp
T median.greater();
```

It returns the $\left(\left\lfloor\frac{N}{2}\right\rfloor + 1\right)$-th smallest element in the array.

### Constraints
- The array is not empty.

### Time Complexity
- $O(1)$
