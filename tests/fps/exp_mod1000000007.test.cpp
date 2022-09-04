#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/fps.hpp"

using mint = atcoder::modint1000000007;

void solve(const tools::fps<mint>& a, const tools::fps<mint>& expected) {
  assert_that(expected == a.exp());
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  solve(tools::fps<mint>({0, 1, 2, 3, 4}), tools::fps<mint>({1, 1, 500000006, 166666673, 41666677}));
  solve(tools::fps<mint>({0}), tools::fps<mint>({1}));
  solve(tools::fps<mint>({0, 264704197}), tools::fps<mint>({1, 264704197}));
  solve(tools::fps<mint>({0, 682152023, 451794314}), tools::fps<mint>({1, 682152023, 564630752}));
  solve(tools::fps<mint>({0, 627477696, 504915182, 841612625}), tools::fps<mint>({1, 627477696, 615600494, 390176605}));
  solve(tools::fps<mint>({0, 729561619, 415335212, 437019262, 878914770}), tools::fps<mint>({1, 729561619, 11375257, 437701961, 334342229}));
  solve(tools::fps<mint>({0, 173330281, 220603612, 817609646, 512965573, 521724489}), tools::fps<mint>({1, 173330281, 771221245, 401981586, 782289750, 703568819}));
  solve(tools::fps<mint>({0, 841413509, 58432763, 698722376, 544666771, 190469745, 876171369}), tools::fps<mint>({1, 841413509, 644360899, 338466365, 45333096, 484662543, 777842481}));
  solve(tools::fps<mint>({0, 251229786, 256388306, 355236246, 511734336, 908168265, 367810644, 342843868}), tools::fps<mint>({1, 251229786, 722283790, 461751668, 607428370, 68463418, 668520856, 986268982}));
  solve(tools::fps<mint>({0, 118232767, 222490630, 398642533, 451309769, 425956381, 488484142, 913374112, 586809}), tools::fps<mint>({1, 118232767, 269802320, 691305862, 194112550, 858277884, 688009741, 275998576, 946785801}));
  solve(tools::fps<mint>({0, 907649120, 290651129, 813718295, 770591820, 913049957, 587190944, 411145555, 899491439, 722412549}), tools::fps<mint>({1, 907649120, 925644116, 38331988, 156875359, 697776255, 802320078, 499725651, 949053640, 121509191}));

  std::cout << "Hello World" << '\n';
  return 0;
}
