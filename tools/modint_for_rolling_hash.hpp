#ifndef TOOLS_MODINT_FOR_ROLLING_HASH_HPP
#define TOOLS_MODINT_FOR_ROLLING_HASH_HPP

#include <cstdint>
#include <chrono>
#include <cassert>

namespace tools {
  class modint_for_rolling_hash {
  private:
    static constexpr ::std::uint64_t MASK30 = (::std::uint64_t(1) << 30) - 1;
    static constexpr ::std::uint64_t MASK31 = (::std::uint64_t(1) << 31) - 1;
    static constexpr ::std::uint64_t MOD = (::std::uint64_t(1) << 61) - 1;
    static constexpr ::std::uint64_t MASK61 = MOD;
    static constexpr ::std::uint64_t POSITIVIZER = MOD * 4;

    inline static ::std::uint64_t m_base = ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    inline static ::std::vector<::std::uint64_t> m_pow_base;
    ::std::uint64_t m_value;

    modint_for_rolling_hash(const ::std::uint64_t x, int) : m_value(x) {
    }

  public:
    static ::std::uint64_t mul(const ::std::uint64_t a, const ::std::uint64_t b) {
      assert(a < MOD);
      assert(b < MOD);
      const ::std::uint64_t au = a >> 31;
      const ::std::uint64_t ad = a & MASK31;
      const ::std::uint64_t bu = b >> 31;
      const ::std::uint64_t bd = b & MASK31;
      const ::std::uint64_t mid = ad * bu + au * bd;
      const ::std::uint64_t midu = mid >> 30;
      const ::std::uint64_t midd = mid & MASK30;
      return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }
    static ::std::uint64_t calc_mod(const ::std::uint64_t x) {
      const ::std::uint64_t xu = x >> 61;
      const ::std::uint64_t xd = x & MASK61;
      ::std::uint64_t res = xu + xd;
      if (res >= MOD) res -= MOD;
      return res;
    }

    modint_for_rolling_hash() = default;
    modint_for_rolling_hash(const ::tools::modint_for_rolling_hash&) = default;
    modint_for_rolling_hash(::tools::modint_for_rolling_hash&&) = default;
    ~modint_for_rolling_hash() = default;
    ::tools::modint_for_rolling_hash& operator=(const ::tools::modint_for_rolling_hash&) = default;
    ::tools::modint_for_rolling_hash& operator=(::tools::modint_for_rolling_hash&&) = default;

    explicit modint_for_rolling_hash(const ::std::uint64_t x) : m_value(calc_mod(x)) {
    }

    ::tools::modint_for_rolling_hash operator+() const {
      return *this;
    }
    ::tools::modint_for_rolling_hash operator-() const {
      return ::tools::modint_for_rolling_hash(POSITIVIZER - this->m_value);
    }
    friend ::tools::modint_for_rolling_hash operator+(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash& rhs) {
      return ::tools::modint_for_rolling_hash(lhs.m_value + rhs.m_value);
    }
    ::tools::modint_for_rolling_hash& operator+=(const ::tools::modint_for_rolling_hash& other) {
      this->m_value = calc_mod(this->m_value + other.m_value);
      return *this;
    }
    friend ::tools::modint_for_rolling_hash operator-(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash& rhs) {
      return ::tools::modint_for_rolling_hash(lhs.m_value + POSITIVIZER - rhs.m_value);
    }
    ::tools::modint_for_rolling_hash& operator-=(const ::tools::modint_for_rolling_hash& other) {
      this->m_value = calc_mod(this->m_value + POSITIVIZER - other.m_value);
      return *this;
    }
    friend ::tools::modint_for_rolling_hash operator*(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash& rhs) {
      return ::tools::modint_for_rolling_hash(mul(lhs.m_value, rhs.m_value));
    }
    ::tools::modint_for_rolling_hash& operator*=(const ::tools::modint_for_rolling_hash& other) {
      this->m_value = calc_mod(mul(this->m_value, other.m_value));
      return *this;
    }

    friend bool operator==(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash& rhs) {
      return lhs.m_value == rhs.m_value;
    }
    friend bool operator!=(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash& rhs) {
      return lhs.m_value != rhs.m_value;
    }

    ::std::uint64_t val() const {
      return this->m_value;
    }

    static ::tools::modint_for_rolling_hash raw(const ::std::uint64_t x) {
      return ::tools::modint_for_rolling_hash(x, 0);
    }
    static ::std::uint64_t mod() {
      return MOD;
    }
    static ::std::uint64_t positivizer() {
      return POSITIVIZER;
    }
    static ::std::uint64_t base() {
      return m_base;
    }
    static ::std::uint64_t pow_base(const ::std::uint64_t n) {
      while (m_pow_base.size() <= n) {
        m_pow_base.push_back(m_pow_base.empty() ? 1 : calc_mod(mul(m_pow_base.back(), m_base)));
      }
      return m_pow_base[n];
    }
  };
}

#endif
