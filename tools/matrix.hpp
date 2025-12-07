#ifndef TOOLS_MATRIX_HPP
#define TOOLS_MATRIX_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/vector.hpp"

namespace tools {
  namespace detail {
    namespace matrix {
      template <typename T, std::size_t N, std::size_t M>
      class members {
      protected:
        constexpr static bool variable_sized = false;
        std::array<T, N * M> m_values;
        members() : m_values() {}
      };
      template <typename T>
      class members<T, std::numeric_limits<std::size_t>::max(), std::numeric_limits<std::size_t>::max()> {
      protected:
        constexpr static bool variable_sized = true;
        std::vector<T> m_values;
        int m_rows;
        int m_cols;
        members() = default;
        members(const int rows, const int cols) : m_values(rows * cols), m_rows(rows), m_cols(cols) {
          assert(rows >= 0);
          assert(cols >= 0);
        }
        members(const int rows, const int cols, const T& value) : m_values(rows * cols, value), m_rows(rows), m_cols(cols) {
          assert(rows >= 0);
          assert(cols >= 0);
        }
      };
    }
  }

  template <typename T, std::size_t N = std::numeric_limits<std::size_t>::max(), std::size_t M = std::numeric_limits<std::size_t>::max()>
  class matrix : tools::detail::matrix::members<T, N, M> {
    template <typename, std::size_t, std::size_t>
    friend class tools::matrix;
    using Mat = tools::matrix<T, N, M>;
    using Base = tools::detail::matrix::members<T, N, M>;
    constexpr static bool variable_sized = Base::variable_sized;

  public:
    matrix() = default;
    template <bool SFINAE = variable_sized> requires (SFINAE)
    matrix(const int rows, const int cols) : Base(rows, cols) {}
    template <bool SFINAE = variable_sized> requires (SFINAE)
    matrix(const int rows, const int cols, const T& value) : Base(rows, cols, value) {}
    template <bool SFINAE = !variable_sized> requires (SFINAE)
    matrix(const std::initializer_list<std::initializer_list<T>> il) {
      assert(il.size() == this->rows());
      assert(std::ranges::all_of(il, [&](const auto& row) { return std::ssize(row) == this->cols(); }));
      for (int r = 0; r < this->rows(); ++r) {
        std::ranges::copy(il.begin()[r], (*this)[r]);
      }
    }
    template <bool SFINAE = variable_sized, std::nullptr_t = nullptr> requires (SFINAE)
    matrix(const std::initializer_list<std::initializer_list<T>> il) : Base(il.size(), il.size() ? il.begin()->size() : 0) {
      assert(std::ranges::all_of(il, [&](const auto& row) { return std::ssize(row) == this->cols(); }));
      for (int r = 0; r < this->rows(); ++r) {
        std::ranges::copy(il.begin()[r], (*this)[r]);
      }
    }
    auto operator[](const int r) {
      assert(0 <= r && r < this->rows());
      return this->m_values.begin() + r * this->cols();
    }
    auto operator[](const int r) const {
      assert(0 <= r && r < this->rows());
      return this->m_values.begin() + r * this->cols();
    }

    int rows() const {
      if constexpr (variable_sized) {
        return this->m_rows;
      } else {
        return N;
      }
    }
    int cols() const {
      if constexpr (variable_sized) {
        return this->m_cols;
      } else {
        return M;
      }
    }

    Mat operator+() const {
      return *this;
    }
    Mat operator-() const {
      return Mat(*this) *= T(-1);
    }
    friend Mat operator+(const Mat& lhs, const Mat& rhs) {
      return Mat(lhs) += rhs;
    }
    friend Mat operator-(const Mat& lhs, const Mat& rhs) {
      return Mat(lhs) -= rhs;
    }
    template <std::size_t K> requires (!Mat::variable_sized || K == std::numeric_limits<std::size_t>::max())
    friend tools::matrix<T, N, K> operator*(const Mat& lhs, const tools::matrix<T, M, K>& rhs) {
      assert(lhs.cols() == rhs.rows());
      auto result = [&]() {
        if constexpr (Mat::variable_sized) {
          return tools::matrix<T>(lhs.rows(), rhs.cols());
        } else {
          return tools::matrix<T, N, K>{};
        }
      }();
      for (int i = 0; i < lhs.rows(); ++i) {
        for (int k = 0; k < lhs.cols(); ++k) {
          for (int j = 0; j < rhs.cols(); ++j) {
            result[i][j] += lhs[i][k] * rhs[k][j];
          }
        }
      }
      return result;
    }
    friend tools::vector<T, N> operator*(const Mat& lhs, const tools::vector<T, M>& rhs) {
      assert(lhs.cols() == rhs.size());
      auto result = [&]() {
        if constexpr (Mat::variable_sized) {
          return tools::vector<T>(lhs.rows());
        } else {
          return tools::vector<T, N>{};
        }
      }();
      for (int i = 0; i < lhs.rows(); ++i) {
        for (int j = 0; j < lhs.cols(); ++j) {
          result[i] += lhs[i][j] * rhs[j];
        }
      }
      return result;
    }
    friend Mat operator*(const Mat& lhs, const T& rhs) {
      return Mat(lhs) *= rhs;
    }
    friend Mat operator/(const Mat& lhs, const tools::matrix<T, M, M>& rhs) {
      const auto inv = rhs.inv();
      assert(inv);
      return lhs * *inv;
    }
    friend Mat operator/(const Mat& lhs, const T& rhs) {
      return Mat(lhs) /= rhs;
    }
    Mat& operator+=(const Mat& other) {
      assert(this->rows() == other.rows());
      assert(this->cols() == other.cols());
      for (std::size_t i = 0; i < this->m_values.size(); ++i) {
        this->m_values[i] += other.m_values[i];
      }
      return *this;
    }
    Mat& operator-=(const Mat& other) {
      assert(this->rows() == other.rows());
      assert(this->cols() == other.cols());
      for (std::size_t i = 0; i < this->m_values.size(); ++i) {
        this->m_values[i] -= other.m_values[i];
      }
      return *this;
    }
    Mat& operator*=(const tools::matrix<T, M, M>& other) {
      return *this = *this * other;
    }
    Mat& operator*=(const T& c) {
      for (auto& v : this->m_values) v *= c;
      return *this;
    }
    Mat& operator/=(const tools::matrix<T, M, M>& other) {
      return *this = *this / other;
    }
    Mat& operator/=(const T& c) {
      return *this *= T(1) / c;
    }
    friend bool operator==(const Mat& lhs, const Mat& rhs) {
      if constexpr (variable_sized) {
        if (lhs.rows() != rhs.rows()) return false;
        if (lhs.cols() != rhs.cols()) return false;
      }
      return lhs.m_values == rhs.m_values;
    }
    friend bool operator!=(const Mat& lhs, const Mat& rhs) {
      return !(lhs == rhs);
    }

    friend std::istream& operator>>(std::istream& is, Mat& self) {
      for (auto& v : self.m_values) is >> v;
      return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Mat& self) {
      for (int r = 0; r < self.rows(); ++r) {
        os << '[';
        std::string delimiter = "";
        for (int c = 0; c < self.cols(); ++c) {
          os << delimiter << self[r][c];
          delimiter = ", ";
        }
        os << ']' << '\n';
      }
      return os;
    }

  private:
    std::pair<int, T> internal_gauss_jordan() {
      int rank = 0;
      T coeff(1);

      for (int c = 0; c < this->cols(); ++c) {
        int pivot;
        for (pivot = rank; pivot < this->rows() && (*this)[pivot][c] == T(0); ++pivot);
        if (pivot == this->rows()) continue;

        if (pivot != rank) {
          for (int cc = c; cc < this->cols(); ++cc) {
            std::swap((*this)[rank][cc], (*this)[pivot][cc]);
          }
          coeff *= T(-1);
        }

        {
          const T scale_inv = T(1) / (*this)[rank][c];
          for (int cc = c; cc < this->cols(); ++cc) {
            (*this)[rank][cc] *= scale_inv;
          }
          coeff *= scale_inv;
        }

        for (int r = 0; r < this->rows(); ++r) {
          if (r == rank) continue;
          const T scale = (*this)[r][c];
          if (scale == T(0)) continue;
          for (int cc = c; cc < this->cols(); ++cc) {
            (*this)[r][cc] -= (*this)[rank][cc] * scale;
          }
        }

        ++rank;
      }

      return std::make_pair(rank, coeff);
    }

  public:
    int gauss_jordan() {
      return this->internal_gauss_jordan().first;
    }

    int rank() const {
      return (this->rows() < this->cols() ? this->transposed() : Mat(*this)).gauss_jordan();
    }

    tools::matrix<T> solve(const tools::vector<T, N>& b) const {
      assert(this->rows() == b.size());
      assert(this->cols() >= 1);
      auto Ab = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->rows(), this->cols() + 1);
        } else {
          return tools::matrix<T, N, M + 1>{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          Ab[r][c] = (*this)[r][c];
        }
        Ab[r][this->cols()] = b[r];
      }

      Ab.internal_gauss_jordan();

      std::vector<int> ranks(Ab.cols());
      for (int r = 0, cl = 0, cr = 0; r <= Ab.rows(); ++r, cl = cr) {
        for (; cr < Ab.cols() && (r == Ab.rows() || Ab[r][cr] == T(0)); ++cr);
        for (int c = cl; c < cr; ++c) {
          ranks[c] = r;
        }
      }

      if (ranks[Ab.cols() - 2] < ranks[Ab.cols() - 1]) {
        return tools::matrix<T>(this->rows(), 0);
      }

      std::vector<tools::vector<T>> answers(this->cols());
      int free = this->cols() - ranks.back() - 1;

      for (int l = this->cols(), r = this->cols(); r > 0; r = l) {
        for (; l > 0 && ranks[l - 1] == ranks[r - 1]; --l);
        for (int c = r - 1; c > l; --c) {
          answers[c] = tools::vector<T>(this->cols() - ranks.back() + 1, T(0));
          answers[c][free] = T(1);
          --free;
        }
        if (ranks[l] > 0) {
          answers[l] = tools::vector<T>(this->cols() - ranks.back() + 1, T(0));
          answers[l][this->cols() - ranks.back()] = Ab[ranks[l] - 1][Ab.cols() - 1];
          for (int c = l + 1; c < Ab.cols() - 1; ++c) {
            answers[l] -= Ab[ranks[l] - 1][c] * answers[c];
          }
        } else {
          answers[l] = tools::vector<T>(this->cols() - ranks.back() + 1, T(0));
          answers[l][free] = T(1);
          --free;
        }
      }

      tools::matrix<T> answer(this->cols(), this->cols() - ranks.back() + 1);
      for (int r = 0; r < this->cols(); ++r) {
        for (int c = 0; c < this->cols() - ranks.back() + 1; ++c) {
          answer[r][c] = answers[r][c];
        }
      }

      return answer;
    }

    T determinant() const {
      assert(this->rows() == this->cols());

      auto A = *this;
      const auto [rank, coeff] = A.internal_gauss_jordan();

      return rank == A.rows() ? T(1) / coeff : T(0);
    }

    template <bool SFINAE = !variable_sized && N == M> requires (SFINAE)
    static Mat e() {
      Mat result{};
      for (int i = 0; i < N; ++i) {
        result[i][i] = T(1);
      }
      return result;
    }
    template <bool SFINAE = variable_sized> requires (SFINAE)
    static Mat e(const int n) {
      assert(n >= 0);
      Mat result(n, n, T(0));
      for (int i = 0; i < n; ++i) {
        result[i][i] = T(1);
      }
      return result;
    }

    template <bool SFINAE = variable_sized || N == M> requires (SFINAE)
    std::optional<Mat> inv() const {
      assert(this->rows() == this->cols());

      auto AI = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->rows(), this->cols() * 2);
        } else {
          return tools::matrix<T, N, M * 2>{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          AI[r][c] = (*this)[r][c];
        }
        for (int c = this->cols(); c < AI.cols(); ++c) {
          AI[r][c] = T(0);
        }
        AI[r][this->cols() + r] = T(1);
      }

      AI.internal_gauss_jordan();
      for (int i = 0; i < this->rows(); ++i) {
        if (AI[i][i] != T(1)) return std::nullopt;
      }

      auto B = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->rows(), this->cols());
        } else {
          return Mat{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          B[r][c] = AI[r][this->cols() + c];
        }
      }
      return B;
    }

    tools::matrix<T, M, N> transposed() const {
      auto A_T = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->cols(), this->rows());
        } else {
          return tools::matrix<T, M, N>{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          A_T[c][r] = (*this)[r][c];
        }
      }
      return A_T;
    }
  };
}

#endif
