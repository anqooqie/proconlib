---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/permutation.hpp
    title: Permutation
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
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
    - https://atcoder.jp/contests/abc013/tasks/abc013_4
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/permutation.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <numeric>\n#include <algorithm>\n\
    #line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include\
    \ <cstdlib>\n\n#define assert_that(cond) do {\\\n  if (!(cond)) {\\\n    ::std::cerr\
    \ << __FILE__ << ':' << __LINE__ << \": \" << __func__ << \": Assertion `\" <<\
    \ #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n\
    } while (false)\n\n\n#line 1 \"tools/permutation.hpp\"\n\n\n\n#line 5 \"tools/permutation.hpp\"\
    \n#include <cstddef>\n#line 7 \"tools/permutation.hpp\"\n#include <cassert>\n\
    #include <utility>\n#include <iterator>\n#line 11 \"tools/permutation.hpp\"\n\
    #include <string>\n\nnamespace tools {\n  template <typename T>\n  class permutation\
    \ {\n  private:\n    ::std::vector<T> m_vector;\n\n    void verify_consistency()\
    \ const {\n#ifndef NDEBUG\n      ::std::vector<bool> unique(this->m_vector.size(),\
    \ true);\n      for (const T& x : this->m_vector) {\n        assert(0 <= x &&\
    \ x < T(this->m_vector.size()));\n        assert(unique[x]);\n        unique[x]\
    \ = false;\n      }\n#endif\n    }\n\n  public:\n    permutation() = default;\n\
    \    permutation(const ::tools::permutation<T>&) = default;\n    permutation(::tools::permutation<T>&&)\
    \ = default;\n    ~permutation() = default;\n    ::tools::permutation<T>& operator=(const\
    \ ::tools::permutation<T>&) = default;\n    ::tools::permutation<T>& operator=(::tools::permutation<T>&&)\
    \ = default;\n\n    permutation(::std::size_t dim) : m_vector(dim) {\n      ::std::iota(this->m_vector.begin(),\
    \ this->m_vector.end(), 0);\n    }\n    template <typename Iterator>\n    permutation(Iterator\
    \ begin, Iterator end) : m_vector(begin, end) {\n      this->verify_consistency();\n\
    \    }\n\n    T operator[](const ::std::size_t i) const {\n      assert(i < this->size());\n\
    \      return this->m_vector[i];\n    }\n    typename ::std::vector<T>::const_iterator\
    \ begin() const {\n      return this->m_vector.begin();\n    }\n    typename ::std::vector<T>::const_iterator\
    \ end() const {\n      return this->m_vector.end();\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_vector.size();\n    }\n\n    void swap(const\
    \ ::std::size_t i, const ::std::size_t j) {\n      assert(i < this->size());\n\
    \      assert(j < this->size());\n      ::std::swap(this->m_vector[i], this->m_vector[j]);\n\
    \    }\n\n    T id() const {\n      if (this->m_vector.empty()) return 0;\n\n\
    \      ::std::vector<T> left(this->m_vector.size());\n      ::std::iota(left.begin(),\
    \ left.end(), 0);\n      ::std::vector<T> fact(this->m_vector.size());\n     \
    \ fact[0] = 1;\n      for (::std::size_t i = 1; i < this->m_vector.size(); ++i)\
    \ {\n        fact[i] = fact[i - 1] * i;\n      }\n\n      T id = 0;\n      for\
    \ (::std::size_t i = 0; i < this->m_vector.size(); ++i) {\n        auto it = ::std::lower_bound(left.begin(),\
    \ left.end(), this->m_vector[i]);\n        id += std::distance(left.begin(), it)\
    \ * fact[this->m_vector.size() - 1 - i];\n        left.erase(it);\n      }\n\n\
    \      return id;\n    }\n\n    static ::tools::permutation<T> from(const ::std::size_t\
    \ dim, T id) {\n      if (dim == 0) return ::tools::permutation<T>(0);\n\n   \
    \   ::std::vector<T> left(dim);\n      ::std::iota(left.begin(), left.end(), 0);\n\
    \      ::std::vector<T> fact(dim);\n      fact[0] = 1;\n      for (::std::size_t\
    \ i = 1; i < dim; ++i) {\n        fact[i] = fact[i - 1] * i;\n      }\n\n    \
    \  ::std::vector<T> p;\n      for (::std::size_t i = 0; i < dim; ++i) {\n    \
    \    auto it = std::next(left.begin(), id / fact[dim - i - 1]);\n        p.push_back(*it);\n\
    \        left.erase(it);\n        id %= fact[dim - i - 1];\n      }\n\n      return\
    \ ::tools::permutation<T>(p.begin(), p.end());\n    }\n\n    ::tools::permutation<T>\
    \ inv() const {\n      ::tools::permutation<T> result(this->size());\n      for\
    \ (::std::size_t i = 0; i < this->size(); ++i) {\n        result.m_vector[this->m_vector[i]]\
    \ = i;\n      }\n      return result;\n    }\n\n    friend ::tools::permutation<T>\
    \ operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      assert(lhs.size() == rhs.size());\n      ::tools::permutation<T>\
    \ result(lhs.size());\n      for (::std::size_t i = 0; i < lhs.size(); ++i) {\n\
    \        result.m_vector[i] = rhs.m_vector[lhs.m_vector[i]];\n      }\n      return\
    \ result;\n    }\n    friend bool operator==(const ::tools::permutation<T>& lhs,\
    \ const ::tools::permutation<T>& rhs) {\n      return lhs.m_vector == rhs.m_vector;\n\
    \    }\n    friend bool operator!=(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>&\
    \ rhs) {\n      return lhs.m_vector != rhs.m_vector;\n    }\n\n    friend ::std::ostream&\
    \ operator<<(::std::ostream& os, const ::tools::permutation<T>& self) {\n    \
    \  os << '(';\n      ::std::string delimiter = \"\";\n      for (const T& value\
    \ : self.m_vector) {\n        os << delimiter << value;\n        delimiter = \"\
    , \";\n      }\n      return os << ')';\n    }\n    friend ::std::istream& operator>>(::std::istream&\
    \ is, ::tools::permutation<T>& self) {\n      for (T& value : self.m_vector) {\n\
    \        is >> value;\n      }\n      self.verify_consistency();\n      return\
    \ is;\n    }\n  };\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 6 \"tools/ssize.hpp\"\n\nnamespace tools {\n\n  template <typename C>\n\
    \  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 1 \"tools/pow.hpp\"\n\n\n\n#line 6 \"tools/pow.hpp\"\n#include <cmath>\n\
    #line 1 \"tools/monoid.hpp\"\n\n\n\n#line 5 \"tools/monoid.hpp\"\n#include <limits>\n\
    #line 7 \"tools/monoid.hpp\"\n\nnamespace tools {\n  namespace monoid {\n    template\
    \ <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n    struct max\
    \ {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n  \
    \      return ::std::max(lhs, rhs);\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n\n    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>\n\
    \    struct min {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type>\n    struct\
    \ multiplies {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n        return\
    \ T(1);\n      }\n    };\n\n    template <typename Type>\n    struct gcd {\n \
    \     using T = Type;\n      static T op(const T lhs, const T rhs) {\n       \
    \ return ::std::gcd(lhs, rhs);\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n    };\n\n    template <typename Type, Type E>\n    struct update\
    \ {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n  \
    \      return lhs == E ? rhs : lhs;\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5\
    \ \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename M>\n  typename\
    \ M::T square(const typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template\
    \ <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 9 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, typename M::T>\
    \ pow(const typename M::T& base, const E exponent) {\n    assert(exponent >= 0);\n\
    \    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n       \
    \ ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ T> pow(const T& base, const E exponent) {\n    assert(exponent >= 0);\n    return\
    \ ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);\n  }\n\n  template\
    \ <typename T, typename E>\n  auto pow(const T base, const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>,\
    \ decltype(::std::pow(base, exponent))> {\n    return ::std::pow(base, exponent);\n\
    \  }\n}\n\n\n#line 11 \"tests/permutation.test.cpp\"\n\nusing ll = long long;\n\
    \nstruct group {\n  using T = tools::permutation<ll>;\n  inline static ll N;\n\
    \  static T op(const T& lhs, const T& rhs) {\n    return lhs * rhs;\n  }\n  static\
    \ T e() {\n    return T(N);\n  }\n  static T inv(const T& p) {\n    return p.inv();\n\
    \  }\n};\n\n// Source: https://atcoder.jp/contests/abc013/tasks/abc013_4\nvoid\
    \ abc013d(const ll& N, const ll& D, const std::vector<ll>& A, const std::vector<ll>&\
    \ expected) {\n  group::N = N;\n  tools::permutation<ll> unit(N);\n  for (ll i\
    \ = 0; i < tools::ssize(A); ++i) {\n    unit.swap(A[i] - 1, A[i]);\n  }\n\n  const\
    \ auto p = tools::pow<group>(unit, D).inv();\n  std::vector<ll> actual(p.begin(),\
    \ p.end());\n  for (ll& actual_i : actual) ++actual_i;\n\n  assert_that(actual\
    \ == expected);\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  abc013d(5, 1, std::vector<ll>({1, 4, 3, 4, 2, 3, 1}), std::vector<ll>({4,\
    \ 2, 5, 3, 1}));\n  abc013d(5, 2, std::vector<ll>({1, 4, 3, 4, 2, 3, 1}), std::vector<ll>({3,\
    \ 2, 1, 5, 4}));\n  abc013d(10, 300, std::vector<ll>({9, 1, 2, 5, 8, 1, 9, 3,\
    \ 5, 6, 4, 5, 4, 6, 8, 3, 2, 7, 9, 6}), std::vector<ll>({3, 7, 2, 4, 5, 9, 6,\
    \ 1, 8, 10}));\n\n  for (ll n = 0; n <= 5; ++n) {\n    std::vector<ll> expected(n);\n\
    \    std::iota(expected.begin(), expected.end(), 0);\n    ll id = 0;\n    do {\n\
    \      const auto actual = tools::permutation<ll>::from(n, id);\n      assert_that(actual\
    \ == tools::permutation<ll>(expected.begin(), expected.end()));\n      assert_that(actual.id()\
    \ == id);\n      ++id;\n    } while (std::next_permutation(expected.begin(), expected.end()));\n\
    \  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <numeric>\n#include <algorithm>\n\
    #include \"tools/assert_that.hpp\"\n#include \"tools/permutation.hpp\"\n#include\
    \ \"tools/ssize.hpp\"\n#include \"tools/pow.hpp\"\n\nusing ll = long long;\n\n\
    struct group {\n  using T = tools::permutation<ll>;\n  inline static ll N;\n \
    \ static T op(const T& lhs, const T& rhs) {\n    return lhs * rhs;\n  }\n  static\
    \ T e() {\n    return T(N);\n  }\n  static T inv(const T& p) {\n    return p.inv();\n\
    \  }\n};\n\n// Source: https://atcoder.jp/contests/abc013/tasks/abc013_4\nvoid\
    \ abc013d(const ll& N, const ll& D, const std::vector<ll>& A, const std::vector<ll>&\
    \ expected) {\n  group::N = N;\n  tools::permutation<ll> unit(N);\n  for (ll i\
    \ = 0; i < tools::ssize(A); ++i) {\n    unit.swap(A[i] - 1, A[i]);\n  }\n\n  const\
    \ auto p = tools::pow<group>(unit, D).inv();\n  std::vector<ll> actual(p.begin(),\
    \ p.end());\n  for (ll& actual_i : actual) ++actual_i;\n\n  assert_that(actual\
    \ == expected);\n}\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  abc013d(5, 1, std::vector<ll>({1, 4, 3, 4, 2, 3, 1}), std::vector<ll>({4,\
    \ 2, 5, 3, 1}));\n  abc013d(5, 2, std::vector<ll>({1, 4, 3, 4, 2, 3, 1}), std::vector<ll>({3,\
    \ 2, 1, 5, 4}));\n  abc013d(10, 300, std::vector<ll>({9, 1, 2, 5, 8, 1, 9, 3,\
    \ 5, 6, 4, 5, 4, 6, 8, 3, 2, 7, 9, 6}), std::vector<ll>({3, 7, 2, 4, 5, 9, 6,\
    \ 1, 8, 10}));\n\n  for (ll n = 0; n <= 5; ++n) {\n    std::vector<ll> expected(n);\n\
    \    std::iota(expected.begin(), expected.end(), 0);\n    ll id = 0;\n    do {\n\
    \      const auto actual = tools::permutation<ll>::from(n, id);\n      assert_that(actual\
    \ == tools::permutation<ll>(expected.begin(), expected.end()));\n      assert_that(actual.id()\
    \ == id);\n      ++id;\n    } while (std::next_permutation(expected.begin(), expected.end()));\n\
    \  }\n\n  std::cout << \"Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/permutation.hpp
  - tools/ssize.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  isVerificationFile: true
  path: tests/permutation.test.cpp
  requiredBy: []
  timestamp: '2022-11-03 23:21:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/permutation.test.cpp
layout: document
redirect_from:
- /verify/tests/permutation.test.cpp
- /verify/tests/permutation.test.cpp.html
title: tests/permutation.test.cpp
---
