#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#ifdef __clang__
  #define IGNORE
#endif

#include "tools/qcfium.hpp"
#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include "tools/mo.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  ::tools::mo mo(N, Q);
  ::std::vector<int> queries(Q);
  for (int i = 0; i < Q; ++i) {
    int l, r;
    std::cin >> l >> r;
    mo.add_query(l, r);
    std::cin >> queries[i];
  }

  ::__gnu_pbds::gp_hash_table<int, int> freq;
  const auto add = [&](const int i) { ++freq[a[i]]; };
  const auto remove = [&](const int i) { --freq[a[i]]; };
  ::std::vector<int> answers(Q);
  mo.run(add, add, remove, remove, [&](const int i) {
    if (const auto it = freq.find(queries[i]); it != freq.end()) {
      answers[i] = it->second;
    } else {
      answers[i] = 0;
    }
  });

  for (const auto& answer : answers) {
    std::cout << answer << '\n';
  }
  return 0;
}
