---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/auxiliary_tree.hpp
    title: Auxiliary tree
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/lca.hpp
    title: Lowest common ancestor
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc340/tasks/abc340_g
    links:
    - https://atcoder.jp/contests/abc340/tasks/abc340_g
  bundledCode: "#line 1 \"tests/auxiliary_tree.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc340/tasks/abc340_g\"\
    \n\n#include <iostream>\n#include <vector>\n#include <array>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\n\n\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"lib/ac-library/atcoder/internal_math.hpp\"\
    \n\n\n\n#include <utility>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n\
    namespace atcoder {\n\nnamespace internal {\n\n// @param m `1 <= m`\n// @return\
    \ x mod m\nconstexpr long long safe_mod(long long x, long long m) {\n    x %=\
    \ m;\n    if (x < 0) x += m;\n    return x;\n}\n\n// Fast modular multiplication\
    \ by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/auxiliary_tree.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 7 \"tools/auxiliary_tree.hpp\"\n#include <algorithm>\n\
    #include <stack>\n#include <limits>\n#include <iterator>\n#line 1 \"tools/lca.hpp\"\
    \n\n\n\n#include <cstdint>\n#line 13 \"tools/lca.hpp\"\n#include <tuple>\n#line\
    \ 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\
    \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N>\
    \ ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0))\
    \ || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/less_by.hpp\"\
    \n\n\n\nnamespace tools {\n\n  template <class F>\n  class less_by {\n  private:\n\
    \    F selector;\n\n  public:\n    less_by(const F& selector) : selector(selector)\
    \ {\n    }\n\n    template <class T>\n    bool operator()(const T& x, const T&\
    \ y) const {\n      return selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line\
    \ 1 \"tools/ceil_log2.hpp\"\n\n\n\n#line 10 \"tools/ceil_log2.hpp\"\n\n// Source:\
    \ https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
    // License: CC BY-SA 3.0\n// Author: dgobbi\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  T ceil_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::ceil_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      constexpr auto t = ::std::make_tuple(\n        ::std::array<::std::uint8_t,\
    \ 3>({\n          UINT8_C(0xf0),\n          UINT8_C(0x0c),\n          UINT8_C(0x02)\n\
    \        }),\n        ::std::array<::std::uint16_t, 4>({\n          UINT16_C(0xff00),\n\
    \          UINT16_C(0x00f0),\n          UINT16_C(0x000c),\n          UINT16_C(0x0002)\n\
    \        }),\n        ::std::array<::std::uint32_t, 5>({\n          UINT32_C(0xffff0000),\n\
    \          UINT32_C(0x0000ff00),\n          UINT32_C(0x000000f0),\n          UINT32_C(0x0000000c),\n\
    \          UINT32_C(0x00000002)\n        }),\n        ::std::array<::std::uint64_t,\
    \ 6>({\n          UINT64_C(0xffffffff00000000),\n          UINT64_C(0x00000000ffff0000),\n\
    \          UINT64_C(0x000000000000ff00),\n          UINT64_C(0x00000000000000f0),\n\
    \          UINT64_C(0x000000000000000c),\n          UINT64_C(0x0000000000000002)\n\
    \        })\n      );\n\n      T y = (((x & (x - 1)) == 0) ? 0 : 1);\n      T\
    \ j = ::std::numeric_limits<T>::digits / 2;\n\n      for (const auto t_i : ::std::get<log2(::std::numeric_limits<T>::digits)\
    \ - 3>(t)) {\n        T k = (((x & t_i) == 0) ? 0 : j);\n        y += k;\n   \
    \     x >>= k;\n        j >>= 1;\n      }\n\n      return y;\n    }\n  }\n}\n\n\
    \n#line 1 \"tools/floor_log2.hpp\"\n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\
    \n#line 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
    \ >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n\
    \    } else {\n      const auto log2 = [](const int w) {\n        if (w == 8)\
    \ return 3;\n        if (w == 16) return 4;\n        if (w == 32) return 5;\n\
    \        if (w == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      if constexpr (::std::numeric_limits<T>::digits == 8) {\n   \
    \     x = (x & UINT8_C(0x55)) + (x >> 1 & UINT8_C(0x55));\n        x = (x & UINT8_C(0x33))\
    \ + (x >> 2 & UINT8_C(0x33));\n        x = (x & UINT8_C(0x0f)) + (x >> 4 & UINT8_C(0x0f));\n\
    \      } else if constexpr (::std::numeric_limits<T>::digits == 16) {\n      \
    \  x = (x & UINT16_C(0x5555)) + (x >> 1 & UINT16_C(0x5555));\n        x = (x &\
    \ UINT16_C(0x3333)) + (x >> 2 & UINT16_C(0x3333));\n        x = (x & UINT16_C(0x0f0f))\
    \ + (x >> 4 & UINT16_C(0x0f0f));\n        x = (x & UINT16_C(0x00ff)) + (x >> 8\
    \ & UINT16_C(0x00ff));\n      } else if constexpr (::std::numeric_limits<T>::digits\
    \ == 32) {\n        x = (x & UINT32_C(0x55555555)) + (x >> 1 & UINT32_C(0x55555555));\n\
    \        x = (x & UINT32_C(0x33333333)) + (x >> 2 & UINT32_C(0x33333333));\n \
    \       x = (x & UINT32_C(0x0f0f0f0f)) + (x >> 4 & UINT32_C(0x0f0f0f0f));\n  \
    \      x = (x & UINT32_C(0x00ff00ff)) + (x >> 8 & UINT32_C(0x00ff00ff));\n   \
    \     x = (x & UINT32_C(0x0000ffff)) + (x >> 16 & UINT32_C(0x0000ffff));\n   \
    \   } else if constexpr (::std::numeric_limits<T>::digits == 64) {\n        x\
    \ = (x & UINT64_C(0x5555555555555555)) + (x >> 1 & UINT64_C(0x5555555555555555));\n\
    \        x = (x & UINT64_C(0x3333333333333333)) + (x >> 2 & UINT64_C(0x3333333333333333));\n\
    \        x = (x & UINT64_C(0x0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT64_C(0x0f0f0f0f0f0f0f0f));\n\
    \        x = (x & UINT64_C(0x00ff00ff00ff00ff)) + (x >> 8 & UINT64_C(0x00ff00ff00ff00ff));\n\
    \        x = (x & UINT64_C(0x0000ffff0000ffff)) + (x >> 16 & UINT64_C(0x0000ffff0000ffff));\n\
    \        x = (x & UINT64_C(0x00000000ffffffff)) + (x >> 32 & UINT64_C(0x00000000ffffffff));\n\
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 8 \"tools/floor_log2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  T floor_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::floor_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      x |= (x >> 1);\n      x |= (x >> 2);\n      x |= (x >> 4);\n\
    \      if constexpr (::std::numeric_limits<T>::digits > 8) x |= (x >> 8);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 16) x |= (x >> 16);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 32) x |= (x >> 32);\n  \
    \    return ::tools::popcount(x) - static_cast<T>(1);\n    }\n  }\n}\n\n\n#line\
    \ 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 19 \"tools/lca.hpp\"\n\
    \nnamespace tools {\n  class lca {\n    using u32 = ::std::uint32_t;\n    ::std::vector<::std::vector<u32>>\
    \ m_graph;\n    ::std::vector<u32> m_depth;\n    ::std::vector<u32> m_tour;\n\
    \    ::std::vector<u32> m_in;\n    u32 m_block_size;\n    ::std::vector<::std::vector<u32>>\
    \ m_sparse_table;\n    ::std::vector<::std::vector<::std::vector<u32>>> m_lookup_table;\n\
    \    ::std::vector<u32> m_patterns;\n\n    bool built() const {\n      return\
    \ !this->m_depth.empty();\n    }\n\n    u32 nblocks() const {\n      return ::tools::ceil(this->m_tour.size(),\
    \ this->m_block_size);\n    }\n\n    auto less_by_depth() const {\n      return\
    \ ::tools::less_by([&](const auto v) { return this->m_depth[v]; });\n    }\n\n\
    \  public:\n    lca() = default;\n    explicit lca(const ::std::size_t n) : m_graph(n)\
    \ {\n      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n\n    void add_edge(const ::std::size_t u, const\
    \ ::std::size_t v) {\n      assert(!this->built());\n      assert(u < this->size());\n\
    \      assert(v < this->size());\n      assert(u != v);\n      this->m_graph[u].push_back(v);\n\
    \      this->m_graph[v].push_back(u);\n    }\n\n    void build(const ::std::size_t\
    \ r) {\n      assert(!this->built());\n      assert(::std::accumulate(this->m_graph.begin(),\
    \ this->m_graph.end(), static_cast<::std::size_t>(0), [](const auto sum, const\
    \ auto& neighbors) { return sum + neighbors.size(); }) == 2 * (this->size() -\
    \ 1));\n\n      this->m_depth.assign(this->size(), ::std::numeric_limits<u32>::max());\n\
    \      this->m_tour.resize(2 * this->size() - 1);\n      this->m_in.resize(this->size());\n\
    \n      u32 t = 0;\n      ::std::stack<::std::pair<u32, u32>> stack;\n      stack.emplace(r,\
    \ 0);\n      while (!stack.empty()) {\n        const auto [here, depth] = stack.top();\n\
    \        stack.pop();\n        this->m_tour[t] = here;\n        if (this->m_depth[here]\
    \ == ::std::numeric_limits<u32>::max()) {\n          this->m_depth[here] = depth;\n\
    \          this->m_in[here] = t;\n          for (const auto next : this->m_graph[here])\
    \ {\n            if (this->m_depth[next] == ::std::numeric_limits<u32>::max())\
    \ {\n              stack.emplace(here, depth);\n              stack.emplace(next,\
    \ depth + 1);\n            }\n          }\n        }\n        ++t;\n      }\n\n\
    \      if (this->size() > 1) {\n        this->m_tour.pop_back();\n      }\n\n\
    \      this->m_block_size = ::std::max<u32>(1, ::tools::ceil(::tools::ceil_log2(this->m_tour.size()),\
    \ 2));\n      this->m_sparse_table.resize(::tools::floor_log2(this->nblocks())\
    \ + 1);\n      this->m_sparse_table[0].resize(this->nblocks());\n      for (u32\
    \ b = 0; (b + 1) * this->m_block_size <= this->m_tour.size(); ++b) {\n       \
    \ const auto l = b * this->m_block_size;\n        const auto r = ::std::min<u32>(l\
    \ + this->m_block_size, this->m_tour.size());\n        this->m_sparse_table[0][b]\
    \ = *::std::min_element(this->m_tour.begin() + l, this->m_tour.begin() + r, this->less_by_depth());\n\
    \      }\n      for (u32 h = 1; h < this->m_sparse_table.size(); ++h) {\n    \
    \    this->m_sparse_table[h].resize(this->nblocks() + UINT32_C(1) - (UINT32_C(1)\
    \ << h));\n        for (u32 b = 0; b < this->m_sparse_table[h].size(); ++b) {\n\
    \          this->m_sparse_table[h][b] = ::std::min(this->m_sparse_table[h - 1][b],\
    \ this->m_sparse_table[h - 1][b + (UINT32_C(1) << (h - 1))], this->less_by_depth());\n\
    \        }\n      }\n\n      this->m_lookup_table.resize(::tools::pow2(this->m_block_size\
    \ - 1));\n      for (u32 p = 0; p < this->m_lookup_table.size(); ++p) {\n    \
    \    this->m_lookup_table[p].resize(this->m_block_size + 1);\n        for (u32\
    \ l = 0; l <= this->m_block_size; ++l) {\n          this->m_lookup_table[p][l].resize(this->m_block_size\
    \ + 1);\n        }\n\n        ::std::vector<u32> partial_sum(this->m_block_size);\n\
    \        partial_sum[0] = this->m_block_size;\n        for (u32 i = 1; i < this->m_block_size;\
    \ ++i) {\n          partial_sum[i] = partial_sum[i - 1] - UINT32_C(1) + (((p >>\
    \ (i - 1)) & UINT32_C(1)) << 1);\n        }\n\n        for (u32 l = 0; l < this->m_block_size;\
    \ ++l) {\n          this->m_lookup_table[p][l][l + 1] = l;\n          for (u32\
    \ r = l + 2; r <= this->m_block_size; ++r) {\n            this->m_lookup_table[p][l][r]\
    \ = ::std::min(this->m_lookup_table[p][l][r - 1], r - 1, ::tools::less_by([&](const\
    \ auto i) { return partial_sum[i]; }));\n          }\n        }\n      }\n\n \
    \     this->m_patterns.resize(this->nblocks());\n      for (u32 b = 0; b * this->m_block_size\
    \ < this->m_tour.size(); ++b) {\n        const auto l = b * this->m_block_size;\n\
    \        const auto r = ::std::min<u32>(l + this->m_block_size, this->m_tour.size());\n\
    \        this->m_patterns[b] = 0;\n        for (u32 i = l; i + 1 < r; ++i) {\n\
    \          this->m_patterns[b] |= static_cast<u32>(this->m_depth[this->m_tour[i]]\
    \ < this->m_depth[this->m_tour[i + 1]]) << (i - l);\n        }\n      }\n    }\n\
    \n    ::std::size_t depth(const ::std::size_t v) const {\n      assert(this->built());\n\
    \      assert(v < this->size());\n      return this->m_depth[v];\n    }\n\n  \
    \  ::std::size_t query(::std::size_t u, ::std::size_t v) const {\n      assert(this->built());\n\
    \      assert(u < this->size());\n      assert(v < this->size());\n\n      ::std::tie(u,\
    \ v) = ::std::minmax({u, v}, ::tools::less_by([&](const auto w) { return this->m_in[w];\
    \ }));\n\n      const auto l = this->m_in[u];\n      const auto r = this->m_in[v]\
    \ + UINT32_C(1);\n      const auto bl = ::tools::ceil(l, this->m_block_size);\n\
    \      const auto br = r / this->m_block_size;\n      u32 lca;\n      if (br <\
    \ bl) {\n        lca = this->m_tour[br * this->m_block_size + this->m_lookup_table[this->m_patterns[br]][l\
    \ % this->m_block_size][r % this->m_block_size]];\n      } else {\n        lca\
    \ = u;\n        if (bl < br) {\n          const auto h = ::tools::floor_log2(br\
    \ - bl);\n          lca = ::std::min(this->m_sparse_table[h][bl], this->m_sparse_table[h][br\
    \ - (UINT32_C(1) << h)], this->less_by_depth());\n        }\n        if (l < bl\
    \ * this->m_block_size) {\n          lca = ::std::min(lca, this->m_tour[(bl -\
    \ UINT32_C(1)) * this->m_block_size + this->m_lookup_table[this->m_patterns[bl\
    \ - 1]][l % this->m_block_size][this->m_block_size]], this->less_by_depth());\n\
    \        }\n        if (br * this->m_block_size < r) {\n          lca = ::std::min(lca,\
    \ this->m_tour[br * this->m_block_size + this->m_lookup_table[this->m_patterns[br]][0][r\
    \ % this->m_block_size]], this->less_by_depth());\n        }\n      }\n\n    \
    \  return lca;\n    }\n\n    // for tools::auxiliary_tree\n    ::std::size_t internal_in(const\
    \ ::std::size_t v) const {\n      assert(this->built());\n      assert(v < this->size());\n\
    \      return this->m_in[v];\n    }\n  };\n}\n\n\n#line 1 \"tools/less_by_first.hpp\"\
    \n\n\n\n#line 5 \"tools/less_by_first.hpp\"\n\nnamespace tools {\n\n  class less_by_first\
    \ {\n  public:\n    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.first < y.first;\n\
    \    }\n  };\n}\n\n\n#line 15 \"tools/auxiliary_tree.hpp\"\n\nnamespace tools\
    \ {\n  class auxiliary_tree {\n    ::tools::lca m_lca;\n\n  public:\n    auxiliary_tree()\
    \ = default;\n    explicit auxiliary_tree(const ::std::size_t n) : m_lca(n) {\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->m_lca.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t u, const ::std::size_t v) {\n\
    \      this->m_lca.add_edge(u, v);\n    }\n\n    void build(const ::std::size_t\
    \ r) {\n      this->m_lca.build(r);\n    }\n\n    ::std::size_t depth(const ::std::size_t\
    \ v) const {\n      return this->m_lca.depth(v);\n    }\n\n    ::std::size_t lca(const\
    \ ::std::size_t u, const ::std::size_t v) const {\n      return this->m_lca.query(u,\
    \ v);\n    }\n\n    class query_result {\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> m_parent;\n      ::std::vector<::std::vector<::std::size_t>>\
    \ m_children;\n      ::std::size_t m_root;\n\n      template <typename InputIterator>\n\
    \      query_result(const ::tools::auxiliary_tree& tree, const InputIterator begin,\
    \ const InputIterator end) {\n        ::std::vector<::std::size_t> X(begin, end);\n\
    \        assert(!X.empty());\n        ::std::sort(X.begin(), X.end(), ::tools::less_by([&](const\
    \ auto v) { return tree.m_lca.internal_in(v); }));\n\n        ::std::stack<::std::size_t>\
    \ stack;\n        auto it = X.begin();\n        stack.push(*(it++));\n       \
    \ for (; it != X.end(); ++it) {\n          const auto w = tree.lca(stack.top(),\
    \ *it);\n          while (!stack.empty() && tree.depth(w) < tree.depth(stack.top()))\
    \ {\n            const auto u = stack.top();\n            stack.pop();\n     \
    \       this->m_parent.emplace_back(u, w);\n            if (!stack.empty() &&\
    \ tree.depth(w) < tree.depth(stack.top())) {\n              this->m_parent.back().second\
    \ = stack.top();\n            }\n          }\n          if (stack.empty() || stack.top()\
    \ != w) {\n            stack.push(w);\n          }\n          stack.push(*it);\n\
    \        }\n        while (!stack.empty()) {\n          const auto u = stack.top();\n\
    \          stack.pop();\n          if (stack.empty()) {\n            this->m_parent.emplace_back(u,\
    \ ::std::numeric_limits<::std::size_t>::max());\n            this->m_root = u;\n\
    \          } else {\n            this->m_parent.emplace_back(u, stack.top());\n\
    \          }\n        }\n\n        ::std::sort(this->m_parent.begin(), this->m_parent.end(),\
    \ ::tools::less_by_first{});\n\n        this->m_children.resize(this->m_parent.size());\n\
    \        for (const auto& [v, p] : this->m_parent) {\n          if (v != this->m_root)\
    \ {\n            const auto it = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(),\
    \ ::std::make_pair(p, ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});\n\
    \            assert(it != this->m_parent.end());\n            assert(it->first\
    \ == p);\n            this->m_children[::std::distance(this->m_parent.begin(),\
    \ it)].push_back(v);\n          }\n        }\n      }\n\n    public:\n      class\
    \ vertices_iterable {\n        query_result const *m_qr;\n\n      public:\n  \
    \      class iterator {\n          query_result const *m_qr;\n          ::std::size_t\
    \ m_i;\n\n        public:\n          using difference_type = ::std::ptrdiff_t;\n\
    \          using value_type = ::std::size_t;\n          using reference = const\
    \ ::std::size_t&;\n          using pointer = const ::std::size_t*;\n         \
    \ using iterator_category = ::std::input_iterator_tag;\n\n          iterator()\
    \ = default;\n          iterator(query_result const * const qr, const ::std::size_t\
    \ i) : m_qr(qr), m_i(i) {\n          }\n\n          reference operator*() const\
    \ {\n            return this->m_qr->m_parent[this->m_i].first;\n          }\n\
    \          iterator& operator++() {\n            ++this->m_i;\n            return\
    \ *this;\n          }\n          iterator operator++(int) {\n            const\
    \ auto self = *this;\n            ++*this;\n            return self;\n       \
    \   }\n          friend bool operator==(const iterator& lhs, const iterator& rhs)\
    \ {\n            assert(lhs.m_qr == rhs.m_qr);\n            return lhs.m_i ==\
    \ rhs.m_i;\n          }\n          friend bool operator!=(const iterator& lhs,\
    \ const iterator& rhs) {\n            return !(lhs == rhs);\n          }\n   \
    \     };\n\n        vertices_iterable() = default;\n        vertices_iterable(query_result\
    \ const * const qr) : m_qr(qr) {\n        }\n\n        iterator begin() const\
    \ {\n          return iterator(this->m_qr, 0);\n        };\n        iterator end()\
    \ const {\n          return iterator(this->m_qr, this->m_qr->m_parent.size());\n\
    \        }\n      };\n\n      query_result() = default;\n\n      ::std::size_t\
    \ size() const {\n        return this->m_parent.size();\n      }\n\n      vertices_iterable\
    \ vertices() const {\n        return vertices_iterable(this);\n      }\n\n   \
    \   ::std::size_t root() const {\n        return this->m_root;\n      }\n\n  \
    \    ::std::size_t parent(const ::std::size_t v) const {\n        const auto it\
    \ = ::std::lower_bound(this->m_parent.begin(), this->m_parent.end(), ::std::make_pair(v,\
    \ ::std::numeric_limits<::std::size_t>::max()), ::tools::less_by_first{});\n \
    \       assert(it != this->m_parent.end());\n        assert(it->first == v);\n\
    \        return it->second;\n      }\n\n      const ::std::vector<::std::size_t>&\
    \ children(const ::std::size_t v) const {\n        const auto it = ::std::lower_bound(this->m_parent.begin(),\
    \ this->m_parent.end(), ::std::make_pair(v, ::std::numeric_limits<::std::size_t>::max()),\
    \ ::tools::less_by_first{});\n        assert(it != this->m_parent.end());\n  \
    \      assert(it->first == v);\n        return this->m_children[::std::distance(this->m_parent.begin(),\
    \ it)];\n      }\n\n      friend ::tools::auxiliary_tree;\n    };\n\n    template\
    \ <typename InputIterator>\n    query_result query(const InputIterator begin,\
    \ const InputIterator end) const {\n      return query_result(*this, begin, end);\n\
    \    }\n\n    template <typename Z, ::std::enable_if_t<::std::is_integral_v<Z>,\
    \ ::std::nullptr_t> = nullptr>\n    query_result query(const ::std::vector<Z>&\
    \ X) const {\n      return this->query(X.begin(), X.end());\n    }\n  };\n}\n\n\
    \n#line 1 \"tools/fix.hpp\"\n\n\n\n#line 6 \"tools/fix.hpp\"\n\nnamespace tools\
    \ {\n  template <typename F>\n  struct fix : F {\n    template <typename G>\n\
    \    fix(G&& g) : F({::std::forward<G>(g)}) {\n    }\n\n    template <typename...\
    \ Args>\n    decltype(auto) operator()(Args&&... args) const {\n      return F::operator()(*this,\
    \ ::std::forward<Args>(args)...);\n    }\n  };\n\n  template <typename F>\n  fix(F&&)\
    \ -> fix<::std::decay_t<F>>;\n}\n\n\n#line 9 \"tests/auxiliary_tree.test.cpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N;\n  std::cin >> N;\n  std::vector<int>\
    \ A(N);\n  for (auto&& A_i : A) {\n    std::cin >> A_i;\n    --A_i;\n  }\n  tools::auxiliary_tree\
    \ graph(N);\n  for (int i = 0; i < N - 1; ++i) {\n    int u, v;\n    std::cin\
    \ >> u >> v;\n    --u, --v;\n    graph.add_edge(u, v);\n  }\n\n  graph.build(0);\n\
    \n  std::vector<std::vector<int>> colors(N);\n  for (int v = 0; v < N; ++v) {\n\
    \    colors[A[v]].push_back(v);\n  }\n  auto answer = mint::raw(0);\n  std::vector<std::array<mint,\
    \ 3>> dp(N);\n  for (int c = 0; c < N; ++c) {\n    if (!colors[c].empty()) {\n\
    \      const auto aux = graph.query(colors[c]);\n      tools::fix([&](auto&& dfs,\
    \ const auto v) -> void {\n        dp[v][0] = mint::raw(0);\n        dp[v][1]\
    \ = mint::raw(0);\n        dp[v][2] = mint::raw(1);\n        for (const auto u\
    \ : aux.children(v)) {\n          dfs(u);\n          dp[v][0] += dp[u][0] + mint::raw(A[u]\
    \ == c) * (mint::raw(1) + dp[u][1]) + dp[u][2];\n          dp[v][1] += mint::raw(A[u]\
    \ == c) + dp[u][1] + dp[u][2];\n          dp[v][2] *= mint::raw(A[u] == c) + dp[u][1]\
    \ + dp[u][2] + mint::raw(1);\n        }\n        dp[v][2] -= dp[v][1];\n     \
    \   --dp[v][2];\n      })(aux.root());\n      answer += dp[aux.root()][0] + mint::raw(A[aux.root()]\
    \ == c) * (mint::raw(1) + dp[aux.root()][1]) + dp[aux.root()][2];\n    }\n  }\n\
    \n  std::cout << answer.val() << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc340/tasks/abc340_g\"\n\n\
    #include <iostream>\n#include <vector>\n#include <array>\n#include \"atcoder/modint.hpp\"\
    \n#include \"tools/auxiliary_tree.hpp\"\n#include \"tools/fix.hpp\"\n\nusing mint\
    \ = atcoder::modint998244353;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N;\n  std::cin >> N;\n  std::vector<int> A(N);\n  for (auto&& A_i : A)\
    \ {\n    std::cin >> A_i;\n    --A_i;\n  }\n  tools::auxiliary_tree graph(N);\n\
    \  for (int i = 0; i < N - 1; ++i) {\n    int u, v;\n    std::cin >> u >> v;\n\
    \    --u, --v;\n    graph.add_edge(u, v);\n  }\n\n  graph.build(0);\n\n  std::vector<std::vector<int>>\
    \ colors(N);\n  for (int v = 0; v < N; ++v) {\n    colors[A[v]].push_back(v);\n\
    \  }\n  auto answer = mint::raw(0);\n  std::vector<std::array<mint, 3>> dp(N);\n\
    \  for (int c = 0; c < N; ++c) {\n    if (!colors[c].empty()) {\n      const auto\
    \ aux = graph.query(colors[c]);\n      tools::fix([&](auto&& dfs, const auto v)\
    \ -> void {\n        dp[v][0] = mint::raw(0);\n        dp[v][1] = mint::raw(0);\n\
    \        dp[v][2] = mint::raw(1);\n        for (const auto u : aux.children(v))\
    \ {\n          dfs(u);\n          dp[v][0] += dp[u][0] + mint::raw(A[u] == c)\
    \ * (mint::raw(1) + dp[u][1]) + dp[u][2];\n          dp[v][1] += mint::raw(A[u]\
    \ == c) + dp[u][1] + dp[u][2];\n          dp[v][2] *= mint::raw(A[u] == c) + dp[u][1]\
    \ + dp[u][2] + mint::raw(1);\n        }\n        dp[v][2] -= dp[v][1];\n     \
    \   --dp[v][2];\n      })(aux.root());\n      answer += dp[aux.root()][0] + mint::raw(A[aux.root()]\
    \ == c) * (mint::raw(1) + dp[aux.root()][1]) + dp[aux.root()][2];\n    }\n  }\n\
    \n  std::cout << answer.val() << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/auxiliary_tree.hpp
  - tools/lca.hpp
  - tools/ceil.hpp
  - tools/less_by.hpp
  - tools/ceil_log2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/pow2.hpp
  - tools/less_by_first.hpp
  - tools/fix.hpp
  isVerificationFile: true
  path: tests/auxiliary_tree.test.cpp
  requiredBy: []
  timestamp: '2024-09-15 21:33:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/auxiliary_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/auxiliary_tree.test.cpp
- /verify/tests/auxiliary_tree.test.cpp.html
title: tests/auxiliary_tree.test.cpp
---
