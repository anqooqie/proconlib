---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: Unified interface for std::abs(x) and x.abs()
  - icon: ':heavy_check_mark:'
    path: tools/detail/vector_common.hpp
    title: tools/detail/vector_common.hpp
  - icon: ':heavy_check_mark:'
    path: tools/matrix.hpp
    title: Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"tests/matrix/determinant.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/matrix_det\"\n\n#include <iostream>\n#line 1 \"\
    lib/ac-library/atcoder/modint.hpp\"\n\n\n\n#include <cassert>\n#include <numeric>\n\
    #include <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line\
    \ 1 \"lib/ac-library/atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n\
    #ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long\
    \ safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n\
    \    return x;\n}\n\n// Fast modular multiplication by barrett reduction\n// Reference:\
    \ https://en.wikipedia.org/wiki/Barrett_reduction\n// NOTE: reconsider after Ice\
    \ Lake\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n\n\
    \    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned int m) : _m(m),\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/matrix.hpp\"\
    \n\n\n\n#include <vector>\n#include <cstddef>\n#line 8 \"tools/matrix.hpp\"\n\
    #include <string>\n#include <optional>\n#line 1 \"tools/vector.hpp\"\n\n\n\n#line\
    \ 6 \"tools/vector.hpp\"\n#include <initializer_list>\n#line 1 \"tools/detail/vector_common.hpp\"\
    \n\n\n\n#line 7 \"tools/detail/vector_common.hpp\"\n#include <algorithm>\n#include\
    \ <cmath>\n#line 1 \"tools/abs.hpp\"\n\n\n\n#line 5 \"tools/abs.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(::std::abs(v))\
    \ {\n    return ::std::abs(v);\n  }\n\n  template <typename T>\n  auto abs(const\
    \ T& v) -> decltype(v.abs()) {\n    return v.abs();\n  }\n}\n\n\n#line 12 \"tools/detail/vector_common.hpp\"\
    \n\n#define TOOLS_DETAIL_VECTOR_COMMON(V) \\\n  private:\\\n    using F = ::std::conditional_t<::std::is_floating_point_v<T>,\
    \ T, double>;\\\n\\\n  public:\\\n    V operator+() const {\\\n      return *this;\\\
    \n    }\\\n\\\n    V operator-() const {\\\n      V res = *this;\\\n      for\
    \ (auto& v : res) {\\\n        v = -v;\\\n      }\\\n      return res;\\\n   \
    \ }\\\n\\\n    V& operator+=(const V& other) {\\\n      assert(this->size() ==\
    \ other.size());\\\n      for (::std::size_t i = 0; i < this->size(); ++i) {\\\
    \n        (*this)[i] += other[i];\\\n      }\\\n      return *this;\\\n    }\\\
    \n    friend V operator+(const V& lhs, const V& rhs) {\\\n      return V(lhs)\
    \ += rhs;\\\n    }\\\n\\\n    V& operator-=(const V& other) {\\\n      assert(this->size()\
    \ == other.size());\\\n      for (::std::size_t i = 0; i < this->size(); ++i)\
    \ {\\\n        (*this)[i] -= other[i];\\\n      }\\\n      return *this;\\\n \
    \   }\\\n    friend V operator-(const V& lhs, const V& rhs) {\\\n      return\
    \ V(lhs) -= rhs;\\\n    }\\\n\\\n    V& operator*=(const T& c) {\\\n      for\
    \ (auto& v : *this) {\\\n        v *= c;\\\n      }\\\n      return *this;\\\n\
    \    }\\\n    friend V operator*(const T& lhs, const V& rhs) {\\\n      return\
    \ V(rhs) *= lhs;\\\n    }\\\n    friend V operator*(const V& lhs, const T& rhs)\
    \ {\\\n      return V(lhs) *= rhs;\\\n    }\\\n\\\n    V& operator/=(const T&\
    \ c) {\\\n      for (auto& v : *this) {\\\n        v /= c;\\\n      }\\\n    \
    \  return *this;\\\n    }\\\n    friend V operator/(const V& lhs, const T& rhs)\
    \ {\\\n      return V(lhs) /= rhs;\\\n    }\\\n\\\n    friend bool operator==(const\
    \ V& lhs, const V& rhs) {\\\n      return ::std::equal(lhs.begin(), lhs.end(),\
    \ rhs.begin());\\\n    }\\\n    friend bool operator!=(const V& lhs, const V&\
    \ rhs) {\\\n      return !(lhs == rhs);\\\n    }\\\n\\\n    T inner_product(const\
    \ V& other) const {\\\n      assert(this->size() == other.size());\\\n      T\
    \ res(0);\\\n      for (::std::size_t i = 0; i < this->size(); ++i) {\\\n    \
    \    res += (*this)[i] * other[i];\\\n      }\\\n      return res;\\\n    }\\\n\
    \\\n    T l1_norm() const {\\\n      T res(0);\\\n      for (const auto& v : *this)\
    \ {\\\n        res += ::tools::abs(v);\\\n      }\\\n      return res;\\\n   \
    \ }\\\n\\\n    T squared_l2_norm() const {\\\n      return this->inner_product(*this);\\\
    \n    }\\\n\\\n    F l2_norm() const {\\\n      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\\\
    \n    }\\\n\\\n    template <typename T_ = T>\\\n    ::std::enable_if_t<::std::is_floating_point_v<T_>,\
    \ V> normalized() const {\\\n      return *this / this->l2_norm();\\\n    }\\\n\
    \\\n    friend ::std::ostream& operator<<(::std::ostream& os, const V& self) {\\\
    \n      os << '(';\\\n      ::std::string delimiter = \"\";\\\n      for (const\
    \ auto& v : self) {\\\n        os << delimiter << v;\\\n        delimiter = \"\
    , \";\\\n      }\\\n      return os << ')';\\\n    }\\\n\\\n    friend ::std::istream&\
    \ operator>>(::std::istream& is, V& self) {\\\n      for (auto& v : self) {\\\n\
    \        is >> v;\\\n      }\\\n      return is;\\\n    }\n\n\n#line 8 \"tools/vector.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class vector {\n  private:\n\
    \    ::std::vector<T> m_values;\n\n  public:\n    using reference = T&;\n    using\
    \ const_reference = const T&;\n    using size_type = ::std::size_t;\n    using\
    \ difference_type = ::std::ptrdiff_t;\n    using pointer = T*;\n    using const_pointer\
    \ = const T*;\n    using value_type = T;\n    using iterator = typename ::std::vector<T>::iterator;\n\
    \    using const_iterator = typename ::std::vector<T>::const_iterator;\n    using\
    \ reverse_iterator = typename ::std::vector<T>::reverse_iterator;\n    using const_reverse_iterator\
    \ = typename ::std::vector<T>::const_reverse_iterator;\n\n    vector() = default;\n\
    \    vector(const ::tools::vector<T>&) = default;\n    vector(::tools::vector<T>&&)\
    \ = default;\n    ~vector() = default;\n    ::tools::vector<T>& operator=(const\
    \ ::tools::vector<T>&) = default;\n    ::tools::vector<T>& operator=(::tools::vector<T>&&)\
    \ = default;\n\n    explicit vector(size_type n) : m_values(n) {}\n    vector(size_type\
    \ n, const_reference value) : m_values(n, value) {}\n    template <typename InputIter>\
    \ vector(const InputIter first, const InputIter last) : m_values(first, last)\
    \ {}\n    vector(const ::std::initializer_list<T> il) : m_values(il) {}\n\n  \
    \  iterator begin() { return this->m_values.begin(); }\n    const_iterator begin()\
    \ const { return this->m_values.begin(); }\n    iterator end() { return this->m_values.end();\
    \ }\n    const_iterator end() const { return this->m_values.end(); }\n    const_iterator\
    \ cbegin() const { return this->m_values.cbegin(); }\n    const_iterator cend()\
    \ const { return this->m_values.cend(); }\n    reverse_iterator rbegin() { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator rbegin() const { return\
    \ this->m_values.rbegin(); }\n    const_reverse_iterator crbegin() const { return\
    \ this->m_values.crbegin(); }\n    reverse_iterator rend() { return this->m_values.rend();\
    \ }\n    const_reverse_iterator rend() const { return this->m_values.rend(); }\n\
    \    const_reverse_iterator crend() const { return this->m_values.crend(); }\n\
    \n    size_type size() const { return this->m_values.size(); }\n    bool empty()\
    \ const { return this->m_values.empty(); }\n\n    reference operator[](const size_type\
    \ n) { return this->m_values[n]; }\n    const_reference operator[](const size_type\
    \ n) const { return this->m_values[n]; }\n    reference front() { return *this->begin();\
    \ }\n    const_reference front() const { return *this->begin(); }\n    reference\
    \ back() { return *this->rbegin(); }\n    const_reference back() const { return\
    \ *this->rbegin(); }\n\n    void swap(::tools::vector<T>& other) { this->m_values.swap(other.m_values);\
    \ }\n\n    TOOLS_DETAIL_VECTOR_COMMON(::tools::vector<T>)\n  };\n}\n\n\n#line\
    \ 11 \"tools/matrix.hpp\"\n\nnamespace tools {\n  template <typename T>\n  class\
    \ matrix {\n  private:\n    ::std::vector<T> m_values;\n    ::std::size_t m_rows;\n\
    \    ::std::size_t m_cols;\n\n  public:\n    matrix() = default;\n    matrix(const\
    \ ::tools::matrix<T>&) = default;\n    matrix(::tools::matrix<T>&&) = default;\n\
    \    ~matrix() = default;\n    ::tools::matrix<T>& operator=(const ::tools::matrix<T>&)\
    \ = default;\n    ::tools::matrix<T>& operator=(::tools::matrix<T>&&) = default;\n\
    \n    matrix(::std::size_t rows, ::std::size_t cols) :\n      m_values(rows *\
    \ cols), m_rows(rows), m_cols(cols) {\n    }\n    matrix(::std::size_t rows, ::std::size_t\
    \ cols, const T& value) :\n      m_values(rows * cols, value), m_rows(rows), m_cols(cols)\
    \ {\n    }\n\n    typename ::std::vector<T>::iterator operator[](const ::std::size_t\
    \ r) {\n      return this->m_values.begin() + r * this->m_cols;\n    }\n    typename\
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
    \        }\n      }\n      return B;\n    }\n  };\n}\n\n\n#line 6 \"tests/matrix/determinant.test.cpp\"\
    \n\nusing ll = long long;\nusing mint = atcoder::modint998244353;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll\
    \ N;\n  std::cin >> N;\n  tools::matrix<mint> A(N, N);\n  for (ll r = 0; r < N;\
    \ ++r) {\n    for (ll c = 0; c < N; ++c) {\n      ll A_rc;\n      std::cin >>\
    \ A_rc;\n      A[r][c] = mint::raw(A_rc);\n    }\n  }\n\n  std::cout << A.determinant().val()\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <iostream>\n#include \"atcoder/modint.hpp\"\n#include \"tools/matrix.hpp\"\n\
    \nusing ll = long long;\nusing mint = atcoder::modint998244353;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll\
    \ N;\n  std::cin >> N;\n  tools::matrix<mint> A(N, N);\n  for (ll r = 0; r < N;\
    \ ++r) {\n    for (ll c = 0; c < N; ++c) {\n      ll A_rc;\n      std::cin >>\
    \ A_rc;\n      A[r][c] = mint::raw(A_rc);\n    }\n  }\n\n  std::cout << A.determinant().val()\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/matrix.hpp
  - tools/vector.hpp
  - tools/detail/vector_common.hpp
  - tools/abs.hpp
  isVerificationFile: true
  path: tests/matrix/determinant.test.cpp
  requiredBy: []
  timestamp: '2022-10-29 17:35:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/matrix/determinant.test.cpp
layout: document
redirect_from:
- /verify/tests/matrix/determinant.test.cpp
- /verify/tests/matrix/determinant.test.cpp.html
title: tests/matrix/determinant.test.cpp
---
