#ifndef TOOLS_NEXT_COMBINATION_HPP
#define TOOLS_NEXT_COMBINATION_HPP

#include <algorithm>

namespace tools {

  /**
   * lists all combinations
   * License: CC BY-SA 3.0
   * Reference: Stack Overflow ( https://stackoverflow.com/questions/5095407/all-combinations-of-k-elements-out-of-n/5097100#5097100 )
   *
   * Usage:
   * ```
   * // 9-choose-3
   * int k = 3;
   * do {
   *   std::cout << std::string(s.begin(), std::next(s.begin(), k)) << std::endl;
   * } while(tools::next_combination(s.begin(), std::next(s.begin(), k), s.end()));
   * ```
   *
   * @author Thomas Draper
   * @param <Iterator> type of iterators
   * @param first beginning iterator
   * @param k iterator referring end of the target range
   * @param last end iterator
   * @return `true` if the next combination exists, `false` otherwise
   */
  template <typename Iterator>
  bool next_combination(const Iterator first, Iterator k, const Iterator last) {
    if ((first == last) || (first == k) || (last == k)) return false;
    Iterator itr1 = first;
    Iterator itr2 = last;
    ++itr1;
    if (last == itr1) return false;
    itr1 = last;
    --itr1;
    itr1 = k;
    --itr2;
    while (first != itr1) {
      if (*--itr1 < *itr2) {
        Iterator j = k;
        while (!(*itr1 < *j)) ++j;
        ::std::iter_swap(itr1, j);
        ++itr1;
        ++j;
        itr2 = k;
        ::std::rotate(itr1, j, last);
        while (last != j) {
          ++j;
          ++itr2;
        }
        ::std::rotate(k, itr2, last);
        return true;
      }
    }
    ::std::rotate(first, k, last);
    return false;
  }
}

#endif
