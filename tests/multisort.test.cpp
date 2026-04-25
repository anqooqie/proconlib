// competitive-verifier: STANDALONE

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/less_by.hpp"
#include "tools/multisort.hpp"
#include "tools/permutation.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<int> a = {5, 2, 4, 3, 1};
    const auto perm = tools::multisort(tools::less_by([&](const int i) { return a[i]; }), a);
    assert_that(a == std::vector<int>{1, 2, 3, 4, 5});
    assert_that(perm == tools::permutation<int>(std::vector<int>{4, 1, 3, 2, 0}));
  }
  {
    std::vector<int> a = {5, 2, 4, 3, 1};
    std::string b = "adbce";
    std::array<double, 5> c = {-5.0, -2.0, -4.0, -3.0, -1.0};
    const auto perm = tools::multisort(tools::less_by([&](const int i) { return a[i]; }), a, b, c);
    assert_that(a == std::vector<int>{1, 2, 3, 4, 5});
    assert_that(b == "edcba");
    assert_that(c == std::array<double, 5>{-1.0, -2.0, -3.0, -4.0, -5.0});
    assert_that(perm == tools::permutation<int>(std::vector<int>{4, 1, 3, 2, 0}));
  }
  {
    std::vector<int> a;
    std::string b;
    const auto perm = tools::multisort(tools::less_by([&](const int i) { return a[i]; }), a, b);
    assert_that(a.empty());
    assert_that(b.empty());
    assert_that(perm.size() == 0);
  }

  return 0;
}
