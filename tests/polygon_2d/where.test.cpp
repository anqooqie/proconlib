#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_C"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/vector2.hpp"
#include "tools/polygon_2d.hpp"

using ll = long long;
using T = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  std::vector<tools::vector2<T>> g;
  std::copy_n(std::istream_iterator<tools::vector2<T>>(std::cin), n, std::back_inserter(g));
  tools::polygon_2d<T, false> polygon(g.begin(), g.end());

  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    tools::vector2<T> p;
    std::cin >> p;
    std::cout << polygon.where(p) + 1 << '\n';
  }

  return 0;
}
