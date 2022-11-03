---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: tools/mo.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/qcfium.hpp
    title: QCFium's method
  - icon: ':heavy_check_mark:'
    path: tools/unordered_map.hpp
    title: Alias for __gnu_pbds::gp_hash_table&amp;lt;Key, T, Hash&amp;gt;
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE_IF_CLANG: ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"tests/mo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#ifdef __clang__\n  #define IGNORE\n#endif\n\n#line 1 \"tools/qcfium.hpp\"\n\
    \n\n\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n\n\n#line 7 \"tests/mo.test.cpp\"\n#include <iostream>\n\
    #include <vector>\n#line 1 \"tools/mo.hpp\"\n\n\n\n#include <cstddef>\n#line 6\
    \ \"tools/mo.hpp\"\n#include <tuple>\n#include <algorithm>\n#include <cassert>\n\
    #line 1 \"tools/floor_sqrt.hpp\"\n\n\n\n#line 5 \"tools/floor_sqrt.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  T floor_sqrt(const T n) {\n    assert(n\
    \ >= 0);\n\n    T ok = 0;\n    T ng;\n    for (ng = 1; ng <= n / ng; ng *= 2);\n\
    \n    while (ng - ok > 1) {\n      const T mid = ok + (ng - ok) / 2;\n      if\
    \ (mid <= n / mid) {\n        ok = mid;\n      } else {\n        ng = mid;\n \
    \     }\n    }\n\n    return ok;\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\
    \n#include <type_traits>\n#line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> ceil(const\
    \ M lhs, const N rhs) {\n    assert(rhs != 0);\n    return lhs / rhs + (((lhs\
    \ > 0 && rhs > 0) || (lhs < 0 && rhs < 0)) && lhs % rhs);\n  }\n}\n\n\n#line 1\
    \ \"tools/less_by_get.hpp\"\n\n\n\n#line 6 \"tools/less_by_get.hpp\"\n\nnamespace\
    \ tools {\n\n  template <::std::size_t I>\n  struct less_by_get {\n    template\
    \ <class T>\n    bool operator()(const T& x, const T& y) const {\n      return\
    \ ::std::get<I>(x) < ::std::get<I>(y);\n    }\n  };\n}\n\n\n#line 1 \"tools/greater_by_get.hpp\"\
    \n\n\n\n#line 6 \"tools/greater_by_get.hpp\"\n\nnamespace tools {\n\n  template\
    \ <::std::size_t I>\n  struct greater_by_get {\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return ::std::get<I>(x) >\
    \ ::std::get<I>(y);\n    }\n  };\n}\n\n\n#line 13 \"tools/mo.hpp\"\n\nnamespace\
    \ tools {\n  class mo {\n  private:\n    ::std::size_t m_query_count;\n    ::std::size_t\
    \ m_bucket_size;\n    ::std::vector<::std::vector<::std::tuple<::std::size_t,\
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
    \  };\n}\n\n\n#line 1 \"tools/unordered_map.hpp\"\n\n\n\n#include <functional>\n\
    #include <utility>\n#line 7 \"tools/unordered_map.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nnamespace tools {\n\n  template <typename Key, typename T, typename Hash = ::std::hash<Key>>\n\
    \  class unordered_map : public ::__gnu_pbds::gp_hash_table<Key, T, Hash> {\n\
    \  public:\n    using ::__gnu_pbds::gp_hash_table<Key, T, Hash>::gp_hash_table;\n\
    \n    template <typename... Args>\n    auto emplace(Args&&... args) {\n      return\
    \ this->insert(::std::make_pair(::std::forward<Args>(args)...));\n    }\n\n  \
    \  template <typename M>\n    auto insert_or_assign(const Key& k, M&& obj) {\n\
    \      if (auto it = this->find(k); it != this->end()) {\n        it->second =\
    \ obj;\n        return ::std::make_pair(it, false);\n      } else {\n        return\
    \ this->emplace(k, obj);\n      }\n    }\n  };\n}\n\n\n#line 11 \"tests/mo.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<int> a(N);\n  for (auto& a_i\
    \ : a) std::cin >> a_i;\n\n  tools::mo mo(N, Q);\n  std::vector<int> queries(Q);\n\
    \  for (int i = 0; i < Q; ++i) {\n    int l, r;\n    std::cin >> l >> r;\n   \
    \ mo.add_query(l, r);\n    std::cin >> queries[i];\n  }\n\n  tools::unordered_map<int,\
    \ int> freq;\n  const auto add = [&](const int i) { ++freq[a[i]]; };\n  const\
    \ auto remove = [&](const int i) { --freq[a[i]]; };\n  ::std::vector<int> answers(Q);\n\
    \  mo.run(add, add, remove, remove, [&](const int q) {\n    if (const auto it\
    \ = freq.find(queries[q]); it != freq.end()) {\n      answers[q] = it->second;\n\
    \    } else {\n      answers[q] = 0;\n    }\n  });\n\n  for (const auto& answer\
    \ : answers) {\n    std::cout << answer << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#ifdef __clang__\n  #define IGNORE\n#endif\n\n#include \"tools/qcfium.hpp\"\n\
    #include <iostream>\n#include <vector>\n#include \"tools/mo.hpp\"\n#include \"\
    tools/unordered_map.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<int> a(N);\n  for (auto& a_i\
    \ : a) std::cin >> a_i;\n\n  tools::mo mo(N, Q);\n  std::vector<int> queries(Q);\n\
    \  for (int i = 0; i < Q; ++i) {\n    int l, r;\n    std::cin >> l >> r;\n   \
    \ mo.add_query(l, r);\n    std::cin >> queries[i];\n  }\n\n  tools::unordered_map<int,\
    \ int> freq;\n  const auto add = [&](const int i) { ++freq[a[i]]; };\n  const\
    \ auto remove = [&](const int i) { --freq[a[i]]; };\n  ::std::vector<int> answers(Q);\n\
    \  mo.run(add, add, remove, remove, [&](const int q) {\n    if (const auto it\
    \ = freq.find(queries[q]); it != freq.end()) {\n      answers[q] = it->second;\n\
    \    } else {\n      answers[q] = 0;\n    }\n  });\n\n  for (const auto& answer\
    \ : answers) {\n    std::cout << answer << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/qcfium.hpp
  - tools/mo.hpp
  - tools/floor_sqrt.hpp
  - tools/ceil.hpp
  - tools/less_by_get.hpp
  - tools/greater_by_get.hpp
  - tools/unordered_map.hpp
  isVerificationFile: true
  path: tests/mo.test.cpp
  requiredBy: []
  timestamp: '2022-07-02 14:04:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/mo.test.cpp
layout: document
redirect_from:
- /verify/tests/mo.test.cpp
- /verify/tests/mo.test.cpp.html
title: tests/mo.test.cpp
---
