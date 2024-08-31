---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/random_tree.hpp
    title: Random tree generator
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/random_tree.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <random>\n#line 1 \"lib/ac-library/atcoder/dsu.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\n// Implement (union by size) + (path compression)\n// Reference:\n\
    // Zvi Galil and Giuseppe F. Italiano,\n// Data structures and algorithms for\
    \ disjoint set union problems\nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n\
    \    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\n    int merge(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        int x = leader(a), y = leader(b);\n        if (x == y) return\
    \ x;\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n\
    \        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] =\
    \ x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/random_tree.hpp\"\n\n\n\n\
    #include <cstddef>\n#line 7 \"tools/random_tree.hpp\"\n#include <utility>\n#include\
    \ <numeric>\n#line 10 \"tools/random_tree.hpp\"\n\n// Source: https://twitter.com/anta_prg/status/869633557362163712\n\
    // License: unknown\n// Author: anta\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  class random_tree {\n  private:\n    ::std::size_t m_size;\n\n  public:\n\
    \    random_tree() = default;\n    random_tree(const ::tools::random_tree<T>&)\
    \ = default;\n    random_tree(::tools::random_tree<T>&&) = default;\n    ~random_tree()\
    \ = default;\n    ::tools::random_tree<T>& operator=(const ::tools::random_tree<T>&)\
    \ = default;\n    ::tools::random_tree<T>& operator=(::tools::random_tree<T>&&)\
    \ = default;\n\n    explicit random_tree(const ::std::size_t n) : m_size(n) {\n\
    \      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_size;\n    }\n\n    template <typename R>\n    ::std::vector<::std::pair<T,\
    \ T>> operator()(R& engine) const {\n      ::std::vector<::std::pair<T, T>> edges;\n\
    \n      ::std::vector<T> perm(this->size());\n      ::std::iota(perm.begin(),\
    \ perm.end(), 0);\n      for (::std::size_t i = 0; i + 1 < this->size(); ++i)\
    \ {\n        const auto x = ::std::uniform_int_distribution<::std::size_t>(0,\
    \ this->size() - i - 2)(engine);\n        const auto y = ::std::uniform_int_distribution<::std::size_t>(0,\
    \ this->size() - 1)(engine);\n        ::std::swap(perm[i + 1], perm[i + 1 + x]);\n\
    \        if (y < i + 1) ::std::swap(perm[i], perm[y]);\n        edges.emplace_back(perm[i],\
    \ perm[i + 1]);\n      }\n\n      return edges;\n    }\n  };\n}\n\n\n#line 8 \"\
    tests/random_tree.test.cpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  std::random_device seed_gen;\n\
    \  std::mt19937 engine(seed_gen());\n\n  for (ll n = 1; n <= 1000; ++n) {\n  \
    \  tools::random_tree<ll> dist(n);\n    for (ll i = 0; i < 10; ++i) {\n      atcoder::dsu\
    \ dsu(n);\n      ll edge_count = 0;\n      for (const auto& [u, v] : dist(engine))\
    \ {\n        dsu.merge(u, v);\n        ++edge_count;\n      }\n      assert_that(dsu.groups().size()\
    \ == 1);\n      assert_that(edge_count == n - 1);\n    }\n  }\n\n  std::cout <<\
    \ \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <random>\n#include \"atcoder/dsu.hpp\"\n#include\
    \ \"tools/assert_that.hpp\"\n#include \"tools/random_tree.hpp\"\n\nusing ll =\
    \ long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::random_device seed_gen;\n  std::mt19937 engine(seed_gen());\n\n  for\
    \ (ll n = 1; n <= 1000; ++n) {\n    tools::random_tree<ll> dist(n);\n    for (ll\
    \ i = 0; i < 10; ++i) {\n      atcoder::dsu dsu(n);\n      ll edge_count = 0;\n\
    \      for (const auto& [u, v] : dist(engine)) {\n        dsu.merge(u, v);\n \
    \       ++edge_count;\n      }\n      assert_that(dsu.groups().size() == 1);\n\
    \      assert_that(edge_count == n - 1);\n    }\n  }\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/random_tree.hpp
  isVerificationFile: true
  path: tests/random_tree.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/random_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/random_tree.test.cpp
- /verify/tests/random_tree.test.cpp.html
title: tests/random_tree.test.cpp
---
