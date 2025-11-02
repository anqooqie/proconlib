// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/0439

#include <iostream>
#include <vector>
#include <utility>
#include "tools/auxiliary_tree.hpp"
#include "tools/rerooting_dp.hpp"
#include "tools/monoids.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  std::vector<int> c(N);
  for (auto&& c_i : c) {
    std::cin >> c_i;
    --c_i;
  }
  tools::auxiliary_tree tree(N);
  for (int i = 0; i < N - 1; ++i) {
    int s, t;
    std::cin >> s >> t;
    --s, --t;
    tree.add_edge(s, t);
  }
  tree.build(0);

  std::vector<std::vector<int>> huts(N);
  for (int v = 0; v < N; ++v) {
    huts[c[v]].push_back(v);
  }

  std::vector<int> answers(N);
  std::vector<int> tree2aux(N);
  for (int color = 0; color < N; ++color) {
    if (huts[color].empty()) continue;

    const auto aux = tree.query(huts[color].begin(), huts[color].end());
    std::vector<int> aux2tree(aux.size());
    {
      int aux_v = 0;
      for (const auto tree_v : aux.vertices()) {
        tree2aux[tree_v] = aux_v;
        aux2tree[aux_v] = tree_v;
        ++aux_v;
      }
    }

    std::vector<int> w;
    const auto f_ve = [&](const auto& v, const auto e) {
      return (v.second ? 0 : v.first) + w[e];
    };
    const auto f_ev = [&](const auto e, const auto v) {
      return std::make_pair(e, c[aux2tree[v]] == color);
    };
    tools::rerooting_dp<std::pair<int, bool>, tools::monoids::min<int>, decltype(f_ve), decltype(f_ev)> dp(aux.size(), f_ve, f_ev);
    for (const auto tree_v : aux.vertices()) {
      if (tree_v == aux.root()) continue;
      dp.add_edge(tree2aux[tree_v], tree2aux[aux.parent(tree_v)]);
      const auto lca = tree.lca(tree_v, aux.parent(tree_v));
      w.push_back(tree.depth(tree_v) + tree.depth(aux.parent(tree_v)) - 2 * tree.depth(lca));
    }
    const auto partial_answers = dp.query();

    for (int aux_v = 0; std::cmp_less(aux_v, aux.size()); ++aux_v) {
      if (partial_answers[aux_v].second) {
        answers[aux2tree[aux_v]] = partial_answers[aux_v].first;
      }
    }
  }

  for (const auto answer : answers) {
    std::cout << answer << '\n';
  }
  return 0;
}
