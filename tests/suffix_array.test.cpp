// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc272/tasks/abc272_f
// competitive-verifier: IGNORE

#include <iostream>
#include <string>
#include "tools/suffix_array.hpp"
#include "tools/chmin.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::string S, T;
  std::cin >> N >> S >> T;

  tools::suffix_array SSTT{S + S, T + T};
  SSTT.erase_if([&](const auto, const auto j) {
    return N <= j;
  });
  for (auto& lcpa_i : SSTT.lcpa) {
    tools::chmin(lcpa_i, N);
  }

  ll answer = 0;
  ll partial_answer = 0;
  for (ll l = 0, r = 0; l < 2 * N; l = r) {
    for (++r; r < 2 * N && SSTT.lcpa[r - 1] == N; ++r);
    for (ll i = l; i < r; ++i) {
      if (SSTT.sa[i].first == 0) ++partial_answer;
    }
    for (ll i = l; i < r; ++i) {
      if (SSTT.sa[i].first == 1) answer += partial_answer;
    }
  }

  std::cout << answer << '\n';
  return 0;
}
