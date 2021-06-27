#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"

#include <cstdint>
#include <iostream>
#include "tools/monoid.hpp"
#include "tools/dual_segtree.hpp"
#include "tools/pow2.hpp"

using i64 = std::int_fast64_t;

int main() {
  i64 n, q;
  std::cin >> n >> q;

  tools::dual_segtree<tools::monoid::update<i64, -1>> dual_segtree(n);
  for (i64 i = 0; i < q; ++i) {
    i64 type;
    std::cin >> type;
    if (type == 0) {
      i64 s, t, x;
      std::cin >> s >> t >> x;
      dual_segtree.apply(s, t + 1, x);
    } else {
      i64 i;
      std::cin >> i;
      std::cout << tools::monoid::update<i64, -1>::op(dual_segtree.get(i), tools::pow2<i64>(31) - 1) << '\n';
    }
  }

  return 0;
}
