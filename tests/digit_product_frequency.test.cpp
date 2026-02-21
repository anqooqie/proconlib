// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc208/tasks/abc208_e

#include <iostream>
#include <numeric>
#include "tools/assert_that.hpp"
#include "tools/digit_product_frequency.hpp"

using ll = long long;

ll solve(const ll N, const int K) {
  const auto freq = tools::digit_product_frequency(N);
  return std::accumulate(freq.begin(), freq.upper_bound(K), 0LL, [](const auto sum, const auto& pair) { return sum + pair.second; });
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve(801890131382041815LL, 1) == 666388030072250961LL);
  assert_that(solve(592783285923278612LL, 1) == 492127000706421141LL);
  assert_that(solve(788760612927149638LL, 295) == 655373344034353395LL);
  assert_that(solve(204696942445405777LL, 835) == 169257931634234755LL);
  assert_that(solve(23297363569791125LL, 391) == 18902925989262912LL);
  assert_that(solve(52527274608650133LL, 231) == 42728857734307917LL);
  assert_that(solve(871425705028477040LL, 597) == 724732992531007935LL);
  assert_that(solve(999999999999999938LL, 999999950) == 841103274358172760LL);
  assert_that(solve(999999999999999990LL, 999999957) == 841103274358172766LL);
  assert_that(solve(999999999999999980LL, 999999933) == 841103274358172765LL);
  assert_that(solve(999999999999999953LL, 999999937) == 841103274358172762LL);
  assert_that(solve(999999999999999939LL, 999999923) == 841103274358172760LL);
  assert_that(solve(1LL, 105322777) == 1LL);
  assert_that(solve(1LL, 271444166) == 1LL);
  assert_that(solve(8420776LL, 738) == 4195282LL);
  assert_that(solve(5172720LL, 124) == 2443569LL);
  assert_that(solve(4086264LL, 92) == 1916318LL);
  assert_that(solve(6581154LL, 542) == 3238850LL);
  assert_that(solve(6739549LL, 509) == 3295977LL);
  assert_that(solve(498788379325901241LL, 910924165) == 420408691788033432LL);
  assert_that(solve(678280404236960168LL, 487751110) == 568895365269412470LL);
  assert_that(solve(273102229147777950LL, 671189099) == 230328734928712567LL);
  assert_that(solve(688322676746607413LL, 794745756) == 579063881684020681LL);
  assert_that(solve(512611985713242481LL, 249704670) == 429803313528466515LL);
  assert_that(solve(13LL, 2) == 5LL);
  assert_that(solve(100LL, 80) == 99LL);
  assert_that(solve(1000000000000000000LL, 1000000000) == 841103275147365677LL);
  assert_that(solve(614LL, 490) == 614LL);
  assert_that(solve(420LL, 945) == 420LL);
  assert_that(solve(613LL, 585) == 613LL);
  assert_that(solve(760LL, 38) == 404LL);
  assert_that(solve(926LL, 725) == 926LL);
  assert_that(solve(667LL, 685) == 667LL);
  assert_that(solve(449LL, 455) == 449LL);
  assert_that(solve(873LL, 948) == 873LL);
  assert_that(solve(726LL, 180) == 662LL);
  assert_that(solve(176LL, 60) == 170LL);

  return 0;
}
