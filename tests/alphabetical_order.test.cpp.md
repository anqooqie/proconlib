---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/alphabetical_order.hpp
    title: Alphabetical order of a given character
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
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
  bundledCode: "#line 1 \"tests/alphabetical_order.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n#include <cstdlib>\n#include\
    \ <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 6 \"tools/assert_that.hpp\"\
    \n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__\
    \ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" << #cond << \"\
    ' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\
    \n\n#line 1 \"tools/alphabetical_order.hpp\"\n\n\n\n#include <array>\n#include\
    \ <limits>\n\nnamespace tools {\n\n  int alphabetical_order(const char c) {\n\
    \    static const ::std::array<char, ::std::numeric_limits<char>::max()> map =\
    \ []() {\n      ::std::array<char, ::std::numeric_limits<char>::max()> m;\n  \
    \    m['A'] = 0;\n      m['B'] = 1;\n      m['C'] = 2;\n      m['D'] = 3;\n  \
    \    m['E'] = 4;\n      m['F'] = 5;\n      m['G'] = 6;\n      m['H'] = 7;\n  \
    \    m['I'] = 8;\n      m['J'] = 9;\n      m['K'] = 10;\n      m['L'] = 11;\n\
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
    \      return m;\n    }();\n    return map[c];\n  }\n}\n\n\n#line 7 \"tests/alphabetical_order.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::alphabetical_order('A') == 0);\n  assert_that(tools::alphabetical_order('B')\
    \ == 1);\n  assert_that(tools::alphabetical_order('C') == 2);\n  assert_that(tools::alphabetical_order('D')\
    \ == 3);\n  assert_that(tools::alphabetical_order('E') == 4);\n  assert_that(tools::alphabetical_order('F')\
    \ == 5);\n  assert_that(tools::alphabetical_order('G') == 6);\n  assert_that(tools::alphabetical_order('H')\
    \ == 7);\n  assert_that(tools::alphabetical_order('I') == 8);\n  assert_that(tools::alphabetical_order('J')\
    \ == 9);\n  assert_that(tools::alphabetical_order('K') == 10);\n  assert_that(tools::alphabetical_order('L')\
    \ == 11);\n  assert_that(tools::alphabetical_order('M') == 12);\n  assert_that(tools::alphabetical_order('N')\
    \ == 13);\n  assert_that(tools::alphabetical_order('O') == 14);\n  assert_that(tools::alphabetical_order('P')\
    \ == 15);\n  assert_that(tools::alphabetical_order('Q') == 16);\n  assert_that(tools::alphabetical_order('R')\
    \ == 17);\n  assert_that(tools::alphabetical_order('S') == 18);\n  assert_that(tools::alphabetical_order('T')\
    \ == 19);\n  assert_that(tools::alphabetical_order('U') == 20);\n  assert_that(tools::alphabetical_order('V')\
    \ == 21);\n  assert_that(tools::alphabetical_order('W') == 22);\n  assert_that(tools::alphabetical_order('X')\
    \ == 23);\n  assert_that(tools::alphabetical_order('Y') == 24);\n  assert_that(tools::alphabetical_order('Z')\
    \ == 25);\n\n  assert_that(tools::alphabetical_order('a') == 0);\n  assert_that(tools::alphabetical_order('b')\
    \ == 1);\n  assert_that(tools::alphabetical_order('c') == 2);\n  assert_that(tools::alphabetical_order('d')\
    \ == 3);\n  assert_that(tools::alphabetical_order('e') == 4);\n  assert_that(tools::alphabetical_order('f')\
    \ == 5);\n  assert_that(tools::alphabetical_order('g') == 6);\n  assert_that(tools::alphabetical_order('h')\
    \ == 7);\n  assert_that(tools::alphabetical_order('i') == 8);\n  assert_that(tools::alphabetical_order('j')\
    \ == 9);\n  assert_that(tools::alphabetical_order('k') == 10);\n  assert_that(tools::alphabetical_order('l')\
    \ == 11);\n  assert_that(tools::alphabetical_order('m') == 12);\n  assert_that(tools::alphabetical_order('n')\
    \ == 13);\n  assert_that(tools::alphabetical_order('o') == 14);\n  assert_that(tools::alphabetical_order('p')\
    \ == 15);\n  assert_that(tools::alphabetical_order('q') == 16);\n  assert_that(tools::alphabetical_order('r')\
    \ == 17);\n  assert_that(tools::alphabetical_order('s') == 18);\n  assert_that(tools::alphabetical_order('t')\
    \ == 19);\n  assert_that(tools::alphabetical_order('u') == 20);\n  assert_that(tools::alphabetical_order('v')\
    \ == 21);\n  assert_that(tools::alphabetical_order('w') == 22);\n  assert_that(tools::alphabetical_order('x')\
    \ == 23);\n  assert_that(tools::alphabetical_order('y') == 24);\n  assert_that(tools::alphabetical_order('z')\
    \ == 25);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cstdlib>\n#include <iostream>\n#include \"tools/assert_that.hpp\"\n\
    #include \"tools/alphabetical_order.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::alphabetical_order('A')\
    \ == 0);\n  assert_that(tools::alphabetical_order('B') == 1);\n  assert_that(tools::alphabetical_order('C')\
    \ == 2);\n  assert_that(tools::alphabetical_order('D') == 3);\n  assert_that(tools::alphabetical_order('E')\
    \ == 4);\n  assert_that(tools::alphabetical_order('F') == 5);\n  assert_that(tools::alphabetical_order('G')\
    \ == 6);\n  assert_that(tools::alphabetical_order('H') == 7);\n  assert_that(tools::alphabetical_order('I')\
    \ == 8);\n  assert_that(tools::alphabetical_order('J') == 9);\n  assert_that(tools::alphabetical_order('K')\
    \ == 10);\n  assert_that(tools::alphabetical_order('L') == 11);\n  assert_that(tools::alphabetical_order('M')\
    \ == 12);\n  assert_that(tools::alphabetical_order('N') == 13);\n  assert_that(tools::alphabetical_order('O')\
    \ == 14);\n  assert_that(tools::alphabetical_order('P') == 15);\n  assert_that(tools::alphabetical_order('Q')\
    \ == 16);\n  assert_that(tools::alphabetical_order('R') == 17);\n  assert_that(tools::alphabetical_order('S')\
    \ == 18);\n  assert_that(tools::alphabetical_order('T') == 19);\n  assert_that(tools::alphabetical_order('U')\
    \ == 20);\n  assert_that(tools::alphabetical_order('V') == 21);\n  assert_that(tools::alphabetical_order('W')\
    \ == 22);\n  assert_that(tools::alphabetical_order('X') == 23);\n  assert_that(tools::alphabetical_order('Y')\
    \ == 24);\n  assert_that(tools::alphabetical_order('Z') == 25);\n\n  assert_that(tools::alphabetical_order('a')\
    \ == 0);\n  assert_that(tools::alphabetical_order('b') == 1);\n  assert_that(tools::alphabetical_order('c')\
    \ == 2);\n  assert_that(tools::alphabetical_order('d') == 3);\n  assert_that(tools::alphabetical_order('e')\
    \ == 4);\n  assert_that(tools::alphabetical_order('f') == 5);\n  assert_that(tools::alphabetical_order('g')\
    \ == 6);\n  assert_that(tools::alphabetical_order('h') == 7);\n  assert_that(tools::alphabetical_order('i')\
    \ == 8);\n  assert_that(tools::alphabetical_order('j') == 9);\n  assert_that(tools::alphabetical_order('k')\
    \ == 10);\n  assert_that(tools::alphabetical_order('l') == 11);\n  assert_that(tools::alphabetical_order('m')\
    \ == 12);\n  assert_that(tools::alphabetical_order('n') == 13);\n  assert_that(tools::alphabetical_order('o')\
    \ == 14);\n  assert_that(tools::alphabetical_order('p') == 15);\n  assert_that(tools::alphabetical_order('q')\
    \ == 16);\n  assert_that(tools::alphabetical_order('r') == 17);\n  assert_that(tools::alphabetical_order('s')\
    \ == 18);\n  assert_that(tools::alphabetical_order('t') == 19);\n  assert_that(tools::alphabetical_order('u')\
    \ == 20);\n  assert_that(tools::alphabetical_order('v') == 21);\n  assert_that(tools::alphabetical_order('w')\
    \ == 22);\n  assert_that(tools::alphabetical_order('x') == 23);\n  assert_that(tools::alphabetical_order('y')\
    \ == 24);\n  assert_that(tools::alphabetical_order('z') == 25);\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/alphabetical_order.hpp
  isVerificationFile: true
  path: tests/alphabetical_order.test.cpp
  requiredBy: []
  timestamp: '2022-06-17 23:50:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/alphabetical_order.test.cpp
layout: document
redirect_from:
- /verify/tests/alphabetical_order.test.cpp
- /verify/tests/alphabetical_order.test.cpp.html
title: tests/alphabetical_order.test.cpp
---
