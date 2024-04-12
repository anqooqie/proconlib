#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/large_fact_mod_cache.hpp"
#include "tools/assert_that.hpp"

using ll = long long;
using mint = atcoder::modint1000000007;
tools::large_fact_mod_cache<mint> cache;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  static const auto discard = [](const char c) {
    assert_that(std::cin.peek() == c);
    std::cin.ignore();
  };

  ll T;
  std::cin >> T;
  discard('\n');
  for (ll t = 0; t < T; ++t) {
    char type;
    ll N, K;
    std::cin >> type;
    assert_that(type == 'C' || type == 'P' || type == 'H');
    discard('(');
    std::cin >> N;
    discard(',');
    std::cin >> K;
    discard(')');
    discard('\n');

    if (type == 'C') {
      std::cout << cache.combination(N, K).val() << '\n';
    } else if (type == 'P') {
      std::cout << cache.permutation(N, K).val() << '\n';
    } else if (type == 'H') {
      std::cout << cache.combination_with_repetition(N, K).val() << '\n';
    }
  }

  return 0;
}
