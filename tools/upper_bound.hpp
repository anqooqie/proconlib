#ifndef TOOLS_UPPER_BOUND_HPP
#define TOOLS_UPPER_BOUND_HPP

#include <iterator>
#include <algorithm>

namespace tools {

  /**
   * `std::upper_bound`, but returns index
   * License: CC0
   * @author anqooqie
   * @param <ForwardIterator> type of iterator
   * @param <T> type of value
   * @return `std::distance(first, std::upper_bound(first, last, value))`
   */
  template <class ForwardIterator, class T>
  typename ::std::iterator_traits<ForwardIterator>::difference_type upper_bound(ForwardIterator first, ForwardIterator last, const T& value) {
    return ::std::distance(first, ::std::upper_bound(first, last, value));
  }
}

#endif
