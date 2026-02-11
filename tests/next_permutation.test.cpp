// competitive-verifier: STANDALONE

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/next_permutation.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // enumerate all P(n, r) for small n
  for (int n = 0; n <= 7; ++n) {
    for (int r = 0; r <= n; ++r) {
      std::vector<int> v(n);
      for (int i = 0; i < n; ++i) v[i] = i;

      std::set<std::vector<int>> seen;
      std::vector<int> prev;
      int count = 0;
      do {
        std::vector<int> chosen(v.begin(), v.begin() + r);

        // lexicographic order
        if (!prev.empty()) {
          assert_that(prev < chosen);
        }
        prev = chosen;

        // no duplicates
        assert_that(seen.insert(chosen).second);
        ++count;
      } while (tools::next_permutation(v.begin(), v.begin() + r, v.end()));

      // correct number of permutations
      // P(n, r) = n! / (n - r)!
      int expected = 1;
      for (int i = 0; i < r; ++i) {
        expected *= (n - i);
      }
      assert_that(count == expected);
    }
  }

  return 0;
}
