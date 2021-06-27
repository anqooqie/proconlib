---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/mex.hpp
    title: Minimum excluded value
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2880
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2880
  bundledCode: "#line 1 \"tests/mex.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    #line 1 \"tools/mex.hpp\"\n\n\n\n#include <map>\n#line 6 \"tools/mex.hpp\"\n#include\
    \ <iterator>\n#include <algorithm>\n#line 9 \"tools/mex.hpp\"\n#include <string>\n\
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
    }\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 9 \"tests/mex.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nstruct query {\n  i64 query_type;\n  i64 id;\n  i64 day;\n  i64 from;\n  i64\
    \ to;\n  query(i64 query_type, i64 id, i64 day, i64 from, i64 to) :\n    query_type(query_type),\n\
    \    id(id),\n    day(day),\n    from(from),\n    to(to) {\n  }\n};\n\nint main()\
    \ {\n  i64 N, M, Q;\n  std::cin >> N >> M >> Q;\n\n  std::vector<query> queries;\n\
    \  for (i64 i = 0; i < M; ++i) {\n    i64 D, A, B;\n    std::cin >> D >> A >>\
    \ B;\n    queries.emplace_back(1, i, D, A, B);\n  }\n  for (i64 i = 0; i < Q;\
    \ ++i) {\n    i64 E, S, T;\n    std::cin >> E >> S >> T;\n    queries.emplace_back(0,\
    \ i, E, S, T);\n  }\n\n  std::sort(queries.begin(), queries.end(), tools::less_by([](const\
    \ query& q) {\n    return std::make_pair(q.day, q.query_type);\n  }));\n\n  tools::mex<i64>\
    \ mex;\n  std::vector<bool> answers(Q);\n  for (const query& query : queries)\
    \ {\n    if (query.query_type == 0) {\n      answers[query.id] = mex.query(query.from\
    \ * 2) >= query.to * 2;\n    } else {\n      mex.add(query.from * 2, query.to\
    \ * 2 + 1);\n    }\n  }\n\n  for (const bool answer : answers) {\n    std::cout\
    \ << (answer ? \"Yes\" : \"No\") << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <utility>\n#include <vector>\n#include\
    \ \"tools/mex.hpp\"\n#include \"tools/less_by.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nstruct query {\n  i64 query_type;\n  i64 id;\n  i64 day;\n  i64 from;\n  i64\
    \ to;\n  query(i64 query_type, i64 id, i64 day, i64 from, i64 to) :\n    query_type(query_type),\n\
    \    id(id),\n    day(day),\n    from(from),\n    to(to) {\n  }\n};\n\nint main()\
    \ {\n  i64 N, M, Q;\n  std::cin >> N >> M >> Q;\n\n  std::vector<query> queries;\n\
    \  for (i64 i = 0; i < M; ++i) {\n    i64 D, A, B;\n    std::cin >> D >> A >>\
    \ B;\n    queries.emplace_back(1, i, D, A, B);\n  }\n  for (i64 i = 0; i < Q;\
    \ ++i) {\n    i64 E, S, T;\n    std::cin >> E >> S >> T;\n    queries.emplace_back(0,\
    \ i, E, S, T);\n  }\n\n  std::sort(queries.begin(), queries.end(), tools::less_by([](const\
    \ query& q) {\n    return std::make_pair(q.day, q.query_type);\n  }));\n\n  tools::mex<i64>\
    \ mex;\n  std::vector<bool> answers(Q);\n  for (const query& query : queries)\
    \ {\n    if (query.query_type == 0) {\n      answers[query.id] = mex.query(query.from\
    \ * 2) >= query.to * 2;\n    } else {\n      mex.add(query.from * 2, query.to\
    \ * 2 + 1);\n    }\n  }\n\n  for (const bool answer : answers) {\n    std::cout\
    \ << (answer ? \"Yes\" : \"No\") << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/mex.hpp
  - tools/less_by.hpp
  isVerificationFile: true
  path: tests/mex.test.cpp
  requiredBy: []
  timestamp: '2021-06-27 22:09:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/mex.test.cpp
layout: document
redirect_from:
- /verify/tests/mex.test.cpp
- /verify/tests/mex.test.cpp.html
title: tests/mex.test.cpp
---
