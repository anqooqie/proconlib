// competitive-verifier: STANDALONE

#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include "tools/assert_that.hpp"
#include "tools/bigint.hpp"
#include "tools/gcd.hpp"

// returns (F(n), F(n+1))
std::pair<tools::bigint, tools::bigint> fib(const int n) {
  assert(n >= 0);
  if (n == 0) {
    return {tools::bigint(0), tools::bigint(1)};
  }
  const auto [a, b] = fib(n / 2);
  const auto c = a * (b * tools::bigint(2) - a);
  const auto d = a * a + b * b;
  if (n & 1) {
    return {d, c + d};
  } else {
    return {c, d};
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int a = -100; a <= 100; ++a) {
    for (int b = -100; b <= 100; ++b) {
      assert_that(tools::gcd(tools::bigint(a), tools::bigint(b)) == tools::bigint(std::gcd(a, b)));
    }
  }

  // F(10^6) ~ 2.0 * 10^208987
  const auto [a, b] = fib(1'000'000);
  assert_that(tools::gcd(a, b) == tools::bigint(1));

  return 0;
}
