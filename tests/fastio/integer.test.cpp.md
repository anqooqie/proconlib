---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cin.hpp
    title: Fast input
  - icon: ':heavy_check_mark:'
    path: tools/cout.hpp
    title: Fast output
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"tests/fastio/integer.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n\n#include <iostream>\n#line 1 \"tools/cin.hpp\"\n\n\n\n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\n#include <cstring>\n#include\
    \ <cstdio>\n#include <string>\n#include <algorithm>\n#include <type_traits>\n\
    #line 14 \"tools/cin.hpp\"\n#include <utility>\n\nnamespace tools {\n  namespace\
    \ detail {\n    namespace istream {\n      static constexpr int SZ = 1 << 17;\n\
    \      char inbuf[SZ];\n      int in_left = 0;\n      int in_right = 0;\n\n  \
    \    void load() {\n        const int len = in_right - in_left;\n        ::std::memmove(inbuf,\
    \ inbuf + in_left, len);\n        in_right = len + ::std::fread(inbuf + len, 1,\
    \ SZ - len, stdin);\n        in_left = 0;\n      }\n\n      void skip_space()\
    \ {\n        if (in_left + 32 > in_right) load();\n        while (inbuf[in_left]\
    \ <= ' ') in_left++;\n      }\n\n      void rd(char& c) {\n        if (in_left\
    \ + 32 > in_right) load();\n        c = inbuf[in_left++];\n      }\n\n      void\
    \ rd(::std::string& s) {\n        for (; (in_left < in_right || (load(), in_left\
    \ < in_right)) && (inbuf[in_left] == ' ' || inbuf[in_left] == '\\n'); ++in_left);\n\
    \        s.clear();\n        if (in_left == in_right) return;\n        int real_size\
    \ = 0;\n        do {\n          int to;\n          for (to = in_left; to < in_right\
    \ && inbuf[to] != ' ' && inbuf[to] != '\\n'; ++to);\n          const int new_real_size\
    \ = real_size + (to - in_left);\n          if (int(s.size()) < new_real_size)\
    \ {\n            s.resize(::std::max(new_real_size, int(s.size()) * 2));\n   \
    \       }\n          ::std::memcpy(s.data() + real_size, inbuf + in_left, to -\
    \ in_left);\n          in_left = to;\n          real_size = new_real_size;\n \
    \       } while (in_left == in_right && (load(), in_left < in_right));\n     \
    \   s.resize(real_size);\n      }\n\n      template <typename T>\n      void rd(T&\
    \ x) {\n        if (in_left + 32 > in_right) load();\n        char c;\n      \
    \  do {\n          c = inbuf[in_left++];\n        } while (c < '-');\n       \
    \ [[maybe_unused]] bool minus = false;\n        if constexpr (::std::is_signed_v<T>)\
    \ {\n          if (c == '-') {\n            minus = true;\n            c = inbuf[in_left++];\n\
    \          }\n        }\n        x = 0;\n        while (c >= '0') {\n        \
    \  x = x * 10 + (c & 15);\n          c = inbuf[in_left++];\n        }\n      \
    \  if constexpr (::std::is_signed_v<T>) {\n          if (minus) x = -x;\n    \
    \    }\n      }\n    }\n  }\n\n  struct istream {\n    template <typename... Args>\n\
    \    ::tools::istream& operator>>(Args&&... args) {\n      ::tools::detail::istream::rd(::std::forward<Args>(args)...);\n\
    \      return *this;\n    }\n  };\n\n  ::tools::istream cin;\n}\n\n\n#line 1 \"\
    tools/cout.hpp\"\n\n\n\n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\n#line 13 \"tools/cout.hpp\"\
    \n#include <cstdint>\n#include <cstdlib>\n#line 17 \"tools/cout.hpp\"\n\nnamespace\
    \ tools {\n  namespace detail {\n    namespace ostream {\n      static constexpr\
    \ int SZ = 1 << 17;\n      char outbuf[SZ];\n      int out_right = 0;\n\n    \
    \  struct Pre {\n        char num[40000];\n        constexpr Pre() : num() {\n\
    \          for (int i = 0; i < 10000; i++) {\n            int n = i;\n       \
    \     for (int j = 3; j >= 0; j--) {\n              num[i * 4 + j] = n % 10 +\
    \ '0';\n              n /= 10;\n            }\n          }\n        }\n      }\
    \ constexpr pre;\n\n      void flush() {\n        ::std::fwrite(outbuf, 1, out_right,\
    \ stdout);\n        out_right = 0;\n      }\n\n      void wt(const char c) {\n\
    \        if (out_right > SZ - 32) flush();\n        outbuf[out_right++] = c;\n\
    \      }\n\n      void wt(const bool b) {\n        if (out_right > SZ - 32) flush();\n\
    \        outbuf[out_right++] = b ? '1' : '0';\n      }\n\n      void wt(const\
    \ ::std::string& s) {\n        for (int l = 0, w; l < int(s.size()); l += w) {\n\
    \          w = ::std::min(int(s.size()) - l, SZ - out_right);\n          ::std::memcpy(outbuf\
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
    \      return *this;\n    }\n  };\n\n  ::tools::ostream cout;\n}\n\n\n#line 6\
    \ \"tests/fastio/integer.test.cpp\"\n\nusing ll = long long;\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  int T;\n\
    \  tools::cin >> T;\n  for (int i = 0; i < T; ++i) {\n    ll A, B;\n    tools::cin\
    \ >> A >> B;\n    tools::cout << A + B << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ <iostream>\n#include \"tools/cin.hpp\"\n#include \"tools/cout.hpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int T;\n  tools::cin >> T;\n  for (int i = 0; i < T; ++i) {\n    ll A, B;\n\
    \    tools::cin >> A >> B;\n    tools::cout << A + B << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/cin.hpp
  - tools/cout.hpp
  isVerificationFile: true
  path: tests/fastio/integer.test.cpp
  requiredBy: []
  timestamp: '2023-05-01 06:00:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/fastio/integer.test.cpp
layout: document
redirect_from:
- /verify/tests/fastio/integer.test.cpp
- /verify/tests/fastio/integer.test.cpp.html
title: tests/fastio/integer.test.cpp
---
