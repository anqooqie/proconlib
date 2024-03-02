---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':heavy_check_mark:'
    path: tools/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':heavy_check_mark:'
    path: tools/tuple_hash.hpp
    title: Hash of std::tuple
  - icon: ':heavy_check_mark:'
    path: tools/vector.hpp
    title: Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"tests/matrix/inv.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/matrix.hpp\"\
    \n\n\n\n#include <vector>\n#include <cstddef>\n#line 9 \"tools/matrix.hpp\"\n\
    #include <optional>\n#line 1 \"tools/vector.hpp\"\n\n\n\n#line 5 \"tools/vector.hpp\"\
    \n#include <limits>\n#line 7 \"tools/vector.hpp\"\n#include <array>\n#line 9 \"\
    tools/vector.hpp\"\n#include <iterator>\n#line 11 \"tools/vector.hpp\"\n#include\
    \ <algorithm>\n#line 13 \"tools/vector.hpp\"\n#include <cmath>\n#line 16 \"tools/vector.hpp\"\
    \n#include <functional>\n#include <tuple>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace\
    \ tools {\n  constexpr float abs(const float x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr double abs(const double x) {\n    return x < 0 ? -x : x;\n \
    \ }\n  constexpr long double abs(const long double x) {\n    return x < 0 ? -x\
    \ : x;\n  }\n  constexpr int abs(const int x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr long abs(const long x) {\n    return x < 0 ? -x : x;\n  }\n\
    \  constexpr long long abs(const long long x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr unsigned int abs(const unsigned int x) {\n    return x;\n  }\n\
    \  constexpr unsigned long abs(const unsigned long x) {\n    return x;\n  }\n\
    \  constexpr unsigned long long abs(const unsigned long long x) {\n    return\
    \ x;\n  }\n}\n\n\n#line 1 \"tools/tuple_hash.hpp\"\n\n\n\n#line 1 \"tools/now.hpp\"\
    \n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline long long now() {\n \
    \   return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \  }\n}\n\n\n#line 1 \"tools/hash_combine.hpp\"\n\n\n\n#line 6 \"tools/hash_combine.hpp\"\
    \n\n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
    // License: MIT\n// Author: Google Inc.\n\n// Copyright (c) 2011 Google, Inc.\n\
    //\n// Permission is hereby granted, free of charge, to any person obtaining a\
    \ copy\n// of this software and associated documentation files (the \"Software\"\
    ), to deal\n// in the Software without restriction, including without limitation\
    \ the rights\n// to use, copy, modify, merge, publish, distribute, sublicense,\
    \ and/or sell\n// copies of the Software, and to permit persons to whom the Software\
    \ is\n// furnished to do so, subject to the following conditions:\n//\n// The\
    \ above copyright notice and this permission notice shall be included in\n// all\
    \ copies or substantial portions of the Software.\n//\n// THE SOFTWARE IS PROVIDED\
    \ \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED, INCLUDING BUT\
    \ NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS FOR A PARTICULAR\
    \ PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS OR COPYRIGHT\
    \ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY, WHETHER IN\
    \ AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF OR IN CONNECTION\
    \ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n// THE SOFTWARE.\n\nnamespace\
    \ tools {\n  template <typename T>\n  void hash_combine(::std::size_t& seed, const\
    \ T& v) {\n    static const ::std::hash<T> hasher;\n    static constexpr ::std::size_t\
    \ k_mul = 0x9ddfea08eb382d69ULL;\n    ::std::size_t a = (hasher(v) ^ seed) * k_mul;\n\
    \    a ^= (a >> 47);\n    ::std::size_t b = (seed ^ a) * k_mul;\n    b ^= (b >>\
    \ 47);\n    seed = b * k_mul;\n  }\n}\n\n\n#line 11 \"tools/tuple_hash.hpp\"\n\
    \nnamespace tools {\n  template <typename... Ts>\n  struct tuple_hash {\n    template\
    \ <::std::size_t I = sizeof...(Ts) - 1>\n    ::std::size_t operator()(const ::std::tuple<Ts...>&\
    \ key) const {\n      if constexpr (I == ::std::numeric_limits<::std::size_t>::max())\
    \ {\n        static const ::std::size_t seed = ::tools::now();\n        return\
    \ seed;\n      } else {\n        ::std::size_t seed = this->operator()<I - 1>(key);\n\
    \        ::tools::hash_combine(seed, ::std::get<I>(key));\n        return seed;\n\
    \      }\n    }\n  };\n}\n\n\n#line 20 \"tools/vector.hpp\"\n\nnamespace tools\
    \ {\n  namespace detail {\n    namespace vector {\n      template <typename T,\
    \ ::std::size_t N>\n      class members {\n      protected:\n        constexpr\
    \ static bool specialized = false;\n      };\n      template <typename T>\n  \
    \    class members<T, 2> {\n      protected:\n        constexpr static bool specialized\
    \ = true;\n      public:\n        T x;\n        T y;\n      };\n      template\
    \ <typename T>\n      class members<T, 3> : public members<T, 2> {\n      public:\n\
    \        T z;\n      };\n      template <typename T>\n      class members<T, 4>\
    \ : public members<T, 3> {\n      public:\n        T w;\n      };\n    }\n  }\n\
    \n  template <typename T, ::std::size_t N = ::std::numeric_limits<::std::size_t>::max()>\n\
    \  class vector : public ::tools::detail::vector::members<T, N> {\n  private:\n\
    \    constexpr static bool STATIC = N != ::std::numeric_limits<::std::size_t>::max();\n\
    \    constexpr static bool specialized = ::tools::detail::vector::members<T, N>::specialized;\n\
    \    ::std::conditional_t<STATIC, ::std::array<::std::conditional_t<specialized,\
    \ T*, T>, N>, ::std::vector<T>> m_values;\n    using F = ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double>;\n    using V = ::tools::vector<T, N>;\n\n  public:\n    using reference\
    \ = T&;\n    using const_reference = const T&;\n    using size_type = ::std::size_t;\n\
    \    using difference_type = ::std::ptrdiff_t;\n    using pointer = T*;\n    using\
    \ const_pointer = const T*;\n    using value_type = T;\n    class iterator {\n\
    \    private:\n      V* m_parent;\n      size_type m_i;\n\n    public:\n     \
    \ using difference_type = ::std::ptrdiff_t;\n      using value_type = T;\n   \
    \   using reference = T&;\n      using pointer = T*;\n      using iterator_category\
    \ = ::std::random_access_iterator_tag;\n\n      iterator() = default;\n      iterator(const\
    \ iterator&) = default;\n      iterator(iterator&&) = default;\n      ~iterator()\
    \ = default;\n      iterator& operator=(const iterator&) = default;\n      iterator&\
    \ operator=(iterator&&) = default;\n\n      iterator(V * const parent, const size_type\
    \ i) : m_parent(parent), m_i(i) {}\n\n      reference operator*() const {\n  \
    \      return (*this->m_parent)[this->m_i];\n      }\n      pointer operator->()\
    \ const {\n        return &(*(*this));\n      }\n\n      iterator& operator++()\
    \ {\n        ++this->m_i;\n        return *this;\n      }\n      iterator operator++(int)\
    \ {\n        const auto self = *this;\n        ++*this;\n        return self;\n\
    \      }\n      iterator& operator--() {\n        --this->m_i;\n        return\
    \ *this;\n      }\n      iterator operator--(int) {\n        const auto self =\
    \ *this;\n        --*this;\n        return self;\n      }\n      iterator& operator+=(const\
    \ difference_type n) {\n        this->m_i += n;\n        return *this;\n     \
    \ }\n      iterator& operator-=(const difference_type n) {\n        this->m_i\
    \ -= n;\n        return *this;\n      }\n      friend iterator operator+(const\
    \ iterator& self, const difference_type n) {\n        return iterator(self) +=\
    \ n;\n      }\n      friend iterator operator+(const difference_type n, const\
    \ iterator& self) {\n        return iterator(self) += n;\n      }\n      friend\
    \ iterator operator-(const iterator& self, const difference_type n) {\n      \
    \  return iterator(self) -= n;\n      }\n      friend difference_type operator-(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);\n\
    \      }\n      reference operator[](const difference_type n) const {\n      \
    \  return *(*this + n);\n      }\n\n      friend bool operator==(const iterator&\
    \ lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i == rhs.m_i;\n      }\n      friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i != rhs.m_i;\n      }\n      friend bool operator<(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i < rhs.m_i;\n      }\n      friend bool operator<=(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i <= rhs.m_i;\n      }\n      friend bool operator>(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i > rhs.m_i;\n      }\n      friend bool operator>=(const\
    \ iterator& lhs, const iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i >= rhs.m_i;\n      }\n    };\n    class const_iterator\
    \ {\n    private:\n      const V *m_parent;\n      size_type m_i;\n\n    public:\n\
    \      using difference_type = ::std::ptrdiff_t;\n      using value_type = T;\n\
    \      using reference = const T&;\n      using pointer = const T*;\n      using\
    \ iterator_category = ::std::random_access_iterator_tag;\n\n      const_iterator()\
    \ = default;\n      const_iterator(const const_iterator&) = default;\n      const_iterator(const_iterator&&)\
    \ = default;\n      ~const_iterator() = default;\n      const_iterator& operator=(const\
    \ const_iterator&) = default;\n      const_iterator& operator=(const_iterator&&)\
    \ = default;\n\n      const_iterator(const V * const parent, const size_type i)\
    \ : m_parent(parent), m_i(i) {}\n\n      reference operator*() const {\n     \
    \   return (*this->m_parent)[this->m_i];\n      }\n      pointer operator->()\
    \ const {\n        return &(*(*this));\n      }\n\n      const_iterator& operator++()\
    \ {\n        ++this->m_i;\n        return *this;\n      }\n      const_iterator\
    \ operator++(int) {\n        const auto self = *this;\n        ++*this;\n    \
    \    return self;\n      }\n      const_iterator& operator--() {\n        --this->m_i;\n\
    \        return *this;\n      }\n      const_iterator operator--(int) {\n    \
    \    const auto self = *this;\n        --*this;\n        return self;\n      }\n\
    \      const_iterator& operator+=(const difference_type n) {\n        this->m_i\
    \ += n;\n        return *this;\n      }\n      const_iterator& operator-=(const\
    \ difference_type n) {\n        this->m_i -= n;\n        return *this;\n     \
    \ }\n      friend const_iterator operator+(const const_iterator& self, const difference_type\
    \ n) {\n        return const_iterator(self) += n;\n      }\n      friend const_iterator\
    \ operator+(const difference_type n, const const_iterator& self) {\n        return\
    \ const_iterator(self) += n;\n      }\n      friend const_iterator operator-(const\
    \ const_iterator& self, const difference_type n) {\n        return const_iterator(self)\
    \ -= n;\n      }\n      friend difference_type operator-(const const_iterator&\
    \ lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);\n\
    \      }\n      reference operator[](const difference_type n) const {\n      \
    \  return *(*this + n);\n      }\n\n      friend bool operator==(const const_iterator&\
    \ lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i == rhs.m_i;\n      }\n      friend bool operator!=(const\
    \ const_iterator& lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i != rhs.m_i;\n      }\n      friend\
    \ bool operator<(const const_iterator& lhs, const const_iterator& rhs) {\n   \
    \     assert(lhs.m_parent == rhs.m_parent);\n        return lhs.m_i < rhs.m_i;\n\
    \      }\n      friend bool operator<=(const const_iterator& lhs, const const_iterator&\
    \ rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n        return lhs.m_i\
    \ <= rhs.m_i;\n      }\n      friend bool operator>(const const_iterator& lhs,\
    \ const const_iterator& rhs) {\n        assert(lhs.m_parent == rhs.m_parent);\n\
    \        return lhs.m_i > rhs.m_i;\n      }\n      friend bool operator>=(const\
    \ const_iterator& lhs, const const_iterator& rhs) {\n        assert(lhs.m_parent\
    \ == rhs.m_parent);\n        return lhs.m_i >= rhs.m_i;\n      }\n    };\n   \
    \ using reverse_iterator = ::std::reverse_iterator<iterator>;\n    using const_reverse_iterator\
    \ = ::std::reverse_iterator<const_iterator>;\n\n  private:\n    void init() {\n\
    \      if constexpr (STATIC && specialized) {\n        this->m_values[0] = &this->x;\n\
    \        this->m_values[1] = &this->y;\n        if constexpr (N > 2) {\n     \
    \     this->m_values[2] = &this->z;\n        }\n        if constexpr (N > 3) {\n\
    \          this->m_values[3] = &this->w;\n        }\n      }\n    }\n\n  public:\n\
    \    vector() {\n      init();\n    }\n    vector(const V& other) {\n      init();\n\
    \      if constexpr (STATIC && specialized) {\n        ::std::copy(other.begin(),\
    \ other.end(), this->begin());\n      } else {\n        this->m_values = other.m_values;\n\
    \      }\n    }\n    vector(V&& other) noexcept {\n      init();\n      if constexpr\
    \ (STATIC && specialized) {\n        ::std::copy(other.begin(), other.end(), this->begin());\n\
    \      } else {\n        this->m_values = ::std::move(other.m_values);\n     \
    \ }\n    }\n    ~vector() = default;\n    V& operator=(const V& other) {\n   \
    \   if constexpr (STATIC && specialized) {\n        ::std::copy(other.begin(),\
    \ other.end(), this->begin());\n      } else {\n        this->m_values = other.m_values;\n\
    \      }\n      return *this;\n    }\n    V& operator=(V&& other) noexcept {\n\
    \      if constexpr (STATIC && specialized) {\n        ::std::copy(other.begin(),\
    \ other.end(), this->begin());\n      } else {\n        this->m_values = ::std::move(other.m_values);\n\
    \      }\n      return *this;\n    }\n\n    template <bool SFINAE = !STATIC, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    explicit vector(size_type n) : m_values(n)\
    \ {\n    }\n    template <bool SFINAE = !STATIC, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    vector(size_type n, const_reference value) : m_values(n, value)\
    \ {\n    }\n    template <typename InputIter, bool SFINAE = !STATIC, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    vector(const InputIter first, const InputIter\
    \ last) : m_values(first, last) {\n    }\n    template <bool SFINAE = N == 2,\
    \ ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n    vector(const T&\
    \ x, const T& y) {\n      init();\n      this->x = x;\n      this->y = y;\n  \
    \  }\n    template <bool SFINAE = N == 3, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    vector(const T& x, const T& y, const T& z) {\n      init();\n\
    \      this->x = x;\n      this->y = y;\n      this->z = z;\n    }\n    template\
    \ <bool SFINAE = N == 4, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n\
    \    vector(const T& x, const T& y, const T& z, const T& w) {\n      init();\n\
    \      this->x = x;\n      this->y = y;\n      this->z = z;\n      this->w = w;\n\
    \    }\n    vector(const ::std::initializer_list<T> il) {\n      init();\n   \
    \   if constexpr (STATIC) {\n        assert(il.size() == N);\n        ::std::copy(il.begin(),\
    \ il.end(), this->begin());\n      } else {\n        this->m_values.reserve(il.size());\n\
    \        ::std::copy(il.begin(), il.end(), ::std::back_inserter(this->m_values));\n\
    \      }\n    }\n\n    iterator begin() noexcept { return iterator(this, 0); }\n\
    \    const_iterator begin() const noexcept { return const_iterator(this, 0); }\n\
    \    const_iterator cbegin() const noexcept { return const_iterator(this, 0);\
    \ }\n    iterator end() noexcept { return iterator(this, this->size()); }\n  \
    \  const_iterator end() const noexcept { return const_iterator(this, this->size());\
    \ }\n    const_iterator cend() const noexcept { return const_iterator(this, this->size());\
    \ }\n    reverse_iterator rbegin() noexcept { return ::std::make_reverse_iterator(this->end());\
    \ }\n    const_reverse_iterator rbegin() const noexcept { return ::std::make_reverse_iterator(this->end());\
    \ }\n    const_reverse_iterator crbegin() const noexcept { return ::std::make_reverse_iterator(this->cend());\
    \ }\n    reverse_iterator rend() noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator rend() const noexcept { return ::std::make_reverse_iterator(this->begin());\
    \ }\n    const_reverse_iterator crend() const noexcept { return ::std::make_reverse_iterator(this->cbegin());\
    \ }\n\n    size_type size() const noexcept { return this->m_values.size(); }\n\
    \    bool empty() const noexcept { return this->m_values.empty(); }\n\n    reference\
    \ operator[](const size_type n) {\n      if constexpr (STATIC && specialized)\
    \ {\n        return *this->m_values[n];\n      } else {\n        return this->m_values[n];\n\
    \      }\n    }\n    const_reference operator[](const size_type n) const {\n \
    \     if constexpr (STATIC && specialized) {\n        return *this->m_values[n];\n\
    \      } else {\n        return this->m_values[n];\n      }\n    }\n    reference\
    \ front() { return *this->begin(); }\n    const_reference front() const { return\
    \ *this->begin(); }\n    reference back() { return *this->rbegin(); }\n    const_reference\
    \ back() const { return *this->rbegin(); }\n\n    V operator+() const {\n    \
    \  return *this;\n    }\n    V operator-() const {\n      V res = *this;\n   \
    \   for (auto& v : res) v = -v;\n      return res;\n    }\n    V& operator+=(const\
    \ V& other) {\n      assert(this->size() == other.size());\n      for (::std::size_t\
    \ i = 0; i < this->size(); ++i) {\n        (*this)[i] += other[i];\n      }\n\
    \      return *this;\n    }\n    friend V operator+(const V& lhs, const V& rhs)\
    \ {\n      return V(lhs) += rhs;\n    }\n    V& operator-=(const V& other) {\n\
    \      assert(this->size() == other.size());\n      for (::std::size_t i = 0;\
    \ i < this->size(); ++i) {\n        (*this)[i] -= other[i];\n      }\n      return\
    \ *this;\n    }\n    friend V operator-(const V& lhs, const V& rhs) {\n      return\
    \ V(lhs) -= rhs;\n    }\n    V& operator*=(const T& c) {\n      for (auto& v :\
    \ *this) v *= c;\n      return *this;\n    }\n    friend V operator*(const T&\
    \ lhs, const V& rhs) {\n      return V(rhs) *= lhs;\n    }\n    friend V operator*(const\
    \ V& lhs, const T& rhs) {\n      return V(lhs) *= rhs;\n    }\n    V& operator/=(const\
    \ T& c) {\n      for (auto& v : *this) v /= c;\n      return *this;\n    }\n \
    \   friend V operator/(const V& lhs, const T& rhs) {\n      return V(lhs) /= rhs;\n\
    \    }\n\n    friend bool operator==(const V& lhs, const V& rhs) {\n      return\
    \ ::std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());\n    }\n    friend\
    \ bool operator!=(const V& lhs, const V& rhs) {\n      return !(lhs == rhs);\n\
    \    }\n\n    T inner_product(const V& other) const {\n      assert(this->size()\
    \ == other.size());\n      T res{};\n      for (::std::size_t i = 0; i < this->size();\
    \ ++i) {\n        res += (*this)[i] * other[i];\n      }\n      return res;\n\
    \    }\n    T l1_norm() const {\n      T res{};\n      for (const auto& v : *this)\
    \ {\n        res += ::tools::abs(v);\n      }\n      return res;\n    }\n    T\
    \ squared_l2_norm() const {\n      return this->inner_product(*this);\n    }\n\
    \    F l2_norm() const {\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\n\
    \    }\n    template <bool SFINAE = ::std::is_floating_point_v<T>, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    V normalized() const {\n      return *this\
    \ / this->l2_norm();\n    }\n\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const V& self) {\n      os << '(';\n      ::std::string delimiter = \"\"\
    ;\n      for (const auto& v : self) {\n        os << delimiter << v;\n       \
    \ delimiter = \", \";\n      }\n      return os << ')';\n    }\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, V& self) {\n      for (auto& v : self) {\n  \
    \      is >> v;\n      }\n      return is;\n    }\n\n    template <bool SFINAE\
    \ = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n    T outer_product(const\
    \ V& other) const {\n      return this->x * other.y - this->y * other.x;\n   \
    \ }\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    V turned90() const {\n      return V{-this->y, this->x};\n \
    \   }\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    V turned270() const {\n      return V{this->y, -this->x};\n\
    \    }\n\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE, ::std::nullptr_t>\
    \ = nullptr>\n    static const ::std::array<V, 4>& four_directions() {\n     \
    \ static const ::std::array<V, 4> res = {\n        V{T(1), T(0)},\n        V{T(0),\
    \ T(1)},\n        V{T(-1), T(0)},\n        V{T(0), T(-1)}\n      };\n      return\
    \ res;\n    }\n    template <bool SFINAE = N == 2, ::std::enable_if_t<SFINAE,\
    \ ::std::nullptr_t> = nullptr>\n    static const ::std::array<V, 8>& eight_directions()\
    \ {\n      static const ::std::array<V, 8> res = {\n        V{T(1), T(0)},\n \
    \       V{T(1), T(1)},\n        V{T(0), T(1)},\n        V{T(-1), T(1)},\n    \
    \    V{T(-1), T(0)},\n        V{T(-1), T(-1)},\n        V{T(0), T(-1)},\n    \
    \    V{T(1), T(-1)}\n      };\n      return res;\n    }\n\n    template <bool\
    \ SFINAE = N == 3, ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n \
    \   V outer_product(const V& other) const {\n      return V{this->y * other.z\
    \ - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y\
    \ - this->y * other.x};\n    }\n    template <bool SFINAE = N == 3 && ::std::is_floating_point_v<T>,\
    \ ::std::enable_if_t<SFINAE, ::std::nullptr_t> = nullptr>\n    ::std::array<V,\
    \ 3> orthonormal_basis() const {\n      assert((*this != V{0, 0, 0}));\n\n   \
    \   ::std::array<V, 3> v;\n      v[0] = *this;\n      v[1] = V{0, this->z, -this->y};\n\
    \      if (v[1] == V{0, 0, 0}) {\n        v[1] = V{-this->z, 0, this->x};\n  \
    \    }\n      v[1] -= v[0].inner_product(v[1]) / v[0].inner_product(v[0]) * v[0];\n\
    \n      v[0] = v[0].normalized();\n      v[1] = v[1].normalized();\n      v[2]\
    \ = v[0].outer_product(v[1]);\n\n      return v;\n    }\n  };\n}\n\nnamespace\
    \ std {\n  template <typename T>\n  struct hash<::tools::vector<T, 2>> {\n   \
    \ using result_type = ::std::size_t;\n    using argument_type = ::tools::vector<T,\
    \ 2>;\n    result_type operator()(const argument_type& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y));\n    }\n  };\n  template <typename T>\n  struct hash<::tools::vector<T,\
    \ 3>> {\n    using result_type = ::std::size_t;\n    using argument_type = ::tools::vector<T,\
    \ 3>;\n    result_type operator()(const argument_type& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y, key.z));\n    }\n  };\n  template <typename T>\n  struct hash<::tools::vector<T,\
    \ 4>> {\n    using result_type = ::std::size_t;\n    using argument_type = ::tools::vector<T,\
    \ 4>;\n    result_type operator()(const argument_type& key) const {\n      static\
    \ const ::tools::tuple_hash<T, T, T, T> hasher;\n      return hasher(::std::make_tuple(key.x,\
    \ key.y, key.z, key.w));\n    }\n  };\n}\n\n\n#line 11 \"tools/matrix.hpp\"\n\n\
    namespace tools {\n  template <typename T>\n  class matrix {\n  private:\n   \
    \ ::std::vector<T> m_values;\n    ::std::size_t m_rows;\n    ::std::size_t m_cols;\n\
    \n  public:\n    matrix() = default;\n    matrix(const ::tools::matrix<T>&) =\
    \ default;\n    matrix(::tools::matrix<T>&&) = default;\n    ~matrix() = default;\n\
    \    ::tools::matrix<T>& operator=(const ::tools::matrix<T>&) = default;\n   \
    \ ::tools::matrix<T>& operator=(::tools::matrix<T>&&) = default;\n\n    matrix(::std::size_t\
    \ rows, ::std::size_t cols) :\n      m_values(rows * cols), m_rows(rows), m_cols(cols)\
    \ {\n    }\n    matrix(::std::size_t rows, ::std::size_t cols, const T& value)\
    \ :\n      m_values(rows * cols, value), m_rows(rows), m_cols(cols) {\n    }\n\
    \n    typename ::std::vector<T>::iterator operator[](const ::std::size_t r) {\n\
    \      return this->m_values.begin() + r * this->m_cols;\n    }\n    typename\
    \ ::std::vector<T>::const_iterator operator[](const ::std::size_t r) const {\n\
    \      return this->m_values.begin() + r * this->m_cols;\n    }\n\n    ::std::size_t\
    \ rows() const {\n      return this->m_rows;\n    }\n    ::std::size_t cols()\
    \ const {\n      return this->m_cols;\n    }\n\n    friend ::tools::matrix<T>&\
    \ operator+(::tools::matrix<T>& self) {\n      return self;\n    }\n    friend\
    \ const ::tools::matrix<T>& operator+(const ::tools::matrix<T>& self) {\n    \
    \  return self;\n    }\n    friend ::tools::matrix<T> operator+(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      return ::tools::matrix<T>(lhs)\
    \ += rhs;\n    }\n    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>&\
    \ self) {\n      return ::tools::matrix<T>(self) *= T(-1);\n    }\n    friend\
    \ ::tools::matrix<T> operator-(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>&\
    \ rhs) {\n      return ::tools::matrix<T>(lhs) -= rhs;\n    }\n    friend ::tools::matrix<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.m_rows);\n      ::tools::matrix<T> result(lhs.m_rows,\
    \ rhs.m_cols, T(0));\n      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {\n\
    \        for (::std::size_t k = 0; k < lhs.m_cols; ++k) {\n          for (::std::size_t\
    \ j = 0; j < rhs.m_cols; ++j) {\n            result[i][j] += lhs[i][k] * rhs[k][j];\n\
    \          }\n        }\n      }\n      return result;\n    }\n    friend ::tools::vector<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {\n\
    \      assert(lhs.m_cols == rhs.size());\n      ::tools::vector<T> result(lhs.m_rows,\
    \ T(0));\n      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {\n        for\
    \ (::std::size_t j = 0; j < lhs.m_cols; ++j) {\n          result[i] += lhs[i][j]\
    \ * rhs[j];\n        }\n      }\n      return result;\n    }\n    friend ::tools::matrix<T>\
    \ operator*(const ::tools::matrix<T>& lhs, const T& rhs) {\n      return ::tools::matrix<T>(lhs)\
    \ * rhs;\n    }\n    friend ::tools::matrix<T> operator/(const ::tools::matrix<T>&\
    \ lhs, const T& rhs) {\n      return ::tools::matrix<T>(lhs) / rhs;\n    }\n \
    \   ::tools::matrix<T> operator+=(const ::tools::matrix<T>& other) {\n      assert(this->m_rows\
    \ == other.m_rows);\n      assert(this->m_cols == other.m_cols);\n      for (::std::size_t\
    \ i = 0; i < this->m_values.size(); ++i) {\n        this->m_values[i] += other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::matrix<T> operator-=(const\
    \ ::tools::matrix<T>& other) {\n      assert(this->m_rows == other.m_rows);\n\
    \      assert(this->m_cols == other.m_cols);\n      for (::std::size_t i = 0;\
    \ i < this->m_values.size(); ++i) {\n        this->m_values[i] -= other.m_values[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::matrix<T> operator*=(const\
    \ ::tools::matrix<T>& other) {\n      return *this = *this * other;\n    }\n \
    \   ::tools::matrix<T> operator*=(const T& c) {\n      for (::std::size_t i =\
    \ 0; i < this->m_values.size(); ++i) {\n        this->m_values[i] *= c;\n    \
    \  }\n      return *this;\n    }\n    ::tools::matrix<T> operator/=(const T& c)\
    \ {\n      const T c_inv = T(1) / c;\n      for (::std::size_t i = 0; i < this->m_values.size();\
    \ ++i) {\n        this->m_values[i] *= c_inv;\n      }\n      return *this;\n\
    \    }\n    friend bool operator==(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>&\
    \ rhs) {\n      return lhs.m_cols == rhs.m_cols && lhs.m_rows == rhs.m_rows &&\
    \ lhs.m_values == rhs.m_values;\n    }\n    friend bool operator!=(const ::tools::matrix<T>&\
    \ lhs, const ::tools::matrix<T>& rhs) {\n      return !(lhs == rhs);\n    }\n\n\
    \    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::matrix<T>&\
    \ self) {\n      for (::std::size_t r = 0; r < self.m_rows; ++r) {\n        os\
    \ << '[';\n        ::std::string delimiter = \"\";\n        for (::std::size_t\
    \ c = 0; c < self.m_cols; ++c) {\n          os << delimiter << self[r][c];\n \
    \         delimiter = \", \";\n        }\n        os << ']' << '\\n';\n      }\n\
    \      return os;\n    }\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::matrix<T>& self) {\n      for (T& value : self.m_values) {\n  \
    \      is >> value;\n      }\n      return is;\n    }\n\n  private:\n    ::std::pair<::std::size_t,\
    \ T> internal_gauss_jordan() {\n      ::std::size_t rank = 0;\n      T coeff(1);\n\
    \n      for (::std::size_t c = 0; c < this->m_cols; ++c) {\n        ::std::size_t\
    \ pivot;\n        for (pivot = rank; pivot < this->m_rows && (*this)[pivot][c]\
    \ == T(0); ++pivot);\n        if (pivot == this->m_rows) continue;\n\n       \
    \ if (pivot != rank) {\n          for (::std::size_t cc = c; cc < this->m_cols;\
    \ ++cc) {\n            ::std::swap((*this)[rank][cc], (*this)[pivot][cc]);\n \
    \         }\n          coeff *= T(-1);\n        }\n\n        {\n          const\
    \ T scale_inv = T(1) / (*this)[rank][c];\n          for (::std::size_t cc = c;\
    \ cc < this->m_cols; ++cc) {\n            (*this)[rank][cc] *= scale_inv;\n  \
    \        }\n          coeff *= scale_inv;\n        }\n\n        for (::std::size_t\
    \ r = 0; r < this->m_rows; ++r) {\n          if (r == rank) continue;\n      \
    \    const T scale = (*this)[r][c];\n          if (scale == T(0)) continue;\n\
    \          for (::std::size_t cc = c; cc < this->m_cols; ++cc) {\n           \
    \ (*this)[r][cc] -= (*this)[rank][cc] * scale;\n          }\n        }\n\n   \
    \     ++rank;\n      }\n\n      return ::std::make_pair(rank, coeff);\n    }\n\
    \n  public:\n    ::std::size_t gauss_jordan() {\n      return this->internal_gauss_jordan().first;\n\
    \    }\n\n    ::tools::matrix<T> solve(const ::tools::vector<T>& b) const {\n\
    \      assert(this->m_rows == b.size());\n      assert(this->m_cols >= 1);\n \
    \     ::tools::matrix<T> Ab(this->m_rows, this->m_cols + 1);\n      for (::std::size_t\
    \ r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c = 0; c < this->m_cols;\
    \ ++c) {\n          Ab[r][c] = (*this)[r][c];\n        }\n        Ab[r][this->m_cols]\
    \ = b[r];\n      }\n\n      Ab.internal_gauss_jordan();\n\n      ::std::vector<::std::size_t>\
    \ ranks(Ab.cols());\n      for (::std::size_t r = 0, cl = 0, cr = 0; r <= Ab.rows();\
    \ ++r, cl = cr) {\n        for (; cr < Ab.cols() && (r == Ab.rows() || Ab[r][cr]\
    \ == T(0)); ++cr);\n        for (::std::size_t c = cl; c < cr; ++c) {\n      \
    \    ranks[c] = r;\n        }\n      }\n\n      if (ranks[Ab.cols() - 2] < ranks[Ab.cols()\
    \ - 1]) {\n        return ::tools::matrix<T>(this->m_rows, 0);\n      }\n\n  \
    \    ::std::vector<::tools::vector<T>> answers(this->m_cols);\n      ::std::size_t\
    \ free = this->m_cols - ranks.back() - 1;\n\n      for (::std::size_t l = this->m_cols,\
    \ r = this->m_cols; r > 0; r = l) {\n        for (; l > 0 && ranks[l - 1] == ranks[r\
    \ - 1]; --l);\n        for (::std::size_t c = r - 1; c > l; --c) {\n         \
    \ answers[c] = tools::vector<T>(this->m_cols - ranks.back() + 1, T(0));\n    \
    \      answers[c][free] = T(1);\n          --free;\n        }\n        if (ranks[l]\
    \ > 0) {\n          answers[l] = ::tools::vector<T>(this->m_cols - ranks.back()\
    \ + 1, T(0));\n          answers[l][this->m_cols - ranks.back()] = Ab[ranks[l]\
    \ - 1][Ab.cols() - 1];\n          for (::std::size_t c = l + 1; c < Ab.cols()\
    \ - 1; ++c) {\n            answers[l] -= Ab[ranks[l] - 1][c] * answers[c];\n \
    \         }\n        } else {\n          answers[l] = ::tools::vector<T>(this->m_cols\
    \ - ranks.back() + 1, T(0));\n          answers[l][free] = T(1);\n          --free;\n\
    \        }\n      }\n\n      ::tools::matrix<T> answer(this->m_cols, this->m_cols\
    \ - ranks.back() + 1);\n      for (::std::size_t r = 0; r < this->m_cols; ++r)\
    \ {\n        for (::std::size_t c = 0; c < this->m_cols - ranks.back() + 1; ++c)\
    \ {\n          answer[r][c] = answers[r][c];\n        }\n      }\n\n      return\
    \ answer;\n    }\n\n    T determinant() const {\n      assert(this->m_rows ==\
    \ this->m_cols);\n\n      ::tools::matrix<T> A = *this;\n      const auto [rank,\
    \ coeff] = A.internal_gauss_jordan();\n\n      return rank == A.m_rows ? T(1)\
    \ / coeff : T(0);\n    }\n\n    static ::tools::matrix<T> e(const ::std::size_t\
    \ n) {\n      ::tools::matrix<T> result(n, n, T(0));\n      for (::std::size_t\
    \ i = 0; i < n; ++i) {\n        result[i][i] = T(1);\n      }\n      return result;\n\
    \    }\n\n    ::std::optional<::tools::matrix<T>> inv() const {\n      if (this->m_rows\
    \ != this->m_cols) return ::std::nullopt;\n\n      ::tools::matrix<T> AI(this->m_rows,\
    \ this->m_cols * 2);\n      for (::std::size_t r = 0; r < this->m_rows; ++r) {\n\
    \        for (::std::size_t c = 0; c < this->m_cols; ++c) {\n          AI[r][c]\
    \ = (*this)[r][c];\n        }\n        for (::std::size_t c = this->m_cols; c\
    \ < AI.m_cols; ++c) {\n          AI[r][c] = T(0);\n        }\n        AI[r][this->m_cols\
    \ + r] = T(1);\n      }\n\n      AI.internal_gauss_jordan();\n      for (::std::size_t\
    \ i = 0; i < this->m_rows; ++i) {\n        if (AI[i][i] != T(1)) return ::std::nullopt;\n\
    \      }\n\n      ::tools::matrix<T> B(this->m_rows, this->m_cols);\n      for\
    \ (::std::size_t r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c\
    \ = 0; c < this->m_cols; ++c) {\n          B[r][c] = AI[r][this->m_cols + c];\n\
    \        }\n      }\n      return B;\n    }\n\n    ::tools::matrix<T> transposed()\
    \ const {\n      ::tools::matrix<T> A_T(this->m_cols, this->m_rows);\n      for\
    \ (::std::size_t r = 0; r < this->m_rows; ++r) {\n        for (::std::size_t c\
    \ = 0; c < this->m_cols; ++c) {\n          A_T[c][r] = (*this)[r][c];\n      \
    \  }\n      }\n      return A_T;\n    }\n  };\n}\n\n\n#line 7 \"tests/matrix/inv.test.cpp\"\
    \n\nusing ll = long long;\nusing mint = atcoder::modint998244353;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll\
    \ N;\n  std::cin >> N;\n  tools::matrix<mint> A(N, N);\n  for (ll r = 0; r < N;\
    \ ++r) {\n    for (ll c = 0; c < N; ++c) {\n      ll A_rc;\n      std::cin >>\
    \ A_rc;\n      A[r][c] = mint::raw(A_rc);\n    }\n  }\n\n  const auto B = A.inv();\n\
    \  if (!B) {\n    std::cout << -1 << '\\n';\n    return 0;\n  }\n\n  ::tools::matrix<mint>\
    \ AI(N, N * 2);\n  for (ll r = 0; r < N; ++r) {\n    for (ll c = 0; c < N; ++c)\
    \ {\n      AI[r][c] = A[r][c];\n    }\n    for (ll c = N; c < N * 2; ++c) {\n\
    \      AI[r][c] = mint(0);\n    }\n    AI[r][N + r] = mint(1);\n  }\n  AI.gauss_jordan();\n\
    \n  for (ll r = 0; r < N; ++r) {\n    std::string delimiter = \"\";\n    for (ll\
    \ c = 0; c < N; ++c) {\n      std::cout << delimiter << (*B)[r][c].val();\n  \
    \    delimiter = \" \";\n    }\n    std::cout << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ <iostream>\n#include <string>\n#include \"atcoder/modint.hpp\"\n#include \"\
    tools/matrix.hpp\"\n\nusing ll = long long;\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n  tools::matrix<mint> A(N, N);\n  for (ll r = 0;\
    \ r < N; ++r) {\n    for (ll c = 0; c < N; ++c) {\n      ll A_rc;\n      std::cin\
    \ >> A_rc;\n      A[r][c] = mint::raw(A_rc);\n    }\n  }\n\n  const auto B = A.inv();\n\
    \  if (!B) {\n    std::cout << -1 << '\\n';\n    return 0;\n  }\n\n  ::tools::matrix<mint>\
    \ AI(N, N * 2);\n  for (ll r = 0; r < N; ++r) {\n    for (ll c = 0; c < N; ++c)\
    \ {\n      AI[r][c] = A[r][c];\n    }\n    for (ll c = N; c < N * 2; ++c) {\n\
    \      AI[r][c] = mint(0);\n    }\n    AI[r][N + r] = mint(1);\n  }\n  AI.gauss_jordan();\n\
    \n  for (ll r = 0; r < N; ++r) {\n    std::string delimiter = \"\";\n    for (ll\
    \ c = 0; c < N; ++c) {\n      std::cout << delimiter << (*B)[r][c].val();\n  \
    \    delimiter = \" \";\n    }\n    std::cout << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/matrix.hpp
  - tools/vector.hpp
  - tools/abs.hpp
  - tools/tuple_hash.hpp
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: true
  path: tests/matrix/inv.test.cpp
  requiredBy: []
  timestamp: '2024-03-02 22:50:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/matrix/inv.test.cpp
layout: document
redirect_from:
- /verify/tests/matrix/inv.test.cpp
- /verify/tests/matrix/inv.test.cpp.html
title: tests/matrix/inv.test.cpp
---
