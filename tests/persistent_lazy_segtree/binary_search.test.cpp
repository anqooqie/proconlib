// competitive-verifier: STANDALONE

#include <iostream>
#include <random>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/inversion_number.hpp"
#include "tools/persistent_lazy_segtree.hpp"

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

  std::uniform_int_distribution<int> a_dist(0, 1);
  std::uniform_int_distribution<int> t_dist(0, 2);
  for (int N = 0; N < 50; ++N) {
    std::vector<int> a(N);
    for (auto& a_i : a) a_i = a_dist(engine);

    tools::persistent_lazy_segtree<SM, FM, mapping>::buffer buffer;
    std::vector<tools::persistent_lazy_segtree<SM, FM, mapping>> seg;
    seg.emplace_back(buffer, [&]() {
      std::vector<S> v(N);
      for (int i = 0; i < N; ++i) {
        v[i] = a[i] ? std::make_tuple(0, 1, 0) : std::make_tuple(1, 0, 0);
      }
      return v;
    }());
    std::vector<std::tuple<int, int, int, int, int>> queries;

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
        seg.push_back(seg.back().apply(l, r, true));
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
        queries.emplace_back(seg.size() - 1, 1, l, x, ok);
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
        queries.emplace_back(seg.size() - 1, 2, r, x, ok);
      }
    }

    for (const auto& [q, t, b, x, expected] : queries) {
      if (t == 1) {
        assert_that(seg[q].max_right(b, [&](const S& e) { return std::get<2>(e) <= x; }) == expected);
      } else {
        assert_that(seg[q].min_left(b, [&](const S& e) { return std::get<2>(e) <= x; }) == expected);
      }
    }
  }

  return 0;
}
