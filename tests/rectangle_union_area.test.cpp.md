---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/compressor.hpp
    title: Compress values (for more complicated cases)
  - icon: ':question:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  - icon: ':heavy_check_mark:'
    path: tools/rectangle_union_area.hpp
    title: Area of union of rectangles
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"tests/rectangle_union_area.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\n\n#include <iostream>\n\
    #line 1 \"tools/rectangle_union_area.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <limits>\n#include <vector>\n#include <tuple>\n#include <cstddef>\n#include\
    \ <cassert>\n#line 1 \"lib/ac-library/atcoder/lazysegtree.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#line 6 \"lib/ac-library/atcoder/lazysegtree.hpp\"\n#include <functional>\n\
    #line 8 \"lib/ac-library/atcoder/lazysegtree.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n\
    #include <bit>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus\
    \ >= 202002L\n\nusing std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\n\
    unsigned int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x\
    \ < (unsigned int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <=\
    \ n`\n// @return same with std::bit::countr_zero\nint countr_zero(unsigned int\
    \ n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n//\
    \ @param n `1 <= n`\n// @return same with std::bit::countr_zero\nconstexpr int\
    \ countr_zero_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1\
    \ << x))) x++;\n    return x;\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n#line 10 \"lib/ac-library/atcoder/lazysegtree.hpp\"\n\nnamespace\
    \ atcoder {\n\n#if __cplusplus >= 201703L\n\ntemplate <class S,\n          auto\
    \ op,\n          auto e,\n          class F,\n          auto mapping,\n      \
    \    auto composition,\n          auto id>\nstruct lazy_segtree {\n    static_assert(std::is_convertible_v<decltype(op),\
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
    \ = id();\n    }\n};\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/compressor.hpp\"\
    \n\n\n\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#include <iterator>\n#line 6\
    \ \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template <class ForwardIterator,\
    \ class T>\n  auto lower_bound(ForwardIterator first, ForwardIterator last, const\
    \ T& value) {\n    return ::std::distance(first, ::std::lower_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 8 \"tools/compressor.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  class compressor {\n  private:\n    ::std::vector<T>\
    \ m_sorted;\n\n  public:\n    compressor() = default;\n    compressor(const ::tools::compressor<T>&)\
    \ = default;\n    compressor(::tools::compressor<T>&&) = default;\n    ~compressor()\
    \ = default;\n    ::tools::compressor<T>& operator=(const ::tools::compressor<T>&)\
    \ = default;\n    ::tools::compressor<T>& operator=(::tools::compressor<T>&&)\
    \ = default;\n\n    template <typename InputIterator>\n    compressor(InputIterator\
    \ begin, InputIterator end) : m_sorted(begin, end) {\n      ::std::sort(this->m_sorted.begin(),\
    \ this->m_sorted.end());\n      this->m_sorted.erase(::std::unique(this->m_sorted.begin(),\
    \ this->m_sorted.end()), this->m_sorted.end());\n    }\n    compressor(const ::std::vector<T>&\
    \ v) : compressor(v.begin(), v.end()) {\n    }\n\n    T size() const {\n     \
    \ return this->m_sorted.size();\n    }\n    T compress(const T& x) const {\n \
    \     const T i = ::tools::lower_bound(this->m_sorted.begin(), this->m_sorted.end(),\
    \ x);\n      assert(i < this->size());\n      assert(this->m_sorted[i] == x);\n\
    \      return i;\n    }\n    T decompress(const T& i) const {\n      assert(0\
    \ <= i && i < this->size());\n      return this->m_sorted[i];\n    }\n\n    auto\
    \ begin() {\n      return this->m_sorted.cbegin();\n    }\n    auto begin() const\
    \ {\n      return this->m_sorted.cbegin();\n    }\n    auto end() {\n      return\
    \ this->m_sorted.cend();\n    }\n    auto end() const {\n      return this->m_sorted.cend();\n\
    \    }\n  };\n}\n\n\n#line 12 \"tools/rectangle_union_area.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  class rectangle_union_area {\n  private:\n\
    \    using S = ::std::pair<int, T>;\n    static S op(const S& x, const S& y) {\n\
    \      return x.first < y.first ? x : x.first > y.first ? y : S(x.first, x.second\
    \ + y.second);\n    }\n    static S e() {\n      return S(::std::numeric_limits<int>::max(),\
    \ 0);\n    }\n    using F = int;\n    static S mapping(const F& f, const S& x)\
    \ {\n      return S(f + x.first, x.second);\n    }\n    static F composition(const\
    \ F& f, const F& g) {\n      return f + g;\n    }\n    static F id() {\n     \
    \ return 0;\n    }\n\n    ::std::vector<::std::tuple<T, T, T, T>> m_rectangles;\n\
    \n  public:\n    rectangle_union_area() = default;\n    rectangle_union_area(const\
    \ ::tools::rectangle_union_area<T>&) = default;\n    rectangle_union_area(::tools::rectangle_union_area<T>&&)\
    \ = default;\n    ~rectangle_union_area() = default;\n    ::tools::rectangle_union_area<T>&\
    \ operator=(const ::tools::rectangle_union_area<T>&) = default;\n    ::tools::rectangle_union_area<T>&\
    \ operator=(::tools::rectangle_union_area<T>&&) = default;\n\n    ::std::size_t\
    \ size() const {\n      return this->m_rectangle.size();\n    }\n\n    ::std::size_t\
    \ add_rectangle(const T l, const T r, const T d, const T u) {\n      assert(l\
    \ < r);\n      assert(d < u);\n      this->m_rectangles.emplace_back(l, r, d,\
    \ u);\n      return this->m_rectangles.size() - 1;\n    }\n\n    const ::std::tuple<T,\
    \ T, T, T>& get_rectangle(const ::std::size_t k) const {\n      assert(k < this->m_rectangles.size());\n\
    \      return this->m_rectangles[k];\n    }\n\n    const ::std::vector<::std::tuple<T,\
    \ T, T, T>>& rectangles() const {\n      return this->m_rectangles;\n    }\n\n\
    \    T query() const {\n      ::std::vector<T> x_list, y_list;\n      for (const\
    \ auto& [l, r, d, u] : this->m_rectangles) {\n        x_list.push_back(l);\n \
    \       x_list.push_back(r);\n        y_list.push_back(d);\n        y_list.push_back(u);\n\
    \      }\n      ::tools::compressor<T> x_comp(x_list), y_comp(y_list);\n\n   \
    \   ::std::vector<::std::pair<::std::vector<::std::size_t>, ::std::vector<::std::size_t>>>\
    \ sorted_rectangles(x_comp.size() + 1);\n      for (::std::size_t i = 0; i < this->m_rectangles.size();\
    \ ++i) {\n        const auto& [l, r, d, u] = this->m_rectangles[i];\n        sorted_rectangles[x_comp.compress(l)].first.push_back(i);\n\
    \        sorted_rectangles[x_comp.compress(r)].second.push_back(i);\n      }\n\
    \n      ::std::vector<S> v;\n      for (decltype(y_comp.size()) i = 0; i + 1 <\
    \ y_comp.size(); ++i) {\n        v.emplace_back(0, y_comp.decompress(i + 1) -\
    \ y_comp.decompress(i));\n      }\n      ::atcoder::lazy_segtree<S, op, e, F,\
    \ mapping, composition, id> lazy_segtree(v);\n      const T H = lazy_segtree.all_prod().second;\n\
    \n      T answer = 0;\n      for (decltype(x_comp.size()) i = 0; i + 1 < x_comp.size();\
    \ ++i) {\n        for (const auto k : sorted_rectangles[i].first) {\n        \
    \  const auto& [l, r, d, u] = this->m_rectangles[k];\n          lazy_segtree.apply(y_comp.compress(d),\
    \ y_comp.compress(u), 1);\n        }\n        for (const auto k : sorted_rectangles[i].second)\
    \ {\n          const auto& [l, r, d, u] = this->m_rectangles[k];\n          lazy_segtree.apply(y_comp.compress(d),\
    \ y_comp.compress(u), -1);\n        }\n        answer += (x_comp.decompress(i\
    \ + 1) - x_comp.decompress(i)) * (H - (lazy_segtree.all_prod().first > 0 ? 0 :\
    \ lazy_segtree.all_prod().second));\n      }\n\n      return answer;\n    }\n\
    \  };\n}\n\n\n#line 5 \"tests/rectangle_union_area.test.cpp\"\n\nusing ll = long\
    \ long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N;\n  std::cin >> N;\n  tools::rectangle_union_area<ll> rs;\n  for (int\
    \ i = 0; i < N; ++i) {\n    ll l, d, r, u;\n    std::cin >> l >> d >> r >> u;\n\
    \    rs.add_rectangle(l, r, d, u);\n  }\n\n  std::cout << rs.query() << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#include <iostream>\n#include \"tools/rectangle_union_area.hpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N;\n  std::cin >> N;\n  tools::rectangle_union_area<ll> rs;\n  for (int\
    \ i = 0; i < N; ++i) {\n    ll l, d, r, u;\n    std::cin >> l >> d >> r >> u;\n\
    \    rs.add_rectangle(l, r, d, u);\n  }\n\n  std::cout << rs.query() << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/rectangle_union_area.hpp
  - tools/compressor.hpp
  - tools/lower_bound.hpp
  isVerificationFile: true
  path: tests/rectangle_union_area.test.cpp
  requiredBy: []
  timestamp: '2023-09-09 10:01:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/rectangle_union_area.test.cpp
layout: document
redirect_from:
- /verify/tests/rectangle_union_area.test.cpp
- /verify/tests/rectangle_union_area.test.cpp.html
title: tests/rectangle_union_area.test.cpp
---
