---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/find_cycle.hpp
    title: Floyd's cycle-finding algorithm
  - icon: ':question:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/has_mod.hpp
    title: Check whether T has the member function mod()
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':question:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
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
  bundledCode: "#line 1 \"tests/has_mod.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <string>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
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
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that(cond)\
    \ do {\\\n  if (!(cond)) {\\\n    ::std::cerr << __FILE__ << ':' << __LINE__ <<\
    \ \": \" << __func__ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\
    \n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n\n\n#line 1 \"tools/has_mod.hpp\"\
    \n\n\n\n#line 6 \"tools/has_mod.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T, typename = ::std::void_t<>>\n  struct has_mod : ::std::false_type {};\n\n\
    \  template <typename T>\n  struct has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>>\
    \ : ::std::true_type {};\n\n  template <typename T>\n  inline constexpr bool has_mod_v\
    \ = ::tools::has_mod<T>::value;\n}\n\n\n#line 1 \"tools/modint_for_rolling_hash.hpp\"\
    \n\n\n\n#line 1 \"tools/detail/rolling_hash.hpp\"\n\n\n\n#include <cstdint>\n\
    #line 6 \"tools/detail/rolling_hash.hpp\"\n#include <tuple>\n#include <vector>\n\
    #line 1 \"tools/pow.hpp\"\n\n\n\n#line 6 \"tools/pow.hpp\"\n#include <cmath>\n\
    #line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n#include <limits>\n\
    #line 7 \"tools/monoid.hpp\"\n\nnamespace tools {\n  namespace monoid {\n    template\
    \ <typename M, M E = ::std::numeric_limits<M>::lowest()>\n    struct max {\n \
    \     using T = M;\n      static T op(const T& lhs, const T& rhs) {\n        return\
    \ ::std::max(lhs, rhs);\n      }\n      static T e() {\n        return E;\n  \
    \    }\n    };\n\n    template <typename M, M E = ::std::numeric_limits<M>::max()>\n\
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
    \  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5 \"tools/square.hpp\"\n\
    \nnamespace tools {\n\n  template <typename M>\n  typename M::T square(const typename\
    \ M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n  T square(const\
    \ T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n  }\n\
    }\n\n\n#line 9 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, typename M::T>\
    \ pow(const typename M::T& base, const E exponent) {\n    assert(exponent >= 0);\n\
    \    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n       \
    \ ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ T> pow(const T& base, const E exponent) {\n    assert(exponent >= 0);\n    return\
    \ ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);\n  }\n\n  template\
    \ <typename T, typename E>\n  auto pow(const T base, const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>,\
    \ decltype(::std::pow(base, exponent))> {\n    return ::std::pow(base, exponent);\n\
    \  }\n}\n\n\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#line 1 \"tools/abs.hpp\"\n\n\
    \n\nnamespace tools {\n  constexpr float abs(const float x) {\n    return x <\
    \ 0 ? -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x < 0\
    \ ? -x : x;\n  }\n  constexpr long double abs(const long double x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return x < 0 ?\
    \ -x : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0 ? -x :\
    \ x;\n  }\n  constexpr long long abs(const long long x) {\n    return x < 0 ?\
    \ -x : x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n    return\
    \ x;\n  }\n  constexpr unsigned long abs(const unsigned long x) {\n    return\
    \ x;\n  }\n  constexpr unsigned long long abs(const unsigned long long x) {\n\
    \    return x;\n  }\n}\n\n\n#line 9 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {\n \
    \   const bool prev_r_is_neg = prev_r < T(0);\n    const bool r_is_neg = r < T(0);\n\
    \n    if (prev_r_is_neg) prev_r = -prev_r;\n    if (r_is_neg) r = -r;\n\n    #ifndef\
    \ NDEBUG\n    const T a = prev_r;\n    const T b = r;\n    #endif\n\n    T prev_s(1);\n\
    \    T prev_t(0);\n    T s(0);\n    T t(1);\n    while (r != T(0)) {\n      const\
    \ T q = prev_r / r;\n      ::std::tie(prev_r, r) = ::std::make_pair(r, prev_r\
    \ - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s, prev_s - q * s);\n\
    \      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t - q * t);\n    }\n\n\
    \    if (prev_r_is_neg) prev_s = -prev_s;\n    if (r_is_neg) prev_t = -prev_t;\n\
    \n    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r / T(2), T(1)));\n \
    \   assert(::tools::abs(prev_t) <= ::std::max(a / prev_r / T(2), T(1)));\n   \
    \ return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n}\n\n\n#line 1 \"tools/pow_mod_cache.hpp\"\
    \n\n\n\n#line 5 \"tools/pow_mod_cache.hpp\"\n#include <optional>\n#line 1 \"tools/ssize.hpp\"\
    \n\n\n\n#line 5 \"tools/ssize.hpp\"\n#include <cstddef>\n\nnamespace tools {\n\
    \n  template <typename C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 1 \"tools/find_cycle.hpp\"\n\n\n\n#line 5 \"tools/find_cycle.hpp\"\n\n\
    namespace tools {\n\n  template <typename T, typename F>\n  ::std::pair<long long,\
    \ long long> find_cycle(const T& seed, const F& f) {\n    auto i = 1LL;\n    auto\
    \ j = 2LL;\n    T x = f(seed);\n    T y = f(f(seed));\n    for (; x != y; ++i,\
    \ j += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x = seed;\n    for (; x !=\
    \ y; ++i, ++j, x = f(x), y = f(y));\n\n    const auto head = i;\n\n    ++i;\n\
    \    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n    for (; x != y; ++i, j +=\
    \ 2, x = f(x), y = f(f(y)));\n\n    const auto cycle = j - i;\n\n    return ::std::make_pair(head,\
    \ cycle);\n  }\n}\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n\
    \      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return\
    \ -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) +\
    \ -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\
    \n\n\n\n#line 6 \"tools/floor.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs >\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6\
    \ \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 14 \"tools/pow_mod_cache.hpp\"\n\nnamespace tools\
    \ {\n\n  template <class M>\n  class pow_mod_cache {\n  private:\n    ::std::vector<M>\
    \ m_pow;\n    ::std::vector<M> m_cumsum;\n    ::std::vector<M> m_inv_pow;\n  \
    \  ::std::vector<M> m_inv_cumsum;\n    ::std::optional<::std::pair<long long,\
    \ long long>> m_period;\n\n  public:\n    pow_mod_cache() = default;\n    pow_mod_cache(const\
    \ ::tools::pow_mod_cache<M>&) = default;\n    pow_mod_cache(::tools::pow_mod_cache<M>&&)\
    \ = default;\n    ~pow_mod_cache() = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(const ::tools::pow_mod_cache<M>&) = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(::tools::pow_mod_cache<M>&&) = default;\n\n    M operator[](const\
    \ long long n) {\n      if (!this->m_period) {\n        if (::std::max<long long>(::tools::ssize(this->m_pow)\
    \ - 1, n) - ::std::min<long long>(n, -(::tools::ssize(this->m_inv_pow) - 1)) +\
    \ 1 < M::mod() - 1) {\n          if (n >= 0) {\n            const long long size\
    \ = ::tools::ssize(this->m_pow);\n            this->m_pow.resize(::std::max(size,\
    \ n + 1));\n            for (long long i = size; i < ::tools::ssize(this->m_pow);\
    \ ++i) {\n              this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];\n\
    \            }\n            return this->m_pow[n];\n          } else {\n     \
    \       if (this->m_inv_pow.size() == 1) {\n              this->m_inv_pow.push_back(this->m_pow[1].inv());\n\
    \            }\n            const long long size = ::tools::ssize(this->m_inv_pow);\n\
    \            this->m_inv_pow.resize(::std::max(size, -n + 1));\n            for\
    \ (long long i = size; i < ::tools::ssize(this->m_inv_pow); ++i) {\n         \
    \     this->m_inv_pow[i] = this->m_inv_pow[i - 1] * this->m_inv_pow[1];\n    \
    \        }\n            return this->m_inv_pow[-n];\n          }\n        }\n\n\
    \        this->m_period = ::std::make_optional(::tools::find_cycle(this->m_pow[0],\
    \ [&](const M& prev) { return prev * this->m_pow[1]; }));\n        const long\
    \ long size = ::tools::ssize(this->m_pow);\n        this->m_pow.resize(this->m_period->first\
    \ + this->m_period->second);\n        for (long long i = size; i < ::tools::ssize(this->m_pow);\
    \ ++i) {\n          this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];\n  \
    \      }\n        this->m_inv_pow.clear();\n        this->m_inv_cumsum.clear();\n\
    \      }\n\n      if (this->m_period->first == 0) {\n        return this->m_pow[::tools::mod(n,\
    \ this->m_period->second)];\n      } else {\n        assert(n >= 0);\n       \
    \ if (n < this->m_period->first + this->m_period->second) {\n          return\
    \ this->m_pow[n];\n        } else {\n          return this->m_pow[(n - this->m_period->first)\
    \ % this->m_period->second + this->m_period->first];\n        }\n      }\n   \
    \ }\n\n    M sum(const long long l, const long long r) {\n      if (l >= r) return\
    \ M::raw(0);\n\n      (*this)[r - 1];\n      (*this)[l];\n\n      {\n        const\
    \ long long size = ::tools::ssize(this->m_cumsum);\n        this->m_cumsum.resize(this->m_pow.size()\
    \ + 1);\n        for (long long i = size; i < ::tools::ssize(this->m_cumsum);\
    \ ++i) {\n          this->m_cumsum[i] = this->m_cumsum[i - 1] + this->m_pow[i\
    \ - 1];\n        }\n      }\n\n      if (!this->m_period) {\n        const long\
    \ long size = ::tools::ssize(this->m_inv_cumsum);\n        this->m_inv_cumsum.resize(this->m_inv_pow.size()\
    \ + 1);\n        for (long long i = size; i < ::tools::ssize(this->m_inv_cumsum);\
    \ ++i) {\n          this->m_inv_cumsum[i] = this->m_inv_cumsum[i - 1] + this->m_pow[i\
    \ - 1];\n        }\n\n        if (l >= 0) {\n          return this->m_cumsum[r]\
    \ - this->m_cumsum[l];\n        } else if (r <= 0) {\n          return this->m_inv_cumsum[-l]\
    \ - this->m_inv_cumsum[-r];\n        } else {\n          return (this->m_inv_cumsum[-l]\
    \ - this->m_inv_cumsum[1]) + (this->m_cumsum[r] - this->m_cumsum[0]);\n      \
    \  }\n      }\n\n      static const auto cumsum = [&](const long long ll, const\
    \ long long rr) {\n        return this->m_cumsum[rr] - this->m_cumsum[ll];\n \
    \     };\n\n      if (l >= 0) {\n        static const auto f = [&](const long\
    \ long x) {\n          if (x <= this->m_period->first + this->m_period->second)\
    \ {\n            return cumsum(0, x);\n          } else {\n            return\
    \ cumsum(0, this->m_period->first) +\n              cumsum(this->m_period->first,\
    \ this->m_period->first + this->m_period->second) * ((x - this->m_period->first)\
    \ / this->m_period->second) +\n              cumsum(this->m_period->first, (x\
    \ - this->m_period->first) % this->m_period->second + this->m_period->first);\n\
    \          }\n        };\n        return f(r) - f(l);\n      } else {\n      \
    \  const auto& n = this->m_period->second;\n        return cumsum(::tools::mod(l,\
    \ n), n) + cumsum(0, ::tools::mod(r, n)) + cumsum(0, n) * M(::tools::floor(r,\
    \ n) - ::tools::ceil(l, n));\n      }\n    }\n\n    explicit pow_mod_cache(const\
    \ M& base) : m_pow({M(1), base}), m_cumsum({M(0)}), m_inv_pow({M(1)}), m_inv_cumsum({M(0)})\
    \ {\n    }\n    explicit pow_mod_cache(const long long base) : pow_mod_cache(M(base))\
    \ {\n    }\n  };\n}\n\n\n#line 1 \"tools/now.hpp\"\n\n\n\n#include <chrono>\n\n\
    namespace tools {\n  inline long long now() {\n    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \  }\n}\n\n\n#line 12 \"tools/detail/rolling_hash.hpp\"\n\nnamespace tools {\n\
    \  class rolling_hash;\n\n  class modint_for_rolling_hash {\n  private:\n    static\
    \ constexpr ::std::uint64_t MASK30 = (::std::uint64_t(1) << 30) - 1;\n    static\
    \ constexpr ::std::uint64_t MASK31 = (::std::uint64_t(1) << 31) - 1;\n    static\
    \ constexpr ::std::uint64_t MOD = (::std::uint64_t(1) << 61) - 1;\n    static\
    \ constexpr ::std::uint64_t MASK61 = MOD;\n    static constexpr ::std::uint64_t\
    \ POSITIVIZER = MOD * 4;\n\n    ::std::uint64_t m_val;\n\n    modint_for_rolling_hash(const\
    \ ::std::uint64_t x, int) : m_val(x) {\n    }\n\n    static ::std::uint64_t mul(const\
    \ ::std::uint64_t a, const ::std::uint64_t b) {\n      assert(a < MOD);\n    \
    \  assert(b < MOD);\n      const ::std::uint64_t au = a >> 31;\n      const ::std::uint64_t\
    \ ad = a & MASK31;\n      const ::std::uint64_t bu = b >> 31;\n      const ::std::uint64_t\
    \ bd = b & MASK31;\n      const ::std::uint64_t mid = ad * bu + au * bd;\n   \
    \   const ::std::uint64_t midu = mid >> 30;\n      const ::std::uint64_t midd\
    \ = mid & MASK30;\n      return au * bu * 2 + midu + (midd << 31) + ad * bd;\n\
    \    }\n    static ::std::uint64_t calc_mod(const ::std::uint64_t x) {\n     \
    \ const ::std::uint64_t xu = x >> 61;\n      const ::std::uint64_t xd = x & MASK61;\n\
    \      ::std::uint64_t res = xu + xd;\n      if (res >= MOD) res -= MOD;\n   \
    \   return res;\n    }\n\n  public:\n    modint_for_rolling_hash() = default;\n\
    \    modint_for_rolling_hash(const ::tools::modint_for_rolling_hash&) = default;\n\
    \    modint_for_rolling_hash(::tools::modint_for_rolling_hash&&) = default;\n\
    \    ~modint_for_rolling_hash() = default;\n    ::tools::modint_for_rolling_hash&\
    \ operator=(const ::tools::modint_for_rolling_hash&) = default;\n    ::tools::modint_for_rolling_hash&\
    \ operator=(::tools::modint_for_rolling_hash&&) = default;\n\n    explicit modint_for_rolling_hash(const\
    \ ::std::uint64_t x) : m_val(calc_mod(x)) {\n    }\n\n    ::tools::modint_for_rolling_hash\
    \ pow(const long long n) const {\n      return ::tools::pow(*this, n);\n    }\n\
    \    ::tools::modint_for_rolling_hash inv() const {\n      assert(this->m_val\
    \ != 0);\n      return ::tools::modint_for_rolling_hash(::std::get<0>(::tools::extgcd(this->m_val,\
    \ MOD)));\n    }\n\n    ::tools::modint_for_rolling_hash operator+() const {\n\
    \      return *this;\n    }\n    ::tools::modint_for_rolling_hash operator-()\
    \ const {\n      return ::tools::modint_for_rolling_hash(POSITIVIZER - this->m_val);\n\
    \    }\n    friend ::tools::modint_for_rolling_hash operator+(const ::tools::modint_for_rolling_hash&\
    \ lhs, const ::tools::modint_for_rolling_hash& rhs) {\n      return ::tools::modint_for_rolling_hash(lhs.m_val\
    \ + rhs.m_val);\n    }\n    ::tools::modint_for_rolling_hash& operator+=(const\
    \ ::tools::modint_for_rolling_hash& other) {\n      this->m_val = calc_mod(this->m_val\
    \ + other.m_val);\n      return *this;\n    }\n    friend ::tools::modint_for_rolling_hash\
    \ operator-(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(lhs.m_val + POSITIVIZER\
    \ - rhs.m_val);\n    }\n    ::tools::modint_for_rolling_hash& operator-=(const\
    \ ::tools::modint_for_rolling_hash& other) {\n      this->m_val = calc_mod(this->m_val\
    \ + POSITIVIZER - other.m_val);\n      return *this;\n    }\n    friend ::tools::modint_for_rolling_hash\
    \ operator*(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(mul(lhs.m_val, rhs.m_val));\n\
    \    }\n    ::tools::modint_for_rolling_hash& operator*=(const ::tools::modint_for_rolling_hash&\
    \ other) {\n      this->m_val = calc_mod(mul(this->m_val, other.m_val));\n   \
    \   return *this;\n    }\n    friend ::tools::modint_for_rolling_hash operator/(const\
    \ ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(mul(lhs.m_val, rhs.inv().m_val));\n\
    \    }\n    ::tools::modint_for_rolling_hash& operator/=(const ::tools::modint_for_rolling_hash&\
    \ other) {\n      this->m_val = calc_mod(mul(this->m_val, other.inv().m_val));\n\
    \      return *this;\n    }\n    ::tools::modint_for_rolling_hash& operator++()\
    \ {\n      this->m_val = calc_mod(this->m_val + 1);\n      return *this;\n   \
    \ }\n    ::tools::modint_for_rolling_hash operator++(int) {\n      const auto\
    \ result = *this;\n      ++(*this);\n      return result;\n    }\n    ::tools::modint_for_rolling_hash&\
    \ operator--() {\n      this->m_val = calc_mod(this->m_val + POSITIVIZER - 1);\n\
    \      return *this;\n    }\n    ::tools::modint_for_rolling_hash operator--(int)\
    \ {\n      const auto result = *this;\n      --(*this);\n      return result;\n\
    \    }\n\n    friend bool operator==(const ::tools::modint_for_rolling_hash& lhs,\
    \ const ::tools::modint_for_rolling_hash& rhs) {\n      return lhs.m_val == rhs.m_val;\n\
    \    }\n    friend bool operator!=(const ::tools::modint_for_rolling_hash& lhs,\
    \ const ::tools::modint_for_rolling_hash& rhs) {\n      return lhs.m_val != rhs.m_val;\n\
    \    }\n\n    long long val() const {\n      return this->m_val;\n    }\n\n  \
    \  static ::tools::modint_for_rolling_hash raw(const ::std::uint64_t x) {\n  \
    \    return ::tools::modint_for_rolling_hash(x, 0);\n    }\n    static long long\
    \ mod() {\n      return MOD;\n    }\n\n    friend ::tools::rolling_hash;\n  };\n\
    \n  class rolling_hash {\n  private:\n    using mint = ::tools::modint_for_rolling_hash;\n\
    \    inline static ::tools::pow_mod_cache<mint> m_pow_base = ::tools::pow_mod_cache<mint>(::tools::now());\n\
    \    ::std::vector<mint> m_hash;\n\n  public:\n    rolling_hash() = default;\n\
    \    rolling_hash(const ::tools::rolling_hash&) = default;\n    rolling_hash(::tools::rolling_hash&&)\
    \ = default;\n    ~rolling_hash() = default;\n    ::tools::rolling_hash& operator=(const\
    \ ::tools::rolling_hash&) = default;\n    ::tools::rolling_hash& operator=(::tools::rolling_hash&&)\
    \ = default;\n\n    template <typename InputIterator>\n    rolling_hash(InputIterator\
    \ begin, InputIterator end) {\n      this->m_hash.push_back(mint::raw(0));\n \
    \     const auto base = m_pow_base[1].m_val;\n      for (auto it = begin; it !=\
    \ end; ++it) {\n        this->m_hash.emplace_back(mint::mul(this->m_hash.back().m_val,\
    \ base) + *it);\n      }\n      m_pow_base[this->m_hash.size()];\n    }\n\n  \
    \  mint pow_base(const ::std::size_t i) const {\n      return m_pow_base[i];\n\
    \    }\n\n    mint slice(const ::std::size_t l, const ::std::size_t r) const {\n\
    \      assert(l <= r && r <= this->m_hash.size());\n      return mint(this->m_hash[r].m_val\
    \ + mint::POSITIVIZER - mint::mul(this->m_hash[l].m_val, m_pow_base[r - l].m_val));\n\
    \    }\n  };\n}\n\n\n#line 5 \"tools/modint_for_rolling_hash.hpp\"\n\n\n#line\
    \ 9 \"tests/has_mod.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(!tools::has_mod_v<int>);\n  assert_that(!tools::has_mod_v<std::string>);\n\
    \  assert_that(tools::has_mod_v<atcoder::modint998244353>);\n  assert_that(tools::has_mod_v<atcoder::modint>);\n\
    \  assert_that(tools::has_mod_v<tools::modint_for_rolling_hash>);\n  assert_that(!tools::has_mod_v<std::vector<atcoder::modint998244353>>);\n\
    \  assert_that(!tools::has_mod_v<std::vector<atcoder::modint>>);\n  assert_that(!tools::has_mod_v<std::vector<tools::modint_for_rolling_hash>>);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <string>\n#include \"atcoder/modint.hpp\"\n#include\
    \ \"tools/assert_that.hpp\"\n#include \"tools/has_mod.hpp\"\n#include \"tools/modint_for_rolling_hash.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  assert_that(!tools::has_mod_v<int>);\n  assert_that(!tools::has_mod_v<std::string>);\n\
    \  assert_that(tools::has_mod_v<atcoder::modint998244353>);\n  assert_that(tools::has_mod_v<atcoder::modint>);\n\
    \  assert_that(tools::has_mod_v<tools::modint_for_rolling_hash>);\n  assert_that(!tools::has_mod_v<std::vector<atcoder::modint998244353>>);\n\
    \  assert_that(!tools::has_mod_v<std::vector<atcoder::modint>>);\n  assert_that(!tools::has_mod_v<std::vector<tools::modint_for_rolling_hash>>);\n\
    \n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/has_mod.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  - tools/extgcd.hpp
  - tools/abs.hpp
  - tools/pow_mod_cache.hpp
  - tools/ssize.hpp
  - tools/find_cycle.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/floor.hpp
  - tools/ceil.hpp
  - tools/now.hpp
  isVerificationFile: true
  path: tests/has_mod.test.cpp
  requiredBy: []
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/has_mod.test.cpp
layout: document
redirect_from:
- /verify/tests/has_mod.test.cpp
- /verify/tests/has_mod.test.cpp.html
title: tests/has_mod.test.cpp
---
