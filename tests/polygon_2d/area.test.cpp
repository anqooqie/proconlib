// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_A

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/rational.hpp"
#include "tools/vector2.hpp"
#include "tools/polygon_2d.hpp"

using ll = long long;
using T = tools::rational;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n;
  std::cin >> n;
  std::vector<tools::vector2<T>> g;
  std::copy_n(std::istream_iterator<tools::vector2<T>>(std::cin), n, std::back_inserter(g));
  tools::polygon_2d<T, true> polygon(g.begin(), g.end());

  std::cout << std::fixed << std::setprecision(1) << static_cast<double>(polygon.area()) << '\n';
  return 0;
}
