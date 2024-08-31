---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/gcd.hpp
    title: std::gcd(m, n) extended for my library
  - icon: ':question:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':question:'
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
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/is_group.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#include <utility>\n\nnamespace tools {\n\n  template <typename\
    \ G, typename = void>\n  struct is_group : ::std::false_type {};\n\n  template\
    \ <typename G>\n  struct is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename\
    \ G::T>()))> &&\n    ::std::is_same_v<typename G::T, decltype(G::e())> &&\n  \
    \  ::std::is_same_v<typename G::T, decltype(G::inv(::std::declval<typename G::T>()))>\n\
    \  , void>> : ::std::true_type {};\n\n  template <typename G>\n  inline constexpr\
    \ bool is_group_v = ::tools::is_group<G>::value;\n}\n\n\n#line 1 \"tools/monoid.hpp\"\
    \n\n\n\n#line 5 \"tools/monoid.hpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <cassert>\n#line 1 \"tools/gcd.hpp\"\n\n\n\n#line 5 \"tools/gcd.hpp\"\
    \n#include <numeric>\n\nnamespace tools {\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> gcd(const M m, const N n) {\n    return\
    \ ::std::gcd(m, n);\n  }\n}\n\n\n#line 9 \"tools/monoid.hpp\"\n\nnamespace tools\
    \ {\n  namespace monoid {\n    template <typename M, M ...dummy>\n    struct max;\n\
    \n    template <typename M>\n    struct max<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::max(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::min();\n        } else {\n       \
    \   return -::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct max<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(E <= lhs);\n        assert(E\
    \ <= rhs);\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename M, M ...dummy>\n\
    \    struct min;\n\n    template <typename M>\n    struct min<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::min(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::max();\n        } else {\n       \
    \   return ::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct min<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(lhs <= E);\n        assert(rhs\
    \ <= E);\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n    private:\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n \
    \       return T(1);\n      }\n    };\n\n    template <>\n    struct multiplies<bool>\
    \ {\n      using T = bool;\n      static T op(const bool lhs, const bool rhs)\
    \ {\n        return lhs && rhs;\n      }\n      static T e() {\n        return\
    \ true;\n      }\n    };\n\n    template <typename M>\n    struct gcd {\n    private:\n\
    \      static_assert(!::std::is_arithmetic_v<M> || (::std::is_integral_v<M> &&\
    \ !::std::is_same_v<M, bool>), \"If M is a built-in arithmetic type, it must be\
    \ integral except for bool.\");\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return ::tools::gcd(lhs, rhs);\n      }\n      static\
    \ T e() {\n        return T(0);\n      }\n    };\n\n    template <typename M,\
    \ M E>\n    struct update {\n      static_assert(::std::is_integral_v<M>, \"M\
    \ must be a built-in integral type.\");\n\n      using T = M;\n      static T\
    \ op(const T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n     \
    \ }\n      static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line\
    \ 1 \"tools/group.hpp\"\n\n\n\nnamespace tools {\n  namespace group {\n    template\
    \ <typename G>\n    struct plus {\n      using T = G;\n      static T op(const\
    \ T& lhs, const T& rhs) {\n        return lhs + rhs;\n      }\n      static T\
    \ e() {\n        return T(0);\n      }\n      static T inv(const T& v) {\n   \
    \     return -v;\n      }\n    };\n\n    template <typename G>\n    struct multiplies\
    \ {\n      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n      static T inv(const T& v) {\n        return e() / v;\n      }\n\
    \    };\n\n    template <typename G>\n    struct bit_xor {\n      using T = G;\n\
    \      static T op(const T& lhs, const T& rhs) {\n        return lhs ^ rhs;\n\
    \      }\n      static T e() {\n        return T(0);\n      }\n      static T\
    \ inv(const T& v) {\n        return v;\n      }\n    };\n  }\n}\n\n\n#line 8 \"\
    tests/is_group.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(tools::is_group_v<int> == false);\n  assert_that(tools::is_group_v<tools::monoid::multiplies<int>>\
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
  - tools/gcd.hpp
  - tools/group.hpp
  isVerificationFile: true
  path: tests/is_group.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/is_group.test.cpp
layout: document
redirect_from:
- /verify/tests/is_group.test.cpp
- /verify/tests/is_group.test.cpp.html
title: tests/is_group.test.cpp
---
