---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':heavy_check_mark:'
    path: tools/is_group.hpp
    title: Check whether T is a group
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
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
  bundledCode: "#line 1 \"tests/is_group.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n\
    \    ::std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion\
    \ `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n\
    \  }\\\n} while (false)\n\n\n#line 1 \"tools/is_group.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <utility>\n\nnamespace tools {\n\n  template <typename G, typename =\
    \ void>\n  struct is_group : ::std::false_type {};\n\n  template <typename G>\n\
    \  struct is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename G::T,\
    \ decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename G::T>()))>\
    \ &&\n    ::std::is_same_v<typename G::T, decltype(G::e())> &&\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::inv(::std::declval<typename G::T>()))>\n  , void>> : ::std::true_type\
    \ {};\n\n  template <typename G>\n  inline constexpr bool is_group_v = ::tools::is_group<G>::value;\n\
    }\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n#include <limits>\n\
    #include <numeric>\n\nnamespace tools {\n  namespace monoid {\n    template <typename\
    \ M, M E = ::std::numeric_limits<M>::lowest()>\n    struct max {\n      using\
    \ T = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::max(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename M, M E = ::std::numeric_limits<M>::max()>\n    struct\
    \ min {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n\
    \        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n       \
    \ return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n\n#line 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace\
    \ group {\n    template <typename G>\n    struct plus {\n      using T = G;\n\
    \      static T op(const T& lhs, const T& rhs) {\n        return lhs + rhs;\n\
    \      }\n      static T e() {\n        return T(0);\n      }\n      static T\
    \ inv(const T& v) {\n        return -v;\n      }\n    };\n\n    template <typename\
    \ G>\n    struct multiplies {\n      using T = G;\n      static T op(const T&\
    \ lhs, const T& rhs) {\n        return lhs * rhs;\n      }\n      static T e()\
    \ {\n        return T(1);\n      }\n      static T inv(const T& v) {\n       \
    \ return e() / v;\n      }\n    };\n\n    template <typename G>\n    struct bit_xor\
    \ {\n      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs ^ rhs;\n      }\n      static T e() {\n        return T(0);\n\
    \      }\n      static T inv(const T& v) {\n        return v;\n      }\n    };\n\
    \  }\n}\n\n\n#line 8 \"tests/is_group.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::is_group_v<int>\
    \ == false);\n  assert_that(tools::is_group_v<tools::monoid::multiplies<int>>\
    \ == false);\n  assert_that(tools::is_group_v<tools::group::plus<int>> == true);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/is_group.hpp\"\
    \n#include \"tools/monoid.hpp\"\n#include \"tools/group.hpp\"\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::is_group_v<int>\
    \ == false);\n  assert_that(tools::is_group_v<tools::monoid::multiplies<int>>\
    \ == false);\n  assert_that(tools::is_group_v<tools::group::plus<int>> == true);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/is_group.hpp
  - tools/monoid.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/is_group.test.cpp
  requiredBy: []
  timestamp: '2024-03-23 15:55:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/is_group.test.cpp
layout: document
redirect_from:
- /verify/tests/is_group.test.cpp
- /verify/tests/is_group.test.cpp.html
title: tests/is_group.test.cpp
---
