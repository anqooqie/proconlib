#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2136"

#include <cstdint>
#include <iostream>
#include <vector>
#include "tools/vector2.hpp"
#include "tools/ccw.hpp"
#include "tools/chromatic_number.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  for (i64 N; std::cin >> N, N > 0;) {
    std::vector<std::vector<tools::vector2<i64>>> lines(N);
    for (i64 i = 0; i < N; ++i) {
      i64 S;
      std::cin >> S;
      for (i64 j = 0; j < S; ++j) {
        i64 X, Y;
        std::cin >> X >> Y;
        lines[i].emplace_back(X, Y);
      }
    }
  
    tools::chromatic_number graph(N);
    for (i64 i = 0; i < N; ++i) {
      for (i64 j = i + 1; j < N; ++j) {
        if ([&]() {
          for (i64 k = 1; k < i64(lines[i].size()); ++k) {
            for (i64 l = 1; l < i64(lines[j].size()); ++l) {
              if (tools::ccw(lines[i][k - 1], lines[i][k], lines[j][l - 1]) * tools::ccw(lines[i][k - 1], lines[i][k], lines[j][l]) <= 0
                  && tools::ccw(lines[j][l - 1], lines[j][l], lines[i][k - 1]) * tools::ccw(lines[j][l - 1], lines[j][l], lines[i][k]) <= 0) {
                return true;
              }
            }
          }
          return false;
        }()) {
          graph.add_edge(i, j);
        }
      }
    }
  
    std::cout << graph.query() << '\n';
  }
  return 0;
}
