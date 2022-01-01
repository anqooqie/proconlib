---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/lca.hpp
    title: Lowest common ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/disjoint_sparse_table.test.cpp
    title: tests/disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lca.test.cpp
    title: tests/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/disjoint_sparse_table.hpp\"\n\n\n\n#include <vector>\n\
    #include <cstddef>\n#include <algorithm>\n#include <iterator>\n#include <cassert>\n\
    #line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <cstdint>\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n\
    \    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  inline ::std::uint64_t\
    \ popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 6 \"tools/floor_log2.hpp\"\n\nnamespace tools {\n\n  inline\
    \ ::std::uint32_t floor_log2(::std::uint32_t x) {\n    x |= (x >> static_cast<::std::uint32_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(2));\n    x |= (x >> static_cast<::std::uint32_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(8));\n    x |= (x >> static_cast<::std::uint32_t>(16));\n\
    \    return ::tools::popcount(x) - static_cast<::std::uint32_t>(1);\n  }\n\n \
    \ inline ::std::uint64_t floor_log2(::std::uint64_t x) {\n    x |= (x >> static_cast<::std::uint64_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(2));\n    x |= (x >> static_cast<::std::uint64_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(8));\n    x |= (x >> static_cast<::std::uint64_t>(16));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(32));\n    return ::tools::popcount(x)\
    \ - static_cast<::std::uint64_t>(1);\n  }\n\n  inline ::std::int32_t floor_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t floor_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 12 \"tools/disjoint_sparse_table.hpp\"\n\nnamespace tools {\n\
    \  template <typename M>\n  class disjoint_sparse_table {\n  private:\n    using\
    \ T = typename M::T;\n    ::std::vector<T> m_value;\n    ::std::size_t m_size;\n\
    \    ::std::size_t m_capacity;\n    ::std::size_t m_height;\n\n  public:\n   \
    \ disjoint_sparse_table() = default;\n    disjoint_sparse_table(const ::tools::disjoint_sparse_table<M>&)\
    \ = default;\n    disjoint_sparse_table(::tools::disjoint_sparse_table<M>&&) =\
    \ default;\n    ~disjoint_sparse_table() = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(const ::tools::disjoint_sparse_table<M>&) = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(::tools::disjoint_sparse_table<M>&&) = default;\n\n    template <typename\
    \ InputIterator>\n    disjoint_sparse_table(const InputIterator& begin, const\
    \ InputIterator& end) {\n      ::std::copy(begin, end, ::std::back_inserter(this->m_value));\n\
    \      this->m_size = this->m_value.size();\n      this->m_height = this->m_size\
    \ <= 1 ? this->m_size : ::tools::ceil_log2(this->m_size);\n      this->m_capacity\
    \ = this->m_size <= 1 ? this->m_size : ::tools::pow2(this->m_height);\n      this->m_value.resize(this->m_height\
    \ * this->m_capacity);\n      ::std::fill(this->m_value.begin() + this->m_size,\
    \ this->m_value.begin() + this->m_capacity, M::e());\n\n      for (::std::size_t\
    \ d = 1; d < this->m_height; ++d) {\n        const ::std::size_t offset = d *\
    \ this->m_capacity;\n        for (::std::size_t m = ::tools::pow2(d); m < this->m_capacity;\
    \ m += ::tools::pow2(d + 1)) {\n          this->m_value[offset + (m - 1)] = this->m_value[m\
    \ - 1];\n          this->m_value[offset + m] = this->m_value[m];\n          for\
    \ (::std::size_t l = m - 1; l --> m - ::tools::pow2(d);) {\n            this->m_value[offset\
    \ + l] = M::op(this->m_value[l], this->m_value[offset + (l + 1)]);\n         \
    \ }\n          for (::std::size_t r = m + 2; r <= m + ::tools::pow2(d); ++r) {\n\
    \            this->m_value[offset + (r - 1)] = M::op(this->m_value[offset + (r\
    \ - 2)], this->m_value[r - 1]);\n          }\n        }\n      }\n    }\n\n  \
    \  ::std::size_t size() const {\n      return this->m_size;\n    }\n\n    T prod(const\
    \ ::std::size_t l, const ::std::size_t r) const {\n      assert(l <= r && r <=\
    \ this->m_size);\n      if (r - l == 0) {\n        return M::e();\n      } else\
    \ if (r - l == 1) {\n        return this->m_value[l];\n      } else {\n      \
    \  const ::std::size_t offset = ::tools::floor_log2(l ^ (r - 1)) * this->m_capacity;\n\
    \        return M::op(this->m_value[offset + l], this->m_value[offset + (r - 1)]);\n\
    \      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DISJOINT_SPARSE_TABLE_HPP\n#define TOOLS_DISJOINT_SPARSE_TABLE_HPP\n\
    \n#include <vector>\n#include <cstddef>\n#include <algorithm>\n#include <iterator>\n\
    #include <cassert>\n#include \"tools/ceil_log2.hpp\"\n#include \"tools/pow2.hpp\"\
    \n#include \"tools/floor_log2.hpp\"\n\nnamespace tools {\n  template <typename\
    \ M>\n  class disjoint_sparse_table {\n  private:\n    using T = typename M::T;\n\
    \    ::std::vector<T> m_value;\n    ::std::size_t m_size;\n    ::std::size_t m_capacity;\n\
    \    ::std::size_t m_height;\n\n  public:\n    disjoint_sparse_table() = default;\n\
    \    disjoint_sparse_table(const ::tools::disjoint_sparse_table<M>&) = default;\n\
    \    disjoint_sparse_table(::tools::disjoint_sparse_table<M>&&) = default;\n \
    \   ~disjoint_sparse_table() = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(const ::tools::disjoint_sparse_table<M>&) = default;\n    ::tools::disjoint_sparse_table<M>&\
    \ operator=(::tools::disjoint_sparse_table<M>&&) = default;\n\n    template <typename\
    \ InputIterator>\n    disjoint_sparse_table(const InputIterator& begin, const\
    \ InputIterator& end) {\n      ::std::copy(begin, end, ::std::back_inserter(this->m_value));\n\
    \      this->m_size = this->m_value.size();\n      this->m_height = this->m_size\
    \ <= 1 ? this->m_size : ::tools::ceil_log2(this->m_size);\n      this->m_capacity\
    \ = this->m_size <= 1 ? this->m_size : ::tools::pow2(this->m_height);\n      this->m_value.resize(this->m_height\
    \ * this->m_capacity);\n      ::std::fill(this->m_value.begin() + this->m_size,\
    \ this->m_value.begin() + this->m_capacity, M::e());\n\n      for (::std::size_t\
    \ d = 1; d < this->m_height; ++d) {\n        const ::std::size_t offset = d *\
    \ this->m_capacity;\n        for (::std::size_t m = ::tools::pow2(d); m < this->m_capacity;\
    \ m += ::tools::pow2(d + 1)) {\n          this->m_value[offset + (m - 1)] = this->m_value[m\
    \ - 1];\n          this->m_value[offset + m] = this->m_value[m];\n          for\
    \ (::std::size_t l = m - 1; l --> m - ::tools::pow2(d);) {\n            this->m_value[offset\
    \ + l] = M::op(this->m_value[l], this->m_value[offset + (l + 1)]);\n         \
    \ }\n          for (::std::size_t r = m + 2; r <= m + ::tools::pow2(d); ++r) {\n\
    \            this->m_value[offset + (r - 1)] = M::op(this->m_value[offset + (r\
    \ - 2)], this->m_value[r - 1]);\n          }\n        }\n      }\n    }\n\n  \
    \  ::std::size_t size() const {\n      return this->m_size;\n    }\n\n    T prod(const\
    \ ::std::size_t l, const ::std::size_t r) const {\n      assert(l <= r && r <=\
    \ this->m_size);\n      if (r - l == 0) {\n        return M::e();\n      } else\
    \ if (r - l == 1) {\n        return this->m_value[l];\n      } else {\n      \
    \  const ::std::size_t offset = ::tools::floor_log2(l ^ (r - 1)) * this->m_capacity;\n\
    \        return M::op(this->m_value[offset + l], this->m_value[offset + (r - 1)]);\n\
    \      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/disjoint_sparse_table.hpp
  requiredBy:
  - tools/lca.hpp
  timestamp: '2021-12-29 01:11:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lca.test.cpp
  - tests/disjoint_sparse_table.test.cpp
documentation_of: tools/disjoint_sparse_table.hpp
layout: document
title: Disjoint sparse table
---

It is a data structure which can return $\prod_{l \leq i < r} a_i$ under a given monoid in $\langle O(N \log N), O(1) \rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
disjoint_sparse_table<M> table(InputIterator begin, InputIterator end);
```

It takes a sequence $(a_1, a_2, \ldots, a_N)$, and constructs a data structure which can return $\prod_{l \leq i < r} a_i$ under a given monoid $M$.

### Constraints
- For all $a$ in `typename M::T`, $b$ in `typename M::T` and $c$ in `typename M::T`, `M::op(M::op(a, b), c)` $=$ `M::op(a, M::op(b, c))`.
- For all $a$ in `typename M::T`, `M::op(M::e(), a)` $=$ `M::op(a, M::e())` $=$ `a`.

### Time Complexity
- $O(N \log N)$

## size
```cpp
std::size_t table.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## prod
```cpp
typename M::T table.prod(std::size_t l, std::size_t r);
```

It returns $\prod_{l \leq i < r} a_i$ under the monoid $M$.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(1)$
