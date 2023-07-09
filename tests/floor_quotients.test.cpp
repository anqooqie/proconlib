#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
#include <cstddef>
#include <algorithm>
#include <limits>
#include "tools/assert_that.hpp"
#include "tools/floor_quotients.hpp"

template <typename T>
std::vector<std::tuple<T, T, T>> naive(const T A) {
  assert(A >= 0);

  std::vector<std::tuple<T, T, T>> res;
  for (T x = 1; x <= A; ++x) {
    res.emplace_back(x, x + 1, A / x);
  }

  std::size_t vl = 0;
  for (std::size_t vr = 0, al = 0, ar = 0; al < res.size(); vl = vr, al = ar) {
    for (; ar < res.size() && std::get<2>(res[al]) == std::get<2>(res[ar]); ++vr, ++ar);
    if (vl < al) std::move(res.begin() + al, res.begin() + ar, res.begin() + vl);
    std::get<1>(res[vl]) = std::get<1>(res[vr - 1]);
    vr = vl + 1;
  }
  res.erase(res.begin() + vl, res.end());

  res.emplace_back(A + 1, std::numeric_limits<T>::max(), 0);
  return res;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (int A = 0; A <= 10000; ++A) {
    assert_that(tools::floor_quotients(A) == naive(A));
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
