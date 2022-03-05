#ifndef TOOLS_DYNAMIC_BITSET_HPP
#define TOOLS_DYNAMIC_BITSET_HPP

#include <cstddef>
#include <vector>
#include <cstdint>
#include <limits>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "tools/ceil.hpp"
#include "tools/popcount.hpp"

namespace tools {
  class dynamic_bitset {
  private:
    ::std::size_t m_size;
    ::std::vector<::std::uint64_t> m_bits;

  public:
    dynamic_bitset() : m_size(0) {}
    explicit dynamic_bitset(const ::std::size_t size) : m_size(size), m_bits(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits)) {}
    dynamic_bitset(const ::tools::dynamic_bitset&) = default;
    dynamic_bitset(::tools::dynamic_bitset&&) = default;
    ~dynamic_bitset() = default;
    ::tools::dynamic_bitset& operator=(const ::tools::dynamic_bitset&) = default;
    ::tools::dynamic_bitset& operator=(::tools::dynamic_bitset&&) = default;

    ::tools::dynamic_bitset& operator&=(const ::tools::dynamic_bitset& other) {
      assert(this->m_size == other.m_size);
      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
        this->m_bits[i] &= other.m_bits[i];
      }
      return *this;
    }
    ::tools::dynamic_bitset& operator|=(const ::tools::dynamic_bitset& other) {
      assert(this->m_size == other.m_size);
      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
        this->m_bits[i] |= other.m_bits[i];
      }
      return *this;
    }
    ::tools::dynamic_bitset& operator^=(const ::tools::dynamic_bitset& other) {
      assert(this->m_size == other.m_size);
      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
        this->m_bits[i] ^= other.m_bits[i];
      }
      return *this;
    }
    ::tools::dynamic_bitset& operator<<=(const ::std::size_t pos) {
      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;
      if (diff < this->m_bits.size()) {
        if (pos % ::std::numeric_limits<::std::uint64_t>::digits > 0) {
          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {
            this->m_bits[i] <<= pos % ::std::numeric_limits<::std::uint64_t>::digits;
            if (i > 0) {
              this->m_bits[i] |= this->m_bits[i - 1] >> (pos - pos % ::std::numeric_limits<::std::uint64_t>::digits);
            }
          }
        }
        if (diff > 0) {
          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {
            this->m_bits[i + diff] = this->m_bits[i];
          }
          ::std::fill(this->m_bits.begin(), ::std::next(this->m_bits.begin(), diff), 0);
        }
        if (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {
          this->m_bits.back() &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits)) - 1;
        }
      } else {
        ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);
      }
      return *this;
    }
    ::tools::dynamic_bitset& operator>>=(const ::std::size_t pos) {
      const ::std::size_t diff = pos / ::std::numeric_limits<::std::uint64_t>::digits;
      if (diff < this->m_bits.size()) {
        if (pos % ::std::numeric_limits<::std::uint64_t>::digits > 0) {
          for (::std::size_t i = diff; i < this->m_bits.size(); ++i) {
            this->m_bits[i] >>= pos % ::std::numeric_limits<::std::uint64_t>::digits;
            if (i + 1 < this->m_bits.size()) {
              this->m_bits[i] |= this->m_bits[i + 1] << (pos - pos % ::std::numeric_limits<::std::uint64_t>::digits);
            }
          }
        }
        if (diff > 0) {
          for (::std::size_t i = diff; i < this->m_bits.size(); ++i) {
            this->m_bits[i - diff] = this->m_bits[i];
          }
          ::std::fill(::std::next(this->m_bits.begin(), this->m_bits.size() - diff), this->m_bits.end(), 0);
        }
      } else {
        ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);
      }
      return *this;
    }
    ::tools::dynamic_bitset& set() {
      ::std::fill(this->m_bits.begin(), this->m_bits.end(), ::std::numeric_limits<::std::uint64_t>::max());
      if (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {
        this->m_bits.back() &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits)) - 1;
      }
      return *this;
    }
    ::tools::dynamic_bitset& set(const ::std::size_t pos) {
      assert(pos < this->m_size);
      this->m_bits[pos / ::std::numeric_limits<::std::uint64_t>::digits] |= ::std::uint64_t(1) << (pos % ::std::numeric_limits<::std::uint64_t>::digits);
      return *this;
    }
    ::tools::dynamic_bitset& reset() {
      ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);
      return *this;
    }
    ::tools::dynamic_bitset& reset(const ::std::size_t pos) {
      assert(pos < this->m_size);
      this->m_bits[pos / ::std::numeric_limits<::std::uint64_t>::digits] &= ~(::std::uint64_t(1) << (pos % ::std::numeric_limits<::std::uint64_t>::digits));
      return *this;
    }
    ::tools::dynamic_bitset& set(const ::std::size_t pos, const bool val) {
      return val ? this->set(pos) : this->reset(pos);
    }
    ::tools::dynamic_bitset& flip() {
      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
        this->m_bits[i] = ~this->m_bits[i];
      }
      if (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {
        this->m_bits.back() &= (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits)) - 1;
      }
      return *this;
    }
    ::tools::dynamic_bitset& flip(const ::std::size_t pos) {
      assert(pos < this->m_size);
      this->m_bits[pos / ::std::numeric_limits<::std::uint64_t>::digits] ^= ::std::uint64_t(1) << (pos % ::std::numeric_limits<::std::uint64_t>::digits);
      return *this;
    }
    ::tools::dynamic_bitset operator~() const {
      return ::tools::dynamic_bitset(*this).flip();
    }
    ::std::size_t count() const {
      ::std::size_t result = 0;
      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
        result += ::tools::popcount(this->m_bits[i]);
      }
      return result;
    }
    ::std::size_t size() const {
      return this->m_size;
    }
    bool test(const ::std::size_t pos) const {
      assert(pos < this->m_size);
      return (this->m_bits[pos / ::std::numeric_limits<::std::uint64_t>::digits] >> (pos % ::std::numeric_limits<::std::uint64_t>::digits)) & 1;
    }
    bool operator[](const ::std::size_t pos) const {
      return this->test(pos);
    }
    bool all() const {
      if (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {
        for (::std::size_t i = 0; i + 1 < this->m_bits.size(); ++i) {
          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max()) {
            return false;
          }
        }
        return this->m_bits.back() == (::std::uint64_t(1) << (this->m_size % ::std::numeric_limits<::std::uint64_t>::digits)) - 1;
      } else {
        for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max()) {
            return false;
          }
        }
        return true;
      }
    }
    bool any() const {
      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
        if (this->m_bits[i] != 0) {
          return true;
        }
      }
      return false;
    }
    bool none() const {
      return !this->any();
    }
    friend bool operator==(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset& rhs) {
      return lhs.m_size == rhs.m_size && lhs.m_bits == rhs.m_bits;
    }
    friend bool operator!=(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset& rhs) {
      return !(lhs == rhs);
    }
    ::tools::dynamic_bitset operator<<(const ::std::size_t pos) const {
      return ::tools::dynamic_bitset(*this) <<= pos;
    }
    ::tools::dynamic_bitset operator>>(const ::std::size_t pos) const {
      return ::tools::dynamic_bitset(*this) >>= pos;
    }
    friend ::tools::dynamic_bitset operator&(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset& rhs) {
      return ::tools::dynamic_bitset(lhs) &= rhs;
    }
    friend ::tools::dynamic_bitset operator|(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset& rhs) {
      return ::tools::dynamic_bitset(lhs) |= rhs;
    }
    friend ::tools::dynamic_bitset operator^(const ::tools::dynamic_bitset& lhs, const ::tools::dynamic_bitset& rhs) {
      return ::tools::dynamic_bitset(lhs) ^= rhs;
    }
    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::dynamic_bitset& self) {
      for (::std::size_t i = self.m_bits.size(); i --> 0;) {
        for (::std::size_t j = (self.m_size - 1) % ::std::numeric_limits<::std::uint64_t>::digits + 1; j --> 0;) {
          os << ((self.m_bits[i] >> j) & 1);
        }
      }
      return os;
    }
    void resize(const ::std::size_t size) {
      this->m_size = size;
      this->m_bits.resize(::tools::ceil(size, ::std::numeric_limits<::std::uint64_t>::digits));
      if (size % ::std::numeric_limits<::std::uint64_t>::digits > 0) {
        this->m_bits.back() &= (::std::uint64_t(1) << (size % ::std::numeric_limits<::std::uint64_t>::digits)) - 1;
      }
    }
    void shrink_to_fit() {
      this->m_bits.shrink_to_fit();
    }
  };
}

#endif
