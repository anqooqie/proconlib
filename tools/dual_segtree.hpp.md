---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: tools/ceil_log2.hpp
    title: tools/ceil_log2.hpp
  - icon: ':warning:'
    path: tools/pow2.hpp
    title: tools/pow2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dual_segtree.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <cstdint>\n\nnamespace\
    \ tools {\n\n  /**\n   * computes $\\left\\lceil \\log_2(x) \\right\\rceil$\n\
    \   * Reference: Stack Overflow ( https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\
    \ )\n   * License: CC BY-SA 3.0\n   * @aurhor dgobbi ( https://stackoverflow.com/users/2154690/dgobbi\
    \ )\n   * @param x input\n   * @return $\\left\\lceil \\log_2(x) \\right\\rceil$\n\
    \   */\n  inline std::uint32_t ceil_log2(std::uint32_t x) {\n    static const\
    \ ::std::uint32_t t[6] = {\n      0xFFFF0000u,\n      0x0000FF00u,\n      0x000000F0u,\n\
    \      0x0000000Cu,\n      0x00000002u\n    };\n\n    ::std::uint32_t y = (((x\
    \ & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint32_t j = 16;\n\n    for (const ::std::uint32_t&\
    \ t_i : t) {\n      ::std::uint32_t k = (((x & t_i) == 0) ? 0 : j);\n      y +=\
    \ k;\n      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  /**\n \
    \  * computes $\\left\\lceil \\log_2(x) \\right\\rceil$\n   * Reference: Stack\
    \ Overflow ( https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\
    \ )\n   * License: CC BY-SA 3.0\n   * @aurhor dgobbi ( https://stackoverflow.com/users/2154690/dgobbi\
    \ )\n   * @param x input\n   * @return $\\left\\lceil \\log_2(x) \\right\\rceil$\n\
    \   */\n  inline ::std::uint64_t ceil_log2(::std::uint64_t x) {\n    static const\
    \ ::std::uint64_t t[6] = {\n      0xFFFFFFFF00000000u,\n      0x00000000FFFF0000u,\n\
    \      0x000000000000FF00u,\n      0x00000000000000F0u,\n      0x000000000000000Cu,\n\
    \      0x0000000000000002u\n    };\n\n    ::std::uint64_t y = (((x & (x - 1))\
    \ == 0) ? 0 : 1);\n    ::std::uint64_t j = 32;\n\n    for (const ::std::uint64_t&\
    \ t_i : t) {\n      ::std::uint64_t k = (((x & t_i) == 0) ? 0 : j);\n      y +=\
    \ k;\n      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  /**\n \
    \  * computes $\\left\\lceil \\log_2(x) \\right\\rceil$\n   * Reference: Stack\
    \ Overflow ( https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\
    \ )\n   * License: CC BY-SA 3.0\n   * @aurhor dgobbi ( https://stackoverflow.com/users/2154690/dgobbi\
    \ )\n   * @param x input\n   * @return $\\left\\lceil \\log_2(x) \\right\\rceil$\n\
    \   */\n  inline ::std::int32_t ceil_log2(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  /**\n   * computes $\\left\\lceil \\log_2(x) \\right\\rceil$\n   * Reference:\
    \ Stack Overflow ( https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\
    \ )\n   * License: CC BY-SA 3.0\n   * @aurhor dgobbi ( https://stackoverflow.com/users/2154690/dgobbi\
    \ )\n   * @param x input\n   * @return $\\left\\lceil \\log_2(x) \\right\\rceil$\n\
    \   */\n  inline ::std::int64_t ceil_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  /**\n   * power of two\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param <T> type of the operand\n   * @param\
    \ x exponent\n   * @return $2^x$\n   */\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  /**\n   * power of two\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param <T> type of the operand\n   * @param x exponent\n\
    \   * @return $2^x$\n   */\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 8 \"tools/dual_segtree.hpp\"\
    \n\nnamespace tools {\n\n  /**\n   * dual segment tree\n   * License: CC0\n  \
    \ *\n   * Usage:\n   * ```\n   * // range-add dual segment tree with 6 elements\n\
    \   * tools::dual_segtree<tools::group::plus<int>> dual_segtree(6);\n   *\n  \
    \ * // adds 30 to [0, 3)\n   * dual_segtree.apply(0, 3, 30);\n   *\n   * // obtains\
    \ operator at 2, that is 30\n   * std::cout << dual_segtree.get(2) << std::endl;\n\
    \   * ```\n   *\n   * @author anqooqie\n   * @param <M> monoid of operator\n \
    \  */\n  template <typename M>\n  class dual_segtree {\n  private:\n    using\
    \ T = typename M::T;\n    ::std::size_t height;\n    ::std::vector<T> lazy;\n\n\
    \    void propagate(const ::std::size_t node_id) {\n      if(this->lazy[node_id]\
    \ == M::e()) return;\n      this->lazy[(node_id << 1) | 0] = M::op(this->lazy[(node_id\
    \ << 1) | 0], this->lazy[node_id]);\n      this->lazy[(node_id << 1) | 1] = M::op(this->lazy[(node_id\
    \ << 1) | 1], this->lazy[node_id]);\n      this->lazy[node_id] = M::e();\n   \
    \ }\n\n    void thrust(const ::std::size_t node_id) {\n      for (::std::size_t\
    \ h = this->height; h > 0; --h) {\n        this->propagate(node_id >> h);\n  \
    \    }\n    }\n\n    ::std::size_t capacity() const {\n      return this->lazy.size()\
    \ / 2;\n    }\n\n  public:\n    dual_segtree(const ::std::size_t& n) :\n     \
    \ height(::tools::ceil_log2(n)),\n      lazy(::tools::pow2(this->height + 1),\
    \ M::e()) {\n    }\n\n    void apply(const ::std::size_t a, const ::std::size_t\
    \ b, const T& x) {\n      if(a >= b) return;\n\n      const ::std::size_t a_id\
    \ = a + this->capacity();\n      const ::std::size_t b_id = b + this->capacity()\
    \ - 1;\n\n      this->thrust(a_id);\n      this->thrust(b_id);\n\n      for (::std::size_t\
    \ l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {\n        if (l & 1) {\n \
    \         this->lazy[l] = M::op(this->lazy[l], x);\n          ++l;\n        }\n\
    \        if (r & 1) {\n          --r;\n          this->lazy[r] = M::op(this->lazy[r],\
    \ x);\n        }\n      }\n    }\n\n    T get(const ::std::size_t a) {\n     \
    \ const ::std::size_t node_id = a + this->capacity();\n      this->thrust(node_id);\n\
    \      return this->lazy[node_id];\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DUAL_SEGTREE_HPP\n#define TOOLS_DUAL_SEGTREE_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include \"tools/ceil_log2.hpp\"\n#include \"\
    tools/pow2.hpp\"\n\nnamespace tools {\n\n  /**\n   * dual segment tree\n   * License:\
    \ CC0\n   *\n   * Usage:\n   * ```\n   * // range-add dual segment tree with 6\
    \ elements\n   * tools::dual_segtree<tools::group::plus<int>> dual_segtree(6);\n\
    \   *\n   * // adds 30 to [0, 3)\n   * dual_segtree.apply(0, 3, 30);\n   *\n \
    \  * // obtains operator at 2, that is 30\n   * std::cout << dual_segtree.get(2)\
    \ << std::endl;\n   * ```\n   *\n   * @author anqooqie\n   * @param <M> monoid\
    \ of operator\n   */\n  template <typename M>\n  class dual_segtree {\n  private:\n\
    \    using T = typename M::T;\n    ::std::size_t height;\n    ::std::vector<T>\
    \ lazy;\n\n    void propagate(const ::std::size_t node_id) {\n      if(this->lazy[node_id]\
    \ == M::e()) return;\n      this->lazy[(node_id << 1) | 0] = M::op(this->lazy[(node_id\
    \ << 1) | 0], this->lazy[node_id]);\n      this->lazy[(node_id << 1) | 1] = M::op(this->lazy[(node_id\
    \ << 1) | 1], this->lazy[node_id]);\n      this->lazy[node_id] = M::e();\n   \
    \ }\n\n    void thrust(const ::std::size_t node_id) {\n      for (::std::size_t\
    \ h = this->height; h > 0; --h) {\n        this->propagate(node_id >> h);\n  \
    \    }\n    }\n\n    ::std::size_t capacity() const {\n      return this->lazy.size()\
    \ / 2;\n    }\n\n  public:\n    dual_segtree(const ::std::size_t& n) :\n     \
    \ height(::tools::ceil_log2(n)),\n      lazy(::tools::pow2(this->height + 1),\
    \ M::e()) {\n    }\n\n    void apply(const ::std::size_t a, const ::std::size_t\
    \ b, const T& x) {\n      if(a >= b) return;\n\n      const ::std::size_t a_id\
    \ = a + this->capacity();\n      const ::std::size_t b_id = b + this->capacity()\
    \ - 1;\n\n      this->thrust(a_id);\n      this->thrust(b_id);\n\n      for (::std::size_t\
    \ l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {\n        if (l & 1) {\n \
    \         this->lazy[l] = M::op(this->lazy[l], x);\n          ++l;\n        }\n\
    \        if (r & 1) {\n          --r;\n          this->lazy[r] = M::op(this->lazy[r],\
    \ x);\n        }\n      }\n    }\n\n    T get(const ::std::size_t a) {\n     \
    \ const ::std::size_t node_id = a + this->capacity();\n      this->thrust(node_id);\n\
    \      return this->lazy[node_id];\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/dual_segtree.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/dual_segtree.hpp
layout: document
redirect_from:
- /library/tools/dual_segtree.hpp
- /library/tools/dual_segtree.hpp.html
title: tools/dual_segtree.hpp
---
