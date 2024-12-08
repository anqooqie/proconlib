#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "tools/assert_that.hpp"
#include "tools/divisors_of_divisor.hpp"
#include "tools/divisors.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<std::vector<ll>> divisors(101);
    for (ll n = 1; n <= 100; ++n) {
      divisors[n] = tools::divisors(n);
    }

    for (ll n = 1; n <= 100; ++n) {
      tools::divisors_of_divisor<ll> ds(n);

      assert_that([&]() {
        std::vector<ll> v(ds.divisors().begin(), ds.divisors().end());
        std::sort(v.begin(), v.end());
        return v;
      }() == divisors[n]);

      for (ll m = 0; m <= 100; ++m) {
        assert_that(ds.contains(m) == (std::find(divisors[n].begin(), divisors[n].end(), m) != divisors[n].end()));
        if (ds.contains(m)) {
          assert_that(*ds.find(m) == m);
        } else {
          assert_that(ds.find(m) == ds.divisors().end());
        }
      }

      for (auto it = ds.divisors().begin(); it != ds.divisors().end(); ++it) {
        assert_that([&]() {
          std::vector<ll> v(ds.divisors(it).begin(), ds.divisors(it).end());
          std::sort(v.begin(), v.end());
          return v;
        }() == divisors[*it]);
        assert_that([&]() {
          std::vector<ll> v(std::make_reverse_iterator(ds.divisors(it).end()), std::make_reverse_iterator(ds.divisors(it).begin()));
          std::sort(v.begin(), v.end());
          return v;
        }() == divisors[*it]);
      }
    }
  }

  {
    const ll n = 897612484786617600;
    const auto divisors = tools::divisors(n);

    tools::divisors_of_divisor<ll> ds(n);

    assert_that([&]() {
      std::vector<ll> v(ds.divisors().begin(), ds.divisors().end());
      std::sort(v.begin(), v.end());
      return v;
    }() == divisors);

    for (auto it = ds.divisors().begin(); it != ds.divisors().end(); ++it) {
      assert_that(std::all_of(ds.divisors(it).begin(), ds.divisors(it).end(), [&](const auto d) { return *it % d == 0; }));
      assert_that(std::all_of(std::make_reverse_iterator(ds.divisors(it).end()), std::make_reverse_iterator(ds.divisors(it).begin()), [&](const auto d) { return *it % d == 0; }));
    }
  }

  std::cout << "Hello World" << '\n';
  return 0;
}
