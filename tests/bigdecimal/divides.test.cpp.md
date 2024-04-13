---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':question:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':question:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':question:'
    path: tools/garner2.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$ and $\mathbb{Z} /
      M_2 \mathbb{Z}$
  - icon: ':question:'
    path: tools/gcd.hpp
    title: std::gcd(m, n) extended for my library
  - icon: ':question:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':question:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':question:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':question:'
    path: tools/rounding_mode.hpp
    title: Rounding mode
  - icon: ':question:'
    path: tools/signum.hpp
    title: Sign function
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':question:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_D
  bundledCode: "#line 1 \"tests/bigdecimal/divides.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_D\"\n\n#include <iostream>\n#line\
    \ 1 \"tools/bigdecimal.hpp\"\n\n\n\n#include <cstddef>\n#include <algorithm>\n\
    #include <string>\n#include <cassert>\n#include <type_traits>\n#include <limits>\n\
    #include <cmath>\n#line 1 \"tools/bigint.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstdint>\n#include <array>\n#line 9 \"tools/bigint.hpp\"\n#include <iterator>\n\
    #line 13 \"tools/bigint.hpp\"\n#include <utility>\n#line 17 \"tools/bigint.hpp\"\
    \n#include <iomanip>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\n\n\n\n#line\
    \ 5 \"lib/ac-library/atcoder/modint.hpp\"\n#include <numeric>\n#line 7 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"lib/ac-library/atcoder/internal_math.hpp\"\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"lib/ac-library/atcoder/convolution.hpp\"\
    \n\n\n\n#line 9 \"lib/ac-library/atcoder/convolution.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\
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
    \    }\n\n    return c;\n}\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n\
    \      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return\
    \ -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) +\
    \ -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n\
    #line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n\
    \    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n   \
    \   return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs)\
    \ * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\n\n\n\n#line 6 \"tools/floor.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M,\
    \ N>;\n    assert(rhs != N(0));\n    return lhs / rhs - T(((lhs > M(0) && rhs\
    \ < N(0)) || (lhs < M(0) && rhs > N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"\
    tools/ssize.hpp\"\n\n\n\n#line 6 \"tools/ssize.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0))\
    \ || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/garner2.hpp\"\
    \n\n\n\n#line 1 \"tools/is_prime.hpp\"\n\n\n\n#line 1 \"tools/prod_mod.hpp\"\n\
    \n\n\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\n#line 1 \"tools/abs.hpp\"\n\n\n\n\
    namespace tools {\n  constexpr float abs(const float x) {\n    return x < 0 ?\
    \ -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x < 0 ? -x\
    \ : x;\n  }\n  constexpr long double abs(const long double x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return x < 0 ? -x\
    \ : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr long long abs(const long long x) {\n    return x < 0 ? -x :\
    \ x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n    return x;\n\
    \  }\n  constexpr unsigned long abs(const unsigned long x) {\n    return x;\n\
    \  }\n  constexpr unsigned long long abs(const unsigned long long x) {\n    return\
    \ x;\n  }\n}\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\nnamespace tools {\n  using\
    \ uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t abs(const ::tools::uint128_t&\
    \ x) {\n    return x;\n  }\n}\n\n::std::istream& operator>>(::std::istream& is,\
    \ ::tools::uint128_t& x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\
    \n  x = 0;\n  for (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0'\
    \ <= s[i] && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n\
    }\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n\
    \  if (x == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n  \
    \  s.push_back('0' + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(),\
    \ s.end());\n\n  return os << s;\n}\n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3\
    \ prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n\
    \    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n\
    \    if ((x >= 0) ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n\
    \  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 6 \"tools/pow_mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T1, typename T2, typename T3>\n\
    \  constexpr T3 pow_mod(const T1 x, T2 n, const T3 m) {\n    if (m == 1) return\
    \ 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x, m);\n    while (n > 0) {\n   \
    \   if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r, y, m);\n      }\n   \
    \   y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n    return r;\n  }\n\
    }\n\n\n#line 7 \"tools/is_prime.hpp\"\n\nnamespace tools {\n\n  constexpr bool\
    \ is_prime(const unsigned long long n) {\n    constexpr ::std::array<unsigned\
    \ long long, 7> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n\
    \    if (n <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 ==\
    \ 0) return false;\n\n    auto d = n - 1;\n    for (; d % 2 == 0; d /= 2);\n\n\
    \    for (const auto a : bases) {\n      if (a % n == 0) return true;\n\n    \
    \  auto power = d;\n      auto target = ::tools::pow_mod(a, power, n);\n\n   \
    \   bool is_composite = true;\n      if (target == 1) is_composite = false;\n\
    \      for (; is_composite && power != n - 1; power *= 2, target = ::tools::prod_mod(target,\
    \ target, n)) {\n        if (target == n - 1) is_composite = false;\n      }\n\
    \n      if (is_composite) {\n        return false;\n      }\n    }\n\n    return\
    \ true;\n  }\n}\n\n\n#line 6 \"tools/garner2.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M1, typename M2>\n  long long garner2(const M1& a, const M2& b) {\n\
    \    using ull = unsigned long long;\n    static constexpr ull m1_m2 = ull(M1::mod())\
    \ * ull(M2::mod());\n    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\
    \n    assert(M1::mod() < M2::mod());\n    assert(::tools::is_prime(M1::mod()));\n\
    \    assert(::tools::is_prime(M2::mod()));\n\n    // t = (b - a) / M1; (mod M2)\n\
    \    // return a + t * M1;\n    const M2 t = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n\
    \    ull r = t.val();\n    r *= M1::mod();\n    r += a.val();\n    if (r >= m1_m2)\
    \ r -= m1_m2;\n    return r;\n  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line\
    \ 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/gcd.hpp\"\n\
    \n\n\n#line 6 \"tools/gcd.hpp\"\n\nnamespace tools {\n  template <typename M,\
    \ typename N>\n  constexpr ::std::common_type_t<M, N> gcd(const M m, const N n)\
    \ {\n    return ::std::gcd(m, n);\n  }\n}\n\n\n#line 30 \"tools/bigint.hpp\"\n\
    \nnamespace tools {\n  class bigint {\n  private:\n    using mint1 = ::atcoder::static_modint<167772161>;\n\
    \    using mint2 = ::atcoder::static_modint<469762049>;\n\n    bool m_positive;\n\
    \    ::std::vector<::std::int_fast32_t> m_digits;\n    static constexpr ::std::int_fast32_t\
    \ BASE = 10000;\n    static constexpr ::std::int_fast32_t LOG10_BASE = 4;\n  \
    \  static constexpr ::std::array<::std::int_fast32_t, 5> POW10 = {1, 10, 100,\
    \ 1000, 10000};\n\n    static int compare_3way(const ::std::size_t lhs, const\
    \ ::std::size_t rhs) {\n      if (lhs < rhs) return -1;\n      if (lhs == rhs)\
    \ return 0;\n      return 1;\n    }\n    static int compare_3way_abs(const ::tools::bigint&\
    \ lhs, const ::tools::bigint& rhs) {\n      if (const auto comp = ::tools::bigint::compare_3way(lhs.m_digits.size(),\
    \ rhs.m_digits.size()); comp != 0) {\n        return comp;\n      }\n      for\
    \ (::std::size_t i = 0; i < lhs.m_digits.size(); ++i) {\n        if (const auto\
    \ comp = ::tools::bigint::compare_3way(lhs.m_digits[lhs.m_digits.size() - 1 -\
    \ i], rhs.m_digits[rhs.m_digits.size() - 1 - i]); comp != 0) {\n          return\
    \ comp;\n        }\n      }\n      return 0;\n    }\n\n    ::tools::bigint& regularize(const\
    \ int level) {\n      if (level > 0) {\n        if (level == 2) {\n          for\
    \ (::std::size_t i = 0; i + 1 < this->m_digits.size(); ++i) {\n            this->m_digits[i\
    \ + 1] += ::tools::quo(this->m_digits[i], BASE);\n            this->m_digits[i]\
    \ = ::tools::mod(this->m_digits[i], BASE);\n          }\n        } else {\n  \
    \        for (::std::size_t i = 0; i + 1 < this->m_digits.size(); ++i) {\n   \
    \         if (this->m_digits[i] < 0) {\n              this->m_digits[i] += BASE;\n\
    \              --this->m_digits[i + 1];\n            } else if (this->m_digits[i]\
    \ >= BASE) {\n              this->m_digits[i] -= BASE;\n              ++this->m_digits[i\
    \ + 1];\n            }\n          }\n        }\n        if (!this->m_digits.empty()\
    \ && this->m_digits.back() < 0) {\n          this->m_positive = !this->m_positive;\n\
    \          for (::std::size_t i = 0; i < this->m_digits.size(); ++i) {\n     \
    \       this->m_digits[i] = -this->m_digits[i];\n          }\n          for (::std::size_t\
    \ i = 0; i + 1 < this->m_digits.size(); ++i) {\n            if (this->m_digits[i]\
    \ < 0) {\n              this->m_digits[i] = BASE + this->m_digits[i];\n      \
    \        --this->m_digits[i + 1];\n            }\n          }\n        }\n   \
    \     if (level == 2) {\n          while (!this->m_digits.empty() && this->m_digits.back()\
    \ >= BASE) {\n            this->m_digits.push_back(this->m_digits.back() / BASE);\n\
    \            this->m_digits[this->m_digits.size() - 2] %= BASE;\n          }\n\
    \        } else {\n          if (!this->m_digits.empty() && this->m_digits.back()\
    \ >= BASE) {\n            this->m_digits.back() -= BASE;\n            this->m_digits.push_back(1);\n\
    \          }\n        }\n      }\n      while (!this->m_digits.empty() && this->m_digits.back()\
    \ == 0) {\n        this->m_digits.pop_back();\n      }\n      if (this->m_digits.empty()\
    \ && !this->m_positive) {\n        this->m_positive = true;\n      }\n      return\
    \ *this;\n    }\n\n  public:\n    ::tools::bigint& negate() {\n      if (!this->m_digits.empty())\
    \ {\n        this->m_positive = !this->m_positive;\n      }\n      return *this;\n\
    \    }\n    ::tools::bigint& multiply_by_pow10(const ::std::ptrdiff_t exponent)\
    \ {\n      if (!this->m_digits.empty()) {\n        const ::std::ptrdiff_t exponent10000\
    \ = ::tools::floor(exponent, LOG10_BASE);\n        ::std::int_fast32_t mod = 0;\n\
    \        if (exponent10000 > 0) {\n          ::std::vector<::std::int_fast32_t>\
    \ zero(exponent10000, 0);\n          this->m_digits.insert(this->m_digits.begin(),\
    \ zero.begin(), zero.end());\n        } else if (exponent10000 < 0) {\n      \
    \    if (::tools::ssize(this->m_digits) >= -exponent10000) {\n            mod\
    \ = this->m_digits[-exponent10000 - 1] / POW10[LOG10_BASE * (exponent10000 + 1)\
    \ - exponent];\n          }\n          this->m_digits.erase(this->m_digits.begin(),\
    \ this->m_digits.begin() + ::std::min<::std::size_t>(-exponent10000, this->m_digits.size()));\n\
    \        }\n        if (const ::std::int_fast32_t coefficient = POW10[exponent\
    \ - LOG10_BASE * exponent10000]; coefficient > POW10[0]) {\n          for (auto&\
    \ d : this->m_digits) {\n            d *= coefficient;\n          }\n        \
    \  if (mod > 0) {\n            if (this->m_digits.empty()) {\n              this->m_digits.push_back(0);\n\
    \            }\n            this->m_digits[0] += mod;\n          }\n         \
    \ this->regularize(2);\n        } else {\n          this->regularize(0);\n   \
    \     }\n      }\n      return *this;\n    }\n    ::tools::bigint& divide_by_pow10(const\
    \ ::std::ptrdiff_t exponent) {\n      this->multiply_by_pow10(-exponent);\n  \
    \    return *this;\n    }\n    static int compare_3way(const ::tools::bigint&\
    \ lhs, const ::tools::bigint& rhs) {\n      if (!lhs.m_positive && rhs.m_positive)\
    \ return -1;\n      if (lhs.m_positive && !rhs.m_positive) return 1;\n      return\
    \ ::tools::bigint::compare_3way_abs(lhs, rhs) * (lhs.m_positive ? 1 : -1);\n \
    \   }\n    int signum() const {\n      if (!this->m_positive) return -1;\n   \
    \   if (this->m_digits.empty()) return 0;\n      return 1;\n    }\n    ::std::size_t\
    \ size() const {\n      if (this->m_digits.empty()) return 0;\n      return LOG10_BASE\
    \ * (this->m_digits.size() - 1) + ::std::distance(POW10.begin(), ::std::upper_bound(POW10.begin(),\
    \ POW10.end(), this->m_digits[this->m_digits.size() - 1]));\n    }\n    ::std::int_fast32_t\
    \ operator[](const ::std::size_t i) const {\n      return i < LOG10_BASE * this->m_digits.size()\
    \ ? this->m_digits[i / LOG10_BASE] / POW10[i % LOG10_BASE] % 10 : 0;\n    }\n\n\
    \  private:\n    ::tools::bigint& internal_add(const ::tools::bigint& other, const\
    \ bool plus) {\n      const bool this_positive = this->m_positive;\n      if (!this_positive)\
    \ {\n        this->negate();\n      }\n      this->m_digits.resize(::std::max(this->m_digits.size(),\
    \ other.m_digits.size()));\n      if (this_positive == (other.m_positive == plus))\
    \ {\n        for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {\n   \
    \       this->m_digits[i] += other.m_digits[i];\n        }\n      } else {\n \
    \       for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {\n        \
    \  this->m_digits[i] -= other.m_digits[i];\n        }\n      }\n      this->regularize(1);\n\
    \      if (!this_positive) {\n        this->negate();\n      }\n      return *this;\n\
    \    }\n\n  public:\n    bigint() : m_positive(true) {\n    }\n    bigint(const\
    \ ::tools::bigint&) = default;\n    bigint(::tools::bigint&&) = default;\n   \
    \ ~bigint() = default;\n    ::tools::bigint& operator=(const ::tools::bigint&)\
    \ = default;\n    ::tools::bigint& operator=(::tools::bigint&&) = default;\n\n\
    \    template <typename T, typename ::std::enable_if<::std::is_integral_v<T>,\
    \ ::std::nullptr_t>::type = nullptr>\n    explicit bigint(T n) : m_positive(n\
    \ >= 0) {\n      while (n != 0) {\n        this->m_digits.push_back(n % BASE);\n\
    \        n /= BASE;\n      }\n      if (!this->m_positive) {\n        for (auto&\
    \ d : this->m_digits) {\n          d = -d;\n        }\n      }\n    }\n    explicit\
    \ bigint(const ::std::string& s) {\n      assert(!s.empty());\n\n      ::std::size_t\
    \ offset;\n      if (s[0] == '+') {\n        this->m_positive = true;\n      \
    \  offset = 1;\n      } else if (s[0] == '-') {\n        this->m_positive = false;\n\
    \        offset = 1;\n      } else {\n        this->m_positive = true;\n     \
    \   offset = 0;\n      }\n\n      this->m_digits.reserve(::tools::ceil<::std::size_t>(s.size()\
    \ - offset, LOG10_BASE));\n      for (::std::size_t i = 0; i < s.size() - offset;\
    \ i += LOG10_BASE) {\n        this->m_digits.push_back(0);\n        for (::std::size_t\
    \ j = ::std::min(i + LOG10_BASE, s.size() - offset); j --> i;) {\n          assert('0'\
    \ <= s[s.size() - 1 - j] && s[s.size() - 1 - j] <= '9');\n          this->m_digits.back()\
    \ = this->m_digits.back() * 10 + (s[s.size() - 1 - j] - '0');\n        }\n   \
    \   }\n\n      this->regularize(0);\n    }\n\n    friend bool operator==(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return lhs.m_positive\
    \ == rhs.m_positive && lhs.m_digits == rhs.m_digits;\n    }\n    friend bool operator!=(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return !(lhs == rhs);\n\
    \    }\n    friend bool operator<(const ::tools::bigint& lhs, const ::tools::bigint&\
    \ rhs) {\n      return ::tools::bigint::compare_3way(lhs, rhs) < 0;\n    }\n \
    \   friend bool operator>(const ::tools::bigint& lhs, const ::tools::bigint& rhs)\
    \ {\n      return ::tools::bigint::compare_3way(lhs, rhs) > 0;\n    }\n    friend\
    \ bool operator<=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n\
    \      return ::tools::bigint::compare_3way(lhs, rhs) <= 0;\n    }\n    friend\
    \ bool operator>=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n\
    \      return ::tools::bigint::compare_3way(lhs, rhs) >= 0;\n    }\n\n    ::tools::bigint\
    \ operator+() const {\n      return *this;\n    }\n    ::tools::bigint operator-()\
    \ const {\n      return ::tools::bigint(*this).negate();\n    }\n\n    ::tools::bigint&\
    \ operator+=(const ::tools::bigint& other) {\n      return this->internal_add(other,\
    \ true);\n    }\n    ::tools::bigint& operator-=(const ::tools::bigint& other)\
    \ {\n      return this->internal_add(other, false);\n    }\n    ::tools::bigint&\
    \ operator*=(const ::tools::bigint& other) {\n      // Constraint derived from\
    \ atcoder::convolution\n      assert(this->m_digits.size() + other.m_digits.size()\
    \ <= ::tools::pow2(25) + 1);\n\n      ::std::vector<mint1> a1, b1;\n      ::std::vector<mint2>\
    \ a2, b2;\n      a1.reserve(this->m_digits.size());\n      a2.reserve(this->m_digits.size());\n\
    \      b1.reserve(other.m_digits.size());\n      b2.reserve(other.m_digits.size());\n\
    \      for (const auto a_i : this->m_digits) {\n        a1.push_back(mint1::raw(a_i));\n\
    \        a2.push_back(mint2::raw(a_i));\n      }\n      for (const auto b_i :\
    \ other.m_digits) {\n        b1.push_back(mint1::raw(b_i));\n        b2.push_back(mint2::raw(b_i));\n\
    \      }\n\n      const auto c1 = ::atcoder::convolution(a1, b1);\n      const\
    \ auto c2 = ::atcoder::convolution(a2, b2);\n\n      this->m_digits.clear();\n\
    \      this->m_digits.reserve(c1.size() + 1);\n      long long carry = 0;\n  \
    \    for (::std::size_t i = 0; i < c1.size(); ++i) {\n\n        // Since a_i <=\
    \ 10^4 - 1 and b_i <= 10^4 - 1, c_i <= (10^4 - 1)^2 * min(this->m_digits.size(),\
    \ other.m_digits.size()) holds.\n        // In addition, since this->m_digits.size()\
    \ + other.m_digits.size() <= 2^25 + 1, c_i <= (10^4 - 1)^2 * 2^24 = 1677386072457216\
    \ holds eventually.\n        // 1677386072457216 < 167772161 * 469762049 = 78812994116517889\
    \ holds, so we can reconstruct c_i from mod(c_i, 167772161) and mod(c_i, 469762049)\
    \ by CRT.\n        long long c_i = ::tools::garner2(c1[i], c2[i]);\n\n       \
    \ c_i += carry;\n        carry = c_i / BASE;\n        c_i %= BASE;\n        this->m_digits.push_back(c_i);\n\
    \      }\n      if (carry > 0) {\n        this->m_digits.push_back(carry);\n \
    \     }\n\n      this->m_positive = this->m_positive == other.m_positive;\n  \
    \    this->regularize(0);\n      return *this;\n    }\n\n    friend ::tools::bigint\
    \ operator+(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return\
    \ ::tools::bigint(lhs) += rhs;\n    }\n    friend ::tools::bigint operator-(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return ::tools::bigint(lhs)\
    \ -= rhs;\n    }\n    friend ::tools::bigint operator*(const ::tools::bigint&\
    \ lhs, const ::tools::bigint& rhs) {\n      return ::tools::bigint(lhs) *= rhs;\n\
    \    }\n\n    ::tools::bigint& operator++() {\n      return *this += ::tools::bigint(1);\n\
    \    }\n    ::tools::bigint operator++(int) {\n      ::tools::bigint old(*this);\n\
    \      ++(*this);\n      return old;\n    }\n    ::tools::bigint& operator--()\
    \ {\n      return *this -= ::tools::bigint(1);\n    }\n    ::tools::bigint operator--(int)\
    \ {\n      ::tools::bigint old(*this);\n      --(*this);\n      return old;\n\
    \    }\n\n    ::tools::bigint& operator/=(const ::tools::bigint& other) {\n  \
    \    assert(other.signum() != 0);\n      if (::tools::bigint::compare_3way_abs(*this,\
    \ other) < 0) {\n        this->m_digits.clear();\n        this->m_positive = true;\
    \        \n        return *this;\n      }\n      if (other.m_digits.size() ==\
    \ 1 && other.m_digits[0] == 1) {\n        this->m_positive = (this->m_positive\
    \ == other.m_positive);\n        return *this;\n      }\n\n      using u64 = ::std::uint_fast64_t;\n\
    \      static const ::tools::bigint u64_threshold((::std::numeric_limits<u64>::max()\
    \ - (BASE - 1)) / BASE);\n      using u128 = ::tools::uint128_t;\n      static\
    \ const ::tools::bigint u128_threshold(\"34028236692093846346337460743176820\"\
    );\n\n      #define TOOLS_BIGINT_NAIVE(type) do {\\\n        if (::tools::bigint::compare_3way_abs(other,\
    \ type ## _threshold) <= 0) { \\\n          type mod = 0;\\\n          for (::std::size_t\
    \ i = other.m_digits.size(); i --> 0;) {\\\n            mod *= BASE;\\\n     \
    \       mod += other.m_digits[i];\\\n          }\\\n          \\\n          type\
    \ carry = 0;\\\n          for (::std::size_t i = this->m_digits.size(); i--> 0;)\
    \ {\\\n            carry *= BASE;\\\n            carry += this->m_digits[i];\\\
    \n            this->m_digits[i] = carry / mod;\\\n            carry %= mod;\\\n\
    \          }\\\n          \\\n          this->m_positive = (this->m_positive ==\
    \ other.m_positive);\\\n          return this->regularize(0);\\\n        }\\\n\
    \      } while (false)\n\n      TOOLS_BIGINT_NAIVE(u64);\n      TOOLS_BIGINT_NAIVE(u128);\n\
    \n      #undef TOOLS_BIGINT_NAIVE\n\n      using bigdecimal = ::std::pair<::tools::bigint,\
    \ ::std::ptrdiff_t>;\n      static const auto precision = [](const bigdecimal&\
    \ x) {\n        return x.first.m_digits.size();\n      };\n      static const\
    \ auto regularize = [](bigdecimal& x) -> bigdecimal& {\n        if (x.first.m_digits.empty())\
    \ {\n          x.second = 0;\n        }\n        return x;\n      };\n      static\
    \ const auto negate = [](bigdecimal& x) -> bigdecimal& {\n        x.first.negate();\n\
    \        return x;\n      };\n      static const auto make_abs = [](bigdecimal&\
    \ x) -> bigdecimal& {\n        if (!x.first.m_positive) {\n          negate(x);\n\
    \        }\n        return x;\n      };\n      static const auto set_precision\
    \ = [](bigdecimal& x, const ::std::size_t p) -> bigdecimal& {\n        const ::std::ptrdiff_t\
    \ diff = ::std::ptrdiff_t(p) - ::std::ptrdiff_t(precision(x));\n        x.first.multiply_by_pow10(diff\
    \ * LOG10_BASE);\n        x.second -= diff;\n        regularize(x);\n        return\
    \ x;\n      };\n      static const auto plus = [](bigdecimal& x, bigdecimal& y)\
    \ -> bigdecimal& {\n        if (x.second < y.second) {\n          set_precision(y,\
    \ precision(y) + (y.second - x.second));\n        } else if (x.second > y.second)\
    \ {\n          set_precision(x, precision(x) + (x.second - y.second));\n     \
    \   }\n        x.first += y.first;\n        regularize(x);\n        return x;\n\
    \      };\n      static const auto multiplies = [](bigdecimal& x, const bigdecimal&\
    \ y) -> bigdecimal& {\n        x.first *= y.first;\n        x.second += y.second;\n\
    \        regularize(x);\n        return x;\n      };\n      static const auto\
    \ compare_3way = [](const bigdecimal& x, const bigdecimal& y) {\n        if (!x.first.m_positive\
    \ && y.first.m_positive) return -1;\n        if (x.first.m_positive && !y.first.m_positive)\
    \ return 1;\n        return [&]() {\n          if (x.second <= y.second) {\n \
    \           if (const auto comp = ::tools::bigint::compare_3way(precision(x),\
    \ precision(y) + (y.second - x.second)); comp != 0) {\n              return comp;\n\
    \            }\n            for (::std::size_t i = 0; i < precision(x); ++i) {\n\
    \              if (const auto comp = ::tools::bigint::compare_3way(x.first.m_digits[precision(x)\
    \ - 1 - i], precision(y) >= i + 1 ? y.first.m_digits[precision(y) - 1 - i] : 0);\
    \ comp != 0) {\n                return comp;\n              }\n            }\n\
    \          } else {\n            if (const auto comp = ::tools::bigint::compare_3way(precision(x)\
    \ + (x.second - y.second), precision(y)); comp != 0) {\n              return comp;\n\
    \            }\n            for (::std::size_t i = 0; i < precision(y); ++i) {\n\
    \              if (const auto comp = ::tools::bigint::compare_3way(precision(x)\
    \ >= i + 1 ? x.first.m_digits[precision(x) - 1 - i] : 0, y.first.m_digits[precision(y)\
    \ - 1 - i]); comp != 0) {\n                return comp;\n              }\n   \
    \         }\n          }\n          return 0;\n        }() * (x.first.m_positive\
    \ ? 1 : -1);\n      };\n\n      const bool r_positive = this->m_positive == other.m_positive;\n\
    \      if (!this->m_positive) {\n        this->negate();\n      }\n      const\
    \ ::std::size_t inv_final_goal_precision = this->m_digits.size() - other.m_digits.size()\
    \ + 2;\n      const ::std::size_t inv_first_goal_precision = ::std::min<::std::size_t>(inv_final_goal_precision,\
    \ 3);\n\n      bigdecimal o(other, 0);\n      make_abs(o);\n      set_precision(o,\
    \ ::std::min<::std::size_t>(other.m_digits.size(), 6));\n      bigdecimal prev_inv(::tools::bigint(0),\
    \ 0);\n      bigdecimal inv(::tools::bigint(1), -::tools::ssize(other.m_digits));\n\
    \n      while (compare_3way(prev_inv, inv) != 0) {\n        prev_inv = inv;\n\
    \        negate(inv);\n        multiplies(inv, o);\n        bigdecimal two(::tools::bigint(2),\
    \ 0);\n        plus(inv, two);\n        multiplies(inv, prev_inv);\n        set_precision(inv,\
    \ ::std::min(precision(inv), inv_first_goal_precision));\n      }\n\n      if\
    \ (inv_first_goal_precision < inv_final_goal_precision) {\n        prev_inv =\
    \ bigdecimal(::tools::bigint(0), 0);\n        while (compare_3way(prev_inv, inv)\
    \ != 0) {\n          prev_inv = inv;\n          negate(inv);\n          multiplies(inv,\
    \ o);\n          bigdecimal two(::tools::bigint(2), 0);\n          plus(inv, two);\n\
    \          multiplies(inv, prev_inv);\n          set_precision(inv, ::std::min(precision(prev_inv)\
    \ * 2, inv_final_goal_precision));\n\n          const ::std::size_t o_precision\
    \ = precision(o);\n          o = bigdecimal(other, 0);\n          make_abs(o);\n\
    \          set_precision(o, ::std::min(o_precision * 2, other.m_digits.size()));\n\
    \        }\n      }\n\n      set_precision(inv, inv_final_goal_precision);\n \
    \     o = bigdecimal(other, 0);\n      make_abs(o);\n      bigdecimal r(*this,\
    \ 0);\n      multiplies(r, inv);\n      set_precision(r, precision(r) + r.second);\n\
    \n      ::tools::bigint r_plus_1 = r.first + ::tools::bigint(1);\n      if (*this\
    \ >= r_plus_1 * o.first) {\n        *this = ::std::move(r_plus_1);\n      } else\
    \ {\n        *this = ::std::move(r.first);\n      }\n\n      this->m_positive\
    \ = r_positive;\n      return *this;\n    }\n    friend ::tools::bigint operator/(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return ::tools::bigint(lhs)\
    \ /= rhs;\n    }\n    ::tools::bigint& operator%=(const ::tools::bigint& other)\
    \ {\n      using u64 = ::std::uint_fast64_t;\n      static const ::tools::bigint\
    \ u64_threshold((::std::numeric_limits<u64>::max() - (BASE - 1)) / BASE);\n  \
    \    using u128 = ::tools::uint128_t;\n      static const ::tools::bigint u128_threshold(\"\
    34028236692093846346337460743176820\");\n\n      #define TOOLS_BIGINT_NAIVE(type)\
    \ do {\\\n        if (::tools::bigint::compare_3way_abs(other, type ## _threshold)\
    \ <= 0) { \\\n          type mod = 0;\\\n          for (::std::size_t i = other.m_digits.size();\
    \ i --> 0;) {\\\n            mod *= BASE;\\\n            mod += other.m_digits[i];\\\
    \n          }\\\n          \\\n          type result = 0;\\\n          for (::std::size_t\
    \ i = this->m_digits.size(); i --> 0;) {\\\n            result *= BASE;\\\n  \
    \          result += this->m_digits[i];\\\n            result %= mod;\\\n    \
    \      }\\\n          \\\n          this->m_digits.clear();\\\n          while\
    \ (result > 0) {\\\n            this->m_digits.push_back(result % BASE);\\\n \
    \           result /= BASE;\\\n          }\\\n          \\\n          return this->regularize(0);\\\
    \n        }\\\n      } while (false)\n\n      TOOLS_BIGINT_NAIVE(u64);\n     \
    \ TOOLS_BIGINT_NAIVE(u128);\n\n      #undef TOOLS_BIGINT_NAIVE\n\n      const\
    \ ::tools::bigint self = *this;\n      *this /= other;\n      this->negate();\n\
    \      *this *= other;\n      *this += self;\n      return *this;\n    }\n   \
    \ friend ::tools::bigint operator%(const ::tools::bigint& lhs, const ::tools::bigint&\
    \ rhs) {\n      return ::tools::bigint(lhs) %= rhs;\n    }\n\n    template <typename\
    \ T, ::std::enable_if_t<::std::is_integral_v<T>, ::std::nullptr_t> = nullptr>\n\
    \    explicit operator T() const {\n      assert(::tools::bigint(::std::numeric_limits<T>::min())\
    \ <= *this && *this <= ::tools::bigint(::std::numeric_limits<T>::max()));\n  \
    \    T result = 0;\n      for (::std::size_t i = this->m_digits.size(); i -->\
    \ 0;) {\n        result = result * BASE + this->m_digits[i] * (this->m_positive\
    \ ? 1 : -1);\n      }\n      return result;\n    }\n\n    explicit operator bool()\
    \ const {\n      return !this->m_digits.empty();\n    }\n\n    explicit operator\
    \ double() const {\n      long double result = 0.0;\n      const ::std::size_t\
    \ precision = this->size();\n      for (::std::size_t i = 0; i < ::std::numeric_limits<long\
    \ double>::digits10; ++i) {\n        result = result * 10.0L + (precision >= i\
    \ + 1 ? (*this)[precision - 1 - i] : 0) * this->signum();\n      }\n      result\
    \ *= ::std::pow(10.0L, static_cast<long double>(precision) - static_cast<long\
    \ double>(::std::numeric_limits<long double>::digits10));\n      return static_cast<double>(result);\n\
    \    }\n\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::bigint&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::bigint(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::bigint& self) {\n      if (!self.m_positive) {\n        os\
    \ << '-';\n      }\n      if (self.m_digits.empty()) {\n        return os << '0';\n\
    \      }\n      os << self.m_digits.back();\n      for (::std::size_t i = 1; i\
    \ < self.m_digits.size(); ++i) {\n        os << ::std::setw(LOG10_BASE) << ::std::setfill('0')\
    \ << self.m_digits[self.m_digits.size() - 1 - i];\n      }\n      return os;\n\
    \    }\n\n    friend ::tools::bigint abs(::tools::bigint x);\n  };\n\n  inline\
    \ ::tools::bigint abs(::tools::bigint x) {\n    if (!x.m_positive) x.negate();\n\
    \    return x;\n  }\n\n  inline ::tools::bigint gcd(::tools::bigint x, ::tools::bigint\
    \ y) {\n    if (x.signum() < 0) x.negate();\n    if (y.signum() < 0) y.negate();\n\
    \n    while (y.signum() != 0) {\n      x %= y;\n      ::std::swap(x, y);\n   \
    \ }\n\n    return x;\n  }\n}\n\n\n#line 1 \"tools/signum.hpp\"\n\n\n\n#line 5\
    \ \"tools/signum.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  constexpr\
    \ int signum(const T x) noexcept {\n    if constexpr (::std::is_signed_v<T>) {\n\
    \      return (T(0) < x) - (x < T(0));\n    } else {\n      return T(0) < x;\n\
    \    }\n  }\n}\n\n\n#line 1 \"tools/rounding_mode.hpp\"\n\n\n\nnamespace tools\
    \ {\n  enum class rounding_mode {\n    ceiling,\n    down,\n    floor,\n    half_down,\n\
    \    half_even,\n    half_up,\n    up\n  };\n}\n\n\n#line 17 \"tools/bigdecimal.hpp\"\
    \n\nnamespace tools {\n  class bigdecimal {\n  private:\n    // *this := this->m_unscaled_value\
    \ * (10 ** -this->m_scale)\n    ::tools::bigint m_unscaled_value;\n    ::std::ptrdiff_t\
    \ m_scale;\n\n  public:\n    const ::tools::bigint& unscaled_value() const {\n\
    \      return this->m_unscaled_value;\n    }\n    ::std::size_t precision() const\
    \ {\n      return this->m_unscaled_value.size();\n    }\n    ::std::ptrdiff_t\
    \ scale() const {\n      return this->m_scale;\n    }\n    int signum() const\
    \ {\n      return this->m_unscaled_value.signum();\n    }\n    ::tools::bigdecimal&\
    \ negate() {\n      this->m_unscaled_value.negate();\n      return *this;\n  \
    \  }\n    ::tools::bigdecimal& multiply_by_pow10(const ::std::ptrdiff_t n) {\n\
    \      this->m_scale -= n;\n      return *this;\n    }\n    ::tools::bigdecimal&\
    \ divide_by_pow10(const ::std::ptrdiff_t n) {\n      return this->multiply_by_pow10(-n);\n\
    \    }\n    ::tools::bigdecimal& set_scale(const ::std::ptrdiff_t s) {\n     \
    \ this->m_unscaled_value.multiply_by_pow10(s - this->m_scale);\n      this->m_scale\
    \ = s;\n      return *this;\n    }\n    static int compare_3way(const ::tools::bigdecimal&\
    \ x, const ::tools::bigdecimal& y) {\n      if (const auto comp = ::tools::signum(x.m_unscaled_value.signum()\
    \ - y.m_unscaled_value.signum()); comp != 0) {\n        return comp;\n      }\n\
    \      return [&]() {\n        ::tools::bigdecimal abs_x(x);\n        if (abs_x.signum()\
    \ < 0) abs_x.negate();\n        abs_x.set_scale(::std::max(x.m_scale, y.m_scale));\n\
    \        ::tools::bigdecimal abs_y(y);\n        if (abs_y.signum() < 0) abs_y.negate();\n\
    \        abs_y.set_scale(::std::max(x.m_scale, y.m_scale));\n        return ::tools::bigint::compare_3way(abs_x.m_unscaled_value,\
    \ abs_y.m_unscaled_value);\n      }() * x.m_unscaled_value.signum();\n    }\n\n\
    \    bigdecimal() : m_unscaled_value(0), m_scale(0) {\n    }\n    bigdecimal(const\
    \ ::tools::bigdecimal&) = default;\n    bigdecimal(::tools::bigdecimal&&) = default;\n\
    \    ~bigdecimal() = default;\n    ::tools::bigdecimal& operator=(const ::tools::bigdecimal&)\
    \ = default;\n    ::tools::bigdecimal& operator=(::tools::bigdecimal&&) = default;\n\
    \n    explicit bigdecimal(const long long n) : m_unscaled_value(n), m_scale(0)\
    \ {\n    }\n    explicit bigdecimal(const ::tools::bigint& n) : m_unscaled_value(n),\
    \ m_scale(0) {\n    }\n    explicit bigdecimal(::std::string s) {\n      if (const\
    \ auto pos = s.find('.'); pos != ::std::string::npos) {\n        this->m_scale\
    \ = s.size() - pos - 1;\n        s.erase(pos, 1);\n      } else {\n        this->m_scale\
    \ = 0;\n      }\n      this->m_unscaled_value = ::tools::bigint(s);\n    }\n\n\
    \    friend bool operator==(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) == 0;\n   \
    \ }\n    friend bool operator!=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) != 0;\n   \
    \ }\n    friend bool operator<(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) < 0;\n    }\n\
    \    friend bool operator>(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) > 0;\n    }\n\
    \    friend bool operator<=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) <= 0;\n   \
    \ }\n    friend bool operator>=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal&\
    \ rhs) {\n      return ::tools::bigdecimal::compare_3way(lhs, rhs) >= 0;\n   \
    \ }\n\n    ::tools::bigdecimal operator+() const {\n      return *this;\n    }\n\
    \    ::tools::bigdecimal operator-() const {\n      return ::tools::bigdecimal(*this).negate();\n\
    \    }\n\n    ::tools::bigdecimal& operator+=(::tools::bigdecimal other) {\n \
    \     const ::std::size_t scale = ::std::max(this->m_scale, other.m_scale);\n\
    \      this->set_scale(scale);\n      other.set_scale(scale);\n      this->m_unscaled_value\
    \ += other.m_unscaled_value;\n      return *this;\n    }\n    ::tools::bigdecimal&\
    \ operator-=(::tools::bigdecimal other) {\n      const ::std::size_t scale = ::std::max(this->m_scale,\
    \ other.m_scale);\n      this->set_scale(scale);\n      other.set_scale(scale);\n\
    \      this->m_unscaled_value -= other.m_unscaled_value;\n      return *this;\n\
    \    }\n    ::tools::bigdecimal& operator*=(const ::tools::bigdecimal& other)\
    \ {\n      this->m_unscaled_value *= other.m_unscaled_value;\n      this->m_scale\
    \ += other.m_scale;\n      return *this;\n    }\n    ::tools::bigdecimal& divide(const\
    \ ::tools::bigdecimal& other, const ::std::ptrdiff_t scale, const ::tools::rounding_mode\
    \ rounding_mode) {\n      assert(other.signum() != 0);\n\n      static const auto\
    \ compare_3way_abs = [](::tools::bigdecimal& x, ::tools::bigdecimal& y) {\n  \
    \      const bool x_positive = x.signum() >= 0;\n        const bool y_positive\
    \ = y.signum() >= 0;\n        if (!x_positive) x.negate();\n        if (!y_positive)\
    \ y.negate();\n        const int result = ::tools::bigdecimal::compare_3way(x,\
    \ y);\n        if (!x_positive) x.negate();\n        if (!y_positive) y.negate();\n\
    \        return result;\n      };\n\n      ::tools::bigdecimal old_this(*this);\n\
    \n      this->m_unscaled_value.multiply_by_pow10(scale - (this->m_scale - other.m_scale));\n\
    \      this->m_unscaled_value /= other.m_unscaled_value;\n      this->m_scale\
    \ = scale;\n\n      if ([&]() {\n        if (rounding_mode == ::tools::rounding_mode::down)\
    \ {\n          return false;\n        }\n        if (rounding_mode == ::tools::rounding_mode::ceiling\
    \ || rounding_mode == ::tools::rounding_mode::floor || rounding_mode == ::tools::rounding_mode::up)\
    \ {\n          if ((rounding_mode == ::tools::rounding_mode::ceiling && old_this.signum()\
    \ * other.signum() > 0)\n            || (rounding_mode == ::tools::rounding_mode::floor\
    \ && old_this.signum() * other.signum() < 0)\n            || rounding_mode ==\
    \ ::tools::rounding_mode::up) {\n            ::tools::bigdecimal d(*this);\n \
    \           d *= other;\n            return compare_3way_abs(old_this, d) > 0;\n\
    \          } else {\n            return false;\n          }\n        }\n\n   \
    \     ::tools::bigdecimal d(*this);\n        d += ::tools::bigdecimal(5 * old_this.signum()\
    \ * other.signum()).divide_by_pow10(scale + 1);\n        d *= other;\n       \
    \ const int comp = compare_3way_abs(old_this, d);\n        if (rounding_mode ==\
    \ ::tools::rounding_mode::half_down) {\n          return comp > 0;\n        }\n\
    \        if (rounding_mode == ::tools::rounding_mode::half_up) {\n          return\
    \ comp >= 0;\n        }\n        return comp > 0 || (comp == 0 && this->m_unscaled_value[0]\
    \ % 2 != 0);\n      }()) {\n        this->m_scale = scale;\n        this->m_unscaled_value\
    \ += ::tools::bigint(old_this.signum() * other.signum());\n      }\n\n      return\
    \ *this;\n    }\n    ::tools::bigdecimal& divide(const ::tools::bigdecimal& other,\
    \ const ::std::ptrdiff_t scale) {\n      return this->divide(other, scale, ::tools::rounding_mode::half_even);\n\
    \    }\n    ::tools::bigdecimal& operator/=(const ::tools::bigdecimal& other)\
    \ {\n      return this->divide(other, this->m_scale - other.m_scale);\n    }\n\
    \n    friend ::tools::bigdecimal operator+(const ::tools::bigdecimal& lhs, const\
    \ ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs) += rhs;\n\
    \    }\n    friend ::tools::bigdecimal operator-(const ::tools::bigdecimal& lhs,\
    \ const ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs) -=\
    \ rhs;\n    }\n    friend ::tools::bigdecimal operator*(const ::tools::bigdecimal&\
    \ lhs, const ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs)\
    \ *= rhs;\n    }\n    ::tools::bigdecimal divide_and_copy(const ::tools::bigdecimal&\
    \ other, const ::std::ptrdiff_t scale, const ::tools::rounding_mode rounding_mode)\
    \ const {\n      return ::tools::bigdecimal(*this).divide(other, scale, rounding_mode);\n\
    \    }\n    ::tools::bigdecimal divide_and_copy(const ::tools::bigdecimal& other,\
    \ const ::std::ptrdiff_t scale) const {\n      return ::tools::bigdecimal(*this).divide(other,\
    \ scale);\n    }\n    friend ::tools::bigdecimal operator/(const ::tools::bigdecimal&\
    \ lhs, const ::tools::bigdecimal& rhs) {\n      return ::tools::bigdecimal(lhs)\
    \ /= rhs;\n    }\n\n    template <typename T, ::std::enable_if_t<::std::is_integral_v<T>,\
    \ ::std::nullptr_t> = nullptr>\n    explicit operator T() const {\n      auto\
    \ x = *this;\n      x.set_scale(0);\n      return static_cast<T>(x.m_unscaled_value);\n\
    \    }\n\n    explicit operator double() const {\n      long double result = 0.0;\n\
    \      const ::std::size_t precision = this->precision();\n      for (::std::size_t\
    \ i = 0; i < ::std::numeric_limits<long double>::digits10; ++i) {\n        result\
    \ = result * 10.0L + (precision >= i + 1 ? this->m_unscaled_value[precision -\
    \ 1 - i] : 0) * this->signum();\n      }\n      result *= ::std::pow(10.0L, static_cast<long\
    \ double>(precision) - static_cast<long double>(this->m_scale) - static_cast<long\
    \ double>(::std::numeric_limits<long double>::digits10));\n      return static_cast<double>(result);\n\
    \    }\n\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::bigdecimal&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::bigdecimal(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::bigdecimal& self) {\n      if (self.signum() == 0 && self.m_scale\
    \ <= 0) {\n        return os << '0';\n      }\n\n      if (self.signum() < 0)\
    \ {\n        os << '-';\n      }\n      for (auto i = ::std::max(::tools::ssize(self.m_unscaled_value)\
    \ - 1, self.m_scale); i >= ::std::min<::std::ptrdiff_t>(0, self.m_scale); --i)\
    \ {\n        if (i == self.m_scale - 1) {\n          os << '.';\n        }\n \
    \       os << (0 <= i && i < ::tools::ssize(self.m_unscaled_value) ? self.m_unscaled_value[i]\
    \ : 0);\n      }\n      return os;\n    }\n  };\n\n  inline ::tools::bigdecimal\
    \ abs(::tools::bigdecimal x) {\n    if (x.signum() < 0) x.negate();\n    return\
    \ x;\n  }\n}\n\n\n#line 6 \"tests/bigdecimal/divides.test.cpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  tools::bigdecimal\
    \ A, B;\n  std::cin >> A >> B;\n  std::cout << A.divide_and_copy(B, 0, tools::rounding_mode::down)\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_D\"\n\n\
    #include <iostream>\n#include \"tools/bigdecimal.hpp\"\n#include \"tools/rounding_mode.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  tools::bigdecimal A, B;\n  std::cin >> A >> B;\n  std::cout << A.divide_and_copy(B,\
    \ 0, tools::rounding_mode::down) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/bigdecimal.hpp
  - tools/bigint.hpp
  - tools/quo.hpp
  - tools/mod.hpp
  - tools/floor.hpp
  - tools/ssize.hpp
  - tools/ceil.hpp
  - tools/garner2.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  - tools/pow_mod.hpp
  - tools/pow2.hpp
  - tools/gcd.hpp
  - tools/signum.hpp
  - tools/rounding_mode.hpp
  isVerificationFile: true
  path: tests/bigdecimal/divides.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/bigdecimal/divides.test.cpp
layout: document
redirect_from:
- /verify/tests/bigdecimal/divides.test.cpp
- /verify/tests/bigdecimal/divides.test.cpp.html
title: tests/bigdecimal/divides.test.cpp
---
