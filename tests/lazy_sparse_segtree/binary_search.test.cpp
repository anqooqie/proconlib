// competitive-verifier: STANDALONE

#include <iostream>
#include <random>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/inversion_number.hpp"
#include "tools/lazy_sparse_segtree.hpp"

struct SM {
  using T = std::tuple<int, int, int>;
  static T op(const T& x, const T& y) {
    return {std::get<0>(x) + std::get<0>(y), std::get<1>(x) + std::get<1>(y), std::get<2>(x) + std::get<2>(y) + std::get<1>(x) * std::get<0>(y)};
  }
  static T e() {
    return {0, 0, 0};
  }
};
using S = typename SM::T;

struct FM {
  using T = bool;
  static T op(const T f, const T g) {
    return f ^ g;
  }
  static T e() {
    return false;
  }
};
using F = typename FM::T;

S mapping(const F f, const S& e) {
  return f ? std::make_tuple(std::get<1>(e), std::get<0>(e), std::get<0>(e) * std::get<1>(e) - std::get<2>(e)) : e;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  std::uniform_int_distribution<int> t_dist(0, 2);
  for (int N = 0; N < 50; ++N) {
    std::vector<int> a(N, 0);
    tools::lazy_sparse_segtree<SM, FM, mapping> seg(0, N, {1, 0, 0});

    std::vector<std::pair<int, int>> lr;
    for (int l = 0; l <= N; ++l) {
      for (int r = l; r <= N; ++r) {
        lr.emplace_back(l, r);
      }
    }

    std::uniform_int_distribution<int> p_dist(0, N);
    std::uniform_int_distribution<int> lr_dist(0, (N + 1) * (N + 2) / 2 - 1);
    for (int q = 0; q < (N + 1) * (N + 2) * 3; ++q) {
      const auto t = t_dist(engine);
      if (t == 0) {
        const auto [l, r] = lr[lr_dist(engine)];
        for (int i = l; i < r; ++i) a[i] ^= 1;
        seg.apply(l, r, true);
      } else if (t == 1) {
        const auto l = p_dist(engine);
        const auto x = std::uniform_int_distribution<int>(0, (N - l) * (N - l - 1) / 2)(engine);
        auto ok = l;
        auto ng = N + 1;
        while (ng - ok > 1) {
          const auto mid = (ok + ng) / 2;
          if (tools::inversion_number(std::ranges::subrange(a.begin() + l, a.begin() + mid)) <= x) {
            ok = mid;
          } else {
            ng = mid;
          }
        }
        assert_that(seg.max_right(l, [&](const S& e) { return std::get<2>(e) <= x; }) == ok);
      } else {
        const auto r = p_dist(engine);
        const auto x = std::uniform_int_distribution<int>(0, r * (r - 1) / 2)(engine);
        auto ok = r;
        auto ng = -1;
        while (ok - ng > 1) {
          const auto mid = (ok + ng) / 2;
          if (tools::inversion_number(std::ranges::subrange(a.begin() + mid, a.begin() + r)) <= x) {
            ok = mid;
          } else {
            ng = mid;
          }
        }
        assert_that(seg.min_left(r, [&](const S& e) { return std::get<2>(e) <= x; }) == ok);
      }
    }
  }

  return 0;
}
