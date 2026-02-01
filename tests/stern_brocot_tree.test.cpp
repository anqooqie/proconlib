// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/stern_brocot_tree

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "tools/stern_brocot_tree.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::string type;
    std::cin >> type;
    if (type == "ENCODE_PATH") {
      int a, b;
      std::cin >> a >> b;
      const auto path = tools::stern_brocot_tree<int>::encode_path(a, b);
      std::cout << path.size();
      for (const auto& [c, n] : path) {
        std::cout << ' ' << c << ' ' << n;
      }
      std::cout << '\n';
    } else if (type == "DECODE_PATH") {
      int k;
      std::cin >> k;
      std::vector<std::pair<char, int>> path(k);
      for (auto& [c, n] : path) {
        std::cin >> c >> n;
      }
      const auto [a, b] = tools::stern_brocot_tree<int>::decode_path(path);
      std::cout << a << ' ' << b << '\n';
    } else if (type == "LCA") {
      int a, b, c, d;
      std::cin >> a >> b >> c >> d;
      const auto [f, g] = tools::stern_brocot_tree<int>::lca(a, b, c, d);
      std::cout << f << ' ' << g << '\n';
    } else if (type == "ANCESTOR") {
      int k, a, b;
      std::cin >> k >> a >> b;
      if (const auto res = tools::stern_brocot_tree<int>::ancestor(k, a, b); res) {
        std::cout << res->first << ' ' << res->second << '\n';
      } else {
        std::cout << -1 << '\n';
      }
    } else if (type == "RANGE") {
      int a, b;
      std::cin >> a >> b;
      const auto [f, g, h, k] = tools::stern_brocot_tree<int>::range(a, b);
      std::cout << f << ' ' << g << ' ' << h << ' ' << k << '\n';
    }
  }

  return 0;
}
