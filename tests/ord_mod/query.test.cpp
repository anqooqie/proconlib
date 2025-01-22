// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/pow_mod.hpp"
#include "tools/is_prime.hpp"
#include "tools/ord_mod.hpp"

using ll = long long;

ll naive(const ll x, const ll P) {
  ll m;
  for (m = 1; tools::pow_mod(x, m, P) != 1; ++m);
  return m;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (ll P = 1; P <= 100; ++P) {
    if (!tools::is_prime(P)) continue;
    tools::ord_mod ord_mod(P);
    for (ll x = 1; x < P; ++x) {
      assert_that(ord_mod.query(x) == naive(x, P));
    }
  }

  tools::ord_mod ord_mod(999999999999999989);
  assert_that(ord_mod.query(1) == 1);
  assert_that(ord_mod.query(2) == 999999999999999988);
  assert_that(ord_mod.query(3) == 999999999999999988);
  assert_that(ord_mod.query(4) == 499999999999999994);
  assert_that(ord_mod.query(5) == 249999999999999997);
  assert_that(ord_mod.query(6) == 499999999999999994);
  assert_that(ord_mod.query(7) == 249999999999999997);
  assert_that(ord_mod.query(8) == 999999999999999988);
  assert_that(ord_mod.query(9) == 499999999999999994);
  assert_that(ord_mod.query(10) == 999999999999999988);
  assert_that(ord_mod.query(11) == 499999999999999994);
  assert_that(ord_mod.query(12) == 999999999999999988);
  assert_that(ord_mod.query(13) == 249999999999999997);
  assert_that(ord_mod.query(14) == 999999999999999988);
  assert_that(ord_mod.query(15) == 999999999999999988);
  assert_that(ord_mod.query(16) == 249999999999999997);
  assert_that(ord_mod.query(17) == 249999999999999997);
  assert_that(ord_mod.query(18) == 999999999999999988);
  assert_that(ord_mod.query(19) == 249999999999999997);
  assert_that(ord_mod.query(20) == 499999999999999994);

  std::cout << "Hello World" << '\n';
  return 0;
}
