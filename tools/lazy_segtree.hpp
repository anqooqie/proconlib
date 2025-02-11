#ifndef TOOLS_LAZY_SEGTREE_HPP
#define TOOLS_LAZY_SEGTREE_HPP

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
  class lazy_segtree {
    using S = typename SM::T;
    using F = typename FM::T;
    static_assert(
      ::std::is_convertible_v<decltype(mapping), ::std::function<S(F, S)>>,
      "mapping must work as S(F, S)");

    int m_height;
    int m_size;
    ::std::vector<S> m_data;
    ::std::vector<F> m_lazy;

    int capacity() const {
      return 1 << this->m_height;
    }
    void push(const int k) {
      assert(0 < k && k < this->capacity());
      this->all_apply(2 * k, this->m_lazy[k]);
      this->all_apply(2 * k + 1, this->m_lazy[k]);
      this->m_lazy[k] = FM::e();
    }
    void all_apply(const int k, const F& f) {
      assert(0 < k && k < 2 * this->capacity());
      this->m_data[k] = mapping(f, this->m_data[k]);
      if (k < this->capacity()) this->m_lazy[k] = FM::op(f, this->m_lazy[k]);
    }
    void update(const int k) {
      assert(0 < k && this->capacity());
      this->m_data[k] = SM::op(this->m_data[2 * k], this->m_data[2 * k + 1]);
    }

  public:
    lazy_segtree() = default;
    explicit lazy_segtree(const int n) : lazy_segtree(::std::vector<S>(n, SM::e())) {
    }
    template <::std::ranges::range R>
    explicit lazy_segtree(R&& r) : m_data(::std::ranges::begin(r), ::std::ranges::end(r)) {
      this->m_size = this->m_data.size();
      this->m_height = ::tools::ceil_log2(::std::max(1, this->m_size));
      this->m_data.reserve(2 * this->capacity());
      this->m_data.insert(this->m_data.begin(), this->capacity(), SM::e());
      this->m_data.resize(2 * this->capacity(), SM::e());
      for (auto k = this->capacity() - 1; k > 0; --k) this->update(k);
      this->m_lazy.assign(this->capacity(), FM::e());
    }

    int size() const {
      return this->m_size;
    }
    void set(const int p, const S& x) {
      assert(0 <= p && p < this->m_size);
      for (auto h = this->m_height; h > 0; --h) this->push((this->capacity() + p) >> h);
      this->m_data[this->capacity() + p] = x;
      for (auto h = 1; h <= this->m_height; ++h) this->update((this->capacity() + p) >> h);
    }
    S get(const int p) {
      return this->prod(p, p + 1);
    }
    S prod(const int l, const int r) {
      assert(0 <= l && l <= r && r <= this->m_size);
      if (l == r) return SM::e();
      return ::tools::fix([&](auto&& dfs, const int k, const int kl, const int kr) -> S {
        assert(kl < kr);
        if (l <= kl && kr <= r) return this->m_data[k];
        this->push(k);
        const auto km = ::std::midpoint(kl, kr);
        S res = SM::e();
        if (l < km) res = SM::op(res, dfs(k << 1, kl, km));
        if (km < r) res = SM::op(res, dfs((k << 1) + 1, km, kr));
        return res;
      })(1, 0, this->capacity());
    }
    S all_prod() {
      return this->prod(0, this->m_size);
    }
    void apply(const int p, const F& f) {
      this->apply(p, p + 1, f);
    }
    void apply(const int l, const int r, const F& f) {
      assert(0 <= l && l <= r && r <= this->m_size);
      if (l == r) return;
      ::tools::fix([&](auto&& dfs, const int k, const int kl, const int kr) -> void {
        assert(kl < kr);
        if (l <= kl && kr <= r) {
          this->all_apply(k, f);
          return;
        }
        this->push(k);
        const auto km = ::std::midpoint(kl, kr);
        if (l < km) dfs(k << 1, kl, km);
        if (km < r) dfs((k << 1) + 1, km, kr);
        this->update(k);
      })(1, 0, this->capacity());
    }
    template <typename G>
    int max_right(const int l, const G& g) {
      assert(0 <= l && l <= this->m_size);
      assert(g(SM::e()));
      if (l == this->m_size) return l;
      return ::std::min(::tools::fix([&](auto&& dfs, const S& c, const int k, const int kl, const int kr) -> ::std::pair<S, int> {
        assert(kl < kr);
        if (kl < l) {
          assert(kl < l && l < kr);
          this->push(k);
          const auto km = ::std::midpoint(kl, kr);
          if (l < km) {
            const auto [hc, hr] = dfs(c, k << 1, kl, km);
            assert(l <= hr && hr <= km);
            if (hr < km) return {hc, hr};
            return dfs(hc, (k << 1) + 1, km, kr);
          } else {
            return dfs(c, (k << 1) + 1, km, kr);
          }
        } else {
          if (const auto wc = SM::op(c, this->m_data[k]); g(wc)) return {wc, kr};
          if (kr - kl == 1) return {c, kl};
          this->push(k);
          const auto km = ::std::midpoint(kl, kr);
          const auto [hc, hr] = dfs(c, k << 1, kl, km);
          assert(l <= hr && hr <= km);
          if (hr < km) return {hc, hr};
          return dfs(hc, (k << 1) + 1, km, kr);
        }
      })(SM::e(), 1, 0, this->capacity()).second, this->m_size);
    }
    template <typename G>
    int min_left(const int r, const G& g) {
      assert(0 <= r && r <= this->m_size);
      assert(g(SM::e()));
      if (r == 0) return r;
      return ::tools::fix([&](auto&& dfs, const S& c, const int k, const int kl, const int kr) -> ::std::pair<S, int> {
        assert(kl < kr);
        if (r < kr) {
          assert(kl < r && r < kr);
          this->push(k);
          const auto km = ::std::midpoint(kl, kr);
          if (km < r) {
            const auto [hc, hl] = dfs(c, (k << 1) + 1, km, kr);
            assert(km <= hl && hl <= r);
            if (km < hl) return {hc, hl};
            return dfs(hc, k << 1, kl, km);
          } else {
            return dfs(c, k << 1, kl, km);
          }
        } else {
          if (const auto wc = SM::op(this->m_data[k], c); g(wc)) return {wc, kl};
          if (kr - kl == 1) return {c, kr};
          this->push(k);
          const auto km = ::std::midpoint(kl, kr);
          const auto [hc, hl] = dfs(c, (k << 1) + 1, km, kr);
          assert(km <= hl && hl <= r);
          if (km < hl) return {hc, hl};
          return dfs(hc, k << 1, kl, km);
        }
      })(SM::e(), 1, 0, this->capacity()).second;
    }
  };
}

#endif
