// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/ceil_kth_root.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(tools::ceil_kth_root(0, 1) == 0);
  assert_that(tools::ceil_kth_root(1, 1) == 1);
  assert_that(tools::ceil_kth_root(2, 1) == 2);
  assert_that(tools::ceil_kth_root(3, 1) == 3);
  assert_that(tools::ceil_kth_root(9223372036854775807, 1) == 9223372036854775807);

  assert_that(tools::ceil_kth_root(0, 2) == 0);
  assert_that(tools::ceil_kth_root(1, 2) == 1);
  assert_that(tools::ceil_kth_root(2, 2) == 2);
  assert_that(tools::ceil_kth_root(3, 2) == 2);
  assert_that(tools::ceil_kth_root(4, 2) == 2);
  assert_that(tools::ceil_kth_root(5, 2) == 3);
  assert_that(tools::ceil_kth_root(8, 2) == 3);
  assert_that(tools::ceil_kth_root(9, 2) == 3);
  assert_that(tools::ceil_kth_root(10, 2) == 4);
  assert_that(tools::ceil_kth_root(9223372030926249000, 2) == 3037000499);
  assert_that(tools::ceil_kth_root(9223372030926249001, 2) == 3037000499);
  assert_that(tools::ceil_kth_root(9223372030926249002, 2) == 3037000500);
  assert_that(tools::ceil_kth_root(9223372036854775807, 2) == 3037000500);

  assert_that(tools::ceil_kth_root(0, 3) == 0);
  assert_that(tools::ceil_kth_root(1, 3) == 1);
  assert_that(tools::ceil_kth_root(2, 3) == 2);
  assert_that(tools::ceil_kth_root(7, 3) == 2);
  assert_that(tools::ceil_kth_root(8, 3) == 2);
  assert_that(tools::ceil_kth_root(9, 3) == 3);
  assert_that(tools::ceil_kth_root(26, 3) == 3);
  assert_that(tools::ceil_kth_root(27, 3) == 3);
  assert_that(tools::ceil_kth_root(28, 3) == 4);
  assert_that(tools::ceil_kth_root(9223358842721533950, 3) == 2097151);
  assert_that(tools::ceil_kth_root(9223358842721533951, 3) == 2097151);
  assert_that(tools::ceil_kth_root(9223358842721533952, 3) == 2097152);
  assert_that(tools::ceil_kth_root(9223372036854775807, 3) == 2097152);

  assert_that(tools::ceil_kth_root(0, 4) == 0);
  assert_that(tools::ceil_kth_root(1, 4) == 1);
  assert_that(tools::ceil_kth_root(2, 4) == 2);
  assert_that(tools::ceil_kth_root(15, 4) == 2);
  assert_that(tools::ceil_kth_root(16, 4) == 2);
  assert_that(tools::ceil_kth_root(17, 4) == 3);
  assert_that(tools::ceil_kth_root(80, 4) == 3);
  assert_that(tools::ceil_kth_root(81, 4) == 3);
  assert_that(tools::ceil_kth_root(82, 4) == 4);
  assert_that(tools::ceil_kth_root(9222710978872688895, 4) == 55108);
  assert_that(tools::ceil_kth_root(9222710978872688896, 4) == 55108);
  assert_that(tools::ceil_kth_root(9222710978872688897, 4) == 55109);
  assert_that(tools::ceil_kth_root(9223372036854775807, 4) == 55109);

  assert_that(tools::ceil_kth_root(0, 5) == 0);
  assert_that(tools::ceil_kth_root(1, 5) == 1);
  assert_that(tools::ceil_kth_root(2, 5) == 2);
  assert_that(tools::ceil_kth_root(31, 5) == 2);
  assert_that(tools::ceil_kth_root(32, 5) == 2);
  assert_that(tools::ceil_kth_root(33, 5) == 3);
  assert_that(tools::ceil_kth_root(242, 5) == 3);
  assert_that(tools::ceil_kth_root(243, 5) == 3);
  assert_that(tools::ceil_kth_root(244, 5) == 4);
  assert_that(tools::ceil_kth_root(9220586390859808767, 5) == 6208);
  assert_that(tools::ceil_kth_root(9220586390859808768, 5) == 6208);
  assert_that(tools::ceil_kth_root(9220586390859808769, 5) == 6209);
  assert_that(tools::ceil_kth_root(9223372036854775807, 5) == 6209);

  assert_that(tools::ceil_kth_root(0, 6) == 0);
  assert_that(tools::ceil_kth_root(1, 6) == 1);
  assert_that(tools::ceil_kth_root(2, 6) == 2);
  assert_that(tools::ceil_kth_root(63, 6) == 2);
  assert_that(tools::ceil_kth_root(64, 6) == 2);
  assert_that(tools::ceil_kth_root(65, 6) == 3);
  assert_that(tools::ceil_kth_root(728, 6) == 3);
  assert_that(tools::ceil_kth_root(729, 6) == 3);
  assert_that(tools::ceil_kth_root(730, 6) == 4);
  assert_that(tools::ceil_kth_root(9217462324974321663, 6) == 1448);
  assert_that(tools::ceil_kth_root(9217462324974321664, 6) == 1448);
  assert_that(tools::ceil_kth_root(9217462324974321665, 6) == 1449);
  assert_that(tools::ceil_kth_root(9223372036854775807, 6) == 1449);

  assert_that(tools::ceil_kth_root(0, 39) == 0);
  assert_that(tools::ceil_kth_root(1, 39) == 1);
  assert_that(tools::ceil_kth_root(2, 39) == 2);
  assert_that(tools::ceil_kth_root(549755813887, 39) == 2);
  assert_that(tools::ceil_kth_root(549755813888, 39) == 2);
  assert_that(tools::ceil_kth_root(549755813889, 39) == 3);
  assert_that(tools::ceil_kth_root(4052555153018976266, 39) == 3);
  assert_that(tools::ceil_kth_root(4052555153018976267, 39) == 3);
  assert_that(tools::ceil_kth_root(4052555153018976268, 39) == 4);
  assert_that(tools::ceil_kth_root(9223372036854775807, 39) == 4);

  assert_that(tools::ceil_kth_root(0, 62) == 0);
  assert_that(tools::ceil_kth_root(1, 62) == 1);
  assert_that(tools::ceil_kth_root(2, 62) == 2);
  assert_that(tools::ceil_kth_root(4611686018427387903, 62) == 2);
  assert_that(tools::ceil_kth_root(4611686018427387904, 62) == 2);
  assert_that(tools::ceil_kth_root(4611686018427387905, 62) == 3);
  assert_that(tools::ceil_kth_root(9223372036854775807, 62) == 3);

  assert_that(tools::ceil_kth_root(0, 63) == 0);
  assert_that(tools::ceil_kth_root(1, 63) == 1);
  assert_that(tools::ceil_kth_root(2, 63) == 2);
  assert_that(tools::ceil_kth_root(9223372036854775807, 63) == 2);

  assert_that(tools::ceil_kth_root(0, 64) == 0);
  assert_that(tools::ceil_kth_root(1, 64) == 1);
  assert_that(tools::ceil_kth_root(2, 64) == 2);
  assert_that(tools::ceil_kth_root(9223372036854775807, 64) == 2);

  std::cout << "Hello World" << '\n';
  return 0;
}
