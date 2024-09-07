---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
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
    - https://atcoder.jp/contests/abc041/tasks/abc041_d
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/tsort/count.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n// Source: https://atcoder.jp/contests/abc041/tasks/abc041_d\n\n#include <iostream>\n\
    #line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include\
    \ <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\n  if (!cond)\
    \ {\\\n    ::std::cerr << file << ':' << line << \": \" << func << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/tsort.hpp\"\n\n\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <cassert>\n#include <queue>\n#include\
    \ <cstdint>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 10 \"tools/tsort.hpp\"\
    \n\nnamespace tools {\n\n  class tsort {\n  public:\n    struct edge {\n     \
    \ ::std::size_t id;\n      ::std::size_t from;\n      ::std::size_t to;\n    };\n\
    \n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    tsort() = default;\n    tsort(const ::tools::tsort&)\
    \ = default;\n    tsort(::tools::tsort&&) = default;\n    ~tsort() = default;\n\
    \    ::tools::tsort& operator=(const ::tools::tsort&) = default;\n    ::tools::tsort&\
    \ operator=(::tools::tsort&&) = default;\n\n    explicit tsort(const ::std::size_t\
    \ n) : m_graph(n) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t\
    \ v) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   this->m_edges.push_back(edge{this->m_edges.size(), u, v});\n      this->m_graph[u].push_back(this->m_edges.size()\
    \ - 1);\n      return this->m_edges.size() - 1;\n    }\n\n    const edge& get_edge(const\
    \ ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n      return\
    \ this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges() const {\n\
    \      return this->m_edges;\n    }\n\n    ::std::vector<::std::size_t> query()\
    \ const {\n      ::std::vector<::std::size_t> indegs(this->size(), 0);\n     \
    \ for (::std::size_t u = 0; u < this->size(); ++u) {\n        for (const auto\
    \ e : this->m_graph[u]) {\n          ++indegs[this->m_edges[e].to];\n        }\n\
    \      }\n\n      ::std::queue<::std::size_t> queue;\n      for (::std::size_t\
    \ v = 0; v < this->size(); ++v) {\n        if (indegs[v] == 0) {\n          queue.push(v);\n\
    \        }\n      }\n\n      ::std::vector<::std::size_t> result;\n      result.reserve(this->size());\n\
    \      while (!queue.empty()) {\n        const ::std::size_t u = queue.front();\n\
    \        queue.pop();\n        result.push_back(u);\n        for (const auto e\
    \ : this->m_graph[u]) {\n          const auto v = this->m_edges[e].to;\n     \
    \     --indegs[v];\n          if (indegs[v] == 0) {\n            queue.push(v);\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n\n    template\
    \ <typename R = long long>\n    R count() const {\n      using u32 = ::std::uint_fast32_t;\n\
    \n      assert(this->size() < 32);\n\n      ::std::vector<u32> graph(this->size());\n\
    \      for (const auto& edge : this->m_edges) {\n        graph[edge.from] |= u32(1)\
    \ << edge.to;\n      }\n\n      ::std::vector<R> dp(::tools::pow2(this->size()));\n\
    \      dp[0] = R(1);\n      for (u32 state = 1; state < ::tools::pow2(this->size());\
    \ ++state) {\n        dp[state] = R(0);\n        for (::std::size_t v = 0; v <\
    \ this->size(); ++v) {\n          if (const auto prev_state = state & ~(u32(1)\
    \ << v); ((state >> v) & 1) && !(graph[v] & prev_state)) {\n            dp[state]\
    \ += dp[prev_state];\n          }\n        }\n      }\n\n      return dp[::tools::pow2(this->size())\
    \ - 1];\n    }\n  };\n}\n\n\n#line 7 \"tests/tsort/count.test.cpp\"\n\nvoid sample_01()\
    \ {\n  tools::tsort graph(3);\n  graph.add_edge(1, 0);\n  graph.add_edge(1, 2);\n\
    \  assert_that(graph.count() == 2);\n}\n\nvoid sample_02() {\n  tools::tsort graph(5);\n\
    \  graph.add_edge(0, 1);\n  graph.add_edge(1, 2);\n  graph.add_edge(2, 4);\n \
    \ graph.add_edge(0, 3);\n  graph.add_edge(3, 4);\n  assert_that(graph.count()\
    \ == 3);\n}\n\nvoid sample_03() {\n  tools::tsort graph(16);\n  graph.add_edge(0,\
    \ 1);\n  assert_that(graph.count() == 10461394944000);\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  sample_01();\n  sample_02();\n\
    \  sample_03();\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\
    // Source: https://atcoder.jp/contests/abc041/tasks/abc041_d\n\n#include <iostream>\n\
    #include \"tools/assert_that.hpp\"\n#include \"tools/tsort.hpp\"\n\nvoid sample_01()\
    \ {\n  tools::tsort graph(3);\n  graph.add_edge(1, 0);\n  graph.add_edge(1, 2);\n\
    \  assert_that(graph.count() == 2);\n}\n\nvoid sample_02() {\n  tools::tsort graph(5);\n\
    \  graph.add_edge(0, 1);\n  graph.add_edge(1, 2);\n  graph.add_edge(2, 4);\n \
    \ graph.add_edge(0, 3);\n  graph.add_edge(3, 4);\n  assert_that(graph.count()\
    \ == 3);\n}\n\nvoid sample_03() {\n  tools::tsort graph(16);\n  graph.add_edge(0,\
    \ 1);\n  assert_that(graph.count() == 10461394944000);\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  sample_01();\n  sample_02();\n\
    \  sample_03();\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/tsort.hpp
  - tools/pow2.hpp
  isVerificationFile: true
  path: tests/tsort/count.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tsort/count.test.cpp
layout: document
redirect_from:
- /verify/tests/tsort/count.test.cpp
- /verify/tests/tsort/count.test.cpp.html
title: tests/tsort/count.test.cpp
---
