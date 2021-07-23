#ifndef TOOLS_VECTOR2_HPP
#define TOOLS_VECTOR2_HPP

#include <cmath>
#include <type_traits>
#include <cstddef>
#include <array>
#include <string>
#include <functional>
#include <limits>
#include <iostream>
#include "tools/pair_hash.hpp"

namespace tools {

  template <typename T>
  class vector2 {
  public:
    T x;
    T y;

    vector2() :
      vector2(T(), T()) {
    }

    vector2(const T& x, const T& y) :
      x(x),
      y(y) {
    }

    double norm() const {
      return ::std::sqrt(static_cast<double>(this->squared_norm()));
    }

    T squared_norm() const {
      return this->inner_product(*this);
    }

    template <typename SFINAE_T = T, typename ::std::enable_if<::std::is_same<SFINAE_T, double>::value, ::std::nullptr_t>::type = nullptr>
    ::tools::vector2<double> normalized() const {
      return *this / this->norm();
    }

    ::tools::vector2<T> operator+() const {
      return *this;
    }

    ::tools::vector2<T> operator-() const {
      return ::tools::vector2<T>(-this->x, -this->y);
    }

    friend ::tools::vector2<T> operator+(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return ::tools::vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    friend ::tools::vector2<T> operator-(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return ::tools::vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::vector2<T> operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs) {
      return ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);
    }
    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::vector2<T> operator*(const OTHER& lhs, const ::tools::vector2<T>& rhs) {
      return ::tools::vector2<T>(lhs * rhs.x, lhs * rhs.y);
    }

    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::vector2<T> operator/(const ::tools::vector2<T>& lhs, const OTHER& rhs) {
      return ::tools::vector2<T>(lhs.x / rhs, lhs.y / rhs);
    }

    T inner_product(const ::tools::vector2<T>& other) const {
      return this->x * other.x + this->y * other.y;
    }

    T outer_product(const ::tools::vector2<T>& other) const {
      return this->x * other.y - this->y * other.x;
    }

    ::tools::vector2<T>& operator+=(const ::tools::vector2<T>& other) {
      return *this = *this + other;
    }

    ::tools::vector2<T>& operator-=(const ::tools::vector2<T>& other) {
      return *this = *this - other;
    }

    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>
    ::tools::vector2<T>& operator*=(const OTHER& other) {
      return *this = *this * other;
    }

    template <typename OTHER, typename ::std::enable_if<!::std::is_same<OTHER, ::tools::vector2<T>>::value, ::std::nullptr_t>::type = nullptr>
    ::tools::vector2<T>& operator/=(const OTHER& other) {
      return *this = *this / other;
    }

    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    friend bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return lhs.x != rhs.x || lhs.y != rhs.y;
    }

    static ::std::array<::tools::vector2<T>, 4> four_directions() {
      return ::std::array<::tools::vector2<T>, 4>({
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1))
      });
    }

    static ::std::array<::tools::vector2<T>, 8> eight_directions() {
      return ::std::array<::tools::vector2<T>, 8>({
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(-1)),
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(1)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(-1)),
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(1))
      });
    }
  };
}

namespace std {
  template <typename T>
  ::std::string to_string(const ::tools::vector2<T>& f) {
    return '(' + ::std::to_string(f.x) + ", " + ::std::to_string(f.y) + ')';
  }

  template <typename T>
  struct hash<::tools::vector2<T>> {
    using result_type = ::std::size_t;
    using argument_type = ::tools::vector2<T>;
    ::std::size_t operator()(const ::tools::vector2<T>& key) const {
      static const ::tools::pair_hash<T, T> hasher = ::tools::pair_hash<T, T>();
      return hasher(key.x, key.y);
    }
  };

  template <typename T>
  ::std::ostream& operator<<(::std::ostream& os, const ::tools::vector2<T>& self) {
    return os << ::std::to_string(self);
  }

  template <typename T>
  ::std::istream& operator>>(::std::istream& is, ::tools::vector2<T>& self) {
    return is >> self.x >> self.y;
  }
}

#endif
