// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/rectangle_sum

#include <iostream>
#include "tools/preset_wavelet_matrix.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  tools::preset_wavelet_matrix<int, ll, false> wm;
  for (int i = 0; i < N; ++i) {
    int x, y, w;
    std::cin >> x >> y >> w;
    wm.add_point(x, y, w);
  }

  wm.build();

  for (int q = 0; q < Q; ++q) {
    int l, d, r, u;
    std::cin >> l >> d >> r >> u;
    std::cout << wm.range_sum(l, r, d, u) << '\n';
  }

  return 0;
}
