---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/countr_zero.hpp
    title: Number of trailing zeros
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/countr_zero.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <cstdint>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that_impl(cond,\
    \ file, line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' <<\
    \ line << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\\
    n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/countr_zero.hpp\"\n\n\n\n#include <cstddef>\n#line 6 \"tools/countr_zero.hpp\"\
    \n#include <type_traits>\n#include <cassert>\n#include <algorithm>\n#include <limits>\n\
    \n// Source: https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6\n// License:\
    \ unknown\n// Author: \u767D\u5C71 \u98A8\u9732\n\nnamespace tools {\n  namespace\
    \ detail {\n    namespace countr_zero {\n      template <::std::size_t N>\n  \
    \    struct ntz_traits;\n\n      template <>\n      struct ntz_traits<1> {\n \
    \       using type = bool;\n        static constexpr int shift = 0;\n        static\
    \ constexpr type magic = true;\n        static constexpr int ntz_table[2] = {\n\
    \          1,  0\n        };\n      };\n\n      template <>\n      struct ntz_traits<8>\
    \ {\n        using type = ::std::uint8_t;\n        static constexpr int shift\
    \ = 4;\n        static constexpr type magic = UINT8_C(0x1D);\n        static constexpr\
    \ int ntz_table[15] = {\n          8,  0, -1,  1,  6, -1, -1,  2,  7, -1,  5,\
    \ -1, -1,  4,  3\n        };\n      };\n\n      template <>\n      struct ntz_traits<16>\
    \ {\n        using type = ::std::uint16_t;\n        static constexpr int shift\
    \ = 11;\n        static constexpr type magic = UINT16_C(0x0F2D);\n        static\
    \ constexpr int ntz_table[31] = {\n          16,  0, -1,  1, -1,  8, -1,  2, 14,\
    \ -1, -1,  9, -1, 11, -1,  3,\n          15, -1,  7, -1, 13, -1, 10, -1, -1, \
    \ 6, 12, -1,  5, -1,  4,\n        };\n      };\n\n      template <>\n      struct\
    \ ntz_traits<32> {\n        using type = ::std::uint32_t;\n        static constexpr\
    \ int shift = 26;\n        static constexpr type magic = UINT32_C(0x07C56E99);\n\
    \        static constexpr int ntz_table[63] = {\n          32,  0, -1,  1, -1,\
    \ 10, -1,  2, 29, -1, 11, -1, 25, -1, -1,  3,\n          30, -1, -1, 23, -1, 12,\
    \ 14, -1, -1, 26, -1, 16, -1, 19, -1,  4,\n          31, -1,  9, -1, 28, -1, 24,\
    \ -1, -1, 22, -1, 13, -1, 15, 18, -1,\n          -1,  8, 27, -1, 21, -1, -1, 17,\
    \  7, -1, 20, -1,  6, -1,  5\n        };\n      };\n\n      template <>\n    \
    \  struct ntz_traits<64> {\n        using type = ::std::uint64_t;\n        static\
    \ constexpr int shift = 57;\n        static constexpr type magic = UINT64_C(0x03F0A933ADCBD8D1);\n\
    \        static constexpr int ntz_table[127] = {\n          64,  0, -1,  1, -1,\
    \ 12, -1,  2, 60, -1, 13, -1, -1, 53, -1,  3,\n          61, -1, -1, 21, -1, 14,\
    \ -1, 42, -1, 24, 54, -1, -1, 28, -1,  4,\n          62, -1, 58, -1, 19, -1, 22,\
    \ -1, -1, 17, 15, -1, -1, 33, -1, 43,\n          -1, 50, -1, 25, 55, -1, -1, 35,\
    \ -1, 38, 29, -1, -1, 45, -1,  5,\n          63, -1, 11, -1, 59, -1, 52, -1, -1,\
    \ 20, -1, 41, 23, -1, 27, -1,\n          -1, 57, 18, -1, 16, -1, 32, -1, 49, -1,\
    \ -1, 34, 37, -1, 44, -1,\n          -1, 10, -1, 51, -1, 40, -1, 26, 56, -1, -1,\
    \ 31, 48, -1, 36, -1,\n          9, -1, 39, -1, -1, 30, 47, -1,  8, -1, -1, 46,\
    \  7, -1,  6,\n        };\n      };\n    }\n  }\n\n  template <typename T>\n \
    \ constexpr int countr_zero(const T x) noexcept {\n    static_assert(::std::is_integral_v<T>);\n\
    \    if constexpr (::std::is_signed_v<T>) {\n      assert(x >= 0);\n      return\
    \ ::std::min(::tools::countr_zero<::std::make_unsigned_t<T>>(x), ::std::numeric_limits<T>::digits);\n\
    \    } else {\n      using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;\n\
    \      using type = typename tr::type;\n      return tr::ntz_table[static_cast<type>(tr::magic\
    \ * static_cast<type>(x & -x)) >> tr::shift];\n    }\n  }\n}\n\n\n#line 7 \"tests/countr_zero.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::countr_zero(false) == 1);\n  assert_that(tools::countr_zero(true)\
    \ == 0);\n\n  assert_that(tools::countr_zero(INT32_C(0)) == 31);\n  assert_that(tools::countr_zero(INT32_C(1))\
    \ == 0);\n  assert_that(tools::countr_zero(INT32_C(2)) == 1);\n  assert_that(tools::countr_zero(INT32_C(3))\
    \ == 0);\n  assert_that(tools::countr_zero(INT32_C(4)) == 2);\n  assert_that(tools::countr_zero(INT32_C(5))\
    \ == 0);\n  assert_that(tools::countr_zero(INT32_C(6)) == 1);\n  assert_that(tools::countr_zero(INT32_C(7))\
    \ == 0);\n  assert_that(tools::countr_zero(INT32_C(8)) == 3);\n  assert_that(tools::countr_zero(INT32_C(9))\
    \ == 0);\n  assert_that(tools::countr_zero(INT32_C(1073741823)) == 0);\n  assert_that(tools::countr_zero(INT32_C(1073741824))\
    \ == 30);\n  assert_that(tools::countr_zero(INT32_C(1073741825)) == 0);\n  assert_that(tools::countr_zero(INT32_C(2147483646))\
    \ == 1);\n  assert_that(tools::countr_zero(INT32_C(2147483647)) == 0);\n\n  assert_that(tools::countr_zero(UINT32_C(0))\
    \ == 32);\n  assert_that(tools::countr_zero(UINT32_C(1)) == 0);\n  assert_that(tools::countr_zero(UINT32_C(2))\
    \ == 1);\n  assert_that(tools::countr_zero(UINT32_C(3)) == 0);\n  assert_that(tools::countr_zero(UINT32_C(4))\
    \ == 2);\n  assert_that(tools::countr_zero(UINT32_C(5)) == 0);\n  assert_that(tools::countr_zero(UINT32_C(6))\
    \ == 1);\n  assert_that(tools::countr_zero(UINT32_C(7)) == 0);\n  assert_that(tools::countr_zero(UINT32_C(8))\
    \ == 3);\n  assert_that(tools::countr_zero(UINT32_C(9)) == 0);\n  assert_that(tools::countr_zero(UINT32_C(2147483647))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT32_C(2147483648)) == 31);\n  assert_that(tools::countr_zero(UINT32_C(2147483649))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT32_C(4294967294)) == 1);\n  assert_that(tools::countr_zero(UINT32_C(4294967295))\
    \ == 0);\n\n  assert_that(tools::countr_zero(INT64_C(0)) == 63);\n  assert_that(tools::countr_zero(INT64_C(1))\
    \ == 0);\n  assert_that(tools::countr_zero(INT64_C(2)) == 1);\n  assert_that(tools::countr_zero(INT64_C(3))\
    \ == 0);\n  assert_that(tools::countr_zero(INT64_C(4)) == 2);\n  assert_that(tools::countr_zero(INT64_C(5))\
    \ == 0);\n  assert_that(tools::countr_zero(INT64_C(6)) == 1);\n  assert_that(tools::countr_zero(INT64_C(7))\
    \ == 0);\n  assert_that(tools::countr_zero(INT64_C(8)) == 3);\n  assert_that(tools::countr_zero(INT64_C(9))\
    \ == 0);\n  assert_that(tools::countr_zero(INT64_C(4611686018427387903)) == 0);\n\
    \  assert_that(tools::countr_zero(INT64_C(4611686018427387904)) == 62);\n  assert_that(tools::countr_zero(INT64_C(4611686018427387905))\
    \ == 0);\n  assert_that(tools::countr_zero(INT64_C(9223372036854775806)) == 1);\n\
    \  assert_that(tools::countr_zero(INT64_C(9223372036854775807)) == 0);\n\n  assert_that(tools::countr_zero(UINT64_C(0))\
    \ == 64);\n  assert_that(tools::countr_zero(UINT64_C(1)) == 0);\n  assert_that(tools::countr_zero(UINT64_C(2))\
    \ == 1);\n  assert_that(tools::countr_zero(UINT64_C(3)) == 0);\n  assert_that(tools::countr_zero(UINT64_C(4))\
    \ == 2);\n  assert_that(tools::countr_zero(UINT64_C(5)) == 0);\n  assert_that(tools::countr_zero(UINT64_C(6))\
    \ == 1);\n  assert_that(tools::countr_zero(UINT64_C(7)) == 0);\n  assert_that(tools::countr_zero(UINT64_C(8))\
    \ == 3);\n  assert_that(tools::countr_zero(UINT64_C(9)) == 0);\n  assert_that(tools::countr_zero(UINT64_C(9223372036854775807))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT64_C(9223372036854775808)) == 63);\n\
    \  assert_that(tools::countr_zero(UINT64_C(9223372036854775809)) == 0);\n  assert_that(tools::countr_zero(UINT64_C(18446744073709551614))\
    \ == 1);\n  assert_that(tools::countr_zero(UINT64_C(18446744073709551615)) ==\
    \ 0);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <cstdint>\n#include \"tools/assert_that.hpp\"\n\
    #include \"tools/countr_zero.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::countr_zero(false)\
    \ == 1);\n  assert_that(tools::countr_zero(true) == 0);\n\n  assert_that(tools::countr_zero(INT32_C(0))\
    \ == 31);\n  assert_that(tools::countr_zero(INT32_C(1)) == 0);\n  assert_that(tools::countr_zero(INT32_C(2))\
    \ == 1);\n  assert_that(tools::countr_zero(INT32_C(3)) == 0);\n  assert_that(tools::countr_zero(INT32_C(4))\
    \ == 2);\n  assert_that(tools::countr_zero(INT32_C(5)) == 0);\n  assert_that(tools::countr_zero(INT32_C(6))\
    \ == 1);\n  assert_that(tools::countr_zero(INT32_C(7)) == 0);\n  assert_that(tools::countr_zero(INT32_C(8))\
    \ == 3);\n  assert_that(tools::countr_zero(INT32_C(9)) == 0);\n  assert_that(tools::countr_zero(INT32_C(1073741823))\
    \ == 0);\n  assert_that(tools::countr_zero(INT32_C(1073741824)) == 30);\n  assert_that(tools::countr_zero(INT32_C(1073741825))\
    \ == 0);\n  assert_that(tools::countr_zero(INT32_C(2147483646)) == 1);\n  assert_that(tools::countr_zero(INT32_C(2147483647))\
    \ == 0);\n\n  assert_that(tools::countr_zero(UINT32_C(0)) == 32);\n  assert_that(tools::countr_zero(UINT32_C(1))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT32_C(2)) == 1);\n  assert_that(tools::countr_zero(UINT32_C(3))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT32_C(4)) == 2);\n  assert_that(tools::countr_zero(UINT32_C(5))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT32_C(6)) == 1);\n  assert_that(tools::countr_zero(UINT32_C(7))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT32_C(8)) == 3);\n  assert_that(tools::countr_zero(UINT32_C(9))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT32_C(2147483647)) == 0);\n  assert_that(tools::countr_zero(UINT32_C(2147483648))\
    \ == 31);\n  assert_that(tools::countr_zero(UINT32_C(2147483649)) == 0);\n  assert_that(tools::countr_zero(UINT32_C(4294967294))\
    \ == 1);\n  assert_that(tools::countr_zero(UINT32_C(4294967295)) == 0);\n\n  assert_that(tools::countr_zero(INT64_C(0))\
    \ == 63);\n  assert_that(tools::countr_zero(INT64_C(1)) == 0);\n  assert_that(tools::countr_zero(INT64_C(2))\
    \ == 1);\n  assert_that(tools::countr_zero(INT64_C(3)) == 0);\n  assert_that(tools::countr_zero(INT64_C(4))\
    \ == 2);\n  assert_that(tools::countr_zero(INT64_C(5)) == 0);\n  assert_that(tools::countr_zero(INT64_C(6))\
    \ == 1);\n  assert_that(tools::countr_zero(INT64_C(7)) == 0);\n  assert_that(tools::countr_zero(INT64_C(8))\
    \ == 3);\n  assert_that(tools::countr_zero(INT64_C(9)) == 0);\n  assert_that(tools::countr_zero(INT64_C(4611686018427387903))\
    \ == 0);\n  assert_that(tools::countr_zero(INT64_C(4611686018427387904)) == 62);\n\
    \  assert_that(tools::countr_zero(INT64_C(4611686018427387905)) == 0);\n  assert_that(tools::countr_zero(INT64_C(9223372036854775806))\
    \ == 1);\n  assert_that(tools::countr_zero(INT64_C(9223372036854775807)) == 0);\n\
    \n  assert_that(tools::countr_zero(UINT64_C(0)) == 64);\n  assert_that(tools::countr_zero(UINT64_C(1))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT64_C(2)) == 1);\n  assert_that(tools::countr_zero(UINT64_C(3))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT64_C(4)) == 2);\n  assert_that(tools::countr_zero(UINT64_C(5))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT64_C(6)) == 1);\n  assert_that(tools::countr_zero(UINT64_C(7))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT64_C(8)) == 3);\n  assert_that(tools::countr_zero(UINT64_C(9))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT64_C(9223372036854775807)) == 0);\n\
    \  assert_that(tools::countr_zero(UINT64_C(9223372036854775808)) == 63);\n  assert_that(tools::countr_zero(UINT64_C(9223372036854775809))\
    \ == 0);\n  assert_that(tools::countr_zero(UINT64_C(18446744073709551614)) ==\
    \ 1);\n  assert_that(tools::countr_zero(UINT64_C(18446744073709551615)) == 0);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/countr_zero.hpp
  isVerificationFile: true
  path: tests/countr_zero.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/countr_zero.test.cpp
layout: document
redirect_from:
- /verify/tests/countr_zero.test.cpp
- /verify/tests/countr_zero.test.cpp.html
title: tests/countr_zero.test.cpp
---
