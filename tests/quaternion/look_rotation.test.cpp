#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B"

#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include "tools/quaternion.hpp"
#include "tools/vector3.hpp"
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

  std::array<int, 6> faces;
  for (auto& f : faces) std::cin >> f;
  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int top_face, front_face;
    std::cin >> top_face >> front_face;
    const auto top_direction = six_directions[std::distance(faces.begin(), std::find(faces.begin(), faces.end(), top_face))];
    const auto front_direction = six_directions[std::distance(faces.begin(), std::find(faces.begin(), faces.end(), front_face))];
    const auto q = ::tools::quaternion<double>::look_rotation(front_direction, top_direction);
    const auto answer_with_error = q * tools::vector3<double>(1, 0, 0);

    std::cout << faces[std::distance(six_directions.begin(), std::min_element(six_directions.begin(), six_directions.end(), tools::less_by([&](const auto& possible_answer) {
      return (possible_answer - answer_with_error).squared_l2_norm();
    })))] << '\n';
  }

  return 0;
}
