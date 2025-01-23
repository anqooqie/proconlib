// competitive-verifier: PROBLEM https://atcoder.jp/contests/agc047/tasks/agc047_a
// competitive-verifier: IGNORE

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "tools/bigdecimal.hpp"
#include "tools/cumsum2d.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<std::string> A(N);
  for (auto& A_i : A) std::cin >> A_i;

  std::array<std::array<ll, 19>, 19> matrix({{}});
  for (const auto& A_i : A) {
    auto A_i_ll = static_cast<ll>(tools::bigdecimal(A_i).multiply_by_pow10(9));
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
  std::cout << answer << std::endl;

  return 0;
}
