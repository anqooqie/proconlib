#ifndef TOOLS_VECTOR_HPP
#define TOOLS_VECTOR_HPP

#include <type_traits>
#include <vector>
#include <cstddef>
#include <cmath>
#include <cassert>
#include <iostream>
#include <string>
#include "tools/abs.hpp"

namespace tools {
  template <typename T>
  class vector {
  private:
    using F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;
    ::std::vector<T> m_values;

  public:
    vector() = default;
    vector(const ::tools::vector<T>&) = default;
    vector(::tools::vector<T>&&) = default;
    ~vector() = default;
    ::tools::vector<T>& operator=(const ::tools::vector<T>&) = default;
    ::tools::vector<T>& operator=(::tools::vector<T>&&) = default;

    vector(::std::size_t dim) : m_values(dim) {
    }
    vector(::std::size_t dim, const T& value) : m_values(dim, value) {
    }

    T& operator[](const ::std::size_t i) {
      return this->m_values[i];
    }
    T operator[](const ::std::size_t i) const {
      return this->m_values[i];
    }

    ::std::size_t dim() const {
      return this->m_values.size();
    }

    T l1_norm() const {
      return ::std::accumulate(this->m_values.begin(), this->m_values.end(), T(0), [](const T& sum, const T& v) { return sum + ::tools::abs(v); });
    }
    F l2_norm() const {
      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));
    }
    T squared_l2_norm() const {
      return this->inner_product(*this);
    }
    template <typename SFINAE = T, ::std::enable_if_t<::std::is_floating_point_v<SFINAE>, ::std::nullptr_t> = nullptr>
    ::tools::vector<T> normalized() const {
      return *this / this->l2_norm();
    }

    T inner_product(const ::tools::vector<T>& other) const {
      assert(this->dim() == other.dim());
      T result(0);
      for (::std::size_t i = 0; i < this->dim(); ++i) {
        result += this->m_values[i] * other.m_values[i];
      }
      return result;
    }

    friend ::tools::vector<T>& operator+(::tools::vector<T>& self) {
      return self;
    }
    friend const ::tools::vector<T>& operator+(const ::tools::vector<T>& self) {
      return self;
    }
    friend ::tools::vector<T> operator+(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      return ::tools::vector<T>(lhs) += rhs;
    }
    friend ::tools::vector<T> operator-(const ::tools::vector<T>& self) {
      return ::tools::vector<T>(self) *= T(-1);
    }
    friend ::tools::vector<T> operator-(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      return ::tools::vector<T>(lhs) -= rhs;
    }
    friend ::tools::vector<T> operator*(const ::tools::vector<T>& lhs, const T& rhs) {
      return ::tools::vector<T>(lhs) *= rhs;
    }
    friend ::tools::vector<T> operator*(const T& lhs, const ::tools::vector<T>& rhs) {
      return ::tools::vector<T>(rhs) *= lhs;
    }
    friend ::tools::vector<T> operator/(const ::tools::vector<T>& lhs, const T& rhs) {
      return ::tools::vector<T>(lhs) /= rhs;
    }
    ::tools::vector<T>& operator+=(const ::tools::vector<T>& other) {
      assert(this->dim() == other.dim());
      for (::std::size_t i = 0; i < this->dim(); ++i) {
        this->m_values[i] += other.m_values[i];
      }
      return *this;
    }
    ::tools::vector<T>& operator-=(const ::tools::vector<T>& other) {
      assert(this->dim() == other.dim());
      for (::std::size_t i = 0; i < this->dim(); ++i) {
        this->m_values[i] -= other.m_values[i];
      }
      return *this;
    }
    ::tools::vector<T>& operator*=(const T& c) {
      for (::std::size_t i = 0; i < this->dim(); ++i) {
        this->m_values[i] *= c;
      }
      return *this;
    }
    ::tools::vector<T>& operator/=(const T& c) {
      const T c_inv = T(1) / c;
      for (::std::size_t i = 0; i < this->dim(); ++i) {
        this->m_values[i] *= c_inv;
      }
      return *this;
    }
    friend bool operator==(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      if (lhs.dim() != rhs.dim()) {
        return false;
      }
      for (::std::size_t i = 0; i < lhs.dim(); ++i) {
        if (lhs.m_values[i] != rhs.m_values[i]) {
          return false;
        }
      }
      return true;
    }
    friend bool operator!=(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      return !(lhs == rhs);
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::vector<T>& self) {
      os << '(';
      ::std::string delimiter = "";
      for (const T& value : self.m_values) {
        os << delimiter << value;
        delimiter = ", ";
      }
      return os << ')';
    }
    friend ::std::istream& operator>>(::std::istream& is, ::tools::vector<T>& self) {
      for (T& value : self.m_values) {
        is >> value;
      }
      return is;
    }
  };
}

#endif
