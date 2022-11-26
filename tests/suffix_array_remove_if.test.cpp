#define PROBLEM "https://atcoder.jp/contests/abc272/tasks/abc272_f"

#include <iostream>
#include <string>
#include "atcoder/string.hpp"
#include "tools/suffix_array_remove_if.hpp"
#include "tools/chmin.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::string S, T;
  std::cin >> N >> S >> T;

  const auto SSTT = S + S + T + T;
  auto sa = atcoder::suffix_array(SSTT);
  auto lcpa = atcoder::lcp_array(SSTT, sa);

  const auto [sa_end, lcpa_end] = tools::suffix_array_remove_if(sa.begin(), sa.end(), lcpa.begin(), lcpa.end(), [&](const auto sa_i) { return sa_i / N % 2; });
  sa.erase(sa_end, sa.end());
  lcpa.erase(lcpa_end, lcpa.end());

  for (auto& sa_i : sa) {
    if (sa_i >= N) sa_i -= N;
  }
  for (auto& lcpa_i : lcpa) {
    tools::chmin(lcpa_i, N);
  }

  ll answer = 0;
  ll partial_answer = 0;
  for (ll l = 0, r = 0; l < 2 * N; l = r) {
    for (++r; r < 2 * N && lcpa[r - 1] == N; ++r);
    for (ll i = l; i < r; ++i) {
      if (sa[i] < N) ++partial_answer;
    }
    for (ll i = l; i < r; ++i) {
      if (sa[i] >= N) answer += partial_answer;
    }
  }

  std::cout << answer << '\n';
  return 0;
}
