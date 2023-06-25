#ifndef TOOLS_RECTANGLE_SUM
#define TOOLS_RECTANGLE_SUM

#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
#include <array>
#include "atcoder/fenwicktree.hpp"
#include "tools/bit_vector.hpp"
#include "tools/lower_bound.hpp"
#include "tools/less_by_first.hpp"
#include "tools/floor_log2.hpp"

namespace tools {
  template <typename T>
  class rectangle_sum {
  private:
    ::std::vector<::std::pair<T, T>> m_ps;
    ::std::vector<T> m_ys;
    ::std::vector<::tools::bit_vector> m_bvs;
    ::std::vector<::atcoder::fenwick_tree<T>> m_fws;

    int xid(const T x) const {
      return ::tools::lower_bound(this->m_ps.begin(), this->m_ps.end(), ::std::make_pair(x, T()), ::tools::less_by_first());
    }
    int yid(const T y) const {
      return ::tools::lower_bound(this->m_ys.begin(), this->m_ys.end(), y);
    }
    int size() const {
      return this->m_ps.size();
    }
    int lg() const {
      return this->m_bvs.size();
    }
    bool built() const {
      return this->lg() > 0;
    }

  public:
    rectangle_sum() = default;
    rectangle_sum(const ::tools::rectangle_sum<T>&) = default;
    rectangle_sum(::tools::rectangle_sum<T>&&) = default;
    ~rectangle_sum() = default;
    ::tools::rectangle_sum<T>& operator=(const ::tools::rectangle_sum<T>&) = default;
    ::tools::rectangle_sum<T>& operator=(::tools::rectangle_sum<T>&&) = default;

    void register_point(const T x, const T y) {
      assert(!this->built());

      this->m_ps.emplace_back(x, y);
      this->m_ys.push_back(y);
    }

    void build() {
      assert(!this->built());

      ::std::sort(this->m_ps.begin(), this->m_ps.end());
      this->m_ps.erase(::std::unique(this->m_ps.begin(), this->m_ps.end()), this->m_ps.end());

      ::std::sort(this->m_ys.begin(), this->m_ys.end());
      this->m_ys.erase(::std::unique(this->m_ys.begin(), this->m_ys.end()), this->m_ys.end());

      const int n = ::std::max(this->size(), 1);
      this->m_bvs.assign(::tools::floor_log2(::std::max<int>(this->m_ys.size(), 1)) + 1, ::tools::bit_vector(n));

      ::std::vector<int> cur;
      cur.reserve(n);
      for (int i = 0; i < this->size(); ++i) {
        cur.push_back(this->yid(this->m_ps[i].second));
      }
      cur.resize(n);
      ::std::vector<int> nxt(n);

      for (int h = this->lg() - 1; h >= 0; --h) {
        for (int i = 0; i < n; ++i)
          if ((cur[i] >> h) & 1) this->m_bvs[h].set(i);
        this->m_bvs[h].build();
        ::std::array<decltype(nxt.begin()), 2> it{nxt.begin(), nxt.begin() + this->m_bvs[h].zeros()};
        for (int i = 0; i < n; ++i) *it[this->m_bvs[h].get(i)]++ = cur[i];
        ::std::swap(cur, nxt);
      }

      this->m_fws.assign(this->lg(), ::atcoder::fenwick_tree<T>(n));
    }

    void add(const T x, const T y, const T w) {
      assert(this->built());

      int k = ::tools::lower_bound(this->m_ps.begin(), this->m_ps.end(), ::std::make_pair(x, y));

      assert(k < this->size());
      assert(this->m_ps[k] == ::std::make_pair(x, y));

      for (int h = this->lg() - 1; h >= 0; --h) {
        k = this->m_bvs[h].get(k) ? this->m_bvs[h].rank1(k) + this->m_bvs[h].zeros() : this->m_bvs[h].rank0(k);
        this->m_fws[h].add(k, w);
      }
    }

  private:
    T sum(int l, int r, const int u) {
      assert(this->built());
      assert(0 <= l && l <= r && r <= this->size());
      assert(0 <= u);

      T res = 0;
      for (int h = this->lg() - 1; h >= 0; --h) {
        const auto l0 = this->m_bvs[h].rank0(l);
        const auto r0 = this->m_bvs[h].rank0(r);
        if ((u >> h) & 1) {
          res += this->m_fws[h].sum(l0, r0);
          l += this->m_bvs[h].zeros() - l0;
          r += this->m_bvs[h].zeros() - r0;
        } else {
          l = l0;
          r = r0;
        }
      }
      return res;
    }

  public:
    T sum(T l, T r, const T d, const T u) {
      assert(this->built());
      assert(l <= r);
      assert(d <= u);

      l = this->xid(l);
      r = this->xid(r);
      return this->sum(l, r, this->yid(u)) - this->sum(l, r, this->yid(d));
    }
  };
}

#endif
