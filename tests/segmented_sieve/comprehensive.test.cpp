// competitive-verifier: STANDALONE

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/segmented_sieve.hpp"

using ll = long long;

bool naive_is_prime(const ll n) {
  if (n < 2) return false;
  for (ll d = 2; d * d <= n; ++d) {
    if (n % d == 0) return false;
  }
  return true;
}

std::vector<ll> naive_prime_factors(ll n) {
  std::vector<ll> result;
  for (ll d = 2; d * d <= n; ++d) {
    while (n % d == 0) {
      result.push_back(d);
      n /= d;
    }
  }
  if (n > 1) result.push_back(n);
  return result;
}

std::map<ll, ll> naive_distinct_prime_factors(ll n) {
  std::map<ll, ll> result;
  for (ll d = 2; d * d <= n; ++d) {
    while (n % d == 0) {
      ++result[d];
      n /= d;
    }
  }
  if (n > 1) ++result[n];
  return result;
}

std::vector<ll> naive_divisors(const ll n) {
  std::vector<ll> result;
  for (ll d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      result.push_back(d);
      if (d != n / d) result.push_back(n / d);
    }
  }
  std::ranges::sort(result);
  return result;
}

ll naive_divisor_count(const ll n) {
  if (n <= 0) return 0;
  ll count = 0;
  for (ll d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      count += (d == n / d) ? 1 : 2;
    }
  }
  return count;
}

void test_sieve(const ll L, const ll R) {
  tools::segmented_sieve sieve(L, R);
  const ll sq = sieve.sqrt_r();

  // sqrt_r, l, r
  assert_that(sq * sq <= R && (sq + 1) * (sq + 1) > R);
  assert_that(sieve.l() == L);
  assert_that(sieve.r() == R);

  // is_prime: small range [1, sqrt_r]
  for (ll n = 1; n <= sq; ++n) {
    assert_that(sieve.is_prime(n) == naive_is_prime(n));
  }

  // is_prime: large range [L, R]
  for (ll n = L; n <= R; ++n) {
    assert_that(sieve.is_prime(n) == naive_is_prime(n));
  }

  // prime_factor_range: small range
  for (ll n = 1; n <= sq; ++n) {
    std::vector<ll> got(sieve.prime_factor_range(n).begin(), sieve.prime_factor_range(n).end());
    std::vector<ll> expected = naive_prime_factors(n);
    std::ranges::sort(got);
    assert_that(got == expected);
  }

  // prime_factor_range: large range
  for (ll n = L; n <= R; ++n) {
    std::vector<ll> got(sieve.prime_factor_range(n).begin(), sieve.prime_factor_range(n).end());
    std::vector<ll> expected = naive_prime_factors(n);
    std::ranges::sort(got);
    assert_that(got == expected);
  }

  // distinct_prime_factor_range: small range
  for (ll n = 1; n <= sq; ++n) {
    std::map<ll, ll> expected = naive_distinct_prime_factors(n);
    std::map<ll, ll> got;
    for (const auto& [p, q, pq] : sieve.distinct_prime_factor_range(n)) {
      got[p] = q;
      ll power = 1;
      for (ll i = 0; i < q; ++i) power *= p;
      assert_that(pq == power);
    }
    assert_that(got == expected);
  }

  // distinct_prime_factor_range: large range
  for (ll n = L; n <= R; ++n) {
    std::map<ll, ll> expected = naive_distinct_prime_factors(n);
    std::map<ll, ll> got;
    for (const auto& [p, q, pq] : sieve.distinct_prime_factor_range(n)) {
      got[p] = q;
      ll power = 1;
      for (ll i = 0; i < q; ++i) power *= p;
      assert_that(pq == power);
    }
    assert_that(got == expected);
  }

  // divisors and sorted_divisors: small range
  for (ll n = 1; n <= sq; ++n) {
    std::vector<ll> expected = naive_divisors(n);
    assert_that(sieve.sorted_divisors(n) == expected);
    std::vector<ll> unsorted = sieve.divisors(n);
    std::ranges::sort(unsorted);
    assert_that(unsorted == expected);
  }

  // divisors and sorted_divisors: large range
  for (ll n = L; n <= R; ++n) {
    std::vector<ll> expected = naive_divisors(n);
    assert_that(sieve.sorted_divisors(n) == expected);
    std::vector<ll> unsorted = sieve.divisors(n);
    std::ranges::sort(unsorted);
    assert_that(unsorted == expected);
  }

  // divisor_counts
  {
    auto [small_dc, large_dc] = sieve.divisor_counts();
    assert_that(static_cast<ll>(small_dc.size()) == sq + 1);
    assert_that(static_cast<ll>(large_dc.size()) == R - L + 1);
    for (ll i = 0; i <= sq; ++i) {
      assert_that(small_dc[i] == naive_divisor_count(i));
    }
    for (ll n = L; n <= R; ++n) {
      assert_that(large_dc[n - L] == naive_divisor_count(n));
    }
  }
}

void test_prime_range(const ll L, const ll R) {
  tools::segmented_sieve sieve(L, R);
  const ll sq = sieve.sqrt_r();
  const bool overlapping = sq + 1 >= L;

  // Helper to get expected primes in [lo, hi]
  auto expected_primes = [&](ll lo, ll hi) {
    std::vector<ll> result;
    for (ll n = lo; n <= hi; ++n) {
      if (naive_is_prime(n)) result.push_back(n);
    }
    return result;
  };

  if (overlapping) {
    // Entirely small
    if (sq >= 2) {
      std::vector<ll> got;
      for (const auto p : sieve.prime_range(1, std::min(sq, R))) got.push_back(p);
      assert_that(got == expected_primes(1, std::min(sq, R)));
    }

    // Entirely large (if range extends beyond sqrt_r)
    if (R > sq) {
      std::vector<ll> got;
      for (const auto p : sieve.prime_range(sq + 1, R)) got.push_back(p);
      assert_that(got == expected_primes(sq + 1, R));
    }

    // Cross-boundary
    if (sq >= 2 && R > sq) {
      std::vector<ll> got;
      for (const auto p : sieve.prime_range(2, R)) got.push_back(p);
      assert_that(got == expected_primes(2, R));
    }

    // Full range
    {
      std::vector<ll> got;
      for (const auto p : sieve.prime_range(1, R)) got.push_back(p);
      assert_that(got == expected_primes(1, R));
    }

    // Subranges around sqrt_r boundary
    if (sq >= 3 && R > sq + 2) {
      std::vector<ll> got;
      for (const auto p : sieve.prime_range(sq - 2, sq + 3)) got.push_back(p);
      assert_that(got == expected_primes(sq - 2, sq + 3));
    }
  } else {
    // Disjoint ranges: can only query within [1, sqrt_r] or [L, R]
    if (sq >= 2) {
      std::vector<ll> got;
      for (const auto p : sieve.prime_range(1, sq)) got.push_back(p);
      assert_that(got == expected_primes(1, sq));
    }
    {
      std::vector<ll> got;
      for (const auto p : sieve.prime_range(L, R)) got.push_back(p);
      assert_that(got == expected_primes(L, R));
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // Edge cases: very small R (small_primes may be empty)
  test_sieve(1, 1);
  test_sieve(1, 2);
  test_sieve(1, 3);
  test_sieve(1, 4);

  // L=1, moderate R (overlapping ranges)
  test_sieve(1, 100);
  test_sieve(1, 200);

  // L>1, still overlapping with small range
  test_sieve(2, 100);
  test_sieve(10, 200);

  // L > sqrt_r (disjoint ranges)
  test_sieve(50, 60);
  test_sieve(9990, 10010);

  // Large values
  test_sieve(999999999990LL, 1000000000000LL);

  // Single element ranges
  test_sieve(1, 1);
  test_sieve(7, 7);
  test_sieve(97, 97);
  test_sieve(100, 100);
  test_sieve(999999999989LL, 999999999989LL);

  // prime_range tests (separate because of constraint differences)
  test_prime_range(1, 1);
  test_prime_range(1, 2);
  test_prime_range(1, 3);
  test_prime_range(1, 4);
  test_prime_range(1, 100);
  test_prime_range(1, 200);
  test_prime_range(2, 100);
  test_prime_range(10, 200);
  test_prime_range(50, 60);
  test_prime_range(9990, 10010);
  test_prime_range(999999999990LL, 1000000000000LL);

  return 0;
}
