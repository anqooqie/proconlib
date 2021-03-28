---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://stackoverflow.com/questions/5095407/all-combinations-of-k-elements-out-of-n/5097100#5097100
  bundledCode: "#line 1 \"tools/next_combination.hpp\"\n\n\n\n#include <algorithm>\n\
    \nnamespace tools {\n\n  /**\n   * lists all combinations\n   * License: CC BY-SA\
    \ 3.0\n   * Reference: Stack Overflow ( https://stackoverflow.com/questions/5095407/all-combinations-of-k-elements-out-of-n/5097100#5097100\
    \ )\n   *\n   * Usage:\n   * ```\n   * // 9-choose-3\n   * int k = 3;\n   * do\
    \ {\n   *   std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;\n\
    \   * } while(tools::next_combination(s.begin(), std::next(s.begin(), k), s.end()));\n\
    \   * ```\n   *\n   * @author Thomas Draper\n   * @param <Iterator> type of iterators\n\
    \   * @param first beginning iterator\n   * @param k iterator referring end of\
    \ the target range\n   * @param last end iterator\n   * @return `true` if the\
    \ next combination exists, `false` otherwise\n   */\n  template <typename Iterator>\n\
    \  bool next_combination(const Iterator first, Iterator k, const Iterator last)\
    \ {\n    if ((first == last) || (first == k) || (last == k)) return false;\n \
    \   Iterator itr1 = first;\n    Iterator itr2 = last;\n    ++itr1;\n    if (last\
    \ == itr1) return false;\n    itr1 = last;\n    --itr1;\n    itr1 = k;\n    --itr2;\n\
    \    while (first != itr1) {\n      if (*--itr1 < *itr2) {\n        Iterator j\
    \ = k;\n        while (!(*itr1 < *j)) ++j;\n        ::std::iter_swap(itr1, j);\n\
    \        ++itr1;\n        ++j;\n        itr2 = k;\n        ::std::rotate(itr1,\
    \ j, last);\n        while (last != j) {\n          ++j;\n          ++itr2;\n\
    \        }\n        ::std::rotate(k, itr2, last);\n        return true;\n    \
    \  }\n    }\n    ::std::rotate(first, k, last);\n    return false;\n  }\n}\n\n\
    \n"
  code: "#ifndef TOOLS_NEXT_COMBINATION_HPP\n#define TOOLS_NEXT_COMBINATION_HPP\n\n\
    #include <algorithm>\n\nnamespace tools {\n\n  /**\n   * lists all combinations\n\
    \   * License: CC BY-SA 3.0\n   * Reference: Stack Overflow ( https://stackoverflow.com/questions/5095407/all-combinations-of-k-elements-out-of-n/5097100#5097100\
    \ )\n   *\n   * Usage:\n   * ```\n   * // 9-choose-3\n   * int k = 3;\n   * do\
    \ {\n   *   std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;\n\
    \   * } while(tools::next_combination(s.begin(), std::next(s.begin(), k), s.end()));\n\
    \   * ```\n   *\n   * @author Thomas Draper\n   * @param <Iterator> type of iterators\n\
    \   * @param first beginning iterator\n   * @param k iterator referring end of\
    \ the target range\n   * @param last end iterator\n   * @return `true` if the\
    \ next combination exists, `false` otherwise\n   */\n  template <typename Iterator>\n\
    \  bool next_combination(const Iterator first, Iterator k, const Iterator last)\
    \ {\n    if ((first == last) || (first == k) || (last == k)) return false;\n \
    \   Iterator itr1 = first;\n    Iterator itr2 = last;\n    ++itr1;\n    if (last\
    \ == itr1) return false;\n    itr1 = last;\n    --itr1;\n    itr1 = k;\n    --itr2;\n\
    \    while (first != itr1) {\n      if (*--itr1 < *itr2) {\n        Iterator j\
    \ = k;\n        while (!(*itr1 < *j)) ++j;\n        ::std::iter_swap(itr1, j);\n\
    \        ++itr1;\n        ++j;\n        itr2 = k;\n        ::std::rotate(itr1,\
    \ j, last);\n        while (last != j) {\n          ++j;\n          ++itr2;\n\
    \        }\n        ::std::rotate(k, itr2, last);\n        return true;\n    \
    \  }\n    }\n    ::std::rotate(first, k, last);\n    return false;\n  }\n}\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/next_combination.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/next_combination.hpp
layout: document
redirect_from:
- /library/tools/next_combination.hpp
- /library/tools/next_combination.hpp.html
title: tools/next_combination.hpp
---
