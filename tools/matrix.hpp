#ifndef TOOLS_MATRIX_HPP
#define TOOLS_MATRIX_HPP

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include "tools/vector.hpp"

namespace tools {
  template <typename T>
  class matrix {
  private:
    ::std::vector<T> m_values;
    ::std::size_t m_rows;
    ::std::size_t m_cols;

  public:
    matrix() = default;
    matrix(const ::tools::matrix<T>&) = default;
    matrix(::tools::matrix<T>&&) = default;
    ~matrix() = default;
    ::tools::matrix<T>& operator=(const ::tools::matrix<T>&) = default;
    ::tools::matrix<T>& operator=(::tools::matrix<T>&&) = default;

    matrix(::std::size_t rows, ::std::size_t cols) :
      m_values(rows * cols), m_rows(rows), m_cols(cols) {
    }
    matrix(::std::size_t rows, ::std::size_t cols, const T& value) :
      m_values(rows * cols, value), m_rows(rows), m_cols(cols) {
    }

    T& at(const ::std::size_t y, const ::std::size_t x) {
      return this->m_values[y * this->m_cols + x];
    }
    T at(const ::std::size_t y, const ::std::size_t x) const {
      return this->m_values[y * this->m_cols + x];
    }

    ::std::size_t rows() const {
      return this->m_rows;
    }
    ::std::size_t cols() const {
      return this->m_cols;
    }

    friend ::tools::matrix<T>& operator+(::tools::matrix<T>& self) {
      return self;
    }
    friend const ::tools::matrix<T>& operator+(const ::tools::matrix<T>& self) {
      return self;
    }
    friend ::tools::matrix<T> operator+(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {
      assert(lhs.m_rows == rhs.m_rows);
      assert(lhs.m_cols == rhs.m_cols);
      ::tools::matrix<T> result(lhs);
      for (::std::size_t i = 0; i < lhs.m_values.size(); ++i) {
        result.m_values[i] += rhs.m_values[i];
      }
      return result;
    }
    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>& self) {
      ::tools::matrix<T> result(self);
      for (::std::size_t i = 0; i < self.m_values.size(); ++i) {
        result.m_values[i] *= -1;
      }
      return result;
    }
    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {
      assert(lhs.m_rows == rhs.m_rows);
      assert(lhs.m_cols == rhs.m_cols);
      ::tools::matrix<T> result(lhs);
      for (::std::size_t i = 0; i < lhs.m_values.size(); ++i) {
        result.m_values[i] -= rhs.m_values[i];
      }
      return result;
    }
    friend ::tools::matrix<T> operator*(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {
      assert(lhs.m_cols == rhs.m_rows);
      ::tools::matrix<T> result(lhs.m_rows, rhs.m_cols, 0);
      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {
        for (::std::size_t j = 0; j < rhs.m_cols; ++j) {
          for (::std::size_t k = 0; k < lhs.m_cols; ++k) {
            result.at(i, j) += lhs.at(i, k) * rhs.at(k, j);
          }
        }
      }
      return result;
    }
    friend ::tools::vector<T> operator*(const ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {
      assert(lhs.m_cols == rhs.dim());
      ::tools::vector<T> result(lhs.m_rows, 0);
      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {
        for (::std::size_t j = 0; j < lhs.m_cols; ++j) {
          result.at(i) += lhs.at(i, j) * rhs.at(j);
        }
      }
      return result;
    }

    static ::tools::matrix<T> e(const ::std::size_t n) {
      ::tools::matrix<T> result(n, n);
      ::std::fill(result.m_values.begin(), result.m_values.end(), 0);
      for (::std::size_t i = 0; i < n; ++i) {
        result.at(i, i) = 1;
      }
      return result;
    }
  };
}

#endif
