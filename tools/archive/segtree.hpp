#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include <functional>
#include <vector>
#include <cstddef>
#include <iterator>
#include "monoid.hpp"
#include "ceil_log2.hpp"
#include "pow2.hpp"

/*
usage:

// 6要素の区間和セグ木
tools::segtree<i64> segtree(
  tools::group<i64>::plus(),
  6,
  0
);

// 0始まりで3番目の要素に30を加算
segtree.update(3, segtree.query(3) + 30);
*/

namespace tools {
  template <typename T>
  class segtree {
  private:
    ::tools::monoid<T> monoid;
    ::std::size_t height;
    ::std::vector<T> data;

    void recalc(::std::size_t node_id) {
      while (node_id >>= 1) {
        this->data[node_id] = this->monoid.operation(this->data[(node_id << 1) | 0], this->data[(node_id << 1) | 1]);
      }
    }

    ::std::size_t capacity() const {
      return this->data.size() / 2;
    }

  public:
    segtree(
      const ::tools::monoid<T>& monoid,
      const ::std::size_t& n
    ) :
      monoid(monoid),
      height(::tools::ceil_log2(n)),
      data(::tools::pow2(this->height + 1), monoid.identity()) {
    }

    template <typename U>
    segtree(
      const ::tools::monoid<T>& monoid,
      const ::std::size_t& n,
      const U& t,
      const ::std::function<T(U)>& map
    ) :
      monoid(monoid),
      height(::tools::ceil_log2(n)),
      data(::tools::pow2(this->height + 1), monoid.identity()) {
      for (::std::size_t node_id = this->capacity(); node_id < this->capacity() + n; ++node_id) {
        this->data[node_id] = map(t);
      }
      for (::std::size_t node_id = this->capacity() - 1; node_id > 0; --node_id) {
        this->data[node_id] = monoid.operation(this->data[(node_id << 1) | 0], this->data[(node_id << 1) | 1]);
      }
    }

    template <typename InputIter>
    segtree(
      const ::tools::monoid<T>& monoid,
      const InputIter& begin,
      const InputIter& end,
      const ::std::function<T(typename InputIter::value_type)>& map
    ) :
      monoid(monoid),
      height(::tools::ceil_log2(::std::distance(begin, end))),
      data(::tools::pow2(this->height + 1), monoid.identity()) {
      ::std::size_t node_id = this->size();
      for (auto it = begin; it != end; ++it, ++node_id) {
        this->data[node_id] = map(*it);
      }
      for (node_id = this->capacity() - 1; node_id > 0; --node_id) {
        this->data[node_id] = monoid.operation(this->data[(node_id << 1) | 0], this->data[(node_id << 1) | 1]);
      }
    }

    void update(const ::std::size_t i, const T& x) {
      const ::std::size_t i_id = i + this->capacity();
      this->data[i_id] = x;
      this->recalc(i_id);
    }

    T query(const ::std::size_t i) const {
      const ::std::size_t i_id = i + this->capacity();
      return this->data[i_id];
    }

    T query(const ::std::size_t a, const ::std::size_t b) const {
      if (a >= b) return this->monoid.identity();

      const ::std::size_t a_id = a + this->capacity();
      const ::std::size_t b_id = b + this->capacity() - 1;

      T vl = this->monoid.identity();
      T vr = this->monoid.identity();
      for (::std::size_t l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          vl = this->monoid.operation(vl, this->data[l]);
          ++l;
        }
        if (r & 1) {
          --r;
          vr = this->monoid.operation(this->data[r], vr);
        }
      }
      return this->monoid.operation(vl, vr);
    }
  };
}

#endif
