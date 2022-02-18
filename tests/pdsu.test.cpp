#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"

#include <cstdint>
#include <iostream>
#include "tools/pdsu.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n, q;
  std::cin >> n >> q;
  tools::pdsu pdsu(n);
  for (i64 i = 0; i < q; ++i) {
    i64 t;
    std::cin >> t;
    if (t == 0) {
      i64 x, y, z;
      std::cin >> x >> y >> z;
      if (pdsu.same(x, y)) {
        assert(pdsu.diff(x, y) == z);
      } else {
        pdsu.merge(x, y, z);
      }
    } else {
      i64 x, y;
      std::cin >> x >> y;
      if (pdsu.same(x, y)) {
        std::cout << pdsu.diff(x, y) << '\n';
      } else {
        std::cout << "?" << '\n';
      }
    }
  }

  return 0;
}
