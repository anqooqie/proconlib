---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/chromatic_number.hpp
    title: Chromatic number
  - icon: ':question:'
    path: tools/dynamic_bitset.hpp
    title: std::bitset with dynamic size
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/chromatic_number.test.cpp
    title: tests/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/countr_zero.test.cpp
    title: tests/countr_zero.test.cpp
  - icon: ':x:'
    path: tests/rotate_left.test.cpp
    title: tests/rotate_left.test.cpp
  - icon: ':x:'
    path: tests/rotate_right.test.cpp
    title: tests/rotate_right.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/edges_to_scc.test.cpp
    title: tests/scc_graph/edges_to_scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6
  bundledCode: "#line 1 \"tools/countr_zero.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <type_traits>\n#include <cassert>\n#include <algorithm>\n\
    #include <limits>\n\n// Source: https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6\n\
    // License: unknown\n// Author: \u767D\u5C71 \u98A8\u9732\n\nnamespace tools {\n\
    \  namespace detail {\n    namespace countr_zero {\n      template <::std::size_t\
    \ N>\n      struct ntz_traits;\n\n      template <>\n      struct ntz_traits<1>\
    \ {\n        using type = bool;\n        static constexpr int shift = 0;\n   \
    \     static constexpr type magic = true;\n        static constexpr int ntz_table[2]\
    \ = {\n          1,  0\n        };\n      };\n\n      template <>\n      struct\
    \ ntz_traits<8> {\n        using type = ::std::uint8_t;\n        static constexpr\
    \ int shift = 4;\n        static constexpr type magic = UINT8_C(0x1D);\n     \
    \   static constexpr int ntz_table[15] = {\n          8,  0, -1,  1,  6, -1, -1,\
    \  2,  7, -1,  5, -1, -1,  4,  3\n        };\n      };\n\n      template <>\n\
    \      struct ntz_traits<16> {\n        using type = ::std::uint16_t;\n      \
    \  static constexpr int shift = 11;\n        static constexpr type magic = UINT16_C(0x0F2D);\n\
    \        static constexpr int ntz_table[31] = {\n          16,  0, -1,  1, -1,\
    \  8, -1,  2, 14, -1, -1,  9, -1, 11, -1,  3,\n          15, -1,  7, -1, 13, -1,\
    \ 10, -1, -1,  6, 12, -1,  5, -1,  4,\n        };\n      };\n\n      template\
    \ <>\n      struct ntz_traits<32> {\n        using type = ::std::uint32_t;\n \
    \       static constexpr int shift = 26;\n        static constexpr type magic\
    \ = UINT32_C(0x07C56E99);\n        static constexpr int ntz_table[63] = {\n  \
    \        32,  0, -1,  1, -1, 10, -1,  2, 29, -1, 11, -1, 25, -1, -1,  3,\n   \
    \       30, -1, -1, 23, -1, 12, 14, -1, -1, 26, -1, 16, -1, 19, -1,  4,\n    \
    \      31, -1,  9, -1, 28, -1, 24, -1, -1, 22, -1, 13, -1, 15, 18, -1,\n     \
    \     -1,  8, 27, -1, 21, -1, -1, 17,  7, -1, 20, -1,  6, -1,  5\n        };\n\
    \      };\n\n      template <>\n      struct ntz_traits<64> {\n        using type\
    \ = ::std::uint64_t;\n        static constexpr int shift = 57;\n        static\
    \ constexpr type magic = UINT64_C(0x03F0A933ADCBD8D1);\n        static constexpr\
    \ int ntz_table[127] = {\n          64,  0, -1,  1, -1, 12, -1,  2, 60, -1, 13,\
    \ -1, -1, 53, -1,  3,\n          61, -1, -1, 21, -1, 14, -1, 42, -1, 24, 54, -1,\
    \ -1, 28, -1,  4,\n          62, -1, 58, -1, 19, -1, 22, -1, -1, 17, 15, -1, -1,\
    \ 33, -1, 43,\n          -1, 50, -1, 25, 55, -1, -1, 35, -1, 38, 29, -1, -1, 45,\
    \ -1,  5,\n          63, -1, 11, -1, 59, -1, 52, -1, -1, 20, -1, 41, 23, -1, 27,\
    \ -1,\n          -1, 57, 18, -1, 16, -1, 32, -1, 49, -1, -1, 34, 37, -1, 44, -1,\n\
    \          -1, 10, -1, 51, -1, 40, -1, 26, 56, -1, -1, 31, 48, -1, 36, -1,\n \
    \         9, -1, 39, -1, -1, 30, 47, -1,  8, -1, -1, 46,  7, -1,  6,\n       \
    \ };\n      };\n    }\n  }\n\n  template <typename T>\n  constexpr int countr_zero(const\
    \ T x) noexcept {\n    static_assert(::std::is_integral_v<T>);\n    if constexpr\
    \ (::std::is_signed_v<T>) {\n      assert(x >= 0);\n      return ::std::min(::tools::countr_zero<::std::make_unsigned_t<T>>(x),\
    \ ::std::numeric_limits<T>::digits);\n    } else {\n      using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;\n\
    \      using type = typename tr::type;\n      return tr::ntz_table[static_cast<type>(tr::magic\
    \ * static_cast<type>(x & -x)) >> tr::shift];\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_COUNTR_ZERO_HPP\n#define TOOLS_COUNTR_ZERO_HPP\n\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <type_traits>\n#include <cassert>\n\
    #include <algorithm>\n#include <limits>\n\n// Source: https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6\n\
    // License: unknown\n// Author: \u767D\u5C71 \u98A8\u9732\n\nnamespace tools {\n\
    \  namespace detail {\n    namespace countr_zero {\n      template <::std::size_t\
    \ N>\n      struct ntz_traits;\n\n      template <>\n      struct ntz_traits<1>\
    \ {\n        using type = bool;\n        static constexpr int shift = 0;\n   \
    \     static constexpr type magic = true;\n        static constexpr int ntz_table[2]\
    \ = {\n          1,  0\n        };\n      };\n\n      template <>\n      struct\
    \ ntz_traits<8> {\n        using type = ::std::uint8_t;\n        static constexpr\
    \ int shift = 4;\n        static constexpr type magic = UINT8_C(0x1D);\n     \
    \   static constexpr int ntz_table[15] = {\n          8,  0, -1,  1,  6, -1, -1,\
    \  2,  7, -1,  5, -1, -1,  4,  3\n        };\n      };\n\n      template <>\n\
    \      struct ntz_traits<16> {\n        using type = ::std::uint16_t;\n      \
    \  static constexpr int shift = 11;\n        static constexpr type magic = UINT16_C(0x0F2D);\n\
    \        static constexpr int ntz_table[31] = {\n          16,  0, -1,  1, -1,\
    \  8, -1,  2, 14, -1, -1,  9, -1, 11, -1,  3,\n          15, -1,  7, -1, 13, -1,\
    \ 10, -1, -1,  6, 12, -1,  5, -1,  4,\n        };\n      };\n\n      template\
    \ <>\n      struct ntz_traits<32> {\n        using type = ::std::uint32_t;\n \
    \       static constexpr int shift = 26;\n        static constexpr type magic\
    \ = UINT32_C(0x07C56E99);\n        static constexpr int ntz_table[63] = {\n  \
    \        32,  0, -1,  1, -1, 10, -1,  2, 29, -1, 11, -1, 25, -1, -1,  3,\n   \
    \       30, -1, -1, 23, -1, 12, 14, -1, -1, 26, -1, 16, -1, 19, -1,  4,\n    \
    \      31, -1,  9, -1, 28, -1, 24, -1, -1, 22, -1, 13, -1, 15, 18, -1,\n     \
    \     -1,  8, 27, -1, 21, -1, -1, 17,  7, -1, 20, -1,  6, -1,  5\n        };\n\
    \      };\n\n      template <>\n      struct ntz_traits<64> {\n        using type\
    \ = ::std::uint64_t;\n        static constexpr int shift = 57;\n        static\
    \ constexpr type magic = UINT64_C(0x03F0A933ADCBD8D1);\n        static constexpr\
    \ int ntz_table[127] = {\n          64,  0, -1,  1, -1, 12, -1,  2, 60, -1, 13,\
    \ -1, -1, 53, -1,  3,\n          61, -1, -1, 21, -1, 14, -1, 42, -1, 24, 54, -1,\
    \ -1, 28, -1,  4,\n          62, -1, 58, -1, 19, -1, 22, -1, -1, 17, 15, -1, -1,\
    \ 33, -1, 43,\n          -1, 50, -1, 25, 55, -1, -1, 35, -1, 38, 29, -1, -1, 45,\
    \ -1,  5,\n          63, -1, 11, -1, 59, -1, 52, -1, -1, 20, -1, 41, 23, -1, 27,\
    \ -1,\n          -1, 57, 18, -1, 16, -1, 32, -1, 49, -1, -1, 34, 37, -1, 44, -1,\n\
    \          -1, 10, -1, 51, -1, 40, -1, 26, 56, -1, -1, 31, 48, -1, 36, -1,\n \
    \         9, -1, 39, -1, -1, 30, 47, -1,  8, -1, -1, 46,  7, -1,  6,\n       \
    \ };\n      };\n    }\n  }\n\n  template <typename T>\n  constexpr int countr_zero(const\
    \ T x) noexcept {\n    static_assert(::std::is_integral_v<T>);\n    if constexpr\
    \ (::std::is_signed_v<T>) {\n      assert(x >= 0);\n      return ::std::min(::tools::countr_zero<::std::make_unsigned_t<T>>(x),\
    \ ::std::numeric_limits<T>::digits);\n    } else {\n      using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;\n\
    \      using type = typename tr::type;\n      return tr::ntz_table[static_cast<type>(tr::magic\
    \ * static_cast<type>(x & -x)) >> tr::shift];\n    }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/countr_zero.hpp
  requiredBy:
  - tools/chromatic_number.hpp
  - tools/dynamic_bitset.hpp
  timestamp: '2024-02-17 19:44:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/countr_zero.test.cpp
  - tests/chromatic_number.test.cpp
  - tests/rotate_right.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
  - tests/rotate_left.test.cpp
documentation_of: tools/countr_zero.hpp
layout: document
title: Number of trailing zeros
---

```cpp
template <typename T>
constexpr int countr_zero(T x) noexcept;
```

It returns the number of trailing zeros. (e.g., `countr_zero(0b10100)` is $2$)
If $x$ is $0$, it returns `std::numeric_limits<T>::digits`.

### Constraints
- `<T>` is an integral type.
- If `<T>` is signed, `std::numeric_limits<T>::digits` is $7$, $15$, $31$ or $63$.
- If `<T>` is unsigned, `std::numeric_limits<T>::digits` is $1$, $8$, $16$, $32$ or $64$.
- $x \geq 0$

### Time Complexity
- $O(1)$

### References
- [C++11で実装するNTZとNLZ](https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6)

### License
- unknown

### Author
- 白山 風露
