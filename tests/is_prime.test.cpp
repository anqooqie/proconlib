#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/is_prime.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n;
  std::cin >> n;
  std::vector<i64> x;
  std::copy_n(std::istream_iterator<i64>(std::cin), n, std::back_inserter(x));

  for (const i64& x_i : x) {
    std::cout << x_i << ' ' << (tools::is_prime(x_i) ? 1 : 0) << '\n';
  }
  return 0;
}
