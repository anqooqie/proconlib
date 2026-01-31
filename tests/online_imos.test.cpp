// competitive-verifier: STANDALONE

#include <iostream>
#include <ranges>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/groups.hpp"
#include "tools/monoids.hpp"
#include "tools/online_imos.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    tools::online_imos<int> a;
    assert_that(a.size() == 0);
    a.apply(0, 0, 1);
    a.add(0, 0, 2);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{});
  }
  {
    tools::online_imos<int> a(1);
    assert_that(a.size() == 1);
    a.apply(0, 0, 1);
    a.apply(1, 1, 2);
    a.apply(0, 1, 4);
    assert_that(a[0] == 4);
    a.apply(1, 1, 8);
    a.add(1, 1, 16);
    assert_that(a[0] == 4);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{4});
  }
  {
    tools::online_imos<int> a(2);
    assert_that(a.size() == 2);
    a.apply(0, 0, 1);
    a.apply(1, 1, 2);
    a.apply(2, 2, 4);
    a.apply(0, 1, 8);
    a.apply(1, 2, 16);
    a.apply(0, 2, 32);
    assert_that(a[0] == 40);
    a.apply(1, 1, 64);
    a.apply(2, 2, 128);
    a.apply(1, 2, 256);
    assert_that(a[0] == 40);
    assert_that(a[1] == 304);
    a.apply(2, 2, 512);
    a.add(2, 2, 1024);
    assert_that(a[0] == 40);
    assert_that(a[1] == 304);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{40, 304});
  }
  {
    tools::online_imos<int, false> a;
    assert_that(a.size() == 0);
    a.apply(0, 0, 1);
    a.add(0, 0, 2);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{});
  }
  {
    tools::online_imos<int, false> a(1);
    assert_that(a.size() == 1);
    a.apply(1, 1, 1);
    a.apply(0, 0, 2);
    a.apply(0, 1, 4);
    assert_that(a[0] == 4);
    a.apply(0, 0, 8);
    a.add(0, 0, 16);
    assert_that(a[0] == 4);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{4});
  }
  {
    tools::online_imos<int, false> a(2);
    assert_that(a.size() == 2);
    a.apply(2, 2, 1);
    a.apply(1, 1, 2);
    a.apply(0, 0, 4);
    a.apply(1, 2, 8);
    a.apply(0, 1, 16);
    a.apply(0, 2, 32);
    assert_that(a[1] == 40);
    a.apply(1, 1, 64);
    a.apply(0, 0, 128);
    a.apply(0, 1, 256);
    assert_that(a[1] == 40);
    assert_that(a[0] == 304);
    a.apply(0, 0, 512);
    a.add(0, 0, 1024);
    assert_that(a[1] == 40);
    assert_that(a[0] == 304);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{304, 40});
  }
  {
    tools::online_imos<tools::monoids::max<int>> a;
    assert_that(a.size() == 0);
    a.apply(0, 0, 0);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{});
  }
  {
    tools::online_imos<tools::monoids::max<int>> a(1);
    assert_that(a.size() == 1);
    a.apply(0, 1, 0);
    a.apply(1, 1, 1);
    assert_that(a[0] == 0);
    a.apply(1, 1, 2);
    assert_that(a[0] == 0);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{0});
  }
  {
    tools::online_imos<tools::monoids::max<int>> a(2);
    assert_that(a.size() == 2);
    a.apply(0, 2, 0);
    a.apply(1, 2, 1);
    a.apply(2, 2, 2);
    assert_that(a[0] == 0);
    a.apply(1, 2, 3);
    a.apply(2, 2, 4);
    assert_that(a[0] == 0);
    assert_that(a[1] == 3);
    a.apply(2, 2, 5);
    assert_that(a[0] == 0);
    assert_that(a[1] == 3);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{0, 3});
  }
  {
    tools::online_imos<tools::monoids::max<int>, false> a;
    assert_that(a.size() == 0);
    a.apply(0, 0, 0);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{});
  }
  {
    tools::online_imos<tools::monoids::max<int>, false> a(1);
    assert_that(a.size() == 1);
    a.apply(0, 1, 0);
    a.apply(0, 0, 1);
    assert_that(a[0] == 0);
    a.apply(0, 0, 2);
    assert_that(a[0] == 0);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{0});
  }
  {
    tools::online_imos<tools::monoids::max<int>, false> a(2);
    assert_that(a.size() == 2);
    a.apply(0, 2, 0);
    a.apply(0, 1, 1);
    a.apply(0, 0, 2);
    assert_that(a[1] == 0);
    a.apply(0, 1, 3);
    a.apply(0, 0, 4);
    assert_that(a[1] == 0);
    assert_that(a[0] == 3);
    a.apply(0, 0, 5);
    assert_that(a[1] == 0);
    assert_that(a[0] == 3);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{3, 0});
  }
  {
    tools::online_imos<tools::groups::bit_xor<int>> a;
    assert_that(a.size() == 0);
    a.apply(0, 0, 1);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{});
  }
  {
    tools::online_imos<tools::groups::bit_xor<int>> a(1);
    assert_that(a.size() == 1);
    a.apply(0, 0, 1);
    a.apply(1, 1, 2);
    a.apply(0, 1, 4);
    assert_that(a[0] == 4);
    a.apply(1, 1, 8);
    assert_that(a[0] == 4);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{4});
  }
  {
    tools::online_imos<tools::groups::bit_xor<int>> a(2);
    assert_that(a.size() == 2);
    a.apply(0, 0, 1);
    a.apply(1, 1, 2);
    a.apply(2, 2, 4);
    a.apply(0, 1, 8);
    a.apply(1, 2, 16);
    a.apply(0, 2, 32);
    assert_that(a[0] == 40);
    a.apply(1, 1, 64);
    a.apply(2, 2, 128);
    a.apply(1, 2, 256);
    assert_that(a[0] == 40);
    assert_that(a[1] == 304);
    a.apply(2, 2, 512);
    assert_that(a[0] == 40);
    assert_that(a[1] == 304);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{40, 304});
  }
  {
    tools::online_imos<tools::groups::bit_xor<int>, false> a;
    assert_that(a.size() == 0);
    a.apply(0, 0, 1);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{});
  }
  {
    tools::online_imos<tools::groups::bit_xor<int>, false> a(1);
    assert_that(a.size() == 1);
    a.apply(1, 1, 1);
    a.apply(0, 0, 2);
    a.apply(0, 1, 4);
    assert_that(a[0] == 4);
    a.apply(0, 0, 8);
    assert_that(a[0] == 4);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{4});
  }
  {
    tools::online_imos<tools::groups::bit_xor<int>, false> a(2);
    assert_that(a.size() == 2);
    a.apply(2, 2, 1);
    a.apply(1, 1, 2);
    a.apply(0, 0, 4);
    a.apply(1, 2, 8);
    a.apply(0, 1, 16);
    a.apply(0, 2, 32);
    assert_that(a[1] == 40);
    a.apply(1, 1, 64);
    a.apply(0, 0, 128);
    a.apply(0, 1, 256);
    assert_that(a[1] == 40);
    assert_that(a[0] == 304);
    a.apply(0, 0, 512);
    assert_that(a[1] == 40);
    assert_that(a[0] == 304);
    assert_that((a | std::ranges::to<std::vector>()) == std::vector<int>{304, 40});
  }

  return 0;
}
