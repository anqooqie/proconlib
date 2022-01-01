#ifndef TOOLS_RATIONAL_HPP
#define TOOLS_RATIONAL_HPP

#include <cstdint>
#include <cassert>
#include "tools/bigint.hpp"
#include "tools/signum.hpp"

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
        const ::tools::bigint gcd = ::std::gcd(this->m_numerator, this->m_denominator);
        this->m_numerator /= gcd;
        this->m_denominator /= gcd;
      }
      return *this;
    }

  public:
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
    int signum() const {
      return this->m_numerator.signum();
    }

    rational() : m_numerator(0), m_denominator(1) {
    }
    rational(const ::tools::rational&) = default;
    rational(::tools::rational&&) = default;
    ~rational() = default;
    ::tools::rational& operator=(const ::tools::rational&) = default;
    ::tools::rational& operator=(::tools::rational&&) = default;

    explicit rational(const ::std::int_fast64_t n) : m_numerator(n), m_denominator(1) {
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

    friend ::tools::rational operator+(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational(lhs.m_numerator * rhs.m_denominator + rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator);
    }
    ::tools::rational& operator+=(const ::tools::rational& other) {
      return *this = *this + other;
    }

    friend ::tools::rational operator-(const ::tools::rational& lhs, const ::tools::rational& rhs) {
      return ::tools::rational(lhs.m_numerator * rhs.m_denominator - rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator);
    }
    ::tools::rational& operator-=(const ::tools::rational& other) {
      return *this = *this - other;
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

    friend ::std::istream& operator>>(::std::istream& is, ::tools::rational& self) {
      self.m_denominator = ::tools::bigint(1);
      return is >> self.m_numerator;
    }
    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::rational& self) {
      return os << '(' << self.m_numerator << '/' << self.m_denominator << ')';
    }
  };
}

#endif
