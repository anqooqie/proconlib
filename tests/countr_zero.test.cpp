// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/assert_that.hpp"
#include "tools/countr_zero.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::countr_zero(false) == 1);
  assert_that(tools::countr_zero(true) == 0);

  assert_that(tools::countr_zero(INT32_C(0)) == 31);
  assert_that(tools::countr_zero(INT32_C(1)) == 0);
  assert_that(tools::countr_zero(INT32_C(2)) == 1);
  assert_that(tools::countr_zero(INT32_C(3)) == 0);
  assert_that(tools::countr_zero(INT32_C(4)) == 2);
  assert_that(tools::countr_zero(INT32_C(5)) == 0);
  assert_that(tools::countr_zero(INT32_C(6)) == 1);
  assert_that(tools::countr_zero(INT32_C(7)) == 0);
  assert_that(tools::countr_zero(INT32_C(8)) == 3);
  assert_that(tools::countr_zero(INT32_C(9)) == 0);
  assert_that(tools::countr_zero(INT32_C(1073741823)) == 0);
  assert_that(tools::countr_zero(INT32_C(1073741824)) == 30);
  assert_that(tools::countr_zero(INT32_C(1073741825)) == 0);
  assert_that(tools::countr_zero(INT32_C(2147483646)) == 1);
  assert_that(tools::countr_zero(INT32_C(2147483647)) == 0);

  assert_that(tools::countr_zero(UINT32_C(0)) == 32);
  assert_that(tools::countr_zero(UINT32_C(1)) == 0);
  assert_that(tools::countr_zero(UINT32_C(2)) == 1);
  assert_that(tools::countr_zero(UINT32_C(3)) == 0);
  assert_that(tools::countr_zero(UINT32_C(4)) == 2);
  assert_that(tools::countr_zero(UINT32_C(5)) == 0);
  assert_that(tools::countr_zero(UINT32_C(6)) == 1);
  assert_that(tools::countr_zero(UINT32_C(7)) == 0);
  assert_that(tools::countr_zero(UINT32_C(8)) == 3);
  assert_that(tools::countr_zero(UINT32_C(9)) == 0);
  assert_that(tools::countr_zero(UINT32_C(2147483647)) == 0);
  assert_that(tools::countr_zero(UINT32_C(2147483648)) == 31);
  assert_that(tools::countr_zero(UINT32_C(2147483649)) == 0);
  assert_that(tools::countr_zero(UINT32_C(4294967294)) == 1);
  assert_that(tools::countr_zero(UINT32_C(4294967295)) == 0);

  assert_that(tools::countr_zero(INT64_C(0)) == 63);
  assert_that(tools::countr_zero(INT64_C(1)) == 0);
  assert_that(tools::countr_zero(INT64_C(2)) == 1);
  assert_that(tools::countr_zero(INT64_C(3)) == 0);
  assert_that(tools::countr_zero(INT64_C(4)) == 2);
  assert_that(tools::countr_zero(INT64_C(5)) == 0);
  assert_that(tools::countr_zero(INT64_C(6)) == 1);
  assert_that(tools::countr_zero(INT64_C(7)) == 0);
  assert_that(tools::countr_zero(INT64_C(8)) == 3);
  assert_that(tools::countr_zero(INT64_C(9)) == 0);
  assert_that(tools::countr_zero(INT64_C(4611686018427387903)) == 0);
  assert_that(tools::countr_zero(INT64_C(4611686018427387904)) == 62);
  assert_that(tools::countr_zero(INT64_C(4611686018427387905)) == 0);
  assert_that(tools::countr_zero(INT64_C(9223372036854775806)) == 1);
  assert_that(tools::countr_zero(INT64_C(9223372036854775807)) == 0);

  assert_that(tools::countr_zero(UINT64_C(0)) == 64);
  assert_that(tools::countr_zero(UINT64_C(1)) == 0);
  assert_that(tools::countr_zero(UINT64_C(2)) == 1);
  assert_that(tools::countr_zero(UINT64_C(3)) == 0);
  assert_that(tools::countr_zero(UINT64_C(4)) == 2);
  assert_that(tools::countr_zero(UINT64_C(5)) == 0);
  assert_that(tools::countr_zero(UINT64_C(6)) == 1);
  assert_that(tools::countr_zero(UINT64_C(7)) == 0);
  assert_that(tools::countr_zero(UINT64_C(8)) == 3);
  assert_that(tools::countr_zero(UINT64_C(9)) == 0);
  assert_that(tools::countr_zero(UINT64_C(9223372036854775807)) == 0);
  assert_that(tools::countr_zero(UINT64_C(9223372036854775808)) == 63);
  assert_that(tools::countr_zero(UINT64_C(9223372036854775809)) == 0);
  assert_that(tools::countr_zero(UINT64_C(18446744073709551614)) == 1);
  assert_that(tools::countr_zero(UINT64_C(18446744073709551615)) == 0);

  return 0;
}
