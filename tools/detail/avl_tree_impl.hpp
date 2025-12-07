#ifndef TOOLS_DETAIL_AVL_TREE_IMPL_HPP
#define TOOLS_DETAIL_AVL_TREE_IMPL_HPP

#include <variant>
#include <type_traits>
#include <functional>
#include <vector>
#include <algorithm>
#include <cassert>
#include <utility>
#include <cmath>
#include "tools/fix.hpp"

namespace tools {
  namespace detail {
    namespace avl_tree {
      struct nop_monoid {
        using T = std::monostate;
        static constexpr T op(T, T) {
          return T{};
        }
        static constexpr T e() {
          return T{};
        }
      };
      template <typename SM>
      typename SM::T nop(typename nop_monoid::T, const typename SM::T& x) {
        return x;
      }

      template <bool Reversible, typename SM, typename FM = nop_monoid, auto mapping = nop<SM>>
      class avl_tree_impl {
      private:
        using S = typename SM::T;
        using F = typename FM::T;
        static_assert(
          std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
          "mapping must work as S(F, S)");
        constexpr static bool is_lazy = !std::is_same_v<FM, nop_monoid>;

        struct node {
          int id;
          int l_id;
          int r_id;
          int height;
          int size;
          S prod;
          std::conditional_t<Reversible, S, std::monostate> rprod;
          bool rev;
          F lazy;
        };

      public:
        class buffer {
        private:
          std::vector<node> m_nodes;

        public:
          buffer() {
            if constexpr (Reversible) {
              this->m_nodes.push_back(node{0, 0, 0, 0, 0, SM::e(), SM::e(), false, FM::e()});
            } else {
              this->m_nodes.push_back(node{0, 0, 0, 0, 0, SM::e(), std::monostate{}, false, FM::e()});
            }
          }
          buffer(const buffer&) = default;
          buffer(buffer&&) = default;
          ~buffer() = default;
          buffer& operator=(const buffer&) = default;
          buffer& operator=(buffer&&) = default;

          friend tools::detail::avl_tree::avl_tree_impl<Reversible, SM, FM, mapping>;
        };

      private:
        buffer *m_buffer;
        int m_root_id;

        void fetch(const int id) {
          auto& node = this->m_buffer->m_nodes[id];
          const auto& l_node = this->m_buffer->m_nodes[node.l_id];
          const auto& r_node = this->m_buffer->m_nodes[node.r_id];

          node.height = 1 + std::max(l_node.height, r_node.height);
          node.size = l_node.size + r_node.size;
          node.prod = SM::op(l_node.prod, r_node.prod);
          if constexpr (Reversible) {
            node.rprod = SM::op(r_node.rprod, l_node.rprod);
          }
        }
        void propagate(const int id) {
          auto& node = this->m_buffer->m_nodes[id];
          auto& l_node = this->m_buffer->m_nodes[node.l_id];
          auto& r_node = this->m_buffer->m_nodes[node.r_id];

          assert(!(node.size == 0) || (node.id == 0 && node.l_id == 0 && node.r_id == 0));
          assert(!(node.size == 1) || (node.id > 0 && node.l_id == 0 && node.r_id == 0));
          assert(!(node.size > 1) || (node.id > 0 && node.l_id > 0 && node.r_id > 0));

          if constexpr (Reversible) {
            if (node.rev) {
              if (node.size > 1) {
                l_node.rev = !l_node.rev;
                r_node.rev = !r_node.rev;
                std::swap(node.l_id, node.r_id);
                std::swap(node.prod, node.rprod);
              }
              node.rev = false;
            }
          }
          if constexpr (is_lazy) {
            if (node.lazy != FM::e()) {
              if (node.size > 1) {
                l_node.lazy = FM::op(node.lazy, l_node.lazy);
                r_node.lazy = FM::op(node.lazy, r_node.lazy);
              }
              node.prod = mapping(node.lazy, node.prod);
              if constexpr (Reversible) {
                 node.rprod = mapping(node.lazy, node.rprod);
              }
              node.lazy = FM::e();
            }
          }
        }

        int add_node(const S& x) {
          const int id = this->m_buffer->m_nodes.size();
          if constexpr (Reversible) {
            this->m_buffer->m_nodes.push_back(node{id, 0, 0, 1, 1, x, x, false, FM::e()});
          } else {
            this->m_buffer->m_nodes.push_back(node{id, 0, 0, 1, 1, x, std::monostate{}, false, FM::e()});
          }
          return id;
        }
        int add_node(const int l_id, const int r_id) {
          const int id = this->m_buffer->m_nodes.size();
          if constexpr (Reversible) {
            this->m_buffer->m_nodes.push_back(node{id, l_id, r_id, 0, 0, SM::e(), SM::e(), false, FM::e()});
          } else {
            this->m_buffer->m_nodes.push_back(node{id, l_id, r_id, 0, 0, SM::e(), std::monostate{}, false, FM::e()});
          }
          this->fetch(id);
          return id;
        }

        int rotate_l(const int id) {
          auto& node = this->m_buffer->m_nodes[id];
          auto& r_node = this->m_buffer->m_nodes[node.r_id];

          assert(node.size > 1);
          assert(node.id > 0);
          assert(node.l_id > 0);
          assert(node.r_id > 0);
          assert(r_node.size > 1);
          assert(r_node.id > 0);
          assert(r_node.l_id > 0);
          assert(r_node.r_id > 0);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
            this->propagate(node.l_id);
            this->propagate(node.r_id);
            this->propagate(r_node.l_id);
            this->propagate(r_node.r_id);
          }

          node.r_id = r_node.l_id;
          r_node.l_id = node.id;

          this->fetch(id);
          this->fetch(r_node.id);

          return r_node.id;
        }
        int rotate_r(const int id) {
          auto& node = this->m_buffer->m_nodes[id];
          auto& l_node = this->m_buffer->m_nodes[node.l_id];

          assert(node.size > 1);
          assert(node.id > 0);
          assert(node.l_id > 0);
          assert(node.r_id > 0);
          assert(l_node.size > 1);
          assert(l_node.id > 0);
          assert(l_node.l_id > 0);
          assert(l_node.r_id > 0);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
            this->propagate(node.l_id);
            this->propagate(node.r_id);
            this->propagate(l_node.l_id);
            this->propagate(l_node.r_id);
          }

          node.l_id = l_node.r_id;
          l_node.r_id = node.id;

          this->fetch(id);
          this->fetch(l_node.id);

          return l_node.id;
        }
        int height_diff(const int id) {
          const auto& node = this->m_buffer->m_nodes[id];
          const auto& l_node = this->m_buffer->m_nodes[node.l_id];
          const auto& r_node = this->m_buffer->m_nodes[node.r_id];

          return l_node.height - r_node.height;
        }
        int balance(const int id) {
          auto& node = this->m_buffer->m_nodes[id];

          const auto diff = this->height_diff(id);
          assert(std::abs(diff) <= 2);

          if (diff == 2) {
            if (this->height_diff(node.l_id) < 0) node.l_id = this->rotate_l(node.l_id);
            return this->rotate_r(id);
          } else if (diff == -2) {
            if (this->height_diff(node.r_id) > 0) node.r_id = this->rotate_r(node.r_id);
            return this->rotate_l(id);
          } else {
            return id;
          }
        }

        void set(const int id, const int p, const S& x) {
          auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= p && p < node.size);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
          }
          if (node.size == 1) {
            node.prod = x;
          } else {
            const auto half = this->m_buffer->m_nodes[node.l_id].size;

            if (p < half) {
              this->set(node.l_id, p, x);
              if constexpr (Reversible || is_lazy) {
                this->propagate(node.r_id);
              }
            } else {
              if constexpr (Reversible || is_lazy) {
                this->propagate(node.l_id);
              }
              this->set(node.r_id, p - half, x);
            }
            this->fetch(id);
          }
        }
        S prod(const int id, const int l, const int r) {
          auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= l && l <= r && r <= node.size);

          if (l == r) return SM::e();

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
          }
          if (l == 0 && r == node.size) {
            return node.prod;
          } else {
            const auto half = this->m_buffer->m_nodes[node.l_id].size;

            auto res = SM::e();
            if (l < half) res = SM::op(res, this->prod(node.l_id, l, std::min(r, half)));
            if (half < r) res = SM::op(res, this->prod(node.r_id, std::max(0, l - half), r - half));
            return res;
          }
        }
        template <bool SFINAE = is_lazy>
        std::enable_if_t<SFINAE, void> apply(const int id, const int l, const int r, const F& f) {
          auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= l && l <= r && r <= node.size);

          if (l == r) return;

          if (l == 0 && r == node.size) {
            node.lazy = FM::op(f, node.lazy);
            this->propagate(id);
          } else {
            this->propagate(id);

            const auto half = this->m_buffer->m_nodes[node.l_id].size;
            if (l < half) {
              this->apply(node.l_id, l, std::min(r, half), f);
            } else {
              this->propagate(node.l_id);
            }
            if (half < r) {
              this->apply(node.r_id, std::max(0, l - half), r - half, f);
            } else {
              this->propagate(node.r_id);
            }
            this->fetch(id);
          }
        }
        int insert(const int id, const int p, const S& x) {
          auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= p && p <= node.size);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
          }
          if (node.size == 0) {
            return this->add_node(x);
          } else if (node.size == 1) {
            if (p == 0) {
              return this->add_node(this->add_node(x), id);
            } else {
              return this->add_node(id, this->add_node(x));
            }
          } else {
            const auto half = this->m_buffer->m_nodes[node.l_id].size;

            if (p < half) {
              if constexpr (Reversible || is_lazy) {
                this->propagate(node.r_id);
              }
              const auto l_id = this->insert(node.l_id, p, x);
              this->m_buffer->m_nodes[id].l_id = l_id;
            } else {
              if constexpr (Reversible || is_lazy) {
                this->propagate(node.l_id);
              }
              const auto r_id = this->insert(node.r_id, p - half, x);
              this->m_buffer->m_nodes[id].r_id = r_id;
            }
            this->fetch(id);
            return this->balance(id);
          }
        }
        int erase(const int id, const int p) {
          auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= p && p < node.size);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
          }
          if (node.size == 1) {
            return 0;
          } else {
            const auto half = this->m_buffer->m_nodes[node.l_id].size;

            if (p < half) {
              if constexpr (Reversible || is_lazy) {
                this->propagate(node.r_id);
              }
              node.l_id = this->erase(node.l_id, p);
              if (node.l_id == 0) return node.r_id;
            } else {
              if constexpr (Reversible || is_lazy) {
                this->propagate(node.l_id);
              }
              node.r_id = this->erase(node.r_id, p - half);
              if (node.r_id == 0) return node.l_id;
            }
            this->fetch(id);
            return this->balance(id);
          }
        }

        int merge(const int l_id, const int r_id, const int free_id) {
          if (l_id == 0) {
            if constexpr (Reversible || is_lazy) {
              this->propagate(r_id);
            }
            return r_id;
          }
          if (r_id == 0) {
            if constexpr (Reversible || is_lazy) {
              this->propagate(l_id);
            }
            return l_id;
          }

          auto& l_node = this->m_buffer->m_nodes[l_id];
          auto& r_node = this->m_buffer->m_nodes[r_id];
          const auto diff = l_node.height - r_node.height;
          if (diff >= 2) {
            if constexpr (Reversible || is_lazy) {
              this->propagate(l_id);
              this->propagate(l_node.l_id);
            }
            const auto merged_id = this->merge(l_node.r_id, r_id, free_id);
            this->m_buffer->m_nodes[l_id].r_id = merged_id;
            this->fetch(l_id);
            return this->balance(l_id);
          } else if (diff <= -2) {
            if constexpr (Reversible || is_lazy) {
              this->propagate(r_id);
              this->propagate(r_node.r_id);
            }
            const auto merged_id = this->merge(l_id, r_node.l_id, free_id);
            this->m_buffer->m_nodes[r_id].l_id = merged_id;
            this->fetch(r_id);
            return this->balance(r_id);
          } else {
            if constexpr (Reversible || is_lazy) {
              this->propagate(l_id);
              this->propagate(r_id);
            }
            if (free_id == 0) {
              return this->add_node(l_id, r_id);
            } else {
              auto& node = this->m_buffer->m_nodes[free_id];
              node.l_id = l_id;
              node.r_id = r_id;
              if constexpr (Reversible) {
                node.rev = false;
              }
              if constexpr (is_lazy) {
                node.lazy = FM::e();
              }
              this->fetch(free_id);
              return free_id;
            }
          }
        }
        std::pair<int, int> split(const int id, const int i) {
          auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= i && i <= node.size);

          if (i == 0) return std::make_pair(0, id);
          if (i == node.size) return std::make_pair(id, 0);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
          }
          const auto half = this->m_buffer->m_nodes[node.l_id].size;
          if (i < half) {
            const auto [l_id, r_id] = this->split(node.l_id, i);
            return std::make_pair(l_id, this->merge(r_id, this->m_buffer->m_nodes[id].r_id, this->m_buffer->m_nodes[id].l_id));
          } else if (i > half) {
            const auto [l_id, r_id] = this->split(node.r_id, i - half);
            return std::make_pair(this->merge(this->m_buffer->m_nodes[id].l_id, l_id, this->m_buffer->m_nodes[id].r_id), r_id);
          } else {
            return std::make_pair(node.l_id, node.r_id);
          }
        }

        template <typename G>
        std::pair<int, S> max_right(const int id, const int l, const G& g, S carry) {
          const auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= l && l <= node.size);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
          }
          if (node.size == 0) {
            return std::make_pair(0, carry);
          } else if (node.size == 1) {
            if (l == 0) {
              const auto whole = SM::op(carry, node.prod);
              if (g(whole)) return std::make_pair(1, whole);
              return std::make_pair(0, carry);
            } else {
              assert(carry == SM::e());
              return std::make_pair(1, carry);
            }
          } else {
            const auto half = this->m_buffer->m_nodes[node.l_id].size;
            int r;
            if (l == 0) {
              const auto whole = SM::op(carry, node.prod);
              if (g(whole)) return std::make_pair(node.size, whole);

              std::tie(r, carry) = this->max_right(node.l_id, 0, g, carry);
              if (r < half) return std::make_pair(r, carry);

              std::tie(r, carry) = this->max_right(node.r_id, 0, g, carry);
              r += half;
              return std::make_pair(r, carry);
            } else {
              assert(carry == SM::e());
              if (l < half) {
                std::tie(r, carry) = this->max_right(node.l_id, l, g, carry);
                if (r < half) return std::make_pair(r, carry);
              }
              std::tie(r, carry) = this->max_right(node.r_id, std::max(0, l - half), g, carry);
              r += half;
              return std::make_pair(r, carry);
            }
          }
        }
        template <typename G>
        std::pair<int, S> min_left(const int id, const int r, const G& g, S carry) {
          const auto& node = this->m_buffer->m_nodes[id];

          assert(0 <= r && r <= node.size);

          if constexpr (Reversible || is_lazy) {
            this->propagate(id);
          }
          if (node.size == 0) {
            return std::make_pair(0, carry);
          } else if (node.size == 1) {
            if (r == node.size) {
              const auto whole = SM::op(node.prod, carry);
              if (g(whole)) return std::make_pair(0, whole);
              return std::make_pair(1, carry);
            } else {
              assert(carry == SM::e());
              return std::make_pair(0, carry);
            }
          } else {
            const auto half = this->m_buffer->m_nodes[node.l_id].size;
            int l;
            if (r == node.size) {
              const auto whole = SM::op(node.prod, carry);
              if (g(whole)) return std::make_pair(0, whole);

              std::tie(l, carry) = this->min_left(node.r_id, node.size - half, g, carry);
              l += half;
              if (half < l) return std::make_pair(l, carry);

              std::tie(l, carry) = this->min_left(node.l_id, half, g, carry);
              return std::make_pair(l, carry);
            } else {
              assert(carry == SM::e());
              if (half < r) {
                std::tie(l, carry) = this->min_left(node.r_id, r - half, g, carry);
                l += half;
                if (half < l) return std::make_pair(l, carry);
              }
              std::tie(l, carry) = this->min_left(node.l_id, std::min(half, r), g, carry);
              return std::make_pair(l, carry);
            }
          }
        }

      public:
        explicit operator std::vector<S>() const {
          std::vector<S> v;
          if (!this->empty()) {
            tools::fix([&](auto&& dfs, const int id) -> void {
              auto& node = this->m_buffer->m_nodes[id];
              if constexpr (Reversible || is_lazy) {
                this->propagate(id);
              }
              if (node.size == 1) {
                v.push_back(node.prod);
              } else {
                dfs(node.l_id);
                dfs(node.r_id);
              }
            })(this->m_root_id);
          }
          return v;
        }

        avl_tree_impl() = default;
        explicit avl_tree_impl(buffer& buffer) : m_buffer(&buffer), m_root_id(0) {
        }
        avl_tree_impl(buffer& buffer, const std::vector<S>& v) : m_buffer(&buffer) {
          this->m_root_id = v.empty() ? 0 : tools::fix([&](auto&& dfs, const int l, const int r) -> int {
            if (r - l == 1) {
              return this->add_node(v[l]);
            } else {
              return this->add_node(dfs(l, (l + r) / 2), dfs((l + r) / 2, r));
            }
          })(0, v.size());
        }
        avl_tree_impl(buffer& buffer, const int n) : avl_tree_impl(buffer, std::vector<S>(n, SM::e())) {
        }
        avl_tree_impl(const avl_tree_impl<Reversible, SM, FM, mapping>& other) : avl_tree_impl(*other.m_buffer, static_cast<std::vector<S>>(other)) {
        }
        avl_tree_impl(avl_tree_impl<Reversible, SM, FM, mapping>&& other) : m_buffer(other.m_buffer), m_root_id(other.m_root_id) {
        }
        ~avl_tree_impl() = default;
        avl_tree_impl<Reversible, SM, FM, mapping>& operator=(const avl_tree_impl<Reversible, SM, FM, mapping>& other) {
          this->m_buffer = other.m_buffer;
          this->m_root_id = avl_tree_impl<Reversible, SM, FM, mapping>(other).m_root_id;
        }
        avl_tree_impl<Reversible, SM, FM, mapping>& operator=(avl_tree_impl<Reversible, SM, FM, mapping>&& other) {
          this->m_buffer = other.m_buffer;
          this->m_root_id = other.m_root_id;
        }

        int size() const {
          return this->m_buffer->m_nodes[this->m_root_id].size;
        }
        bool empty() const {
          return this->m_root_id == 0;
        }

        void set(const int p, const S& x) {
          this->set(this->m_root_id, p, x);
        }
        S get(const int p) {
          return this->prod(this->m_root_id, p, p + 1);
        }
        S prod(const int l, const int r) {
          return this->prod(this->m_root_id, l, r);
        }
        S all_prod() {
          return this->prod(this->m_root_id, 0, this->size());
        }
        template <bool SFINAE = is_lazy>
        std::enable_if_t<SFINAE, void> apply(const int p, const F& f) {
          this->apply(this->m_root_id, p, p + 1, f);
        }
        template <bool SFINAE = is_lazy>
        std::enable_if_t<SFINAE, void> apply(const int l, const int r, const F& f) {
          this->apply(this->m_root_id, l, r, f);
        }
        void insert(const int p, const S& x) {
          this->m_root_id = this->insert(this->m_root_id, p, x);
        }
        void erase(const int p) {
          this->m_root_id = this->erase(this->m_root_id, p);
        }
        void merge(avl_tree_impl<Reversible, SM, FM, mapping>& other) {
          assert(this->m_buffer == other.m_buffer);
          this->m_root_id = this->merge(this->m_root_id, other.m_root_id, 0);
          other.m_root_id = 0;
        }
        std::pair<avl_tree_impl<Reversible, SM, FM, mapping>, avl_tree_impl<Reversible, SM, FM, mapping>> split(const int i) {
          avl_tree_impl<Reversible, SM, FM, mapping> l(*this->m_buffer), r(*this->m_buffer);
          std::tie(l.m_root_id, r.m_root_id) = this->split(this->m_root_id, i);
          return std::make_pair(l, r);
        }
        template <bool SFINAE = Reversible>
        std::enable_if_t<SFINAE, void> reverse(const int l, const int r) {
          assert(0 <= l && l <= r && r <= this->size());

          if (l == r) return;

          if (l == 0) {
            if (r == this->size()) {
              this->m_buffer->m_nodes[this->m_root_id].rev = !this->m_buffer->m_nodes[this->m_root_id].rev;
            } else {
              const auto [l_id, r_id] = this->split(this->m_root_id, r);
              this->m_buffer->m_nodes[l_id].rev = !this->m_buffer->m_nodes[l_id].rev;
              this->m_root_id = this->merge(l_id, r_id, this->m_root_id);
            }
          } else {
            if (r == this->size()) {
              const auto [l_id, r_id] = this->split(this->m_root_id, l);
              this->m_buffer->m_nodes[r_id].rev = !this->m_buffer->m_nodes[r_id].rev;
              this->m_root_id = this->merge(l_id, r_id, this->m_root_id);
            } else {
              const auto [lm_id, r_id] = this->split(this->m_root_id, r);
              const auto [l_id, m_id] = this->split(lm_id, l);
              this->m_buffer->m_nodes[m_id].rev = !this->m_buffer->m_nodes[m_id].rev;
              this->m_root_id = this->merge(this->merge(l_id, m_id, lm_id), r_id, this->m_root_id);
            }
          }
        }
        template <typename G>
        int max_right(const int l, const G& g) {
          return this->max_right(this->m_root_id, l, g, SM::e()).first;
        }
        template <typename G>
        int min_left(const int r, const G& g) {
          return this->min_left(this->m_root_id, r, g, SM::e()).first;
        }
      };
    }
  }
}

#endif
