#ifndef TOOLS_LI_CHAO_SEGTREE_HPP
#define TOOLS_LI_CHAO_SEGTREE_HPP

#include <functional>
#include <vector>
#include <cstddef>
#include <optional>
#include <utility>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <iterator>
#include "tools/ceil_log2.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <typename T, typename Compare = ::std::less<T>>
  class li_chao_segtree {
  private:
    Compare m_comp;
    ::std::vector<T> m_xs;
    ::std::size_t m_height;
    ::std::vector<::std::optional<::std::pair<T, T>>> m_nodes;

    ::std::size_t capacity() const {
      return this->m_nodes.size() / 2;
    }

  public:
    template <typename Iterator>
    li_chao_segtree(const Iterator& begin, const Iterator& end, const Compare& comp) :
      m_comp(comp),
      m_xs(begin, end),
      m_height(::tools::ceil_log2(this->m_xs.size())),
      m_nodes(::tools::pow2(this->m_height + 1)) {
      assert(::std::is_sorted(this->m_xs.begin(), this->m_xs.end()));
      const ::std::size_t n = this->m_xs.size();
      this->m_xs.resize(this->capacity() + 1);
      ::std::iota(this->m_xs.begin() + n, this->m_xs.end(), this->m_xs[n - 1] + 1);
    }
    template <typename Iterator>
    li_chao_segtree(const Iterator& begin, const Iterator& end) :
      li_chao_segtree(begin, end, Compare()) {
    }

    li_chao_segtree() = default;
    li_chao_segtree(const ::tools::li_chao_segtree<T, Compare>&) = default;
    li_chao_segtree(::tools::li_chao_segtree<T, Compare>&&) = default;
    ~li_chao_segtree() = default;
    ::tools::li_chao_segtree<T, Compare>& operator=(const ::tools::li_chao_segtree<T, Compare>&) = default;
    ::tools::li_chao_segtree<T, Compare>& operator=(::tools::li_chao_segtree<T, Compare>&&) = default;

    void add(T fa, T fb) {
      ::std::size_t node_id = 1;
      ::std::size_t l = 0;
      ::std::size_t r = this->capacity();
      while (node_id < this->m_nodes.size()) {
        if (!this->m_nodes[node_id].has_value()) {
          this->m_nodes[node_id] = ::std::make_optional(::std::make_pair(fa, fb));
          return;
        }
        const ::std::size_t m = (l + r) / 2;
        auto& [ga, gb] = *this->m_nodes[node_id];
        bool greater_l = this->m_comp(ga * this->m_xs[l] + gb, fa * this->m_xs[l] + fb);
        bool greater_m = this->m_comp(ga * this->m_xs[m] + gb, fa * this->m_xs[m] + fb);
        bool greater_r = this->m_comp(ga * this->m_xs[r] + gb, fa * this->m_xs[r] + fb);
        if (greater_l == greater_m && greater_m == greater_r) {
          if (greater_l) {
            ::std::swap(fa, ga);
            ::std::swap(fb, gb);
          }
          return;
        }
        if (greater_m) {
          ::std::swap(fa, ga);
          ::std::swap(fb, gb);
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

    T query(const T& x) const {
      assert(this->m_nodes[1].has_value());

      const auto it = ::std::lower_bound(this->m_xs.begin(), this->m_xs.end(), x);
      assert(*it == x);
      const ::std::size_t node_id = this->capacity() + ::std::distance(this->m_xs.begin(), it);

      ::std::optional<T> answer;
      for (::std::size_t h = this->m_height + 1; h --> 0 && this->m_nodes[node_id >> h].has_value();) {
        const auto& [fa, fb] = *this->m_nodes[node_id >> h];
        if (!answer.has_value() || this->m_comp(*answer, fa * x + fb)) {
          answer = ::std::make_optional(fa * x + fb);
        }
      }
      
      return *answer;
    }
  };
}

#endif
