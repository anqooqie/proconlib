// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/inversion_number.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  std::vector<ll> a;
  std::copy_n(std::istream_iterator<ll>(std::cin), n, std::back_inserter(a));
  std::cout << tools::inversion_number(a.begin(), a.end()) << '\n';
  return 0;
}
