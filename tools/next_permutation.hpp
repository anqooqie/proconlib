#ifndef TOOLS_NEXT_PERMUTATION_HPP
#define TOOLS_NEXT_PERMUTATION_HPP

#include <algorithm>

namespace tools {

  /**
   * lists all permutations
   * License: CC0
   *
   * Usage:
   * ```
   * // 9-choose-3
   * int k = 3;
   * do {
   *   std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;
   * } while(tools::next_permutation(s.begin(), std::next(s.begin(), k), s.end()));
   * ```
   *
   * @author anqooqie
   * @param <Iterator> type of iterators
   * @param first beginning iterator
   * @param k iterator referring end of the target range
   * @param last end iterator
   * @return `true` if the next permutation exists, `false` otherwise
   */
  template <typename Iterator>
  bool next_permutation(const Iterator first, const Iterator k, const Iterator last) {
    ::std::reverse(k, last);
    return ::std::next_permutation(first, end);
  }
}

#endif
