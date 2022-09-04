#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/fps.hpp"

using mint = atcoder::modint1000000007;

void solve(const tools::fps<mint>& a, const tools::fps<mint>& expected) {
  assert_that(expected == a.inv());
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  solve(tools::fps<mint>({mint(5), mint(4), mint(3), mint(2), mint(1)}), tools::fps<mint>({mint(400000003), mint(880000006), mint(856000006), mint(427200003), mint(712640005)}));
  solve(tools::fps<mint>({mint(192279221)}), tools::fps<mint>({mint(73800908)}));
  solve(tools::fps<mint>({mint(264704198), mint(120999146)}), tools::fps<mint>({mint(287907068), mint(800104509)}));
  solve(tools::fps<mint>({mint(682152024), mint(451794314), mint(2028037)}), tools::fps<mint>({mint(574612060), mint(952113573), mint(8338112)}));
  solve(tools::fps<mint>({mint(627477697), mint(504915182), mint(841612625), mint(594492394)}), tools::fps<mint>({mint(668857537), mint(250555279), mint(407226641), mint(689556497)}));
  solve(tools::fps<mint>({mint(729561620), mint(415335212), mint(437019262), mint(878914770), mint(692819383)}), tools::fps<mint>({mint(787440026), mint(114299336), mint(803189374), mint(407812379), mint(245736221)}));
  solve(tools::fps<mint>({mint(173330282), mint(220603612), mint(817609646), mint(512965573), mint(521724489), mint(141011335)}), tools::fps<mint>({mint(191023016), mint(985890395), mint(527644792), mint(72988565), mint(170242711), mint(382839670)}));
  solve(tools::fps<mint>({mint(841413510), mint(58432763), mint(698722376), mint(544666771), mint(190469745), mint(876171369), mint(379243778)}), tools::fps<mint>({mint(433510165), mint(164122061), mint(186933015), mint(588614905), mint(202135306), mint(292312010), mint(956310839)}));
  solve(tools::fps<mint>({mint(251229787), mint(256388306), mint(355236246), mint(511734336), mint(908168265), mint(367810644), mint(342843868), mint(180913440)}), tools::fps<mint>({mint(271928983), mint(224283009), mint(490664115), mint(433104026), mint(563577540), mint(648487834), mint(724935186), mint(645042523)}));
  solve(tools::fps<mint>({mint(118232768), mint(222490630), mint(398642533), mint(451309769), mint(425956381), mint(488484142), mint(913374112), mint(586809), mint(283205947)}), tools::fps<mint>({mint(577402108), mint(68678847), mint(320662214), mint(725944102), mint(334829804), mint(745243159), mint(920134107), mint(576164874), mint(608815609)}));
  solve(tools::fps<mint>({mint(907649121), mint(290651129), mint(813718295), mint(770591820), mint(913049957), mint(587190944), mint(411145555), mint(899491439), mint(722412549), mint(182227749)}), tools::fps<mint>({mint(774404931), mint(110665955), mint(52469364), mint(984072205), mint(887285826), mint(364153357), mint(481939283), mint(290281262), mint(373901157), mint(611152916)}));

  std::cout << "Hello World" << '\n';
  return 0;
}
