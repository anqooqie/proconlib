#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>
#include <algorithm>
#include "tools/assert_that.hpp"
#include "tools/permutation.hpp"
#include "tools/ssize.hpp"
#include "tools/pow.hpp"

using i64 = std::int_fast64_t;

struct group {
  using T = tools::permutation<i64>;
  inline static i64 N;
  static T op(const T& lhs, const T& rhs) {
    return lhs * rhs;
  }
  static T e() {
    return T(N);
  }
  static T inv(const T& p) {
    return p.inv();
  }
};

// Source: https://atcoder.jp/contests/abc013/tasks/abc013_4
void abc013d(const i64& N, const i64& D, const std::vector<i64>& A, const std::vector<i64>& expected) {
  group::N = N;
  tools::permutation<i64> unit(N);
  for (i64 i = 0; i < tools::ssize(A); ++i) {
    unit.swap(A[i] - 1, A[i]);
  }

  const auto p = tools::pow<group>(unit, D).inv();
  std::vector<i64> actual(p.begin(), p.end());
  for (i64& actual_i : actual) ++actual_i;

  assert_that(actual == expected);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  abc013d(5, 1, std::vector<i64>({1, 4, 3, 4, 2, 3, 1}), std::vector<i64>({4, 2, 5, 3, 1}));
  abc013d(5, 2, std::vector<i64>({1, 4, 3, 4, 2, 3, 1}), std::vector<i64>({3, 2, 1, 5, 4}));
  abc013d(10, 300, std::vector<i64>({9, 1, 2, 5, 8, 1, 9, 3, 5, 6, 4, 5, 4, 6, 8, 3, 2, 7, 9, 6}), std::vector<i64>({3, 7, 2, 4, 5, 9, 6, 1, 8, 10}));

  for (i64 n = 0; n <= 5; ++n) {
    std::vector<i64> expected(n);
    std::iota(expected.begin(), expected.end(), 0);
    i64 id = 0;
    do {
      const auto actual = tools::permutation<i64>::from(n, id);
      assert_that(actual == tools::permutation<i64>(expected.begin(), expected.end()));
      assert_that(actual.id() == id);
      ++id;
    } while (std::next_permutation(expected.begin(), expected.end()));
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
