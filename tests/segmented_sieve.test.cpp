#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

// Source: https://atcoder.jp/contests/abc227/tasks/abc227_g

#include <cstdint>
#include <unordered_map>
#include <numeric>
#include <iostream>
#include <iterator>
#include "tests/assert_that.hpp"
#include "atcoder/modint.hpp"
#include "tools/segmented_sieve.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

i64 solve1(const i64& N, const i64& K, const tools::segmented_sieve<i64>& sieve) {
  std::unordered_map<i64, i64> nCk;
  for (i64 i = N - K + 1; i <= N; ++i) {
    for (const i64& p : sieve.prime_factor_range(i)) {
      ++nCk[p];
    }
  }
  for (i64 i = 1; i <= K; ++i) {
    for (const i64& p : sieve.prime_factor_range(i)) {
      --nCk[p];
    }
  }
  return std::accumulate(nCk.begin(), nCk.end(), mint(1), [](const mint& prod, const auto& pair) { return prod * mint(pair.second + 1); }).val();
}

i64 solve2(const i64& N, const i64& K, const tools::segmented_sieve<i64>& sieve) {
  std::unordered_map<i64, i64> nCk;
  for (i64 i = N - K + 1; i <= N; ++i) {
    for (const auto& [p, q] : sieve.distinct_prime_factor_range(i)) {
      nCk[p] += q;
    }
  }
  for (i64 i = 1; i <= K; ++i) {
    for (const auto& [p, q] : sieve.distinct_prime_factor_range(i)) {
      nCk[p] -= q;
    }
  }
  return std::accumulate(nCk.begin(), nCk.end(), mint(1), [](const mint& prod, const auto& pair) { return prod * mint(pair.second + 1); }).val();
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    const i64 N = 5;
    const i64 K = 2;
    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);
    assert_that(solve1(N, K, sieve) == 4);
    assert_that(solve2(N, K, sieve) == 4);
  }

  {
    const i64 N = 103;
    const i64 K = 3;
    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);
    assert_that(solve1(N, K, sieve) == 8);
    assert_that(solve2(N, K, sieve) == 8);
  }

  {
    const i64 N = 1000000000000;
    const i64 K = 1000000;
    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);
    assert_that(solve1(N, K, sieve) == 110520107);
    assert_that(solve2(N, K, sieve) == 110520107);

    const auto primes = sieve.prime_range(999999990000, 1000000000000);
    assert_that(std::distance(primes.begin(), primes.end()) == 337);
  }

  {
    const i64 N = 6;
    const i64 K = 3;
    const tools::segmented_sieve<i64> sieve(K, N - K + 1, N);
    assert_that(solve1(N, K, sieve) == 6);
    assert_that(solve2(N, K, sieve) == 6);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
