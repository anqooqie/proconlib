// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc141/tasks/abc141_e

#include <iostream>
#include <unordered_map>
#include "tools/rolling_hash.hpp"
#include "tools/chmax.hpp"

using ll = long long;
using u64 = std::uint_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N;
  std::string S;
  std::cin >> N >> S;

  tools::rolling_hash hash(S.begin(), S.end());
  ll answer = 0;
  for (ll n = 1; n <= N; ++n) {
    std::unordered_map<u64, ll> leftmost;
    for (ll l = 0; l + n <= N; ++l) {
      const auto h = hash.slice(l, l + n).val();
      if (auto it = leftmost.find(h); it != leftmost.end()) {
        if (it->second <= l - n) {
          answer = n;
          break;
        }
      } else {
        leftmost.emplace(h, l);
      }
    }
  }

  std::cout << answer << '\n';
  return 0;
}
