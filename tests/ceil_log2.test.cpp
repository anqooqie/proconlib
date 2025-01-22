// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <cstdlib>
#include <iostream>
#include <cstdint>
#include "tools/assert_that.hpp"
#include "tools/ceil_log2.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::ceil_log2(INT32_C(1)) == 0);
  assert_that(tools::ceil_log2(INT32_C(2)) == 1);
  assert_that(tools::ceil_log2(INT32_C(3)) == 2);
  assert_that(tools::ceil_log2(INT32_C(4)) == 2);
  assert_that(tools::ceil_log2(INT32_C(5)) == 3);
  assert_that(tools::ceil_log2(INT32_C(6)) == 3);
  assert_that(tools::ceil_log2(INT32_C(7)) == 3);
  assert_that(tools::ceil_log2(INT32_C(8)) == 3);
  assert_that(tools::ceil_log2(INT32_C(9)) == 4);
  assert_that(tools::ceil_log2(INT32_C(1073741823)) == 30);
  assert_that(tools::ceil_log2(INT32_C(1073741824)) == 30);
  assert_that(tools::ceil_log2(INT32_C(1073741825)) == 31);
  assert_that(tools::ceil_log2(INT32_C(2147483647)) == 31);

  assert_that(tools::ceil_log2(UINT32_C(1)) == 0);
  assert_that(tools::ceil_log2(UINT32_C(2)) == 1);
  assert_that(tools::ceil_log2(UINT32_C(3)) == 2);
  assert_that(tools::ceil_log2(UINT32_C(4)) == 2);
  assert_that(tools::ceil_log2(UINT32_C(5)) == 3);
  assert_that(tools::ceil_log2(UINT32_C(6)) == 3);
  assert_that(tools::ceil_log2(UINT32_C(7)) == 3);
  assert_that(tools::ceil_log2(UINT32_C(8)) == 3);
  assert_that(tools::ceil_log2(UINT32_C(9)) == 4);
  assert_that(tools::ceil_log2(UINT32_C(2147483647)) == 31);
  assert_that(tools::ceil_log2(UINT32_C(2147483648)) == 31);
  assert_that(tools::ceil_log2(UINT32_C(2147483649)) == 32);
  assert_that(tools::ceil_log2(UINT32_C(4294967295)) == 32);

  assert_that(tools::ceil_log2(INT64_C(1)) == 0);
  assert_that(tools::ceil_log2(INT64_C(2)) == 1);
  assert_that(tools::ceil_log2(INT64_C(3)) == 2);
  assert_that(tools::ceil_log2(INT64_C(4)) == 2);
  assert_that(tools::ceil_log2(INT64_C(5)) == 3);
  assert_that(tools::ceil_log2(INT64_C(6)) == 3);
  assert_that(tools::ceil_log2(INT64_C(7)) == 3);
  assert_that(tools::ceil_log2(INT64_C(8)) == 3);
  assert_that(tools::ceil_log2(INT64_C(9)) == 4);
  assert_that(tools::ceil_log2(INT64_C(4611686018427387903)) == 62);
  assert_that(tools::ceil_log2(INT64_C(4611686018427387904)) == 62);
  assert_that(tools::ceil_log2(INT64_C(4611686018427387905)) == 63);
  assert_that(tools::ceil_log2(INT64_C(9223372036854775807)) == 63);

  assert_that(tools::ceil_log2(UINT64_C(1)) == 0);
  assert_that(tools::ceil_log2(UINT64_C(2)) == 1);
  assert_that(tools::ceil_log2(UINT64_C(3)) == 2);
  assert_that(tools::ceil_log2(UINT64_C(4)) == 2);
  assert_that(tools::ceil_log2(UINT64_C(5)) == 3);
  assert_that(tools::ceil_log2(UINT64_C(6)) == 3);
  assert_that(tools::ceil_log2(UINT64_C(7)) == 3);
  assert_that(tools::ceil_log2(UINT64_C(8)) == 3);
  assert_that(tools::ceil_log2(UINT64_C(9)) == 4);
  assert_that(tools::ceil_log2(UINT64_C(9223372036854775807)) == 63);
  assert_that(tools::ceil_log2(UINT64_C(9223372036854775808)) == 63);
  assert_that(tools::ceil_log2(UINT64_C(9223372036854775809)) == 64);
  assert_that(tools::ceil_log2(UINT64_C(18446744073709551615)) == 64);

  std::cout << "Hello World" << '\n';
  return 0;
}
