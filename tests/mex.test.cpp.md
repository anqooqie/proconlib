---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/interval_set.hpp
    title: Set of closed intervals
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
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <utility>\n#line 1 \"tools/mex.hpp\"\n\n\n\n#line 1 \"tools/interval_set.hpp\"\
    \n\n\n\n#include <map>\n#include <iterator>\n#include <optional>\n#line 9 \"tools/interval_set.hpp\"\
    \n#include <string>\n\nnamespace tools {\n  template <typename T, bool Mergeable>\n\
    \  class interval_set {\n  private:\n    // closed intervals\n    ::std::map<T,\
    \ T> m_intervals;\n\n  public:\n    interval_set() = default;\n    interval_set(const\
    \ ::tools::interval_set<T, Mergeable>&) = default;\n    interval_set(::tools::interval_set<T,\
    \ Mergeable>&&) = default;\n    ~interval_set() = default;\n    ::tools::interval_set<T,\
    \ Mergeable>& operator=(const ::tools::interval_set<T, Mergeable>&) = default;\n\
    \    ::tools::interval_set<T, Mergeable>& operator=(::tools::interval_set<T, Mergeable>&&)\
    \ = default;\n\n    auto begin() const {\n      return this->m_intervals.begin();\n\
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
    \ = \", \";\n      }\n      os << '}';\n      return os;\n    }\n  };\n}\n\n\n\
    #line 6 \"tools/mex.hpp\"\n\nnamespace tools {\n  template <typename T>\n  class\
    \ mex {\n  private:\n    ::tools::interval_set<T, true> m_intervals;\n\n  public:\n\
    \    void insert(const T& x) {\n      this->m_intervals.insert(x, x);\n    }\n\
    \n    void insert(const T& l, const T& r) {\n      this->m_intervals.insert(l,\
    \ r);\n    }\n\n    void erase(const T& x) {\n      this->m_intervals.erase(x,\
    \ x);\n    }\n\n    void erase(const T& l, const T& r) {\n      this->m_intervals.erase(l,\
    \ r);\n    }\n\n    T query(const T& min) const {\n      auto it = this->m_intervals.find(min);\n\
    \      return it != this->m_intervals.end() ? it->second + 1 : min;\n    }\n\n\
    \    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::mex<T>&\
    \ self) {\n      return os << self.m_intervals;\n    }\n  };\n}\n\n\n#line 1 \"\
    tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class F>\n  class\
    \ less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const F& selector)\
    \ : selector(selector) {\n    }\n\n    template <class T>\n    bool operator()(const\
    \ T& x, const T& y) const {\n      return selector(x) < selector(y);\n    }\n\
    \  };\n}\n\n\n#line 10 \"tests/mex.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
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
    \ * 2) >= query.to * 2;\n    } else {\n      mex.insert(query.from * 2, query.to\
    \ * 2);\n    }\n  }\n\n  for (const bool answer : answers) {\n    std::cout <<\
    \ (answer ? \"Yes\" : \"No\") << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include\
    \ <utility>\n#include \"tools/mex.hpp\"\n#include \"tools/less_by.hpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nstruct query {\n  i64 query_type;\n  i64 id;\n \
    \ i64 day;\n  i64 from;\n  i64 to;\n  query(i64 query_type, i64 id, i64 day, i64\
    \ from, i64 to) :\n    query_type(query_type),\n    id(id),\n    day(day),\n \
    \   from(from),\n    to(to) {\n  }\n};\n\nint main() {\n  i64 N, M, Q;\n  std::cin\
    \ >> N >> M >> Q;\n\n  std::vector<query> queries;\n  for (i64 i = 0; i < M; ++i)\
    \ {\n    i64 D, A, B;\n    std::cin >> D >> A >> B;\n    queries.emplace_back(1,\
    \ i, D, A, B);\n  }\n  for (i64 i = 0; i < Q; ++i) {\n    i64 E, S, T;\n    std::cin\
    \ >> E >> S >> T;\n    queries.emplace_back(0, i, E, S, T);\n  }\n\n  std::sort(queries.begin(),\
    \ queries.end(), tools::less_by([](const query& q) {\n    return std::make_pair(q.day,\
    \ q.query_type);\n  }));\n\n  tools::mex<i64> mex;\n  std::vector<bool> answers(Q);\n\
    \  for (const query& query : queries) {\n    if (query.query_type == 0) {\n  \
    \    answers[query.id] = mex.query(query.from * 2) >= query.to * 2;\n    } else\
    \ {\n      mex.insert(query.from * 2, query.to * 2);\n    }\n  }\n\n  for (const\
    \ bool answer : answers) {\n    std::cout << (answer ? \"Yes\" : \"No\") << '\\\
    n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/mex.hpp
  - tools/interval_set.hpp
  - tools/less_by.hpp
  isVerificationFile: true
  path: tests/mex.test.cpp
  requiredBy: []
  timestamp: '2021-06-30 15:42:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/mex.test.cpp
layout: document
redirect_from:
- /verify/tests/mex.test.cpp
- /verify/tests/mex.test.cpp.html
title: tests/mex.test.cpp
---
