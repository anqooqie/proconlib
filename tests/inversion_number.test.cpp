#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/inversion_number.hpp"

using i64 = std::int_fast64_t;

int main() {
  i64 n;
  std::cin >> n;
  std::vector<i64> a;
  std::copy_n(std::istream_iterator<i64>(std::cin), n, std::back_inserter(a));
  std::cout << tools::inversion_number(a.begin(), a.end()) << '\n';
  return 0;
}
