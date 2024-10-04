#ifndef TOOLS_CUMSUM2D_HPP
#define TOOLS_CUMSUM2D_HPP

#include <type_traits>
#include <cstddef>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>
#include "tools/is_group.hpp"
#include "tools/group.hpp"

namespace tools {

  template <typename X>
  class cumsum2d {
  private:
    using G = ::std::conditional_t<::tools::is_group_v<X>, X, tools::group::plus<X>>;
    using T = typename G::T;
    ::std::size_t height;
    ::std::size_t width;
    ::std::vector<T> preprocessed;

  public:
    template <typename Range>
    explicit cumsum2d(const Range& range) {
      const auto begin = ::std::begin(range);
      const auto end = ::std::end(range);
      this->height = ::std::distance(begin, end);
      this->width = this->height == 0 ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin));
      this->preprocessed.reserve((this->height + 1) * (this->width + 1));
      ::std::fill_n(::std::back_inserter(this->preprocessed), (this->height + 1) * (this->width + 1), G::e());

      {
        auto it1 = begin;
        for (::std::size_t y = 0; y < this->height; ++y, ++it1) {
          auto it2 = ::std::begin(*it1);
          for (::std::size_t x = 0; x < this->width; ++x, ++it2) {
            this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)] = G::op(this->preprocessed[(y + 1) * (this->width + 1) + x], *it2);
          }
        }
      }
      for (::std::size_t x = 0; x < this->width; ++x) {
        for (::std::size_t y = 0; y < this->height; ++y) {
          this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)] = G::op(this->preprocessed[y * (this->width + 1) + (x + 1)], this->preprocessed[(y + 1) * (this->width + 1) + (x + 1)]);
        }
      }
    }

    T query(const ::std::size_t y1, const ::std::size_t y2, const ::std::size_t x1, const ::std::size_t x2) const {
      assert(y1 <= y2 && y2 <= this->height);
      assert(x1 <= x2 && x2 <= this->width);
      return G::op(
        G::op(
          G::op(
            this->preprocessed[y2 * (this->width + 1) + x2],
            G::inv(this->preprocessed[y2 * (this->width + 1) + x1])
          ),
          G::inv(this->preprocessed[y1 * (this->width + 1) + x2])
        ),
        this->preprocessed[y1 * (this->width + 1) + x1]
      );
    }
  };
}

#endif
