#ifndef TOOLS_BIGDECIMAL_HPP
#define TOOLS_BIGDECIMAL_HPP

#include <cstddef>
#include <algorithm>
#include <string>
#include <cassert>
#include <type_traits>
#include <limits>
#include <cmath>
#include <iostream>
#include "tools/bigint.hpp"
#include "tools/signum.hpp"
#include "tools/ssize.hpp"
#include "tools/rounding_mode.hpp"

namespace tools {
  class bigdecimal {
  private:
    // *this := this->m_unscaled_value * (10 ** -this->m_scale)
    ::tools::bigint m_unscaled_value;
    ::std::ptrdiff_t m_scale;

    ::tools::bigdecimal& regularize() {
      if (this->m_unscaled_value.signum() == 0) {
        this->m_scale = 0;
      }
      return *this;
    }

  public:
    const ::tools::bigint& unscaled_value() const {
      return this->m_unscaled_value;
    }
    ::std::size_t precision() const {
      return this->m_unscaled_value.size();
    }
    ::std::ptrdiff_t scale() const {
      return this->m_scale;
    }
    int signum() const {
      return this->m_unscaled_value.signum();
    }
    ::tools::bigdecimal& negate() {
      this->m_unscaled_value.negate();
      return *this;
    }
    ::tools::bigdecimal abs() const {
      ::tools::bigdecimal result(*this);
      if (result.signum() < 0) result.negate();
      return result;
    }
    ::tools::bigdecimal& multiply_by_pow10(const ::std::ptrdiff_t n) {
      this->m_scale -= n;
      return *this;
    }
    ::tools::bigdecimal& divide_by_pow10(const ::std::ptrdiff_t n) {
      return this->multiply_by_pow10(-n);
    }
    ::tools::bigdecimal& set_scale(const ::std::ptrdiff_t s) {
      this->m_unscaled_value.multiply_by_pow10(s - this->m_scale);
      this->m_scale = s;
      this->regularize();
      return *this;
    }
    static int compare_3way(const ::tools::bigdecimal& x, const ::tools::bigdecimal& y) {
      if (const auto comp = ::tools::signum(x.m_unscaled_value.signum() - y.m_unscaled_value.signum()); comp != 0) {
        return comp;
      }
      return [&]() {
        ::tools::bigdecimal abs_x(x);
        if (abs_x.signum() < 0) abs_x.negate();
        abs_x.set_scale(::std::max(x.m_scale, y.m_scale));
        ::tools::bigdecimal abs_y(y);
        if (abs_y.signum() < 0) abs_y.negate();
        abs_y.set_scale(::std::max(x.m_scale, y.m_scale));
        return ::tools::bigint::compare_3way(abs_x.m_unscaled_value, abs_y.m_unscaled_value);
      }() * x.m_unscaled_value.signum();
    }

    bigdecimal() : m_unscaled_value(0), m_scale(0) {
    }
    bigdecimal(const ::tools::bigdecimal&) = default;
    bigdecimal(::tools::bigdecimal&&) = default;
    ~bigdecimal() = default;
    ::tools::bigdecimal& operator=(const ::tools::bigdecimal&) = default;
    ::tools::bigdecimal& operator=(::tools::bigdecimal&&) = default;

    explicit bigdecimal(const long long n) : m_unscaled_value(n), m_scale(0) {
    }
    explicit bigdecimal(const ::tools::bigint& n) : m_unscaled_value(n), m_scale(0) {
    }
    explicit bigdecimal(::std::string s) {
      if (const auto pos = s.find('.'); pos != ::std::string::npos) {
        this->m_scale = s.size() - pos - 1;
        s.erase(pos, 1);
      } else {
        this->m_scale = 0;
      }
      this->m_unscaled_value = ::tools::bigint(s);
      this->regularize();
    }

    friend bool operator==(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal::compare_3way(lhs, rhs) == 0;
    }
    friend bool operator!=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal::compare_3way(lhs, rhs) != 0;
    }
    friend bool operator<(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal::compare_3way(lhs, rhs) < 0;
    }
    friend bool operator>(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal::compare_3way(lhs, rhs) > 0;
    }
    friend bool operator<=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal::compare_3way(lhs, rhs) <= 0;
    }
    friend bool operator>=(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal::compare_3way(lhs, rhs) >= 0;
    }

    ::tools::bigdecimal operator+() const {
      return *this;
    }
    ::tools::bigdecimal operator-() const {
      return ::tools::bigdecimal(*this).negate();
    }

    ::tools::bigdecimal& operator+=(::tools::bigdecimal other) {
      const ::std::size_t scale = ::std::max(this->m_scale, other.m_scale);
      this->set_scale(scale);
      other.set_scale(scale);
      this->m_unscaled_value += other.m_unscaled_value;
      return this->regularize();
    }
    ::tools::bigdecimal& operator-=(::tools::bigdecimal other) {
      const ::std::size_t scale = ::std::max(this->m_scale, other.m_scale);
      this->set_scale(scale);
      other.set_scale(scale);
      this->m_unscaled_value -= other.m_unscaled_value;
      return this->regularize();
    }
    ::tools::bigdecimal& operator*=(const ::tools::bigdecimal& other) {
      this->m_unscaled_value *= other.m_unscaled_value;
      this->m_scale += other.m_scale;
      return this->regularize();
    }
    ::tools::bigdecimal& divide(const ::tools::bigdecimal& other, const ::std::ptrdiff_t scale, const ::tools::rounding_mode rounding_mode) {
      assert(other.signum() != 0);

      static const auto compare_3way_abs = [](::tools::bigdecimal& x, ::tools::bigdecimal& y) {
        const bool x_positive = x.signum() >= 0;
        const bool y_positive = y.signum() >= 0;
        if (!x_positive) x.negate();
        if (!y_positive) y.negate();
        const int result = ::tools::bigdecimal::compare_3way(x, y);
        if (!x_positive) x.negate();
        if (!y_positive) y.negate();
        return result;
      };

      ::tools::bigdecimal old_this(*this);

      this->m_unscaled_value.multiply_by_pow10(scale - (this->m_scale - other.m_scale));
      this->m_unscaled_value /= other.m_unscaled_value;
      this->m_scale = scale;
      this->regularize();

      if ([&]() {
        if (rounding_mode == ::tools::rounding_mode::down) {
          return false;
        }
        if (rounding_mode == ::tools::rounding_mode::ceiling || rounding_mode == ::tools::rounding_mode::floor || rounding_mode == ::tools::rounding_mode::up) {
          if ((rounding_mode == ::tools::rounding_mode::ceiling && old_this.signum() * other.signum() > 0)
            || (rounding_mode == ::tools::rounding_mode::floor && old_this.signum() * other.signum() < 0)
            || rounding_mode == ::tools::rounding_mode::up) {
            ::tools::bigdecimal d(*this);
            d *= other;
            return compare_3way_abs(old_this, d) > 0;
          } else {
            return false;
          }
        }

        ::tools::bigdecimal d(*this);
        d += ::tools::bigdecimal(5 * old_this.signum() * other.signum()).divide_by_pow10(scale + 1);
        d *= other;
        const int comp = compare_3way_abs(old_this, d);
        if (rounding_mode == ::tools::rounding_mode::half_down) {
          return comp > 0;
        }
        if (rounding_mode == ::tools::rounding_mode::half_up) {
          return comp >= 0;
        }
        return comp > 0 || (comp == 0 && this->m_unscaled_value[0] % 2 != 0);
      }()) {
        this->m_unscaled_value += ::tools::bigint(old_this.signum() * other.signum());
        this->regularize();
      }

      return *this;
    }
    ::tools::bigdecimal& divide(const ::tools::bigdecimal& other, const ::std::ptrdiff_t scale) {
      return this->divide(other, scale, ::tools::rounding_mode::half_even);
    }
    ::tools::bigdecimal& operator/=(const ::tools::bigdecimal& other) {
      return this->divide(other, this->m_scale - other.m_scale);
    }

    friend ::tools::bigdecimal operator+(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal(lhs) += rhs;
    }
    friend ::tools::bigdecimal operator-(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal(lhs) -= rhs;
    }
    friend ::tools::bigdecimal operator*(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal(lhs) *= rhs;
    }
    ::tools::bigdecimal divide_and_copy(const ::tools::bigdecimal& other, const ::std::ptrdiff_t scale, const ::tools::rounding_mode rounding_mode) const {
      return ::tools::bigdecimal(*this).divide(other, scale, rounding_mode);
    }
    ::tools::bigdecimal divide_and_copy(const ::tools::bigdecimal& other, const ::std::ptrdiff_t scale) const {
      return ::tools::bigdecimal(*this).divide(other, scale);
    }
    friend ::tools::bigdecimal operator/(const ::tools::bigdecimal& lhs, const ::tools::bigdecimal& rhs) {
      return ::tools::bigdecimal(lhs) /= rhs;
    }

    template <typename T, ::std::enable_if_t<::std::is_integral_v<T>, ::std::nullptr_t> = nullptr>
    explicit operator T() const {
      auto x = *this;
      x.set_scale(0);
      return static_cast<T>(x.m_unscaled_value);
    }

    explicit operator double() const {
      long double result = 0.0;
      const ::std::size_t precision = this->precision();
      for (::std::size_t i = 0; i < ::std::numeric_limits<long double>::digits10; ++i) {
        result = result * 10.0L + (precision >= i + 1 ? this->m_unscaled_value[precision - 1 - i] : 0) * this->signum();
      }
      result *= ::std::pow(10.0L, static_cast<long double>(precision) - static_cast<long double>(this->m_scale) - static_cast<long double>(::std::numeric_limits<long double>::digits10));
      return static_cast<double>(result);
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::bigdecimal& self) {
      ::std::string s;
      is >> s;
      self = ::tools::bigdecimal(s);
      return is;
    }
    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::bigdecimal& self) {
      if (self.signum() < 0) {
        os << '-';
      }
      for (auto i = ::std::max(::tools::ssize(self.m_unscaled_value) - 1, self.m_scale); i >= ::std::min<::std::ptrdiff_t>(0, self.m_scale); --i) {
        if (i == self.m_scale - 1) {
          os << '.';
        }
        os << (0 <= i && i < ::tools::ssize(self.m_unscaled_value) ? self.m_unscaled_value[i] : 0);
      }
      return os;
    }
  };
}

#endif
