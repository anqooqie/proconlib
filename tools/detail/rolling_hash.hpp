#ifndef TOOLS_DETAIL_ROLLING_HASH_HPP
#define TOOLS_DETAIL_ROLLING_HASH_HPP

#include <cstdint>
#include <cassert>
#include <tuple>
#include <vector>
#include "tools/pow.hpp"
#include "tools/extgcd.hpp"
#include "tools/pow_mod_cache.hpp"
#include "tools/now.hpp"

namespace tools {
  class rolling_hash;

  class modint_for_rolling_hash {
  private:
    static constexpr std::uint64_t MASK30 = (std::uint64_t(1) << 30) - 1;
    static constexpr std::uint64_t MASK31 = (std::uint64_t(1) << 31) - 1;
    static constexpr std::uint64_t MOD = (std::uint64_t(1) << 61) - 1;
    static constexpr std::uint64_t MASK61 = MOD;
    static constexpr std::uint64_t POSITIVIZER = MOD * 4;

    std::uint64_t m_val;

    modint_for_rolling_hash(const std::uint64_t x, int) : m_val(x) {
    }

    static std::uint64_t mul(const std::uint64_t a, const std::uint64_t b) {
      assert(a < MOD);
      assert(b < MOD);
      const std::uint64_t au = a >> 31;
      const std::uint64_t ad = a & MASK31;
      const std::uint64_t bu = b >> 31;
      const std::uint64_t bd = b & MASK31;
      const std::uint64_t mid = ad * bu + au * bd;
      const std::uint64_t midu = mid >> 30;
      const std::uint64_t midd = mid & MASK30;
      return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }
    static std::uint64_t calc_mod(const std::uint64_t x) {
      const std::uint64_t xu = x >> 61;
      const std::uint64_t xd = x & MASK61;
      std::uint64_t res = xu + xd;
      if (res >= MOD) res -= MOD;
      return res;
    }

  public:
    modint_for_rolling_hash() = default;
    modint_for_rolling_hash(const tools::modint_for_rolling_hash&) = default;
    modint_for_rolling_hash(tools::modint_for_rolling_hash&&) = default;
    ~modint_for_rolling_hash() = default;
    tools::modint_for_rolling_hash& operator=(const tools::modint_for_rolling_hash&) = default;
    tools::modint_for_rolling_hash& operator=(tools::modint_for_rolling_hash&&) = default;

    explicit modint_for_rolling_hash(const std::uint64_t x) : m_val(calc_mod(x)) {
    }

    tools::modint_for_rolling_hash pow(const long long n) const {
      return tools::pow(*this, n);
    }
    tools::modint_for_rolling_hash inv() const {
      assert(this->m_val != 0);
      return tools::modint_for_rolling_hash(std::get<0>(tools::extgcd(this->m_val, MOD)));
    }

    tools::modint_for_rolling_hash operator+() const {
      return *this;
    }
    tools::modint_for_rolling_hash operator-() const {
      return tools::modint_for_rolling_hash(POSITIVIZER - this->m_val);
    }
    friend tools::modint_for_rolling_hash operator+(const tools::modint_for_rolling_hash& lhs, const tools::modint_for_rolling_hash& rhs) {
      return tools::modint_for_rolling_hash(lhs.m_val + rhs.m_val);
    }
    tools::modint_for_rolling_hash& operator+=(const tools::modint_for_rolling_hash& other) {
      this->m_val = calc_mod(this->m_val + other.m_val);
      return *this;
    }
    friend tools::modint_for_rolling_hash operator-(const tools::modint_for_rolling_hash& lhs, const tools::modint_for_rolling_hash& rhs) {
      return tools::modint_for_rolling_hash(lhs.m_val + POSITIVIZER - rhs.m_val);
    }
    tools::modint_for_rolling_hash& operator-=(const tools::modint_for_rolling_hash& other) {
      this->m_val = calc_mod(this->m_val + POSITIVIZER - other.m_val);
      return *this;
    }
    friend tools::modint_for_rolling_hash operator*(const tools::modint_for_rolling_hash& lhs, const tools::modint_for_rolling_hash& rhs) {
      return tools::modint_for_rolling_hash(mul(lhs.m_val, rhs.m_val));
    }
    tools::modint_for_rolling_hash& operator*=(const tools::modint_for_rolling_hash& other) {
      this->m_val = calc_mod(mul(this->m_val, other.m_val));
      return *this;
    }
    friend tools::modint_for_rolling_hash operator/(const tools::modint_for_rolling_hash& lhs, const tools::modint_for_rolling_hash& rhs) {
      return tools::modint_for_rolling_hash(mul(lhs.m_val, rhs.inv().m_val));
    }
    tools::modint_for_rolling_hash& operator/=(const tools::modint_for_rolling_hash& other) {
      this->m_val = calc_mod(mul(this->m_val, other.inv().m_val));
      return *this;
    }
    tools::modint_for_rolling_hash& operator++() {
      this->m_val = calc_mod(this->m_val + 1);
      return *this;
    }
    tools::modint_for_rolling_hash operator++(int) {
      const auto result = *this;
      ++(*this);
      return result;
    }
    tools::modint_for_rolling_hash& operator--() {
      this->m_val = calc_mod(this->m_val + POSITIVIZER - 1);
      return *this;
    }
    tools::modint_for_rolling_hash operator--(int) {
      const auto result = *this;
      --(*this);
      return result;
    }

    friend bool operator==(const tools::modint_for_rolling_hash& lhs, const tools::modint_for_rolling_hash& rhs) {
      return lhs.m_val == rhs.m_val;
    }
    friend bool operator!=(const tools::modint_for_rolling_hash& lhs, const tools::modint_for_rolling_hash& rhs) {
      return lhs.m_val != rhs.m_val;
    }

    long long val() const {
      return this->m_val;
    }

    static tools::modint_for_rolling_hash raw(const std::uint64_t x) {
      return tools::modint_for_rolling_hash(x, 0);
    }
    static long long mod() {
      return MOD;
    }

    friend tools::rolling_hash;
  };

  class rolling_hash {
  private:
    using mint = tools::modint_for_rolling_hash;
    inline static tools::pow_mod_cache<mint> m_pow_base = tools::pow_mod_cache<mint>(tools::now());
    std::vector<mint> m_hash;

  public:
    rolling_hash() = default;
    rolling_hash(const tools::rolling_hash&) = default;
    rolling_hash(tools::rolling_hash&&) = default;
    ~rolling_hash() = default;
    tools::rolling_hash& operator=(const tools::rolling_hash&) = default;
    tools::rolling_hash& operator=(tools::rolling_hash&&) = default;

    template <typename InputIterator>
    rolling_hash(InputIterator begin, InputIterator end) {
      this->m_hash.push_back(mint::raw(0));
      const auto base = m_pow_base[1].m_val;
      for (auto it = begin; it != end; ++it) {
        this->m_hash.emplace_back(mint::mul(this->m_hash.back().m_val, base) + *it);
      }
      m_pow_base[this->m_hash.size()];
    }

    mint pow_base(const std::size_t i) const {
      return m_pow_base[i];
    }

    mint slice(const std::size_t l, const std::size_t r) const {
      assert(l <= r && r <= this->m_hash.size());
      return mint(this->m_hash[r].m_val + mint::POSITIVIZER - mint::mul(this->m_hash[l].m_val, m_pow_base[r - l].m_val));
    }
  };
}

#endif
