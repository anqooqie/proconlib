---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/dual_segtree.hpp
    title: Dual segment tree
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
  bundledCode: "#line 1 \"tests/dual_segtree.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/monoid.hpp\"\n\n\n\
    \n#include <algorithm>\n#include <limits>\n#include <numeric>\n\nnamespace tools\
    \ {\n  namespace monoid {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
    \    struct max {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::max()>\n    struct min {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::min(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type>\n    struct multiplies {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs * rhs;\n  \
    \    }\n      static T e() {\n        return T(1);\n      }\n    };\n\n    template\
    \ <typename Type>\n    struct gcd {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::gcd(lhs, rhs);\n      }\n     \
    \ static T e() {\n        return T(0);\n      }\n    };\n\n    template <typename\
    \ Type, Type E>\n    struct update {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n      }\n     \
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/dual_segtree.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <vector>\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#line 5 \"tools/ceil_log2.hpp\"\n\nnamespace tools {\n\n  inline std::uint32_t\
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
    \  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 8 \"tools/dual_segtree.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M>\n  class dual_segtree {\n  private:\n\
    \    using T = typename M::T;\n    ::std::size_t height;\n    ::std::vector<T>\
    \ lazy;\n\n    void propagate(const ::std::size_t node_id) {\n      if(this->lazy[node_id]\
    \ == M::e()) return;\n      this->lazy[(node_id << 1) | 0] = M::op(this->lazy[node_id],\
    \ this->lazy[(node_id << 1) | 0]);\n      this->lazy[(node_id << 1) | 1] = M::op(this->lazy[node_id],\
    \ this->lazy[(node_id << 1) | 1]);\n      this->lazy[node_id] = M::e();\n    }\n\
    \n    void thrust(const ::std::size_t node_id) {\n      for (::std::size_t h =\
    \ this->height; h > 0; --h) {\n        this->propagate(node_id >> h);\n      }\n\
    \    }\n\n    ::std::size_t capacity() const {\n      return this->lazy.size()\
    \ / 2;\n    }\n\n  public:\n    dual_segtree(const ::std::size_t& n) :\n     \
    \ height(::tools::ceil_log2(n)),\n      lazy(::tools::pow2(this->height + 1),\
    \ M::e()) {\n    }\n\n    void apply(const ::std::size_t a, const ::std::size_t\
    \ b, const T& x) {\n      if(a >= b) return;\n\n      const ::std::size_t a_id\
    \ = a + this->capacity();\n      const ::std::size_t b_id = b + this->capacity()\
    \ - 1;\n\n      this->thrust(a_id);\n      this->thrust(b_id);\n\n      for (::std::size_t\
    \ l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {\n        if (l & 1) {\n \
    \         this->lazy[l] = M::op(x, this->lazy[l]);\n          ++l;\n        }\n\
    \        if (r & 1) {\n          --r;\n          this->lazy[r] = M::op(x, this->lazy[r]);\n\
    \        }\n      }\n    }\n\n    T get(const ::std::size_t a) {\n      const\
    \ ::std::size_t node_id = a + this->capacity();\n      this->thrust(node_id);\n\
    \      return this->lazy[node_id];\n    }\n  };\n}\n\n\n#line 8 \"tests/dual_segtree.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  i64 n, q;\n  std::cin >>\
    \ n >> q;\n\n  tools::dual_segtree<tools::monoid::update<i64, -1>> dual_segtree(n);\n\
    \  for (i64 i = 0; i < q; ++i) {\n    i64 type;\n    std::cin >> type;\n    if\
    \ (type == 0) {\n      i64 s, t, x;\n      std::cin >> s >> t >> x;\n      dual_segtree.apply(s,\
    \ t + 1, x);\n    } else {\n      i64 i;\n      std::cin >> i;\n      std::cout\
    \ << tools::monoid::update<i64, -1>::op(dual_segtree.get(i), tools::pow2<i64>(31)\
    \ - 1) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include \"tools/monoid.hpp\"\n#include\
    \ \"tools/dual_segtree.hpp\"\n#include \"tools/pow2.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  i64 n, q;\n  std::cin >> n >> q;\n\n  tools::dual_segtree<tools::monoid::update<i64,\
    \ -1>> dual_segtree(n);\n  for (i64 i = 0; i < q; ++i) {\n    i64 type;\n    std::cin\
    \ >> type;\n    if (type == 0) {\n      i64 s, t, x;\n      std::cin >> s >> t\
    \ >> x;\n      dual_segtree.apply(s, t + 1, x);\n    } else {\n      i64 i;\n\
    \      std::cin >> i;\n      std::cout << tools::monoid::update<i64, -1>::op(dual_segtree.get(i),\
    \ tools::pow2<i64>(31) - 1) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/monoid.hpp
  - tools/dual_segtree.hpp
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  isVerificationFile: true
  path: tests/dual_segtree.test.cpp
  requiredBy: []
  timestamp: '2021-06-27 14:42:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dual_segtree.test.cpp
layout: document
redirect_from:
- /verify/tests/dual_segtree.test.cpp
- /verify/tests/dual_segtree.test.cpp.html
title: tests/dual_segtree.test.cpp
---
