#ifndef TOOLS_PRESET_WAVELET_MATRIX_HPP
#define TOOLS_PRESET_WAVELET_MATRIX_HPP

#include <cassert>
#include <optional>
#include <ranges>
#include <tuple>
#include <type_traits>
#include <vector>
#include "atcoder/segtree.hpp"
#include "tools/commutative_group.hpp"
#include "tools/groups.hpp"
#include "tools/wavelet_matrix.hpp"

namespace tools {
  template <typename T, typename X, bool Updatable>
  class preset_wavelet_matrix {
    using G = ::std::conditional_t<::tools::commutative_group<X>, X, ::tools::groups::plus<X>>;
    using U = typename G::T;

    ::tools::wavelet_matrix<T> m_wm;
    ::std::vector<U> m_ws;
    ::std::vector<::std::conditional_t<Updatable, ::atcoder::segtree<U, G::op, G::e>, ::std::vector<U>>> m_aux;

    bool built() const {
      return !this->m_aux.empty();
    }

  public:
    preset_wavelet_matrix() = default;

    int size() const {
      return this->m_wm.size();
    }

    int add_point(const T& x, const T& y, const U& w) {
      assert(!this->built());

      this->m_ws.push_back(w);
      return this->m_wm.add_point(x, y);
    }

    ::std::tuple<T, T, U> get_point(const int i) const {
      assert(0 <= i && i < this->size());

      const auto [x, y] = this->m_wm.get_point(i);
      return {x, y, this->m_ws[i]};
    }

    ::std::vector<::std::tuple<T, T, U>> points() const {
      ::std::vector<::std::tuple<T, T, U>> res;
      res.reserve(this->size());
      for (int i = 0; i < this->size(); ++i) {
        res.push_back(this->get_point(i));
      }
      return res;
    }

    void build() {
      assert(!this->built());

      for (const auto& A_h : this->m_wm.build()) {
        if constexpr (Updatable) {
          ::std::vector<U> v(this->size());
          for (int j = 0; j < this->size(); ++j) {
            v[j] = this->m_ws[A_h[j]];
          }
          this->m_aux.emplace_back(v);
        } else {
          this->m_aux.emplace_back();
          this->m_aux.back().reserve(this->size() + 1);
          this->m_aux.back().push_back(G::e());
          for (int j = 0; j < this->size(); ++j) {
            this->m_aux.back().push_back(G::op(this->m_aux.back().back(), this->m_ws[A_h[j]]));
          }
        }
      }
    }

    template <bool SFINAE = Updatable> requires (SFINAE)
    void set_weight(const int i, const U& w) {
      assert(0 <= i && i < this->size());

      this->m_ws[i] = w;
      if (this->built()) {
        for (const auto& [h, j] : this->m_wm.apply(i)) {
          this->m_aux[h].set(j, w);
        }
      }
    }

    int kth_smallest(const T& l, const T& r, const int k) const {
      assert(this->built());
      assert(l <= r);
      assert(k >= 0);

      return this->m_wm.kth_smallest(l, r, k);
    }

    int kth_largest(const T& l, const T& r, const int k) const {
      assert(this->built());
      assert(l <= r);
      assert(k >= 0);

      return this->m_wm.kth_largest(l, r, k);
    }

    U range_sum(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      U res = G::e();
      for (const auto& [h, jl, jr] : this->m_wm.range_prod(l, r, u)) {
        if constexpr (Updatable) {
          res = G::op(res, this->m_aux[h].prod(jl, jr));
        } else {
          res = G::op(res, G::op(G::inv(this->m_aux[h][jl]), this->m_aux[h][jr]));
        }
      }

      return res;
    }

    U range_sum(const T& l, const T& r, const T& d, const T& u) const {
      assert(this->built());
      assert(l <= r);
      assert(d <= u);

      return G::op(this->range_sum(l, r, u), G::inv(this->range_sum(l, r, d)));
    }

    int range_freq(const T& l, const T& r) const {
      assert(this->built());
      assert(l <= r);

      return this->m_wm.range_freq(l, r);
    }

    int range_freq(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      return this->m_wm.range_freq(l, r, u);
    }

    int range_freq(const T& l, const T& r, const T& d, const T& u) const {
      assert(this->built());
      assert(l <= r);
      assert(d <= u);

      return this->m_wm.range_freq(l, r, d, u);
    }

    ::std::optional<T> prev_value(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      return this->m_wm.prev_value(l, r, u);
    }

    ::std::optional<T> next_value(const T& l, const T& r, const T& d) const {
      assert(this->built());
      assert(l <= r);

      return this->m_wm.next_value(l, r, d);
    }

    ::std::ranges::subrange<::std::vector<int>::const_iterator> prev_points(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      return this->m_wm.prev_points(l, r, u);
    }

    ::std::ranges::subrange<::std::vector<int>::const_iterator> next_points(const T& l, const T& r, const T& d) const {
      assert(this->built());
      assert(l <= r);

      return this->m_wm.next_points(l, r, d);
    }
  };
}

#endif
