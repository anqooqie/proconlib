---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mex.test.cpp
    title: tests/mex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/mex.hpp\"\n\n\n\n#include <map>\n#include <utility>\n\
    #include <iterator>\n#include <algorithm>\n#include <iostream>\n#include <string>\n\
    \nnamespace tools {\n  template <typename T>\n  class mex {\n  private:\n    //\
    \ closed intervals\n    ::std::map<T, T> m_intervals;\n\n  public:\n    // The\
    \ method accepts a half-open interval.\n    void add(const T& l, T r) {\n    \
    \  --r;\n\n      if (l > r) {\n        return;\n      }\n\n      const auto [lower_bound,\
    \ min] = [&]() {\n        const auto l_next_it = this->m_intervals.lower_bound(l);\n\
    \n        if (l_next_it == this->m_intervals.begin()) {\n          return ::std::make_pair(l_next_it,\
    \ l);\n        }\n\n        const auto l_prev_it = ::std::prev(l_next_it);\n \
    \       if (l_prev_it->second + 1 < l) {\n          return ::std::make_pair(l_next_it,\
    \ l);\n        }\n\n        return ::std::make_pair(l_prev_it, l_prev_it->first);\n\
    \      }();\n\n      const auto [upper_bound, max] = [&]() {\n        const auto\
    \ r_next_it = this->m_intervals.upper_bound(r + 1);\n\n        if (r_next_it ==\
    \ this->m_intervals.begin()) {\n          return ::std::make_pair(r_next_it, r);\n\
    \        }\n\n        const auto r_prev_it = ::std::prev(r_next_it);\n       \
    \ if (r_prev_it->second + 1 < l) {\n          return ::std::make_pair(r_next_it,\
    \ r);\n        }\n\n        return ::std::make_pair(r_next_it, ::std::max(r, r_prev_it->second));\n\
    \      }();\n\n      this->m_intervals.erase(lower_bound, upper_bound);\n    \
    \  this->m_intervals.emplace(min, max);\n    }\n\n    void add(const T& x) {\n\
    \      this->add(x, x + 1);\n    }\n\n    T query(const T& min) const {\n    \
    \  auto it = this->m_intervals.upper_bound(min);\n      if (it == this->m_intervals.begin())\
    \ {\n        return min;\n      }\n      --it;\n      return min <= it->second\
    \ ? it->second + 1 : min;\n    }\n\n    T query() const {\n      return this->query(0);\n\
    \    }\n\n    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::mex<T>&\
    \ self) {\n      ::std::string delimiter = \"\";\n      for (const auto& [l, r]\
    \ : self.m_intervals) {\n        os << delimiter << '[' << l << \", \" << r <<\
    \ ']';\n        delimiter = \", \";\n      }\n      return os;\n    }\n  };\n\
    }\n\n\n"
  code: "#ifndef TOOLS_MEX_HPP\n#define TOOLS_MEX_HPP\n\n#include <map>\n#include\
    \ <utility>\n#include <iterator>\n#include <algorithm>\n#include <iostream>\n\
    #include <string>\n\nnamespace tools {\n  template <typename T>\n  class mex {\n\
    \  private:\n    // closed intervals\n    ::std::map<T, T> m_intervals;\n\n  public:\n\
    \    // The method accepts a half-open interval.\n    void add(const T& l, T r)\
    \ {\n      --r;\n\n      if (l > r) {\n        return;\n      }\n\n      const\
    \ auto [lower_bound, min] = [&]() {\n        const auto l_next_it = this->m_intervals.lower_bound(l);\n\
    \n        if (l_next_it == this->m_intervals.begin()) {\n          return ::std::make_pair(l_next_it,\
    \ l);\n        }\n\n        const auto l_prev_it = ::std::prev(l_next_it);\n \
    \       if (l_prev_it->second + 1 < l) {\n          return ::std::make_pair(l_next_it,\
    \ l);\n        }\n\n        return ::std::make_pair(l_prev_it, l_prev_it->first);\n\
    \      }();\n\n      const auto [upper_bound, max] = [&]() {\n        const auto\
    \ r_next_it = this->m_intervals.upper_bound(r + 1);\n\n        if (r_next_it ==\
    \ this->m_intervals.begin()) {\n          return ::std::make_pair(r_next_it, r);\n\
    \        }\n\n        const auto r_prev_it = ::std::prev(r_next_it);\n       \
    \ if (r_prev_it->second + 1 < l) {\n          return ::std::make_pair(r_next_it,\
    \ r);\n        }\n\n        return ::std::make_pair(r_next_it, ::std::max(r, r_prev_it->second));\n\
    \      }();\n\n      this->m_intervals.erase(lower_bound, upper_bound);\n    \
    \  this->m_intervals.emplace(min, max);\n    }\n\n    void add(const T& x) {\n\
    \      this->add(x, x + 1);\n    }\n\n    T query(const T& min) const {\n    \
    \  auto it = this->m_intervals.upper_bound(min);\n      if (it == this->m_intervals.begin())\
    \ {\n        return min;\n      }\n      --it;\n      return min <= it->second\
    \ ? it->second + 1 : min;\n    }\n\n    T query() const {\n      return this->query(0);\n\
    \    }\n\n    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::mex<T>&\
    \ self) {\n      ::std::string delimiter = \"\";\n      for (const auto& [l, r]\
    \ : self.m_intervals) {\n        os << delimiter << '[' << l << \", \" << r <<\
    \ ']';\n        delimiter = \", \";\n      }\n      return os;\n    }\n  };\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/mex.hpp
  requiredBy: []
  timestamp: '2021-06-27 22:09:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/mex.test.cpp
documentation_of: tools/mex.hpp
layout: document
title: Minimum excluded value
---

It is a set and can answer the minimum value more than or equal to a given value and not in the set.

## Usage
```cpp
tools::mex<int> mex;

// adds [1, 4) to the set
mex.add(1, 4);

// adds 5 to the set
mex.add(5);

// returns 4 because 4 >= 2 and 4 is not in {1, 2, 3, 5}.
mex.query(2);

// returns 4 because 4 >= 4 and 4 is not in {1, 2, 3, 5}.
mex.query(4);
```

## License
- CC0

## Author
- anqooqie
