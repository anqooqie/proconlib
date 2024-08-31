---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/permutation.hpp
    title: Permutation
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
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/tsort/query.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n// oj-verify currently cannot handle https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\
    \ properly, so I implemented a special judge for the problem.\n\n#include <iostream>\n\
    #include <cstddef>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/tsort.hpp\"\n\n\n\n#line\
    \ 5 \"tools/tsort.hpp\"\n#include <vector>\n#include <cassert>\n#include <queue>\n\
    #include <cstdint>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
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
    \ - 1];\n    }\n  };\n}\n\n\n#line 1 \"tools/permutation.hpp\"\n\n\n\n#line 7\
    \ \"tools/permutation.hpp\"\n#include <numeric>\n#include <algorithm>\n#include\
    \ <iterator>\n#include <utility>\n#line 12 \"tools/permutation.hpp\"\n#include\
    \ <string>\n\nnamespace tools {\n  template <typename T>\n  class permutation\
    \ {\n  private:\n    ::std::vector<T> m_perm;\n    ::std::vector<T> m_inv;\n\n\
    \    void verify_consistency() const {\n#ifndef NDEBUG\n      ::std::vector<bool>\
    \ unique(this->m_perm.size(), true);\n      for (const T x : this->m_perm) {\n\
    \        assert(0 <= x && x < T(this->m_perm.size()));\n        assert(unique[x]);\n\
    \        unique[x] = false;\n      }\n#endif\n    }\n\n    void make_inv() {\n\
    \      this->m_inv.resize(this->m_perm.size());\n      for (::std::size_t i =\
    \ 0; i < this->m_perm.size(); ++i) {\n        this->m_inv[this->m_perm[i]] = i;\n\
    \      }\n    }\n\n  public:\n    permutation() = default;\n    permutation(const\
    \ ::tools::permutation<T>&) = default;\n    permutation(::tools::permutation<T>&&)\
    \ = default;\n    ~permutation() = default;\n    ::tools::permutation<T>& operator=(const\
    \ ::tools::permutation<T>&) = default;\n    ::tools::permutation<T>& operator=(::tools::permutation<T>&&)\
    \ = default;\n\n    explicit permutation(::std::size_t n) : m_perm(n), m_inv(n)\
    \ {\n      ::std::iota(this->m_perm.begin(), this->m_perm.end(), 0);\n      ::std::iota(this->m_inv.begin(),\
    \ this->m_inv.end(), 0);\n    }\n    template <typename Iterator>\n    permutation(Iterator\
    \ begin, Iterator end) : m_perm(begin, end) {\n      this->verify_consistency();\n\
    \      this->make_inv();\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_perm.size();\n    }\n    T operator[](const ::std::size_t i) const {\n\
    \      assert(i < this->size());\n      return this->m_perm[i];\n    }\n    typename\
    \ ::std::vector<T>::const_iterator begin() const {\n      return this->m_perm.begin();\n\
    \    }\n    typename ::std::vector<T>::const_iterator end() const {\n      return\
    \ this->m_perm.end();\n    }\n\n    ::tools::permutation<T>& swap_from_left(const\
    \ T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n      assert(0\
    \ <= y && y < T(this->size()));\n      this->m_inv[this->m_perm[y]] = x;\n   \
    \   this->m_inv[this->m_perm[x]] = y;\n      ::std::swap(this->m_perm[x], this->m_perm[y]);\n\
    \      return *this;\n    }\n    ::tools::permutation<T>& swap_from_right(const\
    \ T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n      assert(0\
    \ <= y && y < T(this->size()));\n      this->m_perm[this->m_inv[y]] = x;\n   \
    \   this->m_perm[this->m_inv[x]] = y;\n      ::std::swap(this->m_inv[x], this->m_inv[y]);\n\
    \      return *this;\n    }\n\n    T id() const {\n      if (this->size() == 0)\
    \ return 0;\n\n      ::std::vector<T> left(this->size());\n      ::std::iota(left.begin(),\
    \ left.end(), 0);\n\n      ::std::vector<T> fact(this->size());\n      fact[0]\
    \ = 1;\n      for (::std::size_t i = 1; i < this->size(); ++i) {\n        fact[i]\
    \ = fact[i - 1] * i;\n      }\n\n      T id = 0;\n      for (::std::size_t i =\
    \ 0; i < this->size(); ++i) {\n        auto it = ::std::lower_bound(left.begin(),\
    \ left.end(), this->m_perm[i]);\n        id += ::std::distance(left.begin(), it)\
    \ * fact[this->m_perm.size() - 1 - i];\n        left.erase(it);\n      }\n\n \
    \     return id;\n    }\n\n    static ::tools::permutation<T> from(const ::std::size_t\
    \ n, T id) {\n      if (n == 0) return ::tools::permutation<T>(0);\n\n      ::std::vector<T>\
    \ left(n);\n      ::std::iota(left.begin(), left.end(), 0);\n\n      ::std::vector<T>\
    \ fact(n);\n      fact[0] = 1;\n      for (::std::size_t i = 1; i < n; ++i) {\n\
    \        fact[i] = fact[i - 1] * i;\n      }\n\n      ::std::vector<T> p;\n  \
    \    for (::std::size_t i = 0; i < n; ++i) {\n        auto it = ::std::next(left.begin(),\
    \ id / fact[n - i - 1]);\n        p.push_back(*it);\n        left.erase(it);\n\
    \        id %= fact[n - i - 1];\n      }\n\n      return ::tools::permutation<T>(p.begin(),\
    \ p.end());\n    }\n\n    ::tools::permutation<T> inv() const {\n      return\
    \ ::tools::permutation<T>(this->m_inv.begin(), this->m_inv.end());\n    }\n  \
    \  ::tools::permutation<T>& inv_inplace() {\n      this->m_perm.swap(this->m_inv);\n\
    \      return *this;\n    }\n    T inv(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      return this->m_inv[i];\n    }\n\n    ::tools::permutation<T>&\
    \ operator*=(const ::tools::permutation<T>& other) {\n      assert(this->size()\
    \ == other.size());\n      for (::std::size_t i = 0; i < this->size(); ++i) {\n\
    \        this->m_inv[i] = other.m_perm[this->m_perm[i]];\n      }\n      this->m_perm.swap(this->m_inv);\n\
    \      this->make_inv();\n      return *this;\n    }\n    friend ::tools::permutation<T>\
    \ operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return ::tools::permutation<T>(lhs) *= rhs;\n    }\n\n    friend\
    \ bool operator==(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return lhs.m_perm == rhs.m_perm;\n    }\n    friend bool operator!=(const\
    \ ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {\n      return\
    \ lhs.m_perm != rhs.m_perm;\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::permutation<T>& self) {\n      os << '(';\n      ::std::string\
    \ delimiter = \"\";\n      for (const T value : self.m_perm) {\n        os <<\
    \ delimiter << value;\n        delimiter = \", \";\n      }\n      return os <<\
    \ ')';\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::permutation<T>&\
    \ self) {\n      for (T& value : self.m_perm) {\n        is >> value;\n      }\n\
    \      self.verify_consistency();\n      self.make_inv();\n      return is;\n\
    \    }\n  };\n}\n\n\n#line 9 \"tests/tsort/query.test.cpp\"\n\nvoid verify(const\
    \ tools::tsort& graph) {\n  const auto result = [&]() {\n    const auto r = graph.query();\n\
    \    return tools::permutation<std::size_t>(r.begin(), r.end());\n  }();\n\n \
    \ assert_that(result.size() == graph.size());\n  for (const auto& edge : graph.edges())\
    \ {\n    assert_that(result.inv(edge.from) < result.inv(edge.to));\n  }\n}\n\n\
    void sample_00() {\n  tools::tsort graph(6);\n  graph.add_edge(0, 1);\n  graph.add_edge(1,\
    \ 2);\n  graph.add_edge(3, 1);\n  graph.add_edge(3, 4);\n  graph.add_edge(4, 5);\n\
    \  graph.add_edge(5, 2);\n  verify(graph);\n}\n\nvoid small_00() {\n  tools::tsort\
    \ graph(5);\n  graph.add_edge(0, 1);\n  graph.add_edge(0, 2);\n  graph.add_edge(2,\
    \ 3);\n  graph.add_edge(2, 4);\n  graph.add_edge(3, 4);\n  verify(graph);\n}\n\
    \nvoid small_01() {\n  tools::tsort graph(6);\n  graph.add_edge(0, 1);\n  graph.add_edge(0,\
    \ 3);\n  graph.add_edge(0, 2);\n  graph.add_edge(2, 3);\n  graph.add_edge(1, 4);\n\
    \  graph.add_edge(3, 5);\n  graph.add_edge(4, 5);\n  verify(graph);\n}\n\nvoid\
    \ small_02() {\n  tools::tsort graph(8);\n  graph.add_edge(0, 1);\n  graph.add_edge(0,\
    \ 2);\n  graph.add_edge(2, 1);\n  graph.add_edge(1, 3);\n  graph.add_edge(2, 3);\n\
    \  graph.add_edge(2, 4);\n  graph.add_edge(3, 4);\n  graph.add_edge(3, 5);\n \
    \ graph.add_edge(4, 6);\n  graph.add_edge(5, 7);\n  graph.add_edge(6, 7);\n  verify(graph);\n\
    }\n\nvoid small_03() {\n  tools::tsort graph(8);\n  graph.add_edge(0, 1);\n  graph.add_edge(0,\
    \ 3);\n  graph.add_edge(1, 2);\n  graph.add_edge(4, 5);\n  graph.add_edge(4, 7);\n\
    \  graph.add_edge(5, 7);\n  graph.add_edge(7, 6);\n  verify(graph);\n}\n\nvoid\
    \ small_04() {\n  tools::tsort graph(8);\n  graph.add_edge(0, 7);\n  graph.add_edge(1,\
    \ 7);\n  graph.add_edge(2, 7);\n  graph.add_edge(3, 7);\n  graph.add_edge(4, 7);\n\
    \  graph.add_edge(5, 7);\n  graph.add_edge(6, 7);\n  verify(graph);\n}\n\nvoid\
    \ small_05() {\n  tools::tsort graph(9);\n  graph.add_edge(1, 2);\n  graph.add_edge(3,\
    \ 4);\n  graph.add_edge(5, 6);\n  graph.add_edge(7, 8);\n  graph.add_edge(0, 2);\n\
    \  graph.add_edge(0, 3);\n  graph.add_edge(0, 6);\n  graph.add_edge(0, 7);\n \
    \ verify(graph);\n}\n\nvoid small_06() {\n  tools::tsort graph(5);\n  graph.add_edge(0,\
    \ 1);\n  graph.add_edge(0, 2);\n  graph.add_edge(2, 3);\n  graph.add_edge(2, 4);\n\
    \  graph.add_edge(3, 4);\n  verify(graph);\n}\n\nvoid corner_00() {\n  tools::tsort\
    \ graph(2);\n  graph.add_edge(0, 1);\n  verify(graph);\n}\n\nvoid corner_01()\
    \ {\n  tools::tsort graph(2);\n  verify(graph);\n}\n\nvoid corner_02() {\n  tools::tsort\
    \ graph(4);\n  graph.add_edge(0, 1);\n  graph.add_edge(2, 3);\n  verify(graph);\n\
    }\n\nvoid corner_03() {\n  tools::tsort graph(3);\n  graph.add_edge(0, 2);\n \
    \ graph.add_edge(1, 2);\n  verify(graph);\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  sample_00();\n  small_00();\n \
    \ small_01();\n  small_02();\n  small_03();\n  small_04();\n  small_05();\n  small_06();\n\
    \  corner_00();\n  corner_01();\n  corner_02();\n  corner_03();\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\
    // oj-verify currently cannot handle https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B\
    \ properly, so I implemented a special judge for the problem.\n\n#include <iostream>\n\
    #include <cstddef>\n#include \"tools/assert_that.hpp\"\n#include \"tools/tsort.hpp\"\
    \n#include \"tools/permutation.hpp\"\n\nvoid verify(const tools::tsort& graph)\
    \ {\n  const auto result = [&]() {\n    const auto r = graph.query();\n    return\
    \ tools::permutation<std::size_t>(r.begin(), r.end());\n  }();\n\n  assert_that(result.size()\
    \ == graph.size());\n  for (const auto& edge : graph.edges()) {\n    assert_that(result.inv(edge.from)\
    \ < result.inv(edge.to));\n  }\n}\n\nvoid sample_00() {\n  tools::tsort graph(6);\n\
    \  graph.add_edge(0, 1);\n  graph.add_edge(1, 2);\n  graph.add_edge(3, 1);\n \
    \ graph.add_edge(3, 4);\n  graph.add_edge(4, 5);\n  graph.add_edge(5, 2);\n  verify(graph);\n\
    }\n\nvoid small_00() {\n  tools::tsort graph(5);\n  graph.add_edge(0, 1);\n  graph.add_edge(0,\
    \ 2);\n  graph.add_edge(2, 3);\n  graph.add_edge(2, 4);\n  graph.add_edge(3, 4);\n\
    \  verify(graph);\n}\n\nvoid small_01() {\n  tools::tsort graph(6);\n  graph.add_edge(0,\
    \ 1);\n  graph.add_edge(0, 3);\n  graph.add_edge(0, 2);\n  graph.add_edge(2, 3);\n\
    \  graph.add_edge(1, 4);\n  graph.add_edge(3, 5);\n  graph.add_edge(4, 5);\n \
    \ verify(graph);\n}\n\nvoid small_02() {\n  tools::tsort graph(8);\n  graph.add_edge(0,\
    \ 1);\n  graph.add_edge(0, 2);\n  graph.add_edge(2, 1);\n  graph.add_edge(1, 3);\n\
    \  graph.add_edge(2, 3);\n  graph.add_edge(2, 4);\n  graph.add_edge(3, 4);\n \
    \ graph.add_edge(3, 5);\n  graph.add_edge(4, 6);\n  graph.add_edge(5, 7);\n  graph.add_edge(6,\
    \ 7);\n  verify(graph);\n}\n\nvoid small_03() {\n  tools::tsort graph(8);\n  graph.add_edge(0,\
    \ 1);\n  graph.add_edge(0, 3);\n  graph.add_edge(1, 2);\n  graph.add_edge(4, 5);\n\
    \  graph.add_edge(4, 7);\n  graph.add_edge(5, 7);\n  graph.add_edge(7, 6);\n \
    \ verify(graph);\n}\n\nvoid small_04() {\n  tools::tsort graph(8);\n  graph.add_edge(0,\
    \ 7);\n  graph.add_edge(1, 7);\n  graph.add_edge(2, 7);\n  graph.add_edge(3, 7);\n\
    \  graph.add_edge(4, 7);\n  graph.add_edge(5, 7);\n  graph.add_edge(6, 7);\n \
    \ verify(graph);\n}\n\nvoid small_05() {\n  tools::tsort graph(9);\n  graph.add_edge(1,\
    \ 2);\n  graph.add_edge(3, 4);\n  graph.add_edge(5, 6);\n  graph.add_edge(7, 8);\n\
    \  graph.add_edge(0, 2);\n  graph.add_edge(0, 3);\n  graph.add_edge(0, 6);\n \
    \ graph.add_edge(0, 7);\n  verify(graph);\n}\n\nvoid small_06() {\n  tools::tsort\
    \ graph(5);\n  graph.add_edge(0, 1);\n  graph.add_edge(0, 2);\n  graph.add_edge(2,\
    \ 3);\n  graph.add_edge(2, 4);\n  graph.add_edge(3, 4);\n  verify(graph);\n}\n\
    \nvoid corner_00() {\n  tools::tsort graph(2);\n  graph.add_edge(0, 1);\n  verify(graph);\n\
    }\n\nvoid corner_01() {\n  tools::tsort graph(2);\n  verify(graph);\n}\n\nvoid\
    \ corner_02() {\n  tools::tsort graph(4);\n  graph.add_edge(0, 1);\n  graph.add_edge(2,\
    \ 3);\n  verify(graph);\n}\n\nvoid corner_03() {\n  tools::tsort graph(3);\n \
    \ graph.add_edge(0, 2);\n  graph.add_edge(1, 2);\n  verify(graph);\n}\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  sample_00();\n\
    \  small_00();\n  small_01();\n  small_02();\n  small_03();\n  small_04();\n \
    \ small_05();\n  small_06();\n  corner_00();\n  corner_01();\n  corner_02();\n\
    \  corner_03();\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/tsort.hpp
  - tools/pow2.hpp
  - tools/permutation.hpp
  isVerificationFile: true
  path: tests/tsort/query.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tsort/query.test.cpp
layout: document
redirect_from:
- /verify/tests/tsort/query.test.cpp
- /verify/tests/tsort/query.test.cpp.html
title: tests/tsort/query.test.cpp
---
