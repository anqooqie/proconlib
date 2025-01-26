// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_rectangle_sum

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <iterator>
#include "atcoder/fenwicktree.hpp"
#include "tools/wavelet_matrix.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  tools::wavelet_matrix<int> wm;
  std::vector<int> ws;
  std::queue<int> qts;
  std::queue<std::tuple<int, int, int, int>> q2s;
  for (int i = 0; i < N; ++i) {
    int x, y, w;
    std::cin >> x >> y >> w;
    wm.add_point(x, y);
    ws.push_back(w);
  }
  for (int q = 0; q < Q; ++q) {
    int qt;
    std::cin >> qt;
    if (qt == 0) {
      int x, y, w;
      std::cin >> x >> y >> w;
      wm.add_point(x, y);
      ws.push_back(w);
      qts.push(0);
    } else {
      int l, d, r, u;
      std::cin >> l >> d >> r >> u;
      qts.push(1);
      q2s.emplace(l, d, r, u);
    }
  }

  std::vector<atcoder::fenwick_tree<ll>> fws;
  for (const auto& v : wm.build()) {
    fws.emplace_back(v.size());
    for (int i = 0; i < std::ssize(v); ++i) {
      if (int(v[i]) < N) {
        fws.back().add(i, ws[v[i]]);
      }
    }
  }

  int p = N;
  for (int q = 0; q < Q; ++q) {
    const auto qt = qts.front();
    qts.pop();
    if (qt == 0) {
      for (const auto& [h, i] : wm.apply(p)) {
        fws[h].add(i, ws[p]);
      }
      ++p;
    } else {
      const auto [l, d, r, u] = q2s.front();
      q2s.pop();
      ll answer = 0;
      for (const auto& [h, il, ir] : wm.range_prod(l, r, u)) {
        answer += fws[h].sum(il, ir);
      }
      for (const auto& [h, il, ir] : wm.range_prod(l, r, d)) {
        answer -= fws[h].sum(il, ir);
      }
      std::cout << answer << '\n';
    }
  }

  return 0;
}
