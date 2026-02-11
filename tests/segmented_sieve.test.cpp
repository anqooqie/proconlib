// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc227/tasks/abc227_g

#include <iostream>
#include <unordered_map>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/segmented_sieve.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

mint solve(const ll N, const int K) {
  std::unordered_map<ll, ll> nCk;
  if (K > 0) {
    tools::segmented_sieve<ll> sieve(K, N - K + 1, N);
    for (ll i = N - K + 1; i <= N; ++i) {
      for (const auto p : sieve.prime_factor_range(i)) {
        ++nCk[p];
      }
    }

    for (ll i = 1; i <= K; ++i) {
      for (const auto p : sieve.prime_factor_range(i)) {
        --nCk[p];
      }
    }
  }

  mint answer(1);
  for (const auto& [p, q] : nCk) {
    answer *= mint(q + 1);
  }
  return answer;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve(260522LL, 0) == mint::raw(1));
  assert_that(solve(250877914575LL, 0) == mint::raw(1));
  assert_that(solve(436426LL, 450) == mint::raw(702197356));
  assert_that(solve(917861648772LL, 118991) == mint::raw(815979133));
  assert_that(solve(933447LL, 818) == mint::raw(722540106));
  assert_that(solve(426262703497LL, 509745) == mint::raw(561446205));
  assert_that(solve(407775LL, 228) == mint::raw(678364367));
  assert_that(solve(828731963982LL, 391307) == mint::raw(692228966));
  assert_that(solve(968417LL, 880) == mint::raw(960576648));
  assert_that(solve(258982631932LL, 309269) == mint::raw(985409932));
  assert_that(solve(999966000289LL, 999983) == mint::raw(141645597));
  assert_that(solve(4922986896LL, 70164) == mint::raw(104415157));
  assert_that(solve(722500LL, 850) == mint::raw(914586245));
  assert_that(solve(731189169216LL, 855096) == mint::raw(623303382));
  assert_that(solve(286225LL, 535) == mint::raw(931530455));
  assert_that(solve(329211LL, 134927) == mint::raw(800661327));
  assert_that(solve(296303238506LL, 552101) == mint::raw(698851498));
  assert_that(solve(686568LL, 338756) == mint::raw(287185310));
  assert_that(solve(16125660016LL, 861628) == mint::raw(183596625));
  assert_that(solve(296263LL, 130165) == mint::raw(959904952));
  assert_that(solve(951492601449LL, 992483) == mint::raw(455362283));
  assert_that(solve(890310LL, 403135) == mint::raw(756935960));
  assert_that(solve(481782177068LL, 898261) == mint::raw(98360632));
  assert_that(solve(8580LL, 7465) == mint::raw(435659331));
  assert_that(solve(449218LL, 372632) == mint::raw(236553770));
  assert_that(solve(594328LL, 392059) == mint::raw(175736881));
  assert_that(solve(829355LL, 758690) == mint::raw(559233694));
  assert_that(solve(323798LL, 323798) == mint::raw(1));
  assert_that(solve(231618LL, 231618) == mint::raw(1));
  assert_that(solve(1000000000000LL, 0) == mint::raw(1));
  assert_that(solve(999999999995LL, 999991) == mint::raw(181590252));
  assert_that(solve(999999999996LL, 420202) == mint::raw(289049345));
  assert_that(solve(999999999994LL, 1) == mint::raw(8));
  assert_that(solve(999999999992LL, 999998) == mint::raw(290102227));
  assert_that(solve(999999999999LL, 328262) == mint::raw(577126736));
  assert_that(solve(1LL, 0) == mint::raw(1));
  assert_that(solve(1LL, 1) == mint::raw(1));
  assert_that(solve(5LL, 2) == mint::raw(4));
  assert_that(solve(103LL, 3) == mint::raw(8));
  assert_that(solve(1000000000000LL, 1000000) == mint::raw(110520107));

  return 0;
}
