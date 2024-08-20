#ifndef TOOLS_PRESET_SEGTREE_BEATS_HPP
#define TOOLS_PRESET_SEGTREE_BEATS_HPP

#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include "tools/segtree_beats.hpp"

// Source: https://github.com/hitonanode/cplib-cpp/blob/5dc514109dcc62c00c9b96b044b0e57d76ac7e9b/segmenttree/acl_beats.hpp
// License: MIT
// Author: hitonanode

// MIT License
// 
// Copyright (c) 2019 Ryotaro Sato
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

namespace tools {
  namespace detail {
    namespace preset_segtree_beats {
      template <typename T>
      T second_lowest(const T a, const T a2, const T c, const T c2) {
        assert(a <= a2); // a < a2 or a == a2 == INF
        assert(c <= c2); // c < c2 or c == c2 == -INF
        return a == c ? ::std::min(a2, c2) : a2 <= c ? a2 : c2 <= a ? c2 : ::std::max(a, c);
      }

      template <typename T>
      T second_highest(const T a, const T a2, const T b, const T b2) {
        assert(a >= a2); // a > a2 or a == a2 == -INF
        assert(b >= b2); // b > b2 or b == b2 == INF
        return a == b ? ::std::max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : ::std::min(a, b);
      }

      template <typename T>
      struct S {
        T lo, hi, lo2, hi2, sum, sz, nlo, nhi;
        bool fail;
        S():
          lo(::std::numeric_limits<T>::max()),
          hi(::std::numeric_limits<T>::min()),
          lo2(::std::numeric_limits<T>::max()),
          hi2(::std::numeric_limits<T>::min()),
          sum(0),
          sz(0),
          nlo(0),
          nhi(0),
          fail(false) {
        }
        S(const T x, const T sz_):
          lo(x),
          hi(x),
          lo2(::std::numeric_limits<T>::max()),
          hi2(::std::numeric_limits<T>::min()),
          sum(x * sz_),
          sz(sz_),
          nlo(sz_),
          nhi(sz_),
          fail(false) {
        }
      };

      template <typename T>
      S<T> op(const S<T>& l, const S<T>& r) {
        if (l.lo > l.hi) return r;
        if (r.lo > r.hi) return l;
        S<T> ret;
        ret.lo = ::std::min(l.lo, r.lo);
        ret.hi = ::std::max(l.hi, r.hi);
        ret.lo2 = second_lowest(l.lo, l.lo2, r.lo, r.lo2);
        ret.hi2 = second_highest(l.hi, l.hi2, r.hi, r.hi2);
        ret.sum = l.sum + r.sum;
        ret.sz = l.sz + r.sz;
        ret.nlo = l.nlo * (l.lo <= r.lo) + r.nlo * (r.lo <= l.lo);
        ret.nhi = l.nhi * (l.hi >= r.hi) + r.nhi * (r.hi >= l.hi);
        return ret;
      }

      template <typename T>
      S<T> e() {
        return S<T>();
      }

      template <typename T>
      struct F {
        T lb, ub, bias;
        F():
          lb(::std::numeric_limits<T>::min()),
          ub(::std::numeric_limits<T>::max()),
          bias(0) {
        }
        F(const T chmax_, const T chmin_, const T add):
          lb(chmax_),
          ub(chmin_),
          bias(add) {
        }
        static F<T> chmin(const T x) {
          return F<T>(::std::numeric_limits<T>::min(), x, 0);
        }
        static F<T> chmax(const T x) {
          return F<T>(x, ::std::numeric_limits<T>::max(), 0);
        }
        static F<T> add(const T x) {
          return F<T>(::std::numeric_limits<T>::min(), ::std::numeric_limits<T>::max(), x);
        }
      };

      template <typename T>
      S<T> mapping(const F<T>& f, S<T> x) {
        if (x.sz == 0) return e<T>();

        // f の作用後 x の要素が 1 種類だけになるケース
        if (x.lo == x.hi || f.lb == f.ub || f.lb >= x.hi || f.ub <= x.lo) {
          return S<T>(::std::clamp(x.lo, f.lb, f.ub) + f.bias, x.sz);
        }

        // 2 種類 -> 1 種類
        if (x.lo2 == x.hi) {
          x.lo = x.hi2 = ::std::max(x.lo, f.lb) + f.bias;
          x.hi = x.lo2 = ::std::min(x.hi, f.ub) + f.bias;
          x.sum = x.lo * x.nlo + x.hi * x.nhi;
          return x;
        }

        // lo と lo2, hi と hi2 が潰れないケース
        if (f.lb < x.lo2 && f.ub > x.hi2) {
          T nxt_lo = std::max(x.lo, f.lb);
          T nxt_hi = std::min(x.hi, f.ub);
          x.sum += (nxt_lo - x.lo) * x.nlo - (x.hi - nxt_hi) * x.nhi + f.bias * x.sz;
          x.lo = nxt_lo + f.bias;
          x.hi = nxt_hi + f.bias;
          x.lo2 += f.bias;
          x.hi2 += f.bias;
          return x;
        }

        x.fail = true;
        return x;
      }

      template <typename T>
      F<T> composition(const F<T>& fnew, const F<T>& fold) {
        F<T> ret;

        ret.lb = fold.lb;
        if (::std::numeric_limits<T>::min() < ret.lb && ret.lb < ::std::numeric_limits<T>::max()) ret.lb += fold.bias;
        ret.lb = ::std::clamp(ret.lb, fnew.lb, fnew.ub);
        if (::std::numeric_limits<T>::min() < ret.lb && ret.lb < ::std::numeric_limits<T>::max()) ret.lb -= fold.bias;

        ret.ub = fold.ub;
        if (::std::numeric_limits<T>::min() < ret.ub && ret.ub < ::std::numeric_limits<T>::max()) ret.ub += fold.bias;
        ret.ub = ::std::clamp(ret.ub, fnew.lb, fnew.ub);
        if (::std::numeric_limits<T>::min() < ret.ub && ret.ub < ::std::numeric_limits<T>::max()) ret.ub -= fold.bias;

        ret.bias = fold.bias + fnew.bias;

        return ret;
      }

      template <typename T>
      F<T> id() {
        return F<T>();
      }

      template <typename T>
      using Base = ::tools::segtree_beats<S<T>, op<T>, e<T>, F<T>, mapping<T>, composition<T>, id<T>>;
    }
  }

  template <typename T>
  class preset_segtree_beats {
  private:
    ::tools::detail::preset_segtree_beats::Base<T> m_base;
    using S = ::tools::detail::preset_segtree_beats::S<T>;
    using F = ::tools::detail::preset_segtree_beats::F<T>;

  public:
    preset_segtree_beats(const ::tools::preset_segtree_beats<T>&) = default;
    preset_segtree_beats(::tools::preset_segtree_beats<T>&&) = default;
    ~preset_segtree_beats() = default;
    ::tools::preset_segtree_beats<T>& operator=(const ::tools::preset_segtree_beats<T>&) = default;
    ::tools::preset_segtree_beats<T>& operator=(::tools::preset_segtree_beats<T>&&) = default;

    explicit preset_segtree_beats(const int n) : m_base(n) {
    }
    template <typename InputIterator>
    preset_segtree_beats(const InputIterator begin, const InputIterator end) : m_base([&]() {
      ::std::vector<S> v;
      for (auto it = begin; it != end; ++it) {
        v.emplace_back(*it, 1);
      }
      return v;
    }()) {
    }
    explicit preset_segtree_beats(const ::std::vector<T>& v) : preset_segtree_beats(v.begin(), v.end()) {
    }

    void set(const int p, const T x) {
      this->m_base.set(p, S(x, 1));
    }
    T get(const int p) {
      return this->m_base.get(p).sum;
    }
    T min(const int l, const int r) {
      return this->m_base.prod(l, r).lo;
    }
    T max(const int l, const int r) {
      return this->m_base.prod(l, r).hi;
    }
    T sum(const int l, const int r) {
      return this->m_base.prod(l, r).sum;
    }
    T all_min() {
      return this->m_base.all_prod().lo;
    }
    T all_max() {
      return this->m_base.all_prod().hi;
    }
    T all_sum() {
      return this->m_base.all_prod().sum;
    }
    void chmin(const int p, const T f) {
      this->m_base.apply(p, F::chmin(f));
    }
    void chmax(const int p, const T f) {
      this->m_base.apply(p, F::chmax(f));
    }
    void add(const int p, const T f) {
      this->m_base.apply(p, F::add(f));
    }
    void chmin(const int l, const int r, const T f) {
      this->m_base.apply(l, r, F::chmin(f));
    }
    void chmax(const int l, const int r, const T f) {
      this->m_base.apply(l, r, F::chmax(f));
    }
    void add(const int l, const int r, const T f) {
      this->m_base.apply(l, r, F::add(f));
    }
    template <class G>
    int max_right(const int l, const G g) {
      return this->m_base.max_right(l, g);
    }
    template <class G>
    int min_left(const int r, const G g) {
      return this->m_base.min_left(r, g);
    }
  };
}

#endif
