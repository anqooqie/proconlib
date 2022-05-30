#ifndef TOOLS_UPPER_BOUND_HPP
#define TOOLS_UPPER_BOUND_HPP

#include <iterator>
#include <algorithm>

namespace tools {

  template <class ForwardIterator, class T>
  auto upper_bound(ForwardIterator first, ForwardIterator last, const T& value) {
    return ::std::distance(first, ::std::upper_bound(first, last, value));
  }

  template <class ForwardIterator, class T, class Compare>
  auto upper_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare comp) {
    return ::std::distance(first, ::std::upper_bound(first, last, value, comp));
  }
}

#endif
