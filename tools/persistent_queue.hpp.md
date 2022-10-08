---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/persistent_queue.test.cpp
    title: tests/persistent_queue.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/persistent_queue.hpp\"\n\n\n\n#include <vector>\n\
    #include <cstddef>\n#include <limits>\n#include <cassert>\n#include <type_traits>\n\
    \nnamespace tools {\n  template <typename T>\n  class persistent_queue {\n  private:\n\
    \    struct node {\n      ::std::vector<::std::size_t> ancestors;\n      ::std::size_t\
    \ depth;\n      T value;\n    };\n\n  public:\n    class buffer {\n    private:\n\
    \      ::std::vector<::tools::persistent_queue<T>::node> m_nodes;\n\n    public:\n\
    \      buffer() = default;\n      buffer(const ::tools::persistent_queue<T>::buffer&)\
    \ = default;\n      buffer(::tools::persistent_queue<T>::buffer&&) = default;\n\
    \      ~buffer() = default;\n      ::tools::persistent_queue<T>::buffer& operator=(const\
    \ ::tools::persistent_queue<T>::buffer&) = default;\n      ::tools::persistent_queue<T>::buffer&\
    \ operator=(::tools::persistent_queue<T>::buffer&&) = default;\n\n      friend\
    \ ::tools::persistent_queue<T>;\n    };\n\n  private:\n    static const ::std::size_t\
    \ EMPTY = ::std::numeric_limits<::std::size_t>::max();\n    ::tools::persistent_queue<T>::buffer\
    \ *m_buffer;\n    ::std::size_t m_front;\n    ::std::size_t m_back;\n\n    persistent_queue(::tools::persistent_queue<T>::buffer&\
    \ buffer, const ::std::size_t front, const ::std::size_t back) : m_buffer(&buffer),\
    \ m_front(front), m_back(back) {\n    }\n\n  public:\n    persistent_queue() =\
    \ default;\n    persistent_queue(const ::tools::persistent_queue<T>&) = default;\n\
    \    persistent_queue(::tools::persistent_queue<T>&&) = default;\n    ~persistent_queue()\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(const ::tools::persistent_queue<T>&)\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(::tools::persistent_queue<T>&&)\
    \ = default;\n\n    explicit persistent_queue(::tools::persistent_queue<T>::buffer&\
    \ buffer) : m_buffer(&buffer), m_front(EMPTY), m_back(EMPTY) {\n    }\n\n    bool\
    \ empty() const {\n      return this->m_front == EMPTY && this->m_back == EMPTY;\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth\
    \ - this->m_buffer->m_nodes[this->m_front].depth + 1;\n    }\n\n    T front()\
    \ const {\n      assert(!this->empty());\n      return this->m_buffer->m_nodes[this->m_front].value;\n\
    \    }\n\n    T back() const {\n      assert(!this->empty());\n      return this->m_buffer->m_nodes[this->m_back].value;\n\
    \    }\n\n    ::tools::persistent_queue<T> push(const T& x) const {\n      this->m_buffer->m_nodes.emplace_back();\n\
    \      this->m_buffer->m_nodes.back().depth = this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth\
    \ + 1;\n      this->m_buffer->m_nodes.back().value = x;\n      if (!this->empty())\
    \ {\n        ::std::size_t i = 0;\n        ::std::size_t v = this->m_back;\n \
    \       while (true) {\n          this->m_buffer->m_nodes.back().ancestors.push_back(v);\n\
    \          if (this->m_buffer->m_nodes[v].ancestors.size() <= i) break;\n    \
    \      v = this->m_buffer->m_nodes[v].ancestors[i];\n          ++i;\n        }\n\
    \      }\n      return ::tools::persistent_queue<T>(*this->m_buffer, this->empty()\
    \ ? this->m_buffer->m_nodes.size() - 1 : this->m_front, this->m_buffer->m_nodes.size()\
    \ - 1);\n    }\n\n    ::tools::persistent_queue<T> pop() const {\n      assert(!this->empty());\n\
    \      if (this->size() == 1) {\n        return ::tools::persistent_queue<T>(*this->m_buffer,\
    \ EMPTY, EMPTY);\n      }\n      ::std::size_t v = this->m_back;\n      for (::std::size_t\
    \ d = this->size() - 2, i = 0; d > 0; d /= 2, ++i) {\n        if (d % 2 == 1)\
    \ {\n          v = this->m_buffer->m_nodes[v].ancestors[i];\n        }\n     \
    \ }\n      return ::tools::persistent_queue<T>(*this->m_buffer, v, this->m_back);\n\
    \    }\n\n    template <typename... Args>\n    ::tools::persistent_queue<T> emplace(Args&&...\
    \ args) const {\n      return this->push(T(::std::forward<Args>(args)...));\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PERSISTENT_QUEUE_HPP\n#define TOOLS_PERSISTENT_QUEUE_HPP\n\n\
    #include <vector>\n#include <cstddef>\n#include <limits>\n#include <cassert>\n\
    #include <type_traits>\n\nnamespace tools {\n  template <typename T>\n  class\
    \ persistent_queue {\n  private:\n    struct node {\n      ::std::vector<::std::size_t>\
    \ ancestors;\n      ::std::size_t depth;\n      T value;\n    };\n\n  public:\n\
    \    class buffer {\n    private:\n      ::std::vector<::tools::persistent_queue<T>::node>\
    \ m_nodes;\n\n    public:\n      buffer() = default;\n      buffer(const ::tools::persistent_queue<T>::buffer&)\
    \ = default;\n      buffer(::tools::persistent_queue<T>::buffer&&) = default;\n\
    \      ~buffer() = default;\n      ::tools::persistent_queue<T>::buffer& operator=(const\
    \ ::tools::persistent_queue<T>::buffer&) = default;\n      ::tools::persistent_queue<T>::buffer&\
    \ operator=(::tools::persistent_queue<T>::buffer&&) = default;\n\n      friend\
    \ ::tools::persistent_queue<T>;\n    };\n\n  private:\n    static const ::std::size_t\
    \ EMPTY = ::std::numeric_limits<::std::size_t>::max();\n    ::tools::persistent_queue<T>::buffer\
    \ *m_buffer;\n    ::std::size_t m_front;\n    ::std::size_t m_back;\n\n    persistent_queue(::tools::persistent_queue<T>::buffer&\
    \ buffer, const ::std::size_t front, const ::std::size_t back) : m_buffer(&buffer),\
    \ m_front(front), m_back(back) {\n    }\n\n  public:\n    persistent_queue() =\
    \ default;\n    persistent_queue(const ::tools::persistent_queue<T>&) = default;\n\
    \    persistent_queue(::tools::persistent_queue<T>&&) = default;\n    ~persistent_queue()\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(const ::tools::persistent_queue<T>&)\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(::tools::persistent_queue<T>&&)\
    \ = default;\n\n    explicit persistent_queue(::tools::persistent_queue<T>::buffer&\
    \ buffer) : m_buffer(&buffer), m_front(EMPTY), m_back(EMPTY) {\n    }\n\n    bool\
    \ empty() const {\n      return this->m_front == EMPTY && this->m_back == EMPTY;\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth\
    \ - this->m_buffer->m_nodes[this->m_front].depth + 1;\n    }\n\n    T front()\
    \ const {\n      assert(!this->empty());\n      return this->m_buffer->m_nodes[this->m_front].value;\n\
    \    }\n\n    T back() const {\n      assert(!this->empty());\n      return this->m_buffer->m_nodes[this->m_back].value;\n\
    \    }\n\n    ::tools::persistent_queue<T> push(const T& x) const {\n      this->m_buffer->m_nodes.emplace_back();\n\
    \      this->m_buffer->m_nodes.back().depth = this->empty() ? 0 : this->m_buffer->m_nodes[this->m_back].depth\
    \ + 1;\n      this->m_buffer->m_nodes.back().value = x;\n      if (!this->empty())\
    \ {\n        ::std::size_t i = 0;\n        ::std::size_t v = this->m_back;\n \
    \       while (true) {\n          this->m_buffer->m_nodes.back().ancestors.push_back(v);\n\
    \          if (this->m_buffer->m_nodes[v].ancestors.size() <= i) break;\n    \
    \      v = this->m_buffer->m_nodes[v].ancestors[i];\n          ++i;\n        }\n\
    \      }\n      return ::tools::persistent_queue<T>(*this->m_buffer, this->empty()\
    \ ? this->m_buffer->m_nodes.size() - 1 : this->m_front, this->m_buffer->m_nodes.size()\
    \ - 1);\n    }\n\n    ::tools::persistent_queue<T> pop() const {\n      assert(!this->empty());\n\
    \      if (this->size() == 1) {\n        return ::tools::persistent_queue<T>(*this->m_buffer,\
    \ EMPTY, EMPTY);\n      }\n      ::std::size_t v = this->m_back;\n      for (::std::size_t\
    \ d = this->size() - 2, i = 0; d > 0; d /= 2, ++i) {\n        if (d % 2 == 1)\
    \ {\n          v = this->m_buffer->m_nodes[v].ancestors[i];\n        }\n     \
    \ }\n      return ::tools::persistent_queue<T>(*this->m_buffer, v, this->m_back);\n\
    \    }\n\n    template <typename... Args>\n    ::tools::persistent_queue<T> emplace(Args&&...\
    \ args) const {\n      return this->push(T(::std::forward<Args>(args)...));\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/persistent_queue.hpp
  requiredBy: []
  timestamp: '2022-04-16 09:34:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/persistent_queue.test.cpp
documentation_of: tools/persistent_queue.hpp
layout: document
title: Persistent queue
---

It is a persistent queue.

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
persistent_queue<T>::buffer buffer();
```

It creates an empty buffer for `tools::persistent_queue<T>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
persistent_queue<T> queue(persistent_queue<T>::buffer& buffer);
```

It creates an empty queue whose data stores on `buffer`.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool queue.empty();
```

It returns whether the queue is empty or not.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## size
```cpp
std::size_t queue.size();
```

It returns the current number of elements of the queue.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## front
```cpp
T queue.front();
```

It returns the oldest element in the queue.

### Constraints
- `buffer` is in its lifetime.
- `queue` is not empty.

### Time Complexity
- $O(1)$

## back
```cpp
T queue.back();
```

It returns the newest element in the queue.

### Constraints
- `buffer` is in its lifetime.
- `queue` is not empty.

### Time Complexity
- $O(1)$

## push
```cpp
persistent_queue<T> queue.push(T x);
```

It clones `queue`, adds `x` to the new queue and returns the new queue.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(\log N)$ where $N$ is the number of ever `push` or `emplace` calls

## pop
```cpp
persistent_queue<T> queue.pop();
```

It clones `queue`, removes the oldest element from the new queue and returns the new queue.

### Constraints
- `buffer` is in its lifetime.
- `queue` is not empty.

### Time Complexity
- $O(\log n)$ where $n$ is the number of elements of `queue`

## emplace
```cpp
template <typename... Args>
persistent_queue<T> emplace(Args&&... args);
```

It clones `queue`, adds `T(args...)` to the new queue and returns the new queue.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(\log N)$ where $N$ is the number of ever `push` or `emplace` calls
