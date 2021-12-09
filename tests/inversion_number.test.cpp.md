---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/compress.hpp
    title: Compress values
  - icon: ':heavy_check_mark:'
    path: tools/inversion_number.hpp
    title: The number of inversions
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
  bundledCode: "#line 1 \"tests/inversion_number.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <iterator>\n#line 1 \"tools/inversion_number.hpp\"\n\n\n\n#line 6 \"\
    tools/inversion_number.hpp\"\n#include <cstddef>\n#line 1 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\n#line 1 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n\n\n\n#line 5\
    \ \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n#include <numeric>\n#include\
    \ <type_traits>\n\nnamespace atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\n\
    template <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
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
    \ atcoder\n\n\n#line 1 \"tools/compress.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <map>\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#line 6 \"tools/lower_bound.hpp\"\
    \n\nnamespace tools {\n\n  template <class ForwardIterator, class T>\n  typename\
    \ ::std::iterator_traits<ForwardIterator>::difference_type lower_bound(ForwardIterator\
    \ first, ForwardIterator last, const T& value) {\n    return ::std::distance(first,\
    \ ::std::lower_bound(first, last, value));\n  }\n}\n\n\n#line 10 \"tools/compress.hpp\"\
    \n\nnamespace tools {\n\n  template <typename InputIterator>\n  ::std::pair<\n\
    \    ::std::map<\n      typename ::std::iterator_traits<InputIterator>::value_type,\n\
    \      typename ::std::iterator_traits<InputIterator>::value_type\n    >,\n  \
    \  ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type>\n\
    \  > compress(InputIterator begin, InputIterator end) {\n    using T = typename\
    \ ::std::iterator_traits<InputIterator>::value_type;\n\n    ::std::vector<T> g(begin,\
    \ end);\n    ::std::sort(g.begin(), g.end());\n    g.erase(::std::unique(g.begin(),\
    \ g.end()), g.end());\n\n    ::std::map<T, T> f;\n    for (T i = 0; i < T(g.size());\
    \ ++i) {\n      f.emplace(g[i], i);\n    }\n\n    return ::std::make_pair(f, g);\n\
    \  }\n\n  template <typename InputIterator, typename OutputIterator>\n  void compress(InputIterator\
    \ begin, InputIterator end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n\
    \    ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n\n#line 9 \"tools/inversion_number.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename Iterator>\n  typename ::std::iterator_traits<Iterator>::value_type\
    \ inversion_number(Iterator begin, Iterator end) {\n    using T = typename ::std::iterator_traits<Iterator>::value_type;\n\
    \n    ::std::vector<T> compressed;\n    ::tools::compress(begin, end, ::std::back_inserter(compressed));\n\
    \n    if (compressed.empty()) return 0;\n\n    ::atcoder::fenwick_tree<T> fw(*::std::max_element(compressed.begin(),\
    \ compressed.end()) + 1);\n    T result = 0;\n    for (::std::size_t i = 0; i\
    \ < compressed.size(); ++i) {\n      result += i - fw.sum(0, compressed[i] + 1);\n\
    \      fw.add(compressed[i], 1);\n    }\n\n    return result;\n  }\n}\n\n\n#line\
    \ 9 \"tests/inversion_number.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n;\n  std::cin >> n;\n  std::vector<i64> a;\n  std::copy_n(std::istream_iterator<i64>(std::cin),\
    \ n, std::back_inserter(a));\n  std::cout << tools::inversion_number(a.begin(),\
    \ a.end()) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\n\
    \n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <iterator>\n#include \"tools/inversion_number.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n;\n  std::cin >> n;\n  std::vector<i64> a;\n  std::copy_n(std::istream_iterator<i64>(std::cin),\
    \ n, std::back_inserter(a));\n  std::cout << tools::inversion_number(a.begin(),\
    \ a.end()) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/inversion_number.hpp
  - tools/compress.hpp
  - tools/lower_bound.hpp
  isVerificationFile: true
  path: tests/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2021-09-25 17:17:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/tests/inversion_number.test.cpp
- /verify/tests/inversion_number.test.cpp.html
title: tests/inversion_number.test.cpp
---