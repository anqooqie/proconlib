---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':heavy_check_mark:'
    path: tools/garner3.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$, $\mathbb{Z} / M_2
      \mathbb{Z}$ and $\mathbb{Z} / M_3 \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/has_mod.hpp
    title: Check whether T has the member function mod()
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/polynomial.hpp
    title: Polynomial
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
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/bostan_mori.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <numeric>\n#include <cstddef>\n#line 1 \"tools/polynomial.hpp\"\n\n\n\n#include\
    \ <vector>\n#line 6 \"tools/polynomial.hpp\"\n#include <initializer_list>\n#include\
    \ <utility>\n#include <algorithm>\n#line 10 \"tools/polynomial.hpp\"\n#include\
    \ <iterator>\n#line 1 \"tools/fps.hpp\"\n\n\n\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\n\n\n#line 6 \"lib/ac-library/atcoder/modint.hpp\"\n#include <type_traits>\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"lib/ac-library/atcoder/internal_math.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/internal_math.hpp\"\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
    // Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned\
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
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
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
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/convolution.hpp\"\n#include <array>\n\
    #line 9 \"lib/ac-library/atcoder/convolution.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U\
    \ << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n\
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int\
    \ bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 << x)))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n\
    }  // namespace atcoder\n\n\n#line 12 \"lib/ac-library/atcoder/convolution.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class mint,\n   \
    \       int g = internal::primitive_root<mint::mod()>,\n          internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n    static constexpr int rank2 = bsf_constexpr(mint::mod()\
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
    \ = internal::ceil_pow2(n);\n\n    static const fft_info<mint> info;\n\n    int\
    \ len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n    while (len\
    \ < h) {\n        if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n\
    \            mint rot = 1;\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto l = a[i + offset];\n               \
    \     auto r = a[i + offset + p] * rot;\n                    a[i + offset] = l\
    \ + r;\n                    a[i + offset + p] = l - r;\n                }\n  \
    \              if (s + 1 != (1 << len))\n                    rot *= info.rate2[bsf(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        } else {\n          \
    \  // 4-base\n            int p = 1 << (h - len - 2);\n            mint rot =\
    \ 1, imag = info.root[2];\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                mint rot2 = rot * rot;\n                mint rot3 = rot2 * rot;\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \                    auto a0 = 1ULL * a[i + offset].val();\n                 \
    \   auto a1 = 1ULL * a[i + offset + p].val() * rot.val();\n                  \
    \  auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n              \
    \      auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n          \
    \          auto a1na3imag =\n                        1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    auto na2 = mod2 - a2;\n                 \
    \   a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset + 1 *\
    \ p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n                    a[i + offset + 2\
    \ * p] = a0 + na2 + a1na3imag;\n                    a[i + offset + 3 * p] = a0\
    \ + na2 + (mod2 - a1na3imag);\n                }\n                if (s + 1 !=\
    \ (1 << len))\n                    rot *= info.rate3[bsf(~(unsigned int)(s))];\n\
    \            }\n            len += 2;\n        }\n    }\n}\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nvoid butterfly_inv(std::vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = internal::ceil_pow2(n);\n\n  \
    \  static const fft_info<mint> info;\n\n    int len = h;  // a[i, i+(n>>len),\
    \ i+2*(n>>len), ..] is transformed\n    while (len) {\n        if (len == 1) {\n\
    \            int p = 1 << (h - len);\n            mint irot = 1;\n           \
    \ for (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s\
    \ << (h - len + 1);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto l = a[i + offset];\n                    auto r = a[i + offset\
    \ + p];\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] =\n                        (unsigned long long)(mint::mod() + l.val()\
    \ - r.val()) *\n                        irot.val();\n                    ;\n \
    \               }\n                if (s + 1 != (1 << (len - 1)))\n          \
    \          irot *= info.irate2[bsf(~(unsigned int)(s))];\n            }\n    \
    \        len--;\n        } else {\n            // 4-base\n            int p =\
    \ 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n       \
    \     for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = 1ULL * a[i + offset + 0 * p].val();\n     \
    \               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n              \
    \      auto a2 = 1ULL * a[i + offset + 2 * p].val();\n                    auto\
    \ a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                    auto a2na3iimag\
    \ =\n                        1ULL *\n                        mint((mint::mod()\
    \ + a2 - a3) * iimag.val()).val();\n\n                    a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n                    a[i + offset + 1 * p] =\n               \
    \         (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n             \
    \       a[i + offset + 2 * p] =\n                        (a0 + a1 + (mint::mod()\
    \ - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n      \
    \              a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[bsf(~(unsigned int)(s))];\n            }\n   \
    \         len -= 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
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
    \   int z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n    internal::butterfly(a);\n\
    \    b.resize(z);\n    internal::butterfly(b);\n    for (int i = 0; i < z; i++)\
    \ {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(n\
    \ + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1;\
    \ i++) a[i] *= iz;\n    return a;\n}\n\n}  // namespace internal\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(std::vector<mint>&&\
    \ a, std::vector<mint>&& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    if (std::min(n, m) <= 60) return convolution_naive(a,\
    \ b);\n    return internal::convolution_fft(a, b);\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& a,\n                              const std::vector<mint>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n    if (std::min(n, m) <= 60) return convolution_naive(a, b);\n    return\
    \ internal::convolution_fft(a, b);\n}\n\ntemplate <unsigned int mod = 998244353,\n\
    \          class T,\n          std::enable_if_t<internal::is_integral<T>::value>*\
    \ = nullptr>\nstd::vector<T> convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n\n    using mint = static_modint<mod>;\n    std::vector<mint> a2(n), b2(m);\n\
    \    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n    }\n    for\
    \ (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n    auto c2 =\
    \ convolution(move(a2), move(b2));\n    std::vector<T> c(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n    }\n    return\
    \ c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long long>&\
    \ a,\n                                      const std::vector<long long>& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n    static\
    \ constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr unsigned\
    \ long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3\
    \ = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n    auto c1 = convolution<MOD1>(a,\
    \ b);\n    auto c2 = convolution<MOD2>(a, b);\n    auto c3 = convolution<MOD3>(a,\
    \ b);\n\n    std::vector<long long> c(n + m - 1);\n    for (int i = 0; i < n +\
    \ m - 1; i++) {\n        unsigned long long x = 0;\n        x += (c1[i] * i1)\
    \ % MOD1 * M2M3;\n        x += (c2[i] * i2) % MOD2 * M1M3;\n        x += (c3[i]\
    \ * i3) % MOD3 * M1M2;\n        // B = 2^63, -B <= x, r(real value) < B\n    \
    \    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n        // r = c1[i] (mod\
    \ MOD1)\n        // focus on MOD1\n        // r = x, x - M', x - 2M', x - 3M'\
    \ (M' = M % 2^64) (mod 2B)\n        // r = x,\n        //     x - M' + (0 or 2B),\n\
    \        //     x - 2M' + (0, 2B or 4B),\n        //     x - 3M' + (0, 2B, 4B\
    \ or 6B) (without mod!)\n        // (r - x) = 0, (0)\n        //           - M'\
    \ + (0 or 2B), (1)\n        //           -2M' + (0 or 2B or 4B), (2)\n       \
    \ //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n        // we checked\
    \ that\n        //   ((1) mod MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod\
    \ 5 = 3\n        //   ((3) mod MOD1) mod 5 = 4\n        long long diff =\n   \
    \         c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));\n   \
    \     if (diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {\n            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x\
    \ -= offset[diff % 5];\n        c[i] = x;\n    }\n\n    return c;\n}\n\n}  //\
    \ namespace atcoder\n\n\n#line 1 \"tools/convolution.hpp\"\n\n\n\n#line 8 \"tools/convolution.hpp\"\
    \n#include <complex>\n#include <cmath>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line\
    \ 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/ceil_log2.hpp\"\
    \n\n\n\n#line 6 \"tools/ceil_log2.hpp\"\n#include <limits>\n#include <tuple>\n\
    #line 9 \"tools/ceil_log2.hpp\"\n#include <cstdint>\n\n// Source: https://stackoverflow.com/questions/3272424/compute-fast-log-base-2-ceiling/15327567#15327567\n\
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
    \n#line 1 \"tools/is_prime.hpp\"\n\n\n\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n\
    #line 1 \"tools/uint128_t.hpp\"\n\n\n\n#include <iostream>\n#include <string>\n\
    #line 9 \"tools/uint128_t.hpp\"\n\nnamespace tools {\n  using uint128_t = unsigned\
    \ __int128;\n}\n\n::std::istream& operator>>(::std::istream& is, ::tools::uint128_t&\
    \ x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for\
    \ (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n\
    ::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n  if (x\
    \ == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n    s.push_back('0'\
    \ + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(), s.end());\n\n  return\
    \ os << s;\n}\n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x,\
    \ const T2 y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n    u128 prod_mod\
    \ = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0)\
    \ ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\
    \n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line\
    \ 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const\
    \ M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else\
    \ {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      }\
    \ else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\
    \n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n\
    \    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n   \
    \   return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs)\
    \ * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools\
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
    \ 1 \"tools/garner3.hpp\"\n\n\n\n#line 7 \"tools/garner3.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename M1, typename M2, typename M3>\n  M garner3(const\
    \ M1& a, const M2& b, const M3& c, const M m) {\n    using ull = unsigned long\
    \ long;\n    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n    static\
    \ const M3 m1_m2_inv_mod_m3 = (M3::raw(M1::mod()) * M3::raw(M2::mod())).inv();\n\
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
    \ 19 \"tools/convolution.hpp\"\n\nnamespace tools {\n  namespace detail {\n  \
    \  namespace convolution {\n      // return maximum 2^k s.t. x = 1 (mod 2^k)\n\
    \      constexpr unsigned int pow2_k(const unsigned int x) {\n        assert(x\
    \ != 1);\n        return (x - 1) & -(x - 1);\n      }\n\n      template <typename\
    \ T>\n      ::std::vector<T> naive(const ::std::vector<T>& a, const ::std::vector<T>&\
    \ b) {\n        assert(!a.empty() && !b.empty());\n\n        ::std::vector<T>\
    \ c(a.size() + b.size() - 1);\n        for (::std::size_t i = 0; i < a.size();\
    \ ++i) {\n          for (::std::size_t j = 0; j < b.size(); ++j) {\n         \
    \   c[i + j] += a[i] * b[j];\n          }\n        }\n\n        return c;\n  \
    \    }\n\n      template <typename C>\n      ::std::vector<C> fft(::std::vector<C>\
    \ a, ::std::vector<C> b) {\n        static_assert(::std::is_same_v<C, ::std::complex<float>>\
    \ || ::std::is_same_v<C, ::std::complex<double>> || ::std::is_same_v<C, ::std::complex<long\
    \ double>>);\n        assert(!a.empty() && !b.empty());\n\n        using R = typename\
    \ C::value_type;\n\n        const auto original_n = a.size() + b.size() - 1;\n\
    \        const auto n = ::tools::pow2(::tools::ceil_log2(original_n));\n     \
    \   a.resize(n);\n        b.resize(n);\n\n        ::std::vector<C> pow_root;\n\
    \        pow_root.reserve(n);\n        pow_root.emplace_back(1, 0);\n        if\
    \ (n > 1) pow_root.push_back(::std::polar<R>(1, R(2) * ::std::acos(R(-1)) / n));\n\
    \        for (::std::size_t p = 2; p < n; p *= 2) {\n          pow_root.push_back(pow_root[p\
    \ / 2] * pow_root[p / 2]);\n          for (::std::size_t i = p + 1; i < p * 2;\
    \ ++i) {\n            pow_root.push_back(pow_root[p] * pow_root[i - p]);\n   \
    \       }\n        }\n\n        const auto butterfly = [&](::std::vector<C>& f)\
    \ {\n          ::std::vector<C> prev(n);\n          for (::std::size_t p = n /\
    \ 2; p >= 1; p /= 2) {\n            prev.swap(f);\n            for (::std::size_t\
    \ qp = 0; qp < n; qp += p) {\n              for (::std::size_t r = 0; r < p; ++r)\
    \ {\n                f[qp + r] = prev[qp * 2 % n + r] + pow_root[qp] * prev[qp\
    \ * 2 % n + p + r];\n              }\n            }\n          }\n        };\n\
    \n        butterfly(a);\n        butterfly(b);\n\n        ::std::vector<C> c;\n\
    \        c.reserve(n);\n        for (::std::size_t i = 0; i < n; ++i) {\n    \
    \      c.push_back(a[i] * b[i]);\n        }\n\n        ::std::reverse(::std::next(pow_root.begin()),\
    \ pow_root.end());\n        butterfly(c);\n        for (auto& c_i : c) c_i /=\
    \ n;\n\n        c.resize(original_n);\n        return c;\n      }\n\n      template\
    \ <typename R>\n      ::std::vector<R> fft_real(const ::std::vector<R>& a, const\
    \ ::std::vector<R>& b) {\n        static_assert(::std::is_floating_point_v<R>);\n\
    \        assert(!a.empty() && !b.empty());\n\n        ::std::vector<::std::complex<R>>\
    \ a_complex;\n        a_complex.reserve(a.size());\n        for (const auto& a_i\
    \ : a) a_complex.emplace_back(a_i, 0);\n\n        ::std::vector<::std::complex<R>>\
    \ b_complex;\n        b_complex.reserve(b.size());\n        for (const auto& b_i\
    \ : b) b_complex.emplace_back(b_i, 0);\n\n        const auto c_complex = ::tools::detail::convolution::fft(a_complex,\
    \ b_complex);\n\n        ::std::vector<R> c;\n        c.reserve(c_complex.size());\n\
    \        for (const auto& c_i : c_complex) c.push_back(c_i.real());\n\n      \
    \  return c;\n      }\n\n      template <typename M>\n      ::std::vector<M> ntt(const\
    \ ::std::vector<M>& a, const ::std::vector<M>& b) {\n        static_assert(::atcoder::internal::is_static_modint<M>::value);\n\
    \        static_assert(2 <= M::mod() && M::mod() <= 2000000000);\n        static_assert(::tools::is_prime(M::mod()));\n\
    \        assert(a.size() + b.size() <= ::tools::detail::convolution::pow2_k(M::mod())\
    \ + 1);\n\n        return ::atcoder::convolution(a, b);\n      }\n\n      template\
    \ <typename M>\n      ::std::vector<M> ntt_and_garner(const ::std::vector<M>&\
    \ a, const ::std::vector<M>& b) {\n        using M1 = ::atcoder::static_modint<1107296257>;\
    \ // 33 * 2^25 + 1\n        using M2 = ::atcoder::static_modint<1711276033>; //\
    \ 51 * 2^25 + 1\n        using M3 = ::atcoder::static_modint<1811939329>; // 27\
    \ * 2^26 + 1\n\n        static_assert(::atcoder::internal::is_static_modint<M>::value\
    \ || ::atcoder::internal::is_dynamic_modint<M>::value);\n        assert(a.size()\
    \ + b.size() <= ::std::min({::tools::detail::convolution::pow2_k(M1::mod()), ::tools::detail::convolution::pow2_k(M2::mod()),\
    \ ::tools::detail::convolution::pow2_k(M3::mod())}) + 1);\n\n        // No need\
    \ for the following assertion because the condition always holds.\n        //\
    \ assert(std::min(a.size(), b.size()) * tools::square(M::mod() - 1) < M1::mod()\
    \ * M2::mod() * M3::mod());\n\n        ::std::vector<M1> a1;\n        ::std::vector<M2>\
    \ a2;\n        ::std::vector<M3> a3;\n        a1.reserve(a.size());\n        a2.reserve(a.size());\n\
    \        a3.reserve(a.size());\n        for (const auto& a_i : a) {\n        \
    \  a1.emplace_back(a_i.val());\n          a2.emplace_back(a_i.val());\n      \
    \    a3.emplace_back(a_i.val());\n        }\n\n        ::std::vector<M1> b1;\n\
    \        ::std::vector<M2> b2;\n        ::std::vector<M3> b3;\n        b1.reserve(b.size());\n\
    \        b2.reserve(b.size());\n        b3.reserve(b.size());\n        for (const\
    \ auto& b_i : b) {\n          b1.emplace_back(b_i.val());\n          b2.emplace_back(b_i.val());\n\
    \          b3.emplace_back(b_i.val());\n        }\n\n        const auto c1 = ::atcoder::convolution(a1,\
    \ b1);\n        const auto c2 = ::atcoder::convolution(a2, b2);\n        const\
    \ auto c3 = ::atcoder::convolution(a3, b3);\n\n        assert(c1.size() == c2.size()\
    \ && c2.size() == c3.size());\n        ::std::vector<M> c;\n        c.reserve(c1.size());\n\
    \n        for (::std::size_t i = 0; i < c1.size(); ++i) {\n          c.push_back(M::raw(::tools::garner3(c1[i],\
    \ c2[i], c3[i], M::mod())));\n        }\n        return c;\n      }\n\n      template\
    \ <typename Z>\n      ::std::vector<Z> ntt_and_garner_for_ll(const ::std::vector<Z>&\
    \ a, const ::std::vector<Z>& b) {\n        assert(a.size() + b.size() <= ::tools::pow2(24)\
    \ + 1);\n\n        const auto c = ::atcoder::convolution_ll(::std::vector<long\
    \ long>(a.begin(), a.end()), ::std::vector<long long>(b.begin(), b.end()));\n\
    \        return ::std::vector<Z>(c.begin(), c.end());\n      }\n    }\n  }\n\n\
    \  template <typename InputIterator, typename OutputIterator>\n  void convolution(const\
    \ InputIterator a_begin, const InputIterator a_end, const InputIterator b_begin,\
    \ const InputIterator b_end, OutputIterator result) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \n    if (a_begin == a_end || b_begin == b_end) return;\n\n    ::std::vector<T>\
    \ a(a_begin, a_end);\n    ::std::vector<T> b(b_begin, b_end);\n\n    auto c =\
    \ [&]() {\n      if constexpr (::std::is_same_v<T, ::std::complex<float>> || ::std::is_same_v<T,\
    \ ::std::complex<double>> || ::std::is_same_v<T, ::std::complex<long double>>)\
    \ {\n        return ::tools::detail::convolution::fft(a, b);\n      } else if\
    \ constexpr (::std::is_floating_point_v<T>) {\n        return ::tools::detail::convolution::fft_real(a,\
    \ b);\n      } else if constexpr (::std::is_integral_v<T>) {\n        return ::tools::detail::convolution::ntt_and_garner_for_ll(a,\
    \ b);\n      } else if constexpr (::atcoder::internal::is_static_modint<T>::value\
    \ || ::atcoder::internal::is_dynamic_modint<T>::value) {\n        if constexpr\
    \ (::atcoder::internal::is_static_modint<T>::value && T::mod() <= 2000000000 &&\
    \ ::tools::is_prime(T::mod())) {\n          if (a.size() + b.size() <= ::tools::detail::convolution::pow2_k(T::mod())\
    \ + 1) {\n            return ::tools::detail::convolution::ntt(a, b);\n      \
    \    } else {\n            return ::tools::detail::convolution::ntt_and_garner(a,\
    \ b);\n          }\n        } else {\n          return ::tools::detail::convolution::ntt_and_garner(a,\
    \ b);\n        }\n      } else {\n        return ::tools::detail::convolution::naive(a,\
    \ b);\n      }\n    }();\n    ::std::move(c.begin(), c.end(), result);\n  }\n\
    }\n\n\n#line 1 \"tools/less_by_first.hpp\"\n\n\n\n#line 5 \"tools/less_by_first.hpp\"\
    \n\nnamespace tools {\n\n  class less_by_first {\n  public:\n    template <class\
    \ T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.first < y.first;\n    }\n  };\n}\n\n\n#line\
    \ 19 \"tools/fps.hpp\"\n\n// Source: https://opt-cp.com/fps-implementation/\n\
    // License: CC0\n// Author: opt\n\nnamespace tools {\n  template <typename M>\n\
    \  class fps {\n  private:\n    using F = ::tools::fps<M>;\n    ::std::vector<M>\
    \ m_vector;\n\n    // maximum 2^k s.t. x = 1 (mod 2^k)\n    static constexpr int\
    \ pow2_k(const unsigned int x) {\n      return (x - 1) & -(x - 1);\n    }\n\n\
    \    // d <= lpf(M)\n    static bool is_leq_lpf_of_M(const int d) {\n      if\
    \ (M::mod() == 1) return true;\n      for (int i = 2; i < d; ++i) {\n        if\
    \ (M::mod() % i == 0) return false;\n      }\n      return true;\n    }\n\n  public:\n\
    \    using reference = M&;\n    using const_reference = const M&;\n    using iterator\
    \ = typename ::std::vector<M>::iterator;\n    using const_iterator = typename\
    \ ::std::vector<M>::const_iterator;\n    using size_type = ::std::size_t;\n  \
    \  using difference_type = ::std::ptrdiff_t;\n    using value_type = M;\n    using\
    \ allocator_type = typename ::std::vector<M>::allocator_type;\n    using pointer\
    \ = M*;\n    using const_pointer = const M*;\n    using reverse_iterator = typename\
    \ ::std::vector<M>::reverse_iterator;\n    using const_reverse_iterator = typename\
    \ ::std::vector<M>::const_reverse_iterator;\n\n    fps() = default;\n    fps(const\
    \ F&) = default;\n    fps(F&&) = default;\n    ~fps() = default;\n    F& operator=(const\
    \ F&) = default;\n    F& operator=(F&&) = default;\n\n    explicit fps(const size_type\
    \ n) : m_vector(n) {}\n    fps(const size_type n, const_reference value) : m_vector(n,\
    \ value) {}\n    template <class InputIter> fps(const InputIter first, const InputIter\
    \ last) : m_vector(first, last) {}\n    fps(const ::std::initializer_list<M> il)\
    \ : m_vector(il) {}\n\n    iterator begin() noexcept { return this->m_vector.begin();\
    \ }\n    const_iterator begin() const noexcept { return this->m_vector.begin();\
    \ }\n    iterator end() noexcept { return this->m_vector.end(); }\n    const_iterator\
    \ end() const noexcept { return this->m_vector.end(); }\n    const_iterator cbegin()\
    \ const noexcept { return this->m_vector.cbegin(); }\n    const_iterator cend()\
    \ const noexcept { return this->m_vector.cend(); }\n    reverse_iterator rbegin()\
    \ noexcept { return this->m_vector.rbegin(); }\n    const_reverse_iterator rbegin()\
    \ const noexcept { return this->m_vector.rbegin(); }\n    const_reverse_iterator\
    \ crbegin() const noexcept { return this->m_vector.crbegin(); }\n    reverse_iterator\
    \ rend() noexcept { return this->m_vector.rend(); }\n    const_reverse_iterator\
    \ rend() const noexcept { return this->m_vector.rend(); }\n    const_reverse_iterator\
    \ crend() const noexcept { return this->m_vector.crend(); }\n\n    size_type size()\
    \ const noexcept { return this->m_vector.size(); }\n    size_type max_size() const\
    \ noexcept { return this->m_vector.max_size(); }\n    void resize(const size_type\
    \ sz) { this->m_vector.resize(sz); }\n    void resize(const size_type sz, const\
    \ M& c) { this->m_vector.resize(sz, c); }\n    size_type capacity() const noexcept\
    \ { return this->m_vector.capacity(); }\n    bool empty() const noexcept { return\
    \ this->m_vector.empty(); }\n    void reserve(const size_type n) { this->m_vector.reserve(n);\
    \ }\n    void shrink_to_fit() { this->m_vector.shrink_to_fit(); }\n\n    reference\
    \ operator[](const size_type n) { return this->m_vector[n]; }\n    const_reference\
    \ operator[](const size_type n) const { return this->m_vector[n]; }\n    reference\
    \ at(const size_type n) { return this->m_vector.at(n); }\n    const_reference\
    \ at(const size_type n) const { return this->m_vector.at(n); }\n    pointer data()\
    \ noexcept { return this->m_vector.data(); }\n    const_pointer data() const noexcept\
    \ { return this->m_vector.data(); }\n    reference front() { return this->m_vector.front();\
    \ }\n    const_reference front() const { return this->m_vector.front(); }\n  \
    \  reference back() { return this->m_vector.back(); }\n    const_reference back()\
    \ const { return this->m_vector.back(); }\n\n    template <class InputIterator>\
    \ void assign(const InputIterator first, const InputIterator last) { this->m_vector.assign(first,\
    \ last); }\n    void assign(const size_type n, const M& u) { this->m_vector.assign(n,\
    \ u); }\n    void assign(const ::std::initializer_list<M> il) { this->m_vector.assign(il);\
    \ }\n    void push_back(const M& x) { this->m_vector.push_back(x); }\n    void\
    \ push_back(M&& x) { this->m_vector.push_back(::std::forward<M>(x)); }\n    template\
    \ <class... Args> reference emplace_back(Args&&... args) { return this->m_vector.emplace_back(::std::forward<Args>(args)...);\
    \ }\n    void pop_back() { this->m_vector.pop_back(); }\n    iterator insert(const\
    \ const_iterator position, const M& x) { return this->m_vector.insert(position,\
    \ x); }\n    iterator insert(const const_iterator position, M&& x) { return this->m_vector.insert(position,\
    \ ::std::forward<M>(x)); }\n    iterator insert(const const_iterator position,\
    \ const size_type n, const M& x) { return this->m_vector.insert(position, n, x);\
    \ }\n    template <class InputIterator> iterator insert(const const_iterator position,\
    \ const InputIterator first, const InputIterator last) { return this->m_vector.insert(position,\
    \ first, last); }\n    iterator insert(const const_iterator position, const ::std::initializer_list<M>\
    \ il) { return this->m_vector.insert(position, il); }\n    template <class...\
    \ Args> iterator emplace(const const_iterator position, Args&&... args) { return\
    \ this->m_vector.emplace(position, ::std::forward<Args>(args)...); }\n    iterator\
    \ erase(const const_iterator position) { return this->m_vector.erase(position);\
    \ }\n    iterator erase(const const_iterator first, const const_iterator last)\
    \ { return this->m_vector.erase(first, last); }\n    void swap(F& x) noexcept\
    \ { this->m_vector.swap(x.m_vector); }\n    void clear() { this->m_vector.clear();\
    \ }\n\n    allocator_type get_allocator() const noexcept { return this->m_vector.get_allocator();\
    \ }\n\n    friend bool operator==(const F& x, const F& y) { return x.m_vector\
    \ == y.m_vector; }\n    friend bool operator!=(const F& x, const F& y) { return\
    \ x.m_vector != y.m_vector; }\n\n    friend void swap(F& x, F& y) noexcept { x.m_vector.swap(y.m_vector);\
    \ }\n\n    F operator+() const {\n      return *this;\n    }\n    F operator-()\
    \ const {\n      F res(*this);\n      for (auto& e : res) {\n        e = -e;\n\
    \      }\n      return res;\n    }\n    F& operator*=(const M& g) {\n      for\
    \ (auto& e : *this) {\n        e *= g;\n      }\n      return *this;\n    }\n\
    \    F& operator/=(const M& g) {\n      assert(::std::gcd(g.val(), M::mod()) ==\
    \ 1);\n      *this *= g.inv();\n      return *this;\n    }\n    F& operator+=(const\
    \ F& g) {\n      const int n = this->size();\n      const int m = g.size();\n\
    \      for (int i = 0; i < ::std::min(n, m); ++i) {\n        (*this)[i] += g[i];\n\
    \      }\n      return *this;\n    }\n    F& operator-=(const F& g) {\n      const\
    \ int n = this->size();\n      const int m = g.size();\n      for (int i = 0;\
    \ i < ::std::min(n, m); ++i) {\n        (*this)[i] -= g[i];\n      }\n      return\
    \ *this;\n    }\n    F& operator<<=(const int d) {\n      if (d < 0) *this >>=\
    \ -d;\n\n      const int n = this->size();\n      this->erase(this->begin(), this->begin()\
    \ + ::std::min(n, d));\n      this->resize(n);\n      return *this;\n    }\n \
    \   F& operator>>=(const int d) {\n      if (d < 0) *this <<= -d;\n\n      const\
    \ int n = this->size();\n      this->resize(::std::max(0, n - d));\n      this->insert(this->begin(),\
    \ ::std::min(n, d), M::raw(0));\n      return *this;\n    }\n    F& multiply_inplace(const\
    \ F& g, const int d) {\n      assert(d >= 0);\n      const int n = this->size();\n\
    \      F res;\n      ::tools::convolution(this->cbegin(), this->cbegin() + ::std::min(d,\
    \ n), g.cbegin(), g.cbegin() + ::std::min<int>(d, g.size()), ::std::back_inserter(res));\n\
    \      res.resize(d);\n      *this = ::std::move(res);\n      return *this;\n\
    \    }\n    F& multiply_inplace(const F& g) { return this->multiply_inplace(g,\
    \ this->size()); }\n    F& operator*=(const F& g) { return this->multiply_inplace(g);\
    \ }\n    F multiply(const F& g, const int d) const { return F(*this).multiply_inplace(g,\
    \ d); }\n    F multiply(const F& g) const { return this->multiply(g, this->size());\
    \ }\n\n  private:\n    F inv_regular(const int d) const {\n      assert(d > 0);\n\
    \      assert(M::mod() > 1);\n      assert(!this->empty());\n      assert(::std::gcd((*this)[0].val(),\
    \ M::mod()) == 1);\n\n      const int n = this->size();\n      F res{(*this)[0].inv()};\n\
    \      for (int m = 1; m < d; m *= 2) {\n        F f(this->begin(), this->begin()\
    \ + ::std::min(n, 2 * m));\n        f *= -1;\n        F r(res);\n        r.multiply_inplace(r,\
    \ 2 * m);\n        r.multiply_inplace(f);\n        r += res;\n        r += res;\n\
    \        res = ::std::move(r);\n      }\n      res.resize(d);\n      return res;\n\
    \    }\n    template <typename M_ = M>\n    F inv_faster(const int d) const {\n\
    \      static_assert(::atcoder::internal::is_static_modint<M>::value);\n     \
    \ static_assert(2 <= M::mod() && M::mod() <= 2000000000);\n      static_assert(::tools::is_prime(M::mod()));\n\
    \      assert(d > 0);\n      assert(!this->empty());\n      assert(::tools::pow2(::tools::ceil_log2(d))\
    \ <= pow2_k(M::mod()));\n      assert(::std::gcd((*this)[0].val(), M::mod()) ==\
    \ 1);\n\n      const int n = this->size();\n      F res{(*this)[0].inv()};\n \
    \     for (int m = 1; m < d; m *= 2) {\n        F f(this->begin(), this->begin()\
    \ + ::std::min(n, 2 * m));\n        F r(res);\n        f.resize(2 * m);\n    \
    \    ::atcoder::internal::butterfly(f.m_vector);\n        r.resize(2 * m);\n \
    \       ::atcoder::internal::butterfly(r.m_vector);\n        for (int i = 0; i\
    \ < 2 * m; ++i) {\n          f[i] *= r[i];\n        }\n        ::atcoder::internal::butterfly_inv(f.m_vector);\n\
    \        f.erase(f.begin(), f.begin() + m);\n        f.resize(2 * m);\n      \
    \  ::atcoder::internal::butterfly(f.m_vector);\n        for (int i = 0; i < 2\
    \ * m; ++i) {\n          f[i] *= r[i];\n        }\n        ::atcoder::internal::butterfly_inv(f.m_vector);\n\
    \        M iz = M(2 * m).inv();\n        iz *= -iz;\n        for (int i = 0; i\
    \ < m; ++i) {\n          f[i] *= iz;\n        }\n        res.insert(res.end(),\
    \ f.begin(), f.begin() + m);\n      }\n      res.resize(d);\n      return res;\n\
    \    }\n\n  public:\n    F inv(const int d) const {\n      assert(d >= 0);\n \
    \     if (d == 0) return F();\n      if (M::mod() == 1) return F(d);\n      assert(!this->empty());\n\
    \      assert(::std::gcd((*this)[0].val(), M::mod()) == 1);\n\n      if constexpr\
    \ (::atcoder::internal::is_static_modint<M>::value && M::mod() <= 2000000000 &&\
    \ ::tools::is_prime(M::mod())) {\n        if (::tools::pow2(::tools::ceil_log2(d))\
    \ <= pow2_k(M::mod())) {\n          return this->inv_faster(d);\n        } else\
    \ {\n          return this->inv_regular(d);\n        }\n      } else {\n     \
    \   return this->inv_regular(d);\n      }\n    }\n    F inv() const { return this->inv(this->size());\
    \ }\n\n    F& divide_inplace(const F& g, const int d) {\n      assert(d >= 0);\n\
    \      const int n = this->size();\n      const auto g_inv = g.inv(d);\n     \
    \ F res;\n      ::tools::convolution(this->cbegin(), this->cbegin() + ::std::min(d,\
    \ n), g_inv.cbegin(), g_inv.cend(), ::std::back_inserter(res));\n      res.resize(d);\n\
    \      *this = ::std::move(res);\n      return *this;\n    }\n    F& divide_inplace(const\
    \ F& g) { return this->divide_inplace(g, this->size()); }\n    F& operator/=(const\
    \ F& g) { return this->divide_inplace(g); }\n    F divide(const F& g, const int\
    \ d) const { return F(*this).divide_inplace(g, d); }\n    F divide(const F& g)\
    \ const { return this->divide(g, this->size()); }\n\n    // sparse\n    template\
    \ <class InputIterator>\n    F& multiply_inplace(InputIterator g_begin, const\
    \ InputIterator g_end) {\n      assert(::std::is_sorted(g_begin, g_end, ::tools::less_by_first()));\n\
    \n      const int n = this->size();\n      if (g_begin == g_end) {\n        ::std::fill(this->begin(),\
    \ this->end(), M::raw(0));\n        return *this;\n      }\n\n      const auto\
    \ [d, c] = *g_begin;\n      if (d == 0) {\n        ++g_begin;\n      } else {\n\
    \        c = M::raw(0);\n      }\n      for (int i = n - 1; i >= 0; --i) {\n \
    \       (*this)[i] *= c;\n        for (auto it = g_begin; it != g_end; ++it) {\n\
    \          const auto& [j, b] = *it;\n          if (j > i) break;\n          (*this)[i]\
    \ += (*this)[i - j] * b;\n        }\n      }\n      return *this;\n    }\n   \
    \ F& multiply_inplace(const ::std::initializer_list<::std::pair<int, M>> il) {\
    \ return this->multiply_inplace(il.begin(), il.end()); }\n    template <class\
    \ InputIterator>\n    F multiply(const InputIterator g_begin, const InputIterator\
    \ g_end) const { return F(*this).multiply_inplace(g_begin, g_end); }\n    F multiply(const\
    \ ::std::initializer_list<::std::pair<int, M>> il) const { return this->multiply(il.begin(),\
    \ il.end()); }\n\n    template <class InputIterator>\n    F& divide_inplace(InputIterator\
    \ g_begin, const InputIterator g_end) {\n      assert(g_begin != g_end);\n   \
    \   assert(::std::is_sorted(g_begin, g_end, ::tools::less_by_first()));\n\n  \
    \    const int n = this->size();\n      if (n == 0) return *this;\n      if (M::mod()\
    \ == 1) return *this;\n\n      const auto [d, c] = *g_begin;\n      assert(d ==\
    \ 0 && ::std::gcd(c, M::mod()) == 1);\n      const M ic = c.inv();\n      ++g_begin;\n\
    \      for (int i = 0; i < n; ++i) {\n        for (auto it = g_begin; it != g_end;\
    \ ++it) {\n          const auto& [j, b] = *it;\n          if (j > i) break;\n\
    \          (*this)[i] -= (*this)[i - j] * b;\n        }\n        (*this)[i] *=\
    \ ic;\n      }\n      return *this;\n    }\n    F& divide_inplace(const ::std::initializer_list<::std::pair<int,\
    \ M>> il) { return this->divide_inplace(il.begin(), il.end()); }\n    template\
    \ <class InputIterator>\n    F divide(const InputIterator g_begin, const InputIterator\
    \ g_end) const { return F(*this).divide_inplace(g_begin, g_end); }\n    F divide(const\
    \ ::std::initializer_list<::std::pair<int, M>> il) const { return this->divide(il.begin(),\
    \ il.end()); }\n\n    // multiply and divide (1 + cz^d)\n    F& multiply_inplace(const\
    \ int d, const M c) {\n      assert(d > 0);\n      const int n = this->size();\n\
    \      if (c == M(1)) {\n        for (int i = n - d - 1; i >= 0; --i) {\n    \
    \      (*this)[i + d] += (*this)[i];\n        }\n      } else if (c == M(-1))\
    \ {\n        for (int i = n - d - 1; i >= 0; --i) {\n          (*this)[i + d]\
    \ -= (*this)[i];\n        }\n      } else {\n        for (int i = n - d - 1; i\
    \ >= 0; --i) {\n          (*this)[i + d] += (*this)[i] * c;\n        }\n     \
    \ }\n      return *this;\n    }\n    F multiply(const int d, const M c) const\
    \ { return F(*this).multiply_inplace(d, c); }\n    F& divide_inplace(const int\
    \ d, const M c) {\n      assert(d > 0);\n      const int n = this->size();\n \
    \     if (c == M(1)) {\n        for (int i = 0; i < n - d; ++i) {\n          (*this)[i\
    \ + d] -= (*this)[i];\n        }\n      } else if (c == M(-1)) {\n        for\
    \ (int i = 0; i < n - d; ++i) {\n          (*this)[i + d] += (*this)[i];\n   \
    \     }\n      } else {\n        for (int i = 0; i < n - d; ++i) {\n         \
    \ (*this)[i + d] -= (*this)[i] * c;\n        }\n      }\n      return *this;\n\
    \    }\n    F divide(const int d, const M c) const { return F(*this).divide_inplace(d,\
    \ c); }\n\n    F& integral_inplace() {\n      const int n = this->size();\n  \
    \    assert(is_leq_lpf_of_M(n));\n\n      if (n == 0) return *this;\n      if\
    \ (n == 1) return *this = F{0};\n      this->insert(this->begin(), 0);\n     \
    \ this->pop_back();\n      ::std::vector<M> inv(n);\n      inv[1] = M(1);\n  \
    \    int p = M::mod();\n      for (int i = 2; i < n; ++i) {\n        inv[i] =\
    \ -inv[p % i] * (p / i);\n      }\n      for (int i = 2; i < n; ++i) {\n     \
    \   (*this)[i] *= inv[i];\n      }\n      return *this;\n    }\n    F integral()\
    \ const { return F(*this).integral_inplace(); }\n\n    F& derivative_inplace()\
    \ {\n      const int n = this->size();\n      if (n == 0) return *this;\n    \
    \  for (int i = 2; i < n; ++i) {\n        (*this)[i] *= i;\n      }\n      this->erase(this->begin());\n\
    \      this->push_back(0);\n      return *this;\n    }\n    F derivative() const\
    \ { return F(*this).derivative_inplace(); }\n\n    F& log_inplace(const int d)\
    \ {\n      assert(d >= 0);\n      assert(is_leq_lpf_of_M(d));\n      this->resize(d);\n\
    \      if (d == 0) return *this;\n      assert((*this)[0] == M(1));\n\n      const\
    \ F f_inv = this->inv();\n      this->derivative_inplace();\n      this->multiply_inplace(f_inv);\n\
    \      this->integral_inplace();\n      return *this;\n    }\n    F& log_inplace()\
    \ { return this->log_inplace(this->size()); }\n    F log(const int d) const {\
    \ return F(*this).log_inplace(d); }\n    F log() const { return this->log(this->size());\
    \ }\n\n  private:\n    F& exp_inplace_regular(const int d) {\n      assert(d >=\
    \ 0);\n      assert(is_leq_lpf_of_M(d));\n      assert(this->empty() || (*this)[0]\
    \ == M::raw(0));\n\n      const int n = this->size();\n      F g{1};\n      for\
    \ (int m = 1; m < d; m *= 2) {\n        F r(g);\n        r.resize(2 * m);\n  \
    \      r.log_inplace();\n        r *= -1;\n        r += F(this->begin(), this->begin()\
    \ + ::std::min(n, 2 * m));\n        ++r[0];\n        r.multiply_inplace(g);\n\
    \        g = ::std::move(r);\n      }\n      g.resize(d);\n      *this = ::std::move(g);\n\
    \      return *this;\n    }\n    template <typename M_ = M>\n    F& exp_inplace_faster(const\
    \ int d) {\n      static_assert(::atcoder::internal::is_static_modint<M>::value);\n\
    \      static_assert(2 <= M::mod() && M::mod() <= 2000000000);\n      static_assert(::tools::is_prime(M::mod()));\n\
    \      assert(d > 0);\n      assert(is_leq_lpf_of_M(d));\n      assert(::tools::pow2(::tools::ceil_log2(d))\
    \ <= pow2_k(M::mod()));\n      assert(this->empty() || (*this)[0] == M::raw(0));\n\
    \ \n      F g{1}, g_fft{1, 1};\n      this->resize(d);\n      (*this)[0] = 1;\n\
    \      F h_drv(this->derivative());\n      for (int m = 2; m < d; m *= 2) {\n\
    \        // prepare\n        F f_fft(this->begin(), this->begin() + m);\n    \
    \    f_fft.resize(2 * m);\n        ::atcoder::internal::butterfly(f_fft.m_vector);\n\
    \n        // Step 2.a'\n        {\n          F g_(m);\n          for (int i =\
    \ 0; i < m; ++i) {\n            g_[i] = f_fft[i] * g_fft[i];\n          }\n  \
    \        ::atcoder::internal::butterfly_inv(g_.m_vector);\n          g_.erase(g_.begin(),\
    \ g_.begin() + m / 2);\n          g_.resize(m);\n          ::atcoder::internal::butterfly(g_.m_vector);\n\
    \          for (int i = 0; i < m; ++i) {\n            g_[i] *= g_fft[i];\n   \
    \       }\n          ::atcoder::internal::butterfly_inv(g_.m_vector);\n      \
    \    g_.resize(m / 2);\n          g_ /= M(-m) * m;\n          g.insert(g.end(),\
    \ g_.begin(), g_.begin() + m / 2);\n        }\n\n        // Step 2.b'--d'\n  \
    \      F t(this->begin(), this->begin() + m);\n        t.derivative_inplace();\n\
    \        {\n          // Step 2.b'\n          F r{h_drv.begin(), h_drv.begin()\
    \ + m - 1};\n          // Step 2.c'\n          r.resize(m);\n          ::atcoder::internal::butterfly(r.m_vector);\n\
    \          for (int i = 0; i < m; ++i) {\n            r[i] *= f_fft[i];\n    \
    \      }\n          ::atcoder::internal::butterfly_inv(r.m_vector);\n        \
    \  r /= -m;\n          // Step 2.d'\n          t += r;\n          t.insert(t.begin(),\
    \ t.back());\n          t.pop_back();\n        }\n\n        // Step 2.e'\n   \
    \     if (2 * m < d) {\n          t.resize(2 * m);\n          ::atcoder::internal::butterfly(t.m_vector);\n\
    \          g_fft = g;\n          g_fft.resize(2*m);\n          ::atcoder::internal::butterfly(g_fft.m_vector);\n\
    \          for (int i = 0; i < 2 * m; ++i) {\n            t[i] *= g_fft[i];\n\
    \          }\n          ::atcoder::internal::butterfly_inv(t.m_vector);\n    \
    \      t.resize(m);\n          t /= 2 * m;\n        } else { // \u3053\u306E\u5834\
    \u5408\u5206\u3051\u3092\u3057\u3066\u3082\u6570\u30D1\u30FC\u30BB\u30F3\u30C8\
    \u3057\u304B\u901F\u304F\u306A\u3089\u306A\u3044\n          F g1(g.begin() + m\
    \ / 2, g.end());\n          F s1(t.begin() + m / 2, t.end());\n          t.resize(m/2);\n\
    \          g1.resize(m);\n          ::atcoder::internal::butterfly(g1.m_vector);\n\
    \          t.resize(m);\n          ::atcoder::internal::butterfly(t.m_vector);\n\
    \          s1.resize(m);\n          ::atcoder::internal::butterfly(s1.m_vector);\n\
    \          for (int i = 0; i < m; ++i) {\n            s1[i] = g_fft[i] * s1[i]\
    \ + g1[i] * t[i];\n          }\n          for (int i = 0; i < m; ++i) {\n    \
    \        t[i] *= g_fft[i];\n          }\n          ::atcoder::internal::butterfly_inv(t.m_vector);\n\
    \          ::atcoder::internal::butterfly_inv(s1.m_vector);\n          for (int\
    \ i = 0; i < m / 2; ++i) {\n            t[i + m / 2] += s1[i];\n          }\n\
    \          t /= m;\n        }\n\n        // Step 2.f'\n        F v(this->begin()\
    \ + m, this->begin() + ::std::min<int>(d, 2 * m));\n        v.resize(m);\n   \
    \     t.insert(t.begin(), m - 1, 0);\n        t.push_back(0);\n        t.integral_inplace();\n\
    \        for (int i = 0; i < m; ++i) {\n          v[i] -= t[m + i];\n        }\n\
    \n        // Step 2.g'\n        v.resize(2 * m);\n        ::atcoder::internal::butterfly(v.m_vector);\n\
    \        for (int i = 0; i < 2 * m; ++i) {\n          v[i] *= f_fft[i];\n    \
    \    }\n        ::atcoder::internal::butterfly_inv(v.m_vector);\n        v.resize(m);\n\
    \        v /= 2 * m;\n\n        // Step 2.h'\n        for (int i = 0; i < ::std::min(d\
    \ - m, m); ++i) {\n          (*this)[m + i] = v[i];\n        }\n      }\n    \
    \  return *this;\n    }\n\n  public:\n    F& exp_inplace(const int d) {\n    \
    \  assert(d >= 0);\n      assert(is_leq_lpf_of_M(d));\n      assert(this->empty()\
    \ || (*this)[0] == M::raw(0));\n\n      if (d == 0) {\n        this->clear();\n\
    \        return *this;\n      }\n\n      if constexpr (::atcoder::internal::is_static_modint<M>::value\
    \ && M::mod() <= 2000000000 && ::tools::is_prime(M::mod())) {\n        if (::tools::pow2(::tools::ceil_log2(d))\
    \ <= pow2_k(M::mod())) {\n          return this->exp_inplace_faster(d);\n    \
    \    } else {\n          return this->exp_inplace_regular(d);\n        }\n   \
    \   } else {\n        return this->exp_inplace_regular(d);\n      }\n    }\n \
    \   F& exp_inplace() { return this->exp_inplace(this->size()); }\n    F exp(const\
    \ int d) const { return F(*this).exp_inplace(d); }\n    F exp() const { return\
    \ this->exp(this->size()); }\n\n  private:\n    F& pow_inplace_regular(long long\
    \ k, const int d, const int l) {\n      assert(k > 0);\n      assert(d > 0);\n\
    \      assert(l >= 0);\n      assert(d - l * k > 0);\n\n      this->erase(this->begin(),\
    \ this->begin() + l);\n      this->resize(d - l * k);\n\n      F sum(d - l * k);\n\
    \      for (F p = *this; k > 0; k /= 2, p *= p) {\n        if (k & 1) sum += p;\n\
    \      }\n\n      *this = ::std::move(sum);\n      this->insert(this->begin(),\
    \ l * k, 0);\n      return *this;\n    }\n    F& pow_inplace_faster(const long\
    \ long k, const int d, const int l) {\n      assert(k > 0);\n      assert(d >\
    \ 0);\n      assert(l >= 0);\n      assert(d - l * k > 0);\n      assert(is_leq_lpf_of_M(d\
    \ - l * k));\n      assert(::std::gcd((*this)[l].val(), M::mod()) == 1);\n\n \
    \     M c{(*this)[l]};\n      this->erase(this->begin(), this->begin() + l);\n\
    \      *this /= c;\n      this->log_inplace(d - l * k);\n      *this *= k;\n \
    \     this->exp_inplace();\n      *this *= c.pow(k);\n      this->insert(this->begin(),\
    \ l * k, 0);\n      return *this;\n    }\n\n  public:\n    F& pow_inplace(const\
    \ long long k, const int d) {\n      assert(k >= 0);\n      assert(d >= 0);\n\n\
    \      const int n = this->size();\n      if (d == 0) {\n        this->clear();\n\
    \        return *this;\n      }\n      if (k == 0) {\n        *this = F(d);\n\
    \        (*this)[0] = M(1);\n        return *this;\n      }\n\n      int l = 0;\n\
    \      while (l < n && (*this)[l] == M::raw(0)) ++l;\n      if (l == n || l >\
    \ (d - 1) / k) {\n        return *this = F(d);\n      }\n\n      if (::std::gcd((*this)[l].val(),\
    \ M::mod()) == 1 && is_leq_lpf_of_M(d - l * k)) {\n        return this->pow_inplace_faster(k,\
    \ d, l);\n      } else {\n        return this->pow_inplace_regular(k, d, l);\n\
    \      }\n    }\n    F& pow_inplace(const long long k) { return this->pow_inplace(k,\
    \ this->size()); }\n    F pow(const long long k, const int d) const { return F(*this).pow_inplace(k,\
    \ d); }\n    F pow(const long long k) const { return this->pow(k, this->size());\
    \ }\n\n    friend F operator*(const F& f, const M& g) { return F(f) *= g; }\n\
    \    friend F operator*(const M& f, const F& g) { return F(g) *= f; }\n    friend\
    \ F operator/(const F& f, const M& g) { return F(f) /= g; }\n    friend F operator+(const\
    \ F& f, const F& g) { return F(f) += g; }\n    friend F operator-(const F& f,\
    \ const F& g) { return F(f) -= g; }\n    friend F operator*(const F& f, const\
    \ F& g) { return F(f) *= g; }\n    friend F operator/(const F& f, const F& g)\
    \ { return F(f) /= g; }\n    friend F operator<<(const F& f, const int d) { return\
    \ F(f) <<= d; }\n    friend F operator>>(const F& f, const int d) { return F(f)\
    \ >>= d; }\n  };\n}\n\n\n#line 1 \"tools/has_mod.hpp\"\n\n\n\n#line 6 \"tools/has_mod.hpp\"\
    \n\nnamespace tools {\n  template <typename T, typename = ::std::void_t<>>\n \
    \ struct has_mod : ::std::false_type {};\n\n  template <typename T>\n  struct\
    \ has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>> : ::std::true_type\
    \ {};\n\n  template <typename T>\n  inline constexpr bool has_mod_v = ::tools::has_mod<T>::value;\n\
    }\n\n\n#line 14 \"tools/polynomial.hpp\"\n\nnamespace tools {\n  template <typename\
    \ R>\n  class polynomial {\n  private:\n    using P = ::tools::polynomial<R>;\n\
    \    ::std::vector<R> m_vector;\n\n  public:\n    using reference = R&;\n    using\
    \ const_reference = const R&;\n    using iterator = typename ::std::vector<R>::iterator;\n\
    \    using const_iterator = typename ::std::vector<R>::const_iterator;\n    using\
    \ size_type = ::std::size_t;\n    using difference_type = ::std::ptrdiff_t;\n\
    \    using value_type = R;\n    using allocator_type = typename ::std::vector<R>::allocator_type;\n\
    \    using pointer = R*;\n    using const_pointer = const R*;\n    using reverse_iterator\
    \ = typename ::std::vector<R>::reverse_iterator;\n    using const_reverse_iterator\
    \ = typename ::std::vector<R>::const_reverse_iterator;\n\n    polynomial() = default;\n\
    \    polynomial(const P&) = default;\n    polynomial(P&&) = default;\n    ~polynomial()\
    \ = default;\n    P& operator=(const P&) = default;\n    P& operator=(P&&) = default;\n\
    \n    explicit polynomial(const size_type n) : m_vector(n) {}\n    polynomial(const\
    \ size_type n, const_reference value) : m_vector(n, value) {}\n    template <class\
    \ InputIter> polynomial(const InputIter first, const InputIter last) : m_vector(first,\
    \ last) {}\n    polynomial(const ::std::initializer_list<R> il) : m_vector(il)\
    \ {}\n\n    iterator begin() noexcept { return this->m_vector.begin(); }\n   \
    \ const_iterator begin() const noexcept { return this->m_vector.begin(); }\n \
    \   iterator end() noexcept { return this->m_vector.end(); }\n    const_iterator\
    \ end() const noexcept { return this->m_vector.end(); }\n    const_iterator cbegin()\
    \ const noexcept { return this->m_vector.cbegin(); }\n    const_iterator cend()\
    \ const noexcept { return this->m_vector.cend(); }\n    reverse_iterator rbegin()\
    \ noexcept { return this->m_vector.rbegin(); }\n    const_reverse_iterator rbegin()\
    \ const noexcept { return this->m_vector.rbegin(); }\n    const_reverse_iterator\
    \ crbegin() const noexcept { return this->m_vector.crbegin(); }\n    reverse_iterator\
    \ rend() noexcept { return this->m_vector.rend(); }\n    const_reverse_iterator\
    \ rend() const noexcept { return this->m_vector.rend(); }\n    const_reverse_iterator\
    \ crend() const noexcept { return this->m_vector.crend(); }\n\n    size_type size()\
    \ const noexcept { return this->m_vector.size(); }\n    size_type max_size() const\
    \ noexcept { return this->m_vector.max_size(); }\n    void resize(const size_type\
    \ sz) { this->m_vector.resize(sz); }\n    void resize(const size_type sz, const\
    \ R& c) { this->m_vector.resize(sz, c); }\n    size_type capacity() const noexcept\
    \ { return this->m_vector.capacity(); }\n    bool empty() const noexcept { return\
    \ this->m_vector.empty(); }\n    void reserve(const size_type n) { this->m_vector.reserve(n);\
    \ }\n    void shrink_to_fit() { this->m_vector.shrink_to_fit(); }\n\n    reference\
    \ operator[](const size_type n) { return this->m_vector[n]; }\n    const_reference\
    \ operator[](const size_type n) const { return this->m_vector[n]; }\n    reference\
    \ at(const size_type n) { return this->m_vector.at(n); }\n    const_reference\
    \ at(const size_type n) const { return this->m_vector.at(n); }\n    pointer data()\
    \ noexcept { return this->m_vector.data(); }\n    const_pointer data() const noexcept\
    \ { return this->m_vector.data(); }\n    reference front() { return this->m_vector.front();\
    \ }\n    const_reference front() const { return this->m_vector.front(); }\n  \
    \  reference back() { return this->m_vector.back(); }\n    const_reference back()\
    \ const { return this->m_vector.back(); }\n\n    template <class InputIterator>\
    \ void assign(const InputIterator first, const InputIterator last) { this->m_vector.assign(first,\
    \ last); }\n    void assign(const size_type n, const R& u) { this->m_vector.assign(n,\
    \ u); }\n    void assign(const ::std::initializer_list<R> il) { this->m_vector.assign(il);\
    \ }\n    void push_back(const R& x) { this->m_vector.push_back(x); }\n    void\
    \ push_back(R&& x) { this->m_vector.push_back(::std::forward<R>(x)); }\n    template\
    \ <class... Args> reference emplace_back(Args&&... args) { return this->m_vector.emplace_back(::std::forward<Args>(args)...);\
    \ }\n    void pop_back() { this->m_vector.pop_back(); }\n    iterator insert(const\
    \ const_iterator position, const R& x) { return this->m_vector.insert(position,\
    \ x); }\n    iterator insert(const const_iterator position, R&& x) { return this->m_vector.insert(position,\
    \ ::std::forward<R>(x)); }\n    iterator insert(const const_iterator position,\
    \ const size_type n, const R& x) { return this->m_vector.insert(position, n, x);\
    \ }\n    template <class InputIterator> iterator insert(const const_iterator position,\
    \ const InputIterator first, const InputIterator last) { return this->m_vector.insert(position,\
    \ first, last); }\n    iterator insert(const const_iterator position, const ::std::initializer_list<R>\
    \ il) { return this->m_vector.insert(position, il); }\n    template <class...\
    \ Args> iterator emplace(const const_iterator position, Args&&... args) { return\
    \ this->m_vector.emplace(position, ::std::forward<Args>(args)...); }\n    iterator\
    \ erase(const const_iterator position) { return this->m_vector.erase(position);\
    \ }\n    iterator erase(const const_iterator first, const const_iterator last)\
    \ { return this->m_vector.erase(first, last); }\n    void swap(P& x) noexcept\
    \ { this->m_vector.swap(x.m_vector); }\n    void clear() { this->m_vector.clear();\
    \ }\n\n    allocator_type get_allocator() const noexcept { return this->m_vector.get_allocator();\
    \ }\n\n    friend bool operator==(const P& x, const P& y) {\n      const auto\
    \ n = ::std::min(x.size(), y.size());\n      static const auto is_zero = [](const\
    \ R& e) { return e == R(0); };\n      return ::std::equal(x.begin(), x.begin()\
    \ + n, y.begin(), y.begin() + n) && ::std::all_of(x.begin() + n, x.end(), is_zero)\
    \ && ::std::all_of(y.begin() + n, y.end(), is_zero);\n    }\n    friend bool operator!=(const\
    \ P& x, const P& y) { return !(x == y); }\n\n    friend void swap(P& x, P& y)\
    \ noexcept { x.m_vector.swap(y.m_vector); }\n\n    int deg() const {\n      for\
    \ (size_type i = this->size(); i --> 0;) {\n        if ((*this)[i] != R(0)) return\
    \ i;\n      }\n      return -1;\n    }\n\n    P operator+() const {\n      return\
    \ *this;\n    }\n    P operator-() const {\n      P res(*this);\n      for (auto&\
    \ e : res) {\n        e = -e;\n      }\n      return res;\n    }\n    P& operator*=(const\
    \ R& g) {\n      for (auto& e : *this) {\n        e *= g;\n      }\n      return\
    \ *this;\n    }\n    P& operator/=(const R& g) {\n      assert(R(0) == R(1) ||\
    \ g != R(0));\n      *this *= R(1) / g;\n      return *this;\n    }\n    P& operator+=(const\
    \ P& g) {\n      const int n = this->size();\n      const int m = g.size();\n\
    \      this->resize(::std::max(n, m));\n      for (int i = 0; i < m; ++i) {\n\
    \        (*this)[i] += g[i];\n      }\n      return *this;\n    }\n    P& operator-=(const\
    \ P& g) {\n      const int n = this->size();\n      const int m = g.size();\n\
    \      this->resize(::std::max(n, m));\n      for (int i = 0; i < m; ++i) {\n\
    \        (*this)[i] -= g[i];\n      }\n      return *this;\n    }\n    P& operator<<=(const\
    \ int d) {\n      if (d < 0) *this >>= -d;\n\n      const int n = this->size();\n\
    \      this->erase(this->begin(), this->begin() + ::std::min(n, d));\n      return\
    \ *this;\n    }\n    P& operator>>=(const int d) {\n      if (d < 0) *this <<=\
    \ -d;\n\n      this->insert(this->begin(), d, R(0));\n      return *this;\n  \
    \  }\n\n    P& operator*=(const P& g) {\n      const int n = this->size();\n \
    \     const int m = g.size();\n\n      if (n == 0 && m == 0) {\n        this->clear();\n\
    \        return *this;\n      }\n      if (n == 0 || m == 0) {\n        ::std::fill(this->begin(),\
    \ this->end(), R(0));\n        this->resize(n + m - 1, R(0));\n        return\
    \ *this;\n      }\n\n      P res;\n      ::tools::convolution(this->cbegin(),\
    \ this->cend(), g.cbegin(), g.cend(), ::std::back_inserter(res));\n      return\
    \ *this = ::std::move(res);\n    }\n\n  private:\n    P& divide_inplace_regular(const\
    \ P& g) {\n      const int n = this->size();\n      const int m = g.size();\n\n\
    \      assert(0 < m && m <= n);\n      assert(this->back() != R(0));\n      assert(g.back()\
    \ != R(0));\n\n      const auto ic = R(1) / g.back();\n      P q(n - m + 1);\n\
    \      for (int i = n - m; i >= 0; --i) {\n        q[i] = (*this)[m - 1 + i] *\
    \ ic;\n        for (int j = 0; j < m; ++j) {\n          (*this)[j + i] -= g[j]\
    \ * q[i];\n        }\n      }\n      return *this = ::std::move(q);\n    }\n \
    \   template <typename R_ = R>\n    P& divide_inplace_faster(const P& g) {\n \
    \     const int n = this->size();\n      const int m = g.size();\n\n      static_assert(::tools::has_mod_v<R>);\n\
    \      assert(::tools::is_prime(R::mod()));\n      assert(0 < m && m <= n);\n\
    \      assert(this->back() != R(0));\n      assert(g.back() != R(0));\n\n    \
    \  ::tools::fps<R> q(this->rbegin(), this->rend());\n      q.divide_inplace(::tools::fps<R>(g.rbegin(),\
    \ g.rend()), n - m + 1);\n      this->assign(q.rbegin(), q.rend());\n      return\
    \ *this;\n    }\n\n  public:\n    P& operator/=(P g) {\n      if (R(0) == R(1))\
    \ {\n        this->clear();\n        return *this;\n      }\n\n      this->resize(this->deg()\
    \ + 1);\n      g.resize(g.deg() + 1);\n\n      const int n = this->size();\n \
    \     const int m = g.size();\n\n      assert(m > 0);\n      if (n < m) {\n  \
    \      this->clear();\n        return *this;\n      }\n\n      if constexpr (::tools::has_mod_v<R>)\
    \ {\n        assert(::tools::is_prime(R::mod()));\n        return this->divide_inplace_faster(g);\n\
    \      } else {\n        return this->divide_inplace_regular(g);\n      }\n  \
    \  }\n    P& operator%=(const P& g) {\n      auto q = (*this) / g;\n      q *=\
    \ g;\n      q *= R(-1);\n      *this += q;\n      this->resize(this->deg() + 1);\n\
    \      return *this;\n    }\n\n    R eval(const R& a) const {\n      R x(1);\n\
    \      R res(0);\n      for (const auto e : *this) {\n        res += e * x;\n\
    \        x *= a;\n      }\n      return res;\n    }\n\n    friend P operator*(const\
    \ P& f, const R& c) { return P(f) *= c; }\n    friend P operator*(const R& c,\
    \ const P& f) { return P(f) *= c; }\n    friend P operator/(const P& f, const\
    \ R& c) { return P(f) /= c; }\n    friend P operator+(const P& f, const P& g)\
    \ { return P(f) += g; }\n    friend P operator-(const P& f, const P& g) { return\
    \ P(f) -= g; }\n    friend P operator*(const P& f, const P& g) { return P(f) *=\
    \ g; }\n    friend P operator/(const P& f, const P& g) { return P(f) /= g; }\n\
    \    friend P operator%(const P& f, const P& g) { return P(f) %= g; }\n    friend\
    \ P operator<<(const P& f, const int d) { return P(f) <<= d; }\n    friend P operator>>(const\
    \ P& f, const int d) { return P(f) >>= d; }\n  };\n}\n\n\n#line 9 \"tools/bostan_mori.hpp\"\
    \n\nnamespace tools {\n  template <typename M>\n  M bostan_mori(::tools::polynomial<M>\
    \ P, ::tools::polynomial<M> Q, unsigned long long n) {\n    static_assert(::tools::has_mod_v<M>);\n\
    \    assert(::std::gcd(Q.empty() ? 0 : Q[0].val(), M::mod()) == 1);\n\n    P.resize(P.deg()\
    \ + 1);\n    Q.resize(Q.deg() + 1);\n\n    while (n > 0) {\n      // Q1(x) = Q(-x)\n\
    \      auto Q1 = Q;\n      for (::std::size_t i = 1; i < Q1.size(); i += 2) {\n\
    \        Q1[i] = -Q1[i];\n      }\n\n      const auto PQ = P * Q1;\n      const\
    \ auto QQ = Q * Q1;\n\n      P.clear();\n      for (::std::size_t i = n & 1; i\
    \ < PQ.size(); i += 2) {\n        P.push_back(PQ[i]);\n      }\n      Q.clear();\n\
    \      for (::std::size_t i = 0; i < QQ.size(); i += 2) {\n        Q.push_back(QQ[i]);\n\
    \      }\n\n      n /= 2;\n    }\n\n    return (P.empty() ? M::raw(0) : P[0])\
    \ / (Q.empty() ? M::raw(0) : Q[0]);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_BOSTAN_MORI_HPP\n#define TOOLS_BOSTAN_MORI_HPP\n\n#include\
    \ <cassert>\n#include <numeric>\n#include <cstddef>\n#include \"tools/polynomial.hpp\"\
    \n#include \"tools/has_mod.hpp\"\n\nnamespace tools {\n  template <typename M>\n\
    \  M bostan_mori(::tools::polynomial<M> P, ::tools::polynomial<M> Q, unsigned\
    \ long long n) {\n    static_assert(::tools::has_mod_v<M>);\n    assert(::std::gcd(Q.empty()\
    \ ? 0 : Q[0].val(), M::mod()) == 1);\n\n    P.resize(P.deg() + 1);\n    Q.resize(Q.deg()\
    \ + 1);\n\n    while (n > 0) {\n      // Q1(x) = Q(-x)\n      auto Q1 = Q;\n \
    \     for (::std::size_t i = 1; i < Q1.size(); i += 2) {\n        Q1[i] = -Q1[i];\n\
    \      }\n\n      const auto PQ = P * Q1;\n      const auto QQ = Q * Q1;\n\n \
    \     P.clear();\n      for (::std::size_t i = n & 1; i < PQ.size(); i += 2) {\n\
    \        P.push_back(PQ[i]);\n      }\n      Q.clear();\n      for (::std::size_t\
    \ i = 0; i < QQ.size(); i += 2) {\n        Q.push_back(QQ[i]);\n      }\n\n  \
    \    n /= 2;\n    }\n\n    return (P.empty() ? M::raw(0) : P[0]) / (Q.empty()\
    \ ? M::raw(0) : Q[0]);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/polynomial.hpp
  - tools/fps.hpp
  - tools/convolution.hpp
  - tools/pow2.hpp
  - tools/ceil_log2.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/garner3.hpp
  - tools/less_by_first.hpp
  - tools/has_mod.hpp
  isVerificationFile: false
  path: tools/bostan_mori.hpp
  requiredBy: []
  timestamp: '2023-01-07 10:26:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bostan_mori.test.cpp
documentation_of: tools/bostan_mori.hpp
layout: document
title: Bostan-Mori algorithm
---

```cpp
template <typename M>
M bostan_mori(tools::polynomial<M> P, tools::polynomial<M> Q, unsigned long long n);
```

It returns $[x^n]\frac{P(x)}{Q(x)}$.

### Constraints
- $\gcd(Q(0), M) = 1$ where $M$ is `M::mod()`

### Time Complexity
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $O((\mathrm{deg}(P) + \mathrm{deg}(Q)) \log (\mathrm{deg}(P) + \mathrm{deg}(Q)) \log n + \log M)$

### References
- [線形漸化式を満たす数列の N 項目を計算するアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)

### License
- CC0

### Author
- anqooqie
