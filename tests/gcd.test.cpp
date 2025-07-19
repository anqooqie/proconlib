// competitive-verifier: STANDALONE

#include <cstdint>
#include <iostream>
#include <type_traits>
#include <utility>
#include "tools/assert_that.hpp"
#include "tools/bigint.hpp"
#include "tools/gcd.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int32_t>(), std::declval<std::int32_t>())), std::int32_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int32_t>(), std::declval<std::uint32_t>())), std::uint32_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int32_t>(), std::declval<std::int64_t>())), std::int64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int32_t>(), std::declval<std::uint64_t>())), std::uint64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int32_t>(), std::declval<tools::int128_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int32_t>(), std::declval<tools::uint128_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int32_t>(), std::declval<tools::bigint>())), tools::bigint>);

  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint32_t>(), std::declval<std::int32_t>())), std::uint32_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint32_t>(), std::declval<std::uint32_t>())), std::uint32_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint32_t>(), std::declval<std::int64_t>())), std::int64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint32_t>(), std::declval<std::uint64_t>())), std::uint64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint32_t>(), std::declval<tools::int128_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint32_t>(), std::declval<tools::uint128_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint32_t>(), std::declval<tools::bigint>())), tools::bigint>);

  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int64_t>(), std::declval<std::int32_t>())), std::int64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int64_t>(), std::declval<std::uint32_t>())), std::int64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int64_t>(), std::declval<std::int64_t>())), std::int64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int64_t>(), std::declval<std::uint64_t>())), std::uint64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int64_t>(), std::declval<tools::int128_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int64_t>(), std::declval<tools::uint128_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::int64_t>(), std::declval<tools::bigint>())), tools::bigint>);

  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint64_t>(), std::declval<std::int32_t>())), std::uint64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint64_t>(), std::declval<std::uint32_t>())), std::uint64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint64_t>(), std::declval<std::int64_t>())), std::uint64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint64_t>(), std::declval<std::uint64_t>())), std::uint64_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint64_t>(), std::declval<tools::int128_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint64_t>(), std::declval<tools::uint128_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<std::uint64_t>(), std::declval<tools::bigint>())), tools::bigint>);

  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::int128_t>(), std::declval<std::int32_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::int128_t>(), std::declval<std::uint32_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::int128_t>(), std::declval<std::int64_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::int128_t>(), std::declval<std::uint64_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::int128_t>(), std::declval<tools::int128_t>())), tools::int128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::int128_t>(), std::declval<tools::uint128_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::int128_t>(), std::declval<tools::bigint>())), tools::bigint>);

  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::uint128_t>(), std::declval<std::int32_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::uint128_t>(), std::declval<std::uint32_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::uint128_t>(), std::declval<std::int64_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::uint128_t>(), std::declval<std::uint64_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::uint128_t>(), std::declval<tools::int128_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::uint128_t>(), std::declval<tools::uint128_t>())), tools::uint128_t>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::uint128_t>(), std::declval<tools::bigint>())), tools::bigint>);

  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::bigint>(), std::declval<std::int32_t>())), tools::bigint>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::bigint>(), std::declval<std::uint32_t>())), tools::bigint>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::bigint>(), std::declval<std::int64_t>())), tools::bigint>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::bigint>(), std::declval<std::uint64_t>())), tools::bigint>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::bigint>(), std::declval<tools::int128_t>())), tools::bigint>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::bigint>(), std::declval<tools::uint128_t>())), tools::bigint>);
  static_assert(std::is_same_v<decltype(tools::gcd(std::declval<tools::bigint>(), std::declval<tools::bigint>())), tools::bigint>);

  assert_that(tools::gcd(INT32_C(12), INT32_C(18)) == INT32_C(6));
  assert_that(tools::gcd(INT32_C(12), UINT32_C(18)) == UINT32_C(6));
  assert_that(tools::gcd(INT32_C(12), INT64_C(18)) == INT64_C(6));
  assert_that(tools::gcd(INT32_C(12), UINT64_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(INT32_C(12), INT128_C(18)) == INT128_C(6));
  assert_that(tools::gcd(INT32_C(12), UINT128_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(INT32_C(12), tools::bigint(18)) == tools::bigint(6));

  assert_that(tools::gcd(UINT32_C(12), INT32_C(18)) == UINT32_C(6));
  assert_that(tools::gcd(UINT32_C(12), UINT32_C(18)) == UINT32_C(6));
  assert_that(tools::gcd(UINT32_C(12), INT64_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(UINT32_C(12), UINT64_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(UINT32_C(12), INT128_C(18)) == INT128_C(6));
  assert_that(tools::gcd(UINT32_C(12), UINT128_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT32_C(12), tools::bigint(18)) == tools::bigint(6));

  assert_that(tools::gcd(INT64_C(12), INT32_C(18)) == INT64_C(6));
  assert_that(tools::gcd(INT64_C(12), UINT32_C(18)) == INT64_C(6));
  assert_that(tools::gcd(INT64_C(12), INT64_C(18)) == INT64_C(6));
  assert_that(tools::gcd(INT64_C(12), UINT64_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(INT64_C(12), INT128_C(18)) == INT128_C(6));
  assert_that(tools::gcd(INT64_C(12), UINT128_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(INT64_C(12), tools::bigint(18)) == tools::bigint(6));

  assert_that(tools::gcd(UINT64_C(12), INT32_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(UINT64_C(12), UINT32_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(UINT64_C(12), INT64_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(UINT64_C(12), UINT64_C(18)) == UINT64_C(6));
  assert_that(tools::gcd(UINT64_C(12), INT128_C(18)) == INT128_C(6));
  assert_that(tools::gcd(UINT64_C(12), UINT128_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT64_C(12), tools::bigint(18)) == tools::bigint(6));

  assert_that(tools::gcd(INT128_C(12), INT32_C(18)) == INT128_C(6));
  assert_that(tools::gcd(INT128_C(12), UINT32_C(18)) == INT128_C(6));
  assert_that(tools::gcd(INT128_C(12), INT64_C(18)) == INT128_C(6));
  assert_that(tools::gcd(INT128_C(12), UINT64_C(18)) == INT128_C(6));
  assert_that(tools::gcd(INT128_C(12), INT128_C(18)) == INT128_C(6));
  assert_that(tools::gcd(INT128_C(12), UINT128_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(INT128_C(12), tools::bigint(18)) == tools::bigint(6));

  assert_that(tools::gcd(UINT128_C(12), INT32_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT128_C(12), UINT32_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT128_C(12), INT64_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT128_C(12), UINT64_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT128_C(12), INT128_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT128_C(12), UINT128_C(18)) == UINT128_C(6));
  assert_that(tools::gcd(UINT128_C(12), tools::bigint(18)) == tools::bigint(6));

  assert_that(tools::gcd(tools::bigint(12), INT32_C(18)) == tools::bigint(6));
  assert_that(tools::gcd(tools::bigint(12), UINT32_C(18)) == tools::bigint(6));
  assert_that(tools::gcd(tools::bigint(12), INT64_C(18)) == tools::bigint(6));
  assert_that(tools::gcd(tools::bigint(12), UINT64_C(18)) == tools::bigint(6));
  assert_that(tools::gcd(tools::bigint(12), INT128_C(18)) == tools::bigint(6));
  assert_that(tools::gcd(tools::bigint(12), UINT128_C(18)) == tools::bigint(6));
  assert_that(tools::gcd(tools::bigint(12), tools::bigint(18)) == tools::bigint(6));

  return 0;
}
