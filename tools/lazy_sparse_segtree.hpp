#ifndef TOOLS_LAZY_SPARSE_SEGTREE_HPP
#define TOOLS_LAZY_SPARSE_SEGTREE_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <numeric>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#include "tools/ceil_log2.hpp"
#include "tools/fix.hpp"
#include "tools/nop_monoid.hpp"

namespace tools {
  template <typename SM, typename FM, auto mapping>
  class lazy_sparse_segtree {
    using S = typename SM::T;
    using F = typename FM::T;
    static_assert(
      std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
      "mapping must work as S(F, S)");

    template <typename T>
    static constexpr bool has_data = !std::is_same_v<T, tools::nop_monoid>;
    template <typename T>
    static constexpr bool has_lazy = !std::is_same_v<T, tools::nop_monoid>;

    struct regular_node {
      S data;
      std::array<int, 2> children;
    };
    struct dual_node {
      F lazy;
      std::array<int, 2> children;
    };
    struct lazy_node {
      S data;
      F lazy;
      std::array<int, 2> children;
    };
    using node = std::conditional_t<has_data<SM>, std::conditional_t<has_lazy<FM>, lazy_node, regular_node>, dual_node>;

    std::vector<node> m_nodes;
    long long m_offset;
    long long m_size;
    int m_height;
    int m_root;

    long long capacity() const {
      return 1LL << this->m_height;
    }
    bool is_mutable(const int k) const {
      assert(0 <= k && std::cmp_less(k, this->m_nodes.size()));
      return this->m_height < k;
    }
    void make_mutable() {
      if (this->is_mutable(this->m_root)) return;
      this->m_nodes.push_back(this->m_nodes[this->m_root]);
      this->m_root = this->m_nodes.size() - 1;
    }
    void make_mutable(const int k, const int d) {
      assert(0 <= k && std::cmp_less(k, this->m_nodes.size()));
      assert(0 <= d && d < 2);
      assert(!this->is_leaf(k));
      if (this->is_mutable(this->m_nodes[k].children[d])) return;
      this->m_nodes.push_back(this->m_nodes[this->m_nodes[k].children[d]]);
      this->m_nodes[k].children[d] = this->m_nodes.size() - 1;
    }
    bool is_leaf(const int k) const {
      assert(0 <= k && std::cmp_less(k, this->m_nodes.size()));
      const auto& node = this->m_nodes[k];
      return node.children[0] < 0 && node.children[1] < 0;
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
    void push(const int k) {
      assert(0 <= k && std::cmp_less(k, this->m_nodes.size()));
      assert(this->is_mutable(k));
      assert(!this->is_leaf(k));
      auto& node = this->m_nodes[k];
      this->all_apply(node.children[0], node.lazy);
      this->all_apply(node.children[1], node.lazy);
      node.lazy = FM::e();
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
    void all_apply(const int k, const F& f) {
      assert(0 <= k && std::cmp_less(k, this->m_nodes.size()));
      assert(this->is_mutable(k));
      auto& node = this->m_nodes[k];
      if constexpr (has_data<SM>) {
        node.data = mapping(f, node.data);
      }
      node.lazy = FM::op(f, node.lazy);
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    void update(const int k) {
      assert(0 <= k && std::cmp_less(k, this->m_nodes.size()));
      assert(this->is_mutable(k));
      assert(!this->is_leaf(k));
      auto& node = this->m_nodes[k];
      node.data = SM::op(this->m_nodes[node.children[0]].data, this->m_nodes[node.children[1]].data);
    }

  public:
    lazy_sparse_segtree() = default;
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    lazy_sparse_segtree(const long long l_star, const long long r_star) : lazy_sparse_segtree(l_star, r_star, SM::e()) {
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    lazy_sparse_segtree(const long long l_star, const long long r_star, const S& x) :
        m_offset(l_star), m_size(r_star - l_star), m_height(tools::ceil_log2(std::max(1LL, r_star - l_star))) {
      assert(l_star <= r_star);
      if constexpr (has_lazy<FM>) {
        this->m_nodes.push_back({x, FM::e(), {-1, -1}});
        for (int k = 1; k <= this->m_height; ++k) {
          this->m_nodes.push_back({SM::op(this->m_nodes.back().data, this->m_nodes.back().data), FM::e(), {k - 1, k - 1}});
        }
      } else {
        this->m_nodes.push_back({x, {-1, -1}});
        for (int k = 1; k <= this->m_height; ++k) {
          this->m_nodes.push_back({SM::op(this->m_nodes.back().data, this->m_nodes.back().data), {k - 1, k - 1}});
        }
      }
      this->m_root = this->m_height;
    }
    template <typename SFINAE = SM> requires (!has_data<SFINAE>)
    lazy_sparse_segtree(const long long l_star, const long long r_star) :
        m_offset(l_star), m_size(r_star - l_star), m_height(tools::ceil_log2(std::max(1LL, r_star - l_star))) {
      assert(l_star <= r_star);
      this->m_nodes.push_back({FM::e(), {-1, -1}});
      for (int k = 1; k <= this->m_height; ++k) {
        this->m_nodes.push_back({FM::e(), {k - 1, k - 1}});
      }
      this->m_root = this->m_height;
    }

    long long lower_bound() const {
      return this->m_offset;
    }
    long long upper_bound() const {
      return this->m_offset + this->m_size;
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    void set(long long p, const S& x) {
      assert(this->lower_bound() <= p && p < this->upper_bound());
      p -= this->m_offset;

      this->make_mutable();
      tools::fix([&](auto&& dfs, const int h, const int k) -> void {
        assert(this->is_mutable(k));
        if (h > 0) {
          assert(!this->is_leaf(k));
          if constexpr (has_lazy<FM>) {
            this->make_mutable(k, 0);
            this->make_mutable(k, 1);
            this->push(k);
          } else {
            this->make_mutable(k, ((this->capacity() + p) >> (h - 1)) & 1);
          }
          dfs(h - 1, this->m_nodes[k].children[((this->capacity() + p) >> (h - 1)) & 1]);
          this->update(k);
        } else {
          assert(this->is_leaf(k));
          this->m_nodes[k].data = x;
        }
      })(this->m_height, this->m_root);
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    S get(const long long p) {
      return this->prod(p, p + 1);
    }
    template <typename SFINAE = SM> requires (!has_data<SFINAE>)
    F get(long long p) {
      assert(this->lower_bound() <= p && p < this->upper_bound());
      p -= this->m_offset;

      this->make_mutable();
      return tools::fix([&](auto&& dfs, const int h, const int k) -> F {
        assert(this->is_mutable(k));
        if (h > 0) {
          assert(!this->is_leaf(k));
          this->make_mutable(k, 0);
          this->make_mutable(k, 1);
          this->push(k);
          return dfs(h - 1, this->m_nodes[k].children[((this->capacity() + p) >> (h - 1)) & 1]);
        } else {
          assert(this->is_leaf(k));
          return this->m_nodes[k].lazy;
        }
      })(this->m_height, this->m_root);
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    S prod(long long l, long long r) {
      assert(this->lower_bound() <= l && l <= r && r <= this->upper_bound());
      if (l == r) return SM::e();
      l -= this->m_offset;
      r -= this->m_offset;

      if constexpr (has_lazy<FM>) {
        this->make_mutable();
      }
      return tools::fix([&](auto&& dfs, const int k, const long long kl, const long long kr) -> S {
        assert(kl < kr);
        if (l <= kl && kr <= r) return this->m_nodes[k].data;
        if constexpr (has_lazy<FM>) {
          this->make_mutable(k, 0);
          this->make_mutable(k, 1);
          this->push(k);
        }
        const auto km = std::midpoint(kl, kr);
        S res = SM::e();
        if (l < km) res = SM::op(res, dfs(this->m_nodes[k].children[0], kl, km));
        if (km < r) res = SM::op(res, dfs(this->m_nodes[k].children[1], km, kr));
        return res;
      })(this->m_root, 0, this->capacity());
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    S all_prod() const {
      return this->m_nodes[this->m_root].data;
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
    void apply(const long long p, const F& f) {
      this->apply(p, p + 1, f);
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
    void apply(long long l, long long r, const F& f) {
      assert(this->lower_bound() <= l && l <= r && r <= this->upper_bound());
      if (l == r) return;
      l -= this->m_offset;
      r -= this->m_offset;

      this->make_mutable();
      tools::fix([&](auto&& dfs, const int k, const long long kl, const long long kr) -> void {
        assert(kl < kr);
        if (l <= kl && kr <= r) {
          this->all_apply(k, f);
          return;
        }
        this->make_mutable(k, 0);
        this->make_mutable(k, 1);
        this->push(k);
        const auto km = std::midpoint(kl, kr);
        if (l < km) dfs(this->m_nodes[k].children[0], kl, km);
        if (km < r) dfs(this->m_nodes[k].children[1], km, kr);
        if constexpr (has_data<SM>) {
          this->update(k);
        }
      })(this->m_root, 0, this->capacity());
    }
    template <typename G, typename SFINAE = SM> requires (has_data<SFINAE>)
    long long max_right(long long l, const G& g) {
      assert(this->lower_bound() <= l && l <= this->upper_bound());
      assert(g(SM::e()));
      if (l == this->upper_bound()) return l;
      l -= this->m_offset;

      if constexpr (has_lazy<FM>) {
        this->make_mutable();
      }
      return this->m_offset + std::min(tools::fix([&](auto&& dfs, const S& c, const int k, const long long kl, const long long kr) -> std::pair<S, long long> {
        assert(kl < kr);
        if (kl < l) {
          assert(kl < l && l < kr);
          if constexpr (has_lazy<FM>) {
            this->make_mutable(k, 0);
            this->make_mutable(k, 1);
            this->push(k);
          }
          const auto km = std::midpoint(kl, kr);
          if (l < km) {
            const auto [hc, hr] = dfs(c, this->m_nodes[k].children[0], kl, km);
            assert(l <= hr && hr <= km);
            if (hr < km) return {hc, hr};
            return dfs(hc, this->m_nodes[k].children[1], km, kr);
          } else {
            return dfs(c, this->m_nodes[k].children[1], km, kr);
          }
        } else {
          if (const auto wc = SM::op(c, this->m_nodes[k].data); g(wc)) return {wc, kr};
          if (kr - kl == 1) return {c, kl};
          if constexpr (has_lazy<FM>) {
            this->make_mutable(k, 0);
            this->make_mutable(k, 1);
            this->push(k);
          }
          const auto km = std::midpoint(kl, kr);
          const auto [hc, hr] = dfs(c, this->m_nodes[k].children[0], kl, km);
          assert(l <= hr && hr <= km);
          if (hr < km) return {hc, hr};
          return dfs(hc, this->m_nodes[k].children[1], km, kr);
        }
      })(SM::e(), this->m_root, 0, this->capacity()).second, this->m_size);
    }
    template <typename G, typename SFINAE = SM> requires (has_data<SFINAE>)
    long long min_left(long long r, const G& g) {
      assert(this->lower_bound() <= r && r <= this->upper_bound());
      assert(g(SM::e()));
      if (r == this->lower_bound()) return r;
      r -= this->m_offset;

      if constexpr (has_lazy<FM>) {
        this->make_mutable();
      }
      return this->m_offset + tools::fix([&](auto&& dfs, const S& c, const int k, const long long kl, const long long kr) -> std::pair<S, long long> {
        assert(kl < kr);
        if (r < kr) {
          assert(kl < r && r < kr);
          if constexpr (has_lazy<FM>) {
            this->make_mutable(k, 0);
            this->make_mutable(k, 1);
            this->push(k);
          }
          const auto km = std::midpoint(kl, kr);
          if (km < r) {
            const auto [hc, hl] = dfs(c, this->m_nodes[k].children[1], km, kr);
            assert(km <= hl && hl <= r);
            if (km < hl) return {hc, hl};
            return dfs(hc, this->m_nodes[k].children[0], kl, km);
          } else {
            return dfs(c, this->m_nodes[k].children[0], kl, km);
          }
        } else {
          if (const auto wc = SM::op(this->m_nodes[k].data, c); g(wc)) return {wc, kl};
          if (kr - kl == 1) return {c, kr};
          if constexpr (has_lazy<FM>) {
            this->make_mutable(k, 0);
            this->make_mutable(k, 1);
            this->push(k);
          }
          const auto km = std::midpoint(kl, kr);
          const auto [hc, hl] = dfs(c, this->m_nodes[k].children[1], km, kr);
          assert(km <= hl && hl <= r);
          if (km < hl) return {hc, hl};
          return dfs(hc, this->m_nodes[k].children[0], kl, km);
        }
      })(SM::e(), this->m_root, 0, this->capacity()).second;
    }
  };
}

#endif
