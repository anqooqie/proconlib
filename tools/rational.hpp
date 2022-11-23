#ifndef TOOLS_RATIONAL_HPP
#define TOOLS_RATIONAL_HPP

#include <cassert>
#include <type_traits>
#include <cstddef>
#include <limits>
#include <iostream>
#include "tools/bigint.hpp"
#include "tools/gcd.hpp"
#include "tools/bigdecimal.hpp"
#include "tools/signum.hpp"
#include "tools/ssize.hpp"
#include "tools/is_rational.hpp"
#include "tools/abs.hpp"

namespace tools {
  class rational {
  private:
    ::tools::bigint m_numerator;
    ::tools::bigint m_denominator;

    ::tools::rational& regularize() {
      if (this->m_denominator.signum() < 0) {
        this->m_numerator.negate();
        this->m_denominator.negate();
      }
      if (this->m_numerator.signum() == 0) {
        this->m_denominator = ::tools::bigint(1);
      } else {
        const ::tools::bigint gcd = ::tools::gcd(this->m_numerator, this->m_denominator);
        this->m_numerator /= gcd;
        this->m_denominator /= gcd;
      }
      return *this;
    }

  public:
    int signum() const {
      return this->m_numerator.signum();
    }
    ::tools::rational& negate() {
      this->m_numerator.negate();
      return *this;
    }
    static int compare_3way(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      if (const auto comp = ::tools::signum(lhs.signum() - rhs.signum()); comp != 0) {
        return comp;
      }
      return ::tools::bigint::compare_3way(lhs.m_numerator * rhs.m_denominator, rhs.m_numerator * lhs.m_denominator);
    }

    rational() : m_numerator(0), m_denominator(1) {
    }
    rational(const ::tools::rational&) = default;
    rational(::tools::rational&&) = default;
    ~rational() = default;
    ::tools::rational& operator=(const ::tools::rational&) = default;
    ::tools::rational& operator=(::tools::rational&&) = default;

    explicit rational(const long long n) : m_numerator(n), m_denominator(1) {
    }
    explicit rational(const ::tools::bigint& n) : m_numerator(n), m_denominator(1) {
    }
    explicit rational(const ::tools::bigdecimal& d)
      : m_numerator(::tools::bigint(1).multiply_by_pow10(::std::max<::std::ptrdiff_t>(0, -d.scale())) *= d.unscaled_value()),
        m_denominator(::tools::bigint(1).multiply_by_pow10(::std::max<::std::ptrdiff_t>(0, d.scale()))) {
      this->regularize();
    }
    rational(const long long numerator, const long long denominator)
      : m_numerator(numerator), m_denominator(denominator) {
      assert(denominator != 0);
      this->regularize();
    }
    rational(const ::tools::bigint& numerator, const ::tools::bigint& denominator)
      : m_numerator(numerator), m_denominator(denominator) {
      assert(this->m_denominator.signum() != 0);
      this->regularize();
    }

    const ::tools::bigint& numerator() const {
      return this->m_numerator;
    }
    const ::tools::bigint& denominator() const {
      return this->m_denominator;
    }

    friend bool operator==(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return lhs.m_numerator == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator;
    }
    friend bool operator!=(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return !(lhs == rhs);
    }
    friend bool operator<(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational::compare_3way(lhs, rhs) < 0;
    }
    friend bool operator>(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational::compare_3way(lhs, rhs) > 0;
    }
    friend bool operator<=(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational::compare_3way(lhs, rhs) <= 0;
    }
    friend bool operator>=(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational::compare_3way(lhs, rhs) >= 0;
    }

    ::tools::rational operator+() const {
      return *this;
    }
    ::tools::rational operator-() const {
      return ::tools::rational(*this).negate();
    }

    ::tools::rational& operator+=(const ::tools::rational& other) {
      this->m_numerator *= other.m_denominator;
      this->m_numerator += other.m_numerator * this->m_denominator;
      this->m_denominator *= other.m_denominator;
      return this->regularize();
    }
    friend ::tools::rational operator+(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational(lhs) += rhs;
    }

    ::tools::rational& operator-=(const ::tools::rational& other) {
      this->m_numerator *= other.m_denominator;
      this->m_numerator -= other.m_numerator * this->m_denominator;
      this->m_denominator *= other.m_denominator;
      return this->regularize();
    }
    friend ::tools::rational operator-(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational(lhs) -= rhs;
    }

    ::tools::rational& operator*=(const ::tools::rational& other) {
      this->m_numerator *= other.m_numerator;
      this->m_denominator *= other.m_denominator;
      return this->regularize();
    }
    friend ::tools::rational operator*(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational(lhs) *= rhs;
    }

    ::tools::rational& operator/=(const ::tools::rational& other) {
      assert(other.signum() != 0);
      this->m_numerator *= other.m_denominator;
      this->m_denominator *= other.m_numerator;
      return this->regularize();
    }
    friend ::tools::rational operator/(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational(lhs) /= rhs;
    }

    template <typename T, ::std::enable_if_t<::std::is_integral_v<T>, ::std::nullptr_t> = nullptr>
    explicit operator T() const {
      return static_cast<T>(this->m_numerator / this->m_denominator);
    }

    explicit operator double() const {
      ::tools::bigint unscaled_value(this->m_numerator);
      unscaled_value.multiply_by_pow10((::std::numeric_limits<double>::digits10 + 2) - (::tools::ssize(this->m_numerator) - ::tools::ssize(this->m_denominator)));
      unscaled_value /= this->m_denominator;

      ::tools::bigdecimal result(unscaled_value);
      result.divide_by_pow10((::std::numeric_limits<double>::digits10 + 2) - (::tools::ssize(this->m_numerator) - ::tools::ssize(this->m_denominator)));
      return static_cast<double>(result);
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::rational& self) {
      ::tools::bigdecimal value;
      is >> value;
      self = ::tools::rational(value);
      return is;
    }
    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::rational& self) {
      return os << '(' << self.m_numerator << '/' << self.m_denominator << ')';
    }
  };

  template <>
  struct is_rational<::tools::rational> : ::std::true_type {};

  inline ::tools::rational abs(::tools::rational x) {
    if (x.signum() < 0) x.negate();
    return x;
  }
}

#endif
