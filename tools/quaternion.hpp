#ifndef TOOLS_QUATERNION_HPP
#define TOOLS_QUATERNION_HPP

#include <cmath>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <random>
#include "tools/vector4.hpp"
#include "tools/vector3.hpp"
#include "tools/square.hpp"

namespace tools {
  template <typename T>
  class quaternion {
  private:
    ::tools::vector4<T> m_vector;
    static constexpr T eps = 1e-5;
    static constexpr T pi = ::std::acos(static_cast<T>(-1));

  public:
    quaternion() = default;
    quaternion(const ::tools::quaternion<T>&) = default;
    quaternion(::tools::quaternion<T>&&) = default;
    ~quaternion() = default;
    ::tools::quaternion<T>& operator=(const ::tools::quaternion<T>&) = default;
    ::tools::quaternion<T>& operator=(::tools::quaternion<T>&&) = default;

    quaternion(const T x, const T y, const T z, const T w) : m_vector(x, y, z, w) {}

    T x() const {
      return this->m_vector.x;
    }
    void x(const T val) {
      return this->m_vector.x = val;
    }
    T y() const {
      return this->m_vector.y;
    }
    void y(const T val) {
      return this->m_vector.y = val;
    }
    T z() const {
      return this->m_vector.z;
    }
    void z(const T val) {
      return this->m_vector.z = val;
    }
    T w() const {
      return this->m_vector.w;
    }
    void w(const T val) {
      return this->m_vector.w = val;
    }

    T real() const {
      return this->w();
    }
    void real(const T val) {
      this->w(val);
    }
    ::tools::vector3<T> imag() const {
      return ::tools::vector3<T>(this->x(), this->y(), this->z());
    }
    void imag(const ::tools::vector3<T>& val) {
      this->x(val.x);
      this->y(val.y);
      this->z(val.z);
    }

    T abs() const {
      return this->m_vector.l2_norm();
    }
    T norm() const {
      return this->m_vector.squared_l2_norm();
    }
    ::tools::quaternion<T> conj() const {
      return ::tools::quaternion<T>(-this->x(), -this->y(), -this->z(), this->w());
    }

    T angle() const {
      assert(::std::abs(this->norm() - 1) <= eps);
      return ::std::acos(::std::clamp<T>(this->real(), -1, 1)) * 2;
    }
    ::tools::vector3<T> axis() const {
      assert(::std::abs(this->norm() - 1) <= eps);
      return ::std::abs(this->real()) >= 1.0 ? ::tools::vector3<T>(1, 0, 0) : this->imag().normalized();
    }

    ::tools::quaternion<T> operator+() const {
      return *this;
    }
    ::tools::quaternion<T> operator-() const {
      return ::tools::quaternion<T>(-this->x(), -this->y(), -this->z(), -this->w());
    }

    ::tools::quaternion<T>& operator+=(const ::tools::quaternion<T>& other) {
      this->m_vector += other.m_vector;
      return *this;
    }
    friend ::tools::quaternion<T> operator+(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {
      return ::tools::quaternion<T>(lhs) += rhs;
    }

    ::tools::quaternion<T>& operator-=(const ::tools::quaternion<T>& other) {
      this->m_vector -= other.m_vector;
      return *this;
    }
    friend ::tools::quaternion<T> operator-(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {
      return ::tools::quaternion<T>(lhs) -= rhs;
    }

    ::tools::quaternion<T>& operator*=(const T c) {
      this->m_vector *= c;
      return *this;
    }
    friend ::tools::quaternion<T> operator*(const ::tools::quaternion<T>& self, const T c) {
      return ::tools::quaternion<T>(self) *= c;
    }
    friend ::tools::quaternion<T> operator*(const T c, const ::tools::quaternion<T>& self) {
      return ::tools::quaternion<T>(self) *= c;
    }

    friend ::tools::quaternion<T> operator*(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {
      const auto real = lhs.real() * rhs.real() - lhs.imag().inner_product(rhs.imag());
      const auto imag = lhs.real() * rhs.imag() + rhs.real() * lhs.imag() + lhs.imag().outer_product(rhs.imag());
      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }
    ::tools::quaternion<T>& operator*=(const ::tools::quaternion<T>& other) {
      return *this = *this * other;
    }
    friend ::tools::vector3<T> operator*(const ::tools::quaternion<T>& q, const ::tools::vector3<T>& v) {
      assert(::std::abs(q.norm() - 1) <= eps);
      return (q * ::tools::quaternion<T>(v.x, v.y, v.z, 0) * q.conj()).imag();
    }

    ::tools::quaternion<T>& operator/=(const T c) {
      this->m_vector /= c;
      return *this;
    }
    friend ::tools::quaternion<T> operator/(const ::tools::quaternion<T>& self, const T c) {
      return ::tools::quaternion<T>(self) /= c;
    }

    ::tools::quaternion<T> inv() const {
      return this->conj() / this->norm();
    }
    friend ::tools::quaternion<T> operator/(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {
      return lhs * rhs.inv();
    }
    ::tools::quaternion<T>& operator/=(const ::tools::quaternion<T>& other) {
      return *this = *this / other;
    }

    friend bool operator==(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {
      return lhs.m_vector == rhs.m_vector;
    }
    friend bool operator!=(const ::tools::quaternion<T>& lhs, const ::tools::quaternion<T>& rhs) {
      return !(lhs == rhs);
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::quaternion<T>& self) {
      ::std::ostringstream s;
      s.flags(os.flags());
      s.imbue(os.getloc());
      s.precision(os.precision());
      s << '(' << self.x() << ',' << self.y() << ',' << self.z() << ',' << self.w() << ')';
      return os << s.str();
    }

  private:
    ::tools::quaternion<T> log() const {
      const auto inorm = this->imag().l2_norm();
      if (inorm == 0) {
        assert(this->real() != 0);
        return ::std::log(this->real());
      }

      const auto real = ::std::log(this->abs());
      const auto imag = ::std::acos(::std::clamp<T>(this->real() / this->abs(), -1, 1)) / inorm * this->imag();
      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }
    ::tools::quaternion<T> exp() const {
      const auto inorm = this->imag().l2_norm();
      if (inorm == 0) {
        return ::std::exp(this->real());
      }

      const auto rexp = ::std::exp(this->real());
      const auto real = rexp * ::std::cos(inorm);
      const auto imag = rexp * ::std::sin(inorm) / inorm * this->imag();
      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }

  public:
    ::tools::quaternion<T> pow(const T t) const {
      const auto norm = this->norm();
      if (norm == 0) {
        assert(t != 0);
        return ::tools::quaternion<T>(0, 0, 0, 0);
      }

      return (t * this->log()).exp();
    }

    static ::tools::quaternion<T> angle_axis(const T angle, const ::tools::vector3<T>& axis) {
      assert(axis != ::tools::vector3<T>(0, 0, 0));
      const auto real = ::std::cos(angle / 2);
      const auto imag = ::std::sin(angle / 2) * axis.normalized();
      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }

    static ::tools::quaternion<T> from_to_rotation(::tools::vector3<T> from_direction, ::tools::vector3<T> to_direction) {
      assert(from_direction != ::tools::vector3<T>(0, 0, 0));
      assert(to_direction != ::tools::vector3<T>(0, 0, 0));
      from_direction = from_direction.normalized();
      to_direction = to_direction.normalized();
      if (from_direction.inner_product(to_direction) <= -1 + eps) {
        return ::tools::quaternion<T>::angle_axis(pi, from_direction.orthonormal_basis()[1]);
      }
      const auto bisect = (from_direction + to_direction).normalized();
      const auto real = from_direction.inner_product(bisect);
      const auto imag = from_direction.outer_product(bisect);
      return ::tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }

    static ::tools::quaternion<T> look_rotation(::tools::vector3<T> forward, ::tools::vector3<T> upwards = ::tools::vector3<T>(0, 1, 0)) {
      assert(forward != ::tools::vector3<T>(0, 0, 0));
      assert(upwards != ::tools::vector3<T>(0, 0, 0));
      forward = forward.normalized();
      upwards = upwards.normalized();
      upwards = ::std::abs(::tools::square(forward.inner_product(upwards)) - 1) <= eps
        ? forward.orthonormal_basis()[1]
        : -::std::sqrt(1 / 1 - ::tools::square(forward.inner_product(upwards))) * forward.inner_product(upwards) * forward + ::std::sqrt(1 / 1 - ::tools::square(forward.inner_product(upwards))) * upwards;
      const auto q1 = ::tools::quaternion<T>::from_to_rotation(::tools::vector3<T>(0, 0, 1), forward);
      const auto theta = ::std::atan2((q1 * ::tools::vector3<T>(0, 1, 0)).outer_product(upwards).inner_product(forward), (q1 * ::tools::vector3<T>(0, 1, 0)).inner_product(upwards));
      const auto q2 = ::tools::quaternion<T>::angle_axis(theta, forward);
      return q2 * q1;
    }

    template <typename R>
    static ::tools::quaternion<T> random(R& engine) {
      static ::std::uniform_real_distribution<T> dist(0, 1);
      const auto u1 = dist(engine);
      const auto u2 = dist(engine);
      const auto u3 = dist(engine);
      return ::tools::quaternion<T>(
        ::std::sqrt(1 - u1) * ::std::sin(2 * pi * u2),
        ::std::sqrt(1 - u1) * ::std::cos(2 * pi * u2),
        ::std::sqrt(u1) * ::std::sin(2 * pi * u3),
        ::std::sqrt(u1) * ::std::cos(2 * pi * u3)
      );
    }

    static ::tools::quaternion<T> slerp(const ::tools::quaternion<T>& q0, const ::tools::quaternion<T>& q1, const T t) {
      return q0 * (q1 / q0).pow(t);
    }

    static ::tools::quaternion<T> identity() {
      return ::tools::quaternion<T>(0, 0, 0, 1);
    }
  };
}

#endif
