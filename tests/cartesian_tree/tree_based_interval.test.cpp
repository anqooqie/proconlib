// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc407/tasks/abc407_f

#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/cartesian_tree.hpp"
#include "tools/second_order_imos.hpp"

using ll = long long;

std::vector<ll> solve(const std::vector<ll>& A) {
  const ll N = A.size();

  tools::cartesian_tree ct(A, std::greater<ll>{});
  tools::second_order_imos<ll> answers(N + 1);
  for (ll i = 0; i < N; ++i) {
    const auto& [l, r] = ct.get_vertex(i).tree_based_interval;
    const auto c = std::min(i - l + 1, r - i);
    answers.add(0, c, 0, A[i]);
    answers.add(c, r - l + 1 - c, c * A[i], 0);
    answers.add(r - l + 1 - c, r - l + 1, c * A[i], -A[i]);
  }

  return answers | std::views::drop(1) | std::ranges::to<std::vector>();
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  assert_that(solve(std::vector<ll>{5, 3, 4, 2}) == std::vector<ll>{14, 13, 9, 5});
  assert_that(solve(std::vector<ll>{2, 0, 2, 5, 0, 5, 2, 4}) == std::vector<ll>{20, 28, 27, 25, 20, 15, 10, 5});  
  assert_that(solve(std::vector<ll>{9203973, 9141294, 9444773, 9292472, 5507634, 9599162, 497764, 430010, 4152216, 3574307, 430010}) == std::vector<ll>{61273615, 68960818, 69588453, 65590626, 61592799, 57594972, 47995810, 38396648, 28797486, 19198324, 9599162});

  return 0;
}
