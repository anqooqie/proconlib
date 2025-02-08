// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/countr_zero.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::countr_zero(INT32_C(0)) == 31);
  static_assert(tools::countr_zero(INT32_C(1)) == 0);
  static_assert(tools::countr_zero(INT32_C(2)) == 1);
  static_assert(tools::countr_zero(INT32_C(3)) == 0);
  static_assert(tools::countr_zero(INT32_C(4)) == 2);
  static_assert(tools::countr_zero(INT32_C(5)) == 0);
  static_assert(tools::countr_zero(INT32_C(6)) == 1);
  static_assert(tools::countr_zero(INT32_C(7)) == 0);
  static_assert(tools::countr_zero(INT32_C(8)) == 3);
  static_assert(tools::countr_zero(INT32_C(9)) == 0);
  static_assert(tools::countr_zero(INT32_C(1073741823)) == 0);
  static_assert(tools::countr_zero(INT32_C(1073741824)) == 30);
  static_assert(tools::countr_zero(INT32_C(1073741825)) == 0);
  static_assert(tools::countr_zero(INT32_C(2147483646)) == 1);
  static_assert(tools::countr_zero(INT32_C(2147483647)) == 0);

  static_assert(tools::countr_zero(UINT32_C(0)) == 32);
  static_assert(tools::countr_zero(UINT32_C(1)) == 0);
  static_assert(tools::countr_zero(UINT32_C(2)) == 1);
  static_assert(tools::countr_zero(UINT32_C(3)) == 0);
  static_assert(tools::countr_zero(UINT32_C(4)) == 2);
  static_assert(tools::countr_zero(UINT32_C(5)) == 0);
  static_assert(tools::countr_zero(UINT32_C(6)) == 1);
  static_assert(tools::countr_zero(UINT32_C(7)) == 0);
  static_assert(tools::countr_zero(UINT32_C(8)) == 3);
  static_assert(tools::countr_zero(UINT32_C(9)) == 0);
  static_assert(tools::countr_zero(UINT32_C(2147483647)) == 0);
  static_assert(tools::countr_zero(UINT32_C(2147483648)) == 31);
  static_assert(tools::countr_zero(UINT32_C(2147483649)) == 0);
  static_assert(tools::countr_zero(UINT32_C(4294967294)) == 1);
  static_assert(tools::countr_zero(UINT32_C(4294967295)) == 0);

  static_assert(tools::countr_zero(INT64_C(0)) == 63);
  static_assert(tools::countr_zero(INT64_C(1)) == 0);
  static_assert(tools::countr_zero(INT64_C(2)) == 1);
  static_assert(tools::countr_zero(INT64_C(3)) == 0);
  static_assert(tools::countr_zero(INT64_C(4)) == 2);
  static_assert(tools::countr_zero(INT64_C(5)) == 0);
  static_assert(tools::countr_zero(INT64_C(6)) == 1);
  static_assert(tools::countr_zero(INT64_C(7)) == 0);
  static_assert(tools::countr_zero(INT64_C(8)) == 3);
  static_assert(tools::countr_zero(INT64_C(9)) == 0);
  static_assert(tools::countr_zero(INT64_C(4611686018427387903)) == 0);
  static_assert(tools::countr_zero(INT64_C(4611686018427387904)) == 62);
  static_assert(tools::countr_zero(INT64_C(4611686018427387905)) == 0);
  static_assert(tools::countr_zero(INT64_C(9223372036854775806)) == 1);
  static_assert(tools::countr_zero(INT64_C(9223372036854775807)) == 0);

  static_assert(tools::countr_zero(UINT64_C(0)) == 64);
  static_assert(tools::countr_zero(UINT64_C(1)) == 0);
  static_assert(tools::countr_zero(UINT64_C(2)) == 1);
  static_assert(tools::countr_zero(UINT64_C(3)) == 0);
  static_assert(tools::countr_zero(UINT64_C(4)) == 2);
  static_assert(tools::countr_zero(UINT64_C(5)) == 0);
  static_assert(tools::countr_zero(UINT64_C(6)) == 1);
  static_assert(tools::countr_zero(UINT64_C(7)) == 0);
  static_assert(tools::countr_zero(UINT64_C(8)) == 3);
  static_assert(tools::countr_zero(UINT64_C(9)) == 0);
  static_assert(tools::countr_zero(UINT64_C(9223372036854775807)) == 0);
  static_assert(tools::countr_zero(UINT64_C(9223372036854775808)) == 63);
  static_assert(tools::countr_zero(UINT64_C(9223372036854775809)) == 0);
  static_assert(tools::countr_zero(UINT64_C(18446744073709551614)) == 1);
  static_assert(tools::countr_zero(UINT64_C(18446744073709551615)) == 0);

  static_assert(tools::countr_zero(INT128_C(0)) == 127);
  static_assert(tools::countr_zero(INT128_C(1)) == 0);
  static_assert(tools::countr_zero(INT128_C(2)) == 1);
  static_assert(tools::countr_zero(INT128_C(3)) == 0);
  static_assert(tools::countr_zero(INT128_C(4)) == 2);
  static_assert(tools::countr_zero(INT128_C(5)) == 0);
  static_assert(tools::countr_zero(INT128_C(6)) == 1);
  static_assert(tools::countr_zero(INT128_C(7)) == 0);
  static_assert(tools::countr_zero(INT128_C(8)) == 3);
  static_assert(tools::countr_zero(INT128_C(9)) == 0);
  static_assert(tools::countr_zero(INT128_C(85070591730234615865843651857942052863)) == 0);
  static_assert(tools::countr_zero(INT128_C(85070591730234615865843651857942052864)) == 126);
  static_assert(tools::countr_zero(INT128_C(85070591730234615865843651857942052865)) == 0);
  static_assert(tools::countr_zero(INT128_C(170141183460469231731687303715884105726)) == 1);
  static_assert(tools::countr_zero(INT128_C(170141183460469231731687303715884105727)) == 0);

  static_assert(tools::countr_zero(UINT128_C(0)) == 128);
  static_assert(tools::countr_zero(UINT128_C(1)) == 0);
  static_assert(tools::countr_zero(UINT128_C(2)) == 1);
  static_assert(tools::countr_zero(UINT128_C(3)) == 0);
  static_assert(tools::countr_zero(UINT128_C(4)) == 2);
  static_assert(tools::countr_zero(UINT128_C(5)) == 0);
  static_assert(tools::countr_zero(UINT128_C(6)) == 1);
  static_assert(tools::countr_zero(UINT128_C(7)) == 0);
  static_assert(tools::countr_zero(UINT128_C(8)) == 3);
  static_assert(tools::countr_zero(UINT128_C(9)) == 0);
  static_assert(tools::countr_zero(UINT128_C(170141183460469231731687303715884105727)) == 0);
  static_assert(tools::countr_zero(UINT128_C(170141183460469231731687303715884105728)) == 127);
  static_assert(tools::countr_zero(UINT128_C(170141183460469231731687303715884105729)) == 0);
  static_assert(tools::countr_zero(UINT128_C(340282366920938463463374607431768211454)) == 1);
  static_assert(tools::countr_zero(UINT128_C(340282366920938463463374607431768211455)) == 0);

  return 0;
}
