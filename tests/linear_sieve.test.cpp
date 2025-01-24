// competitive-verifier: STANDALONE

#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
#include <algorithm>
#include "tools/assert_that.hpp"
#include "tools/linear_sieve.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    tools::linear_sieve<int> sieve(10);
    {
      assert_that(!sieve.is_prime(1));
      assert_that(sieve.is_prime(2));
      assert_that(sieve.is_prime(3));
      assert_that(!sieve.is_prime(4));
      assert_that(sieve.is_prime(5));
      assert_that(!sieve.is_prime(6));
      assert_that(sieve.is_prime(7));
      assert_that(!sieve.is_prime(8));
      assert_that(!sieve.is_prime(9));
      assert_that(!sieve.is_prime(10));
    }
    {
      auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
      begin = sieve.prime_factor_range(3).begin(), end = sieve.prime_factor_range(3).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 3);
      begin = sieve.prime_factor_range(4).begin(), end = sieve.prime_factor_range(4).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      begin = sieve.prime_factor_range(5).begin(), end = sieve.prime_factor_range(5).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 5);
      begin = sieve.prime_factor_range(6).begin(), end = sieve.prime_factor_range(6).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      begin = sieve.prime_factor_range(7).begin(), end = sieve.prime_factor_range(7).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_factor_range(8).begin(), end = sieve.prime_factor_range(8).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      begin = sieve.prime_factor_range(9).begin(), end = sieve.prime_factor_range(9).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 3);
      begin = sieve.prime_factor_range(10).begin(), end = sieve.prime_factor_range(10).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 5);
    }
    {
      auto begin = sieve.distinct_prime_factor_range(1).begin(), end = sieve.distinct_prime_factor_range(1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.distinct_prime_factor_range(2).begin(), end = sieve.distinct_prime_factor_range(2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(2, 1, 2));
      begin = sieve.distinct_prime_factor_range(3).begin(), end = sieve.distinct_prime_factor_range(3).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(3, 1, 3));
      begin = sieve.distinct_prime_factor_range(4).begin(), end = sieve.distinct_prime_factor_range(4).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(2, 2, 4));
      begin = sieve.distinct_prime_factor_range(5).begin(), end = sieve.distinct_prime_factor_range(5).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(5, 1, 5));
      begin = sieve.distinct_prime_factor_range(6).begin(), end = sieve.distinct_prime_factor_range(6).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == std::make_tuple(2, 1, 2));
      assert_that(*(it++) == std::make_tuple(3, 1, 3));
      begin = sieve.distinct_prime_factor_range(7).begin(), end = sieve.distinct_prime_factor_range(7).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(7, 1, 7));
      begin = sieve.distinct_prime_factor_range(8).begin(), end = sieve.distinct_prime_factor_range(8).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(2, 3, 8));
      begin = sieve.distinct_prime_factor_range(9).begin(), end = sieve.distinct_prime_factor_range(9).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(3, 2, 9));
      begin = sieve.distinct_prime_factor_range(10).begin(), end = sieve.distinct_prime_factor_range(10).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == std::make_tuple(2, 1, 2));
      assert_that(*(it++) == std::make_tuple(5, 1, 5));
    }
    {
      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1, 1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1, 2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
      begin = sieve.prime_range(1, 3).begin(), end = sieve.prime_range(1, 3).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      begin = sieve.prime_range(1, 4).begin(), end = sieve.prime_range(1, 4).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      begin = sieve.prime_range(1, 5).begin(), end = sieve.prime_range(1, 5).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(1, 6).begin(), end = sieve.prime_range(1, 6).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(1, 7).begin(), end = sieve.prime_range(1, 7).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(1, 8).begin(), end = sieve.prime_range(1, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(1, 9).begin(), end = sieve.prime_range(1, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(1, 10).begin(), end = sieve.prime_range(1, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(2, 2).begin(), end = sieve.prime_range(2, 2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
      begin = sieve.prime_range(2, 3).begin(), end = sieve.prime_range(2, 3).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      begin = sieve.prime_range(2, 4).begin(), end = sieve.prime_range(2, 4).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      begin = sieve.prime_range(2, 5).begin(), end = sieve.prime_range(2, 5).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(2, 6).begin(), end = sieve.prime_range(2, 6).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(2, 7).begin(), end = sieve.prime_range(2, 7).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(2, 8).begin(), end = sieve.prime_range(2, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(2, 9).begin(), end = sieve.prime_range(2, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(2, 10).begin(), end = sieve.prime_range(2, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 4);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(3, 3).begin(), end = sieve.prime_range(3, 3).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 3);
      begin = sieve.prime_range(3, 4).begin(), end = sieve.prime_range(3, 4).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 3);
      begin = sieve.prime_range(3, 5).begin(), end = sieve.prime_range(3, 5).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(3, 6).begin(), end = sieve.prime_range(3, 6).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(3, 7).begin(), end = sieve.prime_range(3, 7).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(3, 8).begin(), end = sieve.prime_range(3, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(3, 9).begin(), end = sieve.prime_range(3, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(3, 10).begin(), end = sieve.prime_range(3, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 3);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(4, 4).begin(), end = sieve.prime_range(4, 4).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(4, 5).begin(), end = sieve.prime_range(4, 5).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(4, 6).begin(), end = sieve.prime_range(4, 6).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(4, 7).begin(), end = sieve.prime_range(4, 7).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(4, 8).begin(), end = sieve.prime_range(4, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(4, 9).begin(), end = sieve.prime_range(4, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(4, 10).begin(), end = sieve.prime_range(4, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(5, 5).begin(), end = sieve.prime_range(5, 5).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(5, 6).begin(), end = sieve.prime_range(5, 6).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 5);
      begin = sieve.prime_range(5, 7).begin(), end = sieve.prime_range(5, 7).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(5, 8).begin(), end = sieve.prime_range(5, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(5, 9).begin(), end = sieve.prime_range(5, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(5, 10).begin(), end = sieve.prime_range(5, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(6, 6).begin(), end = sieve.prime_range(6, 6).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(6, 7).begin(), end = sieve.prime_range(6, 7).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(6, 8).begin(), end = sieve.prime_range(6, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(6, 9).begin(), end = sieve.prime_range(6, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(6, 10).begin(), end = sieve.prime_range(6, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(7, 7).begin(), end = sieve.prime_range(7, 7).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(7, 8).begin(), end = sieve.prime_range(7, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(7, 9).begin(), end = sieve.prime_range(7, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(7, 10).begin(), end = sieve.prime_range(7, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 7);
      begin = sieve.prime_range(8, 8).begin(), end = sieve.prime_range(8, 8).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(8, 9).begin(), end = sieve.prime_range(8, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(8, 10).begin(), end = sieve.prime_range(8, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(9, 9).begin(), end = sieve.prime_range(9, 9).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(9, 10).begin(), end = sieve.prime_range(9, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(10, 10).begin(), end = sieve.prime_range(10, 10).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
    }
    {
      auto divisors = sieve.divisors(1);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1});
      divisors = sieve.divisors(2);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2});
      divisors = sieve.divisors(3);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 3});
      divisors = sieve.divisors(4);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2, 4});
      divisors = sieve.divisors(5);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 5});
      divisors = sieve.divisors(6);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2, 3, 6});
      divisors = sieve.divisors(7);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 7});
      divisors = sieve.divisors(8);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2, 4, 8});
      divisors = sieve.divisors(9);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 3, 9});
      divisors = sieve.divisors(10);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2, 5, 10});
    }
    {
      assert_that(sieve.sorted_divisors(1) == std::vector<int>{1});
      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1, 2});
      assert_that(sieve.sorted_divisors(3) == std::vector<int>{1, 3});
      assert_that(sieve.sorted_divisors(4) == std::vector<int>{1, 2, 4});
      assert_that(sieve.sorted_divisors(5) == std::vector<int>{1, 5});
      assert_that(sieve.sorted_divisors(6) == std::vector<int>{1, 2, 3, 6});
      assert_that(sieve.sorted_divisors(7) == std::vector<int>{1, 7});
      assert_that(sieve.sorted_divisors(8) == std::vector<int>{1, 2, 4, 8});
      assert_that(sieve.sorted_divisors(9) == std::vector<int>{1, 3, 9});
      assert_that(sieve.sorted_divisors(10) == std::vector<int>{1, 2, 5, 10});
    }
  }
  {
    tools::linear_sieve<int> sieve(1);
    {
      assert_that(!sieve.is_prime(1));
    }
    {
      auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end();
      assert_that(std::distance(begin, end) == 0);
    }
    {
      auto begin = sieve.distinct_prime_factor_range(1).begin(), end = sieve.distinct_prime_factor_range(1).end();
      assert_that(std::distance(begin, end) == 0);
    }
    {
      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1, 1).end();
      assert_that(std::distance(begin, end) == 0);
    }
    {
      auto divisors = sieve.divisors(1);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1});
    }
    {
      assert_that(sieve.sorted_divisors(1) == std::vector<int>{1});
    }
  }
  {
    tools::linear_sieve<int> sieve(2);
    {
      assert_that(!sieve.is_prime(1));
      assert_that(sieve.is_prime(2));
    }
    {
      auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
    }
    {
      auto begin = sieve.distinct_prime_factor_range(1).begin(), end = sieve.distinct_prime_factor_range(1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.distinct_prime_factor_range(2).begin(), end = sieve.distinct_prime_factor_range(2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(2, 1, 2));
    }
    {
      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1, 1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1, 2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
      begin = sieve.prime_range(2, 2).begin(), end = sieve.prime_range(2, 2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
    }
    {
      auto divisors = sieve.divisors(1);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1});
      divisors = sieve.divisors(2);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2});
    }
    {
      assert_that(sieve.sorted_divisors(1) == std::vector<int>{1});
      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1, 2});
    }
  }
  {
    tools::linear_sieve<int> sieve(10000000);
    {
      assert_that(!sieve.is_prime(1));
      assert_that(sieve.is_prime(2));
      assert_that(sieve.is_prime(9999991));
      assert_that(!sieve.is_prime(10000000));
    }
    {
      auto begin = sieve.prime_factor_range(1).begin(), end = sieve.prime_factor_range(1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_factor_range(2).begin(), end = sieve.prime_factor_range(2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
      begin = sieve.prime_factor_range(8648640).begin(), end = sieve.prime_factor_range(8648640).end(), it = begin;
      assert_that(std::distance(begin, end) == 13);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 3);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 7);
      assert_that(*(it++) == 11);
      assert_that(*(it++) == 13);
      begin = sieve.prime_factor_range(9999991).begin(), end = sieve.prime_factor_range(9999991).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 9999991);
      begin = sieve.prime_factor_range(10000000).begin(), end = sieve.prime_factor_range(10000000).end(), it = begin;
      assert_that(std::distance(begin, end) == 14);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 2);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 5);
      assert_that(*(it++) == 5);
    }
    {
      auto begin = sieve.distinct_prime_factor_range(1).begin(), end = sieve.distinct_prime_factor_range(1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.distinct_prime_factor_range(2).begin(), end = sieve.distinct_prime_factor_range(2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(2, 1, 2));
      begin = sieve.distinct_prime_factor_range(8648640).begin(), end = sieve.distinct_prime_factor_range(8648640).end(), it = begin;
      assert_that(std::distance(begin, end) == 6);
      assert_that(*(it++) == std::make_tuple(2, 6, 64));
      assert_that(*(it++) == std::make_tuple(3, 3, 27));
      assert_that(*(it++) == std::make_tuple(5, 1, 5));
      assert_that(*(it++) == std::make_tuple(7, 1, 7));
      assert_that(*(it++) == std::make_tuple(11, 1, 11));
      assert_that(*(it++) == std::make_tuple(13, 1, 13));
      begin = sieve.distinct_prime_factor_range(9999991).begin(), end = sieve.distinct_prime_factor_range(9999991).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == std::make_tuple(9999991, 1, 9999991));
      begin = sieve.distinct_prime_factor_range(10000000).begin(), end = sieve.distinct_prime_factor_range(10000000).end(), it = begin;
      assert_that(std::distance(begin, end) == 2);
      assert_that(*(it++) == std::make_tuple(2, 7, 128));
      assert_that(*(it++) == std::make_tuple(5, 7, 78125));
    }
    {
      auto begin = sieve.prime_range(1, 1).begin(), end = sieve.prime_range(1, 1).end(), it = begin;
      assert_that(std::distance(begin, end) == 0);
      begin = sieve.prime_range(1, 2).begin(), end = sieve.prime_range(1, 2).end(), it = begin;
      assert_that(std::distance(begin, end) == 1);
      assert_that(*(it++) == 2);
      begin = sieve.prime_range(1, 10000000).begin(), end = sieve.prime_range(1, 10000000).end(), it = begin;
      assert_that(std::distance(begin, end) == 664579);
      assert_that(*it == 2);
      it = std::next(it, 664578);
      assert_that(*it == 9999991);
    }
    {
      auto divisors = sieve.divisors(1);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1});
      divisors = sieve.divisors(2);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2});
      divisors = sieve.divisors(8648640);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 35, 36, 39, 40, 42, 44, 45, 48, 52, 54, 55, 56, 60, 63, 64, 65, 66, 70, 72, 77, 78, 80, 84, 88, 90, 91, 96, 99, 104, 105, 108, 110, 112, 117, 120, 126, 130, 132, 135, 140, 143, 144, 154, 156, 160, 165, 168, 176, 180, 182, 189, 192, 195, 198, 208, 210, 216, 220, 224, 231, 234, 240, 252, 260, 264, 270, 273, 280, 286, 288, 297, 308, 312, 315, 320, 330, 336, 351, 352, 360, 364, 378, 385, 390, 396, 416, 420, 429, 432, 440, 448, 455, 462, 468, 480, 495, 504, 520, 528, 540, 546, 560, 572, 576, 585, 594, 616, 624, 630, 660, 672, 693, 702, 704, 715, 720, 728, 756, 770, 780, 792, 819, 832, 840, 858, 864, 880, 910, 924, 936, 945, 960, 990, 1001, 1008, 1040, 1056, 1080, 1092, 1120, 1144, 1155, 1170, 1188, 1232, 1248, 1260, 1287, 1320, 1344, 1365, 1386, 1404, 1430, 1440, 1456, 1485, 1512, 1540, 1560, 1584, 1638, 1680, 1716, 1728, 1755, 1760, 1820, 1848, 1872, 1890, 1980, 2002, 2016, 2079, 2080, 2112, 2145, 2160, 2184, 2240, 2288, 2310, 2340, 2376, 2457, 2464, 2496, 2520, 2574, 2640, 2730, 2772, 2808, 2860, 2880, 2912, 2970, 3003, 3024, 3080, 3120, 3168, 3276, 3360, 3432, 3465, 3510, 3520, 3640, 3696, 3744, 3780, 3861, 3960, 4004, 4032, 4095, 4158, 4160, 4290, 4320, 4368, 4576, 4620, 4680, 4752, 4914, 4928, 5005, 5040, 5148, 5280, 5460, 5544, 5616, 5720, 5824, 5940, 6006, 6048, 6160, 6240, 6336, 6435, 6552, 6720, 6864, 6930, 7020, 7280, 7392, 7488, 7560, 7722, 7920, 8008, 8190, 8316, 8580, 8640, 8736, 9009, 9152, 9240, 9360, 9504, 9828, 10010, 10080, 10296, 10395, 10560, 10920, 11088, 11232, 11440, 11880, 12012, 12096, 12285, 12320, 12480, 12870, 13104, 13728, 13860, 14040, 14560, 14784, 15015, 15120, 15444, 15840, 16016, 16380, 16632, 17160, 17472, 18018, 18480, 18720, 19008, 19305, 19656, 20020, 20160, 20592, 20790, 21840, 22176, 22464, 22880, 23760, 24024, 24570, 24640, 25740, 26208, 27027, 27456, 27720, 28080, 29120, 30030, 30240, 30888, 31680, 32032, 32760, 33264, 34320, 36036, 36960, 37440, 38610, 39312, 40040, 41184, 41580, 43680, 44352, 45045, 45760, 47520, 48048, 49140, 51480, 52416, 54054, 55440, 56160, 60060, 60480, 61776, 64064, 65520, 66528, 68640, 72072, 73920, 77220, 78624, 80080, 82368, 83160, 87360, 90090, 95040, 96096, 98280, 102960, 108108, 110880, 112320, 120120, 123552, 131040, 133056, 135135, 137280, 144144, 154440, 157248, 160160, 166320, 180180, 192192, 196560, 205920, 216216, 221760, 240240, 247104, 262080, 270270, 288288, 308880, 320320, 332640, 360360, 393120, 411840, 432432, 480480, 540540, 576576, 617760, 665280, 720720, 786240, 864864, 960960, 1081080, 1235520, 1441440, 1729728, 2162160, 2882880, 4324320, 8648640});
      divisors = sieve.divisors(9999991);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 9999991});
      divisors = sieve.divisors(10000000);
      std::sort(divisors.begin(), divisors.end());
      assert_that(divisors == std::vector<int>{1, 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 64, 80, 100, 125, 128, 160, 200, 250, 320, 400, 500, 625, 640, 800, 1000, 1250, 1600, 2000, 2500, 3125, 3200, 4000, 5000, 6250, 8000, 10000, 12500, 15625, 16000, 20000, 25000, 31250, 40000, 50000, 62500, 78125, 80000, 100000, 125000, 156250, 200000, 250000, 312500, 400000, 500000, 625000, 1000000, 1250000, 2000000, 2500000, 5000000, 10000000});
    }
    {
      assert_that(sieve.sorted_divisors(1) == std::vector<int>{1});
      assert_that(sieve.sorted_divisors(2) == std::vector<int>{1, 2});
      assert_that(sieve.sorted_divisors(8648640) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 35, 36, 39, 40, 42, 44, 45, 48, 52, 54, 55, 56, 60, 63, 64, 65, 66, 70, 72, 77, 78, 80, 84, 88, 90, 91, 96, 99, 104, 105, 108, 110, 112, 117, 120, 126, 130, 132, 135, 140, 143, 144, 154, 156, 160, 165, 168, 176, 180, 182, 189, 192, 195, 198, 208, 210, 216, 220, 224, 231, 234, 240, 252, 260, 264, 270, 273, 280, 286, 288, 297, 308, 312, 315, 320, 330, 336, 351, 352, 360, 364, 378, 385, 390, 396, 416, 420, 429, 432, 440, 448, 455, 462, 468, 480, 495, 504, 520, 528, 540, 546, 560, 572, 576, 585, 594, 616, 624, 630, 660, 672, 693, 702, 704, 715, 720, 728, 756, 770, 780, 792, 819, 832, 840, 858, 864, 880, 910, 924, 936, 945, 960, 990, 1001, 1008, 1040, 1056, 1080, 1092, 1120, 1144, 1155, 1170, 1188, 1232, 1248, 1260, 1287, 1320, 1344, 1365, 1386, 1404, 1430, 1440, 1456, 1485, 1512, 1540, 1560, 1584, 1638, 1680, 1716, 1728, 1755, 1760, 1820, 1848, 1872, 1890, 1980, 2002, 2016, 2079, 2080, 2112, 2145, 2160, 2184, 2240, 2288, 2310, 2340, 2376, 2457, 2464, 2496, 2520, 2574, 2640, 2730, 2772, 2808, 2860, 2880, 2912, 2970, 3003, 3024, 3080, 3120, 3168, 3276, 3360, 3432, 3465, 3510, 3520, 3640, 3696, 3744, 3780, 3861, 3960, 4004, 4032, 4095, 4158, 4160, 4290, 4320, 4368, 4576, 4620, 4680, 4752, 4914, 4928, 5005, 5040, 5148, 5280, 5460, 5544, 5616, 5720, 5824, 5940, 6006, 6048, 6160, 6240, 6336, 6435, 6552, 6720, 6864, 6930, 7020, 7280, 7392, 7488, 7560, 7722, 7920, 8008, 8190, 8316, 8580, 8640, 8736, 9009, 9152, 9240, 9360, 9504, 9828, 10010, 10080, 10296, 10395, 10560, 10920, 11088, 11232, 11440, 11880, 12012, 12096, 12285, 12320, 12480, 12870, 13104, 13728, 13860, 14040, 14560, 14784, 15015, 15120, 15444, 15840, 16016, 16380, 16632, 17160, 17472, 18018, 18480, 18720, 19008, 19305, 19656, 20020, 20160, 20592, 20790, 21840, 22176, 22464, 22880, 23760, 24024, 24570, 24640, 25740, 26208, 27027, 27456, 27720, 28080, 29120, 30030, 30240, 30888, 31680, 32032, 32760, 33264, 34320, 36036, 36960, 37440, 38610, 39312, 40040, 41184, 41580, 43680, 44352, 45045, 45760, 47520, 48048, 49140, 51480, 52416, 54054, 55440, 56160, 60060, 60480, 61776, 64064, 65520, 66528, 68640, 72072, 73920, 77220, 78624, 80080, 82368, 83160, 87360, 90090, 95040, 96096, 98280, 102960, 108108, 110880, 112320, 120120, 123552, 131040, 133056, 135135, 137280, 144144, 154440, 157248, 160160, 166320, 180180, 192192, 196560, 205920, 216216, 221760, 240240, 247104, 262080, 270270, 288288, 308880, 320320, 332640, 360360, 393120, 411840, 432432, 480480, 540540, 576576, 617760, 665280, 720720, 786240, 864864, 960960, 1081080, 1235520, 1441440, 1729728, 2162160, 2882880, 4324320, 8648640});
      assert_that(sieve.sorted_divisors(9999991) == std::vector<int>{1, 9999991});
      assert_that(sieve.sorted_divisors(10000000) == std::vector<int>{1, 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 64, 80, 100, 125, 128, 160, 200, 250, 320, 400, 500, 625, 640, 800, 1000, 1250, 1600, 2000, 2500, 3125, 3200, 4000, 5000, 6250, 8000, 10000, 12500, 15625, 16000, 20000, 25000, 31250, 40000, 50000, 62500, 78125, 80000, 100000, 125000, 156250, 200000, 250000, 312500, 400000, 500000, 625000, 1000000, 1250000, 2000000, 2500000, 5000000, 10000000});
    }
  }

  return 0;
}
