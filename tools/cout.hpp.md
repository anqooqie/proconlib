---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/fastio/integer.test.cpp
    title: tests/fastio/integer.test.cpp
  - icon: ':x:'
    path: tests/fastio/string.test.cpp
    title: tests/fastio/string.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/misc/fastio.hpp.html
  bundledCode: "#line 1 \"tools/cout.hpp\"\n\n\n\n#include <cstdio>\n#include <string>\n\
    #include <algorithm>\n#include <cstring>\n#include <type_traits>\n#include <cstdint>\n\
    #include <cstdlib>\n#include <iostream>\n#include <utility>\n\n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  namespace\
    \ detail {\n    namespace ostream {\n      static constexpr int SZ = 1 << 17;\n\
    \      char outbuf[SZ];\n      int out_right = 0;\n\n      struct Pre {\n    \
    \    char num[40000];\n        constexpr Pre() : num() {\n          for (int i\
    \ = 0; i < 10000; i++) {\n            int n = i;\n            for (int j = 3;\
    \ j >= 0; j--) {\n              num[i * 4 + j] = n % 10 + '0';\n             \
    \ n /= 10;\n            }\n          }\n        }\n      } constexpr pre;\n\n\
    \      void flush() {\n        ::std::fwrite(outbuf, 1, out_right, stdout);\n\
    \        out_right = 0;\n      }\n\n      void wt(const char c) {\n        if\
    \ (out_right > SZ - 32) flush();\n        outbuf[out_right++] = c;\n      }\n\n\
    \      void wt(const bool b) {\n        if (out_right > SZ - 32) flush();\n  \
    \      outbuf[out_right++] = b ? '1' : '0';\n      }\n\n      void wt(const ::std::string&\
    \ s) {\n        for (int l = 0, w; l < int(s.size()); l += w) {\n          w =\
    \ ::std::min(int(s.size()) - l, SZ - out_right);\n          ::std::memcpy(outbuf\
    \ + out_right, s.data() + l, w);\n          out_right += w;\n          if (out_right\
    \ == SZ) flush();\n        }\n      }\n\n      void wt(const char * const s) {\n\
    \        wt(::std::string(s));\n      }\n\n      template <typename T>\n     \
    \ void wt(T x) {\n        if (out_right > SZ - 32) flush();\n        if (!x) {\n\
    \          outbuf[out_right++] = '0';\n          return;\n        }\n        if\
    \ constexpr (::std::is_signed_v<T>) {\n          if (x < 0) {\n            outbuf[out_right++]\
    \ = '-';\n            x = -x;\n          }\n        }\n        int i = 12;\n \
    \       char buf[16];\n        while (x >= 10000) {\n          ::std::memcpy(buf\
    \ + i, pre.num + (x % 10000) * 4, 4);\n          x /= 10000;\n          i -= 4;\n\
    \        }\n        if (x < 100) {\n          if (x < 10) {\n            outbuf[out_right]\
    \ = '0' + x;\n            ++out_right;\n          } else {\n            ::std::uint32_t\
    \ q = (::std::uint32_t(x) * 205) >> 11;\n            ::std::uint32_t r = ::std::uint32_t(x)\
    \ - q * 10;\n            outbuf[out_right] = '0' + q;\n            outbuf[out_right\
    \ + 1] = '0' + r;\n            out_right += 2;\n          }\n        } else {\n\
    \          if (x < 1000) {\n            ::std::memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n            out_right += 3;\n          } else {\n     \
    \       ::std::memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n          \
    \  out_right += 4;\n          }\n        }\n        ::std::memcpy(outbuf + out_right,\
    \ buf + i + 4, 12 - i);\n        out_right += 12 - i;\n      }\n\n      static\
    \ struct Dummy {\n        Dummy() { ::std::atexit(flush); }\n      } dummy;\n\
    \    }\n  }\n\n  struct ostream {\n    template <typename... Args>\n    ::tools::ostream&\
    \ operator<<(Args&&... args) {\n      ::tools::detail::ostream::wt(::std::forward<Args>(args)...);\n\
    \      return *this;\n    }\n  };\n\n  ::tools::ostream cout;\n}\n\n\n"
  code: "#ifndef TOOLS_COUT_HPP\n#define TOOLS_COUT_HPP\n\n#include <cstdio>\n#include\
    \ <string>\n#include <algorithm>\n#include <cstring>\n#include <type_traits>\n\
    #include <cstdint>\n#include <cstdlib>\n#include <iostream>\n#include <utility>\n\
    \n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n// License:\
    \ CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  namespace detail\
    \ {\n    namespace ostream {\n      static constexpr int SZ = 1 << 17;\n     \
    \ char outbuf[SZ];\n      int out_right = 0;\n\n      struct Pre {\n        char\
    \ num[40000];\n        constexpr Pre() : num() {\n          for (int i = 0; i\
    \ < 10000; i++) {\n            int n = i;\n            for (int j = 3; j >= 0;\
    \ j--) {\n              num[i * 4 + j] = n % 10 + '0';\n              n /= 10;\n\
    \            }\n          }\n        }\n      } constexpr pre;\n\n      void flush()\
    \ {\n        ::std::fwrite(outbuf, 1, out_right, stdout);\n        out_right =\
    \ 0;\n      }\n\n      void wt(const char c) {\n        if (out_right > SZ - 32)\
    \ flush();\n        outbuf[out_right++] = c;\n      }\n\n      void wt(const bool\
    \ b) {\n        if (out_right > SZ - 32) flush();\n        outbuf[out_right++]\
    \ = b ? '1' : '0';\n      }\n\n      void wt(const ::std::string& s) {\n     \
    \   for (int l = 0, w; l < int(s.size()); l += w) {\n          w = ::std::min(int(s.size())\
    \ - l, SZ - out_right);\n          ::std::memcpy(outbuf + out_right, s.data()\
    \ + l, w);\n          out_right += w;\n          if (out_right == SZ) flush();\n\
    \        }\n      }\n\n      void wt(const char * const s) {\n        wt(::std::string(s));\n\
    \      }\n\n      template <typename T>\n      void wt(T x) {\n        if (out_right\
    \ > SZ - 32) flush();\n        if (!x) {\n          outbuf[out_right++] = '0';\n\
    \          return;\n        }\n        if constexpr (::std::is_signed_v<T>) {\n\
    \          if (x < 0) {\n            outbuf[out_right++] = '-';\n            x\
    \ = -x;\n          }\n        }\n        int i = 12;\n        char buf[16];\n\
    \        while (x >= 10000) {\n          ::std::memcpy(buf + i, pre.num + (x %\
    \ 10000) * 4, 4);\n          x /= 10000;\n          i -= 4;\n        }\n     \
    \   if (x < 100) {\n          if (x < 10) {\n            outbuf[out_right] = '0'\
    \ + x;\n            ++out_right;\n          } else {\n            ::std::uint32_t\
    \ q = (::std::uint32_t(x) * 205) >> 11;\n            ::std::uint32_t r = ::std::uint32_t(x)\
    \ - q * 10;\n            outbuf[out_right] = '0' + q;\n            outbuf[out_right\
    \ + 1] = '0' + r;\n            out_right += 2;\n          }\n        } else {\n\
    \          if (x < 1000) {\n            ::std::memcpy(outbuf + out_right, pre.num\
    \ + (x << 2) + 1, 3);\n            out_right += 3;\n          } else {\n     \
    \       ::std::memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n          \
    \  out_right += 4;\n          }\n        }\n        ::std::memcpy(outbuf + out_right,\
    \ buf + i + 4, 12 - i);\n        out_right += 12 - i;\n      }\n\n      static\
    \ struct Dummy {\n        Dummy() { ::std::atexit(flush); }\n      } dummy;\n\
    \    }\n  }\n\n  struct ostream {\n    template <typename... Args>\n    ::tools::ostream&\
    \ operator<<(Args&&... args) {\n      ::tools::detail::ostream::wt(::std::forward<Args>(args)...);\n\
    \      return *this;\n    }\n  };\n\n  ::tools::ostream cout;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cout.hpp
  requiredBy: []
  timestamp: '2023-05-02 20:12:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/fastio/string.test.cpp
  - tests/fastio/integer.test.cpp
documentation_of: tools/cout.hpp
layout: document
title: Fast output
---

It provides very restricted but fast output functions.

### Constraints
- You cannot include this header file from more than one compilation unit.

### License
- CC0 1.0 Universal

### Author
- Nyaan

## tools::cout
```cpp
tools::ostream cout;
```

It is an interface to the output functions.

## tools::ostream::operator&lt;&lt;
```cpp
(1) tools::ostream& cout.operator<<(char c);
(2) tools::ostream& cout.operator<<(bool b);
(3) tools::ostream& cout.operator<<(std::string s);
(4) tools::ostream& cout.operator<<(const char *s);
(5) template <typename T> tools::ostream& cout.operator<<(T& x);
```

- (1)
    - It writes `c` to standard output and returns `cout`.
- (2)
    - If `b` is `true`, it writes `1` to standard output and returns `cout`.
    - If `b` is `false`, it writes `0` to standard output and returns `cout`.
- (3)
    - It writes `s` to standard output and returns `cout`.
- (4)
    - It is identical to `cout << std::string(s)`.
- (5)
    - It writes `x` to standard output and returns `cout`.

### Constraints
- (1), (2), (3), (4)
    - You cannot write standard output by any other ways except for `tools::cout` in the program.
- (5)
    - You cannot write standard output by any other ways except for `tools::cout` in the program.
    - `<T>` is a built-in integral type.

### Time Complexity
- (1), (2), (5)
    - $O(1)$
- (3), (4)
    - $O(\|s\|)$
