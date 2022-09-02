---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':heavy_check_mark:'
    path: tools/persistent_dual_segtree.hpp
    title: Persistent dual segment tree
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc253/tasks/abc253_f
    links:
    - https://atcoder.jp/contests/abc253/tasks/abc253_f
  bundledCode: "#line 1 \"tests/persistent_dual_segtree.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc253/tasks/abc253_f\"\n\n#include <iostream>\n\
    #include <cstdint>\n#include <vector>\n#include <utility>\n#line 1 \"tools/persistent_dual_segtree.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <limits>\n#line 7 \"tools/persistent_dual_segtree.hpp\"\
    \n#include <cassert>\n#include <algorithm>\n#line 1 \"tools/fix.hpp\"\n\n\n\n\
    #line 5 \"tools/fix.hpp\"\n#include <type_traits>\n\nnamespace tools {\n  template\
    \ <typename F>\n  struct fix : F {\n    template <typename G>\n    fix(G&& g)\
    \ : F({::std::forward<G>(g)}) {\n    }\n\n    template <typename... Args>\n  \
    \  decltype(auto) operator()(Args&&... args) const {\n      return F::operator()(*this,\
    \ ::std::forward<Args>(args)...);\n    }\n  };\n\n  template <typename F>\n  fix(F&&)\
    \ -> fix<::std::decay_t<F>>;\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#line 5 \"tools/ceil_log2.hpp\"\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  inline std::uint32_t\
    \ ceil_log2(std::uint32_t x) {\n    static const ::std::uint32_t t[6] = {\n  \
    \    0xFFFF0000u,\n      0x0000FF00u,\n      0x000000F0u,\n      0x0000000Cu,\n\
    \      0x00000002u\n    };\n\n    ::std::uint32_t y = (((x & (x - 1)) == 0) ?\
    \ 0 : 1);\n    ::std::uint32_t j = 16;\n\n    for (const ::std::uint32_t& t_i\
    \ : t) {\n      ::std::uint32_t k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n\
    \      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::uint64_t\
    \ ceil_log2(::std::uint64_t x) {\n    static const ::std::uint64_t t[6] = {\n\
    \      0xFFFFFFFF00000000u,\n      0x00000000FFFF0000u,\n      0x000000000000FF00u,\n\
    \      0x00000000000000F0u,\n      0x000000000000000Cu,\n      0x0000000000000002u\n\
    \    };\n\n    ::std::uint64_t y = (((x & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint64_t\
    \ j = 32;\n\n    for (const ::std::uint64_t& t_i : t) {\n      ::std::uint64_t\
    \ k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n      x >>= k;\n      j >>=\
    \ 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::int32_t ceil_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t ceil_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 12 \"tools/persistent_dual_segtree.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M>\n  class persistent_dual_segtree {\n  private:\n\
    \    using T = typename M::T;\n\n    struct node {\n      T lazy;\n      ::std::size_t\
    \ left;\n      ::std::size_t right;\n    };\n\n  public:\n    class buffer {\n\
    \    private:\n      ::std::vector<::tools::persistent_dual_segtree<M>::node>\
    \ m_nodes;\n\n    public:\n      buffer() = default;\n      buffer(const ::tools::persistent_dual_segtree<M>::buffer&)\
    \ = default;\n      buffer(::tools::persistent_dual_segtree<M>::buffer&&) = default;\n\
    \      ~buffer() = default;\n      ::tools::persistent_dual_segtree<M>::buffer&\
    \ operator=(const ::tools::persistent_dual_segtree<M>::buffer&) = default;\n \
    \     ::tools::persistent_dual_segtree<M>::buffer& operator=(::tools::persistent_dual_segtree<M>::buffer&&)\
    \ = default;\n\n      friend ::tools::persistent_dual_segtree<M>;\n    };\n\n\
    \  private:\n    static const ::std::size_t EMPTY = ::std::numeric_limits<::std::size_t>::max();\n\
    \    ::tools::persistent_dual_segtree<M>::buffer *m_buffer;\n    ::std::size_t\
    \ m_size;\n    ::std::size_t m_root;\n\n    persistent_dual_segtree(::tools::persistent_dual_segtree<M>::buffer\
    \ * const buffer, const ::std::size_t size, const ::std::size_t root) : m_buffer(buffer),\
    \ m_size(size), m_root(root) {\n    }\n\n  public:\n    persistent_dual_segtree()\
    \ = default;\n    persistent_dual_segtree(const ::tools::persistent_dual_segtree<M>&)\
    \ = default;\n    persistent_dual_segtree(::tools::persistent_dual_segtree<M>&&)\
    \ = default;\n    ~persistent_dual_segtree() = default;\n    ::tools::persistent_dual_segtree<M>&\
    \ operator=(const ::tools::persistent_dual_segtree<M>&) = default;\n    ::tools::persistent_dual_segtree<M>&\
    \ operator=(::tools::persistent_dual_segtree<M>&&) = default;\n\n    persistent_dual_segtree(::tools::persistent_dual_segtree<M>::buffer&\
    \ buffer, const ::std::size_t n) : m_buffer(&buffer), m_size(n), m_root(EMPTY)\
    \ {\n      if (n == 0) return;\n\n      this->m_root = ::tools::fix([&](auto&&\
    \ dfs, const ::std::size_t l, const ::std::size_t r) -> ::std::size_t {\n    \
    \    ::tools::persistent_dual_segtree<M>::node node;\n        node.lazy = M::e();\n\
    \        if (r - l == 1) {\n          node.left = EMPTY;\n          node.right\
    \ = EMPTY;\n        } else {\n          const auto mid = l + ::tools::pow2(::tools::ceil_log2(r\
    \ - l) - 1);\n          node.left = dfs(l, mid);\n          node.right = dfs(mid,\
    \ r);\n        }\n\n        buffer.m_nodes.push_back(node);\n        return buffer.m_nodes.size()\
    \ - 1;\n      })(0, n);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_size;\n    }\n\n    ::tools::persistent_dual_segtree<M> apply(const\
    \ ::std::size_t l, const ::std::size_t r, const T& x) {\n      assert(l <= r &&\
    \ r <= this->m_size);\n      if (l == r) return *this;\n      if (x == M::e())\
    \ return *this;\n\n      return ::tools::persistent_dual_segtree<M>(this->m_buffer,\
    \ this->m_size, ::tools::fix(\n        [&](auto&& dfs, const ::std::size_t old_node_id,\
    \ const ::std::size_t ll, const ::std::size_t rr, const T& xx) -> ::std::size_t\
    \ {\n          ::tools::persistent_dual_segtree<M>::node new_node;\n         \
    \ const auto new_lazy = M::op(xx, this->m_buffer->m_nodes[old_node_id].lazy);\n\
    \          if (::std::min(rr, r) <= ::std::max(ll, l)) {\n            new_node.lazy\
    \ = new_lazy;\n            new_node.left = this->m_buffer->m_nodes[old_node_id].left;\n\
    \            new_node.right = this->m_buffer->m_nodes[old_node_id].right;\n  \
    \        } else if (l <= ll && rr <= r) {\n            new_node.lazy = M::op(x,\
    \ new_lazy);\n            new_node.left = this->m_buffer->m_nodes[old_node_id].left;\n\
    \            new_node.right = this->m_buffer->m_nodes[old_node_id].right;\n  \
    \        } else {\n            const auto mid = ll + ::tools::pow2(::tools::ceil_log2(rr\
    \ - ll) - 1);\n            new_node.lazy = M::e();\n            new_node.left\
    \ = dfs(this->m_buffer->m_nodes[old_node_id].left, ll, mid, new_lazy);\n     \
    \       new_node.right = dfs(this->m_buffer->m_nodes[old_node_id].right, mid,\
    \ rr, new_lazy);\n          }\n\n          this->m_buffer->m_nodes.push_back(new_node);\n\
    \          return this->m_buffer->m_nodes.size() - 1;\n        }\n      )(this->m_root,\
    \ 0, this->m_size, M::e()));\n    }\n\n    T get(const ::std::size_t i) const\
    \ {\n      assert(i < this->m_size);\n\n      return ::tools::fix([&](auto&& dfs,\
    \ const ::std::size_t node_id, const ::std::size_t l, const ::std::size_t r, const\
    \ T& x) -> T {\n        const auto& node = this->m_buffer->m_nodes[node_id];\n\
    \        const auto new_lazy = M::op(x, node.lazy);\n        if (r - l == 1) return\
    \ new_lazy;\n\n        const auto mid = l + ::tools::pow2(::tools::ceil_log2(r\
    \ - l) - 1);\n        if (i < mid) {\n          return dfs(node.left, l, mid,\
    \ new_lazy);\n        } else {\n          return dfs(node.right, mid, r, new_lazy);\n\
    \        }\n      })(this->m_root, 0, this->m_size, M::e());\n    }\n  };\n}\n\
    \n\n#line 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace group {\n\
    \    template <typename Type>\n    struct plus {\n      using T = Type;\n    \
    \  static T op(const T lhs, const T rhs) {\n        return lhs + rhs;\n      }\n\
    \      static T e() {\n        return T(0);\n      }\n      static T inv(const\
    \ T v) {\n        return -v;\n      }\n    };\n\n    template <typename Type>\n\
    \    struct bit_xor {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return lhs ^ rhs;\n      }\n      static T e() {\n       \
    \ return T(0);\n      }\n      static T inv(const T v) {\n        return v;\n\
    \      }\n    };\n  }\n}\n\n\n#line 9 \"tests/persistent_dual_segtree.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, M, Q;\n  std::cin >> N >>\
    \ M >> Q;\n\n  std::vector<std::pair<i64, i64>> updated(N, std::make_pair(0, 0));\n\
    \  tools::persistent_dual_segtree<tools::group::plus<i64>>::buffer buffer;\n \
    \ std::vector<tools::persistent_dual_segtree<tools::group::plus<i64>>> dual_segtrees;\n\
    \  dual_segtrees.emplace_back(buffer, M);\n\n  for (i64 q = 0; q < Q; ++q) {\n\
    \    i64 t;\n    std::cin >> t;\n    if (t == 1) {\n      i64 l, r, x;\n     \
    \ std::cin >> l >> r >> x;\n      --l;\n      dual_segtrees.push_back(dual_segtrees.back().apply(l,\
    \ r, x));\n    } else if (t == 2) {\n      i64 i, x;\n      std::cin >> i >> x;\n\
    \      --i;\n      dual_segtrees.push_back(dual_segtrees.back());\n      updated[i]\
    \ = std::make_pair(q, x);\n    } else {\n      i64 i, j;\n      std::cin >> i\
    \ >> j;\n      --i, --j;\n      dual_segtrees.push_back(dual_segtrees.back());\n\
    \      const auto& [t, x] = updated[i];\n      std::cout << dual_segtrees.back().get(j)\
    \ - dual_segtrees[t].get(j) + x << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc253/tasks/abc253_f\"\n\n\
    #include <iostream>\n#include <cstdint>\n#include <vector>\n#include <utility>\n\
    #include \"tools/persistent_dual_segtree.hpp\"\n#include \"tools/group.hpp\"\n\
    \nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n \
    \ std::ios_base::sync_with_stdio(false);\n\n  i64 N, M, Q;\n  std::cin >> N >>\
    \ M >> Q;\n\n  std::vector<std::pair<i64, i64>> updated(N, std::make_pair(0, 0));\n\
    \  tools::persistent_dual_segtree<tools::group::plus<i64>>::buffer buffer;\n \
    \ std::vector<tools::persistent_dual_segtree<tools::group::plus<i64>>> dual_segtrees;\n\
    \  dual_segtrees.emplace_back(buffer, M);\n\n  for (i64 q = 0; q < Q; ++q) {\n\
    \    i64 t;\n    std::cin >> t;\n    if (t == 1) {\n      i64 l, r, x;\n     \
    \ std::cin >> l >> r >> x;\n      --l;\n      dual_segtrees.push_back(dual_segtrees.back().apply(l,\
    \ r, x));\n    } else if (t == 2) {\n      i64 i, x;\n      std::cin >> i >> x;\n\
    \      --i;\n      dual_segtrees.push_back(dual_segtrees.back());\n      updated[i]\
    \ = std::make_pair(q, x);\n    } else {\n      i64 i, j;\n      std::cin >> i\
    \ >> j;\n      --i, --j;\n      dual_segtrees.push_back(dual_segtrees.back());\n\
    \      const auto& [t, x] = updated[i];\n      std::cout << dual_segtrees.back().get(j)\
    \ - dual_segtrees[t].get(j) + x << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/persistent_dual_segtree.hpp
  - tools/fix.hpp
  - tools/pow2.hpp
  - tools/ceil_log2.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/persistent_dual_segtree.test.cpp
  requiredBy: []
  timestamp: '2022-06-18 20:06:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/persistent_dual_segtree.test.cpp
layout: document
redirect_from:
- /verify/tests/persistent_dual_segtree.test.cpp
- /verify/tests/persistent_dual_segtree.test.cpp.html
title: tests/persistent_dual_segtree.test.cpp
---
