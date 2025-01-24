// competitive-verifier: STANDALONE

#include <iostream>
#include <cmath>
#include "tools/assert_that.hpp"
#include "tools/quaternion.hpp"
#include "tools/vector3.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const auto pi = std::acos(-1);

  {
    const auto q0 = tools::quaternion<double>::identity();
    const auto q1 = tools::quaternion<double>::angle_axis(0.8 * pi, tools::vector3<double>(1, 2, 3));
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.0) - q0).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.25) - tools::quaternion<double>::angle_axis(0.2 * pi, tools::vector3<double>(1, 2, 3))).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.5) - tools::quaternion<double>::angle_axis(0.4 * pi, tools::vector3<double>(1, 2, 3))).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.75) - tools::quaternion<double>::angle_axis(0.6 * pi, tools::vector3<double>(1, 2, 3))).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 1.0) - q1).norm() <= 1e-5);
  }

  {
    const auto q0 = tools::quaternion<double>::identity();
    const auto q1 = tools::quaternion<double>::angle_axis(1.2 * pi, tools::vector3<double>(1, 2, 3));
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.0) - q0).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.25) - tools::quaternion<double>::angle_axis(0.3 * pi, tools::vector3<double>(1, 2, 3))).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.5) - tools::quaternion<double>::angle_axis(0.6 * pi, tools::vector3<double>(1, 2, 3))).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 0.75) - tools::quaternion<double>::angle_axis(0.9 * pi, tools::vector3<double>(1, 2, 3))).norm() <= 1e-5);
    assert_that((tools::quaternion<double>::slerp(q0, q1, 1.0) - q1).norm() <= 1e-5);
  }

  return 0;
}
