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
  bundledCode: "#line 1 \"tools/alphabetical_order.hpp\"\n\n\n\n#include <unordered_map>\n\
    \nnamespace tools {\n\n  /**\n   * gets the alphabetical order of the given character\n\
    \   * License: CC0\n   * @aurhor anqooqie\n   * @param c input\n   * @return 0\
    \ if c is 'A' or 'a', 1 if c is 'B' or 'b', ..., and 25 if c is 'Z' or 'z'\n \
    \  */\n  int alphabetical_order(const char c) {\n    static const std::unordered_map<char,\
    \ int> map({\n      {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5},\
    \ {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9},\n      {'K', 10}, {'L', 11}, {'M', 12},\
    \ {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},\n\
    \      {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25}, {'a',\
    \ 0}, {'b', 1}, {'c', 2}, {'d', 3},\n      {'e', 4}, {'f', 5}, {'g', 6}, {'h',\
    \ 7}, {'i', 8}, {'j', 9}, {'k', 10}, {'l', 11}, {'m', 12}, {'n', 13},\n      {'o',\
    \ 14}, {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19}, {'u', 20}, {'v',\
    \ 21}, {'w', 22}, {'x', 23},\n      {'y', 24}, {'z', 25}\n    });\n    return\
    \ map.at(c);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ALPHABETICAL_ORDER\n#define TOOLS_ALPHABETICAL_ORDER\n\n#include\
    \ <unordered_map>\n\nnamespace tools {\n\n  /**\n   * gets the alphabetical order\
    \ of the given character\n   * License: CC0\n   * @aurhor anqooqie\n   * @param\
    \ c input\n   * @return 0 if c is 'A' or 'a', 1 if c is 'B' or 'b', ..., and 25\
    \ if c is 'Z' or 'z'\n   */\n  int alphabetical_order(const char c) {\n    static\
    \ const std::unordered_map<char, int> map({\n      {'A', 0}, {'B', 1}, {'C', 2},\
    \ {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9},\n    \
    \  {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16},\
    \ {'R', 17}, {'S', 18}, {'T', 19},\n      {'U', 20}, {'V', 21}, {'W', 22}, {'X',\
    \ 23}, {'Y', 24}, {'Z', 25}, {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3},\n      {'e',\
    \ 4}, {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9}, {'k', 10}, {'l', 11},\
    \ {'m', 12}, {'n', 13},\n      {'o', 14}, {'p', 15}, {'q', 16}, {'r', 17}, {'s',\
    \ 18}, {'t', 19}, {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23},\n      {'y', 24},\
    \ {'z', 25}\n    });\n    return map.at(c);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/alphabetical_order.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/alphabetical_order.hpp
layout: document
redirect_from:
- /library/tools/alphabetical_order.hpp
- /library/tools/alphabetical_order.hpp.html
title: tools/alphabetical_order.hpp
---
