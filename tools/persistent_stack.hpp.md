---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/persistent_stack.test.cpp
    title: tests/persistent_stack.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/persistent_stack.hpp\"\n\n\n\n#include <cstddef>\n\
    #include <vector>\n#include <limits>\n#include <cassert>\n#include <type_traits>\n\
    \nnamespace tools {\n  template <typename T>\n  class persistent_stack {\n  private:\n\
    \    struct node {\n      ::std::size_t parent;\n      ::std::size_t depth;\n\
    \      T value;\n    };\n\n  public:\n    class buffer {\n    private:\n     \
    \ ::std::vector<::tools::persistent_stack<T>::node> m_nodes;\n\n    public:\n\
    \      buffer() = default;\n      buffer(const ::tools::persistent_stack<T>::buffer&)\
    \ = default;\n      buffer(::tools::persistent_stack<T>::buffer&&) = default;\n\
    \      ~buffer() = default;\n      ::tools::persistent_stack<T>::buffer& operator=(const\
    \ ::tools::persistent_stack<T>::buffer&) = default;\n      ::tools::persistent_stack<T>::buffer&\
    \ operator=(::tools::persistent_stack<T>::buffer&&) = default;\n\n      friend\
    \ ::tools::persistent_stack<T>;\n    };\n\n  private:\n    static const ::std::size_t\
    \ EMPTY = ::std::numeric_limits<::std::size_t>::max();\n    ::tools::persistent_stack<T>::buffer\
    \ *m_buffer;\n    ::std::size_t m_top;\n\n    persistent_stack(::tools::persistent_stack<T>::buffer&\
    \ buffer, const ::std::size_t top) : m_buffer(&buffer), m_top(top) {\n    }\n\n\
    \  public:\n    persistent_stack() = default;\n    persistent_stack(const ::tools::persistent_stack<T>&)\
    \ = default;\n    persistent_stack(::tools::persistent_stack<T>&&) = default;\n\
    \    ~persistent_stack() = default;\n    ::tools::persistent_stack<T>& operator=(const\
    \ ::tools::persistent_stack<T>&) = default;\n    ::tools::persistent_stack<T>&\
    \ operator=(::tools::persistent_stack<T>&&) = default;\n\n    explicit persistent_stack(::tools::persistent_stack<T>::buffer&\
    \ buffer) : m_buffer(&buffer), m_top(EMPTY) {\n    }\n\n    bool empty() const\
    \ {\n      return this->m_top == EMPTY;\n    }\n\n    ::std::size_t size() const\
    \ {\n      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth\
    \ + 1;\n    }\n\n    T top() const {\n      assert(!this->empty());\n      return\
    \ this->m_buffer->m_nodes[this->m_top].value;\n    }\n\n    ::tools::persistent_stack<T>\
    \ push(const T& x) const {\n      this->m_buffer->m_nodes.emplace_back();\n  \
    \    this->m_buffer->m_nodes.back().parent = this->m_top;\n      this->m_buffer->m_nodes.back().depth\
    \ = this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth + 1;\n    \
    \  this->m_buffer->m_nodes.back().value = x;\n      return ::tools::persistent_stack<T>(*this->m_buffer,\
    \ this->m_buffer->m_nodes.size() - 1);\n    }\n\n    ::tools::persistent_stack<T>\
    \ pop() const {\n      assert(!this->empty());\n      return ::tools::persistent_stack<T>(*this->m_buffer,\
    \ this->m_buffer->m_nodes[this->m_top].parent);\n    }\n\n    template <typename...\
    \ Args>\n    ::tools::persistent_stack<T> emplace(Args&&... args) const {\n  \
    \    return this->push(T(::std::forward<Args>(args)...));\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PERSISTENT_STACK_HPP\n#define TOOLS_PERSISTENT_STACK_HPP\n\n\
    #include <cstddef>\n#include <vector>\n#include <limits>\n#include <cassert>\n\
    #include <type_traits>\n\nnamespace tools {\n  template <typename T>\n  class\
    \ persistent_stack {\n  private:\n    struct node {\n      ::std::size_t parent;\n\
    \      ::std::size_t depth;\n      T value;\n    };\n\n  public:\n    class buffer\
    \ {\n    private:\n      ::std::vector<::tools::persistent_stack<T>::node> m_nodes;\n\
    \n    public:\n      buffer() = default;\n      buffer(const ::tools::persistent_stack<T>::buffer&)\
    \ = default;\n      buffer(::tools::persistent_stack<T>::buffer&&) = default;\n\
    \      ~buffer() = default;\n      ::tools::persistent_stack<T>::buffer& operator=(const\
    \ ::tools::persistent_stack<T>::buffer&) = default;\n      ::tools::persistent_stack<T>::buffer&\
    \ operator=(::tools::persistent_stack<T>::buffer&&) = default;\n\n      friend\
    \ ::tools::persistent_stack<T>;\n    };\n\n  private:\n    static const ::std::size_t\
    \ EMPTY = ::std::numeric_limits<::std::size_t>::max();\n    ::tools::persistent_stack<T>::buffer\
    \ *m_buffer;\n    ::std::size_t m_top;\n\n    persistent_stack(::tools::persistent_stack<T>::buffer&\
    \ buffer, const ::std::size_t top) : m_buffer(&buffer), m_top(top) {\n    }\n\n\
    \  public:\n    persistent_stack() = default;\n    persistent_stack(const ::tools::persistent_stack<T>&)\
    \ = default;\n    persistent_stack(::tools::persistent_stack<T>&&) = default;\n\
    \    ~persistent_stack() = default;\n    ::tools::persistent_stack<T>& operator=(const\
    \ ::tools::persistent_stack<T>&) = default;\n    ::tools::persistent_stack<T>&\
    \ operator=(::tools::persistent_stack<T>&&) = default;\n\n    explicit persistent_stack(::tools::persistent_stack<T>::buffer&\
    \ buffer) : m_buffer(&buffer), m_top(EMPTY) {\n    }\n\n    bool empty() const\
    \ {\n      return this->m_top == EMPTY;\n    }\n\n    ::std::size_t size() const\
    \ {\n      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth\
    \ + 1;\n    }\n\n    T top() const {\n      assert(!this->empty());\n      return\
    \ this->m_buffer->m_nodes[this->m_top].value;\n    }\n\n    ::tools::persistent_stack<T>\
    \ push(const T& x) const {\n      this->m_buffer->m_nodes.emplace_back();\n  \
    \    this->m_buffer->m_nodes.back().parent = this->m_top;\n      this->m_buffer->m_nodes.back().depth\
    \ = this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth + 1;\n    \
    \  this->m_buffer->m_nodes.back().value = x;\n      return ::tools::persistent_stack<T>(*this->m_buffer,\
    \ this->m_buffer->m_nodes.size() - 1);\n    }\n\n    ::tools::persistent_stack<T>\
    \ pop() const {\n      assert(!this->empty());\n      return ::tools::persistent_stack<T>(*this->m_buffer,\
    \ this->m_buffer->m_nodes[this->m_top].parent);\n    }\n\n    template <typename...\
    \ Args>\n    ::tools::persistent_stack<T> emplace(Args&&... args) const {\n  \
    \    return this->push(T(::std::forward<Args>(args)...));\n    }\n  };\n}\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/persistent_stack.hpp
  requiredBy: []
  timestamp: '2022-04-16 10:31:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/persistent_stack.test.cpp
documentation_of: tools/persistent_stack.hpp
layout: document
title: Persistent stack
---

It is a persistent stack.

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
persistent_stack<T>::buffer buffer();
```

It creates an empty buffer for `tools::persistent_stack<T>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
persistent_stack<T> stack(persistent_stack<T>::buffer& buffer);
```

It creates an empty stack whose data stores on `buffer`.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool stack.empty();
```

It returns whether the stack is empty or not.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t stack.size();
```

It returns the current number of elements of the stack.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## top
```cpp
T stack.top();
```

It returns the newest element in the stack.

### Constraints
- `buffer` is in its lifetime.
- `stack` is not empty.

### Time Complexity
- $O(1)$

## push
```cpp
persistent_stack<T> stack.push(T x);
```

It clones `stack`, adds `x` to the new stack and returns the new stack.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$ amortized

## pop
```cpp
persistent_stack<T> stack.pop();
```

It clones `stack`, removes the newest element from the new stack and returns the new stack.

### Constraints
- `buffer` is in its lifetime.
- `stack` is not empty.

### Time Complexity
- $O(1)$

## emplace
```cpp
template <typename... Args>
persistent_stack<T> emplace(Args&&... args);
```

It clones `stack`, adds `T(args...)` to the new stack and returns the new stack.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$ amortized
