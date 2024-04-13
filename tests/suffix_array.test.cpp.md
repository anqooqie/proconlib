---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_equal.hpp
    title: Polyfill of std::cmp_equal
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/suffix_array.hpp
    title: Wrapper of atcoder::suffix_array and atcoder::lcp_array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc272/tasks/abc272_f
    links:
    - https://atcoder.jp/contests/abc272/tasks/abc272_f
  bundledCode: "#line 1 \"tests/suffix_array.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc272/tasks/abc272_f\"\
    \n\n#include <iostream>\n#include <string>\n#line 1 \"tools/suffix_array.hpp\"\
    \n\n\n\n#include <vector>\n#include <utility>\n#include <type_traits>\n#line 8\
    \ \"tools/suffix_array.hpp\"\n#include <cstddef>\n#include <limits>\n#include\
    \ <algorithm>\n#include <iterator>\n#include <initializer_list>\n#line 1 \"lib/ac-library/atcoder/string.hpp\"\
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
    }\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 1 \"\
    tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const T t,\
    \ const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 6 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated\
    \ = rhs < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 1 \"tools/chmax.hpp\"\n\n\n\n#line 6 \"tools/chmax.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmax(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(lhs, rhs);\n    } else {\n      updated\
    \ = lhs < rhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 1 \"tools/cmp_equal.hpp\"\n\n\n\n#line 5 \"tools/cmp_equal.hpp\"\n\
    \nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_equal(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t == u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? false : UT(t) == u;\n    } else {\n      return u <\
    \ 0 ? false : t == UU(u);\n    }\n  }\n}\n\n\n#line 17 \"tools/suffix_array.hpp\"\
    \n\nnamespace tools {\n\n  class suffix_array {\n  public:\n    ::std::vector<::std::pair<int,\
    \ int>> sa;\n    ::std::vector<int> lcpa;\n\n    suffix_array() = default;\n \
    \   template <typename InputIterator>\n    suffix_array(const InputIterator begin,\
    \ const InputIterator end) {\n      using Container = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \      static_assert(\n        ::std::is_same_v<Container, ::std::string> ||\n\
    \        ::std::is_same_v<Container, ::std::vector<int>> ||\n        ::std::is_same_v<Container,\
    \ ::std::vector<unsigned int>> ||\n        ::std::is_same_v<Container, ::std::vector<long\
    \ long>> ||\n        ::std::is_same_v<Container, ::std::vector<unsigned long long>>\n\
    \      );\n\n      if (begin == end) return;\n\n      ::std::vector<Container>\
    \ orig(begin, end);\n\n      ::std::vector<::std::size_t> offsets(orig.size());\n\
    \      offsets[0] = 0;\n      for (::std::size_t i = 1; i < orig.size(); ++i)\
    \ {\n        offsets[i] = offsets[i - 1] + orig[i - 1].size() + 1;\n      }\n\n\
    \      ::std::vector<int> concat;\n      concat.reserve(offsets.back() + orig.back().size()\
    \ + 1);\n      int upper;\n      if constexpr (::std::is_same_v<Container, ::std::string>)\
    \ {\n        int lower = ::std::numeric_limits<int>::max();\n        upper = ::std::numeric_limits<int>::min();\n\
    \        for (const auto& s : orig) {\n          for (const auto s_i : s) {\n\
    \            ::tools::chmin(lower, s_i);\n            ::tools::chmax(upper, s_i);\n\
    \          }\n        }\n\n        for (const auto& s : orig) {\n          for\
    \ (const auto s_i : s) {\n            concat.push_back(s_i + (lower == 0));\n\
    \          }\n          concat.push_back(0);\n        }\n        if (lower ==\
    \ 0) ++upper;\n      } else {\n        Container compress;\n        compress.reserve(concat.size()\
    \ - orig.size());\n        for (const auto& s : orig) {\n          ::std::copy(s.begin(),\
    \ s.end(), ::std::back_inserter(compress));\n        }\n        ::std::sort(compress.begin(),\
    \ compress.end());\n        compress.erase(::std::unique(compress.begin(), compress.end()),\
    \ compress.end());\n\n        for (const auto& s : orig) {\n          for (const\
    \ auto s_i : s) {\n            concat.push_back(::std::distance(compress.begin(),\
    \ ::std::lower_bound(compress.begin(), compress.end(), s_i)) + 1);\n         \
    \ }\n          concat.push_back(0);\n        }\n\n        upper = compress.size();\n\
    \      }\n\n      ::std::vector<::std::size_t> belongs;\n      belongs.reserve(concat.size());\n\
    \      for (::std::size_t i = 0; i < orig.size(); ++i) {\n        for (::std::size_t\
    \ j = 0; j <= orig[i].size(); ++j) {\n          belongs.push_back(i);\n      \
    \  }\n      }\n\n      const auto concat_sa = ::atcoder::suffix_array(concat,\
    \ upper);\n      this->lcpa = ::atcoder::lcp_array(concat, concat_sa);\n     \
    \ this->sa.reserve(concat_sa.size());\n      for (const auto ij : concat_sa) {\n\
    \        const int i = belongs[ij];\n        const int j = ij - offsets[i];\n\
    \        this->sa.emplace_back(i, j);\n      }\n\n      for (::std::size_t i =\
    \ 0; i < this->lcpa.size(); ++i) {\n        ::tools::chmin(this->lcpa[i], orig[this->sa[i].first].size()\
    \ - this->sa[i].second);\n        ::tools::chmin(this->lcpa[i], orig[this->sa[i\
    \ + 1].first].size() - this->sa[i + 1].second);\n      }\n\n      this->erase_if([&](const\
    \ int i, const int j) {\n        return ::tools::cmp_equal(j, orig[i].size());\n\
    \      });\n    }\n    template <typename Container>\n    suffix_array(const ::std::initializer_list<Container>\
    \ il) : suffix_array(il.begin(), il.end()) {\n    }\n\n    template <typename\
    \ Predicate>\n    ::std::size_t erase_if(const Predicate pred) {\n      if (this->sa.empty())\
    \ return 0;\n\n      const auto N = this->sa.size();\n      ::std::size_t erased\
    \ = 0;\n\n      ::std::size_t sa_vl = 0, lcpa_vl = 0;\n      for (::std::size_t\
    \ sa_vr = 0, sa_al = 0, sa_ar = 0, lcpa_vr = 0; sa_al < N; sa_vl = sa_vr, sa_al\
    \ = sa_ar, lcpa_vl = lcpa_vr) {\n        const bool removes = pred(this->sa[sa_al].first,\
    \ this->sa[sa_al].second);\n\n        for (; sa_ar < N && removes == pred(this->sa[sa_ar].first,\
    \ this->sa[sa_ar].second); ++sa_vr, ++sa_ar);\n        if (sa_vl < sa_al) ::std::move(this->sa.begin()\
    \ + sa_al, this->sa.begin() + sa_ar, this->sa.begin() + sa_vl);\n\n        const\
    \ auto lcpa_al = sa_al == 0 ? 0 : sa_al - removes;\n        const auto lcpa_ar\
    \ = ::std::min(sa_ar - !removes, N - 1);\n        lcpa_vr = lcpa_vl + (lcpa_ar\
    \ - lcpa_al);\n        if (lcpa_vl < lcpa_al) ::std::move(this->lcpa.begin() +\
    \ lcpa_al, this->lcpa.begin() + lcpa_ar, this->lcpa.begin() + lcpa_vl);\n\n  \
    \      if (removes) {\n          erased += sa_vr - sa_vl;\n          sa_vr = sa_vl;\n\
    \          if (0 < sa_al && sa_ar < N) {\n            this->lcpa[lcpa_vl] = *::std::min_element(this->lcpa.begin()\
    \ + lcpa_vl, this->lcpa.begin() + lcpa_vr);\n            lcpa_vr = lcpa_vl + 1;\n\
    \          } else {\n            lcpa_vr = lcpa_vl;\n          }\n        }\n\
    \      }\n\n      this->sa.erase(this->sa.begin() + sa_vl, this->sa.end());\n\
    \      this->lcpa.erase(this->lcpa.begin() + lcpa_vl, this->lcpa.end());\n\n \
    \     return erased;\n    }\n  };\n}\n\n\n#line 7 \"tests/suffix_array.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::string S, T;\n  std::cin >> N >> S >> T;\n\n  tools::suffix_array\
    \ SSTT{S + S, T + T};\n  SSTT.erase_if([&](const auto, const auto j) {\n    return\
    \ N <= j;\n  });\n  for (auto& lcpa_i : SSTT.lcpa) {\n    tools::chmin(lcpa_i,\
    \ N);\n  }\n\n  ll answer = 0;\n  ll partial_answer = 0;\n  for (ll l = 0, r =\
    \ 0; l < 2 * N; l = r) {\n    for (++r; r < 2 * N && SSTT.lcpa[r - 1] == N; ++r);\n\
    \    for (ll i = l; i < r; ++i) {\n      if (SSTT.sa[i].first == 0) ++partial_answer;\n\
    \    }\n    for (ll i = l; i < r; ++i) {\n      if (SSTT.sa[i].first == 1) answer\
    \ += partial_answer;\n    }\n  }\n\n  std::cout << answer << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc272/tasks/abc272_f\"\n\n\
    #include <iostream>\n#include <string>\n#include \"tools/suffix_array.hpp\"\n\
    #include \"tools/chmin.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll N;\n  std::string S, T;\n  std::cin\
    \ >> N >> S >> T;\n\n  tools::suffix_array SSTT{S + S, T + T};\n  SSTT.erase_if([&](const\
    \ auto, const auto j) {\n    return N <= j;\n  });\n  for (auto& lcpa_i : SSTT.lcpa)\
    \ {\n    tools::chmin(lcpa_i, N);\n  }\n\n  ll answer = 0;\n  ll partial_answer\
    \ = 0;\n  for (ll l = 0, r = 0; l < 2 * N; l = r) {\n    for (++r; r < 2 * N &&\
    \ SSTT.lcpa[r - 1] == N; ++r);\n    for (ll i = l; i < r; ++i) {\n      if (SSTT.sa[i].first\
    \ == 0) ++partial_answer;\n    }\n    for (ll i = l; i < r; ++i) {\n      if (SSTT.sa[i].first\
    \ == 1) answer += partial_answer;\n    }\n  }\n\n  std::cout << answer << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - tools/suffix_array.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/chmax.hpp
  - tools/cmp_equal.hpp
  isVerificationFile: true
  path: tests/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-03-24 19:16:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/tests/suffix_array.test.cpp
- /verify/tests/suffix_array.test.cpp.html
title: tests/suffix_array.test.cpp
---
