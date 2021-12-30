---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/bigint.hpp
    title: tools/bigint.hpp
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_B
  bundledCode: "#line 1 \"tests/bigint/minus.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_B\"\
    \n\n#include <iostream>\n#line 1 \"tools/bigint.hpp\"\n\n\n\n#include <vector>\n\
    #include <cstdint>\n#include <cstddef>\n#include <algorithm>\n#include <string>\n\
    #include <cassert>\n#line 11 \"tools/bigint.hpp\"\n#include <iomanip>\n#line 1\
    \ \"tools/quo.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M\
    \ lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else\
    \ {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      }\
    \ else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\
    \n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\
    \n\n\n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\n\n\n\n#line 5 \"tools/detail/ceil_and_floor.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs);\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs);\n  \n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const\
    \ M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs\
    \ / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n\
    \      lhs >= 0 && rhs < 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs,\
    \ -rhs);\n  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\
    \n#line 15 \"tools/bigint.hpp\"\n\nnamespace tools {\n  class bigint {\n  private:\n\
    \    bool m_positive;\n    ::std::vector<::std::int_fast32_t> m_digits;\n    static\
    \ constexpr ::std::int_fast32_t BASE = 10000;\n    static constexpr ::std::int_fast32_t\
    \ LOG10_BASE = 4;\n\n    static int compare_3way(const ::tools::bigint& lhs, const\
    \ ::tools::bigint& rhs) {\n      if (!lhs.m_positive && rhs.m_positive) return\
    \ -1;\n      if (lhs.m_positive && !rhs.m_positive) return 1;\n      return [&]()\
    \ {\n        if (lhs.m_digits.size() < rhs.m_digits.size()) return -1;\n     \
    \   if (lhs.m_digits.size() > rhs.m_digits.size()) return 1;\n        for (::std::size_t\
    \ i = 0; i < lhs.m_digits.size(); ++i) {\n          if (lhs.m_digits[lhs.m_digits.size()\
    \ - 1 - i] < rhs.m_digits[rhs.m_digits.size() - 1 - i]) return -1;\n         \
    \ if (lhs.m_digits[lhs.m_digits.size() - 1 - i] > rhs.m_digits[rhs.m_digits.size()\
    \ - 1 - i]) return 1;\n        }\n        return 0;\n      }() * (lhs.m_positive\
    \ ? 1 : -1);\n    }\n\n    ::tools::bigint& negate() {\n      if (!this->m_digits.empty())\
    \ {\n        this->m_positive = !this->m_positive;\n      }\n      return *this;\n\
    \    }\n\n    ::tools::bigint& regularize(const int level) {\n      if (level\
    \ > 0) {\n        if (level == 2) {\n          for (::std::size_t i = 0; i + 1\
    \ < this->m_digits.size(); ++i) {\n            this->m_digits[i + 1] += ::tools::quo(this->m_digits[i],\
    \ BASE);\n            this->m_digits[i] = ::tools::mod(this->m_digits[i], BASE);\n\
    \          }\n        } else {\n          for (::std::size_t i = 0; i + 1 < this->m_digits.size();\
    \ ++i) {\n            if (this->m_digits[i] < 0) {\n              this->m_digits[i]\
    \ += BASE;\n              --this->m_digits[i + 1];\n            } else if (this->m_digits[i]\
    \ >= BASE) {\n              this->m_digits[i] -= BASE;\n              ++this->m_digits[i\
    \ + 1];\n            }\n          }\n        }\n        if (!this->m_digits.empty()\
    \ && this->m_digits.back() < 0) {\n          this->m_positive = !this->m_positive;\n\
    \          for (::std::size_t i = 0; i < this->m_digits.size(); ++i) {\n     \
    \       this->m_digits[i] = -this->m_digits[i];\n          }\n          for (::std::size_t\
    \ i = 0; i + 1 < this->m_digits.size(); ++i) {\n            if (this->m_digits[i]\
    \ < 0) {\n              this->m_digits[i] = BASE + this->m_digits[i];\n      \
    \        --this->m_digits[i + 1];\n            }\n          }\n        }\n   \
    \     if (level == 2) {\n          while (!this->m_digits.empty() && this->m_digits.back()\
    \ >= BASE) {\n            this->m_digits.push_back(this->m_digits.back() / BASE);\n\
    \            this->m_digits[this->m_digits.size() - 2] %= BASE;\n          }\n\
    \        } else {\n          if (!this->m_digits.empty() && this->m_digits.back()\
    \ >= BASE) {\n            this->m_digits.back() -= BASE;\n            this->m_digits.push_back(1);\n\
    \          }\n        }\n      }\n      while (!this->m_digits.empty() && this->m_digits.back()\
    \ == 0) {\n        this->m_digits.pop_back();\n      }\n      if (this->m_digits.empty()\
    \ && !this->m_positive) {\n        this->m_positive = true;\n      }\n      return\
    \ *this;\n    }\n\n    ::tools::bigint& internal_add(const ::tools::bigint& other,\
    \ const bool plus) {\n      const bool this_positive = this->m_positive;\n   \
    \   if (!this_positive) {\n        this->negate();\n      }\n      this->m_digits.resize(::std::max(this->m_digits.size(),\
    \ other.m_digits.size()));\n      if (this_positive == (other.m_positive == plus))\
    \ {\n        for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {\n   \
    \       this->m_digits[i] += other.m_digits[i];\n        }\n      } else {\n \
    \       for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {\n        \
    \  this->m_digits[i] -= other.m_digits[i];\n        }\n      }\n      this->regularize(1);\n\
    \      if (!this_positive) {\n        this->negate();\n      }\n      return *this;\n\
    \    }\n\n  public:\n    bigint() : m_positive(true) {\n    }\n    bigint(const\
    \ ::tools::bigint&) = default;\n    bigint(::tools::bigint&&) = default;\n   \
    \ ~bigint() = default;\n    ::tools::bigint& operator=(const ::tools::bigint&)\
    \ = default;\n    ::tools::bigint& operator=(::tools::bigint&&) = default;\n\n\
    \    explicit bigint(const ::std::int_fast64_t n) : m_positive(true) {\n     \
    \ this->m_digits.push_back(n);\n      this->regularize(2);\n    }\n    explicit\
    \ bigint(const ::std::string& s) {\n      assert(!s.empty());\n\n      ::std::size_t\
    \ offset;\n      if (s[0] == '+') {\n        this->m_positive = true;\n      \
    \  offset = 1;\n      } else if (s[0] == '-') {\n        this->m_positive = false;\n\
    \        offset = 1;\n      } else {\n        this->m_positive = true;\n     \
    \   offset = 0;\n      }\n\n      this->m_digits.reserve(::tools::ceil<::std::size_t>(s.size()\
    \ - offset, LOG10_BASE));\n      for (::std::size_t i = 0; i < s.size() - offset;\
    \ i += LOG10_BASE) {\n        this->m_digits.push_back(0);\n        for (::std::size_t\
    \ j = ::std::min(i + LOG10_BASE, s.size() - offset); j --> i;) {\n          this->m_digits.back()\
    \ = this->m_digits.back() * 10 + (s[s.size() - 1 - j] - '0');\n        }\n   \
    \   }\n\n      this->regularize(0);\n    }\n\n    friend bool operator==(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return lhs.m_positive\
    \ == rhs.m_positive && lhs.m_digits == rhs.m_digits;\n    }\n    friend bool operator!=(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return !(lhs == rhs);\n\
    \    }\n    friend bool operator<(const ::tools::bigint& lhs, const ::tools::bigint&\
    \ rhs) {\n      return ::tools::bigint::compare_3way(lhs, rhs) < 0;\n    }\n \
    \   friend bool operator>(const ::tools::bigint& lhs, const ::tools::bigint& rhs)\
    \ {\n      return ::tools::bigint::compare_3way(lhs, rhs) > 0;\n    }\n    friend\
    \ bool operator<=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n\
    \      return ::tools::bigint::compare_3way(lhs, rhs) <= 0;\n    }\n    friend\
    \ bool operator>=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n\
    \      return ::tools::bigint::compare_3way(lhs, rhs) >= 0;\n    }\n\n    ::tools::bigint\
    \ operator+() const {\n      return *this;\n    }\n    ::tools::bigint operator-()\
    \ const {\n      return ::tools::bigint(*this).negate();\n    }\n\n    ::tools::bigint&\
    \ operator+=(const ::tools::bigint& other) {\n      return this->internal_add(other,\
    \ true);\n    }\n    ::tools::bigint& operator-=(const ::tools::bigint& other)\
    \ {\n      return this->internal_add(other, false);\n    }\n\n    friend ::tools::bigint\
    \ operator+(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return\
    \ ::tools::bigint(lhs) += rhs;\n    }\n    friend ::tools::bigint operator-(const\
    \ ::tools::bigint& lhs, const ::tools::bigint& rhs) {\n      return ::tools::bigint(lhs)\
    \ -= rhs;\n    }\n\n    friend ::std::istream& operator>>(::std::istream& is,\
    \ ::tools::bigint& self) {\n      ::std::string s;\n      is >> s;\n      self\
    \ = ::tools::bigint(s);\n      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::bigint& self) {\n      if (!self.m_positive) {\n        os\
    \ << '-';\n      }\n      if (self.m_digits.empty()) {\n        return os << '0';\n\
    \      }\n      os << self.m_digits.back();\n      for (::std::size_t i = 1; i\
    \ < self.m_digits.size(); ++i) {\n        os << ::std::setw(LOG10_BASE) << ::std::setfill('0')\
    \ << self.m_digits[self.m_digits.size() - 1 - i];\n      }\n      return os;\n\
    \    }\n  };\n}\n\n\n#line 5 \"tests/bigint/minus.test.cpp\"\n\nint main() {\n\
    \  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  tools::bigint\
    \ A, B;\n  std::cin >> A >> B;\n  std::cout << A - B << '\\n';\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_2_B\"\n\n\
    #include <iostream>\n#include \"tools/bigint.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  tools::bigint A, B;\n  std::cin\
    \ >> A >> B;\n  std::cout << A - B << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/bigint.hpp
  - tools/quo.hpp
  - tools/mod.hpp
  - tools/ceil.hpp
  - tools/detail/ceil_and_floor.hpp
  isVerificationFile: true
  path: tests/bigint/minus.test.cpp
  requiredBy: []
  timestamp: '2021-12-30 23:33:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/bigint/minus.test.cpp
layout: document
redirect_from:
- /verify/tests/bigint/minus.test.cpp
- /verify/tests/bigint/minus.test.cpp.html
title: tests/bigint/minus.test.cpp
---
