---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/preset_segtree_beats.hpp
    title: tools/preset_segtree_beats.hpp
  - icon: ':heavy_check_mark:'
    path: tools/segtree_beats.hpp
    title: tools/segtree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"tests/preset_segtree_beats.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 1 \"tools/preset_segtree_beats.hpp\"\n\n\
    \n\n#include <cassert>\n#include <algorithm>\n#include <limits>\n#line 1 \"tools/segtree_beats.hpp\"\
    \n\n\n\n#line 1 \"lib/ac-library/atcoder/lazysegtree.hpp\"\n\n\n\n#line 6 \"lib/ac-library/atcoder/lazysegtree.hpp\"\
    \n#include <functional>\n#line 8 \"lib/ac-library/atcoder/lazysegtree.hpp\"\n\n\
    #line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n\
    namespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus >= 202002L\n\n\
    using std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\nunsigned\
    \ int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x < (unsigned\
    \ int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nint countr_zero(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 10 \"lib/ac-library/atcoder/lazysegtree.hpp\"\
    \n\nnamespace atcoder {\n\n#if __cplusplus >= 201703L\n\ntemplate <class S,\n\
    \          auto op,\n          auto e,\n          class F,\n          auto mapping,\n\
    \          auto composition,\n          auto id>\nstruct lazy_segtree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                  \"op must work as S(S, S)\");\n\
    \    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,\n \
    \                 \"e must work as S()\");\n    static_assert(\n        std::is_convertible_v<decltype(mapping),\
    \ std::function<S(F, S)>>,\n        \"mapping must work as F(F, S)\");\n    static_assert(\n\
    \        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,\n\
    \        \"compostiion must work as F(F, F)\");\n    static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>,\n                  \"id must work as F()\");\n\n#else\n\
    \ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n        \
    \  class F,\n          S (*mapping)(F, S),\n          F (*composition)(F, F),\n\
    \          F (*id)()>\nstruct lazy_segtree {\n\n#endif\n\n  public:\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        size = (int)internal::bit_ceil((unsigned int)(_n));\n        log\
    \ = internal::countr_zero((unsigned int)size);\n        d = std::vector<S>(2 *\
    \ size, e());\n        lz = std::vector<F>(size, id());\n        for (int i =\
    \ 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = e(),\
    \ smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  protected:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    virtual\
    \ void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k\
    \ < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n    \
    \    all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k]\
    \ = id();\n    }\n};\n\n}  // namespace atcoder\n\n\n#line 5 \"tools/segtree_beats.hpp\"\
    \n\n// Source: https://github.com/hitonanode/cplib-cpp/blob/94a544f88242fec39b4dd434ed379c23aa4dd99b/segmenttree/acl_beats.hpp\n\
    // License: MIT\n// Author: hitonanode\n\n// MIT License\n// \n// Copyright (c)\
    \ 2019 Ryotaro Sato\n// \n// Permission is hereby granted, free of charge, to\
    \ any person obtaining a copy\n// of this software and associated documentation\
    \ files (the \"Software\"), to deal\n// in the Software without restriction, including\
    \ without limitation the rights\n// to use, copy, modify, merge, publish, distribute,\
    \ sublicense, and/or sell\n// copies of the Software, and to permit persons to\
    \ whom the Software is\n// furnished to do so, subject to the following conditions:\n\
    // \n// The above copyright notice and this permission notice shall be included\
    \ in all\n// copies or substantial portions of the Software.\n// \n// THE SOFTWARE\
    \ IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED,\
    \ INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS\
    \ FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS\
    \ OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY,\
    \ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF\
    \ OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n// SOFTWARE.\n\
    \nnamespace tools {\n  template <class S, auto op, auto e, class F, auto mapping,\
    \ auto composition, auto id>\n  class segtree_beats : public ::atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id> {\n    using Base = ::atcoder::lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>;\n    using Base::lazy_segtree;\n    void\
    \ all_apply(int k, F f) override {\n      Base::d[k] = mapping(f, Base::d[k]);\n\
    \      if (k < Base::size) {\n        Base::lz[k] = composition(f, Base::lz[k]);\n\
    \        if (Base::d[k].fail) Base::push(k), Base::update(k);\n      }\n    }\n\
    \  };\n}\n\n\n#line 9 \"tools/preset_segtree_beats.hpp\"\n\n// Source: https://github.com/hitonanode/cplib-cpp/blob/94a544f88242fec39b4dd434ed379c23aa4dd99b/segmenttree/acl_beats.hpp\n\
    // License: MIT\n// Author: hitonanode\n\n// MIT License\n// \n// Copyright (c)\
    \ 2019 Ryotaro Sato\n// \n// Permission is hereby granted, free of charge, to\
    \ any person obtaining a copy\n// of this software and associated documentation\
    \ files (the \"Software\"), to deal\n// in the Software without restriction, including\
    \ without limitation the rights\n// to use, copy, modify, merge, publish, distribute,\
    \ sublicense, and/or sell\n// copies of the Software, and to permit persons to\
    \ whom the Software is\n// furnished to do so, subject to the following conditions:\n\
    // \n// The above copyright notice and this permission notice shall be included\
    \ in all\n// copies or substantial portions of the Software.\n// \n// THE SOFTWARE\
    \ IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED,\
    \ INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS\
    \ FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS\
    \ OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY,\
    \ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF\
    \ OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n// SOFTWARE.\n\
    \nnamespace tools {\n  namespace detail {\n    namespace preset_segtree_beats\
    \ {\n      template <typename T>\n      T second_lowest(const T a, const T a2,\
    \ const T c, const T c2) {\n        assert(a < a2);\n        assert(c < c2);\n\
    \        return a == c ? ::std::min(a2, c2) : a2 <= c ? a2 : c2 <= a ? c2 : ::std::max(a,\
    \ c);\n      }\n\n      template <typename T>\n      T second_highest(const T\
    \ a, const T a2, const T b, const T b2) {\n        assert(a > a2);\n        assert(b\
    \ > b2);\n        return a == b ? ::std::max(a2, b2) : a2 >= b ? a2 : b2 >= a\
    \ ? b2 : ::std::min(a, b);\n      }\n\n      template <typename T>\n      struct\
    \ S {\n        T lo, hi, lo2, hi2, sum, sz, nlo, nhi;\n        bool fail;\n  \
    \      S():\n          lo(::std::numeric_limits<T>::max()),\n          hi(::std::numeric_limits<T>::min()),\n\
    \          lo2(::std::numeric_limits<T>::max()),\n          hi2(::std::numeric_limits<T>::min()),\n\
    \          sum(0),\n          sz(0),\n          nlo(0),\n          nhi(0),\n \
    \         fail(false) {\n        }\n        S(const T x, const T sz_ = 1):\n \
    \         lo(x),\n          hi(x),\n          lo2(::std::numeric_limits<T>::max()),\n\
    \          hi2(::std::numeric_limits<T>::min()),\n          sum(x * sz_),\n  \
    \        sz(sz_),\n          nlo(sz_),\n          nhi(sz_),\n          fail(false)\
    \ {\n        }\n      };\n\n      template <typename T>\n      S<T> op(const S<T>&\
    \ l, const S<T>& r) {\n        if (l.lo > l.hi) return r;\n        if (r.lo >\
    \ r.hi) return l;\n        S<T> ret;\n        ret.lo = ::std::min(l.lo, r.lo);\n\
    \        ret.hi = ::std::max(l.hi, r.hi);\n        ret.lo2 = second_lowest(l.lo,\
    \ l.lo2, r.lo, r.lo2);\n        ret.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);\n\
    \        ret.sum = l.sum + r.sum;\n        ret.sz = l.sz + r.sz;\n        ret.nlo\
    \ = l.nlo * (l.lo <= r.lo) + r.nlo * (r.lo <= l.lo);\n        ret.nhi = l.nhi\
    \ * (l.hi >= r.hi) + r.nhi * (r.hi >= l.hi);\n        return ret;\n      }\n\n\
    \      template <typename T>\n      S<T> e() {\n        return S<T>();\n     \
    \ }\n\n      template <typename T>\n      struct F {\n        T lb, ub, bias;\n\
    \        F():\n          lb(::std::numeric_limits<T>::min()),\n          ub(::std::numeric_limits<T>::max()),\n\
    \          bias(0) {\n        }\n        F(const T chmax_, const T chmin_, const\
    \ T add):\n          lb(chmax_),\n          ub(chmin_),\n          bias(add) {\n\
    \        }\n        static F<T> chmin(const T x) {\n          return F<T>(::std::numeric_limits<T>::min(),\
    \ x, 0);\n        }\n        static F<T> chmax(const T x) {\n          return\
    \ F<T>(x, ::std::numeric_limits<T>::max(), 0);\n        }\n        static F<T>\
    \ add(const T x) {\n          return F<T>(::std::numeric_limits<T>::min(), ::std::numeric_limits<T>::max(),\
    \ x);\n        }\n      };\n\n      template <typename T>\n      S<T> mapping(const\
    \ F<T>& f, S<T> x) {\n        if (x.sz == 0) return e<T>();\n        if (x.lo\
    \ == x.hi || f.lb == f.ub || f.lb >= x.hi || f.ub < x.lo) {\n          return\
    \ S<T>(::std::clamp(x.lo, f.lb, f.ub) + f.bias, x.sz);\n        }\n        if\
    \ (x.lo2 == x.hi) {\n          x.lo = x.hi2 = ::std::max(x.lo, f.lb) + f.bias;\n\
    \          x.hi = x.lo2 = ::std::min(x.hi, f.ub) + f.bias;\n          x.sum =\
    \ x.lo * x.nlo + x.hi * x.nhi;\n          return x;\n        }\n        if (f.lb\
    \ < x.lo2 && f.ub > x.hi2) {\n          T nxt_lo = std::max(x.lo, f.lb);\n   \
    \       T nxt_hi = std::min(x.hi, f.ub);\n          x.sum += (nxt_lo - x.lo) *\
    \ x.nlo - (x.hi - nxt_hi) * x.nhi + f.bias * x.sz;\n          x.lo = nxt_lo +\
    \ f.bias;\n          x.hi = nxt_hi + f.bias;\n          x.lo2 += f.bias;\n   \
    \       x.hi2 += f.bias;\n          return x;\n        }\n        x.fail = true;\n\
    \        return x;\n      }\n\n      template <typename T>\n      F<T> composition(const\
    \ F<T>& fnew, const F<T>& fold) {\n        F<T> ret;\n\n        ret.lb = fold.lb;\n\
    \        if (::std::numeric_limits<T>::min() < ret.lb && ret.lb < ::std::numeric_limits<T>::max())\
    \ ret.lb += fold.bias;\n        ret.lb = ::std::clamp(ret.lb, fnew.lb, fnew.ub);\n\
    \        if (::std::numeric_limits<T>::min() < ret.lb && ret.lb < ::std::numeric_limits<T>::max())\
    \ ret.lb -= fold.bias;\n\n        ret.ub = fold.ub;\n        if (::std::numeric_limits<T>::min()\
    \ < ret.ub && ret.ub < ::std::numeric_limits<T>::max()) ret.ub += fold.bias;\n\
    \        ret.ub = ::std::clamp(ret.ub, fnew.lb, fnew.ub);\n        if (::std::numeric_limits<T>::min()\
    \ < ret.ub && ret.ub < ::std::numeric_limits<T>::max()) ret.ub -= fold.bias;\n\
    \n        ret.bias = fold.bias + fnew.bias;\n\n        return ret;\n      }\n\n\
    \      template <typename T>\n      F<T> id() {\n        return F<T>();\n    \
    \  }\n\n      template <typename T>\n      using Base = ::tools::segtree_beats<S<T>,\
    \ op<T>, e<T>, F<T>, mapping<T>, composition<T>, id<T>>;\n    }\n  }\n\n  template\
    \ <typename T>\n  class preset_segtree_beats {\n  private:\n    ::tools::detail::preset_segtree_beats::Base<T>\
    \ m_base;\n    using S = ::tools::detail::preset_segtree_beats::S<T>;\n    using\
    \ F = ::tools::detail::preset_segtree_beats::F<T>;\n\n  public:\n    preset_segtree_beats(const\
    \ ::tools::preset_segtree_beats<T>&) = default;\n    preset_segtree_beats(::tools::preset_segtree_beats<T>&&)\
    \ = default;\n    ~preset_segtree_beats() = default;\n    ::tools::preset_segtree_beats<T>&\
    \ operator=(const ::tools::preset_segtree_beats<T>&) = default;\n    ::tools::preset_segtree_beats<T>&\
    \ operator=(::tools::preset_segtree_beats<T>&&) = default;\n\n    explicit preset_segtree_beats(const\
    \ int n) : m_base(n) {\n    }\n    template <typename InputIterator>\n    preset_segtree_beats(const\
    \ InputIterator begin, const InputIterator end) : m_base([&]() {\n      ::std::vector<S>\
    \ v;\n      for (auto it = begin; it != end; ++it) {\n        v.emplace_back(*it);\n\
    \      }\n      return v;\n    }()) {\n    }\n    explicit preset_segtree_beats(const\
    \ ::std::vector<T>& v) : preset_segtree_beats(v.begin(), v.end()) {\n    }\n\n\
    \    void set(const int p, const T x) {\n      this->m_base.set(p, S(x));\n  \
    \  }\n    T get(const int p) {\n      return this->m_base.get(p).sum;\n    }\n\
    \    T min(const int l, const int r) {\n      return this->m_base.prod(l, r).lo;\n\
    \    }\n    T max(const int l, const int r) {\n      return this->m_base.prod(l,\
    \ r).hi;\n    }\n    T sum(const int l, const int r) {\n      return this->m_base.prod(l,\
    \ r).sum;\n    }\n    T all_min() {\n      return this->m_base.all_prod().lo;\n\
    \    }\n    T all_max() {\n      return this->m_base.all_prod().hi;\n    }\n \
    \   T all_sum() {\n      return this->m_base.all_prod().sum;\n    }\n    void\
    \ chmin(const int p, const T f) {\n      this->m_base.apply(p, F::chmin(f));\n\
    \    }\n    void chmax(const int p, const T f) {\n      this->m_base.apply(p,\
    \ F::chmax(f));\n    }\n    void add(const int p, const T f) {\n      this->m_base.apply(p,\
    \ F::add(f));\n    }\n    void chmin(const int l, const int r, const T f) {\n\
    \      this->m_base.apply(l, r, F::chmin(f));\n    }\n    void chmax(const int\
    \ l, const int r, const T f) {\n      this->m_base.apply(l, r, F::chmax(f));\n\
    \    }\n    void add(const int l, const int r, const T f) {\n      this->m_base.apply(l,\
    \ r, F::add(f));\n    }\n    template <class G>\n    int max_right(const int l,\
    \ const G g) {\n      return this->m_base.max_right(l, g);\n    }\n    template\
    \ <class G>\n    int min_left(const int r, const G g) {\n      return this->m_base.min_left(r,\
    \ g);\n    }\n  };\n}\n\n\n#line 6 \"tests/preset_segtree_beats.test.cpp\"\n\n\
    using ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, Q;\n  std::cin >> N >> Q;\n  std::vector<ll> a(N);\n  for (auto& a_i\
    \ : a) std::cin >> a_i;\n\n  tools::preset_segtree_beats<ll> beats(a);\n  for\
    \ (ll q = 0; q < Q; ++q) {\n    ll t;\n    std::cin >> t;\n    if (t == 0) {\n\
    \      ll l, r, b;\n      std::cin >> l >> r >> b;\n      beats.chmin(l, r, b);\n\
    \    } else if (t == 1) {\n      ll l, r, b;\n      std::cin >> l >> r >> b;\n\
    \      beats.chmax(l, r, b);\n    } else if (t == 2) {\n      ll l, r, b;\n  \
    \    std::cin >> l >> r >> b;\n      beats.add(l, r, b);\n    } else {\n     \
    \ ll l, r;\n      std::cin >> l >> r;\n      std::cout << beats.sum(l, r) << '\\\
    n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"tools/preset_segtree_beats.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, Q;\n  std::cin >> N >> Q;\n  std::vector<ll> a(N);\n  for (auto& a_i\
    \ : a) std::cin >> a_i;\n\n  tools::preset_segtree_beats<ll> beats(a);\n  for\
    \ (ll q = 0; q < Q; ++q) {\n    ll t;\n    std::cin >> t;\n    if (t == 0) {\n\
    \      ll l, r, b;\n      std::cin >> l >> r >> b;\n      beats.chmin(l, r, b);\n\
    \    } else if (t == 1) {\n      ll l, r, b;\n      std::cin >> l >> r >> b;\n\
    \      beats.chmax(l, r, b);\n    } else if (t == 2) {\n      ll l, r, b;\n  \
    \    std::cin >> l >> r >> b;\n      beats.add(l, r, b);\n    } else {\n     \
    \ ll l, r;\n      std::cin >> l >> r;\n      std::cout << beats.sum(l, r) << '\\\
    n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/preset_segtree_beats.hpp
  - tools/segtree_beats.hpp
  isVerificationFile: true
  path: tests/preset_segtree_beats.test.cpp
  requiredBy: []
  timestamp: '2023-05-02 20:01:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/preset_segtree_beats.test.cpp
layout: document
redirect_from:
- /verify/tests/preset_segtree_beats.test.cpp
- /verify/tests/preset_segtree_beats.test.cpp.html
title: tests/preset_segtree_beats.test.cpp
---
