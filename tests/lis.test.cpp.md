---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/join.hpp
    title: Join elements with delimiter
  - icon: ':heavy_check_mark:'
    path: tools/lis.hpp
    title: Longest increasing subsequence
  - icon: ':heavy_check_mark:'
    path: tools/persistent_stack.hpp
    title: Persistent stack
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"tests/lis.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include <iostream>\n#include <vector>\n#line 1 \"tools/lis.hpp\"\n\n\n\n\
    #include <tuple>\n#line 6 \"tools/lis.hpp\"\n#include <type_traits>\n#include\
    \ <cstddef>\n#include <algorithm>\n#include <iterator>\n#line 1 \"tools/persistent_stack.hpp\"\
    \n\n\n\n#line 6 \"tools/persistent_stack.hpp\"\n#include <limits>\n#include <cassert>\n\
    #line 9 \"tools/persistent_stack.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class persistent_stack {\n  private:\n    struct node {\n      ::std::size_t\
    \ parent;\n      ::std::size_t depth;\n      T value;\n    };\n\n  public:\n \
    \   class buffer {\n    private:\n      ::std::vector<::tools::persistent_stack<T>::node>\
    \ m_nodes;\n\n    public:\n      buffer() = default;\n      buffer(const ::tools::persistent_stack<T>::buffer&)\
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
    #line 11 \"tools/lis.hpp\"\n\nnamespace tools {\n  template <typename InputIterator>\n\
    \  auto lis(const InputIterator begin, const InputIterator end, const bool strict)\
    \ -> ::std::pair<::std::vector<::std::decay_t<decltype(*begin)>>, ::std::vector<::std::size_t>>\
    \ {\n    using T = ::std::decay_t<decltype(*begin)>;\n    ::std::vector<T> a(begin,\
    \ end);\n    ::tools::persistent_stack<::std::size_t>::buffer buffer;\n    ::std::vector<::tools::persistent_stack<::std::size_t>>\
    \ dp({::tools::persistent_stack<::std::size_t>(buffer)});\n\n    for (::std::size_t\
    \ i = 0; i < a.size(); ++i) {\n      ::std::size_t ok = 0;\n      ::std::size_t\
    \ ng = dp.size();\n      while (ng - ok > 1) {\n        const auto mid = ok +\
    \ (ng - ok) / 2;\n        if (a[dp[mid].top()] < a[i] + (strict ? 0 : 1)) {\n\
    \          ok = mid;\n        } else {\n          ng = mid;\n        }\n     \
    \ }\n      if (ng < dp.size()) {\n        if (a[i] < a[dp[ng].top()]) {\n    \
    \      dp[ng] = dp[ok].push(i);\n        }\n      } else {\n        dp.push_back(dp[ok].push(i));\n\
    \      }\n    }\n\n    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>>\
    \ res;\n    auto& [lis, indices] = res;\n\n    for (auto stack = dp.back(); !stack.empty();\
    \ stack = stack.pop()) {\n      indices.push_back(stack.top());\n    }\n    ::std::reverse(indices.begin(),\
    \ indices.end());\n    ::std::transform(indices.begin(), indices.end(), ::std::back_inserter(lis),\
    \ [&](const ::std::size_t i) { return a[i]; });\n\n    return res;\n  }\n}\n\n\
    \n#line 1 \"tools/join.hpp\"\n\n\n\n#include <string>\n#include <sstream>\n\n\
    namespace tools {\n\n  template <typename Iterator>\n  ::std::string join(const\
    \ Iterator begin, const Iterator end, const ::std::string delimiter) {\n    ::std::ostringstream\
    \ ss;\n    ::std::string current_delimiter = \"\";\n    for (Iterator it = begin;\
    \ it != end; ++it) {\n      ss << current_delimiter << *it;\n      current_delimiter\
    \ = delimiter;\n    }\n    return ss.str();\n  }\n}\n\n\n#line 7 \"tests/lis.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n  std::vector<ll> A(N);\n  for (auto& A_i : A) std::cin\
    \ >> A_i;\n\n  const auto lis_indices = tools::lis(A.begin(), A.end(), true).second;\n\
    \  std::cout << lis_indices.size() << '\\n';\n  std::cout << tools::join(lis_indices.begin(),\
    \ lis_indices.end(), \" \") << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"tools/lis.hpp\"\n#include\
    \ \"tools/join.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll N;\n  std::cin >> N;\n  std::vector<ll>\
    \ A(N);\n  for (auto& A_i : A) std::cin >> A_i;\n\n  const auto lis_indices =\
    \ tools::lis(A.begin(), A.end(), true).second;\n  std::cout << lis_indices.size()\
    \ << '\\n';\n  std::cout << tools::join(lis_indices.begin(), lis_indices.end(),\
    \ \" \") << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/lis.hpp
  - tools/persistent_stack.hpp
  - tools/join.hpp
  isVerificationFile: true
  path: tests/lis.test.cpp
  requiredBy: []
  timestamp: '2022-11-06 09:37:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/lis.test.cpp
layout: document
redirect_from:
- /verify/tests/lis.test.cpp
- /verify/tests/lis.test.cpp.html
title: tests/lis.test.cpp
---
