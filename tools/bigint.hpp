#ifndef TOOLS_BIGINT_HPP
#define TOOLS_BIGINT_HPP

#include <vector>
#include <cstdint>
#include <cstddef>
#include <algorithm>
#include <string>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "tools/quo.hpp"
#include "tools/mod.hpp"
#include "tools/ceil.hpp"

namespace tools {
  class bigint {
  private:
    bool m_positive;
    ::std::vector<::std::int_fast32_t> m_digits;
    static constexpr ::std::int_fast32_t BASE = 10000;
    static constexpr ::std::int_fast32_t LOG10_BASE = 4;

    static int compare_3way(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      if (!lhs.m_positive && rhs.m_positive) return -1;
      if (lhs.m_positive && !rhs.m_positive) return 1;
      return [&]() {
        if (lhs.m_digits.size() < rhs.m_digits.size()) return -1;
        if (lhs.m_digits.size() > rhs.m_digits.size()) return 1;
        for (::std::size_t i = 0; i < lhs.m_digits.size(); ++i) {
          if (lhs.m_digits[lhs.m_digits.size() - 1 - i] < rhs.m_digits[rhs.m_digits.size() - 1 - i]) return -1;
          if (lhs.m_digits[lhs.m_digits.size() - 1 - i] > rhs.m_digits[rhs.m_digits.size() - 1 - i]) return 1;
        }
        return 0;
      }() * (lhs.m_positive ? 1 : -1);
    }

    ::tools::bigint& negate() {
      if (!this->m_digits.empty()) {
        this->m_positive = !this->m_positive;
      }
      return *this;
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

    explicit bigint(const ::std::int_fast64_t n) : m_positive(true) {
      this->m_digits.push_back(n);
      this->regularize(2);
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

    friend ::tools::bigint operator+(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint(lhs) += rhs;
    }
    friend ::tools::bigint operator-(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return ::tools::bigint(lhs) -= rhs;
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
