---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cartesian_tree.hpp
    title: Cartesian tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"tests/cartesian_tree/parent.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include <iostream>\n\
    #include <vector>\n#include <functional>\n#include <limits>\n#include <cstddef>\n\
    #line 1 \"tools/cartesian_tree.hpp\"\n\n\n\n#line 6 \"tools/cartesian_tree.hpp\"\
    \n#include <utility>\n#line 9 \"tools/cartesian_tree.hpp\"\n#include <stack>\n\
    #include <cassert>\n\nnamespace tools {\n  template <typename T, typename Compare\
    \ = ::std::less<T>>\n  class cartesian_tree {\n  public:\n    struct vertex {\n\
    \      ::std::size_t parent;\n      ::std::size_t left;\n      ::std::size_t right;\n\
    \      ::std::pair<::std::size_t, ::std::size_t> interval;\n    };\n\n  private:\n\
    \    Compare m_comp;\n    ::std::vector<vertex> m_vertices;\n\n  public:\n   \
    \ cartesian_tree() = default;\n    cartesian_tree(const ::tools::cartesian_tree<T,\
    \ Compare>&) = default;\n    cartesian_tree(::tools::cartesian_tree<T, Compare>&&)\
    \ = default;\n    ~cartesian_tree() = default;\n    ::tools::cartesian_tree<T,\
    \ Compare>& operator=(const ::tools::cartesian_tree<T, Compare>&) = default;\n\
    \    ::tools::cartesian_tree<T, Compare>& operator=(::tools::cartesian_tree<T,\
    \ Compare>&&) = default;\n\n    cartesian_tree(const ::std::vector<T>& a, const\
    \ Compare& comp = Compare()) : m_comp(comp), m_vertices(a.size()) {\n      const\
    \ auto NONE = ::std::numeric_limits<::std::size_t>::max();\n\n      for (::std::size_t\
    \ i = 0; i < a.size(); ++i) {\n        this->m_vertices[i].parent = i ? i - 1\
    \ : NONE;\n        this->m_vertices[i].left = NONE;\n        this->m_vertices[i].right\
    \ = NONE;\n        auto c = NONE;\n        while (this->m_vertices[i].parent !=\
    \ NONE && this->m_comp(a[i], a[this->m_vertices[i].parent])) {\n          if (c\
    \ != NONE) {\n            this->m_vertices[c].parent = this->m_vertices[i].parent;\n\
    \          }\n          c = this->m_vertices[i].parent;\n\n          const auto\
    \ gp = this->m_vertices[this->m_vertices[i].parent].parent;\n          this->m_vertices[this->m_vertices[i].parent].parent\
    \ = i;\n          this->m_vertices[i].parent = gp;\n        }\n      }\n\n   \
    \   auto root = NONE;\n      for (::std::size_t i = 0; i < a.size(); ++i) {\n\
    \        const auto p = this->m_vertices[i].parent;\n        if (p == NONE) {\n\
    \          root = i;\n        } else {\n          if (p < i) {\n            this->m_vertices[p].right=\
    \ i;\n          } else {\n            this->m_vertices[p].left = i;\n        \
    \  }\n        }\n      }\n\n      ::std::vector<::std::size_t> strict_left(a.size());\n\
    \      strict_left[root] = 0;\n      this->m_vertices[root].interval = ::std::make_pair(0,\
    \ a.size());\n      ::std::stack<::std::size_t> stack;\n      stack.push(root);\n\
    \      while (!stack.empty()) {\n        const auto here = stack.top();\n    \
    \    stack.pop();\n        const auto& v = this->m_vertices[here];\n        if\
    \ (v.right != NONE) {\n          strict_left[v.right] = here + 1;\n          this->m_vertices[v.right].interval\
    \ = ::std::make_pair(\n            this->m_comp(a[here], a[v.right]) ? strict_left[v.right]\
    \ : this->m_vertices[here].interval.first,\n            this->m_vertices[here].interval.second\n\
    \          );\n          stack.push(v.right);\n        }\n        if (v.left !=\
    \ NONE) {\n          strict_left[v.left] = strict_left[here];\n          this->m_vertices[v.left].interval\
    \ = ::std::make_pair(strict_left[v.left], here);\n          stack.push(v.left);\n\
    \        }\n      }\n    }\n    template <typename InputIterator>\n    cartesian_tree(const\
    \ InputIterator begin, const InputIterator end, const Compare& comp = Compare())\
    \ : cartesian_tree(::std::vector<T>(begin, end), comp) {\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_vertices.size();\n    }\n    const vertex&\
    \ get_vertex(::std::size_t i) const {\n      assert(i < this->size());\n     \
    \ return this->m_vertices[i];\n    }\n    const ::std::vector<vertex>& vertices()\
    \ const {\n      return this->m_vertices;\n    }\n  };\n}\n\n\n#line 9 \"tests/cartesian_tree/parent.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N;\n  std::cin >> N;\n  std::vector<int> a(N);\n  for (auto& a_i : a)\
    \ std::cin >> a_i;\n\n  const tools::cartesian_tree<int> cartesian_tree(a);\n\
    \  for (int i = 0; i < N; ++i) {\n    if (i) std::cout << ' ';\n    auto p = cartesian_tree.get_vertex(i).parent;\n\
    \    if (p == std::numeric_limits<std::size_t>::max()) p = i;\n    std::cout <<\
    \ p;\n  }\n  std::cout << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <functional>\n#include <limits>\n#include\
    \ <cstddef>\n#include \"tools/cartesian_tree.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N;\n  std::cin >> N;\n  std::vector<int>\
    \ a(N);\n  for (auto& a_i : a) std::cin >> a_i;\n\n  const tools::cartesian_tree<int>\
    \ cartesian_tree(a);\n  for (int i = 0; i < N; ++i) {\n    if (i) std::cout <<\
    \ ' ';\n    auto p = cartesian_tree.get_vertex(i).parent;\n    if (p == std::numeric_limits<std::size_t>::max())\
    \ p = i;\n    std::cout << p;\n  }\n  std::cout << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/cartesian_tree.hpp
  isVerificationFile: true
  path: tests/cartesian_tree/parent.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 14:35:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cartesian_tree/parent.test.cpp
layout: document
redirect_from:
- /verify/tests/cartesian_tree/parent.test.cpp
- /verify/tests/cartesian_tree/parent.test.cpp.html
title: tests/cartesian_tree/parent.test.cpp
---
