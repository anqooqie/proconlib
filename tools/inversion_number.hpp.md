---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/compress.hpp
    title: Compress values
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/inversion_number.test.cpp
    title: tests/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/inversion_number.hpp\"\n\n\n\n#include <iterator>\n\
    #include <algorithm>\n#include <cstddef>\n#line 1 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\n\n\n#include <cassert>\n#include <vector>\n\n#line 1 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n#include\
    \ <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n    typename\
    \ std::conditional<std::is_same<T, __int128_t>::value ||\n                   \
    \               std::is_same<T, __int128>::value,\n                          \
    \    std::true_type,\n                              std::false_type>::type;\n\n\
    template <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"tools/compress.hpp\"\n\n\n\n#line 1 \"tools/lower_bound.hpp\"\
    \n\n\n\n#line 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template <class\
    \ ForwardIterator, class T>\n  auto lower_bound(ForwardIterator first, ForwardIterator\
    \ last, const T& value) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 8 \"tools/compress.hpp\"\n\nnamespace\
    \ tools {\n  template <typename InputIterator, typename OutputIterator>\n  void\
    \ compress(InputIterator begin, InputIterator end, OutputIterator result) {\n\
    \    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n \
    \   ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n \
    \   ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n\n#line 9 \"tools/inversion_number.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename Iterator>\n  typename ::std::iterator_traits<Iterator>::value_type\
    \ inversion_number(Iterator begin, Iterator end) {\n    using T = typename ::std::iterator_traits<Iterator>::value_type;\n\
    \n    ::std::vector<T> compressed;\n    ::tools::compress(begin, end, ::std::back_inserter(compressed));\n\
    \n    if (compressed.empty()) return 0;\n\n    ::atcoder::fenwick_tree<T> fw(*::std::max_element(compressed.begin(),\
    \ compressed.end()) + 1);\n    T result = 0;\n    for (::std::size_t i = 0; i\
    \ < compressed.size(); ++i) {\n      result += i - fw.sum(0, compressed[i] + 1);\n\
    \      fw.add(compressed[i], 1);\n    }\n\n    return result;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_INVERSION_NUMBER_HPP\n#define TOOLS_INVERSION_NUMBER_HPP\n\n\
    #include <iterator>\n#include <algorithm>\n#include <cstddef>\n#include \"atcoder/fenwicktree.hpp\"\
    \n#include \"tools/compress.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ Iterator>\n  typename ::std::iterator_traits<Iterator>::value_type inversion_number(Iterator\
    \ begin, Iterator end) {\n    using T = typename ::std::iterator_traits<Iterator>::value_type;\n\
    \n    ::std::vector<T> compressed;\n    ::tools::compress(begin, end, ::std::back_inserter(compressed));\n\
    \n    if (compressed.empty()) return 0;\n\n    ::atcoder::fenwick_tree<T> fw(*::std::max_element(compressed.begin(),\
    \ compressed.end()) + 1);\n    T result = 0;\n    for (::std::size_t i = 0; i\
    \ < compressed.size(); ++i) {\n      result += i - fw.sum(0, compressed[i] + 1);\n\
    \      fw.add(compressed[i], 1);\n    }\n\n    return result;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/compress.hpp
  - tools/lower_bound.hpp
  isVerificationFile: false
  path: tools/inversion_number.hpp
  requiredBy: []
  timestamp: '2023-06-28 13:29:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/inversion_number.test.cpp
documentation_of: tools/inversion_number.hpp
layout: document
title: The number of inversions
---

```cpp
template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type inversion_number(Iterator begin, Iterator end);
```

It returns the number of inversions of a given integer sequence $(a_0, a_1, \ldots, a_{N - 1})$.

### Constraints
- None

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
