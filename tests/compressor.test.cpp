// competitive-verifier: STANDALONE

#include <iostream>
#include <ranges>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/compressor.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    tools::compressor<int> cp(std::vector<int>{3, -1, 2, 2});
    assert_that(cp.size() == 3);
    assert_that(cp.compress(-1) == 0);
    assert_that(cp.compress(2) == 1);
    assert_that(cp.compress(3) == 2);
    assert_that(cp.decompress(0) == -1);
    assert_that(cp.decompress(1) == 2);
    assert_that(cp.decompress(2) == 3);
    assert_that(cp.contains(-1));
    assert_that(!cp.contains(0));
    assert_that(!cp.contains(1));
    assert_that(cp.contains(2));
    assert_that(cp.contains(3));
    assert_that(!cp.contains(4));
    assert_that(std::distance(cp.begin(), cp.end()) == 3);
    assert_that(cp.begin()[0] == -1);
    assert_that(cp.begin()[1] == 2);
    assert_that(cp.begin()[2] == 3);
  }
  {
    tools::compressor<int> cp(std::vector<int>{});
    assert_that(cp.size() == 0);
    assert_that(!cp.contains(0));
    assert_that(!cp.contains(1));
    assert_that(std::distance(cp.begin(), cp.end()) == 0);
  }
  {
    tools::compressor<int> cp(std::views::iota(0, 200000));
    assert_that(cp.size() == 200000);
    for (int i = 0; i < 200000; ++i) {
      assert_that(cp.compress(i) == i);
      assert_that(cp.decompress(i) == i);
      assert_that(cp.contains(i));
    }
  }

  return 0;
}
