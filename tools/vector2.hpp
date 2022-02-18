#ifndef TOOLS_VECTOR2_HPP
#define TOOLS_VECTOR2_HPP

#include <cmath>
#include <type_traits>
#include <cstddef>
#include <array>
#include <iostream>
#include <functional>
#include "tools/pair_hash.hpp"

namespace tools {

  template <typename T>
  class vector2 {
  private:
    using F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;

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

    F norm() const {
      return ::std::sqrt(static_cast<F>(this->squared_norm()));
    }

    T squared_norm() const {
      return this->inner_product(*this);
    }

    template <typename SFINAE = T, ::std::enable_if_t<::std::is_floating_point_v<SFINAE>, ::std::nullptr_t> = nullptr>
    ::tools::vector2<T> normalized() const {
      return *this / this->norm();
    }

    ::tools::vector2<T> turn90() const {
      return ::tools::vector2<T>(-this->y, this->x);
    }

    ::tools::vector2<T> turn270() const {
      return ::tools::vector2<T>(this->y, -this->x);
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

    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>
    friend ::tools::vector2<T> operator*(const ::tools::vector2<T>& lhs, const OTHER& rhs) {
      return ::tools::vector2<T>(lhs.x * rhs, lhs.y * rhs);
    }
    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>
    friend ::tools::vector2<T> operator*(const OTHER& lhs, const ::tools::vector2<T>& rhs) {
      return ::tools::vector2<T>(lhs * rhs.x, lhs * rhs.y);
    }

    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>
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

    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>
    ::tools::vector2<T>& operator*=(const OTHER& other) {
      return *this = *this * other;
    }

    template <typename OTHER, ::std::enable_if_t<!::std::is_same_v<OTHER, ::tools::vector2<T>>, ::std::nullptr_t> = nullptr>
    ::tools::vector2<T>& operator/=(const OTHER& other) {
      return *this = *this / other;
    }

    friend bool operator==(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    friend bool operator!=(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return lhs.x != rhs.x || lhs.y != rhs.y;
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::vector2<T>& self) {
      return os << '(' << self.x << ", " << self.y << ')';
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::vector2<T>& self) {
      return is >> self.x >> self.y;
    }

    static ::std::array<::tools::vector2<T>, 4> four_directions() {
      return ::std::array<::tools::vector2<T>, 4>({
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1)),
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1))
      });
    }

    static ::std::array<::tools::vector2<T>, 8> eight_directions() {
      return ::std::array<::tools::vector2<T>, 8>({
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(1)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(1)),
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(1)),
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(0)),
        ::tools::vector2<T>(static_cast<T>(-1), static_cast<T>(-1)),
        ::tools::vector2<T>(static_cast<T>(0), static_cast<T>(-1)),
        ::tools::vector2<T>(static_cast<T>(1), static_cast<T>(-1))
      });
    }
  };
}

namespace std {
  template <typename T>
  struct hash<::tools::vector2<T>> {
    using result_type = ::std::size_t;
    using argument_type = ::tools::vector2<T>;
    ::std::size_t operator()(const ::tools::vector2<T>& key) const {
      static const ::tools::pair_hash<T, T> hasher = ::tools::pair_hash<T, T>();
      return hasher(::std::make_pair(key.x, key.y));
    }
  };
}

#endif
