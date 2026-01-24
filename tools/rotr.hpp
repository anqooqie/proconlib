#ifndef TOOLS_ROTR_HPP
#define TOOLS_ROTR_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <concepts>
#include <limits>
#include <string>
#include <vector>
#include "tools/cmp_less_equal.hpp"
#include "tools/make_unsigned.hpp"
#include "tools/mod.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral T, tools::non_bool_integral S>
  constexpr T rotr(const T x, const int n, const S s) noexcept {
    assert(0 <= n && n <= std::numeric_limits<T>::digits);
    using U = tools::make_unsigned_t<T>;
    const U mask = (n == std::numeric_limits<T>::digits ? std::numeric_limits<T>::max() : (T(1) << n) - 1);
    assert(0 <= x && tools::cmp_less_equal(x, mask));
    const U y = static_cast<U>(x);

    if (n == 0) return x;
    const int r = tools::mod(s, n);
    if (r == 0) return x;
    return ((y << (n - r)) & mask) | (y >> r);
  }

  template <tools::non_bool_integral T, tools::non_bool_integral S>
  constexpr T rotr(const T x, const S s) noexcept {
    return tools::rotr(x, std::numeric_limits<T>::digits, s);
  }

  template <typename T, tools::non_bool_integral S>
  requires requires(T x, T y, int s) {
    { x.size() } -> std::convertible_to<int>;
    { x << s } -> std::same_as<T>;
    { x >> s } -> std::same_as<T>;
    { x | y } -> std::same_as<T>;
  }
  T rotr(const T& x, const S s) {
    const int n = x.size();
    if (n == 0) return x;
    const int r = tools::mod(s, n);
    if (r == 0) return x;
    return (x << (n - r)) | (x >> r);
  }

  template <typename T, std::size_t N, std::size_t M>
  std::array<std::array<T, N>, M> rotr(const std::array<std::array<T, M>, N>& matrix) {
    std::array<std::array<T, N>, M> res;
    for (std::size_t r = 0; r < M; ++r) {
      for (std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[N - 1 - c][r];
      }
    }
    return res;
  }

  template <typename T>
  std::vector<std::vector<T>> rotr(const std::vector<std::vector<T>>& matrix) {
    const auto N = matrix.size();
    assert(N >= 1);
    const auto M = matrix.front().size();
    assert(M >= 1);
    assert(std::ranges::all_of(matrix, [&](const auto& row) { return row.size() == M; }));

    auto res = std::vector(M, std::vector<T>(N));
    for (std::size_t r = 0; r < M; ++r) {
      for (std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[N - 1 - c][r];
      }
    }
    return res;
  }

  inline std::vector<std::string> rotr(const std::vector<std::string>& matrix) {
    const auto N = matrix.size();
    assert(N >= 1);
    const auto M = matrix.front().size();
    assert(M >= 1);
    assert(std::ranges::all_of(matrix, [&](const auto& row) { return row.size() == M; }));

    auto res = std::vector(M, std::string(N, '\0'));
    for (std::size_t r = 0; r < M; ++r) {
      for (std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[N - 1 - c][r];
      }
    }
    return res;
  }
}

#endif
