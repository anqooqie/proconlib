#ifndef TOOLS_SAFE_INT_HPP
#define TOOLS_SAFE_INT_HPP

#include <type_traits>
#include <cstddef>
#include <cassert>
#include <limits>
#include <array>
#include <optional>

namespace tools {
  template <typename T, typename ::std::enable_if<::std::is_signed_v<T>, ::std::nullptr_t>::type = nullptr>
  class safe_int {
  private:
    enum class type {
      finite,
      pos_inf,
      neg_inf,
      nan
    };
    typename ::tools::safe_int<T>::type m_type;
    T m_value;

    constexpr safe_int(const typename ::tools::safe_int<T>::type type) :
      m_type(type), m_value(T()) {
    }

  public:
    constexpr safe_int() :
      m_type(::tools::safe_int<T>::type::finite), m_value(T()) {
    }
    explicit constexpr safe_int(const T value) :
      m_type(::tools::safe_int<T>::type::finite), m_value(value) {
    }
    constexpr safe_int(const ::tools::safe_int<T>& other) :
      m_type(other.m_type), m_value(other.m_value) {
    }
    ~safe_int() = default;
    constexpr ::tools::safe_int<T>& operator=(const ::tools::safe_int<T>& other) {
      this->m_type = other.m_type;
      this->m_value = other.m_value;
    }

    static constexpr ::tools::safe_int<T> infinity() {
      return tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);
    }
    static constexpr ::tools::safe_int<T> nan() {
      return tools::safe_int<T>(::tools::safe_int<T>::type::nan);
    }

  private:
    static constexpr int f1(const ::tools::safe_int<T>& n) {
      switch (n.m_type) {
      case ::tools::safe_int<T>::type::neg_inf:
        return 0;
      case ::tools::safe_int<T>::type::finite:
        return 1;
      case ::tools::safe_int<T>::type::pos_inf:
        return 2;
      default: // nan
        return 3;
      }
    };
    static constexpr int f2(const ::tools::safe_int<T>& n) {
      switch (n.m_type) {
      case ::tools::safe_int<T>::type::neg_inf:
        return 0;
      case ::tools::safe_int<T>::type::finite:
        if (n.m_value < 0) {
          return 1;
        } else if (n.m_value == 0) {
          return 2;
        } else {
          return 3;
        }
      case ::tools::safe_int<T>::type::pos_inf:
        return 4;
      default: // nan
        return 5;
      }
    };
    static constexpr ::std::optional<::tools::safe_int<T>> Q() {
      return ::std::nullopt;
    }
    static constexpr ::std::optional<::tools::safe_int<T>> Z() {
      return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(0));
    }
    static constexpr ::std::optional<::tools::safe_int<T>> N() {
      return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::neg_inf));
    }
    static constexpr ::std::optional<::tools::safe_int<T>> P() {
      return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf));
    }
    static constexpr ::std::optional<::tools::safe_int<T>> U() {
      return ::std::optional<::tools::safe_int<T>>(::tools::safe_int<T>(::tools::safe_int<T>::type::nan));
    }
    static constexpr ::std::optional<bool> BQ() {
      return ::std::nullopt;
    }
    static constexpr ::std::optional<bool> BF() {
      return ::std::optional<bool>(false);
    }
    static constexpr ::std::optional<bool> BT() {
      return ::std::optional<bool>(true);
    }

  public:
    constexpr bool is_finite() const {
      return this->m_type == ::tools::safe_int<T>::type::finite;
    }

    constexpr T val() const {
      assert(this->is_finite());
      return this->m_value;
    }

    friend constexpr bool operator==(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      if (x.is_finite() && y.is_finite()) {
        return x.m_value == y.m_value;
      } else if (!x.is_finite() && !y.is_finite()) {
        return x.m_type == y.m_type;
      } else {
        return false;
      }
    }
    friend constexpr bool operator!=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      return !(x == y);
    }

    constexpr ::tools::safe_int<T> operator+() const {
      return *this;
    }
    constexpr ::tools::safe_int<T> operator-() const {
      const auto r = ::std::array<::std::optional<::tools::safe_int<T>>, 4>({
        {P(), Q(), N(), U()}
      })[f1(*this)];
      if (r) return *r;

      if (this->m_value == ::std::numeric_limits<T>::min()) return *U();
      return ::tools::safe_int<T>(-this->m_value);
    }

    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const auto r = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>, 4>, 4>({{
        {N(), N(), U(), U()},
        {N(), Q(), P(), U()},
        {U(), P(), P(), U()},
        {U(), U(), U(), U()}
      }})[f1(x)][f1(y)];
      if (r) return *r;

      if (y.m_value > 0 && x.m_value > ::std::numeric_limits<T>::max() - y.m_value) return *U();
      if (y.m_value < 0 && x.m_value < ::std::numeric_limits<T>::min() - y.m_value) return *U();
      return ::tools::safe_int<T>(x.m_value + y.m_value);
    }
    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>& x, const T& y) {
      return x + tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator+(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) + y;
    }

    friend constexpr ::tools::safe_int<T> operator-(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const auto r = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>, 4>, 4>({{
        {U(), N(), N(), U()},
        {P(), Q(), N(), U()},
        {P(), P(), U(), U()},
        {U(), U(), U(), U()}
      }})[f1(x)][f1(y)];
      if (r) return *r;

      if (y.m_value < 0 && x.m_value > ::std::numeric_limits<T>::max() + y.m_value) return *U();
      if (y.m_value > 0 && x.m_value < ::std::numeric_limits<T>::min() + y.m_value) return *U();
      return ::tools::safe_int<T>(x.m_value - y.m_value);
    }
    friend constexpr ::tools::safe_int<T> operator-(const ::tools::safe_int<T>& x, const T& y) {
      return x - tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator-(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) - y;
    }

    friend constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const auto r = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>, 6>, 6>({{
        {P(), P(), U(), N(), N(), U()},
        {P(), Q(), Z(), Q(), N(), U()},
        {U(), Z(), Z(), Z(), U(), U()},
        {N(), Q(), Z(), Q(), P(), U()},
        {N(), N(), U(), P(), P(), U()},
        {U(), U(), U(), U(), U(), U()}
      }})[f2(x)][f2(y)];
      if (r) return *r;

      if (x.m_value > 0) {
        if (y.m_value > 0) {
          if (x.m_value > ::std::numeric_limits<T>::max() / y.m_value) {
            return *U();
          }
        } else {
          if (y.m_value < ::std::numeric_limits<T>::min() / x.m_value) {
            return *U();
          }
        }
      } else {
        if (y.m_value > 0) {
          if (x.m_value < ::std::numeric_limits<T>::min() / y.m_value) {
            return *U();
          }
        } else {
          if (x.m_value != 0 && y.m_value < ::std::numeric_limits<T>::max() / x.m_value) {
            return *U();
          }
        }
      }
      return ::tools::safe_int<T>(x.m_value * y.m_value);
    }
    friend constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>& x, const T& y) {
      return x * tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator*(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) * y;
    }

    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const auto r = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>, 6>, 6>({{
        {U(), P(), U(), N(), U(), U()},
        {Z(), Q(), U(), Q(), Z(), U()},
        {Z(), Z(), U(), Z(), Z(), U()},
        {Z(), Q(), U(), Q(), Z(), U()},
        {U(), N(), U(), P(), U(), U()},
        {U(), U(), U(), U(), U(), U()}
      }})[f2(x)][f2(y)];
      if (r) return *r;

      if (x.m_value == ::std::numeric_limits<T>::min() && y.m_value == -1) return *U();
      return ::tools::safe_int<T>(x.m_value / y.m_value);
    }
    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>& x, const T& y) {
      return x / tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator/(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) / y;
    }

    friend constexpr ::tools::safe_int<T> operator%(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const auto r = ::std::array<::std::array<::std::optional<::tools::safe_int<T>>, 6>, 6>({{
        {U(), U(), U(), U(), U(), U()},
        {U(), Q(), U(), Q(), U(), U()},
        {U(), Z(), U(), Z(), U(), U()},
        {U(), Q(), U(), Q(), U(), U()},
        {U(), U(), U(), U(), U(), U()},
        {U(), U(), U(), U(), U(), U()}
      }})[f2(x)][f2(y)];
      if (r) return *r;

      if (x.m_value == ::std::numeric_limits<T>::min() && y.m_value == -1) return *U();
      return ::tools::safe_int<T>(x.m_value % y.m_value);
    }
    friend constexpr ::tools::safe_int<T> operator%(const ::tools::safe_int<T>& x, const T& y) {
      return x % tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator%(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) % y;
    }

    constexpr ::tools::safe_int<T>& operator+=(const ::tools::safe_int<T>& other) {
      return *this = *this + other;
    }
    constexpr ::tools::safe_int<T>& operator+=(const T& other) {
      return *this = *this + ::tools::safe_int<T>(other);
    }
    constexpr ::tools::safe_int<T>& operator-=(const ::tools::safe_int<T>& other) {
      return *this = *this - other;
    }
    constexpr ::tools::safe_int<T>& operator-=(const T& other) {
      return *this = *this - ::tools::safe_int<T>(other);
    }
    constexpr ::tools::safe_int<T>& operator*=(const ::tools::safe_int<T>& other) {
      return *this = *this * other;
    }
    constexpr ::tools::safe_int<T>& operator*=(const T& other) {
      return *this = *this * ::tools::safe_int<T>(other);
    }
    constexpr ::tools::safe_int<T>& operator/=(const ::tools::safe_int<T>& other) {
      return *this = *this / other;
    }
    constexpr ::tools::safe_int<T>& operator/=(const T& other) {
      return *this = *this / ::tools::safe_int<T>(other);
    }
    constexpr ::tools::safe_int<T>& operator%=(const ::tools::safe_int<T>& other) {
      return *this = *this % other;
    }
    constexpr ::tools::safe_int<T>& operator%=(const T& other) {
      return *this = *this % ::tools::safe_int<T>(other);
    }

    friend constexpr bool operator<(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const auto r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{
        {BF(), BT(), BT(), BF()},
        {BF(), BQ(), BT(), BF()},
        {BF(), BF(), BF(), BF()},
        {BF(), BF(), BF(), BF()}
      }})[f1(x)][f1(y)];
      if (r) return *r;

      return x.m_value < y.m_value;
    }
    friend constexpr bool operator>(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const auto r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{
        {BF(), BF(), BF(), BF()},
        {BT(), BQ(), BF(), BF()},
        {BT(), BT(), BF(), BF()},
        {BF(), BF(), BF(), BF()}
      }})[f1(x)][f1(y)];
      if (r) return *r;

      return x.m_value > y.m_value;
    }
    friend constexpr bool operator<=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      return x < y || x == y;
    }
    friend constexpr bool operator>=(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      return x > y || x == y;
    }
  };
}

#endif
