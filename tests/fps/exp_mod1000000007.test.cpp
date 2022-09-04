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

  solve(tools::fps<mint>({mint(0), mint(1), mint(2), mint(3), mint(4)}), tools::fps<mint>({mint(1), mint(1), mint(500000006), mint(166666673), mint(41666677)}));
  solve(tools::fps<mint>({mint(0)}), tools::fps<mint>({mint(1)}));
  solve(tools::fps<mint>({mint(0), mint(264704197)}), tools::fps<mint>({mint(1), mint(264704197)}));
  solve(tools::fps<mint>({mint(0), mint(682152023), mint(451794314)}), tools::fps<mint>({mint(1), mint(682152023), mint(564630752)}));
  solve(tools::fps<mint>({mint(0), mint(627477696), mint(504915182), mint(841612625)}), tools::fps<mint>({mint(1), mint(627477696), mint(615600494), mint(390176605)}));
  solve(tools::fps<mint>({mint(0), mint(729561619), mint(415335212), mint(437019262), mint(878914770)}), tools::fps<mint>({mint(1), mint(729561619), mint(11375257), mint(437701961), mint(334342229)}));
  solve(tools::fps<mint>({mint(0), mint(173330281), mint(220603612), mint(817609646), mint(512965573), mint(521724489)}), tools::fps<mint>({mint(1), mint(173330281), mint(771221245), mint(401981586), mint(782289750), mint(703568819)}));
  solve(tools::fps<mint>({mint(0), mint(841413509), mint(58432763), mint(698722376), mint(544666771), mint(190469745), mint(876171369)}), tools::fps<mint>({mint(1), mint(841413509), mint(644360899), mint(338466365), mint(45333096), mint(484662543), mint(777842481)}));
  solve(tools::fps<mint>({mint(0), mint(251229786), mint(256388306), mint(355236246), mint(511734336), mint(908168265), mint(367810644), mint(342843868)}), tools::fps<mint>({mint(1), mint(251229786), mint(722283790), mint(461751668), mint(607428370), mint(68463418), mint(668520856), mint(986268982)}));
  solve(tools::fps<mint>({mint(0), mint(118232767), mint(222490630), mint(398642533), mint(451309769), mint(425956381), mint(488484142), mint(913374112), mint(586809)}), tools::fps<mint>({mint(1), mint(118232767), mint(269802320), mint(691305862), mint(194112550), mint(858277884), mint(688009741), mint(275998576), mint(946785801)}));
  solve(tools::fps<mint>({mint(0), mint(907649120), mint(290651129), mint(813718295), mint(770591820), mint(913049957), mint(587190944), mint(411145555), mint(899491439), mint(722412549)}), tools::fps<mint>({mint(1), mint(907649120), mint(925644116), mint(38331988), mint(156875359), mint(697776255), mint(802320078), mint(499725651), mint(949053640), mint(121509191)}));

  std::cout << "Hello World" << '\n';
  return 0;
}
