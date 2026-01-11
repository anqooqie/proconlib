// competitive-verifier: STANDALONE

#include <iostream>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/next_integer_partition.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<int> a{1};
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{1});
  }
  {
    std::vector<int> a{2};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{1, 1});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{2});
  }
  {
    std::vector<int> a{3};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{2, 1});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{1, 1, 1});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{3});
  }
  {
    std::vector<int> a{4};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{3, 1});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{2, 2});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{2, 1, 1});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{1, 1, 1, 1});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{4});
  }
  {
    std::vector<int> a{5};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{4, 1});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{3, 2});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{3, 1, 1});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{2, 2, 1});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{2, 1, 1, 1});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{1, 1, 1, 1, 1});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<int>{5});
  }

  {
    std::vector<int> a{60};
    int p = 0;
    do {
      ++p;
    } while (tools::next_integer_partition(a));
    assert_that(p == 966467);
  }

  {
    std::vector<std::pair<int, int>> a{{1, 1}};
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{1, 1}});
  }
  {
    std::vector<std::pair<int, int>> a{{2, 1}};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{1, 2}});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{2, 1}});
  }
  {
    std::vector<std::pair<int, int>> a{{3, 1}};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{2, 1}, {1, 1}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{1, 3}});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{3, 1}});
  }
  {
    std::vector<std::pair<int, int>> a{{4, 1}};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{3, 1}, {1, 1}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{2, 2}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{2, 1}, {1, 2}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{1, 4}});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{4, 1}});
  }
  {
    std::vector<std::pair<int, int>> a{{5, 1}};
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{4, 1}, {1, 1}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{3, 1}, {2, 1}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{3, 1}, {1, 2}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{2, 2}, {1, 1}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{2, 1}, {1, 3}});
    assert_that(tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{1, 5}});
    assert_that(!tools::next_integer_partition(a));
    assert_that(a == std::vector<std::pair<int, int>>{{5, 1}});
  }

  {
    std::vector<std::pair<int, int>> a{{60, 1}};
    int p = 0;
    do {
      ++p;
    } while (tools::next_integer_partition(a));
    assert_that(p == 966467);
  }

  return 0;
}
