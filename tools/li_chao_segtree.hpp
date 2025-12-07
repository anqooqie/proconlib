#ifndef TOOLS_LI_CHAO_SEGTREE_HPP
#define TOOLS_LI_CHAO_SEGTREE_HPP

#include <vector>
#include <cstddef>
#include <utility>
#include <limits>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "tools/pow2.hpp"
#include "tools/floor_log2.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/pow2.hpp"
#include "tools/lower_bound.hpp"

namespace tools {
  template <typename T>
  class li_chao_segtree {
  private:
    bool m_maximal;
    std::vector<T> m_xs;
    std::size_t m_height;
    std::vector<std::pair<T, T>> m_nodes;

    std::size_t capacity() const {
      return this->m_nodes.size() / 2;
    }

    bool comp(const T& x, const T& y) const {
      return this->m_maximal ? x < y : y < x;
    }

    void add_impl(T fa, T fb, std::size_t node_id) {
      assert(tools::floor_log2(node_id) <= this->m_height);
      std::size_t l = (node_id - tools::pow2(tools::floor_log2(node_id))) * tools::pow2(this->m_height - tools::floor_log2(node_id));
      std::size_t r = l + tools::pow2(this->m_height - tools::floor_log2(node_id));
      while (node_id < this->m_nodes.size()) {
        const std::size_t m = (l + r) / 2;
        auto& [ga, gb] = this->m_nodes[node_id];
        bool greater_l = this->comp(ga * this->m_xs[l] + gb, fa * this->m_xs[l] + fb);
        bool greater_m = this->comp(ga * this->m_xs[m] + gb, fa * this->m_xs[m] + fb);
        bool greater_r = this->comp(ga * this->m_xs[r] + gb, fa * this->m_xs[r] + fb);
        if (greater_l == greater_m && greater_m == greater_r) {
          if (greater_l) {
            std::swap(fa, ga);
            std::swap(fb, gb);
          }
          return;
        }
        if (greater_m) {
          std::swap(fa, ga);
          std::swap(fb, gb);
          greater_l = !greater_l;
          greater_m = !greater_m;
          greater_r = !greater_r;
        }
        if (greater_l) {
          node_id = node_id * 2;
          r = m;
        } else {
          node_id = node_id * 2 + 1;
          l = m;
        }
      }
    }

  public:
    template <typename Iterator>
    li_chao_segtree(const Iterator& begin, const Iterator& end, const bool maximal) :
      m_maximal(maximal),
      m_xs(begin, end),
      m_height(this->m_xs.empty() ? std::numeric_limits<T>::min() : tools::ceil_log2(this->m_xs.size())),
      m_nodes(this->m_xs.empty() ? 0 : tools::pow2(this->m_height + 1), std::pair<T, T>(0, maximal ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max())) {
      if (this->m_xs.empty()) return;

      assert(std::is_sorted(this->m_xs.begin(), this->m_xs.end()));
      const std::size_t n = this->m_xs.size();
      this->m_xs.resize(this->capacity() + 1);
      std::iota(this->m_xs.begin() + n, this->m_xs.end(), this->m_xs[n - 1] + 1);
    }

    li_chao_segtree() = default;
    li_chao_segtree(const tools::li_chao_segtree<T>&) = default;
    li_chao_segtree(tools::li_chao_segtree<T>&&) = default;
    ~li_chao_segtree() = default;
    tools::li_chao_segtree<T>& operator=(const tools::li_chao_segtree<T>&) = default;
    tools::li_chao_segtree<T>& operator=(tools::li_chao_segtree<T>&&) = default;

    void add(const T& a, const T& b) {
      if (this->m_xs.empty()) return;

      this->add_impl(a, b, 1);
    }

    void add(const T& a, const T& b, const T& l, const T& r) {
      if (this->m_xs.empty()) return;

      auto l_id = tools::lower_bound(this->m_xs.begin(), std::prev(this->m_xs.end()), l);
      auto r_id = tools::lower_bound(this->m_xs.begin(), std::prev(this->m_xs.end()), r);
      if (r_id == std::ssize(this->m_xs) - 1 || r < this->m_xs[r_id]) --r_id;
      if (r_id < l_id) return;
      l_id += this->capacity();
      r_id += this->capacity() + 1;

      for (; l_id < r_id; l_id >>= 1, r_id >>= 1) {
        if (l_id & 1) {
          this->add_impl(a, b, l_id);
          ++l_id;
        }
        if (r_id & 1) {
          --r_id;
          this->add_impl(a, b, r_id);
        }
      }
    }

    T query(const T& x) const {
      const auto it = std::ranges::lower_bound(this->m_xs, x);
      assert(*it == x);
      const std::size_t node_id = this->capacity() + std::distance(this->m_xs.begin(), it);

      T answer = this->m_maximal ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max();
      for (std::size_t h = this->m_height + 1; h --> 0;) {
        const auto& [fa, fb] = this->m_nodes[node_id >> h];
        if (this->comp(answer, fa * x + fb)) {
          answer = fa * x + fb;
        }
      }
      
      return answer;
    }
  };
}

#endif
