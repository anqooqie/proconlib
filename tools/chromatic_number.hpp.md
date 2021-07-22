---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ntz.hpp
    title: Number of trailing zeros
  - icon: ':heavy_check_mark:'
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
    #include <cstdint>\n#include <cstddef>\n#include <cassert>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/modint.hpp\"\n#include <numeric>\n#include\
    \ <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"\
    lib/ac-library/atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\n// Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    barrett(unsigned\
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
    \ = primitive_root_constexpr(m);\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n\n\
    \n\n#line 7 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n\nnamespace atcoder\
    \ {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
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
    \ dynamic_modint<id>::bt = 998244353;\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/ntz.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n\
    \    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  inline ::std::uint64_t\
    \ popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 6 \"tools/ntz.hpp\"\n\nnamespace tools {\n\n  inline ::std::uint32_t\
    \ ntz(const ::std::uint32_t& x) {\n    return ::tools::popcount((x & -x) - static_cast<::std::uint32_t>(1));\n\
    \  }\n\n  inline ::std::uint64_t ntz(const ::std::uint64_t& x) {\n    return ::tools::popcount((x\
    \ & -x) - static_cast<::std::uint64_t>(1));\n  }\n\n  inline ::std::int32_t ntz(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::ntz(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t ntz(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::ntz(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 11 \"tools/chromatic_number.hpp\"\n\n// Source: https://drken1215.hatenablog.com/entry/2019/01/16/030000\n\
    // License: unknown\n// Author: drken\n\nnamespace tools {\n  class chromatic_number\
    \ {\n  private:\n    ::std::vector<::std::uint_fast64_t> neighbor;\n\n  public:\n\
    \    chromatic_number() = default;\n    chromatic_number(const ::tools::chromatic_number&)\
    \ = default;\n    chromatic_number(::tools::chromatic_number&&) = default;\n \
    \   ~chromatic_number() = default;\n    ::tools::chromatic_number& operator=(const\
    \ ::tools::chromatic_number&) = default;\n    ::tools::chromatic_number& operator=(::tools::chromatic_number&&)\
    \ = default;\n\n    explicit chromatic_number(const ::std::size_t n) : neighbor(n)\
    \ {\n      for (::std::size_t i = 0; i < n; ++i) {\n        this->neighbor[i]\
    \ = (::std::uint_fast64_t(1) << ::std::uint_fast64_t(i));\n      }\n    }\n\n\
    \    ::std::size_t node_count() const {\n      return this->neighbor.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t s, const ::std::size_t t) {\n\
    \      assert(s < this->node_count());\n      assert(t < this->node_count());\n\
    \      this->neighbor[s] |= (::std::uint_fast64_t(1) << ::std::uint_fast64_t(t));\n\
    \      this->neighbor[t] |= (::std::uint_fast64_t(1) << ::std::uint_fast64_t(s));\n\
    \    }\n\n    ::std::int_fast64_t query() const {\n      const auto pow2 = [](const\
    \ ::std::uint_fast64_t x) {\n        return ::std::uint_fast64_t(1) << x;\n  \
    \    };\n      const auto& set = pow2;\n\n      // I[S] := #. of indepndent subsets\
    \ of S\n      ::std::vector<::atcoder::modint1000000007> I(pow2(this->node_count()));\n\
    \      I[0] = ::atcoder::modint1000000007(1);\n      for (::std::uint_fast64_t\
    \ S = 1; S < pow2(this->node_count()); ++S) {\n        const ::std::uint_fast64_t\
    \ v = ::tools::ntz(S);\n        I[S] = I[S & ~set(v)] + I[S & ~this->neighbor[v]];\n\
    \      }\n\n      ::std::int_fast64_t ng = 0;\n      ::std::int_fast64_t ok =\
    \ this->node_count();\n      while (ok - ng > 1) {\n        ::std::int_fast64_t\
    \ k = (ok + ng) / 2;\n\n        // g[S] := #. of \"k independent sets\" which\
    \ cover S just\n        // f[S] := #. of \"k independent sets\" which consist\
    \ of subsets of S\n        // then\n        //   f[S] = sum_{T in S} g(T)\n  \
    \      //   g[S] = sum_{T in S} (-1)^(|S|-|T|)f[T]\n        ::atcoder::modint1000000007\
    \ g(0);\n        for (::std::uint_fast64_t S = 0; S < pow2(this->node_count());\
    \ ++S) {\n          if ((::std::uint_fast64_t(this->node_count()) - ::tools::popcount(S))\
    \ & 1) {\n            g -= I[S].pow(k);\n          } else {\n            g +=\
    \ I[S].pow(k);\n          }\n        }\n\n        if (g.val() != 0) {\n      \
    \    ok = k;\n        } else {\n          ng = k;\n        }\n      }\n\n    \
    \  return ok;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_CHROMATIC_NUMBER_HPP\n#define TOOLS_CHROMATIC_NUMBER_HPP\n\n\
    #include <vector>\n#include <cstdint>\n#include <cstddef>\n#include <cassert>\n\
    #include \"atcoder/modint.hpp\"\n#include \"tools/ntz.hpp\"\n#include \"tools/popcount.hpp\"\
    \n\n// Source: https://drken1215.hatenablog.com/entry/2019/01/16/030000\n// License:\
    \ unknown\n// Author: drken\n\nnamespace tools {\n  class chromatic_number {\n\
    \  private:\n    ::std::vector<::std::uint_fast64_t> neighbor;\n\n  public:\n\
    \    chromatic_number() = default;\n    chromatic_number(const ::tools::chromatic_number&)\
    \ = default;\n    chromatic_number(::tools::chromatic_number&&) = default;\n \
    \   ~chromatic_number() = default;\n    ::tools::chromatic_number& operator=(const\
    \ ::tools::chromatic_number&) = default;\n    ::tools::chromatic_number& operator=(::tools::chromatic_number&&)\
    \ = default;\n\n    explicit chromatic_number(const ::std::size_t n) : neighbor(n)\
    \ {\n      for (::std::size_t i = 0; i < n; ++i) {\n        this->neighbor[i]\
    \ = (::std::uint_fast64_t(1) << ::std::uint_fast64_t(i));\n      }\n    }\n\n\
    \    ::std::size_t node_count() const {\n      return this->neighbor.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t s, const ::std::size_t t) {\n\
    \      assert(s < this->node_count());\n      assert(t < this->node_count());\n\
    \      this->neighbor[s] |= (::std::uint_fast64_t(1) << ::std::uint_fast64_t(t));\n\
    \      this->neighbor[t] |= (::std::uint_fast64_t(1) << ::std::uint_fast64_t(s));\n\
    \    }\n\n    ::std::int_fast64_t query() const {\n      const auto pow2 = [](const\
    \ ::std::uint_fast64_t x) {\n        return ::std::uint_fast64_t(1) << x;\n  \
    \    };\n      const auto& set = pow2;\n\n      // I[S] := #. of indepndent subsets\
    \ of S\n      ::std::vector<::atcoder::modint1000000007> I(pow2(this->node_count()));\n\
    \      I[0] = ::atcoder::modint1000000007(1);\n      for (::std::uint_fast64_t\
    \ S = 1; S < pow2(this->node_count()); ++S) {\n        const ::std::uint_fast64_t\
    \ v = ::tools::ntz(S);\n        I[S] = I[S & ~set(v)] + I[S & ~this->neighbor[v]];\n\
    \      }\n\n      ::std::int_fast64_t ng = 0;\n      ::std::int_fast64_t ok =\
    \ this->node_count();\n      while (ok - ng > 1) {\n        ::std::int_fast64_t\
    \ k = (ok + ng) / 2;\n\n        // g[S] := #. of \"k independent sets\" which\
    \ cover S just\n        // f[S] := #. of \"k independent sets\" which consist\
    \ of subsets of S\n        // then\n        //   f[S] = sum_{T in S} g(T)\n  \
    \      //   g[S] = sum_{T in S} (-1)^(|S|-|T|)f[T]\n        ::atcoder::modint1000000007\
    \ g(0);\n        for (::std::uint_fast64_t S = 0; S < pow2(this->node_count());\
    \ ++S) {\n          if ((::std::uint_fast64_t(this->node_count()) - ::tools::popcount(S))\
    \ & 1) {\n            g -= I[S].pow(k);\n          } else {\n            g +=\
    \ I[S].pow(k);\n          }\n        }\n\n        if (g.val() != 0) {\n      \
    \    ok = k;\n        } else {\n          ng = k;\n        }\n      }\n\n    \
    \  return ok;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ntz.hpp
  - tools/popcount.hpp
  isVerificationFile: false
  path: tools/chromatic_number.hpp
  requiredBy: []
  timestamp: '2021-07-22 17:17:38+09:00'
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
chromatic_number graph(::std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.

### Constraints
- $1 \leq n \leq 63$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void graph.add_edge(::std::size_t s, ::std::size_t t);
```

It adds a edge from $s$ to $t$.

### Constraints
- $0 \leq s < n$
- $0 \leq t < n$

### Time Complexity
- $O(1)$

## query
```cpp
::std::int_fast64_t graph.query();
```

It returns the chromatic number of the graph.

### Constraints
- None

### Time Complexity
- $O(2^n n)$
