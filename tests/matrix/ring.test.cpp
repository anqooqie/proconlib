// competitive-verifier: STANDALONE
// Source: https://atcoder.jp/contests/abc009/tasks/abc009_4

#include <cstdint>
#include <iostream>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/matrix.hpp"
#include "tools/monoids.hpp"
#include "tools/pow.hpp"
#include "tools/rings.hpp"
#include "tools/vector.hpp"

using u32 = std::uint32_t;

struct monoid {
  static inline int N;
  using T = tools::matrix<tools::rings::xor_and<u32>>;
  static T op(const T& a, const T& b) {
    return a * b;
  }
  static T e() {
    return T::e(N);
  }
};

u32 solve(const int K, const int M, const std::vector<u32>& A, const std::vector<u32>& C) {
  monoid::N = K;
  tools::matrix<tools::rings::xor_and<u32>> matrix(K, K);
  for (int i = 0; i + 1 < K; ++i) {
    matrix[i][i + 1] = tools::monoids::bit_and<u32>::e();
  }
  for (int j = 0; j < K; ++j) {
    matrix[K - 1][j] = C[K - 1 - j];
  }
  tools::vector<u32> vector(K);
  for (int i = 0; i < K; ++i) {
    vector[i] = A[i];
  }
  return (tools::pow<monoid>(matrix, M - 1) * vector)[0];
}

void sample_01() {
  const int K = 3;
  const int M = 5;
  const std::vector<u32> A = {10, 20, 30};
  const std::vector<u32> C = {7, 19, 13};
  assert_that(solve(K, M, A, C) == 16);
}

void sample_02() {
  const int K = 5;
  const int M = 100;
  const std::vector<u32> A = {2345678901, 1001001001, 3333333333, 3141592653, 1234567890};
  const std::vector<u32> C = {2147483648, 2147483647, 4294967295, 4294967294, 3434343434};
  assert_that(solve(K, M, A, C) == 1067078691);
}

void sample_03() {
  const int K = 30;
  const int M = 999999999;
  const std::vector<u32> A = {11627, 5078, 8394, 6412, 10346, 3086, 3933, 668, 9879, 11739, 4501, 6108, 12336, 8771, 2768, 2438, 2153, 7047, 5476, 313, 1264, 369, 12070, 10743, 10663, 747, 370, 4671, 5235, 3439};
  const std::vector<u32> C = {114, 3613, 3271, 5032, 11241, 6961, 3628, 150, 12191, 2396, 7638, 3046, 11594, 8162, 11136, 786, 9878, 2356, 11660, 1070, 3649, 10882, 9746, 1415, 3307, 7077, 9319, 9981, 3437, 544};
  assert_that(solve(K, M, A, C) == 2148);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  sample_01();
  sample_02();
  sample_03();

  return 0;
}
