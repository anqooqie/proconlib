---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: tools/popcount.hpp
    title: tools/popcount.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/floor_log2.hpp\"\n\n\n\n#include <cstdint>\n#line\
    \ 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\nnamespace\
    \ tools {\n\n  /**\n   * returns the number of 1 bits in the value of $x$\n  \
    \ * Reference: Henry S. Warren Jr. (2013). \"Hacker's Delight (2nd edition)\"\n\
    \   * License: CC0\n   * @author anqooqie\n   * @param x input\n   * @return the\
    \ number of 1 bits in the value of $x$\n   */\n  inline ::std::uint32_t popcount(::std::uint32_t\
    \ x) {\n    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  /**\n   * returns\
    \ the number of 1 bits in the value of $x$\n   * Reference: Henry S. Warren Jr.\
    \ (2013). \"Hacker's Delight (2nd edition)\"\n   * License: CC0\n   * @author\
    \ anqooqie\n   * @param x input\n   * @return the number of 1 bits in the value\
    \ of $x$\n   */\n  inline ::std::uint64_t popcount(::std::uint64_t x) {\n    x\
    \ = (x & static_cast<::std::uint64_t>(0x5555555555555555ull)) + (x >> static_cast<::std::uint64_t>(1)\
    \ & static_cast<::std::uint64_t>(0x5555555555555555ull));\n    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull))\
    \ + (x >> static_cast<::std::uint64_t>(2) & static_cast<::std::uint64_t>(0x3333333333333333ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full)) + (x >> static_cast<::std::uint64_t>(4)\
    \ & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull))\
    \ + (x >> static_cast<::std::uint64_t>(8) & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull)) + (x >> static_cast<::std::uint64_t>(16)\
    \ & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull))\
    \ + (x >> static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  /**\n   * returns the number of 1 bits in the value of $x$\n   * Reference:\
    \ Henry S. Warren Jr. (2013). \"Hacker's Delight (2nd edition)\"\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param x input\n   * @return the number of\
    \ 1 bits in the value of $x$\n   */\n  inline ::std::int32_t popcount(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  /**\n   * returns the number of 1 bits in the value of $x$\n   * Reference:\
    \ Henry S. Warren Jr. (2013). \"Hacker's Delight (2nd edition)\"\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param x input\n   * @return the number of\
    \ 1 bits in the value of $x$\n   */\n  inline ::std::int64_t popcount(::std::int64_t\
    \ x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 6 \"tools/floor_log2.hpp\"\n\nnamespace tools {\n\n  /**\n\
    \   * computes $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n   * License: CC0\n\
    \   * @author anqooqie\n   * @param x input\n   * @return $\\left\\lfloor \\log_2(x)\
    \ \\right\\rfloor$\n   */\n  inline ::std::uint32_t floor_log2(::std::uint32_t\
    \ x) {\n    x |= (x >> static_cast<::std::uint32_t>(1));\n    x |= (x >> static_cast<::std::uint32_t>(2));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(4));\n    x |= (x >> static_cast<::std::uint32_t>(8));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(16));\n    return ::tools::popcount(x)\
    \ - static_cast<::std::uint32_t>(1);\n  }\n\n  /**\n   * computes $\\left\\lfloor\
    \ \\log_2(x) \\right\\rfloor$\n   * License: CC0\n   * @author anqooqie\n   *\
    \ @param x input\n   * @return $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n \
    \  */\n  inline ::std::uint64_t floor_log2(::std::uint64_t x) {\n    x |= (x >>\
    \ static_cast<::std::uint64_t>(1));\n    x |= (x >> static_cast<::std::uint64_t>(2));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(4));\n    x |= (x >> static_cast<::std::uint64_t>(8));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(16));\n    x |= (x >> static_cast<::std::uint64_t>(32));\n\
    \    return ::tools::popcount(x) - static_cast<::std::uint64_t>(1);\n  }\n\n \
    \ /**\n   * computes $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param x input\n   * @return $\\left\\lfloor\
    \ \\log_2(x) \\right\\rfloor$\n   */\n  inline ::std::int32_t floor_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  /**\n   * computes $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n   *\
    \ License: CC0\n   * @author anqooqie\n   * @param x input\n   * @return $\\left\\\
    lfloor \\log_2(x) \\right\\rfloor$\n   */\n  inline ::std::int64_t floor_log2(::std::int64_t\
    \ x) {\n    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_FLOOR_LOG2_HPP\n#define TOOLS_FLOOR_LOG2_HPP\n\n#include <cstdint>\n\
    #include \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  /**\n   * computes $\\\
    left\\lfloor \\log_2(x) \\right\\rfloor$\n   * License: CC0\n   * @author anqooqie\n\
    \   * @param x input\n   * @return $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n\
    \   */\n  inline ::std::uint32_t floor_log2(::std::uint32_t x) {\n    x |= (x\
    \ >> static_cast<::std::uint32_t>(1));\n    x |= (x >> static_cast<::std::uint32_t>(2));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(4));\n    x |= (x >> static_cast<::std::uint32_t>(8));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(16));\n    return ::tools::popcount(x)\
    \ - static_cast<::std::uint32_t>(1);\n  }\n\n  /**\n   * computes $\\left\\lfloor\
    \ \\log_2(x) \\right\\rfloor$\n   * License: CC0\n   * @author anqooqie\n   *\
    \ @param x input\n   * @return $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n \
    \  */\n  inline ::std::uint64_t floor_log2(::std::uint64_t x) {\n    x |= (x >>\
    \ static_cast<::std::uint64_t>(1));\n    x |= (x >> static_cast<::std::uint64_t>(2));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(4));\n    x |= (x >> static_cast<::std::uint64_t>(8));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(16));\n    x |= (x >> static_cast<::std::uint64_t>(32));\n\
    \    return ::tools::popcount(x) - static_cast<::std::uint64_t>(1);\n  }\n\n \
    \ /**\n   * computes $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param x input\n   * @return $\\left\\lfloor\
    \ \\log_2(x) \\right\\rfloor$\n   */\n  inline ::std::int32_t floor_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  /**\n   * computes $\\left\\lfloor \\log_2(x) \\right\\rfloor$\n   *\
    \ License: CC0\n   * @author anqooqie\n   * @param x input\n   * @return $\\left\\\
    lfloor \\log_2(x) \\right\\rfloor$\n   */\n  inline ::std::int64_t floor_log2(::std::int64_t\
    \ x) {\n    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n#endif\n"
  dependsOn:
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/floor_log2.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/floor_log2.hpp
layout: document
redirect_from:
- /library/tools/floor_log2.hpp
- /library/tools/floor_log2.hpp.html
title: tools/floor_log2.hpp
---
