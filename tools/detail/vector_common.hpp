#ifndef TOOLS_DETAIL_VECTOR_COMMON_HPP
#define TOOLS_DETAIL_VECTOR_COMMON_HPP

#include <type_traits>
#include <cassert>
#include <cstddef>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include "tools/abs.hpp"

#define TOOLS_DETAIL_VECTOR_COMMON(V) \
  private:\
    using F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;\
\
  public:\
    V operator+() const {\
      return *this;\
    }\
\
    V operator-() const {\
      V res = *this;\
      for (auto& v : res) {\
        v = -v;\
      }\
      return res;\
    }\
\
    V& operator+=(const V& other) {\
      assert(this->size() == other.size());\
      for (::std::size_t i = 0; i < this->size(); ++i) {\
        (*this)[i] += other[i];\
      }\
      return *this;\
    }\
    friend V operator+(const V& lhs, const V& rhs) {\
      return V(lhs) += rhs;\
    }\
\
    V& operator-=(const V& other) {\
      assert(this->size() == other.size());\
      for (::std::size_t i = 0; i < this->size(); ++i) {\
        (*this)[i] -= other[i];\
      }\
      return *this;\
    }\
    friend V operator-(const V& lhs, const V& rhs) {\
      return V(lhs) -= rhs;\
    }\
\
    V& operator*=(const T& c) {\
      for (auto& v : *this) {\
        v *= c;\
      }\
      return *this;\
    }\
    friend V operator*(const T& lhs, const V& rhs) {\
      return V(rhs) *= lhs;\
    }\
    friend V operator*(const V& lhs, const T& rhs) {\
      return V(lhs) *= rhs;\
    }\
\
    V& operator/=(const T& c) {\
      for (auto& v : *this) {\
        v /= c;\
      }\
      return *this;\
    }\
    friend V operator/(const V& lhs, const T& rhs) {\
      return V(lhs) /= rhs;\
    }\
\
    friend bool operator==(const V& lhs, const V& rhs) {\
      return ::std::equal(lhs.begin(), lhs.end(), rhs.begin());\
    }\
    friend bool operator!=(const V& lhs, const V& rhs) {\
      return !(lhs == rhs);\
    }\
\
    T inner_product(const V& other) const {\
      assert(this->size() == other.size());\
      T res(0);\
      for (::std::size_t i = 0; i < this->size(); ++i) {\
        res += (*this)[i] * other[i];\
      }\
      return res;\
    }\
\
    T l1_norm() const {\
      T res(0);\
      for (const auto& v : *this) {\
        res += ::tools::abs(v);\
      }\
      return res;\
    }\
\
    T squared_l2_norm() const {\
      return this->inner_product(*this);\
    }\
\
    F l2_norm() const {\
      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));\
    }\
\
    template <typename T_ = T>\
    ::std::enable_if_t<::std::is_floating_point_v<T_>, V> normalized() const {\
      return *this / this->l2_norm();\
    }\
\
    friend ::std::ostream& operator<<(::std::ostream& os, const V& self) {\
      os << '(';\
      ::std::string delimiter = "";\
      for (const auto& v : self) {\
        os << delimiter << v;\
        delimiter = ", ";\
      }\
      return os << ')';\
    }\
\
    friend ::std::istream& operator>>(::std::istream& is, V& self) {\
      for (auto& v : self) {\
        is >> v;\
      }\
      return is;\
    }

#endif
