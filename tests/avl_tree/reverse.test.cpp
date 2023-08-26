#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include <iostream>
#include <vector>
#include "tools/group.hpp"
#include "tools/avl_tree.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<ll> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  tools::avl_tree<tools::group::plus<ll>, true>::buffer buffer;
  tools::avl_tree<tools::group::plus<ll>, true> avl_tree(buffer, a);
  for (int q = 0; q < Q; ++q) {
    int t, l, r;
    std::cin >> t >> l >> r;
    if (t == 0) {
      avl_tree.reverse(l, r);
    } else if (t == 1) {
      std::cout << avl_tree.prod(l, r) << '\n';
    }
  }

  return 0;
}
