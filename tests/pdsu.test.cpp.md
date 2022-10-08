---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':x:'
    path: tools/pdsu.hpp
    title: Potentialized disjoint set union
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"tests/pdsu.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\
    \n\n#include <iostream>\n#line 1 \"tools/pdsu.hpp\"\n\n\n\n#include <vector>\n\
    #include <cassert>\n#include <numeric>\n#include <utility>\n#line 1 \"tools/group.hpp\"\
    \n\n\n\nnamespace tools {\n  namespace group {\n    template <typename Type>\n\
    \    struct plus {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return lhs + rhs;\n      }\n      static T e() {\n       \
    \ return T(0);\n      }\n      static T inv(const T v) {\n        return -v;\n\
    \      }\n    };\n\n    template <typename Type>\n    struct bit_xor {\n     \
    \ using T = Type;\n      static T op(const T lhs, const T rhs) {\n        return\
    \ lhs ^ rhs;\n      }\n      static T e() {\n        return T(0);\n      }\n \
    \     static T inv(const T v) {\n        return v;\n      }\n    };\n  }\n}\n\n\
    \n#line 9 \"tools/pdsu.hpp\"\n\nnamespace tools {\n  template <typename G = ::tools::group::plus<long\
    \ long>>\n  class pdsu {\n  private:\n    using T = typename G::T;\n    ::std::vector<int>\
    \ m_parents;\n    ::std::vector<int> m_sizes;\n    ::std::vector<T> m_diffs;\n\
    \n  public:\n    pdsu(const int n) :\n      m_parents(n),\n      m_sizes(n, 1),\n\
    \      m_diffs(n, 0) {\n      assert(n >= 0);\n      ::std::iota(this->m_parents.begin(),\
    \ this->m_parents.end(), 0);\n    }\n\n    int size() const {\n      return this->m_parents.size();\n\
    \    }\n\n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      if (this->m_parents[x] == x) {\n        return x;\n      }\n      const\
    \ auto r = this->leader(this->m_parents[x]);\n      this->m_diffs[x] = G::op(this->m_diffs[x],\
    \ this->m_diffs[this->m_parents[x]]);\n      return this->m_parents[x] = r;\n\
    \    }\n\n  private:\n    T potential(const int x) {\n      assert(0 <= x && x\
    \ < this->size());\n      this->leader(x);\n      return this->m_diffs[x];\n \
    \   }\n\n  public:\n    T diff(const int x, const int y) {\n      assert(0 <=\
    \ x && x < this->size());\n      assert(0 <= y && y < this->size());\n      assert(this->same(x,\
    \ y));\n      return G::op(this->potential(y), G::inv(this->potential(x)));\n\
    \    }\n\n    bool same(const int x, const int y) {\n      assert(0 <= x && x\
    \ < this->size());\n      assert(0 <= y && y < this->size());\n      return this->leader(x)\
    \ == this->leader(y);\n    }\n\n    int merge(int x, int y, T w) {\n      assert(0\
    \ <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n    \
    \  assert(!this->same(x, y));\n\n      w = G::op(G::op(w, this->potential(x)),\
    \ G::inv(this->potential(y)));\n      x = this->leader(x);\n      y = this->leader(y);\n\
    \      if (x == y) return x;\n\n      if (this->m_sizes[x] < this->m_sizes[y])\
    \ {\n        ::std::swap(x, y);\n        w = G::inv(w);\n      }\n      this->m_parents[y]\
    \ = x;\n      this->m_sizes[x] += this->m_sizes[y];\n\n      this->m_diffs[y]\
    \ = w;\n      return x;\n    }\n\n    int size(const int x) {\n      assert(0\
    \ <= x && x < this->size());\n      return this->m_sizes[this->leader(x)];\n \
    \   }\n\n    ::std::vector<::std::vector<int>> groups() {\n      ::std::vector<int>\
    \ group_indices(this->size(), -1);\n      int next_group_index = 0;\n      for\
    \ (int i = 0; i < this->size(); ++i) {\n        if (group_indices[this->leader(i)]\
    \ == -1) {\n          group_indices[this->leader(i)] = next_group_index;\n   \
    \       ++next_group_index;\n        }\n      }\n\n      ::std::vector<::std::vector<int>>\
    \ groups(next_group_index);\n      for (int i = 0; i < this->size(); ++i) {\n\
    \        groups[group_indices[this->leader(i)]].push_back(i);\n      }\n\n   \
    \   return groups;\n    }\n  };\n}\n\n\n#line 5 \"tests/pdsu.test.cpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll n, q;\n  std::cin >> n >> q;\n  tools::pdsu pdsu(n);\n  for (ll i = 0;\
    \ i < q; ++i) {\n    ll t;\n    std::cin >> t;\n    if (t == 0) {\n      ll x,\
    \ y, z;\n      std::cin >> x >> y >> z;\n      if (pdsu.same(x, y)) {\n      \
    \  assert(pdsu.diff(x, y) == z);\n      } else {\n        pdsu.merge(x, y, z);\n\
    \      }\n    } else {\n      ll x, y;\n      std::cin >> x >> y;\n      if (pdsu.same(x,\
    \ y)) {\n        std::cout << pdsu.diff(x, y) << '\\n';\n      } else {\n    \
    \    std::cout << \"?\" << '\\n';\n      }\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n\n\
    #include <iostream>\n#include \"tools/pdsu.hpp\"\n\nusing ll = long long;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll n, q;\n  std::cin >> n >> q;\n  tools::pdsu pdsu(n);\n  for (ll i = 0;\
    \ i < q; ++i) {\n    ll t;\n    std::cin >> t;\n    if (t == 0) {\n      ll x,\
    \ y, z;\n      std::cin >> x >> y >> z;\n      if (pdsu.same(x, y)) {\n      \
    \  assert(pdsu.diff(x, y) == z);\n      } else {\n        pdsu.merge(x, y, z);\n\
    \      }\n    } else {\n      ll x, y;\n      std::cin >> x >> y;\n      if (pdsu.same(x,\
    \ y)) {\n        std::cout << pdsu.diff(x, y) << '\\n';\n      } else {\n    \
    \    std::cout << \"?\" << '\\n';\n      }\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/pdsu.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/pdsu.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/pdsu.test.cpp
layout: document
redirect_from:
- /verify/tests/pdsu.test.cpp
- /verify/tests/pdsu.test.cpp.html
title: tests/pdsu.test.cpp
---
