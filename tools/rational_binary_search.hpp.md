---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/rational_binary_search.test.cpp
    title: tests/rational_binary_search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/rational_binary_search.hpp\"\n\n\n\n#include <tuple>\n\
    #include <cassert>\n\nnamespace tools {\n  template <typename T, typename F>\n\
    \  ::std::tuple<T, T, T, T> rational_binary_search(const T& p1, const T& q1, const\
    \ T& p2, const T& q2, const F& f, const T& N) {\n    assert(q1 >= T(0));\n   \
    \ assert(q2 >= T(0));\n    assert(N > T(0));\n    assert(p1 * q2 < p2 * q1);\n\
    \    const bool f1 = f(p1, q1);\n    const bool f2 = f(p2, q2);\n    assert(f1\
    \ != f2);\n    const auto g = [&](const T& p, const T& q) {\n      assert(q >\
    \ T(0));\n      if (p * q1 < p1 * q) return f1;\n      if (p2 * q < p * q2) return\
    \ f2;\n      return f(p, q);\n    };\n\n    bool d = g(T(0), T(1)) == f1;\n  \
    \  T p3, q3, p4, q4;\n    if (d) {\n      p3 = T(0);\n      q3 = T(1);\n     \
    \ p4 = T(1);\n      q4 = T(0);\n    } else {\n      p3 = T(-1);\n      q3 = T(0);\n\
    \      p4 = T(0);\n      q4 = T(1);\n    }\n\n    while (q3 <= N - q4) {\n   \
    \   if (d) {\n        T ng(1);\n        if (q4 == T(0)) {\n          for (; g(p3\
    \ + ng * p4, q3) == f1; ng *= T(2));\n        } else {\n          const T max\
    \ = (N - q3) / q4;\n          for (; ng <= max && g(p3 + ng * p4, q3 + ng * q4)\
    \ == f1; ng = (ng == max ? ng + T(1) : ng <= max / T(2) ? T(2) * ng : max));\n\
    \          if (ng == max + T(1)) {\n            --ng;\n            p3 += ng *\
    \ p4;\n            q3 += ng * q4;\n            break;\n          }\n        }\n\
    \        T ok(0);\n        while (ng - ok > T(1)) {\n          const auto mid\
    \ = ok + (ng - ok) / T(2);\n          if (g(p3 + mid * p4, q3 + mid * q4) == f1)\
    \ {\n            ok = mid;\n          } else {\n            ng = mid;\n      \
    \    }\n        }\n        ::std::tie(p3, q3, p4, q4) = ::std::make_tuple(p3 +\
    \ ok * p4, q3 + ok * q4, p3 + ng * p4, q3 + ng * q4);\n      } else {\n      \
    \  T ng(1);\n        if (q3 == T(0)) {\n          for (; g(ng * p3 + p4, q4) ==\
    \ f2; ng *= T(2));\n        } else {\n          const T max = (N - q4) / q3;\n\
    \          for (; ng <= max && g(ng * p3 + p4, ng * q3 + q4) == f2; ng = (ng ==\
    \ max ? ng + T(1) : ng <= max / T(2) ? T(2) * ng : max));\n          if (ng ==\
    \ max + T(1)) {\n            --ng;\n            p4 += ng * p3;\n            q4\
    \ += ng * q3;\n            break;\n          }\n        }\n        T ok(0);\n\
    \        while (ng - ok > T(1)) {\n          const auto mid = ok + (ng - ok) /\
    \ T(2);\n          if (g(mid * p3 + p4, mid * q3 + q4) == f2) {\n            ok\
    \ = mid;\n          } else {\n            ng = mid;\n          }\n        }\n\
    \        ::std::tie(p3, q3, p4, q4) = ::std::make_tuple(ng * p3 + p4, ng * q3\
    \ + q4, ok * p3 + p4, ok * q3 + q4);\n      }\n      d = !d;\n    }\n\n    return\
    \ ::std::make_tuple(p3, q3, p4, q4);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_RATIONAL_BINARY_SEARCH_HPP\n#define TOOLS_RATIONAL_BINARY_SEARCH_HPP\n\
    \n#include <tuple>\n#include <cassert>\n\nnamespace tools {\n  template <typename\
    \ T, typename F>\n  ::std::tuple<T, T, T, T> rational_binary_search(const T& p1,\
    \ const T& q1, const T& p2, const T& q2, const F& f, const T& N) {\n    assert(q1\
    \ >= T(0));\n    assert(q2 >= T(0));\n    assert(N > T(0));\n    assert(p1 * q2\
    \ < p2 * q1);\n    const bool f1 = f(p1, q1);\n    const bool f2 = f(p2, q2);\n\
    \    assert(f1 != f2);\n    const auto g = [&](const T& p, const T& q) {\n   \
    \   assert(q > T(0));\n      if (p * q1 < p1 * q) return f1;\n      if (p2 * q\
    \ < p * q2) return f2;\n      return f(p, q);\n    };\n\n    bool d = g(T(0),\
    \ T(1)) == f1;\n    T p3, q3, p4, q4;\n    if (d) {\n      p3 = T(0);\n      q3\
    \ = T(1);\n      p4 = T(1);\n      q4 = T(0);\n    } else {\n      p3 = T(-1);\n\
    \      q3 = T(0);\n      p4 = T(0);\n      q4 = T(1);\n    }\n\n    while (q3\
    \ <= N - q4) {\n      if (d) {\n        T ng(1);\n        if (q4 == T(0)) {\n\
    \          for (; g(p3 + ng * p4, q3) == f1; ng *= T(2));\n        } else {\n\
    \          const T max = (N - q3) / q4;\n          for (; ng <= max && g(p3 +\
    \ ng * p4, q3 + ng * q4) == f1; ng = (ng == max ? ng + T(1) : ng <= max / T(2)\
    \ ? T(2) * ng : max));\n          if (ng == max + T(1)) {\n            --ng;\n\
    \            p3 += ng * p4;\n            q3 += ng * q4;\n            break;\n\
    \          }\n        }\n        T ok(0);\n        while (ng - ok > T(1)) {\n\
    \          const auto mid = ok + (ng - ok) / T(2);\n          if (g(p3 + mid *\
    \ p4, q3 + mid * q4) == f1) {\n            ok = mid;\n          } else {\n   \
    \         ng = mid;\n          }\n        }\n        ::std::tie(p3, q3, p4, q4)\
    \ = ::std::make_tuple(p3 + ok * p4, q3 + ok * q4, p3 + ng * p4, q3 + ng * q4);\n\
    \      } else {\n        T ng(1);\n        if (q3 == T(0)) {\n          for (;\
    \ g(ng * p3 + p4, q4) == f2; ng *= T(2));\n        } else {\n          const T\
    \ max = (N - q4) / q3;\n          for (; ng <= max && g(ng * p3 + p4, ng * q3\
    \ + q4) == f2; ng = (ng == max ? ng + T(1) : ng <= max / T(2) ? T(2) * ng : max));\n\
    \          if (ng == max + T(1)) {\n            --ng;\n            p4 += ng *\
    \ p3;\n            q4 += ng * q3;\n            break;\n          }\n        }\n\
    \        T ok(0);\n        while (ng - ok > T(1)) {\n          const auto mid\
    \ = ok + (ng - ok) / T(2);\n          if (g(mid * p3 + p4, mid * q3 + q4) == f2)\
    \ {\n            ok = mid;\n          } else {\n            ng = mid;\n      \
    \    }\n        }\n        ::std::tie(p3, q3, p4, q4) = ::std::make_tuple(ng *\
    \ p3 + p4, ng * q3 + q4, ok * p3 + p4, ok * q3 + q4);\n      }\n      d = !d;\n\
    \    }\n\n    return ::std::make_tuple(p3, q3, p4, q4);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/rational_binary_search.hpp
  requiredBy: []
  timestamp: '2024-04-29 15:33:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/rational_binary_search.test.cpp
documentation_of: tools/rational_binary_search.hpp
layout: document
title: Rational binary search
---

```cpp
template <typename T, typename F>
std::tuple<T, T, T, T> rational_binary_search(T p1, T q1, T p2, T q2, F f, T n);
```

Let $S$ be the set of irreducible fractions whose denominator is a positive integer less than or equal to $n$.
It returns $(p_3, q_3, p_4, q_4)$.
$\frac{p_3}{q_3}$ is the maximum $\frac{p}{q}$ such that $\frac{p}{q} \in S$ and $f\left(\frac{p}{q}\right) = f\left(\frac{p_1}{q_1}\right)$.
$\frac{p_4}{q_4}$ is the minimum $\frac{p}{q}$ such that $\frac{p}{q} \in S$ and $f\left(\frac{p}{q}\right) = f\left(\frac{p_2}{q_2}\right)$.

### Constraints
- `<T>` is an integral type.
- $q_1 \geq 0$
- $q_2 \geq 0$
- $\frac{p_1}{q_1} < \frac{p_2}{q_2}$
- $f$ takes a numerator and a denominator as two integer parameters and returns `bool`.
- $f\left(\frac{p_1}{q_1}\right) \neq f\left(\frac{p_2}{q_2}\right)$
- $\exists \frac{p^\ast}{q^\ast} \in \mathbb{Q}. \left( \left( \forall \frac{p}{q} \in \mathbb{Q}. \frac{p_1}{q_1} \leq \frac{p}{q} \leq \frac{p^\ast}{q^\ast} \Rightarrow f\left(\frac{p}{q}\right) = f\left(\frac{p_1}{q_1}\right) \right) \land \left( \forall \frac{p}{q} \in \mathbb{Q}. \frac{p^\ast}{q^\ast} < \frac{p}{q} \leq \frac{p_2}{q_2} \Rightarrow f\left(\frac{p}{q}\right) = f\left(\frac{p_2}{q_2}\right) \right) \right)$
- $n > 0$

### Time Complexity
- $O(\log n)$

### License
- CC0

### Author
- anqooqie
