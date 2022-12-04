#define PROBLEM "https://atcoder.jp/contests/abc245/tasks/abc245_d"

#include <iostream>
#include <cmath>
#include "tools/polynomial.hpp"
#include "tools/join.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  tools::polynomial<double> A(N + 1), C(N + M + 1);
  for (auto& A_i : A) std::cin >> A_i;
  for (auto& C_i : C) std::cin >> C_i;

  const auto B = C / A;
  ::std::vector<ll> answers;
  for (const auto& B_i : B) {
    answers.push_back(::std::round(B_i));
  }

  std::cout << tools::join(answers.begin(), answers.end(), " ") << '\n';
  return 0;
}
