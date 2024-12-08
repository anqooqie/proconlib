---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cmp_equal.hpp
    title: Polyfill of std::cmp_equal
  - icon: ':heavy_check_mark:'
    path: tools/gcd.hpp
    title: std::gcd(m, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/permutation.hpp
    title: Permutation
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/lis/bisect/no_restore.test.cpp
    title: tests/lis/bisect/no_restore.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lis/bisect/restore.test.cpp
    title: tests/lis/bisect/restore.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lis/segtree/no_restore.test.cpp
    title: tests/lis/segtree/no_restore.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lis/segtree/restore.test.cpp
    title: tests/lis/segtree/restore.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/lis.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <iterator>\n#include <cstddef>\n#include <vector>\n#include <numeric>\n#include\
    \ <algorithm>\n#include <functional>\n#line 1 \"lib/ac-library/atcoder/segtree.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/segtree.hpp\"\n#include <cassert>\n#line\
    \ 8 \"lib/ac-library/atcoder/segtree.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\
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
    \ atcoder\n\n\n#line 10 \"lib/ac-library/atcoder/segtree.hpp\"\n\nnamespace atcoder\
    \ {\n\n#if __cplusplus >= 201703L\n\ntemplate <class S, auto op, auto e> struct\
    \ segtree {\n    static_assert(std::is_convertible_v<decltype(op), std::function<S(S,\
    \ S)>>,\n                  \"op must work as S(S, S)\");\n    static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                  \"e must work as S()\");\n\n#else\n\n\
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {\n\n#endif\n\n  public:\n\
    \    segtree() : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        size = (int)internal::bit_ceil((unsigned int)(_n));\n        log\
    \ = internal::countr_zero((unsigned int)size);\n        d = std::vector<S>(2 *\
    \ size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    \
    \    for (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n\
    \    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n    \
    \    p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <= p && p < _n);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) const {\n    \
    \    assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n \
    \       l += size;\n        r += size;\n\n        while (l < r) {\n          \
    \  if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template\
    \ <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S\
    \ x) { return f(x); });\n    }\n    template <class F> int max_right(int l, F\
    \ f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n  \
    \      if (l == _n) return _n;\n        l += size;\n        S sm = e();\n    \
    \    do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/permutation.hpp\"\
    \n\n\n\n#line 10 \"tools/permutation.hpp\"\n#include <utility>\n#include <iostream>\n\
    #include <string>\n\nnamespace tools {\n  template <typename T>\n  class permutation\
    \ {\n    ::std::vector<T> m_perm;\n    ::std::vector<T> m_inv;\n\n    void verify_consistency()\
    \ const {\n#ifndef NDEBUG\n      ::std::vector<bool> unique(this->m_perm.size(),\
    \ true);\n      for (const T x : this->m_perm) {\n        assert(0 <= x && x <\
    \ T(this->m_perm.size()));\n        assert(unique[x]);\n        unique[x] = false;\n\
    \      }\n#endif\n    }\n\n    void make_inv() {\n      this->m_inv.resize(this->m_perm.size());\n\
    \      for (::std::size_t i = 0; i < this->m_perm.size(); ++i) {\n        this->m_inv[this->m_perm[i]]\
    \ = i;\n      }\n    }\n\n  public:\n    permutation() = default;\n    explicit\
    \ permutation(::std::size_t n) : m_perm(n), m_inv(n) {\n      ::std::iota(this->m_perm.begin(),\
    \ this->m_perm.end(), 0);\n      ::std::iota(this->m_inv.begin(), this->m_inv.end(),\
    \ 0);\n    }\n    template <typename Iterator>\n    permutation(Iterator begin,\
    \ Iterator end) : m_perm(begin, end) {\n      this->verify_consistency();\n  \
    \    this->make_inv();\n    }\n    permutation(const ::std::vector<T>& v) : permutation(v.begin(),\
    \ v.end()) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_perm.size();\n\
    \    }\n    T operator[](const ::std::size_t i) const {\n      assert(i < this->size());\n\
    \      return this->m_perm[i];\n    }\n    typename ::std::vector<T>::const_iterator\
    \ begin() const {\n      return this->m_perm.begin();\n    }\n    typename ::std::vector<T>::const_iterator\
    \ end() const {\n      return this->m_perm.end();\n    }\n\n    ::tools::permutation<T>&\
    \ swap_from_left(const T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n\
    \      assert(0 <= y && y < T(this->size()));\n      this->m_inv[this->m_perm[y]]\
    \ = x;\n      this->m_inv[this->m_perm[x]] = y;\n      ::std::swap(this->m_perm[x],\
    \ this->m_perm[y]);\n      return *this;\n    }\n    ::tools::permutation<T>&\
    \ swap_from_right(const T x, const T y) {\n      assert(0 <= x && x < T(this->size()));\n\
    \      assert(0 <= y && y < T(this->size()));\n      this->m_perm[this->m_inv[y]]\
    \ = x;\n      this->m_perm[this->m_inv[x]] = y;\n      ::std::swap(this->m_inv[x],\
    \ this->m_inv[y]);\n      return *this;\n    }\n\n    T id() const {\n      if\
    \ (this->size() == 0) return 0;\n\n      ::std::vector<T> left(this->size());\n\
    \      ::std::iota(left.begin(), left.end(), 0);\n\n      ::std::vector<T> fact(this->size());\n\
    \      fact[0] = 1;\n      for (::std::size_t i = 1; i < this->size(); ++i) {\n\
    \        fact[i] = fact[i - 1] * i;\n      }\n\n      T id = 0;\n      for (::std::size_t\
    \ i = 0; i < this->size(); ++i) {\n        auto it = ::std::lower_bound(left.begin(),\
    \ left.end(), this->m_perm[i]);\n        id += ::std::distance(left.begin(), it)\
    \ * fact[this->m_perm.size() - 1 - i];\n        left.erase(it);\n      }\n\n \
    \     return id;\n    }\n\n    static ::tools::permutation<T> from(const ::std::size_t\
    \ n, T id) {\n      if (n == 0) return ::tools::permutation<T>(0);\n\n      ::std::vector<T>\
    \ left(n);\n      ::std::iota(left.begin(), left.end(), 0);\n\n      ::std::vector<T>\
    \ fact(n);\n      fact[0] = 1;\n      for (::std::size_t i = 1; i < n; ++i) {\n\
    \        fact[i] = fact[i - 1] * i;\n      }\n\n      ::std::vector<T> p;\n  \
    \    for (::std::size_t i = 0; i < n; ++i) {\n        auto it = ::std::next(left.begin(),\
    \ id / fact[n - i - 1]);\n        p.push_back(*it);\n        left.erase(it);\n\
    \        id %= fact[n - i - 1];\n      }\n\n      return ::tools::permutation<T>(p.begin(),\
    \ p.end());\n    }\n\n    ::tools::permutation<T> inv() const {\n      return\
    \ ::tools::permutation<T>(this->m_inv.begin(), this->m_inv.end());\n    }\n  \
    \  ::tools::permutation<T>& inv_inplace() {\n      this->m_perm.swap(this->m_inv);\n\
    \      return *this;\n    }\n    T inv(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      return this->m_inv[i];\n    }\n\n    ::tools::permutation<T>&\
    \ operator*=(const ::tools::permutation<T>& other) {\n      assert(this->size()\
    \ == other.size());\n      for (::std::size_t i = 0; i < this->size(); ++i) {\n\
    \        this->m_inv[i] = other.m_perm[this->m_perm[i]];\n      }\n      this->m_perm.swap(this->m_inv);\n\
    \      this->make_inv();\n      return *this;\n    }\n    friend ::tools::permutation<T>\
    \ operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return ::tools::permutation<T>(lhs) *= rhs;\n    }\n\n    friend\
    \ bool operator==(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return lhs.m_perm == rhs.m_perm;\n    }\n    friend bool operator!=(const\
    \ ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {\n      return\
    \ lhs.m_perm != rhs.m_perm;\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::permutation<T>& self) {\n      os << '(';\n      ::std::string\
    \ delimiter = \"\";\n      for (const T value : self.m_perm) {\n        os <<\
    \ delimiter << value;\n        delimiter = \", \";\n      }\n      return os <<\
    \ ')';\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::permutation<T>&\
    \ self) {\n      for (T& value : self.m_perm) {\n        is >> value;\n      }\n\
    \      self.verify_consistency();\n      self.make_inv();\n      return is;\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line 6 \"tools/monoid.hpp\"\
    \n#include <limits>\n#line 1 \"tools/gcd.hpp\"\n\n\n\n#line 6 \"tools/gcd.hpp\"\
    \n\nnamespace tools {\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> gcd(const M m, const N n) {\n    return ::std::gcd(m, n);\n  }\n}\n\n\n#line\
    \ 9 \"tools/monoid.hpp\"\n\nnamespace tools {\n  namespace monoid {\n    template\
    \ <typename M, M ...dummy>\n    struct max;\n\n    template <typename M>\n   \
    \ struct max<M> {\n      static_assert(::std::is_arithmetic_v<M>, \"M must be\
    \ a built-in arithmetic type.\");\n\n      using T = M;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n     \
    \ static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n         \
    \ return ::std::numeric_limits<M>::min();\n        } else {\n          return\
    \ -::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\n    template\
    \ <typename M, M E>\n    struct max<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(E <= lhs);\n        assert(E\
    \ <= rhs);\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename M, M ...dummy>\n\
    \    struct min;\n\n    template <typename M>\n    struct min<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::min(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::max();\n        } else {\n       \
    \   return ::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct min<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(lhs <= E);\n        assert(rhs\
    \ <= E);\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n    private:\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n \
    \       return T(1);\n      }\n    };\n\n    template <>\n    struct multiplies<bool>\
    \ {\n      using T = bool;\n      static T op(const bool lhs, const bool rhs)\
    \ {\n        return lhs && rhs;\n      }\n      static T e() {\n        return\
    \ true;\n      }\n    };\n\n    template <typename M>\n    struct gcd {\n    private:\n\
    \      static_assert(!::std::is_arithmetic_v<M> || (::std::is_integral_v<M> &&\
    \ !::std::is_same_v<M, bool>), \"If M is a built-in arithmetic type, it must be\
    \ integral except for bool.\");\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return ::tools::gcd(lhs, rhs);\n      }\n      static\
    \ T e() {\n        return T(0);\n      }\n    };\n\n    template <typename M,\
    \ M E>\n    struct update {\n      static_assert(::std::is_integral_v<M>, \"M\
    \ must be a built-in integral type.\");\n\n      using T = M;\n      static T\
    \ op(const T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n     \
    \ }\n      static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line\
    \ 1 \"tools/cmp_equal.hpp\"\n\n\n\n#line 5 \"tools/cmp_equal.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T, typename U>\n  constexpr bool cmp_equal(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t == u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? false : UT(t) == u;\n    } else {\n      return u <\
    \ 0 ? false : t == UU(u);\n    }\n  }\n}\n\n\n#line 15 \"tools/lis.hpp\"\n\nnamespace\
    \ tools {\n  namespace lis {\n    template <bool Strict, bool Restore, typename\
    \ RandomAccessIterator, typename Compare, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end, const Compare& comp)\
    \ {\n      const int N = end - begin;\n\n      const auto p = ::tools::permutation<int>([&]()\
    \ {\n        ::std::vector<int> v(N);\n        if constexpr (Strict) {\n     \
    \     ::std::iota(v.rbegin(), v.rend(), 0);\n        } else {\n          ::std::iota(v.begin(),\
    \ v.end(), 0);\n        }\n        ::std::stable_sort(v.begin(), v.end(), [&](const\
    \ auto x, const auto y) {\n          return comp(begin[x], begin[y]);\n      \
    \  });\n        return v;\n      }()).inv_inplace();\n\n      ::atcoder::segtree<int,\
    \ ::tools::monoid::max<int, 0>::op, ::tools::monoid::max<int, 0>::e> segtree(N);\n\
    \      for (int i = 0; i < N; ++i) {\n        segtree.set(p[i], segtree.prod(0,\
    \ p[i]) + 1);\n      }\n\n      if constexpr (Restore) {\n        ::std::vector<int>\
    \ answer(segtree.all_prod(), -1);\n        for (int i = N - 1; i >= 0; --i) {\n\
    \          if (const auto k = segtree.get(p[i]); k == segtree.all_prod() || (answer[k]\
    \ >= 0 && p[i] < p[answer[k]])) {\n            answer[k - 1] = i;\n          }\n\
    \        }\n        return answer;\n      } else {\n        return segtree.all_prod();\n\
    \      }\n    }\n    template <bool Strict, bool Restore, typename InputIterator,\
    \ typename Compare, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const\
    \ InputIterator begin, const InputIterator end, const Compare& comp) {\n     \
    \ ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type> v(begin,\
    \ end);\n      return ::tools::lis::segtree<Strict, Restore>(v.begin(), v.end());\n\
    \    }\n    template <bool Strict, bool Restore, typename InputIterator>\n   \
    \ ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const InputIterator\
    \ begin, const InputIterator end) {\n      return ::tools::lis::segtree<Strict,\
    \ Restore>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n    template <bool Strict, typename InputIterator, typename Compare>\n\
    \    int segtree(const InputIterator begin, const InputIterator end, const Compare&\
    \ comp) {\n      return ::tools::lis::segtree<Strict, false>(begin, end, comp);\n\
    \    }\n    template <bool Strict, typename InputIterator>\n    int segtree(const\
    \ InputIterator begin, const InputIterator end) {\n      return ::tools::lis::segtree<Strict,\
    \ false>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n\n    template <bool Strict, bool Restore, typename RandomAccessIterator,\
    \ typename Compare, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end, const Compare& comp)\
    \ {\n      const int N = end - begin;\n\n      ::std::vector<int> bisect;\n  \
    \    ::std::vector<int> lengths(Restore ? N : 0);\n      for (int i = 0; i < N;\
    \ ++i) {\n        const auto it = Strict\n          ? ::std::lower_bound(bisect.begin(),\
    \ bisect.end(), i, [&](const auto x, const auto y) { return comp(begin[x], begin[y]);\
    \ })\n          : ::std::upper_bound(bisect.begin(), bisect.end(), i, [&](const\
    \ auto x, const auto y) { return comp(begin[x], begin[y]); });\n        if constexpr\
    \ (Restore) {\n          lengths[i] = ::std::distance(bisect.begin(), it) + 1;\n\
    \        }\n        if (it != bisect.end()) {\n          *it = i;\n        } else\
    \ {\n          bisect.push_back(i);\n        }\n      }\n\n      if constexpr\
    \ (Restore) {\n        ::std::vector<int> answer(bisect.size(), -1);\n       \
    \ for (int i = N - 1; i >= 0; --i) {\n          if (const auto k = lengths[i];\
    \ ::tools::cmp_equal(k, bisect.size()) || (answer[k] >= 0 && (Strict ? comp(begin[i],\
    \ begin[answer[k]]) : !comp(begin[answer[k]], begin[i])))) {\n            answer[k\
    \ - 1] = i;\n          }\n        }\n        return answer;\n      } else {\n\
    \        return bisect.size();\n      }\n    }\n    template <bool Strict, bool\
    \ Restore, typename InputIterator, typename Compare, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const\
    \ InputIterator begin, const InputIterator end, const Compare& comp) {\n     \
    \ ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type> v(begin,\
    \ end);\n      return ::tools::lis::bisect<Strict, Restore>(v.begin(), v.end());\n\
    \    }\n    template <bool Strict, bool Restore, typename InputIterator>\n   \
    \ ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const InputIterator\
    \ begin, const InputIterator end) {\n      return ::tools::lis::bisect<Strict,\
    \ Restore>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n    template <bool Strict, typename InputIterator, typename Compare>\n\
    \    int bisect(const InputIterator begin, const InputIterator end, const Compare&\
    \ comp) {\n      return ::tools::lis::bisect<Strict, false>(begin, end, comp);\n\
    \    }\n    template <bool Strict, typename InputIterator>\n    int bisect(const\
    \ InputIterator begin, const InputIterator end) {\n      return ::tools::lis::bisect<Strict,\
    \ false>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_LIS_HPP\n#define TOOLS_LIS_HPP\n\n#include <type_traits>\n\
    #include <iterator>\n#include <cstddef>\n#include <vector>\n#include <numeric>\n\
    #include <algorithm>\n#include <functional>\n#include \"atcoder/segtree.hpp\"\n\
    #include \"tools/permutation.hpp\"\n#include \"tools/monoid.hpp\"\n#include \"\
    tools/cmp_equal.hpp\"\n\nnamespace tools {\n  namespace lis {\n    template <bool\
    \ Strict, bool Restore, typename RandomAccessIterator, typename Compare, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end, const Compare& comp)\
    \ {\n      const int N = end - begin;\n\n      const auto p = ::tools::permutation<int>([&]()\
    \ {\n        ::std::vector<int> v(N);\n        if constexpr (Strict) {\n     \
    \     ::std::iota(v.rbegin(), v.rend(), 0);\n        } else {\n          ::std::iota(v.begin(),\
    \ v.end(), 0);\n        }\n        ::std::stable_sort(v.begin(), v.end(), [&](const\
    \ auto x, const auto y) {\n          return comp(begin[x], begin[y]);\n      \
    \  });\n        return v;\n      }()).inv_inplace();\n\n      ::atcoder::segtree<int,\
    \ ::tools::monoid::max<int, 0>::op, ::tools::monoid::max<int, 0>::e> segtree(N);\n\
    \      for (int i = 0; i < N; ++i) {\n        segtree.set(p[i], segtree.prod(0,\
    \ p[i]) + 1);\n      }\n\n      if constexpr (Restore) {\n        ::std::vector<int>\
    \ answer(segtree.all_prod(), -1);\n        for (int i = N - 1; i >= 0; --i) {\n\
    \          if (const auto k = segtree.get(p[i]); k == segtree.all_prod() || (answer[k]\
    \ >= 0 && p[i] < p[answer[k]])) {\n            answer[k - 1] = i;\n          }\n\
    \        }\n        return answer;\n      } else {\n        return segtree.all_prod();\n\
    \      }\n    }\n    template <bool Strict, bool Restore, typename InputIterator,\
    \ typename Compare, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const\
    \ InputIterator begin, const InputIterator end, const Compare& comp) {\n     \
    \ ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type> v(begin,\
    \ end);\n      return ::tools::lis::segtree<Strict, Restore>(v.begin(), v.end());\n\
    \    }\n    template <bool Strict, bool Restore, typename InputIterator>\n   \
    \ ::std::conditional_t<Restore, ::std::vector<int>, int> segtree(const InputIterator\
    \ begin, const InputIterator end) {\n      return ::tools::lis::segtree<Strict,\
    \ Restore>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n    template <bool Strict, typename InputIterator, typename Compare>\n\
    \    int segtree(const InputIterator begin, const InputIterator end, const Compare&\
    \ comp) {\n      return ::tools::lis::segtree<Strict, false>(begin, end, comp);\n\
    \    }\n    template <bool Strict, typename InputIterator>\n    int segtree(const\
    \ InputIterator begin, const InputIterator end) {\n      return ::tools::lis::segtree<Strict,\
    \ false>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n\n    template <bool Strict, bool Restore, typename RandomAccessIterator,\
    \ typename Compare, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end, const Compare& comp)\
    \ {\n      const int N = end - begin;\n\n      ::std::vector<int> bisect;\n  \
    \    ::std::vector<int> lengths(Restore ? N : 0);\n      for (int i = 0; i < N;\
    \ ++i) {\n        const auto it = Strict\n          ? ::std::lower_bound(bisect.begin(),\
    \ bisect.end(), i, [&](const auto x, const auto y) { return comp(begin[x], begin[y]);\
    \ })\n          : ::std::upper_bound(bisect.begin(), bisect.end(), i, [&](const\
    \ auto x, const auto y) { return comp(begin[x], begin[y]); });\n        if constexpr\
    \ (Restore) {\n          lengths[i] = ::std::distance(bisect.begin(), it) + 1;\n\
    \        }\n        if (it != bisect.end()) {\n          *it = i;\n        } else\
    \ {\n          bisect.push_back(i);\n        }\n      }\n\n      if constexpr\
    \ (Restore) {\n        ::std::vector<int> answer(bisect.size(), -1);\n       \
    \ for (int i = N - 1; i >= 0; --i) {\n          if (const auto k = lengths[i];\
    \ ::tools::cmp_equal(k, bisect.size()) || (answer[k] >= 0 && (Strict ? comp(begin[i],\
    \ begin[answer[k]]) : !comp(begin[answer[k]], begin[i])))) {\n            answer[k\
    \ - 1] = i;\n          }\n        }\n        return answer;\n      } else {\n\
    \        return bisect.size();\n      }\n    }\n    template <bool Strict, bool\
    \ Restore, typename InputIterator, typename Compare, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag,\
    \ typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t>\
    \ = nullptr>\n    ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const\
    \ InputIterator begin, const InputIterator end, const Compare& comp) {\n     \
    \ ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type> v(begin,\
    \ end);\n      return ::tools::lis::bisect<Strict, Restore>(v.begin(), v.end());\n\
    \    }\n    template <bool Strict, bool Restore, typename InputIterator>\n   \
    \ ::std::conditional_t<Restore, ::std::vector<int>, int> bisect(const InputIterator\
    \ begin, const InputIterator end) {\n      return ::tools::lis::bisect<Strict,\
    \ Restore>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n    template <bool Strict, typename InputIterator, typename Compare>\n\
    \    int bisect(const InputIterator begin, const InputIterator end, const Compare&\
    \ comp) {\n      return ::tools::lis::bisect<Strict, false>(begin, end, comp);\n\
    \    }\n    template <bool Strict, typename InputIterator>\n    int bisect(const\
    \ InputIterator begin, const InputIterator end) {\n      return ::tools::lis::bisect<Strict,\
    \ false>(begin, end, ::std::less<typename ::std::iterator_traits<InputIterator>::value_type>{});\n\
    \    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/permutation.hpp
  - tools/monoid.hpp
  - tools/gcd.hpp
  - tools/cmp_equal.hpp
  isVerificationFile: false
  path: tools/lis.hpp
  requiredBy: []
  timestamp: '2024-11-30 16:59:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lis/segtree/no_restore.test.cpp
  - tests/lis/segtree/restore.test.cpp
  - tests/lis/bisect/no_restore.test.cpp
  - tests/lis/bisect/restore.test.cpp
documentation_of: tools/lis.hpp
layout: document
title: Longest increasing subsequence
---

## (1)
```cpp
int lis::segtree<true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::segtree<true, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<true, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the length of the longest increasing subsequence.
The relationship $a_i < a_j$ is defined by $\mathrm{comp}(a_i, a_j)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
In the `segtree` function, it speeds up the DP of $O(N^2)$ time, which maximizes the length of the increasing subsequence when the last element of the increasing subsequence is $a_i$, to $O(N \log N)$ time using a segment tree.
In the `bisect` function, it sppeds up the DP of $O(N^2)$ time, which minimizes the last element of the increasing subsequence when the length of the increasing subsequence is $l$, to $O(N \log N)$ time using binary search.

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
int lis::segtree<false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::segtree<false, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
int lis::bisect<false, false>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the length of the longest non-decreasing subsequence.
The relationship $a_i \leq a_j$ is defined by $\lnot \mathrm{comp}(a_j, a_i)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
See (1).

### License
- CC0

### Author
- anqooqie

## (3)
```cpp
std::vector<int> lis::segtree<true, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
std::vector<int> lis::bisect<true, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the indices of the longest increasing subsequence.
Since there can be multiple longest increasing subsequences, the one with the smallest index sequence in lexicographic order is returned.

Formally speaking, it returns the smallest integer sequence $(i_0, i_1, \ldots, i_{k - 1})$ in lexicographic order that satisfy the following conditions:

$$\begin{align*}
i_0 < i_1 < \cdots < l_{k - 1}\\
a_{i_0} < a_{i_1} < \cdots < a_{i_{k - 1}}
\end{align*}$$

where $k$ is the length of the longest increasing subsequence, and the relationship $a_i < a_j$ is defined by $\mathrm{comp}(a_i, a_j)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
See (1).

### License
- CC0

### Author
- anqooqie

## (4)
```cpp
std::vector<int> lis::segtree<false, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
std::vector<int> lis::bisect<false, true>(InputIterator begin, InputIterator end, Compare comp = std::less<typename std::iterator_traits<InputIterator>::value_type>{});
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$, it returns the indices of the longest non-decreasing subsequence.
Since there can be multiple longest non-decreasing subsequences, the one with the smallest index sequence in lexicographic order is returned.

Formally speaking, it returns the smallest integer sequence $(i_0, i_1, \ldots, i_{k - 1})$ in lexicographic order that satisfy the following conditions:

$$\begin{align*}
i_0 < i_1 < \cdots < l_{k - 1}\\
a_{i_0} \leq a_{i_1} \leq \cdots \leq a_{i_{k - 1}}
\end{align*}$$

where $k$ is the length of the longest non-decreasing subsequence, and the relationship $a_i \leq a_j$ is defined by $\lnot \mathrm{comp}(a_j, a_i)$.

### Constraints
- `comp` is strict weak ordering.

### Time Complexity
- $O(N \log N)$

### Algorithm
See (1).

### License
- CC0

### Author
- anqooqie
