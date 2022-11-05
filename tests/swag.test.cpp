#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/swag.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

struct monoid {
  using T = std::pair<mint, mint>;
  static T op(const T& x, const T& y) {
    return std::make_pair(y.first * x.first, y.first * x.second + y.second);
  }
  static T e() {
    return std::make_pair(mint::raw(1), mint::raw(0));
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll Q;
  std::cin >> Q;
  tools::swag<monoid> swag;
  for (ll q = 0; q < Q; ++q) {
    ll t;
    std::cin >> t;
    if (t == 0) {
      ll a, b;
      std::cin >> a >> b;
      swag.emplace_front(mint::raw(a), mint::raw(b));
    } else if (t == 1) {
      ll a, b;
      std::cin >> a >> b;
      swag.emplace_back(mint::raw(a), mint::raw(b));
    } else if (t == 2) {
      swag.pop_front();
    } else if (t == 3) {
      swag.pop_back();
    } else {
      ll x;
      std::cin >> x;
      const auto& [a, b] = swag.prod();
      std::cout << (a * mint::raw(x) + b).val() << '\n';
    }
  }

  return 0;
}
