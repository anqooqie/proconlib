---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/hld.hpp
    title: Heavy-light decomposition
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"tests/hld.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <cstdint>\n#include <utility>\n#include <iostream>\n#include <vector>\n\
    #line 1 \"lib/ac-library/atcoder/modint.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <numeric>\n#include <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\n#line 1 \"lib/ac-library/atcoder/internal_math.hpp\"\n\n\n\n#line 5\
    \ \"lib/ac-library/atcoder/internal_math.hpp\"\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param m `1 <= m`\n\
    // @return x mod m\nconstexpr long long safe_mod(long long x, long long m) {\n\
    \    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n// Fast modular multiplication\
    \ by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"lib/ac-library/atcoder/segtree.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 7 \"lib/ac-library/atcoder/segtree.hpp\"\n\
    \n#line 1 \"lib/ac-library/atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint\
    \ ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n)\
    \ {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n//\
    \ @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x))\
    \ != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9\
    \ \"lib/ac-library/atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n    segtree() : segtree(0)\
    \ {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n      \
    \  for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p +\
    \ size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r ==\
    \ 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n      \
    \      r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"tools/hld.hpp\"\n\n\n\n#line 5 \"tools/hld.hpp\"\n#include\
    \ <cstddef>\n#line 8 \"tools/hld.hpp\"\n#include <limits>\n#include <stack>\n\
    #line 11 \"tools/hld.hpp\"\n#include <iterator>\n#line 1 \"lib/ac-library/atcoder/dsu.hpp\"\
    \n\n\n\n#line 7 \"lib/ac-library/atcoder/dsu.hpp\"\n\nnamespace atcoder {\n\n\
    // Implement (union by size) + (path compression)\n// Reference:\n// Zvi Galil\
    \ and Giuseppe F. Italiano,\n// Data structures and algorithms for disjoint set\
    \ union problems\nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n    explicit\
    \ dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\n    int merge(int a, int b)\
    \ {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n  \
    \      int x = leader(a), y = leader(b);\n        if (x == y) return x;\n    \
    \    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return x;\n \
    \   }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n  \
    \      assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n   \
    \ }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n\
    \    }\n\n    int size(int a) {\n        assert(0 <= a && a < _n);\n        return\
    \ -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 14 \"tools/hld.hpp\"\n\nnamespace tools {\n  class\
    \ hld {\n  private:\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\
    \    ::std::vector<::std::size_t> m_parent;\n    ::std::vector<::std::size_t>\
    \ m_depth;\n    ::atcoder::dsu m_dsu;\n    ::std::vector<::std::size_t> m_idx2dfs;\n\
    \    ::std::vector<::std::size_t> m_dfs2idx;\n\n  public:\n    hld() = default;\n\
    \    hld(const ::tools::hld&) = default;\n    hld(::tools::hld&&) = default;\n\
    \    ~hld() = default;\n    ::tools::hld& operator=(const ::tools::hld&) = default;\n\
    \    ::tools::hld& operator=(::tools::hld&&) = default;\n\n    explicit hld(const\
    \ ::std::size_t n) : m_graph(n), m_parent(n), m_depth(n), m_idx2dfs(n), m_dfs2idx(n)\
    \ {\n      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n    const ::std::vector<::std::size_t>& idx2dfs()\
    \ const {\n      return this->m_idx2dfs;\n    }\n    const ::std::vector<::std::size_t>&\
    \ dfs2idx() const {\n      return this->m_dfs2idx;\n    }\n\n    void add_edge(const\
    \ ::std::size_t u, const ::std::size_t v) {\n      assert(u < this->size());\n\
    \      assert(v < this->size());\n      this->m_graph[u].push_back(v);\n     \
    \ this->m_graph[v].push_back(u);\n    }\n\n    void build(const ::std::size_t\
    \ root) {\n      assert(root < this->size());\n\n      ::std::vector<::std::size_t>\
    \ subtree_size(this->size());\n      ::std::fill(this->m_parent.begin(), this->m_parent.end(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      this->m_depth[root] = 0;\n\
    \      {\n        ::std::stack<::std::pair<::std::size_t, bool>> stack;\n    \
    \    stack.emplace(root, false);\n        stack.emplace(root, true);\n       \
    \ while (!stack.empty()) {\n          const auto [here, pre] = stack.top();\n\
    \          stack.pop();\n          if (pre) {\n            for (const auto next\
    \ : this->m_graph[here]) {\n              if (next != this->m_parent[here]) {\n\
    \                this->m_parent[next] = here;\n                this->m_depth[next]\
    \ = this->m_depth[here] + 1;\n                stack.emplace(next, false);\n  \
    \              stack.emplace(next, true);\n              }\n            }\n  \
    \        } else {\n            subtree_size[here] = 1;\n            for (const\
    \ auto child : this->m_graph[here]) {\n              if (child != this->m_parent[here])\
    \ {\n                subtree_size[here] += subtree_size[child];\n            \
    \  }\n            }\n          }\n        }\n      }\n\n      for (::std::size_t\
    \ v = 0; v < this->size(); ++v) {\n        if (v != root) {\n          ::std::iter_swap(\n\
    \            ::std::prev(this->m_graph[v].end()),\n            ::std::find(this->m_graph[v].begin(),\
    \ this->m_graph[v].end(), this->m_parent[v])\n          );\n        }\n      \
    \  ::std::iter_swap(\n          this->m_graph[v].begin(),\n          ::std::max_element(\n\
    \            this->m_graph[v].begin(),\n            ::std::prev(this->m_graph[v].end(),\
    \ v == root ? 0 : 1),\n            ::tools::less_by([&](const ::std::size_t v)\
    \ { return subtree_size[v]; })\n          )\n        );\n      }\n\n      ::std::size_t\
    \ dfs_order = 0;\n      this->m_dsu = ::atcoder::dsu(this->size());\n      {\n\
    \        ::std::stack<::std::size_t> stack;\n        stack.push(root);\n     \
    \   while (!stack.empty()) {\n          const auto here = stack.top();\n     \
    \     stack.pop();\n\n          this->m_idx2dfs[here] = dfs_order;\n         \
    \ this->m_dfs2idx[dfs_order] = here;\n          ++dfs_order;\n\n          if (this->m_graph[here].size()\
    \ > (here == root ? 0 : 1)) {\n            this->m_dsu.merge(here, this->m_graph[here][0]);\n\
    \          }\n          for (auto it = ::std::next(this->m_graph[here].rbegin(),\
    \ here == root ? 0 : 1); it != this->m_graph[here].rend(); ++it) {\n         \
    \   stack.push(*it);\n          }\n        }\n      }\n    }\n    void build()\
    \ {\n      this->build(0);\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> query(::std::size_t u, ::std::size_t v) {\n      assert(u <\
    \ this->size());\n      assert(v < this->size());\n\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> head, tail;\n      while (!this->m_dsu.same(u, v)) {\n     \
    \   if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)])\
    \ {\n          head.emplace_back(this->m_idx2dfs[u] + 1, this->m_idx2dfs[this->m_dsu.leader(u)]);\n\
    \          u = this->m_parent[this->m_dsu.leader(u)];\n        } else {\n    \
    \      tail.emplace_back(this->m_idx2dfs[this->m_dsu.leader(v)], this->m_idx2dfs[v]\
    \ + 1);\n          v = this->m_parent[this->m_dsu.leader(v)];\n        }\n   \
    \   }\n      if (this->m_depth[u] >= this->m_depth[v]) {\n        head.emplace_back(this->m_idx2dfs[u]\
    \ + 1, this->m_idx2dfs[v]);\n      } else {\n        head.emplace_back(this->m_idx2dfs[u],\
    \ this->m_idx2dfs[v] + 1);\n      }\n\n      ::std::copy(tail.rbegin(), tail.rend(),\
    \ ::std::back_inserter(head));\n      return head;\n    }\n  };\n}\n\n\n#line\
    \ 10 \"tests/hld.test.cpp\"\n\nusing i64 = std::int_fast64_t;\nusing mint = atcoder::modint998244353;\n\
    \nstd::pair<mint, mint> lop(const std::pair<mint, mint> e1, const std::pair<mint,\
    \ mint> e2) {\n  return ::std::make_pair(e1.first * e2.first, e1.first * e2.second\
    \ + e1.second);\n}\nstd::pair<mint, mint> rop(const std::pair<mint, mint> e1,\
    \ const std::pair<mint, mint> e2) {\n  return ::std::make_pair(e1.first * e2.first,\
    \ e1.second * e2.first + e2.second);\n}\nstd::pair<mint, mint> e() {\n  return\
    \ ::std::make_pair(mint::raw(1), mint::raw(0));\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, Q;\n  std::cin >> N >> Q;\n\
    \  std::vector<std::pair<mint, mint>> f;\n  f.reserve(N);\n  for (i64 i = 0; i\
    \ < N; ++i) {\n    i64 a, b;\n    std::cin >> a >> b;\n    f.emplace_back(mint::raw(a),\
    \ mint::raw(b));\n  }\n  tools::hld hld(N);\n  for (i64 i = 0; i < N - 1; ++i)\
    \ {\n    i64 u, v;\n    std::cin >> u >> v;\n    hld.add_edge(u, v);\n  }\n\n\
    \  hld.build();\n  std::vector<std::pair<mint, mint>> g(N);\n  for (i64 i = 0;\
    \ i < N; ++i) {\n    g[hld.idx2dfs()[i]] = f[i];\n  }\n  atcoder::segtree<std::pair<mint,\
    \ mint>, lop, e> lsegtree(g);\n  atcoder::segtree<std::pair<mint, mint>, rop,\
    \ e> rsegtree(g);\n\n  for (i64 q = 0; q < Q; ++q) {\n    i64 t;\n    std::cin\
    \ >> t;\n    if (t == 0) {\n      i64 p, c, d;\n      std::cin >> p >> c >> d;\n\
    \      lsegtree.set(hld.idx2dfs()[p], std::make_pair(mint::raw(c), mint::raw(d)));\n\
    \      rsegtree.set(hld.idx2dfs()[p], std::make_pair(mint::raw(c), mint::raw(d)));\n\
    \    } else {\n      i64 u, v, x;\n      std::cin >> u >> v >> x;\n      std::pair<mint,\
    \ mint> prod = e();\n      for (const auto& [from, to] : hld.query(u, v)) {\n\
    \        if (from < to) {\n          prod = rop(prod, rsegtree.prod(from, to));\n\
    \        } else {\n          prod = lop(lsegtree.prod(to, from), prod);\n    \
    \    }\n      }\n      std::cout << (prod.first * mint::raw(x) + prod.second).val()\
    \ << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <cstdint>\n#include <utility>\n#include <iostream>\n#include <vector>\n\
    #include \"atcoder/modint.hpp\"\n#include \"atcoder/segtree.hpp\"\n#include \"\
    tools/hld.hpp\"\n\nusing i64 = std::int_fast64_t;\nusing mint = atcoder::modint998244353;\n\
    \nstd::pair<mint, mint> lop(const std::pair<mint, mint> e1, const std::pair<mint,\
    \ mint> e2) {\n  return ::std::make_pair(e1.first * e2.first, e1.first * e2.second\
    \ + e1.second);\n}\nstd::pair<mint, mint> rop(const std::pair<mint, mint> e1,\
    \ const std::pair<mint, mint> e2) {\n  return ::std::make_pair(e1.first * e2.first,\
    \ e1.second * e2.first + e2.second);\n}\nstd::pair<mint, mint> e() {\n  return\
    \ ::std::make_pair(mint::raw(1), mint::raw(0));\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N, Q;\n  std::cin >> N >> Q;\n\
    \  std::vector<std::pair<mint, mint>> f;\n  f.reserve(N);\n  for (i64 i = 0; i\
    \ < N; ++i) {\n    i64 a, b;\n    std::cin >> a >> b;\n    f.emplace_back(mint::raw(a),\
    \ mint::raw(b));\n  }\n  tools::hld hld(N);\n  for (i64 i = 0; i < N - 1; ++i)\
    \ {\n    i64 u, v;\n    std::cin >> u >> v;\n    hld.add_edge(u, v);\n  }\n\n\
    \  hld.build();\n  std::vector<std::pair<mint, mint>> g(N);\n  for (i64 i = 0;\
    \ i < N; ++i) {\n    g[hld.idx2dfs()[i]] = f[i];\n  }\n  atcoder::segtree<std::pair<mint,\
    \ mint>, lop, e> lsegtree(g);\n  atcoder::segtree<std::pair<mint, mint>, rop,\
    \ e> rsegtree(g);\n\n  for (i64 q = 0; q < Q; ++q) {\n    i64 t;\n    std::cin\
    \ >> t;\n    if (t == 0) {\n      i64 p, c, d;\n      std::cin >> p >> c >> d;\n\
    \      lsegtree.set(hld.idx2dfs()[p], std::make_pair(mint::raw(c), mint::raw(d)));\n\
    \      rsegtree.set(hld.idx2dfs()[p], std::make_pair(mint::raw(c), mint::raw(d)));\n\
    \    } else {\n      i64 u, v, x;\n      std::cin >> u >> v >> x;\n      std::pair<mint,\
    \ mint> prod = e();\n      for (const auto& [from, to] : hld.query(u, v)) {\n\
    \        if (from < to) {\n          prod = rop(prod, rsegtree.prod(from, to));\n\
    \        } else {\n          prod = lop(lsegtree.prod(to, from), prod);\n    \
    \    }\n      }\n      std::cout << (prod.first * mint::raw(x) + prod.second).val()\
    \ << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/hld.hpp
  - tools/less_by.hpp
  isVerificationFile: true
  path: tests/hld.test.cpp
  requiredBy: []
  timestamp: '2022-04-23 16:47:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/hld.test.cpp
layout: document
redirect_from:
- /verify/tests/hld.test.cpp
- /verify/tests/hld.test.cpp.html
title: tests/hld.test.cpp
---
