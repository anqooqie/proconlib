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

  solve(tools::fps<mint>({mint(1), mint(1), mint(499122179), mint(166374064), mint(291154613)}), tools::fps<mint>({mint(0), mint(1), mint(999122182), mint(585221), mint(960979027)}));
  solve(tools::fps<mint>({mint(1)}), tools::fps<mint>({mint(0)}));
  solve(tools::fps<mint>({mint(1), mint(264704197)}), tools::fps<mint>({mint(0), mint(264704197)}));
  solve(tools::fps<mint>({mint(1), mint(682152023), mint(451794314)}), tools::fps<mint>({mint(0), mint(682152023), mint(338957876)}));
  solve(tools::fps<mint>({mint(1), mint(627477696), mint(504915182), mint(841612625)}), tools::fps<mint>({mint(0), mint(627477696), mint(394229870), mint(361681842)}));
  solve(tools::fps<mint>({mint(1), mint(729561619), mint(415335212), mint(437019262), mint(878914770)}), tools::fps<mint>({mint(0), mint(729561619), mint(819295167), mint(718365157), mint(380771800)}));
  solve(tools::fps<mint>({mint(1), mint(173330281), mint(220603612), mint(817609646), mint(512965573), mint(521724489)}), tools::fps<mint>({mint(0), mint(173330281), mint(669985986), mint(616611616), mint(164659373), mint(265939606)}));
  solve(tools::fps<mint>({mint(1), mint(841413509), mint(58432763), mint(698722376), mint(544666771), mint(190469745), mint(876171369)}), tools::fps<mint>({mint(0), mint(841413509), mint(472504634), mint(541512689), mint(248397644), mint(56465855), mint(706193734)}));
  solve(tools::fps<mint>({mint(1), mint(251229786), mint(256388306), mint(355236246), mint(511734336), mint(908168265), mint(367810644), mint(342843868)}), tools::fps<mint>({mint(0), mint(251229786), mint(790492829), mint(173079494), mint(244864021), mint(397382104), mint(196180830), mint(56137219)}));
  solve(tools::fps<mint>({mint(1), mint(118232767), mint(222490630), mint(398642533), mint(451309769), mint(425956381), mint(488484142), mint(913374112), mint(586809)}), tools::fps<mint>({mint(0), mint(118232767), mint(175178940), mint(86968890), mint(301690418), mint(882749806), mint(514112978), mint(213130551), mint(698601823)}));
  solve(tools::fps<mint>({mint(1), mint(907649120), mint(290651129), mint(813718295), mint(770591820), mint(913049957), mint(587190944), mint(411145555), mint(899491439), mint(722412549)}), tools::fps<mint>({mint(0), mint(907649120), mint(655658149), mint(411370281), mint(813857328), mint(304069637), mint(653880096), mint(644045920), mint(986672147), mint(805127995)}));

  std::cout << "Hello World" << '\n';
  return 0;
}
