// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc236/tasks/abc236_d

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include "tools/chmax.hpp"
#include "tools/next_matching.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;

  auto A = std::vector(2 * N, std::vector<ll>(2 * N));
  for (ll i = 0; i < 2 * N; ++i) {
    for (ll j = i + 1; j < 2 * N; ++j) {
      std::cin >> A[i][j];
      A[j][i] = A[i][j];
    }
  }

  std::vector<ll> pattern(2 * N);
  std::iota(pattern.begin(), pattern.end(), 0);

  ll answer = std::numeric_limits<int>::min();
  do {
    ll possible_answer = 0;
    for (ll i = 0; i < 2 * N; i += 2) {
      possible_answer ^= A[pattern[i]][pattern[i + 1]];
    }
    tools::chmax(answer, possible_answer);
  } while (tools::next_matching(pattern.begin(), pattern.end()));

  std::cout << answer << '\n';
  return 0;
}
