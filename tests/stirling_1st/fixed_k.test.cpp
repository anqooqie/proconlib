// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k

#include <iostream>
#include <ranges>
#include "atcoder/modint.hpp"
#include "tools/stirling_1st.hpp"
#include "tools/join.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, K;
  std::cin >> N >> K;

  const auto answer = tools::stirling_1st::fixed_k<mint>(N, K);
  std::cout << tools::join(std::ranges::subrange(answer.begin() + K, answer.end()) | std::views::transform([](const auto x) { return x.val(); }), " ") << '\n';

  return 0;
}
