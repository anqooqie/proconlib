#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_C"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "tools/compressor.hpp"
#include "tools/wavelet_matrix.hpp"
#include "tools/less_by_get.hpp"
#include "tools/lower_bound.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  std::vector<ll> xs, ys_raw;
  std::vector<std::tuple<ll, ll, ll>> ps;
  for (ll i = 0; i < n; ++i) {
    ll x, y;
    std::cin >> x >> y;
    xs.push_back(x);
    ys_raw.push_back(y);
    ps.emplace_back(y, x, i);
  }

  std::sort(xs.begin(), xs.end());
  tools::compressor<ll> ys(ys_raw.begin(), ys_raw.end());

  tools::wavelet_matrix<ll> wm(n);
  std::sort(ps.begin(), ps.end(), tools::less_by_get<1>());
  for (ll i = 0; i < n; ++i) {
    wm.set(i, ys.compress(std::get<0>(ps[i])));
  }
  wm.build();

  std::sort(ps.begin(), ps.end());

  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    ll sx, tx, sy, ty;
    std::cin >> sx >> tx >> sy >> ty;
    ++tx, ++ty;

    std::vector<ll> answers;
    const auto l = tools::lower_bound(xs.begin(), xs.end(), sx);
    const auto r = tools::lower_bound(xs.begin(), xs.end(), tx);
    for (ll yc, y = sy; (yc = wm.next_value(l, r, tools::lower_bound(ys.begin(), ys.end(), y))) >= 0 && (y = ys.decompress(yc)) < ty; ++y) {
      for (auto it = std::lower_bound(ps.begin(), ps.end(), std::make_tuple(y, sx, 0)); it != ps.end() && std::get<0>(*it) == y && std::get<1>(*it) < tx; ++it) {
        answers.push_back(std::get<2>(*it));
      }
    }

    std::sort(answers.begin(), answers.end());
    for (const auto answer : answers) {
      std::cout << answer << '\n';
    }
    std::cout << '\n';
  }

  return 0;
}
