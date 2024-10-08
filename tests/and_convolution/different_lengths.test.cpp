#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <random>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/assert_that.hpp"
#include "tools/and_convolution.hpp"

using mint = atcoder::modint998244353;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::uniform_int_distribution<int> dist(0, 998244352);

  for (int N = 0; N <= 10; ++N) {
    for (int M = 0; M <= 10; ++M) {
      for (int K = 0; K <= 10; ++K) {
        std::vector<mint> a(N);
        for (auto&& a_i : a) a_i = mint::raw(dist(engine));
        std::vector<mint> b(M);
        for (auto&& b_i : b) b_i = mint::raw(dist(engine));
        std::vector<mint> c(K, mint::raw(0));
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < M; ++j) {
            if ((i & j) < K) {
              c[i & j] += a[i] * b[j];
            }
          }
        }

        std::vector<mint> actual_c(K);
        tools::and_convolution(a.begin(), a.end(), b.begin(), b.end(), actual_c.begin(), actual_c.end());

        assert_that(actual_c == c);
      }
    }
  }

  std::cout << "Hello World" << '\n';
  return 0;
}