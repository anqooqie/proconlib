// competitive-verifier: STANDALONE

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/divisors.hpp"
#include "tools/divisors_of_divisor.hpp"

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
        std::vector<ll> v(ds.divisors());
        std::ranges::sort(v);
        return v;
      }() == divisors[n]);

      for (ll m = 0; m <= 100; ++m) {
        assert_that(ds.contains(m) == (std::ranges::find(divisors[n], m) != divisors[n].end()));
        if (ds.contains(m)) {
          assert_that(*ds.find(m) == m);
        } else {
          assert_that(ds.find(m) == ds.divisors().end());
        }
      }

      for (auto it = ds.divisors().begin(); it != ds.divisors().end(); ++it) {
        assert_that([&]() {
          auto v = ds.divisors(it) | std::ranges::to<std::vector>();
          std::ranges::sort(v);
          return v;
        }() == divisors[*it]);
        assert_that([&]() {
          std::vector<ll> v(std::make_reverse_iterator(ds.divisors(it).end()), std::make_reverse_iterator(ds.divisors(it).begin()));
          std::ranges::sort(v);
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
      std::vector<ll> v(ds.divisors());
      std::ranges::sort(v);
      return v;
    }() == divisors);

    for (auto it = ds.divisors().begin(); it != ds.divisors().end(); ++it) {
      assert_that(std::ranges::all_of(ds.divisors(it), [&](const auto d) { return *it % d == 0; }));
      assert_that(std::all_of(std::make_reverse_iterator(ds.divisors(it).end()), std::make_reverse_iterator(ds.divisors(it).begin()), [&](const auto d) { return *it % d == 0; }));
    }
  }

  return 0;
}
