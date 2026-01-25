// competitive-verifier: STANDALONE

#include <iostream>
#include <string>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/modint.hpp"
#include "tools/modint_for_rolling_hash.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(!tools::modint<int>);
  static_assert(!tools::modint<std::string>);
  static_assert(tools::modint<atcoder::modint998244353>);
  static_assert(tools::modint<atcoder::modint>);
  static_assert(!tools::modint<tools::modint_for_rolling_hash>);
  static_assert(!tools::modint<std::vector<atcoder::modint998244353>>);
  static_assert(!tools::modint<std::vector<atcoder::modint>>);
  static_assert(!tools::modint<std::vector<tools::modint_for_rolling_hash>>);

  static_assert(tools::modint<const atcoder::modint998244353>);
  static_assert(tools::modint<const atcoder::modint>);

  return 0;
}
