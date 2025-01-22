// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_C

#include <iostream>
#include <array>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include "tools/vector3.hpp"
#include "tools/quaternion.hpp"
#include "tools/less_by.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const std::array<tools::vector3<double>, 6> six_directions = {
    tools::vector3<double>(0, 1, 0),
    tools::vector3<double>(0, 0, 1),
    tools::vector3<double>(1, 0, 0),
    tools::vector3<double>(-1, 0, 0),
    tools::vector3<double>(0, 0, -1),
    tools::vector3<double>(0, -1, 0)
  };

  std::array<int, 6> faces1, faces2;
  for (auto& f : faces1) std::cin >> f;
  for (auto& f : faces2) std::cin >> f;

  std::cout << ([&]() {
    for (const auto& q : tools::quaternion<double>::dice_rotations()) {
      if ([&]() {
        for (std::size_t i = 0; i < six_directions.size(); ++i) {
          const auto& v1 = six_directions[i];
          const auto v2_with_error = q * v1;
          const auto j = std::distance(six_directions.begin(), std::min_element(six_directions.begin(), six_directions.end(), tools::less_by([&](const auto& v2) { return (v2_with_error - v2).squared_l2_norm(); })));
          if (faces1[i] != faces2[j]) return false;
        }
        return true;
      }()) {
        return true;
      }
    }
    return false;
  }() ? "Yes" : "No") << '\n';

  return 0;
}
