---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':question:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc334/tasks/abc334_g
    links:
    - https://atcoder.jp/contests/abc334/tasks/abc334_g
  bundledCode: "#line 1 \"tests/lowlink/ncc_without_vertex.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc334/tasks/abc334_g\"\n\n#include <iostream>\n\
    #include <vector>\n#include <string>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/lowlink.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 6 \"tools/lowlink.hpp\"\n#include <iterator>\n\
    #line 8 \"tools/lowlink.hpp\"\n#include <tuple>\n#include <algorithm>\n#include\
    \ <limits>\n#include <stack>\n#line 13 \"tools/lowlink.hpp\"\n#include <initializer_list>\n\
    #line 1 \"tools/chmin.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line\
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
    #line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class F>\n\
    \  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/fix.hpp\"\n\n\n\n#line 6 \"tools/fix.hpp\"\
    \n\nnamespace tools {\n  template <typename F>\n  struct fix : F {\n    template\
    \ <typename G>\n    fix(G&& g) : F({::std::forward<G>(g)}) {\n    }\n\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args&&... args) const {\n\
    \      return F::operator()(*this, ::std::forward<Args>(args)...);\n    }\n  };\n\
    \n  template <typename F>\n  fix(F&&) -> fix<::std::decay_t<F>>;\n}\n\n\n#line\
    \ 17 \"tools/lowlink.hpp\"\n\nnamespace tools {\n  class lowlink {\n  public:\n\
    \    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n     \
    \ ::std::size_t to;\n    };\n\n  private:\n    ::std::vector<edge> m_edges;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_graph;\n    bool m_built;\n\
    \    ::std::vector<::std::size_t> m_from;\n    ::std::vector<::std::size_t> m_ord;\n\
    \    ::std::vector<::std::size_t> m_low;\n    ::std::size_t m_ncc;\n    ::std::vector<::std::size_t>\
    \ m_ncc_without_vertex;\n\n  public:\n    class neighbors_iterable {\n    private:\n\
    \      ::tools::lowlink const *m_parent;\n      ::std::size_t m_v;\n\n    public:\n\
    \      class iterator {\n      private:\n        ::tools::lowlink const *m_parent;\n\
    \        ::std::size_t m_v;\n        ::std::size_t m_i;\n\n      public:\n   \
    \     using difference_type = ::std::ptrdiff_t;\n        using value_type = ::std::size_t;\n\
    \        using reference = const ::std::size_t&;\n        using pointer = const\
    \ ::std::size_t*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::lowlink const * const\
    \ parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v),\
    \ m_i(i) {\n        }\n\n        value_type operator*() const {\n          const\
    \ auto& edge = this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n\
    \          return edge.from ^ edge.to ^ this->m_v;\n        }\n        iterator&\
    \ operator++() {\n          ++this->m_i;\n          return *this;\n        }\n\
    \        iterator operator++(int) {\n          const auto self = *this;\n    \
    \      ++*this;\n          return self;\n        }\n        friend bool operator==(const\
    \ iterator& lhs, const iterator& rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n\
    \          assert(lhs.m_v == rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n\
    \        }\n        friend bool operator!=(const iterator& lhs, const iterator&\
    \ rhs) {\n          return !(lhs == rhs);\n        }\n      };\n\n      neighbors_iterable()\
    \ = default;\n      neighbors_iterable(::tools::lowlink const * const parent,\
    \ const ::std::size_t v) : m_parent(parent), m_v(v) {\n      }\n\n      iterator\
    \ begin() const {\n        return iterator(this->m_parent, this->m_v, 0);\n  \
    \    };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    class edges_iterable {\n    private:\n      ::tools::lowlink const *m_parent;\n\
    \      ::std::size_t m_v;\n\n    public:\n      class iterator {\n      private:\n\
    \        ::tools::lowlink const *m_parent;\n        ::std::size_t m_v;\n     \
    \   ::std::size_t m_i;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = edge;\n        using reference = const edge&;\n  \
    \      using pointer = const edge*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::lowlink const * const\
    \ parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v),\
    \ m_i(i) {\n        }\n\n        reference operator*() const {\n          return\
    \ this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n  \
    \      }\n        iterator& operator++() {\n          ++this->m_i;\n         \
    \ return *this;\n        }\n        iterator operator++(int) {\n          const\
    \ auto self = *this;\n          ++*this;\n          return self;\n        }\n\
    \        friend bool operator==(const iterator& lhs, const iterator& rhs) {\n\
    \          assert(lhs.m_parent == rhs.m_parent);\n          assert(lhs.m_v ==\
    \ rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n        }\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      edges_iterable() = default;\n      edges_iterable(::tools::lowlink\
    \ const * const parent, const ::std::size_t v) : m_parent(parent), m_v(v) {\n\
    \      }\n\n      iterator begin() const {\n        return iterator(this->m_parent,\
    \ this->m_v, 0);\n      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    class vchildren_iterable {\n    private:\n      ::tools::lowlink const *m_parent;\n\
    \      ::std::size_t m_v;\n\n    public:\n      class iterator {\n      private:\n\
    \        ::tools::lowlink const *m_parent;\n        ::std::size_t m_v;\n     \
    \   ::std::size_t m_i;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = ::std::size_t;\n        using reference = const ::std::size_t&;\n\
    \        using pointer = const ::std::size_t*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator() = default;\n        iterator(::tools::lowlink\
    \ const * const parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent),\
    \ m_v(v), m_i(i) {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          for (; this->m_i < eids.size() && [&]() {\n            const auto eid\
    \ = eids[this->m_i];\n            const auto& edge = this->m_parent->m_edges[eid];\n\
    \            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] !=\
    \ eid;\n          }(); ++this->m_i);\n        }\n\n        value_type operator*()\
    \ const {\n          const auto& edge = this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n\
    \          return edge.from ^ edge.to ^ this->m_v;\n        }\n        iterator&\
    \ operator++() {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          assert(this->m_i < eids.size());\n\n          for (++this->m_i; this->m_i\
    \ < eids.size() && [&]() {\n            const auto eid = eids[this->m_i];\n  \
    \          const auto& edge = this->m_parent->m_edges[eid];\n            return\
    \ this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;\n          }();\
    \ ++this->m_i);\n\n          return *this;\n        }\n        iterator operator++(int)\
    \ {\n          const auto self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n        friend bool operator==(const iterator& lhs, const\
    \ iterator& rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n        \
    \  assert(lhs.m_v == rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n       \
    \ }\n        friend bool operator!=(const iterator& lhs, const iterator& rhs)\
    \ {\n          return !(lhs == rhs);\n        }\n      };\n\n      vchildren_iterable()\
    \ = default;\n      vchildren_iterable(::tools::lowlink const * const parent,\
    \ const ::std::size_t v) : m_parent(parent), m_v(v) {\n      }\n\n      iterator\
    \ begin() const {\n        return iterator(this->m_parent, this->m_v, 0);\n  \
    \    };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    class echildren_iterable {\n    private:\n      ::tools::lowlink const *m_parent;\n\
    \      ::std::size_t m_v;\n\n    public:\n      class iterator {\n      private:\n\
    \        ::tools::lowlink const *m_parent;\n        ::std::size_t m_v;\n     \
    \   ::std::size_t m_i;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = edge;\n        using reference = const edge&;\n  \
    \      using pointer = const edge*;\n        using iterator_category = ::std::input_iterator_tag;\n\
    \n        iterator() = default;\n        iterator(::tools::lowlink const * const\
    \ parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v),\
    \ m_i(i) {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          for (; this->m_i < eids.size() && [&]() {\n            const auto eid\
    \ = eids[this->m_i];\n            const auto& edge = this->m_parent->m_edges[eid];\n\
    \            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] !=\
    \ eid;\n          }(); ++this->m_i);\n        }\n\n        reference operator*()\
    \ const {\n          return this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];\n\
    \        }\n        iterator& operator++() {\n          const auto& eids = this->m_parent->m_graph[this->m_v];\n\
    \          assert(this->m_i < eids.size());\n\n          for (++this->m_i; this->m_i\
    \ < eids.size() && [&]() {\n            const auto eid = eids[this->m_i];\n  \
    \          const auto& edge = this->m_parent->m_edges[eid];\n            return\
    \ this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;\n          }();\
    \ ++this->m_i);\n\n          return *this;\n        }\n        iterator operator++(int)\
    \ {\n          const auto self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n        friend bool operator==(const iterator& lhs, const\
    \ iterator& rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n        \
    \  assert(lhs.m_v == rhs.m_v);\n          return lhs.m_i == rhs.m_i;\n       \
    \ }\n        friend bool operator!=(const iterator& lhs, const iterator& rhs)\
    \ {\n          return !(lhs == rhs);\n        }\n      };\n\n      echildren_iterable()\
    \ = default;\n      echildren_iterable(::tools::lowlink const * const parent,\
    \ const ::std::size_t v) : m_parent(parent), m_v(v) {\n      }\n\n      iterator\
    \ begin() const {\n        return iterator(this->m_parent, this->m_v, 0);\n  \
    \    };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    lowlink() = default;\n    explicit lowlink(const ::std::size_t n) : m_graph(n),\
    \ m_built(false) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v) {\n   \
    \   assert(!this->m_built);\n      assert(u < this->size());\n      assert(v <\
    \ this->size());\n      ::std::tie(u, v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v});\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n     \
    \ this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    neighbors_iterable neighbors(const ::std::size_t v) const {\n  \
    \    assert(v < this->size());\n      return neighbors_iterable(this, v);\n  \
    \  }\n\n    edges_iterable edges(const ::std::size_t v) const {\n      assert(v\
    \ < this->size());\n      return edges_iterable(this, v);\n    }\n\n    void build()\
    \ {\n      assert(!this->m_built);\n      this->m_built = true;\n\n      const\
    \ auto N_A = ::std::numeric_limits<::std::size_t>::max();\n\n      this->m_from.assign(this->size(),\
    \ N_A);\n      this->m_ord.assign(this->size(), N_A);\n      this->m_low.assign(this->size(),\
    \ N_A);\n      this->m_ncc = 0;\n\n      for (::std::size_t r = 0; r < this->size();\
    \ ++r) {\n        if (this->m_ord[r] != N_A) continue;\n\n        ++this->m_ncc;\n\
    \        ::std::size_t next_ord = 0;\n\n        ::std::stack<::std::pair<::std::size_t,\
    \ ::std::size_t>> stack;\n        stack.emplace(r, N_A);\n        stack.emplace(r,\
    \ N_A - 1);\n        while (!stack.empty()) {\n          const auto [v, from]\
    \ = stack.top();\n          stack.pop();\n\n          if (from != N_A) {\n   \
    \         if (this->m_ord[v] != N_A) continue;\n\n            this->m_from[v]\
    \ = from;\n            this->m_ord[v] = next_ord++;\n\n            for (const\
    \ auto eid : this->m_graph[v]) {\n              const auto& edge = this->m_edges[eid];\n\
    \              const auto u = edge.from ^ edge.to ^ v;\n              if (this->m_ord[u]\
    \ != N_A) continue;\n\n              stack.emplace(u, N_A);\n              stack.emplace(u,\
    \ eid);\n            }\n          } else {\n            if (this->m_low[v] !=\
    \ N_A) continue;\n\n            this->m_low[v] = this->m_ord[v];\n           \
    \ for (const auto eid : this->m_graph[v]) {\n              const auto& edge =\
    \ this->m_edges[eid];\n              const auto u = edge.from ^ edge.to ^ v;\n\
    \              if (this->m_ord[u] < this->m_ord[v] && eid != this->m_from[v])\
    \ {\n                ::tools::chmin(this->m_low[v], this->m_ord[u]);\n       \
    \       } else if (this->m_ord[u] > this->m_ord[v] && eid == this->m_from[u])\
    \ {\n                ::tools::chmin(this->m_low[v], this->m_low[u]);\n       \
    \       }\n            }\n          }\n        }\n\n        this->m_from[r] =\
    \ N_A;\n      }\n\n      this->m_ncc_without_vertex.assign(this->size(), this->m_ncc);\n\
    \      for (::std::size_t v = 0; v < this->size(); ++v) {\n        if (this->m_ord[v]\
    \ == 0) {\n          this->m_ncc_without_vertex[v] += ::std::distance(this->echildren(v).begin(),\
    \ this->echildren(v).end());\n          --this->m_ncc_without_vertex[v];\n   \
    \     } else {\n          for (const auto& edge : this->echildren(v)) {\n    \
    \        const auto u = edge.from ^ edge.to ^ v;\n            if (this->m_ord[v]\
    \ <= this->m_low[u]) {\n              ++this->m_ncc_without_vertex[v];\n     \
    \       }\n          }\n        }\n      }\n    }\n\n    ::std::size_t vparent(const\
    \ ::std::size_t v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      assert(this->m_ord[v] > 0);\n\n      const auto& edge = this->m_edges[this->m_from[v]];\n\
    \      return edge.from ^ edge.to ^ v;\n    }\n\n    const edge& eparent(const\
    \ ::std::size_t v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      assert(this->m_ord[v] > 0);\n\n      return this->m_edges[this->m_from[v]];\n\
    \    }\n\n    vchildren_iterable vchildren(const ::std::size_t v) const {\n  \
    \    assert(this->m_built);\n      assert(v < this->size());\n\n      return vchildren_iterable(this,\
    \ v);\n    }\n\n    echildren_iterable echildren(const ::std::size_t v) const\
    \ {\n      assert(this->m_built);\n      assert(v < this->size());\n\n      return\
    \ echildren_iterable(this, v);\n    }\n\n    ::std::size_t ord(const ::std::size_t\
    \ v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\n\
    \      return this->m_ord[v];\n    }\n\n    ::std::size_t low(const ::std::size_t\
    \ v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\n\
    \      return this->m_low[v];\n    }\n\n    ::std::size_t ncc() const {\n    \
    \  assert(this->m_built);\n\n      return this->m_ncc;\n    }\n\n    ::std::size_t\
    \ ncc_without_vertex(const ::std::size_t v) const {\n      assert(this->m_built);\n\
    \      assert(v < this->size());\n\n      return this->m_ncc_without_vertex[v];\n\
    \    }\n\n    bool is_articulation_point(const ::std::size_t v) const {\n    \
    \  assert(this->m_built);\n      assert(v < this->size());\n\n      return this->m_ncc_without_vertex[v]\
    \ > this->m_ncc;\n    }\n\n    bool is_bridge(const ::std::size_t k) const {\n\
    \      assert(this->m_built);\n      assert(k < this->m_edges.size());\n\n   \
    \   const auto [u, v] = ::std::minmax({this->m_edges[k].from, this->m_edges[k].to},\
    \ ::tools::less_by([&](const auto w) { return this->m_ord[w]; }));\n      return\
    \ this->m_ord[u] < this->m_low[v];\n    }\n\n    ::std::vector<::std::vector<::std::size_t>>\
    \ biconnected_components() const {\n      assert(this->m_built);\n\n      ::std::vector<::std::vector<::std::size_t>>\
    \ groups;\n\n      for (::std::size_t r = 0; r < this->size(); ++r) {\n      \
    \  if (this->ord(r) == 0) {\n          if (this->m_ncc_without_vertex[r] < this->m_ncc)\
    \ {\n            groups.emplace_back(::std::initializer_list<::std::size_t>{r});\n\
    \          } else {\n            ::tools::fix([&](auto&& dfs, const auto g, const\
    \ auto v) -> void {\n              for (const auto u : this->vchildren(v)) {\n\
    \                if (this->ord(v) <= this->low(u)) {\n                  groups.emplace_back(::std::initializer_list<::std::size_t>{v,\
    \ u});\n                  dfs(groups.size() - 1, u);\n                } else {\n\
    \                  groups[g].push_back(u);\n                  dfs(g, u);\n   \
    \             }\n              }\n            })(::std::numeric_limits<::std::size_t>::max(),\
    \ r);\n          }\n        }\n      }\n\n      return groups;\n    }\n  };\n\
    }\n\n\n#line 8 \"tests/lowlink/ncc_without_vertex.test.cpp\"\n\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int H, W;\n  std::cin >> H >> W;\n  std::vector<std::string> S(H);\n  for\
    \ (auto&& S_i : S) std::cin >> S_i;\n\n  auto V = std::vector(H, std::vector<int>(W,\
    \ -1));\n  int k = 0;\n  for (int i = 0; i < H; ++i) {\n    for (int j = 0; j\
    \ < W; ++j) {\n      if (S[i][j] == '#') {\n        V[i][j] = k++;\n      }\n\
    \    }\n  }\n\n  tools::lowlink graph(k);\n  for (int i = 0; i < H; ++i) {\n \
    \   for (int j = 0; j < W; ++j) {\n      if (i + 1 < H && S[i][j] == '#' && S[i\
    \ + 1][j] == '#') {\n        graph.add_edge(V[i][j], V[i + 1][j]);\n      }\n\
    \      if (j + 1 < W && S[i][j] == '#' && S[i][j + 1] == '#') {\n        graph.add_edge(V[i][j],\
    \ V[i][j + 1]);\n      }\n    }\n  }\n\n  graph.build();\n\n  auto answer = mint::raw(0);\n\
    \  for (int v = 0; v < k; ++v) {\n    answer += mint::raw(graph.ncc_without_vertex(v));\n\
    \  }\n  answer /= mint::raw(k);\n\n  std::cout << answer.val() << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc334/tasks/abc334_g\"\n\n\
    #include <iostream>\n#include <vector>\n#include <string>\n#include \"atcoder/modint.hpp\"\
    \n#include \"tools/lowlink.hpp\"\n\nusing mint = atcoder::modint998244353;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int H, W;\n  std::cin >> H >> W;\n  std::vector<std::string> S(H);\n  for\
    \ (auto&& S_i : S) std::cin >> S_i;\n\n  auto V = std::vector(H, std::vector<int>(W,\
    \ -1));\n  int k = 0;\n  for (int i = 0; i < H; ++i) {\n    for (int j = 0; j\
    \ < W; ++j) {\n      if (S[i][j] == '#') {\n        V[i][j] = k++;\n      }\n\
    \    }\n  }\n\n  tools::lowlink graph(k);\n  for (int i = 0; i < H; ++i) {\n \
    \   for (int j = 0; j < W; ++j) {\n      if (i + 1 < H && S[i][j] == '#' && S[i\
    \ + 1][j] == '#') {\n        graph.add_edge(V[i][j], V[i + 1][j]);\n      }\n\
    \      if (j + 1 < W && S[i][j] == '#' && S[i][j + 1] == '#') {\n        graph.add_edge(V[i][j],\
    \ V[i][j + 1]);\n      }\n    }\n  }\n\n  graph.build();\n\n  auto answer = mint::raw(0);\n\
    \  for (int v = 0; v < k; ++v) {\n    answer += mint::raw(graph.ncc_without_vertex(v));\n\
    \  }\n  answer /= mint::raw(k);\n\n  std::cout << answer.val() << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/lowlink.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/less_by.hpp
  - tools/fix.hpp
  isVerificationFile: true
  path: tests/lowlink/ncc_without_vertex.test.cpp
  requiredBy: []
  timestamp: '2024-08-27 00:30:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lowlink/ncc_without_vertex.test.cpp
layout: document
redirect_from:
- /verify/tests/lowlink/ncc_without_vertex.test.cpp
- /verify/tests/lowlink/ncc_without_vertex.test.cpp.html
title: tests/lowlink/ncc_without_vertex.test.cpp
---
