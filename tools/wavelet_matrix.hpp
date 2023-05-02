#ifndef TOOLS_WAVELET_MATRIX_HPP
#define TOOLS_WAVELET_MATRIX_HPP

#include <cstddef>
#include <vector>
#include <utility>
#include <tuple>
#include <cassert>
#include <algorithm>
#include <iterator>
#include "tools/popcount.hpp"

// Source: https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.cpp.html
// License: Unlicense
// Author: ei1333

namespace tools {
  struct succinct_indexable_dictionary {
    ::std::size_t length;
    ::std::size_t blocks;
    ::std::vector<unsigned int> bit, sum;

    succinct_indexable_dictionary() = default;

    succinct_indexable_dictionary(::std::size_t length) : length(length), blocks((length + 31) >> 5) {
      bit.assign(blocks, 0U);
      sum.assign(blocks, 0U);
    }

    void set(int k) {
      bit[k >> 5] |= 1U << (k & 31);
    }

    void build() {
      sum[0] = 0U;
      for (::std::size_t i = 1; i < blocks; ++i) {
        sum[i] = sum[i - 1] + ::tools::popcount(bit[i - 1]);
      }
    }

    bool operator[](int k) {
      return (bool((bit[k >> 5] >> (k & 31)) & 1));
    }

    int rank(int k) {
      return (sum[k >> 5] + ::tools::popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
    }

    int rank(bool val, int k) {
      return (val ? rank(k) : k - rank(k));
    }
  };

  template <typename T, int MAXLOG>
  struct wavelet_matrix {
    ::std::size_t length;
    ::tools::succinct_indexable_dictionary matrix[MAXLOG];
    int mid[MAXLOG];

    wavelet_matrix() = default;

    wavelet_matrix(::std::vector<T> v) : length(v.size()) {
      ::std::vector<T> l(length), r(length);
      for(int level = MAXLOG - 1; level >= 0; level--) {
        matrix[level] = ::tools::succinct_indexable_dictionary(length + 1);
        int left = 0, right = 0;
        for (::std::size_t i = 0; i < length; ++i) {
          if (((v[i] >> level) & 1)) {
            matrix[level].set(i);
            r[right++] = v[i];
          } else {
            l[left++] = v[i];
          }
        }
        mid[level] = left;
        matrix[level].build();
        v.swap(l);
        for (int i = 0; i < right; i++) {
          v[left + i] = r[i];
        }
      }
    }

    ::std::pair<int, int> succ(bool f, int l, int r, int level) {
      return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
    }

    // v[k]
    T access(int k) {
      T ret = 0;
      for (int level = MAXLOG - 1; level >= 0; level--) {
        bool f = matrix[level][k];
        if(f) ret |= T(1) << level;
        k = matrix[level].rank(f, k) + mid[level] * f;
      }
      return ret;
    }

    T operator[](const int &k) {
      return access(k);
    }

    // count i s.t. (0 <= i < r) && v[i] == x
    int rank(const T &x, int r) {
      int l = 0;
      for (int level = MAXLOG - 1; level >= 0; level--) {
        ::std::tie(l, r) = succ((x >> level) & 1, l, r, level);
      }
      return r - l;
    }

    // k-th(0-indexed) smallest number in v[l,r)
    T kth_smallest(int l, int r, int k) {
      assert(0 <= k && k < r - l);
      T ret = 0;
      for (int level = MAXLOG - 1; level >= 0; level--) {
        int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l);
        bool f = cnt <= k;
        if (f) {
          ret |= T(1) << level;
          k -= cnt;
        }
        ::std::tie(l, r) = succ(f, l, r, level);
      }
      return ret;
    }

    // k-th(0-indexed) largest number in v[l,r)
    T kth_largest(int l, int r, int k) {
      return kth_smallest(l, r, r - l - k - 1);
    }

    // count i s.t. (l <= i < r) && (v[i] < upper)
    int range_freq(int l, int r, T upper) {
      int ret = 0;
      for (int level = MAXLOG - 1; level >= 0; level--) {
        bool f = ((upper >> level) & 1);
        if (f) ret += matrix[level].rank(false, r) - matrix[level].rank(false, l);
        ::std::tie(l, r) = succ(f, l, r, level);
      }
      return ret;
    }

    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)
    int range_freq(int l, int r, T lower, T upper) {
      return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    // max v[i] s.t. (l <= i < r) && (v[i] < upper)
    T prev_value(int l, int r, T upper) {
      int cnt = range_freq(l, r, upper);
      return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
    }

    // min v[i] s.t. (l <= i < r) && (lower <= v[i])
    T next_value(int l, int r, T lower) {
      int cnt = range_freq(l, r, lower);
      return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
    }
  };

  template <typename T, int MAXLOG>
  struct compressed_wavelet_matrix {
    ::tools::wavelet_matrix<int, MAXLOG> mat;
    ::std::vector<T> ys;

    compressed_wavelet_matrix(const ::std::vector<T>& v) : ys(v) {
      ::std::sort(::std::begin(ys), ::std::end(ys));
      ys.erase(::std::unique(::std::begin(ys), ::std::end(ys)), ::std::end(ys));
      ::std::vector<int> t(v.size());
      for (::std::size_t i = 0; i < v.size(); ++i) t[i] = get(v[i]);
      mat = ::tools::wavelet_matrix<int, MAXLOG>(t);
    }

    inline int get(const T& x) {
      return lower_bound(::std::begin(ys), ::std::end(ys), x) - ::std::begin(ys);
    }

    T access(int k) {
      return ys[mat.access(k)];
    }

    T operator[](const int &k) {
      return access(k);
    }

    int rank(const T &x, int r) {
      auto pos = get(x);
      if (pos == ys.size() || ys[pos] != x) return 0;
      return mat.rank(pos, r);
    }

    T kth_smallest(int l, int r, int k) {
      return ys[mat.kth_smallest(l, r, k)];
    }

    T kth_largest(int l, int r, int k) {
      return ys[mat.kth_largest(l, r, k)];
    }

    int range_freq(int l, int r, T upper) {
      return mat.range_freq(l, r, get(upper));
    }

    int range_freq(int l, int r, T lower, T upper) {
      return mat.range_freq(l, r, get(lower), get(upper));
    }

    T prev_value(int l, int r, T upper) {
      auto ret = mat.prev_value(l, r, get(upper));
      return ret == -1 ? T(-1) : ys[ret];
    }

    T next_value(int l, int r, T lower) {
      auto ret = mat.next_value(l, r, get(lower));
      return ret == -1 ? T(-1) : ys[ret];
    }
  };
}

#endif
