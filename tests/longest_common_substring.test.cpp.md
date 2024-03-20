---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/longest_common_substring.hpp
    title: Longest common substring
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_common_substring
    links:
    - https://judge.yosupo.jp/problem/longest_common_substring
  bundledCode: "#line 1 \"tests/longest_common_substring.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/longest_common_substring\"\n\n#include <iostream>\n\
    #include <string>\n#line 1 \"tools/longest_common_substring.hpp\"\n\n\n\n#include\
    \ <tuple>\n#include <cstddef>\n#include <type_traits>\n#line 8 \"tools/longest_common_substring.hpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <iterator>\n#line 1 \"lib/ac-library/atcoder/string.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/string.hpp\"\n#include <cassert>\n#include\
    \ <numeric>\n#line 9 \"lib/ac-library/atcoder/string.hpp\"\n\nnamespace atcoder\
    \ {\n\nnamespace internal {\n\nstd::vector<int> sa_naive(const std::vector<int>&\
    \ s) {\n    int n = int(s.size());\n    std::vector<int> sa(n);\n    std::iota(sa.begin(),\
    \ sa.end(), 0);\n    std::sort(sa.begin(), sa.end(), [&](int l, int r) {\n   \
    \     if (l == r) return false;\n        while (l < n && r < n) {\n          \
    \  if (s[l] != s[r]) return s[l] < s[r];\n            l++;\n            r++;\n\
    \        }\n        return l == n;\n    });\n    return sa;\n}\n\nstd::vector<int>\
    \ sa_doubling(const std::vector<int>& s) {\n    int n = int(s.size());\n    std::vector<int>\
    \ sa(n), rnk = s, tmp(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    for (int\
    \ k = 1; k < n; k *= 2) {\n        auto cmp = [&](int x, int y) {\n          \
    \  if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];\n            int rx = x + k <\
    \ n ? rnk[x + k] : -1;\n            int ry = y + k < n ? rnk[y + k] : -1;\n  \
    \          return rx < ry;\n        };\n        std::sort(sa.begin(), sa.end(),\
    \ cmp);\n        tmp[sa[0]] = 0;\n        for (int i = 1; i < n; i++) {\n    \
    \        tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n    \
    \    }\n        std::swap(tmp, rnk);\n    }\n    return sa;\n}\n\n// SA-IS, linear-time\
    \ suffix array construction\n// Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n\
    // Two Efficient Algorithms for Linear Time Suffix Array Construction\ntemplate\
    \ <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const\
    \ std::vector<int>& s, int upper) {\n    int n = int(s.size());\n    if (n ==\
    \ 0) return {};\n    if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0]\
    \ < s[1]) {\n            return {0, 1};\n        } else {\n            return\
    \ {1, 0};\n        }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n\
    \    }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n  \
    \  }\n\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
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
    }\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/mex.hpp\"\n\n\n\n#line 5 \"\
    tools/mex.hpp\"\n#include <utility>\n#line 10 \"tools/mex.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename InputIterator>\n  ::std::decay_t<decltype(*::std::declval<InputIterator>())>\
    \ mex(InputIterator begin, InputIterator end) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const ::std::size_t n = orig.size();\n\
    \n    assert(::std::all_of(orig.begin(), orig.end(), [](const auto& o) { return\
    \ o >= 0; }));\n\n    ::std::vector<bool> exists(n, false);\n    for (const ::std::size_t\
    \ o : orig) {\n      if (o < n) {\n        exists[o] = true;\n      }\n    }\n\
    \    for (::std::size_t i = 0; i < n; ++i) {\n      if (!exists[i]) {\n      \
    \  return i;\n      }\n    }\n    return n;\n  }\n}\n\n\n#line 1 \"tools/chmax.hpp\"\
    \n\n\n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\
    \nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 5 \"tools/chmax.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmax(M& lhs, const N&\
    \ rhs) {\n    const bool updated = ::tools::cmp_less(lhs, rhs);\n    if (updated)\
    \ lhs = rhs;\n    return updated;\n  }\n}\n\n\n#line 14 \"tools/longest_common_substring.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator>\n  ::std::tuple<::std::size_t,\
    \ ::std::size_t, ::std::size_t, ::std::size_t> longest_common_substring(const\
    \ InputIterator S_begin, const InputIterator S_end, const InputIterator T_begin,\
    \ const InputIterator T_end) {\n    using Z = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    using Container = ::std::conditional_t<::std::is_same_v<Z, char>, ::std::string,\
    \ ::std::vector<Z>>;\n\n    Container ST(S_begin, S_end);\n    const int N = ST.size();\n\
    \    ::std::copy(T_begin, T_end, ::std::back_inserter(ST));\n    const int M =\
    \ ST.size() - N;\n\n    ST.push_back(::tools::mex(ST.begin(), ST.end()));\n  \
    \  ::std::rotate(::std::next(ST.begin(), N), ::std::prev(ST.end()), ST.end());\n\
    \n    const auto sa = ::atcoder::suffix_array(ST);\n    const auto lcpa = ::atcoder::lcp_array(ST,\
    \ sa);\n\n    int a = 0;\n    int c = 0;\n    int l = 0;\n    const auto is_in_S\
    \ = [&](const int i) { return i < N; };\n    const auto is_in_T = [&](const int\
    \ i) { return N + 1 <= i; };\n\n    for (int i = 1; i < N + M + 1; ++i) {\n  \
    \    if (is_in_S(sa[i]) && is_in_T(sa[i - 1])) {\n        if (::tools::chmax(l,\
    \ lcpa[i - 1])) {\n          a = sa[i];\n          c = sa[i - 1] - (N + 1);\n\
    \        }\n      } else if (is_in_T(sa[i]) && is_in_S(sa[i - 1])) {\n       \
    \ if (::tools::chmax(l, lcpa[i - 1])) {\n          a = sa[i - 1];\n          c\
    \ = sa[i] - (N + 1);\n        }\n      }\n    }\n\n    return ::std::make_tuple(a,\
    \ a + l, c, c + l);\n  }\n}\n\n\n#line 6 \"tests/longest_common_substring.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::string S, T;\n  std::cin >> S >> T;\n\n  const auto [a, b, c, d] = tools::longest_common_substring(S.begin(),\
    \ S.end(), T.begin(), T.end());\n  std::cout << a << ' ' << b << ' ' << c << '\
    \ ' << d << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\
    \n\n#include <iostream>\n#include <string>\n#include \"tools/longest_common_substring.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::string S, T;\n  std::cin >> S >> T;\n\n  const auto [a, b, c, d] = tools::longest_common_substring(S.begin(),\
    \ S.end(), T.begin(), T.end());\n  std::cout << a << ' ' << b << ' ' << c << '\
    \ ' << d << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/longest_common_substring.hpp
  - tools/mex.hpp
  - tools/chmax.hpp
  - tools/cmp_less.hpp
  isVerificationFile: true
  path: tests/longest_common_substring.test.cpp
  requiredBy: []
  timestamp: '2024-03-20 23:37:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/longest_common_substring.test.cpp
layout: document
redirect_from:
- /verify/tests/longest_common_substring.test.cpp
- /verify/tests/longest_common_substring.test.cpp.html
title: tests/longest_common_substring.test.cpp
---
