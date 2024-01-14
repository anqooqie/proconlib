#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include <iostream>
#include <vector>
#include <utility>
#include "atcoder/modint.hpp"
#include "tools/polynomial_interpolation.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<std::pair<mint, mint>> samples(N);
  for (int i = 0; i < N; ++i) {
    int x_i;
    std::cin >> x_i;
    samples[i].first = mint::raw(x_i);
  }
  for (int i = 0; i < N; ++i) {
    int y_i;
    std::cin >> y_i;
    samples[i].second = mint::raw(y_i);
  }

  const auto f = tools::polynomial_interpolation(samples.begin(), samples.end());

  std::cout << f.pbegin()->val();
  for (int i = 1; i < N; ++i) {
    std::cout << ' ' << f.pbegin()[i].val();
  }
  std::cout << '\n';

  return 0;
}
