---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/detail/avl_tree_impl.hpp
    title: tools/detail/avl_tree_impl.hpp
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':heavy_check_mark:'
    path: tools/lazy_avl_tree.hpp
    title: Lazy reversible self-balancing binary search tree based on AVL tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"tests/lazy_avl_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <utility>\n#include <iostream>\n#include <vector>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\n\n\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"lib/ac-library/atcoder/internal_math.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/internal_math.hpp\"\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
    // Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned long long y = x * _m;\n        return (unsigned int)(z\
    \ - y + (z < y ? _m : 0));\n    }\n};\n\n// @param n `0 <= n`\n// @param m `1\
    \ <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n\nnamespace\
    \ atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\n\
    using is_signed_int128 =\n    typename std::conditional<std::is_same<T, __int128_t>::value\
    \ ||\n                                  std::is_same<T, __int128>::value,\n  \
    \                            std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
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
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/lazy_avl_tree.hpp\"\
    \n\n\n\n#line 1 \"tools/detail/avl_tree_impl.hpp\"\n\n\n\n#include <variant>\n\
    #line 6 \"tools/detail/avl_tree_impl.hpp\"\n#include <functional>\n#line 8 \"\
    tools/detail/avl_tree_impl.hpp\"\n#include <algorithm>\n#line 11 \"tools/detail/avl_tree_impl.hpp\"\
    \n#include <cmath>\n#line 1 \"tools/fix.hpp\"\n\n\n\n#line 6 \"tools/fix.hpp\"\
    \n\nnamespace tools {\n  template <typename F>\n  struct fix : F {\n    template\
    \ <typename G>\n    fix(G&& g) : F({::std::forward<G>(g)}) {\n    }\n\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args&&... args) const {\n\
    \      return F::operator()(*this, ::std::forward<Args>(args)...);\n    }\n  };\n\
    \n  template <typename F>\n  fix(F&&) -> fix<::std::decay_t<F>>;\n}\n\n\n#line\
    \ 13 \"tools/detail/avl_tree_impl.hpp\"\n\nnamespace tools {\n  namespace detail\
    \ {\n    namespace avl_tree {\n      struct nop_monoid {\n        using T = ::std::monostate;\n\
    \        static constexpr T op(T, T) {\n          return T{};\n        }\n   \
    \     static constexpr T e() {\n          return T{};\n        }\n      };\n \
    \     template <typename SM>\n      typename SM::T nop(typename nop_monoid::T,\
    \ const typename SM::T& x) {\n        return x;\n      }\n\n      template <bool\
    \ Reversible, typename SM, typename FM = nop_monoid, auto mapping = nop<SM>>\n\
    \      class avl_tree_impl {\n      private:\n        using S = typename SM::T;\n\
    \        using F = typename FM::T;\n        static_assert(\n          ::std::is_convertible_v<decltype(mapping),\
    \ ::std::function<S(F, S)>>,\n          \"mapping must work as S(F, S)\");\n \
    \       constexpr static bool is_lazy = !::std::is_same_v<FM, nop_monoid>;\n\n\
    \        struct node {\n          int id;\n          int l_id;\n          int\
    \ r_id;\n          int height;\n          int size;\n          S prod;\n     \
    \     ::std::conditional_t<Reversible, S, ::std::monostate> rprod;\n         \
    \ bool rev;\n          F lazy;\n        };\n\n      public:\n        class buffer\
    \ {\n        private:\n          ::std::vector<node> m_nodes;\n\n        public:\n\
    \          buffer() {\n            if constexpr (Reversible) {\n             \
    \ this->m_nodes.push_back(node{0, 0, 0, 0, 0, SM::e(), SM::e(), false, FM::e()});\n\
    \            } else {\n              this->m_nodes.push_back(node{0, 0, 0, 0,\
    \ 0, SM::e(), ::std::monostate{}, false, FM::e()});\n            }\n         \
    \ }\n          buffer(const buffer&) = default;\n          buffer(buffer&&) =\
    \ default;\n          ~buffer() = default;\n          buffer& operator=(const\
    \ buffer&) = default;\n          buffer& operator=(buffer&&) = default;\n\n  \
    \        friend ::tools::detail::avl_tree::avl_tree_impl<Reversible, SM, FM, mapping>;\n\
    \        };\n\n      private:\n        buffer *m_buffer;\n        int m_root_id;\n\
    \n        void fetch(const int id) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \          const auto& l_node = this->m_buffer->m_nodes[node.l_id];\n        \
    \  const auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\n          node.height\
    \ = 1 + ::std::max(l_node.height, r_node.height);\n          node.size = l_node.size\
    \ + r_node.size;\n          node.prod = SM::op(l_node.prod, r_node.prod);\n  \
    \        if constexpr (Reversible) {\n            node.rprod = SM::op(r_node.rprod,\
    \ l_node.rprod);\n          }\n        }\n        void propagate(const int id)\
    \ {\n          auto& node = this->m_buffer->m_nodes[id];\n          auto& l_node\
    \ = this->m_buffer->m_nodes[node.l_id];\n          auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\
    \n          assert(!(node.size == 0) || (node.id == 0 && node.l_id == 0 && node.r_id\
    \ == 0));\n          assert(!(node.size == 1) || (node.id > 0 && node.l_id ==\
    \ 0 && node.r_id == 0));\n          assert(!(node.size > 1) || (node.id > 0 &&\
    \ node.l_id > 0 && node.r_id > 0));\n\n          if constexpr (Reversible) {\n\
    \            if (node.rev) {\n              if (node.size > 1) {\n           \
    \     l_node.rev = !l_node.rev;\n                r_node.rev = !r_node.rev;\n \
    \               ::std::swap(node.l_id, node.r_id);\n                ::std::swap(node.prod,\
    \ node.rprod);\n              }\n              node.rev = false;\n           \
    \ }\n          }\n          if constexpr (is_lazy) {\n            if (node.lazy\
    \ != FM::e()) {\n              if (node.size > 1) {\n                l_node.lazy\
    \ = FM::op(node.lazy, l_node.lazy);\n                r_node.lazy = FM::op(node.lazy,\
    \ r_node.lazy);\n              }\n              node.prod = mapping(node.lazy,\
    \ node.prod);\n              if constexpr (Reversible) {\n                 node.rprod\
    \ = mapping(node.lazy, node.rprod);\n              }\n              node.lazy\
    \ = FM::e();\n            }\n          }\n        }\n\n        int add_node(const\
    \ S& x) {\n          const int id = this->m_buffer->m_nodes.size();\n        \
    \  if constexpr (Reversible) {\n            this->m_buffer->m_nodes.push_back(node{id,\
    \ 0, 0, 1, 1, x, x, false, FM::e()});\n          } else {\n            this->m_buffer->m_nodes.push_back(node{id,\
    \ 0, 0, 1, 1, x, ::std::monostate{}, false, FM::e()});\n          }\n        \
    \  return id;\n        }\n        int add_node(const int l_id, const int r_id)\
    \ {\n          const int id = this->m_buffer->m_nodes.size();\n          if constexpr\
    \ (Reversible) {\n            this->m_buffer->m_nodes.push_back(node{id, l_id,\
    \ r_id, 0, 0, SM::e(), SM::e(), false, FM::e()});\n          } else {\n      \
    \      this->m_buffer->m_nodes.push_back(node{id, l_id, r_id, 0, 0, SM::e(), ::std::monostate{},\
    \ false, FM::e()});\n          }\n          this->fetch(id);\n          return\
    \ id;\n        }\n\n        int rotate_l(const int id) {\n          auto& node\
    \ = this->m_buffer->m_nodes[id];\n          auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\
    \n          assert(node.size > 1);\n          assert(node.id > 0);\n         \
    \ assert(node.l_id > 0);\n          assert(node.r_id > 0);\n          assert(r_node.size\
    \ > 1);\n          assert(r_node.id > 0);\n          assert(r_node.l_id > 0);\n\
    \          assert(r_node.r_id > 0);\n\n          if constexpr (Reversible || is_lazy)\
    \ {\n            this->propagate(id);\n            this->propagate(node.l_id);\n\
    \            this->propagate(node.r_id);\n            this->propagate(r_node.l_id);\n\
    \            this->propagate(r_node.r_id);\n          }\n\n          node.r_id\
    \ = r_node.l_id;\n          r_node.l_id = node.id;\n\n          this->fetch(id);\n\
    \          this->fetch(r_node.id);\n\n          return r_node.id;\n        }\n\
    \        int rotate_r(const int id) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \          auto& l_node = this->m_buffer->m_nodes[node.l_id];\n\n          assert(node.size\
    \ > 1);\n          assert(node.id > 0);\n          assert(node.l_id > 0);\n  \
    \        assert(node.r_id > 0);\n          assert(l_node.size > 1);\n        \
    \  assert(l_node.id > 0);\n          assert(l_node.l_id > 0);\n          assert(l_node.r_id\
    \ > 0);\n\n          if constexpr (Reversible || is_lazy) {\n            this->propagate(id);\n\
    \            this->propagate(node.l_id);\n            this->propagate(node.r_id);\n\
    \            this->propagate(l_node.l_id);\n            this->propagate(l_node.r_id);\n\
    \          }\n\n          node.l_id = l_node.r_id;\n          l_node.r_id = node.id;\n\
    \n          this->fetch(id);\n          this->fetch(l_node.id);\n\n          return\
    \ l_node.id;\n        }\n        int height_diff(const int id) {\n          const\
    \ auto& node = this->m_buffer->m_nodes[id];\n          const auto& l_node = this->m_buffer->m_nodes[node.l_id];\n\
    \          const auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\n      \
    \    return l_node.height - r_node.height;\n        }\n        int balance(const\
    \ int id) {\n          auto& node = this->m_buffer->m_nodes[id];\n\n         \
    \ const auto diff = this->height_diff(id);\n          assert(::std::abs(diff)\
    \ <= 2);\n\n          if (diff == 2) {\n            if (this->height_diff(node.l_id)\
    \ < 0) node.l_id = this->rotate_l(node.l_id);\n            return this->rotate_r(id);\n\
    \          } else if (diff == -2) {\n            if (this->height_diff(node.r_id)\
    \ > 0) node.r_id = this->rotate_r(node.r_id);\n            return this->rotate_l(id);\n\
    \          } else {\n            return id;\n          }\n        }\n\n      \
    \  void set(const int id, const int p, const S& x) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= p && p < node.size);\n\n          if constexpr (Reversible\
    \ || is_lazy) {\n            this->propagate(id);\n          }\n          if (node.size\
    \ == 1) {\n            node.prod = x;\n          } else {\n            const auto\
    \ half = this->m_buffer->m_nodes[node.l_id].size;\n\n            if (p < half)\
    \ {\n              this->set(node.l_id, p, x);\n              if constexpr (Reversible\
    \ || is_lazy) {\n                this->propagate(node.r_id);\n              }\n\
    \            } else {\n              if constexpr (Reversible || is_lazy) {\n\
    \                this->propagate(node.l_id);\n              }\n              this->set(node.r_id,\
    \ p - half, x);\n            }\n            this->fetch(id);\n          }\n  \
    \      }\n        S prod(const int id, const int l, const int r) {\n         \
    \ auto& node = this->m_buffer->m_nodes[id];\n\n          assert(0 <= l && l <=\
    \ r && r <= node.size);\n\n          if (l == r) return SM::e();\n\n         \
    \ if constexpr (Reversible || is_lazy) {\n            this->propagate(id);\n \
    \         }\n          if (l == 0 && r == node.size) {\n            return node.prod;\n\
    \          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \n            auto res = SM::e();\n            if (l < half) res = SM::op(res,\
    \ this->prod(node.l_id, l, ::std::min(r, half)));\n            if (half < r) res\
    \ = SM::op(res, this->prod(node.r_id, ::std::max(0, l - half), r - half));\n \
    \           return res;\n          }\n        }\n        template <bool SFINAE\
    \ = is_lazy>\n        ::std::enable_if_t<SFINAE, void> apply(const int id, const\
    \ int l, const int r, const F& f) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= l && l <= r && r <= node.size);\n\n          if (l ==\
    \ r) return;\n\n          if (l == 0 && r == node.size) {\n            node.lazy\
    \ = FM::op(f, node.lazy);\n            this->propagate(id);\n          } else\
    \ {\n            this->propagate(id);\n\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \            if (l < half) {\n              this->apply(node.l_id, l, ::std::min(r,\
    \ half), f);\n            } else {\n              this->propagate(node.l_id);\n\
    \            }\n            if (half < r) {\n              this->apply(node.r_id,\
    \ ::std::max(0, l - half), r - half, f);\n            } else {\n             \
    \ this->propagate(node.r_id);\n            }\n            this->fetch(id);\n \
    \         }\n        }\n        int insert(const int id, const int p, const S&\
    \ x) {\n          auto& node = this->m_buffer->m_nodes[id];\n\n          assert(0\
    \ <= p && p <= node.size);\n\n          if constexpr (Reversible || is_lazy) {\n\
    \            this->propagate(id);\n          }\n          if (node.size == 0)\
    \ {\n            return this->add_node(x);\n          } else if (node.size ==\
    \ 1) {\n            if (p == 0) {\n              return this->add_node(this->add_node(x),\
    \ id);\n            } else {\n              return this->add_node(id, this->add_node(x));\n\
    \            }\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \n            if (p < half) {\n              if constexpr (Reversible || is_lazy)\
    \ {\n                this->propagate(node.r_id);\n              }\n          \
    \    const auto l_id = this->insert(node.l_id, p, x);\n              this->m_buffer->m_nodes[id].l_id\
    \ = l_id;\n            } else {\n              if constexpr (Reversible || is_lazy)\
    \ {\n                this->propagate(node.l_id);\n              }\n          \
    \    const auto r_id = this->insert(node.r_id, p - half, x);\n              this->m_buffer->m_nodes[id].r_id\
    \ = r_id;\n            }\n            this->fetch(id);\n            return this->balance(id);\n\
    \          }\n        }\n        int erase(const int id, const int p) {\n    \
    \      auto& node = this->m_buffer->m_nodes[id];\n\n          assert(0 <= p &&\
    \ p < node.size);\n\n          if constexpr (Reversible || is_lazy) {\n      \
    \      this->propagate(id);\n          }\n          if (node.size == 1) {\n  \
    \          return 0;\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \n            if (p < half) {\n              if constexpr (Reversible || is_lazy)\
    \ {\n                this->propagate(node.r_id);\n              }\n          \
    \    node.l_id = this->erase(node.l_id, p);\n              if (node.l_id == 0)\
    \ return node.r_id;\n            } else {\n              if constexpr (Reversible\
    \ || is_lazy) {\n                this->propagate(node.l_id);\n              }\n\
    \              node.r_id = this->erase(node.r_id, p - half);\n              if\
    \ (node.r_id == 0) return node.l_id;\n            }\n            this->fetch(id);\n\
    \            return this->balance(id);\n          }\n        }\n\n        int\
    \ merge(const int l_id, const int r_id, const int free_id) {\n          if (l_id\
    \ == 0) {\n            if constexpr (Reversible || is_lazy) {\n              this->propagate(r_id);\n\
    \            }\n            return r_id;\n          }\n          if (r_id == 0)\
    \ {\n            if constexpr (Reversible || is_lazy) {\n              this->propagate(l_id);\n\
    \            }\n            return l_id;\n          }\n\n          auto& l_node\
    \ = this->m_buffer->m_nodes[l_id];\n          auto& r_node = this->m_buffer->m_nodes[r_id];\n\
    \          const auto diff = l_node.height - r_node.height;\n          if (diff\
    \ >= 2) {\n            if constexpr (Reversible || is_lazy) {\n              this->propagate(l_id);\n\
    \              this->propagate(l_node.l_id);\n            }\n            const\
    \ auto merged_id = this->merge(l_node.r_id, r_id, free_id);\n            this->m_buffer->m_nodes[l_id].r_id\
    \ = merged_id;\n            this->fetch(l_id);\n            return this->balance(l_id);\n\
    \          } else if (diff <= -2) {\n            if constexpr (Reversible || is_lazy)\
    \ {\n              this->propagate(r_id);\n              this->propagate(r_node.r_id);\n\
    \            }\n            const auto merged_id = this->merge(l_id, r_node.l_id,\
    \ free_id);\n            this->m_buffer->m_nodes[r_id].l_id = merged_id;\n   \
    \         this->fetch(r_id);\n            return this->balance(r_id);\n      \
    \    } else {\n            if constexpr (Reversible || is_lazy) {\n          \
    \    this->propagate(l_id);\n              this->propagate(r_id);\n          \
    \  }\n            if (free_id == 0) {\n              return this->add_node(l_id,\
    \ r_id);\n            } else {\n              auto& node = this->m_buffer->m_nodes[free_id];\n\
    \              node.l_id = l_id;\n              node.r_id = r_id;\n          \
    \    if constexpr (Reversible) {\n                node.rev = false;\n        \
    \      }\n              if constexpr (is_lazy) {\n                node.lazy =\
    \ FM::e();\n              }\n              this->fetch(free_id);\n           \
    \   return free_id;\n            }\n          }\n        }\n        ::std::pair<int,\
    \ int> split(const int id, const int i) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= i && i <= node.size);\n\n          if (i == 0) return\
    \ ::std::make_pair(0, id);\n          if (i == node.size) return ::std::make_pair(id,\
    \ 0);\n\n          if constexpr (Reversible || is_lazy) {\n            this->propagate(id);\n\
    \          }\n          const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \          if (i < half) {\n            const auto [l_id, r_id] = this->split(node.l_id,\
    \ i);\n            return ::std::make_pair(l_id, this->merge(r_id, this->m_buffer->m_nodes[id].r_id,\
    \ this->m_buffer->m_nodes[id].l_id));\n          } else if (i > half) {\n    \
    \        const auto [l_id, r_id] = this->split(node.r_id, i - half);\n       \
    \     return ::std::make_pair(this->merge(this->m_buffer->m_nodes[id].l_id, l_id,\
    \ this->m_buffer->m_nodes[id].r_id), r_id);\n          } else {\n            return\
    \ ::std::make_pair(node.l_id, node.r_id);\n          }\n        }\n\n        template\
    \ <typename G>\n        ::std::pair<int, S> max_right(const int id, const int\
    \ l, const G& g, S carry) {\n          const auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= l && l <= node.size);\n\n          if constexpr (Reversible\
    \ || is_lazy) {\n            this->propagate(id);\n          }\n          if (node.size\
    \ == 0) {\n            return ::std::make_pair(0, carry);\n          } else if\
    \ (node.size == 1) {\n            if (l == 0) {\n              const auto whole\
    \ = SM::op(carry, node.prod);\n              if (g(whole)) return ::std::make_pair(1,\
    \ whole);\n              return ::std::make_pair(0, carry);\n            } else\
    \ {\n              assert(carry == SM::e());\n              return ::std::make_pair(1,\
    \ carry);\n            }\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \            int r;\n            if (l == 0) {\n              const auto whole\
    \ = SM::op(carry, node.prod);\n              if (g(whole)) return ::std::make_pair(node.size,\
    \ whole);\n\n              ::std::tie(r, carry) = this->max_right(node.l_id, 0,\
    \ g, carry);\n              if (r < half) return ::std::make_pair(r, carry);\n\
    \n              ::std::tie(r, carry) = this->max_right(node.r_id, 0, g, carry);\n\
    \              r += half;\n              return ::std::make_pair(r, carry);\n\
    \            } else {\n              assert(carry == SM::e());\n             \
    \ if (l < half) {\n                ::std::tie(r, carry) = this->max_right(node.l_id,\
    \ l, g, carry);\n                if (r < half) return ::std::make_pair(r, carry);\n\
    \              }\n              ::std::tie(r, carry) = this->max_right(node.r_id,\
    \ ::std::max(0, l - half), g, carry);\n              r += half;\n            \
    \  return ::std::make_pair(r, carry);\n            }\n          }\n        }\n\
    \        template <typename G>\n        ::std::pair<int, S> min_left(const int\
    \ id, const int r, const G& g, S carry) {\n          const auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= r && r <= node.size);\n\n          if constexpr (Reversible\
    \ || is_lazy) {\n            this->propagate(id);\n          }\n          if (node.size\
    \ == 0) {\n            return ::std::make_pair(0, carry);\n          } else if\
    \ (node.size == 1) {\n            if (r == node.size) {\n              const auto\
    \ whole = SM::op(node.prod, carry);\n              if (g(whole)) return ::std::make_pair(0,\
    \ whole);\n              return ::std::make_pair(1, carry);\n            } else\
    \ {\n              assert(carry == SM::e());\n              return ::std::make_pair(0,\
    \ carry);\n            }\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \            int l;\n            if (r == node.size) {\n              const auto\
    \ whole = SM::op(node.prod, carry);\n              if (g(whole)) return ::std::make_pair(0,\
    \ whole);\n\n              ::std::tie(l, carry) = this->min_left(node.r_id, node.size\
    \ - half, g, carry);\n              l += half;\n              if (half < l) return\
    \ ::std::make_pair(l, carry);\n\n              ::std::tie(l, carry) = this->min_left(node.l_id,\
    \ half, g, carry);\n              return ::std::make_pair(l, carry);\n       \
    \     } else {\n              assert(carry == SM::e());\n              if (half\
    \ < r) {\n                ::std::tie(l, carry) = this->min_left(node.r_id, r -\
    \ half, g, carry);\n                l += half;\n                if (half < l)\
    \ return ::std::make_pair(l, carry);\n              }\n              ::std::tie(l,\
    \ carry) = this->min_left(node.l_id, ::std::min(half, r), g, carry);\n       \
    \       return ::std::make_pair(l, carry);\n            }\n          }\n     \
    \   }\n\n      public:\n        explicit operator ::std::vector<S>() const {\n\
    \          ::std::vector<S> v;\n          if (!this->empty()) {\n            ::tools::fix([&](auto&&\
    \ dfs, const int id) -> void {\n              auto& node = this->m_buffer->m_nodes[id];\n\
    \              if constexpr (Reversible || is_lazy) {\n                this->propagate(id);\n\
    \              }\n              if (node.size == 1) {\n                v.push_back(node.prod);\n\
    \              } else {\n                dfs(node.l_id);\n                dfs(node.r_id);\n\
    \              }\n            })(this->m_root_id);\n          }\n          return\
    \ v;\n        }\n\n        avl_tree_impl() = default;\n        explicit avl_tree_impl(buffer&\
    \ buffer) : m_buffer(&buffer), m_root_id(0) {\n        }\n        avl_tree_impl(buffer&\
    \ buffer, const ::std::vector<S>& v) : m_buffer(&buffer) {\n          this->m_root_id\
    \ = v.empty() ? 0 : ::tools::fix([&](auto&& dfs, const int l, const int r) ->\
    \ int {\n            if (r - l == 1) {\n              return this->add_node(v[l]);\n\
    \            } else {\n              return this->add_node(dfs(l, (l + r) / 2),\
    \ dfs((l + r) / 2, r));\n            }\n          })(0, v.size());\n        }\n\
    \        avl_tree_impl(buffer& buffer, const int n) : avl_tree_impl(buffer, ::std::vector<S>(n,\
    \ SM::e())) {\n        }\n        avl_tree_impl(const avl_tree_impl<Reversible,\
    \ SM, FM, mapping>& other) : avl_tree_impl(*other.m_buffer, static_cast<::std::vector<S>>(other))\
    \ {\n        }\n        avl_tree_impl(avl_tree_impl<Reversible, SM, FM, mapping>&&\
    \ other) : m_buffer(other.m_buffer), m_root_id(other.m_root_id) {\n        }\n\
    \        ~avl_tree_impl() = default;\n        avl_tree_impl<Reversible, SM, FM,\
    \ mapping>& operator=(const avl_tree_impl<Reversible, SM, FM, mapping>& other)\
    \ {\n          this->m_buffer = other.m_buffer;\n          this->m_root_id = avl_tree_impl<Reversible,\
    \ SM, FM, mapping>(other).m_root_id;\n        }\n        avl_tree_impl<Reversible,\
    \ SM, FM, mapping>& operator=(avl_tree_impl<Reversible, SM, FM, mapping>&& other)\
    \ {\n          this->m_buffer = other.m_buffer;\n          this->m_root_id = other.m_root_id;\n\
    \        }\n\n        int size() const {\n          return this->m_buffer->m_nodes[this->m_root_id].size;\n\
    \        }\n        bool empty() const {\n          return this->m_root_id ==\
    \ 0;\n        }\n\n        void set(const int p, const S& x) {\n          this->set(this->m_root_id,\
    \ p, x);\n        }\n        S get(const int p) {\n          return this->prod(this->m_root_id,\
    \ p, p + 1);\n        }\n        S prod(const int l, const int r) {\n        \
    \  return this->prod(this->m_root_id, l, r);\n        }\n        S all_prod()\
    \ {\n          return this->prod(this->m_root_id, 0, this->size());\n        }\n\
    \        template <bool SFINAE = is_lazy>\n        ::std::enable_if_t<SFINAE,\
    \ void> apply(const int p, const F& f) {\n          this->apply(this->m_root_id,\
    \ p, p + 1, f);\n        }\n        template <bool SFINAE = is_lazy>\n       \
    \ ::std::enable_if_t<SFINAE, void> apply(const int l, const int r, const F& f)\
    \ {\n          this->apply(this->m_root_id, l, r, f);\n        }\n        void\
    \ insert(const int p, const S& x) {\n          this->m_root_id = this->insert(this->m_root_id,\
    \ p, x);\n        }\n        void erase(const int p) {\n          this->m_root_id\
    \ = this->erase(this->m_root_id, p);\n        }\n        void merge(avl_tree_impl<Reversible,\
    \ SM, FM, mapping>& other) {\n          assert(this->m_buffer == other.m_buffer);\n\
    \          this->m_root_id = this->merge(this->m_root_id, other.m_root_id, 0);\n\
    \          other.m_root_id = 0;\n        }\n        ::std::pair<avl_tree_impl<Reversible,\
    \ SM, FM, mapping>, avl_tree_impl<Reversible, SM, FM, mapping>> split(const int\
    \ i) {\n          avl_tree_impl<Reversible, SM, FM, mapping> l(*this->m_buffer),\
    \ r(*this->m_buffer);\n          ::std::tie(l.m_root_id, r.m_root_id) = this->split(this->m_root_id,\
    \ i);\n          return ::std::make_pair(l, r);\n        }\n        template <bool\
    \ SFINAE = Reversible>\n        ::std::enable_if_t<SFINAE, void> reverse(const\
    \ int l, const int r) {\n          assert(0 <= l && l <= r && r <= this->size());\n\
    \n          if (l == r) return;\n\n          if (l == 0) {\n            if (r\
    \ == this->size()) {\n              this->m_buffer->m_nodes[this->m_root_id].rev\
    \ = !this->m_buffer->m_nodes[this->m_root_id].rev;\n            } else {\n   \
    \           const auto [l_id, r_id] = this->split(this->m_root_id, r);\n     \
    \         this->m_buffer->m_nodes[l_id].rev = !this->m_buffer->m_nodes[l_id].rev;\n\
    \              this->m_root_id = this->merge(l_id, r_id, this->m_root_id);\n \
    \           }\n          } else {\n            if (r == this->size()) {\n    \
    \          const auto [l_id, r_id] = this->split(this->m_root_id, l);\n      \
    \        this->m_buffer->m_nodes[r_id].rev = !this->m_buffer->m_nodes[r_id].rev;\n\
    \              this->m_root_id = this->merge(l_id, r_id, this->m_root_id);\n \
    \           } else {\n              const auto [lm_id, r_id] = this->split(this->m_root_id,\
    \ r);\n              const auto [l_id, m_id] = this->split(lm_id, l);\n      \
    \        this->m_buffer->m_nodes[m_id].rev = !this->m_buffer->m_nodes[m_id].rev;\n\
    \              this->m_root_id = this->merge(this->merge(l_id, m_id, lm_id), r_id,\
    \ this->m_root_id);\n            }\n          }\n        }\n        template <typename\
    \ G>\n        int max_right(const int l, const G& g) {\n          return this->max_right(this->m_root_id,\
    \ l, g, SM::e()).first;\n        }\n        template <typename G>\n        int\
    \ min_left(const int r, const G& g) {\n          return this->min_left(this->m_root_id,\
    \ r, g, SM::e()).first;\n        }\n      };\n    }\n  }\n}\n\n\n#line 5 \"tools/lazy_avl_tree.hpp\"\
    \n\nnamespace tools {\n  template <typename SM, typename FM, auto mapping, bool\
    \ Reversible = false>\n  using lazy_avl_tree = ::tools::detail::avl_tree::avl_tree_impl<Reversible,\
    \ SM, FM, mapping>;\n}\n\n\n#line 8 \"tests/lazy_avl_tree.test.cpp\"\n\nusing\
    \ mint = atcoder::modint998244353;\n\nusing S = std::pair<int, mint>;\nstruct\
    \ SM {\n  using T = S;\n  static T op(const T& x, const T& y) {\n    return T(x.first\
    \ + y.first, x.second + y.second);\n  }\n  static T e() {\n    return T(0, mint::raw(0));\n\
    \  }\n};\nusing F = std::pair<mint, mint>;\nstruct FM {\n  using T = F;\n  static\
    \ T op(const T& f, const T& g) {\n    return F(f.first * g.first, f.first * g.second\
    \ + f.second);\n  }\n  static T e() {\n    return F(mint::raw(1), mint::raw(0));\n\
    \  }\n};\nS mapping(const F& f, const S& x) {\n  return S(x.first, f.first * x.second\
    \ + f.second * x.first);\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<S> a;\n  a.reserve(N);\n \
    \ for (int i = 0; i < N; ++i) {\n    int a_i;\n    std::cin >> a_i;\n    a.emplace_back(1,\
    \ mint::raw(a_i));\n  }\n\n  tools::lazy_avl_tree<SM, FM, mapping, true>::buffer\
    \ buffer;\n  tools::lazy_avl_tree<SM, FM, mapping, true> avl_tree(buffer, a);\n\
    \  for (int q = 0; q < Q; ++q) {\n    int t;\n    std::cin >> t;\n    if (t ==\
    \ 0) {\n      int i, x;\n      std::cin >> i >> x;\n      avl_tree.insert(i, S(1,\
    \ mint::raw(x)));\n    } else if (t == 1) {\n      int i;\n      std::cin >> i;\n\
    \      avl_tree.erase(i);\n    } else if (t == 2) {\n      int l, r;\n      std::cin\
    \ >> l >> r;\n      avl_tree.reverse(l, r);\n    } else if (t == 3) {\n      int\
    \ l, r, b, c;\n      std::cin >> l >> r >> b >> c;\n      avl_tree.apply(l, r,\
    \ F(mint::raw(b), mint::raw(c)));\n    } else {\n      int l, r;\n      std::cin\
    \ >> l >> r;\n      std::cout << avl_tree.prod(l, r).second.val() << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <utility>\n#include <iostream>\n#include <vector>\n#include \"atcoder/modint.hpp\"\
    \n#include \"tools/lazy_avl_tree.hpp\"\n\nusing mint = atcoder::modint998244353;\n\
    \nusing S = std::pair<int, mint>;\nstruct SM {\n  using T = S;\n  static T op(const\
    \ T& x, const T& y) {\n    return T(x.first + y.first, x.second + y.second);\n\
    \  }\n  static T e() {\n    return T(0, mint::raw(0));\n  }\n};\nusing F = std::pair<mint,\
    \ mint>;\nstruct FM {\n  using T = F;\n  static T op(const T& f, const T& g) {\n\
    \    return F(f.first * g.first, f.first * g.second + f.second);\n  }\n  static\
    \ T e() {\n    return F(mint::raw(1), mint::raw(0));\n  }\n};\nS mapping(const\
    \ F& f, const S& x) {\n  return S(x.first, f.first * x.second + f.second * x.first);\n\
    }\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<S> a;\n  a.reserve(N);\n \
    \ for (int i = 0; i < N; ++i) {\n    int a_i;\n    std::cin >> a_i;\n    a.emplace_back(1,\
    \ mint::raw(a_i));\n  }\n\n  tools::lazy_avl_tree<SM, FM, mapping, true>::buffer\
    \ buffer;\n  tools::lazy_avl_tree<SM, FM, mapping, true> avl_tree(buffer, a);\n\
    \  for (int q = 0; q < Q; ++q) {\n    int t;\n    std::cin >> t;\n    if (t ==\
    \ 0) {\n      int i, x;\n      std::cin >> i >> x;\n      avl_tree.insert(i, S(1,\
    \ mint::raw(x)));\n    } else if (t == 1) {\n      int i;\n      std::cin >> i;\n\
    \      avl_tree.erase(i);\n    } else if (t == 2) {\n      int l, r;\n      std::cin\
    \ >> l >> r;\n      avl_tree.reverse(l, r);\n    } else if (t == 3) {\n      int\
    \ l, r, b, c;\n      std::cin >> l >> r >> b >> c;\n      avl_tree.apply(l, r,\
    \ F(mint::raw(b), mint::raw(c)));\n    } else {\n      int l, r;\n      std::cin\
    \ >> l >> r;\n      std::cout << avl_tree.prod(l, r).second.val() << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/lazy_avl_tree.hpp
  - tools/detail/avl_tree_impl.hpp
  - tools/fix.hpp
  isVerificationFile: true
  path: tests/lazy_avl_tree.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lazy_avl_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/lazy_avl_tree.test.cpp
- /verify/tests/lazy_avl_tree.test.cpp.html
title: tests/lazy_avl_tree.test.cpp
---
