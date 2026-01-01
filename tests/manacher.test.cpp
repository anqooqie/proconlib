// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2934

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "atcoder/string.hpp"
#include "tools/manacher.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::string T;
  std::cin >> N >> T;

  tools::manacher manacher(T);
  const auto Z = atcoder::z_algorithm(T);

  std::cout << [&]() {
    for (int i = 1; i < N; ++i) {
      if (manacher.odd_length<true>(i).first == 0 && [&]() {
        for (int j = 0; j < N; j += manacher.odd_length(i) - 1) {
          if (Z[j] < N - j) {
            return false;
          }
        }
        return true;
      }()) {
        return (manacher.odd_length(i) + 1) / 2;
      }
    }
    for (int i = 0; i < N; ++i) {
      if (manacher.odd_length<true>(i).second == N) {
        return (N + manacher.odd_length<true>(i).first + 1) / 2;
      }
    }
    std::exit(EXIT_FAILURE);
  }() << '\n';

  return 0;
}
