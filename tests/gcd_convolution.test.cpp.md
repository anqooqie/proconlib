---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/gcd_convolution.hpp
    title: GCD convolution
  - icon: ':x:'
    path: tools/osa_k.hpp
    title: osa_k's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"tests/gcd_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\
    \n\n#include <iostream>\n#include <vector>\n#include <string>\n#line 1 \"lib/ac-library/atcoder/modint.hpp\"\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"tools/gcd_convolution.hpp\"\
    \n\n\n\n#line 6 \"tools/gcd_convolution.hpp\"\n#include <algorithm>\n#include\
    \ <cstddef>\n#include <iterator>\n#line 1 \"tools/osa_k.hpp\"\n\n\n\n#line 9 \"\
    tools/osa_k.hpp\"\n#include <limits>\n#line 11 \"tools/osa_k.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class osa_k {\n  private:\n    ::std::vector<T>\
    \ m_min_prime_factors;\n    ::std::vector<T> m_divisor_counts;\n\n    T size()\
    \ const {\n      return this->m_min_prime_factors.size();\n    }\n\n  public:\n\
    \    class prime_factor_iterable {\n    private:\n      const ::std::vector<T>&\
    \ m_min_prime_factors;\n      T m_n;\n\n    public:\n      class iterator {\n\
    \      private:\n        const ::std::vector<T>& m_min_prime_factors;\n      \
    \  T m_n;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator(const ::std::vector<T>& min_prime_factors, const T& n) :\n     \
    \     m_min_prime_factors(min_prime_factors),\n          m_n(n) {\n        }\n\
    \n        iterator(const iterator& other) = default;\n        ~iterator() = default;\n\
    \        iterator& operator=(const iterator& other) = default;\n\n        T operator*()\
    \ const {\n          return this->m_min_prime_factors[this->m_n];\n        }\n\
    \n        iterator& operator++() {\n          this->m_n /= **this;\n         \
    \ return *this;\n        }\n\n        iterator operator++(int) {\n          const\
    \ iterator self = *this;\n          ++*this;\n          return self;\n       \
    \ }\n\n        friend bool operator==(const iterator& lhs, const iterator& rhs)\
    \ {\n          return lhs.m_n == rhs.m_n;\n        }\n\n        friend bool operator!=(const\
    \ iterator& lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n   \
    \     }\n      };\n\n      prime_factor_iterable(const ::std::vector<T>& min_prime_factors,\
    \ const T& n) :\n        m_min_prime_factors(min_prime_factors),\n        m_n(n)\
    \ {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_min_prime_factors,\
    \ this->m_n);\n      };\n\n      iterator end() const {\n        return iterator(this->m_min_prime_factors,\
    \ 1);\n      }\n    };\n\n    class distinct_prime_factor_iterable {\n    private:\n\
    \      const ::std::vector<T>& m_min_prime_factors;\n      T m_n;\n\n    public:\n\
    \      class iterator {\n      private:\n        const ::std::vector<T>& m_min_prime_factors;\n\
    \        T m_n;\n        bool m_evaluated;\n        ::std::pair<T, T> m_value;\n\
    \        T m_next_n;\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = ::std::pair<T, T>;\n        using reference = ::std::pair<T,\
    \ T>&;\n        using pointer = ::std::pair<T, T>*;\n        using iterator_category\
    \ = ::std::input_iterator_tag;\n\n        iterator(const ::std::vector<T>& min_prime_factors,\
    \ const T& n) :\n          m_min_prime_factors(min_prime_factors),\n         \
    \ m_n(n),\n          m_evaluated(false) {\n        }\n\n        iterator(const\
    \ iterator& other) = default;\n        ~iterator() = default;\n        iterator&\
    \ operator=(const iterator& other) = default;\n\n        iterator& operator++()\
    \ {\n          **this;\n          this->m_n = this->m_next_n;\n          this->m_evaluated\
    \ = false;\n          return *this;\n        }\n\n        iterator operator++(int)\
    \ {\n          **this;\n          const iterator self = *this;\n          this->m_n\
    \ = this->m_next_n;\n          this->m_evaluated = false;\n          return self;\n\
    \        }\n\n        ::std::pair<T, T> operator*() {\n          if (!this->m_evaluated)\
    \ {\n            for (\n              this->m_next_n = this->m_n, this->m_value\
    \ = ::std::make_pair(this->m_min_prime_factors[this->m_n], 0);\n             \
    \ this->m_min_prime_factors[this->m_next_n] == this->m_min_prime_factors[this->m_n];\n\
    \              this->m_next_n /= this->m_min_prime_factors[this->m_n], ++this->m_value.second\n\
    \            );\n            this->m_evaluated = true;\n          }\n        \
    \  return this->m_value;\n        }\n\n        friend bool operator==(const iterator&\
    \ lhs, const iterator& rhs) {\n          return lhs.m_n == rhs.m_n;\n        }\n\
    \n        friend bool operator!=(const iterator& lhs, const iterator& rhs) {\n\
    \          return !(lhs == rhs);\n        }\n      };\n\n      distinct_prime_factor_iterable(const\
    \ ::std::vector<T>& min_prime_factors, const T& n) :\n        m_min_prime_factors(min_prime_factors),\n\
    \        m_n(n) {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_min_prime_factors,\
    \ this->m_n);\n      };\n\n      iterator end() const {\n        return iterator(this->m_min_prime_factors,\
    \ 1);\n      }\n    };\n\n    class prime_iterable {\n    private:\n      const\
    \ ::std::vector<T>& m_min_prime_factors;\n      T m_l;\n      T m_r;\n\n    public:\n\
    \      class iterator {\n      private:\n        const ::std::vector<T>& m_min_prime_factors;\n\
    \        T m_p;\n\n        T size() const {\n          return this->m_min_prime_factors.size();\n\
    \        }\n\n      public:\n        using difference_type = ::std::ptrdiff_t;\n\
    \        using value_type = T;\n        using reference = T&;\n        using pointer\
    \ = T*;\n        using iterator_category = ::std::input_iterator_tag;\n\n    \
    \    iterator(const ::std::vector<T>& min_prime_factors, const T p) :\n      \
    \    m_min_prime_factors(min_prime_factors),\n          m_p(p) {\n          for\
    \ (; this->m_p < this->size() && this->m_min_prime_factors[this->m_p] != this->m_p;\
    \ ++this->m_p);\n        }\n\n        iterator(const iterator& other) = default;\n\
    \        ~iterator() = default;\n        iterator& operator=(const iterator& other)\
    \ = default;\n\n        iterator& operator++() {\n          for (++this->m_p;\
    \ this->m_p < this->size() && this->m_min_prime_factors[this->m_p] != this->m_p;\
    \ ++this->m_p);\n          return *this;\n        }\n\n        iterator operator++(int)\
    \ {\n          const iterator self = *this;\n          ++*this;\n          return\
    \ self;\n        }\n\n        T operator*() const {\n          return this->m_p;\n\
    \        }\n\n        friend bool operator==(const iterator& lhs, const iterator&\
    \ rhs) {\n          return lhs.m_p == rhs.m_p;\n        }\n\n        friend bool\
    \ operator!=(const iterator& lhs, const iterator& rhs) {\n          return !(lhs\
    \ == rhs);\n        }\n      };\n\n      prime_iterable(const ::std::vector<T>&\
    \ min_prime_factors, const T l, const T r) :\n        m_min_prime_factors(min_prime_factors),\
    \ m_l(l), m_r(r) {\n      }\n\n      iterator begin() const {\n        return\
    \ iterator(this->m_min_prime_factors, this->m_l);\n      };\n\n      iterator\
    \ end() const {\n        return iterator(this->m_min_prime_factors, this->m_r);\n\
    \      }\n    };\n\n    explicit osa_k(const T N) :\n      m_min_prime_factors(::std::max<T>(N,\
    \ 1), ::std::numeric_limits<T>::max()),\n      m_divisor_counts(::std::max<T>(N,\
    \ 1)) {\n      assert(N >= 1);\n\n      for (T i = 2; i < N; ++i) {\n        if\
    \ (this->m_min_prime_factors[i] == ::std::numeric_limits<T>::max()) {\n      \
    \    this->m_min_prime_factors[i] = i;\n          for (T j = i * i; j < N; j +=\
    \ i) {\n            if (this->m_min_prime_factors[j] == ::std::numeric_limits<T>::max())\
    \ {\n              this->m_min_prime_factors[j] = i;\n            }\n        \
    \  }\n        }\n      }\n\n      ::std::vector<::std::pair<T, T>> dp(N);\n  \
    \    dp[0] = ::std::make_pair(0, 0);\n      if (N > 1) dp[1] = ::std::make_pair(1,\
    \ 1);\n      for (T i = 2; i < N; ++i) {\n        const auto& prev = dp[i / this->m_min_prime_factors[i]];\n\
    \        if (this->m_min_prime_factors[i / this->m_min_prime_factors[i]] == this->m_min_prime_factors[i])\
    \ {\n          dp[i] = ::std::make_pair(prev.first + 1, prev.second);\n      \
    \  } else {\n          dp[i] = ::std::make_pair(T(2), prev.first * prev.second);\n\
    \        }\n      }\n\n      for (T i = 0; i < N; ++i) {\n        this->m_divisor_counts[i]\
    \ = dp[i].first * dp[i].second;\n      }\n    }\n\n    T divisor_count(const T\
    \ n) const {\n      assert(1 <= n && n < this->size());\n      return this->m_divisor_counts[n];\n\
    \    }\n\n    prime_factor_iterable prime_factor_range(const T n) const {\n  \
    \    assert(1 <= n && n < this->size());\n      return prime_factor_iterable(this->m_min_prime_factors,\
    \ n);\n    }\n\n    distinct_prime_factor_iterable distinct_prime_factor_range(const\
    \ T n) const {\n      assert(1 <= n && n < this->size());\n      return distinct_prime_factor_iterable(this->m_min_prime_factors,\
    \ n);\n    }\n\n    prime_iterable prime_range(const T l, const T r) const {\n\
    \      assert(1 <= l && l <= r && r <= this->size());\n      return prime_iterable(this->m_min_prime_factors,\
    \ l, r);\n    }\n\n    ::std::vector<T> divisors(const T n) const {\n      assert(1\
    \ <= n && n < this->size());\n      ::std::vector<T> result({1});\n      for (const\
    \ auto& pair : this->distinct_prime_factor_range(n)) {\n        const T end =\
    \ result.size();\n        for (T i = 1, x = pair.first; i <= pair.second; ++i,\
    \ x *= pair.first) {\n          for (T j = 0; j < end; ++j) {\n            result.push_back(result[j]\
    \ * x);\n          }\n        }\n      }\n\n      ::std::sort(result.begin(),\
    \ result.end());\n      return result;\n    }\n  };\n}\n\n\n#line 10 \"tools/gcd_convolution.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void gcd_convolution(InputIterator a_begin, InputIterator a_end, InputIterator\
    \ b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end)\
    \ {\n    if (c_begin == c_end) return;\n\n    using T = ::std::decay_t<decltype(*a_begin)>;\n\
    \    ::std::vector<T> a(a_begin, a_end);\n    ::std::vector<T> b(b_begin, b_end);\n\
    \    if (a.empty() || b.empty()) {\n      ::std::fill(c_begin, c_end, T(0));\n\
    \      return;\n    }\n    const ::std::size_t N = a.size();\n    const ::std::size_t\
    \ M = b.size();\n    const ::std::size_t K = ::std::distance(c_begin, c_end);\n\
    \n    ::std::vector<T> base(K, T(0));\n    base[0] = a[0] * b[0];\n    for (::std::size_t\
    \ i = 1; i < ::std::min(N, K); ++i) {\n      base[i] += a[i] * b[0];\n    }\n\
    \    for (::std::size_t i = 1; i < ::std::min(M, K); ++i) {\n      base[i] +=\
    \ a[0] * b[i];\n    }\n\n    ::tools::osa_k<::std::size_t> osa_k(::std::max({N,\
    \ M, K}));\n    for (const auto p : osa_k.prime_range(1, N)) {\n      for (::std::size_t\
    \ k = (N - 1) / p; k >= 1; --k) {\n        a[k] += a[k * p];\n      }\n    }\n\
    \    for (const auto p : osa_k.prime_range(1, M)) {\n      for (::std::size_t\
    \ k = (M - 1) / p; k >= 1; --k) {\n        b[k] += b[k * p];\n      }\n    }\n\
    \n    for (::std::size_t i = 1; i < ::std::min({N, M, K}); ++i) {\n      c_begin[i]\
    \ = a[i] * b[i];\n    }\n    ::std::fill(::std::next(c_begin, ::std::min({N, M,\
    \ K})), c_end, T(0));\n\n    for (const auto p : osa_k.prime_range(1, K)) {\n\
    \      for (::std::size_t k = 1; k * p < K; ++k) {\n        c_begin[k] -= c_begin[k\
    \ * p];\n      }\n    }\n\n    for (::std::size_t i = 0; i < K; ++i) {\n     \
    \ c_begin[i] += base[i];\n    }\n  }\n}\n\n\n#line 8 \"tests/gcd_convolution.test.cpp\"\
    \n\nusing ll = long long;\nusing mint = atcoder::modint998244353;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll\
    \ N;\n  std::cin >> N;\n  std::vector<mint> a(N + 1), b(N + 1);\n  for (ll i =\
    \ 1; i <= N; ++i) {\n    ll a_i;\n    std::cin >> a_i;\n    a[i] = mint::raw(a_i);\n\
    \  }\n  for (ll i = 1; i <= N; ++i) {\n    ll b_i;\n    std::cin >> b_i;\n   \
    \ b[i] = mint::raw(b_i);\n  }\n\n  std::vector<mint> c(N + 1);\n  tools::gcd_convolution(a.begin(),\
    \ a.end(), b.begin(), b.end(), c.begin(), c.end());\n\n  std::string delimiter\
    \ = \"\";\n  for (ll i = 1; i <= N; ++i) {\n    std::cout << delimiter << c[i].val();\n\
    \    delimiter = \" \";\n  }\n  std::cout << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <string>\n#include \"atcoder/modint.hpp\"\
    \n#include \"tools/gcd_convolution.hpp\"\n\nusing ll = long long;\nusing mint\
    \ = atcoder::modint998244353;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n  std::vector<mint> a(N + 1), b(N + 1);\n  for (ll\
    \ i = 1; i <= N; ++i) {\n    ll a_i;\n    std::cin >> a_i;\n    a[i] = mint::raw(a_i);\n\
    \  }\n  for (ll i = 1; i <= N; ++i) {\n    ll b_i;\n    std::cin >> b_i;\n   \
    \ b[i] = mint::raw(b_i);\n  }\n\n  std::vector<mint> c(N + 1);\n  tools::gcd_convolution(a.begin(),\
    \ a.end(), b.begin(), b.end(), c.begin(), c.end());\n\n  std::string delimiter\
    \ = \"\";\n  for (ll i = 1; i <= N; ++i) {\n    std::cout << delimiter << c[i].val();\n\
    \    delimiter = \" \";\n  }\n  std::cout << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/gcd_convolution.hpp
  - tools/osa_k.hpp
  isVerificationFile: true
  path: tests/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/tests/gcd_convolution.test.cpp
- /verify/tests/gcd_convolution.test.cpp.html
title: tests/gcd_convolution.test.cpp
---
