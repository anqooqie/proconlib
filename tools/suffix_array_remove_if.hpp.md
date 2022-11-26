---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/suffix_array_remove_if.test.cpp
    title: tests/suffix_array_remove_if.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/suffix_array_remove_if.hpp\"\n\n\n\n#include <utility>\n\
    #include <cstddef>\n#include <cassert>\n#include <algorithm>\n\nnamespace tools\
    \ {\n  template <typename RandomAccessIterator, typename Predicate>\n  ::std::pair<RandomAccessIterator,\
    \ RandomAccessIterator> suffix_array_remove_if(\n      const RandomAccessIterator\
    \ sa,\n      const RandomAccessIterator sa_end,\n      const RandomAccessIterator\
    \ lcpa,\n      const RandomAccessIterator lcpa_end,\n      const Predicate pred\n\
    \  ) {\n    const ::std::size_t N = sa_end - sa;\n    assert(N >= 1);\n    assert(static_cast<::std::size_t>(lcpa_end\
    \ - lcpa) + 1 == N);\n\n    ::std::size_t sa_vl = 0, lcpa_vl = 0;\n    for (::std::size_t\
    \ sa_vr = 0, sa_al = 0, sa_ar = 0, lcpa_vr = 0; sa_al < N; sa_vl = sa_vr, sa_al\
    \ = sa_ar, lcpa_vl = lcpa_vr) {\n      const bool removes = pred(sa[sa_al]);\n\
    \n      for (; sa_ar < N && removes == pred(sa[sa_ar]); ++sa_vr, ++sa_ar);\n \
    \     if (sa_vl < sa_al) ::std::move(sa + sa_al, sa + sa_ar, sa + sa_vl);\n\n\
    \      const auto lcpa_al = sa_al == 0 ? 0 : sa_al - removes;\n      const auto\
    \ lcpa_ar = ::std::min(sa_ar - !removes, N - 1);\n      lcpa_vr = lcpa_vl + (lcpa_ar\
    \ - lcpa_al);\n      if (lcpa_vl < lcpa_al) ::std::move(lcpa + lcpa_al, lcpa +\
    \ lcpa_ar, lcpa + lcpa_vl);\n\n      if (removes) {\n        sa_vr = sa_vl;\n\
    \        if (0 < sa_al && sa_ar < N) {\n          lcpa[lcpa_vl] = *::std::min_element(lcpa\
    \ + lcpa_vl, lcpa + lcpa_vr);\n          lcpa_vr = lcpa_vl + 1;\n        } else\
    \ {\n          lcpa_vr = lcpa_vl;\n        }\n      }\n    }\n\n    return ::std::make_pair(sa\
    \ + sa_vl, lcpa + lcpa_vl);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SUFFIX_ARRAY_REMOVE_IF_HPP\n#define TOOLS_SUFFIX_ARRAY_REMOVE_IF_HPP\n\
    \n#include <utility>\n#include <cstddef>\n#include <cassert>\n#include <algorithm>\n\
    \nnamespace tools {\n  template <typename RandomAccessIterator, typename Predicate>\n\
    \  ::std::pair<RandomAccessIterator, RandomAccessIterator> suffix_array_remove_if(\n\
    \      const RandomAccessIterator sa,\n      const RandomAccessIterator sa_end,\n\
    \      const RandomAccessIterator lcpa,\n      const RandomAccessIterator lcpa_end,\n\
    \      const Predicate pred\n  ) {\n    const ::std::size_t N = sa_end - sa;\n\
    \    assert(N >= 1);\n    assert(static_cast<::std::size_t>(lcpa_end - lcpa) +\
    \ 1 == N);\n\n    ::std::size_t sa_vl = 0, lcpa_vl = 0;\n    for (::std::size_t\
    \ sa_vr = 0, sa_al = 0, sa_ar = 0, lcpa_vr = 0; sa_al < N; sa_vl = sa_vr, sa_al\
    \ = sa_ar, lcpa_vl = lcpa_vr) {\n      const bool removes = pred(sa[sa_al]);\n\
    \n      for (; sa_ar < N && removes == pred(sa[sa_ar]); ++sa_vr, ++sa_ar);\n \
    \     if (sa_vl < sa_al) ::std::move(sa + sa_al, sa + sa_ar, sa + sa_vl);\n\n\
    \      const auto lcpa_al = sa_al == 0 ? 0 : sa_al - removes;\n      const auto\
    \ lcpa_ar = ::std::min(sa_ar - !removes, N - 1);\n      lcpa_vr = lcpa_vl + (lcpa_ar\
    \ - lcpa_al);\n      if (lcpa_vl < lcpa_al) ::std::move(lcpa + lcpa_al, lcpa +\
    \ lcpa_ar, lcpa + lcpa_vl);\n\n      if (removes) {\n        sa_vr = sa_vl;\n\
    \        if (0 < sa_al && sa_ar < N) {\n          lcpa[lcpa_vl] = *::std::min_element(lcpa\
    \ + lcpa_vl, lcpa + lcpa_vr);\n          lcpa_vr = lcpa_vl + 1;\n        } else\
    \ {\n          lcpa_vr = lcpa_vl;\n        }\n      }\n    }\n\n    return ::std::make_pair(sa\
    \ + sa_vl, lcpa + lcpa_vl);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/suffix_array_remove_if.hpp
  requiredBy: []
  timestamp: '2022-11-26 23:39:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/suffix_array_remove_if.test.cpp
documentation_of: tools/suffix_array_remove_if.hpp
layout: document
title: std::remove_if for suffix array and LCP array
---

```cpp
template <typename RandomAccessIterator, typename Predicate>
std::pair<RandomAccessIterator, RandomAccessIterator> suffix_array_remove_if(RandomAccessIterator sa, RandomAccessIterator sa_end, RandomAccessIterator lcpa, RandomAccessIterator lcpa_end, Predicate pred);
```

Let us denote the first element of the returned pair by `sa_new_end`, and the second element by `lcpa_new_end`.
Also, let us denote `sa_end - sa` by $N$, and `sa_new_end - sa` by $N'$.

It executes `std::remove_if(sa, sa_end, pred)` and returns the return value of it as `sa_new_end`.
Also, it updates `lcpa[i]` to the length of the longest common prefix between `s[sa[i] .. N)` and `s[sa[i + 1] .. N)` for all $0 \leq i < \max(0, N' - 1)$, and returns `lcpa +` $\max(0, N' - 1)$ as `lcpa_new_end`, where $s$ is the source sequence of `sa`.

### Constraints
- $N \geq 1$
- `lcpa_end - lcpa_begin` $= N - 1$

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
