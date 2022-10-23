#ifndef TOOLS_VECTOR2_HPP
#define TOOLS_VECTOR2_HPP

#include <array>
#include <type_traits>
#include <utility>
#include <cmath>
#include <iostream>
#include <cstddef>
#include <functional>
#include "tools/abs.hpp"
#include "tools/pair_hash.hpp"

namespace tools {
  template <typename T>
  class vector2 : public ::std::array<T, 2> {
  private:
    using F = ::std::conditional_t<::std::is_floating_point_v<T>, T, double>;

  public:
    T& x = (*this)[0];
    T& y = (*this)[1];

    vector2(const T& x, const T& y) {
      this->x = x;
      this->y = y;
    }

    vector2() : vector2(T(), T()) {
    }
    vector2(const ::tools::vector2<T>& other) : vector2(other.x, other.y) {
    }
    vector2(::tools::vector2<T>&& other) {
      this->x = ::std::move(other.x);
      this->y = ::std::move(other.y);
    }
    ~vector2() = default;
    ::tools::vector2<T>& operator=(const ::tools::vector2<T>& other) {
      this->x = other.x;
      this->y = other.y;
      return *this;
    }
    ::tools::vector2<T>& operator=(::tools::vector2<T>&& other) {
      this->x = ::std::move(other.x);
      this->y = ::std::move(other.y);
      return *this;
    }

    ::tools::vector2<T> operator+() const {
      return *this;
    }

    ::tools::vector2<T> operator-() const {
      return ::tools::vector2<T>(-this->x, -this->y);
    }

    ::tools::vector2<T>& operator+=(const ::tools::vector2<T>& other) {
      this->x += other.x;
      this->y += other.y;
      return *this;
    }
    friend ::tools::vector2<T> operator+(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return ::tools::vector2<T>(lhs) += rhs;
    }

    ::tools::vector2<T>& operator-=(const ::tools::vector2<T>& other) {
      this->x -= other.x;
      this->y -= other.y;
      return *this;
    }
    friend ::tools::vector2<T> operator-(const ::tools::vector2<T>& lhs, const ::tools::vector2<T>& rhs) {
      return ::tools::vector2<T>(lhs) -= rhs;
    }

    ::tools::vector2<T>& operator*=(const T& c) {
      this->x *= c;
      this->y *= c;
      return *this;
    }
    friend ::tools::vector2<T> operator*(const T& lhs, const ::tools::vector2<T>& rhs) {
      return ::tools::vector2<T>(rhs) *= lhs;
    }
    friend ::tools::vector2<T> operator*(const ::tools::vector2<T>& lhs, const T& rhs) {
      return ::tools::vector2<T>(lhs) *= rhs;
    }

    ::tools::vector2<T>& operator/=(const T& c) {
      this->x /= c;
      this->y /= c;
      return *this;
    }
    friend ::tools::vector2<T> operator/(const ::tools::vector2<T>& lhs, const T& rhs) {
      return ::tools::vector2<T>(lhs) /= rhs;
    }

    T inner_product(const ::tools::vector2<T>& other) const {
      return this->x * other.x + this->y * other.y;
    }

    T outer_product(const ::tools::vector2<T>& other) const {
      return this->x * other.y - this->y * other.x;
    }

    T l1_norm() const {
      return ::tools::abs(this->x) + ::tools::abs(this->y);
    }

    F l2_norm() const {
      return ::std::sqrt(static_cast<F>(this->squared_l2_norm()));
    }

    T squared_l2_norm() const {
      return this->inner_product(*this);
    }

    template <typename T_ = T>
    ::std::enable_if_t<::std::is_floating_point_v<T_>, ::tools::vector2<T_>> normalized() const {
      return *this / this->l2_norm();
    }

    ::tools::vector2<T> turned90() const {
      return ::tools::vector2<T>(-this->y, this->x);
    }

    ::tools::vector2<T> turned270() const {
      return ::tools::vector2<T>(this->y, -this->x);
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::vector2<T>& self) {
      return os << '(' << self.x << ", " << self.y << ')';
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::vector2<T>& self) {
      return is >> self.x >> self.y;
    }

    static ::std::array<::tools::vector2<T>, 4> four_directions() {
      return ::std::array<::tools::vector2<T>, 4>({
        ::tools::vector2<T>(T(1), T(0)),
        ::tools::vector2<T>(T(0), T(1)),
        ::tools::vector2<T>(T(-1), T(0)),
        ::tools::vector2<T>(T(0), T(-1))
      });
    }

    static ::std::array<::tools::vector2<T>, 8> eight_directions() {
      return ::std::array<::tools::vector2<T>, 8>({
        ::tools::vector2<T>(T(1), T(0)),
        ::tools::vector2<T>(T(1), T(1)),
        ::tools::vector2<T>(T(0), T(1)),
        ::tools::vector2<T>(T(-1), T(1)),
        ::tools::vector2<T>(T(-1), T(0)),
        ::tools::vector2<T>(T(-1), T(-1)),
        ::tools::vector2<T>(T(0), T(-1)),
        ::tools::vector2<T>(T(1), T(-1))
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
