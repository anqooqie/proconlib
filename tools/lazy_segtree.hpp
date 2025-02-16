#ifndef TOOLS_LAZY_SEGTREE_HPP
#define TOOLS_LAZY_SEGTREE_HPP

#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>
#include <ranges>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#include "tools/ceil_log2.hpp"
#include "tools/fix.hpp"

namespace tools {
  namespace detail {
    namespace lazy_segtree {
      struct nop_monoid {
        using T = ::std::monostate;
        static T op(T, T) {
          return {};
        }
        static T e() {
          return {};
        }
      };
      template <typename F, typename S>
      S nop_mapping(F, const S& e) {
        return e;
      }
    }
  }

  template <typename SM, typename FM, auto mapping>
  class lazy_segtree {
    using S = typename SM::T;
    using F = typename FM::T;
    static_assert(
      ::std::is_convertible_v<decltype(mapping), ::std::function<S(F, S)>>,
      "mapping must work as S(F, S)");

    template <typename T>
    static constexpr bool has_data = !::std::is_same_v<T, ::tools::detail::lazy_segtree::nop_monoid>;
    template <typename T>
    static constexpr bool has_lazy = !::std::is_same_v<T, ::tools::detail::lazy_segtree::nop_monoid>;

    int m_size;
    int m_height;
    ::std::vector<S> m_data;
    ::std::vector<F> m_lazy;

    int capacity() const {
      return 1 << this->m_height;
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
    void push(const int k) {
      assert(0 < k && k < this->capacity());
      this->all_apply(2 * k, this->m_lazy[k]);
      this->all_apply(2 * k + 1, this->m_lazy[k]);
      this->m_lazy[k] = FM::e();
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
    void all_apply(const int k, const F& f) {
      assert(0 < k && k < 2 * this->capacity());
      if constexpr (has_data<SM>) {
        this->m_data[k] = mapping(f, this->m_data[k]);
        if (k < this->capacity()) this->m_lazy[k] = FM::op(f, this->m_lazy[k]);
      } else {
        this->m_lazy[k] = FM::op(f, this->m_lazy[k]);
      }
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    void update(const int k) {
      assert(0 < k && this->capacity());
      this->m_data[k] = SM::op(this->m_data[2 * k], this->m_data[2 * k + 1]);
    }

  public:
    lazy_segtree() = default;
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    explicit lazy_segtree(const int n) : lazy_segtree(::std::vector<S>(n, SM::e())) {
    }
    template <typename SFINAE = SM> requires (!has_data<SFINAE>)
    explicit lazy_segtree(const int n) : m_size(n), m_height(::tools::ceil_log2(::std::max(1, n))) {
      this->m_lazy.assign(2 * this->capacity(), FM::e());
    }
    template <::std::ranges::range R, typename SFINAE = SM> requires (has_data<SFINAE>)
    explicit lazy_segtree(R&& r) : m_data(::std::ranges::begin(r), ::std::ranges::end(r)) {
      this->m_size = this->m_data.size();
      this->m_height = ::tools::ceil_log2(::std::max(1, this->m_size));
      this->m_data.reserve(2 * this->capacity());
      this->m_data.insert(this->m_data.begin(), this->capacity(), SM::e());
      this->m_data.resize(2 * this->capacity(), SM::e());
      for (auto k = this->capacity() - 1; k > 0; --k) this->update(k);
      if constexpr (has_lazy<FM>) {
        this->m_lazy.assign(this->capacity(), FM::e());
      }
    }

    int size() const {
      return this->m_size;
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    void set(const int p, const S& x) {
      assert(0 <= p && p < this->m_size);
      ::tools::fix([&](auto&& dfs, const int h, const int k) -> void {
        if (h > 0) {
          if constexpr (has_lazy<FM>) {
            this->push(k);
          }
          dfs(h - 1, (this->capacity() + p) >> (h - 1));
          this->update(k);
        } else {
          this->m_data[this->capacity() + p] = x;
        }
      })(this->m_height, 1);
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    S get(const int p) {
      return this->prod(p, p + 1);
    }
    template <typename SFINAE = SM> requires (!has_data<SFINAE>)
    F get(const int p) {
      assert(0 <= p && p < this->m_size);
      return ::tools::fix([&](auto&& dfs, const int h, const int k) -> F {
        if (h > 0) {
          this->push(k);
          return dfs(h - 1, (this->capacity() + p) >> (h - 1));
        } else {
          return this->m_lazy[this->capacity() + p];
        }
      })(this->m_height, 1);
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    S prod(const int l, const int r) {
      assert(0 <= l && l <= r && r <= this->m_size);
      if (l == r) return SM::e();
      return ::tools::fix([&](auto&& dfs, const int k, const int kl, const int kr) -> S {
        assert(kl < kr);
        if (l <= kl && kr <= r) return this->m_data[k];
        if constexpr (has_lazy<FM>) {
          this->push(k);
        }
        const auto km = ::std::midpoint(kl, kr);
        S res = SM::e();
        if (l < km) res = SM::op(res, dfs(k << 1, kl, km));
        if (km < r) res = SM::op(res, dfs((k << 1) + 1, km, kr));
        return res;
      })(1, 0, this->capacity());
    }
    template <typename SFINAE = SM> requires (has_data<SFINAE>)
    S all_prod() {
      return this->prod(0, this->m_size);
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
    void apply(const int p, const F& f) {
      this->apply(p, p + 1, f);
    }
    template <typename SFINAE = FM> requires (has_lazy<SFINAE>)
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
        if constexpr (has_data<SM>) {
          this->update(k);
        }
      })(1, 0, this->capacity());
    }
    template <typename G, typename SFINAE = SM> requires (has_data<SFINAE>)
    int max_right(const int l, const G& g) {
      assert(0 <= l && l <= this->m_size);
      assert(g(SM::e()));
      if (l == this->m_size) return l;
      return ::std::min(::tools::fix([&](auto&& dfs, const S& c, const int k, const int kl, const int kr) -> ::std::pair<S, int> {
        assert(kl < kr);
        if (kl < l) {
          assert(kl < l && l < kr);
          if constexpr (has_lazy<FM>) {
            this->push(k);
          }
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
          if constexpr (has_lazy<FM>) {
            this->push(k);
          }
          const auto km = ::std::midpoint(kl, kr);
          const auto [hc, hr] = dfs(c, k << 1, kl, km);
          assert(l <= hr && hr <= km);
          if (hr < km) return {hc, hr};
          return dfs(hc, (k << 1) + 1, km, kr);
        }
      })(SM::e(), 1, 0, this->capacity()).second, this->m_size);
    }
    template <typename G, typename SFINAE = SM> requires (has_data<SFINAE>)
    int min_left(const int r, const G& g) {
      assert(0 <= r && r <= this->m_size);
      assert(g(SM::e()));
      if (r == 0) return r;
      return ::tools::fix([&](auto&& dfs, const S& c, const int k, const int kl, const int kr) -> ::std::pair<S, int> {
        assert(kl < kr);
        if (r < kr) {
          assert(kl < r && r < kr);
          if constexpr (has_lazy<FM>) {
            this->push(k);
          }
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
          if constexpr (has_lazy<FM>) {
            this->push(k);
          }
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
