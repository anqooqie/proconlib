#ifndef TOOLS_BIGINT_HPP
#define TOOLS_BIGINT_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string>
#include <tuple>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>
#include "atcoder/convolution.hpp"
#include "atcoder/modint.hpp"
#include "tools/abs.hpp"
#include "tools/ceil.hpp"
#include "tools/chmin.hpp"
#include "tools/floor.hpp"
#include "tools/floor_log2.hpp"
#include "tools/garner2.hpp"
#include "tools/gcd.hpp"
#include "tools/int128_t.hpp"
#include "tools/mod.hpp"
#include "tools/pow2.hpp"
#include "tools/quo.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  class bigint;

  ::tools::bigint abs(::tools::bigint x);

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
      for (::std::size_t i = lhs.m_digits.size(); i --> 0;) {
        if (const auto comp = ::tools::bigint::compare_3way(lhs.m_digits[i], rhs.m_digits[i]); comp != 0) {
          return comp;
        }
      }
      return 0;
    }

    template <int LEVEL>
    ::tools::bigint& regularize() {
      if constexpr (LEVEL > 0) {
        if constexpr (LEVEL == 2) {
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
        if constexpr (LEVEL == 2) {
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
    ::tools::bigint& multiply_by_pow10(const ::std::ptrdiff_t exponent) {
      if (!this->m_digits.empty()) {
        const ::std::ptrdiff_t exponent10000 = ::tools::floor(exponent, LOG10_BASE);
        ::std::int_fast32_t mod = 0;
        if (exponent10000 > 0) {
          ::std::vector<::std::int_fast32_t> zero(exponent10000, 0);
          this->m_digits.insert(this->m_digits.begin(), zero.begin(), zero.end());
        } else if (exponent10000 < 0) {
          if (::std::ssize(this->m_digits) >= -exponent10000) {
            mod = this->m_digits[-exponent10000 - 1] / POW10[LOG10_BASE * (exponent10000 + 1) - exponent];
          }
          this->m_digits.erase(this->m_digits.begin(), this->m_digits.begin() + ::std::min<::std::size_t>(-exponent10000, this->m_digits.size()));
        }
        if (const ::std::int_fast32_t coefficient = POW10[exponent - LOG10_BASE * exponent10000]; coefficient > POW10[0]) {
          for (auto& d : this->m_digits) {
            d *= coefficient;
          }
          if (mod > 0) {
            if (this->m_digits.empty()) {
              this->m_digits.push_back(0);
            }
            this->m_digits[0] += mod;
          }
          this->regularize<2>();
        } else {
          this->regularize<0>();
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
    template <bool PLUS>
    ::tools::bigint& internal_add(const ::tools::bigint& other) {
      if (this == &other) {
        if constexpr (PLUS) {
          for (auto& d : this->m_digits) d <<= 1;
          this->regularize<1>();
        } else {
          this->m_digits.clear();
          this->m_positive = true;
        }
      } else {
        const bool this_positive = this->m_positive;
        if (!this_positive) {
          this->negate();
        }
        this->m_digits.resize(::std::max(this->m_digits.size(), other.m_digits.size()));
        if (this_positive == (other.m_positive == PLUS)) {
          for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {
            this->m_digits[i] += other.m_digits[i];
          }
        } else {
          for (::std::size_t i = 0; i < other.m_digits.size(); ++i) {
            this->m_digits[i] -= other.m_digits[i];
          }
        }
        this->regularize<1>();
        if (!this_positive) {
          this->negate();
        }
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

    template <typename T, typename ::std::enable_if<::std::is_integral_v<T> || ::std::is_same_v<T, ::tools::int128_t> || ::std::is_same_v<T, ::tools::uint128_t>, ::std::nullptr_t>::type = nullptr>
    explicit bigint(T n) : m_positive(n >= 0) {
      while (n != 0) {
        this->m_digits.push_back(n % BASE);
        n /= BASE;
      }
      if (!this->m_positive) {
        for (auto& d : this->m_digits) {
          d = -d;
        }
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

      this->regularize<0>();
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
      return this->internal_add<true>(other);
    }
    ::tools::bigint& operator-=(const ::tools::bigint& other) {
      return this->internal_add<false>(other);
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
      long long carry = 0;
      for (::std::size_t i = 0; i < c1.size(); ++i) {

        // Since a_i <= 10^4 - 1 and b_i <= 10^4 - 1, c_i <= (10^4 - 1)^2 * min(this->m_digits.size(), other.m_digits.size()) holds.
        // In addition, since this->m_digits.size() + other.m_digits.size() <= 2^25 + 1, c_i <= (10^4 - 1)^2 * 2^24 = 1677386072457216 holds eventually.
        // 1677386072457216 < 167772161 * 469762049 = 78812994116517889 holds, so we can reconstruct c_i from mod(c_i, 167772161) and mod(c_i, 469762049) by CRT.
        long long c_i = ::tools::garner2(c1[i], c2[i]);

        c_i += carry;
        carry = c_i / BASE;
        c_i %= BASE;
        this->m_digits.push_back(c_i);
      }
      if (carry > 0) {
        this->m_digits.push_back(carry);
      }

      this->m_positive = this->m_positive == other.m_positive;
      this->regularize<0>();
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

  private:
    static const ::tools::bigint& divmod_naive_u64_threshold() {
      static const ::tools::bigint threshold((::std::numeric_limits<::std::uint_fast64_t>::max() - (BASE - 1)) / BASE);
      return threshold;
    }

    ::std::pair<::tools::bigint, ::tools::bigint> divmod_naive_u64(const ::tools::bigint& other) const {
      assert(!other.m_digits.empty());
      assert(::tools::bigint::compare_3way_abs(other, divmod_naive_u64_threshold()) <= 0);

      ::std::uint_fast64_t b = 0;
      for (::std::size_t i = other.m_digits.size(); i --> 0;) {
        b *= BASE;
        b += other.m_digits[i];
      }

      ::tools::bigint Q(*this);
      ::std::uint_fast64_t r = 0;
      for (::std::size_t i = Q.m_digits.size(); i--> 0;) {
        r *= BASE;
        r += Q.m_digits[i];
        Q.m_digits[i] = r / b;
        r %= b;
      }

      Q.m_positive = (this->m_positive == other.m_positive);
      Q.regularize<0>();
      ::tools::bigint R(r);
      R.m_positive = (r == 0 || this->m_positive);

      return ::std::make_pair(Q, R);
    }

    static const ::tools::bigint& divmod_naive_u128_threshold() {
      static const ::tools::bigint threshold("34028236692093846346337460743176820");
      return threshold;
    }

    ::std::pair<::tools::bigint, ::tools::bigint> divmod_naive_u128(const ::tools::bigint& other) const {
      assert(!other.m_digits.empty());
      assert(::tools::bigint::compare_3way_abs(other, divmod_naive_u128_threshold()) <= 0);

      ::tools::uint128_t b = 0;
      for (::std::size_t i = other.m_digits.size(); i --> 0;) {
        b *= BASE;
        b += other.m_digits[i];
      }

      ::tools::bigint Q(*this);
      ::tools::uint128_t r = 0;
      for (::std::size_t i = Q.m_digits.size(); i--> 0;) {
        r *= BASE;
        r += Q.m_digits[i];
        Q.m_digits[i] = r / b;
        r %= b;
      }

      Q.m_positive = (this->m_positive == other.m_positive);
      Q.regularize<0>();
      ::tools::bigint R(r);
      R.m_positive = (r == 0 || this->m_positive);

      return ::std::make_pair(Q, R);
    }

    // S1の[l1, r1)桁目 * (BASE ** n1) <=> S2の[l2, r2)桁目 * (BASE ** n2)
    static int compare_3way_abs(const ::tools::bigint& S1, ::std::size_t l1, ::std::size_t r1, ::std::size_t n1, const ::tools::bigint& S2, ::std::size_t l2, ::std::size_t r2, ::std::size_t n2) {
      assert(l1 <= r1);
      assert(l2 <= r2);

      ::tools::chmin(l1, S1.m_digits.size());
      ::tools::chmin(r1, S1.m_digits.size());
      ::tools::chmin(l2, S2.m_digits.size());
      ::tools::chmin(r2, S2.m_digits.size());
      const auto n_min = ::std::min(n1, n2);
      n1 -= n_min;
      n2 -= n_min;

      if (const auto comp = ::tools::bigint::compare_3way(r1 - l1 + n1, r2 - l2 + n2); comp != 0) {
        return comp;
      }
      if (n1 > 0) {
        const auto m2 = r2 - (r1 - l1);
        for (::std::size_t i1 = r1, i2 = r2; --i1, i2 --> m2;) {
          if (const auto comp = ::tools::bigint::compare_3way(S1.m_digits[i1], S2.m_digits[i2]); comp != 0) {
            return comp;
          }
        }
        for (::std::size_t i2 = m2; i2 --> l2;) {
          if (0 < S2.m_digits[i2]) {
            return -1;
          }
        }
      } else if (n2 > 0) {
        const auto m1 = r1 - (r2 - l2);
        for (::std::size_t i1 = r1, i2 = r2; --i1, i2 --> l2;) {
          if (const auto comp = ::tools::bigint::compare_3way(S1.m_digits[i1], S2.m_digits[i2]); comp != 0) {
            return comp;
          }
        }
        for (::std::size_t i1 = m1; i1 --> l1;) {
          if (S1.m_digits[i1] > 0) {
            return 1;
          }
        }
      } else {
        for (::std::size_t i1 = r1, i2 = r2; --i1, i2 --> l2;) {
          if (const auto comp = ::tools::bigint::compare_3way(S1.m_digits[i1], S2.m_digits[i2]); comp != 0) {
            return comp;
          }
        }
      }
      return 0;
    }
    // *thisの[l, r)桁目
    ::tools::bigint slice(::std::size_t l, ::std::size_t r) const {
      assert(this->m_positive);
      assert(l <= r);

      ::tools::chmin(l, this->m_digits.size());
      ::tools::chmin(r, this->m_digits.size());

      ::tools::bigint S;
      S.m_digits.reserve(r - l);
      ::std::copy(this->m_digits.begin() + l, this->m_digits.begin() + r, ::std::back_inserter(S.m_digits));
      return S.regularize<0>();
    }
    // *this * (BASE ** n)
    ::tools::bigint lshift(const int n) const {
      assert(this->m_positive);

      if (n == 0) return *this;
      if (this->m_digits.empty()) return *this;

      ::tools::bigint S;
      S.m_digits.reserve(n + this->m_digits.size());
      ::std::fill_n(::std::back_inserter(S.m_digits), n, 0);
      ::std::copy(this->m_digits.begin(), this->m_digits.end(), ::std::back_inserter(S.m_digits));
      return S;
    }
    // *this / (BASE ** n)
    ::tools::bigint rshift(const ::std::size_t n) const {
      assert(this->m_positive);

      if (this->m_digits.size() <= n) return ::tools::bigint{};

      ::tools::bigint S;
      S.m_digits.reserve(this->m_digits.size() - n);
      ::std::copy(this->m_digits.begin() + n, this->m_digits.end(), ::std::back_inserter(S.m_digits));
      return S;
    }
    // *this * (BASE ** (r - l)) + otherの[l, r)桁目
    ::tools::bigint concat(const ::tools::bigint& other, ::std::size_t l, ::std::size_t r) const {
      assert(this->m_positive);
      assert(other.m_positive);
      assert(l < r);

      if (this->m_digits.empty()) return other.slice(l, r);

      const auto n = r - l;
      ::tools::chmin(l, other.m_digits.size());
      ::tools::chmin(r, other.m_digits.size());

      ::tools::bigint S;
      S.m_digits.reserve(this->m_digits.size() + n);
      ::std::copy(other.m_digits.begin() + l, other.m_digits.begin() + r, ::std::back_inserter(S.m_digits));
      ::std::fill_n(::std::back_inserter(S.m_digits), n - (r - l), 0);
      ::std::copy(this->m_digits.begin(), this->m_digits.end(), ::std::back_inserter(S.m_digits));
      return S;
    }

    ::std::pair<::tools::bigint, ::tools::bigint> divmod_3n_2n(const ::tools::bigint& other, const ::std::size_t n) const {
      assert(this->m_positive);
      assert(this->m_digits.size() <= n * 3);
      assert(other.m_positive);
      assert(other.m_digits.size() == n * 2);
      assert(BASE <= other.m_digits.back() * 2);
      assert(compare_3way_abs(*this, 0, n * 3, 0, other, 0, n * 2, n) < 0);

      ::tools::bigint Q_hat, S, D;
      if (compare_3way_abs(*this, n * 2, n * 3, 0, other, n, n * 2, 0) < 0) {
        ::std::tie(Q_hat, S) = this->slice(n, n * 3).divmod_2n_n(other.slice(n, n * 2), n);
        D = other.slice(0, n);
        D *= Q_hat;
      } else {
        Q_hat.m_digits.assign(n, BASE - 1);
        S = this->slice(n, n * 3);
        S += other.slice(n, n * 2);
        S -= other.slice(n, n * 2).lshift(n);
        D = other.slice(0, n).lshift(n);
        D -= other.slice(0, n);
      }

      auto R_hat = S.concat(*this, 0, n);
      R_hat -= D;
      while (!R_hat.m_positive) {
        R_hat += other;
        --Q_hat;
      }

      return ::std::make_pair(Q_hat, R_hat);
    }

    ::std::pair<::tools::bigint, ::tools::bigint> divmod_4n_2n(const ::tools::bigint& other, const ::std::size_t n) const {
      assert(this->m_positive);
      assert(this->m_digits.size() <= n * 4);
      assert(other.m_positive);
      assert(other.m_digits.size() == n * 2);
      assert(BASE <= other.m_digits.back() * 2);
      assert(compare_3way_abs(*this, 0, n * 4, 0, other, 0, n * 2, n * 2) < 0);

      const auto [Q1, S] = this->slice(n, n * 4).divmod_3n_2n(other, n);
      const auto [Q0, R] = S.concat(*this, 0, n).divmod_3n_2n(other, n);

      return ::std::make_pair(Q1.concat(Q0, 0, n), R);
    }

    ::std::pair<::tools::bigint, ::tools::bigint> divmod_2n_n(const ::tools::bigint& other, const ::std::size_t n) const {
      assert(this->m_positive);
      assert(this->m_digits.size() <= n * 2);
      assert(other.m_positive);
      assert(other.m_digits.size() == n);
      assert(BASE <= other.m_digits.back() * 2);

      if (other.m_digits.size() <= 3) {
        return this->divmod_naive_u64(other);
      }
      if (other.m_digits.size() <= 8) {
        return this->divmod_naive_u128(other);
      }

      assert(n % 2 == 0);
      return this->divmod_4n_2n(other, n / 2);
    }

  public:
    ::std::pair<::tools::bigint, ::tools::bigint> divmod(const ::tools::bigint& other) const {
      assert(!other.m_digits.empty());

      if (::tools::bigint::compare_3way_abs(*this, other) < 0) {
        return ::std::make_pair(::tools::bigint{}, *this);
      }
      if (::tools::bigint::compare_3way_abs(other, divmod_naive_u64_threshold()) <= 0) {
        return this->divmod_naive_u64(other);
      }
      if (::tools::bigint::compare_3way_abs(other, divmod_naive_u128_threshold()) <= 0) {
        return this->divmod_naive_u128(other);
      }

      if (!this->m_positive || !other.m_positive) {
        auto [Q, R] = ::tools::abs(*this).divmod(::tools::abs(other));
        Q.m_positive = Q.m_digits.empty() || (this->m_positive == other.m_positive);
        R.m_positive = R.m_digits.empty() || this->m_positive;
        return ::std::make_pair(Q, R);
      }

      const ::std::size_t DIV_LIMIT = 8;
      const auto s = other.m_digits.size();
      const auto m = ::tools::pow2(::tools::floor_log2(s / DIV_LIMIT) + 1);
      const auto n = ::tools::ceil(s, m) * m;

      const auto sigma1 = n - s;
      auto sigma2 = ::tools::pow2(::tools::floor_log2(BASE / (other.m_digits.back() + 1)));

      auto B = other.lshift(sigma1);
      for (auto& B_i : B.m_digits) B_i *= sigma2;
      B.regularize<2>();
      assert(B.m_digits.size() == n);
      while (B.m_digits.back() * 2 < BASE) {
        sigma2 *= 2;
        B += B;
        assert(B.m_digits.size() == n);
      }

      auto A = this->lshift(sigma1);
      for (auto& A_i : A.m_digits) A_i *= sigma2;
      A.regularize<2>();

      const auto t = ::std::max<::std::size_t>(2, ::tools::ceil(A.m_digits.size() + 1, n));
      ::tools::bigint Q, Q_i, R_i;
      Q.m_digits.resize(n * (t - 1));
      auto Z = A.slice(n * (t - 2), n * t);
      ::std::tie(Q_i, R_i) = Z.divmod_2n_n(B, n);
      ::std::copy(Q_i.m_digits.begin(), Q_i.m_digits.end(), Q.m_digits.begin() + n * (t - 2));
      for (::std::size_t i = t - 2; i --> 0;) {
        Z = R_i.concat(A, n * i, n * (i + 1));
        ::std::tie(Q_i, R_i) = Z.divmod_2n_n(B, n);
        ::std::copy(Q_i.m_digits.begin(), Q_i.m_digits.end(), Q.m_digits.begin() + n * i);
      }

      return ::std::make_pair(Q.regularize<0>(), R_i.divmod_naive_u64(::tools::bigint(sigma2)).first.rshift(sigma1));
    }

    ::tools::bigint& operator/=(const ::tools::bigint& other) {
      return *this = *this / other;
    }
    friend ::tools::bigint operator/(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return lhs.divmod(rhs).first;
    }
    ::tools::bigint& operator%=(const ::tools::bigint& other) {
      return *this = *this % other;
    }
    friend ::tools::bigint operator%(const ::tools::bigint& lhs, const ::tools::bigint& rhs) {
      return lhs.divmod(rhs).second;
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

    explicit operator bool() const {
      return !this->m_digits.empty();
    }

    explicit operator ::tools::int128_t() const {
      assert(::tools::bigint(::std::numeric_limits<::tools::int128_t>::min()) <= *this && *this <= ::tools::bigint(::std::numeric_limits<::tools::int128_t>::max()));
      ::tools::int128_t result = 0;
      for (::std::size_t i = this->m_digits.size(); i --> 0;) {
        result = result * BASE + this->m_digits[i] * (this->m_positive ? 1 : -1);
      }
      return result;
    }

    explicit operator ::tools::uint128_t() const {
      assert(::tools::bigint(0) <= *this && *this <= ::tools::bigint(::std::numeric_limits<::tools::uint128_t>::max()));
      ::tools::uint128_t result = 0;
      for (::std::size_t i = this->m_digits.size(); i --> 0;) {
        result = result * BASE + this->m_digits[i];
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

    friend ::tools::bigint abs(::tools::bigint x);
  };

  inline ::tools::bigint abs(::tools::bigint x) {
    if (!x.m_positive) x.negate();
    return x;
  }

  template <>
  ::tools::bigint gcd<::tools::bigint, ::tools::bigint>(::tools::bigint x, ::tools::bigint y) {
    if (x.signum() < 0) x.negate();
    if (y.signum() < 0) y.negate();

    while (y.signum() != 0) {
      x %= y;
      ::std::swap(x, y);
    }

    return x;
  }
}

#endif
