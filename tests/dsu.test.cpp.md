---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/dsu.hpp
    title: Disjoint set union
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"tests/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <iostream>\n#line 1 \"tools/dsu.hpp\"\n\n\n\n#include <vector>\n\
    #include <cassert>\n#include <utility>\n#include <algorithm>\n\nnamespace tools\
    \ {\n  class dsu {\n  private:\n    ::std::vector<int> m_parents;\n    ::std::vector<int>\
    \ m_sizes;\n\n    int size() const {\n      return this->m_parents.size();\n \
    \   }\n\n  public:\n    dsu() = default;\n    dsu(const ::tools::dsu&) = default;\n\
    \    dsu(::tools::dsu&&) = default;\n    ~dsu() = default;\n    ::tools::dsu&\
    \ operator=(const ::tools::dsu&) = default;\n    ::tools::dsu& operator=(::tools::dsu&&)\
    \ = default;\n\n    explicit dsu(const int n) :\n      m_parents(n),\n      m_sizes(n,\
    \ 1) {\n      for (int i = 0; i < n; ++i) {\n        this->m_parents[i] = i;\n\
    \      }\n    }\n\n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \n      return this->m_parents[x] == x ? x : (this->m_parents[x] = this->leader(this->m_parents[x]));\n\
    \    }\n\n    bool same(const int x, const int y) {\n      assert(0 <= x && x\
    \ < this->size());\n      assert(0 <= y && y < this->size());\n\n      return\
    \ this->leader(x) == this->leader(y);\n    }\n\n    int merge(int x, int y) {\n\
    \      assert(0 <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\
    \n      x = this->leader(x);\n      y = this->leader(y);\n      if (x == y) return\
    \ x;\n\n      if (this->m_sizes[x] < this->m_sizes[y]) ::std::swap(x, y);\n  \
    \    this->m_parents[y] = x;\n      this->m_sizes[x] += this->m_sizes[y];\n\n\
    \      return x;\n    }\n\n    int size(const int x) {\n      return this->m_sizes[this->leader(x)];\n\
    \    }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<::std::vector<int>>\
    \ res(this->size());\n      for (int i = 0; i < this->size(); ++i) {\n       \
    \ res[this->leader(i)].push_back(i);\n      }\n      res.erase(::std::remove_if(res.begin(),\
    \ res.end(), [](const auto& group) { return group.empty(); }), res.end());\n \
    \     return res;\n    }\n  };\n}\n\n\n#line 5 \"tests/dsu.test.cpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  int\
    \ N, Q;\n  std::cin >> N >> Q;\n  tools::dsu dsu(N);\n  for (int q = 0; q < Q;\
    \ ++q) {\n    int t, u, v;\n    std::cin >> t >> u >> v;\n    if (t == 0) {\n\
    \      dsu.merge(u, v);\n    } else {\n      std::cout << (dsu.same(u, v) ? 1\
    \ : 0) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include \"tools/dsu.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N, Q;\n  std::cin >> N >> Q;\n\
    \  tools::dsu dsu(N);\n  for (int q = 0; q < Q; ++q) {\n    int t, u, v;\n   \
    \ std::cin >> t >> u >> v;\n    if (t == 0) {\n      dsu.merge(u, v);\n    } else\
    \ {\n      std::cout << (dsu.same(u, v) ? 1 : 0) << '\\n';\n    }\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/dsu.hpp
  isVerificationFile: true
  path: tests/dsu.test.cpp
  requiredBy: []
  timestamp: '2022-09-19 16:01:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dsu.test.cpp
layout: document
redirect_from:
- /verify/tests/dsu.test.cpp
- /verify/tests/dsu.test.cpp.html
title: tests/dsu.test.cpp
---
