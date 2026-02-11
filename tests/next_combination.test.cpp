// competitive-verifier: STANDALONE

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/next_combination.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // enumerate all C(n, r) for small n
  for (int n = 0; n <= 8; ++n) {
    for (int r = 0; r <= n; ++r) {
      std::vector<int> v(n);
      for (int i = 0; i < n; ++i) v[i] = i;

      std::set<std::vector<int>> seen;
      std::vector<int> prev;
      int count = 0;
      do {
        std::vector<int> chosen(v.begin(), v.begin() + r);

        // chosen part is sorted
        assert_that(std::is_sorted(chosen.begin(), chosen.end()));

        // unchosen part is sorted
        assert_that(std::is_sorted(v.begin() + r, v.end()));

        // lexicographic order
        if (!prev.empty()) {
          assert_that(prev < chosen);
        }
        prev = chosen;

        // no duplicates
        assert_that(seen.insert(chosen).second);
        ++count;
      } while (tools::next_combination(v.begin(), v.begin() + r, v.end()));

      // correct number of combinations
      // C(n, r) = n! / (r! * (n - r)!)
      int expected = 1;
      for (int i = 0; i < r; ++i) {
        expected = expected * (n - i) / (i + 1);
      }
      assert_that(count == expected);
    }
  }

  return 0;
}
