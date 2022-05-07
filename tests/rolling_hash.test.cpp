#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include "tools/rolling_hash.hpp"
#include "tools/chmax.hpp"

using i64 = std::int_fast64_t;
using u64 = std::uint_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N;
  std::string S;
  std::cin >> N >> S;

  tools::rolling_hash hash(S.begin(), S.end());
  i64 answer = 0;
  for (i64 n = 1; n <= N; ++n) {
    std::unordered_map<u64, i64> leftmost;
    for (i64 l = 0; l + n <= N; ++l) {
      const auto h = hash.slice(l, l + n).val();
      if (auto it = leftmost.find(h); it != leftmost.end()) {
        if (it->second <= l - n) {
          answer = n;
          break;
        }
      } else {
        leftmost.emplace(h, l);
      }
    }
  }

  std::cout << answer << '\n';
  return 0;
}
