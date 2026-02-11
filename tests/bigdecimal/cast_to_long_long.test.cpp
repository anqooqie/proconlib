// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/agc047/tasks/agc047_a

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/bigdecimal.hpp"
#include "tools/cumsum2d.hpp"

using ll = long long;

ll solve(const std::vector<std::string>& A) {
  std::array<std::array<ll, 19>, 19> matrix{{}};
  for (const auto& A_i : A) {
    auto A_i_ll = static_cast<ll>(tools::bigdecimal(A_i).multiply_inplace_by_pow10(9));
    ll y;
    for (y = 0; y < 18 && A_i_ll % 2 == 0; ++y, A_i_ll /= 2);
    ll x;
    for (x = 0; x < 18 && A_i_ll % 5 == 0; ++x, A_i_ll /= 5);
 
    ++matrix[y][x];
  }

  const auto cumsum = tools::cumsum2d<ll>(matrix);
  auto answer = 0LL;
  for (ll y = 0; y <= 18; ++y) {
    for (ll x = 0; x <= 18; ++x) {
      answer += matrix[y][x] * cumsum.query(18 - y, 19, 18 - x, 19);
    }
  }
  answer -= cumsum.query(9, 19, 9, 19);
  answer /= 2;
  return answer;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve({"7.5", "2.4", "17.000000001", "17", "16.000000000"}) == 3);
  assert_that(solve({"0.9", "1", "1", "1.25", "2.30000", "5", "70", "0.000000001", "9999.999999999", "0.999999999", "1.000000001"}) == 8);

  return 0;
}
