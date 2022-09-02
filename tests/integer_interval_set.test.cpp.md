---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/detail/interval_set.hpp
    title: tools/detail/interval_set.hpp
  - icon: ':heavy_check_mark:'
    path: tools/integer_interval_set.hpp
    title: Set of integers as closed integer intervals
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc228/tasks/abc228_d
    links:
    - https://atcoder.jp/contests/abc228/tasks/abc228_d
  bundledCode: "#line 1 \"tests/integer_interval_set.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc228/tasks/abc228_d\"\n\n#include <cstdint>\n#include\
    \ <iostream>\n#include <vector>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <cstddef>\n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/integer_interval_set.hpp\"\
    \n\n\n\n#line 1 \"tools/detail/interval_set.hpp\"\n\n\n\n#include <map>\n#include\
    \ <iterator>\n#include <optional>\n#include <utility>\n#line 9 \"tools/detail/interval_set.hpp\"\
    \n#include <string>\n\nnamespace tools {\n  namespace detail {\n    template <typename\
    \ T, bool Mergeable>\n    class interval_set {\n    private:\n      // closed\
    \ intervals\n      ::std::map<T, T> m_intervals;\n  \n    public:\n      interval_set()\
    \ = default;\n      interval_set(const ::tools::detail::interval_set<T, Mergeable>&)\
    \ = default;\n      interval_set(::tools::detail::interval_set<T, Mergeable>&&)\
    \ = default;\n      ~interval_set() = default;\n      ::tools::detail::interval_set<T,\
    \ Mergeable>& operator=(const ::tools::detail::interval_set<T, Mergeable>&) =\
    \ default;\n      ::tools::detail::interval_set<T, Mergeable>& operator=(::tools::detail::interval_set<T,\
    \ Mergeable>&&) = default;\n  \n      auto begin() const {\n        return this->m_intervals.begin();\n\
    \      }\n  \n      auto end() const {\n        return this->m_intervals.end();\n\
    \      }\n  \n      bool empty() const {\n        return this->m_intervals.empty();\n\
    \      }\n  \n      auto size() const {\n        return this->m_intervals.size();\n\
    \      }\n  \n      auto find(const T& x) const {\n        const auto next = this->m_intervals.upper_bound(x);\n\
    \        if (next == this->m_intervals.begin()) return this->m_intervals.end();\n\
    \        const auto prev = ::std::prev(next);\n        if (prev->second < x) return\
    \ this->m_intervals.end();\n        return prev;\n      }\n  \n      bool contains(const\
    \ T& x) const {\n        return this->find(x) != this->m_intervals.end();\n  \
    \    }\n  \n      auto lower_bound(const T& x) const {\n        const auto next\
    \ = this->m_intervals.lower_bound(x);\n        if (next == this->m_intervals.begin())\
    \ return next;\n        const auto prev = ::std::prev(next);\n        if (prev->second\
    \ < x) return next;\n        return prev;\n      }\n  \n      auto upper_bound(const\
    \ T& x) const {\n        return this->m_intervals.upper_bound(x);\n      }\n \
    \ \n      void insert(const T& l, const T& r) {\n        if (!(l <= r)) {\n  \
    \        return;\n        }\n  \n        const auto l_it = this->find(l - (Mergeable\
    \ ? 1 : 0));\n        const T min = l_it != this->m_intervals.end() ? l_it->first\
    \ : l;\n        const auto r_it = this->find(r + (Mergeable ? 1 : 0));\n     \
    \   const T max = r_it != this->m_intervals.end() ? r_it->second : r;\n  \n  \
    \      this->m_intervals.erase(this->lower_bound(l - (Mergeable ? 1 : 0)), this->upper_bound(r\
    \ + (Mergeable ? 1 : 0)));\n        this->m_intervals.emplace(min, max);\n   \
    \   }\n  \n      void erase(const T& l, const T& r) {\n        if (!(l <= r +\
    \ (Mergeable ? 0 : 1))) {\n          return;\n        }\n  \n        const auto\
    \ l_it = this->find(l);\n        const auto l_new_interval = l_it != this->m_intervals.end()\
    \ && l_it->first <= l - (Mergeable ? 1 : 0)\n          ? ::std::make_optional(::std::make_pair(l_it->first,\
    \ l - (Mergeable ? 1 : 0)))\n          : ::std::nullopt;\n        const auto r_it\
    \ = this->find(r);\n        const auto r_new_interval = r_it != this->m_intervals.end()\
    \ && r + (Mergeable ? 1 : 0) <= r_it->second\n          ? ::std::make_optional(::std::make_pair(r\
    \ + (Mergeable ? 1 : 0), r_it->second))\n          : ::std::nullopt;\n  \n   \
    \     this->m_intervals.erase(this->lower_bound(l), this->upper_bound(r));\n \
    \ \n        if (l_new_interval) {\n          this->m_intervals.emplace(l_new_interval->first,\
    \ l_new_interval->second);\n        }\n        if (r_new_interval) {\n       \
    \   this->m_intervals.emplace(r_new_interval->first, r_new_interval->second);\n\
    \        }\n      }\n  \n      friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::detail::interval_set<T, Mergeable>& self) {\n        os <<\
    \ '{';\n        ::std::string delimiter = \"\";\n        for (const auto& [l,\
    \ r] : self) {\n          os << delimiter << '[' << l << \", \" << r << ']';\n\
    \          delimiter = \", \";\n        }\n        os << '}';\n        return\
    \ os;\n      }\n    };\n  }\n}\n\n\n#line 5 \"tools/integer_interval_set.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  using integer_interval_set =\
    \ ::tools::detail::interval_set<T, true>;\n}\n\n\n#line 8 \"tests/integer_interval_set.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  const i64 N = tools::pow2(20);\n\
    \  std::vector<i64> A(N, -1);\n  tools::integer_interval_set<i64> set;\n\n  i64\
    \ Q;\n  std::cin >> Q;\n  for (i64 q = 0; q < Q; ++q) {\n    i64 t, x;\n    std::cin\
    \ >> t >> x;\n    if (t == 1) {\n      const i64 h = [&]() -> i64 {\n        if\
    \ (auto it = set.find(x % N); it != set.end()) {\n          if (it->second ==\
    \ N - 1) {\n            if (auto it2 = set.find(0); it2 != set.end()) {\n    \
    \          return it2->second + 1;\n            } else {\n              return\
    \ 0;\n            }\n          } else {\n            return it->second + 1;\n\
    \          }\n        } else {\n          return x % N;\n        }\n      }();\n\
    \      A[h] = x;\n      set.insert(h, h);\n    } else {\n      std::cout << A[x\
    \ % N] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc228/tasks/abc228_d\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n#include \"tools/pow2.hpp\"\
    \n#include \"tools/integer_interval_set.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const i64 N = tools::pow2(20);\n  std::vector<i64> A(N, -1);\n  tools::integer_interval_set<i64>\
    \ set;\n\n  i64 Q;\n  std::cin >> Q;\n  for (i64 q = 0; q < Q; ++q) {\n    i64\
    \ t, x;\n    std::cin >> t >> x;\n    if (t == 1) {\n      const i64 h = [&]()\
    \ -> i64 {\n        if (auto it = set.find(x % N); it != set.end()) {\n      \
    \    if (it->second == N - 1) {\n            if (auto it2 = set.find(0); it2 !=\
    \ set.end()) {\n              return it2->second + 1;\n            } else {\n\
    \              return 0;\n            }\n          } else {\n            return\
    \ it->second + 1;\n          }\n        } else {\n          return x % N;\n  \
    \      }\n      }();\n      A[h] = x;\n      set.insert(h, h);\n    } else {\n\
    \      std::cout << A[x % N] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/pow2.hpp
  - tools/integer_interval_set.hpp
  - tools/detail/interval_set.hpp
  isVerificationFile: true
  path: tests/integer_interval_set.test.cpp
  requiredBy: []
  timestamp: '2022-03-12 16:17:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/integer_interval_set.test.cpp
layout: document
redirect_from:
- /verify/tests/integer_interval_set.test.cpp
- /verify/tests/integer_interval_set.test.cpp.html
title: tests/integer_interval_set.test.cpp
---
