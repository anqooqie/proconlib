#ifndef TOOLS_SAFE_INT_HPP
#define TOOLS_SAFE_INT_HPP

#include <type_traits>
#include <cstddef>
#include <limits>
#include <stdexcept>

namespace tools {
  template <typename T, typename ::std::enable_if<::std::is_signed_v<T>, ::std::nullptr_t>::type = nullptr>
  class safe_int {
  private:
    T m_value;

  public:
    safe_int() = default;
    safe_int(const safe_int&) = default;
    safe_int(safe_int&&) = default;
    ~safe_int() = default;
    safe_int& operator=(const safe_int&) = default;
    safe_int& operator=(safe_int&&) = default;

    safe_int(const T value) : m_value(value) {
    }

    T val() const {
      return this->m_value;
    }

    friend bool operator==(const safe_int<T>& lhs, const safe_int<T>& rhs) {
      return lhs.val() == rhs.val();
    }
    friend bool operator!=(const safe_int<T>& lhs, const safe_int<T>& rhs) {
      return lhs.val() != rhs.val();
    }

    friend safe_int<T> operator+(const safe_int<T>& lhs, const safe_int<T>& rhs) {
      if (lhs.val() == ::std::numeric_limits<T>::min() && rhs.val() == ::std::numeric_limits<T>::max()) throw std::runtime_error("Indefinite.");
      if (lhs.val() == ::std::numeric_limits<T>::max() && rhs.val() == ::std::numeric_limits<T>::min()) throw std::runtime_error("Indefinite.");
      if (lhs.val() == ::std::numeric_limits<T>::min() || rhs.val() == ::std::numeric_limits<T>::min()) return safe_int<T>(::std::numeric_limits<T>::min());
      if (lhs.val() == ::std::numeric_limits<T>::max() || rhs.val() == ::std::numeric_limits<T>::max()) return safe_int<T>(::std::numeric_limits<T>::max());
      if (rhs.val() > 0 && lhs.val() > ::std::numeric_limits<T>::max() - rhs.val()) return safe_int<T>(::std::numeric_limits<T>::max());
      if (rhs.val() < 0 && lhs.val() < ::std::numeric_limits<T>::min() - rhs.val()) return safe_int<T>(::std::numeric_limits<T>::min());
      return safe_int<T>(lhs.val() + rhs.val());
    }
    template <typename U, typename ::std::enable_if<!::std::is_same<U, safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend safe_int<T> operator+(const U& lhs, const safe_int<T>& rhs) {
      return safe_int<T>(lhs) + rhs;
    }
    template <typename U, typename ::std::enable_if<!::std::is_same<U, safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend safe_int<T> operator+(const safe_int<T>& lhs, const U& rhs) {
      return lhs + safe_int<T>(rhs);
    }

    friend safe_int<T> operator-(const safe_int<T>& lhs, const safe_int<T>& rhs) {
      if (lhs.val() == ::std::numeric_limits<T>::max() && rhs.val() == ::std::numeric_limits<T>::max()) throw std::runtime_error("Indefinite.");
      if (lhs.val() == ::std::numeric_limits<T>::min() && rhs.val() == ::std::numeric_limits<T>::min()) throw std::runtime_error("Indefinite.");
      if (lhs.val() == ::std::numeric_limits<T>::max() || rhs.val() == ::std::numeric_limits<T>::min()) return safe_int<T>(::std::numeric_limits<T>::max());
      if (lhs.val() == ::std::numeric_limits<T>::min() || rhs.val() == ::std::numeric_limits<T>::max()) return safe_int<T>(::std::numeric_limits<T>::min());
      if (rhs.val() < 0 && lhs.val() > ::std::numeric_limits<T>::max() + rhs.val()) return safe_int<T>(::std::numeric_limits<T>::max());
      if (rhs.val() > 0 && lhs.val() < ::std::numeric_limits<T>::min() + rhs.val()) return safe_int<T>(::std::numeric_limits<T>::min());
      return safe_int<T>(lhs.val() - rhs.val());
    }
    template <typename U, typename ::std::enable_if<!::std::is_same<U, safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend safe_int<T> operator-(const U& lhs, const safe_int<T>& rhs) {
      return safe_int<T>(lhs) - rhs;
    }
    template <typename U, typename ::std::enable_if<!::std::is_same<U, safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend safe_int<T> operator-(const safe_int<T>& lhs, const U& rhs) {
      return lhs - safe_int<T>(rhs);
    }

    friend safe_int<T> operator*(const safe_int<T>& lhs, const safe_int<T>& rhs) {
      if (lhs.val() == 0 || rhs.val() == 0) return safe_int<T>(0);
      if (lhs.val() == ::std::numeric_limits<T>::min() || lhs.val() == ::std::numeric_limits<T>::max() || rhs.val() == ::std::numeric_limits<T>::min() || rhs.val() == ::std::numeric_limits<T>::max()) {
        if ((lhs.val() > 0) == (rhs.val() > 0)) return safe_int<T>(::std::numeric_limits<T>::max());
        else return safe_int<T>(::std::numeric_limits<T>::min());
      }
      if (lhs.val() > 0) {
        if (rhs.val() > 0) {
          if (lhs.val() > ::std::numeric_limits<T>::max() / rhs.val()) {
            return safe_int<T>(::std::numeric_limits<T>::max());
          }
        } else {
          if (rhs.val() < ::std::numeric_limits<T>::min() / lhs.val()) {
            return safe_int<T>(::std::numeric_limits<T>::min());
          }
        }
      } else {
        if (rhs.val() > 0) {
          if (lhs.val() < ::std::numeric_limits<T>::min() / rhs.val()) {
            return safe_int<T>(::std::numeric_limits<T>::min());
          }
        } else {
          if (lhs.val() != 0 && rhs.val() < ::std::numeric_limits<T>::max() / lhs.val()) {
            return safe_int<T>(::std::numeric_limits<T>::max());
          }
        }
      }
      return safe_int<T>(lhs.val() * rhs.val());
    }
    template <typename U, typename ::std::enable_if<!::std::is_same<U, safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend safe_int<T> operator*(const U& lhs, const safe_int<T>& rhs) {
      return safe_int<T>(lhs) * rhs;
    }
    template <typename U, typename ::std::enable_if<!::std::is_same<U, safe_int<T>>::value, ::std::nullptr_t>::type = nullptr>
    friend safe_int<T> operator*(const safe_int<T>& lhs, const U& rhs) {
      return lhs * safe_int<T>(rhs);
    }
  };
}

#endif
