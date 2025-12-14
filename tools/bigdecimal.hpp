#ifndef TOOLS_BIGDECIMAL_HPP
#define TOOLS_BIGDECIMAL_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cmath>
#include <compare>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>
#include "tools/abs.hpp"
#include "tools/bigint.hpp"
#include "tools/getter_result.hpp"
#include "tools/integral.hpp"
#include "tools/non_bool_integral.hpp"
#include "tools/rounding_mode.hpp"
#include "tools/signum.hpp"

namespace tools {
  class bigdecimal;

  template <>
  struct detail::abs::impl<tools::bigdecimal> {
    tools::bigdecimal operator()(auto&&) const;
  };
  template <>
  struct detail::signum::impl<tools::bigdecimal> {
    int operator()(const tools::bigdecimal&) const;
  };

  class bigdecimal {
    // *this := this->m_unscaled_value * (10 ** -this->m_scale)
    tools::bigint m_unscaled_value;
    std::ptrdiff_t m_scale;

  public:
    bigdecimal() : m_unscaled_value(0), m_scale(0) {
    }
    explicit bigdecimal(tools::integral auto const n) : m_unscaled_value(n), m_scale(0) {
    }
    explicit bigdecimal(const tools::bigint& n) : m_unscaled_value(n), m_scale(0) {
    }
    explicit bigdecimal(std::string s) {
      if (const auto pos = s.find('.'); pos != std::string::npos) {
        this->m_scale = s.size() - pos - 1;
        s.erase(pos, 1);
      } else {
        this->m_scale = 0;
      }
      this->m_unscaled_value = tools::bigint(s);
    }

    auto abs_inplace(this auto&& self) -> decltype(self) {
      if (tools::signum(self) < 0) self.negate();
      return self;
    }
    tools::bigdecimal divide(this auto&& self, const tools::bigdecimal& other, const std::ptrdiff_t scale) {
      if constexpr (std::is_lvalue_reference_v<decltype(self)> || std::is_const_v<std::remove_reference_t<decltype(self)>>) {
        return tools::bigdecimal(self).divide_inplace(other, scale);
      } else {
        self.divide_inplace(other, scale);
        return std::move(self);
      }
    }
    tools::bigdecimal divide(this auto&& self, const tools::bigdecimal& other, const std::ptrdiff_t scale, const tools::rounding_mode rounding_mode) {
      if constexpr (std::is_lvalue_reference_v<decltype(self)> || std::is_const_v<std::remove_reference_t<decltype(self)>>) {
        return tools::bigdecimal(self).divide_inplace(other, scale, rounding_mode);
      } else {
        self.divide_inplace(other, scale, rounding_mode);
        return std::move(self);
      }
    }
    tools::bigdecimal divide_by_pow10(this auto&& self, const std::ptrdiff_t n) {
      return tools::bigdecimal(std::forward<decltype(self)>(self)).divide_inplace_by_pow10(n);
    }
    auto divide_inplace(this auto&& self, const tools::bigdecimal& other, const std::ptrdiff_t scale) -> decltype(self) {
      self.divide_inplace(other, scale, tools::rounding_mode::half_even);
      return self;
    }
    auto divide_inplace(this auto&& self, const tools::bigdecimal& other, const std::ptrdiff_t scale, const tools::rounding_mode rounding_mode) -> decltype(self) {
      assert(tools::signum(other) != 0);

      if (std::addressof(self) == std::addressof(other)) {
        self.m_unscaled_value = tools::bigint(1).multiply_inplace_by_pow10(scale);
        self.m_scale = scale;
        return self;
      }

      tools::bigdecimal old_this(self);

      self.m_unscaled_value.multiply_inplace_by_pow10(scale - (self.m_scale - other.m_scale));
      self.m_unscaled_value /= other.m_unscaled_value;
      self.m_scale = scale;

      if ([&]() {
        if (rounding_mode == tools::rounding_mode::down) {
          return false;
        }
        if (rounding_mode == tools::rounding_mode::ceiling || rounding_mode == tools::rounding_mode::floor || rounding_mode == tools::rounding_mode::up) {
          if ((rounding_mode == tools::rounding_mode::ceiling && tools::signum(old_this) * tools::signum(other) > 0)
            || (rounding_mode == tools::rounding_mode::floor && tools::signum(old_this) * tools::signum(other) < 0)
            || rounding_mode == tools::rounding_mode::up) {
            return (tools::abs(old_this) <=> tools::abs(self * other)) > 0;
          } else {
            return false;
          }
        }

        tools::bigdecimal d(self);
        d += tools::bigdecimal(5 * tools::signum(old_this) * tools::signum(other)).divide_inplace_by_pow10(scale + 1);
        d *= other;
        const auto comp = tools::abs(old_this) <=> tools::abs(std::move(d));
        if (rounding_mode == tools::rounding_mode::half_down) {
          return comp > 0;
        }
        if (rounding_mode == tools::rounding_mode::half_up) {
          return comp >= 0;
        }
        return comp > 0 || (comp == 0 && self.m_unscaled_value[0] % 2 != 0);
      }()) {
        self.m_scale = scale;
        self.m_unscaled_value += tools::bigint(tools::signum(old_this) * tools::signum(other));
      }

      return self;
    }
    auto divide_inplace_by_pow10(this auto&& self, const std::ptrdiff_t n) -> decltype(self) {
      self.multiply_inplace_by_pow10(-n);
      return self;
    }
    tools::bigdecimal multiply_by_pow10(this auto&& self, const std::ptrdiff_t n) {
      return tools::bigdecimal(std::forward<decltype(self)>(self)).multiply_inplace_by_pow10(n);
    }
    auto multiply_inplace_by_pow10(this auto&& self, const std::ptrdiff_t n) -> decltype(self) {
      self.m_scale -= n;
      return self;
    }
    auto negate(this auto&& self) -> decltype(self) {
      self.m_unscaled_value.negate();
      return self;
    }
    std::size_t precision() const {
      return this->m_unscaled_value.size();
    }
    std::ptrdiff_t scale() const {
      return this->m_scale;
    }
    auto set_scale(this auto&& self, const std::ptrdiff_t s) -> decltype(self) {
      self.m_unscaled_value.multiply_inplace_by_pow10(s - self.m_scale);
      self.m_scale = s;
      return self;
    }
    auto unscaled_value(this auto&& self) -> tools::getter_result_t<decltype(self), tools::bigint> {
      return std::forward_like<decltype(self)>(self.m_unscaled_value);
    }

    friend std::weak_ordering operator<=>(const tools::bigdecimal& x, const tools::bigdecimal& y) {
      if (const auto comp = tools::signum(x.m_unscaled_value) <=> tools::signum(y.m_unscaled_value); comp != 0) {
        return comp;
      }
      if (tools::signum(x.m_unscaled_value) == 0) {
        return std::weak_ordering::equivalent;
      }
      const auto comp = tools::abs(x).set_scale(std::max(x.m_scale, y.m_scale)).unscaled_value() <=> tools::abs(y).set_scale(std::max(x.m_scale, y.m_scale)).unscaled_value();
      return tools::signum(x.m_unscaled_value) > 0 ? comp : 0 <=> comp;
    }
    friend bool operator==(const tools::bigdecimal& lhs, const tools::bigdecimal& rhs) {
      return (lhs <=> rhs) == 0;
    }

    tools::bigdecimal operator+(this auto&& self) {
      return std::forward<decltype(self)>(self);
    }
    tools::bigdecimal operator-(this auto&& self) {
      return tools::bigdecimal(std::forward<decltype(self)>(self)).negate();
    }

    auto operator++(this auto&& self) -> decltype(self) {
      self += tools::bigdecimal(1);
      return self;
    }
    tools::bigdecimal operator++(int) {
      tools::bigdecimal old(*this);
      ++(*this);
      return old;
    }
    auto operator--(this auto&& self) -> decltype(self) {
      self -= tools::bigdecimal(1);
      return self;
    }
    tools::bigdecimal operator--(int) {
      tools::bigdecimal old(*this);
      --(*this);
      return old;
    }

    auto operator+=(this auto&& self, tools::bigdecimal other) -> decltype(self) {
      const std::size_t scale = std::max(self.m_scale, other.m_scale);
      self.set_scale(scale);
      other.set_scale(scale);
      self.m_unscaled_value += other.m_unscaled_value;
      return self;
    }
    tools::bigdecimal operator+(this auto&& lhs, const tools::bigdecimal& rhs) {
      if constexpr (std::is_lvalue_reference_v<decltype(lhs)> || std::is_const_v<std::remove_reference_t<decltype(lhs)>>) {
        return tools::bigdecimal(lhs) += rhs;
      } else {
        lhs += rhs;
        return std::move(lhs);
      }
    }

    auto operator-=(this auto&& self, tools::bigdecimal other) -> decltype(self) {
      const std::size_t scale = std::max(self.m_scale, other.m_scale);
      self.set_scale(scale);
      other.set_scale(scale);
      self.m_unscaled_value -= other.m_unscaled_value;
      return self;
    }
    tools::bigdecimal operator-(this auto&& lhs, const tools::bigdecimal& rhs) {
      if constexpr (std::is_lvalue_reference_v<decltype(lhs)> || std::is_const_v<std::remove_reference_t<decltype(lhs)>>) {
        return tools::bigdecimal(lhs) -= rhs;
      } else {
        lhs -= rhs;
        return std::move(lhs);
      }
    }

    auto operator*=(this auto&& self, const tools::bigdecimal& other) -> decltype(self) {
      self.m_unscaled_value *= other.m_unscaled_value;
      self.m_scale += other.m_scale;
      return self;
    }
    tools::bigdecimal operator*(this auto&& lhs, const tools::bigdecimal& rhs) {
      if constexpr (std::is_lvalue_reference_v<decltype(lhs)> || std::is_const_v<std::remove_reference_t<decltype(lhs)>>) {
        return tools::bigdecimal(lhs) *= rhs;
      } else {
        lhs *= rhs;
        return std::move(lhs);
      }
    }

    auto operator/=(this auto&& self, const tools::bigdecimal& other) -> decltype(self) {
      self.divide_inplace(other, self.m_scale - other.m_scale);
      return self;
    }
    tools::bigdecimal operator/(this auto&& lhs, const tools::bigdecimal& rhs) {
      if constexpr (std::is_lvalue_reference_v<decltype(lhs)> || std::is_const_v<std::remove_reference_t<decltype(lhs)>>) {
        return tools::bigdecimal(lhs) /= rhs;
      } else {
        lhs /= rhs;
        return std::move(lhs);
      }
    }

    explicit operator bool() const {
      return tools::signum(*this) != 0;
    }
    template <tools::non_bool_integral T>
    explicit operator T() const {
      auto x = *this;
      x.set_scale(0);
      return static_cast<T>(x.m_unscaled_value);
    }
    explicit operator double() const {
      long double result = 0.0;
      const std::size_t precision = this->precision();
      for (std::size_t i = 0; i < std::numeric_limits<long double>::digits10; ++i) {
        result = result * 10.0L + (precision >= i + 1 ? this->m_unscaled_value[precision - 1 - i] : 0) * tools::signum(*this);
      }
      result *= std::pow(10.0L, static_cast<long double>(precision) - static_cast<long double>(this->m_scale) - static_cast<long double>(std::numeric_limits<long double>::digits10));
      return static_cast<double>(result);
    }

    friend std::istream& operator>>(std::istream& is, tools::bigdecimal& self) {
      std::string s;
      is >> s;
      self = tools::bigdecimal(s);
      return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const tools::bigdecimal& self) {
      if (tools::signum(self) == 0 && self.m_scale <= 0) {
        return os << '0';
      }

      if (tools::signum(self) < 0) {
        os << '-';
      }
      for (auto i = std::max(std::ssize(self.m_unscaled_value) - 1, self.m_scale); i >= std::min<std::ptrdiff_t>(0, self.m_scale); --i) {
        if (i == self.m_scale - 1) {
          os << '.';
        }
        os << (0 <= i && i < std::ssize(self.m_unscaled_value) ? self.m_unscaled_value[i] : 0);
      }
      return os;
    }
  };

  tools::bigdecimal detail::abs::impl<tools::bigdecimal>::operator()(auto&& x) const {
    return tools::bigdecimal(std::forward<decltype(x)>(x)).abs_inplace();
  };
  int detail::signum::impl<tools::bigdecimal>::operator()(const tools::bigdecimal& x) const {
    return tools::signum(x.unscaled_value());
  };
}

#endif
