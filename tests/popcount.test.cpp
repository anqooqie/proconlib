// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/int128_t.hpp"
#include "tools/popcount.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::popcount(INT32_C(0)) == 0);
  static_assert(tools::popcount(INT32_C(1)) == 1);
  static_assert(tools::popcount(INT32_C(2)) == 1);
  static_assert(tools::popcount(INT32_C(3)) == 2);
  static_assert(tools::popcount(INT32_C(4)) == 1);
  static_assert(tools::popcount(INT32_C(5)) == 2);
  static_assert(tools::popcount(INT32_C(6)) == 2);
  static_assert(tools::popcount(INT32_C(7)) == 3);
  static_assert(tools::popcount(INT32_C(8)) == 1);
  static_assert(tools::popcount(INT32_C(9)) == 2);
  static_assert(tools::popcount(INT32_C(2147483645)) == 30);
  static_assert(tools::popcount(INT32_C(2147483646)) == 30);
  static_assert(tools::popcount(INT32_C(2147483647)) == 31);

  static_assert(tools::popcount(UINT32_C(0)) == 0);
  static_assert(tools::popcount(UINT32_C(1)) == 1);
  static_assert(tools::popcount(UINT32_C(2)) == 1);
  static_assert(tools::popcount(UINT32_C(3)) == 2);
  static_assert(tools::popcount(UINT32_C(4)) == 1);
  static_assert(tools::popcount(UINT32_C(5)) == 2);
  static_assert(tools::popcount(UINT32_C(6)) == 2);
  static_assert(tools::popcount(UINT32_C(7)) == 3);
  static_assert(tools::popcount(UINT32_C(8)) == 1);
  static_assert(tools::popcount(UINT32_C(9)) == 2);
  static_assert(tools::popcount(UINT32_C(4294967293)) == 31);
  static_assert(tools::popcount(UINT32_C(4294967294)) == 31);
  static_assert(tools::popcount(UINT32_C(4294967295)) == 32);

  static_assert(tools::popcount(INT64_C(0)) == 0);
  static_assert(tools::popcount(INT64_C(1)) == 1);
  static_assert(tools::popcount(INT64_C(2)) == 1);
  static_assert(tools::popcount(INT64_C(3)) == 2);
  static_assert(tools::popcount(INT64_C(4)) == 1);
  static_assert(tools::popcount(INT64_C(5)) == 2);
  static_assert(tools::popcount(INT64_C(6)) == 2);
  static_assert(tools::popcount(INT64_C(7)) == 3);
  static_assert(tools::popcount(INT64_C(8)) == 1);
  static_assert(tools::popcount(INT64_C(9)) == 2);
  static_assert(tools::popcount(INT64_C(9223372036854775805)) == 62);
  static_assert(tools::popcount(INT64_C(9223372036854775806)) == 62);
  static_assert(tools::popcount(INT64_C(9223372036854775807)) == 63);

  static_assert(tools::popcount(UINT64_C(0)) == 0);
  static_assert(tools::popcount(UINT64_C(1)) == 1);
  static_assert(tools::popcount(UINT64_C(2)) == 1);
  static_assert(tools::popcount(UINT64_C(3)) == 2);
  static_assert(tools::popcount(UINT64_C(4)) == 1);
  static_assert(tools::popcount(UINT64_C(5)) == 2);
  static_assert(tools::popcount(UINT64_C(6)) == 2);
  static_assert(tools::popcount(UINT64_C(7)) == 3);
  static_assert(tools::popcount(UINT64_C(8)) == 1);
  static_assert(tools::popcount(UINT64_C(9)) == 2);
  static_assert(tools::popcount(UINT64_C(18446744073709551613)) == 63);
  static_assert(tools::popcount(UINT64_C(18446744073709551614)) == 63);
  static_assert(tools::popcount(UINT64_C(18446744073709551615)) == 64);

  static_assert(tools::popcount(INT128_C(0)) == 0);
  static_assert(tools::popcount(INT128_C(1)) == 1);
  static_assert(tools::popcount(INT128_C(2)) == 1);
  static_assert(tools::popcount(INT128_C(3)) == 2);
  static_assert(tools::popcount(INT128_C(4)) == 1);
  static_assert(tools::popcount(INT128_C(5)) == 2);
  static_assert(tools::popcount(INT128_C(6)) == 2);
  static_assert(tools::popcount(INT128_C(7)) == 3);
  static_assert(tools::popcount(INT128_C(8)) == 1);
  static_assert(tools::popcount(INT128_C(9)) == 2);
  static_assert(tools::popcount(INT128_C(170141183460469231731687303715884105725)) == 126);
  static_assert(tools::popcount(INT128_C(170141183460469231731687303715884105726)) == 126);
  static_assert(tools::popcount(INT128_C(170141183460469231731687303715884105727)) == 127);

  static_assert(tools::popcount(UINT128_C(0)) == 0);
  static_assert(tools::popcount(UINT128_C(1)) == 1);
  static_assert(tools::popcount(UINT128_C(2)) == 1);
  static_assert(tools::popcount(UINT128_C(3)) == 2);
  static_assert(tools::popcount(UINT128_C(4)) == 1);
  static_assert(tools::popcount(UINT128_C(5)) == 2);
  static_assert(tools::popcount(UINT128_C(6)) == 2);
  static_assert(tools::popcount(UINT128_C(7)) == 3);
  static_assert(tools::popcount(UINT128_C(8)) == 1);
  static_assert(tools::popcount(UINT128_C(9)) == 2);
  static_assert(tools::popcount(UINT128_C(340282366920938463463374607431768211453)) == 127);
  static_assert(tools::popcount(UINT128_C(340282366920938463463374607431768211454)) == 127);
  static_assert(tools::popcount(UINT128_C(340282366920938463463374607431768211455)) == 128);

  return 0;
}
