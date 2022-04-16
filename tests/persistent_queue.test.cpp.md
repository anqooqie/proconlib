---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/persistent_queue.hpp
    title: Persistent queue
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"tests/persistent_queue.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#line 1 \"tools/persistent_queue.hpp\"\
    \n\n\n\n#line 5 \"tools/persistent_queue.hpp\"\n#include <cstddef>\n#include <limits>\n\
    #include <cassert>\n#include <type_traits>\n\nnamespace tools {\n  template <typename\
    \ T>\n  class persistent_queue {\n  private:\n    struct node {\n      ::std::vector<::std::size_t>\
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
    \    }\n  };\n}\n\n\n#line 7 \"tests/persistent_queue.test.cpp\"\n\nusing i64\
    \ = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  tools::persistent_queue<i64>::buffer buffer;\n  std::vector<tools::persistent_queue<i64>>\
    \ S;\n  S.emplace_back(buffer);\n  i64 Q;\n  std::cin >> Q;\n  for (i64 q = 0;\
    \ q < Q; ++q) {\n    i64 type;\n    std::cin >> type;\n    if (type == 0) {\n\
    \      i64 t, x;\n      std::cin >> t >> x;\n      ++t;\n      S.push_back(S[t].push(x));\n\
    \    } else {\n      i64 t;\n      std::cin >> t;\n      ++t;\n      std::cout\
    \ << S[t].front() << '\\n';\n      S.push_back(S[t].pop());\n    }\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n#include \"tools/persistent_queue.hpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  tools::persistent_queue<i64>::buffer\
    \ buffer;\n  std::vector<tools::persistent_queue<i64>> S;\n  S.emplace_back(buffer);\n\
    \  i64 Q;\n  std::cin >> Q;\n  for (i64 q = 0; q < Q; ++q) {\n    i64 type;\n\
    \    std::cin >> type;\n    if (type == 0) {\n      i64 t, x;\n      std::cin\
    \ >> t >> x;\n      ++t;\n      S.push_back(S[t].push(x));\n    } else {\n   \
    \   i64 t;\n      std::cin >> t;\n      ++t;\n      std::cout << S[t].front()\
    \ << '\\n';\n      S.push_back(S[t].pop());\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/persistent_queue.hpp
  isVerificationFile: true
  path: tests/persistent_queue.test.cpp
  requiredBy: []
  timestamp: '2022-04-16 09:34:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/tests/persistent_queue.test.cpp
- /verify/tests/persistent_queue.test.cpp.html
title: tests/persistent_queue.test.cpp
---
