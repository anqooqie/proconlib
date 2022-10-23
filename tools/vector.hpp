#ifndef TOOLS_VECTOR_HPP
#define TOOLS_VECTOR_HPP

#include <vector>
#include <type_traits>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cassert>
#include <cstddef>
#include <cmath>
#include <iostream>
#include <string>
#include "tools/abs.hpp"

namespace tools {
  template <typename T>
  class vector : public ::std::vector<T> {
  private:
    using F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;

  public:
    using ::std::vector<T>::vector;
    using ::std::vector<T>::operator=;

    ::tools::vector<T> operator+() const {
      return *this;
    }

    ::tools::vector<T> operator-() const {
      ::tools::vector<T> res;
      res.reserve(this->size());
      ::std::transform(this->begin(), this->end(), ::std::back_inserter(res), ::std::negate<T>());
      return res;
    }

    ::tools::vector<T>& operator+=(const ::tools::vector<T>& other) {
      assert(this->size() == other.size());
      for (::std::size_t i = 0; i < this->size(); ++i) {
        (*this)[i] += other[i];
      }
      return *this;
    }
    friend ::tools::vector<T> operator+(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      return ::tools::vector<T>(lhs) += rhs;
    }

    ::tools::vector<T>& operator-=(const ::tools::vector<T>& other) {
      assert(this->size() == other.size());
      for (::std::size_t i = 0; i < this->size(); ++i) {
        (*this)[i] -= other[i];
      }
      return *this;
    }
    friend ::tools::vector<T> operator-(const ::tools::vector<T>& lhs, const ::tools::vector<T>& rhs) {
      return ::tools::vector<T>(lhs) -= rhs;
    }

    ::tools::vector<T>& operator*=(const T& c) {
      for (auto& v : *this) v *= c;
      return *this;
    }
    friend ::tools::vector<T> operator*(const T& lhs, const ::tools::vector<T>& rhs) {
      return ::tools::vector<T>(rhs) *= lhs;
    }
    friend ::tools::vector<T> operator*(const ::tools::vector<T>& lhs, const T& rhs) {
      return ::tools::vector<T>(lhs) *= rhs;
    }

    ::tools::vector<T>& operator/=(const T& c) {
      for (auto& v : *this) v /= c;
      return *this;
    }
    friend ::tools::vector<T> operator/(const ::tools::vector<T>& lhs, const T& rhs) {
      return ::tools::vector<T>(lhs) /= rhs;
    }

    T inner_product(const ::tools::vector<T>& other) const {
      assert(this->size() == other.size());
      T result(0);
      for (::std::size_t i = 0; i < this->size(); ++i) {
        result += (*this)[i] * other[i];
      }
      return result;
    }

    T l1_norm() const {
      return ::std::accumulate(this->begin(), this->end(), T(0), [](const T& sum, const T& v) { return sum + ::tools::abs(v); });
    }

    F l2_norm() const {
      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));
    }

    T squared_l2_norm() const {
      return this->inner_product(*this);
    }

    template <typename T_ = T>
    ::std::enable_if_t<::std::is_floating_point_v<T_>, ::tools::vector<T_>> normalized() const {
      return *this / this->l2_norm();
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::vector<T>& self) {
      os << '(';
      ::std::string delimiter = "";
      for (const auto& v : self) {
        os << delimiter << v;
        delimiter = ", ";
      }
      return os << ')';
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::vector<T>& self) {
      for (auto& v : self) is >> v;
      return is;
    }
  };
}

#endif
