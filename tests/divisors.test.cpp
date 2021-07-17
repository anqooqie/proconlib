#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include "tools/divisors.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 a, b, c;
  std::cin >> a >> b >> c;
  const ::std::vector<i64> divisors = tools::divisors(c);
  std::cout << std::count_if(divisors.begin(), divisors.end(), [&](const i64& d) { return a <= d && d <= b; }) << '\n';
  return 0;
}
