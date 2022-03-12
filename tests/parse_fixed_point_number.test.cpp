#define PROBLEM "https://atcoder.jp/contests/agc047/tasks/agc047_a"

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "tools/parse_fixed_point_number.hpp"
#include "tools/cumsum2d.hpp"
#include "tools/group.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::cin >> N;
  std::vector<std::string> A(N);
  for (auto& A_i : A) std::cin >> A_i;

  std::array<std::array<i64, 19>, 19> matrix({{}});
  for (const auto& A_i : A) {
    i64 A_i_i64 = tools::parse_fixed_point_number(A_i, 9);
    i64 y;
    for (y = 0; y < 18 && A_i_i64 % 2 == 0; ++y, A_i_i64 /= 2);
    i64 x;
    for (x = 0; x < 18 && A_i_i64 % 5 == 0; ++x, A_i_i64 /= 5);
 
    ++matrix[y][x];
  }

  const auto cumsum = tools::cumsum2d<tools::group::plus<i64>>(matrix);
  i64 answer = 0;
  for (i64 y = 0; y <= 18; ++y) {
    for (i64 x = 0; x <= 18; ++x) {
      answer += matrix[y][x] * cumsum.query(18 - y, 19, 18 - x, 19);
    }
  }
  answer -= cumsum.query(9, 19, 9, 19);
  answer /= 2;
  std::cout << answer << std::endl;

  return 0;
}
