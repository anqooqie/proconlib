// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/partition_function

#include <iostream>
#include <ranges>
#include "atcoder/modint.hpp"
#include "tools/partition_function.hpp"
#include "tools/join.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  const auto answers = tools::partition_function::diagonal<mint>(N);
  std::cout << tools::join(answers | std::views::transform([](const auto x) { return x.val(); }), " ") << '\n';

  return 0;
}
