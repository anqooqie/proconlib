---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/interval_set.test.cpp
    title: tests/interval_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/interval_set.hpp\"\n\n\n\n#include <map>\n#include\
    \ <iterator>\n#include <optional>\n#include <utility>\n#include <iostream>\n#include\
    \ <string>\n\nnamespace tools {\n  template <typename T, bool Mergeable>\n  class\
    \ interval_set {\n  private:\n    // closed intervals\n    ::std::map<T, T> m_intervals;\n\
    \n  public:\n    interval_set() = default;\n    interval_set(const ::tools::interval_set<T,\
    \ Mergeable>&) = default;\n    interval_set(::tools::interval_set<T, Mergeable>&&)\
    \ = default;\n    ~interval_set() = default;\n    ::tools::interval_set<T, Mergeable>&\
    \ operator=(const ::tools::interval_set<T, Mergeable>&) = default;\n    ::tools::interval_set<T,\
    \ Mergeable>& operator=(::tools::interval_set<T, Mergeable>&&) = default;\n\n\
    \    auto begin() const {\n      return this->m_intervals.begin();\n    }\n\n\
    \    auto end() const {\n      return this->m_intervals.end();\n    }\n\n    bool\
    \ empty() const {\n      return this->m_intervals.empty();\n    }\n\n    auto\
    \ size() const {\n      return this->m_intervals.size();\n    }\n\n    auto find(const\
    \ T& x) const {\n      const auto next = this->m_intervals.upper_bound(x);\n \
    \     if (next == this->m_intervals.begin()) return this->m_intervals.end();\n\
    \      const auto prev = ::std::prev(next);\n      if (prev->second < x) return\
    \ this->m_intervals.end();\n      return prev;\n    }\n\n    bool contains(const\
    \ T& x) const {\n      return this->find(x) != this->m_intervals.end();\n    }\n\
    \n    auto lower_bound(const T& x) const {\n      const auto next = this->m_intervals.lower_bound(x);\n\
    \      if (next == this->m_intervals.begin()) return next;\n      const auto prev\
    \ = ::std::prev(next);\n      if (prev->second < x) return next;\n      return\
    \ prev;\n    }\n\n    auto upper_bound(const T& x) const {\n      return this->m_intervals.upper_bound(x);\n\
    \    }\n\n    void insert(const T& l, const T& r) {\n      if (l > r) {\n    \
    \    return;\n      }\n\n      const auto l_it = this->find(l - (Mergeable ? 1\
    \ : 0));\n      const T min = l_it != this->m_intervals.end() ? l_it->first :\
    \ l;\n      const auto r_it = this->find(r + (Mergeable ? 1 : 0));\n      const\
    \ T max = r_it != this->m_intervals.end() ? r_it->second : r;\n\n      this->m_intervals.erase(this->lower_bound(l\
    \ - (Mergeable ? 1 : 0)), this->upper_bound(r + (Mergeable ? 1 : 0)));\n     \
    \ this->m_intervals.emplace(min, max);\n    }\n\n    void erase(const T& l, const\
    \ T& r) {\n      if (l > r) {\n        return;\n      }\n\n      const auto l_it\
    \ = this->find(l);\n      const auto l_new_interval = l_it != this->m_intervals.end()\
    \ && l_it->first < l\n        ? ::std::make_optional(::std::make_pair(l_it->first,\
    \ l - 1))\n        : ::std::nullopt;\n      const auto r_it = this->find(r);\n\
    \      const auto r_new_interval = r_it != this->m_intervals.end() && r < r_it->second\n\
    \        ? ::std::make_optional(::std::make_pair(r + 1, r_it->second))\n     \
    \   : ::std::nullopt;\n\n      this->m_intervals.erase(this->lower_bound(l), this->upper_bound(r));\n\
    \n      if (l_new_interval) {\n        this->m_intervals.emplace(l_new_interval->first,\
    \ l_new_interval->second);\n      }\n      if (r_new_interval) {\n        this->m_intervals.emplace(r_new_interval->first,\
    \ r_new_interval->second);\n      }\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::interval_set<T, Mergeable>& self) {\n      os << '{';\n \
    \     ::std::string delimiter = \"\";\n      for (const auto& [l, r] : self) {\n\
    \        os << delimiter << '[' << l << \", \" << r << ']';\n        delimiter\
    \ = \", \";\n      }\n      os << '}';\n      return os;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_INTERVAL_SET_HPP\n#define TOOLS_INTERVAL_SET_HPP\n\n#include\
    \ <map>\n#include <iterator>\n#include <optional>\n#include <utility>\n#include\
    \ <iostream>\n#include <string>\n\nnamespace tools {\n  template <typename T,\
    \ bool Mergeable>\n  class interval_set {\n  private:\n    // closed intervals\n\
    \    ::std::map<T, T> m_intervals;\n\n  public:\n    interval_set() = default;\n\
    \    interval_set(const ::tools::interval_set<T, Mergeable>&) = default;\n   \
    \ interval_set(::tools::interval_set<T, Mergeable>&&) = default;\n    ~interval_set()\
    \ = default;\n    ::tools::interval_set<T, Mergeable>& operator=(const ::tools::interval_set<T,\
    \ Mergeable>&) = default;\n    ::tools::interval_set<T, Mergeable>& operator=(::tools::interval_set<T,\
    \ Mergeable>&&) = default;\n\n    auto begin() const {\n      return this->m_intervals.begin();\n\
    \    }\n\n    auto end() const {\n      return this->m_intervals.end();\n    }\n\
    \n    bool empty() const {\n      return this->m_intervals.empty();\n    }\n\n\
    \    auto size() const {\n      return this->m_intervals.size();\n    }\n\n  \
    \  auto find(const T& x) const {\n      const auto next = this->m_intervals.upper_bound(x);\n\
    \      if (next == this->m_intervals.begin()) return this->m_intervals.end();\n\
    \      const auto prev = ::std::prev(next);\n      if (prev->second < x) return\
    \ this->m_intervals.end();\n      return prev;\n    }\n\n    bool contains(const\
    \ T& x) const {\n      return this->find(x) != this->m_intervals.end();\n    }\n\
    \n    auto lower_bound(const T& x) const {\n      const auto next = this->m_intervals.lower_bound(x);\n\
    \      if (next == this->m_intervals.begin()) return next;\n      const auto prev\
    \ = ::std::prev(next);\n      if (prev->second < x) return next;\n      return\
    \ prev;\n    }\n\n    auto upper_bound(const T& x) const {\n      return this->m_intervals.upper_bound(x);\n\
    \    }\n\n    void insert(const T& l, const T& r) {\n      if (l > r) {\n    \
    \    return;\n      }\n\n      const auto l_it = this->find(l - (Mergeable ? 1\
    \ : 0));\n      const T min = l_it != this->m_intervals.end() ? l_it->first :\
    \ l;\n      const auto r_it = this->find(r + (Mergeable ? 1 : 0));\n      const\
    \ T max = r_it != this->m_intervals.end() ? r_it->second : r;\n\n      this->m_intervals.erase(this->lower_bound(l\
    \ - (Mergeable ? 1 : 0)), this->upper_bound(r + (Mergeable ? 1 : 0)));\n     \
    \ this->m_intervals.emplace(min, max);\n    }\n\n    void erase(const T& l, const\
    \ T& r) {\n      if (l > r) {\n        return;\n      }\n\n      const auto l_it\
    \ = this->find(l);\n      const auto l_new_interval = l_it != this->m_intervals.end()\
    \ && l_it->first < l\n        ? ::std::make_optional(::std::make_pair(l_it->first,\
    \ l - 1))\n        : ::std::nullopt;\n      const auto r_it = this->find(r);\n\
    \      const auto r_new_interval = r_it != this->m_intervals.end() && r < r_it->second\n\
    \        ? ::std::make_optional(::std::make_pair(r + 1, r_it->second))\n     \
    \   : ::std::nullopt;\n\n      this->m_intervals.erase(this->lower_bound(l), this->upper_bound(r));\n\
    \n      if (l_new_interval) {\n        this->m_intervals.emplace(l_new_interval->first,\
    \ l_new_interval->second);\n      }\n      if (r_new_interval) {\n        this->m_intervals.emplace(r_new_interval->first,\
    \ r_new_interval->second);\n      }\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::interval_set<T, Mergeable>& self) {\n      os << '{';\n \
    \     ::std::string delimiter = \"\";\n      for (const auto& [l, r] : self) {\n\
    \        os << delimiter << '[' << l << \", \" << r << ']';\n        delimiter\
    \ = \", \";\n      }\n      os << '}';\n      return os;\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/interval_set.hpp
  requiredBy: []
  timestamp: '2021-06-30 15:42:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/interval_set.test.cpp
documentation_of: tools/interval_set.hpp
layout: document
title: Set of closed integer intervals
---

It is a set of closed integer intervals.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) interval_set<T, false> set;
(2) interval_set<T, true> set;
```

It creates an empty set of closed integer intervals.
The type parameter `<T>` represents the type of integers.

It internally manages `std::map<T, T> m` whose key is the lower bound of an interval and value is the upper bound of an interval.

- (1)
    - Adjacent intervals will not be merged. For example, $\\{[1, 3], [6, 6]\\} \cup \\{[4, 5]\\} = \\{[1, 3], [4, 5], [6, 6]\\}$.
- (2)
    - Adjacent intervals will be merged. For example, $\\{[1, 3], [6, 6]\\} \cup \\{[4, 5]\\} = \\{[1, 6]\\}$.

### Constraints
- None

### Time Complexity
- $O(1)$

## begin
```cpp
std::map<T, T>::const_iterator set.begin();
```

It returns an iterator pointing to the least closed integer interval.
In other words, it returns `m.begin()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## end
```cpp
std::map<T, T>::const_iterator set.end();
```

It returns an iterator pointing to the interval which would follow the greatest closed integer interval.
In other words, it returns `m.end()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## empty
```cpp
bool set.empty();
```

It returns whether the set is empty or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
std::map<T, T>::size_type set.size();
```

It returns the number of closed integer intervals.
In other words, it returns `m.size()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## find
```cpp
std::map<T, T>::const_iterator set.find(T x);
```

It returns an iterator pointing to the interval which contains $x$.
If such the interval does not exist, it returns `set.end()`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## contains
```cpp
bool set.contains(T x);
```

It returns whether the set contains $x$ or not.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## lower_bound
```cpp
std::map<T, T>::const_iterator set.lower_bound(T x);
```

It returns an iterator pointing to the least interval whose upper bound is greater than or equal to $x$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## upper_bound
```cpp
std::map<T, T>::const_iterator set.upper_bound(T x);
```

It returns an iterator pointing to the least interval whose lower bound is greater than $x$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## insert
```cpp
void set.insert(T l, T r);
```

It inserts a interval $\\{l, r\\}$ to the set.
Duplicated intervals will be merged one interval.
For example, $\\{[1, 3], [6, 6]\\} \cup \\{[2, 4]\\} = \\{[1, 4], [6, 6]\\}$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.

## erase
```cpp
void set.erase(T l, T r);
```

It removes a interval $\\{l, r\\}$ from the set.
For example, $\\{[1, 4], [6, 6]\\} - \\{[2, 3]\\} = \\{[1, 1], [4, 4], [6, 6]\\}$.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of intervals.
