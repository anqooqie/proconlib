---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: tools/fact_mod_cache.hpp
    title: Cache for $n^{-1}, n!, n!^{-1} \pmod{P}$
  - icon: ':heavy_check_mark:'
    path: tools/garner3.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$, $\mathbb{Z} / M_2
      \mathbb{Z}$ and $\mathbb{Z} / M_3 \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':heavy_check_mark:'
    path: tools/is_group.hpp
    title: Check whether T is a group
  - icon: ':heavy_check_mark:'
    path: tools/is_monoid.hpp
    title: Check whether T is a monoid
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/join.hpp
    title: Join elements with delimiter
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/online_cumsum.hpp
    title: Online cumulative sum
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/sample_point_shift.hpp
    title: Shift of sampling points of polynomial
  - icon: ':heavy_check_mark:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':heavy_check_mark:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial
    links:
    - https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial
  bundledCode: "#line 1 \"tests/sample_point_shift.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/sample_point_shift.hpp\"\
    \n\n\n\n#line 5 \"tools/sample_point_shift.hpp\"\n#include <iterator>\n#line 7\
    \ \"tools/sample_point_shift.hpp\"\n#include <array>\n#line 9 \"tools/sample_point_shift.hpp\"\
    \n#include <initializer_list>\n#include <algorithm>\n#line 1 \"tools/is_prime.hpp\"\
    \n\n\n\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\n\
    \n\n\n#line 5 \"tools/uint128_t.hpp\"\n#include <string>\n#line 7 \"tools/uint128_t.hpp\"\
    \n#include <cstddef>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr\
    \ float abs(const float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double\
    \ abs(const double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double\
    \ abs(const long double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int\
    \ abs(const int x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const\
    \ long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const\
    \ long long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const\
    \ unsigned int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned\
    \ long x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\
    \nnamespace tools {\n  using uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t\
    \ abs(const ::tools::uint128_t& x) {\n    return x;\n  }\n}\n\n::std::istream&\
    \ operator>>(::std::istream& is, ::tools::uint128_t& x) {\n  ::std::string s;\n\
    \  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for (::std::size_t i = s[0]\
    \ == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i] && s[i] <= '9');\n    x\
    \ = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream&\
    \ os, ::tools::uint128_t x) {\n  if (x == 0) return os << '0';\n\n  ::std::string\
    \ s;\n  while (x > 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n \
    \ ::std::reverse(s.begin(), s.end());\n\n  return os << s;\n}\n\n\n#line 5 \"\
    tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template <typename T1, typename\
    \ T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m)\
    \ {\n    using u128 = ::tools::uint128_t;\n    u128 prod_mod = u128(x >= 0 ? x\
    \ : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >= 0)) prod_mod\
    \ = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\
    \n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line\
    \ 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n      return\
    \ lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return -((-lhs -\
    \ T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) + -rhs) / -rhs;\n\
    \      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const\
    \ M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const\
    \ T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3\
    \ y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n   \
    \     r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n#line 7 \"tools/is_prime.hpp\"\
    \n\nnamespace tools {\n\n  constexpr bool is_prime(const unsigned long long n)\
    \ {\n    constexpr ::std::array<unsigned long long, 7> bases = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if\
    \ (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n    auto d = n -\
    \ 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const auto a : bases) {\n  \
    \    if (a % n == 0) return true;\n\n      auto power = d;\n      auto target\
    \ = ::tools::pow_mod(a, power, n);\n\n      bool is_composite = true;\n      if\
    \ (target == 1) is_composite = false;\n      for (; is_composite && power != n\
    \ - 1; power *= 2, target = ::tools::prod_mod(target, target, n)) {\n        if\
    \ (target == n - 1) is_composite = false;\n      }\n\n      if (is_composite)\
    \ {\n        return false;\n      }\n    }\n\n    return true;\n  }\n}\n\n\n#line\
    \ 1 \"tools/fact_mod_cache.hpp\"\n\n\n\n#line 7 \"tools/fact_mod_cache.hpp\"\n\
    #include <cmath>\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 6 \"tools/ssize.hpp\"\
    \n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto ssize(const\
    \ C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 10 \"tools/fact_mod_cache.hpp\"\n\
    \nnamespace tools {\n\n  template <class M>\n  class fact_mod_cache {\n    ::std::vector<M>\
    \ m_inv;\n    ::std::vector<M> m_fact;\n    ::std::vector<M> m_fact_inv;\n\n \
    \ public:\n    fact_mod_cache() : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1),\
    \ M::raw(1)}), m_fact_inv({M::raw(1), M::raw(1)}) {\n      assert(::tools::is_prime(M::mod()));\n\
    \    }\n    explicit fact_mod_cache(const long long max) : fact_mod_cache() {\n\
    \      this->fact(::std::min<long long>(max, M::mod() - 1));\n      this->fact_inv(::std::min<long\
    \ long>(max, M::mod() - 1));\n    }\n\n    M inv(const long long n) {\n      assert(n\
    \ % M::mod() != 0);\n      const long long size = ::tools::ssize(this->m_inv);\n\
    \      this->m_inv.resize(::std::clamp<long long>(::std::abs(n) + 1, size, M::mod()));\n\
    \      for (long long i = size; i < ::tools::ssize(this->m_inv); ++i) {\n    \
    \    this->m_inv[i] = -this->m_inv[M::mod() % i] * M::raw(M::mod() / i);\n   \
    \   }\n      M result = this->m_inv[::std::abs(n) % M::mod()];\n      if (n <\
    \ 0) result = -result;\n      return result;\n    }\n    M fact(const long long\
    \ n) {\n      assert(n >= 0);\n      const long long size = ::tools::ssize(this->m_fact);\n\
    \      this->m_fact.resize(::std::clamp<long long>(n + 1, size, M::mod()));\n\
    \      for (long long i = size; i < ::tools::ssize(this->m_fact); ++i) {\n   \
    \     this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);\n      }\n      return\
    \ n < M::mod() ? this->m_fact[n] : M::raw(0);\n    }\n    M fact_inv(const long\
    \ long n) {\n      assert(0 <= n && n < M::mod());\n      const long long size\
    \ = ::tools::ssize(this->m_fact_inv);\n      this->m_fact_inv.resize(::std::max<long\
    \ long>(size, n + 1));\n      this->inv(this->m_fact_inv.size() - 1);\n      for\
    \ (long long i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {\n        this->m_fact_inv[i]\
    \ = this->m_fact_inv[i - 1] * this->m_inv[i];\n      }\n      return this->m_fact_inv[n];\n\
    \    }\n\n    M binomial(long long n, long long r) {\n      if (r < 0) return\
    \ M::raw(0);\n      if (0 <= n && n < r) return M::raw(0);\n      if (n < 0) return\
    \ M(1 - ((r & 1) << 1)) * this->binomial(-n + r - 1, r);\n\n      this->fact(::std::min<long\
    \ long>(n, M::mod() - 1));\n      this->fact_inv(::std::min<long long>(n, M::mod()\
    \ - 1));\n      const auto c = [&](const long long nn, const long long rr) {\n\
    \        return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn -\
    \ rr] * this->m_fact_inv[rr] : M::raw(0);\n      };\n\n      M result(1);\n  \
    \    while (n > 0 || r > 0) {\n        result *= c(n % M::mod(), r % M::mod());\n\
    \        n /= M::mod();\n        r /= M::mod();\n      }\n\n      return result;\n\
    \    }\n    M combination(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->binomial(n, r);\n   \
    \ }\n    M permutation(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->binomial(n, r) * this->fact(r);\n\
    \    }\n    M combination_with_repetition(const long long n, const long long r)\
    \ {\n      if (n < 0 || r < 0) return M::raw(0);\n      return this->binomial(n\
    \ + r - 1, r);\n    }\n  };\n}\n\n\n#line 1 \"tools/online_cumsum.hpp\"\n\n\n\n\
    #line 1 \"tools/is_monoid.hpp\"\n\n\n\n#line 6 \"tools/is_monoid.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename = void>\n  struct is_monoid : ::std::false_type\
    \ {};\n\n  template <typename M>\n  struct is_monoid<M, ::std::enable_if_t<\n\
    \    ::std::is_same_v<typename M::T, decltype(M::op(::std::declval<typename M::T>(),\
    \ ::std::declval<typename M::T>()))> &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n\
    \  , void>> : ::std::true_type {};\n\n  template <typename M>\n  inline constexpr\
    \ bool is_monoid_v = ::tools::is_monoid<M>::value;\n}\n\n\n#line 1 \"tools/group.hpp\"\
    \n\n\n\nnamespace tools {\n  namespace group {\n    template <typename G>\n  \
    \  struct plus {\n      using T = G;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return lhs + rhs;\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n      static T inv(const T& v) {\n        return -v;\n     \
    \ }\n    };\n\n    template <typename G>\n    struct multiplies {\n      using\
    \ T = G;\n      static T op(const T& lhs, const T& rhs) {\n        return lhs\
    \ * rhs;\n      }\n      static T e() {\n        return T(1);\n      }\n     \
    \ static T inv(const T& v) {\n        return e() / v;\n      }\n    };\n\n   \
    \ template <typename G>\n    struct bit_xor {\n      using T = G;\n      static\
    \ T op(const T& lhs, const T& rhs) {\n        return lhs ^ rhs;\n      }\n   \
    \   static T e() {\n        return T(0);\n      }\n      static T inv(const T&\
    \ v) {\n        return v;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/is_group.hpp\"\
    \n\n\n\n#line 6 \"tools/is_group.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ G, typename = void>\n  struct is_group : ::std::false_type {};\n\n  template\
    \ <typename G>\n  struct is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename\
    \ G::T>()))> &&\n    ::std::is_same_v<typename G::T, decltype(G::e())> &&\n  \
    \  ::std::is_same_v<typename G::T, decltype(G::inv(::std::declval<typename G::T>()))>\n\
    \  , void>> : ::std::true_type {};\n\n  template <typename G>\n  inline constexpr\
    \ bool is_group_v = ::tools::is_group<G>::value;\n}\n\n\n#line 11 \"tools/online_cumsum.hpp\"\
    \n\nnamespace tools {\n  template <typename X, bool Forward = true>\n  class online_cumsum\
    \ {\n    using M = ::std::conditional_t<::tools::is_monoid_v<X>, X, ::tools::group::plus<X>>;\n\
    \    using T = typename M::T;\n    ::std::vector<T> m_vector;\n    ::std::vector<T>\
    \ m_cumsum;\n    ::std::size_t m_processed;\n\n  public:\n    online_cumsum()\
    \ : online_cumsum(0) {\n    }\n    online_cumsum(const ::std::size_t n) : m_vector(n,\
    \ M::e()), m_cumsum(n + 1, M::e()), m_processed(Forward ? 0 : n) {\n    }\n\n\
    \    ::std::size_t size() const {\n      return this->m_vector.size();\n    }\n\
    \    T& operator[](const ::std::size_t i) {\n      assert(i < this->size());\n\
    \      return this->m_vector[i];\n    }\n    T prod(const ::std::size_t l, const\
    \ ::std::size_t r) {\n      assert(l <= r && r <= this->size());\n      if constexpr\
    \ (Forward) {\n        for (; this->m_processed < r; ++this->m_processed) {\n\
    \          this->m_cumsum[this->m_processed + 1] = M::op(this->m_cumsum[this->m_processed],\
    \ this->m_vector[this->m_processed]);\n        }\n        if constexpr (::tools::is_group_v<M>)\
    \ {\n          return M::op(M::inv(this->m_cumsum[l]), this->m_cumsum[r]);\n \
    \       } else {\n          assert(l == 0);\n          return this->m_cumsum[r];\n\
    \        }\n      } else {\n        for (; this->m_processed > l; --this->m_processed)\
    \ {\n          this->m_cumsum[this->m_processed - 1] = M::op(this->m_vector[this->m_processed\
    \ - 1], this->m_cumsum[this->m_processed]);\n        }\n        if constexpr (::tools::is_group_v<M>)\
    \ {\n          return M::op(this->m_cumsum[l], M::inv(this->m_cumsum[r]));\n \
    \       } else {\n          assert(r == this->size());\n          return this->m_cumsum[l];\n\
    \        }\n      }\n    }\n    template <typename Y = X>\n    ::std::enable_if_t<!::tools::is_monoid_v<Y>,\
    \ T> sum(const ::std::size_t l, const ::std::size_t r) {\n      return this->prod(l,\
    \ r);\n    }\n  };\n}\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line 5 \"tools/monoid.hpp\"\
    \n#include <limits>\n#line 7 \"tools/monoid.hpp\"\n\nnamespace tools {\n  namespace\
    \ monoid {\n    template <typename M, M E = ::std::numeric_limits<M>::lowest()>\n\
    \    struct max {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M, M E = ::std::numeric_limits<M>::max()>\n\
    \    struct min {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n\n#line 1 \"tools/convolution.hpp\"\n\n\n\n#line 5 \"tools/convolution.hpp\"\
    \n#include <complex>\n#line 1 \"lib/ac-library/atcoder/convolution.hpp\"\n\n\n\
    \n#line 9 \"lib/ac-library/atcoder/convolution.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\
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
    \ atcoder\n\n\n#line 12 \"lib/ac-library/atcoder/convolution.hpp\"\n\nnamespace\
    \ atcoder {\n\nnamespace internal {\n\ntemplate <class mint,\n          int g\
    \ = internal::primitive_root<mint::mod()>,\n          internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n    static constexpr int rank2 = countr_zero_constexpr(mint::mod()\
    \ - 1);\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n    std::array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n    std::array<mint, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\n    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;\n\
    \n    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;\n    std::array<mint,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\n\n    fft_info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n\
    \        for (int i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i\
    \ + 1] * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n \
    \       }\n\n        {\n            mint prod = 1, iprod = 1;\n            for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n                rate2[i] = root[i + 2] *\
    \ prod;\n                irate2[i] = iroot[i + 2] * iprod;\n                prod\
    \ *= iroot[i + 2];\n                iprod *= root[i + 2];\n            }\n   \
    \     }\n        {\n            mint prod = 1, iprod = 1;\n            for (int\
    \ i = 0; i <= rank2 - 3; i++) {\n                rate3[i] = root[i + 3] * prod;\n\
    \                irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i\
    \ + 3];\n                iprod *= root[i + 3];\n            }\n        }\n   \
    \ }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    int n = int(a.size());\n    int h\
    \ = internal::countr_zero((unsigned int)n);\n\n    static const fft_info<mint>\
    \ info;\n\n    int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \    while (len < h) {\n        if (h - len == 1) {\n            int p = 1 <<\
    \ (h - len - 1);\n            mint rot = 1;\n            for (int s = 0; s < (1\
    \ << len); s++) {\n                int offset = s << (h - len);\n            \
    \    for (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n\
    \                    auto r = a[i + offset + p] * rot;\n                    a[i\
    \ + offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
    \         }\n                if (s + 1 != (1 << len))\n                    rot\
    \ *= info.rate2[countr_zero(~(unsigned int)(s))];\n            }\n           \
    \ len++;\n        } else {\n            // 4-base\n            int p = 1 << (h\
    \ - len - 2);\n            mint rot = 1, imag = info.root[2];\n            for\
    \ (int s = 0; s < (1 << len); s++) {\n                mint rot2 = rot * rot;\n\
    \                mint rot3 = rot2 * rot;\n                int offset = s << (h\
    \ - len);\n                for (int i = 0; i < p; i++) {\n                   \
    \ auto mod2 = 1ULL * mint::mod() * mint::mod();\n                    auto a0 =\
    \ 1ULL * a[i + offset].val();\n                    auto a1 = 1ULL * a[i + offset\
    \ + p].val() * rot.val();\n                    auto a2 = 1ULL * a[i + offset +\
    \ 2 * p].val() * rot2.val();\n                    auto a3 = 1ULL * a[i + offset\
    \ + 3 * p].val() * rot3.val();\n                    auto a1na3imag =\n       \
    \                 1ULL * mint(a1 + mod2 - a3).val() * imag.val();\n          \
    \          auto na2 = mod2 - a2;\n                    a[i + offset] = a0 + a2\
    \ + a1 + a3;\n                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n                    a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n\
    \                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n\
    \                }\n                if (s + 1 != (1 << len))\n               \
    \     rot *= info.rate3[countr_zero(~(unsigned int)(s))];\n            }\n   \
    \         len += 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    int n = int(a.size());\n\
    \    int h = internal::countr_zero((unsigned int)n);\n\n    static const fft_info<mint>\
    \ info;\n\n    int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \    while (len) {\n        if (len == 1) {\n            int p = 1 << (h - len);\n\
    \            mint irot = 1;\n            for (int s = 0; s < (1 << (len - 1));\
    \ s++) {\n                int offset = s << (h - len + 1);\n                for\
    \ (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n   \
    \                 auto r = a[i + offset + p];\n                    a[i + offset]\
    \ = l + r;\n                    a[i + offset + p] =\n                        (unsigned\
    \ long long)(mint::mod() + l.val() - r.val()) *\n                        irot.val();\n\
    \                    ;\n                }\n                if (s + 1 != (1 <<\
    \ (len - 1)))\n                    irot *= info.irate2[countr_zero(~(unsigned\
    \ int)(s))];\n            }\n            len--;\n        } else {\n          \
    \  // 4-base\n            int p = 1 << (h - len);\n            mint irot = 1,\
    \ iimag = info.iroot[2];\n            for (int s = 0; s < (1 << (len - 2)); s++)\
    \ {\n                mint irot2 = irot * irot;\n                mint irot3 = irot2\
    \ * irot;\n                int offset = s << (h - len + 2);\n                for\
    \ (int i = 0; i < p; i++) {\n                    auto a0 = 1ULL * a[i + offset\
    \ + 0 * p].val();\n                    auto a1 = 1ULL * a[i + offset + 1 * p].val();\n\
    \                    auto a2 = 1ULL * a[i + offset + 2 * p].val();\n         \
    \           auto a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                \
    \    auto a2na3iimag =\n                        1ULL *\n                     \
    \   mint((mint::mod() + a2 - a3) * iimag.val()).val();\n\n                   \
    \ a[i + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset + 1 * p]\
    \ =\n                        (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n\
    \                    a[i + offset + 2 * p] =\n                        (a0 + a1\
    \ + (mint::mod() - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n\
    \                    a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[countr_zero(~(unsigned int)(s))];\n          \
    \  }\n            len -= 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_naive(const std::vector<mint>& a,\n\
    \                                    const std::vector<mint>& b) {\n    int n\
    \ = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   int z = (int)internal::bit_ceil((unsigned int)(n + m - 1));\n    a.resize(z);\n\
    \    internal::butterfly(a);\n    b.resize(z);\n    internal::butterfly(b);\n\
    \    for (int i = 0; i < z; i++) {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i\
    \ < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n\n}  // namespace internal\n\
    \ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint>\
    \ convolution(std::vector<mint>&& a, std::vector<mint>&& b) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    if (!n || !m) return {};\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    std::vector<mint> convolution(const std::vector<mint>& a,\n                  \
    \            const std::vector<mint>& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\n\ntemplate <unsigned int mod = 998244353,\n          class T,\n    \
    \      std::enable_if_t<internal::is_integral<T>::value>* = nullptr>\nstd::vector<T>\
    \ convolution(const std::vector<T>& a, const std::vector<T>& b) {\n    int n =\
    \ int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\n    using\
    \ mint = static_modint<mod>;\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    std::vector<mint>\
    \ a2(n), b2(m);\n    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n\
    \    }\n    for (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n\
    \    auto c2 = convolution(std::move(a2), std::move(b2));\n    std::vector<T>\
    \ c(n + m - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n\
    \    }\n    return c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long\
    \ long>& a,\n                                      const std::vector<long long>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n\n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n\
    \    static constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static\
    \ constexpr unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr\
    \ unsigned long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long\
    \ M1M3 = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n        \n    static constexpr\
    \ int MAX_AB_BIT = 24;\n    static_assert(MOD1 % (1ull << MAX_AB_BIT) == 1, \"\
    MOD1 isn't enough to support an array length of 2^24.\");\n    static_assert(MOD2\
    \ % (1ull << MAX_AB_BIT) == 1, \"MOD2 isn't enough to support an array length\
    \ of 2^24.\");\n    static_assert(MOD3 % (1ull << MAX_AB_BIT) == 1, \"MOD3 isn't\
    \ enough to support an array length of 2^24.\");\n    assert(n + m - 1 <= (1 <<\
    \ MAX_AB_BIT));\n\n    auto c1 = convolution<MOD1>(a, b);\n    auto c2 = convolution<MOD2>(a,\
    \ b);\n    auto c3 = convolution<MOD3>(a, b);\n\n    std::vector<long long> c(n\
    \ + m - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        unsigned long\
    \ long x = 0;\n        x += (c1[i] * i1) % MOD1 * M2M3;\n        x += (c2[i] *\
    \ i2) % MOD2 * M1M3;\n        x += (c3[i] * i3) % MOD3 * M1M2;\n        // B =\
    \ 2^63, -B <= x, r(real value) < B\n        // (x, x - M, x - 2M, or x - 3M) =\
    \ r (mod 2B)\n        // r = c1[i] (mod MOD1)\n        // focus on MOD1\n    \
    \    // r = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)\n        // r\
    \ = x,\n        //     x - M' + (0 or 2B),\n        //     x - 2M' + (0, 2B or\
    \ 4B),\n        //     x - 3M' + (0, 2B, 4B or 6B) (without mod!)\n        //\
    \ (r - x) = 0, (0)\n        //           - M' + (0 or 2B), (1)\n        //   \
    \        -2M' + (0 or 2B or 4B), (2)\n        //           -3M' + (0 or 2B or\
    \ 4B or 6B) (3) (mod MOD1)\n        // we checked that\n        //   ((1) mod\
    \ MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod 5 = 3\n        //   ((3) mod\
    \ MOD1) mod 5 = 4\n        long long diff =\n            c1[i] - internal::safe_mod((long\
    \ long)(x), (long long)(MOD1));\n        if (diff < 0) diff += MOD1;\n       \
    \ static constexpr unsigned long long offset[5] = {\n            0, 0, M1M2M3,\
    \ 2 * M1M2M3, 3 * M1M2M3};\n        x -= offset[diff % 5];\n        c[i] = x;\n\
    \    }\n\n    return c;\n}\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/pow2.hpp\"\
    \n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n  constexpr T pow2(const T x) {\n    return static_cast<T>(1) <<\
    \ x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#line 7 \"tools/ceil_log2.hpp\"\n#include <tuple>\n#line 9 \"tools/ceil_log2.hpp\"\
    \n#include <cstdint>\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \n#line 1 \"tools/garner3.hpp\"\n\n\n\n#line 7 \"tools/garner3.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename M1, typename M2, typename M3>\n\
    \  M garner3(const M1& a, const M2& b, const M3& c, const M m) {\n    using ull\
    \ = unsigned long long;\n    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\
    \    static const M3 m1_m2_inv_mod_m3 = (M3::raw(M1::mod()) * M3::raw(M2::mod())).inv();\n\
    \n    static const auto plus_mod = [](ull x, const ull y, const ull mod) {\n \
    \     assert(x < mod);\n      assert(y < mod);\n\n      x += y;\n      if (x >=\
    \ mod) x -= mod;\n      return x; \n    };\n\n    assert(m >= 1);\n    assert(M1::mod()\
    \ < M2::mod());\n    assert(M2::mod() < M3::mod());\n    assert(::tools::is_prime(M1::mod()));\n\
    \    assert(::tools::is_prime(M2::mod()));\n    assert(::tools::is_prime(M3::mod()));\n\
    \n    // t1 = (b - a) / M1; (mod M2)\n    // t2 = (c - a - t1 * M1) / M1 / M2;\
    \ (mod M3)\n    // return a + t1 * M1 + t2 * M1 * M2; (mod m)\n    const M2 t1\
    \ = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n    const M3 t2 = (c - M3::raw(a.val())\
    \ - M3::raw(t1.val()) * M3::raw(M1::mod())) * m1_m2_inv_mod_m3;\n    ull r = ::tools::prod_mod(t2.val(),\
    \ ull(M1::mod()) * ull(M2::mod()), m);\n    assert(r < ull(m));\n    r = plus_mod(r,\
    \ ull(t1.val()) * ull(M1::mod()) % m, m);\n    assert(r < ull(m));\n    r = plus_mod(r,\
    \ a.val() % m, m);\n    assert(r < ull(m));\n    return r;\n  }\n}\n\n\n#line\
    \ 22 \"tools/convolution.hpp\"\n\nnamespace tools {\n  namespace detail {\n  \
    \  namespace convolution {\n      template <typename T, typename = void>\n   \
    \   struct make_complex {\n        using type = T;\n      };\n\n      template\
    \ <typename T>\n      struct make_complex<T, ::std::enable_if_t<::std::is_floating_point_v<T>,\
    \ void>> {\n        using type = ::std::complex<T>;\n      };\n\n      template\
    \ <typename T>\n      using make_complex_t = typename ::tools::detail::convolution::make_complex<T>::type;\n\
    \n      template <typename AG, typename MM, typename InputIterator1, typename\
    \ InputIterator2, typename OutputIterator>\n      void naive(const InputIterator1\
    \ a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2\
    \ b_end, OutputIterator result) {\n        static_assert(::std::is_same_v<typename\
    \ AG::T, typename MM::T>);\n        assert(a_begin != a_end);\n        assert(b_begin\
    \ != b_end);\n\n        using T = typename AG::T;\n\n        const auto n = ::std::distance(a_begin,\
    \ a_end);\n        const auto m = ::std::distance(b_begin, b_end);\n\n       \
    \ ::std::vector<T> c(n + m - 1, AG::e());\n        if (n < m) {\n          auto\
    \ c_begin = c.begin();\n          for (auto b_it = b_begin; b_it != b_end; ++b_it,\
    \ ++c_begin) {\n            auto c_it = c_begin;\n            for (auto a_it =\
    \ a_begin; a_it != a_end; ++a_it, ++c_it) {\n              *c_it = AG::op(*c_it,\
    \ MM::op(*a_it, *b_it));\n            }\n          }\n        } else {\n     \
    \     auto c_begin = c.begin();\n          for (auto a_it = a_begin; a_it != a_end;\
    \ ++a_it, ++c_begin) {\n            auto c_it = c_begin;\n            for (auto\
    \ b_it = b_begin; b_it != b_end; ++b_it, ++c_it) {\n              *c_it = AG::op(*c_it,\
    \ MM::op(*a_it, *b_it));\n            }\n          }\n        }\n\n        ::std::move(c.begin(),\
    \ c.end(), result);\n      }\n\n      template <typename InputIterator1, typename\
    \ InputIterator2, typename OutputIterator>\n      void fft(const InputIterator1\
    \ a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2\
    \ b_end, OutputIterator result) {\n        using T = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;\n\
    \        static_assert(::std::is_same_v<T, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);\n\
    \        using C = ::tools::detail::convolution::make_complex_t<T>;\n        static_assert(::std::is_same_v<C,\
    \ ::std::complex<float>> || ::std::is_same_v<C, ::std::complex<double>> || ::std::is_same_v<C,\
    \ ::std::complex<long double>>);\n        using R = typename C::value_type;\n\n\
    \        assert(a_begin != a_end);\n        assert(b_begin != b_end);\n\n    \
    \    ::std::vector<C> a, b;\n        if constexpr (::std::is_same_v<T, R>) {\n\
    \          for (auto it = a_begin; it != a_end; ++it) {\n            a.emplace_back(*it,\
    \ 0);\n          }\n          for (auto it = b_begin; it != b_end; ++it) {\n \
    \           b.emplace_back(*it, 0);\n          }\n        } else if constexpr\
    \ (::std::is_same_v<T, C>) {\n          a.assign(a_begin, a_end);\n          b.assign(b_begin,\
    \ b_end);\n        }\n        const auto n = a.size() + b.size() - 1;\n      \
    \  const auto z = ::tools::pow2(::tools::ceil_log2(n));\n        a.resize(z);\n\
    \        b.resize(z);\n\n        ::std::vector<C> pow_root;\n        pow_root.reserve(z);\n\
    \        pow_root.emplace_back(1, 0);\n        if (z > 1) pow_root.push_back(::std::polar<R>(1,\
    \ R(2) * ::std::acos(R(-1)) / z));\n        for (::std::size_t p = 2; p < z; p\
    \ *= 2) {\n          pow_root.push_back(pow_root[p / 2] * pow_root[p / 2]);\n\
    \          for (::std::size_t i = p + 1; i < p * 2; ++i) {\n            pow_root.push_back(pow_root[p]\
    \ * pow_root[i - p]);\n          }\n        }\n\n        const auto butterfly\
    \ = [&](::std::vector<C>& f) {\n          ::std::vector<C> prev(z);\n        \
    \  for (::std::size_t p = z / 2; p >= 1; p /= 2) {\n            prev.swap(f);\n\
    \            for (::std::size_t qp = 0; qp < z; qp += p) {\n              for\
    \ (::std::size_t r = 0; r < p; ++r) {\n                f[qp + r] = prev[qp * 2\
    \ % z + r] + pow_root[qp] * prev[qp * 2 % z + p + r];\n              }\n     \
    \       }\n          }\n        };\n\n        butterfly(a);\n        butterfly(b);\n\
    \n        for (::std::size_t i = 0; i < z; ++i) {\n          a[i] *= b[i];\n \
    \       }\n\n        ::std::reverse(::std::next(pow_root.begin()), pow_root.end());\n\
    \        butterfly(a);\n\n        for (::std::size_t i = 0; i < n; ++i) {\n  \
    \        if constexpr (::std::is_same_v<T, R>) {\n            *result = a[i].real()\
    \ / z;\n          } else {\n            *result = a[i] / z;\n          }\n   \
    \       ++result;\n        }\n      }\n\n      template <typename InputIterator1,\
    \ typename InputIterator2, typename OutputIterator>\n      void ntt(const InputIterator1\
    \ a_begin, const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2\
    \ b_end, OutputIterator result) {\n        using M = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;\n\
    \        static_assert(::std::is_same_v<M, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);\n\
    \n        static_assert(::atcoder::internal::is_static_modint<M>::value);\n  \
    \      static_assert(2 <= M::mod() && M::mod() <= 2000000000);\n        static_assert(::tools::is_prime(M::mod()));\n\
    \        assert(a_begin != a_end);\n        assert(b_begin != b_end);\n\n    \
    \    ::std::vector<M> a(a_begin, a_end);\n        ::std::vector<M> b(b_begin,\
    \ b_end);\n        const auto n = a.size();\n        const auto m = b.size();\n\
    \        const auto z = ::tools::pow2(::tools::ceil_log2(n + m - 1));\n      \
    \  assert((M::mod() - 1) % z == 0);\n\n        if (n == m && 4 * n == z + 4) {\n\
    \n          const auto afbf = a.front() * b.front();\n          const auto abbb\
    \ = a.back() * b.back();\n\n          a.resize(z / 2);\n          ::atcoder::internal::butterfly(a);\n\
    \n          b.resize(z / 2);\n          ::atcoder::internal::butterfly(b);\n\n\
    \          for (::std::size_t i = 0; i < z / 2; ++i) {\n            a[i] *= b[i];\n\
    \          }\n\n          ::atcoder::internal::butterfly_inv(a);\n          const\
    \ auto iz = M(z / 2).inv();\n\n          *result = afbf;\n          ++result;\n\
    \          for (::std::size_t i = 1; i < n + m - 2; ++i) {\n            *result\
    \ = a[i] * iz;\n            ++result;\n          }\n          *result = abbb;\n\
    \          ++result;\n\n        } else {\n\n          a.resize(z);\n         \
    \ ::atcoder::internal::butterfly(a);\n\n          b.resize(z);\n          ::atcoder::internal::butterfly(b);\n\
    \n          for (::std::size_t i = 0; i < z; ++i) {\n            a[i] *= b[i];\n\
    \          }\n\n          ::atcoder::internal::butterfly_inv(a);\n          const\
    \ auto iz = M(z).inv();\n\n          for (::std::size_t i = 0; i < n + m - 1;\
    \ ++i) {\n            *result = a[i] * iz;\n            ++result;\n          }\n\
    \n        }\n      }\n\n      template <typename InputIterator1, typename InputIterator2,\
    \ typename OutputIterator>\n      void ntt_and_garner(const InputIterator1 a_begin,\
    \ const InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2\
    \ b_end, OutputIterator result) {\n        using M = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;\n\
    \        static_assert(::std::is_same_v<M, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);\n\
    \        using M1 = ::atcoder::static_modint<1107296257>; // 33 * 2^25 + 1\n \
    \       using M2 = ::atcoder::static_modint<1711276033>; // 51 * 2^25 + 1\n  \
    \      using M3 = ::atcoder::static_modint<1811939329>; // 27 * 2^26 + 1\n\n \
    \       static_assert(::atcoder::internal::is_static_modint<M>::value || ::atcoder::internal::is_dynamic_modint<M>::value);\n\
    \        assert(a_begin != a_end);\n        assert(b_begin != b_end);\n\n    \
    \    const auto n = ::std::distance(a_begin, a_end);\n        const auto m = ::std::distance(b_begin,\
    \ b_end);\n        const auto z = ::tools::pow2(::tools::ceil_log2(n + m - 1));\n\
    \n        assert((M1::mod() - 1) % z == 0);\n        assert((M2::mod() - 1) %\
    \ z == 0);\n        assert((M3::mod() - 1) % z == 0);\n\n        // No need for\
    \ the following assertion because the condition always holds.\n        // assert(std::min(a.size(),\
    \ b.size()) * tools::square(M::mod() - 1) < M1::mod() * M2::mod() * M3::mod());\n\
    \n        ::std::vector<M1> c1;\n        c1.reserve(n + m - 1);\n        {\n \
    \         ::std::vector<M1> a1;\n          a1.reserve(n);\n          for (auto\
    \ it = a_begin; it != a_end; ++it) {\n            a1.emplace_back(it->val());\n\
    \          }\n\n          ::std::vector<M1> b1;\n          b1.reserve(m);\n  \
    \        for (auto it = b_begin; it != b_end; ++it) {\n            b1.emplace_back(it->val());\n\
    \          }\n\n          ::tools::detail::convolution::ntt(a1.begin(), a1.end(),\
    \ b1.begin(), b1.end(), ::std::back_inserter(c1));\n        }\n\n        ::std::vector<M2>\
    \ c2;\n        c2.reserve(n + m - 1);\n        {\n          ::std::vector<M2>\
    \ a2;\n          a2.reserve(n);\n          for (auto it = a_begin; it != a_end;\
    \ ++it) {\n            a2.emplace_back(it->val());\n          }\n\n          ::std::vector<M2>\
    \ b2;\n          b2.reserve(m);\n          for (auto it = b_begin; it != b_end;\
    \ ++it) {\n            b2.emplace_back(it->val());\n          }\n\n          ::tools::detail::convolution::ntt(a2.begin(),\
    \ a2.end(), b2.begin(), b2.end(), ::std::back_inserter(c2));\n        }\n\n  \
    \      ::std::vector<M3> c3;\n        c3.reserve(n + m - 1);\n        {\n    \
    \      ::std::vector<M3> a3;\n          a3.reserve(n);\n          for (auto it\
    \ = a_begin; it != a_end; ++it) {\n            a3.emplace_back(it->val());\n \
    \         }\n\n          ::std::vector<M3> b3;\n          b3.reserve(m);\n   \
    \       for (auto it = b_begin; it != b_end; ++it) {\n            b3.emplace_back(it->val());\n\
    \          }\n\n          ::tools::detail::convolution::ntt(a3.begin(), a3.end(),\
    \ b3.begin(), b3.end(), ::std::back_inserter(c3));\n        }\n\n        for (::std::size_t\
    \ i = 0; i < c1.size(); ++i) {\n          *result = M::raw(::tools::garner3(c1[i],\
    \ c2[i], c3[i], M::mod()));\n          ++result;\n        }\n      }\n\n     \
    \ template <typename InputIterator1, typename InputIterator2, typename OutputIterator>\n\
    \      void ntt_and_garner_for_ll(const InputIterator1 a_begin, const InputIterator1\
    \ a_end, const InputIterator2 b_begin, const InputIterator2 b_end, OutputIterator\
    \ result) {\n        using Z = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;\n\
    \        static_assert(::std::is_same_v<Z, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);\n\
    \        using ll = long long;\n\n        static_assert(::std::is_integral_v<Z>);\n\
    \        assert(a_begin != a_end);\n        assert(b_begin != b_end);\n\n    \
    \    const auto n = ::std::distance(a_begin, a_end);\n        const auto m = ::std::distance(b_begin,\
    \ b_end);\n        assert(n + m - 1 <= ::tools::pow2(24));\n\n        ::std::vector<ll>\
    \ a, b;\n        a.reserve(n);\n        b.reserve(m);\n        ::std::copy(a_begin,\
    \ a_end, ::std::back_inserter(a));\n        ::std::copy(b_begin, b_end, ::std::back_inserter(b));\n\
    \n        for (const auto c_i : ::atcoder::convolution_ll(a, b)) {\n         \
    \ *result = c_i;\n          ++result;\n        }\n      }\n    }\n  }\n\n  template\
    \ <typename AG, typename MM, typename InputIterator1, typename InputIterator2,\
    \ typename OutputIterator>\n  void convolution(const InputIterator1 a_begin, const\
    \ InputIterator1 a_end, const InputIterator2 b_begin, const InputIterator2 b_end,\
    \ OutputIterator result) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;\n\
    \    static_assert(::std::is_same_v<T, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);\n\
    \n    if (a_begin == a_end || b_begin == b_end) return;\n\n    const auto n =\
    \ ::std::distance(a_begin, a_end);\n    const auto m = ::std::distance(b_begin,\
    \ b_end);\n    if (::std::min(n, m) <= 60) {\n      ::tools::detail::convolution::naive<AG,\
    \ MM>(a_begin, a_end, b_begin, b_end, result);\n      return;\n    }\n\n    if\
    \ constexpr (::std::is_same_v<AG, ::tools::group::plus<T>> && (::std::is_same_v<MM,\
    \ ::tools::monoid::multiplies<T>> || ::std::is_same_v<MM, ::tools::group::multiplies<T>>))\
    \ {\n      if constexpr (::std::is_floating_point_v<T> || ::std::is_same_v<T,\
    \ ::std::complex<float>> || ::std::is_same_v<T, ::std::complex<double>> || ::std::is_same_v<T,\
    \ ::std::complex<long double>>) {\n        ::tools::detail::convolution::fft(a_begin,\
    \ a_end, b_begin, b_end, result);\n      } else if constexpr (::std::is_integral_v<T>)\
    \ {\n        ::tools::detail::convolution::ntt_and_garner_for_ll(a_begin, a_end,\
    \ b_begin, b_end, result);\n      } else if constexpr (::atcoder::internal::is_static_modint<T>::value\
    \ || ::atcoder::internal::is_dynamic_modint<T>::value) {\n        if constexpr\
    \ (::atcoder::internal::is_static_modint<T>::value && T::mod() <= 2000000000 &&\
    \ ::tools::is_prime(T::mod())) {\n          if ((T::mod() - 1) % ::tools::pow2(::tools::ceil_log2(n\
    \ + m - 1)) == 0) {\n            ::tools::detail::convolution::ntt(a_begin, a_end,\
    \ b_begin, b_end, result);\n          } else {\n            ::tools::detail::convolution::ntt_and_garner(a_begin,\
    \ a_end, b_begin, b_end, result);\n          }\n        } else {\n          ::tools::detail::convolution::ntt_and_garner(a_begin,\
    \ a_end, b_begin, b_end, result);\n        }\n      } else {\n        ::tools::detail::convolution::naive<AG,\
    \ MM>(a_begin, a_end, b_begin, b_end, result);\n      }\n    } else {\n      ::tools::detail::convolution::naive<AG,\
    \ MM>(a_begin, a_end, b_begin, b_end, result);\n    }\n  }\n\n  template <typename\
    \ InputIterator1, typename InputIterator2, typename OutputIterator>\n  void convolution(const\
    \ InputIterator1 a_begin, const InputIterator1 a_end, const InputIterator2 b_begin,\
    \ const InputIterator2 b_end, const OutputIterator result) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator1>())>;\n\
    \    static_assert(::std::is_same_v<T, ::std::decay_t<decltype(*::std::declval<InputIterator2>())>>);\n\
    \    ::tools::convolution<::tools::group::plus<T>, ::tools::monoid::multiplies<T>>(a_begin,\
    \ a_end, b_begin, b_end, result);\n  }\n}\n\n\n#line 16 \"tools/sample_point_shift.hpp\"\
    \n\nnamespace tools {\n\n  template <typename RandomAccessIterator>\n  ::std::enable_if_t<\n\
    \    ::std::is_base_of_v<\n      ::std::random_access_iterator_tag,\n      typename\
    \ ::std::iterator_traits<RandomAccessIterator>::iterator_category\n    >,\n  \
    \  typename ::std::iterator_traits<RandomAccessIterator>::value_type\n  > sample_point_shift(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end, const typename ::std::iterator_traits<RandomAccessIterator>::value_type\
    \ c) {\n    using T = typename ::std::iterator_traits<RandomAccessIterator>::value_type;\n\
    \    assert(::tools::is_prime(T::mod()));\n    const int N = ::std::distance(begin,\
    \ end);\n    assert(1 <= N && N <= T::mod());\n    ::tools::fact_mod_cache<T>\
    \ cache;\n    const ::std::array<T, 2> minus_1_pow = {T(1), T(-1)};\n\n    ::tools::online_cumsum<::tools::monoid::multiplies<T>,\
    \ true> nl(N);\n    ::tools::online_cumsum<::tools::monoid::multiplies<T>, false>\
    \ nr(N);\n    {\n      T last = c;\n      for (int i = 0; i < N; ++i, --last)\
    \ {\n        nl[i] = nr[i] = last;\n      }\n    }\n\n    T answer(0);\n    for\
    \ (int i = 0; i < N; ++i) {\n      answer += nl.prod(0, i) * nr.prod(i + 1, N)\
    \ * minus_1_pow[(N - 1 - i) & 1] * cache.fact_inv(N - 1 - i) * cache.fact_inv(i)\
    \ * begin[i];\n    }\n\n    return answer;\n  }\n\n  template <typename InputIterator>\n\
    \  ::std::enable_if_t<\n    !::std::is_base_of_v<\n      ::std::random_access_iterator_tag,\n\
    \      typename ::std::iterator_traits<InputIterator>::iterator_category\n   \
    \ >,\n    typename ::std::iterator_traits<InputIterator>::value_type\n  > sample_point_shift(const\
    \ InputIterator begin, const InputIterator end, const typename ::std::iterator_traits<InputIterator>::value_type\
    \ c) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    const ::std::vector<T> samples(begin, end);\n    return ::tools::sample_point_shift(samples.begin(),\
    \ samples.end(), c);\n  }\n\n  template <typename T>\n  T sample_point_shift(const\
    \ ::std::initializer_list<T> il, const T c) {\n    return ::tools::sample_point_shift(il.begin(),\
    \ il.end(), c);\n  }\n\n  template <typename RandomAccessIterator, typename OutputIterator>\n\
    \  ::std::enable_if_t<\n    ::std::is_base_of_v<\n      ::std::random_access_iterator_tag,\n\
    \      typename ::std::iterator_traits<RandomAccessIterator>::iterator_category\n\
    \    >,\n    void\n  > sample_point_shift(const RandomAccessIterator begin, const\
    \ RandomAccessIterator end, const typename ::std::iterator_traits<RandomAccessIterator>::value_type\
    \ c, const int M, OutputIterator result) {\n    using T = typename ::std::iterator_traits<RandomAccessIterator>::value_type;\n\
    \    assert(::tools::is_prime(T::mod()));\n    const int N = ::std::distance(begin,\
    \ end);\n    assert(1 <= N && N <= T::mod());\n    assert(0 <= M);\n    if (M\
    \ == 1) {\n      result = ::tools::sample_point_shift(begin, end, c);\n      ++result;\n\
    \    }\n    if (M <= 1) return;\n    ::tools::fact_mod_cache<T> cache;\n    const\
    \ ::std::array<T, 2> minus_1_pow = {T(1), T(-1)};\n\n    ::std::vector<T> c1;\n\
    \    {\n      ::std::vector<T> a1(N);\n      for (int i = 0; i < N; ++i) {\n \
    \       a1[i] = begin[i] * cache.fact_inv(i);\n      }\n\n      ::std::vector<T>\
    \ b1(N);\n      for (int i = 0; i < N; ++i) {\n        b1[i] = minus_1_pow[i &\
    \ 1] * cache.fact_inv(i);\n      }\n\n      ::tools::convolution(a1.begin(), a1.end(),\
    \ b1.begin(), b1.end(), ::std::back_inserter(c1));\n      c1.resize(N);\n    }\n\
    \n    ::std::vector<T> c2;\n    {\n      ::std::vector<T> a2(N);\n      for (int\
    \ i = 0; i < N; ++i) {\n        a2[i] = c1[N - 1 - i] * cache.fact(N - 1 - i);\n\
    \      }\n\n      ::std::vector<T> b2(N);\n      b2[0] = T(1);\n      T b = c;\n\
    \      for (int i = 1; i < N; ++i, --b) {\n        b2[i] = b2[i - 1] * b;\n  \
    \    }\n      for (int i = 0; i < N; ++i) {\n        b2[i] *= cache.fact_inv(i);\n\
    \      }\n\n      ::tools::convolution(a2.begin(), a2.end(), b2.begin(), b2.end(),\
    \ ::std::back_inserter(c2));\n      c2.resize(N);\n      ::std::reverse(c2.begin(),\
    \ c2.end());\n      for (int i = 0; i < N; ++i) {\n        c2[i] *= cache.fact_inv(i);\n\
    \      }\n    }\n\n    ::std::vector<T> c3;\n    const int m = ::std::min(M, T::mod());\n\
    \    {\n      const auto& a3 = c2;\n\n      ::std::vector<T> b3(m);\n      for\
    \ (int i = 0; i < m; ++i) {\n        b3[i] = cache.fact_inv(i);\n      }\n\n \
    \     ::tools::convolution(a3.begin(), a3.end(), b3.begin(), b3.end(), ::std::back_inserter(c3));\n\
    \      c3.resize(m);\n      for (int i = 0; i < m; ++i) {\n        c3[i] *= cache.fact(i);\n\
    \      }\n    }\n\n    c3.resize(M);\n    for (int i = m; i < M; ++i) {\n    \
    \  c3[i] = c3[i % T::mod()];\n    }\n\n    ::std::copy(c3.begin(), c3.end(), result);\n\
    \  }\n\n  template <typename InputIterator, typename OutputIterator>\n  ::std::enable_if_t<\n\
    \    !::std::is_base_of_v<\n      ::std::random_access_iterator_tag,\n      typename\
    \ ::std::iterator_traits<InputIterator>::iterator_category\n    >,\n    void\n\
    \  > sample_point_shift(const InputIterator begin, const InputIterator end, const\
    \ typename ::std::iterator_traits<InputIterator>::value_type c, const int M, const\
    \ OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    const ::std::vector<T> samples(begin, end);\n    ::tools::sample_point_shift(samples.begin(),\
    \ samples.end(), c, M, result);\n  }\n\n  template <typename InputIterator>\n\
    \  ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type>\n\
    \  sample_point_shift(const InputIterator begin, const InputIterator end, const\
    \ typename ::std::iterator_traits<InputIterator>::value_type c, const int M) {\n\
    \    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n \
    \   ::std::vector<T> res;\n    ::tools::sample_point_shift(begin, end, c, M, ::std::back_inserter(res));\n\
    \    return res;\n  }\n\n  template <typename T>\n  ::std::vector<T> sample_point_shift(const\
    \ ::std::initializer_list<T> il, const T c, const int M) {\n    ::std::vector<T>\
    \ res;\n    return ::tools::sample_point_shift(il.begin(), il.end(), c, M, ::std::back_inserter(res));\n\
    \    return res;\n  }\n}\n\n\n#line 1 \"tools/join.hpp\"\n\n\n\n#line 5 \"tools/join.hpp\"\
    \n#include <sstream>\n#line 7 \"tools/join.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename Iterator>\n  ::std::string join(const Iterator begin, const Iterator\
    \ end, const ::std::string& delimiter) {\n    ::std::ostringstream ss;\n    if\
    \ (begin != end) {\n      ss << *begin;\n      for (auto it = ::std::next(begin);\
    \ it != end; ++it) {\n        ss << delimiter << *it;\n      }\n    }\n    return\
    \ ss.str();\n  }\n\n  template <typename Iterator, typename F>\n  ::std::string\
    \ join(const Iterator begin, const Iterator end, const F& mapper, const ::std::string&\
    \ delimiter) {\n    ::std::ostringstream ss;\n    if (begin != end) {\n      ss\
    \ << mapper(*begin);\n      for (auto it = ::std::next(begin); it != end; ++it)\
    \ {\n        ss << delimiter << mapper(*it);\n      }\n    }\n    return ss.str();\n\
    \  }\n}\n\n\n#line 8 \"tests/sample_point_shift.test.cpp\"\n\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, M;\n  std::cin >> N >> M;\n  mint c;\n  {\n    int c_int;\n    std::cin\
    \ >> c_int;\n    c = mint::raw(c_int);\n  }\n  std::vector<mint> f(N);\n  for\
    \ (int i = 0; i < N; ++i) {\n    int f_i;\n    std::cin >> f_i;\n    f[i] = mint::raw(f_i);\n\
    \  }\n\n  const auto g = tools::sample_point_shift(f.begin(), f.end(), c, M);\n\
    \  std::cout << tools::join(g.begin(), g.end(), [](const auto g_i) { return g_i.val();\
    \ }, \" \") << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"atcoder/modint.hpp\"\n\
    #include \"tools/sample_point_shift.hpp\"\n#include \"tools/join.hpp\"\n\nusing\
    \ mint = atcoder::modint998244353;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N, M;\n  std::cin >> N >> M;\n\
    \  mint c;\n  {\n    int c_int;\n    std::cin >> c_int;\n    c = mint::raw(c_int);\n\
    \  }\n  std::vector<mint> f(N);\n  for (int i = 0; i < N; ++i) {\n    int f_i;\n\
    \    std::cin >> f_i;\n    f[i] = mint::raw(f_i);\n  }\n\n  const auto g = tools::sample_point_shift(f.begin(),\
    \ f.end(), c, M);\n  std::cout << tools::join(g.begin(), g.end(), [](const auto\
    \ g_i) { return g_i.val(); }, \" \") << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/sample_point_shift.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/fact_mod_cache.hpp
  - tools/ssize.hpp
  - tools/online_cumsum.hpp
  - tools/is_monoid.hpp
  - tools/group.hpp
  - tools/is_group.hpp
  - tools/monoid.hpp
  - tools/convolution.hpp
  - tools/pow2.hpp
  - tools/ceil_log2.hpp
  - tools/garner3.hpp
  - tools/join.hpp
  isVerificationFile: true
  path: tests/sample_point_shift.test.cpp
  requiredBy: []
  timestamp: '2024-04-27 09:47:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sample_point_shift.test.cpp
layout: document
redirect_from:
- /verify/tests/sample_point_shift.test.cpp
- /verify/tests/sample_point_shift.test.cpp.html
title: tests/sample_point_shift.test.cpp
---
