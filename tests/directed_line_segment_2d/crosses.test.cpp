// competitive-verifier: STANDALONE

#include <iostream>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/bigint.hpp"
#include "tools/directed_line_segment_2d.hpp"
#include "tools/rational.hpp"
#include "tools/vector2.hpp"

using ll = long long;
using R = tools::rational<tools::bigint>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::vector<tools::vector2<ll>> points;
  for (int x = 0; x < 4; ++x) {
    for (int y = 0; y < 4; ++y) {
      points.emplace_back(x, y);
    }
  }

  for (int i = 0; i + 1 < 16; ++i) {
    for (int j = i + 1; j < 16; ++j) {
      for (int k = 0; k + 1 < 16; ++k) {
        for (int l = k + 1; l < 16; ++l) {
          const auto& p1_Z = points[i];
          const auto& p2_Z = points[j];
          const auto& p3_Z = points[k];
          const auto& p4_Z = points[l];
          const tools::directed_line_segment_2d<ll> s1_Z(p1_Z, p2_Z);
          const tools::directed_line_segment_2d<ll> s2_Z(p3_Z, p4_Z);

          const tools::vector2<R> p1_R(R(p1_Z.x), R(p1_Z.y));
          const tools::vector2<R> p2_R(R(p2_Z.x), R(p2_Z.y));
          const tools::vector2<R> p3_R(R(p3_Z.x), R(p3_Z.y));
          const tools::vector2<R> p4_R(R(p4_Z.x), R(p4_Z.y));
          const tools::directed_line_segment_2d<R> s1_R(p1_R, p2_R);
          const tools::directed_line_segment_2d<R> s2_R(p3_R, p4_R);

          const auto expected = static_cast<bool>(s1_R.cross_point(s2_R));
          const auto actual = s1_Z.crosses(s2_Z);

          assert_that(expected == actual);
        }
      }      
    }
  }

  return 0;
}
