#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/bell.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const int N = 100;
  const auto actual = tools::bell::diagonal<mint>(100);
  const auto expected = tools::bell::all<mint>(100, 100);
  for (int n = 0; n <= N; ++n) {
    assert_that(actual[n] == expected[n][n]);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
