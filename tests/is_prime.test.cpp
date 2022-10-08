#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/is_prime.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  std::vector<ll> x;
  std::copy_n(std::istream_iterator<ll>(std::cin), n, std::back_inserter(x));

  for (const ll& x_i : x) {
    std::cout << x_i << ' ' << (tools::is_prime(x_i) ? 1 : 0) << '\n';
  }
  return 0;
}
