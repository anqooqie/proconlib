// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_totient_function

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/fds_with_prefix_sums.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  long long N;
  std::cin >> N;

  const auto inv2 = mint::raw(2).inv();
  std::cout << (
    tools::fds_with_prefix_sums<mint>(N, [&](const long long i) { return mint(i) * mint(i + 1) * inv2; }) /
    tools::fds_with_prefix_sums<mint>(N, [&](const long long i) { return mint(i); })
  ).rbegin()->val() << '\n';

  return 0;
}
