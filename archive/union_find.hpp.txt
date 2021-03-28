#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>
#include <utility>

/*
usage:

tools::union_find<std::int_fast64_t> uf(10);
uf.unite(1, 3);
uf.is_same(1, 3);
*/

namespace tools {
  template <typename T>
  class union_find {
  private:
    std::vector<T> parents;
    std::vector<T> sizes;
    T component_count;

  public:
    union_find(const T n) :
      parents(n),
      sizes(n, 1),
      component_count(n) {
      for (T i = 0; i < n; ++i) {
        parents[i] = i;
      }
    }

    T root(const T x) {
      return this->parents[x] == x ? x : (this->parents[x] = this->root(this->parents[x]));
    }

    bool is_same(const T x, const T y) {
      return this->root(x) == this->root(y);
    }

    void unite(T x, T y) {
      x = this->root(x);
      y = this->root(y);
      if (x == y) return;

      if (this->sizes[x] < this->sizes[y]) std::swap(x, y);
      this->parents[y] = x;
      this->sizes[x] += this->sizes[y];
      --this->component_count;
    }

    T size() const {
      return this->component_count;
    }

    T size(const T x) {
      return this->sizes[this->root(x)];
    }
  };
}

#endif
