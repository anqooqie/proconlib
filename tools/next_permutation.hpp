#ifndef TOOLS_NEXT_PERMUTATION_HPP
#define TOOLS_NEXT_PERMUTATION_HPP

#include <algorithm>
#include <iterator>

namespace tools {
  template <std::random_access_iterator Iterator>
  bool next_permutation(const Iterator first, const Iterator k, const Iterator last) {
    std::reverse(k, last);
    return std::next_permutation(first, last);
  }
}

#endif
