---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/countr_zero.hpp
    title: Number of trailing zeros
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/chromatic_number.test.cpp
    title: tests/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://drken1215.hatenablog.com/entry/2019/01/16/030000
  bundledCode: "#line 1 \"tools/chromatic_number.hpp\"\n\n\n\n#include <vector>\n\
    #include <cstddef>\n#include <cassert>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/modint.hpp\"\n#include <numeric>\n#include\
    \ <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"\
    lib/ac-library/atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\n// Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/countr_zero.hpp\"\
    \n\n\n\n#line 5 \"tools/countr_zero.hpp\"\n#include <cstdint>\n#line 8 \"tools/countr_zero.hpp\"\
    \n#include <algorithm>\n#include <limits>\n\n// Source: https://qiita.com/kazatsuyu/items/38203287c19890a2b7c6\n\
    // License: unknown\n// Author: \u767D\u5C71 \u98A8\u9732\n\nnamespace tools {\n\
    \  namespace detail {\n    namespace countr_zero {\n      template <::std::size_t\
    \ N>\n      struct ntz_traits;\n\n      template <>\n      struct ntz_traits<1>\
    \ {\n        using type = bool;\n        static constexpr int shift = 0;\n   \
    \     static constexpr type magic = true;\n        static constexpr int ntz_table[2]\
    \ = {\n          1,  0\n        };\n      };\n\n      template <>\n      struct\
    \ ntz_traits<8> {\n        using type = ::std::uint8_t;\n        static constexpr\
    \ int shift = 4;\n        static constexpr type magic = UINT8_C(0x1D);\n     \
    \   static constexpr int ntz_table[15] = {\n          8,  0, -1,  1,  6, -1, -1,\
    \  2,  7, -1,  5, -1, -1,  4,  3\n        };\n      };\n\n      template <>\n\
    \      struct ntz_traits<16> {\n        using type = ::std::uint16_t;\n      \
    \  static constexpr int shift = 11;\n        static constexpr type magic = UINT16_C(0x0F2D);\n\
    \        static constexpr int ntz_table[31] = {\n          16,  0, -1,  1, -1,\
    \  8, -1,  2, 14, -1, -1,  9, -1, 11, -1,  3,\n          15, -1,  7, -1, 13, -1,\
    \ 10, -1, -1,  6, 12, -1,  5, -1,  4,\n        };\n      };\n\n      template\
    \ <>\n      struct ntz_traits<32> {\n        using type = ::std::uint32_t;\n \
    \       static constexpr int shift = 26;\n        static constexpr type magic\
    \ = UINT32_C(0x07C56E99);\n        static constexpr int ntz_table[63] = {\n  \
    \        32,  0, -1,  1, -1, 10, -1,  2, 29, -1, 11, -1, 25, -1, -1,  3,\n   \
    \       30, -1, -1, 23, -1, 12, 14, -1, -1, 26, -1, 16, -1, 19, -1,  4,\n    \
    \      31, -1,  9, -1, 28, -1, 24, -1, -1, 22, -1, 13, -1, 15, 18, -1,\n     \
    \     -1,  8, 27, -1, 21, -1, -1, 17,  7, -1, 20, -1,  6, -1,  5\n        };\n\
    \      };\n\n      template <>\n      struct ntz_traits<64> {\n        using type\
    \ = ::std::uint64_t;\n        static constexpr int shift = 57;\n        static\
    \ constexpr type magic = UINT64_C(0x03F0A933ADCBD8D1);\n        static constexpr\
    \ int ntz_table[127] = {\n          64,  0, -1,  1, -1, 12, -1,  2, 60, -1, 13,\
    \ -1, -1, 53, -1,  3,\n          61, -1, -1, 21, -1, 14, -1, 42, -1, 24, 54, -1,\
    \ -1, 28, -1,  4,\n          62, -1, 58, -1, 19, -1, 22, -1, -1, 17, 15, -1, -1,\
    \ 33, -1, 43,\n          -1, 50, -1, 25, 55, -1, -1, 35, -1, 38, 29, -1, -1, 45,\
    \ -1,  5,\n          63, -1, 11, -1, 59, -1, 52, -1, -1, 20, -1, 41, 23, -1, 27,\
    \ -1,\n          -1, 57, 18, -1, 16, -1, 32, -1, 49, -1, -1, 34, 37, -1, 44, -1,\n\
    \          -1, 10, -1, 51, -1, 40, -1, 26, 56, -1, -1, 31, 48, -1, 36, -1,\n \
    \         9, -1, 39, -1, -1, 30, 47, -1,  8, -1, -1, 46,  7, -1,  6,\n       \
    \ };\n      };\n    }\n  }\n\n  template <typename T>\n  constexpr int countr_zero(const\
    \ T x) noexcept {\n    static_assert(::std::is_integral_v<T>);\n    if constexpr\
    \ (::std::is_signed_v<T>) {\n      assert(x >= 0);\n      return ::std::min(::tools::countr_zero<::std::make_unsigned_t<T>>(x),\
    \ ::std::numeric_limits<T>::digits);\n    } else {\n      using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;\n\
    \      using type = typename tr::type;\n      return tr::ntz_table[static_cast<type>(tr::magic\
    \ * static_cast<type>(x & -x)) >> tr::shift];\n    }\n  }\n}\n\n\n#line 1 \"tools/popcount.hpp\"\
    \n\n\n\n#line 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename\
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
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 10 \"tools/chromatic_number.hpp\"\
    \n\n// Source: https://drken1215.hatenablog.com/entry/2019/01/16/030000\n// License:\
    \ unknown\n// Author: drken\n\nnamespace tools {\n  class chromatic_number {\n\
    \  private:\n    ::std::vector<unsigned long long> neighbor;\n\n  public:\n  \
    \  chromatic_number() = default;\n    chromatic_number(const ::tools::chromatic_number&)\
    \ = default;\n    chromatic_number(::tools::chromatic_number&&) = default;\n \
    \   ~chromatic_number() = default;\n    ::tools::chromatic_number& operator=(const\
    \ ::tools::chromatic_number&) = default;\n    ::tools::chromatic_number& operator=(::tools::chromatic_number&&)\
    \ = default;\n\n    explicit chromatic_number(const ::std::size_t n) : neighbor(n)\
    \ {\n      for (::std::size_t i = 0; i < n; ++i) {\n        this->neighbor[i]\
    \ = (1ULL << i);\n      }\n    }\n\n    ::std::size_t node_count() const {\n \
    \     return this->neighbor.size();\n    }\n\n    void add_edge(const ::std::size_t\
    \ s, const ::std::size_t t) {\n      assert(s < this->node_count());\n      assert(t\
    \ < this->node_count());\n      this->neighbor[s] |= (1ULL << t);\n      this->neighbor[t]\
    \ |= (1ULL << s);\n    }\n\n    long long query() const {\n      const auto pow2\
    \ = [](const unsigned long long x) {\n        return 1ULL << x;\n      };\n  \
    \    const auto& set = pow2;\n\n      // I[S] := #. of indepndent subsets of S\n\
    \      ::std::vector<::atcoder::modint1000000007> I(pow2(this->node_count()));\n\
    \      I[0] = ::atcoder::modint1000000007(1);\n      for (unsigned long long S\
    \ = 1; S < pow2(this->node_count()); ++S) {\n        const unsigned long long\
    \ v = ::tools::countr_zero(S);\n        I[S] = I[S & ~set(v)] + I[S & ~this->neighbor[v]];\n\
    \      }\n\n      long long ng = 0;\n      long long ok = this->node_count();\n\
    \      while (ok - ng > 1) {\n        long long k = (ok + ng) / 2;\n\n       \
    \ // g[S] := #. of \"k independent sets\" which cover S just\n        // f[S]\
    \ := #. of \"k independent sets\" which consist of subsets of S\n        // then\n\
    \        //   f[S] = sum_{T in S} g(T)\n        //   g[S] = sum_{T in S} (-1)^(|S|-|T|)f[T]\n\
    \        ::atcoder::modint1000000007 g(0);\n        for (unsigned long long S\
    \ = 0; S < pow2(this->node_count()); ++S) {\n          if ((static_cast<unsigned\
    \ long long>(this->node_count()) - ::tools::popcount(S)) & 1) {\n            g\
    \ -= I[S].pow(k);\n          } else {\n            g += I[S].pow(k);\n       \
    \   }\n        }\n\n        if (g.val() != 0) {\n          ok = k;\n        }\
    \ else {\n          ng = k;\n        }\n      }\n\n      return ok;\n    }\n \
    \ };\n}\n\n\n"
  code: "#ifndef TOOLS_CHROMATIC_NUMBER_HPP\n#define TOOLS_CHROMATIC_NUMBER_HPP\n\n\
    #include <vector>\n#include <cstddef>\n#include <cassert>\n#include \"atcoder/modint.hpp\"\
    \n#include \"tools/countr_zero.hpp\"\n#include \"tools/popcount.hpp\"\n\n// Source:\
    \ https://drken1215.hatenablog.com/entry/2019/01/16/030000\n// License: unknown\n\
    // Author: drken\n\nnamespace tools {\n  class chromatic_number {\n  private:\n\
    \    ::std::vector<unsigned long long> neighbor;\n\n  public:\n    chromatic_number()\
    \ = default;\n    chromatic_number(const ::tools::chromatic_number&) = default;\n\
    \    chromatic_number(::tools::chromatic_number&&) = default;\n    ~chromatic_number()\
    \ = default;\n    ::tools::chromatic_number& operator=(const ::tools::chromatic_number&)\
    \ = default;\n    ::tools::chromatic_number& operator=(::tools::chromatic_number&&)\
    \ = default;\n\n    explicit chromatic_number(const ::std::size_t n) : neighbor(n)\
    \ {\n      for (::std::size_t i = 0; i < n; ++i) {\n        this->neighbor[i]\
    \ = (1ULL << i);\n      }\n    }\n\n    ::std::size_t node_count() const {\n \
    \     return this->neighbor.size();\n    }\n\n    void add_edge(const ::std::size_t\
    \ s, const ::std::size_t t) {\n      assert(s < this->node_count());\n      assert(t\
    \ < this->node_count());\n      this->neighbor[s] |= (1ULL << t);\n      this->neighbor[t]\
    \ |= (1ULL << s);\n    }\n\n    long long query() const {\n      const auto pow2\
    \ = [](const unsigned long long x) {\n        return 1ULL << x;\n      };\n  \
    \    const auto& set = pow2;\n\n      // I[S] := #. of indepndent subsets of S\n\
    \      ::std::vector<::atcoder::modint1000000007> I(pow2(this->node_count()));\n\
    \      I[0] = ::atcoder::modint1000000007(1);\n      for (unsigned long long S\
    \ = 1; S < pow2(this->node_count()); ++S) {\n        const unsigned long long\
    \ v = ::tools::countr_zero(S);\n        I[S] = I[S & ~set(v)] + I[S & ~this->neighbor[v]];\n\
    \      }\n\n      long long ng = 0;\n      long long ok = this->node_count();\n\
    \      while (ok - ng > 1) {\n        long long k = (ok + ng) / 2;\n\n       \
    \ // g[S] := #. of \"k independent sets\" which cover S just\n        // f[S]\
    \ := #. of \"k independent sets\" which consist of subsets of S\n        // then\n\
    \        //   f[S] = sum_{T in S} g(T)\n        //   g[S] = sum_{T in S} (-1)^(|S|-|T|)f[T]\n\
    \        ::atcoder::modint1000000007 g(0);\n        for (unsigned long long S\
    \ = 0; S < pow2(this->node_count()); ++S) {\n          if ((static_cast<unsigned\
    \ long long>(this->node_count()) - ::tools::popcount(S)) & 1) {\n            g\
    \ -= I[S].pow(k);\n          } else {\n            g += I[S].pow(k);\n       \
    \   }\n        }\n\n        if (g.val() != 0) {\n          ok = k;\n        }\
    \ else {\n          ng = k;\n        }\n      }\n\n      return ok;\n    }\n \
    \ };\n}\n\n#endif\n"
  dependsOn:
  - tools/countr_zero.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/chromatic_number.hpp
  requiredBy: []
  timestamp: '2024-02-17 19:44:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/chromatic_number.test.cpp
documentation_of: tools/chromatic_number.hpp
layout: document
title: Chromatic number
---

It calculates the chromatic number of a given graph which is not necessarily simple.

### References
- [AOJ 2136 Webby Subway (JAG 夏合宿 2008 day2-F) - けんちょんの競プロ精進記録](https://drken1215.hatenablog.com/entry/2019/01/16/030000)

### License
- unknown

### Author
- drken

## Constructor
```cpp
chromatic_number graph(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $1 \leq n \leq 63$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void graph.add_edge(std::size_t s, std::size_t t);
```

It adds a edge from $s$ to $t$.

### Constraints
- $0 \leq s < n$
- $0 \leq t < n$

### Time Complexity
- $O(1)$

## query
```cpp
long long graph.query();
```

It returns the chromatic number of the graph.

### Constraints
- None

### Time Complexity
- $O(2^n n)$
