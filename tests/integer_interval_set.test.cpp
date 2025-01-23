// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc228/tasks/abc228_d
// competitive-verifier: IGNORE

#include <iostream>
#include <vector>
#include "tools/pow2.hpp"
#include "tools/integer_interval_set.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const ll N = tools::pow2(20);
  std::vector<ll> A(N, -1);
  tools::integer_interval_set<ll> set;

  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    ll t, x;
    std::cin >> t >> x;
    if (t == 1) {
      const ll h = [&]() -> ll {
        if (auto it = set.find(x % N); it != set.end()) {
          if (it->second == N - 1) {
            if (auto it2 = set.find(0); it2 != set.end()) {
              return it2->second + 1;
            } else {
              return 0;
            }
          } else {
            return it->second + 1;
          }
        } else {
          return x % N;
        }
      }();
      A[h] = x;
      set.insert(h, h);
    } else {
      std::cout << A[x % N] << '\n';
    }
  }

  return 0;
}
