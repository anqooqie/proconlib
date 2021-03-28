---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/next_permutation.hpp\"\n\n\n\n#include <algorithm>\n\
    \nnamespace tools {\n\n  /**\n   * lists all permutations\n   * License: CC0\n\
    \   *\n   * Usage:\n   * ```\n   * // 9-choose-3\n   * int k = 3;\n   * do {\n\
    \   *   std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;\n\
    \   * } while(tools::next_permutation(s.begin(), std::next(s.begin(), k), s.end()));\n\
    \   * ```\n   *\n   * @author anqooqie\n   * @param <Iterator> type of iterators\n\
    \   * @param first beginning iterator\n   * @param k iterator referring end of\
    \ the target range\n   * @param last end iterator\n   * @return `true` if the\
    \ next permutation exists, `false` otherwise\n   */\n  template <typename Iterator>\n\
    \  bool next_permutation(const Iterator first, const Iterator k, const Iterator\
    \ last) {\n    ::std::reverse(k, last);\n    return ::std::next_permutation(first,\
    \ end);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_NEXT_PERMUTATION_HPP\n#define TOOLS_NEXT_PERMUTATION_HPP\n\n\
    #include <algorithm>\n\nnamespace tools {\n\n  /**\n   * lists all permutations\n\
    \   * License: CC0\n   *\n   * Usage:\n   * ```\n   * // 9-choose-3\n   * int\
    \ k = 3;\n   * do {\n   *   std::cout << std::string(s.begin(), std::next(s.begin(),\
    \ k)) << std::endl;\n   * } while(tools::next_permutation(s.begin(), std::next(s.begin(),\
    \ k), s.end()));\n   * ```\n   *\n   * @author anqooqie\n   * @param <Iterator>\
    \ type of iterators\n   * @param first beginning iterator\n   * @param k iterator\
    \ referring end of the target range\n   * @param last end iterator\n   * @return\
    \ `true` if the next permutation exists, `false` otherwise\n   */\n  template\
    \ <typename Iterator>\n  bool next_permutation(const Iterator first, const Iterator\
    \ k, const Iterator last) {\n    ::std::reverse(k, last);\n    return ::std::next_permutation(first,\
    \ end);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/next_permutation.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/next_permutation.hpp
layout: document
redirect_from:
- /library/tools/next_permutation.hpp
- /library/tools/next_permutation.hpp.html
title: tools/next_permutation.hpp
---
