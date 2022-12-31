---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/int128_t.hpp
    title: 128 bit signed integer
  - icon: ':heavy_check_mark:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
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
  bundledCode: "#line 1 \"tests/int128_t.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <sstream>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/int128_t.hpp\"\
    \n\n\n\n#line 5 \"tools/int128_t.hpp\"\n#include <string>\n#include <cassert>\n\
    #include <cstddef>\n#include <algorithm>\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\
    \n#line 9 \"tools/uint128_t.hpp\"\n\nnamespace tools {\n  using uint128_t = unsigned\
    \ __int128;\n}\n\n::std::istream& operator>>(::std::istream& is, ::tools::uint128_t&\
    \ x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for\
    \ (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n\
    ::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n  if (x\
    \ == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n    s.push_back('0'\
    \ + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(), s.end());\n\n  return\
    \ os << s;\n}\n\n\n#line 10 \"tools/int128_t.hpp\"\n\nnamespace tools {\n  using\
    \ int128_t = __int128;\n}\n\n::std::istream& operator>>(::std::istream& is, ::tools::int128_t&\
    \ x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  if (s == \"\
    -170141183460469231731687303715884105728\") {\n    x = -::tools::int128_t((::tools::uint128_t(1)\
    \ << 127) - 1) - 1;\n    return is;\n  }\n\n  x = 0;\n  for (::std::size_t i =\
    \ s[0] == '+' || s[0] == '-'; i < s.size(); ++i) {\n    assert('0' <= s[i] &&\
    \ s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  if (s[0] == '-') x =\
    \ -x;\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::int128_t\
    \ x) {\n  if (x == 0) return os << '0';\n  if (x == -::tools::int128_t((::tools::uint128_t(1)\
    \ << 127) - 1) - 1) return os << \"-170141183460469231731687303715884105728\"\
    ;\n\n  ::std::string s;\n  const bool negative = x < 0;\n\n  if (negative) x =\
    \ -x;\n  while (x > 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n\n\
    \  if (negative) s.push_back('-');\n  ::std::reverse(s.begin(), s.end());\n  return\
    \ os << s;\n}\n\n\n#line 7 \"tests/int128_t.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  {\n    tools::int128_t v;\n   \
    \ std::istringstream iss(\"-170141183460469231731687303715884105728\");\n    iss\
    \ >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"-170141183460469231731687303715884105728\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"-170141183460469231731687303715884105727\"\
    );\n    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"-170141183460469231731687303715884105727\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"-1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"-1\");\n  }\n\n  {\n   \
    \ tools::int128_t v;\n    std::istringstream iss(\"0\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"+0\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"+1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"170141183460469231731687303715884105727\");\n\
    \    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"170141183460469231731687303715884105727\");\n  }\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"+170141183460469231731687303715884105727\"\
    );\n    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"170141183460469231731687303715884105727\");\n  }\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <sstream>\n#include \"tools/assert_that.hpp\"\n\
    #include \"tools/int128_t.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    tools::int128_t v;\n    std::istringstream iss(\"-170141183460469231731687303715884105728\"\
    );\n    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"-170141183460469231731687303715884105728\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"-170141183460469231731687303715884105727\"\
    );\n    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"-170141183460469231731687303715884105727\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"-1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"-1\");\n  }\n\n  {\n   \
    \ tools::int128_t v;\n    std::istringstream iss(\"0\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"+0\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"0\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"+1\");\n    iss >> v;\n    std::ostringstream\
    \ oss;\n    oss << v;\n    assert_that(oss.str() == \"1\");\n  }\n\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"170141183460469231731687303715884105727\");\n\
    \    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"170141183460469231731687303715884105727\");\n  }\n  {\n    tools::int128_t\
    \ v;\n    std::istringstream iss(\"+170141183460469231731687303715884105727\"\
    );\n    iss >> v;\n    std::ostringstream oss;\n    oss << v;\n    assert_that(oss.str()\
    \ == \"170141183460469231731687303715884105727\");\n  }\n\n  std::cout << \"Hello\
    \ World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/int128_t.hpp
  - tools/uint128_t.hpp
  isVerificationFile: true
  path: tests/int128_t.test.cpp
  requiredBy: []
  timestamp: '2022-11-23 11:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/int128_t.test.cpp
layout: document
redirect_from:
- /verify/tests/int128_t.test.cpp
- /verify/tests/int128_t.test.cpp.html
title: tests/int128_t.test.cpp
---