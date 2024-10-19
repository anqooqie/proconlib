---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/manacher.hpp
    title: Manacher
  - icon: ':heavy_check_mark:'
    path: tools/mex.hpp
    title: Minimum excluded value
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2934
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2934
  bundledCode: "#line 1 \"tests/manacher.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2934\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n#include <utility>\n\
    #include <iterator>\n#include <cstdlib>\n#line 1 \"lib/ac-library/atcoder/string.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#line 9\
    \ \"lib/ac-library/atcoder/string.hpp\"\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\nstd::vector<int> sa_naive(const std::vector<int>& s) {\n    int n = int(s.size());\n\
    \    std::vector<int> sa(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    std::sort(sa.begin(),\
    \ sa.end(), [&](int l, int r) {\n        if (l == r) return false;\n        while\
    \ (l < n && r < n) {\n            if (s[l] != s[r]) return s[l] < s[r];\n    \
    \        l++;\n            r++;\n        }\n        return l == n;\n    });\n\
    \    return sa;\n}\n\nstd::vector<int> sa_doubling(const std::vector<int>& s)\
    \ {\n    int n = int(s.size());\n    std::vector<int> sa(n), rnk = s, tmp(n);\n\
    \    std::iota(sa.begin(), sa.end(), 0);\n    for (int k = 1; k < n; k *= 2) {\n\
    \        auto cmp = [&](int x, int y) {\n            if (rnk[x] != rnk[y]) return\
    \ rnk[x] < rnk[y];\n            int rx = x + k < n ? rnk[x + k] : -1;\n      \
    \      int ry = y + k < n ? rnk[y + k] : -1;\n            return rx < ry;\n  \
    \      };\n        std::sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] =\
    \ 0;\n        for (int i = 1; i < n; i++) {\n            tmp[sa[i]] = tmp[sa[i\
    \ - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        std::swap(tmp,\
    \ rnk);\n    }\n    return sa;\n}\n\n// SA-IS, linear-time suffix array construction\n\
    // Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n// Two Efficient Algorithms\
    \ for Linear Time Suffix Array Construction\ntemplate <int THRESHOLD_NAIVE = 10,\
    \ int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\n    int n = int(s.size());\n    if (n == 0) return {};\n  \
    \  if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0] < s[1]) {\n  \
    \          return {0, 1};\n        } else {\n            return {1, 0};\n    \
    \    }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n \
    \   }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n   \
    \ }\n\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
    \ i = n - 2; i >= 0; i--) {\n        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] :\
    \ (s[i] < s[i + 1]);\n    }\n    std::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i]) {\n          \
    \  sum_s[s[i]]++;\n        } else {\n            sum_l[s[i] + 1]++;\n        }\n\
    \    }\n    for (int i = 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n\
    \        if (i < upper) sum_l[i + 1] += sum_s[i];\n    }\n\n    auto induce =\
    \ [&](const std::vector<int>& lms) {\n        std::fill(sa.begin(), sa.end(),\
    \ -1);\n        std::vector<int> buf(upper + 1);\n        std::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (auto d : lms) {\n            if (d\
    \ == n) continue;\n            sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int v = sa[i];\n            if (v >=\
    \ 1 && !ls[v - 1]) {\n                sa[buf[s[v - 1]]++] = v - 1;\n         \
    \   }\n        }\n        std::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int v = sa[i];\n    \
    \        if (v >= 1 && ls[v - 1]) {\n                sa[--buf[s[v - 1] + 1]] =\
    \ v - 1;\n            }\n        }\n    };\n\n    std::vector<int> lms_map(n +\
    \ 1, -1);\n    int m = 0;\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms_map[i] = m++;\n        }\n    }\n    std::vector<int>\
    \ lms;\n    lms.reserve(m);\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms.push_back(i);\n        }\n    }\n\n    induce(lms);\n\
    \n    if (m) {\n        std::vector<int> sorted_lms;\n        sorted_lms.reserve(m);\n\
    \        for (int v : sa) {\n            if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \        }\n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n \
    \       rec_s[lms_map[sorted_lms[0]]] = 0;\n        for (int i = 1; i < m; i++)\
    \ {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n            int\
    \ end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n            int end_r\
    \ = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n            bool same = true;\n\
    \            if (end_l - l != end_r - r) {\n                same = false;\n  \
    \          } else {\n                while (l < end_l) {\n                   \
    \ if (s[l] != s[r]) {\n                        break;\n                    }\n\
    \                    l++;\n                    r++;\n                }\n     \
    \           if (l == n || s[l] != s[r]) same = false;\n            }\n       \
    \     if (!same) rec_upper++;\n            rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n\
    \        }\n\n        auto rec_sa =\n            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n        for (int i = 0; i < m; i++) {\n            sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        }\n        induce(sorted_lms);\n    }\n    return\
    \ sa;\n}\n\n}  // namespace internal\n\nstd::vector<int> suffix_array(const std::vector<int>&\
    \ s, int upper) {\n    assert(0 <= upper);\n    for (int d : s) {\n        assert(0\
    \ <= d && d <= upper);\n    }\n    auto sa = internal::sa_is(s, upper);\n    return\
    \ sa;\n}\n\ntemplate <class T> std::vector<int> suffix_array(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    std::vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int l, int r) { return\
    \ s[l] < s[r]; });\n    std::vector<int> s2(n);\n    int now = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) now++;\n\
    \        s2[idx[i]] = now;\n    }\n    return internal::sa_is(s2, now);\n}\n\n\
    std::vector<int> suffix_array(const std::string& s) {\n    int n = int(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i]\
    \ = s[i];\n    }\n    return internal::sa_is(s2, 255);\n}\n\n// Reference:\n//\
    \ T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,\n// Linear-Time Longest-Common-Prefix\
    \ Computation in Suffix Arrays and Its\n// Applications\ntemplate <class T>\n\
    std::vector<int> lcp_array(const std::vector<T>& s,\n                        \
    \   const std::vector<int>& sa) {\n    int n = int(s.size());\n    assert(n >=\
    \ 1);\n    std::vector<int> rnk(n);\n    for (int i = 0; i < n; i++) {\n     \
    \   rnk[sa[i]] = i;\n    }\n    std::vector<int> lcp(n - 1);\n    int h = 0;\n\
    \    for (int i = 0; i < n; i++) {\n        if (h > 0) h--;\n        if (rnk[i]\
    \ == 0) continue;\n        int j = sa[rnk[i] - 1];\n        for (; j + h < n &&\
    \ i + h < n; h++) {\n            if (s[j + h] != s[i + h]) break;\n        }\n\
    \        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n}\n\nstd::vector<int> lcp_array(const\
    \ std::string& s, const std::vector<int>& sa) {\n    int n = int(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i]\
    \ = s[i];\n    }\n    return lcp_array(s2, sa);\n}\n\n// Reference:\n// D. Gusfield,\n\
    // Algorithms on Strings, Trees, and Sequences: Computer Science and\n// Computational\
    \ Biology\ntemplate <class T> std::vector<int> z_algorithm(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    if (n == 0) return {};\n    std::vector<int>\
    \ z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i\
    \ + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/manacher.hpp\"\n\n\n\n#line\
    \ 6 \"tools/manacher.hpp\"\n#include <cstddef>\n#line 1 \"tools/mex.hpp\"\n\n\n\
    \n#include <type_traits>\n#line 10 \"tools/mex.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename InputIterator>\n  ::std::decay_t<decltype(*::std::declval<InputIterator>())>\
    \ mex(InputIterator begin, InputIterator end) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const ::std::size_t n = orig.size();\n\
    \n    assert(::std::all_of(orig.begin(), orig.end(), [](const auto& o) { return\
    \ o >= 0; }));\n\n    ::std::vector<bool> exists(n, false);\n    for (const ::std::size_t\
    \ o : orig) {\n      if (o < n) {\n        exists[o] = true;\n      }\n    }\n\
    \    for (::std::size_t i = 0; i < n; ++i) {\n      if (!exists[i]) {\n      \
    \  return i;\n      }\n    }\n    return n;\n  }\n}\n\n\n#line 10 \"tools/manacher.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void manacher(const InputIterator begin, const InputIterator end, const OutputIterator\
    \ result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> S(begin, end);\n    const auto N = S.size();\n    {\n  \
    \    ::std::vector<T> new_S(2 * N + 1, ::tools::mex(S.begin(), S.end()));\n  \
    \    for (::std::size_t i = 0; i < N; ++i) {\n        new_S[2 * i + 1] = S[i];\n\
    \      }\n      S = ::std::move(new_S);\n    }\n\n    ::std::vector<::std::size_t>\
    \ R(S.size());\n    {\n      ::std::size_t i = 0;\n      ::std::size_t j = 0;\n\
    \      while (i < S.size()) {\n        for (; i >= j && i + j < S.size() && S[i\
    \ - j] == S[i + j]; ++j);\n        R[i] = j;\n        ::std::size_t k;\n     \
    \   for (k = 1; i >= k && k + R[i - k] < j; ++k) {\n          R[i + k] = R[i -\
    \ k];\n        }\n        i += k;\n        j -= k;\n      }\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> new_R(S.size());\n    for (::std::size_t i = 0; i <= N; ++i)\
    \ {\n      new_R[i * 2] = ::std::make_pair(i - (R[i * 2] - 1) / 2, i + (R[i *\
    \ 2] - 1) / 2);\n    }\n    for (::std::size_t i = 0; i < N; ++i) {\n      new_R[i\
    \ * 2 + 1] = ::std::make_pair(i - (R[i * 2 + 1] / 2 - 1), i + R[i * 2 + 1] / 2);\n\
    \    }\n    ::std::move(new_R.begin(), new_R.end(), result);\n  }\n}\n\n\n#line\
    \ 11 \"tests/manacher.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n \
    \ std::ios_base::sync_with_stdio(false);\n\n  int N;\n  std::string T;\n  std::cin\
    \ >> N >> T;\n\n  std::vector<std::pair<int, int>> R;\n  tools::manacher(T.begin(),\
    \ T.end(), std::back_inserter(R));\n  const auto Z = atcoder::z_algorithm(T);\n\
    \n  std::cout << [&]() {\n    for (int i = 1; i < N; ++i) {\n      if (R[i * 2\
    \ + 1].first == 0 && [&]() {\n        for (int j = 0; j < N; j += R[i * 2 + 1].second\
    \ - R[i * 2 + 1].first - 1) {\n          if (Z[j] < N - j) {\n            return\
    \ false;\n          }\n        }\n        return true;\n      }()) {\n       \
    \ return (R[i * 2 + 1].second - R[i * 2 + 1].first + 1) / 2;\n      }\n    }\n\
    \    for (int i = 0; i < N; ++i) {\n      if (R[i * 2 + 1].second == N) {\n  \
    \      return (N + R[i * 2 + 1].first + 1) / 2;\n      }\n    }\n    std::exit(EXIT_FAILURE);\n\
    \  }() << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2934\"\n\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n#include <utility>\n#include\
    \ <iterator>\n#include <cstdlib>\n#include \"atcoder/string.hpp\"\n#include \"\
    tools/manacher.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N;\n  std::string T;\n  std::cin >> N >> T;\n\n  std::vector<std::pair<int,\
    \ int>> R;\n  tools::manacher(T.begin(), T.end(), std::back_inserter(R));\n  const\
    \ auto Z = atcoder::z_algorithm(T);\n\n  std::cout << [&]() {\n    for (int i\
    \ = 1; i < N; ++i) {\n      if (R[i * 2 + 1].first == 0 && [&]() {\n        for\
    \ (int j = 0; j < N; j += R[i * 2 + 1].second - R[i * 2 + 1].first - 1) {\n  \
    \        if (Z[j] < N - j) {\n            return false;\n          }\n       \
    \ }\n        return true;\n      }()) {\n        return (R[i * 2 + 1].second -\
    \ R[i * 2 + 1].first + 1) / 2;\n      }\n    }\n    for (int i = 0; i < N; ++i)\
    \ {\n      if (R[i * 2 + 1].second == N) {\n        return (N + R[i * 2 + 1].first\
    \ + 1) / 2;\n      }\n    }\n    std::exit(EXIT_FAILURE);\n  }() << '\\n';\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/manacher.hpp
  - tools/mex.hpp
  isVerificationFile: true
  path: tests/manacher.test.cpp
  requiredBy: []
  timestamp: '2024-10-20 00:08:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/manacher.test.cpp
layout: document
redirect_from:
- /verify/tests/manacher.test.cpp
- /verify/tests/manacher.test.cpp.html
title: tests/manacher.test.cpp
---
