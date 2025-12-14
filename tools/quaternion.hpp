#ifndef TOOLS_QUATERNION_HPP
#define TOOLS_QUATERNION_HPP

#include <type_traits>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <random>
#include "tools/abs.hpp"
#include "tools/exp.hpp"
#include "tools/log.hpp"
#include "tools/pow.hpp"
#include "tools/vector4.hpp"
#include "tools/vector3.hpp"

namespace tools {
  template <typename T>
  class quaternion;

  template <typename T>
  struct detail::abs::impl<tools::quaternion<T>> {
    T operator()(const tools::quaternion<T>&) const;
  };
  template <typename T>
  tools::quaternion<T> exp(const tools::quaternion<T>& q);
  template <typename T>
  tools::quaternion<T> log(const tools::quaternion<T>& q);
  template <typename T>
  tools::quaternion<T> pow(const tools::quaternion<T>& base, T exponent);

  template <typename T>
  class quaternion {
    static_assert(std::is_floating_point_v<T>);

    static constexpr T eps = 1e-5;
    static constexpr T pi = 3.14159265358979323846264338327950288419716939937510L;

  public:
    T x;
    T y;
    T z;
    T w;

    quaternion() = default;
    quaternion(const T x, const T y, const T z, const T w) : x(x), y(y), z(z), w(w) {}

    T real() const {
      return this->w;
    }
    void real(const T val) {
      this->w = val;
    }
    tools::vector3<T> imag() const {
      return tools::vector3<T>(this->x, this->y, this->z);
    }
    void imag(const tools::vector3<T>& val) {
      this->x = val.x;
      this->y = val.y;
      this->z = val.z;
    }

    T norm() const {
      return tools::vector4<T>(this->x, this->y, this->z, this->w).squared_l2_norm();
    }
    tools::quaternion<T> conj() const {
      return tools::quaternion<T>(-this->x, -this->y, -this->z, this->w);
    }

    T angle() const {
      assert(std::abs(this->norm() - 1) <= eps);
      return std::acos(std::clamp<T>(this->real(), -1, 1)) * 2;
    }
    tools::vector3<T> axis() const {
      assert(std::abs(this->norm() - 1) <= eps);
      return std::abs(this->real()) >= 1.0 ? tools::vector3<T>(1, 0, 0) : this->imag().normalized();
    }

    tools::quaternion<T> operator+() const {
      return *this;
    }
    tools::quaternion<T> operator-() const {
      return tools::quaternion<T>(-this->x, -this->y, -this->z, -this->w);
    }

    auto operator+=(this auto&& self, const tools::quaternion<T>& other) -> decltype(self) {
      self.x += other.x;
      self.y += other.y;
      self.z += other.z;
      self.w += other.w;
      return self;
    }
    friend tools::quaternion<T> operator+(const tools::quaternion<T>& lhs, const tools::quaternion<T>& rhs) {
      return tools::quaternion<T>(lhs) += rhs;
    }

    auto operator-=(this auto&& self, const tools::quaternion<T>& other) -> decltype(self) {
      self.x -= other.x;
      self.y -= other.y;
      self.z -= other.z;
      self.w -= other.w;
      return self;
    }
    friend tools::quaternion<T> operator-(const tools::quaternion<T>& lhs, const tools::quaternion<T>& rhs) {
      return tools::quaternion<T>(lhs) -= rhs;
    }

    auto operator*=(this auto&& self, const T c) -> decltype(self) {
      self.x *= c;
      self.y *= c;
      self.z *= c;
      self.w *= c;
      return self;
    }
    friend tools::quaternion<T> operator*(const tools::quaternion<T>& self, const T c) {
      return tools::quaternion<T>(self) *= c;
    }
    friend tools::quaternion<T> operator*(const T c, const tools::quaternion<T>& self) {
      return tools::quaternion<T>(self) *= c;
    }

    friend tools::quaternion<T> operator*(const tools::quaternion<T>& lhs, const tools::quaternion<T>& rhs) {
      const auto real = lhs.real() * rhs.real() - lhs.imag().inner_product(rhs.imag());
      const auto imag = lhs.real() * rhs.imag() + rhs.real() * lhs.imag() + lhs.imag().outer_product(rhs.imag());
      return tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }
    auto operator*=(this auto&& self, const tools::quaternion<T>& other) -> decltype(self) {
      self = self * other;
      return self;
    }
    friend tools::vector3<T> operator*(const tools::quaternion<T>& q, const tools::vector3<T>& v) {
      assert(std::abs(q.norm() - 1) <= eps);
      return (q * tools::quaternion<T>(v.x, v.y, v.z, 0) * q.conj()).imag();
    }

    auto operator/=(this auto&& self, const T c) -> decltype(self) {
      self.x /= c;
      self.y /= c;
      self.z /= c;
      self.w /= c;
      return self;
    }
    friend tools::quaternion<T> operator/(const tools::quaternion<T>& self, const T c) {
      return tools::quaternion<T>(self) /= c;
    }

    tools::quaternion<T> inv() const {
      const auto norm = this->norm();
      assert(norm != 0);
      return this->conj() / norm;
    }
    friend tools::quaternion<T> operator/(const tools::quaternion<T>& lhs, const tools::quaternion<T>& rhs) {
      return lhs * rhs.inv();
    }
    auto operator/=(this auto&& self, const tools::quaternion<T>& other) -> decltype(self) {
      self = self / other;
      return self;
    }

    friend bool operator==(const tools::quaternion<T>& lhs, const tools::quaternion<T>& rhs) {
      return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
    }
    friend bool operator!=(const tools::quaternion<T>& lhs, const tools::quaternion<T>& rhs) {
      return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream& os, const tools::quaternion<T>& self) {
      std::ostringstream s;
      s.flags(os.flags());
      s.imbue(os.getloc());
      s.precision(os.precision());
      s << '(' << self.x << ',' << self.y << ',' << self.z << ',' << self.w << ')';
      return os << s.str();
    }

    static tools::quaternion<T> angle_axis(const T angle, const tools::vector3<T>& axis) {
      assert(axis != tools::vector3<T>(0, 0, 0));
      const auto real = std::cos(angle / 2);
      const auto imag = std::sin(angle / 2) * axis.normalized();
      return tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }

    static tools::quaternion<T> from_to_rotation(tools::vector3<T> from_direction, tools::vector3<T> to_direction) {
      assert(from_direction != tools::vector3<T>(0, 0, 0));
      assert(to_direction != tools::vector3<T>(0, 0, 0));
      from_direction = from_direction.normalized();
      to_direction = to_direction.normalized();
      if (from_direction.inner_product(to_direction) <= -1 + eps) {
        return tools::quaternion<T>::angle_axis(pi, from_direction.orthonormal_basis()[1]);
      }
      const auto bisect = (from_direction + to_direction).normalized();
      const auto real = from_direction.inner_product(bisect);
      const auto imag = from_direction.outer_product(bisect);
      return tools::quaternion<T>(imag.x, imag.y, imag.z, real);
    }

    static tools::quaternion<T> look_rotation(tools::vector3<T> forward, tools::vector3<T> upwards = tools::vector3<T>(0, 1, 0)) {
      assert(forward != tools::vector3<T>(0, 0, 0));
      assert(upwards != tools::vector3<T>(0, 0, 0));

      auto side = upwards.outer_product(forward);
      if (side == tools::vector3<T>(0, 0, 0)) {
        upwards = tools::vector3<T>(0, 1, 0);
        side = upwards.outer_product(forward);
      }
      if (side == tools::vector3<T>(0, 0, 0)) {
        side = forward.orthonormal_basis()[1];
      }
      upwards = forward.outer_product(side);

      forward = forward.normalized();
      upwards = upwards.normalized();

      const auto q1 = tools::quaternion<T>::from_to_rotation(tools::vector3<T>(0, 0, 1), forward);
      const auto theta = std::atan2((q1 * tools::vector3<T>(0, 1, 0)).outer_product(upwards).inner_product(forward), (q1 * tools::vector3<T>(0, 1, 0)).inner_product(upwards));
      const auto q2 = tools::quaternion<T>::angle_axis(theta, forward);
      return q2 * q1;
    }

    static tools::quaternion<T> slerp(const tools::quaternion<T>& q0, const tools::quaternion<T>& q1, const T t) {
      return q0 * tools::pow(q0.inv() * q1, t);
    }

    static tools::quaternion<T> identity() {
      return tools::quaternion<T>(0, 0, 0, 1);
    }

    template <typename R>
    static tools::quaternion<T> random(R& engine) {
      thread_local std::uniform_real_distribution<T> dist(0, 1);
      const auto u1 = dist(engine);
      const auto u2 = dist(engine);
      const auto u3 = dist(engine);
      return tools::quaternion<T>(
        std::sqrt(1 - u1) * std::sin(2 * pi * u2),
        std::sqrt(1 - u1) * std::cos(2 * pi * u2),
        std::sqrt(u1) * std::sin(2 * pi * u3),
        std::sqrt(u1) * std::cos(2 * pi * u3)
      );
    }

    static std::array<tools::quaternion<T>, 24> dice_rotations() {
      return std::array<tools::quaternion<T>, 24>({
        tools::quaternion<double>::identity(),
        tools::quaternion<double>::angle_axis(-0.5 * pi, tools::vector3<double>(1, 0, 0)),
        tools::quaternion<double>::angle_axis(0.5 * pi, tools::vector3<double>(1, 0, 0)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(1, 0, 0)),
        tools::quaternion<double>::angle_axis(-0.5 * pi, tools::vector3<double>(0, 1, 0)),
        tools::quaternion<double>::angle_axis(0.5 * pi, tools::vector3<double>(0, 1, 0)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(0, 1, 0)),
        tools::quaternion<double>::angle_axis(-0.5 * pi, tools::vector3<double>(0, 0, 1)),
        tools::quaternion<double>::angle_axis(0.5 * pi, tools::vector3<double>(0, 0, 1)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(0, 0, 1)),
        tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, tools::vector3<double>(-1, -1, 1)),
        tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, tools::vector3<double>(-1, -1, 1)),
        tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, tools::vector3<double>(-1, 1, 1)),
        tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, tools::vector3<double>(-1, 1, 1)),
        tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, tools::vector3<double>(1, -1, 1)),
        tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, tools::vector3<double>(1, -1, 1)),
        tools::quaternion<double>::angle_axis(-2.0 / 3.0 * pi, tools::vector3<double>(1, 1, 1)),
        tools::quaternion<double>::angle_axis(2.0 / 3.0 * pi, tools::vector3<double>(1, 1, 1)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(0, -1, 1)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(0, 1, 1)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(-1, 0, 1)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(1, 0, 1)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(-1, 1, 0)),
        tools::quaternion<double>::angle_axis(pi, tools::vector3<double>(1, 1, 0))
      });
    }
  };

  template <typename T>
  T detail::abs::impl<tools::quaternion<T>>::operator()(const tools::quaternion<T>& q) const {
    return tools::vector4<T>(q.x, q.y, q.z, q.w).l2_norm();
  };

  template <typename T>
  tools::quaternion<T> exp(const tools::quaternion<T>& q) {
    const auto inorm = q.imag().l2_norm();
    if (inorm == 0) {
      return tools::quaternion<T>(0, 0, 0, std::exp(q.real()));
    }

    const auto rexp = std::exp(q.real());
    const auto real = rexp * std::cos(inorm);
    const auto imag = rexp * std::sin(inorm) / inorm * q.imag();
    return tools::quaternion<T>(imag.x, imag.y, imag.z, real);
  }

  template <typename T>
  tools::quaternion<T> log(const tools::quaternion<T>& q) {
    assert(q != tools::quaternion<T>(0, 0, 0, 0));
    const auto inorm = q.imag().l2_norm();
    const auto uimag = inorm == 0 ? tools::vector3<T>(1, 0, 0) : q.imag() / inorm;
    const auto real = std::log(tools::abs(q));
    const auto imag = std::atan2(inorm, q.real()) * uimag;
    return tools::quaternion<T>(imag.x, imag.y, imag.z, real);
  }

  template <typename T>
  tools::quaternion<T> pow(const tools::quaternion<T>& base, const T exponent) {
    const auto norm = base.norm();
    if (norm == 0) {
      assert(exponent != 0);
      return tools::quaternion<T>(0, 0, 0, 0);
    }

    return tools::exp(exponent * tools::log(base));
  }
}

#endif
