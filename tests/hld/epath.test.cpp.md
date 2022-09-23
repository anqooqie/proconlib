---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/hld.hpp
    title: Heavy-light decomposition
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D
  bundledCode: "#line 1 \"tests/hld/epath.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #line 1 \"lib/ac-library/atcoder/fenwicktree.hpp\"\n\n\n\n#include <cassert>\n\
    #line 6 \"lib/ac-library/atcoder/fenwicktree.hpp\"\n\n#line 1 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 5 \"lib/ac-library/atcoder/internal_type_traits.hpp\"\n#include\
    \ <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n    typename\
    \ std::conditional<std::is_same<T, __int128_t>::value ||\n                   \
    \               std::is_same<T, __int128>::value,\n                          \
    \    std::true_type,\n                              std::false_type>::type;\n\n\
    template <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"lib/ac-library/atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"tools/hld.hpp\"\n\n\n\n#line 5 \"tools/hld.hpp\"\n#include\
    \ <cstddef>\n#include <iterator>\n#line 8 \"tools/hld.hpp\"\n#include <limits>\n\
    #include <stack>\n#include <utility>\n#line 1 \"lib/ac-library/atcoder/dsu.hpp\"\
    \n\n\n\n#line 7 \"lib/ac-library/atcoder/dsu.hpp\"\n\nnamespace atcoder {\n\n\
    // Implement (union by size) + (path compression)\n// Reference:\n// Zvi Galil\
    \ and Giuseppe F. Italiano,\n// Data structures and algorithms for disjoint set\
    \ union problems\nstruct dsu {\n  public:\n    dsu() : _n(0) {}\n    explicit\
    \ dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\n    int merge(int a, int b)\
    \ {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n  \
    \      int x = leader(a), y = leader(b);\n        if (x == y) return x;\n    \
    \    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return x;\n \
    \   }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n  \
    \      assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n   \
    \ }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        return parent_or_size[a] = leader(parent_or_size[a]);\n\
    \    }\n\n    int size(int a) {\n        assert(0 <= a && a < _n);\n        return\
    \ -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace atcoder\n\
    \n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class\
    \ F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 16 \"tools/hld.hpp\"\n\
    \nnamespace tools {\n  class hld {\n  private:\n    bool m_built;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    ::std::vector<::std::size_t> m_edges;\n    ::std::vector<::std::size_t>\
    \ m_parent;\n    ::std::vector<::std::size_t> m_depth;\n    ::atcoder::dsu m_dsu;\n\
    \    ::std::vector<::std::size_t> m_out;\n    ::std::vector<::std::size_t> m_vid2dfs;\n\
    \    ::std::vector<::std::size_t> m_dfs2vid;\n    ::std::vector<::std::size_t>\
    \ m_eid2dfs;\n    ::std::vector<::std::size_t> m_dfs2eid;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_ancestors;\n\n  public:\n    class vchildren_iterable {\n    private:\n  \
    \    ::tools::hld const *m_parent;\n      ::std::size_t m_v;\n\n    public:\n\
    \      class iterator {\n      private:\n        ::tools::hld const *m_parent;\n\
    \        ::std::size_t m_v;\n        ::std::size_t m_i;\n\n      public:\n   \
    \     using difference_type = ::std::ptrdiff_t;\n        using value_type = ::std::size_t;\n\
    \        using reference = ::std::size_t&;\n        using pointer = ::std::size_t*;\n\
    \        using iterator_category = ::std::input_iterator_tag;\n\n        iterator()\
    \ = default;\n        iterator(const iterator&) = default;\n        iterator(iterator&&)\
    \ = default;\n        ~iterator() = default;\n        iterator& operator=(const\
    \ iterator&) = default;\n        iterator& operator=(iterator&&) = default;\n\n\
    \        iterator(::tools::hld const * const parent, const ::std::size_t v, const\
    \ ::std::size_t i) :\n          m_parent(parent),\n          m_v(v),\n       \
    \   m_i(i) {\n        }\n\n        ::std::size_t operator*() const {\n       \
    \   return this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]]\
    \ ^ this->m_v;\n        }\n        iterator& operator++() {\n          ++this->m_i;\n\
    \          return *this;\n        }\n        iterator operator++(int) {\n    \
    \      const auto self = *this;\n          ++*this;\n          return self;\n\
    \        }\n        friend bool operator==(const iterator& lhs, const iterator&\
    \ rhs) {\n          return lhs.m_parent == rhs.m_parent && lhs.m_v == rhs.m_v\
    \ && lhs.m_i == rhs.m_i;\n        }\n        friend bool operator!=(const iterator&\
    \ lhs, const iterator& rhs) {\n          return !(lhs == rhs);\n        }\n  \
    \    };\n\n      vchildren_iterable() = default;\n      vchildren_iterable(const\
    \ vchildren_iterable&) = default;\n      vchildren_iterable(vchildren_iterable&&)\
    \ = default;\n      ~vchildren_iterable() = default;\n      vchildren_iterable&\
    \ operator=(const vchildren_iterable&) = default;\n      vchildren_iterable& operator=(vchildren_iterable&&)\
    \ = default;\n\n      vchildren_iterable(::tools::hld const * const parent, const\
    \ ::std::size_t v) :\n        m_parent(parent),\n        m_v(v) {\n      }\n\n\
    \      iterator begin() const {\n        return iterator(this->m_parent, this->m_v,\
    \ 0);\n      };\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_v, this->m_parent->m_graph[this->m_v].size());\n      }\n    };\n\n\
    \    hld() = default;\n    hld(const ::tools::hld&) = default;\n    hld(::tools::hld&&)\
    \ = default;\n    ~hld() = default;\n    ::tools::hld& operator=(const ::tools::hld&)\
    \ = default;\n    ::tools::hld& operator=(::tools::hld&&) = default;\n\n    explicit\
    \ hld(const ::std::size_t n) : m_built(false), m_graph(n) {\n      assert(n >=\
    \ 1);\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t u, const ::std::size_t v) {\n\
    \      assert(!this->m_built);\n      assert(u < this->size());\n      assert(v\
    \ < this->size());\n      this->m_graph[u].push_back(this->m_edges.size());\n\
    \      this->m_graph[v].push_back(this->m_edges.size());\n      this->m_edges.push_back(u\
    \ ^ v);\n    }\n\n    void build(const ::std::size_t root) {\n      assert(!this->m_built);\n\
    \      assert(root < this->size());\n      assert(this->m_edges.size() + 1 ==\
    \ this->size());\n\n      this->m_parent.resize(this->size());\n      this->m_depth.resize(this->size());\n\
    \      this->m_dsu = ::atcoder::dsu(this->size());\n      this->m_out.resize(this->size());\n\
    \      this->m_vid2dfs.resize(this->size());\n      this->m_dfs2vid.resize(this->size());\n\
    \      this->m_eid2dfs.resize(this->m_edges.size());\n      this->m_dfs2eid.resize(this->m_edges.size());\n\
    \n      ::std::vector<::std::size_t> subtree_size(this->size());\n      this->m_parent[root]\
    \ = ::std::numeric_limits<::std::size_t>::max();\n      this->m_depth[root] =\
    \ 0;\n      ::std::stack<::std::pair<::std::size_t, bool>> stack;\n      stack.emplace(root,\
    \ false);\n      stack.emplace(root, true);\n      while (!stack.empty()) {\n\
    \        const auto [here, pre] = stack.top();\n        stack.pop();\n       \
    \ if (pre) {\n          for (const auto eid : this->m_graph[here]) {\n       \
    \     const auto next = this->m_edges[eid] ^ here;\n            if (here == root\
    \ || next != (this->m_edges[this->m_parent[here]] ^ here)) {\n              this->m_parent[next]\
    \ = eid;\n              this->m_depth[next] = this->m_depth[here] + 1;\n     \
    \         stack.emplace(next, false);\n              stack.emplace(next, true);\n\
    \            }\n          }\n        } else {\n          subtree_size[here] =\
    \ 1;\n          for (const auto eid : this->m_graph[here]) {\n            const\
    \ auto child = this->m_edges[eid] ^ here;\n            if (here == root || child\
    \ != (this->m_edges[this->m_parent[here]] ^ here)) {\n              subtree_size[here]\
    \ += subtree_size[child];\n            }\n          }\n        }\n      }\n\n\
    \      for (::std::size_t v = 0; v < this->size(); ++v) {\n        if (v != root)\
    \ {\n          this->m_graph[v].erase(::std::find(this->m_graph[v].begin(), this->m_graph[v].end(),\
    \ this->m_parent[v]));\n        }\n        if (this->m_graph[v].size() > 1) {\n\
    \          ::std::iter_swap(\n            this->m_graph[v].begin(),\n        \
    \    ::std::max_element(\n              this->m_graph[v].begin(),\n          \
    \    this->m_graph[v].end(),\n              ::tools::less_by([&](const ::std::size_t\
    \ eid) { return subtree_size[this->m_edges[eid] ^ v]; })\n            )\n    \
    \      );\n        }\n      }\n\n      ::std::size_t dfs_order = 0;\n      stack.emplace(root,\
    \ false);\n      stack.emplace(root, true);\n      while (!stack.empty()) {\n\
    \        const auto [here, pre] = stack.top();\n        stack.pop();\n\n     \
    \   if (pre) {\n          this->m_vid2dfs[here] = dfs_order;\n          this->m_dfs2vid[dfs_order]\
    \ = here;\n          if (here != root) {\n            this->m_eid2dfs[this->m_parent[here]]\
    \ = dfs_order - 1;\n            this->m_dfs2eid[dfs_order - 1] = this->m_parent[here];\n\
    \          }\n          ++dfs_order;\n\n          if (!this->m_graph[here].empty())\
    \ {\n            this->m_dsu.merge(here, this->m_edges[this->m_graph[here].front()]\
    \ ^ here);\n          }\n          for (auto it = this->m_graph[here].rbegin();\
    \ it != this->m_graph[here].rend(); ++it) {\n            stack.emplace(this->m_edges[*it]\
    \ ^ here, false);\n            stack.emplace(this->m_edges[*it] ^ here, true);\n\
    \          }\n        } else {\n          this->m_out[here] = dfs_order;\n   \
    \     }\n      }\n\n      this->m_built = true;\n    }\n\n    ::std::size_t depth(const\
    \ ::std::size_t v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      return this->m_depth[v];\n    }\n    ::std::size_t vparent(const ::std::size_t\
    \ v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      assert(this->m_depth[v] > 0);\n      return this->m_edges[this->m_parent[v]]\
    \ ^ v;\n    }\n    ::std::size_t eparent(const ::std::size_t v) const {\n    \
    \  assert(this->m_built);\n      assert(v < this->size());\n      assert(this->m_depth[v]\
    \ > 0);\n      return this->m_parent[v];\n    }\n    ::std::size_t vancestor(const\
    \ ::std::size_t v, const ::std::size_t k) {\n      assert(this->m_built);\n  \
    \    assert(v < this->size());\n      assert(k <= this->m_depth[v]);\n\n     \
    \ if (this->m_ancestors.empty()) {\n        this->m_ancestors.resize(this->size());\n\
    \        ::std::vector<::std::size_t> targets(this->size());\n        ::std::iota(targets.begin(),\
    \ targets.end(), 0);\n        targets.erase(::std::remove(targets.begin(), targets.end(),\
    \ this->m_dfs2vid[0]), targets.end());\n        for (const auto t : targets) {\n\
    \          this->m_ancestors[t].push_back(this->vparent(t));\n        }\n    \
    \    for (::std::size_t g = 1; [&]() {\n          targets.erase(::std::remove_if(targets.begin(),\
    \ targets.end(), [&](const ::std::size_t t) {\n            return this->m_depth[t]\
    \ < ::tools::pow2(g);\n          }), targets.end());\n          return !targets.empty();\n\
    \        }(); ++g) {\n          for (const auto t : targets) {\n            this->m_ancestors[t].push_back(this->m_ancestors[this->m_ancestors[t][g\
    \ - 1]][g - 1]);\n          }\n        }\n      }\n\n      ::std::size_t res =\
    \ v;\n      for (::std::size_t g = 0; ::tools::pow2(g) <= k; ++g) {\n        if\
    \ ((k >> g) & 1) {\n          res = this->m_ancestors[res][g];\n        }\n  \
    \    }\n\n      return res;\n    }\n    ::tools::hld::vchildren_iterable vchildren(const\
    \ ::std::size_t v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      return ::tools::hld::vchildren_iterable(this, v);\n    }\n    const ::std::vector<::std::size_t>&\
    \ echildren(const ::std::size_t v) const {\n      assert(this->m_built);\n   \
    \   assert(v < this->size());\n      return this->m_graph[v];\n    }\n\n    ::std::size_t\
    \ vid2dfs(const ::std::size_t v) const {\n      assert(this->m_built);\n     \
    \ assert(v < this->size());\n      return this->m_vid2dfs[v];\n    }\n    ::std::size_t\
    \ dfs2vid(const ::std::size_t i) const {\n      assert(this->m_built);\n     \
    \ assert(i < this->size());\n      return this->m_dfs2vid[i];\n    }\n    ::std::size_t\
    \ eid2dfs(const ::std::size_t e) const {\n      assert(this->m_built);\n     \
    \ assert(e < this->size());\n      return this->m_eid2dfs[e];\n    }\n    ::std::size_t\
    \ dfs2eid(const ::std::size_t i) const {\n      assert(this->m_built);\n     \
    \ assert(i < this->size());\n      return this->m_dfs2eid[i];\n    }\n\n    ::std::size_t\
    \ lca(::std::size_t u, ::std::size_t v) {\n      assert(this->m_built);\n    \
    \  assert(u < this->size());\n      assert(v < this->size());\n\n      while (!this->m_dsu.same(u,\
    \ v)) {\n        if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)])\
    \ {\n          u = this->m_edges[this->m_parent[this->m_dsu.leader(u)]] ^ this->m_dsu.leader(u);\n\
    \        } else {\n          v = this->m_edges[this->m_parent[this->m_dsu.leader(v)]]\
    \ ^ this->m_dsu.leader(v);\n        }\n      }\n      if (this->m_depth[u] >=\
    \ this->m_depth[v]) {\n        return v;\n      } else {\n        return u;\n\
    \      }\n    }\n\n    ::std::pair<::std::size_t, ::std::size_t> vsubtree(const\
    \ ::std::size_t v) const {\n      assert(this->m_built);\n      assert(v < this->size());\n\
    \      return ::std::make_pair(this->m_vid2dfs[v], this->m_out[v]);\n    }\n \
    \   ::std::pair<::std::size_t, ::std::size_t> esubtree(const ::std::size_t v)\
    \ const {\n      assert(this->m_built);\n      assert(v < this->size());\n   \
    \   return ::std::make_pair(this->m_depth[v] == 0 ? 0 : this->m_eid2dfs[this->m_parent[v]]\
    \ + 1, this->m_out[v] - 1);\n    }\n\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> vpath(::std::size_t u, ::std::size_t v) {\n      assert(this->m_built);\n\
    \      assert(u < this->size());\n      assert(v < this->size());\n\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> head, tail;\n      while (!this->m_dsu.same(u, v)) {\n     \
    \   if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)])\
    \ {\n          head.emplace_back(this->m_vid2dfs[u] + 1, this->m_vid2dfs[this->m_dsu.leader(u)]);\n\
    \          u = this->m_edges[this->m_parent[this->m_dsu.leader(u)]] ^ this->m_dsu.leader(u);\n\
    \        } else {\n          tail.emplace_back(this->m_vid2dfs[this->m_dsu.leader(v)],\
    \ this->m_vid2dfs[v] + 1);\n          v = this->m_edges[this->m_parent[this->m_dsu.leader(v)]]\
    \ ^ this->m_dsu.leader(v);\n        }\n      }\n      if (this->m_depth[u] >=\
    \ this->m_depth[v]) {\n        head.emplace_back(this->m_vid2dfs[u] + 1, this->m_vid2dfs[v]);\n\
    \      } else {\n        head.emplace_back(this->m_vid2dfs[u], this->m_vid2dfs[v]\
    \ + 1);\n      }\n\n      ::std::copy(tail.rbegin(), tail.rend(), ::std::back_inserter(head));\n\
    \      return head;\n    }\n    ::std::vector<::std::pair<::std::size_t, ::std::size_t>>\
    \ epath(::std::size_t u, ::std::size_t v) {\n      assert(this->m_built);\n  \
    \    assert(u < this->size());\n      assert(v < this->size());\n\n      ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> head, tail;\n      while (!this->m_dsu.same(u, v)) {\n     \
    \   if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)])\
    \ {\n          head.emplace_back(this->m_eid2dfs[this->m_parent[u]] + 1, this->m_eid2dfs[this->m_parent[this->m_dsu.leader(u)]]);\n\
    \          u = this->m_edges[this->m_parent[this->m_dsu.leader(u)]] ^ this->m_dsu.leader(u);\n\
    \        } else {\n          tail.emplace_back(this->m_eid2dfs[this->m_parent[this->m_dsu.leader(v)]],\
    \ this->m_eid2dfs[this->m_parent[v]] + 1);\n          v = this->m_edges[this->m_parent[this->m_dsu.leader(v)]]\
    \ ^ this->m_dsu.leader(v);\n        }\n      }\n      if (this->m_depth[u] > this->m_depth[v])\
    \ {\n        head.emplace_back(this->m_eid2dfs[this->m_parent[u]] + 1, this->m_eid2dfs[this->m_graph[v].front()]);\n\
    \      } else if (this->m_depth[u] < this->m_depth[v]) {\n        head.emplace_back(this->m_eid2dfs[this->m_graph[u].front()],\
    \ this->m_eid2dfs[this->m_parent[v]] + 1);\n      }\n\n      ::std::copy(tail.rbegin(),\
    \ tail.rend(), ::std::back_inserter(head));\n      return head;\n    }\n  };\n\
    }\n\n\n#line 9 \"tests/hld/epath.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n;\n  std::cin >> n;\n  std::vector<i64> parent(n, -1);\n  for (i64 i\
    \ = 0; i < n; ++i) {\n    i64 k;\n    std::cin >> k;\n    for (i64 j = 0; j <\
    \ k; ++j) {\n      i64 c;\n      std::cin >> c;\n      parent[c] = i;\n    }\n\
    \  }\n\n  tools::hld hld(n);\n  for (i64 i = 1; i < n; ++i) {\n    hld.add_edge(parent[i],\
    \ i);\n  }\n  hld.build(0);\n  atcoder::fenwick_tree<i64> fw(n - 1);\n  i64 q;\n\
    \  std::cin >> q;\n  for (i64 i = 0; i < q; ++i) {\n    i64 t;\n    std::cin >>\
    \ t;\n    if (t == 0) {\n      i64 v, w;\n      std::cin >> v >> w;\n      fw.add(hld.eid2dfs(v\
    \ - 1), w);\n    } else {\n      i64 u;\n      std::cin >> u;\n      i64 sum =\
    \ 0;\n      for (const auto& [from, to] : hld.epath(0, u)) {\n        const auto\
    \ [l, r] = std::minmax(from, to);\n        sum += fw.sum(l, r);\n      }\n   \
    \   std::cout << sum << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include \"atcoder/fenwicktree.hpp\"\n#include \"tools/hld.hpp\"\n\nusing i64\
    \ = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n;\n  std::cin >> n;\n  std::vector<i64> parent(n, -1);\n  for (i64 i\
    \ = 0; i < n; ++i) {\n    i64 k;\n    std::cin >> k;\n    for (i64 j = 0; j <\
    \ k; ++j) {\n      i64 c;\n      std::cin >> c;\n      parent[c] = i;\n    }\n\
    \  }\n\n  tools::hld hld(n);\n  for (i64 i = 1; i < n; ++i) {\n    hld.add_edge(parent[i],\
    \ i);\n  }\n  hld.build(0);\n  atcoder::fenwick_tree<i64> fw(n - 1);\n  i64 q;\n\
    \  std::cin >> q;\n  for (i64 i = 0; i < q; ++i) {\n    i64 t;\n    std::cin >>\
    \ t;\n    if (t == 0) {\n      i64 v, w;\n      std::cin >> v >> w;\n      fw.add(hld.eid2dfs(v\
    \ - 1), w);\n    } else {\n      i64 u;\n      std::cin >> u;\n      i64 sum =\
    \ 0;\n      for (const auto& [from, to] : hld.epath(0, u)) {\n        const auto\
    \ [l, r] = std::minmax(from, to);\n        sum += fw.sum(l, r);\n      }\n   \
    \   std::cout << sum << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/hld.hpp
  - tools/less_by.hpp
  - tools/pow2.hpp
  isVerificationFile: true
  path: tests/hld/epath.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 14:57:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/hld/epath.test.cpp
layout: document
redirect_from:
- /verify/tests/hld/epath.test.cpp
- /verify/tests/hld/epath.test.cpp.html
title: tests/hld/epath.test.cpp
---