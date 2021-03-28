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
  bundledCode: "#line 1 \"tools/priority_queue.hpp\"\n\n\n\n#include <functional>\n\
    #include <utility>\n#include <queue>\n#include <vector>\n#include <unordered_map>\n\
    \nnamespace tools {\n\n  template <class T, class Priority, class Compare = ::std::less<Priority>>\n\
    \  class priority_queue {\n  private:\n    class compare_by_priority {\n    private:\n\
    \      Compare compare;\n\n    public:\n      compare_by_priority(const Compare&\
    \ compare) : compare(compare) {\n      }\n\n      bool operator()(const ::std::pair<T,\
    \ Priority>& x, const ::std::pair<T, Priority>& y) const {\n        return this->compare(x.second,\
    \ y.second) || (!this->compare(x.second, y.second) && !this->compare(y.second,\
    \ x.second) && x.first < y.first);\n      }\n    };\n\n    ::std::priority_queue<::std::pair<T,\
    \ Priority>, ::std::vector<::std::pair<T, Priority>>, compare_by_priority> heap;\n\
    \    ::std::priority_queue<::std::pair<T, Priority>, ::std::vector<::std::pair<T,\
    \ Priority>>, compare_by_priority> outdated;\n    ::std::unordered_map<T, Priority>\
    \ latest_priority;\n\n  public:\n    using container_type = ::std::vector<::std::pair<T,\
    \ Priority>>;\n    using value_type = typename container_type::value_type;\n \
    \   using reference = typename container_type::reference;\n    using const_reference\
    \ = typename container_type::const_reference;\n    using size_type = typename\
    \ container_type::size_type;\n\n    explicit priority_queue(const Compare& compare\
    \ = Compare()) : heap(compare), outdated(compare) {\n    }\n    priority_queue(const\
    \ priority_queue&) = default;\n    priority_queue(priority_queue&&) = default;\n\
    \    ~priority_queue() = default;\n    priority_queue& operator=(const priority_queue&)\
    \ = default;\n    priority_queue& operator=(priority_queue&&) = default;\n\n \
    \   bool empty() const {\n      return this->latest_priority.empty();\n    }\n\
    \n    size_type size() const {\n      return this->latest_priority.size();\n \
    \   }\n\n    Priority at(const T& k) const {\n      return this->latest_priority.at(k);\n\
    \    }\n\n    const_reference top() {\n      while (!this->outdated.empty() &&\
    \ this->outdated.top() == this->heap.top()) {\n        this->outdated.pop();\n\
    \        this->heap.pop();\n      }\n      return this->heap.top();\n    }\n\n\
    \    void push(const value_type& x) {\n      if (auto it = this->latest_priority.find(x.first);\
    \ it != this->latest_priority.end()) {\n        if (it->second == x.second) return;\n\
    \        this->outdated.push(*it);\n        this->heap.push(x);\n        it->second\
    \ = x.second;\n      } else {\n        this->heap.push(x);\n        this->latest_priority.insert(x);\n\
    \      }\n    }\n\n    void pop() {\n      while (!this->outdated.empty() && this->outdated.top()\
    \ == this->heap.top()) {\n        this->outdated.pop();\n        this->heap.pop();\n\
    \      }\n      this->latest_priority.erase(this->heap.top().first);\n      this->heap.pop();\n\
    \    }\n\n    size_type erase(const T& k) {\n      if (auto it = this->latest_priority.find(k);\
    \ it != this->latest_priority.end()) {\n        this->outdated.push(*it);\n  \
    \      this->latest_priority.erase(it);\n        return 1;\n      } else {\n \
    \       return 0;\n      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_PRIORITY_QUEUE_HPP\n#define TOOLS_PRIORITY_QUEUE_HPP\n\n#include\
    \ <functional>\n#include <utility>\n#include <queue>\n#include <vector>\n#include\
    \ <unordered_map>\n\nnamespace tools {\n\n  template <class T, class Priority,\
    \ class Compare = ::std::less<Priority>>\n  class priority_queue {\n  private:\n\
    \    class compare_by_priority {\n    private:\n      Compare compare;\n\n   \
    \ public:\n      compare_by_priority(const Compare& compare) : compare(compare)\
    \ {\n      }\n\n      bool operator()(const ::std::pair<T, Priority>& x, const\
    \ ::std::pair<T, Priority>& y) const {\n        return this->compare(x.second,\
    \ y.second) || (!this->compare(x.second, y.second) && !this->compare(y.second,\
    \ x.second) && x.first < y.first);\n      }\n    };\n\n    ::std::priority_queue<::std::pair<T,\
    \ Priority>, ::std::vector<::std::pair<T, Priority>>, compare_by_priority> heap;\n\
    \    ::std::priority_queue<::std::pair<T, Priority>, ::std::vector<::std::pair<T,\
    \ Priority>>, compare_by_priority> outdated;\n    ::std::unordered_map<T, Priority>\
    \ latest_priority;\n\n  public:\n    using container_type = ::std::vector<::std::pair<T,\
    \ Priority>>;\n    using value_type = typename container_type::value_type;\n \
    \   using reference = typename container_type::reference;\n    using const_reference\
    \ = typename container_type::const_reference;\n    using size_type = typename\
    \ container_type::size_type;\n\n    explicit priority_queue(const Compare& compare\
    \ = Compare()) : heap(compare), outdated(compare) {\n    }\n    priority_queue(const\
    \ priority_queue&) = default;\n    priority_queue(priority_queue&&) = default;\n\
    \    ~priority_queue() = default;\n    priority_queue& operator=(const priority_queue&)\
    \ = default;\n    priority_queue& operator=(priority_queue&&) = default;\n\n \
    \   bool empty() const {\n      return this->latest_priority.empty();\n    }\n\
    \n    size_type size() const {\n      return this->latest_priority.size();\n \
    \   }\n\n    Priority at(const T& k) const {\n      return this->latest_priority.at(k);\n\
    \    }\n\n    const_reference top() {\n      while (!this->outdated.empty() &&\
    \ this->outdated.top() == this->heap.top()) {\n        this->outdated.pop();\n\
    \        this->heap.pop();\n      }\n      return this->heap.top();\n    }\n\n\
    \    void push(const value_type& x) {\n      if (auto it = this->latest_priority.find(x.first);\
    \ it != this->latest_priority.end()) {\n        if (it->second == x.second) return;\n\
    \        this->outdated.push(*it);\n        this->heap.push(x);\n        it->second\
    \ = x.second;\n      } else {\n        this->heap.push(x);\n        this->latest_priority.insert(x);\n\
    \      }\n    }\n\n    void pop() {\n      while (!this->outdated.empty() && this->outdated.top()\
    \ == this->heap.top()) {\n        this->outdated.pop();\n        this->heap.pop();\n\
    \      }\n      this->latest_priority.erase(this->heap.top().first);\n      this->heap.pop();\n\
    \    }\n\n    size_type erase(const T& k) {\n      if (auto it = this->latest_priority.find(k);\
    \ it != this->latest_priority.end()) {\n        this->outdated.push(*it);\n  \
    \      this->latest_priority.erase(it);\n        return 1;\n      } else {\n \
    \       return 0;\n      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/priority_queue.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/priority_queue.hpp
layout: document
title: Updatable priority queue
---

It is nearly `std::prirority_queue`, but allows you to update priority.

## Usage
```cpp
tools::priority_queue<std::string, int> pq;
pq.push(std::make_pair("abc", 5));
const std::pair<std::string, int> pair = pq.top();
pq.push(std::make_pair("abc", 7));
pq.erase("abc");
```

## License
- CC0

## Author
- anqooqie
