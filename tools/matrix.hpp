#ifndef TOOLS_MATRIX_HPP
#define TOOLS_MATRIX_HPP

#include <vector>
#include <cstddef>
#include <cassert>
#include <iostream>
#include <string>
#include <cstdint>
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

    typename ::std::vector<T>::iterator operator[](const ::std::size_t r) {
      return this->m_values.begin() + r * this->m_cols;
    }
    typename ::std::vector<T>::const_iterator operator[](const ::std::size_t r) const {
      return this->m_values.begin() + r * this->m_cols;
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
      return ::tools::matrix<T>(lhs) += rhs;
    }
    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>& self) {
      return ::tools::matrix<T>(self) *= T(-1);
    }
    friend ::tools::matrix<T> operator-(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {
      return ::tools::matrix<T>(lhs) - rhs;
    }
    friend ::tools::matrix<T> operator*(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {
      assert(lhs.m_cols == rhs.m_rows);
      ::tools::matrix<T> result(lhs.m_rows, rhs.m_cols, T(0));
      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {
        for (::std::size_t k = 0; k < lhs.m_cols; ++k) {
          for (::std::size_t j = 0; j < rhs.m_cols; ++j) {
            result[i][j] += lhs[i][k] * rhs[k][j];
          }
        }
      }
      return result;
    }
    friend ::tools::vector<T> operator*(const ::tools::matrix<T>& lhs, const ::tools::vector<T>& rhs) {
      assert(lhs.m_cols == rhs.dim());
      ::tools::vector<T> result(lhs.m_rows, T(0));
      for (::std::size_t i = 0; i < lhs.m_rows; ++i) {
        for (::std::size_t j = 0; j < lhs.m_cols; ++j) {
          result[i] += lhs[i][j] * rhs[j];
        }
      }
      return result;
    }
    friend ::tools::matrix<T> operator*(const ::tools::matrix<T>& lhs, const T& rhs) {
      return ::tools::matrix<T>(lhs) * rhs;
    }
    friend ::tools::matrix<T> operator/(const ::tools::matrix<T>& lhs, const T& rhs) {
      return ::tools::matrix<T>(lhs) / rhs;
    }
    ::tools::matrix<T> operator+=(const ::tools::matrix<T>& other) {
      assert(this->m_rows == other.m_rows);
      assert(this->m_cols == other.m_cols);
      for (::std::size_t i = 0; i < this->m_values.size(); ++i) {
        this->m_values[i] += other.m_values[i];
      }
      return *this;
    }
    ::tools::matrix<T> operator-=(const ::tools::matrix<T>& other) {
      assert(this->m_rows == other.m_rows);
      assert(this->m_cols == other.m_cols);
      for (::std::size_t i = 0; i < this->m_values.size(); ++i) {
        this->m_values[i] -= other.m_values[i];
      }
      return *this;
    }
    ::tools::matrix<T> operator*=(const ::tools::matrix<T>& other) {
      return *this = *this * other;
    }
    ::tools::matrix<T> operator*=(const T& c) {
      for (::std::size_t i = 0; i < this->m_values.size(); ++i) {
        this->m_values[i] *= c;
      }
      return *this;
    }
    ::tools::matrix<T> operator/=(const T& c) {
      const T c_inv = T(1) / c;
      for (::std::size_t i = 0; i < this->m_values.size(); ++i) {
        this->m_values[i] *= c_inv;
      }
      return *this;
    }
    friend bool operator==(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {
      return lhs.m_cols == rhs.m_cols && lhs.m_rows == rhs.m_rows && lhs.m_values == rhs.m_values;
    }
    friend bool operator!=(const ::tools::matrix<T>& lhs, const ::tools::matrix<T>& rhs) {
      return !(lhs == rhs);
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::matrix<T>& self) {
      for (::std::size_t r = 0; r < self.m_rows; ++r) {
        os << '[';
        ::std::string delimiter = "";
        for (::std::size_t c = 0; c < self.m_cols; ++c) {
          os << delimiter << self[r][c];
          delimiter = ", ";
        }
        os << ']' << '\n';
      }
      return os;
    }
    friend ::std::istream& operator>>(::std::istream& is, ::tools::matrix<T>& self) {
      for (T& value : self.m_values) {
        is >> value;
      }
      return is;
    }

    ::std::int_fast64_t gauss_jordan() {
      ::std::size_t rank = 0;
      for (::std::size_t c = 0; c < this->m_cols; ++c) {
        ::std::size_t pivot;
        for (pivot = rank; pivot < this->m_rows && (*this)[pivot][c] == T(0); ++pivot);
        if (pivot == this->m_rows) continue;

        if (pivot != rank) {
          for (::std::size_t cc = c; cc < this->m_cols; ++cc) {
            ::std::swap((*this)[rank][cc], (*this)[pivot][cc]);
          }
        }

        {
          const T scale_inv = T(1) / (*this)[rank][c];
          for (::std::size_t cc = c; cc < this->m_cols; ++cc) {
            (*this)[rank][cc] *= scale_inv;
          }
        }

        for (::std::size_t r = rank + 1; r < this->m_rows; ++r) {
          const T scale = (*this)[r][c];
          for (::std::size_t cc = c; cc < this->m_cols; ++cc) {
            (*this)[r][cc] -= (*this)[rank][cc] * scale;
          }
        }

        ++rank;
      }
      return rank;
    }

    ::tools::matrix<T> solve(const ::tools::vector<T>& b) const {
      assert(this->m_rows == b.dim());
      assert(this->m_cols >= 1);
      ::tools::matrix<T> Ab(this->m_rows, this->m_cols + 1);
      for (::std::size_t r = 0; r < this->m_rows; ++r) {
        for (::std::size_t c = 0; c < this->m_cols; ++c) {
          Ab[r][c] = (*this)[r][c];
        }
        Ab[r][this->m_cols] = b[r];
      }

      Ab.gauss_jordan();

      ::std::vector<::std::size_t> ranks(Ab.cols());
      for (::std::size_t r = 0, cl = 0, cr = 0; r <= Ab.rows(); ++r, cl = cr) {
        for (; cr < Ab.cols() && (r == Ab.rows() || Ab[r][cr] == T(0)); ++cr);
        for (::std::size_t c = cl; c < cr; ++c) {
          ranks[c] = r;
        }
      }

      if (ranks[Ab.cols() - 2] < ranks[Ab.cols() - 1]) {
        return ::tools::matrix<T>(this->m_rows, 0);
      }

      ::std::vector<::tools::vector<T>> answers(this->m_cols);
      ::std::size_t free = this->m_cols - ranks.back() - 1;

      for (::std::size_t l = this->m_cols, r = this->m_cols; r > 0; r = l) {
        for (; l > 0 && ranks[l - 1] == ranks[r - 1]; --l);
        for (::std::size_t c = r - 1; c > l; --c) {
          answers[c] = tools::vector<T>(this->m_cols - ranks.back() + 1, T(0));
          answers[c][free] = T(1);
          --free;
        }
        if (ranks[l] > 0) {
          answers[l] = ::tools::vector<T>(this->m_cols - ranks.back() + 1, T(0));
          answers[l][this->m_cols - ranks.back()] = Ab[ranks[l] - 1][Ab.cols() - 1];
          for (::std::size_t c = l + 1; c < Ab.cols() - 1; ++c) {
            answers[l] -= Ab[ranks[l] - 1][c] * answers[c];
          }
        } else {
          answers[l] = ::tools::vector<T>(this->m_cols - ranks.back() + 1, T(0));
          answers[l][free] = T(1);
          --free;
        }
      }

      ::tools::matrix<T> answer(this->m_cols, this->m_cols - ranks.back() + 1);
      for (::std::size_t r = 0; r < this->m_cols; ++r) {
        for (::std::size_t c = 0; c < this->m_cols - ranks.back() + 1; ++c) {
          answer[r][c] = answers[r][c];
        }
      }

      return answer;
    }

    static ::tools::matrix<T> e(const ::std::size_t n) {
      assert(n >= 0);
      ::tools::matrix<T> result(n, n, T(0));
      for (::std::size_t i = 0; i < n; ++i) {
        result[i][i] = 1;
      }
      return result;
    }
  };
}

#endif
