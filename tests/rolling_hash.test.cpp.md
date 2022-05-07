---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: tools/modint_for_rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: tools/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc141/tasks/abc141_e
    links:
    - https://atcoder.jp/contests/abc141/tasks/abc141_e
  bundledCode: "#line 1 \"tests/rolling_hash.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc141/tasks/abc141_e\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <unordered_map>\n#line 1\
    \ \"tools/rolling_hash.hpp\"\n\n\n\n#include <vector>\n#include <cassert>\n#line\
    \ 1 \"tools/modint_for_rolling_hash.hpp\"\n\n\n\n#line 5 \"tools/modint_for_rolling_hash.hpp\"\
    \n#include <chrono>\n#line 7 \"tools/modint_for_rolling_hash.hpp\"\n\nnamespace\
    \ tools {\n  class modint_for_rolling_hash {\n  private:\n    static constexpr\
    \ ::std::uint64_t MASK30 = (::std::uint64_t(1) << 30) - 1;\n    static constexpr\
    \ ::std::uint64_t MASK31 = (::std::uint64_t(1) << 31) - 1;\n    static constexpr\
    \ ::std::uint64_t MOD = (::std::uint64_t(1) << 61) - 1;\n    static constexpr\
    \ ::std::uint64_t MASK61 = MOD;\n    static constexpr ::std::uint64_t POSITIVIZER\
    \ = MOD * 4;\n\n    inline static ::std::uint64_t m_base = ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \    inline static ::std::vector<::std::uint64_t> m_pow_base;\n    ::std::uint64_t\
    \ m_value;\n\n    modint_for_rolling_hash(const ::std::uint64_t x, int) : m_value(x)\
    \ {\n    }\n\n  public:\n    static ::std::uint64_t mul(const ::std::uint64_t\
    \ a, const ::std::uint64_t b) {\n      assert(a < MOD);\n      assert(b < MOD);\n\
    \      const ::std::uint64_t au = a >> 31;\n      const ::std::uint64_t ad = a\
    \ & MASK31;\n      const ::std::uint64_t bu = b >> 31;\n      const ::std::uint64_t\
    \ bd = b & MASK31;\n      const ::std::uint64_t mid = ad * bu + au * bd;\n   \
    \   const ::std::uint64_t midu = mid >> 30;\n      const ::std::uint64_t midd\
    \ = mid & MASK30;\n      return au * bu * 2 + midu + (midd << 31) + ad * bd;\n\
    \    }\n    static ::std::uint64_t calc_mod(const ::std::uint64_t x) {\n     \
    \ const ::std::uint64_t xu = x >> 61;\n      const ::std::uint64_t xd = x & MASK61;\n\
    \      ::std::uint64_t res = xu + xd;\n      if (res >= MOD) res -= MOD;\n   \
    \   return res;\n    }\n\n    modint_for_rolling_hash() = default;\n    modint_for_rolling_hash(const\
    \ ::tools::modint_for_rolling_hash&) = default;\n    modint_for_rolling_hash(::tools::modint_for_rolling_hash&&)\
    \ = default;\n    ~modint_for_rolling_hash() = default;\n    ::tools::modint_for_rolling_hash&\
    \ operator=(const ::tools::modint_for_rolling_hash&) = default;\n    ::tools::modint_for_rolling_hash&\
    \ operator=(::tools::modint_for_rolling_hash&&) = default;\n\n    explicit modint_for_rolling_hash(const\
    \ ::std::uint64_t x) : m_value(calc_mod(x)) {\n    }\n\n    ::tools::modint_for_rolling_hash\
    \ operator+() const {\n      return *this;\n    }\n    ::tools::modint_for_rolling_hash\
    \ operator-() const {\n      return ::tools::modint_for_rolling_hash(POSITIVIZER\
    \ - this->m_value);\n    }\n    friend ::tools::modint_for_rolling_hash operator+(const\
    \ ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(lhs.m_value + rhs.m_value);\n\
    \    }\n    ::tools::modint_for_rolling_hash& operator+=(const ::tools::modint_for_rolling_hash&\
    \ other) {\n      this->m_value = calc_mod(this->m_value + other.m_value);\n \
    \     return *this;\n    }\n    friend ::tools::modint_for_rolling_hash operator-(const\
    \ ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(lhs.m_value + POSITIVIZER\
    \ - rhs.m_value);\n    }\n    ::tools::modint_for_rolling_hash& operator-=(const\
    \ ::tools::modint_for_rolling_hash& other) {\n      this->m_value = calc_mod(this->m_value\
    \ + POSITIVIZER - other.m_value);\n      return *this;\n    }\n    friend ::tools::modint_for_rolling_hash\
    \ operator*(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(mul(lhs.m_value, rhs.m_value));\n\
    \    }\n    ::tools::modint_for_rolling_hash& operator*=(const ::tools::modint_for_rolling_hash&\
    \ other) {\n      this->m_value = calc_mod(mul(this->m_value, other.m_value));\n\
    \      return *this;\n    }\n\n    friend bool operator==(const ::tools::modint_for_rolling_hash&\
    \ lhs, const ::tools::modint_for_rolling_hash& rhs) {\n      return lhs.m_value\
    \ == rhs.m_value;\n    }\n    friend bool operator!=(const ::tools::modint_for_rolling_hash&\
    \ lhs, const ::tools::modint_for_rolling_hash& rhs) {\n      return lhs.m_value\
    \ != rhs.m_value;\n    }\n\n    ::std::uint64_t val() const {\n      return this->m_value;\n\
    \    }\n\n    static ::tools::modint_for_rolling_hash raw(const ::std::uint64_t\
    \ x) {\n      return ::tools::modint_for_rolling_hash(x, 0);\n    }\n    static\
    \ ::std::uint64_t mod() {\n      return MOD;\n    }\n    static ::std::uint64_t\
    \ positivizer() {\n      return POSITIVIZER;\n    }\n    static ::std::uint64_t\
    \ base() {\n      return m_base;\n    }\n    static ::std::uint64_t pow_base(const\
    \ ::std::uint64_t n) {\n      while (m_pow_base.size() <= n) {\n        m_pow_base.push_back(m_pow_base.empty()\
    \ ? 1 : calc_mod(mul(m_pow_base.back(), m_base)));\n      }\n      return m_pow_base[n];\n\
    \    }\n  };\n}\n\n\n#line 7 \"tools/rolling_hash.hpp\"\n\nnamespace tools {\n\
    \  class rolling_hash {\n  private:\n    using mint = ::tools::modint_for_rolling_hash;\n\
    \    ::std::vector<mint> m_hash;\n\n  public:\n    rolling_hash() = default;\n\
    \    rolling_hash(const ::tools::rolling_hash&) = default;\n    rolling_hash(::tools::rolling_hash&&)\
    \ = default;\n    ~rolling_hash() = default;\n    ::tools::rolling_hash& operator=(const\
    \ ::tools::rolling_hash&) = default;\n    ::tools::rolling_hash& operator=(::tools::rolling_hash&&)\
    \ = default;\n\n    template <typename InputIterator>\n    rolling_hash(InputIterator\
    \ begin, InputIterator end) {\n      this->m_hash.push_back(mint::raw(0));\n \
    \     for (auto it = begin; it != end; ++it) {\n        this->m_hash.emplace_back(mint::mul(this->m_hash.back().val(),\
    \ mint::base()) + *it);\n      }\n    }\n\n    mint slice(const ::std::size_t\
    \ l, const ::std::size_t r) const {\n      assert(l <= r && r <= this->m_hash.size());\n\
    \      return mint(this->m_hash[r].val() + mint::positivizer() - mint::mul(this->m_hash[l].val(),\
    \ mint::pow_base(r - l)));\n    }\n  };\n}\n\n\n#line 1 \"tools/chmax.hpp\"\n\n\
    \n\n#include <algorithm>\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  bool chmax(M& lhs, const N& rhs) {\n    const bool updated = lhs < rhs;\n\
    \    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n#line 8 \"tests/rolling_hash.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  i64\
    \ N;\n  std::string S;\n  std::cin >> N >> S;\n\n  tools::rolling_hash hash(S.begin(),\
    \ S.end());\n  i64 answer = 0;\n  for (i64 n = 1; n <= N; ++n) {\n    std::unordered_map<u64,\
    \ i64> leftmost;\n    for (i64 l = 0; l + n <= N; ++l) {\n      const auto h =\
    \ hash.slice(l, l + n).val();\n      if (auto it = leftmost.find(h); it != leftmost.end())\
    \ {\n        if (it->second <= l - n) {\n          answer = n;\n          break;\n\
    \        }\n      } else {\n        leftmost.emplace(h, l);\n      }\n    }\n\
    \  }\n\n  std::cout << answer << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc141/tasks/abc141_e\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <unordered_map>\n#include \"\
    tools/rolling_hash.hpp\"\n#include \"tools/chmax.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    using u64 = std::uint_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N;\n  std::string S;\n  std::cin >> N >> S;\n\n  tools::rolling_hash hash(S.begin(),\
    \ S.end());\n  i64 answer = 0;\n  for (i64 n = 1; n <= N; ++n) {\n    std::unordered_map<u64,\
    \ i64> leftmost;\n    for (i64 l = 0; l + n <= N; ++l) {\n      const auto h =\
    \ hash.slice(l, l + n).val();\n      if (auto it = leftmost.find(h); it != leftmost.end())\
    \ {\n        if (it->second <= l - n) {\n          answer = n;\n          break;\n\
    \        }\n      } else {\n        leftmost.emplace(h, l);\n      }\n    }\n\
    \  }\n\n  std::cout << answer << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/rolling_hash.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/chmax.hpp
  isVerificationFile: true
  path: tests/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2022-05-07 17:45:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/tests/rolling_hash.test.cpp
- /verify/tests/rolling_hash.test.cpp.html
title: tests/rolling_hash.test.cpp
---
