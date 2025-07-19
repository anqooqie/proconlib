// competitive-verifier: STANDALONE

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/bigint.hpp"
#include "tools/group.hpp"
#include "tools/int128_t.hpp"
#include "tools/rational.hpp"
#include "tools/uint128_t.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::group::bit_xor<bool>::op(false, true) == true);
  assert_that(tools::group::bit_xor<bool>::e() == false);
  assert_that(tools::group::bit_xor<bool>::inv(true) == true);
  assert_that(tools::group::bit_xor<short>::op(2, 3) == 1);
  assert_that(tools::group::bit_xor<short>::e() == 0);
  assert_that(tools::group::bit_xor<short>::inv(2) == 2);
  assert_that(tools::group::bit_xor<unsigned short>::op(2U, 3U) == 1U);
  assert_that(tools::group::bit_xor<unsigned short>::e() == 0U);
  assert_that(tools::group::bit_xor<unsigned short>::inv(2U) == 2U);
  assert_that(tools::group::bit_xor<int>::op(2, 3) == 1);
  assert_that(tools::group::bit_xor<int>::e() == 0);
  assert_that(tools::group::bit_xor<int>::inv(2) == 2);
  assert_that(tools::group::bit_xor<unsigned int>::op(2U, 3U) == 1U);
  assert_that(tools::group::bit_xor<unsigned int>::e() == 0U);
  assert_that(tools::group::bit_xor<unsigned int>::inv(2U) == 2U);
  assert_that(tools::group::bit_xor<long>::op(2L, 3L) == 1L);
  assert_that(tools::group::bit_xor<long>::e() == 0L);
  assert_that(tools::group::bit_xor<long>::inv(2L) == 2L);
  assert_that(tools::group::bit_xor<unsigned long>::op(2UL, 3UL) == 1UL);
  assert_that(tools::group::bit_xor<unsigned long>::e() == 0UL);
  assert_that(tools::group::bit_xor<unsigned long>::inv(2UL) == 2UL);
  assert_that(tools::group::bit_xor<long long>::op(2LL, 3LL) == 1LL);
  assert_that(tools::group::bit_xor<long long>::e() == 0LL);
  assert_that(tools::group::bit_xor<long long>::inv(2LL) == 2LL);
  assert_that(tools::group::bit_xor<unsigned long long>::op(2ULL, 3ULL) == 1ULL);
  assert_that(tools::group::bit_xor<unsigned long long>::e() == 0ULL);
  assert_that(tools::group::bit_xor<unsigned long long>::inv(2ULL) == 2ULL);
  assert_that(tools::group::bit_xor<tools::int128_t>::op(INT128_C(2), INT128_C(3)) == INT128_C(1));
  assert_that(tools::group::bit_xor<tools::int128_t>::e() == INT128_C(0));
  assert_that(tools::group::bit_xor<tools::int128_t>::inv(INT128_C(2)) == INT128_C(2));
  assert_that(tools::group::bit_xor<tools::uint128_t>::op(UINT128_C(2), UINT128_C(3)) == UINT128_C(1));
  assert_that(tools::group::bit_xor<tools::uint128_t>::e() == UINT128_C(0));
  assert_that(tools::group::bit_xor<tools::uint128_t>::inv(UINT128_C(2)) == UINT128_C(2));

  assert_that(tools::group::multiplies<float>::op(2.0F, 3.0F) == 6.0F);
  assert_that(tools::group::multiplies<float>::e() == 1.0F);
  assert_that(tools::group::multiplies<float>::inv(2.0F) == 0.5F);
  assert_that(tools::group::multiplies<double>::op(2.0, 3.0) == 6.0);
  assert_that(tools::group::multiplies<double>::e() == 1.0);
  assert_that(tools::group::multiplies<double>::inv(2.0) == 0.5);
  assert_that(tools::group::multiplies<long double>::op(2.0L, 3.0L) == 6.0L);
  assert_that(tools::group::multiplies<long double>::e() == 1.0L);
  assert_that(tools::group::multiplies<long double>::inv(2.0L) == 0.5L);
  assert_that(tools::group::multiplies<mint>::op(mint::raw(2), mint::raw(3)) == mint::raw(6));
  assert_that(tools::group::multiplies<mint>::e() == mint::raw(1));
  assert_that(tools::group::multiplies<mint>::inv(mint::raw(2)) == mint::raw(499122177));
  assert_that(tools::group::multiplies<tools::rational>::op(tools::rational(2), tools::rational(3)) == tools::rational(6));
  assert_that(tools::group::multiplies<tools::rational>::e() == tools::rational(1));
  assert_that(tools::group::multiplies<tools::rational>::inv(tools::rational(2)) == tools::rational(1, 2));

  assert_that(tools::group::plus<int>::op(2, 3) == 5);
  assert_that(tools::group::plus<int>::e() == 0);
  assert_that(tools::group::plus<int>::inv(2) == -2);
  assert_that(tools::group::plus<long>::op(2L, 3L) == 5L);
  assert_that(tools::group::plus<long>::e() == 0L);
  assert_that(tools::group::plus<long>::inv(2L) == -2L);
  assert_that(tools::group::plus<long long>::op(2LL, 3LL) == 5LL);
  assert_that(tools::group::plus<long long>::e() == 0LL);
  assert_that(tools::group::plus<long long>::inv(2LL) == -2LL);
  assert_that(tools::group::plus<mint>::op(mint::raw(2), mint::raw(3)) == mint::raw(5));
  assert_that(tools::group::plus<mint>::e() == mint::raw(0));
  assert_that(tools::group::plus<mint>::inv(mint::raw(2)) == mint::raw(998244351));
  assert_that(tools::group::plus<tools::int128_t>::op(INT128_C(2), INT128_C(3)) == INT128_C(5));
  assert_that(tools::group::plus<tools::int128_t>::e() == INT128_C(0));
  assert_that(tools::group::plus<tools::int128_t>::inv(INT128_C(2)) == INT128_C(-2));
  assert_that(tools::group::plus<tools::bigint>::op(tools::bigint(2), tools::bigint(3)) == tools::bigint(5));
  assert_that(tools::group::plus<tools::bigint>::e() == tools::bigint(0));
  assert_that(tools::group::plus<tools::bigint>::inv(tools::bigint(2)) == tools::bigint(-2));
  assert_that(tools::group::plus<tools::rational>::op(tools::rational(2), tools::rational(3)) == tools::rational(5));
  assert_that(tools::group::plus<tools::rational>::e() == tools::rational(0));
  assert_that(tools::group::plus<tools::rational>::inv(tools::rational(2)) == tools::rational(-2));

  return 0;
}
