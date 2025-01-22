// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc276/tasks/abc276_g

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/fps.hpp"
#include "tools/sparse_fps_pow.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;

  tools::fps<mint> edge{mint(1)};
  edge.resize(M + 1);
  edge.divide_inplace(1, mint(-1));
  edge.divide_inplace(1, mint(-1));

  using p = std::pair<int, mint>;
  const auto center = tools::sparse_fps_pow({p(1, mint(1)), p(2, mint(1))}, {p(0, mint(1)), p(3, mint(-1))}, N - 1, M + 1);

  mint answer(0);
  for (int i = 0; i <= M; ++i) {
    answer += center[i] * edge[M - i];
  }

  std::cout << answer.val() << '\n';
  return 0;
}
