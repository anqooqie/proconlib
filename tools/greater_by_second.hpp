#ifndef TOOLS_GREATER_BY_SECOND_HPP
#define TOOLS_GREATER_BY_SECOND_HPP

#include <utility>

namespace tools {

  /**
   * `std::greater` by second
   * License: CC0
   *
   * Usage:
   * ```
   * std::vector<std::pair<i64, i64>> a;
   * std::sort(a.begin(), a.end(), tools::greater_by_second());
   * ```
   *
   * @author anqooqie
   */
  class greater_by_second {
  public:
    template <class T1, class T2>
    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1, T2>& y) const {
      return x.second > y.second;
    }
  };
}

#endif
