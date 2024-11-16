#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include <iostream>
#include <algorithm>
#include <iterator>
#include "tools/set.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  tools::set<int> S;
  if (N > 0) std::copy_n(std::istream_iterator<int>(std::cin), N, std::inserter(S, S.end()));

  for (int q = 0; q < Q; ++q) {
    int t, x;
    std::cin >> t >> x;
    if (t == 0) {
      S.insert(x);
    } else if (t == 1) {
      S.erase(x);
    } else if (t == 2) {
      --x;
      const auto it = S.find_by_order(x);
      std::cout << (it != S.end() ? *it : -1) << '\n';
    } else if (t == 3) {
      std::cout << S.order_of_key(x + 1) << '\n';
    } else if (t == 4) {
      const auto it = S.upper_bound(x);
      std::cout << (it != S.begin() ? *std::prev(it) : -1) << '\n';
    } else {
      const auto it = S.lower_bound(x);
      std::cout << (it != S.end() ? *it : -1) << '\n';
    }
  }

  return 0;
}
