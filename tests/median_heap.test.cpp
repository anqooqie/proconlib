// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc127/tasks/abc127_f

#include <iostream>
#include "tools/median_heap.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll Q;
  std::cin >> Q;

  tools::median_heap<ll> heap;
  ll min = 0;
  for (ll i = 0; i < Q; ++i) {
    ll t;
    std::cin >> t;
    if (t == 1) {
      ll a, b;
      std::cin >> a >> b;

      const bool uses_prev_median = heap.size() % 2 == 1 && a < heap.lesser();
      if (uses_prev_median) {
        min += std::abs(heap.lesser() - a) + b;
      }
      heap.push(a);
      if (!uses_prev_median) {
        min += std::abs(heap.lesser() - a) + b;
      }
    } else {
      std::cout << heap.lesser() << ' ' << min << '\n';
    }
  }

  return 0;
}
