---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':question:'
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
    #include <vector>\n#include <utility>\n#line 1 \"tools/persistent_dual_segtree.hpp\"\
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
    \n\n\n\n#line 7 \"tools/ceil_log2.hpp\"\n#include <tuple>\n#include <array>\n\
    #include <cstdint>\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  T ceil_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ceil_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      constexpr auto t = ::std::make_tuple(\n        ::std::array<::std::uint8_t,\
    \ 3>({\n          UINT8_C(0xf0),\n          UINT8_C(0x0c),\n          UINT8_C(0x02)\n\
    \        }),\n        ::std::array<::std::uint16_t, 4>({\n          UINT16_C(0xff00),\n\
    \          UINT16_C(0x00f0),\n          UINT16_C(0x000c),\n          UINT16_C(0x0002)\n\
    \        }),\n        ::std::array<::std::uint32_t, 5>({\n          UINT32_C(0xffff0000),\n\
    \          UINT32_C(0x0000ff00),\n          UINT32_C(0x000000f0),\n          UINT32_C(0x0000000c),\n\
    \          UINT32_C(0x00000002)\n        }),\n        ::std::array<::std::uint64_t,\
    \ 6>({\n          UINT64_C(0xffffffff00000000),\n          UINT64_C(0x00000000ffff0000),\n\
    \          UINT64_C(0x000000000000ff00),\n          UINT64_C(0x00000000000000f0),\n\
    \          UINT64_C(0x000000000000000c),\n          UINT64_C(0x0000000000000002)\n\
    \        })\n      );\n\n      T y = (((x & (x - 1)) == 0) ? 0 : 1);\n      T\
    \ j = ::std::numeric_limits<T>::digits / 2;\n\n      for (const auto t_i : ::std::get<log2(::std::numeric_limits<T>::digits)\
    \ - 3>(t)) {\n        T k = (((x & t_i) == 0) ? 0 : j);\n        y += k;\n   \
    \     x >>= k;\n        j >>= 1;\n      }\n\n      return y;\n    }\n  }\n}\n\n\
    \n#line 12 \"tools/persistent_dual_segtree.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M>\n  class persistent_dual_segtree {\n  private:\n    using T = typename\
    \ M::T;\n\n    struct node {\n      T lazy;\n      ::std::size_t left;\n     \
    \ ::std::size_t right;\n    };\n\n  public:\n    class buffer {\n    private:\n\
    \      ::std::vector<::tools::persistent_dual_segtree<M>::node> m_nodes;\n\n \
    \   public:\n      buffer() = default;\n      buffer(const ::tools::persistent_dual_segtree<M>::buffer&)\
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
    \    template <typename G>\n    struct plus {\n      using T = G;\n      static\
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
    \n\n#line 8 \"tests/persistent_dual_segtree.test.cpp\"\n\nusing ll = long long;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M, Q;\n  std::cin >> N >> M >> Q;\n\n  std::vector<std::pair<ll, ll>>\
    \ updated(N, std::make_pair(0, 0));\n  tools::persistent_dual_segtree<tools::group::plus<ll>>::buffer\
    \ buffer;\n  std::vector<tools::persistent_dual_segtree<tools::group::plus<ll>>>\
    \ dual_segtrees;\n  dual_segtrees.emplace_back(buffer, M);\n\n  for (ll q = 0;\
    \ q < Q; ++q) {\n    ll t;\n    std::cin >> t;\n    if (t == 1) {\n      ll l,\
    \ r, x;\n      std::cin >> l >> r >> x;\n      --l;\n      dual_segtrees.push_back(dual_segtrees.back().apply(l,\
    \ r, x));\n    } else if (t == 2) {\n      ll i, x;\n      std::cin >> i >> x;\n\
    \      --i;\n      dual_segtrees.push_back(dual_segtrees.back());\n      updated[i]\
    \ = std::make_pair(q, x);\n    } else {\n      ll i, j;\n      std::cin >> i >>\
    \ j;\n      --i, --j;\n      dual_segtrees.push_back(dual_segtrees.back());\n\
    \      const auto& [t, x] = updated[i];\n      std::cout << dual_segtrees.back().get(j)\
    \ - dual_segtrees[t].get(j) + x << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc253/tasks/abc253_f\"\n\n\
    #include <iostream>\n#include <vector>\n#include <utility>\n#include \"tools/persistent_dual_segtree.hpp\"\
    \n#include \"tools/group.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll N, M, Q;\n  std::cin >> N >>\
    \ M >> Q;\n\n  std::vector<std::pair<ll, ll>> updated(N, std::make_pair(0, 0));\n\
    \  tools::persistent_dual_segtree<tools::group::plus<ll>>::buffer buffer;\n  std::vector<tools::persistent_dual_segtree<tools::group::plus<ll>>>\
    \ dual_segtrees;\n  dual_segtrees.emplace_back(buffer, M);\n\n  for (ll q = 0;\
    \ q < Q; ++q) {\n    ll t;\n    std::cin >> t;\n    if (t == 1) {\n      ll l,\
    \ r, x;\n      std::cin >> l >> r >> x;\n      --l;\n      dual_segtrees.push_back(dual_segtrees.back().apply(l,\
    \ r, x));\n    } else if (t == 2) {\n      ll i, x;\n      std::cin >> i >> x;\n\
    \      --i;\n      dual_segtrees.push_back(dual_segtrees.back());\n      updated[i]\
    \ = std::make_pair(q, x);\n    } else {\n      ll i, j;\n      std::cin >> i >>\
    \ j;\n      --i, --j;\n      dual_segtrees.push_back(dual_segtrees.back());\n\
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
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/persistent_dual_segtree.test.cpp
layout: document
redirect_from:
- /verify/tests/persistent_dual_segtree.test.cpp
- /verify/tests/persistent_dual_segtree.test.cpp.html
title: tests/persistent_dual_segtree.test.cpp
---
