---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/persistent_queue.test.cpp
    title: tests/persistent_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/persistent_queue.hpp\"\n\n\n\n#include <vector>\n\
    #include <cstddef>\n#include <cassert>\n#include <type_traits>\n#include <limits>\n\
    \nnamespace tools {\n  template <typename T>\n  class persistent_queue_buffer;\n\
    \n  namespace detail {\n    namespace persistent_queue {\n      template <typename\
    \ T>\n      struct node;\n    }\n  }\n\n  template <typename T>\n  class persistent_queue;\n\
    \n  template <typename T>\n  class persistent_queue_buffer {\n  private:\n   \
    \ ::std::vector<::tools::detail::persistent_queue::node<T>> m_nodes;\n    ::std::vector<::tools::persistent_queue<T>>\
    \ m_queues;\n\n  public:\n    persistent_queue_buffer() = default;\n    persistent_queue_buffer(const\
    \ ::tools::persistent_queue_buffer<T>&) = default;\n    persistent_queue_buffer(::tools::persistent_queue_buffer<T>&&)\
    \ = default;\n    ~persistent_queue_buffer() = default;\n    ::tools::persistent_queue_buffer<T>&\
    \ operator=(const ::tools::persistent_queue_buffer<T>&) = default;\n    ::tools::persistent_queue_buffer<T>&\
    \ operator=(::tools::persistent_queue_buffer<T>&&) = default;\n\n    bool empty()\
    \ const {\n      return this->m_queues.empty();\n    }\n\n    ::std::size_t size()\
    \ const {\n      return this->m_queues.size();\n    }\n\n    ::tools::persistent_queue<T>\
    \ operator[](const ::std::size_t i) const {\n      assert(i < this->size());\n\
    \      return this->m_queues[i];\n    }\n\n    const ::tools::persistent_queue<T>&\
    \ front() const {\n      assert(!this->empty());\n      return this->m_queues.front();\n\
    \    }\n\n    const ::tools::persistent_queue<T>& back() const {\n      assert(!this->empty());\n\
    \      return this->m_queues.back();\n    }\n\n    void push_back(const ::tools::persistent_queue<T>&\
    \ x) {\n      this->m_queues.push_back(x);\n    }\n\n    template <typename...\
    \ Args>\n    ::tools::persistent_queue<T>& emplace_back(Args&&... args) {\n  \
    \    return this->m_queues.emplace_back(this, ::std::forward<Args>(args)...);\n\
    \    }\n\n    void pop_back() {\n      this->m_queues.pop_back();\n    }\n\n \
    \   void clear() {\n      this->m_queues.clear();\n    }\n\n    friend ::tools::persistent_queue<T>;\n\
    \  };\n\n  namespace detail {\n    namespace persistent_queue {\n      template\
    \ <typename T>\n      struct node {\n      private:\n        ::std::vector<::std::size_t>\
    \ m_ancestors;\n        ::std::size_t m_depth;\n        T m_value;\n\n      public:\n\
    \        node() = default;\n        node(const ::tools::detail::persistent_queue::node<T>&)\
    \ = default;\n        node(::tools::detail::persistent_queue::node<T>&&) = default;\n\
    \        ~node() = default;\n        ::tools::detail::persistent_queue::node<T>&\
    \ operator=(const ::tools::detail::persistent_queue::node<T>&) = default;\n  \
    \      ::tools::detail::persistent_queue::node<T>& operator=(::tools::detail::persistent_queue::node<T>&&)\
    \ = default;\n\n        node(const ::std::vector<::std::size_t>& ancestors, const\
    \ ::std::size_t depth, const T& value) : m_ancestors(ancestors), m_depth(depth),\
    \ m_value(value) {\n        }\n\n        const ::std::vector<::std::size_t>& ancestors()\
    \ const {\n          return this->m_ancestors;\n        }\n        ::std::size_t\
    \ depth() const {\n          return this->m_depth;\n        }\n        const T&\
    \ value() const {\n          return this->m_value;\n        }\n      };\n    }\n\
    \  }\n\n  template <typename T>\n  class persistent_queue {\n  private:\n    static\
    \ const ::std::size_t EMPTY = ::std::numeric_limits<::std::size_t>::max();\n \
    \   ::tools::persistent_queue_buffer<T> *m_buffer;\n    ::std::size_t m_front;\n\
    \    ::std::size_t m_back;\n\n    persistent_queue(::tools::persistent_queue_buffer<T>\
    \ * const buffer, const ::std::size_t front, const ::std::size_t back) : m_buffer(buffer),\
    \ m_front(front), m_back(back) {\n    }\n\n  public:\n    persistent_queue() =\
    \ default;\n    persistent_queue(const ::tools::persistent_queue<T>&) = default;\n\
    \    persistent_queue(::tools::persistent_queue<T>&&) = default;\n    ~persistent_queue()\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(const ::tools::persistent_queue<T>&)\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(::tools::persistent_queue<T>&&)\
    \ = default;\n\n    explicit persistent_queue(::tools::persistent_queue_buffer<T>\
    \ * const buffer) : m_buffer(buffer), m_front(EMPTY), m_back(EMPTY) {\n    }\n\
    \n    bool empty() const {\n      return this->m_front == EMPTY && this->m_back\
    \ == EMPTY;\n    }\n\n    ::std::size_t size() const {\n      return this->empty()\
    \ ? 0 : this->m_buffer->m_nodes[this->m_back].depth() - this->m_buffer->m_nodes[this->m_front].depth()\
    \ + 1;\n    }\n\n    T front() const {\n      assert(!this->empty());\n      return\
    \ this->m_buffer->m_nodes[this->m_front].value();\n    }\n\n    T back() const\
    \ {\n      assert(!this->empty());\n      return this->m_buffer->m_nodes[this->m_back].value();\n\
    \    }\n\n    ::tools::persistent_queue<T> push(const T& x) const {\n      ::std::vector<::std::size_t>\
    \ ancestors;\n      if (!this->empty()) {\n        ::std::size_t i = 0;\n    \
    \    ::std::size_t v = this->m_back;\n        while (true) {\n          ancestors.push_back(v);\n\
    \          if (this->m_buffer->m_nodes[v].ancestors().size() <= i) break;\n  \
    \        v = this->m_buffer->m_nodes[v].ancestors()[i];\n          ++i;\n    \
    \    }\n      }\n      this->m_buffer->m_nodes.emplace_back(ancestors, this->empty()\
    \ ? 0 : this->m_buffer->m_nodes[this->m_back].depth() + 1, x);\n      return ::tools::persistent_queue<T>(this->m_buffer,\
    \ this->empty() ? this->m_buffer->m_nodes.size() - 1 : this->m_front, this->m_buffer->m_nodes.size()\
    \ - 1);\n    }\n\n    ::tools::persistent_queue<T> pop() const {\n      assert(!this->empty());\n\
    \      if (this->size() == 1) {\n        return ::tools::persistent_queue<T>(this->m_buffer,\
    \ EMPTY, EMPTY);\n      }\n      ::std::size_t v = this->m_back;\n      for (::std::size_t\
    \ d = this->size() - 2, i = 0; d > 0; d /= 2, ++i) {\n        if (d % 2 == 1)\
    \ {\n          v = this->m_buffer->m_nodes[v].ancestors()[i];\n        }\n   \
    \   }\n      return ::tools::persistent_queue<T>(this->m_buffer, v, this->m_back);\n\
    \    }\n\n    template <typename... Args>\n    ::tools::persistent_queue<T> emplace(Args&&...\
    \ args) const {\n      return this->push(T(::std::forward<Args>(args)...));\n\
    \    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PERSISTENT_QUEUE_HPP\n#define TOOLS_PERSISTENT_QUEUE_HPP\n\n\
    #include <vector>\n#include <cstddef>\n#include <cassert>\n#include <type_traits>\n\
    #include <limits>\n\nnamespace tools {\n  template <typename T>\n  class persistent_queue_buffer;\n\
    \n  namespace detail {\n    namespace persistent_queue {\n      template <typename\
    \ T>\n      struct node;\n    }\n  }\n\n  template <typename T>\n  class persistent_queue;\n\
    \n  template <typename T>\n  class persistent_queue_buffer {\n  private:\n   \
    \ ::std::vector<::tools::detail::persistent_queue::node<T>> m_nodes;\n    ::std::vector<::tools::persistent_queue<T>>\
    \ m_queues;\n\n  public:\n    persistent_queue_buffer() = default;\n    persistent_queue_buffer(const\
    \ ::tools::persistent_queue_buffer<T>&) = default;\n    persistent_queue_buffer(::tools::persistent_queue_buffer<T>&&)\
    \ = default;\n    ~persistent_queue_buffer() = default;\n    ::tools::persistent_queue_buffer<T>&\
    \ operator=(const ::tools::persistent_queue_buffer<T>&) = default;\n    ::tools::persistent_queue_buffer<T>&\
    \ operator=(::tools::persistent_queue_buffer<T>&&) = default;\n\n    bool empty()\
    \ const {\n      return this->m_queues.empty();\n    }\n\n    ::std::size_t size()\
    \ const {\n      return this->m_queues.size();\n    }\n\n    ::tools::persistent_queue<T>\
    \ operator[](const ::std::size_t i) const {\n      assert(i < this->size());\n\
    \      return this->m_queues[i];\n    }\n\n    const ::tools::persistent_queue<T>&\
    \ front() const {\n      assert(!this->empty());\n      return this->m_queues.front();\n\
    \    }\n\n    const ::tools::persistent_queue<T>& back() const {\n      assert(!this->empty());\n\
    \      return this->m_queues.back();\n    }\n\n    void push_back(const ::tools::persistent_queue<T>&\
    \ x) {\n      this->m_queues.push_back(x);\n    }\n\n    template <typename...\
    \ Args>\n    ::tools::persistent_queue<T>& emplace_back(Args&&... args) {\n  \
    \    return this->m_queues.emplace_back(this, ::std::forward<Args>(args)...);\n\
    \    }\n\n    void pop_back() {\n      this->m_queues.pop_back();\n    }\n\n \
    \   void clear() {\n      this->m_queues.clear();\n    }\n\n    friend ::tools::persistent_queue<T>;\n\
    \  };\n\n  namespace detail {\n    namespace persistent_queue {\n      template\
    \ <typename T>\n      struct node {\n      private:\n        ::std::vector<::std::size_t>\
    \ m_ancestors;\n        ::std::size_t m_depth;\n        T m_value;\n\n      public:\n\
    \        node() = default;\n        node(const ::tools::detail::persistent_queue::node<T>&)\
    \ = default;\n        node(::tools::detail::persistent_queue::node<T>&&) = default;\n\
    \        ~node() = default;\n        ::tools::detail::persistent_queue::node<T>&\
    \ operator=(const ::tools::detail::persistent_queue::node<T>&) = default;\n  \
    \      ::tools::detail::persistent_queue::node<T>& operator=(::tools::detail::persistent_queue::node<T>&&)\
    \ = default;\n\n        node(const ::std::vector<::std::size_t>& ancestors, const\
    \ ::std::size_t depth, const T& value) : m_ancestors(ancestors), m_depth(depth),\
    \ m_value(value) {\n        }\n\n        const ::std::vector<::std::size_t>& ancestors()\
    \ const {\n          return this->m_ancestors;\n        }\n        ::std::size_t\
    \ depth() const {\n          return this->m_depth;\n        }\n        const T&\
    \ value() const {\n          return this->m_value;\n        }\n      };\n    }\n\
    \  }\n\n  template <typename T>\n  class persistent_queue {\n  private:\n    static\
    \ const ::std::size_t EMPTY = ::std::numeric_limits<::std::size_t>::max();\n \
    \   ::tools::persistent_queue_buffer<T> *m_buffer;\n    ::std::size_t m_front;\n\
    \    ::std::size_t m_back;\n\n    persistent_queue(::tools::persistent_queue_buffer<T>\
    \ * const buffer, const ::std::size_t front, const ::std::size_t back) : m_buffer(buffer),\
    \ m_front(front), m_back(back) {\n    }\n\n  public:\n    persistent_queue() =\
    \ default;\n    persistent_queue(const ::tools::persistent_queue<T>&) = default;\n\
    \    persistent_queue(::tools::persistent_queue<T>&&) = default;\n    ~persistent_queue()\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(const ::tools::persistent_queue<T>&)\
    \ = default;\n    ::tools::persistent_queue<T>& operator=(::tools::persistent_queue<T>&&)\
    \ = default;\n\n    explicit persistent_queue(::tools::persistent_queue_buffer<T>\
    \ * const buffer) : m_buffer(buffer), m_front(EMPTY), m_back(EMPTY) {\n    }\n\
    \n    bool empty() const {\n      return this->m_front == EMPTY && this->m_back\
    \ == EMPTY;\n    }\n\n    ::std::size_t size() const {\n      return this->empty()\
    \ ? 0 : this->m_buffer->m_nodes[this->m_back].depth() - this->m_buffer->m_nodes[this->m_front].depth()\
    \ + 1;\n    }\n\n    T front() const {\n      assert(!this->empty());\n      return\
    \ this->m_buffer->m_nodes[this->m_front].value();\n    }\n\n    T back() const\
    \ {\n      assert(!this->empty());\n      return this->m_buffer->m_nodes[this->m_back].value();\n\
    \    }\n\n    ::tools::persistent_queue<T> push(const T& x) const {\n      ::std::vector<::std::size_t>\
    \ ancestors;\n      if (!this->empty()) {\n        ::std::size_t i = 0;\n    \
    \    ::std::size_t v = this->m_back;\n        while (true) {\n          ancestors.push_back(v);\n\
    \          if (this->m_buffer->m_nodes[v].ancestors().size() <= i) break;\n  \
    \        v = this->m_buffer->m_nodes[v].ancestors()[i];\n          ++i;\n    \
    \    }\n      }\n      this->m_buffer->m_nodes.emplace_back(ancestors, this->empty()\
    \ ? 0 : this->m_buffer->m_nodes[this->m_back].depth() + 1, x);\n      return ::tools::persistent_queue<T>(this->m_buffer,\
    \ this->empty() ? this->m_buffer->m_nodes.size() - 1 : this->m_front, this->m_buffer->m_nodes.size()\
    \ - 1);\n    }\n\n    ::tools::persistent_queue<T> pop() const {\n      assert(!this->empty());\n\
    \      if (this->size() == 1) {\n        return ::tools::persistent_queue<T>(this->m_buffer,\
    \ EMPTY, EMPTY);\n      }\n      ::std::size_t v = this->m_back;\n      for (::std::size_t\
    \ d = this->size() - 2, i = 0; d > 0; d /= 2, ++i) {\n        if (d % 2 == 1)\
    \ {\n          v = this->m_buffer->m_nodes[v].ancestors()[i];\n        }\n   \
    \   }\n      return ::tools::persistent_queue<T>(this->m_buffer, v, this->m_back);\n\
    \    }\n\n    template <typename... Args>\n    ::tools::persistent_queue<T> emplace(Args&&...\
    \ args) const {\n      return this->push(T(::std::forward<Args>(args)...));\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/persistent_queue.hpp
  requiredBy: []
  timestamp: '2022-04-05 01:39:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/persistent_queue.test.cpp
documentation_of: tools/persistent_queue.hpp
layout: document
redirect_from:
- /library/tools/persistent_queue.hpp
- /library/tools/persistent_queue.hpp.html
title: tools/persistent_queue.hpp
---
