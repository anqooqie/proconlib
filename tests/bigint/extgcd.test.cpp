// competitive-verifier: STANDALONE

#include <iostream>
#include <utility>
#include "tools/abs.hpp"
#include "tools/assert_that.hpp"
#include "tools/bigint.hpp"
#include "tools/extgcd.hpp"
#include "tools/gcd.hpp"

using B = tools::bigint;

// returns (F(n), F(n+1))
std::pair<B, B> fib(const int n) {
  assert(n >= 0);
  if (n == 0) {
    return {B(0), B(1)};
  }
  const auto [a, b] = fib(n / 2);
  const auto c = a * (b * B(2) - a);
  const auto d = a * a + b * b;
  if (n & 1) {
    return {d, c + d};
  } else {
    return {c, d};
  }
}

void verify(const B& a, const B& b) {
  const auto [x, y, gcd] = tools::extgcd(a, b);

  // Bezout identity
  assert_that(a * x + b * y == gcd);

  // Correct GCD value
  assert_that(gcd == tools::gcd(a, b));

  // GCD is non-negative
  assert_that(gcd >= B(0));

  // Coefficient bounds (when gcd != 0)
  if (gcd != B(0)) {
    const auto abs_b_over_2g = tools::abs(b) / (gcd * B(2));
    const auto abs_a_over_2g = tools::abs(a) / (gcd * B(2));
    assert_that(tools::abs(x) <= std::max(B(1), abs_b_over_2g));
    assert_that(tools::abs(y) <= std::max(B(1), abs_a_over_2g));
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // 1. Small exhaustive
  for (int a = -50; a <= 50; ++a) {
    for (int b = -50; b <= 50; ++b) {
      verify(B(a), B(b));
    }
  }
  std::cerr << "Small exhaustive: OK" << std::endl;

  // 2. Large coprime pair: F(100000) and F(100001)
  {
    const auto [a, b] = fib(100'000);
    verify(a, b);
    const auto [x, y, gcd] = tools::extgcd(a, b);
    assert_that(gcd == B(1));
  }
  std::cerr << "Large coprime: OK" << std::endl;

  // 3. Large non-trivial GCD: k * F(100000) and k * F(100001) where k = F(1000)
  {
    const auto [f0, f1] = fib(100'000);
    const auto [k, _] = fib(1'000);
    const auto a = k * f0;
    const auto b = k * f1;
    verify(a, b);
    const auto [x, y, gcd] = tools::extgcd(a, b);
    assert_that(gcd == k);
  }
  std::cerr << "Large non-trivial GCD: OK" << std::endl;

  // 4. Asymmetric magnitudes: F(100000) and 7
  {
    const auto [a, _] = fib(100'000);
    verify(a, B(7));
    verify(B(7), a);
  }
  std::cerr << "Asymmetric magnitudes: OK" << std::endl;

  // 5. Both zero
  {
    const auto [x, y, gcd] = tools::extgcd(B(0), B(0));
    assert_that(gcd == B(0));
    assert_that(B(0) * x + B(0) * y == gcd);
  }
  std::cerr << "Both zero: OK" << std::endl;

  return 0;
}
