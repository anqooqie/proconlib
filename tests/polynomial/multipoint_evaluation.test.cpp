// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/multipoint_evaluation

#include <iostream>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/polynomial.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::polynomial<mint> f(N);
  for (int i = 0; i < N; ++i) {
    int c_i;
    std::cin >> c_i;
    f[i] = mint::raw(c_i);
  }
  std::vector<mint> p(M);
  for (int i = 0; i < M; ++i) {
    int p_i;
    std::cin >> p_i;
    p[i] = mint::raw(p_i);
  }

  const auto v = f.multipoint_evaluation(p.begin(), p.end());

  std::cout << v[0].val();
  for (int i = 1; i < M; ++i) {
    std::cout << ' ' << v[i].val();
  }
  std::cout << '\n';

  return 0;
}
