#ifndef TOOLS_WAVELET_MATRIX_HPP
#define TOOLS_WAVELET_MATRIX_HPP

#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#include <utility>
#include <cassert>
#include "tools/bit_vector.hpp"
#include "tools/floor_log2.hpp"

// Source: https://nyaannyaan.github.io/library/data-structure-2d/wavelet-matrix.hpp.html
// License: CC0 1.0 Universal
// Author: Nyaan

namespace tools {
  template <typename T>
  class wavelet_matrix {
  private:
    using u32 = ::std::uint32_t;
    using i64 = ::std::int64_t;
    using u64 = ::std::uint64_t;

    int n, lg;
    ::std::vector<T> a;
    ::std::vector<::tools::bit_vector> bv;

  public:
    wavelet_matrix() = default;
    explicit wavelet_matrix(u32 _n) : n(::std::max<u32>(_n, 1)), a(n) {}
    wavelet_matrix(const ::std::vector<T>& _a) : n(_a.size()), a(_a) { build(); }

    __attribute__((optimize("O3"))) void build() {
      assert(::std::all_of(::std::begin(a), ::std::end(a), [](const auto a_i) { return a_i >= 0; }));

      lg = ::tools::floor_log2(::std::max<T>(*::std::max_element(::std::begin(a), ::std::end(a)), 1)) + 1;
      bv.assign(lg, ::tools::bit_vector(n));
      ::std::vector<T> cur = a, nxt(n);
      for (int h = lg - 1; h >= 0; --h) {
        for (int i = 0; i < n; ++i)
          if ((cur[i] >> h) & 1) bv[h].set(i);
        bv[h].build();
        ::std::array<decltype(::std::begin(nxt)), 2> it{::std::begin(nxt), ::std::begin(nxt) + bv[h].zeros()};
        for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];
        ::std::swap(cur, nxt);
      }
      return;
    }

    void set(u32 i, const T& x) {
      assert(x >= 0);
      a[i] = x; 
    }

  private:
    inline ::std::pair<u32, u32> succ0(int l, int r, int h) const {
      return ::std::make_pair(bv[h].rank0(l), bv[h].rank0(r));
    }

    inline ::std::pair<u32, u32> succ1(int l, int r, int h) const {
      u32 l0 = bv[h].rank0(l);
      u32 r0 = bv[h].rank0(r);
      u32 zeros = bv[h].zeros();
      return ::std::make_pair(l + zeros - l0, r + zeros - r0);
    }

  public:
    // return a[k]
    T access(u32 k) const {
      assert(k <= u32(n));

      T ret = 0;
      for (int h = lg - 1; h >= 0; --h) {
        u32 f = bv[h].get(k);
        ret |= f ? T(1) << h : 0;
        k = f ? bv[h].rank1(k) + bv[h].zeros() : bv[h].rank0(k);
      }
      return ret;
    }

    // k-th (0-indexed) smallest number in a[l, r)
    T kth_smallest(u32 l, u32 r, u32 k) const {
      assert(l <= r && r <= u32(n));
      assert(k < r - l);

      T res = 0;
      for (int h = lg - 1; h >= 0; --h) {
        u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
        if (k < r0 - l0)
          l = l0, r = r0;
        else {
          k -= r0 - l0;
          res |= T(1) << h;
          l += bv[h].zeros() - l0;
          r += bv[h].zeros() - r0;
        }
      }
      return res;
    }

    // k-th (0-indexed) largest number in a[l, r)
    T kth_largest(int l, int r, int k) {
      assert(l <= r && r <= n);
      assert(k < r - l);

      return kth_smallest(l, r, r - l - k - 1);
    }

    // count i s.t. (l <= i < r) && (v[i] < upper)
    int range_freq(int l, int r, T upper) {
      assert(l <= r && r <= n);
      assert(upper >= 0);

      if (upper >= (T(1) << lg)) return r - l;
      int ret = 0;
      for (int h = lg - 1; h >= 0; --h) {
        bool f = (upper >> h) & 1;
        u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);
        if (f) {
          ret += r0 - l0;
          l += bv[h].zeros() - l0;
          r += bv[h].zeros() - r0;
        } else {
          l = l0;
          r = r0;
        }
      }
      return ret;
    }

    int range_freq(int l, int r, T lower, T upper) {
      assert(l <= r && r <= n);
      assert(0 <= lower && lower <= upper);

      return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    // max v[i] s.t. (l <= i < r) && (v[i] < upper)
    T prev_value(int l, int r, T upper) {
      assert(l <= r && r <= n);
      assert(upper >= 0);

      int cnt = range_freq(l, r, upper);
      return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
    }

    // min v[i] s.t. (l <= i < r) && (lower <= v[i])
    T next_value(int l, int r, T lower) {
      assert(l <= r && r <= n);
      assert(lower >= 0);

      int cnt = range_freq(l, r, lower);
      return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
    }
  };
}

#endif
