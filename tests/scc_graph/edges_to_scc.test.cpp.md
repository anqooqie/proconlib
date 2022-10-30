---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/dynamic_bitset.hpp
    title: std::bitset with dynamic size
  - icon: ':question:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/scc_graph.hpp
    title: Strongly connected component decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc204/tasks/abc204_c
    links:
    - https://atcoder.jp/contests/abc204/tasks/abc204_c
  bundledCode: "#line 1 \"tests/scc_graph/edges_to_scc.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc204/tasks/abc204_c\"\n\n#include <iostream>\n\
    #line 1 \"tools/scc_graph.hpp\"\n\n\n\n#include <vector>\n#include <utility>\n\
    #include <cstddef>\n#include <cassert>\n#include <stack>\n#include <algorithm>\n\
    #line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class F>\n\
    \  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 11 \"tools/scc_graph.hpp\"\n\nnamespace tools {\n \
    \ class scc_graph {\n  private:\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_rev_graph;\n    ::std::vector<::std::size_t>\
    \ m_vid2scc;\n    ::std::vector<::std::vector<::std::size_t>> m_sccs;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_edges_in_scc;\n    ::std::vector<::std::vector<::std::pair<::std::size_t,\
    \ ::std::vector<::std::size_t>>>> m_scc_graph;\n    ::std::vector<::std::vector<::std::pair<::std::size_t,\
    \ ::std::vector<::std::size_t>>>> m_rev_scc_graph;\n    bool m_built;\n\n  public:\n\
    \    scc_graph() = default;\n    scc_graph(const ::tools::scc_graph&) = default;\n\
    \    scc_graph(::tools::scc_graph&&) = default;\n    ~scc_graph() = default;\n\
    \    ::tools::scc_graph& operator=(const ::tools::scc_graph&) = default;\n   \
    \ ::tools::scc_graph& operator=(::tools::scc_graph&&) = default;\n\n    explicit\
    \ scc_graph(const ::std::size_t n) : m_graph(n), m_rev_graph(n), m_vid2scc(n),\
    \ m_built(false) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(const ::std::size_t from, const ::std::size_t\
    \ to) {\n      assert(from < this->size());\n      assert(to < this->size());\n\
    \      assert(!this->m_built);\n      const auto edge_id = this->m_edges.size();\n\
    \      this->m_edges.emplace_back(from, to);\n      this->m_graph[from].push_back(edge_id);\n\
    \      this->m_rev_graph[to].push_back(edge_id);\n      return edge_id;\n    }\n\
    \n    ::std::pair<::std::size_t, ::std::size_t> edge(const ::std::size_t i) const\
    \ {\n      assert(i < this->m_edges.size());\n      return this->m_edges[i];\n\
    \    }\n    const ::std::vector<::std::size_t>& edges_from(const ::std::size_t\
    \ i) const {\n      assert(i < this->size());\n      return this->m_graph[i];\n\
    \    }\n    const ::std::vector<::std::size_t>& edges_to(const ::std::size_t i)\
    \ const {\n      assert(i < this->size());\n      return this->m_rev_graph[i];\n\
    \    }\n\n    void build() {\n      assert(!this->m_built);\n      ::std::stack<::std::size_t>\
    \ ordered_by_dfs;\n      {\n        ::std::vector<bool> visited(this->size(),\
    \ false);\n        ::std::stack<::std::pair<bool, ::std::size_t>> stack;\n   \
    \     for (::std::size_t i = this->size(); i --> 0;) {\n          stack.emplace(true,\
    \ i);\n        }\n        while (!stack.empty()) {\n          const auto [pre,\
    \ here] = stack.top();\n          stack.pop();\n          if (pre) {\n       \
    \     if (visited[here]) continue;\n            visited[here] = true;\n      \
    \      stack.emplace(false, here);\n            for (const auto e : this->m_graph[here])\
    \ {\n              const auto next = this->m_edges[e].second;\n              if\
    \ (visited[next]) continue;\n              stack.emplace(true, next);\n      \
    \      }\n          } else {\n            ordered_by_dfs.push(here);\n       \
    \   }\n        }\n      }\n\n      {\n        ::std::vector<bool> visited(this->size(),\
    \ false);\n        while (!ordered_by_dfs.empty()) {\n          const auto root\
    \ = ordered_by_dfs.top();\n          ordered_by_dfs.pop();\n          if (visited[root])\
    \ continue;\n\n          const auto scc_id = this->m_sccs.size();\n          this->m_sccs.emplace_back();\n\
    \          this->m_edges_in_scc.emplace_back();\n          this->m_scc_graph.emplace_back();\n\
    \          this->m_rev_scc_graph.emplace_back();\n\n          ::std::stack<::std::size_t>\
    \ stack({root});\n          while (!stack.empty()) {\n            const auto here\
    \ = stack.top();\n            stack.pop();\n            if (visited[here]) continue;\n\
    \            visited[here] = true;\n\n            this->m_vid2scc[here] = scc_id;\n\
    \            this->m_sccs[scc_id].push_back(here);\n\n            for (const auto\
    \ e : this->m_rev_graph[here]) {\n              const auto next = this->m_edges[e].first;\n\
    \              if (visited[next]) continue;\n              stack.push(next);\n\
    \            }\n          }\n\n          ::std::vector<::std::size_t> buffer;\
    \ \n          for (const auto v : this->m_sccs[scc_id]) {\n            for (const\
    \ auto e : this->m_rev_graph[v]) {\n              const auto u = this->m_edges[e].first;\n\
    \              if (this->m_vid2scc[u] == this->m_vid2scc[v]) {\n             \
    \   this->m_edges_in_scc[scc_id].push_back(e);\n              } else {\n     \
    \           buffer.push_back(e);\n              }\n            }\n          }\n\
    \n          ::std::sort(buffer.begin(), buffer.end(), tools::less_by([&](const\
    \ auto e) { return this->m_vid2scc[this->m_edges[e].first]; }));\n          for\
    \ (::std::size_t l = 0, r = 0; l < buffer.size(); l = r) {\n            const\
    \ auto u_scc_id = this->m_vid2scc[this->m_edges[buffer[l]].first];\n         \
    \   this->m_rev_scc_graph[scc_id].emplace_back(u_scc_id, ::std::vector<::std::size_t>());\n\
    \            for (; r < buffer.size() && this->m_vid2scc[this->m_edges[buffer[l]].first]\
    \ == this->m_vid2scc[this->m_edges[buffer[r]].first]; ++r);\n            for (::std::size_t\
    \ i = l; i < r; ++i) {\n              this->m_rev_scc_graph[scc_id].back().second.push_back(buffer[i]);\n\
    \            }\n          }\n        }\n\n        for (::std::size_t v_scc_id\
    \ = 0; v_scc_id < this->m_sccs.size(); ++v_scc_id) {\n          for (const auto&\
    \ [u_scc_id, edge_ids] : this->m_rev_scc_graph[v_scc_id]) {\n            this->m_scc_graph[u_scc_id].emplace_back(v_scc_id,\
    \ edge_ids);\n          }\n        }\n      }\n\n      this->m_built = true;\n\
    \    }\n\n    ::std::size_t scc_id(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      assert(this->m_built);\n      return this->m_vid2scc[i];\n\
    \    }\n    const ::std::vector<::std::vector<::std::size_t>>& sccs() const {\n\
    \      assert(this->m_built);\n      return this->m_sccs;\n    }\n    const ::std::vector<::std::size_t>&\
    \ edges_in_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_edges_in_scc[i];\n    }\n\
    \    const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_from_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_scc_graph[i];\n    }\n   \
    \ const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_to_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_rev_scc_graph[i];\n    }\n\
    \  };\n}\n\n\n#line 1 \"tools/dynamic_bitset.hpp\"\n\n\n\n#line 6 \"tools/dynamic_bitset.hpp\"\
    \n#include <cstdint>\n#include <limits>\n#include <string>\n#line 11 \"tools/dynamic_bitset.hpp\"\
    \n#include <iterator>\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    assert(rhs != 0);\n    return lhs / rhs + (((lhs > 0 && rhs > 0) || (lhs\
    \ < 0 && rhs < 0)) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/popcount.hpp\"\n\
    \n\n\n#line 8 \"tools/popcount.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n    assert(x\
    \ >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n\
    \    } else {\n      const auto log2 = [](const int w) {\n        if (w == 8)\
    \ return 3;\n        if (w == 16) return 4;\n        if (w == 32) return 5;\n\
    \        if (w == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      if constexpr (::std::numeric_limits<T>::digits == 8) {\n   \
    \     x = (x & UINT8_C(0x55)) + (x >> 1 & UINT8_C(0x55));\n        x = (x & UINT8_C(0x33))\
    \ + (x >> 2 & UINT8_C(0x33));\n        x = (x & UINT8_C(0x0f)) + (x >> 4 & UINT8_C(0x0f));\n\
    \      } else if constexpr (::std::numeric_limits<T>::digits == 16) {\n      \
    \  x = (x & UINT16_C(0x5555)) + (x >> 1 & UINT16_C(0x5555));\n        x = (x &\
    \ UINT16_C(0x3333)) + (x >> 2 & UINT16_C(0x3333));\n        x = (x & UINT16_C(0x0f0f))\
    \ + (x >> 4 & UINT16_C(0x0f0f));\n        x = (x & UINT16_C(0x00ff)) + (x >> 8\
    \ & UINT16_C(0x00ff));\n      } else if constexpr (::std::numeric_limits<T>::digits\
    \ == 32) {\n        x = (x & UINT32_C(0x55555555)) + (x >> 1 & UINT32_C(0x55555555));\n\
    \        x = (x & UINT32_C(0x33333333)) + (x >> 2 & UINT32_C(0x33333333));\n \
    \       x = (x & UINT32_C(0x0f0f0f0f)) + (x >> 4 & UINT32_C(0x0f0f0f0f));\n  \
    \      x = (x & UINT32_C(0x00ff00ff)) + (x >> 8 & UINT32_C(0x00ff00ff));\n   \
    \     x = (x & UINT32_C(0x0000ffff)) + (x >> 16 & UINT32_C(0x0000ffff));\n   \
    \   } else if constexpr (::std::numeric_limits<T>::digits == 64) {\n        x\
    \ = (x & UINT64_C(0x5555555555555555)) + (x >> 1 & UINT64_C(0x5555555555555555));\n\
    \        x = (x & UINT64_C(0x3333333333333333)) + (x >> 2 & UINT64_C(0x3333333333333333));\n\
    \        x = (x & UINT64_C(0x0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT64_C(0x0f0f0f0f0f0f0f0f));\n\
    \        x = (x & UINT64_C(0x00ff00ff00ff00ff)) + (x >> 8 & UINT64_C(0x00ff00ff00ff00ff));\n\
    \        x = (x & UINT64_C(0x0000ffff0000ffff)) + (x >> 16 & UINT64_C(0x0000ffff0000ffff));\n\
    \        x = (x & UINT64_C(0x00000000ffffffff)) + (x >> 32 & UINT64_C(0x00000000ffffffff));\n\
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 15 \"tools/dynamic_bitset.hpp\"\
    \n\nnamespace tools {\n  class dynamic_bitset {\n  private:\n    ::std::size_t\
    \ m_size;\n    ::std::vector<::std::uint64_t> m_bits;\n\n  public:\n    dynamic_bitset()\
    \ : m_size(0) {}\n    dynamic_bitset(const ::tools::dynamic_bitset&) = default;\n\
    \    dynamic_bitset(::tools::dynamic_bitset&&) = default;\n    ~dynamic_bitset()\
    \ = default;\n    ::tools::dynamic_bitset& operator=(const ::tools::dynamic_bitset&)\
    \ = default;\n    ::tools::dynamic_bitset& operator=(::tools::dynamic_bitset&&)\
    \ = default;\n\n    explicit dynamic_bitset(const ::std::size_t size) : m_size(size),\
    \ m_bits(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits),\
    \ 0) {}\n    explicit dynamic_bitset(const ::std::string& str) : m_size(str.size()),\
    \ m_bits(::tools::ceil(str.size(), ::std::numeric_limits<::std::uint64_t>::digits),\
    \ 0) {\n      for (::std::size_t i = 0; i < str.size(); ++i) {\n        const\
    \ auto c = str[str.size() - 1 - i];\n        assert(c == '0' || c == '1');\n \
    \       if (c == '1') {\n          this->m_bits[i / ::std::numeric_limits<::std::uint64_t>::digits]\
    \ |= ::std::uint64_t(1) << (i % ::std::numeric_limits<::std::uint64_t>::digits);\n\
    \        }\n      }\n    }\n\n    ::tools::dynamic_bitset& operator&=(const ::tools::dynamic_bitset&\
    \ other) {\n      assert(this->m_size == other.m_size);\n      for (::std::size_t\
    \ i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i] &= other.m_bits[i];\n\
    \      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& operator|=(const\
    \ ::tools::dynamic_bitset& other) {\n      assert(this->m_size == other.m_size);\n\
    \      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        this->m_bits[i]\
    \ |= other.m_bits[i];\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ operator^=(const ::tools::dynamic_bitset& other) {\n      assert(this->m_size\
    \ == other.m_size);\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        this->m_bits[i] ^= other.m_bits[i];\n      }\n      return *this;\n\
    \    }\n    ::tools::dynamic_bitset& operator<<=(const ::std::size_t pos) {\n\
    \      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \      if (diff < this->m_bits.size()) {\n        if (pos % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;)\
    \ {\n            this->m_bits[i] <<= pos % ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \            if (i > 0) {\n              this->m_bits[i] |= this->m_bits[i - 1]\
    \ >> (::std::numeric_limits<::std::uint64_t>::digits - pos % ::std::numeric_limits<::std::uint64_t>::digits);\n\
    \            }\n          }\n        }\n        if (diff > 0) {\n          for\
    \ (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {\n            this->m_bits[i\
    \ + diff] = this->m_bits[i];\n          }\n          ::std::fill(this->m_bits.begin(),\
    \ ::std::next(this->m_bits.begin(), diff), 0);\n        }\n        if (this->m_size\
    \ % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n          this->m_bits.back()\
    \ &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n        }\n      } else {\n        ::std::fill(this->m_bits.begin(), this->m_bits.end(),\
    \ 0);\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& operator>>=(const\
    \ ::std::size_t pos) {\n      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \      if (diff < this->m_bits.size()) {\n        if (pos % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n          for (::std::size_t i = diff; i < this->m_bits.size(); ++i)\
    \ {\n            this->m_bits[i] >>= pos % ::std::numeric_limits<::std::uint64_t>::digits;\n\
    \            if (i + 1 < this->m_bits.size()) {\n              this->m_bits[i]\
    \ |= this->m_bits[i + 1] << (::std::numeric_limits<::std::uint64_t>::digits -\
    \ pos % ::std::numeric_limits<::std::uint64_t>::digits);\n            }\n    \
    \      }\n        }\n        if (diff > 0) {\n          for (::std::size_t i =\
    \ diff; i < this->m_bits.size(); ++i) {\n            this->m_bits[i - diff] =\
    \ this->m_bits[i];\n          }\n          ::std::fill(::std::next(this->m_bits.begin(),\
    \ this->m_bits.size() - diff), this->m_bits.end(), 0);\n        }\n      } else\
    \ {\n        ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);\n     \
    \ }\n      return *this;\n    }\n    ::tools::dynamic_bitset& set() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), ::std::numeric_limits<::std::uint64_t>::max());\n      if\
    \ (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n    \
    \    this->m_bits.back() &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& set(const\
    \ ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] |= ::std::uint64_t(1) << (pos\
    \ % ::std::numeric_limits<::std::uint64_t>::digits);\n      return *this;\n  \
    \  }\n    ::tools::dynamic_bitset& reset() {\n      ::std::fill(this->m_bits.begin(),\
    \ this->m_bits.end(), 0);\n      return *this;\n    }\n    ::tools::dynamic_bitset&\
    \ reset(const ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] &= ~(::std::uint64_t(1) <<\
    \ (pos % ::std::numeric_limits<::std::uint64_t>::digits));\n      return *this;\n\
    \    }\n    ::tools::dynamic_bitset& set(const ::std::size_t pos, const bool val)\
    \ {\n      return val ? this->set(pos) : this->reset(pos);\n    }\n    ::tools::dynamic_bitset&\
    \ flip() {\n      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n\
    \        this->m_bits[i] = ~this->m_bits[i];\n      }\n      if (this->m_size\
    \ % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n        this->m_bits.back()\
    \ &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n      return *this;\n    }\n    ::tools::dynamic_bitset& flip(const\
    \ ::std::size_t pos) {\n      assert(pos < this->m_size);\n      this->m_bits[pos\
    \ / ::std::numeric_limits<::std::uint64_t>::digits] ^= ::std::uint64_t(1) << (pos\
    \ % ::std::numeric_limits<::std::uint64_t>::digits);\n      return *this;\n  \
    \  }\n    ::tools::dynamic_bitset operator~() const {\n      return ::tools::dynamic_bitset(*this).flip();\n\
    \    }\n    ::std::size_t count() const {\n      ::std::size_t result = 0;\n \
    \     for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {\n        result\
    \ += ::tools::popcount(this->m_bits[i]);\n      }\n      return result;\n    }\n\
    \    ::std::size_t size() const {\n      return this->m_size;\n    }\n    bool\
    \ test(const ::std::size_t pos) const {\n      assert(pos < this->m_size);\n \
    \     return (this->m_bits[pos / ::std::numeric_limits<::std::uint64_t>::digits]\
    \ >> (pos % ::std::numeric_limits<::std::uint64_t>::digits)) & 1;\n    }\n   \
    \ bool operator[](const ::std::size_t pos) const {\n      return this->test(pos);\n\
    \    }\n    bool all() const {\n      if (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits\
    \ > 0) {\n        for (::std::size_t i = 0; i + 1 < this->m_bits.size(); ++i)\
    \ {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return this->m_bits.back()\
    \ == (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      } else {\n        for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max())\
    \ {\n            return false;\n          }\n        }\n        return true;\n\
    \      }\n    }\n    bool any() const {\n      for (::std::size_t i = 0; i < this->m_bits.size();\
    \ ++i) {\n        if (this->m_bits[i] != 0) {\n          return true;\n      \
    \  }\n      }\n      return false;\n    }\n    bool none() const {\n      return\
    \ !this->any();\n    }\n    friend bool operator==(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return lhs.m_size == rhs.m_size\
    \ && lhs.m_bits == rhs.m_bits;\n    }\n    friend bool operator!=(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return !(lhs == rhs);\n  \
    \  }\n    ::tools::dynamic_bitset operator<<(const ::std::size_t pos) const {\n\
    \      return ::tools::dynamic_bitset(*this) <<= pos;\n    }\n    ::tools::dynamic_bitset\
    \ operator>>(const ::std::size_t pos) const {\n      return ::tools::dynamic_bitset(*this)\
    \ >>= pos;\n    }\n    friend ::tools::dynamic_bitset operator&(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ &= rhs;\n    }\n    friend ::tools::dynamic_bitset operator|(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ |= rhs;\n    }\n    friend ::tools::dynamic_bitset operator^(const ::tools::dynamic_bitset&\
    \ lhs, const ::tools::dynamic_bitset& rhs) {\n      return ::tools::dynamic_bitset(lhs)\
    \ ^= rhs;\n    }\n    friend ::std::istream& operator>>(::std::istream& is, ::tools::dynamic_bitset&\
    \ self) {\n      ::std::string s;\n      is >> s;\n      self = ::tools::dynamic_bitset(s);\n\
    \      return is;\n    }\n    friend ::std::ostream& operator<<(::std::ostream&\
    \ os, const ::tools::dynamic_bitset& self) {\n      for (::std::size_t i = self.m_bits.size();\
    \ i --> 0;) {\n        for (::std::size_t j = (self.m_size - 1) % ::std::numeric_limits<::std::uint64_t>::digits\
    \ + 1; j --> 0;) {\n          os << ((self.m_bits[i] >> j) & 1);\n        }\n\
    \      }\n      return os;\n    }\n    void resize(const ::std::size_t size) {\n\
    \      this->m_size = size;\n      this->m_bits.resize(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits));\n\
    \      if (size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {\n    \
    \    this->m_bits.back() &= (::std::uint64_t(1) << (size % ::std::numeric_limits<::std::uint64_t>::digits))\
    \ - 1;\n      }\n    }\n    void shrink_to_fit() {\n      this->m_bits.shrink_to_fit();\n\
    \    }\n  };\n}\n\n\n#line 6 \"tests/scc_graph/edges_to_scc.test.cpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M;\n  std::cin >> N >> M;\n  tools::scc_graph graph(N);\n  for (ll i\
    \ = 0; i < M; ++i) {\n    ll A, B;\n    std::cin >> A >> B;\n    --A, --B;\n \
    \   graph.add_edge(A, B);\n  }\n\n  graph.build();\n\n  std::vector<tools::dynamic_bitset>\
    \ dp(graph.sccs().size(), tools::dynamic_bitset(N));\n  for (ll i = graph.sccs().size()\
    \ - 1; i >= 0; --i) {\n    for (const auto v : graph.sccs()[i]) {\n      dp[i].set(v);\n\
    \    }\n    for (const auto& [j, unused] : graph.edges_to_scc(i)) {\n      dp[j]\
    \ |= dp[i];\n    }\n  }\n\n  ll answer = 0;\n  for (ll i = 0; i < N; ++i) {\n\
    \    answer += dp[graph.scc_id(i)].count();\n  }\n  std::cout << answer << '\\\
    n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc204/tasks/abc204_c\"\n\n\
    #include <iostream>\n#include \"tools/scc_graph.hpp\"\n#include \"tools/dynamic_bitset.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M;\n  std::cin >> N >> M;\n  tools::scc_graph graph(N);\n  for (ll i\
    \ = 0; i < M; ++i) {\n    ll A, B;\n    std::cin >> A >> B;\n    --A, --B;\n \
    \   graph.add_edge(A, B);\n  }\n\n  graph.build();\n\n  std::vector<tools::dynamic_bitset>\
    \ dp(graph.sccs().size(), tools::dynamic_bitset(N));\n  for (ll i = graph.sccs().size()\
    \ - 1; i >= 0; --i) {\n    for (const auto v : graph.sccs()[i]) {\n      dp[i].set(v);\n\
    \    }\n    for (const auto& [j, unused] : graph.edges_to_scc(i)) {\n      dp[j]\
    \ |= dp[i];\n    }\n  }\n\n  ll answer = 0;\n  for (ll i = 0; i < N; ++i) {\n\
    \    answer += dp[graph.scc_id(i)].count();\n  }\n  std::cout << answer << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - tools/scc_graph.hpp
  - tools/less_by.hpp
  - tools/dynamic_bitset.hpp
  - tools/ceil.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/scc_graph/edges_to_scc.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/scc_graph/edges_to_scc.test.cpp
layout: document
redirect_from:
- /verify/tests/scc_graph/edges_to_scc.test.cpp
- /verify/tests/scc_graph/edges_to_scc.test.cpp.html
title: tests/scc_graph/edges_to_scc.test.cpp
---
