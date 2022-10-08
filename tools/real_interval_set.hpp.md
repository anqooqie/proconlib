---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/detail/interval_set.hpp
    title: tools/detail/interval_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/real_interval_set.test.cpp
    title: tests/real_interval_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/real_interval_set.hpp\"\n\n\n\n#line 1 \"tools/detail/interval_set.hpp\"\
    \n\n\n\n#include <map>\n#include <iterator>\n#include <optional>\n#include <utility>\n\
    #include <iostream>\n#include <string>\n\nnamespace tools {\n  namespace detail\
    \ {\n    template <typename T, bool Mergeable>\n    class interval_set {\n   \
    \ private:\n      // closed intervals\n      ::std::map<T, T> m_intervals;\n \
    \ \n    public:\n      interval_set() = default;\n      interval_set(const ::tools::detail::interval_set<T,\
    \ Mergeable>&) = default;\n      interval_set(::tools::detail::interval_set<T,\
    \ Mergeable>&&) = default;\n      ~interval_set() = default;\n      ::tools::detail::interval_set<T,\
    \ Mergeable>& operator=(const ::tools::detail::interval_set<T, Mergeable>&) =\
    \ default;\n      ::tools::detail::interval_set<T, Mergeable>& operator=(::tools::detail::interval_set<T,\
    \ Mergeable>&&) = default;\n  \n      auto begin() const {\n        return this->m_intervals.begin();\n\
    \      }\n  \n      auto end() const {\n        return this->m_intervals.end();\n\
    \      }\n  \n      bool empty() const {\n        return this->m_intervals.empty();\n\
    \      }\n  \n      auto size() const {\n        return this->m_intervals.size();\n\
    \      }\n  \n      auto find(const T& x) const {\n        const auto next = this->m_intervals.upper_bound(x);\n\
    \        if (next == this->m_intervals.begin()) return this->m_intervals.end();\n\
    \        const auto prev = ::std::prev(next);\n        if (prev->second < x) return\
    \ this->m_intervals.end();\n        return prev;\n      }\n  \n      bool contains(const\
    \ T& x) const {\n        return this->find(x) != this->m_intervals.end();\n  \
    \    }\n  \n      auto lower_bound(const T& x) const {\n        const auto next\
    \ = this->m_intervals.lower_bound(x);\n        if (next == this->m_intervals.begin())\
    \ return next;\n        const auto prev = ::std::prev(next);\n        if (prev->second\
    \ < x) return next;\n        return prev;\n      }\n  \n      auto upper_bound(const\
    \ T& x) const {\n        return this->m_intervals.upper_bound(x);\n      }\n \
    \ \n      void insert(const T& l, const T& r) {\n        if (!(l <= r)) {\n  \
    \        return;\n        }\n  \n        const auto l_it = this->find(l - (Mergeable\
    \ ? 1 : 0));\n        const T min = l_it != this->m_intervals.end() ? l_it->first\
    \ : l;\n        const auto r_it = this->find(r + (Mergeable ? 1 : 0));\n     \
    \   const T max = r_it != this->m_intervals.end() ? r_it->second : r;\n  \n  \
    \      this->m_intervals.erase(this->lower_bound(l - (Mergeable ? 1 : 0)), this->upper_bound(r\
    \ + (Mergeable ? 1 : 0)));\n        this->m_intervals.emplace(min, max);\n   \
    \   }\n  \n      void erase(const T& l, const T& r) {\n        if (!(l <= r +\
    \ (Mergeable ? 0 : 1))) {\n          return;\n        }\n  \n        const auto\
    \ l_it = this->find(l);\n        const auto l_new_interval = l_it != this->m_intervals.end()\
    \ && l_it->first <= l - (Mergeable ? 1 : 0)\n          ? ::std::make_optional(::std::make_pair(l_it->first,\
    \ l - (Mergeable ? 1 : 0)))\n          : ::std::nullopt;\n        const auto r_it\
    \ = this->find(r);\n        const auto r_new_interval = r_it != this->m_intervals.end()\
    \ && r + (Mergeable ? 1 : 0) <= r_it->second\n          ? ::std::make_optional(::std::make_pair(r\
    \ + (Mergeable ? 1 : 0), r_it->second))\n          : ::std::nullopt;\n  \n   \
    \     this->m_intervals.erase(this->lower_bound(l), this->upper_bound(r));\n \
    \ \n        if (l_new_interval) {\n          this->m_intervals.emplace(l_new_interval->first,\
    \ l_new_interval->second);\n        }\n        if (r_new_interval) {\n       \
    \   this->m_intervals.emplace(r_new_interval->first, r_new_interval->second);\n\
    \        }\n      }\n  \n      friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::detail::interval_set<T, Mergeable>& self) {\n        os <<\
    \ '{';\n        ::std::string delimiter = \"\";\n        for (const auto& [l,\
    \ r] : self) {\n          os << delimiter << '[' << l << \", \" << r << ']';\n\
    \          delimiter = \", \";\n        }\n        os << '}';\n        return\
    \ os;\n      }\n    };\n  }\n}\n\n\n#line 5 \"tools/real_interval_set.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  using real_interval_set = ::tools::detail::interval_set<T,\
    \ false>;\n}\n\n\n"
  code: "#ifndef TOOLS_REAL_INTERVAL_SET_HPP\n#define TOOLS_REAL_INTERVAL_SET_HPP\n\
    \n#include \"tools/detail/interval_set.hpp\"\n\nnamespace tools {\n  template\
    \ <typename T>\n  using real_interval_set = ::tools::detail::interval_set<T, false>;\n\
    }\n\n#endif\n"
  dependsOn:
  - tools/detail/interval_set.hpp
  isVerificationFile: false
  path: tools/real_interval_set.hpp
  requiredBy: []
  timestamp: '2021-10-23 20:26:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/real_interval_set.test.cpp
documentation_of: tools/real_interval_set.hpp
layout: document
title: Set of real numbers as closed integer intervals
---

It is a set of real numbers, and provides the following two operations.

- Add the real numbers $x$ such that $l \leq x \leq r$ to the set, where $l$ and $r$ are given integers.
- Remove the real numbers $x$ such that $l < x < r$ from the set, where $l$ and $r$ are given integers.

It manages the elements as a set of mutually exclusive closed integer intervals.
The set of intervals is implemented as `std::map<T, T> m`, whose key is the lower bound of an interval and value is the upper bound of it.
It provides limited (read-only) access to `m`.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
real_interval_set<T> set;
```

It creates an empty set of real numbers.
The type parameter `<T>` represents the type of integer bounds.

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

It returns the number of mutually exclusive closed integer intervals.
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
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## contains
```cpp
bool set.contains(T x);
```

It returns whether the set contains $x$ or not.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## lower_bound
```cpp
std::map<T, T>::const_iterator set.lower_bound(T x);
```

It returns an iterator pointing to the least interval whose upper bound is greater than or equal to $x$.
If such the interval does not exist, it returns `set.end()`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## upper_bound
```cpp
std::map<T, T>::const_iterator set.upper_bound(T x);
```

It returns an iterator pointing to the least interval whose lower bound is greater than $x$.
If such the interval does not exist, it returns `set.end()`.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## insert
```cpp
void set.insert(T l, T r);
```

It inserts the real numbers $x$ such that $l \leq x \leq r$ to the set.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.

## erase
```cpp
void set.erase(T l, T r);
```

It removes the real numbers $x$ such that $l < x < r$ from the set.

### Constraints
- None

### Time Complexity
- $O(\log n)$ where $n$ is the number of mutually exclusive closed integer intervals.
