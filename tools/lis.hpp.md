---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/compress.hpp
    title: Compress values
  - icon: ':x:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/lis.test.cpp
    title: tests/lis.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/lis.hpp\"\n\n\n\n#include <iterator>\n#include <vector>\n\
    #include <algorithm>\n#line 1 \"lib/ac-library/atcoder/segtree.hpp\"\n\n\n\n#line\
    \ 5 \"lib/ac-library/atcoder/segtree.hpp\"\n#include <cassert>\n#line 7 \"lib/ac-library/atcoder/segtree.hpp\"\
    \n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint\
    \ ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n)\
    \ {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n//\
    \ @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x))\
    \ != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9\
    \ \"lib/ac-library/atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n    segtree() : segtree(0)\
    \ {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n      \
    \  for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p +\
    \ size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r ==\
    \ 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n      \
    \      r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line 5 \"tools/monoid.hpp\"\
    \n#include <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid\
    \ {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
    \    struct max {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::max()>\n    struct min {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::min(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type>\n    struct multiplies {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs * rhs;\n  \
    \    }\n      static T e() {\n        return T(1);\n      }\n    };\n\n    template\
    \ <typename Type>\n    struct gcd {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::gcd(lhs, rhs);\n      }\n     \
    \ static T e() {\n        return T(0);\n      }\n    };\n\n    template <typename\
    \ Type, Type E>\n    struct update {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n      }\n     \
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/compress.hpp\"\
    \n\n\n\n#include <utility>\n#include <map>\n#line 1 \"tools/lower_bound.hpp\"\n\
    \n\n\n#line 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template <class\
    \ ForwardIterator, class T>\n  auto lower_bound(ForwardIterator first, ForwardIterator\
    \ last, const T& value) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 10 \"tools/compress.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename InputIterator>\n  ::std::pair<\n    ::std::map<\n\
    \      typename ::std::iterator_traits<InputIterator>::value_type,\n      typename\
    \ ::std::iterator_traits<InputIterator>::value_type\n    >,\n    ::std::vector<typename\
    \ ::std::iterator_traits<InputIterator>::value_type>\n  > compress(InputIterator\
    \ begin, InputIterator end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \n    ::std::vector<T> g(begin, end);\n    ::std::sort(g.begin(), g.end());\n\
    \    g.erase(::std::unique(g.begin(), g.end()), g.end());\n\n    ::std::map<T,\
    \ T> f;\n    for (T i = 0; i < T(g.size()); ++i) {\n      f.emplace(g[i], i);\n\
    \    }\n\n    return ::std::make_pair(f, g);\n  }\n\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void compress(InputIterator begin, InputIterator\
    \ end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n\
    \    ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n\n#line 10 \"tools/lis.hpp\"\n\nnamespace tools {\n\
    \  template <typename InputIterator>\n  long long lis(const InputIterator& begin,\
    \ const InputIterator& end, const bool strict) {\n    using M = ::tools::monoid::max<long\
    \ long, 0>;\n\n    ::std::vector<long long> compressed;\n    ::tools::compress(begin,\
    \ end, ::std::back_inserter(compressed));\n\n    ::atcoder::segtree<long long,\
    \ M::op, M::e> segtree(compressed.empty() ? 0 : *::std::max_element(compressed.begin(),\
    \ compressed.end()) + 1);\n    for (const auto c : compressed) {\n      segtree.set(c,\
    \ segtree.prod(0, c + (strict ? 0 : 1)) + 1);\n    }\n\n    return segtree.all_prod();\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_LIS_HPP\n#define TOOLS_LIS_HPP\n\n#include <iterator>\n#include\
    \ <vector>\n#include <algorithm>\n#include \"atcoder/segtree.hpp\"\n#include \"\
    tools/monoid.hpp\"\n#include \"tools/compress.hpp\"\n\nnamespace tools {\n  template\
    \ <typename InputIterator>\n  long long lis(const InputIterator& begin, const\
    \ InputIterator& end, const bool strict) {\n    using M = ::tools::monoid::max<long\
    \ long, 0>;\n\n    ::std::vector<long long> compressed;\n    ::tools::compress(begin,\
    \ end, ::std::back_inserter(compressed));\n\n    ::atcoder::segtree<long long,\
    \ M::op, M::e> segtree(compressed.empty() ? 0 : *::std::max_element(compressed.begin(),\
    \ compressed.end()) + 1);\n    for (const auto c : compressed) {\n      segtree.set(c,\
    \ segtree.prod(0, c + (strict ? 0 : 1)) + 1);\n    }\n\n    return segtree.all_prod();\n\
    \  }\n}\n\n#endif\n"
  dependsOn:
  - tools/monoid.hpp
  - tools/compress.hpp
  - tools/lower_bound.hpp
  isVerificationFile: false
  path: tools/lis.hpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/lis.test.cpp
documentation_of: tools/lis.hpp
layout: document
title: Longest increasing subsequence
---

```cpp
template <typename Iterator>
long long lis(Iterator begin, Iterator end, bool strict);
```

If `strict` is true, it returns the length of the longest strictly increasing subsequence.
If `strict` is false, it returns the length of the longest non-decreasing subsequence.

## Constraints
- `begin` $\leq$ `end`

## Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
