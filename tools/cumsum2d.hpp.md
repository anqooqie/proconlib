---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cumsum2d.test.cpp
    title: tests/cumsum2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/cumsum2d.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <iterator>\n#include <cstddef>\n#include <utility>\n\nnamespace tools {\n\n\
    \  /**\n   * 2D cumulative sum\n   * License: CC0\n   *\n   * Usage:\n   * ```\n\
    \   * // Assume that the value on (x, y) can be obtained as a[y][x].\n   * std::vector<std::vector<int>>\
    \ a;\n   *\n   * // Builds the cumulative sum of a.\n   * const tools::cumsum2d<tools::group::plus<int>>\
    \ cumsum(a.begin(), a.end());\n   *\n   * // Queries sum of a[y][x], for x1 <=\
    \ x < x2 and y1 <= y < y2.\n   * cumsum.query(x1, y1, x2, y2);\n   * ```\n   *\n\
    \   * @author anqooqie\n   * @param <G> group\n   */\n  template <typename G>\n\
    \  class cumsum2d {\n  private:\n    using T = typename G::T;\n    ::std::vector<::std::vector<T>>\
    \ preprocessed;\n\n  public:\n    template <typename OuterIterator>\n    cumsum2d(const\
    \ OuterIterator& begin, const OuterIterator& end) :\n      preprocessed(\n   \
    \     ::std::distance(begin, end) + 1,\n        ::std::vector<T>((begin == end\
    \ ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin))) + 1, G::e())\n\
    \      )\n    {\n      const ::std::size_t height = ::std::distance(begin, end);\n\
    \      const ::std::size_t width = begin == end ? 0 : ::std::distance(::std::begin(*begin),\
    \ ::std::end(*begin));\n      using InnerIterator = decltype(::std::begin(::std::declval<typename\
    \ ::std::iterator_traits<OuterIterator>::value_type>()));\n\n      {\n       \
    \ OuterIterator it1 = begin;\n        for (::std::size_t y = 0; y < height; ++y,\
    \ ++it1) {\n          InnerIterator it2 = ::std::begin(*it1);\n          for (::std::size_t\
    \ x = 0; x < width; ++x, ++it2) {\n            this->preprocessed[y + 1][x + 1]\
    \ = G::op(this->preprocessed[y + 1][x], *it2);\n          }\n        }\n     \
    \ }\n      for (::std::size_t x = 0; x < width; ++x) {\n        for (::std::size_t\
    \ y = 0; y < height; ++y) {\n          this->preprocessed[y + 1][x + 1] = G::op(this->preprocessed[y][x\
    \ + 1], this->preprocessed[y + 1][x + 1]);\n        }\n      }\n    }\n\n    T\
    \ query(const ::std::size_t x1, const ::std::size_t y1, const ::std::size_t x2,\
    \ const ::std::size_t y2) const {\n      T tmp = G::op(this->preprocessed[y2][x2],\
    \ G::inv(this->preprocessed[y2][x1]));\n      tmp = G::op(tmp, G::inv(this->preprocessed[y1][x2]));\n\
    \      return G::op(tmp, this->preprocessed[y1][x1]);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_CUMSUM2D_HPP\n#define TOOLS_CUMSUM2D_HPP\n\n#include <vector>\n\
    #include <iterator>\n#include <cstddef>\n#include <utility>\n\nnamespace tools\
    \ {\n\n  /**\n   * 2D cumulative sum\n   * License: CC0\n   *\n   * Usage:\n \
    \  * ```\n   * // Assume that the value on (x, y) can be obtained as a[y][x].\n\
    \   * std::vector<std::vector<int>> a;\n   *\n   * // Builds the cumulative sum\
    \ of a.\n   * const tools::cumsum2d<tools::group::plus<int>> cumsum(a.begin(),\
    \ a.end());\n   *\n   * // Queries sum of a[y][x], for x1 <= x < x2 and y1 <=\
    \ y < y2.\n   * cumsum.query(x1, y1, x2, y2);\n   * ```\n   *\n   * @author anqooqie\n\
    \   * @param <G> group\n   */\n  template <typename G>\n  class cumsum2d {\n \
    \ private:\n    using T = typename G::T;\n    ::std::vector<::std::vector<T>>\
    \ preprocessed;\n\n  public:\n    template <typename OuterIterator>\n    cumsum2d(const\
    \ OuterIterator& begin, const OuterIterator& end) :\n      preprocessed(\n   \
    \     ::std::distance(begin, end) + 1,\n        ::std::vector<T>((begin == end\
    \ ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin))) + 1, G::e())\n\
    \      )\n    {\n      const ::std::size_t height = ::std::distance(begin, end);\n\
    \      const ::std::size_t width = begin == end ? 0 : ::std::distance(::std::begin(*begin),\
    \ ::std::end(*begin));\n      using InnerIterator = decltype(::std::begin(::std::declval<typename\
    \ ::std::iterator_traits<OuterIterator>::value_type>()));\n\n      {\n       \
    \ OuterIterator it1 = begin;\n        for (::std::size_t y = 0; y < height; ++y,\
    \ ++it1) {\n          InnerIterator it2 = ::std::begin(*it1);\n          for (::std::size_t\
    \ x = 0; x < width; ++x, ++it2) {\n            this->preprocessed[y + 1][x + 1]\
    \ = G::op(this->preprocessed[y + 1][x], *it2);\n          }\n        }\n     \
    \ }\n      for (::std::size_t x = 0; x < width; ++x) {\n        for (::std::size_t\
    \ y = 0; y < height; ++y) {\n          this->preprocessed[y + 1][x + 1] = G::op(this->preprocessed[y][x\
    \ + 1], this->preprocessed[y + 1][x + 1]);\n        }\n      }\n    }\n\n    T\
    \ query(const ::std::size_t x1, const ::std::size_t y1, const ::std::size_t x2,\
    \ const ::std::size_t y2) const {\n      T tmp = G::op(this->preprocessed[y2][x2],\
    \ G::inv(this->preprocessed[y2][x1]));\n      tmp = G::op(tmp, G::inv(this->preprocessed[y1][x2]));\n\
    \      return G::op(tmp, this->preprocessed[y1][x1]);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cumsum2d.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cumsum2d.test.cpp
documentation_of: tools/cumsum2d.hpp
layout: document
redirect_from:
- /library/tools/cumsum2d.hpp
- /library/tools/cumsum2d.hpp.html
title: tools/cumsum2d.hpp
---
