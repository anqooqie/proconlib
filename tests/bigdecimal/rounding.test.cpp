// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc273/tasks/abc273_b

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/bigdecimal.hpp"
#include "tools/rounding_mode.hpp"

tools::bigdecimal solve(tools::bigdecimal X, const int K) {
  for (int k = 0; k < K; ++k) {
    X.divide_inplace(tools::bigdecimal(1), -k - 1, tools::rounding_mode::half_up);
  }
  return X;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve(tools::bigdecimal("2048"), 2) == tools::bigdecimal("2100"));
  assert_that(solve(tools::bigdecimal("1"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("999"), 3) == tools::bigdecimal("1000"));
  assert_that(solve(tools::bigdecimal("314159265358979"), 12) == tools::bigdecimal("314000000000000"));
  assert_that(solve(tools::bigdecimal("444444444444445"), 1) == tools::bigdecimal("444444444444450"));
  assert_that(solve(tools::bigdecimal("444444444444445"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("444444444444445"), 3) == tools::bigdecimal("444444444445000"));
  assert_that(solve(tools::bigdecimal("444444444444445"), 4) == tools::bigdecimal("444444444450000"));
  assert_that(solve(tools::bigdecimal("444444444444445"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("44444444444445"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("944444444444445"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("94444444444445"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("0"), 1) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("0"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("5"), 1) == tools::bigdecimal("10"));
  assert_that(solve(tools::bigdecimal("5"), 2) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("999999999999999"), 1) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("999999999999999"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("999999999999999"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("99999999999999"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("43"), 1) == tools::bigdecimal("40"));
  assert_that(solve(tools::bigdecimal("44"), 1) == tools::bigdecimal("40"));
  assert_that(solve(tools::bigdecimal("45"), 1) == tools::bigdecimal("50"));
  assert_that(solve(tools::bigdecimal("46"), 1) == tools::bigdecimal("50"));
  assert_that(solve(tools::bigdecimal("43"), 2) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("44"), 2) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("45"), 2) == tools::bigdecimal("100"));
  assert_that(solve(tools::bigdecimal("46"), 2) == tools::bigdecimal("100"));
  assert_that(solve(tools::bigdecimal("444444444444450"), 14) == tools::bigdecimal("500000000000000"));
  assert_that(solve(tools::bigdecimal("944444500000000"), 13) == tools::bigdecimal("950000000000000"));
  assert_that(solve(tools::bigdecimal("444444445000000"), 5) == tools::bigdecimal("444444445000000"));
  assert_that(solve(tools::bigdecimal("944444444445000"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("944444444450000"), 14) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("944445000000000"), 10) == tools::bigdecimal("944450000000000"));
  assert_that(solve(tools::bigdecimal("444450000000000"), 8) == tools::bigdecimal("444450000000000"));
  assert_that(solve(tools::bigdecimal("444444444500000"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("444444500000000"), 14) == tools::bigdecimal("500000000000000"));
  assert_that(solve(tools::bigdecimal("444444444444450"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("944500000000000"), 3) == tools::bigdecimal("944500000000000"));
  assert_that(solve(tools::bigdecimal("444444444500000"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("950000000000000"), 14) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("444444445000000"), 11) == tools::bigdecimal("444500000000000"));
  assert_that(solve(tools::bigdecimal("444450000000000"), 8) == tools::bigdecimal("444450000000000"));
  assert_that(solve(tools::bigdecimal("444444500000000"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("244444800000000"), 14) == tools::bigdecimal("300000000000000"));
  assert_that(solve(tools::bigdecimal("244444444444800"), 8) == tools::bigdecimal("244444500000000"));
  assert_that(solve(tools::bigdecimal("144444600000000"), 8) == tools::bigdecimal("144444600000000"));
  assert_that(solve(tools::bigdecimal("144444600000000"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("344444444600000"), 14) == tools::bigdecimal("400000000000000"));
  assert_that(solve(tools::bigdecimal("144447000000000"), 12) == tools::bigdecimal("145000000000000"));
  assert_that(solve(tools::bigdecimal("246000000000000"), 10) == tools::bigdecimal("246000000000000"));
  assert_that(solve(tools::bigdecimal("144444444449000"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("644444444444900"), 14) == tools::bigdecimal("700000000000000"));
  assert_that(solve(tools::bigdecimal("844470000000000"), 11) == tools::bigdecimal("844500000000000"));
  assert_that(solve(tools::bigdecimal("844700000000000"), 9) == tools::bigdecimal("844700000000000"));
  assert_that(solve(tools::bigdecimal("746000000000000"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("544447000000000"), 14) == tools::bigdecimal("600000000000000"));
  assert_that(solve(tools::bigdecimal("544446000000000"), 12) == tools::bigdecimal("545000000000000"));
  assert_that(solve(tools::bigdecimal("844800000000000"), 11) == tools::bigdecimal("844800000000000"));
  assert_that(solve(tools::bigdecimal("780000000000000"), 15) == tools::bigdecimal("1000000000000000"));
  assert_that(solve(tools::bigdecimal("901048185320"), 5) == tools::bigdecimal("901048200000"));
  assert_that(solve(tools::bigdecimal("596949"), 6) == tools::bigdecimal("1000000"));
  assert_that(solve(tools::bigdecimal("1683"), 4) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("24806"), 9) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("728361"), 4) == tools::bigdecimal("730000"));
  assert_that(solve(tools::bigdecimal("45"), 2) == tools::bigdecimal("100"));
  assert_that(solve(tools::bigdecimal("9102555156"), 1) == tools::bigdecimal("9102555160"));
  assert_that(solve(tools::bigdecimal("341039"), 3) == tools::bigdecimal("341000"));
  assert_that(solve(tools::bigdecimal("93039348447"), 15) == tools::bigdecimal("0"));
  assert_that(solve(tools::bigdecimal("342"), 1) == tools::bigdecimal("340"));
  assert_that(solve(tools::bigdecimal("999073936"), 4) == tools::bigdecimal("999070000"));
  assert_that(solve(tools::bigdecimal("7212413"), 2) == tools::bigdecimal("7212400"));
  assert_that(solve(tools::bigdecimal("436281229766151"), 4) == tools::bigdecimal("436281229770000"));
  assert_that(solve(tools::bigdecimal("8674247990068"), 14) == tools::bigdecimal("0"));

  return 0;
}
