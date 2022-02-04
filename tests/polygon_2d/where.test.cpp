#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_C"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/vector2.hpp"
#include "tools/polygon_2d.hpp"

using i64 = std::int_fast64_t;
using T = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n;
  std::cin >> n;
  std::vector<tools::vector2<T>> g;
  std::copy_n(std::istream_iterator<tools::vector2<T>>(std::cin), n, std::back_inserter(g));
  tools::polygon_2d<T> polygon(g.begin(), g.end());

  i64 Q;
  std::cin >> Q;
  for (i64 q = 0; q < Q; ++q) {
    tools::vector2<T> p;
    std::cin >> p;
    switch (polygon.where(p)) {
    case ::tools::polygon_2d<T>::position::inside:
      std::cout << 2 << '\n';
      break;
    case ::tools::polygon_2d<T>::position::on_edge:
      std::cout << 1 << '\n';
      break;
    case ::tools::polygon_2d<T>::position::outside:
      std::cout << 0 << '\n';
      break;
    }
  }

  return 0;
}
