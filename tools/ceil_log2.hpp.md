---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/binary_heap.hpp
    title: Binary heap
  - icon: ':heavy_check_mark:'
    path: tools/dual_segtree.hpp
    title: Dual segment tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/binary_heap.test.cpp
    title: tests/binary_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dual_segtree.test.cpp
    title: tests/dual_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/ceil_log2.hpp\"\n\n\n\n#include <cstdint>\n\nnamespace\
    \ tools {\n\n  inline std::uint32_t ceil_log2(std::uint32_t x) {\n    static const\
    \ ::std::uint32_t t[6] = {\n      0xFFFF0000u,\n      0x0000FF00u,\n      0x000000F0u,\n\
    \      0x0000000Cu,\n      0x00000002u\n    };\n\n    ::std::uint32_t y = (((x\
    \ & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint32_t j = 16;\n\n    for (const ::std::uint32_t&\
    \ t_i : t) {\n      ::std::uint32_t k = (((x & t_i) == 0) ? 0 : j);\n      y +=\
    \ k;\n      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  inline\
    \ ::std::uint64_t ceil_log2(::std::uint64_t x) {\n    static const ::std::uint64_t\
    \ t[6] = {\n      0xFFFFFFFF00000000u,\n      0x00000000FFFF0000u,\n      0x000000000000FF00u,\n\
    \      0x00000000000000F0u,\n      0x000000000000000Cu,\n      0x0000000000000002u\n\
    \    };\n\n    ::std::uint64_t y = (((x & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint64_t\
    \ j = 32;\n\n    for (const ::std::uint64_t& t_i : t) {\n      ::std::uint64_t\
    \ k = (((x & t_i) == 0) ? 0 : j);\n      y += k;\n      x >>= k;\n      j >>=\
    \ 1;\n    }\n\n    return y;\n  }\n\n  inline ::std::int32_t ceil_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t ceil_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_CEIL_LOG2_HPP\n#define TOOLS_CEIL_LOG2_HPP\n\n#include <cstdint>\n\
    \nnamespace tools {\n\n  inline std::uint32_t ceil_log2(std::uint32_t x) {\n \
    \   static const ::std::uint32_t t[6] = {\n      0xFFFF0000u,\n      0x0000FF00u,\n\
    \      0x000000F0u,\n      0x0000000Cu,\n      0x00000002u\n    };\n\n    ::std::uint32_t\
    \ y = (((x & (x - 1)) == 0) ? 0 : 1);\n    ::std::uint32_t j = 16;\n\n    for\
    \ (const ::std::uint32_t& t_i : t) {\n      ::std::uint32_t k = (((x & t_i) ==\
    \ 0) ? 0 : j);\n      y += k;\n      x >>= k;\n      j >>= 1;\n    }\n\n    return\
    \ y;\n  }\n\n  inline ::std::uint64_t ceil_log2(::std::uint64_t x) {\n    static\
    \ const ::std::uint64_t t[6] = {\n      0xFFFFFFFF00000000u,\n      0x00000000FFFF0000u,\n\
    \      0x000000000000FF00u,\n      0x00000000000000F0u,\n      0x000000000000000Cu,\n\
    \      0x0000000000000002u\n    };\n\n    ::std::uint64_t y = (((x & (x - 1))\
    \ == 0) ? 0 : 1);\n    ::std::uint64_t j = 32;\n\n    for (const ::std::uint64_t&\
    \ t_i : t) {\n      ::std::uint64_t k = (((x & t_i) == 0) ? 0 : j);\n      y +=\
    \ k;\n      x >>= k;\n      j >>= 1;\n    }\n\n    return y;\n  }\n\n  inline\
    \ ::std::int32_t ceil_log2(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::ceil_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t ceil_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ceil_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/ceil_log2.hpp
  requiredBy:
  - tools/dual_segtree.hpp
  - tools/binary_heap.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/binary_heap.test.cpp
  - tests/dual_segtree.test.cpp
documentation_of: tools/ceil_log2.hpp
layout: document
title: $\left\lceil \log_2(x) \right\rceil$
---

```cpp
std::int32_t ceil_log2(std::int32_t x);
std::uint32_t ceil_log2(std::uint32_t x);
std::int64_t ceil_log2(std::int64_t x);
std::uint64_t ceil_log2(std::uint64_t x);
```

It returns $\left\lceil \log_2(x) \right\rceil$.

## References
- [Stack Overflow](https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567)

## License
- CC BY-SA 3.0

## Author
- [dgobbi](https://stackoverflow.com/users/2154690/dgobbi)
