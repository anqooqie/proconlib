#ifndef TOOLS_BIGINT_HPP
#define TOOLS_BIGINT_HPP

#include <vector>
#include <cstdint>
#include <array>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <cmath>
#include <string>
#include <cassert>
#include <utility>
#include <iostream>
#include <iomanip>
#include "atcoder/modint.hpp"
#include "atcoder/convolution.hpp"
#include "tools/quo.hpp"
#include "tools/mod.hpp"
#include "tools/ceil.hpp"
#include "tools/garner2.hpp"
#include "tools/pow2.hpp"
#include "tools/ssize.hpp"

namespace tools {
  class bigint {
  private:
    using mint1 = ::atcoder::static_modint<167772161>;
    using mint2 = ::atcoder::static_modint<469762049>;

    bool m_positive;
    ::std::vector<::std::int_fast32_t> m_digits;
    static constexpr ::std::int_fast32_t BASE = 10000;
    static constexpr ::std::int_fast32_t LOG10_BASE = 4;
    static constexpr ::std::array<::std::int_fast32_t, 5> POW10 = {1, 10, 100, 1000, 10000};

    static int compare_3way(const ::std::size_t lhs, const ::std::size_t rhs) {
      if (lhs < rhs) return -1;
      if (lhs == rhs) return 0;
      return 1;
    }
    static int compare_3way_abs(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      if (const auto comp = ::tools::bigint::compare_3way(lhs.m_digits.size(), rhs.m_digits.size()); comp != 0) {
        return comp;
      }
      for (::std::size_t i = 0; i < lhs.m_digits.size(); ++i) {
        if (const auto comp = ::tools::bigint::compare_3way(lhs.m_digits[lhs.m_digits.size() - 1 - i], rhs.m_digits[rhs.m_digits.size() - 1 - i]); comp != 0) {
          return comp;
        }
      }
      return 0;
    }

    ::tools::bigint& regularize(const int level) {
      if (level > 0) {
        if (level == 2) {
          for (::std::size_t i = 0; i + 1 < this->m_digits.size(); ++i) {
            this->m_digits[i + 1] += ::tools::quo(this->m_digits[i], BASE);
            this->m_digits[i] = ::tools::mod(this->m_digits[i], BASE);
          }
        } else {
          for (::std::size_t i = 0; i + 1 < this->m_digits.size(); ++i) {
            if (this->m_digits[i] < 0) {
              this->m_digits[i] += BASE;
              --this->m_digits[i + 1];
            } else if (this->m_digits[i] >= BASE) {
              this->m_digits[i] -= BASE;
              ++this->m_digits[i + 1];
            }
          }
        }
        if (!this->m_digits.empty() && this->m_digits.back() < 0) {
          this->m_positive = !this->m_positive;
          for (::std::size_t i = 0; i < this->m_digits.size(); ++i) {
            this->m_digits[i] = -this->m_digits[i];
          }
          for (::std::size_t i = 0; i + 1 < this->m_digits.size(); ++i) {
            if (this->m_digits[i] < 0) {
              this->m_digits[i] = BASE + this->m_digits[i];
              --this->m_digits[i + 1];
            }
          }
        }
        if (level == 2) {
          while (!this->m_digits.empty() && this->m_digits.back() >= BASE) {
            this->m_digits.push_back(this->m_digits.back() / BASE);
            this->m_digits[this->m_digits.size() - 2] %= BASE;
          }
        } else {
          if (!this->m_digits.empty() && this->m_digits.back() >= BASE) {
            this->m_digits.back() -= BASE;
            this->m_digits.push_back(1);
          }
        }
      }
      while (!this->m_digits.empty() && this->m_digits.back() == 0) {
        this->m_digits.pop_back();
      }
      if (this->m_digits.empty() && !this->m_positive) {
        this->m_positive = true;
      }
      return *this;
    }

  public:
    ::tools::bigint& negate() {
      if (!this->m_digits.empty()) {
        this->m_positive = !this->m_positive;
      }
      return *this;
    }
    ::tools::bigint abs() const {
      ::tools::bigint result(*this);
      if (!result.m_positive) result.negate();
      return result;
    }
    ::tools::bigint& multiply_by_pow10(const ::std::ptrdiff_t exponent) {
      if (!this->m_digits.empty()) {
        const ::std::ptrdiff_t exponent10000 = ::tools::floor(exponent, LOG10_BASE);
        ::std::int_fast32_t mod = 0;
        if (exponent10000 > 0) {
          ::std::vector<::std::int_fast32_t> zero(exponent10000, 0);
          this->m_digits.insert(this->m_digits.begin(), zero.begin(), zero.end());
        } else if (exponent10000 < 0) {
          mod = this->m_digits[0] / POW10[LOG10_BASE * (exponent10000 + 1) - exponent] % POW10[exponent - LOG10_BASE * exponent10000];
          this->m_digits.erase(this->m_digits.begin(), this->m_digits.begin() + ::std::min<::std::size_t>(-exponent10000, this->m_digits.size()));
        }
        if (const ::std::int_fast32_t coefficient = POW10[exponent - LOG10_BASE * exponent10000]; coefficient > POW10[0]) {
          for (auto& d : this->m_digits) {
            d *= coefficient;
          }
          if (mod > 0 && this->m_digits.empty()) {
            this->m_digits.push_back(0);
          }
          this->m_digits[0] += mod;
          this->regularize(2);
        } else {
          this->regularize(0);
        }
      }
      return *this;
    }
    ::tools::bigint& divide_by_pow10(const ::std::ptrdiff_t exponent) {
      this->multiply_by_pow10(-exponent);
      return *this;
    }
    static int compare_3way(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      if (!lhs.m_positive && rhs.m_positive) return -1;
      if (lhs.m_positive && !rhs.m_positive) return 1;
      return ::tools::bigint::compare_3way_abs(lhs, rhs) * (lhs.m_positive ? 1 : -1);
    }
    int signum() const {
      if (!this->m_positive) return -1;
      if (this->m_digits.empty()) return 0;
      return 1;
    }
    ::std::size_t size() const {
      if (this->m_digits.empty()) return 0;
      return LOG10_BASE * (this->m_digits.size() - 1) + ::std::distance(POW10.begin(), ::std::upper_bound(POW10.begin(), POW10.end(), this->m_digits[this->m_digits.size() - 1]));
    }
    ::std::int_fast32_t operator[](const ::std::size_t i) const {
      return i < LOG10_BASE * this->m_digits.size() ? this->m_digits[i / LOG10_BASE] / POW10[i % LOG10_BASE] % 10 : 0;
    }

  private:
    ::tools::bigint& internal_add(const ::tools::bigint& other, const bool plus) {
      const bool this_positive = this->m_positive;
      if (!this_positive) {
        this->negate();
      }
      this->m_digits.resize(::std::max(this->m_digits.size(), other.m_digits.size()));
      if (this_positive == (other.m_positive == plus)) {
        for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {
          this->m_digits[i] += other.m_digits[i];
        }
      } else {
        for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {
          this->m_digits[i] -= other.m_digits[i];
        }
      }
      this->regularize(1);
      if (!this_positive) {
        this->negate();
      }
      return *this;
    }

  public:
    bigint() : m_positive(true) {
    }
    bigint(const ::tools::bigint&) = default;
    bigint(::tools::bigint&&) = default;
    ~bigint() = default;
    ::tools::bigint& operator=(const ::tools::bigint&) = default;
    ::tools::bigint& operator=(::tools::bigint&&) = default;

    template <typename T, typename ::std::enable_if<::std::is_integral_v<T>, ::std::nullptr_t>::type = nullptr>
    explicit bigint(T n) : m_positive(n >= 0) {
      while (n != 0) {
        this->m_digits.push_back(::std::abs(n % BASE));
        n /= BASE;
      } 
    }
    explicit bigint(const ::std::string& s) {
      assert(!s.empty());

      ::std::size_t offset;
      if (s[0] == '+') {
        this->m_positive = true;
        offset = 1;
      } else if (s[0] == '-') {
        this->m_positive = false;
        offset = 1;
      } else {
        this->m_positive = true;
        offset = 0;
      }

      this->m_digits.reserve(::tools::ceil<::std::size_t>(s.size() - offset, LOG10_BASE));
      for (::std::size_t i = 0; i < s.size() - offset; i += LOG10_BASE) {
        this->m_digits.push_back(0);
        for (::std::size_t j = ::std::min(i + LOG10_BASE, s.size() - offset); j --> i;) {
          assert('0' <= s[s.size() - 1 - j] && s[s.size() - 1 - j] <= '9');
          this->m_digits.back() = this->m_digits.back() * 10 + (s[s.size() - 1 - j] - '0');
        }
      }

      this->regularize(0);
    }

    friend bool operator==(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return lhs.m_positive == rhs.m_positive && lhs.m_digits == rhs.m_digits;
    }
    friend bool operator!=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return !(lhs == rhs);
    }
    friend bool operator<(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint::compare_3way(lhs, rhs) < 0;
    }
    friend bool operator>(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint::compare_3way(lhs, rhs) > 0;
    }
    friend bool operator<=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint::compare_3way(lhs, rhs) <= 0;
    }
    friend bool operator>=(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint::compare_3way(lhs, rhs) >= 0;
    }

    ::tools::bigint operator+() const {
      return *this;
    }
    ::tools::bigint operator-() const {
      return ::tools::bigint(*this).negate();
    }

    ::tools::bigint& operator+=(const ::tools::bigint& other) {
      return this->internal_add(other, true);
    }
    ::tools::bigint& operator-=(const ::tools::bigint& other) {
      return this->internal_add(other, false);
    }
    ::tools::bigint& operator*=(const ::tools::bigint& other) {
      // Constraint derived from atcoder::convolution
      assert(this->m_digits.size() + other.m_digits.size() <= ::tools::pow2(25) + 1);

      ::std::vector<mint1> a1, b1;
      ::std::vector<mint2> a2, b2;
      a1.reserve(this->m_digits.size());
      a2.reserve(this->m_digits.size());
      b1.reserve(other.m_digits.size());
      b2.reserve(other.m_digits.size());
      for (const auto a_i : this->m_digits) {
        a1.push_back(mint1::raw(a_i));
        a2.push_back(mint2::raw(a_i));
      }
      for (const auto b_i : other.m_digits) {
        b1.push_back(mint1::raw(b_i));
        b2.push_back(mint2::raw(b_i));
      }

      const auto c1 = ::atcoder::convolution(a1, b1);
      const auto c2 = ::atcoder::convolution(a2, b2);

      this->m_digits.clear();
      this->m_digits.reserve(c1.size() + 1);
      ::std::int_fast64_t carry = 0;
      for (::std::size_t i = 0; i < c1.size(); ++i) {

        // Since a_i <= 10^4 - 1 and b_i <= 10^4 - 1, c_i <= (10^4 - 1)^2 * min(this->m_digits.size(), other.m_digits.size()) holds.
        // In addition, since this->m_digits.size() + other.m_digits.size() <= 2^25 + 1, c_i <= (10^4 - 1)^2 * 2^24 = 1677386072457216 holds eventually.
        // 1677386072457216 < 167772161 * 469762049 = 78812994116517889 holds, so we can reconstruct c_i from mod(c_i, 167772161) and mod(c_i, 469762049) by CRT.
        ::std::int_fast64_t c_i = ::tools::garner2(c1[i], c2[i]);

        c_i += carry;
        carry = c_i / BASE;
        c_i %= BASE;
        this->m_digits.push_back(c_i);
      }
      if (carry > 0) {
        this->m_digits.push_back(carry);
      }

      this->m_positive = this->m_positive == other.m_positive;
      this->regularize(0);
      return *this;
    }

    friend ::tools::bigint operator+(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint(lhs) += rhs;
    }
    friend ::tools::bigint operator-(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint(lhs) -= rhs;
    }
    friend ::tools::bigint operator*(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint(lhs) *= rhs;
    }

    ::tools::bigint& operator++() {
      return *this += ::tools::bigint(1);
    }
    ::tools::bigint operator++(int) {
      ::tools::bigint old(*this);
      ++(*this);
      return old;
    }
    ::tools::bigint& operator--() {
      return *this -= ::tools::bigint(1);
    }
    ::tools::bigint operator--(int) {
      ::tools::bigint old(*this);
      --(*this);
      return old;
    }

    ::tools::bigint& operator/=(const ::tools::bigint& other) {
      assert(other.signum() != 0);
      if (::tools::bigint::compare_3way_abs(*this, other) < 0) {
        this->m_digits.clear();
        this->m_positive = true;        
        return *this;
      }
      if (other.m_digits.size() == 1 && other.m_digits[0] == 1) {
        this->m_positive = (this->m_positive == other.m_positive);
        return *this;
      }

      using bigdecimal = ::std::pair<::tools::bigint, ::std::ptrdiff_t>;
      static const auto precision = [](const bigdecimal& x) {
        return x.first.m_digits.size();
      };
      static const auto regularize = [](bigdecimal& x) -> bigdecimal& {
        if (x.first.m_digits.empty()) {
          x.second = 0;
        }
        return x;
      };
      static const auto negate = [](bigdecimal& x) -> bigdecimal& {
        x.first.negate();
        return x;
      };
      static const auto make_abs = [](bigdecimal& x) -> bigdecimal& {
        if (!x.first.m_positive) {
          negate(x);
        }
        return x;
      };
      static const auto set_precision = [](bigdecimal& x, const ::std::size_t p) -> bigdecimal& {
        const ::std::ptrdiff_t diff = ::std::ptrdiff_t(p) - ::std::ptrdiff_t(precision(x));
        x.first.multiply_by_pow10(diff * LOG10_BASE);
        x.second -= diff;
        regularize(x);
        return x;
      };
      static const auto plus = [](bigdecimal& x, bigdecimal& y) -> bigdecimal& {
        if (x.second < y.second) {
          set_precision(y, precision(y) + (y.second - x.second));
        } else if (x.second > y.second) {
          set_precision(x, precision(x) + (x.second - y.second));
        }
        x.first += y.first;
        regularize(x);
        return x;
      };
      static const auto multiplies = [](bigdecimal& x, const bigdecimal& y) -> bigdecimal& {
        x.first *= y.first;
        x.second += y.second;
        regularize(x);
        return x;
      };
      static const auto compare_3way = [](const bigdecimal& x, const bigdecimal& y) {
        if (!x.first.m_positive && y.first.m_positive) return -1;
        if (x.first.m_positive && !y.first.m_positive) return 1;
        return [&]() {
          if (x.second <= y.second) {
            if (const auto comp = ::tools::bigint::compare_3way(precision(x), precision(y) + (y.second - x.second)); comp != 0) {
              return comp;
            }
            for (::std::size_t i = 0; i < precision(x); ++i) {
              if (const auto comp = ::tools::bigint::compare_3way(x.first.m_digits[precision(x) - 1 - i], precision(y) >= i + 1 ? y.first.m_digits[precision(y) - 1 - i] : 0); comp != 0) {
                return comp;
              }
            }
          } else {
            if (const auto comp = ::tools::bigint::compare_3way(precision(x) + (x.second - y.second), precision(y)); comp != 0) {
              return comp;
            }
            for (::std::size_t i = 0; i < precision(y); ++i) {
              if (const auto comp = ::tools::bigint::compare_3way(precision(x) >= i + 1 ? x.first.m_digits[precision(x) - 1 - i] : 0, y.first.m_digits[precision(y) - 1 - i]); comp != 0) {
                return comp;
              }
            }
          }
          return 0;
        }() * (x.first.m_positive ? 1 : -1);
      };

      const bool r_positive = this->m_positive == other.m_positive;
      if (!this->m_positive) {
        this->negate();
      }
      const ::std::size_t inv_final_goal_precision = ::std::max(other.m_digits.size(), this->m_digits.size() - other.m_digits.size()) + 1;
      const ::std::size_t inv_first_goal_precision = ::std::min<::std::size_t>(inv_final_goal_precision, 3);

      bigdecimal o(other, 0);
      make_abs(o);
      set_precision(o, ::std::min<::std::size_t>(other.m_digits.size(), 6));
      bigdecimal prev_inv(::tools::bigint(0), 0);
      bigdecimal inv(::tools::bigint(1), -::tools::ssize(other.m_digits));

      while (compare_3way(prev_inv, inv) != 0) {
        prev_inv = inv;
        negate(inv);
        multiplies(inv, o);
        bigdecimal two(::tools::bigint(2), 0);
        plus(inv, two);
        multiplies(inv, prev_inv);
        set_precision(inv, ::std::min(precision(inv), inv_first_goal_precision));
      }

      if (inv_first_goal_precision < inv_final_goal_precision) {
        prev_inv = bigdecimal(::tools::bigint(0), 0);
        while (compare_3way(prev_inv, inv) != 0) {
          prev_inv = inv;
          negate(inv);
          multiplies(inv, o);
          bigdecimal two(::tools::bigint(2), 0);
          plus(inv, two);
          multiplies(inv, prev_inv);
          set_precision(inv, ::std::min(precision(prev_inv) * 2, inv_final_goal_precision));

          const ::std::size_t o_precision = precision(o);
          o = bigdecimal(other, 0);
          make_abs(o);
          set_precision(o, ::std::min(o_precision * 2, other.m_digits.size()));
        }
      }

      set_precision(inv, inv_final_goal_precision);
      o = bigdecimal(other, 0);
      make_abs(o);
      bigdecimal r(*this, 0);
      multiplies(r, inv);
      set_precision(r, precision(r) + r.second);

      ::tools::bigint r_plus_1 = r.first + ::tools::bigint(1);
      if (*this >= r_plus_1 * o.first) {
        *this = ::std::move(r_plus_1);
      } else {
        *this = ::std::move(r.first);
      }

      this->m_positive = r_positive;
      return *this;
    }
    friend ::tools::bigint operator/(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint(lhs) /= rhs;
    }
    ::tools::bigint& operator%=(const ::tools::bigint& other) {
      // 3 = 10000^floor_log10000(((max value of uint64_t) - 9999) / 10000)
      if (other.m_digits.size() <= 3) {
        using u64 = ::std::uint_fast64_t;

        u64 mod = 0;
        for (::std::size_t i = other.m_digits.size(); i --> 0;) {
          mod *= BASE;
          mod += other.m_digits[i];
        }

        u64 result = 0;
        for (::std::size_t i = this->m_digits.size(); i --> 0;) {
          result *= BASE;
          result += this->m_digits[i];
          result %= mod;
        }

        this->m_digits.clear();
        while (result > 0) {
          this->m_digits.push_back(result % BASE);
          result /= BASE;
        }

        return this->regularize(0);
      }

      // 8 = 10000^floor_log10000(((max value of uint128_t) - 9999) / 10000)
      if (other.m_digits.size() <= 8) {
        using u128 = unsigned __int128;

        u128 mod = 0;
        for (::std::size_t i = other.m_digits.size(); i --> 0;) {
          mod *= BASE;
          mod += other.m_digits[i];
        }

        u128 result = 0;
        for (::std::size_t i = this->m_digits.size(); i --> 0;) {
          result *= BASE;
          result += this->m_digits[i];
          result %= mod;
        }

        this->m_digits.clear();
        while (result > 0) {
          this->m_digits.push_back(result % BASE);
          result /= BASE;
        }

        return this->regularize(0);
      }

      const ::tools::bigint self = *this;
      *this /= other;
      this->negate();
      *this *= other;
      *this += self;
      return *this;
    }
    friend ::tools::bigint operator%(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint(lhs) %= rhs;
    }

    static ::tools::bigint gcd(::tools::bigint x, ::tools::bigint y) {
      if (x.signum() < 0) x.negate();
      if (y.signum() < 0) y.negate();

      while (y.signum() != 0) {
        x %= y;
        ::std::swap(x, y);
      }

      return x;
    }

    template <typename T, ::std::enable_if_t<::std::is_integral_v<T>, ::std::nullptr_t> = nullptr>
    explicit operator T() const {
      assert(::tools::bigint(::std::numeric_limits<T>::min()) <= *this && *this <= ::tools::bigint(::std::numeric_limits<T>::max()));
      T result = 0;
      for (::std::size_t i = this->m_digits.size(); i --> 0;) {
        result = result * BASE + this->m_digits[i] * (this->m_positive ? 1 : -1);
      }
      return result;
    }

    explicit operator double() const {
      long double result = 0.0;
      const ::std::size_t precision = this->size();
      for (::std::size_t i = 0; i < ::std::numeric_limits<long double>::digits10; ++i) {
        result = result * 10.0L + (precision >= i + 1 ? (*this)[precision - 1 - i] : 0) * this->signum();
      }
      result *= ::std::pow(10.0L, static_cast<long double>(precision) - static_cast<long double>(::std::numeric_limits<long double>::digits10));
      return static_cast<double>(result);
    }

    friend ::std::istream& operator>>(::std::istream& is, ::tools::bigint& self) {
      ::std::string s;
      is >> s;
      self = ::tools::bigint(s);
      return is;
    }
    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::bigint& self) {
      if (!self.m_positive) {
        os << '-';
      }
      if (self.m_digits.empty()) {
        return os << '0';
      }
      os << self.m_digits.back();
      for (::std::size_t i = 1; i < self.m_digits.size(); ++i) {
        os << ::std::setw(LOG10_BASE) << ::std::setfill('0') << self.m_digits[self.m_digits.size() - 1 - i];
      }
      return os;
    }
  };
}

#endif
