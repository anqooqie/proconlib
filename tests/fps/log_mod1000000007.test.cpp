#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/fps.hpp"

using mint = atcoder::modint1000000007;

void solve(const tools::fps<mint>& a, const tools::fps<mint>& expected) {
  assert_that(expected == a.log());
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  solve(tools::fps<mint>({1, 1, 499122179, 166374064, 291154613}), tools::fps<mint>({0, 1, 999122182, 585221, 960979027}));
  solve(tools::fps<mint>({1}), tools::fps<mint>({0}));
  solve(tools::fps<mint>({1, 264704197}), tools::fps<mint>({0, 264704197}));
  solve(tools::fps<mint>({1, 682152023, 451794314}), tools::fps<mint>({0, 682152023, 338957876}));
  solve(tools::fps<mint>({1, 627477696, 504915182, 841612625}), tools::fps<mint>({0, 627477696, 394229870, 361681842}));
  solve(tools::fps<mint>({1, 729561619, 415335212, 437019262, 878914770}), tools::fps<mint>({0, 729561619, 819295167, 718365157, 380771800}));
  solve(tools::fps<mint>({1, 173330281, 220603612, 817609646, 512965573, 521724489}), tools::fps<mint>({0, 173330281, 669985986, 616611616, 164659373, 265939606}));
  solve(tools::fps<mint>({1, 841413509, 58432763, 698722376, 544666771, 190469745, 876171369}), tools::fps<mint>({0, 841413509, 472504634, 541512689, 248397644, 56465855, 706193734}));
  solve(tools::fps<mint>({1, 251229786, 256388306, 355236246, 511734336, 908168265, 367810644, 342843868}), tools::fps<mint>({0, 251229786, 790492829, 173079494, 244864021, 397382104, 196180830, 56137219}));
  solve(tools::fps<mint>({1, 118232767, 222490630, 398642533, 451309769, 425956381, 488484142, 913374112, 586809}), tools::fps<mint>({0, 118232767, 175178940, 86968890, 301690418, 882749806, 514112978, 213130551, 698601823}));
  solve(tools::fps<mint>({1, 907649120, 290651129, 813718295, 770591820, 913049957, 587190944, 411145555, 899491439, 722412549}), tools::fps<mint>({0, 907649120, 655658149, 411370281, 813857328, 304069637, 653880096, 644045920, 986672147, 805127995}));

  std::cout << "Hello World" << '\n';
  return 0;
}
