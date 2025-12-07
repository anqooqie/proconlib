#ifndef TOOLS_DUAL_SEGTREE_HPP
#define TOOLS_DUAL_SEGTREE_HPP

#include <vector>
#include "tools/ceil_log2.hpp"
#include "tools/monoid.hpp"
#include "tools/pow2.hpp"

namespace tools {

  template <tools::monoid M>
  class dual_segtree {
    using T = typename M::T;
    int height;
    std::vector<T> lazy;

    void propagate(const int node_id) {
      if(this->lazy[node_id] == M::e()) return;
      this->lazy[(node_id << 1) | 0] = M::op(this->lazy[node_id], this->lazy[(node_id << 1) | 0]);
      this->lazy[(node_id << 1) | 1] = M::op(this->lazy[node_id], this->lazy[(node_id << 1) | 1]);
      this->lazy[node_id] = M::e();
    }

    void thrust(const int node_id) {
      for (int h = this->height; h > 0; --h) {
        this->propagate(node_id >> h);
      }
    }

    int capacity() const {
      return this->lazy.size() / 2;
    }

  public:
    dual_segtree() = default;
    explicit dual_segtree(const int n) :
      height(tools::ceil_log2(n)),
      lazy(tools::pow2(this->height + 1), M::e()) {
    }

    void apply(const int a, const int b, const T& x) {
      if(a >= b) return;

      const int a_id = a + this->capacity();
      const int b_id = b + this->capacity() - 1;

      this->thrust(a_id);
      this->thrust(b_id);

      for (int l = a_id, r = b_id + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          this->lazy[l] = M::op(x, this->lazy[l]);
          ++l;
        }
        if (r & 1) {
          --r;
          this->lazy[r] = M::op(x, this->lazy[r]);
        }
      }
    }

    T get(const int a) {
      const int node_id = a + this->capacity();
      this->thrust(node_id);
      return this->lazy[node_id];
    }
  };
}

#endif
