#ifndef TOOLS_DSU_HPP
#define TOOLS_DSU_HPP

#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

namespace tools {
  class dsu {
  private:
    ::std::vector<int> m_parents;
    ::std::vector<int> m_sizes;

    int size() const {
      return this->m_parents.size();
    }

  public:
    dsu() = default;
    dsu(const ::tools::dsu&) = default;
    dsu(::tools::dsu&&) = default;
    ~dsu() = default;
    ::tools::dsu& operator=(const ::tools::dsu&) = default;
    ::tools::dsu& operator=(::tools::dsu&&) = default;

    explicit dsu(const int n) :
      m_parents(n),
      m_sizes(n, 1) {
      for (int i = 0; i < n; ++i) {
        this->m_parents[i] = i;
      }
    }

    int leader(const int x) {
      assert(0 <= x && x < this->size());

      return this->m_parents[x] == x ? x : (this->m_parents[x] = this->leader(this->m_parents[x]));
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

      if (this->m_sizes[x] < this->m_sizes[y]) ::std::swap(x, y);
      this->m_parents[y] = x;
      this->m_sizes[x] += this->m_sizes[y];

      return x;
    }

    int size(const int x) {
      return this->m_sizes[this->leader(x)];
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
