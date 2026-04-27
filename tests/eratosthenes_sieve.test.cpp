// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_primes

#include <iostream>
#include <ranges>
#include <tuple>
#include <vector>
#include "tools/eratosthenes_sieve.hpp"
#include "tools/join.hpp"
#include "tools/mod.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, A, B;
  std::cin >> N >> A >> B;

  tools::eratosthenes_sieve<int> sieve(N);

  const auto view = sieve.prime_range(1, N);
  const auto pi_N = view.size();
  const auto answers = view
    | std::views::enumerate
    | std::views::filter([&](const auto& tuple) { return tools::mod(std::get<0>(tuple) - B, A) == 0; })
    | std::views::transform([](const auto& tuple) { return std::get<1>(tuple); })
    | std::ranges::to<std::vector>();

  std::cout << pi_N << ' ' << answers.size() << '\n';
  std::cout << tools::join(answers, ' ') << '\n';

  return 0;
}
