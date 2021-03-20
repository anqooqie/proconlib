#ifndef TOOLS_LESS_BY_FIRST_HPP
#define TOOLS_LESS_BY_FIRST_HPP

#include <utility>

namespace tools {

  /**
   * `std::less` by first
   * License: CC0
   *
   * Usage:
   * ```
   * std::vector<std::pair<i64, i64>> a;
   * std::sort(a.begin(), a.end(), tools::less_by_first());
   * ```
   *
   * @author anqooqie
   */
  class less_by_first {
  public:
    template <class T1, class T2>
    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1, T2>& y) const {
      return x.first < y.first;
    }
  };
}

#endif
