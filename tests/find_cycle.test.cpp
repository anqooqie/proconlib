#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "tools/assert_that.hpp"
#include "atcoder/modint.hpp"
#include "tools/find_cycle.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  using mint12 = atcoder::static_modint<12>;
  using mint13 = atcoder::static_modint<13>;
  using pair = std::pair<long long, long long>;

  assert_that(tools::find_cycle(mint12(0), [](const auto& x) { return x * mint12(0); }) == pair(0, 1));
  assert_that(tools::find_cycle(mint12(1), [](const auto& x) { return x * mint12(1); }) == pair(0, 1));
  assert_that(tools::find_cycle(mint12(2), [](const auto& x) { return x * mint12(2); }) == pair(1, 2));
  assert_that(tools::find_cycle(mint12(3), [](const auto& x) { return x * mint12(3); }) == pair(0, 2));
  assert_that(tools::find_cycle(mint12(4), [](const auto& x) { return x * mint12(4); }) == pair(0, 1));
  assert_that(tools::find_cycle(mint12(5), [](const auto& x) { return x * mint12(5); }) == pair(0, 2));
  assert_that(tools::find_cycle(mint12(6), [](const auto& x) { return x * mint12(6); }) == pair(1, 1));
  assert_that(tools::find_cycle(mint12(7), [](const auto& x) { return x * mint12(7); }) == pair(0, 2));
  assert_that(tools::find_cycle(mint12(8), [](const auto& x) { return x * mint12(8); }) == pair(0, 2));
  assert_that(tools::find_cycle(mint12(9), [](const auto& x) { return x * mint12(9); }) == pair(0, 1));
  assert_that(tools::find_cycle(mint12(10), [](const auto& x) { return x * mint12(10); }) == pair(1, 1));
  assert_that(tools::find_cycle(mint12(11), [](const auto& x) { return x * mint12(11); }) == pair(0, 2));

  assert_that(tools::find_cycle(mint13(0), [](const auto& x) { return x * mint13(0); }) == pair(0, 1));
  assert_that(tools::find_cycle(mint13(1), [](const auto& x) { return x * mint13(1); }) == pair(0, 1));
  assert_that(tools::find_cycle(mint13(2), [](const auto& x) { return x * mint13(2); }) == pair(0, 12));
  assert_that(tools::find_cycle(mint13(3), [](const auto& x) { return x * mint13(3); }) == pair(0, 3));
  assert_that(tools::find_cycle(mint13(4), [](const auto& x) { return x * mint13(4); }) == pair(0, 6));
  assert_that(tools::find_cycle(mint13(5), [](const auto& x) { return x * mint13(5); }) == pair(0, 4));
  assert_that(tools::find_cycle(mint13(6), [](const auto& x) { return x * mint13(6); }) == pair(0, 12));
  assert_that(tools::find_cycle(mint13(7), [](const auto& x) { return x * mint13(7); }) == pair(0, 12));
  assert_that(tools::find_cycle(mint13(8), [](const auto& x) { return x * mint13(8); }) == pair(0, 4));
  assert_that(tools::find_cycle(mint13(9), [](const auto& x) { return x * mint13(9); }) == pair(0, 3));
  assert_that(tools::find_cycle(mint13(10), [](const auto& x) { return x * mint13(10); }) == pair(0, 6));
  assert_that(tools::find_cycle(mint13(11), [](const auto& x) { return x * mint13(11); }) == pair(0, 12));
  assert_that(tools::find_cycle(mint13(12), [](const auto& x) { return x * mint13(12); }) == pair(0, 2));

  std::cout << "Hello World" << '\n';
  return 0;
}
