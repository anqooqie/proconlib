---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/wavelet_matrix.hpp
    title: Wavelet matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"tests/wavelet_matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\
    \n\n#include <iostream>\n#include <vector>\n#line 1 \"tools/wavelet_matrix.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 6 \"tools/wavelet_matrix.hpp\"\n#include <utility>\n\
    #include <tuple>\n#include <cassert>\n#include <algorithm>\n#include <iterator>\n\
    #line 1 \"tools/popcount.hpp\"\n\n\n\n#include <cstdint>\n\nnamespace tools {\n\
    \n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n    x = (x & static_cast<::std::uint32_t>(0x55555555ull))\
    \ + (x >> static_cast<::std::uint32_t>(1) & static_cast<::std::uint32_t>(0x55555555ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x33333333ull)) + (x >> static_cast<::std::uint32_t>(2)\
    \ & static_cast<::std::uint32_t>(0x33333333ull));\n    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full))\
    \ + (x >> static_cast<::std::uint32_t>(4) & static_cast<::std::uint32_t>(0x0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull)) + (x >> static_cast<::std::uint32_t>(8)\
    \ & static_cast<::std::uint32_t>(0x00ff00ffull));\n    return (x & static_cast<::std::uint32_t>(0x0000ffffull))\
    \ + (x >> static_cast<::std::uint32_t>(16) & static_cast<::std::uint32_t>(0x0000ffffull));\n\
    \  }\n\n  inline ::std::uint64_t popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 12 \"tools/wavelet_matrix.hpp\"\n\nnamespace tools {\n\n  //\
    \ Source: https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp.html\n\
    \  // License: Unlicense\n  // Author: ei1333\n\n  struct succinct_indexable_dictionary\
    \ {\n    ::std::size_t length;\n    ::std::size_t blocks;\n    ::std::vector<unsigned\
    \ int> bit, sum;\n\n    succinct_indexable_dictionary() = default;\n\n    succinct_indexable_dictionary(::std::size_t\
    \ length) : length(length), blocks((length + 31) >> 5) {\n      bit.assign(blocks,\
    \ 0U);\n      sum.assign(blocks, 0U);\n    }\n\n    void set(int k) {\n      bit[k\
    \ >> 5] |= 1U << (k & 31);\n    }\n\n    void build() {\n      sum[0] = 0U;\n\
    \      for (::std::size_t i = 1; i < blocks; ++i) {\n        sum[i] = sum[i -\
    \ 1] + ::tools::popcount(bit[i - 1]);\n      }\n    }\n\n    bool operator[](int\
    \ k) {\n      return (bool((bit[k >> 5] >> (k & 31)) & 1));\n    }\n\n    int\
    \ rank(int k) {\n      return (sum[k >> 5] + ::tools::popcount(bit[k >> 5] & ((1U\
    \ << (k & 31)) - 1)));\n    }\n\n    int rank(bool val, int k) {\n      return\
    \ (val ? rank(k) : k - rank(k));\n    }\n  };\n\n  template <typename T, int MAXLOG>\n\
    \  struct wavelet_matrix {\n    ::std::size_t length;\n    ::tools::succinct_indexable_dictionary\
    \ matrix[MAXLOG];\n    int mid[MAXLOG];\n\n    wavelet_matrix() = default;\n\n\
    \    wavelet_matrix(::std::vector<T> v) : length(v.size()) {\n      ::std::vector<T>\
    \ l(length), r(length);\n      for(int level = MAXLOG - 1; level >= 0; level--)\
    \ {\n        matrix[level] = ::tools::succinct_indexable_dictionary(length + 1);\n\
    \        int left = 0, right = 0;\n        for (::std::size_t i = 0; i < length;\
    \ ++i) {\n          if (((v[i] >> level) & 1)) {\n            matrix[level].set(i);\n\
    \            r[right++] = v[i];\n          } else {\n            l[left++] = v[i];\n\
    \          }\n        }\n        mid[level] = left;\n        matrix[level].build();\n\
    \        v.swap(l);\n        for (int i = 0; i < right; i++) {\n          v[left\
    \ + i] = r[i];\n        }\n      }\n    }\n\n    ::std::pair<int, int> succ(bool\
    \ f, int l, int r, int level) {\n      return {matrix[level].rank(f, l) + mid[level]\
    \ * f, matrix[level].rank(f, r) + mid[level] * f};\n    }\n\n    // v[k]\n   \
    \ T access(int k) {\n      T ret = 0;\n      for (int level = MAXLOG - 1; level\
    \ >= 0; level--) {\n        bool f = matrix[level][k];\n        if(f) ret |= T(1)\
    \ << level;\n        k = matrix[level].rank(f, k) + mid[level] * f;\n      }\n\
    \      return ret;\n    }\n\n    T operator[](const int &k) {\n      return access(k);\n\
    \    }\n\n    // count i s.t. (0 <= i < r) && v[i] == x\n    int rank(const T\
    \ &x, int r) {\n      int l = 0;\n      for (int level = MAXLOG - 1; level >=\
    \ 0; level--) {\n        ::std::tie(l, r) = succ((x >> level) & 1, l, r, level);\n\
    \      }\n      return r - l;\n    }\n\n    // k-th(0-indexed) smallest number\
    \ in v[l,r)\n    T kth_smallest(int l, int r, int k) {\n      assert(0 <= k &&\
    \ k < r - l);\n      T ret = 0;\n      for (int level = MAXLOG - 1; level >= 0;\
    \ level--) {\n        int cnt = matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n        bool f = cnt <= k;\n        if (f) {\n          ret |= T(1) <<\
    \ level;\n          k -= cnt;\n        }\n        ::std::tie(l, r) = succ(f, l,\
    \ r, level);\n      }\n      return ret;\n    }\n\n    // k-th(0-indexed) largest\
    \ number in v[l,r)\n    T kth_largest(int l, int r, int k) {\n      return kth_smallest(l,\
    \ r, r - l - k - 1);\n    }\n\n    // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \    int range_freq(int l, int r, T upper) {\n      int ret = 0;\n      for (int\
    \ level = MAXLOG - 1; level >= 0; level--) {\n        bool f = ((upper >> level)\
    \ & 1);\n        if (f) ret += matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n        ::std::tie(l, r) = succ(f, l, r, level);\n      }\n      return\
    \ ret;\n    }\n\n    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)\n\
    \    int range_freq(int l, int r, T lower, T upper) {\n      return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n    }\n\n    // max v[i] s.t. (l <= i\
    \ < r) && (v[i] < upper)\n    T prev_value(int l, int r, T upper) {\n      int\
    \ cnt = range_freq(l, r, upper);\n      return cnt == 0 ? T(-1) : kth_smallest(l,\
    \ r, cnt - 1);\n    }\n\n    // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \    T next_value(int l, int r, T lower) {\n      int cnt = range_freq(l, r, lower);\n\
    \      return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);\n    }\n  };\n\n\
    \  template <typename T, int MAXLOG>\n  struct compressed_wavelet_matrix {\n \
    \   ::tools::wavelet_matrix<int, MAXLOG> mat;\n    ::std::vector<T> ys;\n\n  \
    \  compressed_wavelet_matrix(const ::std::vector<T>& v) : ys(v) {\n      ::std::sort(::std::begin(ys),\
    \ ::std::end(ys));\n      ys.erase(::std::unique(::std::begin(ys), ::std::end(ys)),\
    \ ::std::end(ys));\n      ::std::vector<int> t(v.size());\n      for (::std::size_t\
    \ i = 0; i < v.size(); ++i) t[i] = get(v[i]);\n      mat = ::tools::wavelet_matrix<int,\
    \ MAXLOG>(t);\n    }\n\n    inline int get(const T& x) {\n      return lower_bound(::std::begin(ys),\
    \ ::std::end(ys), x) - ::std::begin(ys);\n    }\n\n    T access(int k) {\n   \
    \   return ys[mat.access(k)];\n    }\n\n    T operator[](const int &k) {\n   \
    \   return access(k);\n    }\n\n    int rank(const T &x, int r) {\n      auto\
    \ pos = get(x);\n      if (pos == ys.size() || ys[pos] != x) return 0;\n     \
    \ return mat.rank(pos, r);\n    }\n\n    T kth_smallest(int l, int r, int k) {\n\
    \      return ys[mat.kth_smallest(l, r, k)];\n    }\n\n    T kth_largest(int l,\
    \ int r, int k) {\n      return ys[mat.kth_largest(l, r, k)];\n    }\n\n    int\
    \ range_freq(int l, int r, T upper) {\n      return mat.range_freq(l, r, get(upper));\n\
    \    }\n\n    int range_freq(int l, int r, T lower, T upper) {\n      return mat.range_freq(l,\
    \ r, get(lower), get(upper));\n    }\n\n    T prev_value(int l, int r, T upper)\
    \ {\n      auto ret = mat.prev_value(l, r, get(upper));\n      return ret == -1\
    \ ? T(-1) : ys[ret];\n    }\n\n    T next_value(int l, int r, T lower) {\n   \
    \   auto ret = mat.next_value(l, r, get(lower));\n      return ret == -1 ? T(-1)\
    \ : ys[ret];\n    }\n  };\n}\n\n\n#line 6 \"tests/wavelet_matrix.test.cpp\"\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<int> a(N);\n  for (auto& a_i\
    \ : a) std::cin >> a_i;\n\n  // floor_log2(200000) + 1 = 18\n  tools::compressed_wavelet_matrix<int,\
    \ 18> mat(a);\n  for (int q = 0; q < Q; ++q) {\n    int l, r, k;\n    std::cin\
    \ >> l >> r >> k;\n    std::cout << mat.kth_smallest(l, r, k) << \"\\n\";\n  }\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"tools/wavelet_matrix.hpp\"\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<int> a(N);\n  for (auto& a_i\
    \ : a) std::cin >> a_i;\n\n  // floor_log2(200000) + 1 = 18\n  tools::compressed_wavelet_matrix<int,\
    \ 18> mat(a);\n  for (int q = 0; q < Q; ++q) {\n    int l, r, k;\n    std::cin\
    \ >> l >> r >> k;\n    std::cout << mat.kth_smallest(l, r, k) << \"\\n\";\n  }\n\
    \n  return 0;\n}\n"
  dependsOn:
  - tools/wavelet_matrix.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2022-05-30 14:51:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/tests/wavelet_matrix.test.cpp
- /verify/tests/wavelet_matrix.test.cpp.html
title: tests/wavelet_matrix.test.cpp
---
