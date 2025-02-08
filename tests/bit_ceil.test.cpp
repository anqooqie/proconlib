// competitive-verifier: STANDALONE

#include <iostream>
#include <cstdint>
#include "tools/bit_ceil.hpp"
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static_assert(tools::bit_ceil(INT32_C(0)) == INT32_C(1));
  static_assert(tools::bit_ceil(INT32_C(1)) == INT32_C(1));
  static_assert(tools::bit_ceil(INT32_C(2)) == INT32_C(2));
  static_assert(tools::bit_ceil(INT32_C(3)) == INT32_C(4));
  static_assert(tools::bit_ceil(INT32_C(4)) == INT32_C(4));
  static_assert(tools::bit_ceil(INT32_C(5)) == INT32_C(8));
  static_assert(tools::bit_ceil(INT32_C(6)) == INT32_C(8));
  static_assert(tools::bit_ceil(INT32_C(7)) == INT32_C(8));
  static_assert(tools::bit_ceil(INT32_C(8)) == INT32_C(8));
  static_assert(tools::bit_ceil(INT32_C(9)) == INT32_C(16));
  static_assert(tools::bit_ceil(INT32_C(10)) == INT32_C(16));
  static_assert(tools::bit_ceil(INT32_C(1073741823)) == INT32_C(1073741824));
  static_assert(tools::bit_ceil(INT32_C(1073741824)) == INT32_C(1073741824));

  static_assert(tools::bit_ceil(UINT32_C(0)) == UINT32_C(1));
  static_assert(tools::bit_ceil(UINT32_C(1)) == UINT32_C(1));
  static_assert(tools::bit_ceil(UINT32_C(2)) == UINT32_C(2));
  static_assert(tools::bit_ceil(UINT32_C(3)) == UINT32_C(4));
  static_assert(tools::bit_ceil(UINT32_C(4)) == UINT32_C(4));
  static_assert(tools::bit_ceil(UINT32_C(5)) == UINT32_C(8));
  static_assert(tools::bit_ceil(UINT32_C(6)) == UINT32_C(8));
  static_assert(tools::bit_ceil(UINT32_C(7)) == UINT32_C(8));
  static_assert(tools::bit_ceil(UINT32_C(8)) == UINT32_C(8));
  static_assert(tools::bit_ceil(UINT32_C(9)) == UINT32_C(16));
  static_assert(tools::bit_ceil(UINT32_C(10)) == UINT32_C(16));
  static_assert(tools::bit_ceil(UINT32_C(2147483647)) == UINT32_C(2147483648));
  static_assert(tools::bit_ceil(UINT32_C(2147483648)) == UINT32_C(2147483648));

  static_assert(tools::bit_ceil(INT64_C(0)) == INT64_C(1));
  static_assert(tools::bit_ceil(INT64_C(1)) == INT64_C(1));
  static_assert(tools::bit_ceil(INT64_C(2)) == INT64_C(2));
  static_assert(tools::bit_ceil(INT64_C(3)) == INT64_C(4));
  static_assert(tools::bit_ceil(INT64_C(4)) == INT64_C(4));
  static_assert(tools::bit_ceil(INT64_C(5)) == INT64_C(8));
  static_assert(tools::bit_ceil(INT64_C(6)) == INT64_C(8));
  static_assert(tools::bit_ceil(INT64_C(7)) == INT64_C(8));
  static_assert(tools::bit_ceil(INT64_C(8)) == INT64_C(8));
  static_assert(tools::bit_ceil(INT64_C(9)) == INT64_C(16));
  static_assert(tools::bit_ceil(INT64_C(10)) == INT64_C(16));
  static_assert(tools::bit_ceil(INT64_C(4611686018427387903)) == INT64_C(4611686018427387904));
  static_assert(tools::bit_ceil(INT64_C(4611686018427387904)) == INT64_C(4611686018427387904));

  static_assert(tools::bit_ceil(UINT64_C(0)) == UINT64_C(1));
  static_assert(tools::bit_ceil(UINT64_C(1)) == UINT64_C(1));
  static_assert(tools::bit_ceil(UINT64_C(2)) == UINT64_C(2));
  static_assert(tools::bit_ceil(UINT64_C(3)) == UINT64_C(4));
  static_assert(tools::bit_ceil(UINT64_C(4)) == UINT64_C(4));
  static_assert(tools::bit_ceil(UINT64_C(5)) == UINT64_C(8));
  static_assert(tools::bit_ceil(UINT64_C(6)) == UINT64_C(8));
  static_assert(tools::bit_ceil(UINT64_C(7)) == UINT64_C(8));
  static_assert(tools::bit_ceil(UINT64_C(8)) == UINT64_C(8));
  static_assert(tools::bit_ceil(UINT64_C(9)) == UINT64_C(16));
  static_assert(tools::bit_ceil(UINT64_C(10)) == UINT64_C(16));
  static_assert(tools::bit_ceil(UINT64_C(9223372036854775807)) == UINT64_C(9223372036854775808));
  static_assert(tools::bit_ceil(UINT64_C(9223372036854775808)) == UINT64_C(9223372036854775808));

  static_assert(tools::bit_ceil(INT128_C(0)) == INT128_C(1));
  static_assert(tools::bit_ceil(INT128_C(1)) == INT128_C(1));
  static_assert(tools::bit_ceil(INT128_C(2)) == INT128_C(2));
  static_assert(tools::bit_ceil(INT128_C(3)) == INT128_C(4));
  static_assert(tools::bit_ceil(INT128_C(4)) == INT128_C(4));
  static_assert(tools::bit_ceil(INT128_C(5)) == INT128_C(8));
  static_assert(tools::bit_ceil(INT128_C(6)) == INT128_C(8));
  static_assert(tools::bit_ceil(INT128_C(7)) == INT128_C(8));
  static_assert(tools::bit_ceil(INT128_C(8)) == INT128_C(8));
  static_assert(tools::bit_ceil(INT128_C(9)) == INT128_C(16));
  static_assert(tools::bit_ceil(INT128_C(10)) == INT128_C(16));
  static_assert(tools::bit_ceil(INT128_C(85070591730234615865843651857942052863)) == INT128_C(85070591730234615865843651857942052864));
  static_assert(tools::bit_ceil(INT128_C(85070591730234615865843651857942052864)) == INT128_C(85070591730234615865843651857942052864));

  static_assert(tools::bit_ceil(UINT128_C(0)) == UINT128_C(1));
  static_assert(tools::bit_ceil(UINT128_C(1)) == UINT128_C(1));
  static_assert(tools::bit_ceil(UINT128_C(2)) == UINT128_C(2));
  static_assert(tools::bit_ceil(UINT128_C(3)) == UINT128_C(4));
  static_assert(tools::bit_ceil(UINT128_C(4)) == UINT128_C(4));
  static_assert(tools::bit_ceil(UINT128_C(5)) == UINT128_C(8));
  static_assert(tools::bit_ceil(UINT128_C(6)) == UINT128_C(8));
  static_assert(tools::bit_ceil(UINT128_C(7)) == UINT128_C(8));
  static_assert(tools::bit_ceil(UINT128_C(8)) == UINT128_C(8));
  static_assert(tools::bit_ceil(UINT128_C(9)) == UINT128_C(16));
  static_assert(tools::bit_ceil(UINT128_C(10)) == UINT128_C(16));
  static_assert(tools::bit_ceil(UINT128_C(170141183460469231731687303715884105727)) == UINT128_C(170141183460469231731687303715884105728));
  static_assert(tools::bit_ceil(UINT128_C(170141183460469231731687303715884105728)) == UINT128_C(170141183460469231731687303715884105728));

  return 0;
}
