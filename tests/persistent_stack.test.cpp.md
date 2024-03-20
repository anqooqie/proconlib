---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':question:'
    path: tools/greater_by_second.hpp
    title: std::greater by second
  - icon: ':question:'
    path: tools/persistent_stack.hpp
    title: Persistent stack
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"tests/persistent_stack.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#include <limits>\n\
    #include <queue>\n#include <algorithm>\n#line 1 \"tools/persistent_stack.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 7 \"tools/persistent_stack.hpp\"\n#include <cassert>\n\
    #include <type_traits>\n\nnamespace tools {\n  template <typename T>\n  class\
    \ persistent_stack {\n  private:\n    struct node {\n      ::std::size_t parent;\n\
    \      ::std::size_t depth;\n      T value;\n    };\n\n  public:\n    class buffer\
    \ {\n    private:\n      ::std::vector<::tools::persistent_stack<T>::node> m_nodes;\n\
    \n    public:\n      buffer() = default;\n      buffer(const ::tools::persistent_stack<T>::buffer&)\
    \ = default;\n      buffer(::tools::persistent_stack<T>::buffer&&) = default;\n\
    \      ~buffer() = default;\n      ::tools::persistent_stack<T>::buffer& operator=(const\
    \ ::tools::persistent_stack<T>::buffer&) = default;\n      ::tools::persistent_stack<T>::buffer&\
    \ operator=(::tools::persistent_stack<T>::buffer&&) = default;\n\n      friend\
    \ ::tools::persistent_stack<T>;\n    };\n\n  private:\n    static const ::std::size_t\
    \ EMPTY = ::std::numeric_limits<::std::size_t>::max();\n    ::tools::persistent_stack<T>::buffer\
    \ *m_buffer;\n    ::std::size_t m_top;\n\n    persistent_stack(::tools::persistent_stack<T>::buffer&\
    \ buffer, const ::std::size_t top) : m_buffer(&buffer), m_top(top) {\n    }\n\n\
    \  public:\n    persistent_stack() = default;\n    persistent_stack(const ::tools::persistent_stack<T>&)\
    \ = default;\n    persistent_stack(::tools::persistent_stack<T>&&) = default;\n\
    \    ~persistent_stack() = default;\n    ::tools::persistent_stack<T>& operator=(const\
    \ ::tools::persistent_stack<T>&) = default;\n    ::tools::persistent_stack<T>&\
    \ operator=(::tools::persistent_stack<T>&&) = default;\n\n    explicit persistent_stack(::tools::persistent_stack<T>::buffer&\
    \ buffer) : m_buffer(&buffer), m_top(EMPTY) {\n    }\n\n    bool empty() const\
    \ {\n      return this->m_top == EMPTY;\n    }\n\n    ::std::size_t size() const\
    \ {\n      return this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth\
    \ + 1;\n    }\n\n    T top() const {\n      assert(!this->empty());\n      return\
    \ this->m_buffer->m_nodes[this->m_top].value;\n    }\n\n    ::tools::persistent_stack<T>\
    \ push(const T& x) const {\n      this->m_buffer->m_nodes.emplace_back();\n  \
    \    this->m_buffer->m_nodes.back().parent = this->m_top;\n      this->m_buffer->m_nodes.back().depth\
    \ = this->empty() ? 0 : this->m_buffer->m_nodes[this->m_top].depth + 1;\n    \
    \  this->m_buffer->m_nodes.back().value = x;\n      return ::tools::persistent_stack<T>(*this->m_buffer,\
    \ this->m_buffer->m_nodes.size() - 1);\n    }\n\n    ::tools::persistent_stack<T>\
    \ pop() const {\n      assert(!this->empty());\n      return ::tools::persistent_stack<T>(*this->m_buffer,\
    \ this->m_buffer->m_nodes[this->m_top].parent);\n    }\n\n    template <typename...\
    \ Args>\n    ::tools::persistent_stack<T> emplace(Args&&... args) const {\n  \
    \    return this->push(T(::std::forward<Args>(args)...));\n    }\n  };\n}\n\n\n\
    #line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#line 5 \"tools/greater_by_second.hpp\"\
    \n\nnamespace tools {\n\n  class greater_by_second {\n  public:\n    template\
    \ <class T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const\
    \ ::std::pair<T1, T2>& y) const {\n      return x.second > y.second;\n    }\n\
    \  };\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\
    \n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T, typename U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n\
    \    using UT = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n\
    \    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool\
    \ updated = ::tools::cmp_less(rhs, lhs);\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 6 \"tools/ssize.hpp\"\
    \n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto ssize(const\
    \ C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 13 \"tests/persistent_stack.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n  std::vector<std::vector<std::pair<ll,\
    \ ll>>> graph(N);\n  for (ll i = 0; i < M; ++i) {\n    ll a, b, c;\n    std::cin\
    \ >> a >> b >> c;\n    graph[a].emplace_back(b, c);\n  }\n\n  std::vector<ll>\
    \ dist(N, std::numeric_limits<ll>::max());\n  dist[s] = 0;\n\n  tools::persistent_stack<ll>::buffer\
    \ buffer;\n  std::vector<tools::persistent_stack<ll>> path(N, tools::persistent_stack<ll>(buffer));\n\
    \  path[s] = path[s].push(s);\n\n  std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll,\
    \ ll>>, tools::greater_by_second> pq;\n  pq.emplace(s, 0);\n  while (!pq.empty())\
    \ {\n    const auto [here, d] = pq.top();\n    pq.pop();\n    if (dist[here] <\
    \ d) continue;\n    for (const auto& [next, w] : graph[here]) {\n      if (tools::chmin(dist[next],\
    \ dist[here] + w)) {\n        path[next] = path[here].push(next);\n        pq.emplace(next,\
    \ dist[next]);\n      }\n    }\n  }\n\n  if (dist[t] == std::numeric_limits<ll>::max())\
    \ {\n    std::cout << -1 << '\\n';\n    return 0;\n  }\n\n  std::cout << dist[t]\
    \ << ' ' << path[t].size() - 1 << '\\n';\n  std::vector<ll> answers;\n  for (auto\
    \ stack = path[t]; !stack.empty(); stack = stack.pop()) {\n    answers.push_back(stack.top());\n\
    \  }\n  std::reverse(answers.begin(), answers.end());\n  for (ll i = 0; i + 1\
    \ < tools::ssize(answers); ++i) {\n    std::cout << answers[i] << ' ' << answers[i\
    \ + 1] << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <utility>\n#include <limits>\n#include\
    \ <queue>\n#include <algorithm>\n#include \"tools/persistent_stack.hpp\"\n#include\
    \ \"tools/greater_by_second.hpp\"\n#include \"tools/chmin.hpp\"\n#include \"tools/ssize.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n  std::vector<std::vector<std::pair<ll,\
    \ ll>>> graph(N);\n  for (ll i = 0; i < M; ++i) {\n    ll a, b, c;\n    std::cin\
    \ >> a >> b >> c;\n    graph[a].emplace_back(b, c);\n  }\n\n  std::vector<ll>\
    \ dist(N, std::numeric_limits<ll>::max());\n  dist[s] = 0;\n\n  tools::persistent_stack<ll>::buffer\
    \ buffer;\n  std::vector<tools::persistent_stack<ll>> path(N, tools::persistent_stack<ll>(buffer));\n\
    \  path[s] = path[s].push(s);\n\n  std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll,\
    \ ll>>, tools::greater_by_second> pq;\n  pq.emplace(s, 0);\n  while (!pq.empty())\
    \ {\n    const auto [here, d] = pq.top();\n    pq.pop();\n    if (dist[here] <\
    \ d) continue;\n    for (const auto& [next, w] : graph[here]) {\n      if (tools::chmin(dist[next],\
    \ dist[here] + w)) {\n        path[next] = path[here].push(next);\n        pq.emplace(next,\
    \ dist[next]);\n      }\n    }\n  }\n\n  if (dist[t] == std::numeric_limits<ll>::max())\
    \ {\n    std::cout << -1 << '\\n';\n    return 0;\n  }\n\n  std::cout << dist[t]\
    \ << ' ' << path[t].size() - 1 << '\\n';\n  std::vector<ll> answers;\n  for (auto\
    \ stack = path[t]; !stack.empty(); stack = stack.pop()) {\n    answers.push_back(stack.top());\n\
    \  }\n  std::reverse(answers.begin(), answers.end());\n  for (ll i = 0; i + 1\
    \ < tools::ssize(answers); ++i) {\n    std::cout << answers[i] << ' ' << answers[i\
    \ + 1] << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/persistent_stack.hpp
  - tools/greater_by_second.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/ssize.hpp
  isVerificationFile: true
  path: tests/persistent_stack.test.cpp
  requiredBy: []
  timestamp: '2024-03-20 23:37:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/persistent_stack.test.cpp
layout: document
redirect_from:
- /verify/tests/persistent_stack.test.cpp
- /verify/tests/persistent_stack.test.cpp.html
title: tests/persistent_stack.test.cpp
---
