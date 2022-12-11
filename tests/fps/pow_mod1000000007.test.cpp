#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/fps.hpp"

using ll = long long;
using mint = atcoder::modint1000000007;

void solve(const tools::fps<mint>& a, const ll M, const tools::fps<mint>& expected) {
  assert_that(expected == a.pow(M));
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  solve(tools::fps<mint>{0, 0, 9, 12}, 3, tools::fps<mint>{0, 0, 0, 0});
  solve(tools::fps<mint>{1, 1}, 2, tools::fps<mint>{1, 2});
  solve(tools::fps<mint>{0, 0}, 0, tools::fps<mint>{1, 0});
  solve(tools::fps<mint>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 536870912, tools::fps<mint>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  solve(tools::fps<mint>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 576460752303423488, tools::fps<mint>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

  std::cout << "Hello World" << '\n';
  return 0;
}
