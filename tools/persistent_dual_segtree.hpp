#ifndef TOOLS_PERSISTENT_DUAL_SEGTREE_HPP
#define TOOLS_PERSISTENT_DUAL_SEGTREE_HPP

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
  template <typename FM>
  class persistent_dual_segtree {
    using F = typename FM::T;

    struct node {
      F lazy;
      ::std::array<int, 2> children;
    };

  public:
    class buffer {
      ::std::vector<::tools::persistent_dual_segtree<FM>::node> m_nodes;
      long long m_offset;
      long long m_size;
      int m_height;

    public:
      friend ::tools::persistent_dual_segtree<FM>;
    };

  private:
    ::tools::persistent_dual_segtree<FM>::buffer *m_buffer;
    int m_root;

    long long capacity() const {
      return 1LL << this->m_buffer->m_height;
    }

  public:
    persistent_dual_segtree() = default;
    persistent_dual_segtree(::tools::persistent_dual_segtree<FM>::buffer& buffer, const long long l_star, const long long r_star) : m_buffer(&buffer) {
      assert(buffer.m_nodes.empty());
      assert(l_star <= r_star);
      buffer.m_offset = l_star;
      buffer.m_size = r_star - l_star;
      buffer.m_height = ::tools::ceil_log2(::std::max(1LL, r_star - l_star));
      buffer.m_nodes.push_back({FM::e(), {-1, -1}});
      for (int k = 1; k <= buffer.m_height; ++k) {
        buffer.m_nodes.push_back({FM::e(), {k - 1, k - 1}});
      }
      this->m_root = buffer.m_height;
    }

    long long lower_bound() const {
      return this->m_buffer->m_offset;
    }
    long long upper_bound() const {
      return this->m_buffer->m_offset + this->m_buffer->m_size;
    }
    F get(long long p) const {
      assert(this->lower_bound() <= p && p < this->upper_bound());
      auto& buffer = *this->m_buffer;
      p -= buffer.m_offset;

      return ::tools::fix([&](auto&& dfs, const int k, const long long kl, const long long kr, const F& lz) -> F {
        assert(kl < kr);
        if (p <= kl && kr <= p + 1) return FM::op(lz, buffer.m_nodes[k].lazy);
        const auto km = ::std::midpoint(kl, kr);
        const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
        if (p < km) return dfs(buffer.m_nodes[k].children[0], kl, km, next_lz);
        else return dfs(buffer.m_nodes[k].children[1], km, kr, next_lz);
      })(this->m_root, 0, this->capacity(), FM::e());
    }
    ::tools::persistent_dual_segtree<FM> apply(const long long p, const F& f) const {
      return this->apply(p, p + 1, f);
    }
    ::tools::persistent_dual_segtree<FM> apply(long long l, long long r, const F& f) const {
      assert(this->lower_bound() <= l && l <= r && r <= this->upper_bound());
      if (l == r) return *this;
      auto& buffer = *this->m_buffer;
      l -= buffer.m_offset;
      r -= buffer.m_offset;

      auto res = *this;
      res.m_root = ::tools::fix([&](auto&& dfs, const int k, const long long kl, const long long kr, const F& lz) -> int {
        assert(kl < kr);
        if (l <= kl && kr <= r) {
          const F modified_lz = FM::op(f, lz);
          buffer.m_nodes.push_back({FM::op(modified_lz, buffer.m_nodes[k].lazy), buffer.m_nodes[k].children});
          return buffer.m_nodes.size() - 1;
        }
        if (kr <= l || r <= kl) {
          if (lz == FM::e()) return k;
          buffer.m_nodes.push_back({FM::op(lz, buffer.m_nodes[k].lazy), buffer.m_nodes[k].children});
          return buffer.m_nodes.size() - 1;
        }
        const auto km = ::std::midpoint(kl, kr);
        const F next_lz = FM::op(lz, buffer.m_nodes[k].lazy);
        const auto left_child = dfs(buffer.m_nodes[k].children[0], kl, km, next_lz);
        const auto right_child = dfs(buffer.m_nodes[k].children[1], km, kr, next_lz);
        buffer.m_nodes.push_back({FM::e(), {left_child, right_child}});
        return buffer.m_nodes.size() - 1;
      })(res.m_root, 0, res.capacity(), FM::e());
      return res;
    }
    ::tools::persistent_dual_segtree<FM> rollback(const ::tools::persistent_dual_segtree<FM>& s, long long l, long long r) const {
      assert(this->m_buffer == s.m_buffer);
      assert(this->lower_bound() <= l && l <= r && r <= this->upper_bound());
      if (l == r) return *this;
      if (l == this->lower_bound() && r == this->upper_bound()) return s;
      auto& buffer = *this->m_buffer;
      l -= buffer.m_offset;
      r -= buffer.m_offset;

      auto res = *this;
      res.m_root = ::tools::fix([&](auto&& dfs, const int k1, const int k2, const long long kl, const long long kr, const F& lz1, const F& lz2) -> int {
        assert(kl < kr);
        if (l <= kl && kr <= r) {
          if (lz2 == FM::e()) return k2;
          buffer.m_nodes.push_back({FM::op(lz2, buffer.m_nodes[k2].lazy), buffer.m_nodes[k2].children});
          return buffer.m_nodes.size() - 1;
        }
        if (kr <= l || r <= kl) {
          if (lz1 == FM::e()) return k1;
          buffer.m_nodes.push_back({FM::op(lz1, buffer.m_nodes[k1].lazy), buffer.m_nodes[k1].children});
          return buffer.m_nodes.size() - 1;
        }
        const auto km = ::std::midpoint(kl, kr);
        const F next_lz1 = FM::op(lz1, buffer.m_nodes[k1].lazy);
        const F next_lz2 = FM::op(lz2, buffer.m_nodes[k2].lazy);
        const auto left_child = dfs(buffer.m_nodes[k1].children[0], buffer.m_nodes[k2].children[0], kl, km, next_lz1, next_lz2);
        const auto right_child = dfs(buffer.m_nodes[k1].children[1], buffer.m_nodes[k2].children[1], km, kr, next_lz1, next_lz2);
        buffer.m_nodes.push_back({FM::e(), {left_child, right_child}});
        return buffer.m_nodes.size() - 1;
      })(res.m_root, s.m_root, 0, res.capacity(), FM::e(), FM::e());
      return res;
    }
  };
}

#endif
