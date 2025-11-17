#ifndef TOOLS_CUMSUM2D_HPP
#define TOOLS_CUMSUM2D_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/commutative_group.hpp"
#include "tools/groups.hpp"

namespace tools {

  template <typename X>
  class cumsum2d {
    using G = ::std::conditional_t<::tools::commutative_group<X>, X, ::tools::groups::plus<X>>;
    using T = typename G::T;
    int m_height;
    int m_width;
    ::std::vector<T> m_preprocessed;

    int p(const int y, const int x) const {
      return y * (this->m_width + 1) + x;
    }

  public:
    template <::std::ranges::input_range R>
    requires ::std::ranges::input_range<::std::ranges::range_reference_t<R>>
          && ::std::assignable_from<T&, ::std::ranges::range_value_t<::std::ranges::range_reference_t<R>>>
    explicit cumsum2d(R&& range) : m_height(0), m_width(0) {
      for (auto&& row : ::std::forward<R>(range)) {
        this->m_preprocessed.push_back(G::e());
        const auto old_size = this->m_preprocessed.size();
        ::std::ranges::copy(::std::forward<decltype(row)>(row), ::std::back_inserter(this->m_preprocessed));
        if (this->m_height == 0) {
          this->m_width = this->m_preprocessed.size() - old_size;
          this->m_preprocessed.insert(this->m_preprocessed.begin(), this->m_width + 1, G::e());
        } else {
          assert(::std::cmp_equal(this->m_width, this->m_preprocessed.size() - old_size));
        }
        ++this->m_height;
      }

      for (int y = 0; y < this->m_height; ++y) {
        for (int x = 0; x < this->m_width; ++x) {
          this->m_preprocessed[this->p(y + 1, x + 1)] = G::op(this->m_preprocessed[this->p(y + 1, x)], this->m_preprocessed[this->p(y + 1, x + 1)]);
        }
      }
      for (int x = 0; x < this->m_width; ++x) {
        for (int y = 0; y < this->m_height; ++y) {
          this->m_preprocessed[this->p(y + 1, x + 1)] = G::op(this->m_preprocessed[this->p(y, x + 1)], this->m_preprocessed[this->p(y + 1, x + 1)]);
        }
      }
    }

    T query(const int y1, const int y2, const int x1, const int x2) const {
      assert(y1 <= y2 && y2 <= this->m_height);
      assert(x1 <= x2 && x2 <= this->m_width);
      return G::op(
        G::op(
          G::op(
            this->m_preprocessed[this->p(y2, x2)],
            G::inv(this->m_preprocessed[this->p(y2, x1)])
          ),
          G::inv(this->m_preprocessed[this->p(y1, x2)])
        ),
        this->m_preprocessed[this->p(y1, x1)]
      );
    }
  };
}

#endif
