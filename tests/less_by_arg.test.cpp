#define PROBLEM "https://yukicoder.me/problems/no/1144"

#include <cstdint>
#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/vector2.hpp"
#include "tools/less_by_arg.hpp"

using mint = atcoder::modint1000000007;
using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 n;
  std::cin >> n;
  std::vector<tools::vector2<i64>> orig_p(n);
  for (auto& orig_p_i : orig_p) std::cin >> orig_p_i;

  mint answer(0);
  for (auto it = orig_p.begin(); it != orig_p.end(); ++it) {
    std::vector<tools::vector2<i64>> p(std::next(it), orig_p.end());
    for (auto& p_i : p) p_i -= *it;
    std::sort(p.begin(), p.end(), tools::less_by_arg());

    auto whole = std::accumulate(p.begin(), p.end(), tools::vector2<i64>(0, 0));
    i64 r = 0;
    tools::vector2<i64> sum(0, 0);
    for (i64 l = 0; l < i64(p.size()); ++l) {
      for (; r < i64(p.size()) && tools::less_by_arg(p[l])(p[r], -p[l]); ++r) {
        sum += p[r];
      }

      answer += mint(p[l].outer_product(sum));
      answer -= mint(p[l].outer_product(whole - sum));

      if (l == r) {
        ++r;
      } else {
        sum -= p[l];
      }
      whole -= p[l];
    }
  }

  std::cout << answer.val() << '\n';
}
