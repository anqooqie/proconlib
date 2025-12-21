// competitive-verifier: STANDALONE

#include <iostream>
#include "tools/mutable_type.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::mutable_type<int>);
  static_assert(tools::mutable_type<int&>);
  static_assert(tools::mutable_type<int&&>);
  static_assert(!tools::mutable_type<const int>);
  static_assert(!tools::mutable_type<const int&>);
  static_assert(!tools::mutable_type<const int&&>);

  return 0;
}
