// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/assert_that.hpp"
#include "tools/bit_floor.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::bit_floor(INT32_C(0)) == INT32_C(0));
  assert_that(tools::bit_floor(INT32_C(1)) == INT32_C(1));
  assert_that(tools::bit_floor(INT32_C(2)) == INT32_C(2));
  assert_that(tools::bit_floor(INT32_C(3)) == INT32_C(2));
  assert_that(tools::bit_floor(INT32_C(4)) == INT32_C(4));
  assert_that(tools::bit_floor(INT32_C(5)) == INT32_C(4));
  assert_that(tools::bit_floor(INT32_C(6)) == INT32_C(4));
  assert_that(tools::bit_floor(INT32_C(7)) == INT32_C(4));
  assert_that(tools::bit_floor(INT32_C(8)) == INT32_C(8));
  assert_that(tools::bit_floor(INT32_C(9)) == INT32_C(8));
  assert_that(tools::bit_floor(INT32_C(10)) == INT32_C(8));
  assert_that(tools::bit_floor(INT32_C(1073741823)) == INT32_C(536870912));
  assert_that(tools::bit_floor(INT32_C(1073741824)) == INT32_C(1073741824));
  assert_that(tools::bit_floor(INT32_C(1073741825)) == INT32_C(1073741824));
  assert_that(tools::bit_floor(INT32_C(2147483647)) == INT32_C(1073741824));

  assert_that(tools::bit_floor(UINT32_C(0)) == UINT32_C(0));
  assert_that(tools::bit_floor(UINT32_C(1)) == UINT32_C(1));
  assert_that(tools::bit_floor(UINT32_C(2)) == UINT32_C(2));
  assert_that(tools::bit_floor(UINT32_C(3)) == UINT32_C(2));
  assert_that(tools::bit_floor(UINT32_C(4)) == UINT32_C(4));
  assert_that(tools::bit_floor(UINT32_C(5)) == UINT32_C(4));
  assert_that(tools::bit_floor(UINT32_C(6)) == UINT32_C(4));
  assert_that(tools::bit_floor(UINT32_C(7)) == UINT32_C(4));
  assert_that(tools::bit_floor(UINT32_C(8)) == UINT32_C(8));
  assert_that(tools::bit_floor(UINT32_C(9)) == UINT32_C(8));
  assert_that(tools::bit_floor(UINT32_C(10)) == UINT32_C(8));
  assert_that(tools::bit_floor(UINT32_C(2147483647)) == UINT32_C(1073741824));
  assert_that(tools::bit_floor(UINT32_C(2147483648)) == UINT32_C(2147483648));
  assert_that(tools::bit_floor(UINT32_C(2147483649)) == UINT32_C(2147483648));
  assert_that(tools::bit_floor(UINT32_C(4294967295)) == UINT32_C(2147483648));

  assert_that(tools::bit_floor(INT64_C(0)) == INT64_C(0));
  assert_that(tools::bit_floor(INT64_C(1)) == INT64_C(1));
  assert_that(tools::bit_floor(INT64_C(2)) == INT64_C(2));
  assert_that(tools::bit_floor(INT64_C(3)) == INT64_C(2));
  assert_that(tools::bit_floor(INT64_C(4)) == INT64_C(4));
  assert_that(tools::bit_floor(INT64_C(5)) == INT64_C(4));
  assert_that(tools::bit_floor(INT64_C(6)) == INT64_C(4));
  assert_that(tools::bit_floor(INT64_C(7)) == INT64_C(4));
  assert_that(tools::bit_floor(INT64_C(8)) == INT64_C(8));
  assert_that(tools::bit_floor(INT64_C(9)) == INT64_C(8));
  assert_that(tools::bit_floor(INT64_C(10)) == INT64_C(8));
  assert_that(tools::bit_floor(INT64_C(4611686018427387903)) == INT64_C(2305843009213693952));
  assert_that(tools::bit_floor(INT64_C(4611686018427387904)) == INT64_C(4611686018427387904));
  assert_that(tools::bit_floor(INT64_C(4611686018427387905)) == INT64_C(4611686018427387904));
  assert_that(tools::bit_floor(INT64_C(9223372036854775807)) == INT64_C(4611686018427387904));

  assert_that(tools::bit_floor(UINT64_C(0)) == UINT64_C(0));
  assert_that(tools::bit_floor(UINT64_C(1)) == UINT64_C(1));
  assert_that(tools::bit_floor(UINT64_C(2)) == UINT64_C(2));
  assert_that(tools::bit_floor(UINT64_C(3)) == UINT64_C(2));
  assert_that(tools::bit_floor(UINT64_C(4)) == UINT64_C(4));
  assert_that(tools::bit_floor(UINT64_C(5)) == UINT64_C(4));
  assert_that(tools::bit_floor(UINT64_C(6)) == UINT64_C(4));
  assert_that(tools::bit_floor(UINT64_C(7)) == UINT64_C(4));
  assert_that(tools::bit_floor(UINT64_C(8)) == UINT64_C(8));
  assert_that(tools::bit_floor(UINT64_C(9)) == UINT64_C(8));
  assert_that(tools::bit_floor(UINT64_C(10)) == UINT64_C(8));
  assert_that(tools::bit_floor(UINT64_C(9223372036854775807)) == UINT64_C(4611686018427387904));
  assert_that(tools::bit_floor(UINT64_C(9223372036854775808)) == UINT64_C(9223372036854775808));
  assert_that(tools::bit_floor(UINT64_C(9223372036854775809)) == UINT64_C(9223372036854775808));
  assert_that(tools::bit_floor(UINT64_C(18446744073709551615)) == UINT64_C(9223372036854775808));

  assert_that(tools::bit_floor(INT128_C(0)) == INT128_C(0));
  assert_that(tools::bit_floor(INT128_C(1)) == INT128_C(1));
  assert_that(tools::bit_floor(INT128_C(2)) == INT128_C(2));
  assert_that(tools::bit_floor(INT128_C(3)) == INT128_C(2));
  assert_that(tools::bit_floor(INT128_C(4)) == INT128_C(4));
  assert_that(tools::bit_floor(INT128_C(5)) == INT128_C(4));
  assert_that(tools::bit_floor(INT128_C(6)) == INT128_C(4));
  assert_that(tools::bit_floor(INT128_C(7)) == INT128_C(4));
  assert_that(tools::bit_floor(INT128_C(8)) == INT128_C(8));
  assert_that(tools::bit_floor(INT128_C(9)) == INT128_C(8));
  assert_that(tools::bit_floor(INT128_C(10)) == INT128_C(8));
  assert_that(tools::bit_floor(INT128_C(85070591730234615865843651857942052863)) == INT128_C(42535295865117307932921825928971026432));
  assert_that(tools::bit_floor(INT128_C(85070591730234615865843651857942052864)) == INT128_C(85070591730234615865843651857942052864));
  assert_that(tools::bit_floor(INT128_C(85070591730234615865843651857942052865)) == INT128_C(85070591730234615865843651857942052864));
  assert_that(tools::bit_floor(INT128_C(170141183460469231731687303715884105727)) == INT128_C(85070591730234615865843651857942052864));

  assert_that(tools::bit_floor(UINT128_C(0)) == UINT128_C(0));
  assert_that(tools::bit_floor(UINT128_C(1)) == UINT128_C(1));
  assert_that(tools::bit_floor(UINT128_C(2)) == UINT128_C(2));
  assert_that(tools::bit_floor(UINT128_C(3)) == UINT128_C(2));
  assert_that(tools::bit_floor(UINT128_C(4)) == UINT128_C(4));
  assert_that(tools::bit_floor(UINT128_C(5)) == UINT128_C(4));
  assert_that(tools::bit_floor(UINT128_C(6)) == UINT128_C(4));
  assert_that(tools::bit_floor(UINT128_C(7)) == UINT128_C(4));
  assert_that(tools::bit_floor(UINT128_C(8)) == UINT128_C(8));
  assert_that(tools::bit_floor(UINT128_C(9)) == UINT128_C(8));
  assert_that(tools::bit_floor(UINT128_C(10)) == UINT128_C(8));
  assert_that(tools::bit_floor(UINT128_C(170141183460469231731687303715884105727)) == UINT128_C(85070591730234615865843651857942052864));
  assert_that(tools::bit_floor(UINT128_C(170141183460469231731687303715884105728)) == UINT128_C(170141183460469231731687303715884105728));
  assert_that(tools::bit_floor(UINT128_C(170141183460469231731687303715884105729)) == UINT128_C(170141183460469231731687303715884105728));
  assert_that(tools::bit_floor(UINT128_C(340282366920938463463374607431768211455)) == UINT128_C(170141183460469231731687303715884105728));

  return 0;
}
