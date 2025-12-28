// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/agc002/tasks/agc002_d

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/partially_persistent_dsu.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const int N = 5;
  const int M = 6;
  tools::partially_persistent_dsu dsu(N);
  dsu.merge(1, 2);
  dsu.merge(3, 4);
  dsu.merge(0, 1);
  dsu.merge(0, 2);
  dsu.merge(0, 3);
  dsu.merge(0, 4);

  const auto query = [&](const int x, const int y, const int z) {
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
    return ok;
  };

  assert_that(query(1, 3, 3) == 1);
  assert_that(query(1, 3, 4) == 2);
  assert_that(query(1, 3, 5) == 3);
  assert_that(query(0, 2, 3) == 1);
  assert_that(query(0, 2, 4) == 5);
  assert_that(query(0, 2, 5) == 5);

  return 0;
}
