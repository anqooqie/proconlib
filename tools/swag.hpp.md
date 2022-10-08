---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/swag.test.cpp
    title: tests/swag.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/swag.hpp\"\n\n\n\n#include <stack>\n#include <utility>\n\
    #include <cassert>\n\nnamespace tools {\n  template <typename M>\n  class swag\
    \ {\n  private:\n    using T = typename M::T;\n    ::std::stack<T> stack1;\n \
    \   T stack1_prod;\n    ::std::stack<::std::pair<T, T>> stack2;\n\n    T stack2_prod()\
    \ const {\n      return this->stack2.empty() ? M::e() : this->stack2.top().second;\n\
    \    }\n\n  public:\n    swag() : stack1_prod(M::e()) {\n    }\n    swag(const\
    \ ::tools::swag<M>&) = default;\n    swag(::tools::swag<M>&&) = default;\n   \
    \ ~swag() = default;\n    ::tools::swag<M>& operator=(const ::tools::swag<M>&)\
    \ = default;\n    ::tools::swag<M>& operator=(::tools::swag<M>&&) = default;\n\
    \n    bool empty() const {\n      return this->stack1.empty() && this->stack2.empty();\n\
    \    }\n\n    void push(const T& x) {\n      this->stack1_prod = M::op(this->stack1_prod,\
    \ x);\n      this->stack1.push(x);\n    }\n\n    template <typename... Args>\n\
    \    void emplace(Args&&... args) {\n      this->push(T(::std::forward<Args>(args)...));\n\
    \    }\n\n    void pop() {\n      assert(!this->empty());\n      if (this->stack2.empty())\
    \ {\n        while (!this->stack1.empty()) {\n          this->stack2.emplace(\n\
    \            this->stack1.top(),\n            M::op(this->stack1.top(), this->stack2_prod())\n\
    \            );\n          this->stack1.pop();\n        }\n        this->stack1_prod\
    \ = M::e();\n      }\n      this->stack2.pop();\n    }\n\n    T prod() const {\n\
    \      return M::op(this->stack2_prod(), this->stack1_prod);\n    }\n  };\n}\n\
    \n\n"
  code: "#ifndef TOOLS_SWAG_HPP\n#define TOOLS_SWAG_HPP\n\n#include <stack>\n#include\
    \ <utility>\n#include <cassert>\n\nnamespace tools {\n  template <typename M>\n\
    \  class swag {\n  private:\n    using T = typename M::T;\n    ::std::stack<T>\
    \ stack1;\n    T stack1_prod;\n    ::std::stack<::std::pair<T, T>> stack2;\n\n\
    \    T stack2_prod() const {\n      return this->stack2.empty() ? M::e() : this->stack2.top().second;\n\
    \    }\n\n  public:\n    swag() : stack1_prod(M::e()) {\n    }\n    swag(const\
    \ ::tools::swag<M>&) = default;\n    swag(::tools::swag<M>&&) = default;\n   \
    \ ~swag() = default;\n    ::tools::swag<M>& operator=(const ::tools::swag<M>&)\
    \ = default;\n    ::tools::swag<M>& operator=(::tools::swag<M>&&) = default;\n\
    \n    bool empty() const {\n      return this->stack1.empty() && this->stack2.empty();\n\
    \    }\n\n    void push(const T& x) {\n      this->stack1_prod = M::op(this->stack1_prod,\
    \ x);\n      this->stack1.push(x);\n    }\n\n    template <typename... Args>\n\
    \    void emplace(Args&&... args) {\n      this->push(T(::std::forward<Args>(args)...));\n\
    \    }\n\n    void pop() {\n      assert(!this->empty());\n      if (this->stack2.empty())\
    \ {\n        while (!this->stack1.empty()) {\n          this->stack2.emplace(\n\
    \            this->stack1.top(),\n            M::op(this->stack1.top(), this->stack2_prod())\n\
    \            );\n          this->stack1.pop();\n        }\n        this->stack1_prod\
    \ = M::e();\n      }\n      this->stack2.pop();\n    }\n\n    T prod() const {\n\
    \      return M::op(this->stack2_prod(), this->stack1_prod);\n    }\n  };\n}\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/swag.hpp
  requiredBy: []
  timestamp: '2021-11-27 16:35:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/swag.test.cpp
documentation_of: tools/swag.hpp
layout: document
title: Sliding window aggregation
---

It is a data structure which supports the following operations.

- Create an empty sequence of elements on a given monoid in $O(1)$.
- Add an element to the sequence as the last element in $O(1)$.
- Remove the first element from the sequence in amortized $O(1)$.
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

## push
```cpp
void swag.push(typename M::T x);
```

It adds an element $x$ to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## emplace
```cpp
template <typename... Args>
void swag.emplace(Args&&... args);
```

It adds an element `typename M::T(args...)` to the sequence as the last element.

### Constraints
- None

### Time Complexity
- $O(1)$

## pop
```cpp
void swag.pop();
```

It removes the first element from the sequence.

### Constraints
- The sequence is not empty.

### Time Complexity
- amortized $O(1)$

## prod
```cpp
typename M::T swag.prod();
```

It returns the production on the monoid of all elements in the sequence.

### Constraints
- None

### Time Complexity
- $O(1)$
