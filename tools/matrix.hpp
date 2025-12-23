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
#include <utility>
#include <vector>
#include "tools/field.hpp"
#include "tools/groups.hpp"
#include "tools/multiplicative_structure.hpp"
#include "tools/mutable_type.hpp"
#include "tools/ring.hpp"
#include "tools/rings.hpp"
#include "tools/semiring.hpp"
#include "tools/vector.hpp"

namespace tools {
  namespace detail {
    namespace matrix {
      template <typename X, std::size_t N, std::size_t M>
      class members {
        using R = std::conditional_t<tools::semiring<X>, X, tools::rings::of<tools::groups::plus<X>, tools::multiplicative_structure<X>>>;
        using Add = typename R::add;
        using Mul = typename R::mul;
        using T = typename Add::T;

      protected:
        constexpr static bool variable_sized = false;
        std::array<T, N * M> m_values;
        members() {
          std::ranges::fill(this->m_values, Add::e());
        }
      };
      template <typename X>
      class members<X, std::numeric_limits<std::size_t>::max(), std::numeric_limits<std::size_t>::max()> {
        using R = std::conditional_t<tools::semiring<X>, X, tools::rings::of<tools::groups::plus<X>, tools::multiplicative_structure<X>>>;
        using Add = typename R::add;
        using Mul = typename R::mul;
        using T = typename Add::T;

      protected:
        constexpr static bool variable_sized = true;
        std::vector<T> m_values;
        int m_rows;
        int m_cols;
        members() = default;
        members(const int rows, const int cols) : m_values(rows * cols, Add::e()), m_rows(rows), m_cols(cols) {
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

  template <typename X, std::size_t N = std::numeric_limits<std::size_t>::max(), std::size_t M = std::numeric_limits<std::size_t>::max()>
  class matrix : tools::detail::matrix::members<X, N, M> {
    template <typename, std::size_t, std::size_t>
    friend class tools::matrix;
    using Mat = tools::matrix<X, N, M>;
    using Base = tools::detail::matrix::members<X, N, M>;
    constexpr static bool variable_sized = Base::variable_sized;

    using R = std::conditional_t<tools::semiring<X>, X, tools::rings::of<tools::groups::plus<X>, tools::multiplicative_structure<X>>>;
    using Add = typename R::add;
    using Mul = typename R::mul;
    using T = typename Add::T;

  public:
    matrix() = default;
    matrix(const int rows, const int cols) requires variable_sized : Base(rows, cols) {}
    matrix(const int rows, const int cols, const T& value) requires variable_sized : Base(rows, cols, value) {}
    matrix(const std::initializer_list<std::initializer_list<T>> il) requires (!variable_sized) {
      assert(il.size() == this->rows());
      assert(std::ranges::all_of(il, [&](const auto& row) { return std::ssize(row) == this->cols(); }));
      for (int r = 0; r < this->rows(); ++r) {
        std::ranges::copy(il.begin()[r], (*this)[r]);
      }
    }
    matrix(const std::initializer_list<std::initializer_list<T>> il) requires variable_sized : Base(il.size(), il.size() ? il.begin()->size() : 0) {
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

    Mat operator+(this auto&& self) {
      return std::forward<decltype(self)>(self);
    }
    Mat operator-(this auto&& self) requires tools::ring<R> {
      return Mat(std::forward<decltype(self)>(self)) *= Add::inv(Mul::e());
    }
    Mat operator+(this auto&& lhs, const Mat& rhs) {
      return Mat(std::forward<decltype(lhs)>(lhs)) += rhs;
    }
    Mat operator-(this auto&& lhs, const Mat& rhs) requires tools::ring<R> {
      return Mat(std::forward<decltype(lhs)>(lhs)) -= rhs;
    }
    template <std::size_t K> requires (!Mat::variable_sized || K == std::numeric_limits<std::size_t>::max())
    friend tools::matrix<X, N, K> operator*(const Mat& lhs, const tools::matrix<X, M, K>& rhs) {
      assert(lhs.cols() == rhs.rows());
      auto result = [&]() {
        if constexpr (Mat::variable_sized) {
          return tools::matrix<X>(lhs.rows(), rhs.cols());
        } else {
          return tools::matrix<X, N, K>{};
        }
      }();
      for (int i = 0; i < lhs.rows(); ++i) {
        for (int k = 0; k < lhs.cols(); ++k) {
          for (int j = 0; j < rhs.cols(); ++j) {
            result[i][j] = Add::op(result[i][j], Mul::op(lhs[i][k], rhs[k][j]));
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
          result[i] = Add::op(result[i], Mul::op(lhs[i][j], rhs[j]));
        }
      }
      return result;
    }
    Mat operator*(this auto&& lhs, const T& rhs) {
      return Mat(std::forward<decltype(lhs)>(lhs)) *= rhs;
    }
    friend Mat operator/(const Mat& lhs, const tools::matrix<X, M, M>& rhs) requires tools::field<R> {
      const auto inv = rhs.inv();
      assert(inv);
      return lhs * *inv;
    }
    Mat operator/(this auto&& lhs, const T& rhs) requires tools::field<R> {
      return Mat(std::forward<decltype(lhs)>(lhs)) /= rhs;
    }
    auto operator+=(this tools::mutable_type auto&& self, const Mat& other) -> decltype(self) {
      assert(self.rows() == other.rows());
      assert(self.cols() == other.cols());
      for (std::size_t i = 0; i < self.m_values.size(); ++i) {
        self.m_values[i] = Add::op(self.m_values[i], other.m_values[i]);
      }
      return std::forward<decltype(self)>(self);
    }
    auto operator-=(this tools::mutable_type auto&& self, const Mat& other) -> decltype(self) requires tools::ring<R> {
      assert(self.rows() == other.rows());
      assert(self.cols() == other.cols());
      for (std::size_t i = 0; i < self.m_values.size(); ++i) {
        self.m_values[i] = Add::op(self.m_values[i], Add::inv(other.m_values[i]));
      }
      return std::forward<decltype(self)>(self);
    }
    auto operator*=(this tools::mutable_type auto&& self, const tools::matrix<X, M, M>& other) -> decltype(self) {
      self = self * other;
      return std::forward<decltype(self)>(self);
    }
    auto operator*=(this tools::mutable_type auto&& self, const T& c) -> decltype(self) {
      for (auto& v : self.m_values) v = Mul::op(v, c);
      return std::forward<decltype(self)>(self);
    }
    auto operator/=(this tools::mutable_type auto&& self, const tools::matrix<T, M, M>& other) -> decltype(self) requires tools::field<R> {
      self = self / other;
      return std::forward<decltype(self)>(self);
    }
    auto operator/=(this tools::mutable_type auto&& self, const T& c) -> decltype(self) requires tools::field<R> {
      self *= Mul::inv(c);
      return std::forward<decltype(self)>(self);
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
    std::pair<int, T> internal_gauss_jordan() requires tools::field<R> {
      int rank = 0;
      auto coeff = Mul::e();

      for (int c = 0; c < this->cols(); ++c) {
        int pivot;
        for (pivot = rank; pivot < this->rows() && (*this)[pivot][c] == Add::e(); ++pivot);
        if (pivot == this->rows()) continue;

        if (pivot != rank) {
          for (int cc = c; cc < this->cols(); ++cc) {
            std::swap((*this)[rank][cc], (*this)[pivot][cc]);
          }
          coeff = Mul::op(coeff, Add::inv(Mul::e()));
        }

        {
          const auto scale_inv = Mul::inv((*this)[rank][c]);
          for (int cc = c; cc < this->cols(); ++cc) {
            (*this)[rank][cc] = Mul::op((*this)[rank][cc], scale_inv);
          }
          coeff = Mul::op(coeff, scale_inv);
        }

        for (int r = 0; r < this->rows(); ++r) {
          if (r == rank) continue;
          const auto scale = (*this)[r][c];
          if (scale == Add::e()) continue;
          for (int cc = c; cc < this->cols(); ++cc) {
            (*this)[r][cc] = Add::op((*this)[r][cc], Add::inv(Mul::op((*this)[rank][cc], scale)));
          }
        }

        ++rank;
      }

      return std::make_pair(rank, coeff);
    }

  public:
    int gauss_jordan() requires tools::field<R> {
      return this->internal_gauss_jordan().first;
    }

    int rank() const requires tools::field<R> {
      return (this->rows() < this->cols() ? this->transposed() : Mat(*this)).gauss_jordan();
    }

    tools::matrix<X> solve(const tools::vector<T, N>& b) const requires tools::field<R> {
      assert(this->rows() == b.size());
      assert(this->cols() >= 1);
      auto Ab = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->rows(), this->cols() + 1);
        } else {
          return tools::matrix<X, N, M + 1>{};
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
        for (; cr < Ab.cols() && (r == Ab.rows() || Ab[r][cr] == Add::e()); ++cr);
        for (int c = cl; c < cr; ++c) {
          ranks[c] = r;
        }
      }

      if (ranks[Ab.cols() - 2] < ranks[Ab.cols() - 1]) {
        return tools::matrix<X>(this->rows(), 0);
      }

      std::vector<tools::vector<T>> answers(this->cols());
      int free = this->cols() - ranks.back() - 1;

      for (int cl = this->cols(), cr = this->cols(); cr > 0; cr = cl) {
        for (; cl > 0 && ranks[cl - 1] == ranks[cr - 1]; --cl);
        for (int c = cr - 1; c > cl; --c) {
          answers[c] = tools::vector<T>(this->cols() - ranks.back() + 1, Add::e());
          answers[c][free] = Mul::e();
          --free;
        }
        if (ranks[cl] > 0) {
          answers[cl] = tools::vector<T>(this->cols() - ranks.back() + 1, Add::e());
          answers[cl][this->cols() - ranks.back()] = Ab[ranks[cl] - 1][Ab.cols() - 1];
          for (int c = cl + 1; c < Ab.cols() - 1; ++c) {
            for (int r = 0; r < std::ssize(answers[cl]); ++r) {
              answers[cl][r] = Add::op(answers[cl][r], Add::inv(Ab[ranks[cl] - 1][c] * answers[c][r]));
            }
          }
        } else {
          answers[cl] = tools::vector<T>(this->cols() - ranks.back() + 1, Add::e());
          answers[cl][free] = Mul::e();
          --free;
        }
      }

      tools::matrix<X> answer(this->cols(), this->cols() - ranks.back() + 1);
      for (int r = 0; r < this->cols(); ++r) {
        for (int c = 0; c < this->cols() - ranks.back() + 1; ++c) {
          answer[r][c] = answers[r][c];
        }
      }

      return answer;
    }

    T determinant() const requires tools::field<R> {
      assert(this->rows() == this->cols());

      auto A = *this;
      const auto [rank, coeff] = A.internal_gauss_jordan();

      return rank == A.rows() ? Mul::inv(coeff) : Add::e();
    }

    static Mat e() requires (!variable_sized && N == M) {
      Mat result{};
      for (int i = 0; i < N; ++i) {
        result[i][i] = Mul::e();
      }
      return result;
    }
    static Mat e(const int n) requires variable_sized {
      assert(n >= 0);
      Mat result(n, n, Add::e());
      for (int i = 0; i < n; ++i) {
        result[i][i] = Mul::e();
      }
      return result;
    }

    std::optional<Mat> inv() const requires (variable_sized || N == M) && tools::field<R> {
      assert(this->rows() == this->cols());

      auto AI = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->rows(), this->cols() * 2);
        } else {
          return tools::matrix<X, N, M * 2>{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          AI[r][c] = (*this)[r][c];
        }
        for (int c = this->cols(); c < AI.cols(); ++c) {
          AI[r][c] = Add::e();
        }
        AI[r][this->cols() + r] = Mul::e();
      }

      AI.internal_gauss_jordan();
      for (int i = 0; i < this->rows(); ++i) {
        if (AI[i][i] != Mul::e()) return std::nullopt;
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

    tools::matrix<X, M, N> transposed() const {
      auto A_T = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->cols(), this->rows());
        } else {
          return tools::matrix<X, M, N>{};
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
