// competitive-verifier: STANDALONE

#include <iostream>
#include <limits>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/bigint.hpp"
#include "tools/int128_t.hpp"
#include "tools/monoid.hpp"
#include "tools/uint128_t.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::monoid::bit_and<bool>::op(false, true) == false);
  assert_that(tools::monoid::bit_and<bool>::e() == true);
  assert_that(tools::monoid::bit_and<short>::op(3, 5) == 1);
  assert_that(tools::monoid::bit_and<short>::e() == std::numeric_limits<short>::max());
  assert_that(tools::monoid::bit_and<unsigned short>::op(3U, 5U) == 1U);
  assert_that(tools::monoid::bit_and<unsigned short>::e() == std::numeric_limits<unsigned short>::max());
  assert_that(tools::monoid::bit_and<int>::op(3, 5) == 1);
  assert_that(tools::monoid::bit_and<int>::e() == std::numeric_limits<int>::max());
  assert_that(tools::monoid::bit_and<unsigned int>::op(3U, 5U) == 1U);
  assert_that(tools::monoid::bit_and<unsigned int>::e() == std::numeric_limits<unsigned int>::max());
  assert_that(tools::monoid::bit_and<long>::op(3L, 5L) == 1L);
  assert_that(tools::monoid::bit_and<long>::e() == std::numeric_limits<long>::max());
  assert_that(tools::monoid::bit_and<unsigned long>::op(3UL, 5UL) == 1UL);
  assert_that(tools::monoid::bit_and<unsigned long>::e() == std::numeric_limits<unsigned long>::max());
  assert_that(tools::monoid::bit_and<long long>::op(3LL, 5LL) == 1LL);
  assert_that(tools::monoid::bit_and<long long>::e() == std::numeric_limits<long long>::max());
  assert_that(tools::monoid::bit_and<unsigned long long>::op(3ULL, 5ULL) == 1ULL);
  assert_that(tools::monoid::bit_and<unsigned long long>::e() == std::numeric_limits<unsigned long long>::max());
  assert_that(tools::monoid::bit_and<tools::int128_t>::op(INT128_C(3), INT128_C(5)) == INT128_C(1));
  assert_that(tools::monoid::bit_and<tools::int128_t>::e() == std::numeric_limits<tools::int128_t>::max());
  assert_that(tools::monoid::bit_and<tools::uint128_t>::op(UINT128_C(3), UINT128_C(5)) == UINT128_C(1));
  assert_that(tools::monoid::bit_and<tools::uint128_t>::e() == std::numeric_limits<tools::uint128_t>::max());

  assert_that(tools::monoid::bit_or<bool>::op(false, true) == true);
  assert_that(tools::monoid::bit_or<bool>::e() == false);
  assert_that(tools::monoid::bit_or<short>::op(3, 5) == 7);
  assert_that(tools::monoid::bit_or<short>::e() == 0);
  assert_that(tools::monoid::bit_or<unsigned short>::op(3U, 5U) == 7U);
  assert_that(tools::monoid::bit_or<unsigned short>::e() == 0U);
  assert_that(tools::monoid::bit_or<int>::op(3, 5) == 7);
  assert_that(tools::monoid::bit_or<int>::e() == 0);
  assert_that(tools::monoid::bit_or<unsigned int>::op(3U, 5U) == 7U);
  assert_that(tools::monoid::bit_or<unsigned int>::e() == 0U);
  assert_that(tools::monoid::bit_or<long>::op(3L, 5L) == 7L);
  assert_that(tools::monoid::bit_or<long>::e() == 0L);
  assert_that(tools::monoid::bit_or<unsigned long>::op(3UL, 5UL) == 7UL);
  assert_that(tools::monoid::bit_or<unsigned long>::e() == 0UL);
  assert_that(tools::monoid::bit_or<long long>::op(3LL, 5LL) == 7LL);
  assert_that(tools::monoid::bit_or<long long>::e() == 0LL);
  assert_that(tools::monoid::bit_or<unsigned long long>::op(3ULL, 5ULL) == 7ULL);
  assert_that(tools::monoid::bit_or<unsigned long long>::e() == 0ULL);
  assert_that(tools::monoid::bit_or<tools::int128_t>::op(INT128_C(3), INT128_C(5)) == INT128_C(7));
  assert_that(tools::monoid::bit_or<tools::int128_t>::e() == INT128_C(0));
  assert_that(tools::monoid::bit_or<tools::uint128_t>::op(UINT128_C(3), UINT128_C(5)) == UINT128_C(7));
  assert_that(tools::monoid::bit_or<tools::uint128_t>::e() == UINT128_C(0));

  assert_that(tools::monoid::gcd<short>::op(-12, 18) == 6);
  assert_that(tools::monoid::gcd<short>::e() == 0);
  assert_that(tools::monoid::gcd<unsigned short>::op(12U, 18U) == 6U);
  assert_that(tools::monoid::gcd<unsigned short>::e() == 0U);
  assert_that(tools::monoid::gcd<int>::op(-12, 18) == 6);
  assert_that(tools::monoid::gcd<int>::e() == 0);
  assert_that(tools::monoid::gcd<unsigned int>::op(12U, 18U) == 6U);
  assert_that(tools::monoid::gcd<unsigned int>::e() == 0U);
  assert_that(tools::monoid::gcd<long>::op(-12L, 18L) == 6L);
  assert_that(tools::monoid::gcd<long>::e() == 0L);
  assert_that(tools::monoid::gcd<unsigned long>::op(12UL, 18UL) == 6UL);
  assert_that(tools::monoid::gcd<unsigned long>::e() == 0UL);
  assert_that(tools::monoid::gcd<long long>::op(-12LL, 18LL) == 6LL);
  assert_that(tools::monoid::gcd<long long>::e() == 0LL);
  assert_that(tools::monoid::gcd<unsigned long long>::op(12ULL, 18ULL) == 6ULL);
  assert_that(tools::monoid::gcd<unsigned long long>::e() == 0ULL);
  assert_that(tools::monoid::gcd<tools::int128_t>::op(INT128_C(-12), INT128_C(18)) == INT128_C(6));
  assert_that(tools::monoid::gcd<tools::int128_t>::e() == INT128_C(0));
  assert_that(tools::monoid::gcd<tools::uint128_t>::op(UINT128_C(12), UINT128_C(18)) == UINT128_C(6));
  assert_that(tools::monoid::gcd<tools::uint128_t>::e() == UINT128_C(0));
  assert_that(tools::monoid::gcd<tools::bigint>::op(tools::bigint(-12), tools::bigint(18)) == tools::bigint(6));
  assert_that(tools::monoid::gcd<tools::bigint>::e() == tools::bigint(0));

  assert_that(tools::monoid::max<bool>::op(false, true) == true);
  assert_that(tools::monoid::max<bool>::e() == false);
  assert_that(tools::monoid::max<char>::op('a', 'b') == 'b');
  assert_that(tools::monoid::max<char>::e() == std::numeric_limits<char>::min());
  assert_that(tools::monoid::max<short>::op(-1, 1) == 1);
  assert_that(tools::monoid::max<short>::e() == std::numeric_limits<short>::min());
  assert_that(tools::monoid::max<unsigned short>::op(0U, 1U) == 1U);
  assert_that(tools::monoid::max<unsigned short>::e() == 0U);
  assert_that(tools::monoid::max<int>::op(-1, 1) == 1);
  assert_that(tools::monoid::max<int>::e() == std::numeric_limits<int>::min());
  assert_that(tools::monoid::max<unsigned int>::op(0U, 1U) == 1U);
  assert_that(tools::monoid::max<unsigned int>::e() == 0U);
  assert_that(tools::monoid::max<long>::op(-1L, 1L) == 1L);
  assert_that(tools::monoid::max<long>::e() == std::numeric_limits<long>::min());
  assert_that(tools::monoid::max<unsigned long>::op(0UL, 1UL) == 1UL);
  assert_that(tools::monoid::max<unsigned long>::e() == 0UL);
  assert_that(tools::monoid::max<long long>::op(-1LL, 1LL) == 1LL);
  assert_that(tools::monoid::max<long long>::e() == std::numeric_limits<long long>::min());
  assert_that(tools::monoid::max<unsigned long long>::op(0ULL, 1ULL) == 1ULL);
  assert_that(tools::monoid::max<unsigned long long>::e() == 0ULL);
  assert_that(tools::monoid::max<float>::op(-1.0F, 1.0F) == 1.0F);
  assert_that(tools::monoid::max<float>::e() == -std::numeric_limits<float>::infinity());
  assert_that(tools::monoid::max<double>::op(-1.0, 1.0) == 1.0);
  assert_that(tools::monoid::max<double>::e() == -std::numeric_limits<double>::infinity());
  assert_that(tools::monoid::max<long double>::op(-1.0L, 1.0L) == 1.0L);
  assert_that(tools::monoid::max<long double>::e() == -std::numeric_limits<long double>::infinity());
  assert_that(tools::monoid::max<tools::int128_t>::op(INT128_C(-1), INT128_C(1)) == INT128_C(1));
  assert_that(tools::monoid::max<tools::int128_t>::e() == std::numeric_limits<tools::int128_t>::min());
  assert_that(tools::monoid::max<tools::uint128_t>::op(UINT128_C(0), UINT128_C(1)) == UINT128_C(1));
  assert_that(tools::monoid::max<tools::uint128_t>::e() == UINT128_C(0));
  assert_that(tools::monoid::max<int, 42>::op(42, 43) == 43);
  assert_that(tools::monoid::max<int, 42>::e() == 42);

  assert_that(tools::monoid::min<bool>::op(false, true) == false);
  assert_that(tools::monoid::min<bool>::e() == true);
  assert_that(tools::monoid::min<char>::op('a', 'b') == 'a');
  assert_that(tools::monoid::min<char>::e() == std::numeric_limits<char>::max());
  assert_that(tools::monoid::min<short>::op(-1, 1) == -1);
  assert_that(tools::monoid::min<short>::e() == std::numeric_limits<short>::max());
  assert_that(tools::monoid::min<unsigned short>::op(0U, 1U) == 0U);
  assert_that(tools::monoid::min<unsigned short>::e() == std::numeric_limits<unsigned short>::max());
  assert_that(tools::monoid::min<int>::op(-1, 1) == -1);
  assert_that(tools::monoid::min<int>::e() == std::numeric_limits<int>::max());
  assert_that(tools::monoid::min<unsigned int>::op(0U, 1U) == 0U);
  assert_that(tools::monoid::min<unsigned int>::e() == std::numeric_limits<unsigned int>::max());
  assert_that(tools::monoid::min<long>::op(-1L, 1L) == -1L);
  assert_that(tools::monoid::min<long>::e() == std::numeric_limits<long>::max());
  assert_that(tools::monoid::min<unsigned long>::op(0UL, 1UL) == 0UL);
  assert_that(tools::monoid::min<unsigned long>::e() == std::numeric_limits<unsigned long>::max());
  assert_that(tools::monoid::min<long long>::op(-1LL, 1LL) == -1LL);
  assert_that(tools::monoid::min<long long>::e() == std::numeric_limits<long long>::max());
  assert_that(tools::monoid::min<unsigned long long>::op(0ULL, 1ULL) == 0ULL);
  assert_that(tools::monoid::min<unsigned long long>::e() == std::numeric_limits<unsigned long long>::max());
  assert_that(tools::monoid::min<float>::op(-1.0F, 1.0F) == -1.0F);
  assert_that(tools::monoid::min<float>::e() == std::numeric_limits<float>::infinity());
  assert_that(tools::monoid::min<double>::op(-1.0, 1.0) == -1.0);
  assert_that(tools::monoid::min<double>::e() == std::numeric_limits<double>::infinity());
  assert_that(tools::monoid::min<long double>::op(-1.0L, 1.0L) == -1.0L);
  assert_that(tools::monoid::min<long double>::e() == std::numeric_limits<long double>::infinity());
  assert_that(tools::monoid::min<tools::int128_t>::op(INT128_C(-1), INT128_C(1)) == INT128_C(-1));
  assert_that(tools::monoid::min<tools::int128_t>::e() == std::numeric_limits<tools::int128_t>::max());
  assert_that(tools::monoid::min<tools::uint128_t>::op(UINT128_C(0), UINT128_C(1)) == UINT128_C(0));
  assert_that(tools::monoid::min<tools::uint128_t>::e() == std::numeric_limits<tools::uint128_t>::max());
  assert_that(tools::monoid::min<int, 42>::op(41, 42) == 41);
  assert_that(tools::monoid::min<int, 42>::e() == 42);

  assert_that(tools::monoid::multiplies<bool>::op(false, true) == false);
  assert_that(tools::monoid::multiplies<bool>::e() == true);
  assert_that(tools::monoid::multiplies<short>::op(-2, 3) == -6);
  assert_that(tools::monoid::multiplies<short>::e() == 1);
  assert_that(tools::monoid::multiplies<unsigned short>::op(2U, 3U) == 6U);
  assert_that(tools::monoid::multiplies<unsigned short>::e() == 1U);
  assert_that(tools::monoid::multiplies<int>::op(-2, 3) == -6);
  assert_that(tools::monoid::multiplies<int>::e() == 1);
  assert_that(tools::monoid::multiplies<unsigned int>::op(2U, 3U) == 6U);
  assert_that(tools::monoid::multiplies<unsigned int>::e() == 1U);
  assert_that(tools::monoid::multiplies<long>::op(-2L, 3L) == -6L);
  assert_that(tools::monoid::multiplies<long>::e() == 1L);
  assert_that(tools::monoid::multiplies<unsigned long>::op(2UL, 3UL) == 6UL);
  assert_that(tools::monoid::multiplies<unsigned long>::e() == 1UL);
  assert_that(tools::monoid::multiplies<long long>::op(-2LL, 3LL) == -6LL);
  assert_that(tools::monoid::multiplies<long long>::e() == 1LL);
  assert_that(tools::monoid::multiplies<unsigned long long>::op(2ULL, 3ULL) == 6ULL);
  assert_that(tools::monoid::multiplies<unsigned long long>::e() == 1ULL);
  assert_that(tools::monoid::multiplies<float>::op(-2.0F, 3.0F) == -6.0F);
  assert_that(tools::monoid::multiplies<float>::e() == 1.0F);
  assert_that(tools::monoid::multiplies<double>::op(-2.0, 3.0) == -6.0);
  assert_that(tools::monoid::multiplies<double>::e() == 1.0);
  assert_that(tools::monoid::multiplies<long double>::op(-2.0L, 3.0L) == -6.0L);
  assert_that(tools::monoid::multiplies<long double>::e() == 1.0L);
  assert_that(tools::monoid::multiplies<mint>::op(mint::raw(2), mint::raw(3)) == mint::raw(6));
  assert_that(tools::monoid::multiplies<mint>::e() == mint::raw(1));
  assert_that(tools::monoid::multiplies<tools::int128_t>::op(INT128_C(-2), INT128_C(3)) == INT128_C(-6));
  assert_that(tools::monoid::multiplies<tools::int128_t>::e() == INT128_C(1));
  assert_that(tools::monoid::multiplies<tools::uint128_t>::op(UINT128_C(2), UINT128_C(3)) == UINT128_C(6));
  assert_that(tools::monoid::multiplies<tools::uint128_t>::e() == UINT128_C(1));
  assert_that(tools::monoid::multiplies<tools::bigint>::op(tools::bigint(-2), tools::bigint(3)) == tools::bigint(-6));
  assert_that(tools::monoid::multiplies<tools::bigint>::e() == tools::bigint(1));

  assert_that(tools::monoid::update<bool, false>::op(true, false) == true);
  assert_that(tools::monoid::update<bool, false>::op(false, true) == true);
  assert_that(tools::monoid::update<bool, false>::e() == false);
  assert_that(tools::monoid::update<char, '\0'>::op('a', 'b') == 'a');
  assert_that(tools::monoid::update<char, '\0'>::op('\0', 'b') == 'b');
  assert_that(tools::monoid::update<char, '\0'>::e() == '\0');
  assert_that(tools::monoid::update<short, 42>::op(-1, 1) == -1);
  assert_that(tools::monoid::update<short, 42>::op(42, 1) == 1);
  assert_that(tools::monoid::update<short, 42>::e() == 42);
  assert_that(tools::monoid::update<unsigned short, 42U>::op(0U, 1U) == 0U);
  assert_that(tools::monoid::update<unsigned short, 42U>::op(42U, 1U) == 1U);
  assert_that(tools::monoid::update<unsigned short, 42U>::e() == 42U);
  assert_that(tools::monoid::update<int, 42>::op(-1, 1) == -1);
  assert_that(tools::monoid::update<int, 42>::op(42, 1) == 1);
  assert_that(tools::monoid::update<int, 42>::e() == 42);
  assert_that(tools::monoid::update<unsigned int, 42U>::op(0U, 1U) == 0U);
  assert_that(tools::monoid::update<unsigned int, 42U>::op(42U, 1U) == 1U);
  assert_that(tools::monoid::update<unsigned int, 42U>::e() == 42U);
  assert_that(tools::monoid::update<long, 42L>::op(-1L, 1L) == -1L);
  assert_that(tools::monoid::update<long, 42L>::op(42L, 1L) == 1L);
  assert_that(tools::monoid::update<long, 42L>::e() == 42L);
  assert_that(tools::monoid::update<unsigned long, 42UL>::op(0UL, 1UL) == 0UL);
  assert_that(tools::monoid::update<unsigned long, 42UL>::op(42UL, 1UL) == 1UL);
  assert_that(tools::monoid::update<unsigned long, 42UL>::e() == 42UL);
  assert_that(tools::monoid::update<long long, 42LL>::op(-1LL, 1LL) == -1LL);
  assert_that(tools::monoid::update<long long, 42LL>::op(42LL, 1LL) == 1LL);
  assert_that(tools::monoid::update<long long, 42LL>::e() == 42LL);
  assert_that(tools::monoid::update<unsigned long long, 42ULL>::op(0ULL, 1ULL) == 0ULL);
  assert_that(tools::monoid::update<unsigned long long, 42ULL>::op(42ULL, 1ULL) == 1ULL);
  assert_that(tools::monoid::update<unsigned long long, 42ULL>::e() == 42ULL);
  assert_that(tools::monoid::update<tools::int128_t, INT128_C(42)>::op(INT128_C(-1), INT128_C(1)) == INT128_C(-1));
  assert_that(tools::monoid::update<tools::int128_t, INT128_C(42)>::op(INT128_C(42), INT128_C(1)) == INT128_C(1));
  assert_that(tools::monoid::update<tools::int128_t, INT128_C(42)>::e() == INT128_C(42));
  assert_that(tools::monoid::update<tools::uint128_t, UINT128_C(42)>::op(UINT128_C(0), UINT128_C(1)) == UINT128_C(0));
  assert_that(tools::monoid::update<tools::uint128_t, UINT128_C(42)>::op(UINT128_C(42), UINT128_C(1)) == UINT128_C(1));
  assert_that(tools::monoid::update<tools::uint128_t, UINT128_C(42)>::e() == UINT128_C(42));

  return 0;
}
