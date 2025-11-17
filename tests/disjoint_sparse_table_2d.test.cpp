// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/0560

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "tools/disjoint_sparse_table_2d.hpp"
#include "tools/groups.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int M, N, K;
  std::cin >> M >> N >> K;
  std::vector<std::string> map;
  map.reserve(M);
  std::copy_n(std::istream_iterator<std::string>(std::cin), M, std::back_inserter(map));

  auto J = std::vector(M, std::vector<int>(N, 0));
  auto O = std::vector(M, std::vector<int>(N, 0));
  auto I = std::vector(M, std::vector<int>(N, 0));
  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x) {
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

  tools::disjoint_sparse_table_2d<tools::groups::plus<int>> J_dst(J);
  tools::disjoint_sparse_table_2d<tools::groups::plus<int>> O_dst(O);
  tools::disjoint_sparse_table_2d<tools::groups::plus<int>> I_dst(I);

  for (int i = 0; i < K; ++i) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    --a;
    --b;
    std::cout << J_dst.prod(a, c, b, d) << ' ' << O_dst.prod(a, c, b, d) << ' ' << I_dst.prod(a, c, b, d) << '\n';
  }

  return 0;
}
