#ifndef TOOLS_LOWER_BOUND_HPP
#define TOOLS_LOWER_BOUND_HPP

#include <iterator>
#include <algorithm>

namespace tools {

  template <class ForwardIterator, class T>
  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value) {
    return ::std::distance(first, ::std::lower_bound(first, last, value));
  }

  template <class ForwardIterator, class T, class Compare>
  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare comp) {
    return ::std::distance(first, ::std::lower_bound(first, last, value, comp));
  }
}

#endif
