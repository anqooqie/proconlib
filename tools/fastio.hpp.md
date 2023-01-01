---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/fastio.test.cpp
    title: tests/fastio.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/misc/fastio.hpp.html
  bundledCode: "#line 1 \"tools/fastio.hpp\"\n\n\n\n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\n#include <cstring>\n#include\
    \ <cstdio>\n#include <type_traits>\n#include <cstdint>\n#include <string>\n#include\
    \ <utility>\n#include <cstdlib>\n\nnamespace fastio {\n  static constexpr int\
    \ SZ = 1 << 17;\n  char inbuf[SZ], outbuf[SZ];\n  int in_left = 0, in_right =\
    \ 0, out_right = 0;\n\n  struct Pre {\n    char num[40000];\n    constexpr Pre()\
    \ : num() {\n      for (int i = 0; i < 10000; i++) {\n        int n = i;\n   \
    \     for (int j = 3; j >= 0; j--) {\n          num[i * 4 + j] = n % 10 + '0';\n\
    \          n /= 10;\n        }\n      }\n    }\n  } constexpr pre;\n\n  inline\
    \ void load() {\n    int len = in_right - in_left;\n    ::std::memmove(inbuf,\
    \ inbuf + in_left, len);\n    in_right = len + ::std::fread(inbuf + len, 1, SZ\
    \ - len, stdin);\n    in_left = 0;\n  }\n\n  inline void flush() {\n    ::std::fwrite(outbuf,\
    \ 1, out_right, stdout);\n    out_right = 0;\n  }\n\n  inline void skip_space()\
    \ {\n    if (in_left + 32 > in_right) load();\n    while (inbuf[in_left] <= '\
    \ ') in_left++;\n  }\n\n  inline void rd(char& c) {\n    if (in_left + 32 > in_right)\
    \ load();\n    c = inbuf[in_left++];\n  }\n  template <typename T>\n  inline void\
    \ rd(T& x) {\n    if (in_left + 32 > in_right) load();\n    char c;\n    do c\
    \ = inbuf[in_left++];\n    while (c < '-');\n    [[maybe_unused]] bool minus =\
    \ false;\n    if constexpr (::std::is_signed<T>::value == true) {\n      if (c\
    \ == '-') minus = true, c = inbuf[in_left++];\n    }\n    x = 0;\n    while (c\
    \ >= '0') {\n      x = x * 10 + (c & 15);\n      c = inbuf[in_left++];\n    }\n\
    \    if constexpr (::std::is_signed<T>::value == true) {\n      if (minus) x =\
    \ -x;\n    }\n  }\n  inline void rd() {}\n  template <typename Head, typename...\
    \ Tail>\n  inline void rd(Head& head, Tail&... tail) {\n    rd(head);\n    rd(tail...);\n\
    \  }\n\n  inline void wt(char c) {\n    if (out_right > SZ - 32) flush();\n  \
    \  outbuf[out_right++] = c;\n  }\n  inline void wt(bool b) {\n    if (out_right\
    \ > SZ - 32) flush();\n    outbuf[out_right++] = b ? '1' : '0';\n  }\n  inline\
    \ void wt(const ::std::string &s) {\n    if (out_right + s.size() > SZ - 32) flush();\n\
    \    ::std::memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\n \
    \   out_right += s.size();\n  }\n  template <typename T>\n  inline void wt(T x)\
    \ {\n    if (out_right > SZ - 32) flush();\n    if (!x) {\n      outbuf[out_right++]\
    \ = '0';\n      return;\n    }\n    if constexpr (::std::is_signed<T>::value ==\
    \ true) {\n      if (x < 0) outbuf[out_right++] = '-', x = -x;\n    }\n    int\
    \ i = 12;\n    char buf[16];\n    while (x >= 10000) {\n      ::std::memcpy(buf\
    \ + i, pre.num + (x % 10000) * 4, 4);\n      x /= 10000;\n      i -= 4;\n    }\n\
    \    if (x < 100) {\n      if (x < 10) {\n        outbuf[out_right] = '0' + x;\n\
    \        ++out_right;\n      } else {\n        ::std::uint32_t q = (::std::uint32_t(x)\
    \ * 205) >> 11;\n        ::std::uint32_t r = ::std::uint32_t(x) - q * 10;\n  \
    \      outbuf[out_right] = '0' + q;\n        outbuf[out_right + 1] = '0' + r;\n\
    \        out_right += 2;\n      }\n    } else {\n      if (x < 1000) {\n     \
    \   ::std::memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);\n        out_right\
    \ += 3;\n      } else {\n        ::std::memcpy(outbuf + out_right, pre.num + (x\
    \ << 2), 4);\n        out_right += 4;\n      }\n    }\n    ::std::memcpy(outbuf\
    \ + out_right, buf + i + 4, 12 - i);\n    out_right += 12 - i;\n  }\n  inline\
    \ void wt() {}\n  template <typename Head, typename... Tail>\n  inline void wt(Head&&\
    \ head, Tail&&... tail) {\n    wt(head);\n    wt(::std::forward<Tail>(tail)...);\n\
    \  }\n  template <typename... Args>\n  inline void wtn(Args&&... x) {\n    wt(::std::forward<Args>(x)...);\n\
    \    wt('\\n');\n  }\n\n  struct Dummy {\n    Dummy() { ::std::atexit(flush);\
    \ }\n  } dummy;\n}\n\n\n"
  code: "#ifndef TOOLS_FASTIO_HPP\n#define TOOLS_FASTIO_HPP\n\n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\n#include <cstring>\n#include\
    \ <cstdio>\n#include <type_traits>\n#include <cstdint>\n#include <string>\n#include\
    \ <utility>\n#include <cstdlib>\n\nnamespace fastio {\n  static constexpr int\
    \ SZ = 1 << 17;\n  char inbuf[SZ], outbuf[SZ];\n  int in_left = 0, in_right =\
    \ 0, out_right = 0;\n\n  struct Pre {\n    char num[40000];\n    constexpr Pre()\
    \ : num() {\n      for (int i = 0; i < 10000; i++) {\n        int n = i;\n   \
    \     for (int j = 3; j >= 0; j--) {\n          num[i * 4 + j] = n % 10 + '0';\n\
    \          n /= 10;\n        }\n      }\n    }\n  } constexpr pre;\n\n  inline\
    \ void load() {\n    int len = in_right - in_left;\n    ::std::memmove(inbuf,\
    \ inbuf + in_left, len);\n    in_right = len + ::std::fread(inbuf + len, 1, SZ\
    \ - len, stdin);\n    in_left = 0;\n  }\n\n  inline void flush() {\n    ::std::fwrite(outbuf,\
    \ 1, out_right, stdout);\n    out_right = 0;\n  }\n\n  inline void skip_space()\
    \ {\n    if (in_left + 32 > in_right) load();\n    while (inbuf[in_left] <= '\
    \ ') in_left++;\n  }\n\n  inline void rd(char& c) {\n    if (in_left + 32 > in_right)\
    \ load();\n    c = inbuf[in_left++];\n  }\n  template <typename T>\n  inline void\
    \ rd(T& x) {\n    if (in_left + 32 > in_right) load();\n    char c;\n    do c\
    \ = inbuf[in_left++];\n    while (c < '-');\n    [[maybe_unused]] bool minus =\
    \ false;\n    if constexpr (::std::is_signed<T>::value == true) {\n      if (c\
    \ == '-') minus = true, c = inbuf[in_left++];\n    }\n    x = 0;\n    while (c\
    \ >= '0') {\n      x = x * 10 + (c & 15);\n      c = inbuf[in_left++];\n    }\n\
    \    if constexpr (::std::is_signed<T>::value == true) {\n      if (minus) x =\
    \ -x;\n    }\n  }\n  inline void rd() {}\n  template <typename Head, typename...\
    \ Tail>\n  inline void rd(Head& head, Tail&... tail) {\n    rd(head);\n    rd(tail...);\n\
    \  }\n\n  inline void wt(char c) {\n    if (out_right > SZ - 32) flush();\n  \
    \  outbuf[out_right++] = c;\n  }\n  inline void wt(bool b) {\n    if (out_right\
    \ > SZ - 32) flush();\n    outbuf[out_right++] = b ? '1' : '0';\n  }\n  inline\
    \ void wt(const ::std::string &s) {\n    if (out_right + s.size() > SZ - 32) flush();\n\
    \    ::std::memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\n \
    \   out_right += s.size();\n  }\n  template <typename T>\n  inline void wt(T x)\
    \ {\n    if (out_right > SZ - 32) flush();\n    if (!x) {\n      outbuf[out_right++]\
    \ = '0';\n      return;\n    }\n    if constexpr (::std::is_signed<T>::value ==\
    \ true) {\n      if (x < 0) outbuf[out_right++] = '-', x = -x;\n    }\n    int\
    \ i = 12;\n    char buf[16];\n    while (x >= 10000) {\n      ::std::memcpy(buf\
    \ + i, pre.num + (x % 10000) * 4, 4);\n      x /= 10000;\n      i -= 4;\n    }\n\
    \    if (x < 100) {\n      if (x < 10) {\n        outbuf[out_right] = '0' + x;\n\
    \        ++out_right;\n      } else {\n        ::std::uint32_t q = (::std::uint32_t(x)\
    \ * 205) >> 11;\n        ::std::uint32_t r = ::std::uint32_t(x) - q * 10;\n  \
    \      outbuf[out_right] = '0' + q;\n        outbuf[out_right + 1] = '0' + r;\n\
    \        out_right += 2;\n      }\n    } else {\n      if (x < 1000) {\n     \
    \   ::std::memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);\n        out_right\
    \ += 3;\n      } else {\n        ::std::memcpy(outbuf + out_right, pre.num + (x\
    \ << 2), 4);\n        out_right += 4;\n      }\n    }\n    ::std::memcpy(outbuf\
    \ + out_right, buf + i + 4, 12 - i);\n    out_right += 12 - i;\n  }\n  inline\
    \ void wt() {}\n  template <typename Head, typename... Tail>\n  inline void wt(Head&&\
    \ head, Tail&&... tail) {\n    wt(head);\n    wt(::std::forward<Tail>(tail)...);\n\
    \  }\n  template <typename... Args>\n  inline void wtn(Args&&... x) {\n    wt(::std::forward<Args>(x)...);\n\
    \    wt('\\n');\n  }\n\n  struct Dummy {\n    Dummy() { ::std::atexit(flush);\
    \ }\n  } dummy;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/fastio.hpp
  requiredBy: []
  timestamp: '2023-01-02 00:43:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/fastio.test.cpp
documentation_of: tools/fastio.hpp
layout: document
redirect_from:
- /library/tools/fastio.hpp
- /library/tools/fastio.hpp.html
title: tools/fastio.hpp
---
