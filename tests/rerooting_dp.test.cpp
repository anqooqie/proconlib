// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/tree_path_composite_sum

#include <utility>
#include <iostream>
#include <vector>
#include <cstddef>
#include "atcoder/modint.hpp"
#include "tools/rerooting_dp.hpp"

using mint = atcoder::modint998244353;

struct monoid {
  using T = std::pair<int, mint>;
  static T op(const T& x, const T& y) {
    return T(x.first + y.first, x.second + y.second);
  }
  static T e() {
    return T(0, mint::raw(0));
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<mint> a, b, c;
  a.reserve(N);
  b.reserve(N - 1);
  c.reserve(N - 1);
  for (int i = 0; i < N; ++i) {
    int a_i;
    std::cin >> a_i;
    a.push_back(mint::raw(a_i));
  }

  const auto f_ve = [&](const std::pair<int, mint>& sum, const std::size_t edge_id) {
    return std::make_pair(sum.first, b[edge_id] * sum.second + c[edge_id] * sum.first);
  };
  const auto f_ev = [&](const std::pair<int, mint>& sum, const std::size_t vertex_id) {
    return std::make_pair(sum.first + 1, sum.second + a[vertex_id]);
  };

  tools::rerooting_dp<std::pair<int, mint>, monoid, decltype(f_ve), decltype(f_ev)> dp(N, f_ve, f_ev);
  for (int i = 0; i < N - 1; ++i) {
    int u_i, v_i, b_i, c_i;
    std::cin >> u_i >> v_i >> b_i >> c_i;
    dp.add_edge(u_i, v_i);
    b.push_back(mint::raw(b_i));
    c.push_back(mint::raw(c_i));
  }

  const auto answers = dp.query();
  for (int i = 0; i < N; ++i) {
    std::cout << answers[i].second.val() << " \n"[i == N - 1];
  }
  return 0;
}
