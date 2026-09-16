// competitive-verifier: STANDALONE

#include <algorithm>
#include <concepts>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/assert_that.hpp"
#include "tools/int128_t.hpp"
#include "tools/palindromes.hpp"

using ll = long long;
using ull = unsigned long long;
using i128 = tools::int128_t;

template <tools::non_bool_integral T>
bool is_palindrome(T n) {
  std::vector<int> digits;
  do {
    digits.push_back(int(n % 10));
    n /= 10;
  } while (n > 0);
  return std::ranges::equal(digits, digits | std::views::reverse);
}

template <tools::non_bool_integral T>
std::vector<T> brute_force(const T a, const T b) {
  std::vector<T> res;
  for (T n = a; n < b; ++n) {
    if (is_palindrome(n)) res.push_back(n);
  }
  return res;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  using V = tools::palindrome_view<ll>;
  static_assert(std::ranges::view<V>);
  static_assert(std::ranges::random_access_range<V>);
  static_assert(std::ranges::sized_range<V>);
  static_assert(std::ranges::common_range<V>);
  static_assert(std::ranges::borrowed_range<V>);
  static_assert(std::same_as<std::ranges::range_value_t<V>, ll>);
  static_assert(std::same_as<std::ranges::range_difference_t<V>, std::ptrdiff_t>);
  static_assert(std::same_as<std::ranges::range_difference_t<tools::palindrome_view<i128>>, i128>);
  static_assert(std::same_as<std::ranges::range_size_t<V>, std::ptrdiff_t>);
  static_assert(std::same_as<std::ranges::range_size_t<tools::palindrome_view<i128>>, i128>);
  static_assert(std::same_as<decltype(std::declval<const V&>().size()), std::ptrdiff_t>);

  static_assert(std::same_as<decltype(tools::palindromes(0, 0LL)), tools::palindrome_view<ll>>);
  static_assert(std::same_as<decltype(tools::palindromes(0, i128(0))), tools::palindrome_view<i128>>);

  static_assert(*tools::palindromes(100, 1000).begin() == 101);
  static_assert(tools::palindromes(0, 1000).size() == 109);

  // exhaustive comparison against brute force
  {
    const auto expected = brute_force<ll>(0, 20000);
    assert_that(std::ranges::equal(tools::palindromes(0LL, 20000LL), expected));
  }
  for (ll a = 0; a <= 200; ++a) {
    for (ll b = a; b <= 200; ++b) {
      const auto r = tools::palindromes(a, b);
      const auto expected = brute_force(a, b);
      assert_that(std::ranges::equal(r, expected));
      assert_that(r.size() == std::ssize(expected));
    }
  }

  // windows far from the origin, where the number of digits changes in the middle
  {
    const ll a = 999000;
    const ll b = 1001000;
    assert_that(std::ranges::equal(tools::palindromes(a, b), brute_force(a, b)));
  }
  {
    const ll a = 999999999999998000LL;
    const ll b = 1000000000000002000LL;
    assert_that(std::ranges::equal(tools::palindromes(a, b), brute_force(a, b)));
  }
  {
    const ull a = std::numeric_limits<ull>::max() - 2000;
    const ull b = std::numeric_limits<ull>::max();
    assert_that(std::ranges::equal(tools::palindromes(a, b), brute_force(a, b)));
  }

  // a narrow type, where the tables hold only a few entries
  {
    using uc = unsigned char;
    const auto r = tools::palindromes(uc(0), std::numeric_limits<uc>::max());
    assert_that(std::ranges::equal(r, brute_force<uc>(0, std::numeric_limits<uc>::max())));
    assert_that(r.size() == 35);
  }

  // degenerate cases
  assert_that(tools::palindromes(0, 0).empty());
  assert_that(tools::palindromes(5, 5).empty());
  assert_that(std::ranges::equal(tools::palindromes(0, 1), std::vector<int>{0}));
  assert_that(std::ranges::equal(tools::palindromes(10, 11), std::vector<int>{}));

  // random access
  {
    const auto r = tools::palindromes(0LL, 1000LL);
    assert_that(r.size() == 109);
    assert_that(r[0] == 0);
    assert_that(r[9] == 9);
    assert_that(r[10] == 11);
    assert_that(r[108] == 999);
    assert_that(r.front() == 0);
    assert_that(r.back() == 999);
    assert_that(*(r.begin() + 19) == 101);
    assert_that(*std::ranges::prev(r.end()) == 999);
    assert_that(std::ranges::equal(r | std::views::drop(100), brute_force<ll>(919, 1000)));
    assert_that(std::ranges::lower_bound(r, 500LL) - r.begin() == 59);
  }

  // a huge range which cannot be materialized
  {
    const auto r = tools::palindromes(0LL, 1000000000000000000LL);
    assert_that(r.size() == 1999999999LL);
    assert_that(r[0] == 0);
    assert_that(r[1999999998] == 999999999999999999LL);
    assert_that(std::ranges::equal(r | std::views::take(12), brute_force<ll>(0, 23)));
  }

  // the maximum value of T, where building the palindrome sharing the leading
  // digits with it would overflow T
  {
    const auto r = tools::palindromes(0ULL, std::numeric_limits<ull>::max());
    assert_that(r.size() == 11844674406LL);
    assert_that(r[11844674405] == 18446744066044764481ULL);
    assert_that(is_palindrome(r[11844674405]));
  }

  // a difference type wider than 64 bits
  {
    const auto r = tools::palindromes(i128(0), std::numeric_limits<i128>::max());
    assert_that(r.size() == i128(27) * 1000000000000000000 + 14118346046923172);
    assert_that(r[0] == 0);
    assert_that(is_palindrome(r[i128(10) * 1000000000000000000]));
    assert_that(std::ranges::equal(r | std::views::take(12), brute_force<i128>(0, 23)));
  }

  return 0;
}
