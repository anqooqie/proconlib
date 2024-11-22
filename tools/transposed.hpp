#ifndef TOOLS_TRANSPOSED_HPP
#define TOOLS_TRANSPOSED_HPP

#include <vector>
#include <cassert>
#include <algorithm>
#include <cstddef>
#include <array>

namespace tools {
  template <typename T>
  ::std::vector<::std::vector<T>> transposed(const ::std::vector<::std::vector<T>>& matrix) {
    const auto N = matrix.size();
    const auto M = matrix.empty() ? 0 : matrix.front().size();
    assert(::std::all_of(matrix.begin(), matrix.end(), [&](const auto& row) { return row.size() == M; }));

    auto res = ::std::vector(M, ::std::vector<T>(N));
    for (::std::size_t r = 0; r < M; ++r) {
      for (::std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[c][r];
      }
    }
    return res;
  }

  template <typename T, ::std::size_t N>
  ::std::vector<::std::array<T, N>> transposed(const ::std::array<::std::vector<T>, N>& matrix) {
    const auto M = matrix.empty() ? 0 : matrix.front().size();
    assert(::std::all_of(matrix.begin(), matrix.end(), [&](const auto& row) { return row.size() == M; }));

    auto res = ::std::vector(M, ::std::array<T, N>{});
    for (::std::size_t r = 0; r < M; ++r) {
      for (::std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[c][r];
      }
    }
    return res;
  }

  template <typename T, ::std::size_t M>
  ::std::array<::std::vector<T>, M> transposed(const ::std::vector<::std::array<T, M>>& matrix) {
    const auto N = matrix.size();

    ::std::array<::std::vector<T>, M> res;
    for (::std::size_t r = 0; r < M; ++r) {
      res[r].resize(N);
      for (::std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[c][r];
      }
    }
    return res;
  }

  template <typename T, ::std::size_t N, ::std::size_t M>
  ::std::array<::std::array<T, N>, M> transposed(const ::std::array<::std::array<T, M>, N>& matrix) {
    ::std::array<::std::array<T, N>, M> res;
    for (::std::size_t r = 0; r < M; ++r) {
      for (::std::size_t c = 0; c < N; ++c) {
        res[r][c] = matrix[c][r];
      }
    }
    return res;
  }
}

#endif
