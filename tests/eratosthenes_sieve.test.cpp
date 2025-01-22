// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_primes

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "tools/eratosthenes_sieve.hpp"
#include "tools/join.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, A, B;
  std::cin >> N >> A >> B;

  tools::eratosthenes_sieve<int> sieve(N);

  const auto begin = sieve.prime_range(1, N).begin();
  const auto end = sieve.prime_range(1, N).end();
  const int pi_N = std::distance(begin, end);

  std::vector<int> answers;
  int i = B;
  for (auto it = std::next(begin, std::min(i, pi_N)); it != end; it = std::next(it, std::min(A, pi_N - i)), i = std::min(i + A, pi_N)) {
    answers.push_back(*it);
  }

  std::cout << pi_N << ' ' << answers.size() << '\n';
  std::cout << tools::join(answers.begin(), answers.end(), " ") << '\n';

  return 0;
}
