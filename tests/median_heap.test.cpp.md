---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/median_heap.hpp
    title: Heap managing median
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc127/tasks/abc127_f
    links:
    - https://atcoder.jp/contests/abc127/tasks/abc127_f
  bundledCode: "#line 1 \"tests/median_heap.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc127/tasks/abc127_f\"\
    \n\n#include <iostream>\n#line 1 \"tools/median_heap.hpp\"\n\n\n\n#include <functional>\n\
    #include <queue>\n#include <vector>\n#include <cstddef>\n#include <cassert>\n\n\
    namespace tools {\n\n  template <typename T, typename Compare = ::std::less<T>>\n\
    \  class median_heap {\n  private:\n    class RevCompare {\n    private:\n   \
    \   Compare m_less;\n    public:\n      explicit RevCompare(const Compare& less)\
    \ : m_less(less) {\n      }\n      bool operator()(const T& x, const T& y) const\
    \ {\n        return this->m_less(y, x);\n      }\n    };\n\n    Compare m_less;\n\
    \    ::std::priority_queue<T, ::std::vector<T>, Compare> m_pq1;\n    ::std::priority_queue<T,\
    \ ::std::vector<T>, RevCompare> m_pq2;\n\n  public:\n    explicit median_heap(const\
    \ Compare& less) : m_less(less), m_pq1(less), m_pq2(RevCompare(less)) {\n    }\n\
    \    median_heap() : median_heap(Compare()) {\n    }\n    median_heap(const ::tools::median_heap<T,\
    \ Compare>&) = default;\n    median_heap(::tools::median_heap<T, Compare>&&) =\
    \ default;\n    ~median_heap() = default;\n    ::tools::median_heap<T, Compare>&\
    \ operator=(const ::tools::median_heap<T, Compare>&) = default;\n    ::tools::median_heap<T,\
    \ Compare>& operator=(::tools::median_heap<T, Compare>&&) = default;\n\n    bool\
    \ empty() const {\n      return this->m_pq1.empty() && this->m_pq2.empty();\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->m_pq1.size() +\
    \ this->m_pq2.size();\n    }\n\n    T lesser() const {\n      assert(!this->empty());\n\
    \      return this->m_pq1.top();\n    }\n\n    T greater() const {\n      assert(!this->empty());\n\
    \      return this->m_pq1.size() == this->m_pq2.size() ? this->m_pq2.top() : this->m_pq1.top();\n\
    \    }\n\n    void push(const T& v) {\n      if (this->m_pq1.size() == this->m_pq2.size())\
    \ {\n        if (!this->m_pq2.empty() && this->m_less(this->m_pq2.top(), v)) {\n\
    \          this->m_pq1.push(this->m_pq2.top());\n          this->m_pq2.pop();\n\
    \          this->m_pq2.push(v);\n        } else {\n          this->m_pq1.push(v);\n\
    \        }\n      } else {\n        if (this->m_less(v, this->m_pq1.top())) {\n\
    \          this->m_pq2.push(this->m_pq1.top());\n          this->m_pq1.pop();\n\
    \          this->m_pq1.push(v);\n        } else {\n          this->m_pq2.push(v);\n\
    \        }\n      }\n    }\n\n    template <typename... Args>\n    void emplace(Args&&...\
    \ args) {\n      this->push(T(::std::forward<Args>(args)...));\n    }\n\n    void\
    \ swap(::tools::median_heap<T, Compare>& other) {\n      ::std::swap(this->m_less,\
    \ other.m_less);\n      this->m_pq1.swap(other.m_pq1);\n      this->m_pq2.swap(other.m_pq2);\n\
    \    }\n  };\n}\n\n\n#line 5 \"tests/median_heap.test.cpp\"\n\nusing ll = long\
    \ long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll Q;\n  std::cin >> Q;\n\n  tools::median_heap<ll> heap;\n  ll min = 0;\n\
    \  for (ll i = 0; i < Q; ++i) {\n    ll t;\n    std::cin >> t;\n    if (t == 1)\
    \ {\n      ll a, b;\n      std::cin >> a >> b;\n\n      const bool uses_prev_median\
    \ = heap.size() % 2 == 1 && a < heap.lesser();\n      if (uses_prev_median) {\n\
    \        min += std::abs(heap.lesser() - a) + b;\n      }\n      heap.push(a);\n\
    \      if (!uses_prev_median) {\n        min += std::abs(heap.lesser() - a) +\
    \ b;\n      }\n    } else {\n      std::cout << heap.lesser() << ' ' << min <<\
    \ '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc127/tasks/abc127_f\"\n\n\
    #include <iostream>\n#include \"tools/median_heap.hpp\"\n\nusing ll = long long;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll Q;\n  std::cin >> Q;\n\n  tools::median_heap<ll> heap;\n  ll min = 0;\n\
    \  for (ll i = 0; i < Q; ++i) {\n    ll t;\n    std::cin >> t;\n    if (t == 1)\
    \ {\n      ll a, b;\n      std::cin >> a >> b;\n\n      const bool uses_prev_median\
    \ = heap.size() % 2 == 1 && a < heap.lesser();\n      if (uses_prev_median) {\n\
    \        min += std::abs(heap.lesser() - a) + b;\n      }\n      heap.push(a);\n\
    \      if (!uses_prev_median) {\n        min += std::abs(heap.lesser() - a) +\
    \ b;\n      }\n    } else {\n      std::cout << heap.lesser() << ' ' << min <<\
    \ '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/median_heap.hpp
  isVerificationFile: true
  path: tests/median_heap.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/median_heap.test.cpp
layout: document
redirect_from:
- /verify/tests/median_heap.test.cpp
- /verify/tests/median_heap.test.cpp.html
title: tests/median_heap.test.cpp
---
