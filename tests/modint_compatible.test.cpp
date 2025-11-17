// competitive-verifier: STANDALONE

#include <iostream>
#include <string>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/modint_compatible.hpp"
#include "tools/modint_for_rolling_hash.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(!tools::modint_compatible<int>);
  static_assert(!tools::modint_compatible<std::string>);
  static_assert(tools::modint_compatible<atcoder::modint998244353>);
  static_assert(tools::modint_compatible<atcoder::modint>);
  static_assert(tools::modint_compatible<tools::modint_for_rolling_hash>);
  static_assert(!tools::modint_compatible<std::vector<atcoder::modint998244353>>);
  static_assert(!tools::modint_compatible<std::vector<atcoder::modint>>);
  static_assert(!tools::modint_compatible<std::vector<tools::modint_for_rolling_hash>>);

  return 0;
}
