// competitive-verifier: STANDALONE

#include <iostream>
#include <vector>
#include <algorithm>
#include "tools/assert_that.hpp"
#include "tools/tuple_hash.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    std::vector<std::size_t> v;
    const tools::tuple_hash<ll> hasher;
    for (ll i = 0; i < 10000000; ++i) {
      const auto tuple = std::make_tuple(i);
      v.push_back(hasher(tuple));
      assert_that(hasher(tuple) == v.back());
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  {
    std::vector<std::size_t> v;
    const tools::tuple_hash<ll, ll> hasher;
    for (ll i = 0; i < 3000; ++i) {
      for (ll j = 0; j < 3000; ++j) {
        const auto tuple = std::make_tuple(i, j);
        v.push_back(hasher(tuple));
        assert_that(hasher(tuple) == v.back());
      }
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  {
    std::vector<std::size_t> v;
    const tools::tuple_hash<ll, ll, ll> hasher;
    for (ll i = 0; i < 200; ++i) {
      for (ll j = 0; j < 200; ++j) {
        for (ll k = 0; k < 200; ++k) {
          const auto tuple = std::make_tuple(i, j, k);
          v.push_back(hasher(tuple));
          assert_that(hasher(tuple) == v.back());
        }
      }
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  {
    std::vector<std::size_t> v;
    const tools::tuple_hash<ll, ll, ll, ll> hasher;
    for (ll i = 0; i < 60; ++i) {
      for (ll j = 0; j < 60; ++j) {
        for (ll k = 0; k < 60; ++k) {
          for (ll l = 0; l < 60; ++l) {
            const auto tuple = std::make_tuple(i, j, k, l);
            v.push_back(hasher(tuple));
            assert_that(hasher(tuple) == v.back());
          }
        }
      }
    }

    const auto old_size = v.size();
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    assert_that(v.size() == old_size);
  }

  return 0;
}
