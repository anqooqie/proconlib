#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <cstdint>
#include <tuple>
#include <stdexcept>
#include <type_traits>
#include <cstddef>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include "extgcd.hpp"

/*
usage:

tools::fraction(5, 2) // => (5/2)
*/

namespace tools {
  class fraction {
  private:
    ::std::intmax_t m_numerator;
    ::std::intmax_t m_denominator;

    void reduct() noexcept {
      if (this->m_denominator < 0) {
        this->m_numerator *= -1;
        this->m_denominator *= -1;
      }
      if (this->m_numerator == 0) {
        this->m_denominator = 1;
      } else {
        const ::std::intmax_t gcd = ::std::get<0>(::tools::extgcd(this->m_numerator, this->m_denominator));
        this->m_numerator /= gcd;
        this->m_denominator /= gcd;
      }
    }

    fraction(const ::std::intmax_t numerator, const ::std::intmax_t denominator, bool) noexcept :
      m_numerator(numerator),
      m_denominator(denominator) {
      this->reduct();
    }

  public:
    fraction() noexcept :
      fraction(0, 1, true) {
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    fraction(const T n) noexcept :
      fraction(n, 1, true) {
    }
    template <typename T1, typename T2, typename ::std::enable_if<::std::is_integral<T1>::value && ::std::is_integral<T2>::value, ::std::nullptr_t>::type = nullptr>
    fraction(const T1 numerator, const T2 denominator) :
      m_numerator(numerator),
      m_denominator(denominator) {
      if (this->m_denominator == 0) throw ::std::domain_error("Denominator cannot be zero.");
      this->reduct();
    }

    ::std::intmax_t numerator() const noexcept {
      return this->m_numerator;
    }

    ::std::intmax_t denominator() const noexcept {
      return this->m_denominator;
    }

    explicit operator double() const noexcept {
      return static_cast<double>(this->m_numerator) / this->m_denominator;
    }

    ::tools::fraction operator+() const noexcept {
      return *this;
    }

    ::tools::fraction operator-() const noexcept {
      return ::tools::fraction(-this->m_numerator, this->m_denominator, true);
    }

    friend ::tools::fraction operator+(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return ::tools::fraction(lhs.m_numerator * rhs.m_denominator + rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator, true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator+(const ::tools::fraction& lhs, const T rhs) noexcept {
      return ::tools::fraction(lhs.m_numerator + static_cast<::std::intmax_t>(rhs) * lhs.m_denominator, lhs.m_denominator, true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator+(const T lhs, const ::tools::fraction& rhs) noexcept {
      return ::tools::fraction(static_cast<::std::intmax_t>(lhs) * rhs.m_denominator + rhs.m_numerator, rhs.m_denominator, true);
    }

    friend ::tools::fraction operator-(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return ::tools::fraction(lhs.m_numerator * rhs.m_denominator - rhs.m_numerator * lhs.m_denominator, lhs.m_denominator * rhs.m_denominator, true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator-(const ::tools::fraction& lhs, const T rhs) noexcept {
      return ::tools::fraction(lhs.m_numerator - static_cast<::std::intmax_t>(rhs) * lhs.m_denominator, lhs.m_denominator, true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator-(const T lhs, const ::tools::fraction& rhs) noexcept {
      return ::tools::fraction(static_cast<::std::intmax_t>(lhs) * rhs.m_denominator - rhs.m_numerator, rhs.m_denominator, true);
    }

    friend ::tools::fraction operator*(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return ::tools::fraction(lhs.m_numerator * rhs.m_numerator, lhs.m_denominator * rhs.m_denominator, true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator*(const ::tools::fraction& lhs, const T rhs) noexcept {
      return ::tools::fraction(lhs.m_numerator * static_cast<::std::intmax_t>(rhs), lhs.m_denominator, true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator*(const T lhs, const ::tools::fraction& rhs) noexcept {
      return ::tools::fraction(static_cast<::std::intmax_t>(lhs) * rhs.m_numerator, rhs.m_denominator, true);
    }

    friend ::tools::fraction operator/(const ::tools::fraction& lhs, const ::tools::fraction& rhs) {
      if (rhs == 0) throw ::std::domain_error("Cannot divide by zero.");
      return ::tools::fraction(lhs.m_numerator * rhs.m_denominator, lhs.m_denominator * rhs.m_numerator, true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator/(const ::tools::fraction& lhs, const T rhs) {
      if (rhs == 0) throw ::std::domain_error("Cannot divide by zero.");
      return ::tools::fraction(lhs.m_numerator, lhs.m_denominator * static_cast<::std::intmax_t>(rhs), true);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend ::tools::fraction operator/(const T lhs, const ::tools::fraction& rhs) {
      if (rhs == 0) throw ::std::domain_error("Cannot divide by zero.");
      return ::tools::fraction(static_cast<::std::intmax_t>(lhs) * rhs.m_denominator, rhs.m_numerator, true);
    }

    ::tools::fraction& operator++() noexcept {
      return *this = *this + 1;
    }
    ::tools::fraction operator++(int) noexcept {
      const ::tools::fraction prev = *this;
      ++*this;
      return prev;
    }

    ::tools::fraction& operator--() noexcept {
      return *this = *this - 1;
    }
    ::tools::fraction operator--(int) noexcept {
      const ::tools::fraction prev = *this;
      --*this;
      return prev;
    }

    ::tools::fraction& operator+=(const ::tools::fraction& other) noexcept {
      return *this = *this + other;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    ::tools::fraction& operator+=(const T other) noexcept {
      return *this = *this + other;
    }

    ::tools::fraction& operator-=(const ::tools::fraction& other) noexcept {
      return *this = *this - other;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    ::tools::fraction& operator-=(const T other) noexcept {
      return *this = *this - other;
    }

    ::tools::fraction& operator*=(const ::tools::fraction& other) noexcept {
      return *this = *this * other;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    ::tools::fraction& operator*=(const T other) noexcept {
      return *this = *this * other;
    }

    ::tools::fraction& operator/=(const ::tools::fraction& other) {
      return *this = *this / other;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    ::tools::fraction& operator/=(const T other) {
      return *this = *this / other;
    }

    friend bool operator==(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return lhs.m_numerator == rhs.m_numerator && lhs.m_denominator == rhs.m_denominator;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator==(const ::tools::fraction& lhs, const T rhs) noexcept {
      return lhs.m_numerator == static_cast<::std::intmax_t>(rhs) && lhs.m_denominator == 1;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator==(const T lhs, const ::tools::fraction& rhs) noexcept {
      return static_cast<::std::intmax_t>(lhs) == rhs.m_numerator && 1 == rhs.m_denominator;
    }

    friend bool operator!=(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return !(lhs == rhs);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator!=(const ::tools::fraction& lhs, const T rhs) noexcept {
      return !(lhs == rhs);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator!=(const T lhs, const ::tools::fraction& rhs) noexcept {
      return !(lhs == rhs);
    }

    friend bool operator<(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return lhs.m_numerator * rhs.m_denominator < rhs.m_numerator * lhs.m_denominator;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator<(const ::tools::fraction& lhs, const T rhs) noexcept {
      return lhs.m_numerator < static_cast<::std::intmax_t>(rhs) * lhs.m_denominator;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator<(const T lhs, const ::tools::fraction& rhs) noexcept {
      return static_cast<::std::intmax_t>(lhs) * rhs.m_denominator < rhs.m_numerator;
    }

    friend bool operator>(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return rhs < lhs;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator>(const ::tools::fraction& lhs, const T rhs) noexcept {
      return rhs < lhs;
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator>(const T lhs, const ::tools::fraction& rhs) noexcept {
      return rhs < lhs;
    }

    friend bool operator<=(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return !(rhs < lhs);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator<=(const ::tools::fraction& lhs, const T rhs) noexcept {
      return !(rhs < lhs);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator<=(const T lhs, const ::tools::fraction& rhs) noexcept {
      return !(rhs < lhs);
    }

    friend bool operator>=(const ::tools::fraction& lhs, const ::tools::fraction& rhs) noexcept {
      return !(lhs < rhs);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator>=(const ::tools::fraction& lhs, const T rhs) noexcept {
      return !(lhs < rhs);
    }
    template <typename T, typename ::std::enable_if<::std::is_integral<T>::value, ::std::nullptr_t>::type = nullptr>
    friend bool operator>=(const T lhs, const ::tools::fraction& rhs) noexcept {
      return !(lhs < rhs);
    }
  };
}

namespace std {
  ::std::string to_string(const ::tools::fraction& f);
  ::tools::fraction abs(const ::tools::fraction& f);
  double sqrt(const ::tools::fraction& f);
  ::std::ostream& operator<<(::std::ostream& os, const ::tools::fraction& self);

  template <>
  struct hash<::tools::fraction> {
    typedef ::std::size_t result_type;
    typedef ::tools::fraction argument_type;
    ::std::size_t operator()(const ::tools::fraction& key) const {
      static const ::std::hash<::std::intmax_t> hash = ::std::hash<::std::intmax_t>();
      ::std::size_t result = 17;
      result = 31 * result + hash(key.numerator());
      result = 31 * result + hash(key.denominator());
      return result;
    }
  };
}

#endif
