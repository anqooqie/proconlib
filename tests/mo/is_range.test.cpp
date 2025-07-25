// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_frequency

#include <iostream>
#include <vector>
#include "tools/mo.hpp"
#include "tools/unordered_map.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  tools::mo mo(N, Q);
  std::vector<int> queries(Q);
  for (int q = 0; q < Q; ++q) {
    int l, r;
    std::cin >> l >> r;
    mo.add_query(l, r);
    std::cin >> queries[q];
  }

  tools::unordered_map<int, int> freq;
  ::std::vector<int> answers(Q);
  mo.run([&](const int i) {
    --freq[a[i]];
  }, [&](const int i) {
    ++freq[a[i]];
  }, [&](const int q) {
    if (const auto it = freq.find(queries[q]); it != freq.end()) {
      answers[q] = it->second;
    } else {
      answers[q] = 0;
    }
  });

  for (const auto& answer : answers) {
    std::cout << answer << '\n';
  }
  return 0;
}
