// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/groups.hpp"
#include "tools/monoid.hpp"
#include "tools/monoids.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(!tools::monoid<int>);
  static_assert(tools::monoid<tools::monoids::multiplies<int>>);
  static_assert(tools::monoid<tools::groups::plus<int>>);

  return 0;
}
