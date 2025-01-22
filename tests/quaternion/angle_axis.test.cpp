// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_A

#include <iostream>
#include <array>
#include <string>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <algorithm>
#include "tools/quaternion.hpp"
#include "tools/vector3.hpp"
#include "tools/less_by.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::array<int, 6> faces;
  for (auto& f : faces) std::cin >> f;
  std::string ops;
  std::cin >> ops;

  std::unordered_map<char, tools::quaternion<double>> map;
  map['N'] = tools::quaternion<double>::angle_axis(-std::acos(-1) / 2, tools::vector3<double>(1, 0, 0));
  map['E'] = tools::quaternion<double>::angle_axis(-std::acos(-1) / 2, tools::vector3<double>(0, 0, 1));
  map['S'] = tools::quaternion<double>::angle_axis(std::acos(-1) / 2, tools::vector3<double>(1, 0, 0));
  map['W'] = tools::quaternion<double>::angle_axis(std::acos(-1) / 2, tools::vector3<double>(0, 0, 1));

  auto q = tools::quaternion<double>::identity();
  for (const auto op : ops) q = map[op] * q;

  const auto answer_with_error = q.conj() * tools::vector3<double>(0, 1, 0);

  const std::array<tools::vector3<double>, 6> six_directions = {
    tools::vector3<double>(0, 1, 0),
    tools::vector3<double>(0, 0, 1),
    tools::vector3<double>(1, 0, 0),
    tools::vector3<double>(-1, 0, 0),
    tools::vector3<double>(0, 0, -1),
    tools::vector3<double>(0, -1, 0)
  };

  std::cout << faces[std::distance(six_directions.begin(), std::min_element(six_directions.begin(), six_directions.end(), tools::less_by([&](const auto& possible_answer) {
    return (possible_answer - answer_with_error).squared_l2_norm();
  })))] << '\n';

  return 0;
}
