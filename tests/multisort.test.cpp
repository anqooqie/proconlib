// competitive-verifier: STANDALONE

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/less_by.hpp"
#include "tools/multisort.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<int> a = {5, 2, 4, 3, 1};
    std::string b = "adbce";
    tools::multisort(a, b, tools::less_by([&](const int i) { return a[i]; }));
    assert_that(a == std::vector<int>{1, 2, 3, 4, 5});
    assert_that(b == "edcba");
  }
  {
    std::vector<int> a = {5, 2, 4, 3, 1};
    std::string b = "adbce";
    std::array<double, 5> c = {-5.0, -2.0, -4.0, -3.0, -1.0};
    tools::multisort(a, b, c, tools::less_by([&](const int i) { return a[i]; }));
    assert_that(a == std::vector<int>{1, 2, 3, 4, 5});
    assert_that(b == "edcba");
    assert_that(c == std::array<double, 5>{-1.0, -2.0, -3.0, -4.0, -5.0});
  }
  {
    std::vector<int> a = {5, 2, 4, 3, 1};
    std::string b = "adbce";
    std::array<double, 5> c = {-5.0, -2.0, -4.0, -3.0, -1.0};
    std::vector<int> d = {5, 2, 4, 3, 1};
    tools::multisort(a, b, c, d, tools::less_by([&](const int i) { return a[i]; }));
    assert_that(a == std::vector<int>{1, 2, 3, 4, 5});
    assert_that(b == "edcba");
    assert_that(c == std::array<double, 5>{-1.0, -2.0, -3.0, -4.0, -5.0});
    assert_that(d == std::vector<int>{1, 2, 3, 4, 5});
  }
  {
    std::vector<int> a = {5, 2, 4, 3, 1};
    std::string b = "adbce";
    std::array<double, 5> c = {-5.0, -2.0, -4.0, -3.0, -1.0};
    std::vector<int> d = {5, 2, 4, 3, 1};
    std::string e = "adbce";
    tools::multisort(a, b, c, d, e, tools::less_by([&](const int i) { return a[i]; }));
    assert_that(a == std::vector<int>{1, 2, 3, 4, 5});
    assert_that(b == "edcba");
    assert_that(c == std::array<double, 5>{-1.0, -2.0, -3.0, -4.0, -5.0});
    assert_that(d == std::vector<int>{1, 2, 3, 4, 5});
    assert_that(e == "edcba");
  }
  {
    std::vector<int> a;
    std::string b;
    tools::multisort(a, b, tools::less_by([&](const int i) { return a[i]; }));
    assert_that(a.empty());
    assert_that(b.empty());
  }

  return 0;
}
