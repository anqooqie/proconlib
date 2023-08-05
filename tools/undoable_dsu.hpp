#ifndef TOOLS_UNDOABLE_DSU_HPP
#define TOOLS_UNDOABLE_DSU_HPP

#include <vector>
#include <stack>
#include <tuple>
#include <cassert>
#include <utility>
#include <algorithm>

namespace tools {
  class undoable_dsu {
  private:
    ::std::vector<int> m_data;
    ::std::stack<::std::tuple<int, int, int, int>> m_history;

    int size() const {
      return this->m_data.size();
    }

  public:
    undoable_dsu() = default;
    undoable_dsu(const ::tools::undoable_dsu&) = default;
    undoable_dsu(::tools::undoable_dsu&&) = default;
    ~undoable_dsu() = default;
    ::tools::undoable_dsu& operator=(const ::tools::undoable_dsu&) = default;
    ::tools::undoable_dsu& operator=(::tools::undoable_dsu&&) = default;

    explicit undoable_dsu(const int n) : m_data(n, -1) {
    }

    int leader(const int x) const {
      assert(0 <= x && x < this->size());

      return this->m_data[x] < 0 ? x : this->leader(this->m_data[x]);
    }

    bool same(const int x, const int y) const {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      return this->leader(x) == this->leader(y);
    }

    int merge(int x, int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      x = this->leader(x);
      y = this->leader(y);
      if (this->m_data[x] > this->m_data[y]) ::std::swap(x, y);
      this->m_history.emplace(x, y, this->m_data[x], this->m_data[y]);

      if (x == y) return x;

      this->m_data[x] += this->m_data[y];
      this->m_data[y] = x;

      return x;
    }

    int size(const int x) const {
      assert(0 <= x && x < this->size());

      return -this->m_data[this->leader(x)];
    }

    void undo() {
      assert(!this->m_history.empty());

      const auto [x, y, dx, dy] = this->m_history.top();
      this->m_history.pop();

      this->m_data[x] = dx;
      this->m_data[y] = dy;
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
