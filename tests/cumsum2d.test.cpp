#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0560"

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "tools/cumsum2d.hpp"
#include "tools/group.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 M, N, K;
  std::cin >> M >> N >> K;
  std::vector<std::string> map;
  map.reserve(M);
  std::copy_n(std::istream_iterator<std::string>(std::cin), M, std::back_inserter(map));

  std::vector<std::vector<i64>> J(M, std::vector<i64>(N, 0));
  std::vector<std::vector<i64>> O(M, std::vector<i64>(N, 0));
  std::vector<std::vector<i64>> I(M, std::vector<i64>(N, 0));
  for (i64 y = 0; y < M; ++y) {
    for (i64 x = 0; x < N; ++x) {
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

  tools::cumsum2d<tools::group::plus<i64>> J_cumsum(J.begin(), J.end());
  tools::cumsum2d<tools::group::plus<i64>> O_cumsum(O.begin(), O.end());
  tools::cumsum2d<tools::group::plus<i64>> I_cumsum(I.begin(), I.end());

  for (i64 i = 0; i < K; ++i) {
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    --a;
    --b;
    std::cout << J_cumsum.query(b, a, d, c) << ' ' << O_cumsum.query(b, a, d, c) << ' ' << I_cumsum.query(b, a, d, c) << '\n';
  }

  return 0;
}
