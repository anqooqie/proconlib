#ifndef TOOLS_NEXT_PERMUTATION_HPP
#define TOOLS_NEXT_PERMUTATION_HPP

#include <algorithm>

namespace tools {

  template <typename Iterator>
  bool next_permutation(const Iterator first, const Iterator k, const Iterator last) {
    std::reverse(k, last);
    return std::next_permutation(first, last);
  }
}

#endif
