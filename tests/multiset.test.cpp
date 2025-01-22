// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include <iostream>
#include "tools/assert_that.hpp"
#include "tools/multiset.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  tools::multiset<int, std::greater<int>> bag({3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5});

  assert_that(bag.size() == 11);

  {
    auto it = bag.begin();
    assert_that(*it == 9);
    ++it;
    assert_that(*it == 6);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 4);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 2);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(it == bag.end());
    --it;
    assert_that(*it == 1);
    --it;
    assert_that(*it == 1);
    --it;
    assert_that(*it == 2);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 4);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 6);
    --it;
    assert_that(*it == 9);
  }

  {
    auto it = bag.cbegin();
    assert_that(*it == 9);
    ++it;
    assert_that(*it == 6);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 4);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 2);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(it == bag.cend());
    --it;
    assert_that(*it == 1);
    --it;
    assert_that(*it == 1);
    --it;
    assert_that(*it == 2);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 4);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 6);
    --it;
    assert_that(*it == 9);
  }

  {
    auto it = bag.rbegin();
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 2);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 4);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 6);
    ++it;
    assert_that(*it == 9);
    ++it;
    assert_that(it == bag.rend());
    --it;
    assert_that(*it == 9);
    --it;
    assert_that(*it == 6);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 4);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 2);
    --it;
    assert_that(*it == 1);
    --it;
    assert_that(*it == 1);
  }

  {
    auto it = bag.crbegin();
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 2);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 4);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 6);
    ++it;
    assert_that(*it == 9);
    ++it;
    assert_that(it == bag.crend());
    --it;
    assert_that(*it == 9);
    --it;
    assert_that(*it == 6);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 5);
    --it;
    assert_that(*it == 4);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 3);
    --it;
    assert_that(*it == 2);
    --it;
    assert_that(*it == 1);
    --it;
    assert_that(*it == 1);
  }

  assert_that(bag.count(1) == 2);
  assert_that(bag.count(2) == 1);
  assert_that(bag.count(3) == 2);
  assert_that(bag.count(4) == 1);
  assert_that(bag.count(5) == 3);
  assert_that(bag.count(6) == 1);
  assert_that(bag.count(7) == 0);
  assert_that(bag.count(8) == 0);
  assert_that(bag.count(9) == 1);

  assert_that(std::distance(bag.begin(), bag.lower_bound(1)) == 9);
  assert_that(std::distance(bag.begin(), bag.lower_bound(2)) == 8);
  assert_that(std::distance(bag.begin(), bag.lower_bound(3)) == 6);
  assert_that(std::distance(bag.begin(), bag.lower_bound(4)) == 5);
  assert_that(std::distance(bag.begin(), bag.lower_bound(5)) == 2);
  assert_that(std::distance(bag.begin(), bag.lower_bound(6)) == 1);
  assert_that(std::distance(bag.begin(), bag.lower_bound(7)) == 1);
  assert_that(std::distance(bag.begin(), bag.lower_bound(8)) == 1);
  assert_that(std::distance(bag.begin(), bag.lower_bound(9)) == 0);

  assert_that(std::distance(bag.begin(), bag.upper_bound(1)) == 11);
  assert_that(std::distance(bag.begin(), bag.upper_bound(2)) == 9);
  assert_that(std::distance(bag.begin(), bag.upper_bound(3)) == 8);
  assert_that(std::distance(bag.begin(), bag.upper_bound(4)) == 6);
  assert_that(std::distance(bag.begin(), bag.upper_bound(5)) == 5);
  assert_that(std::distance(bag.begin(), bag.upper_bound(6)) == 2);
  assert_that(std::distance(bag.begin(), bag.upper_bound(7)) == 1);
  assert_that(std::distance(bag.begin(), bag.upper_bound(8)) == 1);
  assert_that(std::distance(bag.begin(), bag.upper_bound(9)) == 1);

  assert_that(bag.key_comp()(2, 1));
  assert_that(!bag.key_comp()(2, 2));
  assert_that(!bag.key_comp()(2, 3));

  assert_that(!bag.empty());

  assert_that(std::distance(bag.begin(), bag.find(1)) == 9);
  assert_that(std::distance(bag.begin(), bag.find(2)) == 8);
  assert_that(std::distance(bag.begin(), bag.find(3)) == 6);
  assert_that(std::distance(bag.begin(), bag.find(4)) == 5);
  assert_that(std::distance(bag.begin(), bag.find(5)) == 2);
  assert_that(std::distance(bag.begin(), bag.find(6)) == 1);
  assert_that(bag.find(7) == bag.end());
  assert_that(bag.find(8) == bag.end());
  assert_that(std::distance(bag.begin(), bag.lower_bound(9)) == 0);

  assert_that(bag.contains(1));
  assert_that(bag.contains(2));
  assert_that(bag.contains(3));
  assert_that(bag.contains(4));
  assert_that(bag.contains(5));
  assert_that(bag.contains(6));
  assert_that(!bag.contains(7));
  assert_that(!bag.contains(8));
  assert_that(bag.contains(9));

  {
    const auto [lb, ub] = bag.equal_range(1);
    assert_that(std::distance(bag.begin(), lb) == 9);
    assert_that(std::distance(bag.begin(), ub) == 11);
  }
  {
    const auto [lb, ub] = bag.equal_range(2);
    assert_that(std::distance(bag.begin(), lb) == 8);
    assert_that(std::distance(bag.begin(), ub) == 9);
  }
  {
    const auto [lb, ub] = bag.equal_range(3);
    assert_that(std::distance(bag.begin(), lb) == 6);
    assert_that(std::distance(bag.begin(), ub) == 8);
  }
  {
    const auto [lb, ub] = bag.equal_range(4);
    assert_that(std::distance(bag.begin(), lb) == 5);
    assert_that(std::distance(bag.begin(), ub) == 6);
  }
  {
    const auto [lb, ub] = bag.equal_range(5);
    assert_that(std::distance(bag.begin(), lb) == 2);
    assert_that(std::distance(bag.begin(), ub) == 5);
  }
  {
    const auto [lb, ub] = bag.equal_range(6);
    assert_that(std::distance(bag.begin(), lb) == 1);
    assert_that(std::distance(bag.begin(), ub) == 2);
  }
  {
    const auto [lb, ub] = bag.equal_range(7);
    assert_that(std::distance(bag.begin(), lb) == 1);
    assert_that(std::distance(bag.begin(), ub) == 1);
  }
  {
    const auto [lb, ub] = bag.equal_range(8);
    assert_that(std::distance(bag.begin(), lb) == 1);
    assert_that(std::distance(bag.begin(), ub) == 1);
  }
  {
    const auto [lb, ub] = bag.equal_range(9);
    assert_that(std::distance(bag.begin(), lb) == 0);
    assert_that(std::distance(bag.begin(), ub) == 1);
  }

  assert_that(bag.value_comp()(2, 1));
  assert_that(!bag.value_comp()(2, 2));
  assert_that(!bag.value_comp()(2, 3));

  assert_that(*bag.find_by_order(0) == 9);
  assert_that(*bag.find_by_order(1) == 6);
  assert_that(*bag.find_by_order(2) == 5);
  assert_that(*bag.find_by_order(3) == 5);
  assert_that(*bag.find_by_order(4) == 5);
  assert_that(*bag.find_by_order(5) == 4);
  assert_that(*bag.find_by_order(6) == 3);
  assert_that(*bag.find_by_order(7) == 3);
  assert_that(*bag.find_by_order(8) == 2);
  assert_that(*bag.find_by_order(9) == 1);
  assert_that(*bag.find_by_order(10) == 1);
  assert_that(bag.find_by_order(11) == bag.end());

  assert_that(bag.order_of_key(1) == 9);
  assert_that(bag.order_of_key(2) == 8);
  assert_that(bag.order_of_key(3) == 6);
  assert_that(bag.order_of_key(4) == 5);
  assert_that(bag.order_of_key(5) == 2);
  assert_that(bag.order_of_key(6) == 1);
  assert_that(bag.order_of_key(7) == 1);
  assert_that(bag.order_of_key(8) == 1);
  assert_that(bag.order_of_key(9) == 0);

  bag.clear();
  assert_that(bag.empty());

  bag.insert({3, 1, 4, 1, 5});
  assert_that(bag.size() == 5);
  {
    auto it = bag.begin();
    assert_that(*it == 5);
    ++it;
    assert_that(*it == 4);
    ++it;
    assert_that(*it == 3);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 1);
  }

  bag.emplace(9);
  assert_that(bag.size() == 6);

  bag.erase(std::next(bag.begin()), std::prev(bag.end()));
  assert_that(bag.size() == 2);
  {
    auto it = bag.begin();
    assert_that(*it == 9);
    ++it;
    assert_that(*it == 1);
  }

  bag.insert(1);
  bag.insert(2);
  bag.insert(2);
  assert_that(bag.size() == 5);

  bag.erase(2);
  assert_that(bag.size() == 3);
  {
    auto it = bag.begin();
    assert_that(*it == 9);
    ++it;
    assert_that(*it == 1);
    ++it;
    assert_that(*it == 1);
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
