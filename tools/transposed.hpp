#ifndef TOOLS_TRANSPOSED_HPP
#define TOOLS_TRANSPOSED_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <string>
#include <vector>

namespace tools {
  template <typename T>
  std::vector<std::vector<T>> transposed(const std::vector<std::vector<T>>& matrix) {
    const auto N = matrix.size();
    const auto M = matrix.empty() ? 0 : matrix.front().size();
    assert(std::ranges::all_of(matrix, [&](const auto& row) { return row.size() == M; }));

    auto res = std::vector(M, std::vector<T>(N));
    for (std::size_t r = 0; r < M; ++r) {
      for (std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[c][r];
      }
    }
    return res;
  }

  template <typename T, std::size_t N, std::size_t M>
  std::array<std::array<T, N>, M> transposed(const std::array<std::array<T, M>, N>& matrix) {
    std::array<std::array<T, N>, M> res;
    for (std::size_t r = 0; r < M; ++r) {
      for (std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[c][r];
      }
    }
    return res;
  }

  inline std::vector<std::string> transposed(const std::vector<std::string>& matrix) {
    const auto N = matrix.size();
    const auto M = matrix.empty() ? 0 : matrix.front().size();
    assert(std::ranges::all_of(matrix, [&](const auto& row) { return row.size() == M; }));

    auto res = std::vector(M, std::string(N, '\0'));
    for (std::size_t r = 0; r < M; ++r) {
      for (std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[c][r];
      }
    }
    return res;
  }
}

#endif
