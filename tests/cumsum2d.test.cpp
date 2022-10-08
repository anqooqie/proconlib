#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0560"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "tools/cumsum2d.hpp"
#include "tools/group.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll M, N, K;
  std::cin >> M >> N >> K;
  std::vector<std::string> map;
  map.reserve(M);
  std::copy_n(std::istream_iterator<std::string>(std::cin), M, std::back_inserter(map));

  std::vector<std::vector<ll>> J(M, std::vector<ll>(N, 0));
  std::vector<std::vector<ll>> O(M, std::vector<ll>(N, 0));
  std::vector<std::vector<ll>> I(M, std::vector<ll>(N, 0));
  for (ll y = 0; y < M; ++y) {
    for (ll x = 0; x < N; ++x) {
      switch (map[y][x]) {
      case 'J':
        ++J[y][x];
        break;
      case 'O':
        ++O[y][x];
        break;
      case 'I':
        ++I[y][x];
        break;
      }
    }
  }

  tools::cumsum2d<tools::group::plus<ll>> J_cumsum(J);
  tools::cumsum2d<tools::group::plus<ll>> O_cumsum(O);
  tools::cumsum2d<tools::group::plus<ll>> I_cumsum(I);

  for (ll i = 0; i < K; ++i) {
    ll a, b, c, d;
    std::cin >> a >> b >> c >> d;
    --a;
    --b;
    std::cout << J_cumsum.query(a, c, b, d) << ' ' << O_cumsum.query(a, c, b, d) << ' ' << I_cumsum.query(a, c, b, d) << '\n';
  }

  return 0;
}
