#ifndef TOOLS_ROTR45_HPP
#define TOOLS_ROTR45_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <string>
#include <type_traits>
#include <vector>

namespace tools {
  template <typename T, std::size_t N, std::size_t M>
  std::array<std::array<T, N + M - 1>, N + M - 1> rotr45(const std::array<std::array<T, M>, N>& matrix, const std::type_identity_t<T> default_value) {
    static_assert(N >= 1);
    static_assert(M >= 1);

    std::array<T, N + M - 1> row;
    row.fill(default_value);
    std::array<std::array<T, N + M - 1>, N + M - 1> res;
    res.fill(row);
    for (int r = 0; r < int(N); ++r) {
      for (int c = 0; c < int(M); ++c) {
        res[r + c][c - r + int(N) - 1] = matrix[r][c];
      }
    }
    return res;
  }

  template <typename T>
  std::vector<std::vector<T>> rotr45(const std::vector<std::vector<T>>& matrix, const std::type_identity_t<T> default_value) {
    const int N = matrix.size();
    assert(N >= 1);
    const int M = matrix.front().size();
    assert(M >= 1);
    assert(std::ranges::all_of(matrix, [&](const auto& row) { return std::ssize(row) == M; }));

    auto res = std::vector(N + M - 1, std::vector<T>(N + M - 1, default_value));
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < M; ++c) {
        res[r + c][c - r + N - 1] = matrix[r][c];
      }
    }
    return res;
  }

  inline std::vector<std::string> rotr45(const std::vector<std::string>& matrix, const char default_value) {
    const int N = matrix.size();
    assert(N >= 1);
    const int M = matrix.front().size();
    assert(M >= 1);
    assert(std::ranges::all_of(matrix, [&](const auto& row) { return std::ssize(row) == M; }));

    auto res = std::vector(N + M - 1, std::string(N + M - 1, default_value));
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < M; ++c) {
        res[r + c][c - r + N - 1] = matrix[r][c];
      }
    }
    return res;
  }
}

#endif
