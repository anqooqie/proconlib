#ifndef TOOLS_CUMSUM2D_HPP
#define TOOLS_CUMSUM2D_HPP

#include <vector>
#include <iterator>
#include <cstddef>
#include <utility>

namespace tools {

  template <typename G>
  class cumsum2d {
  private:
    using T = typename G::T;
    ::std::vector<::std::vector<T>> preprocessed;

  public:
    template <typename OuterIterator>
    cumsum2d(const OuterIterator& begin, const OuterIterator& end) :
      preprocessed(
        ::std::distance(begin, end) + 1,
        ::std::vector<T>((begin == end ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin))) + 1, G::e())
      )
    {
      const ::std::size_t height = ::std::distance(begin, end);
      const ::std::size_t width = begin == end ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin));
      using InnerIterator = decltype(::std::begin(::std::declval<typename ::std::iterator_traits<OuterIterator>::value_type>()));

      {
        OuterIterator it1 = begin;
        for (::std::size_t y = 0; y < height; ++y, ++it1) {
          InnerIterator it2 = ::std::begin(*it1);
          for (::std::size_t x = 0; x < width; ++x, ++it2) {
            this->preprocessed[y + 1][x + 1] = G::op(this->preprocessed[y + 1][x], *it2);
          }
        }
      }
      for (::std::size_t x = 0; x < width; ++x) {
        for (::std::size_t y = 0; y < height; ++y) {
          this->preprocessed[y + 1][x + 1] = G::op(this->preprocessed[y][x + 1], this->preprocessed[y + 1][x + 1]);
        }
      }
    }

    T query(const ::std::size_t x1, const ::std::size_t y1, const ::std::size_t x2, const ::std::size_t y2) const {
      T tmp = G::op(this->preprocessed[y2][x2], G::inv(this->preprocessed[y2][x1]));
      tmp = G::op(tmp, G::inv(this->preprocessed[y1][x2]));
      return G::op(tmp, this->preprocessed[y1][x1]);
    }
  };
}

#endif
