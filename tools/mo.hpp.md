---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/floor_sqrt.hpp
    title: $\left\lfloor \sqrt{x} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_get.hpp
    title: std::greater by std::get
  - icon: ':heavy_check_mark:'
    path: tools/less_by_get.hpp
    title: std::less by std::get
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mo.test.cpp
    title: tests/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/mo.hpp\"\n\n\n\n#include <cstddef>\n#include <vector>\n\
    #include <tuple>\n#include <algorithm>\n#include <cassert>\n#line 1 \"tools/floor_sqrt.hpp\"\
    \n\n\n\n#line 5 \"tools/floor_sqrt.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T floor_sqrt(const T n) {\n    assert(n >= 0);\n\n    T ok = 0;\n    T\
    \ ng;\n    for (ng = 1; ng <= n / ng; ng *= 2);\n\n    while (ng - ok > 1) {\n\
    \      const T mid = ok + (ng - ok) / 2;\n      if (mid <= n / mid) {\n      \
    \  ok = mid;\n      } else {\n        ng = mid;\n      }\n    }\n\n    return\
    \ ok;\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/less_by_get.hpp\"\n\n\n\n#line 6 \"\
    tools/less_by_get.hpp\"\n\nnamespace tools {\n\n  template <::std::size_t I>\n\
    \  struct less_by_get {\n    template <class T>\n    bool operator()(const T&\
    \ x, const T& y) const {\n      return ::std::get<I>(x) < ::std::get<I>(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/greater_by_get.hpp\"\n\n\n\n#line 6 \"tools/greater_by_get.hpp\"\
    \n\nnamespace tools {\n\n  template <::std::size_t I>\n  struct greater_by_get\
    \ {\n    template <class T>\n    bool operator()(const T& x, const T& y) const\
    \ {\n      return ::std::get<I>(x) > ::std::get<I>(y);\n    }\n  };\n}\n\n\n#line\
    \ 13 \"tools/mo.hpp\"\n\nnamespace tools {\n  class mo {\n  private:\n    ::std::size_t\
    \ m_query_count;\n    ::std::size_t m_bucket_size;\n    ::std::vector<::std::vector<::std::tuple<::std::size_t,\
    \ ::std::size_t, ::std::size_t>>> m_buckets;\n\n  public:\n    mo() = default;\n\
    \    mo(const ::tools::mo&) = default;\n    mo(::tools::mo&&) = default;\n   \
    \ ~mo() = default;\n    ::tools::mo& operator=(const ::tools::mo&) = default;\n\
    \    ::tools::mo& operator=(::tools::mo&&) = default;\n\n    mo(const ::std::size_t\
    \ n, const ::std::size_t q) :\n      m_query_count(0),\n      m_bucket_size(::std::clamp<::std::size_t>(::tools::floor_sqrt(3\
    \ * (n + 1) * (n + 1) / (2 * (q + 1))), 1, n + 1)),\n      m_buckets(::tools::ceil(n\
    \ + 1, this->m_bucket_size)) {\n    }\n\n    void add_query(const ::std::size_t\
    \ l, const ::std::size_t r) {\n      assert(l <= r);\n      this->m_buckets[l\
    \ / this->m_bucket_size].emplace_back(this->m_query_count, l, r);\n      ++this->m_query_count;\n\
    \    }\n\n    template <typename AL, typename AR, typename DL, typename DR, typename\
    \ F>\n    void run(const AL& add_left, const AR& add_right, const DL& delete_left,\
    \ const DR& delete_right, const F& run_query) {\n      ::std::size_t l = 0;\n\
    \      ::std::size_t r = 0;\n      for (::std::size_t i = 0; i < this->m_buckets.size();\
    \ ++i) {\n        if (i % 2 == 0) {\n          ::std::sort(this->m_buckets[i].begin(),\
    \ this->m_buckets[i].end(), ::tools::less_by_get<2>());\n        } else {\n  \
    \        ::std::sort(this->m_buckets[i].begin(), this->m_buckets[i].end(), ::tools::greater_by_get<2>());\n\
    \        }\n        for (const auto& [qi, ql, qr] : this->m_buckets[i]) {\n  \
    \        for (; ql < l; --l) add_left(l - 1);\n          for (; r < qr; ++r) add_right(r);\n\
    \          for (; l < ql; ++l) delete_left(l);\n          for (; qr < r; --r)\
    \ delete_right(r - 1);\n          run_query(qi);\n        }\n      }\n    }\n\
    \  };\n}\n\n\n"
  code: "#ifndef TOOLS_MO_HPP\n#define TOOLS_MO_HPP\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <tuple>\n#include <algorithm>\n#include <cassert>\n#include\
    \ \"tools/floor_sqrt.hpp\"\n#include \"tools/ceil.hpp\"\n#include \"tools/less_by_get.hpp\"\
    \n#include \"tools/greater_by_get.hpp\"\n\nnamespace tools {\n  class mo {\n \
    \ private:\n    ::std::size_t m_query_count;\n    ::std::size_t m_bucket_size;\n\
    \    ::std::vector<::std::vector<::std::tuple<::std::size_t, ::std::size_t, ::std::size_t>>>\
    \ m_buckets;\n\n  public:\n    mo() = default;\n    mo(const ::tools::mo&) = default;\n\
    \    mo(::tools::mo&&) = default;\n    ~mo() = default;\n    ::tools::mo& operator=(const\
    \ ::tools::mo&) = default;\n    ::tools::mo& operator=(::tools::mo&&) = default;\n\
    \n    mo(const ::std::size_t n, const ::std::size_t q) :\n      m_query_count(0),\n\
    \      m_bucket_size(::std::clamp<::std::size_t>(::tools::floor_sqrt(3 * (n +\
    \ 1) * (n + 1) / (2 * (q + 1))), 1, n + 1)),\n      m_buckets(::tools::ceil(n\
    \ + 1, this->m_bucket_size)) {\n    }\n\n    void add_query(const ::std::size_t\
    \ l, const ::std::size_t r) {\n      assert(l <= r);\n      this->m_buckets[l\
    \ / this->m_bucket_size].emplace_back(this->m_query_count, l, r);\n      ++this->m_query_count;\n\
    \    }\n\n    template <typename AL, typename AR, typename DL, typename DR, typename\
    \ F>\n    void run(const AL& add_left, const AR& add_right, const DL& delete_left,\
    \ const DR& delete_right, const F& run_query) {\n      ::std::size_t l = 0;\n\
    \      ::std::size_t r = 0;\n      for (::std::size_t i = 0; i < this->m_buckets.size();\
    \ ++i) {\n        if (i % 2 == 0) {\n          ::std::sort(this->m_buckets[i].begin(),\
    \ this->m_buckets[i].end(), ::tools::less_by_get<2>());\n        } else {\n  \
    \        ::std::sort(this->m_buckets[i].begin(), this->m_buckets[i].end(), ::tools::greater_by_get<2>());\n\
    \        }\n        for (const auto& [qi, ql, qr] : this->m_buckets[i]) {\n  \
    \        for (; ql < l; --l) add_left(l - 1);\n          for (; r < qr; ++r) add_right(r);\n\
    \          for (; l < ql; ++l) delete_left(l);\n          for (; qr < r; --r)\
    \ delete_right(r - 1);\n          run_query(qi);\n        }\n      }\n    }\n\
    \  };\n}\n\n#endif\n"
  dependsOn:
  - tools/floor_sqrt.hpp
  - tools/ceil.hpp
  - tools/less_by_get.hpp
  - tools/greater_by_get.hpp
  isVerificationFile: false
  path: tools/mo.hpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/mo.test.cpp
documentation_of: tools/mo.hpp
layout: document
title: Mo's algorithm
---

Assume the following situation.

- $Q$ queries are given.
- The $i$-th query asks you about some kind of value for the range $[l_i, r_i)$. $(0 \leq l_i \leq r_i \leq N)$
- Some kind of state is uniquely determined from a range $[l, r)$.
- If you know the state uniquely determined from $[l - 1, r)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l + 1, r)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l, r - 1)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l, r + 1)$, you can calculate the state uniquely determined from $[l, r)$ in $\alpha$ time.
- If you know the state uniquely determined from $[l_i, r_i)$, you can answer the $i$-th query in $\beta$ time.

In this situation, Mo's algorithm can answer $Q$ queries in $O(\alpha N \sqrt{Q} + \beta Q)$ time.

### License
- CC0

### Author
- anqooqie

### References
- [Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)
- [Mo’s algorithm \| Nyaan’s Library](https://nyaannyaan.github.io/library/misc/mo.hpp.html)

## Constructor
```cpp
mo mo(std::size_t N, std::size_t Q);
```

It creates a storage for queries.

### Constraints
- None

### Time Complexity
- $O\left(\log \frac{N}{\sqrt{Q}} + \sqrt{Q}\right)$

## add_query
```cpp
void mo.add_query(std::size_t l, std::size_t r);
```

It adds a query for $[l, r)$ to the storage.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(1)$ amortized

## run
```cpp
template <typename AL, typename AR, typename DL, typename DR, typename F>
void mo.run(AL add_left, AR add_right, DL delete_left, DR delete_right, F run_query);
```

It runs Mo's algorithm.
When `run_query(i)` is invoked, you can answer the $i$-th query by using the state uniquely determined from $[l_i, r_i)$.

### Constraints
- `add_left(std::size_t)` is invocable.
- `add_right(std::size_t)` is invocable.
- `delete_left(std::size_t)` is invocable.
- `delete_right(std::size_t)` is invocable.
- `run_query(std::size_t)` is invocable.
- When `add_left(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l - 1, r)$. (You may utilize the contract that $i = l - 1$ holds.)
- When `add_right(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l, r + 1)$. (You may utilize the contract that $i = r$ holds.)
- When `delete_left(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l + 1, r)$. (You may utilize the contract that $i = l$ holds.)
- When `delete_right(i)` is invoked, you have to update the state from one uniquely determined from $[l, r)$ to one uniquely determined from $[l, r - 1)$. (You may utilize the contract that $i = r - 1$ holds.)

### Time Complexity
- $O(\alpha N \sqrt{Q} + \beta Q)$ where $\alpha$ is the time to run `add_left`, `add_right`, `delete_left` and `delete_right`, and $\beta$ is the time to run `run_query`.
