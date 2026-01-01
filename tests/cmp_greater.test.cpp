// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/cmp_greater.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(!tools::cmp_greater(-1, 0U));
  static_assert(!tools::cmp_greater(0U, 0U));
  static_assert(tools::cmp_greater(0U, -1));

  return 0;
}
