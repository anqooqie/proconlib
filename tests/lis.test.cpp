#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D"

#include <iostream>
#include <vector>
#include "tools/lis.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  std::vector<ll> a(n);
  for (ll& a_i : a) std::cin >> a_i;
  std::cout << tools::lis(a.begin(), a.end(), true) << '\n';

  return 0;
}
