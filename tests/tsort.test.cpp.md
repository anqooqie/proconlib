---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':heavy_check_mark:'
    path: tools/tsort.hpp
    title: Topological sorting
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/tsort.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n// oj-verify currently cannot handle https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\
    \ properly, so I implemented a special judge for the problem.\n\n#include <cstdlib>\n\
    #include <vector>\n#include <utility>\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 6 \"tools/assert_that.hpp\"\n\n#define assert_that(cond) do {\\\n\
    \  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \"\
    \ << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n   \
    \ ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/tsort.hpp\"\
    \n\n\n\n#line 5 \"tools/tsort.hpp\"\n#include <cstddef>\n#line 7 \"tools/tsort.hpp\"\
    \n#include <queue>\n\nnamespace tools {\n\n  class tsort {\n  private:\n    ::std::vector<::std::vector<::std::size_t>>\
    \ edges;\n\n  public:\n    explicit tsort(const ::std::size_t node_count) : edges(node_count)\
    \ {\n    }\n\n    ::std::size_t node_count() const noexcept {\n      return this->edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t s, const ::std::size_t t) {\n\
    \      this->edges[s].push_back(t);\n    }\n\n    template <typename OutputIterator>\n\
    \    void query(OutputIterator result) const {\n\n      ::std::vector<::std::size_t>\
    \ indegs(this->node_count(), 0);\n      for (::std::size_t s = 0; s < this->node_count();\
    \ ++s) {\n        for (const ::std::size_t t : this->edges[s]) {\n          ++indegs[t];\n\
    \        }\n      }\n\n      ::std::queue<::std::size_t> queue;\n      for (::std::size_t\
    \ v = 0; v < this->node_count(); ++v) {\n        if (indegs[v] == 0) {\n     \
    \     queue.push(v);\n        }\n      }\n\n      while (!queue.empty()) {\n \
    \       const ::std::size_t s = queue.front();\n        queue.pop();\n       \
    \ *result = s;\n        ++result;\n        for (const ::std::size_t t : edges[s])\
    \ {\n          --indegs[t];\n          if (indegs[t] == 0) {\n            queue.push(t);\n\
    \          }\n        }\n      }\n    }\n  };\n}\n\n\n#line 1 \"tools/lower_bound.hpp\"\
    \n\n\n\n#include <iterator>\n#include <algorithm>\n\nnamespace tools {\n\n  template\
    \ <class ForwardIterator, class T>\n  auto lower_bound(ForwardIterator first,\
    \ ForwardIterator last, const T& value) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 11 \"tests/tsort.test.cpp\"\n\nusing\
    \ ll = long long;\n\nvoid verify(const ll node_count, std::vector<std::pair<ll,\
    \ ll>>& edges) {\n\n  tools::tsort tsort(node_count);\n  for (const auto& [s,\
    \ t] : edges) {\n    tsort.add_edge(s, t);\n  }\n\n  std::vector<ll> result;\n\
    \  tsort.query(std::back_inserter(result));\n\n  assert_that(ll(result.size())\
    \ == node_count);\n\n  std::vector<ll> order(node_count);\n  for (ll i = 0; i\
    \ < node_count; ++i) {\n    order[result[i]] = i;\n  }\n  for (const auto& [s,\
    \ t] : edges) {\n    assert_that(order[s] < order[t]);\n  }\n}\n\nvoid sample_00()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(1,\
    \ 2);\n  edges.emplace_back(3, 1);\n  edges.emplace_back(3, 4);\n  edges.emplace_back(4,\
    \ 5);\n  edges.emplace_back(5, 2);\n  verify(6, edges);\n}\n\nvoid small_00()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(0,\
    \ 2);\n  edges.emplace_back(2, 3);\n  edges.emplace_back(2, 4);\n  edges.emplace_back(3,\
    \ 4);\n  verify(5, edges);\n}\n\nvoid small_01() {\n  std::vector<std::pair<ll,\
    \ ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(0, 3);\n  edges.emplace_back(0,\
    \ 2);\n  edges.emplace_back(2, 3);\n  edges.emplace_back(1, 4);\n  edges.emplace_back(3,\
    \ 5);\n  edges.emplace_back(4, 5);\n  verify(6, edges);\n}\n\nvoid small_02()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(0,\
    \ 2);\n  edges.emplace_back(2, 1);\n  edges.emplace_back(1, 3);\n  edges.emplace_back(2,\
    \ 3);\n  edges.emplace_back(2, 4);\n  edges.emplace_back(3, 4);\n  edges.emplace_back(3,\
    \ 5);\n  edges.emplace_back(4, 6);\n  edges.emplace_back(5, 7);\n  edges.emplace_back(6,\
    \ 7);\n  verify(8, edges);\n}\n\nvoid small_03() {\n  std::vector<std::pair<ll,\
    \ ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(0, 3);\n  edges.emplace_back(1,\
    \ 2);\n  edges.emplace_back(4, 5);\n  edges.emplace_back(4, 7);\n  edges.emplace_back(5,\
    \ 7);\n  edges.emplace_back(7, 6);\n  verify(8, edges);\n}\n\nvoid small_04()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 7);\n  edges.emplace_back(1,\
    \ 7);\n  edges.emplace_back(2, 7);\n  edges.emplace_back(3, 7);\n  edges.emplace_back(4,\
    \ 7);\n  edges.emplace_back(5, 7);\n  edges.emplace_back(6, 7);\n  verify(8, edges);\n\
    }\n\nvoid small_05() {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(1,\
    \ 2);\n  edges.emplace_back(3, 4);\n  edges.emplace_back(5, 6);\n  edges.emplace_back(7,\
    \ 8);\n  edges.emplace_back(0, 2);\n  edges.emplace_back(0, 3);\n  edges.emplace_back(0,\
    \ 6);\n  edges.emplace_back(0, 7);\n  verify(9, edges);\n}\n\nvoid small_06()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(0,\
    \ 2);\n  edges.emplace_back(2, 3);\n  edges.emplace_back(2, 4);\n  edges.emplace_back(3,\
    \ 4);\n  verify(5, edges);\n}\n\nvoid corner_00() {\n  std::vector<std::pair<ll,\
    \ ll>> edges;\n  edges.emplace_back(0, 1);\n  verify(2, edges);\n}\n\nvoid corner_01()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  verify(2, edges);\n}\n\nvoid corner_02()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(2,\
    \ 3);\n  verify(4, edges);\n}\n\nvoid corner_03() {\n  std::vector<std::pair<ll,\
    \ ll>> edges;\n  edges.emplace_back(0, 2);\n  edges.emplace_back(1, 2);\n  verify(3,\
    \ edges);\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  sample_00();\n  small_00();\n  small_01();\n  small_02();\n  small_03();\n\
    \  small_04();\n  small_05();\n  small_06();\n  corner_00();\n  corner_01();\n\
    \  corner_02();\n  corner_03();\n\n  std::cout << \"Hello World\" << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\
    // oj-verify currently cannot handle https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\
    \ properly, so I implemented a special judge for the problem.\n\n#include <cstdlib>\n\
    #include <vector>\n#include <utility>\n#include <iostream>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/tsort.hpp\"\n#include \"tools/lower_bound.hpp\"\n\nusing ll\
    \ = long long;\n\nvoid verify(const ll node_count, std::vector<std::pair<ll, ll>>&\
    \ edges) {\n\n  tools::tsort tsort(node_count);\n  for (const auto& [s, t] : edges)\
    \ {\n    tsort.add_edge(s, t);\n  }\n\n  std::vector<ll> result;\n  tsort.query(std::back_inserter(result));\n\
    \n  assert_that(ll(result.size()) == node_count);\n\n  std::vector<ll> order(node_count);\n\
    \  for (ll i = 0; i < node_count; ++i) {\n    order[result[i]] = i;\n  }\n  for\
    \ (const auto& [s, t] : edges) {\n    assert_that(order[s] < order[t]);\n  }\n\
    }\n\nvoid sample_00() {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0,\
    \ 1);\n  edges.emplace_back(1, 2);\n  edges.emplace_back(3, 1);\n  edges.emplace_back(3,\
    \ 4);\n  edges.emplace_back(4, 5);\n  edges.emplace_back(5, 2);\n  verify(6, edges);\n\
    }\n\nvoid small_00() {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0,\
    \ 1);\n  edges.emplace_back(0, 2);\n  edges.emplace_back(2, 3);\n  edges.emplace_back(2,\
    \ 4);\n  edges.emplace_back(3, 4);\n  verify(5, edges);\n}\n\nvoid small_01()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(0,\
    \ 3);\n  edges.emplace_back(0, 2);\n  edges.emplace_back(2, 3);\n  edges.emplace_back(1,\
    \ 4);\n  edges.emplace_back(3, 5);\n  edges.emplace_back(4, 5);\n  verify(6, edges);\n\
    }\n\nvoid small_02() {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0,\
    \ 1);\n  edges.emplace_back(0, 2);\n  edges.emplace_back(2, 1);\n  edges.emplace_back(1,\
    \ 3);\n  edges.emplace_back(2, 3);\n  edges.emplace_back(2, 4);\n  edges.emplace_back(3,\
    \ 4);\n  edges.emplace_back(3, 5);\n  edges.emplace_back(4, 6);\n  edges.emplace_back(5,\
    \ 7);\n  edges.emplace_back(6, 7);\n  verify(8, edges);\n}\n\nvoid small_03()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(0,\
    \ 3);\n  edges.emplace_back(1, 2);\n  edges.emplace_back(4, 5);\n  edges.emplace_back(4,\
    \ 7);\n  edges.emplace_back(5, 7);\n  edges.emplace_back(7, 6);\n  verify(8, edges);\n\
    }\n\nvoid small_04() {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0,\
    \ 7);\n  edges.emplace_back(1, 7);\n  edges.emplace_back(2, 7);\n  edges.emplace_back(3,\
    \ 7);\n  edges.emplace_back(4, 7);\n  edges.emplace_back(5, 7);\n  edges.emplace_back(6,\
    \ 7);\n  verify(8, edges);\n}\n\nvoid small_05() {\n  std::vector<std::pair<ll,\
    \ ll>> edges;\n  edges.emplace_back(1, 2);\n  edges.emplace_back(3, 4);\n  edges.emplace_back(5,\
    \ 6);\n  edges.emplace_back(7, 8);\n  edges.emplace_back(0, 2);\n  edges.emplace_back(0,\
    \ 3);\n  edges.emplace_back(0, 6);\n  edges.emplace_back(0, 7);\n  verify(9, edges);\n\
    }\n\nvoid small_06() {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0,\
    \ 1);\n  edges.emplace_back(0, 2);\n  edges.emplace_back(2, 3);\n  edges.emplace_back(2,\
    \ 4);\n  edges.emplace_back(3, 4);\n  verify(5, edges);\n}\n\nvoid corner_00()\
    \ {\n  std::vector<std::pair<ll, ll>> edges;\n  edges.emplace_back(0, 1);\n  verify(2,\
    \ edges);\n}\n\nvoid corner_01() {\n  std::vector<std::pair<ll, ll>> edges;\n\
    \  verify(2, edges);\n}\n\nvoid corner_02() {\n  std::vector<std::pair<ll, ll>>\
    \ edges;\n  edges.emplace_back(0, 1);\n  edges.emplace_back(2, 3);\n  verify(4,\
    \ edges);\n}\n\nvoid corner_03() {\n  std::vector<std::pair<ll, ll>> edges;\n\
    \  edges.emplace_back(0, 2);\n  edges.emplace_back(1, 2);\n  verify(3, edges);\n\
    }\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  sample_00();\n  small_00();\n  small_01();\n  small_02();\n  small_03();\n\
    \  small_04();\n  small_05();\n  small_06();\n  corner_00();\n  corner_01();\n\
    \  corner_02();\n  corner_03();\n\n  std::cout << \"Hello World\" << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/tsort.hpp
  - tools/lower_bound.hpp
  isVerificationFile: true
  path: tests/tsort.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tsort.test.cpp
layout: document
redirect_from:
- /verify/tests/tsort.test.cpp
- /verify/tests/tsort.test.cpp.html
title: tests/tsort.test.cpp
---
