// competitive-verifier: STANDALONE

#include <cmath>
#include <iostream>
#include <iterator>
#include <random>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/persistent_array.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  {
    const tools::persistent_array<int> a;
    assert_that(a.empty());
    assert_that(a.size() == 0);
  }
  assert_that(tools::persistent_array<int>::fully_released());
  {
    const tools::persistent_array<int> a{0};
    assert_that(!a.empty());
    assert_that(a.size() == 1);
    assert_that(a[0] == 0);
  }
  assert_that(tools::persistent_array<int>::fully_released());
  {
    const tools::persistent_array<int> a{0, 1};
    assert_that(!a.empty());
    assert_that(a.size() == 2);
    assert_that(a[0] == 0);
    assert_that(a[1] == 1);
  }
  assert_that(tools::persistent_array<int>::fully_released());
  {
    const tools::persistent_array<int> a{0, 1, 2};
    assert_that(!a.empty());
    assert_that(a.size() == 3);
    assert_that(a[0] == 0);
    assert_that(a[1] == 1);
    assert_that(a[2] == 2);
  }
  assert_that(tools::persistent_array<int>::fully_released());

  for (int n = 0; n <= 40; ++n) {
    {
      const tools::persistent_array<int> a(n);
      for (int i = 0; i < n; ++i) {
        assert_that(a[i] == 0);
      }
      assert_that(static_cast<std::vector<int>>(a) == std::vector<int>(n, 0));
    }
    assert_that(tools::persistent_array<int>::fully_released());
    {
      const tools::persistent_array<int> a(n, -1234);
      for (int i = 0; i < n; ++i) {
        assert_that(a[i] == -1234);
      }
      assert_that(static_cast<std::vector<int>>(a) == std::vector<int>(n, -1234));
    }
    assert_that(tools::persistent_array<int>::fully_released());
    {
      const tools::persistent_array<int> a(std::views::iota(0, n));
      for (int i = 0; i < n; ++i) {
        assert_that(a[i] == i);
      }
      assert_that(static_cast<std::vector<int>>(a) == (std::views::iota(0, n) | std::ranges::to<std::vector>()));
    }
    assert_that(tools::persistent_array<int>::fully_released());

    {
      std::vector<tools::persistent_array<int>> arrays(n + 1);
      arrays[0] = tools::persistent_array<int>(n, -1234);
      for (int i = 1; i <= n; ++i) {
        arrays[i] = arrays[i - 1].set(i - 1, i - 1);
      }
      for (int i = 0; i <= n; ++i) {
        assert_that(static_cast<std::vector<int>>(arrays[i]) == (std::views::iota(0, n) | std::views::transform([&](const auto j) { return j < i ? j : -1234; }) | std::ranges::to<std::vector>()));
      }
    }
    assert_that(tools::persistent_array<int>::fully_released());
    {
      std::vector<tools::persistent_array<int>> arrays(n + 1);
      arrays[0] = tools::persistent_array<int>(std::views::repeat(-1234, n));
      for (int i = 1; i <= n; ++i) {
        arrays[i] = arrays[i - 1].set(i - 1, i - 1);
      }
      for (int i = 0; i <= n; ++i) {
        assert_that(static_cast<std::vector<int>>(arrays[i]) == (std::views::iota(0, n) | std::views::transform([&](const auto j) { return j < i ? j : -1234; }) | std::ranges::to<std::vector>()));
      }
    }
    assert_that(tools::persistent_array<int>::fully_released());

    {
      std::vector<tools::persistent_array<int>> arrays(2 * n + 1);
      for (int i = 1; i <= n; ++i) {
        arrays[i] = arrays[i - 1].push_back(i - 1);
      }
      for (int i = n + 1; i <= 2 * n; ++i) {
        arrays[i] = arrays[i - 1].pop_back();
      }
      for (int i = 0; i <= 2 * n; ++i) {
        assert_that(static_cast<std::vector<int>>(arrays[i]) == (std::views::iota(0, n - std::abs(n - i)) | std::ranges::to<std::vector>()));
      }
    }
    assert_that(tools::persistent_array<int>::fully_released());
  }

  {
    const tools::persistent_array<int> a{3, 1, 4, 1, 5};
    auto b = a;
    const auto c = b;
    b = b.set(2, -1);
    assert_that(static_cast<std::vector<int>>(a) == std::vector<int>{3, 1, 4, 1, 5});
    assert_that(static_cast<std::vector<int>>(b) == std::vector<int>{3, 1, -1, 1, 5});
    assert_that(static_cast<std::vector<int>>(c) == std::vector<int>{3, 1, 4, 1, 5});
  }
  assert_that(tools::persistent_array<int>::fully_released());
  {
    tools::persistent_array<int> a{3, 1, 4, 1, 5};
    tools::persistent_array<int> b(std::move(a));
    assert_that(a.empty());
    assert_that(static_cast<std::vector<int>>(b) == std::vector<int>{3, 1, 4, 1, 5});

    const auto c = std::move(b);
    assert_that(a.empty());
    assert_that(b.empty());
    assert_that(static_cast<std::vector<int>>(c) == std::vector<int>{3, 1, 4, 1, 5});
  }
  assert_that(tools::persistent_array<int>::fully_released());

  {
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::uniform_int_distribution<int> t_dist(0, 3);
    std::uniform_int_distribution<int> x_dist(-1000000000, 1000000000);

    tools::persistent_array<int> a;
    std::vector<tools::persistent_array<int>> a_history;
    std::vector<int> naive;
    std::vector<std::vector<int>> naive_history;
    for (int q = 1; q <= 1000000; ++q) {
      const int t = a.empty() ? 0 : t_dist(engine);
      if (t <= 1) {
        const auto x = x_dist(engine);
        a = a.push_back(x);
        naive.push_back(x);
      } else if (t == 2) {
        a = a.pop_back();
        naive.pop_back();
      } else {
        const auto i = std::uniform_int_distribution<int>(0, a.size() - 1)(engine);
        const auto x = x_dist(engine);
        a = a.set(i, x);
        naive[i] = x;
      }

      if (q % 100000 == 0) {
        a_history.push_back(a);
        naive_history.push_back(naive);
      }
    }

    for (int q = 0; q < std::ssize(a_history); ++q) {
      assert_that(static_cast<std::vector<int>>(a_history[q]) == naive_history[q]);
    }
  }
  assert_that(tools::persistent_array<int>::fully_released());

  return 0;
}
