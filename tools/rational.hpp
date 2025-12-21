#ifndef TOOLS_RATIONAL_HPP
#define TOOLS_RATIONAL_HPP

#include <algorithm>
#include <cassert>
#include <compare>
#include <concepts>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>
#include "tools/abs.hpp"
#include "tools/bigdecimal.hpp"
#include "tools/bigint.hpp"
#include "tools/gcd.hpp"
#include "tools/getter_result.hpp"
#include "tools/integral.hpp"
#include "tools/is_rational.hpp"
#include "tools/mutable_type.hpp"
#include "tools/non_bool_integral.hpp"
#include "tools/signed_integral.hpp"
#include "tools/signum.hpp"

namespace tools {
  template <typename Z, bool AutoReduce = true>
  requires tools::signed_integral<Z> || std::same_as<Z, tools::bigint>
  class rational;

  template <typename Z, bool AutoReduce>
  struct detail::abs::impl<tools::rational<Z, AutoReduce>> {
    tools::rational<Z, AutoReduce> operator()(auto&&) const;
  };
  template <typename Z, bool AutoReduce>
  struct detail::signum::impl<tools::rational<Z, AutoReduce>> {
    int operator()(const tools::rational<Z, AutoReduce>&) const;
  };

  template <typename Z, bool AutoReduce>
  requires tools::signed_integral<Z> || std::same_as<Z, tools::bigint>
  class rational {
    using R = tools::rational<Z, AutoReduce>;
    Z m_numerator;
    Z m_denominator;

    template <typename T>
    static void negate(T& x) {
      if constexpr (requires(T n) { n.negate(); }) {
        x.negate();
      } else {
        x = -x;
      }
    }
    auto regularize(this tools::mutable_type auto&& self) -> decltype(self) {
      if (tools::signum(self.m_denominator) < 0) {
        R::negate(self.m_numerator);
        R::negate(self.m_denominator);
      }
      if (tools::signum(self.m_numerator) == 0) {
        self.m_denominator = Z(1);
      } else {
        if constexpr (AutoReduce) {
          self.template reduce<true>();
        }
      }
      return std::forward<decltype(self)>(self);
    }

  public:
    rational() : m_numerator(0), m_denominator(1) {
    }
    template <typename T>
    requires requires(T n) { Z(n); }
    explicit rational(const T& n) : m_numerator(n), m_denominator(1) {
    }
    explicit rational(const tools::bigdecimal& d)
      : m_numerator(static_cast<Z>(tools::bigint(1).multiply_inplace_by_pow10(std::max<std::ptrdiff_t>(0, -d.scale())) *= d.unscaled_value())),
        m_denominator(static_cast<Z>(tools::bigint(1).multiply_inplace_by_pow10(std::max<std::ptrdiff_t>(0, d.scale())))) {
      this->regularize();
    }
    template <typename T>
    requires requires(T n) { Z(n); }
    rational(const T& numerator, const T& denominator)
      : m_numerator(numerator), m_denominator(denominator) {
      assert(tools::signum(denominator) != 0);
      this->regularize();
    }

    auto abs_inplace(this tools::mutable_type auto&& self) -> decltype(self) {
      if (tools::signum(self) < 0) self.negate();
      return std::forward<decltype(self)>(self);
    }
    auto denominator(this auto&& self) -> tools::getter_result_t<decltype(self), Z> {
      return std::forward_like<decltype(self)>(self.m_denominator);
    }
    auto negate(this tools::mutable_type auto&& self) -> decltype(self) {
      R::negate(self.m_numerator);
      return std::forward<decltype(self)>(self);
    }
    auto numerator(this auto&& self) -> tools::getter_result_t<decltype(self), Z> {
      return std::forward_like<decltype(self)>(self.m_numerator);
    }
    template <bool SFINAE = !AutoReduce>
    requires SFINAE
    auto reduce(this tools::mutable_type auto&& self) -> decltype(self) {
      const auto gcd = tools::gcd(self.m_numerator, self.m_denominator);
      self.m_numerator /= gcd;
      self.m_denominator /= gcd;
      return std::forward<decltype(self)>(self);
    }

    friend std::conditional_t<AutoReduce, std::strong_ordering, std::weak_ordering> operator<=>(const R& lhs, const R& rhs) {
      if (const auto comp = tools::signum(lhs) <=> tools::signum(rhs); comp != 0) {
        return comp;
      }
      return lhs.m_numerator * rhs.m_denominator <=> rhs.m_numerator * lhs.m_denominator;
    }
    friend bool operator==(const R& lhs, const R& rhs) {
      if constexpr (AutoReduce) {
        return lhs.m_numerator == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator;
      } else {
        return (lhs <=> rhs) == 0;
      }
    }

    R operator+(this auto&& self) {
      return std::forward<decltype(self)>(self);
    }
    R operator-(this auto&& self) {
      return R(std::forward<decltype(self)>(self)).negate();
    }

    auto operator++(this tools::mutable_type auto&& self) -> decltype(self) {
      self += R(1);
      return std::forward<decltype(self)>(self);
    }
    R operator++(int) {
      R old(*this);
      ++(*this);
      return old;
    }
    auto operator--(this tools::mutable_type auto&& self) -> decltype(self) {
      self -= R(1);
      return std::forward<decltype(self)>(self);
    }
    R operator--(int) {
      R old(*this);
      --(*this);
      return old;
    }

    auto operator+=(this tools::mutable_type auto&& self, const R& other) -> decltype(self) {
      self.m_numerator *= other.m_denominator;
      self.m_numerator += other.m_numerator * self.m_denominator;
      self.m_denominator *= other.m_denominator;
      self.regularize();
      return std::forward<decltype(self)>(self);
    }
    R operator+(this auto&& lhs, const R& rhs) {
      return R(std::forward<decltype(lhs)>(lhs)) += rhs;
    }

    auto operator-=(this tools::mutable_type auto&& self, const R& other) -> decltype(self) {
      self.m_numerator *= other.m_denominator;
      self.m_numerator -= other.m_numerator * self.m_denominator;
      self.m_denominator *= other.m_denominator;
      self.regularize();
      return std::forward<decltype(self)>(self);
    }
    R operator-(this auto&& lhs, const R& rhs) {
      return R(std::forward<decltype(lhs)>(lhs)) -= rhs;
    }

    auto operator*=(this tools::mutable_type auto&& self, const R& other) -> decltype(self) {
      self.m_numerator *= other.m_numerator;
      self.m_denominator *= other.m_denominator;
      self.regularize();
      return std::forward<decltype(self)>(self);
    }
    R operator*(this auto&& lhs, const R& rhs) {
      return R(std::forward<decltype(lhs)>(lhs)) *= rhs;
    }

    auto operator/=(this tools::mutable_type auto&& self, const R& other) -> decltype(self) {
      assert(tools::signum(other) != 0);
      self.m_numerator *= other.m_denominator;
      self.m_denominator *= other.m_numerator;
      self.regularize();
      return std::forward<decltype(self)>(self);
    }
    R operator/(this auto&& lhs, const R& rhs) {
      return R(std::forward<decltype(lhs)>(lhs)) /= rhs;
    }

    explicit operator bool() const {
      return tools::signum(this->m_numerator) != 0;
    }
    template <tools::non_bool_integral T>
    explicit operator T() const {
      return static_cast<T>(this->m_numerator / this->m_denominator);
    }
    explicit operator double() const requires std::same_as<Z, tools::bigint> {
      tools::bigint unscaled_value(this->m_numerator);
      unscaled_value.multiply_inplace_by_pow10((std::numeric_limits<double>::digits10 + 2) - (std::ssize(this->m_numerator) - std::ssize(this->m_denominator)));
      unscaled_value /= this->m_denominator;

      tools::bigdecimal result(unscaled_value);
      result.divide_inplace_by_pow10((std::numeric_limits<double>::digits10 + 2) - (std::ssize(this->m_numerator) - std::ssize(this->m_denominator)));
      return static_cast<double>(result);
    }
    explicit operator double() const requires tools::signed_integral<Z> {
      return static_cast<double>(this->m_numerator) / static_cast<double>(this->m_denominator);
    }

    friend std::istream& operator>>(std::istream& is, R& self) {
      tools::bigdecimal value;
      is >> value;
      self = R(value);
      return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const R& self) {
      return os << '(' << self.m_numerator << '/' << self.m_denominator << ')';
    }
  };

  template <typename Z, bool AutoReduce>
  struct is_rational<tools::rational<Z, AutoReduce>> : std::true_type {};

  template <typename Z, bool AutoReduce>
  tools::rational<Z, AutoReduce> detail::abs::impl<tools::rational<Z, AutoReduce>>::operator()(auto&& x) const {
    return tools::rational<Z, AutoReduce>(std::forward<decltype(x)>(x)).abs_inplace();
  }
  template <typename Z, bool AutoReduce>
  int detail::signum::impl<tools::rational<Z, AutoReduce>>::operator()(const tools::rational<Z, AutoReduce>& x) const {
    return tools::signum(x.numerator());
  };
}

#endif
