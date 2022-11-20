---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/floor_kth_root.hpp
    title: $\left\lfloor x^\frac{1}{k} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':x:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':x:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_kth_root.test.cpp
    title: tests/ceil_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_kth_root.test.cpp
    title: tests/floor_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/slerp.test.cpp
    title: tests/quaternion/slerp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':x:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':x:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pow.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cassert>\n#include <cmath>\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid\
    \ {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
    \    struct max {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::max()>\n    struct min {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::min(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type>\n    struct multiplies {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs * rhs;\n  \
    \    }\n      static T e() {\n        return T(1);\n      }\n    };\n\n    template\
    \ <typename Type>\n    struct gcd {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::gcd(lhs, rhs);\n      }\n     \
    \ static T e() {\n        return T(0);\n      }\n    };\n\n    template <typename\
    \ Type, Type E>\n    struct update {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n      }\n     \
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\
    \n\n\n\n#line 5 \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T square(const typename M::T& x) {\n    return M::op(x, x);\n\
    \  }\n\n  template <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
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
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_POW_H\n#define TOOLS_POW_H\n\n#include <type_traits>\n#include\
    \ <cassert>\n#include <cmath>\n#include \"tools/monoid.hpp\"\n#include \"tools/square.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ typename M::T> pow(const typename M::T& base, const E exponent) {\n    assert(exponent\
    \ >= 0);\n    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n\
    \        ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        :\
    \ M::op(::tools::pow<M>(base, exponent - 1), base);\n  }\n\n  template <typename\
    \ T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, T> pow(const T&\
    \ base, const E exponent) {\n    assert(exponent >= 0);\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base,\
    \ exponent);\n  }\n\n  template <typename T, typename E>\n  auto pow(const T base,\
    \ const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>, decltype(::std::pow(base,\
    \ exponent))> {\n    return ::std::pow(base, exponent);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/monoid.hpp
  - tools/square.hpp
  isVerificationFile: false
  path: tools/pow.hpp
  requiredBy:
  - tools/modint_for_rolling_hash.hpp
  - tools/totient.hpp
  - tools/ceil_kth_root.hpp
  - tools/tetration_mod.hpp
  - tools/floor_kth_root.hpp
  - tools/detail/rolling_hash.hpp
  - tools/rolling_hash.hpp
  - tools/quaternion.hpp
  timestamp: '2022-11-03 23:21:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/tetration_mod.test.cpp
  - tests/floor_kth_root.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/totient.test.cpp
  - tests/has_mod.test.cpp
  - tests/permutation.test.cpp
  - tests/ceil_kth_root.test.cpp
documentation_of: tools/pow.hpp
layout: document
title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
---

## (1)
```cpp
template <typename M, typename E>
typename M::T pow(typename M::T b, E n);

template <typename T, typename E>
T pow(T b, E n);
```

It returns $b^n$ under a given monoid $M$.
If $M$ is not given, `tools::monoid::multiplies<T>` will be used.

## Constraints
- `std::is_integral_v<E>` is `true`.
- $n \geq 0$

## Time Complexity
- $O(\log n)$ if `M::op(b, b)` takes $O(1)$ time

## License
- CC0

## Author
- anqooqie

## (2)
```cpp
template <typename T, typename E>
T pow(T b, E n);
```

If `std::pow(b, n)` is available, it returns `std::pow(b, n)`.

`tools::pow(b, n)` will be extended by other header files in my library.
For example, `tools::pow(tools::quaternion<T>, T)` gets available if you include `tools/quaternion.hpp`.

## Constraints
- `std::is_integral_v<E>` is `false`.
- See the standard or the explanation of the corresponding header file.

## Time Complexity
- See the standard or the explanation of the corresponding header file.

## License
- CC0

## Author
- anqooqie
