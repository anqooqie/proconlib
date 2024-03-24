---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cartesian_tree.hpp
    title: Cartesian tree
  - icon: ':question:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/cumsum2d.hpp
    title: 2D cumulative sum
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc311/tasks/abc311_g
    links:
    - https://atcoder.jp/contests/abc311/tasks/abc311_g
  bundledCode: "#line 1 \"tests/cartesian_tree/interval.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc311/tasks/abc311_g\"\n\n#include <iostream>\n\
    #include <vector>\n#include <limits>\n#include <functional>\n#line 1 \"tools/cumsum2d.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 6 \"tools/cumsum2d.hpp\"\n#include <iterator>\n\
    #include <algorithm>\n#include <cassert>\n\nnamespace tools {\n\n  template <typename\
    \ G>\n  class cumsum2d {\n  private:\n    using T = typename G::T;\n    ::std::size_t\
    \ height;\n    ::std::size_t width;\n    ::std::vector<T> preprocessed;\n\n  public:\n\
    \    template <typename Range>\n    explicit cumsum2d(const Range& range) {\n\
    \      const auto begin = ::std::begin(range);\n      const auto end = ::std::end(range);\n\
    \      this->height = ::std::distance(begin, end);\n      this->width = this->height\
    \ == 0 ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin));\n    \
    \  this->preprocessed.reserve((this->height + 1) * (this->width + 1));\n     \
    \ ::std::fill_n(::std::back_inserter(this->preprocessed), (this->height + 1) *\
    \ (this->width + 1), G::e());\n\n      {\n        auto it1 = begin;\n        for\
    \ (::std::size_t y = 0; y < this->height; ++y, ++it1) {\n          auto it2 =\
    \ ::std::begin(*it1);\n          for (::std::size_t x = 0; x < this->width; ++x,\
    \ ++it2) {\n            this->preprocessed[(y + 1) * (this->width + 1) + (x +\
    \ 1)] = G::op(this->preprocessed[(y + 1) * (this->width + 1) + x], *it2);\n  \
    \        }\n        }\n      }\n      for (::std::size_t x = 0; x < this->width;\
    \ ++x) {\n        for (::std::size_t y = 0; y < this->height; ++y) {\n       \
    \   this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)] = G::op(this->preprocessed[y\
    \ * (this->width + 1) + (x + 1)], this->preprocessed[(y + 1) * (this->width +\
    \ 1) + (x + 1)]);\n        }\n      }\n    }\n\n    T query(const ::std::size_t\
    \ y1, const ::std::size_t y2, const ::std::size_t x1, const ::std::size_t x2)\
    \ const {\n      assert(y1 <= y2 && y2 <= this->height);\n      assert(x1 <= x2\
    \ && x2 <= this->width);\n      return G::op(\n        G::op(\n          G::op(\n\
    \            this->preprocessed[y2 * (this->width + 1) + x2],\n            G::inv(this->preprocessed[y2\
    \ * (this->width + 1) + x1])\n          ),\n          G::inv(this->preprocessed[y1\
    \ * (this->width + 1) + x2])\n        ),\n        this->preprocessed[y1 * (this->width\
    \ + 1) + x1]\n      );\n    }\n  };\n}\n\n\n#line 1 \"tools/group.hpp\"\n\n\n\n\
    namespace tools {\n  namespace group {\n    template <typename G>\n    struct\
    \ plus {\n      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n\
    \        return lhs + rhs;\n      }\n      static T e() {\n        return T(0);\n\
    \      }\n      static T inv(const T& v) {\n        return -v;\n      }\n    };\n\
    \n    template <typename G>\n    struct multiplies {\n      using T = G;\n   \
    \   static T op(const T& lhs, const T& rhs) {\n        return lhs * rhs;\n   \
    \   }\n      static T e() {\n        return T(1);\n      }\n      static T inv(const\
    \ T& v) {\n        return e() / v;\n      }\n    };\n\n    template <typename\
    \ G>\n    struct bit_xor {\n      using T = G;\n      static T op(const T& lhs,\
    \ const T& rhs) {\n        return lhs ^ rhs;\n      }\n      static T e() {\n\
    \        return T(0);\n      }\n      static T inv(const T& v) {\n        return\
    \ v;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 6 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated\
    \ = rhs < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 1 \"tools/cartesian_tree.hpp\"\n\n\n\n#line 6 \"tools/cartesian_tree.hpp\"\
    \n#include <utility>\n#line 9 \"tools/cartesian_tree.hpp\"\n#include <stack>\n\
    #line 11 \"tools/cartesian_tree.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T, typename Compare = ::std::less<T>>\n  class cartesian_tree {\n  public:\n\
    \    struct vertex {\n      ::std::size_t parent;\n      ::std::size_t left;\n\
    \      ::std::size_t right;\n      ::std::pair<::std::size_t, ::std::size_t> interval;\n\
    \    };\n\n  private:\n    Compare m_comp;\n    ::std::vector<vertex> m_vertices;\n\
    \n  public:\n    cartesian_tree() = default;\n    cartesian_tree(const ::tools::cartesian_tree<T,\
    \ Compare>&) = default;\n    cartesian_tree(::tools::cartesian_tree<T, Compare>&&)\
    \ = default;\n    ~cartesian_tree() = default;\n    ::tools::cartesian_tree<T,\
    \ Compare>& operator=(const ::tools::cartesian_tree<T, Compare>&) = default;\n\
    \    ::tools::cartesian_tree<T, Compare>& operator=(::tools::cartesian_tree<T,\
    \ Compare>&&) = default;\n\n    explicit cartesian_tree(const ::std::vector<T>&\
    \ a, const Compare& comp = Compare()) : m_comp(comp), m_vertices(a.size()) {\n\
    \      const auto NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    \
    \  for (::std::size_t i = 0; i < a.size(); ++i) {\n        this->m_vertices[i].parent\
    \ = i ? i - 1 : NONE;\n        this->m_vertices[i].left = NONE;\n        this->m_vertices[i].right\
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
    \ const {\n      return this->m_vertices;\n    }\n  };\n}\n\n\n#line 1 \"tools/chmax.hpp\"\
    \n\n\n\n#line 6 \"tools/chmax.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  bool chmax(M& lhs, const N& rhs) {\n    bool updated;\n  \
    \  if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>) {\n     \
    \ updated = ::tools::cmp_less(lhs, rhs);\n    } else {\n      updated = lhs <\
    \ rhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 12 \"tests/cartesian_tree/interval.test.cpp\"\n\nusing ll = long long;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, M;\n  std::cin >> N >> M;\n  auto A = std::vector(N, std::vector<int>(M));\n\
    \  for (auto& A_r : A) {\n    for (auto& A_rc: A_r) {\n      std::cin >> A_rc;\n\
    \    }\n  }\n\n  const tools::cumsum2d<tools::group::plus<int>> sum(A);\n\n  ll\
    \ answer = std::numeric_limits<ll>::min();\n  for (int r1 = 0; r1 < N; ++r1) {\n\
    \    std::vector<int> row(M, std::numeric_limits<int>::max());\n    for (int r2\
    \ = r1 + 1; r2 <= N; ++r2) {\n      for (int c = 0; c < M; ++c) {\n        tools::chmin(row[c],\
    \ A[r2 - 1][c]);\n      }\n      const tools::cartesian_tree<int> cartesian_tree(row);\n\
    \      for (int c = 0; c < M; ++c) {\n        const auto& [c1, c2] = cartesian_tree.get_vertex(c).interval;\n\
    \        tools::chmax(answer, static_cast<ll>(row[c]) * sum.query(r1, r2, c1,\
    \ c2));\n      }\n    }\n  }\n\n  std::cout << answer << '\\n';\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc311/tasks/abc311_g\"\n\n\
    #include <iostream>\n#include <vector>\n#include <limits>\n#include <functional>\n\
    #include \"tools/cumsum2d.hpp\"\n#include \"tools/group.hpp\"\n#include \"tools/chmin.hpp\"\
    \n#include \"tools/cartesian_tree.hpp\"\n#include \"tools/chmax.hpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, M;\n  std::cin >> N >> M;\n  auto A = std::vector(N, std::vector<int>(M));\n\
    \  for (auto& A_r : A) {\n    for (auto& A_rc: A_r) {\n      std::cin >> A_rc;\n\
    \    }\n  }\n\n  const tools::cumsum2d<tools::group::plus<int>> sum(A);\n\n  ll\
    \ answer = std::numeric_limits<ll>::min();\n  for (int r1 = 0; r1 < N; ++r1) {\n\
    \    std::vector<int> row(M, std::numeric_limits<int>::max());\n    for (int r2\
    \ = r1 + 1; r2 <= N; ++r2) {\n      for (int c = 0; c < M; ++c) {\n        tools::chmin(row[c],\
    \ A[r2 - 1][c]);\n      }\n      const tools::cartesian_tree<int> cartesian_tree(row);\n\
    \      for (int c = 0; c < M; ++c) {\n        const auto& [c1, c2] = cartesian_tree.get_vertex(c).interval;\n\
    \        tools::chmax(answer, static_cast<ll>(row[c]) * sum.query(r1, r2, c1,\
    \ c2));\n      }\n    }\n  }\n\n  std::cout << answer << '\\n';\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/cumsum2d.hpp
  - tools/group.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/cartesian_tree.hpp
  - tools/chmax.hpp
  isVerificationFile: true
  path: tests/cartesian_tree/interval.test.cpp
  requiredBy: []
  timestamp: '2024-03-24 19:16:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cartesian_tree/interval.test.cpp
layout: document
redirect_from:
- /verify/tests/cartesian_tree/interval.test.cpp
- /verify/tests/cartesian_tree/interval.test.cpp.html
title: tests/cartesian_tree/interval.test.cpp
---
