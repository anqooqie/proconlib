---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/swag.test.cpp
    title: tests/swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/swag.hpp\"\n\n\n\n#include <stack>\n#include <utility>\n\
    #include <cassert>\n\nnamespace tools {\n  template <typename M>\n  class swag\
    \ {\n  private:\n    using T = typename M::T;\n    ::std::stack<::std::pair<T,\
    \ T>> m_head;\n    ::std::stack<::std::pair<T, T>> m_tail;\n\n    T head_prod()\
    \ const {\n      return this->m_head.empty() ? M::e() : this->m_head.top().second;\n\
    \    }\n    T tail_prod() const {\n      return this->m_tail.empty() ? M::e()\
    \ : this->m_tail.top().second;\n    }\n\n  public:\n    swag() = default;\n  \
    \  swag(const ::tools::swag<M>&) = default;\n    swag(::tools::swag<M>&&) = default;\n\
    \    ~swag() = default;\n    ::tools::swag<M>& operator=(const ::tools::swag<M>&)\
    \ = default;\n    ::tools::swag<M>& operator=(::tools::swag<M>&&) = default;\n\
    \n    bool empty() const {\n      return this->m_head.empty() && this->m_tail.empty();\n\
    \    }\n\n    void push_back(const T& x) {\n      this->m_tail.emplace(x, M::op(this->tail_prod(),\
    \ x));\n    }\n\n    template <typename... Args>\n    void emplace_back(Args&&...\
    \ args) {\n      this->push_back(T(::std::forward<Args>(args)...));\n    }\n\n\
    \    void pop_back() {\n      assert(!this->empty());\n      if (this->m_tail.empty())\
    \ {\n        ::std::stack<T> tmp;\n        while (tmp.size() + 1 < this->m_head.size())\
    \ {\n          tmp.push(this->m_head.top().first);\n          this->m_head.pop();\n\
    \        }\n        while (!this->m_head.empty()) {\n          this->m_tail.emplace(this->m_head.top().first,\
    \ M::op(this->tail_prod(), this->m_head.top().first));\n          this->m_head.pop();\n\
    \        }\n        while (!tmp.empty()) {\n          this->m_head.emplace(tmp.top(),\
    \ M::op(tmp.top(), this->head_prod()));\n          tmp.pop();\n        }\n   \
    \   }\n      this->m_tail.pop();\n    }\n\n    void push_front(const T& x) {\n\
    \      this->m_head.emplace(x, M::op(x, this->head_prod()));\n    }\n\n    template\
    \ <typename... Args>\n    void emplace_front(Args&&... args) {\n      this->push_front(T(::std::forward<Args>(args)...));\n\
    \    }\n\n    void pop_front() {\n      assert(!this->empty());\n      if (this->m_head.empty())\
    \ {\n        ::std::stack<T> tmp;\n        while (this->m_tail.size() > tmp.size()\
    \ + 1) {\n          tmp.push(this->m_tail.top().first);\n          this->m_tail.pop();\n\
    \        }\n        while (!this->m_tail.empty()) {\n          this->m_head.emplace(this->m_tail.top().first,\
    \ M::op(this->m_tail.top().first, this->head_prod()));\n          this->m_tail.pop();\n\
    \        }\n        while (!tmp.empty()) {\n          this->m_tail.emplace(tmp.top(),\
    \ M::op(this->tail_prod(), tmp.top()));\n          tmp.pop();\n        }\n   \
    \   }\n      this->m_head.pop();\n    }\n\n    T prod() const {\n      return\
    \ M::op(this->head_prod(), this->tail_prod());\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_SWAG_HPP\n#define TOOLS_SWAG_HPP\n\n#include <stack>\n#include\
    \ <utility>\n#include <cassert>\n\nnamespace tools {\n  template <typename M>\n\
    \  class swag {\n  private:\n    using T = typename M::T;\n    ::std::stack<::std::pair<T,\
    \ T>> m_head;\n    ::std::stack<::std::pair<T, T>> m_tail;\n\n    T head_prod()\
    \ const {\n      return this->m_head.empty() ? M::e() : this->m_head.top().second;\n\
    \    }\n    T tail_prod() const {\n      return this->m_tail.empty() ? M::e()\
    \ : this->m_tail.top().second;\n    }\n\n  public:\n    swag() = default;\n  \
    \  swag(const ::tools::swag<M>&) = default;\n    swag(::tools::swag<M>&&) = default;\n\
    \    ~swag() = default;\n    ::tools::swag<M>& operator=(const ::tools::swag<M>&)\
    \ = default;\n    ::tools::swag<M>& operator=(::tools::swag<M>&&) = default;\n\
    \n    bool empty() const {\n      return this->m_head.empty() && this->m_tail.empty();\n\
    \    }\n\n    void push_back(const T& x) {\n      this->m_tail.emplace(x, M::op(this->tail_prod(),\
    \ x));\n    }\n\n    template <typename... Args>\n    void emplace_back(Args&&...\
    \ args) {\n      this->push_back(T(::std::forward<Args>(args)...));\n    }\n\n\
    \    void pop_back() {\n      assert(!this->empty());\n      if (this->m_tail.empty())\
    \ {\n        ::std::stack<T> tmp;\n        while (tmp.size() + 1 < this->m_head.size())\
    \ {\n          tmp.push(this->m_head.top().first);\n          this->m_head.pop();\n\
    \        }\n        while (!this->m_head.empty()) {\n          this->m_tail.emplace(this->m_head.top().first,\
    \ M::op(this->tail_prod(), this->m_head.top().first));\n          this->m_head.pop();\n\
    \        }\n        while (!tmp.empty()) {\n          this->m_head.emplace(tmp.top(),\
    \ M::op(tmp.top(), this->head_prod()));\n          tmp.pop();\n        }\n   \
    \   }\n      this->m_tail.pop();\n    }\n\n    void push_front(const T& x) {\n\
    \      this->m_head.emplace(x, M::op(x, this->head_prod()));\n    }\n\n    template\
    \ <typename... Args>\n    void emplace_front(Args&&... args) {\n      this->push_front(T(::std::forward<Args>(args)...));\n\
    \    }\n\n    void pop_front() {\n      assert(!this->empty());\n      if (this->m_head.empty())\
    \ {\n        ::std::stack<T> tmp;\n        while (this->m_tail.size() > tmp.size()\
    \ + 1) {\n          tmp.push(this->m_tail.top().first);\n          this->m_tail.pop();\n\
    \        }\n        while (!this->m_tail.empty()) {\n          this->m_head.emplace(this->m_tail.top().first,\
    \ M::op(this->m_tail.top().first, this->head_prod()));\n          this->m_tail.pop();\n\
    \        }\n        while (!tmp.empty()) {\n          this->m_tail.emplace(tmp.top(),\
    \ M::op(this->tail_prod(), tmp.top()));\n          tmp.pop();\n        }\n   \
    \   }\n      this->m_head.pop();\n    }\n\n    T prod() const {\n      return\
    \ M::op(this->head_prod(), this->tail_prod());\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/swag.hpp
  requiredBy: []
  timestamp: '2022-11-05 13:33:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/swag.test.cpp
documentation_of: tools/swag.hpp
layout: document
title: Sliding window aggregation
---

It is a data structure which supports the following operations.

- Create an empty sequence of elements on a given monoid in $O(1)$.
- Add an element to the sequence as the first element in $O(1)$.
- Add an element to the sequence as the last element in $O(1)$.
- Remove the first element from the sequence in $O(1)$ amortized.
- Remove the last element from the sequence in $O(1)$ amortized.
- Calculate the production on the monoid of all elements in the sequence, in $O(1)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename M>
swag<M> swag();
```

It creates an empty sequence of elements on a given monoid $M$.

### Constraints
- For all $a$ in `typename M::T`, $b$ in `typename M::T` and $c$ in `typename M::T`, `M::op(M::op(a, b), c)` $=$ `M::op(a, M::op(b, c))`.
- For all $a$ in `typename M::T`, `M::op(M::e(), a)` $=$ `M::op(a, M::e())` $=$ `a`.

### Time Complexity
- $O(1)$

## empty
```cpp
bool swag.empty();
```

It returns whether the sequence is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## push_front
```cpp
void swag.push_front(typename M::T x);
```

It adds an element $x$ to the sequence as the first element.

### Constraints
- None

### Time Complexity
- $O(1)$

## emplace_front
```cpp
template <typename... Args>
void swag.emplace_front(Args&&... args);
```

It adds an element `typename M::T(args...)` to the sequence as the first element.

### Constraints
- None

### Time Complexity
- $O(1)$

## push_back
```cpp
void swag.push_back(typename M::T x);
```

It adds an element $x$ to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## emplace_back
```cpp
template <typename... Args>
void swag.emplace_back(Args&&... args);
```

It adds an element `typename M::T(args...)` to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## pop_front
```cpp
void swag.pop_front();
```

It removes the first element from the sequence.

### Constraints
- The sequence is not empty.

### Time Complexity
- $O(1)$ amortized

## pop_back
```cpp
void swag.pop_back();
```

It removes the last element from the sequence.

### Constraints
- The sequence is not empty.

### Time Complexity
- $O(1)$ amortized

## prod
```cpp
typename M::T swag.prod();
```

It returns the production on the monoid of all elements in the sequence.

### Constraints
- None

### Time Complexity
- $O(1)$
