---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/median_heap.test.cpp
    title: tests/median_heap.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/median_heap.hpp\"\n\n\n\n#include <functional>\n#include\
    \ <queue>\n#include <vector>\n#include <cstddef>\n#include <cassert>\n\nnamespace\
    \ tools {\n\n  template <typename T, typename Compare = ::std::less<T>>\n  class\
    \ median_heap {\n  private:\n    class RevCompare {\n    private:\n      Compare\
    \ m_less;\n    public:\n      explicit RevCompare(const Compare& less) : m_less(less)\
    \ {\n      }\n      bool operator()(const T& x, const T& y) const {\n        return\
    \ this->m_less(y, x);\n      }\n    };\n\n    Compare m_less;\n    ::std::priority_queue<T,\
    \ ::std::vector<T>, Compare> m_pq1;\n    ::std::priority_queue<T, ::std::vector<T>,\
    \ RevCompare> m_pq2;\n\n  public:\n    explicit median_heap(const Compare& less)\
    \ : m_less(less), m_pq1(less), m_pq2(RevCompare(less)) {\n    }\n    median_heap()\
    \ : median_heap(Compare()) {\n    }\n    median_heap(const ::tools::median_heap<T,\
    \ Compare>&) = default;\n    median_heap(::tools::median_heap<T, Compare>&&) =\
    \ default;\n    ~median_heap() = default;\n    ::tools::median_heap<T, Compare>&\
    \ operator=(const ::tools::median_heap<T, Compare>&) = default;\n    ::tools::median_heap<T,\
    \ Compare>& operator=(::tools::median_heap<T, Compare>&&) = default;\n\n    bool\
    \ empty() const {\n      return this->m_pq1.empty() && this->m_pq2.empty();\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->m_pq1.size() +\
    \ this->m_pq2.size();\n    }\n\n    T lesser() const {\n      assert(!this->empty());\n\
    \      return this->m_pq1.top();\n    }\n\n    T greater() const {\n      assert(!this->empty());\n\
    \      return this->m_pq1.size() == this->m_pq2.size() ? this->m_pq2.top() : this->m_pq1.top();\n\
    \    }\n\n    void push(const T& v) {\n      if (this->m_pq1.size() == this->m_pq2.size())\
    \ {\n        if (!this->m_pq2.empty() && this->m_less(this->m_pq2.top(), v)) {\n\
    \          this->m_pq1.push(this->m_pq2.top());\n          this->m_pq2.pop();\n\
    \          this->m_pq2.push(v);\n        } else {\n          this->m_pq1.push(v);\n\
    \        }\n      } else {\n        if (this->m_less(v, this->m_pq1.top())) {\n\
    \          this->m_pq2.push(this->m_pq1.top());\n          this->m_pq1.pop();\n\
    \          this->m_pq1.push(v);\n        } else {\n          this->m_pq2.push(v);\n\
    \        }\n      }\n    }\n\n    template <typename... Args>\n    void emplace(Args&&...\
    \ args) {\n      this->push(T(::std::forward<Args>(args)...));\n    }\n\n    void\
    \ swap(::tools::median_heap<T, Compare>& other) {\n      ::std::swap(this->m_less,\
    \ other.m_less);\n      this->m_pq1.swap(other.m_pq1);\n      this->m_pq2.swap(other.m_pq2);\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_MEDIAN_HEAP_HPP\n#define TOOLS_MEDIAN_HEAP_HPP\n\n#include\
    \ <functional>\n#include <queue>\n#include <vector>\n#include <cstddef>\n#include\
    \ <cassert>\n\nnamespace tools {\n\n  template <typename T, typename Compare =\
    \ ::std::less<T>>\n  class median_heap {\n  private:\n    class RevCompare {\n\
    \    private:\n      Compare m_less;\n    public:\n      explicit RevCompare(const\
    \ Compare& less) : m_less(less) {\n      }\n      bool operator()(const T& x,\
    \ const T& y) const {\n        return this->m_less(y, x);\n      }\n    };\n\n\
    \    Compare m_less;\n    ::std::priority_queue<T, ::std::vector<T>, Compare>\
    \ m_pq1;\n    ::std::priority_queue<T, ::std::vector<T>, RevCompare> m_pq2;\n\n\
    \  public:\n    explicit median_heap(const Compare& less) : m_less(less), m_pq1(less),\
    \ m_pq2(RevCompare(less)) {\n    }\n    median_heap() : median_heap(Compare())\
    \ {\n    }\n    median_heap(const ::tools::median_heap<T, Compare>&) = default;\n\
    \    median_heap(::tools::median_heap<T, Compare>&&) = default;\n    ~median_heap()\
    \ = default;\n    ::tools::median_heap<T, Compare>& operator=(const ::tools::median_heap<T,\
    \ Compare>&) = default;\n    ::tools::median_heap<T, Compare>& operator=(::tools::median_heap<T,\
    \ Compare>&&) = default;\n\n    bool empty() const {\n      return this->m_pq1.empty()\
    \ && this->m_pq2.empty();\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_pq1.size() + this->m_pq2.size();\n    }\n\n    T lesser() const {\n\
    \      assert(!this->empty());\n      return this->m_pq1.top();\n    }\n\n   \
    \ T greater() const {\n      assert(!this->empty());\n      return this->m_pq1.size()\
    \ == this->m_pq2.size() ? this->m_pq2.top() : this->m_pq1.top();\n    }\n\n  \
    \  void push(const T& v) {\n      if (this->m_pq1.size() == this->m_pq2.size())\
    \ {\n        if (!this->m_pq2.empty() && this->m_less(this->m_pq2.top(), v)) {\n\
    \          this->m_pq1.push(this->m_pq2.top());\n          this->m_pq2.pop();\n\
    \          this->m_pq2.push(v);\n        } else {\n          this->m_pq1.push(v);\n\
    \        }\n      } else {\n        if (this->m_less(v, this->m_pq1.top())) {\n\
    \          this->m_pq2.push(this->m_pq1.top());\n          this->m_pq1.pop();\n\
    \          this->m_pq1.push(v);\n        } else {\n          this->m_pq2.push(v);\n\
    \        }\n      }\n    }\n\n    template <typename... Args>\n    void emplace(Args&&...\
    \ args) {\n      this->push(T(::std::forward<Args>(args)...));\n    }\n\n    void\
    \ swap(::tools::median_heap<T, Compare>& other) {\n      ::std::swap(this->m_less,\
    \ other.m_less);\n      this->m_pq1.swap(other.m_pq1);\n      this->m_pq2.swap(other.m_pq2);\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/median_heap.hpp
  requiredBy: []
  timestamp: '2022-03-19 14:14:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/median_heap.test.cpp
documentation_of: tools/median_heap.hpp
layout: document
title: Heap managing median
---

It is a heap managing median.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
median_heap<T, Compare = std::less<T>> heap(Compare less = Compare());
```

It creates an empty heap.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool heap.empty();
```

It returns whether the heap is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t heap.size();
```

It returns the number of elements in the heap.

### Constraints
- None

### Time Complexity
- $O(1)$

## lesser
```cpp
T heap.lesser();
```

It returns the $\left\lfloor\frac{N + 1}{2}\right\rfloor$-th smallest element in the heap where $N$ is the number of elements in the heap.

### Constraints
- The heap is not empty.

### Time Complexity
- $O(1)$

## greater
```cpp
T heap.greater();
```

It returns the $\left(\left\lfloor\frac{N}{2}\right\rfloor + 1\right)$-th smallest element in the heap where $N$ is the number of elements in the heap.

### Constraints
- The heap is not empty.

### Time Complexity
- $O(1)$

## push
```cpp
void heap.push(T x);
```

It adds $x$ to the heap.

### Constraints
- None

### Time Complexity
- $O(\log N)$ where $N$ is the number of elements in the heap

## emplace
```cpp
template <typename... Args>
void heap.emplace(Args&&... args);
```

It adds `T(args...)` to the heap.

### Constraints
- None

### Time Complexity
- $O(\log N)$ where $N$ is the number of elements in the heap

## swap
```cpp
void heap.swap(median_heap<T, Compare>& other);
```

It swaps `heap` and `other`.

### Constraints
- None

### Time Complexity
- $O(1)$
