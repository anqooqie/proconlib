// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/floor_log2.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::floor_log2(INT32_C(1)) == 0);
  static_assert(tools::floor_log2(INT32_C(2)) == 1);
  static_assert(tools::floor_log2(INT32_C(3)) == 1);
  static_assert(tools::floor_log2(INT32_C(4)) == 2);
  static_assert(tools::floor_log2(INT32_C(5)) == 2);
  static_assert(tools::floor_log2(INT32_C(6)) == 2);
  static_assert(tools::floor_log2(INT32_C(7)) == 2);
  static_assert(tools::floor_log2(INT32_C(8)) == 3);
  static_assert(tools::floor_log2(INT32_C(9)) == 3);
  static_assert(tools::floor_log2(INT32_C(1073741823)) == 29);
  static_assert(tools::floor_log2(INT32_C(1073741824)) == 30);
  static_assert(tools::floor_log2(INT32_C(1073741825)) == 30);
  static_assert(tools::floor_log2(INT32_C(2147483646)) == 30);
  static_assert(tools::floor_log2(INT32_C(2147483647)) == 30);

  static_assert(tools::floor_log2(UINT32_C(1)) == 0);
  static_assert(tools::floor_log2(UINT32_C(2)) == 1);
  static_assert(tools::floor_log2(UINT32_C(3)) == 1);
  static_assert(tools::floor_log2(UINT32_C(4)) == 2);
  static_assert(tools::floor_log2(UINT32_C(5)) == 2);
  static_assert(tools::floor_log2(UINT32_C(6)) == 2);
  static_assert(tools::floor_log2(UINT32_C(7)) == 2);
  static_assert(tools::floor_log2(UINT32_C(8)) == 3);
  static_assert(tools::floor_log2(UINT32_C(9)) == 3);
  static_assert(tools::floor_log2(UINT32_C(2147483647)) == 30);
  static_assert(tools::floor_log2(UINT32_C(2147483648)) == 31);
  static_assert(tools::floor_log2(UINT32_C(2147483649)) == 31);
  static_assert(tools::floor_log2(UINT32_C(4294967294)) == 31);
  static_assert(tools::floor_log2(UINT32_C(4294967295)) == 31);

  static_assert(tools::floor_log2(INT64_C(1)) == 0);
  static_assert(tools::floor_log2(INT64_C(2)) == 1);
  static_assert(tools::floor_log2(INT64_C(3)) == 1);
  static_assert(tools::floor_log2(INT64_C(4)) == 2);
  static_assert(tools::floor_log2(INT64_C(5)) == 2);
  static_assert(tools::floor_log2(INT64_C(6)) == 2);
  static_assert(tools::floor_log2(INT64_C(7)) == 2);
  static_assert(tools::floor_log2(INT64_C(8)) == 3);
  static_assert(tools::floor_log2(INT64_C(9)) == 3);
  static_assert(tools::floor_log2(INT64_C(4611686018427387903)) == 61);
  static_assert(tools::floor_log2(INT64_C(4611686018427387904)) == 62);
  static_assert(tools::floor_log2(INT64_C(4611686018427387905)) == 62);
  static_assert(tools::floor_log2(INT64_C(9223372036854775806)) == 62);
  static_assert(tools::floor_log2(INT64_C(9223372036854775807)) == 62);

  static_assert(tools::floor_log2(UINT64_C(1)) == 0);
  static_assert(tools::floor_log2(UINT64_C(2)) == 1);
  static_assert(tools::floor_log2(UINT64_C(3)) == 1);
  static_assert(tools::floor_log2(UINT64_C(4)) == 2);
  static_assert(tools::floor_log2(UINT64_C(5)) == 2);
  static_assert(tools::floor_log2(UINT64_C(6)) == 2);
  static_assert(tools::floor_log2(UINT64_C(7)) == 2);
  static_assert(tools::floor_log2(UINT64_C(8)) == 3);
  static_assert(tools::floor_log2(UINT64_C(9)) == 3);
  static_assert(tools::floor_log2(UINT64_C(9223372036854775807)) == 62);
  static_assert(tools::floor_log2(UINT64_C(9223372036854775808)) == 63);
  static_assert(tools::floor_log2(UINT64_C(9223372036854775809)) == 63);
  static_assert(tools::floor_log2(UINT64_C(18446744073709551614)) == 63);
  static_assert(tools::floor_log2(UINT64_C(18446744073709551615)) == 63);

  static_assert(tools::floor_log2(INT128_C(1)) == 0);
  static_assert(tools::floor_log2(INT128_C(2)) == 1);
  static_assert(tools::floor_log2(INT128_C(3)) == 1);
  static_assert(tools::floor_log2(INT128_C(4)) == 2);
  static_assert(tools::floor_log2(INT128_C(5)) == 2);
  static_assert(tools::floor_log2(INT128_C(6)) == 2);
  static_assert(tools::floor_log2(INT128_C(7)) == 2);
  static_assert(tools::floor_log2(INT128_C(8)) == 3);
  static_assert(tools::floor_log2(INT128_C(9)) == 3);
  static_assert(tools::floor_log2(INT128_C(85070591730234615865843651857942052863)) == 125);
  static_assert(tools::floor_log2(INT128_C(85070591730234615865843651857942052864)) == 126);
  static_assert(tools::floor_log2(INT128_C(85070591730234615865843651857942052865)) == 126);
  static_assert(tools::floor_log2(INT128_C(170141183460469231731687303715884105726)) == 126);
  static_assert(tools::floor_log2(INT128_C(170141183460469231731687303715884105727)) == 126);

  static_assert(tools::floor_log2(UINT128_C(1)) == 0);
  static_assert(tools::floor_log2(UINT128_C(2)) == 1);
  static_assert(tools::floor_log2(UINT128_C(3)) == 1);
  static_assert(tools::floor_log2(UINT128_C(4)) == 2);
  static_assert(tools::floor_log2(UINT128_C(5)) == 2);
  static_assert(tools::floor_log2(UINT128_C(6)) == 2);
  static_assert(tools::floor_log2(UINT128_C(7)) == 2);
  static_assert(tools::floor_log2(UINT128_C(8)) == 3);
  static_assert(tools::floor_log2(UINT128_C(9)) == 3);
  static_assert(tools::floor_log2(UINT128_C(170141183460469231731687303715884105727)) == 126);
  static_assert(tools::floor_log2(UINT128_C(170141183460469231731687303715884105728)) == 127);
  static_assert(tools::floor_log2(UINT128_C(170141183460469231731687303715884105729)) == 127);
  static_assert(tools::floor_log2(UINT128_C(340282366920938463463374607431768211454)) == 127);
  static_assert(tools::floor_log2(UINT128_C(340282366920938463463374607431768211455)) == 127);

  return 0;
}
