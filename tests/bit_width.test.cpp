// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/bit_width.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::bit_width(INT32_C(0)) == 0);
  static_assert(tools::bit_width(INT32_C(1)) == 1);
  static_assert(tools::bit_width(INT32_C(2)) == 2);
  static_assert(tools::bit_width(INT32_C(3)) == 2);
  static_assert(tools::bit_width(INT32_C(4)) == 3);
  static_assert(tools::bit_width(INT32_C(5)) == 3);
  static_assert(tools::bit_width(INT32_C(6)) == 3);
  static_assert(tools::bit_width(INT32_C(7)) == 3);
  static_assert(tools::bit_width(INT32_C(8)) == 4);
  static_assert(tools::bit_width(INT32_C(9)) == 4);
  static_assert(tools::bit_width(INT32_C(1073741823)) == 30);
  static_assert(tools::bit_width(INT32_C(1073741824)) == 31);
  static_assert(tools::bit_width(INT32_C(1073741825)) == 31);
  static_assert(tools::bit_width(INT32_C(2147483646)) == 31);
  static_assert(tools::bit_width(INT32_C(2147483647)) == 31);

  static_assert(tools::bit_width(UINT32_C(0)) == 0);
  static_assert(tools::bit_width(UINT32_C(1)) == 1);
  static_assert(tools::bit_width(UINT32_C(2)) == 2);
  static_assert(tools::bit_width(UINT32_C(3)) == 2);
  static_assert(tools::bit_width(UINT32_C(4)) == 3);
  static_assert(tools::bit_width(UINT32_C(5)) == 3);
  static_assert(tools::bit_width(UINT32_C(6)) == 3);
  static_assert(tools::bit_width(UINT32_C(7)) == 3);
  static_assert(tools::bit_width(UINT32_C(8)) == 4);
  static_assert(tools::bit_width(UINT32_C(9)) == 4);
  static_assert(tools::bit_width(UINT32_C(2147483647)) == 31);
  static_assert(tools::bit_width(UINT32_C(2147483648)) == 32);
  static_assert(tools::bit_width(UINT32_C(2147483649)) == 32);
  static_assert(tools::bit_width(UINT32_C(4294967294)) == 32);
  static_assert(tools::bit_width(UINT32_C(4294967295)) == 32);

  static_assert(tools::bit_width(INT64_C(0)) == 0);
  static_assert(tools::bit_width(INT64_C(1)) == 1);
  static_assert(tools::bit_width(INT64_C(2)) == 2);
  static_assert(tools::bit_width(INT64_C(3)) == 2);
  static_assert(tools::bit_width(INT64_C(4)) == 3);
  static_assert(tools::bit_width(INT64_C(5)) == 3);
  static_assert(tools::bit_width(INT64_C(6)) == 3);
  static_assert(tools::bit_width(INT64_C(7)) == 3);
  static_assert(tools::bit_width(INT64_C(8)) == 4);
  static_assert(tools::bit_width(INT64_C(9)) == 4);
  static_assert(tools::bit_width(INT64_C(4611686018427387903)) == 62);
  static_assert(tools::bit_width(INT64_C(4611686018427387904)) == 63);
  static_assert(tools::bit_width(INT64_C(4611686018427387905)) == 63);
  static_assert(tools::bit_width(INT64_C(9223372036854775806)) == 63);
  static_assert(tools::bit_width(INT64_C(9223372036854775807)) == 63);

  static_assert(tools::bit_width(UINT64_C(0)) == 0);
  static_assert(tools::bit_width(UINT64_C(1)) == 1);
  static_assert(tools::bit_width(UINT64_C(2)) == 2);
  static_assert(tools::bit_width(UINT64_C(3)) == 2);
  static_assert(tools::bit_width(UINT64_C(4)) == 3);
  static_assert(tools::bit_width(UINT64_C(5)) == 3);
  static_assert(tools::bit_width(UINT64_C(6)) == 3);
  static_assert(tools::bit_width(UINT64_C(7)) == 3);
  static_assert(tools::bit_width(UINT64_C(8)) == 4);
  static_assert(tools::bit_width(UINT64_C(9)) == 4);
  static_assert(tools::bit_width(UINT64_C(9223372036854775807)) == 63);
  static_assert(tools::bit_width(UINT64_C(9223372036854775808)) == 64);
  static_assert(tools::bit_width(UINT64_C(9223372036854775809)) == 64);
  static_assert(tools::bit_width(UINT64_C(18446744073709551614)) == 64);
  static_assert(tools::bit_width(UINT64_C(18446744073709551615)) == 64);

  static_assert(tools::bit_width(INT128_C(0)) == 0);
  static_assert(tools::bit_width(INT128_C(1)) == 1);
  static_assert(tools::bit_width(INT128_C(2)) == 2);
  static_assert(tools::bit_width(INT128_C(3)) == 2);
  static_assert(tools::bit_width(INT128_C(4)) == 3);
  static_assert(tools::bit_width(INT128_C(5)) == 3);
  static_assert(tools::bit_width(INT128_C(6)) == 3);
  static_assert(tools::bit_width(INT128_C(7)) == 3);
  static_assert(tools::bit_width(INT128_C(8)) == 4);
  static_assert(tools::bit_width(INT128_C(9)) == 4);
  static_assert(tools::bit_width(INT128_C(85070591730234615865843651857942052863)) == 126);
  static_assert(tools::bit_width(INT128_C(85070591730234615865843651857942052864)) == 127);
  static_assert(tools::bit_width(INT128_C(85070591730234615865843651857942052865)) == 127);
  static_assert(tools::bit_width(INT128_C(170141183460469231731687303715884105726)) == 127);
  static_assert(tools::bit_width(INT128_C(170141183460469231731687303715884105727)) == 127);

  static_assert(tools::bit_width(UINT128_C(0)) == 0);
  static_assert(tools::bit_width(UINT128_C(1)) == 1);
  static_assert(tools::bit_width(UINT128_C(2)) == 2);
  static_assert(tools::bit_width(UINT128_C(3)) == 2);
  static_assert(tools::bit_width(UINT128_C(4)) == 3);
  static_assert(tools::bit_width(UINT128_C(5)) == 3);
  static_assert(tools::bit_width(UINT128_C(6)) == 3);
  static_assert(tools::bit_width(UINT128_C(7)) == 3);
  static_assert(tools::bit_width(UINT128_C(8)) == 4);
  static_assert(tools::bit_width(UINT128_C(9)) == 4);
  static_assert(tools::bit_width(UINT128_C(170141183460469231731687303715884105727)) == 127);
  static_assert(tools::bit_width(UINT128_C(170141183460469231731687303715884105728)) == 128);
  static_assert(tools::bit_width(UINT128_C(170141183460469231731687303715884105729)) == 128);
  static_assert(tools::bit_width(UINT128_C(340282366920938463463374607431768211454)) == 128);
  static_assert(tools::bit_width(UINT128_C(340282366920938463463374607431768211455)) == 128);

  return 0;
}
