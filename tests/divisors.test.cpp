#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"

#include <iostream>
#include <vector>
#include <algorithm>
#include "tools/divisors.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll a, b, c;
  std::cin >> a >> b >> c;
  const ::std::vector<ll> divisors = tools::divisors(c);
  std::cout << std::count_if(divisors.begin(), divisors.end(), [&](const ll& d) { return a <= d && d <= b; }) << '\n';
  return 0;
}
