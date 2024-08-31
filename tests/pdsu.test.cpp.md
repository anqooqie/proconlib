---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':heavy_check_mark:'
    path: tools/pdsu.hpp
    title: Potentialized disjoint set union
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"tests/pdsu.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\
    \n\n#include <iostream>\n#include <cassert>\n#line 1 \"tools/pdsu.hpp\"\n\n\n\n\
    #include <vector>\n#line 6 \"tools/pdsu.hpp\"\n#include <numeric>\n#include <utility>\n\
    #line 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace group {\n  \
    \  template <typename G>\n    struct plus {\n      using T = G;\n      static\
    \ T op(const T& lhs, const T& rhs) {\n        return lhs + rhs;\n      }\n   \
    \   static T e() {\n        return T(0);\n      }\n      static T inv(const T&\
    \ v) {\n        return -v;\n      }\n    };\n\n    template <typename G>\n   \
    \ struct multiplies {\n      using T = G;\n      static T op(const T& lhs, const\
    \ T& rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n      \
    \  return T(1);\n      }\n      static T inv(const T& v) {\n        return e()\
    \ / v;\n      }\n    };\n\n    template <typename G>\n    struct bit_xor {\n \
    \     using T = G;\n      static T op(const T& lhs, const T& rhs) {\n        return\
    \ lhs ^ rhs;\n      }\n      static T e() {\n        return T(0);\n      }\n \
    \     static T inv(const T& v) {\n        return v;\n      }\n    };\n  }\n}\n\
    \n\n#line 9 \"tools/pdsu.hpp\"\n\nnamespace tools {\n  enum class pdsu_diff {\n\
    \    known,\n    unknown,\n    inconsistent\n  };\n\n  template <typename G =\
    \ ::tools::group::plus<long long>>\n  class pdsu {\n  private:\n    using T =\
    \ typename G::T;\n\n    ::std::vector<int> m_parents;\n    ::std::vector<int>\
    \ m_sizes;\n    ::std::vector<T> m_diffs;\n    ::std::vector<bool> m_consistent;\n\
    \n  public:\n    explicit pdsu(const int n) :\n      m_parents(n),\n      m_sizes(n,\
    \ 1),\n      m_diffs(n, G::e()),\n      m_consistent(n, true) {\n      assert(n\
    \ >= 0);\n      ::std::iota(this->m_parents.begin(), this->m_parents.end(), 0);\n\
    \    }\n\n    int size() const {\n      return this->m_parents.size();\n    }\n\
    \n    int leader(const int x) {\n      assert(0 <= x && x < this->size());\n \
    \     if (this->m_parents[x] == x) {\n        return x;\n      }\n      const\
    \ auto r = this->leader(this->m_parents[x]);\n      if (this->m_consistent[r])\
    \ {\n        this->m_diffs[x] = G::op(this->m_diffs[x], this->m_diffs[this->m_parents[x]]);\n\
    \      }\n      return this->m_parents[x] = r;\n    }\n\n    ::std::pair<::tools::pdsu_diff,\
    \ T> diff(const int x, const int y) {\n      assert(0 <= x && x < this->size());\n\
    \      assert(0 <= y && y < this->size());\n      const auto x_r = this->leader(x);\n\
    \      const auto y_r = this->leader(y);\n      if (x_r == y_r) {\n        if\
    \ (this->m_consistent[x_r]) {\n          return ::std::make_pair(::tools::pdsu_diff::known,\
    \ G::op(this->m_diffs[y], G::inv(this->m_diffs[x])));\n        } else {\n    \
    \      return ::std::make_pair(::tools::pdsu_diff::inconsistent, G::e());\n  \
    \      }\n      } else {\n        return ::std::make_pair(::tools::pdsu_diff::unknown,\
    \ G::e());\n      }\n    }\n\n    bool same(const int x, const int y) {\n    \
    \  assert(0 <= x && x < this->size());\n      assert(0 <= y && y < this->size());\n\
    \      return this->leader(x) == this->leader(y);\n    }\n\n    int merge(int\
    \ x, int y, T w) {\n      assert(0 <= x && x < this->size());\n      assert(0\
    \ <= y && y < this->size());\n\n      auto x_r = this->leader(x);\n      auto\
    \ y_r = this->leader(y);\n\n      if (x_r == y_r) {\n        this->m_consistent[x_r]\
    \ = (this->m_consistent[x_r] && G::op(this->m_diffs[x], w) == this->m_diffs[y]);\n\
    \        return x_r;\n      }\n\n      if (this->m_sizes[x_r] < this->m_sizes[y_r])\
    \ {\n        ::std::swap(x, y);\n        w = G::inv(w);\n        ::std::swap(x_r,\
    \ y_r);\n      }\n      this->m_parents[y_r] = x_r;\n      this->m_sizes[x_r]\
    \ += this->m_sizes[y_r];\n      if (this->m_consistent[x_r] = (this->m_consistent[x_r]\
    \ && this->m_consistent[y_r])) {\n        this->m_diffs[y_r] = G::op(G::op(w,\
    \ this->m_diffs[x]), G::inv(this->m_diffs[y]));\n      }\n      return x_r;\n\
    \    }\n\n    int size(const int x) {\n      assert(0 <= x && x < this->size());\n\
    \      return this->m_sizes[this->leader(x)];\n    }\n\n    ::std::vector<::std::vector<int>>\
    \ groups() {\n      ::std::vector<int> group_indices(this->size(), -1);\n    \
    \  int next_group_index = 0;\n      for (int i = 0; i < this->size(); ++i) {\n\
    \        if (group_indices[this->leader(i)] == -1) {\n          group_indices[this->leader(i)]\
    \ = next_group_index;\n          ++next_group_index;\n        }\n      }\n\n \
    \     ::std::vector<::std::vector<int>> groups(next_group_index);\n      for (int\
    \ i = 0; i < this->size(); ++i) {\n        groups[group_indices[this->leader(i)]].push_back(i);\n\
    \      }\n\n      return groups;\n    }\n  };\n}\n\n\n#line 6 \"tests/pdsu.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll n, q;\n  std::cin >> n >> q;\n  tools::pdsu pdsu(n);\n  for (ll i = 0;\
    \ i < q; ++i) {\n    ll t;\n    std::cin >> t;\n    if (t == 0) {\n      ll x,\
    \ y, z;\n      std::cin >> x >> y >> z;\n      pdsu.merge(x, y, z);\n      assert(pdsu.diff(x,\
    \ y).first == tools::pdsu_diff::known);\n    } else {\n      ll x, y;\n      std::cin\
    \ >> x >> y;\n      const auto [t, d] = pdsu.diff(x, y);\n      assert(t != tools::pdsu_diff::inconsistent);\n\
    \      if (t == tools::pdsu_diff::known) {\n        std::cout << d << '\\n';\n\
    \      } else {\n        std::cout << \"?\" << '\\n';\n      }\n    }\n  }\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n\n\
    #include <iostream>\n#include <cassert>\n#include \"tools/pdsu.hpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll n, q;\n  std::cin >> n >> q;\n  tools::pdsu pdsu(n);\n  for (ll i = 0;\
    \ i < q; ++i) {\n    ll t;\n    std::cin >> t;\n    if (t == 0) {\n      ll x,\
    \ y, z;\n      std::cin >> x >> y >> z;\n      pdsu.merge(x, y, z);\n      assert(pdsu.diff(x,\
    \ y).first == tools::pdsu_diff::known);\n    } else {\n      ll x, y;\n      std::cin\
    \ >> x >> y;\n      const auto [t, d] = pdsu.diff(x, y);\n      assert(t != tools::pdsu_diff::inconsistent);\n\
    \      if (t == tools::pdsu_diff::known) {\n        std::cout << d << '\\n';\n\
    \      } else {\n        std::cout << \"?\" << '\\n';\n      }\n    }\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/pdsu.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/pdsu.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/pdsu.test.cpp
layout: document
redirect_from:
- /verify/tests/pdsu.test.cpp
- /verify/tests/pdsu.test.cpp.html
title: tests/pdsu.test.cpp
---
