// competitive-verifier: STANDALONE

#include <iostream>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/highly_composite_numbers.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

using ll = long long;
using ull = unsigned long long;

template <typename T>
void test_small(const int max_n) {
  std::vector<int> d(max_n + 1, 0);
  for (int i = 1; i <= max_n; ++i) {
    for (int j = i; j <= max_n; j += i) {
      ++d[j];
    }
  }

  std::vector<std::pair<T, T>> expected;
  for (int n = 1; n <= max_n; ++n) {
    if (expected.empty() || expected.back().second < T(d[n])) {
      expected.emplace_back(T(n), T(d[n]));
    }
    assert_that(tools::highly_composite_numbers(T(n)) == expected);
  }
}

template <typename T>
void test_max(const int expected_size, const T expected_m, const T expected_d) {
  const auto actual = tools::highly_composite_numbers(std::numeric_limits<T>::max());
  assert_that(std::ssize(actual) == expected_size);
  assert_that(actual.back() == std::make_pair(expected_m, expected_d));
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  test_small<signed char>(std::numeric_limits<signed char>::max());
  test_small<unsigned char>(std::numeric_limits<unsigned char>::max());
  test_small<int>(10000);
  test_small<ll>(10000);

  test_max<int>(69, 2095133040, 1600);
  test_max<unsigned int>(73, 3491888400U, 1920U);
  test_max<ll>(167, 9200527969062830400LL, 161280LL);
  test_max<ull>(170, 18401055938125660800ULL, 184320ULL);
  test_max<tools::int128_t>(400, INT128_C(166969507443679424029034031829385299200), INT128_C(286654464));
  test_max<tools::uint128_t>(404, UINT128_C(278282512406132373381723386382308832000), UINT128_C(318504960));

  return 0;
}
