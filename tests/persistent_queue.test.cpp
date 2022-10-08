#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <iostream>
#include <vector>
#include "tools/persistent_queue.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::persistent_queue<ll>::buffer buffer;
  std::vector<tools::persistent_queue<ll>> S;
  S.emplace_back(buffer);
  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    ll type;
    std::cin >> type;
    if (type == 0) {
      ll t, x;
      std::cin >> t >> x;
      ++t;
      S.push_back(S[t].push(x));
    } else {
      ll t;
      std::cin >> t;
      ++t;
      std::cout << S[t].front() << '\n';
      S.push_back(S[t].pop());
    }
  }

  return 0;
}
