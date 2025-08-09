#ifndef TOOLS_DSU_HPP
#define TOOLS_DSU_HPP

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace tools {
  class dsu {
    // if this->m_data[x] < 0:
    //   x is a root.
    //   size(x) is -this->m_data[x].
    // if this->m_data[x] >= 0:
    //   x is an inner or leaf node.
    //   parent(x) is this->m_data[x].
    ::std::vector<int> m_data;

    int size() const {
      return this->m_data.size();
    }

  public:
    dsu() = default;
    explicit dsu(const int n) : m_data(n, -1) {
    }

    int leader(const int x) {
      assert(0 <= x && x < this->size());

      return this->m_data[x] < 0 ? x : (this->m_data[x] = this->leader(this->m_data[x]));
    }

    bool same(const int x, const int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      return this->leader(x) == this->leader(y);
    }

    int merge(int x, int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      x = this->leader(x);
      y = this->leader(y);
      if (x == y) return x;

      if (this->m_data[x] > this->m_data[y]) ::std::swap(x, y);
      this->m_data[x] += this->m_data[y];
      this->m_data[y] = x;

      return x;
    }

    int size(const int x) {
      assert(0 <= x && x < this->size());

      return -this->m_data[this->leader(x)];
    }

    ::std::vector<::std::vector<int>> groups() {
      ::std::vector<::std::vector<int>> res(this->size());
      for (int i = 0; i < this->size(); ++i) {
        res[this->leader(i)].push_back(i);
      }
      res.erase(::std::remove_if(res.begin(), res.end(), [](const auto& group) { return group.empty(); }), res.end());
      return res;
    }
  };
}

#endif
