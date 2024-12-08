---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/garner2.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$ and $\mathbb{Z} /
      M_2 \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/gcd.hpp
    title: std::gcd(m, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/int128_t.hpp
    title: 128 bit signed integer
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/monoid.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <limits>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that_impl(cond,\
    \ file, line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' <<\
    \ line << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\\
    n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/monoid.hpp\"\n\n\n\n#line 5 \"tools/monoid.hpp\"\n#include <algorithm>\n\
    #line 1 \"tools/gcd.hpp\"\n\n\n\n#line 6 \"tools/gcd.hpp\"\n\nnamespace tools\
    \ {\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \ 1 \"tools/bigint.hpp\"\n\n\n\n#include <vector>\n#include <cstdint>\n#include\
    \ <array>\n#include <cstddef>\n#line 9 \"tools/bigint.hpp\"\n#include <iterator>\n\
    #line 11 \"tools/bigint.hpp\"\n#include <string>\n#line 15 \"tools/bigint.hpp\"\
    \n#include <tuple>\n#include <cmath>\n#line 18 \"tools/bigint.hpp\"\n#include\
    \ <iomanip>\n#line 1 \"lib/ac-library/atcoder/convolution.hpp\"\n\n\n\n#line 9\
    \ \"lib/ac-library/atcoder/convolution.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\
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
    \    }\n\n    return c;\n}\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\nnamespace tools {\n  constexpr float abs(const float x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr long double abs(const long double x) {\n   \
    \ return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0\
    \ ? -x : x;\n  }\n  constexpr long long abs(const long long x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n \
    \   return x;\n  }\n  constexpr unsigned long abs(const unsigned long x) {\n \
    \   return x;\n  }\n  constexpr unsigned long long abs(const unsigned long long\
    \ x) {\n    return x;\n  }\n}\n\n\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"\
    tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N rhs) {\n    using\
    \ T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return -((-lhs - T(1)\
    \ + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) + -rhs) / -rhs;\n\
    \      }\n    }\n  }\n}\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 6 \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\
    \n\n\n\n#line 6 \"tools/floor.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs >\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line\
    \ 6 \"tools/ssize.hpp\"\n\nnamespace tools {\n\n  template <typename C>\n  constexpr\
    \ auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 1 \"tools/int128_t.hpp\"\n\n\n\n\
    #line 1 \"tools/uint128_t.hpp\"\n\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\nnamespace\
    \ tools {\n  using uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t\
    \ abs(const ::tools::uint128_t& x) {\n    return x;\n  }\n}\n\nconstexpr inline\
    \ ::tools::uint128_t UINT128_MAX = (::tools::uint128_t(1) << 127) | ((::tools::uint128_t(1)\
    \ << 127) - 1);\n\n::std::istream& operator>>(::std::istream& is, ::tools::uint128_t&\
    \ x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for\
    \ (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n\
    ::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n  if (x\
    \ == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n    s.push_back('0'\
    \ + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(), s.end());\n\n  return\
    \ os << s;\n}\n\n\n#line 11 \"tools/int128_t.hpp\"\n\nnamespace tools {\n  using\
    \ int128_t = __int128;\n\n  constexpr ::tools::int128_t abs(const ::tools::int128_t&\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n}\n\nconstexpr inline ::tools::int128_t\
    \ INT128_MAX = (::tools::int128_t(1) << 126) | ((::tools::int128_t(1) << 126)\
    \ - 1);\nconstexpr inline ::tools::int128_t INT128_MIN = -INT128_MAX - 1;\n\n\
    ::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {\n  ::std::string\
    \ s;\n  is >> s;\n  assert(!s.empty());\n\n  if (s == \"-170141183460469231731687303715884105728\"\
    ) {\n    x = INT128_MIN;\n    return is;\n  }\n\n  x = 0;\n  for (::std::size_t\
    \ i = s[0] == '+' || s[0] == '-'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  if (s[0] == '-')\
    \ x = -x;\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream& os,\
    \ ::tools::int128_t x) {\n  if (x == 0) return os << '0';\n  if (x == INT128_MIN)\
    \ return os << \"-170141183460469231731687303715884105728\";\n\n  ::std::string\
    \ s;\n  const bool negative = x < 0;\n\n  if (negative) x = -x;\n  while (x >\
    \ 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n\n  if (negative) s.push_back('-');\n\
    \  ::std::reverse(s.begin(), s.end());\n  return os << s;\n}\n\n\n#line 1 \"tools/ceil.hpp\"\
    \n\n\n\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs <\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6\
    \ \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/garner2.hpp\"\
    \n\n\n\n#line 1 \"tools/is_prime.hpp\"\n\n\n\n#line 1 \"tools/prod_mod.hpp\"\n\
    \n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2\
    \ y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n    u128 prod_mod =\
    \ u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^\
    \ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n\
    #line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3\
    \ pow_mod(const T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r\
    \ = 1;\n    T3 y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n & 1)\
    \ > 0) {\n        r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
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
    \ 6 \"tools/garner2.hpp\"\n\nnamespace tools {\n\n  template <typename M1, typename\
    \ M2>\n  long long garner2(const M1& a, const M2& b) {\n    using ull = unsigned\
    \ long long;\n    static constexpr ull m1_m2 = ull(M1::mod()) * ull(M2::mod());\n\
    \    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\n    assert(M1::mod()\
    \ < M2::mod());\n    assert(::tools::is_prime(M1::mod()));\n    assert(::tools::is_prime(M2::mod()));\n\
    \n    // t = (b - a) / M1; (mod M2)\n    // return a + t * M1;\n    const M2 t\
    \ = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n    ull r = t.val();\n    r *= M1::mod();\n\
    \    r += a.val();\n    if (r >= m1_m2) r -= m1_m2;\n    return r;\n  }\n}\n\n\
    \n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line\
    \ 5 \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename T, typename\
    \ U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n    using UT\
    \ = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n  \
    \  if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    bool updated;\n\
    \    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>) {\n   \
    \   updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated = rhs\
    \ < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 1 \"tools/floor_log2.hpp\"\n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n\
    #line 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n\
    \  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
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
    \ 34 \"tools/bigint.hpp\"\n\nnamespace tools {\n  class bigint;\n\n  ::tools::bigint\
    \ abs(::tools::bigint x);\n\n  class bigint {\n  private:\n    using mint1 = ::atcoder::static_modint<167772161>;\n\
    \    using mint2 = ::atcoder::static_modint<469762049>;\n\n    bool m_positive;\n\
    \    ::std::vector<::std::int_fast32_t> m_digits;\n    static constexpr ::std::int_fast32_t\
    \ BASE = 10000;\n    static constexpr ::std::int_fast32_t LOG10_BASE = 4;\n  \
    \  static constexpr ::std::array<::std::int_fast32_t, 5> POW10 = {1, 10, 100,\
    \ 1000, 10000};\n\n    static int compare_3way(const ::std::size_t lhs, const\
    \ ::std::size_t rhs) {\n      if (lhs < rhs) return -1;\n      if (lhs == rhs)\
    \ return 0;\n      return 1;\n    }\n    static int compare_3way_abs(const ::tools::bigint&\
    \ lhs, const ::tools::bigint& rhs) {\n      if (const auto comp = ::tools::bigint::compare_3way(lhs.m_digits.size(),\
    \ rhs.m_digits.size()); comp != 0) {\n        return comp;\n      }\n      for\
    \ (::std::size_t i = lhs.m_digits.size(); i --> 0;) {\n        if (const auto\
    \ comp = ::tools::bigint::compare_3way(lhs.m_digits[i], rhs.m_digits[i]); comp\
    \ != 0) {\n          return comp;\n        }\n      }\n      return 0;\n    }\n\
    \n    template <int LEVEL>\n    ::tools::bigint& regularize() {\n      if constexpr\
    \ (LEVEL > 0) {\n        if constexpr (LEVEL == 2) {\n          for (::std::size_t\
    \ i = 0; i + 1 < this->m_digits.size(); ++i) {\n            this->m_digits[i +\
    \ 1] += ::tools::quo(this->m_digits[i], BASE);\n            this->m_digits[i]\
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
    \     if constexpr (LEVEL == 2) {\n          while (!this->m_digits.empty() &&\
    \ this->m_digits.back() >= BASE) {\n            this->m_digits.push_back(this->m_digits.back()\
    \ / BASE);\n            this->m_digits[this->m_digits.size() - 2] %= BASE;\n \
    \         }\n        } else {\n          if (!this->m_digits.empty() && this->m_digits.back()\
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
    \ this->regularize<2>();\n        } else {\n          this->regularize<0>();\n\
    \        }\n      }\n      return *this;\n    }\n    ::tools::bigint& divide_by_pow10(const\
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
    \  private:\n    template <bool PLUS>\n    ::tools::bigint& internal_add(const\
    \ ::tools::bigint& other) {\n      if (this == &other) {\n        if constexpr\
    \ (PLUS) {\n          for (auto& d : this->m_digits) d <<= 1;\n          this->regularize<1>();\n\
    \        } else {\n          this->m_digits.clear();\n          this->m_positive\
    \ = true;\n        }\n      } else {\n        const bool this_positive = this->m_positive;\n\
    \        if (!this_positive) {\n          this->negate();\n        }\n       \
    \ this->m_digits.resize(::std::max(this->m_digits.size(), other.m_digits.size()));\n\
    \        if (this_positive == (other.m_positive == PLUS)) {\n          for (::std::size_t\
    \ i = 0; i < other.m_digits.size(); ++i) {\n            this->m_digits[i] += other.m_digits[i];\n\
    \          }\n        } else {\n          for (::std::size_t i = 0; i < other.m_digits.size();\
    \ ++i) {\n            this->m_digits[i] -= other.m_digits[i];\n          }\n \
    \       }\n        this->regularize<1>();\n        if (!this_positive) {\n   \
    \       this->negate();\n        }\n      }\n      return *this;\n    }\n\n  public:\n\
    \    bigint() : m_positive(true) {\n    }\n    bigint(const ::tools::bigint&)\
    \ = default;\n    bigint(::tools::bigint&&) = default;\n    ~bigint() = default;\n\
    \    ::tools::bigint& operator=(const ::tools::bigint&) = default;\n    ::tools::bigint&\
    \ operator=(::tools::bigint&&) = default;\n\n    template <typename T, typename\
    \ ::std::enable_if<::std::is_integral_v<T> || ::std::is_same_v<T, ::tools::int128_t>\
    \ || ::std::is_same_v<T, ::tools::uint128_t>, ::std::nullptr_t>::type = nullptr>\n\
    \    explicit bigint(T n) : m_positive(n >= 0) {\n      while (n != 0) {\n   \
    \     this->m_digits.push_back(n % BASE);\n        n /= BASE;\n      }\n     \
    \ if (!this->m_positive) {\n        for (auto& d : this->m_digits) {\n       \
    \   d = -d;\n        }\n      }\n    }\n    explicit bigint(const ::std::string&\
    \ s) {\n      assert(!s.empty());\n\n      ::std::size_t offset;\n      if (s[0]\
    \ == '+') {\n        this->m_positive = true;\n        offset = 1;\n      } else\
    \ if (s[0] == '-') {\n        this->m_positive = false;\n        offset = 1;\n\
    \      } else {\n        this->m_positive = true;\n        offset = 0;\n     \
    \ }\n\n      this->m_digits.reserve(::tools::ceil<::std::size_t>(s.size() - offset,\
    \ LOG10_BASE));\n      for (::std::size_t i = 0; i < s.size() - offset; i += LOG10_BASE)\
    \ {\n        this->m_digits.push_back(0);\n        for (::std::size_t j = ::std::min(i\
    \ + LOG10_BASE, s.size() - offset); j --> i;) {\n          assert('0' <= s[s.size()\
    \ - 1 - j] && s[s.size() - 1 - j] <= '9');\n          this->m_digits.back() =\
    \ this->m_digits.back() * 10 + (s[s.size() - 1 - j] - '0');\n        }\n     \
    \ }\n\n      this->regularize<0>();\n    }\n\n    friend bool operator==(const\
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
    \ operator+=(const ::tools::bigint& other) {\n      return this->internal_add<true>(other);\n\
    \    }\n    ::tools::bigint& operator-=(const ::tools::bigint& other) {\n    \
    \  return this->internal_add<false>(other);\n    }\n    ::tools::bigint& operator*=(const\
    \ ::tools::bigint& other) {\n      // Constraint derived from atcoder::convolution\n\
    \      assert(this->m_digits.size() + other.m_digits.size() <= ::tools::pow2(25)\
    \ + 1);\n\n      ::std::vector<mint1> a1, b1;\n      ::std::vector<mint2> a2,\
    \ b2;\n      a1.reserve(this->m_digits.size());\n      a2.reserve(this->m_digits.size());\n\
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
    \    this->regularize<0>();\n      return *this;\n    }\n\n    friend ::tools::bigint\
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
    \    }\n\n  private:\n    static const ::tools::bigint& divmod_naive_u64_threshold()\
    \ {\n      static const ::tools::bigint threshold((::std::numeric_limits<::std::uint_fast64_t>::max()\
    \ - (BASE - 1)) / BASE);\n      return threshold;\n    }\n\n    ::std::pair<::tools::bigint,\
    \ ::tools::bigint> divmod_naive_u64(const ::tools::bigint& other) const {\n  \
    \    assert(!other.m_digits.empty());\n      assert(::tools::bigint::compare_3way_abs(other,\
    \ divmod_naive_u64_threshold()) <= 0);\n\n      ::std::uint_fast64_t b = 0;\n\
    \      for (::std::size_t i = other.m_digits.size(); i --> 0;) {\n        b *=\
    \ BASE;\n        b += other.m_digits[i];\n      }\n\n      ::tools::bigint Q(*this);\n\
    \      ::std::uint_fast64_t r = 0;\n      for (::std::size_t i = Q.m_digits.size();\
    \ i--> 0;) {\n        r *= BASE;\n        r += Q.m_digits[i];\n        Q.m_digits[i]\
    \ = r / b;\n        r %= b;\n      }\n\n      Q.m_positive = (this->m_positive\
    \ == other.m_positive);\n      Q.regularize<0>();\n      ::tools::bigint R(r);\n\
    \      R.m_positive = (r == 0 || this->m_positive);\n\n      return ::std::make_pair(Q,\
    \ R);\n    }\n\n    static const ::tools::bigint& divmod_naive_u128_threshold()\
    \ {\n      static const ::tools::bigint threshold(\"34028236692093846346337460743176820\"\
    );\n      return threshold;\n    }\n\n    ::std::pair<::tools::bigint, ::tools::bigint>\
    \ divmod_naive_u128(const ::tools::bigint& other) const {\n      assert(!other.m_digits.empty());\n\
    \      assert(::tools::bigint::compare_3way_abs(other, divmod_naive_u128_threshold())\
    \ <= 0);\n\n      ::tools::uint128_t b = 0;\n      for (::std::size_t i = other.m_digits.size();\
    \ i --> 0;) {\n        b *= BASE;\n        b += other.m_digits[i];\n      }\n\n\
    \      ::tools::bigint Q(*this);\n      ::tools::uint128_t r = 0;\n      for (::std::size_t\
    \ i = Q.m_digits.size(); i--> 0;) {\n        r *= BASE;\n        r += Q.m_digits[i];\n\
    \        Q.m_digits[i] = r / b;\n        r %= b;\n      }\n\n      Q.m_positive\
    \ = (this->m_positive == other.m_positive);\n      Q.regularize<0>();\n      ::tools::bigint\
    \ R(r);\n      R.m_positive = (r == 0 || this->m_positive);\n\n      return ::std::make_pair(Q,\
    \ R);\n    }\n\n    // S1\u306E[l1, r1)\u6841\u76EE * (BASE ** n1) <=> S2\u306E\
    [l2, r2)\u6841\u76EE * (BASE ** n2)\n    static int compare_3way_abs(const ::tools::bigint&\
    \ S1, ::std::size_t l1, ::std::size_t r1, ::std::size_t n1, const ::tools::bigint&\
    \ S2, ::std::size_t l2, ::std::size_t r2, ::std::size_t n2) {\n      assert(l1\
    \ <= r1);\n      assert(l2 <= r2);\n\n      ::tools::chmin(l1, S1.m_digits.size());\n\
    \      ::tools::chmin(r1, S1.m_digits.size());\n      ::tools::chmin(l2, S2.m_digits.size());\n\
    \      ::tools::chmin(r2, S2.m_digits.size());\n      const auto n_min = ::std::min(n1,\
    \ n2);\n      n1 -= n_min;\n      n2 -= n_min;\n\n      if (const auto comp =\
    \ ::tools::bigint::compare_3way(r1 - l1 + n1, r2 - l2 + n2); comp != 0) {\n  \
    \      return comp;\n      }\n      if (n1 > 0) {\n        const auto m2 = r2\
    \ - (r1 - l1);\n        for (::std::size_t i1 = r1, i2 = r2; --i1, i2 --> m2;)\
    \ {\n          if (const auto comp = ::tools::bigint::compare_3way(S1.m_digits[i1],\
    \ S2.m_digits[i2]); comp != 0) {\n            return comp;\n          }\n    \
    \    }\n        for (::std::size_t i2 = m2; i2 --> l2;) {\n          if (0 < S2.m_digits[i2])\
    \ {\n            return -1;\n          }\n        }\n      } else if (n2 > 0)\
    \ {\n        const auto m1 = r1 - (r2 - l2);\n        for (::std::size_t i1 =\
    \ r1, i2 = r2; --i1, i2 --> l2;) {\n          if (const auto comp = ::tools::bigint::compare_3way(S1.m_digits[i1],\
    \ S2.m_digits[i2]); comp != 0) {\n            return comp;\n          }\n    \
    \    }\n        for (::std::size_t i1 = m1; i1 --> l1;) {\n          if (S1.m_digits[i1]\
    \ > 0) {\n            return 1;\n          }\n        }\n      } else {\n    \
    \    for (::std::size_t i1 = r1, i2 = r2; --i1, i2 --> l2;) {\n          if (const\
    \ auto comp = ::tools::bigint::compare_3way(S1.m_digits[i1], S2.m_digits[i2]);\
    \ comp != 0) {\n            return comp;\n          }\n        }\n      }\n  \
    \    return 0;\n    }\n    // *this\u306E[l, r)\u6841\u76EE\n    ::tools::bigint\
    \ slice(::std::size_t l, ::std::size_t r) const {\n      assert(this->m_positive);\n\
    \      assert(l <= r);\n\n      ::tools::chmin(l, this->m_digits.size());\n  \
    \    ::tools::chmin(r, this->m_digits.size());\n\n      ::tools::bigint S;\n \
    \     S.m_digits.reserve(r - l);\n      ::std::copy(this->m_digits.begin() + l,\
    \ this->m_digits.begin() + r, ::std::back_inserter(S.m_digits));\n      return\
    \ S.regularize<0>();\n    }\n    // *this * (BASE ** n)\n    ::tools::bigint lshift(const\
    \ int n) const {\n      assert(this->m_positive);\n\n      if (n == 0) return\
    \ *this;\n      if (this->m_digits.empty()) return *this;\n\n      ::tools::bigint\
    \ S;\n      S.m_digits.reserve(n + this->m_digits.size());\n      ::std::fill_n(::std::back_inserter(S.m_digits),\
    \ n, 0);\n      ::std::copy(this->m_digits.begin(), this->m_digits.end(), ::std::back_inserter(S.m_digits));\n\
    \      return S;\n    }\n    // *this / (BASE ** n)\n    ::tools::bigint rshift(const\
    \ ::std::size_t n) const {\n      assert(this->m_positive);\n\n      if (this->m_digits.size()\
    \ <= n) return ::tools::bigint{};\n\n      ::tools::bigint S;\n      S.m_digits.reserve(this->m_digits.size()\
    \ - n);\n      ::std::copy(this->m_digits.begin() + n, this->m_digits.end(), ::std::back_inserter(S.m_digits));\n\
    \      return S;\n    }\n    // *this * (BASE ** (r - l)) + other\u306E[l, r)\u6841\
    \u76EE\n    ::tools::bigint concat(const ::tools::bigint& other, ::std::size_t\
    \ l, ::std::size_t r) const {\n      assert(this->m_positive);\n      assert(other.m_positive);\n\
    \      assert(l < r);\n\n      if (this->m_digits.empty()) return other.slice(l,\
    \ r);\n\n      const auto n = r - l;\n      ::tools::chmin(l, other.m_digits.size());\n\
    \      ::tools::chmin(r, other.m_digits.size());\n\n      ::tools::bigint S;\n\
    \      S.m_digits.reserve(this->m_digits.size() + n);\n      ::std::copy(other.m_digits.begin()\
    \ + l, other.m_digits.begin() + r, ::std::back_inserter(S.m_digits));\n      ::std::fill_n(::std::back_inserter(S.m_digits),\
    \ n - (r - l), 0);\n      ::std::copy(this->m_digits.begin(), this->m_digits.end(),\
    \ ::std::back_inserter(S.m_digits));\n      return S;\n    }\n\n    ::std::pair<::tools::bigint,\
    \ ::tools::bigint> divmod_3n_2n(const ::tools::bigint& other, const ::std::size_t\
    \ n) const {\n      assert(this->m_positive);\n      assert(this->m_digits.size()\
    \ <= n * 3);\n      assert(other.m_positive);\n      assert(other.m_digits.size()\
    \ == n * 2);\n      assert(BASE <= other.m_digits.back() * 2);\n      assert(compare_3way_abs(*this,\
    \ 0, n * 3, 0, other, 0, n * 2, n) < 0);\n\n      ::tools::bigint Q_hat, S, D;\n\
    \      if (compare_3way_abs(*this, n * 2, n * 3, 0, other, n, n * 2, 0) < 0) {\n\
    \        ::std::tie(Q_hat, S) = this->slice(n, n * 3).divmod_2n_n(other.slice(n,\
    \ n * 2), n);\n        D = other.slice(0, n);\n        D *= Q_hat;\n      } else\
    \ {\n        Q_hat.m_digits.assign(n, BASE - 1);\n        S = this->slice(n, n\
    \ * 3);\n        S += other.slice(n, n * 2);\n        S -= other.slice(n, n *\
    \ 2).lshift(n);\n        D = other.slice(0, n).lshift(n);\n        D -= other.slice(0,\
    \ n);\n      }\n\n      auto R_hat = S.concat(*this, 0, n);\n      R_hat -= D;\n\
    \      while (!R_hat.m_positive) {\n        R_hat += other;\n        --Q_hat;\n\
    \      }\n\n      return ::std::make_pair(Q_hat, R_hat);\n    }\n\n    ::std::pair<::tools::bigint,\
    \ ::tools::bigint> divmod_4n_2n(const ::tools::bigint& other, const ::std::size_t\
    \ n) const {\n      assert(this->m_positive);\n      assert(this->m_digits.size()\
    \ <= n * 4);\n      assert(other.m_positive);\n      assert(other.m_digits.size()\
    \ == n * 2);\n      assert(BASE <= other.m_digits.back() * 2);\n      assert(compare_3way_abs(*this,\
    \ 0, n * 4, 0, other, 0, n * 2, n * 2) < 0);\n\n      const auto [Q1, S] = this->slice(n,\
    \ n * 4).divmod_3n_2n(other, n);\n      const auto [Q0, R] = S.concat(*this, 0,\
    \ n).divmod_3n_2n(other, n);\n\n      return ::std::make_pair(Q1.concat(Q0, 0,\
    \ n), R);\n    }\n\n    ::std::pair<::tools::bigint, ::tools::bigint> divmod_2n_n(const\
    \ ::tools::bigint& other, const ::std::size_t n) const {\n      assert(this->m_positive);\n\
    \      assert(this->m_digits.size() <= n * 2);\n      assert(other.m_positive);\n\
    \      assert(other.m_digits.size() == n);\n      assert(BASE <= other.m_digits.back()\
    \ * 2);\n\n      if (other.m_digits.size() <= 3) {\n        return this->divmod_naive_u64(other);\n\
    \      }\n      if (other.m_digits.size() <= 8) {\n        return this->divmod_naive_u128(other);\n\
    \      }\n\n      assert(n % 2 == 0);\n      return this->divmod_4n_2n(other,\
    \ n / 2);\n    }\n\n  public:\n    ::std::pair<::tools::bigint, ::tools::bigint>\
    \ divmod(const ::tools::bigint& other) const {\n      assert(!other.m_digits.empty());\n\
    \n      if (::tools::bigint::compare_3way_abs(*this, other) < 0) {\n        return\
    \ ::std::make_pair(::tools::bigint{}, *this);\n      }\n      if (::tools::bigint::compare_3way_abs(other,\
    \ divmod_naive_u64_threshold()) <= 0) {\n        return this->divmod_naive_u64(other);\n\
    \      }\n      if (::tools::bigint::compare_3way_abs(other, divmod_naive_u128_threshold())\
    \ <= 0) {\n        return this->divmod_naive_u128(other);\n      }\n\n      if\
    \ (!this->m_positive || !other.m_positive) {\n        auto [Q, R] = ::tools::abs(*this).divmod(::tools::abs(other));\n\
    \        Q.m_positive = Q.m_digits.empty() || (this->m_positive == other.m_positive);\n\
    \        R.m_positive = R.m_digits.empty() || this->m_positive;\n        return\
    \ ::std::make_pair(Q, R);\n      }\n\n      const ::std::size_t DIV_LIMIT = 8;\n\
    \      const auto s = other.m_digits.size();\n      const auto m = ::tools::pow2(::tools::floor_log2(s\
    \ / DIV_LIMIT) + 1);\n      const auto n = ::tools::ceil(s, m) * m;\n\n      const\
    \ auto sigma1 = n - s;\n      auto sigma2 = ::tools::pow2(::tools::floor_log2(BASE\
    \ / (other.m_digits.back() + 1)));\n\n      auto B = other.lshift(sigma1);\n \
    \     for (auto& B_i : B.m_digits) B_i *= sigma2;\n      B.regularize<2>();\n\
    \      assert(B.m_digits.size() == n);\n      while (B.m_digits.back() * 2 < BASE)\
    \ {\n        sigma2 *= 2;\n        B += B;\n        assert(B.m_digits.size() ==\
    \ n);\n      }\n\n      auto A = this->lshift(sigma1);\n      for (auto& A_i :\
    \ A.m_digits) A_i *= sigma2;\n      A.regularize<2>();\n\n      const auto t =\
    \ ::std::max<::std::size_t>(2, ::tools::ceil(A.m_digits.size() + 1, n));\n   \
    \   ::tools::bigint Q, Q_i, R_i;\n      Q.m_digits.resize(n * (t - 1));\n    \
    \  auto Z = A.slice(n * (t - 2), n * t);\n      ::std::tie(Q_i, R_i) = Z.divmod_2n_n(B,\
    \ n);\n      ::std::copy(Q_i.m_digits.begin(), Q_i.m_digits.end(), Q.m_digits.begin()\
    \ + n * (t - 2));\n      for (::std::size_t i = t - 2; i --> 0;) {\n        Z\
    \ = R_i.concat(A, n * i, n * (i + 1));\n        ::std::tie(Q_i, R_i) = Z.divmod_2n_n(B,\
    \ n);\n        ::std::copy(Q_i.m_digits.begin(), Q_i.m_digits.end(), Q.m_digits.begin()\
    \ + n * i);\n      }\n\n      return ::std::make_pair(Q.regularize<0>(), R_i.divmod_naive_u64(::tools::bigint(sigma2)).first.rshift(sigma1));\n\
    \    }\n\n    ::tools::bigint& operator/=(const ::tools::bigint& other) {\n  \
    \    return *this = *this / other;\n    }\n    friend ::tools::bigint operator/(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return lhs.divmod(rhs).first;\n\
    \    }\n    ::tools::bigint& operator%=(const ::tools::bigint& other) {\n    \
    \  return *this = *this % other;\n    }\n    friend ::tools::bigint operator%(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return lhs.divmod(rhs).second;\n\
    \    }\n\n    template <typename T, ::std::enable_if_t<::std::is_integral_v<T>,\
    \ ::std::nullptr_t> = nullptr>\n    explicit operator T() const {\n      assert(::tools::bigint(::std::numeric_limits<T>::min())\
    \ <= *this && *this <= ::tools::bigint(::std::numeric_limits<T>::max()));\n  \
    \    T result = 0;\n      for (::std::size_t i = this->m_digits.size(); i -->\
    \ 0;) {\n        result = result * BASE + this->m_digits[i] * (this->m_positive\
    \ ? 1 : -1);\n      }\n      return result;\n    }\n\n    explicit operator bool()\
    \ const {\n      return !this->m_digits.empty();\n    }\n\n    explicit operator\
    \ ::tools::int128_t() const {\n      assert(::tools::bigint(INT128_MIN) <= *this\
    \ && *this <= ::tools::bigint(INT128_MAX));\n      ::tools::int128_t result =\
    \ 0;\n      for (::std::size_t i = this->m_digits.size(); i --> 0;) {\n      \
    \  result = result * BASE + this->m_digits[i] * (this->m_positive ? 1 : -1);\n\
    \      }\n      return result;\n    }\n\n    explicit operator ::tools::uint128_t()\
    \ const {\n      assert(::tools::bigint(0) <= *this && *this <= ::tools::bigint(UINT128_MAX));\n\
    \      ::tools::uint128_t result = 0;\n      for (::std::size_t i = this->m_digits.size();\
    \ i --> 0;) {\n        result = result * BASE + this->m_digits[i];\n      }\n\
    \      return result;\n    }\n\n    explicit operator double() const {\n     \
    \ long double result = 0.0;\n      const ::std::size_t precision = this->size();\n\
    \      for (::std::size_t i = 0; i < ::std::numeric_limits<long double>::digits10;\
    \ ++i) {\n        result = result * 10.0L + (precision >= i + 1 ? (*this)[precision\
    \ - 1 - i] : 0) * this->signum();\n      }\n      result *= ::std::pow(10.0L,\
    \ static_cast<long double>(precision) - static_cast<long double>(::std::numeric_limits<long\
    \ double>::digits10));\n      return static_cast<double>(result);\n    }\n\n \
    \   friend ::std::istream& operator>>(::std::istream& is, ::tools::bigint& self)\
    \ {\n      ::std::string s;\n      is >> s;\n      self = ::tools::bigint(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::bigint& self) {\n      if (!self.m_positive) {\n        os\
    \ << '-';\n      }\n      if (self.m_digits.empty()) {\n        return os << '0';\n\
    \      }\n      os << self.m_digits.back();\n      for (::std::size_t i = 1; i\
    \ < self.m_digits.size(); ++i) {\n        os << ::std::setw(LOG10_BASE) << ::std::setfill('0')\
    \ << self.m_digits[self.m_digits.size() - 1 - i];\n      }\n      return os;\n\
    \    }\n\n    friend ::tools::bigint abs(::tools::bigint x);\n  };\n\n  inline\
    \ ::tools::bigint abs(::tools::bigint x) {\n    if (!x.m_positive) x.negate();\n\
    \    return x;\n  }\n\n  template <>\n  ::tools::bigint gcd<::tools::bigint, ::tools::bigint>(::tools::bigint\
    \ x, ::tools::bigint y) {\n    if (x.signum() < 0) x.negate();\n    if (y.signum()\
    \ < 0) y.negate();\n\n    while (y.signum() != 0) {\n      x %= y;\n      ::std::swap(x,\
    \ y);\n    }\n\n    return x;\n  }\n}\n\n\n#line 9 \"tests/monoid.test.cpp\"\n\
    \nusing mint = atcoder::modint998244353;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::monoid::max<bool>::op(false,\
    \ true) == true);\n  assert_that(tools::monoid::max<bool>::e() == false);\n  assert_that(tools::monoid::max<char>::op('a',\
    \ 'b') == 'b');\n  assert_that(tools::monoid::max<char>::e() == std::numeric_limits<char>::min());\n\
    \  assert_that(tools::monoid::max<short>::op(-1, 1) == 1);\n  assert_that(tools::monoid::max<short>::e()\
    \ == std::numeric_limits<short>::min());\n  assert_that(tools::monoid::max<unsigned\
    \ short>::op(0U, 1U) == 1U);\n  assert_that(tools::monoid::max<unsigned short>::e()\
    \ == 0U);\n  assert_that(tools::monoid::max<int>::op(-1, 1) == 1);\n  assert_that(tools::monoid::max<int>::e()\
    \ == std::numeric_limits<int>::min());\n  assert_that(tools::monoid::max<unsigned\
    \ int>::op(0U, 1U) == 1U);\n  assert_that(tools::monoid::max<unsigned int>::e()\
    \ == 0U);\n  assert_that(tools::monoid::max<long>::op(-1L, 1L) == 1L);\n  assert_that(tools::monoid::max<long>::e()\
    \ == std::numeric_limits<long>::min());\n  assert_that(tools::monoid::max<unsigned\
    \ long>::op(0UL, 1UL) == 1UL);\n  assert_that(tools::monoid::max<unsigned long>::e()\
    \ == 0UL);\n  assert_that(tools::monoid::max<long long>::op(-1LL, 1LL) == 1LL);\n\
    \  assert_that(tools::monoid::max<long long>::e() == std::numeric_limits<long\
    \ long>::min());\n  assert_that(tools::monoid::max<unsigned long long>::op(0ULL,\
    \ 1ULL) == 1ULL);\n  assert_that(tools::monoid::max<unsigned long long>::e() ==\
    \ 0ULL);\n  assert_that(tools::monoid::max<float>::op(-1.0F, 1.0F) == 1.0F);\n\
    \  assert_that(tools::monoid::max<float>::e() == -std::numeric_limits<float>::infinity());\n\
    \  assert_that(tools::monoid::max<double>::op(-1.0, 1.0) == 1.0);\n  assert_that(tools::monoid::max<double>::e()\
    \ == -std::numeric_limits<double>::infinity());\n  assert_that(tools::monoid::max<long\
    \ double>::op(-1.0L, 1.0L) == 1.0L);\n  assert_that(tools::monoid::max<long double>::e()\
    \ == -std::numeric_limits<long double>::infinity());\n  assert_that(tools::monoid::max<int,\
    \ 42>::op(42, 43) == 43);\n  assert_that(tools::monoid::max<int, 42>::e() == 42);\n\
    \n  assert_that(tools::monoid::min<bool>::op(false, true) == false);\n  assert_that(tools::monoid::min<bool>::e()\
    \ == true);\n  assert_that(tools::monoid::min<char>::op('a', 'b') == 'a');\n \
    \ assert_that(tools::monoid::min<char>::e() == std::numeric_limits<char>::max());\n\
    \  assert_that(tools::monoid::min<short>::op(-1, 1) == -1);\n  assert_that(tools::monoid::min<short>::e()\
    \ == std::numeric_limits<short>::max());\n  assert_that(tools::monoid::min<unsigned\
    \ short>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::min<unsigned short>::e()\
    \ == std::numeric_limits<unsigned short>::max());\n  assert_that(tools::monoid::min<int>::op(-1,\
    \ 1) == -1);\n  assert_that(tools::monoid::min<int>::e() == std::numeric_limits<int>::max());\n\
    \  assert_that(tools::monoid::min<unsigned int>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::min<unsigned\
    \ int>::e() == std::numeric_limits<unsigned int>::max());\n  assert_that(tools::monoid::min<long>::op(-1L,\
    \ 1L) == -1L);\n  assert_that(tools::monoid::min<long>::e() == std::numeric_limits<long>::max());\n\
    \  assert_that(tools::monoid::min<unsigned long>::op(0UL, 1UL) == 0UL);\n  assert_that(tools::monoid::min<unsigned\
    \ long>::e() == std::numeric_limits<unsigned long>::max());\n  assert_that(tools::monoid::min<long\
    \ long>::op(-1LL, 1LL) == -1LL);\n  assert_that(tools::monoid::min<long long>::e()\
    \ == std::numeric_limits<long long>::max());\n  assert_that(tools::monoid::min<unsigned\
    \ long long>::op(0ULL, 1ULL) == 0ULL);\n  assert_that(tools::monoid::min<unsigned\
    \ long long>::e() == std::numeric_limits<unsigned long long>::max());\n  assert_that(tools::monoid::min<float>::op(-1.0F,\
    \ 1.0F) == -1.0F);\n  assert_that(tools::monoid::min<float>::e() == std::numeric_limits<float>::infinity());\n\
    \  assert_that(tools::monoid::min<double>::op(-1.0, 1.0) == -1.0);\n  assert_that(tools::monoid::min<double>::e()\
    \ == std::numeric_limits<double>::infinity());\n  assert_that(tools::monoid::min<long\
    \ double>::op(-1.0L, 1.0L) == -1.0L);\n  assert_that(tools::monoid::min<long double>::e()\
    \ == std::numeric_limits<long double>::infinity());\n  assert_that(tools::monoid::min<int,\
    \ 42>::op(41, 42) == 41);\n  assert_that(tools::monoid::min<int, 42>::e() == 42);\n\
    \n  assert_that(tools::monoid::multiplies<bool>::op(false, true) == false);\n\
    \  assert_that(tools::monoid::multiplies<bool>::e() == true);\n  assert_that(tools::monoid::multiplies<short>::op(-2,\
    \ 3) == -6);\n  assert_that(tools::monoid::multiplies<short>::e() == 1);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ short>::op(2U, 3U) == 6U);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ short>::e() == 1U);\n  assert_that(tools::monoid::multiplies<int>::op(-2, 3)\
    \ == -6);\n  assert_that(tools::monoid::multiplies<int>::e() == 1);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ int>::op(2U, 3U) == 6U);\n  assert_that(tools::monoid::multiplies<unsigned int>::e()\
    \ == 1U);\n  assert_that(tools::monoid::multiplies<long>::op(-2L, 3L) == -6L);\n\
    \  assert_that(tools::monoid::multiplies<long>::e() == 1L);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ long>::op(2UL, 3UL) == 6UL);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ long>::e() == 1UL);\n  assert_that(tools::monoid::multiplies<long long>::op(-2LL,\
    \ 3LL) == -6LL);\n  assert_that(tools::monoid::multiplies<long long>::e() == 1LL);\n\
    \  assert_that(tools::monoid::multiplies<unsigned long long>::op(2ULL, 3ULL) ==\
    \ 6ULL);\n  assert_that(tools::monoid::multiplies<unsigned long long>::e() ==\
    \ 1ULL);\n  assert_that(tools::monoid::multiplies<float>::op(-2.0F, 3.0F) == -6.0F);\n\
    \  assert_that(tools::monoid::multiplies<float>::e() == 1.0F);\n  assert_that(tools::monoid::multiplies<double>::op(-2.0,\
    \ 3.0) == -6.0);\n  assert_that(tools::monoid::multiplies<double>::e() == 1.0);\n\
    \  assert_that(tools::monoid::multiplies<long double>::op(-2.0L, 3.0L) == -6.0L);\n\
    \  assert_that(tools::monoid::multiplies<long double>::e() == 1.0L);\n  assert_that(tools::monoid::multiplies<mint>::op(mint::raw(2),\
    \ mint::raw(3)) == mint::raw(6));\n  assert_that(tools::monoid::multiplies<mint>::e()\
    \ == mint::raw(1));\n  assert_that(tools::monoid::multiplies<tools::bigint>::op(tools::bigint(-2),\
    \ tools::bigint(3)) == tools::bigint(-6));\n  assert_that(tools::monoid::multiplies<tools::bigint>::e()\
    \ == tools::bigint(1));\n\n  assert_that(tools::monoid::gcd<short>::op(-12, 18)\
    \ == 6);\n  assert_that(tools::monoid::gcd<short>::e() == 0);\n  assert_that(tools::monoid::gcd<unsigned\
    \ short>::op(12U, 18U) == 6U);\n  assert_that(tools::monoid::gcd<unsigned short>::e()\
    \ == 0U);\n  assert_that(tools::monoid::gcd<int>::op(-12, 18) == 6);\n  assert_that(tools::monoid::gcd<int>::e()\
    \ == 0);\n  assert_that(tools::monoid::gcd<unsigned int>::op(12U, 18U) == 6U);\n\
    \  assert_that(tools::monoid::gcd<unsigned int>::e() == 0U);\n  assert_that(tools::monoid::gcd<long>::op(-12L,\
    \ 18L) == 6L);\n  assert_that(tools::monoid::gcd<long>::e() == 0L);\n  assert_that(tools::monoid::gcd<unsigned\
    \ long>::op(12UL, 18UL) == 6UL);\n  assert_that(tools::monoid::gcd<unsigned long>::e()\
    \ == 0UL);\n  assert_that(tools::monoid::gcd<long long>::op(-12LL, 18LL) == 6LL);\n\
    \  assert_that(tools::monoid::gcd<long long>::e() == 0LL);\n  assert_that(tools::monoid::gcd<unsigned\
    \ long long>::op(12ULL, 18ULL) == 6ULL);\n  assert_that(tools::monoid::gcd<unsigned\
    \ long long>::e() == 0ULL);\n  assert_that(tools::monoid::gcd<tools::bigint>::op(tools::bigint(-12),\
    \ tools::bigint(18)) == tools::bigint(6));\n  assert_that(tools::monoid::gcd<tools::bigint>::e()\
    \ == tools::bigint(0));\n\n  assert_that(tools::monoid::update<bool, false>::op(true,\
    \ false) == true);\n  assert_that(tools::monoid::update<bool, false>::op(false,\
    \ true) == true);\n  assert_that(tools::monoid::update<bool, false>::e() == false);\n\
    \  assert_that(tools::monoid::update<char, '\\0'>::op('a', 'b') == 'a');\n  assert_that(tools::monoid::update<char,\
    \ '\\0'>::op('\\0', 'b') == 'b');\n  assert_that(tools::monoid::update<char, '\\\
    0'>::e() == '\\0');\n  assert_that(tools::monoid::update<short, 42>::op(-1, 1)\
    \ == -1);\n  assert_that(tools::monoid::update<short, 42>::op(42, 1) == 1);\n\
    \  assert_that(tools::monoid::update<short, 42>::e() == 42);\n  assert_that(tools::monoid::update<unsigned\
    \ short, 42U>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::update<unsigned\
    \ short, 42U>::op(42U, 1U) == 1U);\n  assert_that(tools::monoid::update<unsigned\
    \ short, 42U>::e() == 42U);\n  assert_that(tools::monoid::update<int, 42>::op(-1,\
    \ 1) == -1);\n  assert_that(tools::monoid::update<int, 42>::op(42, 1) == 1);\n\
    \  assert_that(tools::monoid::update<int, 42>::e() == 42);\n  assert_that(tools::monoid::update<unsigned\
    \ int, 42U>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::update<unsigned\
    \ int, 42U>::op(42U, 1U) == 1U);\n  assert_that(tools::monoid::update<unsigned\
    \ int, 42U>::e() == 42U);\n  assert_that(tools::monoid::update<long, 42L>::op(-1L,\
    \ 1L) == -1L);\n  assert_that(tools::monoid::update<long, 42L>::op(42L, 1L) ==\
    \ 1L);\n  assert_that(tools::monoid::update<long, 42L>::e() == 42L);\n  assert_that(tools::monoid::update<unsigned\
    \ long, 42UL>::op(0UL, 1UL) == 0UL);\n  assert_that(tools::monoid::update<unsigned\
    \ long, 42UL>::op(42UL, 1UL) == 1UL);\n  assert_that(tools::monoid::update<unsigned\
    \ long, 42UL>::e() == 42UL);\n  assert_that(tools::monoid::update<long long, 42LL>::op(-1LL,\
    \ 1LL) == -1LL);\n  assert_that(tools::monoid::update<long long, 42LL>::op(42LL,\
    \ 1LL) == 1LL);\n  assert_that(tools::monoid::update<long long, 42LL>::e() ==\
    \ 42LL);\n  assert_that(tools::monoid::update<unsigned long long, 42ULL>::op(0ULL,\
    \ 1ULL) == 0ULL);\n  assert_that(tools::monoid::update<unsigned long long, 42ULL>::op(42ULL,\
    \ 1ULL) == 1ULL);\n  assert_that(tools::monoid::update<unsigned long long, 42ULL>::e()\
    \ == 42ULL);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <limits>\n#include \"atcoder/modint.hpp\"\n#include\
    \ \"tools/assert_that.hpp\"\n#include \"tools/monoid.hpp\"\n#include \"tools/bigint.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  assert_that(tools::monoid::max<bool>::op(false,\
    \ true) == true);\n  assert_that(tools::monoid::max<bool>::e() == false);\n  assert_that(tools::monoid::max<char>::op('a',\
    \ 'b') == 'b');\n  assert_that(tools::monoid::max<char>::e() == std::numeric_limits<char>::min());\n\
    \  assert_that(tools::monoid::max<short>::op(-1, 1) == 1);\n  assert_that(tools::monoid::max<short>::e()\
    \ == std::numeric_limits<short>::min());\n  assert_that(tools::monoid::max<unsigned\
    \ short>::op(0U, 1U) == 1U);\n  assert_that(tools::monoid::max<unsigned short>::e()\
    \ == 0U);\n  assert_that(tools::monoid::max<int>::op(-1, 1) == 1);\n  assert_that(tools::monoid::max<int>::e()\
    \ == std::numeric_limits<int>::min());\n  assert_that(tools::monoid::max<unsigned\
    \ int>::op(0U, 1U) == 1U);\n  assert_that(tools::monoid::max<unsigned int>::e()\
    \ == 0U);\n  assert_that(tools::monoid::max<long>::op(-1L, 1L) == 1L);\n  assert_that(tools::monoid::max<long>::e()\
    \ == std::numeric_limits<long>::min());\n  assert_that(tools::monoid::max<unsigned\
    \ long>::op(0UL, 1UL) == 1UL);\n  assert_that(tools::monoid::max<unsigned long>::e()\
    \ == 0UL);\n  assert_that(tools::monoid::max<long long>::op(-1LL, 1LL) == 1LL);\n\
    \  assert_that(tools::monoid::max<long long>::e() == std::numeric_limits<long\
    \ long>::min());\n  assert_that(tools::monoid::max<unsigned long long>::op(0ULL,\
    \ 1ULL) == 1ULL);\n  assert_that(tools::monoid::max<unsigned long long>::e() ==\
    \ 0ULL);\n  assert_that(tools::monoid::max<float>::op(-1.0F, 1.0F) == 1.0F);\n\
    \  assert_that(tools::monoid::max<float>::e() == -std::numeric_limits<float>::infinity());\n\
    \  assert_that(tools::monoid::max<double>::op(-1.0, 1.0) == 1.0);\n  assert_that(tools::monoid::max<double>::e()\
    \ == -std::numeric_limits<double>::infinity());\n  assert_that(tools::monoid::max<long\
    \ double>::op(-1.0L, 1.0L) == 1.0L);\n  assert_that(tools::monoid::max<long double>::e()\
    \ == -std::numeric_limits<long double>::infinity());\n  assert_that(tools::monoid::max<int,\
    \ 42>::op(42, 43) == 43);\n  assert_that(tools::monoid::max<int, 42>::e() == 42);\n\
    \n  assert_that(tools::monoid::min<bool>::op(false, true) == false);\n  assert_that(tools::monoid::min<bool>::e()\
    \ == true);\n  assert_that(tools::monoid::min<char>::op('a', 'b') == 'a');\n \
    \ assert_that(tools::monoid::min<char>::e() == std::numeric_limits<char>::max());\n\
    \  assert_that(tools::monoid::min<short>::op(-1, 1) == -1);\n  assert_that(tools::monoid::min<short>::e()\
    \ == std::numeric_limits<short>::max());\n  assert_that(tools::monoid::min<unsigned\
    \ short>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::min<unsigned short>::e()\
    \ == std::numeric_limits<unsigned short>::max());\n  assert_that(tools::monoid::min<int>::op(-1,\
    \ 1) == -1);\n  assert_that(tools::monoid::min<int>::e() == std::numeric_limits<int>::max());\n\
    \  assert_that(tools::monoid::min<unsigned int>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::min<unsigned\
    \ int>::e() == std::numeric_limits<unsigned int>::max());\n  assert_that(tools::monoid::min<long>::op(-1L,\
    \ 1L) == -1L);\n  assert_that(tools::monoid::min<long>::e() == std::numeric_limits<long>::max());\n\
    \  assert_that(tools::monoid::min<unsigned long>::op(0UL, 1UL) == 0UL);\n  assert_that(tools::monoid::min<unsigned\
    \ long>::e() == std::numeric_limits<unsigned long>::max());\n  assert_that(tools::monoid::min<long\
    \ long>::op(-1LL, 1LL) == -1LL);\n  assert_that(tools::monoid::min<long long>::e()\
    \ == std::numeric_limits<long long>::max());\n  assert_that(tools::monoid::min<unsigned\
    \ long long>::op(0ULL, 1ULL) == 0ULL);\n  assert_that(tools::monoid::min<unsigned\
    \ long long>::e() == std::numeric_limits<unsigned long long>::max());\n  assert_that(tools::monoid::min<float>::op(-1.0F,\
    \ 1.0F) == -1.0F);\n  assert_that(tools::monoid::min<float>::e() == std::numeric_limits<float>::infinity());\n\
    \  assert_that(tools::monoid::min<double>::op(-1.0, 1.0) == -1.0);\n  assert_that(tools::monoid::min<double>::e()\
    \ == std::numeric_limits<double>::infinity());\n  assert_that(tools::monoid::min<long\
    \ double>::op(-1.0L, 1.0L) == -1.0L);\n  assert_that(tools::monoid::min<long double>::e()\
    \ == std::numeric_limits<long double>::infinity());\n  assert_that(tools::monoid::min<int,\
    \ 42>::op(41, 42) == 41);\n  assert_that(tools::monoid::min<int, 42>::e() == 42);\n\
    \n  assert_that(tools::monoid::multiplies<bool>::op(false, true) == false);\n\
    \  assert_that(tools::monoid::multiplies<bool>::e() == true);\n  assert_that(tools::monoid::multiplies<short>::op(-2,\
    \ 3) == -6);\n  assert_that(tools::monoid::multiplies<short>::e() == 1);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ short>::op(2U, 3U) == 6U);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ short>::e() == 1U);\n  assert_that(tools::monoid::multiplies<int>::op(-2, 3)\
    \ == -6);\n  assert_that(tools::monoid::multiplies<int>::e() == 1);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ int>::op(2U, 3U) == 6U);\n  assert_that(tools::monoid::multiplies<unsigned int>::e()\
    \ == 1U);\n  assert_that(tools::monoid::multiplies<long>::op(-2L, 3L) == -6L);\n\
    \  assert_that(tools::monoid::multiplies<long>::e() == 1L);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ long>::op(2UL, 3UL) == 6UL);\n  assert_that(tools::monoid::multiplies<unsigned\
    \ long>::e() == 1UL);\n  assert_that(tools::monoid::multiplies<long long>::op(-2LL,\
    \ 3LL) == -6LL);\n  assert_that(tools::monoid::multiplies<long long>::e() == 1LL);\n\
    \  assert_that(tools::monoid::multiplies<unsigned long long>::op(2ULL, 3ULL) ==\
    \ 6ULL);\n  assert_that(tools::monoid::multiplies<unsigned long long>::e() ==\
    \ 1ULL);\n  assert_that(tools::monoid::multiplies<float>::op(-2.0F, 3.0F) == -6.0F);\n\
    \  assert_that(tools::monoid::multiplies<float>::e() == 1.0F);\n  assert_that(tools::monoid::multiplies<double>::op(-2.0,\
    \ 3.0) == -6.0);\n  assert_that(tools::monoid::multiplies<double>::e() == 1.0);\n\
    \  assert_that(tools::monoid::multiplies<long double>::op(-2.0L, 3.0L) == -6.0L);\n\
    \  assert_that(tools::monoid::multiplies<long double>::e() == 1.0L);\n  assert_that(tools::monoid::multiplies<mint>::op(mint::raw(2),\
    \ mint::raw(3)) == mint::raw(6));\n  assert_that(tools::monoid::multiplies<mint>::e()\
    \ == mint::raw(1));\n  assert_that(tools::monoid::multiplies<tools::bigint>::op(tools::bigint(-2),\
    \ tools::bigint(3)) == tools::bigint(-6));\n  assert_that(tools::monoid::multiplies<tools::bigint>::e()\
    \ == tools::bigint(1));\n\n  assert_that(tools::monoid::gcd<short>::op(-12, 18)\
    \ == 6);\n  assert_that(tools::monoid::gcd<short>::e() == 0);\n  assert_that(tools::monoid::gcd<unsigned\
    \ short>::op(12U, 18U) == 6U);\n  assert_that(tools::monoid::gcd<unsigned short>::e()\
    \ == 0U);\n  assert_that(tools::monoid::gcd<int>::op(-12, 18) == 6);\n  assert_that(tools::monoid::gcd<int>::e()\
    \ == 0);\n  assert_that(tools::monoid::gcd<unsigned int>::op(12U, 18U) == 6U);\n\
    \  assert_that(tools::monoid::gcd<unsigned int>::e() == 0U);\n  assert_that(tools::monoid::gcd<long>::op(-12L,\
    \ 18L) == 6L);\n  assert_that(tools::monoid::gcd<long>::e() == 0L);\n  assert_that(tools::monoid::gcd<unsigned\
    \ long>::op(12UL, 18UL) == 6UL);\n  assert_that(tools::monoid::gcd<unsigned long>::e()\
    \ == 0UL);\n  assert_that(tools::monoid::gcd<long long>::op(-12LL, 18LL) == 6LL);\n\
    \  assert_that(tools::monoid::gcd<long long>::e() == 0LL);\n  assert_that(tools::monoid::gcd<unsigned\
    \ long long>::op(12ULL, 18ULL) == 6ULL);\n  assert_that(tools::monoid::gcd<unsigned\
    \ long long>::e() == 0ULL);\n  assert_that(tools::monoid::gcd<tools::bigint>::op(tools::bigint(-12),\
    \ tools::bigint(18)) == tools::bigint(6));\n  assert_that(tools::monoid::gcd<tools::bigint>::e()\
    \ == tools::bigint(0));\n\n  assert_that(tools::monoid::update<bool, false>::op(true,\
    \ false) == true);\n  assert_that(tools::monoid::update<bool, false>::op(false,\
    \ true) == true);\n  assert_that(tools::monoid::update<bool, false>::e() == false);\n\
    \  assert_that(tools::monoid::update<char, '\\0'>::op('a', 'b') == 'a');\n  assert_that(tools::monoid::update<char,\
    \ '\\0'>::op('\\0', 'b') == 'b');\n  assert_that(tools::monoid::update<char, '\\\
    0'>::e() == '\\0');\n  assert_that(tools::monoid::update<short, 42>::op(-1, 1)\
    \ == -1);\n  assert_that(tools::monoid::update<short, 42>::op(42, 1) == 1);\n\
    \  assert_that(tools::monoid::update<short, 42>::e() == 42);\n  assert_that(tools::monoid::update<unsigned\
    \ short, 42U>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::update<unsigned\
    \ short, 42U>::op(42U, 1U) == 1U);\n  assert_that(tools::monoid::update<unsigned\
    \ short, 42U>::e() == 42U);\n  assert_that(tools::monoid::update<int, 42>::op(-1,\
    \ 1) == -1);\n  assert_that(tools::monoid::update<int, 42>::op(42, 1) == 1);\n\
    \  assert_that(tools::monoid::update<int, 42>::e() == 42);\n  assert_that(tools::monoid::update<unsigned\
    \ int, 42U>::op(0U, 1U) == 0U);\n  assert_that(tools::monoid::update<unsigned\
    \ int, 42U>::op(42U, 1U) == 1U);\n  assert_that(tools::monoid::update<unsigned\
    \ int, 42U>::e() == 42U);\n  assert_that(tools::monoid::update<long, 42L>::op(-1L,\
    \ 1L) == -1L);\n  assert_that(tools::monoid::update<long, 42L>::op(42L, 1L) ==\
    \ 1L);\n  assert_that(tools::monoid::update<long, 42L>::e() == 42L);\n  assert_that(tools::monoid::update<unsigned\
    \ long, 42UL>::op(0UL, 1UL) == 0UL);\n  assert_that(tools::monoid::update<unsigned\
    \ long, 42UL>::op(42UL, 1UL) == 1UL);\n  assert_that(tools::monoid::update<unsigned\
    \ long, 42UL>::e() == 42UL);\n  assert_that(tools::monoid::update<long long, 42LL>::op(-1LL,\
    \ 1LL) == -1LL);\n  assert_that(tools::monoid::update<long long, 42LL>::op(42LL,\
    \ 1LL) == 1LL);\n  assert_that(tools::monoid::update<long long, 42LL>::e() ==\
    \ 42LL);\n  assert_that(tools::monoid::update<unsigned long long, 42ULL>::op(0ULL,\
    \ 1ULL) == 0ULL);\n  assert_that(tools::monoid::update<unsigned long long, 42ULL>::op(42ULL,\
    \ 1ULL) == 1ULL);\n  assert_that(tools::monoid::update<unsigned long long, 42ULL>::e()\
    \ == 42ULL);\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/monoid.hpp
  - tools/gcd.hpp
  - tools/bigint.hpp
  - tools/abs.hpp
  - tools/quo.hpp
  - tools/mod.hpp
  - tools/floor.hpp
  - tools/ssize.hpp
  - tools/int128_t.hpp
  - tools/uint128_t.hpp
  - tools/ceil.hpp
  - tools/pow2.hpp
  - tools/garner2.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/monoid.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/monoid.test.cpp
layout: document
redirect_from:
- /verify/tests/monoid.test.cpp
- /verify/tests/monoid.test.cpp.html
title: tests/monoid.test.cpp
---