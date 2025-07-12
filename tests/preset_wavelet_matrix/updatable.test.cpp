// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_rectangle_sum

#include <iostream>
#include <queue>
#include <tuple>
#include "tools/preset_wavelet_matrix.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  tools::preset_wavelet_matrix<int, ll, true> wm;
  std::queue<int> qts;
  std::queue<int> q1s;
  std::queue<std::tuple<int, int, int, int>> q2s;
  for (int i = 0; i < N; ++i) {
    int x, y, w;
    std::cin >> x >> y >> w;
    wm.add_point(x, y, w);
  }
  for (int q = 0; q < Q; ++q) {
    int qt;
    std::cin >> qt;
    if (qt == 0) {
      int x, y, w;
      std::cin >> x >> y >> w;
      wm.add_point(x, y, 0);
      qts.push(0);
      q1s.push(w);
    } else {
      int l, d, r, u;
      std::cin >> l >> d >> r >> u;
      qts.push(1);
      q2s.emplace(l, d, r, u);
    }
  }

  wm.build();

  int p = N;
  for (int q = 0; q < Q; ++q) {
    const auto qt = qts.front();
    qts.pop();
    if (qt == 0) {
      const auto w = q1s.front();
      q1s.pop();
      wm.set_weight(p, w);
      ++p;
    } else {
      const auto [l, d, r, u] = q2s.front();
      q2s.pop();
      std::cout << wm.range_sum(l, r, d, u) << '\n';
    }
  }

  return 0;
}
