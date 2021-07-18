---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/alphabetical_order.test.cpp
    title: tests/alphabetical_order.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/alphabetical_order.hpp\"\n\n\n\n#include <array>\n\
    #include <limits>\n\nnamespace tools {\n\n  int alphabetical_order(const char\
    \ c) {\n    static const ::std::array<char, ::std::numeric_limits<char>::max()>\
    \ map = []() {\n      ::std::array<char, ::std::numeric_limits<char>::max()> m;\n\
    \      m['A'] = 0;\n      m['B'] = 1;\n      m['C'] = 2;\n      m['D'] = 3;\n\
    \      m['E'] = 4;\n      m['F'] = 5;\n      m['G'] = 6;\n      m['H'] = 7;\n\
    \      m['I'] = 8;\n      m['J'] = 9;\n      m['K'] = 10;\n      m['L'] = 11;\n\
    \      m['M'] = 12;\n      m['N'] = 13;\n      m['O'] = 14;\n      m['P'] = 15;\n\
    \      m['Q'] = 16;\n      m['R'] = 17;\n      m['S'] = 18;\n      m['T'] = 19;\n\
    \      m['U'] = 20;\n      m['V'] = 21;\n      m['W'] = 22;\n      m['X'] = 23;\n\
    \      m['Y'] = 24;\n      m['Z'] = 25;\n      m['a'] = 0;\n      m['b'] = 1;\n\
    \      m['c'] = 2;\n      m['d'] = 3;\n      m['e'] = 4;\n      m['f'] = 5;\n\
    \      m['g'] = 6;\n      m['h'] = 7;\n      m['i'] = 8;\n      m['j'] = 9;\n\
    \      m['k'] = 10;\n      m['l'] = 11;\n      m['m'] = 12;\n      m['n'] = 13;\n\
    \      m['o'] = 14;\n      m['p'] = 15;\n      m['q'] = 16;\n      m['r'] = 17;\n\
    \      m['s'] = 18;\n      m['t'] = 19;\n      m['u'] = 20;\n      m['v'] = 21;\n\
    \      m['w'] = 22;\n      m['x'] = 23;\n      m['y'] = 24;\n      m['z'] = 25;\n\
    \      return m;\n    }();\n    return map[c];\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ALPHABETICAL_ORDER_HPP\n#define TOOLS_ALPHABETICAL_ORDER_HPP\n\
    \n#include <array>\n#include <limits>\n\nnamespace tools {\n\n  int alphabetical_order(const\
    \ char c) {\n    static const ::std::array<char, ::std::numeric_limits<char>::max()>\
    \ map = []() {\n      ::std::array<char, ::std::numeric_limits<char>::max()> m;\n\
    \      m['A'] = 0;\n      m['B'] = 1;\n      m['C'] = 2;\n      m['D'] = 3;\n\
    \      m['E'] = 4;\n      m['F'] = 5;\n      m['G'] = 6;\n      m['H'] = 7;\n\
    \      m['I'] = 8;\n      m['J'] = 9;\n      m['K'] = 10;\n      m['L'] = 11;\n\
    \      m['M'] = 12;\n      m['N'] = 13;\n      m['O'] = 14;\n      m['P'] = 15;\n\
    \      m['Q'] = 16;\n      m['R'] = 17;\n      m['S'] = 18;\n      m['T'] = 19;\n\
    \      m['U'] = 20;\n      m['V'] = 21;\n      m['W'] = 22;\n      m['X'] = 23;\n\
    \      m['Y'] = 24;\n      m['Z'] = 25;\n      m['a'] = 0;\n      m['b'] = 1;\n\
    \      m['c'] = 2;\n      m['d'] = 3;\n      m['e'] = 4;\n      m['f'] = 5;\n\
    \      m['g'] = 6;\n      m['h'] = 7;\n      m['i'] = 8;\n      m['j'] = 9;\n\
    \      m['k'] = 10;\n      m['l'] = 11;\n      m['m'] = 12;\n      m['n'] = 13;\n\
    \      m['o'] = 14;\n      m['p'] = 15;\n      m['q'] = 16;\n      m['r'] = 17;\n\
    \      m['s'] = 18;\n      m['t'] = 19;\n      m['u'] = 20;\n      m['v'] = 21;\n\
    \      m['w'] = 22;\n      m['x'] = 23;\n      m['y'] = 24;\n      m['z'] = 25;\n\
    \      return m;\n    }();\n    return map[c];\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/alphabetical_order.hpp
  requiredBy: []
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/alphabetical_order.test.cpp
documentation_of: tools/alphabetical_order.hpp
layout: document
title: Alphabetical order of a given character
---

```cpp
int alphabetical_order(char c);
```

It returns 

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $c$ is 'A' or 'a')}\\
1 & \text{(if $c$ is 'B' or 'b')}\\
\vdots &\\
25 & \text{(if $c$ is 'Z' or 'z')}
\end{array}\right.&
\end{align*}$$

## Constraints
- `c` is any one of `[A-Za-z]`.

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
