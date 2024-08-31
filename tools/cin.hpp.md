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
  bundledCode: "#line 1 \"tools/cin.hpp\"\n\n\n\n#include <cstring>\n#include <cstdio>\n\
    #include <string>\n#include <algorithm>\n#include <type_traits>\n#include <iostream>\n\
    #include <utility>\n\n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  namespace\
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
    \      return *this;\n    }\n  };\n\n  ::tools::istream cin;\n}\n\n\n"
  code: "#ifndef TOOLS_CIN_HPP\n#define TOOLS_CIN_HPP\n\n#include <cstring>\n#include\
    \ <cstdio>\n#include <string>\n#include <algorithm>\n#include <type_traits>\n\
    #include <iostream>\n#include <utility>\n\n// Source: https://nyaannyaan.github.io/library/misc/fastio.hpp.html\n\
    // License: CC0 1.0 Universal\n// Author: Nyaan\n\nnamespace tools {\n  namespace\
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
    \      return *this;\n    }\n  };\n\n  ::tools::istream cin;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cin.hpp
  requiredBy: []
  timestamp: '2023-05-02 20:12:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/fastio/integer.test.cpp
  - tests/fastio/string.test.cpp
documentation_of: tools/cin.hpp
layout: document
title: Fast input
---

It provides very restricted but fast input functions.

### Constraints
- You cannot include this header file from more than one compilation unit.

### License
- CC0 1.0 Universal

### Author
- Nyaan

## tools::cin
```cpp
tools::istream cin;
```

It is an interface to the input functions.

## tools::istream::operator&gt;&gt;
```cpp
(1) tools::istream& cin.operator>>(char& c);
(2) tools::istream& cin.operator>>(std::string& s);
(3) template <typename T> tools::istream& cin.operator>>(T& x);
```

- (1)
    - It reads one character from standard input, sets the value to `c` and returns `cin`.
- (2)
    - We can express the entire string not yet read from standard input in the form of the regular expression `([ \n]*)([^ \n]*).*`. It reads the first and second groups from standard input, sets the second group to `s` and returns `cin`.
- (3)
    - If we can express the entire string not yet read from standard input in the form of the regular expression `([ \n]*)(-?[0-9]+).*`, it reads the first and second groups from standard input, sets the integer parsed from the second group to `x` and returns `cin`.

### Constraints
- (1)
    - You cannot read standard input by any other ways except for `tools::cin` in the program.
    - There are at least one character not yet read from standard input.
- (2)
    - You cannot read standard input by any other ways except for `tools::cin` in the program.
- (3)
    - You cannot read standard input by any other ways except for `tools::cin` in the program.
    - `<T>` is a built-in integral type.
    - If `<T>` is signed:
        - The entire string not yet read from standard input matches the regular expression `^[ \n]*-?[0-9]+`.
        - `-std::numeric_limits<T>::max()` $\leq v \leq$ `std::numeric_limits<T>::max()` where $v$ is the value that will be read.
    - If `<T>` is unsigned:
        - The entire string not yet read from standard input matches the regular expression `^[ \n]*[0-9]+`.
        - $0 \leq v \leq$ `std::numeric_limits<T>::max()` where $v$ is the value that will be read.

### Time Complexity
- (1), (3)
    - $O(1)$
- (2)
    - $O(\|v\|)$ where $v$ is the value that will be read
