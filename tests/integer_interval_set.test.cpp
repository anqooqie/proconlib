// competitive-verifier: STANDALONE

#include <iostream>
#include <iterator>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/integer_interval_set.hpp"

using ll = long long;

// Helper: collect all intervals as vector of pairs
std::vector<std::pair<ll, ll>> to_vec(const tools::integer_interval_set<ll>& s) {
  return std::vector<std::pair<ll, ll>>(s.begin(), s.end());
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // empty set
  {
    tools::integer_interval_set<ll> s;
    assert_that(s.empty());
    assert_that(s.size() == 0);
    assert_that(s.begin() == s.end());
    assert_that(!s.contains(0));
    assert_that(s.find(0) == s.end());
    assert_that(s.lower_bound(0) == s.end());
    assert_that(s.upper_bound(0) == s.end());
  }

  // insert single element
  {
    tools::integer_interval_set<ll> s;
    s.insert(5);
    assert_that(!s.empty());
    assert_that(s.size() == 1);
    assert_that(s.contains(5));
    assert_that(!s.contains(4));
    assert_that(!s.contains(6));
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{5, 5}}));
  }

  // insert range
  {
    tools::integer_interval_set<ll> s;
    s.insert(3, 7);
    assert_that(s.size() == 1);
    for (ll x = 3; x <= 7; ++x) assert_that(s.contains(x));
    assert_that(!s.contains(2));
    assert_that(!s.contains(8));
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{3, 7}}));
  }

  // insert merges adjacent intervals
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 3);
    s.insert(4, 6);
    // [1,3] and [4,6] are adjacent -> merged to [1,6]
    assert_that(s.size() == 1);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 6}}));
  }

  // insert merges overlapping intervals
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 5);
    s.insert(3, 8);
    assert_that(s.size() == 1);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 8}}));
  }

  // insert merges multiple existing intervals
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 3);
    s.insert(7, 9);
    s.insert(13, 15);
    assert_that(s.size() == 3);
    // bridge all three
    s.insert(4, 12);
    assert_that(s.size() == 1);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 15}}));
  }

  // insert does not merge disjoint (gap >= 2)
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 3);
    s.insert(5, 7);
    assert_that(s.size() == 2);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 3}, {5, 7}}));
    assert_that(!s.contains(4));
  }

  // insert subset (no change)
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 10);
    s.insert(3, 7);
    assert_that(s.size() == 1);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 10}}));
  }

  // erase single element from middle of interval
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 10);
    s.erase(5);
    assert_that(s.size() == 2);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 4}, {6, 10}}));
    assert_that(!s.contains(5));
    assert_that(s.contains(4));
    assert_that(s.contains(6));
  }

  // erase single element at left boundary
  {
    tools::integer_interval_set<ll> s;
    s.insert(3, 7);
    s.erase(3);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{4, 7}}));
  }

  // erase single element at right boundary
  {
    tools::integer_interval_set<ll> s;
    s.insert(3, 7);
    s.erase(7);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{3, 6}}));
  }

  // erase single-element interval entirely
  {
    tools::integer_interval_set<ll> s;
    s.insert(5);
    s.erase(5);
    assert_that(s.empty());
  }

  // erase range from middle
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 20);
    s.erase(5, 15);
    assert_that(s.size() == 2);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 4}, {16, 20}}));
  }

  // erase range covering entire interval
  {
    tools::integer_interval_set<ll> s;
    s.insert(3, 7);
    s.erase(3, 7);
    assert_that(s.empty());
  }

  // erase range covering multiple intervals
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 3);
    s.insert(5, 7);
    s.insert(9, 11);
    s.erase(2, 10);
    assert_that(s.size() == 2);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 1}, {11, 11}}));
  }

  // erase non-existent element (no-op)
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 3);
    s.erase(5);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 3}}));
  }

  // erase range in gap (no-op)
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 3);
    s.insert(7, 9);
    s.erase(4, 6);
    assert_that(s.size() == 2);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 3}, {7, 9}}));
  }

  // erase superset of all intervals
  {
    tools::integer_interval_set<ll> s;
    s.insert(3, 5);
    s.insert(8, 10);
    s.erase(1, 20);
    assert_that(s.empty());
  }

  // find
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 5);
    s.insert(10, 15);

    auto it = s.find(3);
    assert_that(it != s.end());
    assert_that(it->first == 1);
    assert_that(it->second == 5);

    it = s.find(12);
    assert_that(it != s.end());
    assert_that(it->first == 10);
    assert_that(it->second == 15);

    assert_that(s.find(0) == s.end());
    assert_that(s.find(6) == s.end());
    assert_that(s.find(9) == s.end());
    assert_that(s.find(16) == s.end());

    // boundary
    assert_that(s.find(1) != s.end());
    assert_that(s.find(5) != s.end());
    assert_that(s.find(10) != s.end());
    assert_that(s.find(15) != s.end());
  }

  // lower_bound
  {
    tools::integer_interval_set<ll> s;
    s.insert(3, 5);
    s.insert(10, 15);

    // x inside an interval -> that interval
    auto it = s.lower_bound(4);
    assert_that(it != s.end());
    assert_that(it->first == 3);

    // x in gap -> next interval
    it = s.lower_bound(7);
    assert_that(it != s.end());
    assert_that(it->first == 10);

    // x at left boundary
    it = s.lower_bound(3);
    assert_that(it != s.end());
    assert_that(it->first == 3);

    // x at right boundary
    it = s.lower_bound(5);
    assert_that(it != s.end());
    assert_that(it->first == 3);

    // x before all
    it = s.lower_bound(0);
    assert_that(it != s.end());
    assert_that(it->first == 3);

    // x after all
    it = s.lower_bound(16);
    assert_that(it == s.end());

    // x == upper bound of last interval
    it = s.lower_bound(15);
    assert_that(it != s.end());
    assert_that(it->first == 10);
  }

  // upper_bound
  {
    tools::integer_interval_set<ll> s;
    s.insert(3, 5);
    s.insert(10, 15);

    // x before first interval's lower bound
    auto it = s.upper_bound(2);
    assert_that(it != s.end());
    assert_that(it->first == 3);

    // x == lower bound of first interval
    it = s.upper_bound(3);
    assert_that(it != s.end());
    assert_that(it->first == 10);

    // x in gap
    it = s.upper_bound(7);
    assert_that(it != s.end());
    assert_that(it->first == 10);

    // x == lower bound of second interval
    it = s.upper_bound(10);
    assert_that(it == s.end());

    // x after all
    it = s.upper_bound(15);
    assert_that(it == s.end());
  }

  // complex scenario: incremental inserts and erases
  {
    tools::integer_interval_set<ll> s;
    // build {1,2,3,4,5,6,7,8,9,10}
    for (ll i = 1; i <= 10; ++i) s.insert(i);
    assert_that(s.size() == 1);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 10}}));

    // remove evens
    s.erase(2);
    s.erase(4);
    s.erase(6);
    s.erase(8);
    s.erase(10);
    assert_that(s.size() == 5);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 1}, {3, 3}, {5, 5}, {7, 7}, {9, 9}}));

    // re-insert to merge pairs
    s.insert(2);
    s.insert(4);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 5}, {7, 7}, {9, 9}}));

    // erase range that partially overlaps
    s.erase(4, 8);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 3}, {9, 9}}));
  }

  // negative values
  {
    tools::integer_interval_set<ll> s;
    s.insert(-10, -5);
    s.insert(-3, 3);
    assert_that(s.size() == 2);
    s.insert(-4);
    // [-10,-5] and [-4] merge to [-10,-4], then [-10,-4] and [-3,3] merge to [-10,3]
    assert_that(s.size() == 1);
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{-10, 3}}));
  }

  // copy constructor
  {
    tools::integer_interval_set<ll> s;
    s.insert(1, 5);
    s.insert(10, 15);
    auto t = s;
    t.erase(3);
    // s unchanged
    assert_that(to_vec(s) == (std::vector<std::pair<ll, ll>>{{1, 5}, {10, 15}}));
    assert_that(to_vec(t) == (std::vector<std::pair<ll, ll>>{{1, 2}, {4, 5}, {10, 15}}));
  }

  return 0;
}
