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

    constexpr safe_int(const type type) :
      m_type(type), m_value(T()) {
    }

    static constexpr ::tools::safe_int<T> pos_inf = tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);
    static constexpr ::tools::safe_int<T> neg_inf = tools::safe_int<T>(::tools::safe_int<T>::type::neg_inf);

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

    static constexpr ::tools::safe_int<T> infinity = tools::safe_int<T>(::tools::safe_int<T>::type::pos_inf);
    static constexpr ::tools::safe_int<T> nan = tools::safe_int<T>(::tools::safe_int<T>::type::nan);

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
    static constexpr ::tools::safe_int<T> g1(int i) {
      return ::std::array<::tools::safe_int<T>, 4>({
        ::tools::safe_int<T>::neg_inf,
        ::tools::safe_int<T>(),
        ::tools::safe_int<T>::pos_inf,
        ::tools::safe_int<T>::nan
      })[i];
    }
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
    static constexpr ::tools::safe_int<T> g2(int i) {
      return ::std::array<::tools::safe_int<T>, 6>({
        ::tools::safe_int<T>::neg_inf,
        ::tools::safe_int<T>(),
        ::tools::safe_int<T>(0),
        ::tools::safe_int<T>(),
        ::tools::safe_int<T>::pos_inf,
        ::tools::safe_int<T>::nan
      })[i];
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
      switch (this->m_type) {
      case ::tools::safe_int<T>::type::finite:
        return this->m_value == ::std::numeric_limits<T>::min()
          ? ::tools::safe_int<T>::nan
          : ::tools::safe_int<T>(-this->m_value);
      case ::tools::safe_int<T>::type::pos_inf:
        return ::tools::safe_int<T>::neg_inf;
      case ::tools::safe_int<T>::type::neg_inf:
        return ::tools::safe_int<T>::pos_inf;
      default: // nan
        return ::tools::safe_int<T>::nan;
      }
    }

    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const int NI = 0;
      const int F = 1;
      const int PI = 2;
      const int U = 3;
      const int r = ::std::array<::std::array<int, 4>, 4>({{
        {NI, NI,  U,  U},
        {NI,  F, PI,  U},
        { U, PI, PI,  U},
        { U,  U,  U,  U}
      }})[f1(x)][f1(y)];
      if (r == F) {
        if (y.m_value > 0 && x.m_value > ::std::numeric_limits<T>::max() - y.m_value) return g1(U);
        if (y.m_value < 0 && x.m_value < ::std::numeric_limits<T>::min() - y.m_value) return g1(U);
        return ::tools::safe_int<T>(x.m_value + y.m_value);
      } else {
        return g1(r);
      }
    }
    friend constexpr ::tools::safe_int<T> operator+(const ::tools::safe_int<T>& x, const T& y) {
      return x + tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator+(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) + y;
    }

    friend constexpr ::tools::safe_int<T> operator-(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const int NI = 0;
      const int F = 1;
      const int PI = 2;
      const int U = 3;
      const int r = ::std::array<::std::array<int, 4>, 4>({{
        { U, NI, NI,  U},
        {PI,  F, NI,  U},
        {PI, PI,  U,  U},
        { U,  U,  U,  U}
      }})[f1(x)][f1(y)];
      if (r == F) {
        if (y.m_value < 0 && x.m_value > ::std::numeric_limits<T>::max() + y.m_value) return g1(U);
        if (y.m_value > 0 && x.m_value < ::std::numeric_limits<T>::min() + y.m_value) return g1(U);
        return ::tools::safe_int<T>(x.m_value - y.m_value);
      } else {
        return g1(r);
      }
    }
    friend constexpr ::tools::safe_int<T> operator-(const ::tools::safe_int<T>& x, const T& y) {
      return x - tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator-(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) - y;
    }

    friend constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const int NI = 0;
      const int NF = 1;
      const int Z = 2;
      const int PF = 3;
      const int PI = 4;
      const int U = 5;
      const int r = ::std::array<::std::array<int, 6>, 6>({{
        {PI, PI,  U, NI, NI,  U},
        {PI, PF,  Z, NF, NI,  U},
        { U,  Z,  Z,  Z,  U,  U},
        {NI, NF,  Z, PF, PI,  U},
        {NI, NI,  U, PI, PI,  U},
        { U,  U,  U,  U,  U,  U}
      }})[f2(x)][f2(y)];
      if (r == NF || r == PF) {
        if (x.m_value > 0) {
          if (y.m_value > 0) {
            if (x.m_value > ::std::numeric_limits<T>::max() / y.m_value) {
              return g2(U);
            }
          } else {
            if (y.m_value < ::std::numeric_limits<T>::min() / x.m_value) {
              return g2(U);
            }
          }
        } else {
          if (y.m_value > 0) {
            if (x.m_value < ::std::numeric_limits<T>::min() / y.m_value) {
              return g2(U);
            }
          } else {
            if (x.m_value != 0 && y.m_value < ::std::numeric_limits<T>::max() / x.m_value) {
              return g2(U);
            }
          }
        }
        return ::tools::safe_int<T>(x.m_value * y.m_value);
      } else {
        return g2(r);
      }
    }
    friend constexpr ::tools::safe_int<T> operator*(const ::tools::safe_int<T>& x, const T& y) {
      return x * tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator*(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) * y;
    }

    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const int NI = 0;
      const int NF = 1;
      const int Z = 2;
      const int PF = 3;
      const int PI = 4;
      const int U = 5;
      const int r = ::std::array<::std::array<int, 6>, 6>({{
        { U, PI,  U, NI,  U,  U},
        { Z, PF,  U, NF,  Z,  U},
        { Z,  Z,  U,  Z,  Z,  U},
        { Z, NF,  U, PF,  Z,  U},
        { U, NI,  U, PI,  U,  U},
        { U,  U,  U,  U,  U,  U}
      }})[f2(x)][f2(y)];
      if (r == NF || r == PF) {
        if (x.m_value == ::std::numeric_limits<T>::min() && y.m_value == -1) return g2(U);
        return ::tools::safe_int<T>(x.m_value / y.m_value);
      } else {
        return g2(r);
      }
    }
    friend constexpr ::tools::safe_int<T> operator/(const ::tools::safe_int<T>& x, const T& y) {
      return x / tools::safe_int<T>(y);
    }
    friend constexpr ::tools::safe_int<T> operator/(const T& x, const ::tools::safe_int<T>& y) {
      return tools::safe_int<T>(x) / y;
    }

    friend constexpr ::tools::safe_int<T> operator%(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const int NF = 1;
      const int Z = 2;
      const int PF = 3;
      const int U = 5;
      const int r = ::std::array<::std::array<int, 6>, 6>({{
        { U,  U,  U,  U,  U,  U},
        { U, NF,  U, NF,  U,  U},
        { U,  Z,  U,  Z,  U,  U},
        { U, PF,  U, PF,  U,  U},
        { U,  U,  U,  U,  U,  U},
        { U,  U,  U,  U,  U,  U}
      }})[f2(x)][f2(y)];
      if (r == NF || r == PF) {
        if (x.m_value == ::std::numeric_limits<T>::min() && y.m_value == -1) return g2(U);
        return ::tools::safe_int<T>(x.m_value % y.m_value);
      } else {
        return g2(r);
      }
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
      const ::std::optional<bool> FALSE = ::std::make_optional(false);
      const ::std::optional<bool> TRUE = ::std::make_optional(true);
      const ::std::optional<bool> UNKNOWN = ::std::nullopt;
      const ::std::optional<bool> r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{
        {FALSE,    TRUE,  TRUE, FALSE},
        {FALSE, UNKNOWN,  TRUE, FALSE},
        {FALSE,   FALSE, FALSE, FALSE},
        {FALSE,   FALSE, FALSE, FALSE}
      }})[f1(x)][f1(y)];
      if (!r) {
        return x.m_value < y.m_value;
      } else {
        return *r;
      }
    }
    friend constexpr bool operator>(const ::tools::safe_int<T>& x, const ::tools::safe_int<T>& y) {
      const ::std::optional<bool> FALSE = ::std::make_optional(false);
      const ::std::optional<bool> TRUE = ::std::make_optional(true);
      const ::std::optional<bool> UNKNOWN = ::std::nullopt;
      const ::std::optional<bool> r = ::std::array<::std::array<::std::optional<bool>, 4>, 4>({{
        {FALSE,   FALSE, FALSE, FALSE},
        { TRUE, UNKNOWN, FALSE, FALSE},
        { TRUE,    TRUE, FALSE, FALSE},
        {FALSE,   FALSE, FALSE, FALSE}
      }})[f1(x)][f1(y)];
      if (!r) {
        return x.m_value > y.m_value;
      } else {
        return *r;
      }
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
