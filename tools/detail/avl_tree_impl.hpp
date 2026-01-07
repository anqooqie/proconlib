#ifndef TOOLS_DETAIL_AVL_TREE_IMPL_HPP
#define TOOLS_DETAIL_AVL_TREE_IMPL_HPP

#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <functional>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/fix.hpp"
#include "tools/monoid.hpp"
#include "tools/nop_monoid.hpp"

namespace tools {
  namespace detail {
    namespace avl_tree {
      template <bool Reversible, tools::monoid SM, tools::monoid FM>
      struct extended_node_members {
      };
      template <tools::monoid SM, tools::monoid FM>
      struct extended_node_members<false, SM, FM> {
        typename FM::T lazy;
      };
      template <tools::monoid SM>
      struct extended_node_members<false, SM, tools::nop_monoid> {
      };
      template <tools::monoid SM, tools::monoid FM>
      struct extended_node_members<true, SM, FM> {
        typename SM::T rprod;
        bool rev;
        typename FM::T lazy;
      };
      template <tools::monoid SM>
      struct extended_node_members<true, SM, tools::nop_monoid> {
        typename SM::T rprod;
        bool rev;
      };

      template <bool Reversible, tools::monoid SM, tools::monoid FM, auto mapping>
      requires std::invocable<decltype(mapping), typename FM::T, typename SM::T>
            && std::same_as<std::invoke_result_t<decltype(mapping), typename FM::T, typename SM::T>, typename SM::T>
      class avl_tree_impl {
        using S = typename SM::T;
        using F = typename FM::T;
        constexpr static bool is_lazy = !std::same_as<FM, tools::nop_monoid>;

        struct node : public tools::detail::avl_tree::extended_node_members<Reversible, SM, FM> {
          int id;
          int l_id;
          int r_id;
          int height;
          int size;
          S prod;
        };

        static inline std::vector<node> s_nodes = []() {
          std::vector<node> nodes;
          auto& sentinel = nodes.emplace_back();
          sentinel.id = 0;
          sentinel.l_id = 0;
          sentinel.r_id = 0;
          sentinel.height = 0;
          sentinel.size = 0;
          sentinel.prod = SM::e();
          if constexpr (Reversible) {
            sentinel.rprod = SM::e();
            sentinel.rev = false;
          }
          if constexpr (is_lazy) {
            sentinel.lazy = FM::e();
          }
          return nodes;
        }();
        static inline std::vector<int> s_free_ids;

        static node& get_node(const int id) {
          assert(0 <= id && id < std::ssize(s_nodes));
          return s_nodes[id];
        }
        static int malloc() {
          if (s_free_ids.empty()) {
            const int id = s_nodes.size();
            s_nodes.emplace_back();
            return id;
          } else {
            const int id = s_free_ids.back();
            s_free_ids.pop_back();
            return id;
          }
        }
        static void free(const int id) {
          assert(id > 0);
          s_free_ids.push_back(id);
        }
        static int add_node(const S& x) {
          const auto id = malloc();
          auto& node = get_node(id);
          node.id = id;
          node.l_id = 0;
          node.r_id = 0;
          node.height = 1;
          node.size = 1;
          node.prod = x;
          if constexpr (Reversible) {
            node.rprod = x;
            node.rev = false;
          }
          if constexpr (is_lazy) {
            node.lazy = FM::e();
          }
          return id;
        }
        static int add_node(const int l_id, const int r_id) {
          const auto id = malloc();
          auto& node = get_node(id);
          node.id = id;
          node.l_id = l_id;
          node.r_id = r_id;
          if constexpr (Reversible) {
            node.rev = false;
          }
          if constexpr (is_lazy) {
            node.lazy = FM::e();
          }
          fetch(id);
          return id;
        }

        static void fetch(const int id) {
          auto& node = get_node(id);
          const auto& l_node = get_node(node.l_id);
          const auto& r_node = get_node(node.r_id);

          node.height = 1 + std::max(l_node.height, r_node.height);
          node.size = l_node.size + r_node.size;
          node.prod = SM::op(l_node.prod, r_node.prod);
          if constexpr (Reversible) {
            node.rprod = SM::op(r_node.rprod, l_node.rprod);
          }
        }
        static void propagate(const int id) {
          auto& node = get_node(id);
          auto& l_node = get_node(node.l_id);
          auto& r_node = get_node(node.r_id);

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
              node.prod = std::invoke(mapping, node.lazy, node.prod);
              if constexpr (Reversible) {
                 node.rprod = std::invoke(mapping, node.lazy, node.rprod);
              }
              node.lazy = FM::e();
            }
          }
        }

        static int rotate_l(const int id) {
          auto& node = get_node(id);
          auto& r_node = get_node(node.r_id);

          assert(node.size > 1);
          assert(node.id > 0);
          assert(node.l_id > 0);
          assert(node.r_id > 0);
          assert(r_node.size > 1);
          assert(r_node.id > 0);
          assert(r_node.l_id > 0);
          assert(r_node.r_id > 0);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
            propagate(node.l_id);
            propagate(node.r_id);
            propagate(r_node.l_id);
            propagate(r_node.r_id);
          }

          node.r_id = r_node.l_id;
          r_node.l_id = node.id;

          fetch(id);
          fetch(r_node.id);

          return r_node.id;
        }
        static int rotate_r(const int id) {
          auto& node = get_node(id);
          auto& l_node = get_node(node.l_id);

          assert(node.size > 1);
          assert(node.id > 0);
          assert(node.l_id > 0);
          assert(node.r_id > 0);
          assert(l_node.size > 1);
          assert(l_node.id > 0);
          assert(l_node.l_id > 0);
          assert(l_node.r_id > 0);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
            propagate(node.l_id);
            propagate(node.r_id);
            propagate(l_node.l_id);
            propagate(l_node.r_id);
          }

          node.l_id = l_node.r_id;
          l_node.r_id = node.id;

          fetch(id);
          fetch(l_node.id);

          return l_node.id;
        }
        static int height_diff(const int id) {
          const auto& node = get_node(id);
          const auto& l_node = get_node(node.l_id);
          const auto& r_node = get_node(node.r_id);

          return l_node.height - r_node.height;
        }
        static int balance(const int id) {
          auto& node = get_node(id);

          const auto diff = height_diff(id);
          assert(std::abs(diff) <= 2);

          if (diff == 2) {
            if (height_diff(node.l_id) < 0) node.l_id = rotate_l(node.l_id);
            return rotate_r(id);
          } else if (diff == -2) {
            if (height_diff(node.r_id) > 0) node.r_id = rotate_r(node.r_id);
            return rotate_l(id);
          } else {
            return id;
          }
        }

        static void set(const int id, const int p, const S& x) {
          auto& node = get_node(id);

          assert(0 <= p && p < node.size);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
          }
          if (node.size == 1) {
            node.prod = x;
          } else {
            const auto half = get_node(node.l_id).size;

            if (p < half) {
              set(node.l_id, p, x);
              if constexpr (Reversible || is_lazy) {
                propagate(node.r_id);
              }
            } else {
              if constexpr (Reversible || is_lazy) {
                propagate(node.l_id);
              }
              set(node.r_id, p - half, x);
            }
            fetch(id);
          }
        }
        static S prod(const int id, const int l, const int r) {
          auto& node = get_node(id);

          assert(0 <= l && l <= r && r <= node.size);

          if (l == r) return SM::e();

          if constexpr (Reversible || is_lazy) {
            propagate(id);
          }
          if (l == 0 && r == node.size) {
            return node.prod;
          } else {
            const auto half = get_node(node.l_id).size;

            auto res = SM::e();
            if (l < half) res = SM::op(res, prod(node.l_id, l, std::min(r, half)));
            if (half < r) res = SM::op(res, prod(node.r_id, std::max(0, l - half), r - half));
            return res;
          }
        }
        static void apply(const int id, const int l, const int r, const F& f) requires is_lazy {
          auto& node = get_node(id);

          assert(0 <= l && l <= r && r <= node.size);

          if (l == r) return;

          if (l == 0 && r == node.size) {
            node.lazy = FM::op(f, node.lazy);
            propagate(id);
          } else {
            propagate(id);

            const auto half = get_node(node.l_id).size;
            if (l < half) {
              apply(node.l_id, l, std::min(r, half), f);
            } else {
              propagate(node.l_id);
            }
            if (half < r) {
              apply(node.r_id, std::max(0, l - half), r - half, f);
            } else {
              propagate(node.r_id);
            }
            fetch(id);
          }
        }
        static int insert(const int id, const int p, const S& x) {
          auto& node = get_node(id);

          assert(0 <= p && p <= node.size);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
          }
          if (node.size == 0) {
            return add_node(x);
          } else if (node.size == 1) {
            if (p == 0) {
              return add_node(add_node(x), id);
            } else {
              return add_node(id, add_node(x));
            }
          } else {
            const auto half = get_node(node.l_id).size;

            if (p < half) {
              if constexpr (Reversible || is_lazy) {
                propagate(node.r_id);
              }
              const auto l_id = insert(node.l_id, p, x);
              get_node(id).l_id = l_id;
            } else {
              if constexpr (Reversible || is_lazy) {
                propagate(node.l_id);
              }
              const auto r_id = insert(node.r_id, p - half, x);
              get_node(id).r_id = r_id;
            }
            fetch(id);
            return balance(id);
          }
        }
        static int erase(const int id, const int p) {
          auto& node = get_node(id);

          assert(0 <= p && p < node.size);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
          }
          if (node.size == 1) {
            free(id);
            return 0;
          } else {
            const auto half = get_node(node.l_id).size;

            if (p < half) {
              if constexpr (Reversible || is_lazy) {
                propagate(node.r_id);
              }
              node.l_id = erase(node.l_id, p);
              if (node.l_id == 0) {
                free(id);
                return node.r_id;
              }
            } else {
              if constexpr (Reversible || is_lazy) {
                propagate(node.l_id);
              }
              node.r_id = erase(node.r_id, p - half);
              if (node.r_id == 0) {
                free(id);
                return node.l_id;
              }
            }
            fetch(id);
            return balance(id);
          }
        }

        static int merge(const int l_id, const int r_id) {
          if (l_id == 0) {
            if constexpr (Reversible || is_lazy) {
              propagate(r_id);
            }
            return r_id;
          }
          if (r_id == 0) {
            if constexpr (Reversible || is_lazy) {
              propagate(l_id);
            }
            return l_id;
          }

          auto& l_node = get_node(l_id);
          auto& r_node = get_node(r_id);
          const auto diff = l_node.height - r_node.height;
          if (diff >= 2) {
            if constexpr (Reversible || is_lazy) {
              propagate(l_id);
              propagate(l_node.l_id);
            }
            const auto merged_id = merge(l_node.r_id, r_id);
            get_node(l_id).r_id = merged_id;
            fetch(l_id);
            return balance(l_id);
          } else if (diff <= -2) {
            if constexpr (Reversible || is_lazy) {
              propagate(r_id);
              propagate(r_node.r_id);
            }
            const auto merged_id = merge(l_id, r_node.l_id);
            get_node(r_id).l_id = merged_id;
            fetch(r_id);
            return balance(r_id);
          } else {
            if constexpr (Reversible || is_lazy) {
              propagate(l_id);
              propagate(r_id);
            }
            return add_node(l_id, r_id);
          }
        }
        static std::pair<int, int> split(const int id, const int i) {
          auto& node = get_node(id);

          assert(0 <= i && i <= node.size);

          if (i == 0) return std::make_pair(0, id);
          if (i == node.size) return std::make_pair(id, 0);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
          }

          const auto l_id = node.l_id;
          const auto r_id = node.r_id;
          const auto half = get_node(l_id).size;
          free(id);

          if (i < half) {
            const auto [ll_id, lr_id] = split(l_id, i);
            return std::make_pair(ll_id, merge(lr_id, r_id));
          } else if (i > half) {
            const auto [rl_id, rr_id] = split(r_id, i - half);
            return std::make_pair(merge(l_id, rl_id), rr_id);
          } else {
            return std::make_pair(l_id, r_id);
          }
        }

        template <std::predicate<S> G>
        static std::pair<int, S> max_right(const int id, const int l, const G& g, S carry) {
          const auto& node = get_node(id);

          assert(0 <= l && l <= node.size);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
          }
          if (node.size == 0) {
            return std::make_pair(0, carry);
          } else if (node.size == 1) {
            if (l == 0) {
              const auto whole = SM::op(carry, node.prod);
              if (std::invoke(g, whole)) return std::make_pair(1, whole);
              return std::make_pair(0, carry);
            } else {
              assert(carry == SM::e());
              return std::make_pair(1, carry);
            }
          } else {
            const auto half = get_node(node.l_id).size;
            int r;
            if (l == 0) {
              const auto whole = SM::op(carry, node.prod);
              if (std::invoke(g, whole)) return std::make_pair(node.size, whole);

              std::tie(r, carry) = max_right(node.l_id, 0, g, carry);
              if (r < half) return std::make_pair(r, carry);

              std::tie(r, carry) = max_right(node.r_id, 0, g, carry);
              r += half;
              return std::make_pair(r, carry);
            } else {
              assert(carry == SM::e());
              if (l < half) {
                std::tie(r, carry) = max_right(node.l_id, l, g, carry);
                if (r < half) return std::make_pair(r, carry);
              }
              std::tie(r, carry) = max_right(node.r_id, std::max(0, l - half), g, carry);
              r += half;
              return std::make_pair(r, carry);
            }
          }
        }
        template <std::predicate<S> G>
        static std::pair<int, S> min_left(const int id, const int r, const G& g, S carry) {
          const auto& node = get_node(id);

          assert(0 <= r && r <= node.size);

          if constexpr (Reversible || is_lazy) {
            propagate(id);
          }
          if (node.size == 0) {
            return std::make_pair(0, carry);
          } else if (node.size == 1) {
            if (r == node.size) {
              const auto whole = SM::op(node.prod, carry);
              if (std::invoke(g, whole)) return std::make_pair(0, whole);
              return std::make_pair(1, carry);
            } else {
              assert(carry == SM::e());
              return std::make_pair(0, carry);
            }
          } else {
            const auto half = get_node(node.l_id).size;
            int l;
            if (r == node.size) {
              const auto whole = SM::op(node.prod, carry);
              if (std::invoke(g, whole)) return std::make_pair(0, whole);

              std::tie(l, carry) = min_left(node.r_id, node.size - half, g, carry);
              l += half;
              if (half < l) return std::make_pair(l, carry);

              std::tie(l, carry) = min_left(node.l_id, half, g, carry);
              return std::make_pair(l, carry);
            } else {
              assert(carry == SM::e());
              if (half < r) {
                std::tie(l, carry) = min_left(node.r_id, r - half, g, carry);
                l += half;
                if (half < l) return std::make_pair(l, carry);
              }
              std::tie(l, carry) = min_left(node.l_id, std::min(half, r), g, carry);
              return std::make_pair(l, carry);
            }
          }
        }

        int m_root_id;

        void wipe() {
          if (!this->empty()) {
            tools::fix([&](auto&& dfs, const int id) -> void {
              auto& node = get_node(id);
              if (node.size > 1) {
                dfs(node.l_id);
                dfs(node.r_id);
              }
              free(id);
            })(this->m_root_id);
          }
        }

      public:
        explicit operator std::vector<S>() const {
          std::vector<S> v;
          if (!this->empty()) {
            tools::fix([&](auto&& dfs, const int id) -> void {
              auto& node = get_node(id);
              if constexpr (Reversible || is_lazy) {
                propagate(id);
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

        avl_tree_impl() : m_root_id(0) {
        }
        template <std::ranges::random_access_range R>
        requires std::assignable_from<S&, std::ranges::range_reference_t<R>>
        explicit avl_tree_impl(R&& v) : m_root_id(std::ranges::empty(v) ? 0 : tools::fix([&](auto&& dfs, const int l, const int r) -> int {
          if (r - l == 1) {
            return add_node(std::ranges::begin(v)[l]);
          } else {
            return add_node(dfs(l, (l + r) / 2), dfs((l + r) / 2, r));
          }
        })(0, std::ranges::distance(v))) {
        }
        template <std::ranges::input_range R>
        requires (std::assignable_from<S&, std::ranges::range_reference_t<R>> && !std::ranges::random_access_range<R>)
        explicit avl_tree_impl(R&& v) : avl_tree_impl(std::forward<R>(v) | std::ranges::to<std::vector<S>>()) {
        }
        explicit avl_tree_impl(const int n) : avl_tree_impl(std::vector<S>(n, SM::e())) {
        }
        avl_tree_impl(const avl_tree_impl<Reversible, SM, FM, mapping>& other) : avl_tree_impl(static_cast<std::vector<S>>(other)) {
        }
        avl_tree_impl(avl_tree_impl<Reversible, SM, FM, mapping>&& other) noexcept : m_root_id(other.m_root_id) {
          other.m_root_id = 0;
        }
        ~avl_tree_impl() {
          this->wipe();
        }
        avl_tree_impl<Reversible, SM, FM, mapping>& operator=(const avl_tree_impl<Reversible, SM, FM, mapping>& other) {
          this->wipe();
          this->m_root_id = avl_tree_impl<Reversible, SM, FM, mapping>(other).m_root_id;
          return *this;
        }
        avl_tree_impl<Reversible, SM, FM, mapping>& operator=(avl_tree_impl<Reversible, SM, FM, mapping>&& other) noexcept {
          this->wipe();
          this->m_root_id = other.m_root_id;
          other.m_root_id = 0;
          return *this;
        }

        int size() const {
          return get_node(this->m_root_id).size;
        }
        bool empty() const {
          return this->m_root_id == 0;
        }

        void set(const int p, const S& x) {
          set(this->m_root_id, p, x);
        }
        S get(const int p) {
          return prod(this->m_root_id, p, p + 1);
        }
        S prod(const int l, const int r) {
          return prod(this->m_root_id, l, r);
        }
        S all_prod() {
          return prod(this->m_root_id, 0, this->size());
        }
        void apply(const int p, const F& f) requires is_lazy {
          apply(this->m_root_id, p, p + 1, f);
        }
        void apply(const int l, const int r, const F& f) requires is_lazy {
          apply(this->m_root_id, l, r, f);
        }
        void insert(const int p, const S& x) {
          this->m_root_id = insert(this->m_root_id, p, x);
        }
        void erase(const int p) {
          this->m_root_id = erase(this->m_root_id, p);
        }
        void merge(avl_tree_impl<Reversible, SM, FM, mapping>&& other) {
          this->m_root_id = merge(this->m_root_id, other.m_root_id);
          other.m_root_id = 0;
        }
        std::pair<avl_tree_impl<Reversible, SM, FM, mapping>, avl_tree_impl<Reversible, SM, FM, mapping>> split(const int i) && {
          avl_tree_impl<Reversible, SM, FM, mapping> l, r;
          std::tie(l.m_root_id, r.m_root_id) = split(this->m_root_id, i);
          this->m_root_id = 0;
          return std::make_pair(std::move(l), std::move(r));
        }
        void reverse(const int l, const int r) requires Reversible {
          assert(0 <= l && l <= r && r <= this->size());

          if (l == r) return;

          if (l == 0) {
            if (r == this->size()) {
              get_node(this->m_root_id).rev = !get_node(this->m_root_id).rev;
            } else {
              const auto [l_id, r_id] = split(this->m_root_id, r);
              get_node(l_id).rev = !get_node(l_id).rev;
              this->m_root_id = merge(l_id, r_id);
            }
          } else {
            if (r == this->size()) {
              const auto [l_id, r_id] = split(this->m_root_id, l);
              get_node(r_id).rev = !get_node(r_id).rev;
              this->m_root_id = merge(l_id, r_id);
            } else {
              const auto [lm_id, r_id] = split(this->m_root_id, r);
              const auto [l_id, m_id] = split(lm_id, l);
              get_node(m_id).rev = !get_node(m_id).rev;
              this->m_root_id = merge(merge(l_id, m_id), r_id);
            }
          }
        }
        template <std::predicate<S> G>
        int max_right(const int l, const G& g) {
          assert(std::invoke(g, SM::e()));
          return max_right(this->m_root_id, l, g, SM::e()).first;
        }
        template <std::predicate<S> G>
        int min_left(const int r, const G& g) {
          assert(std::invoke(g, SM::e()));
          return min_left(this->m_root_id, r, g, SM::e()).first;
        }
      };
    }
  }
}

#endif
