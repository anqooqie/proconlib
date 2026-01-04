// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc276/tasks/abc276_g

#include <iostream>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/fps.hpp"
#include "tools/sparse_fps_pow.hpp"

using mint = atcoder::modint998244353;

mint solve(const int N, const int M) {
  using P = std::pair<int, mint>;
  return tools::sparse_fps_pow({P{1, mint(1)}, P{2, mint(1)}}, {P{0, mint(1)}, P{3, mint(-1)}}, N - 1, M + 1).divide_inplace({{0, mint(1)}, {1, mint(-2)}, {2, mint(1)}})[M];
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve(3, 4) == mint::raw(8));
  assert_that(solve(276, 10000000) == mint::raw(909213205));
  assert_that(solve(2, 1) == mint::raw(1));
  assert_that(solve(2, 2) == mint::raw(3));
  assert_that(solve(2, 3) == mint::raw(5));
  assert_that(solve(2, 4) == mint::raw(8));
  assert_that(solve(3, 1) == mint::raw(0));
  assert_that(solve(3, 2) == mint::raw(1));
  assert_that(solve(3, 3) == mint::raw(4));
  assert_that(solve(3, 4) == mint::raw(8));
  assert_that(solve(4, 1) == mint::raw(0));
  assert_that(solve(4, 2) == mint::raw(0));
  assert_that(solve(4, 3) == mint::raw(1));
  assert_that(solve(4, 4) == mint::raw(5));
  assert_that(solve(2, 10000000) == mint::raw(962808977));
  assert_that(solve(3, 10000000) == mint::raw(107270003));
  assert_that(solve(4, 10000000) == mint::raw(409885375));
  assert_that(solve(5, 10000000) == mint::raw(701576233));
  assert_that(solve(6, 10000000) == mint::raw(91140356));
  assert_that(solve(7, 10000000) == mint::raw(871453462));
  assert_that(solve(8, 10000000) == mint::raw(216116240));
  assert_that(solve(7165882, 4979445) == mint::raw(0));
  assert_that(solve(2593913, 3690081) == mint::raw(352065276));
  assert_that(solve(7255322, 1047202) == mint::raw(0));
  assert_that(solve(5681501, 8894325) == mint::raw(285185982));
  assert_that(solve(4517699, 2804784) == mint::raw(0));
  assert_that(solve(2911042, 9330739) == mint::raw(833998410));
  assert_that(solve(7772319, 2329211) == mint::raw(0));
  assert_that(solve(2079387, 3238506) == mint::raw(107103074));
  assert_that(solve(10000000, 10000000) == mint::raw(10000001));
  assert_that(solve(5000000, 9999999) == mint::raw(342150353));
  assert_that(solve(2500000, 9999998) == mint::raw(797943309));
  assert_that(solve(1250000, 9999997) == mint::raw(584594191));
  assert_that(solve(625000, 9999996) == mint::raw(314124565));
  assert_that(solve(10000000, 9999999) == mint::raw(1));
  assert_that(solve(10000000, 9999998) == mint::raw(0));
  assert_that(solve(10000000, 9999997) == mint::raw(0));
  assert_that(solve(9999999, 10000000) == mint::raw(930091291));
  assert_that(solve(9999999, 9999999) == mint::raw(10000000));
  assert_that(solve(9999999, 9999998) == mint::raw(1));
  assert_that(solve(9999999, 9999997) == mint::raw(0));
  assert_that(solve(9999998, 10000000) == mint::raw(728711115));
  assert_that(solve(9999998, 9999999) == mint::raw(920091292));
  assert_that(solve(9999998, 9999998) == mint::raw(9999999));
  assert_that(solve(9999998, 9999997) == mint::raw(1));
  assert_that(solve(9999997, 10000000) == mint::raw(67204116));
  assert_that(solve(9999997, 9999999) == mint::raw(816864173));
  assert_that(solve(9999997, 9999998) == mint::raw(910091294));
  assert_that(solve(9999997, 9999997) == mint::raw(9999998));

  return 0;
}
