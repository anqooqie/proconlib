---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/bell.hpp
    title: Bell numbers
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':question:'
    path: tools/ceil_log2.hpp
    title: $\left\lceil \log_2(x) \right\rceil$
  - icon: ':question:'
    path: tools/convolution.hpp
    title: Convolution
  - icon: ':question:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':question:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':question:'
    path: tools/fact_mod_cache.hpp
    title: Cache for $n^{-1}, n!, n!^{-1} \pmod{P}$
  - icon: ':question:'
    path: tools/find_cycle.hpp
    title: Floyd's cycle-finding algorithm
  - icon: ':question:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':question:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':question:'
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':question:'
    path: tools/garner3.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$, $\mathbb{Z} / M_2
      \mathbb{Z}$ and $\mathbb{Z} / M_3 \mathbb{Z}$
  - icon: ':question:'
    path: tools/group.hpp
    title: Typical groups
  - icon: ':question:'
    path: tools/int128_t.hpp
    title: 128 bit signed integer
  - icon: ':question:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':question:'
    path: tools/is_group.hpp
    title: Check whether T is a group
  - icon: ':question:'
    path: tools/is_monoid.hpp
    title: Check whether T is a monoid
  - icon: ':question:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':x:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
  - icon: ':question:'
    path: tools/less_by_first.hpp
    title: std::less by first
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':question:'
    path: tools/online_cumsum.hpp
    title: Online cumulative sum
  - icon: ':x:'
    path: tools/partition_function.hpp
    title: Partition function
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':question:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':question:'
    path: tools/pow_mod_cache.hpp
    title: Cache for $b^n \pmod{M}$
  - icon: ':question:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':question:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':question:'
    path: tools/run_length.hpp
    title: Run-length encoding
  - icon: ':x:'
    path: tools/sample_point_shift.hpp
    title: Shift of sampling points of polynomial
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':question:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind
  - icon: ':x:'
    path: tools/twelvefold_way.hpp
    title: Twelvefold way
  - icon: ':question:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  - icon: ':question:'
    path: tools/virtual_vector.hpp
    title: Lazy evaluation read-only std::vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_A
  bundledCode: "#line 1 \"tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_A\"\n\n#include\
    \ <iostream>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\n\n\n\n#include <cassert>\n\
    #include <numeric>\n#include <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\n#line 1 \"lib/ac-library/atcoder/internal_math.hpp\"\n\n\n\n#include\
    \ <utility>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder\
    \ {\n\nnamespace internal {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr\
    \ long long safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0)\
    \ x += m;\n    return x;\n}\n\n// Fast modular multiplication by barrett reduction\n\
    // Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n// NOTE: reconsider\
    \ after Ice Lake\nstruct barrett {\n    unsigned int _m;\n    unsigned long long\
    \ im;\n\n    // @param m `1 <= m`\n    explicit barrett(unsigned int m) : _m(m),\
    \ im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n    unsigned int\
    \ umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n    // @param b\
    \ `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned int\
    \ a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im = 0,\
    \ so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n        //\
    \ -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0 <= c,\
    \ d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r\
    \ + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 +\
    \ m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n       \
    \ unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/twelvefold_way.hpp\"\
    \n\n\n\n#line 5 \"tools/twelvefold_way.hpp\"\n#include <algorithm>\n#line 1 \"\
    tools/is_prime.hpp\"\n\n\n\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\n\
    \n\n\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\n#line 5 \"tools/uint128_t.hpp\"\n\
    #include <string>\n#line 7 \"tools/uint128_t.hpp\"\n#include <cstddef>\n#line\
    \ 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const float\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const double x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const long double\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n\
    \    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n\
    \    return x;\n  }\n  constexpr unsigned long abs(const unsigned long x) {\n\
    \    return x;\n  }\n  constexpr unsigned long long abs(const unsigned long long\
    \ x) {\n    return x;\n  }\n}\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\nnamespace\
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
    \ os << s;\n}\n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x,\
    \ const T2 y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n    u128 prod_mod\
    \ = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0)\
    \ ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\
    \n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line\
    \ 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const\
    \ M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs\
    \ >= M(0)) {\n      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n\
    \        return -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return\
    \ (-lhs - T(1) + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\
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
    \ true;\n  }\n}\n\n\n#line 1 \"tools/fact_mod_cache.hpp\"\n\n\n\n#include <vector>\n\
    #line 7 \"tools/fact_mod_cache.hpp\"\n#include <cmath>\n#line 1 \"tools/ssize.hpp\"\
    \n\n\n\n#line 6 \"tools/ssize.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 10 \"tools/fact_mod_cache.hpp\"\n\nnamespace tools {\n\n  template <class\
    \ M>\n  class fact_mod_cache {\n    ::std::vector<M> m_inv;\n    ::std::vector<M>\
    \ m_fact;\n    ::std::vector<M> m_fact_inv;\n\n  public:\n    fact_mod_cache()\
    \ : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1), M::raw(1)}), m_fact_inv({M::raw(1),\
    \ M::raw(1)}) {\n      assert(::tools::is_prime(M::mod()));\n    }\n    explicit\
    \ fact_mod_cache(const long long max) : fact_mod_cache() {\n      this->fact(::std::min<long\
    \ long>(max, M::mod() - 1));\n      this->fact_inv(::std::min<long long>(max,\
    \ M::mod() - 1));\n    }\n\n    M inv(const long long n) {\n      assert(n % M::mod()\
    \ != 0);\n      const long long size = ::tools::ssize(this->m_inv);\n      this->m_inv.resize(::std::clamp<long\
    \ long>(::std::abs(n) + 1, size, M::mod()));\n      for (long long i = size; i\
    \ < ::tools::ssize(this->m_inv); ++i) {\n        this->m_inv[i] = -this->m_inv[M::mod()\
    \ % i] * M::raw(M::mod() / i);\n      }\n      M result = this->m_inv[::std::abs(n)\
    \ % M::mod()];\n      if (n < 0) result = -result;\n      return result;\n   \
    \ }\n    M fact(const long long n) {\n      assert(n >= 0);\n      const long\
    \ long size = ::tools::ssize(this->m_fact);\n      this->m_fact.resize(::std::clamp<long\
    \ long>(n + 1, size, M::mod()));\n      for (long long i = size; i < ::tools::ssize(this->m_fact);\
    \ ++i) {\n        this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);\n      }\n\
    \      return n < M::mod() ? this->m_fact[n] : M::raw(0);\n    }\n    M fact_inv(const\
    \ long long n) {\n      assert(0 <= n && n < M::mod());\n      const long long\
    \ size = ::tools::ssize(this->m_fact_inv);\n      this->m_fact_inv.resize(::std::max<long\
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
    \ + r - 1, r);\n    }\n  };\n}\n\n\n#line 1 \"tools/large_fact_mod_cache.hpp\"\
    \n\n\n\n#line 5 \"tools/large_fact_mod_cache.hpp\"\n#include <iterator>\n#line\
    \ 1 \"tools/pow_mod_cache.hpp\"\n\n\n\n#line 5 \"tools/pow_mod_cache.hpp\"\n#include\
    \ <optional>\n#line 1 \"tools/find_cycle.hpp\"\n\n\n\n#line 5 \"tools/find_cycle.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T, typename F>\n  ::std::pair<long\
    \ long, long long> find_cycle(const T& seed, const F& f) {\n    auto i = 1LL;\n\
    \    auto j = 2LL;\n    T x = f(seed);\n    T y = f(f(seed));\n    for (; x !=\
    \ y; ++i, j += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x = seed;\n    for\
    \ (; x != y; ++i, ++j, x = f(x), y = f(y));\n\n    const auto head = i;\n\n  \
    \  ++i;\n    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n    for (; x != y; ++i,\
    \ j += 2, x = f(x), y = f(f(y)));\n\n    const auto cycle = j - i;\n\n    return\
    \ ::std::make_pair(head, cycle);\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\n\n\n\
    \n#line 6 \"tools/floor.hpp\"\n\nnamespace tools {\n\n  template <typename M,\
    \ typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs >\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6\
    \ \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 16 \"tools/pow_mod_cache.hpp\"\n\nnamespace tools\
    \ {\n\n  template <class M>\n  class pow_mod_cache {\n    ::std::vector<M> m_pow;\n\
    \    ::std::vector<M> m_cumsum;\n    ::std::vector<M> m_inv_pow;\n    ::std::vector<M>\
    \ m_inv_cumsum;\n    ::std::optional<::std::pair<long long, long long>> m_period;\n\
    \n  public:\n    pow_mod_cache() = default;\n    explicit pow_mod_cache(const\
    \ M base) : m_pow({M(1), base}), m_cumsum({M::raw(0)}), m_inv_pow({M(1)}), m_inv_cumsum({M::raw(0)})\
    \ {\n      if (base == M(-1)) {\n        if (M::mod() > 2) {\n          this->m_period\
    \ = ::std::make_pair(0LL, 2LL);\n        } else {\n          this->m_period =\
    \ ::std::make_pair(0LL, 1LL);\n          this->m_pow.resize(1);\n        }\n \
    \       this->m_inv_pow.clear();\n        this->m_inv_cumsum.clear();\n      }\n\
    \    }\n    template <typename Z, ::std::enable_if_t<::std::is_integral_v<Z>,\
    \ ::std::nullptr_t> = nullptr>\n    explicit pow_mod_cache(const Z base) : pow_mod_cache(M(base))\
    \ {\n    }\n\n    M operator[](const long long n) {\n      if (!this->m_period)\
    \ {\n        if (::std::max<long long>(::tools::ssize(this->m_pow) - 1, n) - ::std::min<long\
    \ long>(n, -(::tools::ssize(this->m_inv_pow) - 1)) + 1 < M::mod() - 1) {\n   \
    \       if (n >= 0) {\n            const long long size = ::tools::ssize(this->m_pow);\n\
    \            this->m_pow.resize(::std::max(size, n + 1));\n            for (long\
    \ long i = size; i < ::tools::ssize(this->m_pow); ++i) {\n              this->m_pow[i]\
    \ = this->m_pow[i - 1] * this->m_pow[1];\n            }\n            return this->m_pow[n];\n\
    \          } else {\n            if (this->m_inv_pow.size() == 1) {\n        \
    \      this->m_inv_pow.push_back(this->m_pow[1].inv());\n            }\n     \
    \       const long long size = ::tools::ssize(this->m_inv_pow);\n            this->m_inv_pow.resize(::std::max(size,\
    \ -n + 1));\n            for (long long i = size; i < ::tools::ssize(this->m_inv_pow);\
    \ ++i) {\n              this->m_inv_pow[i] = this->m_inv_pow[i - 1] * this->m_inv_pow[1];\n\
    \            }\n            return this->m_inv_pow[-n];\n          }\n       \
    \ }\n\n        this->m_period = ::tools::find_cycle(this->m_pow[0], [&](const\
    \ M& prev) { return prev * this->m_pow[1]; });\n        const long long size =\
    \ ::tools::ssize(this->m_pow);\n        this->m_pow.resize(this->m_period->first\
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
    \ n) - ::tools::ceil(l, n));\n      }\n    }\n  };\n}\n\n\n#line 1 \"tools/ceil_log2.hpp\"\
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
    \n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/sample_point_shift.hpp\"\
    \n\n\n\n#line 9 \"tools/sample_point_shift.hpp\"\n#include <initializer_list>\n\
    #line 1 \"tools/online_cumsum.hpp\"\n\n\n\n#line 1 \"tools/is_monoid.hpp\"\n\n\
    \n\n#line 6 \"tools/is_monoid.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename = void>\n  struct is_monoid : ::std::false_type {};\n\n  template\
    \ <typename M>\n  struct is_monoid<M, ::std::enable_if_t<\n    ::std::is_same_v<typename\
    \ M::T, decltype(M::op(::std::declval<typename M::T>(), ::std::declval<typename\
    \ M::T>()))> &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n  , void>>\
    \ : ::std::true_type {};\n\n  template <typename M>\n  inline constexpr bool is_monoid_v\
    \ = ::tools::is_monoid<M>::value;\n}\n\n\n#line 1 \"tools/group.hpp\"\n\n\n\n\
    namespace tools {\n  namespace group {\n    template <typename G>\n    struct\
    \ plus {\n      using T = G;\n      static T op(const T& lhs, const T& rhs) {\n\
    \        return lhs + rhs;\n      }\n      static T e() {\n        return T(0);\n\
    \      }\n      static T inv(const T& v) {\n        return -v;\n      }\n    };\n\
    \n    template <typename G>\n    struct multiplies {\n      using T = G;\n   \
    \   static T op(const T& lhs, const T& rhs) {\n        return lhs * rhs;\n   \
    \   }\n      static T e() {\n        return T(1);\n      }\n      static T inv(const\
    \ T& v) {\n        return e() / v;\n      }\n    };\n\n    template <typename\
    \ G>\n    struct bit_xor {\n      using T = G;\n      static T op(const T& lhs,\
    \ const T& rhs) {\n        return lhs ^ rhs;\n      }\n      static T e() {\n\
    \        return T(0);\n      }\n      static T inv(const T& v) {\n        return\
    \ v;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/is_group.hpp\"\n\n\n\n#line\
    \ 6 \"tools/is_group.hpp\"\n\nnamespace tools {\n\n  template <typename G, typename\
    \ = void>\n  struct is_group : ::std::false_type {};\n\n  template <typename G>\n\
    \  struct is_group<G, ::std::enable_if_t<\n    ::std::is_same_v<typename G::T,\
    \ decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename G::T>()))>\
    \ &&\n    ::std::is_same_v<typename G::T, decltype(G::e())> &&\n    ::std::is_same_v<typename\
    \ G::T, decltype(G::inv(::std::declval<typename G::T>()))>\n  , void>> : ::std::true_type\
    \ {};\n\n  template <typename G>\n  inline constexpr bool is_group_v = ::tools::is_group<G>::value;\n\
    }\n\n\n#line 11 \"tools/online_cumsum.hpp\"\n\nnamespace tools {\n  template <typename\
    \ X, bool Forward = true>\n  class online_cumsum {\n    using M = ::std::conditional_t<::tools::is_monoid_v<X>,\
    \ X, ::tools::group::plus<X>>;\n    using T = typename M::T;\n    ::std::vector<T>\
    \ m_vector;\n    ::std::vector<T> m_cumsum;\n    ::std::size_t m_processed;\n\n\
    \  public:\n    online_cumsum() : online_cumsum(0) {\n    }\n    online_cumsum(const\
    \ ::std::size_t n) : m_vector(n, M::e()), m_cumsum(n + 1, M::e()), m_processed(Forward\
    \ ? 0 : n) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_vector.size();\n\
    \    }\n    T& operator[](const ::std::size_t i) {\n      assert(i < this->size());\n\
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
    \ r);\n    }\n  };\n}\n\n\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#line 7 \"tools/monoid.hpp\"\
    \n\nnamespace tools {\n  namespace monoid {\n    template <typename M, M E = ::std::numeric_limits<M>::lowest()>\n\
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
    \    }\n\n    return c;\n}\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/garner3.hpp\"\
    \n\n\n\n#line 7 \"tools/garner3.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename M1, typename M2, typename M3>\n  M garner3(const M1& a, const M2&\
    \ b, const M3& c, const M m) {\n    using ull = unsigned long long;\n    static\
    \ const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n    static const M3 m1_m2_inv_mod_m3\
    \ = (M3::raw(M1::mod()) * M3::raw(M2::mod())).inv();\n\n    static const auto\
    \ plus_mod = [](ull x, const ull y, const ull mod) {\n      assert(x < mod);\n\
    \      assert(y < mod);\n\n      x += y;\n      if (x >= mod) x -= mod;\n    \
    \  return x; \n    };\n\n    assert(m >= 1);\n    assert(M1::mod() < M2::mod());\n\
    \    assert(M2::mod() < M3::mod());\n    assert(::tools::is_prime(M1::mod()));\n\
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
    \    return res;\n  }\n}\n\n\n#line 16 \"tools/large_fact_mod_cache.hpp\"\n\n\
    namespace tools {\n\n  template <class M>\n  class large_fact_mod_cache {\n  \
    \  int m_K;\n    ::std::vector<M> m_factbs;\n\n  public:\n    large_fact_mod_cache()\
    \ {\n      const long long P = M::mod();\n      assert(::tools::is_prime(P));\n\
    \      ::tools::pow_mod_cache<M> pow2(2);\n\n      long long K = 0;\n      const\
    \ long long Q = 200000;\n      for (; ::tools::ceil(P * ::tools::ceil_log2(P),\
    \ ::tools::pow2(K)) + Q * ::tools::pow2(K) > ::tools::ceil(P * ::tools::ceil_log2(P),\
    \ ::tools::pow2(K + 1)) + Q * ::tools::pow2(K + 1); ++K);\n      this->m_K = K;\n\
    \n      ::std::vector<M> f_im1{M(1)};\n      ::std::vector<M> f_i;\n      for\
    \ (int i = 1; i <= K; ++i, f_i.swap(f_im1)) {\n        ::tools::sample_point_shift(f_im1.begin(),\
    \ f_im1.end(), pow2[i - 1], 3 * ::tools::pow2(i - 1), ::std::back_inserter(f_im1));\n\
    \        f_i.resize(::tools::pow2(i));\n        for (int j = 0; j < ::tools::pow2(i);\
    \ ++j) {\n          f_i[j] = f_im1[2 * j] * f_im1[2 * j + 1] * pow2[i - 1] * (M(2)\
    \ * M(j) + M(1));\n        }\n      }\n\n      this->m_factbs = ::std::move(f_im1);\n\
    \      if (::tools::pow2(K) <= P / ::tools::pow2(K)) {\n        ::tools::sample_point_shift(this->m_factbs.begin(),\
    \ this->m_factbs.end(), pow2[K], P / ::tools::pow2(K) + 1 - ::tools::pow2(K),\
    \ ::std::back_inserter(this->m_factbs));\n      }\n      this->m_factbs.insert(this->m_factbs.begin(),\
    \ M(1));\n      for (int i = 1; i < ::tools::ssize(this->m_factbs); ++i) {\n \
    \       this->m_factbs[i] *= this->m_factbs[i - 1] * pow2[K] * M(i);\n      }\n\
    \    }\n\n    M fact(const long long nll) const {\n      assert(nll >= 0);\n \
    \     if (nll >= M::mod()) return M::raw(0);\n\n      const auto n = static_cast<int>(nll);\n\
    \      const auto prev = (n >> this->m_K) << this->m_K;\n      const auto next\
    \ = ((n >> this->m_K) + 1) << this->m_K;\n      if (n - prev <= ::std::min(next,\
    \ M::mod() - 1) - n) {\n        auto res = this->m_factbs[prev >> this->m_K];\n\
    \        int i;\n        for (M m(i = prev + 1); i <= n; ++i, ++m) {\n       \
    \   res *= m;\n        }\n        return res;\n      } else {\n        if (next\
    \ <= M::mod() - 1) {\n          auto res = this->m_factbs[next >> this->m_K].inv();\n\
    \          int i;\n          for (M m(i = n + 1); i <= next; ++i, ++m) {\n   \
    \         res *= m;\n          }\n          return res.inv();\n        } else\
    \ {\n          M res(-1);\n          int i;\n          for (M m(i = n + 1); i\
    \ < M::mod(); ++i, ++m) {\n            res *= m;\n          }\n          return\
    \ res.inv();\n        }\n      }\n    }\n\n    M binomial(long long n, long long\
    \ r) const {\n      if (r < 0) return M::raw(0);\n      if (0 <= n && n < r) return\
    \ M::raw(0);\n      if (n < 0) return M(1 - ((r & 1) << 1)) * this->binomial(-n\
    \ + r - 1, r);\n\n      const auto c = [&](const long long nn, const long long\
    \ rr) {\n        return 0 <= rr && rr <= nn ? this->fact(nn) / (this->fact(nn\
    \ - rr) * this->fact(rr)) : M::raw(0);\n      };\n\n      M result(1);\n     \
    \ while (n > 0 || r > 0) {\n        result *= c(n % M::mod(), r % M::mod());\n\
    \        n /= M::mod();\n        r /= M::mod();\n      }\n\n      return result;\n\
    \    }\n    M combination(const long long n, const long long r) const {\n    \
    \  if (!(0 <= r && r <= n)) return M::raw(0);\n      return this->binomial(n,\
    \ r);\n    }\n    M permutation(const long long n, const long long r) const {\n\
    \      if (!(0 <= r && r <= n)) return M::raw(0);\n      return this->binomial(n,\
    \ r) * this->fact(r);\n    }\n    M combination_with_repetition(const long long\
    \ n, const long long r) const {\n      if (n < 0 || r < 0) return M::raw(0);\n\
    \      return this->binomial(n + r - 1, r);\n    }\n  };\n}\n\n\n#line 1 \"tools/extended_lucas.hpp\"\
    \n\n\n\n#line 1 \"tools/int128_t.hpp\"\n\n\n\n#line 11 \"tools/int128_t.hpp\"\n\
    \nnamespace tools {\n  using int128_t = __int128;\n\n  constexpr ::tools::int128_t\
    \ abs(const ::tools::int128_t& x) {\n    return x < 0 ? -x : x;\n  }\n}\n\nconstexpr\
    \ inline ::tools::int128_t INT128_MAX = (::tools::int128_t(1) << 126) | ((::tools::int128_t(1)\
    \ << 126) - 1);\nconstexpr inline ::tools::int128_t INT128_MIN = -INT128_MAX -\
    \ 1;\n\n::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {\n\
    \  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  if (s == \"-170141183460469231731687303715884105728\"\
    ) {\n    x = INT128_MIN;\n    return is;\n  }\n\n  x = 0;\n  for (::std::size_t\
    \ i = s[0] == '+' || s[0] == '-'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  if (s[0] == '-')\
    \ x = -x;\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream& os,\
    \ ::tools::int128_t x) {\n  if (x == 0) return os << '0';\n  if (x == INT128_MIN)\
    \ return os << \"-170141183460469231731687303715884105728\";\n\n  ::std::string\
    \ s;\n  const bool negative = x < 0;\n\n  if (negative) x = -x;\n  while (x >\
    \ 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n\n  if (negative) s.push_back('-');\n\
    \  ::std::reverse(s.begin(), s.end());\n  return os << s;\n}\n\n\n#line 1 \"tools/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"tools/prime_factorization.hpp\"\n#include <queue>\n#line 1 \"\
    tools/floor_log2.hpp\"\n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 8 \"\
    tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  T popcount(T\
    \ x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x >= 0);\n   \
    \ if constexpr (::std::is_signed_v<T>) {\n      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n\
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
    \ 15 \"tools/prime_factorization.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  ::std::vector<T> prime_factorization(T n) {\n    assert(1 <= n && n <=\
    \ 1000000000000000000);\n    ::std::vector<T> result;\n\n    if (n == 1) return\
    \ result;\n\n    ::std::queue<::std::pair<T, T>> factors({::std::pair<T, T>(n,\
    \ 1)});\n    while (!factors.empty()) {\n      const T factor = factors.front().first;\n\
    \      const T occurrences = factors.front().second;\n      factors.pop();\n \
    \     if (::tools::is_prime(factor)) {\n        for (T i = 0; i < occurrences;\
    \ ++i) {\n          result.push_back(factor);\n        }\n      } else {\n   \
    \     const T m = ::tools::pow2((::tools::floor_log2(factor) + 1) / 8);\n    \
    \    for (T c = 1; ; ++c) {\n          const auto f = [&](T& x) {\n          \
    \  x = ::tools::prod_mod(x, x, factor);\n            x += c;\n            if (x\
    \ >= factor) x -= factor;\n          };\n          T y = 2;\n          T r = 1;\n\
    \          T q = 1;\n          T x, g, ys;\n          do {\n            x = y;\n\
    \            for (T i = 0; i < r; ++i) {\n              f(y);\n            }\n\
    \            T k = 0;\n            do {\n              ys = y;\n             \
    \ for (T i = 0; i < ::std::min(m, r - k); ++i) {\n                f(y);\n    \
    \            q = ::tools::prod_mod(q, ::std::abs(x - y), factor);\n          \
    \    }\n              g = ::std::gcd(q, factor);\n              k += m;\n    \
    \        } while (k < r && g == 1);\n            r *= 2;\n          } while (g\
    \ == 1);\n          if (g == factor) {\n            do {\n              f(ys);\n\
    \              g = ::std::gcd(::std::abs(x - ys), factor);\n            } while\
    \ (g == 1);\n          }\n          if (g < factor) {\n            T h = factor\
    \ / g;\n            if (h < g) ::std::swap(g, h);\n            T n = 1;\n    \
    \        while (h % g == 0) {\n              h /= g;\n              ++n;\n   \
    \         }\n            factors.emplace(g, occurrences * n);\n            if\
    \ (h > 1) factors.emplace(h, occurrences);\n            break;\n          }\n\
    \        }\n      }\n    }\n\n    ::std::sort(result.begin(), result.end());\n\
    \    return result;\n  }\n}\n\n\n#line 1 \"tools/run_length.hpp\"\n\n\n\n#line\
    \ 8 \"tools/run_length.hpp\"\n\nnamespace tools {\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void run_length(const InputIterator& begin, const\
    \ InputIterator& end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    if (begin == end) return;\n\n    ::std::pair<T, ::std::size_t> prev;\n  \
    \  for (auto [it, breaks] = ::std::make_pair(begin, false); !breaks; breaks =\
    \ it == end, it = ::std::next(it, breaks ? 0 : 1)) {\n      bool flg1, flg2;\n\
    \      if (it == begin) {\n        flg1 = false;\n        flg2 = true;\n     \
    \ } else if (it == end) {\n        flg1 = true;\n        flg2 = false;\n     \
    \ } else if (*it != prev.first) {\n        flg1 = true;\n        flg2 = true;\n\
    \      } else {\n        flg1 = false;\n        flg2 = false;\n      }\n     \
    \ if (flg1 || flg2) {\n        if (flg1) {\n          *result = prev;\n      \
    \    ++result;\n        }\n        if (flg2) {\n          prev.first = *it;\n\
    \          prev.second = 1;\n        }\n      } else {\n        ++prev.second;\n\
    \      }\n    }\n  }\n}\n\n\n#line 1 \"tools/garner.hpp\"\n\n\n\n#line 1 \"tools/inv_mod.hpp\"\
    \n\n\n\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#line 9 \"tools/extgcd.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r,\
    \ T r) {\n    const bool prev_r_is_neg = prev_r < T(0);\n    const bool r_is_neg\
    \ = r < T(0);\n\n    if (prev_r_is_neg) prev_r = -prev_r;\n    if (r_is_neg) r\
    \ = -r;\n\n    #ifndef NDEBUG\n    const T a = prev_r;\n    const T b = r;\n \
    \   #endif\n\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n    T t(1);\n \
    \   while (r != T(0)) {\n      const T q = prev_r / r;\n      ::std::tie(prev_r,\
    \ r) = ::std::make_pair(r, prev_r - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s,\
    \ prev_s - q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t -\
    \ q * t);\n    }\n\n    if (prev_r_is_neg) prev_s = -prev_s;\n    if (r_is_neg)\
    \ prev_t = -prev_t;\n\n    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r\
    \ / T(2), T(1)));\n    assert(::tools::abs(prev_t) <= ::std::max(a / prev_r /\
    \ T(2), T(1)));\n    return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n\
    }\n\n\n#line 7 \"tools/inv_mod.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2>\n  constexpr T2 inv_mod(const T1 x, const T2 m) {\n    const\
    \ auto [x0, y0, gcd] = ::tools::extgcd(x, m);\n    assert(gcd == 1);\n    return\
    \ ::tools::mod(x0, m);\n  }\n}\n\n\n#line 9 \"tools/garner.hpp\"\n\n// Source:\
    \ https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n// License: unknown\n//\
    \ Author: drken\n\nnamespace tools {\n\n  template <typename Iterator, typename\
    \ ModType>\n  ::std::pair<long long, long long> garner(const Iterator& begin,\
    \ const Iterator& end, const ModType& mod) {\n    ::std::vector<long long> b,\
    \ m;\n    for (auto it = begin; it != end; ++it) {\n      b.push_back(::tools::mod(it->first,\
    \ it->second));\n      m.push_back(it->second);\n    }\n\n    auto lcm = 1LL;\n\
    \    for (::std::size_t i = 0; i < b.size(); ++i) {\n      (lcm *= m[i]) %= mod;\n\
    \    }\n\n    m.push_back(mod);\n    ::std::vector<long long> coeffs(m.size(),\
    \ 1);\n    ::std::vector<long long> constants(m.size(), 0);\n    for (::std::size_t\
    \ k = 0; k < b.size(); ++k) {\n      long long t = ::tools::mod((b[k] - constants[k])\
    \ * ::tools::inv_mod(coeffs[k], m[k]), m[k]);\n      for (::std::size_t i = k\
    \ + 1; i < m.size(); ++i) {\n        (constants[i] += t * coeffs[i]) %= m[i];\n\
    \        (coeffs[i] *= m[k]) %= m[i];\n      }\n    }\n\n    return ::std::make_pair(constants.back(),\
    \ lcm);\n  }\n\n  template <typename M, typename Iterator>\n  ::std::pair<M, M>\
    \ garner(const Iterator& begin, const Iterator& end) {\n    const auto [y, z]\
    \ = ::tools::garner(begin, end, M::mod());\n    return ::std::make_pair(M::raw(y),\
    \ M::raw(z));\n  }\n}\n\n\n#line 12 \"tools/extended_lucas.hpp\"\n\n// Source:\
    \ https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html\n// License:\
    \ MIT\n// Author: hitonanode\n\n// MIT License\n// \n// Copyright (c) 2019 Ryotaro\
    \ Sato\n// \n// Permission is hereby granted, free of charge, to any person obtaining\
    \ a copy\n// of this software and associated documentation files (the \"Software\"\
    ), to deal\n// in the Software without restriction, including without limitation\
    \ the rights\n// to use, copy, modify, merge, publish, distribute, sublicense,\
    \ and/or sell\n// copies of the Software, and to permit persons to whom the Software\
    \ is\n// furnished to do so, subject to the following conditions:\n// \n// The\
    \ above copyright notice and this permission notice shall be included in all\n\
    // copies or substantial portions of the Software.\n// \n// THE SOFTWARE IS PROVIDED\
    \ \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED, INCLUDING BUT\
    \ NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS FOR A PARTICULAR\
    \ PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS OR COPYRIGHT\
    \ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY, WHETHER IN\
    \ AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF OR IN CONNECTION\
    \ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n// SOFTWARE.\n\nnamespace\
    \ tools {\n\n  template <class M>\n  class extended_lucas {\n    struct combination_prime_pow\
    \ {\n      int p, q, m;\n      ::std::vector<int> fac, invfac, ppow;\n\n     \
    \ long long ej(long long n) const {\n        long long ret = 0;\n        while\
    \ (n) ret += n, n /= this->p;\n        return ret;\n      }\n\n      combination_prime_pow(const\
    \ int p_, const int q_) : p(p_), q(q_), m(1), ppow{1} {\n        for (int t =\
    \ 0; t < this->q; ++t) this->m *= this->p, this->ppow.push_back(this->m);\n  \
    \      this->fac.assign(this->m, 1);\n        this->invfac.assign(this->m, 1);\n\
    \        for (int i = 1; i < this->m; ++i) this->fac[i] = static_cast<long long>(this->fac[i\
    \ - 1]) * (i % this->p ? i : 1) % this->m;\n        this->invfac[this->m - 1]\
    \ = this->fac[this->m - 1]; // Same as Wilson's theorem\n        assert(1LL *\
    \ this->fac.back() * this->invfac.back() % this->m == 1);\n        for (int i\
    \ = this->m - 1; i; --i) this->invfac[i - 1] = static_cast<long long>(this->invfac[i])\
    \ * (i % this->p ? i : 1) % this->m;\n      }\n\n      int fact(const long long\
    \ n) const {\n        assert(n >= 0);\n        const auto q0 = this->ej(n / this->p);\n\
    \        return q0 < this->q ? static_cast<long long>(this->fac[n]) * this->ppow[q0]\
    \ % this->m : 0;\n      }\n\n      int combination(long long n, long long r) const\
    \ {\n        assert(0 <= r && r <= n);\n        if (this->p == 2 && this->q ==\
    \ 1) return !((~n) & r); // Lucas\n        long long k = n - r;\n        const\
    \ long long e0 = this->ej(n / this->p) - this->ej(r / this->p) - this->ej(k /\
    \ this->p);\n        if (e0 >= q) return 0;\n\n        long long ret = this->ppow[e0];\n\
    \        if (this->q == 1) { // Lucas\n          while (n) {\n            ret\
    \ = ::tools::int128_t(ret) * this->fac[n % this->p] * this->invfac[r % this->p]\
    \ * this->invfac[k % this->p] % this->p;\n            n /= this->p, r /= this->p,\
    \ k /= this->p;\n          }\n          return static_cast<int>(ret);\n      \
    \  } else {\n          if ((p > 2 || q < 3) && (this->ej(n / this->m) - this->ej(r\
    \ / this->m) - this->ej(k / this->m)) & 1) ret = this->m - ret;\n          while\
    \ (n) {\n            ret = ::tools::int128_t(ret) * this->fac[n % this->m] * this->invfac[r\
    \ % this->m] * this->invfac[k % this->m] % this->m;\n            n /= this->p,\
    \ r /= this->p, k /= this->p;\n          }\n          return static_cast<int>(ret);\n\
    \        }\n      }\n    };\n\n    ::std::vector<combination_prime_pow> m_cpps;\n\
    \n  public:\n    extended_lucas() {\n      const auto prime_factors = ::tools::prime_factorization(M::mod());\n\
    \      ::std::vector<::std::pair<int, int>> distinct_prime_factors;\n      ::tools::run_length(prime_factors.begin(),\
    \ prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n      for\
    \ (const auto& [p, q] : distinct_prime_factors) {\n        this->m_cpps.emplace_back(p,\
    \ q);\n      }\n    }\n\n    M fact(const long long n) const {\n      assert(n\
    \ >= 0);\n      ::std::vector<::std::pair<int, int>> rs;\n      for (const auto&\
    \ cpp : this->m_cpps) rs.emplace_back(cpp.fact(n), cpp.m);\n      return ::tools::garner<M>(rs.begin(),\
    \ rs.end()).first;\n    }\n    M binomial(const long long n, const long long r)\
    \ const {\n      if (r < 0) return M::raw(0);\n      if (0 <= n && n < r) return\
    \ M::raw(0);\n      if (n < 0) return M((r & 1) ? -1 : 1) * this->binomial(-n\
    \ + r - 1, r);\n\n      ::std::vector<::std::pair<int, int>> rs;\n      for (const\
    \ auto& cpp : this->m_cpps) rs.emplace_back(cpp.combination(n, r), cpp.m);\n \
    \     return ::tools::garner<M>(rs.begin(), rs.end()).first;\n    }\n    M combination(const\
    \ long long n, const long long r) const {\n      if (!(0 <= r && r <= n)) return\
    \ M::raw(0);\n      return this->binomial(n, r);\n    }\n    M permutation(const\
    \ long long n, const long long r) const {\n      if (!(0 <= r && r <= n)) return\
    \ M::raw(0);\n      return this->binomial(n, r) * this->fact(r);\n    }\n    M\
    \ combination_with_repetition(const long long n, const long long r) const {\n\
    \      if (n < 0 || r < 0) return M::raw(0);\n      return this->binomial(n +\
    \ r - 1, r);\n    }\n  };\n}\n\n\n#line 1 \"tools/bell.hpp\"\n\n\n\n#line 1 \"\
    tools/stirling_2nd.hpp\"\n\n\n\n#line 1 \"tools/fps.hpp\"\n\n\n\n#line 1 \"tools/less_by_first.hpp\"\
    \n\n\n\n#line 5 \"tools/less_by_first.hpp\"\n\nnamespace tools {\n\n  class less_by_first\
    \ {\n  public:\n    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.first < y.first;\n\
    \    }\n  };\n}\n\n\n#line 19 \"tools/fps.hpp\"\n\n// Source: https://opt-cp.com/fps-implementation/\n\
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
    \      }\n      return res;\n    }\n    F& operator++() {\n      if (!this->empty())\
    \ ++(*this)[0];\n      return *this;\n    }\n    F operator++(int) {\n      const\
    \ auto self = *this;\n      ++*this;\n      return self;\n    }\n    F& operator--()\
    \ {\n      if (!this->empty()) --(*this)[0];\n      return *this;\n    }\n   \
    \ F operator--(int) {\n      const auto self = *this;\n      --*this;\n      return\
    \ self;\n    }\n    F& operator*=(const M& g) {\n      for (auto& e : *this) {\n\
    \        e *= g;\n      }\n      return *this;\n    }\n    F& operator/=(const\
    \ M& g) {\n      assert(::std::gcd(g.val(), M::mod()) == 1);\n      *this *= g.inv();\n\
    \      return *this;\n    }\n    F& operator+=(const F& g) {\n      const int\
    \ n = this->size();\n      const int m = g.size();\n      for (int i = 0; i <\
    \ ::std::min(n, m); ++i) {\n        (*this)[i] += g[i];\n      }\n      return\
    \ *this;\n    }\n    F& operator-=(const F& g) {\n      const int n = this->size();\n\
    \      const int m = g.size();\n      for (int i = 0; i < ::std::min(n, m); ++i)\
    \ {\n        (*this)[i] -= g[i];\n      }\n      return *this;\n    }\n    F&\
    \ operator<<=(const int d) {\n      if (d < 0) *this >>= -d;\n\n      const int\
    \ n = this->size();\n      this->resize(::std::max(0, n - d));\n      this->insert(this->begin(),\
    \ ::std::min(n, d), M::raw(0));\n      return *this;\n    }\n    F& operator>>=(const\
    \ int d) {\n      if (d < 0) *this <<= -d;\n\n      const int n = this->size();\n\
    \      this->erase(this->begin(), this->begin() + ::std::min(n, d));\n      this->resize(n);\n\
    \      return *this;\n    }\n    F& multiply_inplace(const F& g, const int d)\
    \ {\n      assert(d >= 0);\n      const int n = this->size();\n      F res;\n\
    \      ::tools::convolution(this->cbegin(), this->cbegin() + ::std::min(d, n),\
    \ g.cbegin(), g.cbegin() + ::std::min<int>(d, g.size()), ::std::back_inserter(res));\n\
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
    \ this->end(), M::raw(0));\n        return *this;\n      }\n\n      auto [d, c]\
    \ = *g_begin;\n      if (d == 0) {\n        ++g_begin;\n      } else {\n     \
    \   c = M::raw(0);\n      }\n      for (int i = n - 1; i >= 0; --i) {\n      \
    \  (*this)[i] *= c;\n        for (auto it = g_begin; it != g_end; ++it) {\n  \
    \        const auto& [j, b] = *it;\n          if (j > i) break;\n          (*this)[i]\
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
    \ 0 && ::std::gcd(c.val(), M::mod()) == 1);\n      const M ic = c.inv();\n   \
    \   ++g_begin;\n      for (int i = 0; i < n; ++i) {\n        for (auto it = g_begin;\
    \ it != g_end; ++it) {\n          const auto& [j, b] = *it;\n          if (j >\
    \ i) break;\n          (*this)[i] -= (*this)[i - j] * b;\n        }\n        (*this)[i]\
    \ *= ic;\n      }\n      return *this;\n    }\n    F& divide_inplace(const ::std::initializer_list<::std::pair<int,\
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
    \ }\n\n    F operator()(const F& g) const {\n      assert(g.empty() || g[0] ==\
    \ M::raw(0));\n\n      const int n = this->size();\n      F h(n);\n      if (n\
    \ == 0) return h;\n\n      const int m = g.size();\n      int l;\n      for (l\
    \ = 0; l < ::std::min(m, n) && g[l] == M::raw(0); ++l);\n      h[0] = (*this)[0];\n\
    \      if (l == ::std::min(m, n)) return h;\n\n      const F g_1(g.begin() + l,\
    \ g.begin() + ::std::min(m, n));\n      for (int i = l; i < ::std::min(m, n);\
    \ ++i) {\n        h[i] += (*this)[1] * g[i];\n      }\n\n      auto g_k = g_1;\n\
    \      for (int k = 2, d; (d = ::std::min(k * (m - l - 1) + 1, n - l * k)) > 0;\
    \ ++k) {\n        g_k.multiply_inplace(g_1, d);\n        for (int i = l * k; i\
    \ < l * k + d; ++i) {\n          h[i] += (*this)[k] * g_k[i - l * k];\n      \
    \  }\n      }\n\n      return h;\n    }\n    F compositional_inverse() const {\n\
    \      assert(this->size() >= 2);\n      assert((*this)[0] == M::raw(0));\n  \
    \    assert(::std::gcd((*this)[1].val(), M::mod()) == 1);\n\n      const int n\
    \ = this->size();\n      ::std::vector<F> f;\n      f.reserve(::std::max(2, n\
    \ - 1));\n      f.emplace_back(n);\n      f[0][0] = M::raw(1);\n      f.push_back(*this);\n\
    \      for (int i = 2; i < n - 1; ++i) {\n        f.push_back(f.back() * f[1]);\n\
    \      }\n\n      ::std::vector<M> invpow_f11;\n      invpow_f11.reserve(n);\n\
    \      invpow_f11.push_back(M::raw(1));\n      invpow_f11.push_back(f[1][1].inv());\n\
    \      for (int i = 2; i < n; ++i) {\n        invpow_f11.push_back(invpow_f11.back()\
    \ * invpow_f11[1]);\n      }\n\n      F g(n);\n      g[1] = invpow_f11[1];\n \
    \     for (int i = 2; i < n; ++i) {\n        for (int j = 1; j < i; ++j) {\n \
    \         g[i] -= f[j][i] * g[j];\n        }\n        g[i] *= invpow_f11[i];\n\
    \      }\n\n      return g;\n    }\n\n    friend F operator*(const F& f, const\
    \ M& g) { return F(f) *= g; }\n    friend F operator*(const M& f, const F& g)\
    \ { return F(g) *= f; }\n    friend F operator/(const F& f, const M& g) { return\
    \ F(f) /= g; }\n    friend F operator+(const F& f, const F& g) { return F(f) +=\
    \ g; }\n    friend F operator-(const F& f, const F& g) { return F(f) -= g; }\n\
    \    friend F operator*(const F& f, const F& g) { return F(f) *= g; }\n    friend\
    \ F operator/(const F& f, const F& g) { return F(f) /= g; }\n    friend F operator<<(const\
    \ F& f, const int d) { return F(f) <<= d; }\n    friend F operator>>(const F&\
    \ f, const int d) { return F(f) >>= d; }\n  };\n}\n\n\n#line 1 \"tools/virtual_vector.hpp\"\
    \n\n\n\n#line 6 \"tools/virtual_vector.hpp\"\n#include <memory>\n#line 10 \"tools/virtual_vector.hpp\"\
    \n\nnamespace tools {\n  template <typename F>\n  class virtual_vector {\n  public:\n\
    \    using size_type = ::std::size_t;\n\n    class iterator {\n      const virtual_vector<F>\
    \ *m_parent;\n      size_type m_i;\n\n    public:\n      using reference = decltype(::std::declval<F>()(::std::declval<size_type>()));\n\
    \      using value_type = ::std::remove_const_t<::std::remove_reference_t<reference>>;\n\
    \      using difference_type = ::std::ptrdiff_t;\n      using pointer = const\
    \ value_type*;\n      using iterator_category = ::std::random_access_iterator_tag;\n\
    \n      iterator() = default;\n      iterator(const virtual_vector<F> * const\
    \ parent, const size_type i) : m_parent(parent), m_i(i) {\n      }\n\n      reference\
    \ operator*() const {\n        return (*this->m_parent)[this->m_i];\n      }\n\
    \      pointer operator->() const {\n        return &(*(*this));\n      }\n\n\
    \      iterator& operator++() {\n        ++this->m_i;\n        return *this;\n\
    \      }\n      iterator operator++(int) {\n        const auto self = *this;\n\
    \        ++*this;\n        return self;\n      }\n      iterator& operator--()\
    \ {\n        --this->m_i;\n        return *this;\n      }\n      iterator operator--(int)\
    \ {\n        const auto self = *this;\n        --*this;\n        return self;\n\
    \      }\n      iterator& operator+=(const difference_type n) {\n        this->m_i\
    \ += n;\n        return *this;\n      }\n      iterator& operator-=(const difference_type\
    \ n) {\n        this->m_i -= n;\n        return *this;\n      }\n      friend\
    \ iterator operator+(const iterator self, const difference_type n) {\n       \
    \ return iterator(self.m_parent, self.m_i + n);\n      }\n      friend iterator\
    \ operator+(const difference_type n, const iterator self) {\n        return self\
    \ + n;\n      }\n      friend iterator operator-(const iterator self, const difference_type\
    \ n) {\n        return iterator(self.m_parent, self.m_i - n);\n      }\n     \
    \ friend difference_type operator-(const iterator lhs, const iterator rhs) {\n\
    \        assert(lhs.m_parent == rhs.m_parent);\n        return static_cast<difference_type>(lhs.m_i)\
    \ - static_cast<difference_type>(rhs.m_i);\n      }\n      reference operator[](const\
    \ difference_type n) const {\n        return *(*this + n);\n      }\n\n      friend\
    \ bool operator==(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i == rhs.m_i;\n      }\n      friend\
    \ bool operator!=(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i != rhs.m_i;\n      }\n      friend\
    \ bool operator<(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i < rhs.m_i;\n      }\n      friend\
    \ bool operator<=(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i <= rhs.m_i;\n      }\n      friend\
    \ bool operator>(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i > rhs.m_i;\n      }\n      friend\
    \ bool operator>=(const iterator lhs, const iterator rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i >= rhs.m_i;\n      }\n    };\n\n \
    \   using const_reference = decltype(::std::declval<F>()(::std::declval<size_type>()));\n\
    \    using value_type = ::std::remove_const_t<::std::remove_reference_t<const_reference>>;\n\
    \    using reference = value_type&;\n    using const_iterator = iterator;\n  \
    \  using difference_type = ::std::ptrdiff_t;\n    using allocator_type = ::std::allocator<value_type>;\n\
    \    using pointer = value_type*;\n    using const_pointer = const value_type*;\n\
    \    using reverse_iterator = ::std::reverse_iterator<iterator>;\n    using const_reverse_iterator\
    \ = ::std::reverse_iterator<const_iterator>;\n\n  private:\n    size_type m_size;\n\
    \    F m_selector;\n\n  public:\n    virtual_vector() = default;\n    virtual_vector(const\
    \ size_type n, const F& selector) : m_size(n), m_selector(selector) {\n    }\n\
    \n    iterator begin() noexcept { return iterator(this, 0); }\n    const_iterator\
    \ begin() const noexcept { return const_iterator(this, 0); }\n    const_iterator\
    \ cbegin() const noexcept { return const_iterator(this, 0); }\n    iterator end()\
    \ noexcept { return iterator(this, this->size()); }\n    const_iterator end()\
    \ const noexcept { return const_iterator(this, this->size()); }\n    const_iterator\
    \ cend() const noexcept { return const_iterator(this, this->size()); }\n    reverse_iterator\
    \ rbegin() noexcept { return ::std::make_reverse_iterator(this->end()); }\n  \
    \  const_reverse_iterator rbegin() const noexcept { return ::std::make_reverse_iterator(this->end());\
    \ }\n    const_reverse_iterator crbegin() const noexcept { return ::std::make_reverse_iterator(this->cend());\
    \ }\n    reverse_iterator rend() noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator rend() const noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator crend() const noexcept { return ::std::make_reverse_iterator(this->cbegin());\
    \ }\n\n    size_type size() const noexcept { return this->m_size; }\n    bool\
    \ empty() const noexcept { return this->size() == 0; }\n\n    const_reference\
    \ operator[](const size_type n) const { assert(n < this->size()); return this->m_selector(n);\
    \ }\n    const_reference at(const size_type n) const { return (*this)[n]; }\n\
    \    const_reference front() const { return *this->begin(); }\n    const_reference\
    \ back() const { return *this->rbegin(); }\n\n    template <typename G>\n    friend\
    \ bool operator==(const virtual_vector<F>& x, const virtual_vector<G>& y) { return\
    \ ::std::equal(x.begin(), x.end(), y.begin(), y.end()); }\n    template <typename\
    \ G>\n    friend bool operator!=(const virtual_vector<F>& x, const virtual_vector<G>&\
    \ y) { return !(x == y); }\n    template <typename G>\n    friend bool operator<(const\
    \ virtual_vector<F>& x, const virtual_vector<G>& y) { return ::std::lexicographical_compare(x.begin(),\
    \ x.end(), y.begin(), y.end()); }\n    template <typename G>\n    friend bool\
    \ operator<=(const virtual_vector<F>& x, const virtual_vector<G>& y) { return\
    \ !(x > y); }\n    template <typename G>\n    friend bool operator>(const virtual_vector<F>&\
    \ x, const virtual_vector<G>& y) { return y < x; }\n    template <typename G>\n\
    \    friend bool operator>=(const virtual_vector<F>& x, const virtual_vector<G>&\
    \ y) { return !(x < y); }\n  };\n}\n\n\n#line 12 \"tools/stirling_2nd.hpp\"\n\n\
    namespace tools {\n\n  namespace stirling_2nd {\n\n    template <typename M>\n\
    \    auto fixed_n(const int N, const int K) {\n      assert(::tools::is_prime(M::mod()));\n\
    \      assert(0 <= ::std::min(N, K) && ::std::min(N, K) < M::mod());\n\n     \
    \ ::tools::fact_mod_cache<M> cache;\n      ::tools::pow_mod_cache<M> pow_m1(-1);\n\
    \      ::tools::fps<M> a, b;\n      for (int i = 0; i <= ::std::min(N, K); ++i)\
    \ {\n        a.push_back(M(i).pow(N) * cache.fact_inv(i));\n        b.push_back(pow_m1[i]\
    \ * cache.fact_inv(i));\n      }\n      a.multiply_inplace(b);\n\n      return\
    \ ::tools::virtual_vector(K + 1, [N, a](const int k) -> const M& {\n        static\
    \ const auto zero = M::raw(0);\n        return k <= N ? a[k] : zero;\n      });\n\
    \    }\n\n    template <typename M>\n    auto fixed_k(const int N, const int K)\
    \ {\n      assert(::tools::is_prime(M::mod()));\n      assert(N >= 0);\n     \
    \ assert(0 <= K && K < M::mod());\n      assert(N - K + 1 < M::mod());\n\n   \
    \   ::tools::fps<M> f(::std::max(0, N - K + 1));\n      if (!f.empty()) {\n  \
    \      ::tools::fact_mod_cache<M> cache;\n        for (int i = 0; i <= N - K;\
    \ ++i) {\n          f[i] = cache.fact_inv(i + 1);\n        }\n        f.pow_inplace(K);\n\
    \        f *= cache.fact_inv(K);\n        for (int n = K; n <= N; ++n) {\n   \
    \       f[n - K] *= cache.fact(n);\n        }\n      }\n\n      return ::tools::virtual_vector(N\
    \ + 1, [K, f](const int n) -> const M& {\n        static const auto zero = M::raw(0);\n\
    \        return n < K ? zero : f[n - K];\n      });\n    }\n\n    template <typename\
    \ M>\n    auto diagonal(const int N) {\n      assert(N >= 0);\n\n      return\
    \ ::tools::virtual_vector(N + 1, [](const int n) -> const M& {\n        static\
    \ const M one(1);\n        return one;\n      });\n    }\n\n    template <typename\
    \ M>\n    ::std::vector<::std::vector<M>> all(const int N, const int K) {\n  \
    \    assert(N >= 0);\n      assert(K >= 0);\n      ::std::vector<::std::vector<M>>\
    \ S(N + 1);\n      S[0].emplace_back(1);\n      S[0].insert(S[0].end(), K, M::raw(0));\n\
    \      for (int n = 1; n <= N; ++n) {\n        S[n].resize(K + 1, M::raw(0));\n\
    \        for (int k = 0; k <= ::std::min(n, K); ++k) {\n          if (k > 0) S[n][k]\
    \ += S[n - 1][k - 1];\n          S[n][k] += M(k) * S[n - 1][k];\n        }\n \
    \     }\n      return S;\n    }\n  }\n}\n\n\n#line 14 \"tools/bell.hpp\"\n\nnamespace\
    \ tools {\n\n  namespace bell {\n\n    template <typename M>\n    auto fixed_n(const\
    \ int N, const int K) {\n      assert(::tools::is_prime(M::mod()));\n      assert(0\
    \ <= ::std::min(N, K) && ::std::min(N, K) < M::mod());\n\n      const auto S_N\
    \ = ::tools::stirling_2nd::fixed_n<M>(N, K);\n      ::std::vector<M> B_N;\n  \
    \    ::std::partial_sum(S_N.begin(), ::std::next(S_N.begin(), ::std::min(N, K)\
    \ + 1), ::std::back_inserter(B_N));\n\n      return ::tools::virtual_vector(K\
    \ + 1, [N, B_N](const int k) -> const M& {\n        return B_N[::std::min(N, k)];\n\
    \      });\n    }\n\n    template <typename M>\n    ::std::vector<M> diagonal(const\
    \ int N) {\n      assert(::tools::is_prime(M::mod()));\n      assert(0 <= N &&\
    \ N < M::mod());\n\n      ::tools::fact_mod_cache<M> cache;\n      ::tools::fps<M>\
    \ f(N + 1);\n      for (int i = 1; i <= N; ++i) f[i] = cache.fact_inv(i);\n  \
    \    f.exp_inplace();\n      for (int n = 0; n <= N; ++n) f[n] *= cache.fact(n);\n\
    \n      return ::std::vector<M>(f.begin(), f.end());\n    }\n\n    template <typename\
    \ M>\n    ::std::vector<::std::vector<M>> all(const int N, const int K) {\n  \
    \    assert(N >= 0);\n      assert(K >= 0);\n\n      auto res = ::tools::stirling_2nd::all<M>(N,\
    \ K);\n      for (int n = 0; n <= N; ++n) {\n        for (int k = 1; k <= K; ++k)\
    \ {\n          res[n][k] += res[n][k - 1];\n        }\n      }\n\n      return\
    \ res;\n    }\n  }\n}\n\n\n#line 1 \"tools/partition_function.hpp\"\n\n\n\n#line\
    \ 7 \"tools/partition_function.hpp\"\n\nnamespace tools {\n\n  namespace partition_function\
    \ {\n    template <typename M>\n    ::std::vector<M> diagonal(const int N) {\n\
    \      assert(N >= 0);\n\n      ::tools::fps<M> p(N + 1);\n\n      ++p[0];\n \
    \     for (int k = 1; k * (3 * k + 1) / 2 <= N; k += 2) --p[k * (3 * k + 1) /\
    \ 2];\n      for (int k = 2; k * (3 * k + 1) / 2 <= N; k += 2) ++p[k * (3 * k\
    \ + 1) / 2];\n      for (int k = 1; k * (3 * k - 1) / 2 <= N; k += 2) --p[k *\
    \ (3 * k - 1) / 2];\n      for (int k = 2; k * (3 * k - 1) / 2 <= N; k += 2) ++p[k\
    \ * (3 * k - 1) / 2];\n      p = p.inv();\n\n      return ::std::vector<M>(p.begin(),\
    \ p.end());\n    }\n\n    template <typename M>\n    ::std::vector<::std::vector<M>>\
    \ all(const int N, const int K) {\n      assert(N >= 0);\n      assert(K >= 0);\n\
    \n      auto dp = ::std::vector(N + 1, ::std::vector<M>(K + 1, M::raw(0)));\n\n\
    \      dp[0][0] = M(1);\n      for (int i = 0; i <= N; ++i) {\n        for (int\
    \ j = !i; j <= K; ++j) {\n          if (j > 0) dp[i][j] += dp[i][j - 1];\n   \
    \       if (i >= j) dp[i][j] += dp[i - j][j];\n        }\n      }\n\n      return\
    \ dp;\n    }\n  }\n}\n\n\n#line 14 \"tools/twelvefold_way.hpp\"\n\nnamespace tools\
    \ {\n  template <bool labels_ball, bool labels_box>\n  struct twelvefold_way {};\n\
    \n  template <>\n  struct twelvefold_way<true, true> {\n    twelvefold_way() =\
    \ delete;\n\n    template <typename M>\n    static M at_most_1(const long long\
    \ N, const long long K) {\n      assert(N >= 0);\n      assert(K >= 0);\n\n  \
    \    if (K < N) {\n        // O(1)\n        return M::raw(0);\n      } else {\n\
    \        if (::tools::is_prime(M::mod())) {\n          if (::std::min<long long>(K,\
    \ M::mod()) <= 10000000) {\n            // O(min(K, P) + log K / log P)\n    \
    \        ::tools::fact_mod_cache<M> cache;\n            return cache.permutation(K,\
    \ N);\n          } else {\n            // O(sqrt(P log P) + sqrt(P / log P) log\
    \ K)\n            ::tools::large_fact_mod_cache<M> cache;\n            return\
    \ cache.permutation(K, N);\n          }\n        } else {\n          // O(M +\
    \ (log M / log log M) log K)\n          ::tools::extended_lucas<M> cache;\n  \
    \        return cache.permutation(K, N);\n        }\n      }\n    }\n\n    template\
    \ <typename M>\n    static M unrestricted(const long long N, const long long K)\
    \ {\n      assert(N >= 0);\n      assert(K >= 0);\n\n      // O(log N)\n     \
    \ return M(K).pow(N);\n    }\n\n    template <typename M>\n    static M at_least_1(const\
    \ long long N, const long long K) {\n      assert(N >= 0);\n      assert(K >=\
    \ 0);\n\n      if (N < K) {\n        // O(1)\n        return M::raw(0);\n    \
    \  } else {\n        if (::tools::is_prime(M::mod())) {\n          // O(K log\
    \ N)\n          ::tools::fact_mod_cache<M> cache;\n          ::tools::pow_mod_cache<M>\
    \ pow_m1(-1);\n          auto res = M::raw(0);\n          for (int i = 0; i <=\
    \ K; ++i) {\n            res += pow_m1[K - i] * cache.combination(K, i) * M(i).pow(N);\n\
    \          }\n          return res;\n        } else {\n          if (N <= 10000000\
    \ / K) {\n            // O(NK)\n            ::tools::fact_mod_cache<M> cache;\n\
    \            auto res = ::tools::stirling_2nd::all<M>(N, K)[N][K];\n         \
    \   int i;\n            for (M k(i = 1); i <= K; ++i, ++k) {\n              res\
    \ *= k;\n            }\n            return res;\n          } else {\n        \
    \    // O(M + K ((log M / log log M) log K + (log M / log log M)^2 + log N))\n\
    \            ::tools::extended_lucas<M> cache;\n            ::tools::pow_mod_cache<M>\
    \ pow_m1(-1);\n            auto res = M::raw(0);\n            for (int i = 0;\
    \ i <= K; ++i) {\n              res += pow_m1[K - i] * cache.combination(K, i)\
    \ * M(i).pow(N);\n            }\n            return res;\n          }\n      \
    \  }\n      }\n    }\n  };\n\n  template <>\n  struct twelvefold_way<false, true>\
    \ {\n    twelvefold_way() = delete;\n\n    template <typename M>\n    static M\
    \ at_most_1(const long long N, const long long K) {\n      assert(N >= 0);\n \
    \     assert(K >= 0);\n\n      if (K < N) {\n        // O(1)\n        return M::raw(0);\n\
    \      } else {\n        if (::tools::is_prime(M::mod())) {\n          if (std::min<long\
    \ long>(K, M::mod()) <= 10000000) {\n            // O(min(K, P) + log K / log\
    \ P)\n            ::tools::fact_mod_cache<M> cache;\n            return cache.combination(K,\
    \ N);\n          } else {\n            // O(sqrt(P log P) + sqrt(P / log P) log\
    \ K)\n            ::tools::large_fact_mod_cache<M> cache;\n            return\
    \ cache.combination(K, N);\n          }\n        } else {\n          // O(M +\
    \ (log M / log log M) log K)\n          ::tools::extended_lucas<M> cache;\n  \
    \        return cache.combination(K, N);\n        }\n      }\n    }\n\n    template\
    \ <typename M>\n    static M unrestricted(const long long N, const long long K)\
    \ {\n      assert(N >= 0);\n      assert(K >= 0);\n\n      if (::tools::is_prime(M::mod()))\
    \ {\n        if (std::min<long long>(N + K, M::mod()) <= 10000000) {\n       \
    \   // O(min(N + K, P) + log (N + K) / log P)\n          ::tools::fact_mod_cache<M>\
    \ cache;\n          return cache.combination_with_repetition(K, N);\n        }\
    \ else {\n          // O(sqrt(P log P) + sqrt(P / log P) log (N + K))\n      \
    \    ::tools::large_fact_mod_cache<M> cache;\n          return cache.combination_with_repetition(K,\
    \ N);\n        }\n      } else {\n        // O(M + (log M / log log M) log (N\
    \ + K))\n        ::tools::extended_lucas<M> cache;\n        return cache.combination_with_repetition(K,\
    \ N);\n      }\n    }\n\n    template <typename M>\n    static M at_least_1(const\
    \ long long N, const long long K) {\n      assert(N >= 0);\n      assert(K >=\
    \ 0);\n\n      if (N < K) {\n        // O(1)\n        return M::raw(0);\n    \
    \  } else {\n        if (::tools::is_prime(M::mod())) {\n          if (std::min<long\
    \ long>(N, M::mod()) <= 10000000) {\n            // O(min(N, P) + log N / log\
    \ P)\n            ::tools::fact_mod_cache<M> cache;\n            return cache.binomial(N\
    \ - 1, N - K);\n          } else {\n            // O(sqrt(P log P) + sqrt(P /\
    \ log P) log N)\n            ::tools::large_fact_mod_cache<M> cache;\n       \
    \     return cache.binomial(N - 1, N - K);\n          }\n        } else {\n  \
    \        // O(M + (log M / log log M) log N)\n          ::tools::extended_lucas<M>\
    \ cache;\n          return cache.binomial(N - 1, N - K);\n        }\n      }\n\
    \    }\n  };\n\n  template <>\n  struct twelvefold_way<true, false> {\n    twelvefold_way()\
    \ = delete;\n\n    template <typename M>\n    static M at_most_1(const long long\
    \ N, const long long K) {\n      assert(N >= 0);\n      assert(K >= 0);\n\n  \
    \    // O(1)\n      return M(N <= K);\n    }\n\n    template <typename M>\n  \
    \  static M unrestricted(const long long N, const long long K) {\n      assert(N\
    \ >= 0);\n      assert(K >= 0);\n\n      if (::tools::is_prime(M::mod()) && ::std::min(N,\
    \ K) < M::mod()) {\n        // O(min(N, K) log N)\n        return ::tools::bell::fixed_n<M>(N,\
    \ K)[K];\n      } else {\n        // O(NK)\n        return ::tools::bell::all<M>(N,\
    \ K)[N][K];\n      }\n    }\n\n    template <typename M>\n    static M at_least_1(const\
    \ long long N, const long long K) {\n      assert(N >= 0);\n      assert(K >=\
    \ 0);\n\n      if (N < K) {\n        // O(1)\n        return M::raw(0);\n    \
    \  } else {\n        if (::tools::is_prime(M::mod()) && K < M::mod()) {\n    \
    \      // O(K \\log N)\n          return ::tools::stirling_2nd::fixed_n<M>(N,\
    \ K)[K];\n        } else {\n          // O(NK)\n          return ::tools::stirling_2nd::all<M>(N,\
    \ K)[N][K];\n        }\n      }\n    }\n  };\n\n  template <>\n  struct twelvefold_way<false,\
    \ false> {\n    twelvefold_way() = delete;\n\n    template <typename M>\n    static\
    \ M at_most_1(const long long N, const long long K) {\n      assert(N >= 0);\n\
    \      assert(K >= 0);\n\n      // O(1)\n      return M(N <= K);\n    }\n\n  \
    \  template <typename M>\n    static M unrestricted(const long long N, const long\
    \ long K) {\n      assert(N >= 0);\n      assert(K >= 0);\n\n      if (N == K)\
    \ {\n        // O(N log N)\n        return ::tools::partition_function::diagonal<M>(N)[N];\n\
    \      } else {\n        // O(N min(N, K))\n        return ::tools::partition_function::all<M>(N,\
    \ ::std::min(N, K))[N][::std::min(N, K)];\n      }\n    }\n\n    template <typename\
    \ M>\n    static M at_least_1(const long long N, const long long K) {\n      assert(N\
    \ >= 0);\n      assert(K >= 0);\n\n      if (N < K) {\n        // O(1)\n     \
    \   return M::raw(0);\n      } else if (N == 2 * K) {\n        // O(K log K)\n\
    \        return ::tools::partition_function::diagonal<M>(K)[K];\n      } else\
    \ {\n        // O((N - K) min(N - K, K))\n        return ::tools::partition_function::all<M>(N\
    \ - K, ::std::min(N - K, K))[N - K][::std::min(N - K, K)];\n      }\n    }\n \
    \ };\n}\n\n\n#line 6 \"tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp\"\
    \n\nusing mint = atcoder::modint1000000007;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int n, k;\n  std::cin >> n >> k;\n\
    \  std::cout << tools::twelvefold_way<true, true>::unrestricted<mint>(n, k).val()\
    \ << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_A\"\n\n\
    #include <iostream>\n#include \"atcoder/modint.hpp\"\n#include \"tools/twelvefold_way.hpp\"\
    \n\nusing mint = atcoder::modint1000000007;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int n, k;\n  std::cin >> n >> k;\n\
    \  std::cout << tools::twelvefold_way<true, true>::unrestricted<mint>(n, k).val()\
    \ << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/twelvefold_way.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/fact_mod_cache.hpp
  - tools/ssize.hpp
  - tools/large_fact_mod_cache.hpp
  - tools/pow_mod_cache.hpp
  - tools/find_cycle.hpp
  - tools/floor.hpp
  - tools/ceil.hpp
  - tools/ceil_log2.hpp
  - tools/pow2.hpp
  - tools/sample_point_shift.hpp
  - tools/online_cumsum.hpp
  - tools/is_monoid.hpp
  - tools/group.hpp
  - tools/is_group.hpp
  - tools/monoid.hpp
  - tools/convolution.hpp
  - tools/garner3.hpp
  - tools/extended_lucas.hpp
  - tools/int128_t.hpp
  - tools/prime_factorization.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/run_length.hpp
  - tools/garner.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  - tools/bell.hpp
  - tools/stirling_2nd.hpp
  - tools/fps.hpp
  - tools/less_by_first.hpp
  - tools/virtual_vector.hpp
  - tools/partition_function.hpp
  isVerificationFile: true
  path: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 15:33:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
layout: document
redirect_from:
- /verify/tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
- /verify/tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp.html
title: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
---
