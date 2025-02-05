// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/assert_that.hpp"
#include "tools/bit_floor.hpp"

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

  return 0;
}
