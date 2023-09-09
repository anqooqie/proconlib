#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include <iostream>
#include "tools/rectangle_union_area.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  tools::rectangle_union_area<ll> rs;
  for (int i = 0; i < N; ++i) {
    ll l, d, r, u;
    std::cin >> l >> d >> r >> u;
    rs.add_rectangle(l, r, d, u);
  }

  std::cout << rs.query() << '\n';
  return 0;
}
