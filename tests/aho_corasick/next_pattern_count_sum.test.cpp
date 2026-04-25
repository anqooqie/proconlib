// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2873

#include <iostream>
#include <string>
#include "tools/aho_corasick.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string S;
  int N;
  std::cin >> S >> N;
  tools::aho_corasick<> ac;
  for (int i = 0; i < N; ++i) {
    std::string p_i;
    std::cin >> p_i;
    ac.add_pattern(p_i);
  }
  ac.build();

  int answer = 0;
  int v = 0;
  for (const auto S_i : S) {
    v = ac.get_node(v).next[ac.encode(S_i)];
    if (ac.get_node(v).pattern_count_sum > 0) {
      ++answer;
      v = 0;
    }
  }

  std::cout << answer << '\n';
  return 0;
}
