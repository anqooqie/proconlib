#define PROBLEM "https://atcoder.jp/contests/abc322/tasks/abc322_d"

#include <iostream>
#include <array>
#include <string>
#include "tools/matrix.hpp"
#include "tools/vector3.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::array<std::array<std::string, 4>, 3> P;
  for (int i = 0; i < 3; ++i) {
    for (int r = 0; r < 4; ++r) {
      std::cin >> P[i][r];
    }
  }

  std::array<tools::matrix<int, 3, 3>, 4> matrix;
  matrix[0] = tools::matrix<int, 3, 3>::e();
  matrix[1] = {
    { 0,  1,  0},
    {-1,  0,  3},
    { 0,  0,  1},
  };
  matrix[2] = matrix[1] * matrix[1];
  matrix[3] = matrix[2] * matrix[1];

  std::cout << ([&]() {
    const int d0 = 0;
    for (int dr0 = -3; dr0 <= 3; ++dr0) {
      for (int dc0 = -3; dc0 <= 3; ++dc0) {
        for (int d1 = 0; d1 < 4; ++d1) {
          for (int dr1 = -3; dr1 <= 3; ++dr1) {
            for (int dc1 = -3; dc1 <= 3; ++dc1) {
              for (int d2 = 0; d2 < 4; ++d2) {
                for (int dr2 = -3; dr2 <= 3; ++dr2) {
                  for (int dc2 = -3; dc2 <= 3; ++dc2) {
                    if ([&]() {
                      std::array<std::array<int, 4>, 4> grid;
                      for (auto& row : grid) {
                        std::fill(row.begin(), row.end(), -1);
                      }
                      for (int r = 0; r < 4; ++r) {
                        for (int c = 0; c < 4; ++c) {
                          if (P[0][r][c] == '#') {
                            const auto v = matrix[d0] * tools::vector3<int>(r, c, 1) + tools::vector3<int>(dr0, dc0, 0);
                            if (!(0 <= v[0] && v[0] < 4 && 0 <= v[1] && v[1] < 4 && grid[v[0]][v[1]] == -1)) return false;
                            grid[v[0]][v[1]] = 0;
                          }
                        }
                      }
                      for (int r = 0; r < 4; ++r) {
                        for (int c = 0; c < 4; ++c) {
                          if (P[1][r][c] == '#') {
                            const auto v = matrix[d1] * tools::vector3<int>(r, c, 1) + tools::vector3<int>(dr1, dc1, 0);
                            if (!(0 <= v[0] && v[0] < 4 && 0 <= v[1] && v[1] < 4 && grid[v[0]][v[1]] == -1)) return false;
                            grid[v[0]][v[1]] = 1;
                          }
                        }
                      }
                      for (int r = 0; r < 4; ++r) {
                        for (int c = 0; c < 4; ++c) {
                          if (P[2][r][c] == '#') {
                            const auto v = matrix[d2] * tools::vector3<int>(r, c, 1) + tools::vector3<int>(dr2, dc2, 0);
                            if (!(0 <= v[0] && v[0] < 4 && 0 <= v[1] && v[1] < 4 && grid[v[0]][v[1]] == -1)) return false;
                            grid[v[0]][v[1]] = 2;
                          }
                        }
                      }
                      for (int r = 0; r < 4; ++r) {
                        for (int c = 0; c < 4; ++c) {
                          if (grid[r][c] < 0) return false;
                        }
                      }
                      return true;
                    }()) {
                      return true;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return false;
  }() ? "Yes" : "No") << '\n';

  return 0;
}
