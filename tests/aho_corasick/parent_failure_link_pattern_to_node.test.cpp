// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/aho_corasick

#include <iostream>
#include <ranges>
#include <string>
#include "tools/aho_corasick.hpp"
#include "tools/join.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  tools::aho_corasick<> ac;
  for (int i = 0; i < N; ++i) {
    std::string S_i;
    std::cin >> S_i;
    ac.add_pattern(S_i);
  }
  ac.build();

  std::cout << ac.nodes().size() << '\n';
  for (const auto& node : ac.nodes() | std::views::drop(1)) {
    std::cout << node.parent << ' ' << node.failure_link << '\n';
  }
  std::cout << tools::join(std::views::iota(0, N) | std::views::transform([&](const int k) { return ac.pattern_to_node(k); }), ' ') << '\n';

  return 0;
}
