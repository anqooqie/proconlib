#define PROBLEM "https://yukicoder.me/problems/no/187"

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "atcoder/modint.hpp"
#include "tools/extended_garner.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector<std::pair<ll, ll>> system(N);
  for (ll i = 0; i < N; ++i) {
    std::cin >> system[i].first >> system[i].second;
  }

  const auto answer = tools::extended_garner<atcoder::modint1000000007>(system.begin(), system.end());
  if (!answer) {
    std::cout << -1 << '\n';
    return 0;
  }
  if (std::all_of(system.begin(), system.end(), [](const std::pair<ll, ll>& pair) { return pair.first == 0; })) {
    std::cout << answer->second.val() << '\n';
    return 0;
  }
  std::cout << answer->first.val() << '\n';
  return 0;
}
