#ifndef TOOLS_WAVELET_MATRIX_HPP
#define TOOLS_WAVELET_MATRIX_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <iterator>
#include <optional>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/bit_vector.hpp"
#include "tools/floor_log2.hpp"
#include "tools/less_by_first.hpp"
#include "tools/lower_bound.hpp"

namespace tools {
  template <typename T>
  class wavelet_matrix {
    ::std::vector<::std::pair<T, T>> m_ps;
    ::std::vector<::std::pair<T, int>> m_xs;
    ::std::vector<T> m_ys;
    ::std::vector<int> m_is;
    ::std::vector<::tools::bit_vector> m_bvs;

    int iid(const int i) const {
      return ::tools::lower_bound(this->m_xs.begin(), this->m_xs.end(), ::std::make_pair(this->m_ps[i].first, i));
    }
    int xid(const T& x) const {
      return ::tools::lower_bound(this->m_xs.begin(), this->m_xs.end(), ::std::make_pair(x, 0), ::tools::less_by_first());
    }
    int yid(const T& y) const {
      return ::tools::lower_bound(this->m_ys.begin(), this->m_ys.end(), y);
    }
    int lg() const {
      return this->m_bvs.size();
    }
    bool built() const {
      return this->lg() > 0;
    }

  public:
    wavelet_matrix() = default;

    int size() const {
      return this->m_ps.size();
    }

    int add_point(const T& x, const T& y) {
      assert(!this->built());
      this->m_ps.emplace_back(x, y);
      return this->size() - 1;
    }

    ::std::pair<T, T> get_point(const int i) const {
      assert(0 <= i && i < this->size());
      return this->m_ps[i];
    }

    const ::std::vector<::std::pair<T, T>>& points() const {
      return this->m_ps;
    }

    ::std::vector<::std::vector<int>> build() {
      assert(!this->built());

      this->m_xs.reserve(this->size());
      for (int i = 0; i < this->size(); ++i) {
        this->m_xs.emplace_back(this->m_ps[i].first, i);
      }
      ::std::ranges::sort(this->m_xs);

      this->m_ys.reserve(this->size());
      ::std::ranges::transform(this->m_ps, ::std::back_inserter(this->m_ys), [](const auto& p) { return p.second; });
      ::std::ranges::sort(this->m_ys);
      this->m_ys.erase(::std::unique(this->m_ys.begin(), this->m_ys.end()), this->m_ys.end());

      const auto n = ::std::max(this->size(), 1);
      this->m_bvs.assign(::tools::floor_log2(::std::max<int>(this->m_ys.size(), 1)) + 1, ::tools::bit_vector(n));

      ::std::vector<int> cur;
      cur.reserve(n);
      ::std::ranges::transform(this->m_xs, ::std::back_inserter(cur), [&](const auto& p) { return this->yid(this->m_ps[p.second].second); });
      cur.resize(n);
      ::std::vector<int> nxt(n);

      auto res = ::std::vector(this->lg() + 1, ::std::vector<int>(n));
      ::std::ranges::transform(this->m_xs, res.back().begin(), [&](const auto& p) { return p.second; });

      for (int h = this->lg(); h --> 0;) {
        for (int i = 0; i < n; ++i) {
          if ((cur[i] >> h) & 1) {
            this->m_bvs[h].set(i);
          }
        }
        this->m_bvs[h].build();
        ::std::array<int, 2> offsets = {0, static_cast<int>(this->m_bvs[h].zeros())};
        for (int i = 0; i < n; ++i) {
          auto& offset = offsets[this->m_bvs[h].get(i)];
          nxt[offset] = cur[i];
          res[h][offset] = res[h + 1][i];
          ++offset;
        }
        ::std::swap(cur, nxt);
      }

      this->m_is = res.front();
      res.pop_back();
      return res;
    }

    ::std::vector<::std::pair<int, int>> apply(int i) const {
      assert(this->built());
      assert(0 <= i && i < this->size());

      ::std::vector<::std::pair<int, int>> res(this->lg());
      i = this->iid(i);
      for (int h = this->lg(); h --> 0;) {
        i = this->m_bvs[h].get(i) ? this->m_bvs[h].zeros() + this->m_bvs[h].rank1(i) : this->m_bvs[h].rank0(i);
        res[h] = ::std::make_pair(h, i);
      }
      return res;
    }

    int kth_smallest(const T& l, const T& r, int k) const {
      assert(this->built());
      assert(l <= r);

      auto lid = this->xid(l);
      auto rid = this->xid(r);

      assert(0 <= k && k < rid - lid);

      for (int h = this->lg(); h --> 0;) {
        const auto l0 = this->m_bvs[h].rank0(lid);
        const auto r0 = this->m_bvs[h].rank0(rid);
        if (k < r0 - l0) {
          lid = l0;
          rid = r0;
        } else {
          k -= r0 - l0;
          lid += this->m_bvs[h].zeros() - l0;
          rid += this->m_bvs[h].zeros() - r0;
        }
      }

      return this->m_is[lid + k];
    }

    int kth_largest(const T& l, const T& r, int k) const {
      assert(this->built());
      assert(l <= r);

      const auto lid = this->xid(l);
      const auto rid = this->xid(r);

      assert(0 <= k && k < rid - lid);

      return this->kth_smallest(l, r, rid - lid - k - 1);
    }

    ::std::vector<::std::tuple<int, int, int>> range_prod(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      auto lid = this->xid(l);
      auto rid = this->xid(r);
      const auto uid = this->yid(u);

      ::std::vector<::std::tuple<int, int, int>> res(this->lg());
      for (int h = this->lg(); h --> 0;) {
        const auto l0 = this->m_bvs[h].rank0(lid);
        const auto r0 = this->m_bvs[h].rank0(rid);
        if ((uid >> h) & 1) {
          res[h] = ::std::make_tuple(h, l0, r0);
          lid += this->m_bvs[h].zeros() - l0;
          rid += this->m_bvs[h].zeros() - r0;
        } else {
          res[h] = ::std::make_tuple(h, 0, 0);
          lid = l0;
          rid = r0;
        }
      }
      return res;
    }

    int range_freq(const T& l, const T& r) const {
      assert(this->built());
      assert(l <= r);

      return this->xid(r) - this->xid(l);
    }

    int range_freq(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      auto lid = this->xid(l);
      auto rid = this->xid(r);
      const auto uid = this->yid(u);

      int res = 0;
      for (int h = this->lg(); h --> 0;) {
        const auto l0 = this->m_bvs[h].rank0(lid);
        const auto r0 = this->m_bvs[h].rank0(rid);
        if ((uid >> h) & 1) {
          res += r0 - l0;
          lid += this->m_bvs[h].zeros() - l0;
          rid += this->m_bvs[h].zeros() - r0;
        } else {
          lid = l0;
          rid = r0;
        }
      }
      return res;
    }

    int range_freq(const T& l, const T& r, const T& d, const T& u) const {
      assert(this->built());
      assert(l <= r);
      assert(d <= u);

      return this->range_freq(l, r, u) - this->range_freq(l, r, d);
    }

    ::std::optional<T> prev_value(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      const auto k = this->range_freq(l, r, u);
      return k == 0 ? ::std::nullopt : ::std::make_optional(this->m_ps[this->kth_smallest(l, r, k - 1)].second);
    }

    ::std::optional<T> next_value(const T& l, const T& r, const T& d) const {
      assert(this->built());
      assert(l <= r);

      const auto k = this->range_freq(l, r, d);
      return k == this->range_freq(l, r) ? ::std::nullopt : ::std::make_optional(this->m_ps[this->kth_smallest(l, r, k)].second);
    }

    ::std::ranges::subrange<::std::vector<int>::const_iterator> prev_points(const T& l, const T& r, const T& u) const {
      assert(this->built());
      assert(l <= r);

      auto lid = this->xid(l);
      auto rid = this->xid(r);
      auto k = this->range_freq(l, r, u);
      if (k == 0) return ::std::ranges::subrange(this->m_is.cend(), this->m_is.cend());
      --k;

      for (int h = this->lg(); h --> 0;) {
        const auto l0 = this->m_bvs[h].rank0(lid);
        const auto r0 = this->m_bvs[h].rank0(rid);
        if (k < r0 - l0) {
          lid = l0;
          rid = r0;
        } else {
          k -= r0 - l0;
          lid += this->m_bvs[h].zeros() - l0;
          rid += this->m_bvs[h].zeros() - r0;
        }
      }

      return ::std::ranges::subrange(this->m_is.cbegin() + lid, this->m_is.cbegin() + rid);
    }

    ::std::ranges::subrange<::std::vector<int>::const_iterator> next_points(const T& l, const T& r, const T& d) const {
      assert(this->built());
      assert(l <= r);

      auto lid = this->xid(l);
      auto rid = this->xid(r);
      auto k = this->range_freq(l, r, d);
      if (k == rid - lid) return ::std::ranges::subrange(this->m_is.cend(), this->m_is.cend());

      for (int h = this->lg(); h --> 0;) {
        const auto l0 = this->m_bvs[h].rank0(lid);
        const auto r0 = this->m_bvs[h].rank0(rid);
        if (k < r0 - l0) {
          lid = l0;
          rid = r0;
        } else {
          k -= r0 - l0;
          lid += this->m_bvs[h].zeros() - l0;
          rid += this->m_bvs[h].zeros() - r0;
        }
      }

      return ::std::ranges::subrange(this->m_is.cbegin() + lid, this->m_is.cbegin() + rid);
    }
  };
}

#endif
