#define PROBLEM "https://atcoder.jp/contests/agc002/tasks/agc002_d"

#include <iostream>
#include "tools/partially_persistent_dsu.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  tools::partially_persistent_dsu dsu(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a, --b;
    dsu.merge(a, b);
  }

  int Q;
  std::cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int x, y, z;
    std::cin >> x >> y >> z;
    --x, --y;

    int ng = 0;
    int ok = M;
    while (ok - ng > 1) {
      const auto t = (ng + ok) / 2;
      if (z <= dsu.size(t, x) + (dsu.same(t, x, y) ? 0 : dsu.size(t, y))) {
        ok = t;
      } else {
        ng = t;
      }
    }

    std::cout << ok << '\n';
  }

  return 0;
}
