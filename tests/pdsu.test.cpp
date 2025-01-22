// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/matrix.hpp"
#include "tools/pdsu.hpp"
#include "tools/assert_that.hpp"

using mint = atcoder::modint998244353;

struct group {
  using T = tools::matrix<mint, 2, 2>;
  static T op(const T& x, const T& y) {
    return x * y;
  }
  static T e() {
    return T::e();
  }
  static T inv(const T& x) {
    return *x.inv();
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  tools::pdsu<group> pdsu(N);
  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int u, v, x00, x01, x10, x11;
      std::cin >> u >> v >> x00 >> x01 >> x10 >> x11;
      const tools::matrix<mint, 2, 2> x = {
        {mint::raw(x00), mint::raw(x01)},
        {mint::raw(x10), mint::raw(x11)},
      };
      const auto [t, d] = pdsu.diff(u, v);
      assert_that(t != tools::pdsu_diff::inconsistent);
      if (t == tools::pdsu_diff::known) {
        if (d == x) {
          std::cout << 1 << '\n';
        } else {
          std::cout << 0 << '\n';
        }
      } else if (t == tools::pdsu_diff::unknown) {
        std::cout << 1 << '\n';
        pdsu.merge(u, v, x);
      }
    } else {
      int u, v;
      std::cin >> u >> v;
      const auto [t, d] = pdsu.diff(u, v);
      assert_that(t != tools::pdsu_diff::inconsistent);
      if (t == tools::pdsu_diff::known) {
        std::cout << d[0][0].val() << ' ' << d[0][1].val() << ' ' << d[1][0].val() << ' ' << d[1][1].val() << '\n';
      } else if (t == tools::pdsu_diff::unknown) {
        std::cout << -1 << '\n';
      }
    }
  }

  return 0;
}
