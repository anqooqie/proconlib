#ifndef TOOLS_MATRIX_MOD2_HPP
#define TOOLS_MATRIX_MOD2_HPP

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <optional>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/dynamic_bitset.hpp"
#include "tools/matrix.hpp"
#include "tools/vector.hpp"

namespace tools {
  namespace detail {
    namespace matrix {
      template <int N, int M>
      class members<::atcoder::static_modint<2>, N, M> {
      protected:
        constexpr static bool variable_sized = false;
        ::std::array<::std::bitset<M>, N> m_values;
        members() : m_values() {}
      };
      template <>
      class members<::atcoder::static_modint<2>, -1, -1> {
      protected:
        constexpr static bool variable_sized = true;
        ::std::vector<::tools::dynamic_bitset> m_values;
        int m_cols;
        members() = default;
        members(const int rows, const int cols) : m_values(rows, ::tools::dynamic_bitset(cols)), m_cols(cols) {}
        members(const int rows, const int cols, const ::atcoder::static_modint<2> value) : m_values(rows, value.val() ? ::tools::dynamic_bitset(cols).set() : ::tools::dynamic_bitset(cols)), m_cols(cols) {}
      };
    }
  }

  template <int N, int M>
  class matrix<::atcoder::static_modint<2>, N, M> : ::tools::detail::matrix::members<::atcoder::static_modint<2>, N, M> {
    template <typename, int, int>
    friend class ::tools::matrix;
    using T = ::atcoder::static_modint<2>;
    using Mat = ::tools::matrix<T, N, M>;
    using Base = ::tools::detail::matrix::members<T, N, M>;
    constexpr static bool variable_sized = Base::variable_sized;

  public:
    class row_refenrece;
    class reference;
    class const_row_reference;
    class row_reference {
      friend Mat;
      friend class const_row_reference;

      using wrapped = typename ::std::conditional_t<variable_sized, ::std::vector<::tools::dynamic_bitset>, ::std::array<::std::bitset<M>, N>>::iterator;
      wrapped m_it;

      explicit row_reference(const wrapped it) : m_it(it) {
      }

    public:
      row_reference() = default;

      reference operator[](const int c) const {
        assert(0 <= c && c < ::std::ssize(*this->m_it));
        return reference((*this->m_it)[c]);
      }
    };
    class reference {
      friend class row_reference;

      using wrapped = typename ::std::conditional_t<variable_sized, ::tools::dynamic_bitset, ::std::bitset<M>>::reference;
      wrapped m_ref;

      explicit reference(const wrapped ref) : m_ref(ref) {
      }

    public:
      reference() = default;
      reference(const reference&) = default;
      reference& operator=(const T x) {
        this->m_ref = x.val();
        return *this;
      }
      reference& operator=(const reference& other) {
        this->m_ref = other.m_ref;
        return *this;
      }
      operator T() const {
        return T::raw(static_cast<bool>(this->m_ref));
      }

      unsigned int val() const {
        return static_cast<bool>(this->m_ref);
      }
      reference& operator++() {
        this->m_ref = !static_cast<bool>(this->m_ref);
        return *this;
      }
      reference& operator--() {
        return ++*this;
      }
      T operator++(int) {
        const T result = *this;
        ++*this;
        return result;
      }
      T operator--(int) {
        return (*this)++;
      }
      reference& operator+=(const T rhs) {
        if (rhs.val()) ++*this;
        return *this;
      }
      reference& operator+=(const reference& rhs) {
        if (rhs.m_ref) ++*this;
        return *this;
      }
      reference& operator-=(const T rhs) {
        return *this += rhs;
      }
      reference& operator-=(const reference& rhs) {
        return *this += rhs;
      }
      reference& operator*=(const T rhs) {
        if (!rhs.val()) this->m_ref = false;
        return *this;
      }
      reference& operator*=(const reference& rhs) {
        if (!rhs.m_ref) this->m_ref = false;
        return *this;
      }
      reference& operator/=(const T rhs) {
        assert(rhs.val());
        return *this;
      }
      reference& operator/=(const reference& rhs) {
        assert(rhs.m_ref);
        return *this;
      }
      T operator+() const {
        return *this;
      }
      T operator-() const {
        return *this;
      }
      T pow(const long long n) const {
        assert(0 <= n);
        return *this;
      }
      T inv() const {
        assert(this->m_ref);
        return *this;
      }
      friend T operator+(const reference& lhs, const reference& rhs) {
        return static_cast<T>(lhs) += rhs;
      }
      friend T operator+(const T lhs, const reference& rhs) {
        return T(lhs) += rhs;
      }
      friend T operator+(const reference& lhs, const T rhs) {
        return static_cast<T>(lhs) += rhs;
      }
      friend T operator-(const reference& lhs, const reference& rhs) {
        return static_cast<T>(lhs) -= rhs;
      }
      friend T operator-(const T lhs, const reference& rhs) {
        return T(lhs) -= rhs;
      }
      friend T operator-(const reference& lhs, const T rhs) {
        return static_cast<T>(lhs) -= rhs;
      }
      friend T operator*(const reference& lhs, const reference& rhs) {
        return static_cast<T>(lhs) *= rhs;
      }
      friend T operator*(const T lhs, const reference& rhs) {
        return T(lhs) *= rhs;
      }
      friend T operator*(const reference& lhs, const T rhs) {
        return static_cast<T>(lhs) *= rhs;
      }
      friend T operator/(const reference& lhs, const reference& rhs) {
        return static_cast<T>(lhs) /= rhs;
      }
      friend T operator/(const T lhs, const reference& rhs) {
        return T(lhs) /= rhs;
      }
      friend T operator/(const reference& lhs, const T rhs) {
        return static_cast<T>(lhs) /= rhs;
      }
      friend bool operator==(const reference& lhs, const reference& rhs) {
        return static_cast<bool>(lhs.m_ref) == static_cast<bool>(rhs.m_ref);
      }
      friend bool operator==(const T lhs, const reference& rhs) {
        return lhs.val() == static_cast<bool>(rhs.m_ref);
      }
      friend bool operator==(const reference& lhs, const T rhs) {
        return static_cast<bool>(lhs.m_ref) == rhs.val();
      }
      friend bool operator!=(const reference& lhs, const reference& rhs) {
        return static_cast<bool>(lhs.m_ref) != static_cast<bool>(rhs.m_ref);
      }
      friend bool operator!=(const T lhs, const reference& rhs) {
        return lhs.val() != static_cast<bool>(rhs.m_ref);
      }
      friend bool operator!=(const reference& lhs, const T rhs) {
        return static_cast<bool>(lhs.m_ref) != rhs.val();
      }
    };
    class const_row_reference {
      friend Mat;

      using wrapped = typename ::std::conditional_t<variable_sized, ::std::vector<::tools::dynamic_bitset>, ::std::array<::std::bitset<M>, N>>::const_iterator;
      wrapped m_it;

      explicit const_row_reference(const wrapped it) : m_it(it) {
      }

    public:
      const_row_reference() = default;
      const_row_reference(const row_reference ref) : m_it(ref.m_it) {
      }

      T operator[](const int c) const {
        assert(0 <= c && c < ::std::ssize(*this->m_it));
        return T::raw(this->m_it->test(c));
      }
    };

    matrix() = default;
    template <bool SFINAE = variable_sized> requires (SFINAE)
    matrix(const int rows, const int cols) : Base(rows, cols) {}
    template <bool SFINAE = variable_sized> requires (SFINAE)
    matrix(const int rows, const int cols, const T value) : Base(rows, cols, value) {}
    template <bool SFINAE = !variable_sized> requires (SFINAE)
    matrix(const ::std::initializer_list<::std::initializer_list<T>> il) {
      assert(il.size() == this->rows());
      assert(::std::ranges::all_of(il, [&](const auto& row) { return ::std::ssize(row) == this->cols(); }));
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          if (il.begin()[r].begin()[c].val()) {
            this->m_values[r].set(c);
          }
        }
      }
    }
    template <bool SFINAE = variable_sized, ::std::nullptr_t = nullptr> requires (SFINAE)
    matrix(const ::std::initializer_list<::std::initializer_list<T>> il) : Base(il.size(), il.size() ? il.begin()->size() : 0) {
      assert(::std::ranges::all_of(il, [&](const auto& row) { return ::std::ssize(row) == this->cols(); }));
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          if (il.begin()[r].begin()[c].val()) {
            this->m_values[r].set(c);
          }
        }
      }
    }
    row_reference operator[](const int r) {
      assert(0 <= r && r < this->rows());
      return row_reference(this->m_values.begin() + r);
    }
    const_row_reference operator[](const int r) const {
      assert(0 <= r && r < this->rows());
      return const_row_reference(this->m_values.begin() + r);
    }

    int rows() const {
      if constexpr (variable_sized) {
        return this->m_values.size();
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
      return *this;
    }
    friend Mat operator+(const Mat& lhs, const Mat& rhs) {
      return Mat(lhs) += rhs;
    }
    friend Mat operator-(const Mat& lhs, const Mat& rhs) {
      return Mat(lhs) -= rhs;
    }
    template <int K> requires (!Mat::variable_sized || K == -1)
    friend ::tools::matrix<T, N, K> operator*(const Mat& lhs, const ::tools::matrix<T, M, K>& rhs) {
      assert(lhs.cols() == rhs.rows());

      const auto transposed = rhs.transposed();

      auto result = [&]() {
        if constexpr (Mat::variable_sized) {
          return ::tools::matrix<T>(lhs.rows(), rhs.cols());
        } else {
          return ::tools::matrix<T, N, K>{};
        }
      }();
      for (int i = 0; i < lhs.rows(); ++i) {
        for (int j = 0; j < rhs.cols(); ++j) {
          if ((lhs.m_values[i] & transposed.m_values[j]).count() % 2) {
            result.m_values[i].set(j);
          }
        }
      }
      return result;
    }
    friend ::tools::vector<T, N> operator*(const Mat& lhs, const ::tools::vector<T, M>& rhs) {
      assert(lhs.cols() == rhs.size());

      auto bitset = [&]() {
        if constexpr (Mat::variable_sized) {
          return ::tools::dynamic_bitset(lhs.cols());
        } else {
          return ::std::bitset<M>{};
        }
      }();
      for (int i = 0; i < ::std::ssize(rhs); ++i) {
        if (rhs[i].val()) {
          bitset.set(i);
        }
      }

      auto result = [&]() {
        if constexpr (Mat::variable_sized) {
          return ::tools::vector<T>(lhs.rows());
        } else {
          return ::tools::vector<T, N>{};
        }
      }();
      for (int i = 0; i < lhs.rows(); ++i) {
        result[i] = T::raw((lhs[i] & bitset).count() % 2);
      }
      return result;
    }
    friend Mat operator*(const Mat& lhs, const T& rhs) {
      return Mat(lhs) *= rhs;
    }
    friend Mat operator/(const Mat& lhs, const ::tools::matrix<T, M, M>& rhs) {
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
      for (int r = 0; r < this->rows(); ++r) {
        this->m_values[r] ^= other.m_values[r];
      }
      return *this;
    }
    Mat& operator-=(const Mat& other) {
      return *this += other;
    }
    Mat& operator*=(const ::tools::matrix<T, M, M>& other) {
      return *this = *this * other;
    }
    Mat& operator*=(const T c) {
      if (c.val() == 0) {
        for (auto& row : this->m_values) {
          row.reset();
        }
      }
      return *this;
    }
    Mat& operator/=(const ::tools::matrix<T, M, M>& other) {
      return *this = *this / other;
    }
    Mat& operator/=(const T c) {
      assert(c.val());
      return *this;
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

    friend ::std::istream& operator>>(::std::istream& is, Mat& self) {
      for (int r = 0; r < self.rows(); ++r) {
        for (int c = 0; c < self.cols(); ++c) {
          char v;
          do {
            is >> v;
            assert(is);
          } while (!(v == '0' || v == '1'));
          self.m_values[r].set(c, v - '0');
        }
      }
      return is;
    }
    friend ::std::ostream& operator<<(::std::ostream& os, const Mat& self) {
      for (int r = 0; r < self.rows(); ++r) {
        os << '[';
        for (int c = 0; c < self.cols(); ++c) {
          os << ('0' + self.m_values[r].test(c)) << ::std::array<::std::string_view, 2>{", ", ""}[c == self.cols() - 1];
        }
        os << ']' << '\n';
      }
      return os;
    }

    int gauss_jordan() {
      int rank = 0;

      for (int c = 0; c < this->cols(); ++c) {
        int pivot;
        for (pivot = rank; pivot < this->rows() && !this->m_values[pivot].test(c); ++pivot);
        if (pivot == this->rows()) continue;

        if (pivot != rank) {
          ::std::swap(this->m_values[rank], this->m_values[pivot]);
        }

        for (int r = 0; r < this->rows(); ++r) {
          if (r == rank) continue;
          if (!this->m_values[r].test(c)) continue;
          this->m_values[r] ^= this->m_values[rank];
        }

        ++rank;
      }

      return rank;
    }

    int rank() const {
      return (this->rows() < this->cols() ? this->transposed() : Mat(*this)).gauss_jordan();
    }

    ::tools::matrix<T> solve(const ::tools::vector<T, N>& b) const {
      assert(this->rows() == ::std::ssize(b));
      assert(this->cols() >= 1);
      auto Ab = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->rows(), this->cols() + 1);
        } else {
          return ::tools::matrix<T, N, M + 1>{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          if (this->m_values[r].test(c)) {
            Ab.m_values[r].set(c);
          }
        }
        if (b[r].val()) {
          Ab.m_values[r].set(this->cols());
        }
      }

      Ab.gauss_jordan();

      ::std::vector<int> ranks(Ab.cols());
      for (int r = 0, cl = 0, cr = 0; r <= Ab.rows(); ++r, cl = cr) {
        for (; cr < Ab.cols() && (r == Ab.rows() || !Ab.m_values[r].test(cr)); ++cr);
        for (int c = cl; c < cr; ++c) {
          ranks[c] = r;
        }
      }

      if (ranks[Ab.cols() - 2] < ranks[Ab.cols() - 1]) {
        return ::tools::matrix<T>(this->rows(), 0);
      }

      ::tools::matrix<T> answer(this->cols(), this->cols() - ranks.back() + 1);
      int free = this->cols() - ranks.back() - 1;

      for (int l = this->cols(), r = this->cols(); r > 0; r = l) {
        for (; l > 0 && ranks[l - 1] == ranks[r - 1]; --l);
        for (int c = r - 1; c > l; --c) {
          answer.m_values[c].set(free);
          --free;
        }
        if (ranks[l] > 0) {
          answer.m_values[l].set(this->cols() - ranks.back(), Ab.m_values[ranks[l] - 1].test(Ab.cols() - 1));
          for (int c = l + 1; c < Ab.cols() - 1; ++c) {
            if (Ab.m_values[ranks[l] - 1].test(c)) {
              answer.m_values[l] ^= answer.m_values[c];
            }
          }
        } else {
          answer.m_values[l].set(free);
          --free;
        }
      }

      return answer;
    }

    T determinant() const {
      assert(this->rows() == this->cols());

      auto A = *this;
      const auto rank = A.gauss_jordan();

      return T::raw(rank == A.rows());
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
      Mat result(n, n);
      for (int i = 0; i < n; ++i) {
        result[i][i] = T::raw(1);
      }
      return result;
    }

    template <bool SFINAE = variable_sized || N == M> requires (SFINAE)
    ::std::optional<Mat> inv() const {
      assert(this->rows() == this->cols());

      auto AI = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->rows(), this->cols() * 2);
        } else {
          return ::tools::matrix<T, N, M * 2>{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          if (this->m_values[r].test(c)) {
            AI.m_values[r].set(c);
          }
        }
        AI.m_values[r].set(this->cols() + r);
      }

      AI.gauss_jordan();
      for (int i = 0; i < this->rows(); ++i) {
        if (!AI.m_values[i].test(i)) return ::std::nullopt;
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
          if (AI.m_values[r].test(this->cols() + c)) {
            B.m_values[r].set(c);
          }
        }
      }
      return B;
    }

    ::tools::matrix<T, M, N> transposed() const {
      auto A_T = [&]() {
        if constexpr (variable_sized) {
          return Mat(this->cols(), this->rows());
        } else {
          return ::tools::matrix<T, M, N>{};
        }
      }();
      for (int r = 0; r < this->rows(); ++r) {
        for (int c = 0; c < this->cols(); ++c) {
          if (this->m_values[r].test(c)) {
            A_T.m_values[c].set(r);
          }
        }
      }
      return A_T;
    }
  };
}

#endif
