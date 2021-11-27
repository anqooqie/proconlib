#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <cstdint>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/swag.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

struct monoid {
  using T = std::pair<mint, mint>;
  static T op(T x, T y) {
    return std::make_pair(y.first * x.first, y.first * x.second + y.second);
  }
  static T e() {
    return std::make_pair(mint(1), mint(0));
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 Q;
  std::cin >> Q;
  tools::swag<monoid> swag;
  for (i64 i = 0; i < Q; ++i) {
    i64 t;
    std::cin >> t;
    if (t == 0) {
      i64 a, b;
      std::cin >> a >> b;
      swag.emplace(mint::raw(a), mint::raw(b));
    } else if (t == 1) {
      swag.pop();
    } else {
      i64 x;
      std::cin >> x;
      const auto& [a, b] = swag.prod();
      std::cout << (a * mint::raw(x) + b).val() << '\n';
    }
  }

  return 0;
}
