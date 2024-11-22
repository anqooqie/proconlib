---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/transposed.hpp
    title: Transposition
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
  bundledCode: "#line 1 \"tests/transposed.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <array>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that_impl(cond,\
    \ file, line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' <<\
    \ line << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\\
    n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/transposed.hpp\"\n\n\n\n#line 5 \"tools/transposed.hpp\"\n#include <cassert>\n\
    #include <algorithm>\n#include <cstddef>\n#line 9 \"tools/transposed.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  ::std::vector<::std::vector<T>>\
    \ transposed(const ::std::vector<::std::vector<T>>& matrix) {\n    const auto\
    \ N = matrix.size();\n    const auto M = matrix.empty() ? 0 : matrix.front().size();\n\
    \    assert(::std::all_of(matrix.begin(), matrix.end(), [&](const auto& row) {\
    \ return row.size() == M; }));\n\n    auto res = ::std::vector(M, ::std::vector<T>(N));\n\
    \    for (::std::size_t r = 0; r < M; ++r) {\n      for (::std::size_t c = 0;\
    \ c < N; ++c) {\n        res[r][c] = matrix[c][r];\n      }\n    }\n    return\
    \ res;\n  }\n\n  template <typename T, ::std::size_t N>\n  ::std::vector<::std::array<T,\
    \ N>> transposed(const ::std::array<::std::vector<T>, N>& matrix) {\n    const\
    \ auto M = matrix.empty() ? 0 : matrix.front().size();\n    assert(::std::all_of(matrix.begin(),\
    \ matrix.end(), [&](const auto& row) { return row.size() == M; }));\n\n    auto\
    \ res = ::std::vector(M, ::std::array<T, N>{});\n    for (::std::size_t r = 0;\
    \ r < M; ++r) {\n      for (::std::size_t c = 0; c < N; ++c) {\n        res[r][c]\
    \ = matrix[c][r];\n      }\n    }\n    return res;\n  }\n\n  template <typename\
    \ T, ::std::size_t M>\n  ::std::array<::std::vector<T>, M> transposed(const ::std::vector<::std::array<T,\
    \ M>>& matrix) {\n    const auto N = matrix.size();\n\n    ::std::array<::std::vector<T>,\
    \ M> res;\n    for (::std::size_t r = 0; r < M; ++r) {\n      res[r].resize(N);\n\
    \      for (::std::size_t c = 0; c < N; ++c) {\n        res[r][c] = matrix[c][r];\n\
    \      }\n    }\n    return res;\n  }\n\n  template <typename T, ::std::size_t\
    \ N, ::std::size_t M>\n  ::std::array<::std::array<T, N>, M> transposed(const\
    \ ::std::array<::std::array<T, M>, N>& matrix) {\n    ::std::array<::std::array<T,\
    \ N>, M> res;\n    for (::std::size_t r = 0; r < M; ++r) {\n      for (::std::size_t\
    \ c = 0; c < N; ++c) {\n        res[r][c] = matrix[c][r];\n      }\n    }\n  \
    \  return res;\n  }\n}\n\n\n#line 8 \"tests/transposed.test.cpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::transposed(std::vector<std::vector<int>>\
    \ {\n  }) == std::vector<std::vector<int>> {\n  });\n  assert_that(tools::transposed(std::vector<std::vector<int>>\
    \ {\n    {},\n    {},\n  }) == std::vector<std::vector<int>> {\n  });\n  assert_that(tools::transposed(std::vector<std::vector<int>>\
    \ {\n    {1, 2, 3},\n    {4, 5, 6},\n  }) == std::vector<std::vector<int>> {\n\
    \    {1, 4},\n    {2, 5},\n    {3, 6},\n  });\n\n  assert_that(tools::transposed(std::array<std::vector<int>,\
    \ 0> {{\n  }}) == std::vector<std::array<int, 0>> {\n  });\n  assert_that(tools::transposed(std::array<std::vector<int>,\
    \ 2> {{\n    {},\n    {},\n  }}) == std::vector<std::array<int, 2>> {\n  });\n\
    \  assert_that(tools::transposed(std::array<std::vector<int>, 2> {{\n    {1, 2,\
    \ 3},\n    {4, 5, 6},\n  }}) == std::vector<std::array<int, 2>> {\n    {1, 4},\n\
    \    {2, 5},\n    {3, 6},\n  });\n\n  assert_that(tools::transposed(std::vector<std::array<int,\
    \ 0>> {\n  }) == std::array<std::vector<int>, 0> {{\n  }});\n  assert_that(tools::transposed(std::vector<std::array<int,\
    \ 3>> {\n  }) == std::array<std::vector<int>, 3> {{\n    {},\n    {},\n    {},\n\
    \  }});\n  assert_that(tools::transposed(std::vector<std::array<int, 0>> {\n \
    \   {},\n    {},\n  }) == std::array<std::vector<int>, 0> {{\n  }});\n  assert_that(tools::transposed(std::vector<std::array<int,\
    \ 3>> {\n    {1, 2, 3},\n    {4, 5, 6},\n  }) == std::array<std::vector<int>,\
    \ 3> {{\n    {1, 4},\n    {2, 5},\n    {3, 6},\n  }});\n\n  assert_that(tools::transposed(std::array<std::array<int,\
    \ 0>, 0> {{\n  }}) == std::array<std::array<int, 0>, 0> {{\n  }});\n  assert_that(tools::transposed(std::array<std::array<int,\
    \ 3>, 0> {{\n  }}) == std::array<std::array<int, 0>, 3> {{\n    {},\n    {},\n\
    \    {},\n  }});\n  assert_that(tools::transposed(std::array<std::array<int, 0>,\
    \ 2> {{\n    {},\n    {},\n  }}) == std::array<std::array<int, 2>, 0> {{\n  }});\n\
    \  assert_that(tools::transposed(std::array<std::array<int, 3>, 2> {{\n    {1,\
    \ 2, 3},\n    {4, 5, 6},\n  }}) == std::array<std::array<int, 2>, 3> {{\n    {1,\
    \ 4},\n    {2, 5},\n    {3, 6},\n  }});\n\n  std::cout << \"Hello World\" << '\\\
    n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <array>\n#include \"tools/assert_that.hpp\"\
    \n#include \"tools/transposed.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::transposed(std::vector<std::vector<int>>\
    \ {\n  }) == std::vector<std::vector<int>> {\n  });\n  assert_that(tools::transposed(std::vector<std::vector<int>>\
    \ {\n    {},\n    {},\n  }) == std::vector<std::vector<int>> {\n  });\n  assert_that(tools::transposed(std::vector<std::vector<int>>\
    \ {\n    {1, 2, 3},\n    {4, 5, 6},\n  }) == std::vector<std::vector<int>> {\n\
    \    {1, 4},\n    {2, 5},\n    {3, 6},\n  });\n\n  assert_that(tools::transposed(std::array<std::vector<int>,\
    \ 0> {{\n  }}) == std::vector<std::array<int, 0>> {\n  });\n  assert_that(tools::transposed(std::array<std::vector<int>,\
    \ 2> {{\n    {},\n    {},\n  }}) == std::vector<std::array<int, 2>> {\n  });\n\
    \  assert_that(tools::transposed(std::array<std::vector<int>, 2> {{\n    {1, 2,\
    \ 3},\n    {4, 5, 6},\n  }}) == std::vector<std::array<int, 2>> {\n    {1, 4},\n\
    \    {2, 5},\n    {3, 6},\n  });\n\n  assert_that(tools::transposed(std::vector<std::array<int,\
    \ 0>> {\n  }) == std::array<std::vector<int>, 0> {{\n  }});\n  assert_that(tools::transposed(std::vector<std::array<int,\
    \ 3>> {\n  }) == std::array<std::vector<int>, 3> {{\n    {},\n    {},\n    {},\n\
    \  }});\n  assert_that(tools::transposed(std::vector<std::array<int, 0>> {\n \
    \   {},\n    {},\n  }) == std::array<std::vector<int>, 0> {{\n  }});\n  assert_that(tools::transposed(std::vector<std::array<int,\
    \ 3>> {\n    {1, 2, 3},\n    {4, 5, 6},\n  }) == std::array<std::vector<int>,\
    \ 3> {{\n    {1, 4},\n    {2, 5},\n    {3, 6},\n  }});\n\n  assert_that(tools::transposed(std::array<std::array<int,\
    \ 0>, 0> {{\n  }}) == std::array<std::array<int, 0>, 0> {{\n  }});\n  assert_that(tools::transposed(std::array<std::array<int,\
    \ 3>, 0> {{\n  }}) == std::array<std::array<int, 0>, 3> {{\n    {},\n    {},\n\
    \    {},\n  }});\n  assert_that(tools::transposed(std::array<std::array<int, 0>,\
    \ 2> {{\n    {},\n    {},\n  }}) == std::array<std::array<int, 2>, 0> {{\n  }});\n\
    \  assert_that(tools::transposed(std::array<std::array<int, 3>, 2> {{\n    {1,\
    \ 2, 3},\n    {4, 5, 6},\n  }}) == std::array<std::array<int, 2>, 3> {{\n    {1,\
    \ 4},\n    {2, 5},\n    {3, 6},\n  }});\n\n  std::cout << \"Hello World\" << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/transposed.hpp
  isVerificationFile: true
  path: tests/transposed.test.cpp
  requiredBy: []
  timestamp: '2024-11-22 17:09:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/transposed.test.cpp
layout: document
redirect_from:
- /verify/tests/transposed.test.cpp
- /verify/tests/transposed.test.cpp.html
title: tests/transposed.test.cpp
---
