---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tests/assert_that.hpp
    title: tests/assert_that.hpp
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor_sqrt.hpp
    title: $\left\lfloor \sqrt{x} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/segmented_sieve.hpp
    title: Segmented sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc227/tasks/abc227_g
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/segmented_sieve.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n// Source: https://atcoder.jp/contests/abc227/tasks/abc227_g\n\n#include <cstdint>\n\
    #include <unordered_map>\n#include <numeric>\n#include <iostream>\n#include <iterator>\n\
    #line 1 \"tests/assert_that.hpp\"\n\n\n\n#define assert_that(cond) do {\\\n  if\
    \ (!(cond)) {\\\n    std::cerr << __FILE__ << ':' << __LINE__ << \": \" << __func__\
    \ << \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n\n\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\n\n\
    \n\n#include <cassert>\n#line 6 \"lib/ac-library/atcoder/modint.hpp\"\n#include\
    \ <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"\
    lib/ac-library/atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\n// Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/segmented_sieve.hpp\"\
    \n\n\n\n#include <vector>\n#line 6 \"tools/segmented_sieve.hpp\"\n#include <algorithm>\n\
    #include <limits>\n#line 9 \"tools/segmented_sieve.hpp\"\n#include <cstddef>\n\
    #line 1 \"tools/floor_sqrt.hpp\"\n\n\n\n#line 5 \"tools/floor_sqrt.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  T floor_sqrt(T n) {\n    assert(n >= 0);\n\
    \n    T ok = 0;\n    T ng;\n    for (ng = 1; ng * ng <= n; ng *= 2);\n\n    while\
    \ (ng - ok > 1) {\n      const T mid = (ok + ng) / 2;\n      if (mid * mid <=\
    \ n) {\n        ok = mid;\n      } else {\n        ng = mid;\n      }\n    }\n\
    \n    return ok;\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  bool chmin(M&\
    \ lhs, const N& rhs) {\n    const bool updated = lhs > rhs;\n    if (updated)\
    \ lhs = rhs;\n    return updated;\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\
    \n#line 1 \"tools/detail/ceil_and_floor.hpp\"\n\n\n\n#line 5 \"tools/detail/ceil_and_floor.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs);\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs);\n  \n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const\
    \ M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs\
    \ / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n\
    \      lhs >= 0 && rhs < 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs,\
    \ -rhs);\n  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\
    \n#line 15 \"tools/segmented_sieve.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class segmented_sieve {\n  private:\n    ::std::vector<T> m_lpf;\n   \
    \ ::std::vector<::std::vector<T>> m_pf;\n    ::std::vector<T> m_aux;\n    T m_l;\n\
    \n  public:\n    segmented_sieve() = default;\n    segmented_sieve(const ::tools::segmented_sieve<T>&)\
    \ = default;\n    segmented_sieve(::tools::segmented_sieve<T>&&) = default;\n\
    \    ~segmented_sieve() = default;\n    ::tools::segmented_sieve<T>& operator=(const\
    \ ::tools::segmented_sieve<T>&) = default;\n    ::tools::segmented_sieve<T>& operator=(::tools::segmented_sieve<T>&&)\
    \ = default;\n\n    segmented_sieve(const T& k, const T& l, const T& r) {\n  \
    \    assert(l <= r);\n\n      const T lpf_max = ::std::max(::tools::floor_sqrt(r),\
    \ k);\n      this->m_lpf.resize(lpf_max + 1);\n      ::std::fill(this->m_lpf.begin(),\
    \ this->m_lpf.end(), ::std::numeric_limits<T>::max());\n      this->m_pf.resize(r\
    \ - l + 1);\n      this->m_aux.resize(r - l + 1);\n      ::std::iota(this->m_aux.begin(),\
    \ this->m_aux.end(), l);\n      this->m_l = l;\n\n      for (T p = 2; p <= lpf_max;\
    \ ++p) {\n        if (::tools::chmin(this->m_lpf[p], p)) {\n          for (T np\
    \ = p * p; np <= lpf_max; np += p) {\n            ::tools::chmin(this->m_lpf[np],\
    \ p);\n          }\n          for (T p_q = p, np_q; (np_q = ::tools::ceil(l, p_q)\
    \ * p_q) <= r; p_q *= p) {\n            for (; np_q <= r; np_q += p_q) {\n   \
    \           if (lpf_max < this->m_aux[np_q - l]) {\n                this->m_pf[np_q\
    \ - l].push_back(p);\n                this->m_aux[np_q - l] /= p;\n          \
    \    }\n            }\n          }\n        }\n      }\n\n      for (T i = l;\
    \ i <= r; ++i) {\n        if (lpf_max < this->m_aux[i - l]) {\n          this->m_pf[i\
    \ - l].push_back(this->m_aux[i - l]);\n          this->m_aux[i - l] = 1;\n   \
    \     }\n      }\n    }\n\n    segmented_sieve(const T& l, const T& r) :\n   \
    \   segmented_sieve(0, l, r) {\n    }\n\n    T lpf_max() const {\n      return\
    \ this->m_lpf.size() - 1;\n    }\n    T l() const {\n      return this->m_l;\n\
    \    }\n    T r() const {\n      return this->m_l + this->m_pf.size() - 1;\n \
    \   }\n\n    class prime_factor_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_n;\n\n    public:\n      class iterator {\n      private:\n\
    \        const prime_factor_iterable *m_parent;\n        bool m_large;\n     \
    \   T m_i;\n\n        T n() const {\n          return this->m_parent->m_n;\n \
    \       }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator() = default;\n        iterator(const iterator&) = default;\n   \
    \     iterator(iterator&&) = default;\n        ~iterator() = default;\n      \
    \  iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(prime_factor_iterable const * const parent, const\
    \ bool large, const T& i) :\n          m_parent(parent), m_large(large), m_i(i)\
    \ {\n        }\n\n        T operator*() const {\n          if (this->m_large)\
    \ {\n            return this->m_parent->m_parent->m_pf[this->n() - this->m_parent->m_parent->l()][this->m_i];\n\
    \          } else {\n            return this->m_parent->m_parent->m_lpf[this->m_i];\n\
    \          }\n        }\n\n        iterator& operator++() {\n          if (this->m_large)\
    \ {\n            ++this->m_i;\n            if (this->m_i == T(this->m_parent->m_parent->m_pf[this->n()\
    \ - this->m_parent->m_parent->l()].size())) {\n              this->m_large = false;\n\
    \              this->m_i = this->m_parent->m_parent->m_aux[this->n() - this->m_parent->m_parent->l()];\n\
    \            }\n          } else {\n            this->m_i /= this->m_parent->m_parent->m_lpf[this->m_i];\n\
    \          }\n          return *this;\n        }\n\n        iterator operator++(int)\
    \ {\n          const iterator self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n\n        friend bool operator==(const iterator& lhs, const\
    \ iterator& rhs) {\n          return lhs.m_large == rhs.m_large && (!lhs.m_large\
    \ || lhs.n() == rhs.n()) && lhs.m_i == rhs.m_i;\n        }\n\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      prime_factor_iterable(::tools::segmented_sieve<T>\
    \ const * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n  \
    \    }\n\n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    class distinct_prime_factor_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      T m_n;\n\n    public:\n      class iterator {\n      private:\n\
    \        const distinct_prime_factor_iterable *m_parent;\n        bool m_large;\n\
    \        T m_i;\n        ::std::pair<T, T> m_value;\n\n        T n() const {\n\
    \          return this->m_parent->m_n;\n        }\n\n        void next() {\n \
    \         const ::std::vector<T>& lpf = this->m_parent->m_parent->m_lpf;\n   \
    \       if (this->m_large) {\n            const ::std::vector<T>& pf = this->m_parent->m_parent->m_pf[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n            this->m_value.first = pf[this->m_i];\n\
    \            this->m_value.second = 0;\n            for (; this->m_i < T(pf.size())\
    \ && pf[this->m_i] == this->m_value.first; ++this->m_i) {\n              ++this->m_value.second;\n\
    \            }\n            if (this->m_i == T(pf.size())) {\n              this->m_large\
    \ = false;\n              this->m_i = this->m_parent->m_parent->m_aux[this->m_parent->m_n\
    \ - this->m_parent->m_parent->l()];\n              for (; lpf[this->m_i] == this->m_value.first;\
    \ this->m_i /= lpf[this->m_i]) {\n                ++this->m_value.second;\n  \
    \            }\n            }\n          } else {\n            if (this->m_i ==\
    \ 1) {\n              this->m_value.first = ::std::numeric_limits<T>::max();\n\
    \              this->m_value.second = 0;\n            } else {\n             \
    \ this->m_value.first = lpf[this->m_i];\n              this->m_value.second =\
    \ 0;\n              for (; lpf[this->m_i] == this->m_value.first; this->m_i /=\
    \ lpf[this->m_i]) {\n                ++this->m_value.second;\n              }\n\
    \            }\n          }\n        }\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = ::std::pair<T, T>;\n       \
    \ using reference = ::std::pair<T, T>&;\n        using pointer = ::std::pair<T,\
    \ T>*;\n        using iterator_category = ::std::input_iterator_tag;\n\n     \
    \   iterator() = default;\n        iterator(const iterator&) = default;\n    \
    \    iterator(iterator&&) = default;\n        ~iterator() = default;\n       \
    \ iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(distinct_prime_factor_iterable const * const\
    \ parent, const bool large, const T& i) :\n          m_parent(parent), m_large(large),\
    \ m_i(i) {\n          this->next();\n        }\n\n        ::std::pair<T, T> operator*()\
    \ const {\n          return this->m_value;\n        }\n\n        iterator& operator++()\
    \ {\n          this->next();\n          return *this;\n        }\n\n        iterator\
    \ operator++(int) {\n          const iterator self = *this;\n          ++*this;\n\
    \          return self;\n        }\n\n        friend bool operator==(const iterator&\
    \ lhs, const iterator& rhs) {\n          return lhs.n() == rhs.n() && lhs.m_value.first\
    \ == rhs.m_value.first;\n        }\n\n        friend bool operator!=(const iterator&\
    \ lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n        }\n  \
    \    };\n\n      distinct_prime_factor_iterable(::tools::segmented_sieve<T> const\
    \ * const parent, const T& n) :\n        m_parent(parent), m_n(n) {\n      }\n\
    \n      iterator begin() const {\n        if (this->m_n <= this->m_parent->lpf_max())\
    \ {\n          return iterator(this, false, this->m_n);\n        } else {\n  \
    \        return iterator(this, true, 0);\n        }\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, false, 1);\n      }\n    };\n\n\
    \    class prime_iterable {\n    private:\n      const ::tools::segmented_sieve<T>\
    \ *m_parent;\n      bool m_large;\n      T m_lb;\n      T m_ub;\n\n    public:\n\
    \      class iterator {\n      private:\n        const prime_iterable *m_parent;\n\
    \        T m_i;\n\n        void next() {\n          ++this->m_i;\n          if\
    \ (this->m_parent->m_large) {\n            for (; this->m_i <= this->m_parent->m_ub\
    \ && this->m_parent->m_parent->m_pf[this->m_i - this->m_parent->m_parent->l()][0]\
    \ != this->m_i; ++this->m_i);\n          } else {\n            for (; this->m_i\
    \ <= this->m_parent->m_ub && this->m_parent->m_parent->m_lpf[this->m_i] != this->m_i;\
    \ ++this->m_i);\n          }\n        }\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = T;\n        using reference\
    \ = T&;\n        using pointer = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(const iterator&) = default;\n\
    \        iterator(iterator&&) = default;\n        ~iterator() = default;\n   \
    \     iterator& operator=(const iterator&) = default;\n        iterator& operator=(iterator&&)\
    \ = default;\n\n        iterator(prime_iterable const * const parent, const T&\
    \ i) :\n          m_parent(parent), m_i(i) {\n          this->next();\n      \
    \  }\n\n        T operator*() const {\n          return this->m_i;\n        }\n\
    \n        iterator& operator++() {\n          this->next();\n          return\
    \ *this;\n        }\n\n        iterator operator++(int) {\n          const iterator\
    \ self = *this;\n          ++*this;\n          return self;\n        }\n\n   \
    \     friend bool operator==(const iterator& lhs, const iterator& rhs) {\n   \
    \       return lhs.m_i == rhs.m_i;\n        }\n\n        friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n   \
    \     }\n      };\n\n      prime_iterable(::tools::segmented_sieve<T> const *\
    \ const parent, const bool large, const T& lb, const T& ub) :\n        m_parent(parent),\
    \ m_large(large), m_lb(lb), m_ub(ub) {\n      }\n\n      iterator begin() const\
    \ {\n        return iterator(this, this->m_lb - 1);\n      }\n\n      iterator\
    \ end() const {\n        return iterator(this, this->m_ub);\n      }\n    };\n\
    \n    prime_factor_iterable prime_factor_range(const T& n) const {\n      assert((1\
    \ <= n && n <= this->lpf_max()) || (this->l() <= n && n <= this->r()));\n    \
    \  return prime_factor_iterable(this, n);\n    }\n\n    distinct_prime_factor_iterable\
    \ distinct_prime_factor_range(const T& n) const {\n      assert((1 <= n && n <=\
    \ this->lpf_max()) || (this->l() <= n && n <= this->r()));\n      return distinct_prime_factor_iterable(this,\
    \ n);\n    }\n\n    prime_iterable prime_range(const T& lb, const T& ub) const\
    \ {\n      assert(lb <= ub);\n      const bool is_in_small_sieve = 1 <= lb &&\
    \ ub <= this->lpf_max();\n      const bool is_in_large_sieve = this->l() <= lb\
    \ && ub <= this->r();\n      assert(is_in_small_sieve || is_in_large_sieve);\n\
    \      return prime_iterable(this, !is_in_small_sieve, lb, ub);\n    }\n  };\n\
    }\n\n\n#line 13 \"tests/segmented_sieve.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    using mint = atcoder::modint998244353;\n\ni64 solve1(const i64& N, const i64&\
    \ K, const tools::segmented_sieve<i64>& sieve) {\n  std::unordered_map<i64, i64>\
    \ nCk;\n  for (i64 i = N - K + 1; i <= N; ++i) {\n    for (const i64& p : sieve.prime_factor_range(i))\
    \ {\n      ++nCk[p];\n    }\n  }\n  for (i64 i = 1; i <= K; ++i) {\n    for (const\
    \ i64& p : sieve.prime_factor_range(i)) {\n      --nCk[p];\n    }\n  }\n  return\
    \ std::accumulate(nCk.begin(), nCk.end(), mint(1), [](const mint& prod, const\
    \ auto& pair) { return prod * mint(pair.second + 1); }).val();\n}\n\ni64 solve2(const\
    \ i64& N, const i64& K, const tools::segmented_sieve<i64>& sieve) {\n  std::unordered_map<i64,\
    \ i64> nCk;\n  for (i64 i = N - K + 1; i <= N; ++i) {\n    for (const auto& [p,\
    \ q] : sieve.distinct_prime_factor_range(i)) {\n      nCk[p] += q;\n    }\n  }\n\
    \  for (i64 i = 1; i <= K; ++i) {\n    for (const auto& [p, q] : sieve.distinct_prime_factor_range(i))\
    \ {\n      nCk[p] -= q;\n    }\n  }\n  return std::accumulate(nCk.begin(), nCk.end(),\
    \ mint(1), [](const mint& prod, const auto& pair) { return prod * mint(pair.second\
    \ + 1); }).val();\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    const i64 N = 5;\n    const i64 K = 2;\n    const tools::segmented_sieve<i64>\
    \ sieve(K, N - K + 1, N);\n    assert_that(solve1(N, K, sieve) == 4);\n    assert_that(solve2(N,\
    \ K, sieve) == 4);\n  }\n\n  {\n    const i64 N = 103;\n    const i64 K = 3;\n\
    \    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);\n    assert_that(solve1(N,\
    \ K, sieve) == 8);\n    assert_that(solve2(N, K, sieve) == 8);\n  }\n\n  {\n \
    \   const i64 N = 1000000000000;\n    const i64 K = 1000000;\n    const tools::segmented_sieve<i64>\
    \ sieve(K, N - K + 1, N);\n    assert_that(solve1(N, K, sieve) == 110520107);\n\
    \    assert_that(solve2(N, K, sieve) == 110520107);\n\n    const auto primes =\
    \ sieve.prime_range(999999990000, 1000000000000);\n    assert_that(std::distance(primes.begin(),\
    \ primes.end()) == 337);\n  }\n\n  {\n    const i64 N = 6;\n    const i64 K =\
    \ 3;\n    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);\n    assert_that(solve1(N,\
    \ K, sieve) == 6);\n    assert_that(solve2(N, K, sieve) == 6);\n  }\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    // Source: https://atcoder.jp/contests/abc227/tasks/abc227_g\n\n#include <cstdint>\n\
    #include <unordered_map>\n#include <numeric>\n#include <iostream>\n#include <iterator>\n\
    #include \"tests/assert_that.hpp\"\n#include \"atcoder/modint.hpp\"\n#include\
    \ \"tools/segmented_sieve.hpp\"\n\nusing i64 = std::int_fast64_t;\nusing mint\
    \ = atcoder::modint998244353;\n\ni64 solve1(const i64& N, const i64& K, const\
    \ tools::segmented_sieve<i64>& sieve) {\n  std::unordered_map<i64, i64> nCk;\n\
    \  for (i64 i = N - K + 1; i <= N; ++i) {\n    for (const i64& p : sieve.prime_factor_range(i))\
    \ {\n      ++nCk[p];\n    }\n  }\n  for (i64 i = 1; i <= K; ++i) {\n    for (const\
    \ i64& p : sieve.prime_factor_range(i)) {\n      --nCk[p];\n    }\n  }\n  return\
    \ std::accumulate(nCk.begin(), nCk.end(), mint(1), [](const mint& prod, const\
    \ auto& pair) { return prod * mint(pair.second + 1); }).val();\n}\n\ni64 solve2(const\
    \ i64& N, const i64& K, const tools::segmented_sieve<i64>& sieve) {\n  std::unordered_map<i64,\
    \ i64> nCk;\n  for (i64 i = N - K + 1; i <= N; ++i) {\n    for (const auto& [p,\
    \ q] : sieve.distinct_prime_factor_range(i)) {\n      nCk[p] += q;\n    }\n  }\n\
    \  for (i64 i = 1; i <= K; ++i) {\n    for (const auto& [p, q] : sieve.distinct_prime_factor_range(i))\
    \ {\n      nCk[p] -= q;\n    }\n  }\n  return std::accumulate(nCk.begin(), nCk.end(),\
    \ mint(1), [](const mint& prod, const auto& pair) { return prod * mint(pair.second\
    \ + 1); }).val();\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    const i64 N = 5;\n    const i64 K = 2;\n    const tools::segmented_sieve<i64>\
    \ sieve(K, N - K + 1, N);\n    assert_that(solve1(N, K, sieve) == 4);\n    assert_that(solve2(N,\
    \ K, sieve) == 4);\n  }\n\n  {\n    const i64 N = 103;\n    const i64 K = 3;\n\
    \    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);\n    assert_that(solve1(N,\
    \ K, sieve) == 8);\n    assert_that(solve2(N, K, sieve) == 8);\n  }\n\n  {\n \
    \   const i64 N = 1000000000000;\n    const i64 K = 1000000;\n    const tools::segmented_sieve<i64>\
    \ sieve(K, N - K + 1, N);\n    assert_that(solve1(N, K, sieve) == 110520107);\n\
    \    assert_that(solve2(N, K, sieve) == 110520107);\n\n    const auto primes =\
    \ sieve.prime_range(999999990000, 1000000000000);\n    assert_that(std::distance(primes.begin(),\
    \ primes.end()) == 337);\n  }\n\n  {\n    const i64 N = 6;\n    const i64 K =\
    \ 3;\n    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);\n    assert_that(solve1(N,\
    \ K, sieve) == 6);\n    assert_that(solve2(N, K, sieve) == 6);\n  }\n\n  std::cout\
    \ << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tests/assert_that.hpp
  - tools/segmented_sieve.hpp
  - tools/floor_sqrt.hpp
  - tools/chmin.hpp
  - tools/ceil.hpp
  - tools/detail/ceil_and_floor.hpp
  isVerificationFile: true
  path: tests/segmented_sieve.test.cpp
  requiredBy: []
  timestamp: '2021-12-10 23:22:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/segmented_sieve.test.cpp
layout: document
redirect_from:
- /verify/tests/segmented_sieve.test.cpp
- /verify/tests/segmented_sieve.test.cpp.html
title: tests/segmented_sieve.test.cpp
---
