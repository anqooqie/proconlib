// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc412/tasks/abc412_e

#include <iostream>
#include <ranges>
#include "tools/assert_that.hpp"
#include "tools/ceil_kth_root.hpp"
#include "tools/floor_kth_root.hpp"
#include "tools/floor_log2.hpp"
#include "tools/simpler_segmented_sieve.hpp"

using ll = long long;

ll solve(const ll L, const ll R) {
  ll answer = 1;
  if (L + 1 <= R) {
    tools::simpler_segmented_sieve sieve(L + 1, R);
    answer += std::ranges::size(sieve.large_prime_range(L + 1, R));
    for (ll k = 2; k <= tools::floor_log2(R); ++k) {
      if (const auto L_k = tools::ceil_kth_root(L + 1, k), R_k = tools::floor_kth_root(R, k); L_k <= R_k) {
        answer += std::ranges::size(sieve.small_prime_range(L_k, R_k));
      }
    }
  }
  return answer;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve(4, 12) == 6);
  assert_that(solve(123456789, 123456789) == 1);
  assert_that(solve(99999990000000, 100000000000000) == 310458);
  
  assert_that(solve(1, 1) == 1);
  assert_that(solve(1, 2) == 2);
  assert_that(solve(1, 3) == 3);
  assert_that(solve(1, 4) == 4);
  assert_that(solve(1, 5) == 5);
  assert_that(solve(1, 6) == 5);
  assert_that(solve(1, 7) == 6);
  assert_that(solve(1, 8) == 7);
  assert_that(solve(1, 9) == 8);
  assert_that(solve(1, 10) == 8);
  assert_that(solve(2, 2) == 1);
  assert_that(solve(2, 3) == 2);
  assert_that(solve(2, 4) == 3);
  assert_that(solve(2, 5) == 4);
  assert_that(solve(2, 6) == 4);
  assert_that(solve(6, 6) == 1);
  assert_that(solve(6, 7) == 2);
  assert_that(solve(6, 8) == 3);
  assert_that(solve(6, 9) == 4);
  assert_that(solve(6, 10) == 4);

  assert_that(solve(1, 10000001) == 665135);
  assert_that(solve(2, 10000002) == 665134);

  assert_that(solve(7291297807098, 7291300925731) == 105215);
  assert_that(solve(1632163833109, 1632169508586) == 201922);
  assert_that(solve(81089952915431, 81089961928268) == 281510);
  assert_that(solve(83801350188413, 83801357601095) == 230918);
  assert_that(solve(40128628501956, 40128632123156) == 115929);
  assert_that(solve(86595312160968, 86595319497962) == 228176);
  assert_that(solve(56458715710795, 56458722127250) == 202842);
  assert_that(solve(89503694845116, 89503700831717) == 186448);
  assert_that(solve(64890423893554, 64890425199039) == 40938);
  assert_that(solve(67181633717331, 67181637045890) == 104464);

  assert_that(solve(33716863922352, 33716863922361) == 1);
  assert_that(solve(311021332722, 311021332731) == 1);
  assert_that(solve(69587223089975, 69587223089978) == 2);
  assert_that(solve(52652176473886, 52652176473888) == 1);
  assert_that(solve(28802790142010, 28802790142013) == 1);
  assert_that(solve(33162340680012, 33162340680013) == 1);
  assert_that(solve(52769235597872, 52769235597875) == 1);
  assert_that(solve(43996456722172, 43996456722174) == 2);
  assert_that(solve(41262348609280, 41262348609288) == 2);
  assert_that(solve(94066473782574, 94066473782576) == 1);

  return 0;
}
