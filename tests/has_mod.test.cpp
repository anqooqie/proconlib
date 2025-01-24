// competitive-verifier: STANDALONE

#include <iostream>
#include <string>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/has_mod.hpp"
#include "tools/modint_for_rolling_hash.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(!tools::has_mod_v<int>);
  assert_that(!tools::has_mod_v<std::string>);
  assert_that(tools::has_mod_v<atcoder::modint998244353>);
  assert_that(tools::has_mod_v<atcoder::modint>);
  assert_that(tools::has_mod_v<tools::modint_for_rolling_hash>);
  assert_that(!tools::has_mod_v<std::vector<atcoder::modint998244353>>);
  assert_that(!tools::has_mod_v<std::vector<atcoder::modint>>);
  assert_that(!tools::has_mod_v<std::vector<tools::modint_for_rolling_hash>>);

  return 0;
}
