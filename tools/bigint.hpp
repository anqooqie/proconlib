#ifndef TOOLS_BIGINT_HPP
#define TOOLS_BIGINT_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <compare>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>
#include "atcoder/convolution.hpp"
#include "atcoder/modint.hpp"
#include "tools/abs.hpp"
#include "tools/block_ceil.hpp"
#include "tools/ceil.hpp"
#include "tools/chmin.hpp"
#include "tools/extgcd.hpp"
#include "tools/floor.hpp"
#include "tools/floor_log2.hpp"
#include "tools/garner2.hpp"
#include "tools/gcd.hpp"
#include "tools/int128_t.hpp"
#include "tools/integral.hpp"
#include "tools/mod.hpp"
#include "tools/mutable_type.hpp"
#include "tools/non_bool_integral.hpp"
#include "tools/pow2.hpp"
#include "tools/quo.hpp"
#include "tools/signum.hpp"
#include "tools/uint128_t.hpp"
#include "tools/unsigned_integral.hpp"

namespace tools {
  class bigint;

  template <>
  struct detail::abs::impl<tools::bigint> {
    tools::bigint operator()(auto&&) const;
  };
  template <>
  struct detail::extgcd::impl<tools::bigint, tools::bigint> {
    std::tuple<tools::bigint, tools::bigint, tools::bigint> operator()(tools::bigint, tools::bigint) const;
  };
  template <>
  struct detail::gcd::impl<tools::bigint, tools::bigint> {
    struct mat22;
    static mat22 half_gcd(tools::bigint& a, tools::bigint& b);
    tools::bigint operator()(tools::bigint, tools::bigint) const;
  };
  template <>
  struct detail::signum::impl<tools::bigint> {
    int operator()(const tools::bigint&) const;
  };

  class bigint {
    using mint1 = atcoder::static_modint<167772161>;
    using mint2 = atcoder::static_modint<469762049>;

    bool m_nonnegative;
    std::vector<std::int_fast32_t> m_digits;
    static constexpr std::int_fast32_t BASE = 10000;
    static constexpr std::int_fast32_t LOG10_BASE = 4;
    static constexpr std::array<std::int_fast32_t, 5> POW10 = {1, 10, 100, 1000, 10000};

    static std::strong_ordering compare_3way_abs(const tools::bigint& lhs, const tools::bigint& rhs) {
      if (const auto comp = lhs.m_digits.size() <=> rhs.m_digits.size(); comp != 0) {
        return comp;
      }
      for (std::size_t i = lhs.m_digits.size(); i --> 0;) {
        if (const auto comp = lhs.m_digits[i] <=> rhs.m_digits[i]; comp != 0) {
          return comp;
        }
      }
      return std::strong_ordering::equal;
    }

    template <bool PLUS>
    auto internal_add(this tools::mutable_type auto&& self, const tools::bigint& other) -> decltype(self) {
      if (std::addressof(self) == std::addressof(other)) {
        if constexpr (PLUS) {
          for (auto& d : self.m_digits) d <<= 1;
          self.template regularize<1>();
        } else {
          self.m_digits.clear();
          self.m_nonnegative = true;
        }
      } else {
        const bool this_nonnegative = self.m_nonnegative;
        if (!this_nonnegative) {
          self.negate();
        }
        self.m_digits.resize(std::max(self.m_digits.size(), other.m_digits.size()));
        if (this_nonnegative == (other.m_nonnegative == PLUS)) {
          for (std::size_t i = 0; i < other.m_digits.size(); ++i) {
            self.m_digits[i] += other.m_digits[i];
          }
        } else {
          for (std::size_t i = 0; i < other.m_digits.size(); ++i) {
            self.m_digits[i] -= other.m_digits[i];
          }
        }
        self.template regularize<1>();
        if (!this_nonnegative) {
          self.negate();
        }
      }
      return std::forward<decltype(self)>(self);
    }
    template <int LEVEL> requires (0 <= LEVEL && LEVEL <= 2)
    auto regularize(this tools::mutable_type auto&& self) -> decltype(self) {
      if constexpr (LEVEL > 0) {
        if constexpr (LEVEL == 2) {
          for (std::size_t i = 0; i + 1 < self.m_digits.size(); ++i) {
            self.m_digits[i + 1] += tools::quo(self.m_digits[i], BASE);
            self.m_digits[i] = tools::mod(self.m_digits[i], BASE);
          }
        } else {
          for (std::size_t i = 0; i + 1 < self.m_digits.size(); ++i) {
            if (self.m_digits[i] < 0) {
              self.m_digits[i] += BASE;
              --self.m_digits[i + 1];
            } else if (self.m_digits[i] >= BASE) {
              self.m_digits[i] -= BASE;
              ++self.m_digits[i + 1];
            }
          }
        }
        if (!self.m_digits.empty() && self.m_digits.back() < 0) {
          self.m_nonnegative = !self.m_nonnegative;
          for (std::size_t i = 0; i < self.m_digits.size(); ++i) {
            self.m_digits[i] = -self.m_digits[i];
          }
          for (std::size_t i = 0; i + 1 < self.m_digits.size(); ++i) {
            if (self.m_digits[i] < 0) {
              self.m_digits[i] = BASE + self.m_digits[i];
              --self.m_digits[i + 1];
            }
          }
        }
        if constexpr (LEVEL == 2) {
          while (!self.m_digits.empty() && self.m_digits.back() >= BASE) {
            self.m_digits.push_back(self.m_digits.back() / BASE);
            self.m_digits[self.m_digits.size() - 2] %= BASE;
          }
        } else {
          if (!self.m_digits.empty() && self.m_digits.back() >= BASE) {
            self.m_digits.back() -= BASE;
            self.m_digits.push_back(1);
          }
        }
      }
      while (!self.m_digits.empty() && self.m_digits.back() == 0) {
        self.m_digits.pop_back();
      }
      if (self.m_digits.empty() && !self.m_nonnegative) {
        self.m_nonnegative = true;
      }
      return std::forward<decltype(self)>(self);
    }

  public:
    bigint() : m_nonnegative(true) {
    }
    explicit bigint(tools::integral auto n) : m_nonnegative(n >= 0) {
      while (n != 0) {
        this->m_digits.push_back(n % BASE);
        n /= BASE;
      }
      if (!this->m_nonnegative) {
        for (auto& d : this->m_digits) {
          d = -d;
        }
      }
    }
    explicit bigint(const std::string_view s) {
      assert(!s.empty());

      std::size_t offset;
      if (s[0] == '+') {
        this->m_nonnegative = true;
        offset = 1;
      } else if (s[0] == '-') {
        this->m_nonnegative = false;
        offset = 1;
      } else {
        this->m_nonnegative = true;
        offset = 0;
      }

      this->m_digits.reserve(tools::ceil<std::size_t>(s.size() - offset, LOG10_BASE));
      for (std::size_t i = 0; i < s.size() - offset; i += LOG10_BASE) {
        this->m_digits.push_back(0);
        for (std::size_t j = std::min(i + LOG10_BASE, s.size() - offset); j --> i;) {
          assert('0' <= s[s.size() - 1 - j] && s[s.size() - 1 - j] <= '9');
          this->m_digits.back() = this->m_digits.back() * 10 + (s[s.size() - 1 - j] - '0');
        }
      }

      this->regularize<0>();
    }

    auto abs_inplace(this tools::mutable_type auto&& self) -> decltype(self) {
      if (!self.m_nonnegative) self.negate();
      return std::forward<decltype(self)>(self);
    }
    tools::bigint divide_by_pow10(this auto&& self, const std::ptrdiff_t exponent) {
      return tools::bigint(std::forward<decltype(self)>(self)).divide_inplace_by_pow10(exponent);
    }
    auto divide_inplace_by_pow10(this tools::mutable_type auto&& self, const std::ptrdiff_t exponent) -> decltype(self) {
      self.multiply_inplace_by_pow10(-exponent);
      return std::forward<decltype(self)>(self);
    }

  private:
    template <tools::unsigned_integral T>
    static const tools::bigint& divmod_naive_threshold() {
      static const tools::bigint threshold((std::numeric_limits<T>::max() - (BASE - 1)) / BASE);
      return threshold;
    }
    template <tools::unsigned_integral T>
    std::pair<tools::bigint, tools::bigint> divmod_naive(const tools::bigint& other) const {
      assert(!other.m_digits.empty());
      assert(tools::bigint::compare_3way_abs(other, divmod_naive_threshold<T>()) <= 0);

      T b = 0;
      for (std::size_t i = other.m_digits.size(); i --> 0;) {
        b *= BASE;
        b += other.m_digits[i];
      }

      tools::bigint Q(*this);
      T r = 0;
      for (std::size_t i = Q.m_digits.size(); i--> 0;) {
        r *= BASE;
        r += Q.m_digits[i];
        Q.m_digits[i] = r / b;
        r %= b;
      }

      Q.m_nonnegative = (this->m_nonnegative == other.m_nonnegative);
      Q.regularize<0>();
      tools::bigint R(r);
      R.m_nonnegative = (r == 0 || this->m_nonnegative);

      return std::make_pair(std::move(Q), std::move(R));
    }
    static constexpr std::size_t divmod_div_limit() {
      return 48;
    }
    std::pair<tools::bigint, tools::bigint> divmod_knuth_d(const tools::bigint& other) const {
      assert(this->m_nonnegative);
      assert(other.m_nonnegative);
      assert(!other.m_digits.empty());
      assert(BASE <= other.m_digits.back() * 2);

      if (*this < other) {
        return std::make_pair(tools::bigint{}, *this);
      }

      tools::bigint R(*this);
      R.m_digits.push_back(0);

      tools::bigint Q;
      Q.m_digits.resize(R.m_digits.size() - other.m_digits.size());
      for (int i = Q.m_digits.size() - 1; i >= 0; --i) {
        Q.m_digits[i] = std::min((R.m_digits.back() * BASE + R.m_digits.rbegin()[1]) / other.m_digits.back(), BASE - 1);
        for (int j = 0; j < std::ssize(other.m_digits); ++j) {
          R.m_digits[i + j] -= Q.m_digits[i] * other.m_digits[j];
          R.m_digits[i + j + 1] += tools::quo(R.m_digits[i + j], BASE);
          R.m_digits[i + j] = tools::mod(R.m_digits[i + j], BASE);
        }
        while (R.m_digits.back() < 0) {
          --Q.m_digits[i];
          for (int j = 0; j < std::ssize(other.m_digits); ++j) {
            R.m_digits[i + j] += other.m_digits[j];
            if (R.m_digits[i + j] >= BASE) {
              R.m_digits[i + j] -= BASE;
              ++R.m_digits[i + j + 1];
            }
          }
        }
        R.m_digits.pop_back();
      }

      while (!Q.m_digits.empty() && Q.m_digits.back() == 0) {
        Q.m_digits.pop_back();
      }
      while (!R.m_digits.empty() && R.m_digits.back() == 0) {
        R.m_digits.pop_back();
      }

      return std::make_pair(std::move(Q), std::move(R));
    }
    // S1の[l1, r1)桁目 * (BASE ** n1) <=> S2の[l2, r2)桁目 * (BASE ** n2)
    static std::strong_ordering compare_3way_abs(const tools::bigint& S1, std::size_t l1, std::size_t r1, std::size_t n1, const tools::bigint& S2, std::size_t l2, std::size_t r2, std::size_t n2) {
      assert(l1 <= r1);
      assert(l2 <= r2);

      tools::chmin(l1, S1.m_digits.size());
      tools::chmin(r1, S1.m_digits.size());
      tools::chmin(l2, S2.m_digits.size());
      tools::chmin(r2, S2.m_digits.size());
      const auto n_min = std::min(n1, n2);
      n1 -= n_min;
      n2 -= n_min;

      if (const auto comp = (r1 - l1 + n1) <=> (r2 - l2 + n2); comp != 0) {
        return comp;
      }
      if (n1 > 0) {
        const auto m2 = r2 - (r1 - l1);
        for (std::size_t i1 = r1, i2 = r2; --i1, i2 --> m2;) {
          if (const auto comp = S1.m_digits[i1] <=> S2.m_digits[i2]; comp != 0) {
            return comp;
          }
        }
        for (std::size_t i2 = m2; i2 --> l2;) {
          if (0 < S2.m_digits[i2]) {
            return std::strong_ordering::less;
          }
        }
      } else if (n2 > 0) {
        const auto m1 = r1 - (r2 - l2);
        for (std::size_t i1 = r1, i2 = r2; --i1, i2 --> l2;) {
          if (const auto comp = S1.m_digits[i1] <=> S2.m_digits[i2]; comp != 0) {
            return comp;
          }
        }
        for (std::size_t i1 = m1; i1 --> l1;) {
          if (S1.m_digits[i1] > 0) {
            return std::strong_ordering::greater;
          }
        }
      } else {
        for (std::size_t i1 = r1, i2 = r2; --i1, i2 --> l2;) {
          if (const auto comp = S1.m_digits[i1] <=> S2.m_digits[i2]; comp != 0) {
            return comp;
          }
        }
      }
      return std::strong_ordering::equal;
    }
    // *thisの[l, r)桁目
    tools::bigint slice(std::size_t l, std::size_t r) const {
      assert(this->m_nonnegative);
      assert(l <= r);

      tools::chmin(l, this->m_digits.size());
      tools::chmin(r, this->m_digits.size());

      tools::bigint S;
      S.m_digits.reserve(r - l);
      std::copy(this->m_digits.begin() + l, this->m_digits.begin() + r, std::back_inserter(S.m_digits));
      S.regularize<0>();
      return S;
    }
    // *this * (BASE ** n)
    tools::bigint lshift(const int n) const {
      assert(this->m_nonnegative);

      if (n == 0) return *this;
      if (this->m_digits.empty()) return *this;

      tools::bigint S;
      S.m_digits.reserve(n + this->m_digits.size());
      S.m_digits.resize(n, 0);
      std::ranges::copy(this->m_digits, std::back_inserter(S.m_digits));
      return S;
    }
    // *this / (BASE ** n)
    tools::bigint rshift(const std::size_t n) const {
      assert(this->m_nonnegative);

      if (this->m_digits.size() <= n) return tools::bigint{};

      tools::bigint S;
      S.m_digits.reserve(this->m_digits.size() - n);
      std::copy(this->m_digits.begin() + n, this->m_digits.end(), std::back_inserter(S.m_digits));
      return S;
    }
    // *this * (BASE ** (r - l)) + otherの[l, r)桁目
    tools::bigint concat(const tools::bigint& other, std::size_t l, std::size_t r) const {
      assert(this->m_nonnegative);
      assert(other.m_nonnegative);
      assert(l < r);

      if (this->m_digits.empty()) return other.slice(l, r);

      const auto n = r - l;
      tools::chmin(l, other.m_digits.size());
      tools::chmin(r, other.m_digits.size());

      tools::bigint S;
      S.m_digits.reserve(this->m_digits.size() + n);
      std::copy(other.m_digits.begin() + l, other.m_digits.begin() + r, std::back_inserter(S.m_digits));
      std::fill_n(std::back_inserter(S.m_digits), n - (r - l), 0);
      std::copy(this->m_digits.begin(), this->m_digits.end(), std::back_inserter(S.m_digits));
      return S;
    }

    std::pair<tools::bigint, tools::bigint> divmod_3n_2n(const tools::bigint& other, const std::size_t n) const {
      assert(this->m_nonnegative);
      assert(this->m_digits.size() <= n * 3);
      assert(other.m_nonnegative);
      assert(other.m_digits.size() == n * 2);
      assert(BASE <= other.m_digits.back() * 2);
      assert(compare_3way_abs(*this, 0, n * 3, 0, other, 0, n * 2, n) < 0);

      tools::bigint Q_hat, S, D;
      if (compare_3way_abs(*this, n * 2, n * 3, 0, other, n, n * 2, 0) < 0) {
        std::tie(Q_hat, S) = this->slice(n, n * 3).divmod_2n_n(other.slice(n, n * 2), n);
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
      while (!R_hat.m_nonnegative) {
        R_hat += other;
        --Q_hat;
      }

      return std::make_pair(std::move(Q_hat), std::move(R_hat));
    }

    std::pair<tools::bigint, tools::bigint> divmod_4n_2n(const tools::bigint& other, const std::size_t n) const {
      assert(this->m_nonnegative);
      assert(this->m_digits.size() <= n * 4);
      assert(other.m_nonnegative);
      assert(other.m_digits.size() == n * 2);
      assert(BASE <= other.m_digits.back() * 2);
      assert(compare_3way_abs(*this, 0, n * 4, 0, other, 0, n * 2, n * 2) < 0);

      const auto [Q1, S] = this->slice(n, n * 4).divmod_3n_2n(other, n);
      auto [Q0, R] = S.concat(*this, 0, n).divmod_3n_2n(other, n);

      return std::make_pair(Q1.concat(Q0, 0, n), std::move(R));
    }

    std::pair<tools::bigint, tools::bigint> divmod_2n_n(const tools::bigint& other, const std::size_t n) const {
      assert(this->m_nonnegative);
      assert(this->m_digits.size() <= n * 2);
      assert(other.m_nonnegative);
      assert(other.m_digits.size() == n);
      assert(BASE <= other.m_digits.back() * 2);

      if (other.m_digits.size() <= 3) {
        return this->divmod_naive<std::uint_fast64_t>(other);
      }
      if (other.m_digits.size() <= 8) {
        return this->divmod_naive<tools::uint128_t>(other);
      }
      if (other.m_digits.size() <= tools::bigint::divmod_div_limit()) {
        return this->divmod_knuth_d(other);
      }

      assert(n % 2 == 0);
      return this->divmod_4n_2n(other, n / 2);
    }

  public:
    std::pair<tools::bigint, tools::bigint> divmod(const tools::bigint& other) const {
      assert(!other.m_digits.empty());

      if (tools::bigint::compare_3way_abs(*this, other) < 0) {
        return std::make_pair(tools::bigint{}, *this);
      }
      if (tools::bigint::compare_3way_abs(other, divmod_naive_threshold<std::uint_fast64_t>()) <= 0) {
        return this->divmod_naive<std::uint_fast64_t>(other);
      }
      if (tools::bigint::compare_3way_abs(other, divmod_naive_threshold<tools::uint128_t>()) <= 0) {
        return this->divmod_naive<tools::uint128_t>(other);
      }

      if (!this->m_nonnegative || !other.m_nonnegative) {
        auto [Q, R] = tools::abs(*this).divmod(tools::abs(other));
        Q.m_nonnegative = Q.m_digits.empty() || (this->m_nonnegative == other.m_nonnegative);
        R.m_nonnegative = R.m_digits.empty() || this->m_nonnegative;
        return std::make_pair(std::move(Q), std::move(R));
      }

      if (other.m_digits.size() <= tools::bigint::divmod_div_limit()) {
        const auto sigma = BASE / (other.m_digits.back() + 1);

        tools::bigint A(*this);
        for (auto& A_i : A.m_digits) A_i *= sigma;
        A.regularize<2>();

        tools::bigint B(other);
        for (auto& B_i : B.m_digits) B_i *= sigma;
        B.regularize<2>();

        auto [Q, R] = A.divmod_knuth_d(B);
        return std::make_pair(std::move(Q), R.divmod_naive<std::uint_fast64_t>(tools::bigint(sigma)).first);
      }

      const auto s = other.m_digits.size();
      const auto m = tools::pow2(tools::floor_log2(s / tools::bigint::divmod_div_limit()) + 1);
      const auto n = tools::block_ceil(s, m);

      const auto sigma1 = n - s;
      auto sigma2 = tools::pow2(tools::floor_log2(BASE / (other.m_digits.back() + 1)));

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

      const auto t = std::max<std::size_t>(2, tools::ceil(A.m_digits.size() + 1, n));
      tools::bigint Q, Q_i, R_i;
      Q.m_digits.resize(n * (t - 1));
      auto Z = A.slice(n * (t - 2), n * t);
      std::tie(Q_i, R_i) = Z.divmod_2n_n(B, n);
      std::ranges::copy(Q_i.m_digits, Q.m_digits.begin() + n * (t - 2));
      for (std::size_t i = t - 2; i --> 0;) {
        Z = R_i.concat(A, n * i, n * (i + 1));
        std::tie(Q_i, R_i) = Z.divmod_2n_n(B, n);
        std::ranges::copy(Q_i.m_digits, Q.m_digits.begin() + n * i);
      }

      return std::make_pair(std::move(Q.regularize<0>()), R_i.divmod_naive<std::uint_fast64_t>(tools::bigint(sigma2)).first.rshift(sigma1));
    }
    tools::bigint multiply_by_pow10(this auto&& self, const std::ptrdiff_t exponent) {
      return tools::bigint(std::forward<decltype(self)>(self)).multiply_inplace_by_pow10(exponent);
    }
    auto multiply_inplace_by_pow10(this tools::mutable_type auto&& self, const std::ptrdiff_t exponent) -> decltype(self) {
      if (!self.m_digits.empty()) {
        const std::ptrdiff_t exponent10000 = tools::floor(exponent, LOG10_BASE);
        std::int_fast32_t mod = 0;
        if (exponent10000 > 0) {
          std::vector<std::int_fast32_t> zero(exponent10000, 0);
          self.m_digits.insert(self.m_digits.begin(), zero.begin(), zero.end());
        } else if (exponent10000 < 0) {
          if (std::ssize(self.m_digits) >= -exponent10000) {
            mod = self.m_digits[-exponent10000 - 1] / POW10[LOG10_BASE * (exponent10000 + 1) - exponent];
          }
          self.m_digits.erase(self.m_digits.begin(), self.m_digits.begin() + std::min<std::size_t>(-exponent10000, self.m_digits.size()));
        }
        if (const std::int_fast32_t coefficient = POW10[exponent - LOG10_BASE * exponent10000]; coefficient > POW10[0]) {
          for (auto& d : self.m_digits) {
            d *= coefficient;
          }
          if (mod > 0) {
            if (self.m_digits.empty()) {
              self.m_digits.push_back(0);
            }
            self.m_digits[0] += mod;
          }
          self.template regularize<2>();
        } else {
          self.template regularize<0>();
        }
      }
      return std::forward<decltype(self)>(self);
    }
    auto negate(this tools::mutable_type auto&& self) -> decltype(self) {
      if (!self.m_digits.empty()) {
        self.m_nonnegative = !self.m_nonnegative;
      }
      return std::forward<decltype(self)>(self);
    }
    std::size_t size() const {
      if (this->m_digits.empty()) return 0;
      return LOG10_BASE * (this->m_digits.size() - 1) + std::distance(POW10.begin(), std::upper_bound(POW10.begin(), POW10.end(), this->m_digits[this->m_digits.size() - 1]));
    }

    std::int_fast32_t operator[](const std::size_t i) const {
      return i < LOG10_BASE * this->m_digits.size() ? this->m_digits[i / LOG10_BASE] / POW10[i % LOG10_BASE] % 10 : 0;
    }

    friend std::strong_ordering operator<=>(const tools::bigint& lhs, const tools::bigint& rhs) {
      if (!lhs.m_nonnegative && rhs.m_nonnegative) return std::strong_ordering::less;
      if (lhs.m_nonnegative && !rhs.m_nonnegative) return std::strong_ordering::greater;
      const auto comp = tools::bigint::compare_3way_abs(lhs, rhs);
      return lhs.m_nonnegative ? comp : 0 <=> comp;
    }
    friend bool operator==(const tools::bigint& lhs, const tools::bigint& rhs) {
      return lhs.m_nonnegative == rhs.m_nonnegative && lhs.m_digits == rhs.m_digits;
    }

    tools::bigint operator+(this auto&& self) {
      return std::forward<decltype(self)>(self);
    }
    tools::bigint operator-(this auto&& self) {
      return tools::bigint(std::forward<decltype(self)>(self)).negate();
    }

    auto operator++(this tools::mutable_type auto&& self) -> decltype(self) {
      self += tools::bigint(1);
      return std::forward<decltype(self)>(self);
    }
    tools::bigint operator++(int) {
      tools::bigint old(*this);
      ++(*this);
      return old;
    }
    auto operator--(this tools::mutable_type auto&& self) -> decltype(self) {
      self -= tools::bigint(1);
      return std::forward<decltype(self)>(self);
    }
    tools::bigint operator--(int) {
      tools::bigint old(*this);
      --(*this);
      return old;
    }

    auto operator+=(this tools::mutable_type auto&& self, const tools::bigint& other) -> decltype(self) {
      self.template internal_add<true>(other);
      return std::forward<decltype(self)>(self);
    }
    tools::bigint operator+(this auto&& lhs, const tools::bigint& rhs) {
      return tools::bigint(std::forward<decltype(lhs)>(lhs)) += rhs;
    }

    auto operator-=(this tools::mutable_type auto&& self, const tools::bigint& other) -> decltype(self) {
      self.template internal_add<false>(other);
      return std::forward<decltype(self)>(self);
    }
    tools::bigint operator-(this auto&& lhs, const tools::bigint& rhs) {
      return tools::bigint(std::forward<decltype(lhs)>(lhs)) -= rhs;
    }

    auto operator*=(this tools::mutable_type auto&& self, const tools::bigint& other) -> decltype(self) {
      // Constraint derived from atcoder::convolution
      assert(self.m_digits.size() + other.m_digits.size() <= tools::pow2(25) + 1);

      const auto c1 = atcoder::convolution(
        self.m_digits | std::views::transform(mint1::raw) | std::ranges::to<std::vector>(),
        other.m_digits | std::views::transform(mint1::raw) | std::ranges::to<std::vector>()
      );
      const auto c2 = atcoder::convolution(
        self.m_digits | std::views::transform(mint2::raw) | std::ranges::to<std::vector>(),
        other.m_digits | std::views::transform(mint2::raw) | std::ranges::to<std::vector>()
      );

      self.m_digits.clear();
      self.m_digits.reserve(c1.size() + 1);
      long long carry = 0;
      for (std::size_t i = 0; i < c1.size(); ++i) {

        // Since a_i <= 10^4 - 1 and b_i <= 10^4 - 1, c_i <= (10^4 - 1)^2 * min(self.m_digits.size(), other.m_digits.size()) holds.
        // In addition, since self.m_digits.size() + other.m_digits.size() <= 2^25 + 1, c_i <= (10^4 - 1)^2 * 2^24 = 1677386072457216 holds eventually.
        // 1677386072457216 < 167772161 * 469762049 = 78812994116517889 holds, so we can reconstruct c_i from mod(c_i, 167772161) and mod(c_i, 469762049) by CRT.
        long long c_i = tools::garner2(c1[i], c2[i]);

        c_i += carry;
        carry = c_i / BASE;
        c_i %= BASE;
        self.m_digits.push_back(c_i);
      }
      if (carry > 0) {
        self.m_digits.push_back(carry);
      }

      self.m_nonnegative = self.m_nonnegative == other.m_nonnegative;
      self.template regularize<0>();
      return std::forward<decltype(self)>(self);
    }
    tools::bigint operator*(this auto&& lhs, const tools::bigint& rhs) {
      return tools::bigint(std::forward<decltype(lhs)>(lhs)) *= rhs;
    }

    auto operator/=(this tools::mutable_type auto&& self, const tools::bigint& other) -> decltype(self) {
      self = self / other;
      return std::forward<decltype(self)>(self);
    }
    friend tools::bigint operator/(const tools::bigint& lhs, const tools::bigint& rhs) {
      return lhs.divmod(rhs).first;
    }

    auto operator%=(this tools::mutable_type auto&& self, const tools::bigint& other) -> decltype(self) {
      self = self % other;
      return std::forward<decltype(self)>(self);
    }
    friend tools::bigint operator%(const tools::bigint& lhs, const tools::bigint& rhs) {
      return lhs.divmod(rhs).second;
    }

    explicit operator bool() const {
      return !this->m_digits.empty();
    }
    template <tools::non_bool_integral T>
    explicit operator T() const {
      assert(tools::bigint(std::numeric_limits<T>::min()) <= *this && *this <= tools::bigint(std::numeric_limits<T>::max()));
      T result = 0;
      for (std::size_t i = this->m_digits.size(); i --> 0;) {
        result = result * BASE + this->m_digits[i] * (this->m_nonnegative ? 1 : -1);
      }
      return result;
    }
    explicit operator double() const {
      long double result = 0.0;
      const std::size_t precision = this->size();
      for (std::size_t i = 0; i < std::numeric_limits<long double>::digits10; ++i) {
        result = result * 10.0L + (precision >= i + 1 ? (*this)[precision - 1 - i] : 0) * tools::signum(*this);
      }
      result *= std::pow(10.0L, static_cast<long double>(precision) - static_cast<long double>(std::numeric_limits<long double>::digits10));
      return static_cast<double>(result);
    }

    friend std::istream& operator>>(std::istream& is, tools::bigint& self) {
      std::string s;
      is >> s;
      self = tools::bigint(s);
      return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const tools::bigint& self) {
      if (!self.m_nonnegative) {
        os << '-';
      }
      if (self.m_digits.empty()) {
        return os << '0';
      }
      os << self.m_digits.back();
      for (std::size_t i = 1; i < self.m_digits.size(); ++i) {
        os << std::setw(LOG10_BASE) << std::setfill('0') << self.m_digits[self.m_digits.size() - 1 - i];
      }
      return os;
    }

    friend tools::detail::extgcd::impl<tools::bigint, tools::bigint>;
    friend tools::detail::gcd::impl<tools::bigint, tools::bigint>;
    friend tools::detail::signum::impl<tools::bigint>;
  };

  struct detail::gcd::impl<tools::bigint, tools::bigint>::mat22 {
    tools::bigint a00, a01, a10, a11;
  };

  tools::bigint detail::abs::impl<tools::bigint>::operator()(auto&& x) const {
    return tools::bigint(std::forward<decltype(x)>(x)).abs_inplace();
  };

  std::tuple<tools::bigint, tools::bigint, tools::bigint> detail::extgcd::impl<tools::bigint, tools::bigint>::operator()(tools::bigint a, tools::bigint b) const {
    const bool a_neg = !a.m_nonnegative;
    const bool b_neg = !b.m_nonnegative;

    a.abs_inplace();
    b.abs_inplace();

    // Track cumulative matrix M: [a, b]^T = M * [|a_orig|, |b_orig|]^T
    tools::bigint m00(1), m01(0), m10(0), m11(1);

    if (tools::bigint::compare_3way_abs(a, b) < 0) {
      std::swap(a, b);
      std::swap(m00, m10);
      std::swap(m01, m11);
    }

    while (!b.m_digits.empty()) {
      if (a.m_digits.size() <= 64) {
        while (!b.m_digits.empty()) {
          auto [q, r] = a.divmod(b);
          a = std::move(b);
          b = std::move(r);
          auto new_m10 = std::move(m00) - q * m10;
          auto new_m11 = std::move(m01) - q * m11;
          m00 = std::move(m10);
          m01 = std::move(m11);
          m10 = std::move(new_m10);
          m11 = std::move(new_m11);
        }
        break;
      }
      auto R = tools::detail::gcd::impl<tools::bigint, tools::bigint>::half_gcd(a, b);
      {
        auto new_m00 = R.a00 * m00 + R.a01 * m10;
        auto new_m01 = R.a00 * m01 + R.a01 * m11;
        auto new_m10 = R.a10 * m00 + R.a11 * m10;
        auto new_m11 = R.a10 * m01 + R.a11 * m11;
        m00 = std::move(new_m00);
        m01 = std::move(new_m01);
        m10 = std::move(new_m10);
        m11 = std::move(new_m11);
      }
      if (b.m_digits.empty()) break;
      if (tools::bigint::compare_3way_abs(a, b) < 0) {
        std::swap(a, b);
        std::swap(m00, m10);
        std::swap(m01, m11);
      }
      {
        auto [q, r] = a.divmod(b);
        a = std::move(b);
        b = std::move(r);
        auto new_m10 = std::move(m00) - q * m10;
        auto new_m11 = std::move(m01) - q * m11;
        m00 = std::move(m10);
        m01 = std::move(m11);
        m10 = std::move(new_m10);
        m11 = std::move(new_m11);
      }
    }

    // m00 * |a_orig| + m01 * |b_orig| = gcd  (first row)
    // m10 * |a_orig| + m11 * |b_orig| = 0    (second row)
    // From second row: b' = |b_orig|/gcd = |m10|, a' = |a_orig|/gcd = |m11|
    // Normalize m00 to [-b'/2, b'/2] for canonical (minimal) coefficients
    if (!a.m_digits.empty()) {
      auto b_prime = tools::abs(m10);
      if (b_prime > tools::bigint(1)) {
        auto a_prime = tools::abs(m11);
        // Centered reduction: m00 mod b_prime in [-b_prime/2, b_prime/2]
        auto r = m00 % b_prime;
        if (!r.m_nonnegative) r += b_prime;
        if (r * tools::bigint(2) > b_prime) r -= b_prime;
        m00 = std::move(r);
        // Recompute m01 from Bezout: m00*a' + m01*b' = 1
        m01 = (tools::bigint(1) - m00 * a_prime) / b_prime;
      }
    }

    // Adjust signs for original inputs
    if (a_neg) m00.negate();
    if (b_neg) m01.negate();

    return std::make_tuple(std::move(m00), std::move(m01), std::move(a));
  };

  auto detail::gcd::impl<tools::bigint, tools::bigint>::half_gcd(tools::bigint& a, tools::bigint& b) -> mat22 {
    const std::size_t n = a.m_digits.size();
    const std::size_t m = n / 2;

    if (b.m_digits.empty() || b.m_digits.size() <= m) {
      return {tools::bigint(1), tools::bigint(0), tools::bigint(0), tools::bigint(1)};
    }

    if (n <= 64) {
      mat22 R = {tools::bigint(1), tools::bigint(0), tools::bigint(0), tools::bigint(1)};
      while (!b.m_digits.empty() && b.m_digits.size() > m) {
        auto [q, r] = a.divmod(b);
        a = std::move(b);
        b = std::move(r);
        auto new_a10 = std::move(R.a00) - q * R.a10;
        auto new_a11 = std::move(R.a01) - q * R.a11;
        R.a00 = std::move(R.a10);
        R.a01 = std::move(R.a11);
        R.a10 = std::move(new_a10);
        R.a11 = std::move(new_a11);
      }
      return R;
    }

    // First recursive call on top halves
    auto a1 = a.rshift(m);
    auto b1 = b.rshift(m);
    auto R = half_gcd(a1, b1);

    // Apply R to full (a, b)
    {
      auto na = R.a00 * a + R.a01 * b;
      auto nb = R.a10 * a + R.a11 * b;
      a = std::move(na);
      b = std::move(nb);
    }
    if (!a.m_nonnegative) { a.negate(); R.a00.negate(); R.a01.negate(); }
    if (!b.m_nonnegative) { b.negate(); R.a10.negate(); R.a11.negate(); }
    if (tools::bigint::compare_3way_abs(a, b) < 0) {
      std::swap(a, b);
      std::swap(R.a00, R.a10);
      std::swap(R.a01, R.a11);
    }

    if (b.m_digits.empty() || b.m_digits.size() <= m) {
      return R;
    }

    // Euclidean step
    {
      auto [q, r] = a.divmod(b);
      a = std::move(b);
      b = std::move(r);
      auto new_a10 = std::move(R.a00) - q * R.a10;
      auto new_a11 = std::move(R.a01) - q * R.a11;
      R.a00 = std::move(R.a10);
      R.a01 = std::move(R.a11);
      R.a10 = std::move(new_a10);
      R.a11 = std::move(new_a11);
    }

    if (b.m_digits.empty() || b.m_digits.size() <= m) {
      return R;
    }

    // Second recursive call on top halves (adjusted shift)
    const std::size_t l = a.m_digits.size();
    const std::size_t k = (2 * m >= l) ? (2 * m - l) : 0;
    auto a2 = a.rshift(k);
    auto b2 = b.rshift(k);
    auto R2 = half_gcd(a2, b2);

    // Apply R2 to (a, b)
    {
      auto na = R2.a00 * a + R2.a01 * b;
      auto nb = R2.a10 * a + R2.a11 * b;
      a = std::move(na);
      b = std::move(nb);
    }
    if (!a.m_nonnegative) { a.negate(); R2.a00.negate(); R2.a01.negate(); }
    if (!b.m_nonnegative) { b.negate(); R2.a10.negate(); R2.a11.negate(); }
    if (tools::bigint::compare_3way_abs(a, b) < 0) {
      std::swap(a, b);
      std::swap(R2.a00, R2.a10);
      std::swap(R2.a01, R2.a11);
    }

    // Combine R2 * R
    return {
      R2.a00 * R.a00 + R2.a01 * R.a10,
      R2.a00 * R.a01 + R2.a01 * R.a11,
      R2.a10 * R.a00 + R2.a11 * R.a10,
      R2.a10 * R.a01 + R2.a11 * R.a11
    };
  }
  tools::bigint detail::gcd::impl<tools::bigint, tools::bigint>::operator()(tools::bigint a, tools::bigint b) const {
    a.abs_inplace();
    b.abs_inplace();
    if (tools::bigint::compare_3way_abs(a, b) < 0) std::swap(a, b);

    while (!b.m_digits.empty()) {
      if (a.m_digits.size() <= 64) {
        while (!b.m_digits.empty()) {
          a %= b;
          std::swap(a, b);
        }
        break;
      }
      half_gcd(a, b);
      if (b.m_digits.empty()) break;
      if (tools::bigint::compare_3way_abs(a, b) < 0) std::swap(a, b);
      auto [q, r] = a.divmod(b);
      a = std::move(b);
      b = std::move(r);
    }

    return a;
  };

  int detail::signum::impl<tools::bigint>::operator()(const tools::bigint& x) const {
    if (!x.m_nonnegative) return -1;
    if (x.m_digits.empty()) return 0;
    return 1;
  };
}

#endif
