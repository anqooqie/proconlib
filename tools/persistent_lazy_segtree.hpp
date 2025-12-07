#ifndef TOOLS_PERSISTENT_LAZY_SEGTREE_HPP
#define TOOLS_PERSISTENT_LAZY_SEGTREE_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <numeric>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/ceil_log2.hpp"
#include "tools/fix.hpp"

namespace tools {
  template <typename SM, typename FM, auto mapping>
  class persistent_lazy_segtree {
    using S = typename SM::T;
    using F = typename FM::T;
    static_assert(
      std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
      "mapping must work as S(F, S)");

    struct node {
      S data;
      F lazy;
      std::array<int, 2> children;
    };

  public:
    class buffer {
      std::vector<tools::persistent_lazy_segtree<SM, FM, mapping>::node> m_nodes;
      long long m_offset;
      long long m_size;
      int m_height;

    public:
      friend tools::persistent_lazy_segtree<SM, FM, mapping>;
    };

  private:
    tools::persistent_lazy_segtree<SM, FM, mapping>::buffer *m_buffer;
    int m_root;

    long long capacity() const {
      return 1LL << this->m_buffer->m_height;
    }

  public:
    persistent_lazy_segtree() = default;
    persistent_lazy_segtree(tools::persistent_lazy_segtree<SM, FM, mapping>::buffer& buffer, const long long l_star, const long long r_star) :
      persistent_lazy_segtree(buffer, l_star, r_star, SM::e()) {
    }
    persistent_lazy_segtree(tools::persistent_lazy_segtree<SM, FM, mapping>::buffer& buffer, const long long l_star, const long long r_star, const S& x) : m_buffer(&buffer) {
      assert(buffer.m_nodes.empty());
      assert(l_star <= r_star);
      buffer.m_offset = l_star;
      buffer.m_size = r_star - l_star;
      buffer.m_height = tools::ceil_log2(std::max(1LL, r_star - l_star));
      buffer.m_nodes.push_back({x, FM::e(), {-1, -1}});
      for (int k = 1; k <= buffer.m_height; ++k) {
        buffer.m_nodes.push_back({SM::op(buffer.m_nodes.back().data, buffer.m_nodes.back().data), FM::e(), {k - 1, k - 1}});
      }
      this->m_root = buffer.m_height;
    }
    template <std::ranges::range R>
    persistent_lazy_segtree(tools::persistent_lazy_segtree<SM, FM, mapping>::buffer& buffer, R&& v) : m_buffer(&buffer) {
      assert(buffer.m_nodes.empty());
      for (auto&& x : v) {
        buffer.m_nodes.push_back({x, FM::e(), {-1, -1}});
      }
      buffer.m_offset = 0;
      buffer.m_size = buffer.m_nodes.size();
      buffer.m_height = tools::ceil_log2(std::max(1LL, buffer.m_size));
      buffer.m_nodes.push_back({SM::e(), FM::e(), {-1, -1}});
      for (int h = 1; h <= buffer.m_height; ++h) {
        buffer.m_nodes.push_back({SM::e(), FM::e(), {static_cast<int>(buffer.m_nodes.size()) - 1, static_cast<int>(buffer.m_nodes.size()) - 1}});
      }
      this->m_root = tools::fix([&](auto&& dfs, const int h, const long long kl, const long long kr) -> int {
        assert(kl < kr);
        if (buffer.m_size <= kl) return buffer.m_size + h;
        if (h == 0) return kl;
        const auto km = std::midpoint(kl, kr);
        const auto left_child = dfs(h - 1, kl, km);
        const auto right_child = dfs(h - 1, km, kr);
        buffer.m_nodes.push_back({SM::op(buffer.m_nodes[left_child].data, buffer.m_nodes[right_child].data), FM::e(), {left_child, right_child}});
        return buffer.m_nodes.size() - 1;
      })(buffer.m_height, 0, this->capacity());
    }

    long long lower_bound() const {
      return this->m_buffer->m_offset;
    }
    long long upper_bound() const {
      return this->m_buffer->m_offset + this->m_buffer->m_size;
    }
    tools::persistent_lazy_segtree<SM, FM, mapping> set(long long p, const S& x) const {
      assert(this->lower_bound() <= p && p < this->upper_bound());
      auto& buffer = *this->m_buffer;
      p -= buffer.m_offset;

      auto res = *this;
      res.m_root = tools::fix([&](auto&& dfs, const int k, const long long kl, const long long kr, const F& lz) -> int {
        assert(kl < kr);
        if (p <= kl && kr <= p + 1) {
          buffer.m_nodes.push_back({x, FM::e(), buffer.m_nodes[k].children});
          return buffer.m_nodes.size() - 1;
        }
        if (kr <= p || p + 1 <= kl) {
          if (lz == FM::e()) return k;
          buffer.m_nodes.push_back({mapping(lz, buffer.m_nodes[k].data), FM::op(lz, buffer.m_nodes[k].lazy), buffer.m_nodes[k].children});
          return buffer.m_nodes.size() - 1;
        }
        const auto km = std::midpoint(kl, kr);
        const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
        const auto left_child = dfs(buffer.m_nodes[k].children[0], kl, km, next_lz);
        const auto right_child = dfs(buffer.m_nodes[k].children[1], km, kr, next_lz);
        buffer.m_nodes.push_back({SM::op(buffer.m_nodes[left_child].data, buffer.m_nodes[right_child].data), FM::e(), {left_child, right_child}});
        return buffer.m_nodes.size() - 1;
      })(res.m_root, 0, res.capacity(), FM::e());
      return res;
    }
    S get(const long long p) const {
      return this->prod(p, p + 1);
    }
    S prod(long long l, long long r) const {
      assert(this->lower_bound() <= l && l <= r && r <= this->upper_bound());
      if (l == r) return SM::e();
      auto& buffer = *this->m_buffer;
      l -= buffer.m_offset;
      r -= buffer.m_offset;

      return tools::fix([&](auto&& dfs, const int k, const long long kl, const long long kr, const F& lz) -> S {
        assert(kl < kr);
        if (l <= kl && kr <= r) return mapping(lz, buffer.m_nodes[k].data);
        const auto km = std::midpoint(kl, kr);
        const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
        S res = SM::e();
        if (l < km) res = SM::op(res, dfs(buffer.m_nodes[k].children[0], kl, km, next_lz));
        if (km < r) res = SM::op(res, dfs(buffer.m_nodes[k].children[1], km, kr, next_lz));
        return res;
      })(this->m_root, 0, this->capacity(), FM::e());
    }
    S all_prod() const {
      return this->m_buffer->m_nodes[this->m_root].data;
    }
    tools::persistent_lazy_segtree<SM, FM, mapping> apply(const long long p, const F& f) const {
      return this->apply(p, p + 1, f);
    }
    tools::persistent_lazy_segtree<SM, FM, mapping> apply(long long l, long long r, const F& f) const {
      assert(this->lower_bound() <= l && l <= r && r <= this->upper_bound());
      if (l == r) return *this;
      auto& buffer = *this->m_buffer;
      l -= buffer.m_offset;
      r -= buffer.m_offset;

      auto res = *this;
      res.m_root = tools::fix([&](auto&& dfs, const int k, const long long kl, const long long kr, const F& lz) -> int {
        assert(kl < kr);
        if (l <= kl && kr <= r) {
          const F modified_lz = FM::op(f, lz);
          buffer.m_nodes.push_back({mapping(modified_lz, buffer.m_nodes[k].data), FM::op(modified_lz, buffer.m_nodes[k].lazy), buffer.m_nodes[k].children});
          return buffer.m_nodes.size() - 1;
        }
        if (kr <= l || r <= kl) {
          if (lz == FM::e()) return k;
          buffer.m_nodes.push_back({mapping(lz, buffer.m_nodes[k].data), FM::op(lz, buffer.m_nodes[k].lazy), buffer.m_nodes[k].children});
          return buffer.m_nodes.size() - 1;
        }
        const auto km = std::midpoint(kl, kr);
        const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
        const auto left_child = dfs(buffer.m_nodes[k].children[0], kl, km, next_lz);
        const auto right_child = dfs(buffer.m_nodes[k].children[1], km, kr, next_lz);
        buffer.m_nodes.push_back({SM::op(buffer.m_nodes[left_child].data, buffer.m_nodes[right_child].data), FM::e(), {left_child, right_child}});
        return buffer.m_nodes.size() - 1;
      })(res.m_root, 0, res.capacity(), FM::e());
      return res;
    }
    tools::persistent_lazy_segtree<SM, FM, mapping> rollback(const tools::persistent_lazy_segtree<SM, FM, mapping>& s, long long l, long long r) const {
      assert(this->m_buffer == s.m_buffer);
      assert(this->lower_bound() <= l && l <= r && r <= this->upper_bound());
      if (l == r) return *this;
      if (l == this->lower_bound() && r == this->upper_bound()) return s;
      auto& buffer = *this->m_buffer;
      l -= buffer.m_offset;
      r -= buffer.m_offset;

      auto res = *this;
      res.m_root = tools::fix([&](auto&& dfs, const int k1, const int k2, const long long kl, const long long kr, const F& lz1, const F& lz2) -> int {
        assert(kl < kr);
        if (l <= kl && kr <= r) {
          if (lz2 == FM::e()) return k2;
          buffer.m_nodes.push_back({mapping(lz2, buffer.m_nodes[k2].data), FM::op(lz2, buffer.m_nodes[k2].lazy), buffer.m_nodes[k2].children});
          return buffer.m_nodes.size() - 1;
        }
        if (kr <= l || r <= kl) {
          if (lz1 == FM::e()) return k1;
          buffer.m_nodes.push_back({mapping(lz1, buffer.m_nodes[k1].data), FM::op(lz1, buffer.m_nodes[k1].lazy), buffer.m_nodes[k1].children});
          return buffer.m_nodes.size() - 1;
        }
        const auto km = std::midpoint(kl, kr);
        const F next_lz1 = FM::op(lz1, buffer.m_nodes[k1].lazy);
        const F next_lz2 = FM::op(lz2, buffer.m_nodes[k2].lazy);
        const auto left_child = dfs(buffer.m_nodes[k1].children[0], buffer.m_nodes[k2].children[0], kl, km, next_lz1, next_lz2);
        const auto right_child = dfs(buffer.m_nodes[k1].children[1], buffer.m_nodes[k2].children[1], km, kr, next_lz1, next_lz2);
        buffer.m_nodes.push_back({SM::op(buffer.m_nodes[left_child].data, buffer.m_nodes[right_child].data), FM::e(), {left_child, right_child}});
        return buffer.m_nodes.size() - 1;
      })(res.m_root, s.m_root, 0, res.capacity(), FM::e(), FM::e());
      return res;
    }
    template <typename G>
    long long max_right(long long l, const G& g) const {
      assert(this->lower_bound() <= l && l <= this->upper_bound());
      assert(g(SM::e()));
      if (l == this->upper_bound()) return l;
      auto& buffer = *this->m_buffer;
      l -= buffer.m_offset;

      return buffer.m_offset + std::min(tools::fix([&](auto&& dfs, const S& c, const int k, const long long kl, const long long kr, const F& lz) -> std::pair<S, long long> {
        assert(kl < kr);
        if (kl < l) {
          assert(kl < l && l < kr);
          const auto km = std::midpoint(kl, kr);
          const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
          if (l < km) {
            const auto [hc, hr] = dfs(c, buffer.m_nodes[k].children[0], kl, km, next_lz);
            assert(l <= hr && hr <= km);
            if (hr < km) return {hc, hr};
            return dfs(hc, buffer.m_nodes[k].children[1], km, kr, next_lz);
          } else {
            return dfs(c, buffer.m_nodes[k].children[1], km, kr, next_lz);
          }
        } else {
          if (const auto wc = SM::op(c, mapping(lz, buffer.m_nodes[k].data)); g(wc)) return {wc, kr};
          if (kr - kl == 1) return {c, kl};
          const auto km = std::midpoint(kl, kr);
          const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
          const auto [hc, hr] = dfs(c, buffer.m_nodes[k].children[0], kl, km, next_lz);
          assert(l <= hr && hr <= km);
          if (hr < km) return {hc, hr};
          return dfs(hc, buffer.m_nodes[k].children[1], km, kr, next_lz);
        }
      })(SM::e(), this->m_root, 0, this->capacity(), FM::e()).second, buffer.m_size);
    }
    template <typename G>
    long long min_left(long long r, const G& g) const {
      assert(this->lower_bound() <= r && r <= this->upper_bound());
      assert(g(SM::e()));
      if (r == this->lower_bound()) return r;
      auto& buffer = *this->m_buffer;
      r -= buffer.m_offset;

      return buffer.m_offset + tools::fix([&](auto&& dfs, const S& c, const int k, const long long kl, const long long kr, const F& lz) -> std::pair<S, long long> {
        assert(kl < kr);
        if (r < kr) {
          assert(kl < r && r < kr);
          const auto km = std::midpoint(kl, kr);
          const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
          if (km < r) {
            const auto [hc, hl] = dfs(c, buffer.m_nodes[k].children[1], km, kr, next_lz);
            assert(km <= hl && hl <= r);
            if (km < hl) return {hc, hl};
            return dfs(hc, buffer.m_nodes[k].children[0], kl, km, next_lz);
          } else {
            return dfs(c, buffer.m_nodes[k].children[0], kl, km, next_lz);
          }
        } else {
          if (const auto wc = SM::op(mapping(lz, buffer.m_nodes[k].data), c); g(wc)) return {wc, kl};
          if (kr - kl == 1) return {c, kr};
          const auto km = std::midpoint(kl, kr);
          const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
          const auto [hc, hl] = dfs(c, buffer.m_nodes[k].children[1], km, kr, next_lz);
          assert(km <= hl && hl <= r);
          if (km < hl) return {hc, hl};
          return dfs(hc, buffer.m_nodes[k].children[0], kl, km, next_lz);
        }
      })(SM::e(), this->m_root, 0, this->capacity(), FM::e()).second;
    }
  };
}

#endif
