---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/mex.hpp
    title: Minimum excluded value
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mex.test.cpp
    title: tests/mex.test.cpp
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
  requiredBy:
  - tools/mex.hpp
  timestamp: '2021-06-30 15:42:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/mex.test.cpp
documentation_of: tools/interval_set.hpp
layout: document
title: Set of closed intervals
---

It is a set of closed intervals.

## Usage
```cpp
tools::interval_set<int, false> set;

// It adds [1, 6] to the set.
// The set is now {[1, 6]}.
set.insert(1, 6);

// It removes [4, 5] from the set.
// The set is now {[1, 3], [6, 6]}.
set.erase(4, 5);

// It returns the iterator referring to the interval which contains 2, that is [1, 2].
set.find(2);

// It adds [4, 6] to the set.
// The set is now {[1, 3], [4, 6]}.
set.insert(4, 6);

// The second type parameter allows you to merge two adjacent intervals.
tools::interval_set<int, true> set2;

// The set is now {[1, 3], [6, 6]}.
set2.insert(1, 3);
set2.insert(6, 6);

// It adds [4, 5] to the set.
// The set is now {[1, 6]} because [1, 3], [4, 5] and [6, 6] are adjacent and regarded as mergeable intervals.
set2.insert(4, 5);
```

## License
- CC0

## Author
- anqooqie
