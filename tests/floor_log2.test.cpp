#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <cstdlib>
#include <iostream>
#include <cstdint>
#include "tools/floor_log2.hpp"

void assert_that(const bool cond) {
  if (!cond) {
    std::exit(EXIT_FAILURE);
  }
}

int main() {
  assert_that(tools::floor_log2(INT32_C(1)) == 0);
  assert_that(tools::floor_log2(INT32_C(2)) == 1);
  assert_that(tools::floor_log2(INT32_C(3)) == 1);
  assert_that(tools::floor_log2(INT32_C(4)) == 2);
  assert_that(tools::floor_log2(INT32_C(5)) == 2);
  assert_that(tools::floor_log2(INT32_C(6)) == 2);
  assert_that(tools::floor_log2(INT32_C(7)) == 2);
  assert_that(tools::floor_log2(INT32_C(8)) == 3);
  assert_that(tools::floor_log2(INT32_C(9)) == 3);
  assert_that(tools::floor_log2(INT32_C(1073741823)) == 29);
  assert_that(tools::floor_log2(INT32_C(1073741824)) == 30);
  assert_that(tools::floor_log2(INT32_C(1073741825)) == 30);
  assert_that(tools::floor_log2(INT32_C(2147483647)) == 30);

  assert_that(tools::floor_log2(UINT32_C(1)) == 0);
  assert_that(tools::floor_log2(UINT32_C(2)) == 1);
  assert_that(tools::floor_log2(UINT32_C(3)) == 1);
  assert_that(tools::floor_log2(UINT32_C(4)) == 2);
  assert_that(tools::floor_log2(UINT32_C(5)) == 2);
  assert_that(tools::floor_log2(UINT32_C(6)) == 2);
  assert_that(tools::floor_log2(UINT32_C(7)) == 2);
  assert_that(tools::floor_log2(UINT32_C(8)) == 3);
  assert_that(tools::floor_log2(UINT32_C(9)) == 3);
  assert_that(tools::floor_log2(UINT32_C(2147483647)) == 30);
  assert_that(tools::floor_log2(UINT32_C(2147483648)) == 31);
  assert_that(tools::floor_log2(UINT32_C(2147483649)) == 31);
  assert_that(tools::floor_log2(UINT32_C(4294967295)) == 31);

  assert_that(tools::floor_log2(INT64_C(1)) == 0);
  assert_that(tools::floor_log2(INT64_C(2)) == 1);
  assert_that(tools::floor_log2(INT64_C(3)) == 1);
  assert_that(tools::floor_log2(INT64_C(4)) == 2);
  assert_that(tools::floor_log2(INT64_C(5)) == 2);
  assert_that(tools::floor_log2(INT64_C(6)) == 2);
  assert_that(tools::floor_log2(INT64_C(7)) == 2);
  assert_that(tools::floor_log2(INT64_C(8)) == 3);
  assert_that(tools::floor_log2(INT64_C(9)) == 3);
  assert_that(tools::floor_log2(INT64_C(4611686018427387903)) == 61);
  assert_that(tools::floor_log2(INT64_C(4611686018427387904)) == 62);
  assert_that(tools::floor_log2(INT64_C(4611686018427387905)) == 62);
  assert_that(tools::floor_log2(INT64_C(9223372036854775807)) == 62);

  assert_that(tools::floor_log2(UINT64_C(1)) == 0);
  assert_that(tools::floor_log2(UINT64_C(2)) == 1);
  assert_that(tools::floor_log2(UINT64_C(3)) == 1);
  assert_that(tools::floor_log2(UINT64_C(4)) == 2);
  assert_that(tools::floor_log2(UINT64_C(5)) == 2);
  assert_that(tools::floor_log2(UINT64_C(6)) == 2);
  assert_that(tools::floor_log2(UINT64_C(7)) == 2);
  assert_that(tools::floor_log2(UINT64_C(8)) == 3);
  assert_that(tools::floor_log2(UINT64_C(9)) == 3);
  assert_that(tools::floor_log2(UINT64_C(9223372036854775807)) == 62);
  assert_that(tools::floor_log2(UINT64_C(9223372036854775808)) == 63);
  assert_that(tools::floor_log2(UINT64_C(9223372036854775809)) == 63);
  assert_that(tools::floor_log2(UINT64_C(18446744073709551615)) == 63);

  std::cout << "Hello World" << '\n';
  return 0;
}
