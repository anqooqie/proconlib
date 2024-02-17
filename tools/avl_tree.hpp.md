---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/detail/avl_tree_impl.hpp
    title: tools/detail/avl_tree_impl.hpp
  - icon: ':heavy_check_mark:'
    path: tools/fix.hpp
    title: Fixed point combinator
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/binary_search.test.cpp
    title: tests/avl_tree/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/reverse.test.cpp
    title: tests/avl_tree/reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/avl_tree/set.test.cpp
    title: tests/avl_tree/set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/avl_tree.hpp\"\n\n\n\n#line 1 \"tools/detail/avl_tree_impl.hpp\"\
    \n\n\n\n#include <variant>\n#include <type_traits>\n#include <functional>\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <cmath>\n#line 1 \"tools/fix.hpp\"\n\n\n\n#line 6 \"tools/fix.hpp\"\n\nnamespace\
    \ tools {\n  template <typename F>\n  struct fix : F {\n    template <typename\
    \ G>\n    fix(G&& g) : F({::std::forward<G>(g)}) {\n    }\n\n    template <typename...\
    \ Args>\n    decltype(auto) operator()(Args&&... args) const {\n      return F::operator()(*this,\
    \ ::std::forward<Args>(args)...);\n    }\n  };\n\n  template <typename F>\n  fix(F&&)\
    \ -> fix<::std::decay_t<F>>;\n}\n\n\n#line 13 \"tools/detail/avl_tree_impl.hpp\"\
    \n\nnamespace tools {\n  namespace detail {\n    namespace avl_tree {\n      struct\
    \ nop_monoid {\n        using T = ::std::monostate;\n        static constexpr\
    \ T op(T, T) {\n          return T{};\n        }\n        static constexpr T e()\
    \ {\n          return T{};\n        }\n      };\n      template <typename SM>\n\
    \      typename SM::T nop(typename nop_monoid::T, const typename SM::T& x) {\n\
    \        return x;\n      }\n\n      template <bool Reversible, typename SM, typename\
    \ FM = nop_monoid, auto mapping = nop<SM>>\n      class avl_tree_impl {\n    \
    \  private:\n        using S = typename SM::T;\n        using F = typename FM::T;\n\
    \        static_assert(\n          ::std::is_convertible_v<decltype(mapping),\
    \ ::std::function<S(F, S)>>,\n          \"mapping must work as S(F, S)\");\n \
    \       constexpr static bool is_lazy = !::std::is_same_v<FM, nop_monoid>;\n\n\
    \        struct node {\n          int id;\n          int l_id;\n          int\
    \ r_id;\n          int height;\n          int size;\n          S prod;\n     \
    \     ::std::conditional_t<Reversible, S, ::std::monostate> rprod;\n         \
    \ bool rev;\n          F lazy;\n        };\n\n      public:\n        class buffer\
    \ {\n        private:\n          ::std::vector<node> m_nodes;\n\n        public:\n\
    \          buffer() {\n            if constexpr (Reversible) {\n             \
    \ this->m_nodes.push_back(node{0, 0, 0, 0, 0, SM::e(), SM::e(), false, FM::e()});\n\
    \            } else {\n              this->m_nodes.push_back(node{0, 0, 0, 0,\
    \ 0, SM::e(), ::std::monostate{}, false, FM::e()});\n            }\n         \
    \ }\n          buffer(const buffer&) = default;\n          buffer(buffer&&) =\
    \ default;\n          ~buffer() = default;\n          buffer& operator=(const\
    \ buffer&) = default;\n          buffer& operator=(buffer&&) = default;\n\n  \
    \        friend ::tools::detail::avl_tree::avl_tree_impl<Reversible, SM, FM, mapping>;\n\
    \        };\n\n      private:\n        buffer *m_buffer;\n        int m_root_id;\n\
    \n        void fetch(const int id) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \          const auto& l_node = this->m_buffer->m_nodes[node.l_id];\n        \
    \  const auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\n          node.height\
    \ = 1 + ::std::max(l_node.height, r_node.height);\n          node.size = l_node.size\
    \ + r_node.size;\n          node.prod = SM::op(l_node.prod, r_node.prod);\n  \
    \        if constexpr (Reversible) {\n            node.rprod = SM::op(r_node.rprod,\
    \ l_node.rprod);\n          }\n        }\n        void propagate(const int id)\
    \ {\n          auto& node = this->m_buffer->m_nodes[id];\n          auto& l_node\
    \ = this->m_buffer->m_nodes[node.l_id];\n          auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\
    \n          assert(!(node.size == 0) || (node.id == 0 && node.l_id == 0 && node.r_id\
    \ == 0));\n          assert(!(node.size == 1) || (node.id > 0 && node.l_id ==\
    \ 0 && node.r_id == 0));\n          assert(!(node.size > 1) || (node.id > 0 &&\
    \ node.l_id > 0 && node.r_id > 0));\n\n          if constexpr (Reversible) {\n\
    \            if (node.rev) {\n              if (node.size > 1) {\n           \
    \     l_node.rev = !l_node.rev;\n                r_node.rev = !r_node.rev;\n \
    \               ::std::swap(node.l_id, node.r_id);\n                ::std::swap(node.prod,\
    \ node.rprod);\n              }\n              node.rev = false;\n           \
    \ }\n          }\n          if constexpr (is_lazy) {\n            if (node.lazy\
    \ != FM::e()) {\n              if (node.size > 1) {\n                l_node.lazy\
    \ = FM::op(node.lazy, l_node.lazy);\n                r_node.lazy = FM::op(node.lazy,\
    \ r_node.lazy);\n              }\n              node.prod = mapping(node.lazy,\
    \ node.prod);\n              if constexpr (Reversible) {\n                 node.rprod\
    \ = mapping(node.lazy, node.rprod);\n              }\n              node.lazy\
    \ = FM::e();\n            }\n          }\n        }\n\n        int add_node(const\
    \ S& x) {\n          const int id = this->m_buffer->m_nodes.size();\n        \
    \  if constexpr (Reversible) {\n            this->m_buffer->m_nodes.push_back(node{id,\
    \ 0, 0, 1, 1, x, x, false, FM::e()});\n          } else {\n            this->m_buffer->m_nodes.push_back(node{id,\
    \ 0, 0, 1, 1, x, ::std::monostate{}, false, FM::e()});\n          }\n        \
    \  return id;\n        }\n        int add_node(const int l_id, const int r_id)\
    \ {\n          const int id = this->m_buffer->m_nodes.size();\n          if constexpr\
    \ (Reversible) {\n            this->m_buffer->m_nodes.push_back(node{id, l_id,\
    \ r_id, 0, 0, SM::e(), SM::e(), false, FM::e()});\n          } else {\n      \
    \      this->m_buffer->m_nodes.push_back(node{id, l_id, r_id, 0, 0, SM::e(), ::std::monostate{},\
    \ false, FM::e()});\n          }\n          this->fetch(id);\n          return\
    \ id;\n        }\n\n        int rotate_l(const int id) {\n          auto& node\
    \ = this->m_buffer->m_nodes[id];\n          auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\
    \n          assert(node.size > 1);\n          assert(node.id > 0);\n         \
    \ assert(node.l_id > 0);\n          assert(node.r_id > 0);\n          assert(r_node.size\
    \ > 1);\n          assert(r_node.id > 0);\n          assert(r_node.l_id > 0);\n\
    \          assert(r_node.r_id > 0);\n\n          if constexpr (Reversible || is_lazy)\
    \ {\n            this->propagate(id);\n            this->propagate(node.l_id);\n\
    \            this->propagate(node.r_id);\n            this->propagate(r_node.l_id);\n\
    \            this->propagate(r_node.r_id);\n          }\n\n          node.r_id\
    \ = r_node.l_id;\n          r_node.l_id = node.id;\n\n          this->fetch(id);\n\
    \          this->fetch(r_node.id);\n\n          return r_node.id;\n        }\n\
    \        int rotate_r(const int id) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \          auto& l_node = this->m_buffer->m_nodes[node.l_id];\n\n          assert(node.size\
    \ > 1);\n          assert(node.id > 0);\n          assert(node.l_id > 0);\n  \
    \        assert(node.r_id > 0);\n          assert(l_node.size > 1);\n        \
    \  assert(l_node.id > 0);\n          assert(l_node.l_id > 0);\n          assert(l_node.r_id\
    \ > 0);\n\n          if constexpr (Reversible || is_lazy) {\n            this->propagate(id);\n\
    \            this->propagate(node.l_id);\n            this->propagate(node.r_id);\n\
    \            this->propagate(l_node.l_id);\n            this->propagate(l_node.r_id);\n\
    \          }\n\n          node.l_id = l_node.r_id;\n          l_node.r_id = node.id;\n\
    \n          this->fetch(id);\n          this->fetch(l_node.id);\n\n          return\
    \ l_node.id;\n        }\n        int height_diff(const int id) {\n          const\
    \ auto& node = this->m_buffer->m_nodes[id];\n          const auto& l_node = this->m_buffer->m_nodes[node.l_id];\n\
    \          const auto& r_node = this->m_buffer->m_nodes[node.r_id];\n\n      \
    \    return l_node.height - r_node.height;\n        }\n        int balance(const\
    \ int id) {\n          auto& node = this->m_buffer->m_nodes[id];\n\n         \
    \ const auto diff = this->height_diff(id);\n          assert(::std::abs(diff)\
    \ <= 2);\n\n          if (diff == 2) {\n            if (this->height_diff(node.l_id)\
    \ < 0) node.l_id = this->rotate_l(node.l_id);\n            return this->rotate_r(id);\n\
    \          } else if (diff == -2) {\n            if (this->height_diff(node.r_id)\
    \ > 0) node.r_id = this->rotate_r(node.r_id);\n            return this->rotate_l(id);\n\
    \          } else {\n            return id;\n          }\n        }\n\n      \
    \  void set(const int id, const int p, const S& x) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= p && p < node.size);\n\n          if constexpr (Reversible\
    \ || is_lazy) {\n            this->propagate(id);\n          }\n          if (node.size\
    \ == 1) {\n            node.prod = x;\n          } else {\n            const auto\
    \ half = this->m_buffer->m_nodes[node.l_id].size;\n\n            if (p < half)\
    \ {\n              this->set(node.l_id, p, x);\n              if constexpr (Reversible\
    \ || is_lazy) {\n                this->propagate(node.r_id);\n              }\n\
    \            } else {\n              if constexpr (Reversible || is_lazy) {\n\
    \                this->propagate(node.l_id);\n              }\n              this->set(node.r_id,\
    \ p - half, x);\n            }\n            this->fetch(id);\n          }\n  \
    \      }\n        S prod(const int id, const int l, const int r) {\n         \
    \ auto& node = this->m_buffer->m_nodes[id];\n\n          assert(0 <= l && l <=\
    \ r && r <= node.size);\n\n          if (l == r) return SM::e();\n\n         \
    \ if constexpr (Reversible || is_lazy) {\n            this->propagate(id);\n \
    \         }\n          if (l == 0 && r == node.size) {\n            return node.prod;\n\
    \          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \n            auto res = SM::e();\n            if (l < half) res = SM::op(res,\
    \ this->prod(node.l_id, l, ::std::min(r, half)));\n            if (half < r) res\
    \ = SM::op(res, this->prod(node.r_id, ::std::max(0, l - half), r - half));\n \
    \           return res;\n          }\n        }\n        template <bool SFINAE\
    \ = is_lazy>\n        ::std::enable_if_t<SFINAE, void> apply(const int id, const\
    \ int l, const int r, const F& f) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= l && l <= r && r <= node.size);\n\n          if (l ==\
    \ r) return;\n\n          if (l == 0 && r == node.size) {\n            node.lazy\
    \ = FM::op(f, node.lazy);\n            this->propagate(id);\n          } else\
    \ {\n            this->propagate(id);\n\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \            if (l < half) {\n              this->apply(node.l_id, l, ::std::min(r,\
    \ half), f);\n            } else {\n              this->propagate(node.l_id);\n\
    \            }\n            if (half < r) {\n              this->apply(node.r_id,\
    \ ::std::max(0, l - half), r - half, f);\n            } else {\n             \
    \ this->propagate(node.r_id);\n            }\n            this->fetch(id);\n \
    \         }\n        }\n        int insert(const int id, const int p, const S&\
    \ x) {\n          auto& node = this->m_buffer->m_nodes[id];\n\n          assert(0\
    \ <= p && p <= node.size);\n\n          if constexpr (Reversible || is_lazy) {\n\
    \            this->propagate(id);\n          }\n          if (node.size == 0)\
    \ {\n            return this->add_node(x);\n          } else if (node.size ==\
    \ 1) {\n            if (p == 0) {\n              return this->add_node(this->add_node(x),\
    \ id);\n            } else {\n              return this->add_node(id, this->add_node(x));\n\
    \            }\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \n            if (p < half) {\n              if constexpr (Reversible || is_lazy)\
    \ {\n                this->propagate(node.r_id);\n              }\n          \
    \    const auto l_id = this->insert(node.l_id, p, x);\n              this->m_buffer->m_nodes[id].l_id\
    \ = l_id;\n            } else {\n              if constexpr (Reversible || is_lazy)\
    \ {\n                this->propagate(node.l_id);\n              }\n          \
    \    const auto r_id = this->insert(node.r_id, p - half, x);\n              this->m_buffer->m_nodes[id].r_id\
    \ = r_id;\n            }\n            this->fetch(id);\n            return this->balance(id);\n\
    \          }\n        }\n        int erase(const int id, const int p) {\n    \
    \      auto& node = this->m_buffer->m_nodes[id];\n\n          assert(0 <= p &&\
    \ p < node.size);\n\n          if constexpr (Reversible || is_lazy) {\n      \
    \      this->propagate(id);\n          }\n          if (node.size == 1) {\n  \
    \          return 0;\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \n            if (p < half) {\n              if constexpr (Reversible || is_lazy)\
    \ {\n                this->propagate(node.r_id);\n              }\n          \
    \    node.l_id = this->erase(node.l_id, p);\n              if (node.l_id == 0)\
    \ return node.r_id;\n            } else {\n              if constexpr (Reversible\
    \ || is_lazy) {\n                this->propagate(node.l_id);\n              }\n\
    \              node.r_id = this->erase(node.r_id, p - half);\n              if\
    \ (node.r_id == 0) return node.l_id;\n            }\n            this->fetch(id);\n\
    \            return this->balance(id);\n          }\n        }\n\n        int\
    \ merge(const int l_id, const int r_id, const int free_id) {\n          if (l_id\
    \ == 0) {\n            if constexpr (Reversible || is_lazy) {\n              this->propagate(r_id);\n\
    \            }\n            return r_id;\n          }\n          if (r_id == 0)\
    \ {\n            if constexpr (Reversible || is_lazy) {\n              this->propagate(l_id);\n\
    \            }\n            return l_id;\n          }\n\n          auto& l_node\
    \ = this->m_buffer->m_nodes[l_id];\n          auto& r_node = this->m_buffer->m_nodes[r_id];\n\
    \          const auto diff = l_node.height - r_node.height;\n          if (diff\
    \ >= 2) {\n            if constexpr (Reversible || is_lazy) {\n              this->propagate(l_id);\n\
    \              this->propagate(l_node.l_id);\n            }\n            const\
    \ auto merged_id = this->merge(l_node.r_id, r_id, free_id);\n            this->m_buffer->m_nodes[l_id].r_id\
    \ = merged_id;\n            this->fetch(l_id);\n            return this->balance(l_id);\n\
    \          } else if (diff <= -2) {\n            if constexpr (Reversible || is_lazy)\
    \ {\n              this->propagate(r_id);\n              this->propagate(r_node.r_id);\n\
    \            }\n            const auto merged_id = this->merge(l_id, r_node.l_id,\
    \ free_id);\n            this->m_buffer->m_nodes[r_id].l_id = merged_id;\n   \
    \         this->fetch(r_id);\n            return this->balance(r_id);\n      \
    \    } else {\n            if constexpr (Reversible || is_lazy) {\n          \
    \    this->propagate(l_id);\n              this->propagate(r_id);\n          \
    \  }\n            if (free_id == 0) {\n              return this->add_node(l_id,\
    \ r_id);\n            } else {\n              auto& node = this->m_buffer->m_nodes[free_id];\n\
    \              node.l_id = l_id;\n              node.r_id = r_id;\n          \
    \    if constexpr (Reversible) {\n                node.rev = false;\n        \
    \      }\n              if constexpr (is_lazy) {\n                node.lazy =\
    \ FM::e();\n              }\n              this->fetch(free_id);\n           \
    \   return free_id;\n            }\n          }\n        }\n        ::std::pair<int,\
    \ int> split(const int id, const int i) {\n          auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= i && i <= node.size);\n\n          if (i == 0) return\
    \ ::std::make_pair(0, id);\n          if (i == node.size) return ::std::make_pair(id,\
    \ 0);\n\n          if constexpr (Reversible || is_lazy) {\n            this->propagate(id);\n\
    \          }\n          const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \          if (i < half) {\n            const auto [l_id, r_id] = this->split(node.l_id,\
    \ i);\n            return ::std::make_pair(l_id, this->merge(r_id, this->m_buffer->m_nodes[id].r_id,\
    \ this->m_buffer->m_nodes[id].l_id));\n          } else if (i > half) {\n    \
    \        const auto [l_id, r_id] = this->split(node.r_id, i - half);\n       \
    \     return ::std::make_pair(this->merge(this->m_buffer->m_nodes[id].l_id, l_id,\
    \ this->m_buffer->m_nodes[id].r_id), r_id);\n          } else {\n            return\
    \ ::std::make_pair(node.l_id, node.r_id);\n          }\n        }\n\n        template\
    \ <typename G>\n        ::std::pair<int, S> max_right(const int id, const int\
    \ l, const G& g, S carry) {\n          const auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= l && l <= node.size);\n\n          if constexpr (Reversible\
    \ || is_lazy) {\n            this->propagate(id);\n          }\n          if (node.size\
    \ == 0) {\n            return ::std::make_pair(0, carry);\n          } else if\
    \ (node.size == 1) {\n            if (l == 0) {\n              const auto whole\
    \ = SM::op(carry, node.prod);\n              if (g(whole)) return ::std::make_pair(1,\
    \ whole);\n              return ::std::make_pair(0, carry);\n            } else\
    \ {\n              assert(carry == SM::e());\n              return ::std::make_pair(1,\
    \ carry);\n            }\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \            int r;\n            if (l == 0) {\n              const auto whole\
    \ = SM::op(carry, node.prod);\n              if (g(whole)) return ::std::make_pair(node.size,\
    \ whole);\n\n              ::std::tie(r, carry) = this->max_right(node.l_id, 0,\
    \ g, carry);\n              if (r < half) return ::std::make_pair(r, carry);\n\
    \n              ::std::tie(r, carry) = this->max_right(node.r_id, 0, g, carry);\n\
    \              r += half;\n              return ::std::make_pair(r, carry);\n\
    \            } else {\n              assert(carry == SM::e());\n             \
    \ if (l < half) {\n                ::std::tie(r, carry) = this->max_right(node.l_id,\
    \ l, g, carry);\n                if (r < half) return ::std::make_pair(r, carry);\n\
    \              }\n              ::std::tie(r, carry) = this->max_right(node.r_id,\
    \ ::std::max(0, l - half), g, carry);\n              r += half;\n            \
    \  return ::std::make_pair(r, carry);\n            }\n          }\n        }\n\
    \        template <typename G>\n        ::std::pair<int, S> min_left(const int\
    \ id, const int r, const G& g, S carry) {\n          const auto& node = this->m_buffer->m_nodes[id];\n\
    \n          assert(0 <= r && r <= node.size);\n\n          if constexpr (Reversible\
    \ || is_lazy) {\n            this->propagate(id);\n          }\n          if (node.size\
    \ == 0) {\n            return ::std::make_pair(0, carry);\n          } else if\
    \ (node.size == 1) {\n            if (r == node.size) {\n              const auto\
    \ whole = SM::op(node.prod, carry);\n              if (g(whole)) return ::std::make_pair(0,\
    \ whole);\n              return ::std::make_pair(1, carry);\n            } else\
    \ {\n              assert(carry == SM::e());\n              return ::std::make_pair(0,\
    \ carry);\n            }\n          } else {\n            const auto half = this->m_buffer->m_nodes[node.l_id].size;\n\
    \            int l;\n            if (r == node.size) {\n              const auto\
    \ whole = SM::op(node.prod, carry);\n              if (g(whole)) return ::std::make_pair(0,\
    \ whole);\n\n              ::std::tie(l, carry) = this->min_left(node.r_id, node.size\
    \ - half, g, carry);\n              l += half;\n              if (half < l) return\
    \ ::std::make_pair(l, carry);\n\n              ::std::tie(l, carry) = this->min_left(node.l_id,\
    \ half, g, carry);\n              return ::std::make_pair(l, carry);\n       \
    \     } else {\n              assert(carry == SM::e());\n              if (half\
    \ < r) {\n                ::std::tie(l, carry) = this->min_left(node.r_id, r -\
    \ half, g, carry);\n                l += half;\n                if (half < l)\
    \ return ::std::make_pair(l, carry);\n              }\n              ::std::tie(l,\
    \ carry) = this->min_left(node.l_id, ::std::min(half, r), g, carry);\n       \
    \       return ::std::make_pair(l, carry);\n            }\n          }\n     \
    \   }\n\n      public:\n        explicit operator ::std::vector<S>() const {\n\
    \          ::std::vector<S> v;\n          if (!this->empty()) {\n            ::tools::fix([&](auto&&\
    \ dfs, const int id) -> void {\n              auto& node = this->m_buffer->m_nodes[id];\n\
    \              if constexpr (Reversible || is_lazy) {\n                this->propagate(id);\n\
    \              }\n              if (node.size == 1) {\n                v.push_back(node.prod);\n\
    \              } else {\n                dfs(node.l_id);\n                dfs(node.r_id);\n\
    \              }\n            })(this->m_root_id);\n          }\n          return\
    \ v;\n        }\n\n        avl_tree_impl() = default;\n        avl_tree_impl(buffer&\
    \ buffer) : m_buffer(&buffer), m_root_id(0) {\n        }\n        avl_tree_impl(buffer&\
    \ buffer, const ::std::vector<S>& v) : m_buffer(&buffer) {\n          this->m_root_id\
    \ = v.empty() ? 0 : ::tools::fix([&](auto&& dfs, const int l, const int r) ->\
    \ int {\n            if (r - l == 1) {\n              return this->add_node(v[l]);\n\
    \            } else {\n              return this->add_node(dfs(l, (l + r) / 2),\
    \ dfs((l + r) / 2, r));\n            }\n          })(0, v.size());\n        }\n\
    \        avl_tree_impl(buffer& buffer, const int n) : avl_tree_impl(buffer, ::std::vector<S>(n,\
    \ SM::e())) {\n        }\n        avl_tree_impl(const avl_tree_impl<Reversible,\
    \ SM, FM, mapping>& other) : avl_tree_impl(*other.m_buffer, static_cast<::std::vector<S>>(other))\
    \ {\n        }\n        avl_tree_impl(avl_tree_impl<Reversible, SM, FM, mapping>&&\
    \ other) : m_buffer(other.m_buffer), m_root_id(other.m_root_id) {\n        }\n\
    \        ~avl_tree_impl() = default;\n        avl_tree_impl<Reversible, SM, FM,\
    \ mapping>& operator=(const avl_tree_impl<Reversible, SM, FM, mapping>& other)\
    \ {\n          this->m_buffer = other.m_buffer;\n          this->m_root_id = avl_tree_impl<Reversible,\
    \ SM, FM, mapping>(other).m_root_id;\n        }\n        avl_tree_impl<Reversible,\
    \ SM, FM, mapping>& operator=(avl_tree_impl<Reversible, SM, FM, mapping>&& other)\
    \ {\n          this->m_buffer = other.m_buffer;\n          this->m_root_id = other.m_root_id;\n\
    \        }\n\n        int size() const {\n          return this->m_buffer->m_nodes[this->m_root_id].size;\n\
    \        }\n        bool empty() const {\n          return this->m_root_id ==\
    \ 0;\n        }\n\n        void set(const int p, const S& x) {\n          this->set(this->m_root_id,\
    \ p, x);\n        }\n        S get(const int p) {\n          return this->prod(this->m_root_id,\
    \ p, p + 1);\n        }\n        S prod(const int l, const int r) {\n        \
    \  return this->prod(this->m_root_id, l, r);\n        }\n        S all_prod()\
    \ {\n          return this->prod(this->m_root_id, 0, this->size());\n        }\n\
    \        template <bool SFINAE = is_lazy>\n        ::std::enable_if_t<SFINAE,\
    \ void> apply(const int p, const F& f) {\n          this->apply(this->m_root_id,\
    \ p, p + 1, f);\n        }\n        template <bool SFINAE = is_lazy>\n       \
    \ ::std::enable_if_t<SFINAE, void> apply(const int l, const int r, const F& f)\
    \ {\n          this->apply(this->m_root_id, l, r, f);\n        }\n        void\
    \ insert(const int p, const S& x) {\n          this->m_root_id = this->insert(this->m_root_id,\
    \ p, x);\n        }\n        void erase(const int p) {\n          this->m_root_id\
    \ = this->erase(this->m_root_id, p);\n        }\n        void merge(avl_tree_impl<Reversible,\
    \ SM, FM, mapping>& other) {\n          assert(this->m_buffer == other.m_buffer);\n\
    \          this->m_root_id = this->merge(this->m_root_id, other.m_root_id, 0);\n\
    \          other.m_root_id = 0;\n        }\n        ::std::pair<avl_tree_impl<Reversible,\
    \ SM, FM, mapping>, avl_tree_impl<Reversible, SM, FM, mapping>> split(const int\
    \ i) {\n          avl_tree_impl<Reversible, SM, FM, mapping> l(*this->m_buffer),\
    \ r(*this->m_buffer);\n          ::std::tie(l.m_root_id, r.m_root_id) = this->split(this->m_root_id,\
    \ i);\n          return ::std::make_pair(l, r);\n        }\n        template <bool\
    \ SFINAE = Reversible>\n        ::std::enable_if_t<SFINAE, void> reverse(const\
    \ int l, const int r) {\n          assert(0 <= l && l <= r && r <= this->size());\n\
    \n          if (l == r) return;\n\n          if (l == 0) {\n            if (r\
    \ == this->size()) {\n              this->m_buffer->m_nodes[this->m_root_id].rev\
    \ = !this->m_buffer->m_nodes[this->m_root_id].rev;\n            } else {\n   \
    \           const auto [l_id, r_id] = this->split(this->m_root_id, r);\n     \
    \         this->m_buffer->m_nodes[l_id].rev = !this->m_buffer->m_nodes[l_id].rev;\n\
    \              this->m_root_id = this->merge(l_id, r_id, this->m_root_id);\n \
    \           }\n          } else {\n            if (r == this->size()) {\n    \
    \          const auto [l_id, r_id] = this->split(this->m_root_id, l);\n      \
    \        this->m_buffer->m_nodes[r_id].rev = !this->m_buffer->m_nodes[r_id].rev;\n\
    \              this->m_root_id = this->merge(l_id, r_id, this->m_root_id);\n \
    \           } else {\n              const auto [lm_id, r_id] = this->split(this->m_root_id,\
    \ r);\n              const auto [l_id, m_id] = this->split(lm_id, l);\n      \
    \        this->m_buffer->m_nodes[m_id].rev = !this->m_buffer->m_nodes[m_id].rev;\n\
    \              this->m_root_id = this->merge(this->merge(l_id, m_id, lm_id), r_id,\
    \ this->m_root_id);\n            }\n          }\n        }\n        template <typename\
    \ G>\n        int max_right(const int l, const G& g) {\n          return this->max_right(this->m_root_id,\
    \ l, g, SM::e()).first;\n        }\n        template <typename G>\n        int\
    \ min_left(const int r, const G& g) {\n          return this->min_left(this->m_root_id,\
    \ r, g, SM::e()).first;\n        }\n      };\n    }\n  }\n}\n\n\n#line 5 \"tools/avl_tree.hpp\"\
    \n\nnamespace tools {\n  template <typename SM, bool Reversible = false>\n  using\
    \ avl_tree = ::tools::detail::avl_tree::avl_tree_impl<Reversible, SM>;\n}\n\n\n"
  code: "#ifndef TOOLS_AVL_TREE_HPP\n#define TOOLS_AVL_TREE_HPP\n\n#include \"tools/detail/avl_tree_impl.hpp\"\
    \n\nnamespace tools {\n  template <typename SM, bool Reversible = false>\n  using\
    \ avl_tree = ::tools::detail::avl_tree::avl_tree_impl<Reversible, SM>;\n}\n\n\
    #endif\n"
  dependsOn:
  - tools/detail/avl_tree_impl.hpp
  - tools/fix.hpp
  isVerificationFile: false
  path: tools/avl_tree.hpp
  requiredBy: []
  timestamp: '2023-08-26 10:00:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/avl_tree/reverse.test.cpp
  - tests/avl_tree/binary_search.test.cpp
  - tests/avl_tree/set.test.cpp
documentation_of: tools/avl_tree.hpp
layout: document
title: Reversible self-balancing binary search tree based on AVL tree
---

It is the data structure for [monoids](https://en.wikipedia.org/wiki/Monoid) $(S, \cdot: S \times S \to S, e \in S)$, i.e., the algebraic structure that satisfies the following properties.

- associativity: $(a \cdot b) \cdot c$ = $a \cdot (b \cdot c)$ for all $a, b, c \in S$
- existence of the identity element: $a \cdot e$ = $e \cdot a$ = $a$ for all $a \in S$

Given an array $S$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Updating an element
- Calculating the product of the elements of an interval
- Inserting an element $x \in S$ to the array
- Removing an element from the array
- Spliting the array into two subarrays
- Merging the two arrays into one array
- Reversing the elements of an interval

For simplicity, in this document, we assume that the oracles `op` and `e` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### References
- [AVL木(split/merge) - Qiita](https://qiita.com/QCFium/items/3cf26a6dc2d49ef490d7)

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
(1) avl_tree<M>::buffer buffer();
(2) avl_tree<M, Reversible>::buffer buffer();
```

- (1)
    - It is identical to `avl_tree<M, false>::buffer buffer()`.
- (2)
    - It creates an empty buffer for `tools::avl_tree<M, Reversible>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
(1) avl_tree<M> avl_tree(avl_tree<M>::buffer& buffer);
(2) avl_tree<M> avl_tree(avl_tree<M>::buffer& buffer, int n);
(3) avl_tree<M> avl_tree(avl_tree<M>::buffer& buffer, std::vector<S> v);
(4) avl_tree<M, Reversible> avl_tree(avl_tree<M, Reversible>::buffer& buffer);
(5) avl_tree<M, Reversible> avl_tree(avl_tree<M, Reversible>::buffer& buffer, int n);
(6) avl_tree<M, Reversible> avl_tree(avl_tree<M, Reversible>::buffer& buffer, std::vector<S> v);
```

It defines $S$ by `typename M::T`, $\mathrm{op}$ by `S M::op(S x, S y)` and $\mathrm{e}$ by `S M::e()`.
If `Reversible` is `true`, it enables `reverse` member function.

- (1)
    - It is identical to `avl_tree<M, false> avl_tree(buffer);`.
- (2)
    - It is identical to `avl_tree<M, false> avl_tree(buffer, n);`.
- (3)
    - It is identical to `avl_tree<M, false> avl_tree(buffer, v);`.
- (4)
    - It creates an empty array `a`.
- (5)
    - It creates an array `a` of length `n`. All the elements are initialized to `e()`.
- (6)
    - It creates an array `a` of length `n = v.size()`, initialized to `v`.

### Constraints
- $\forall x \in S. \forall y \in S. \forall z \in S. \mathrm{op}(\mathrm{op}(x, y), z) = \mathrm{op}(x, \mathrm{op}(y, z))$
- $\forall x \in S. \mathrm{op}(\mathrm{e}(), x) = \mathrm{op}(x, \mathrm{e}()) = x$
- $n \geq 0$

### Time Complexity
- $O(n)$

## empty
```cpp
bool avl_tree.empty();
```

It returns whether $\|a\| = 0$ or not.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## size
```cpp
int avl_tree.size();
```

It returns $\|a\|$.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## set
```cpp
void avl_tree.set(int p, S x);
```

`a[p] = x`

### Constraints
- `buffer` is in its lifetime.
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## get
```cpp
S avl_tree.get(int p);
```

It returns `a[p]`.

### Constraints
- `buffer` is in its lifetime.
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## prod
```cpp
S avl_tree.prod(int l, int r);
```

It returns `op(a[l], ..., a[r - 1])`, assuming the properties of the monoid.
It returns `e()` if $l = r$.

### Constraints
- `buffer` is in its lifetime.
- $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## all_prod
```cpp
S avl_tree.all_prod();
```

It returns `op(a[0], ..., a[a.size() - 1])`, assuming the properties of the monoid.
It returns `e()` if $\|a\| = 0$.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## insert
```cpp
void avl_tree.insert(int p, S x);
```

If $p < \|a\|$, it inserts $x$ immediately before `a[i]`.
If $p = \|a\|$, it inserts $x$ to the end of `a`.

### Constraints
- `buffer` is in its lifetime.
- $0 \leq p \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## erase
```cpp
void avl_tree.erase(int p);
```

It removes `a[i]`. (remaining elements will be concatenated)

### Constraints
- `buffer` is in its lifetime.
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## merge
```cpp
void avl_tree.merge(avl_tree<M, Reversible> other);
```

It appends the sequence represented by `other` to the end of `a`.
`other` gets empty after call of this function.

### Constraints
- `buffer` is in its lifetime.
- `avl_tree` and `other` shares the same buffer.

### Time Complexity
- $O(\log \|a\| + \log \|b\|)$ where $\|b\|$ is `other.size()`

## split
```cpp
std::pair<avl_tree<M, Reversible>, avl_tree<M, Reversible>> avl_tree.split(int i);
```

It splits `a` into the two sequences `a[0], a[1], ..., a[i - 1]` and `a[i], a[i + 1], ..., a[a.size() - 1]`.

### Constraints
- `buffer` is in its lifetime.
- $0 \leq i \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## reverse
```cpp
void avl_tree.reverse(int l, int r);
```

It reverses `a[l], a[l + 1], ..., a[r - 1]`.

### Constraints
- `<Reversible>` is `true`.
- `buffer` is in its lifetime.
- $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## max_right
```cpp
int avl_tree.max_right<G>(int l, G g)
```
It returns an index `r` that satisfies both of the followings.

- `r = l` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = a.size()` or `g(op(a[l], a[l + 1], ..., a[r])) = false`

If `g` is monotone, this is the maximum `r` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- `buffer` is in its lifetime.
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq l \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## min_left
```cpp
int avl_tree.min_left<G>(int l, G g)
```
It returns an index `l` that satisfies both of the followings.

- `l = r` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` or `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

If `g` is monotone, this is the minimum `l` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- `buffer` is in its lifetime.
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$
