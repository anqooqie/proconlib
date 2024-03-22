#ifndef TOOLS_DYNAMIC_BITSET_HPP
#define TOOLS_DYNAMIC_BITSET_HPP

#include <cstddef>
#include <limits>
#include <cstdint>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include "tools/ceil.hpp"
#include "tools/popcount.hpp"
#include "tools/countr_zero.hpp"

namespace tools {
  class dynamic_bitset {
    constexpr static ::std::size_t W = ::std::numeric_limits<::std::uint64_t>::digits;
    ::std::size_t m_size;
    ::std::vector<::std::uint64_t> m_bits;

  public:
    class reference {
      friend class ::tools::dynamic_bitset;

      ::tools::dynamic_bitset *m_parent;
      ::std::size_t m_pos;

      reference(::tools::dynamic_bitset * const parent, const ::std::size_t pos) : m_parent(parent), m_pos(pos) {
      }

    public:
      reference(const reference&) = default;
      reference& operator=(const bool x) {
        this->m_parent->set(this->m_pos, x);
        return *this;
      }
      reference& operator=(const reference& other) {
        return *this = static_cast<bool>(other);
      }
      bool operator~() const {
        return !static_cast<bool>(*this);
      }
      operator bool() const {
        return this->m_parent->test(this->m_pos);
      }
      reference& flip() {
        this->m_parent->flip(this->m_pos);
        return *this;
      }
    };

    dynamic_bitset() : m_size(0) {}
    explicit dynamic_bitset(const ::std::size_t size) : m_size(size), m_bits(::tools::ceil(size, W), 0) {}
    explicit dynamic_bitset(const ::std::string& str) : m_size(str.size()), m_bits(::tools::ceil(str.size(), W), 0) {
      for (::std::size_t i = 0; i < str.size(); ++i) {
        const auto c = str[str.size() - 1 - i];
        assert(c == '0' || c == '1');
        if (c == '1') {
          this->m_bits[i / W] |= UINT64_C(1) << (i % W);
        }
      }
    }

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
      const ::std::size_t diff = pos / W;
      if (diff < this->m_bits.size()) {
        if (pos % W > 0) {
          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {
            this->m_bits[i] <<= pos % W;
            if (i > 0) {
              this->m_bits[i] |= this->m_bits[i - 1] >> (W - pos % W);
            }
          }
        }
        if (diff > 0) {
          for (::std::size_t i = this->m_bits.size() - diff; i --> 0;) {
            this->m_bits[i + diff] = this->m_bits[i];
          }
          ::std::fill(this->m_bits.begin(), ::std::next(this->m_bits.begin(), diff), 0);
        }
        if (this->m_size % W > 0) {
          this->m_bits.back() &= (UINT64_C(1) << (this->m_size % W)) - 1;
        }
      } else {
        ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);
      }
      return *this;
    }
    ::tools::dynamic_bitset& operator>>=(const ::std::size_t pos) {
      const ::std::size_t diff = pos / W;
      if (diff < this->m_bits.size()) {
        if (pos % W > 0) {
          for (::std::size_t i = diff; i < this->m_bits.size(); ++i) {
            this->m_bits[i] >>= pos % W;
            if (i + 1 < this->m_bits.size()) {
              this->m_bits[i] |= this->m_bits[i + 1] << (W - pos % W);
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
      if (this->m_size % W > 0) {
        this->m_bits.back() &= (UINT64_C(1) << (this->m_size % W)) - 1;
      }
      return *this;
    }
    ::tools::dynamic_bitset& set(const ::std::size_t pos) {
      assert(pos < this->m_size);
      this->m_bits[pos / W] |= UINT64_C(1) << (pos % W);
      return *this;
    }
    ::tools::dynamic_bitset& set(const ::std::size_t pos, const bool val) {
      return val ? this->set(pos) : this->reset(pos);
    }
    ::tools::dynamic_bitset& reset() {
      ::std::fill(this->m_bits.begin(), this->m_bits.end(), 0);
      return *this;
    }
    ::tools::dynamic_bitset& reset(const ::std::size_t pos) {
      assert(pos < this->m_size);
      this->m_bits[pos / W] &= ~(UINT64_C(1) << (pos % W));
      return *this;
    }
    ::tools::dynamic_bitset operator~() const {
      return ::tools::dynamic_bitset(*this).flip();
    }
    ::tools::dynamic_bitset& flip() {
      for (::std::size_t i = 0; i < this->m_bits.size(); ++i) {
        this->m_bits[i] = ~this->m_bits[i];
      }
      if (this->m_size % W > 0) {
        this->m_bits.back() &= (UINT64_C(1) << (this->m_size % W)) - 1;
      }
      return *this;
    }
    ::tools::dynamic_bitset& flip(const ::std::size_t pos) {
      assert(pos < this->m_size);
      this->m_bits[pos / W] ^= UINT64_C(1) << (pos % W);
      return *this;
    }
    reference operator[](const ::std::size_t pos) {
      return reference(this, pos);
    }
    bool operator[](const ::std::size_t pos) const {
      return this->test(pos);
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
      return (this->m_bits[pos / W] >> (pos % W)) & 1;
    }
    bool all() const {
      if (this->m_size % W > 0) {
        for (::std::size_t i = 0; i + 1 < this->m_bits.size(); ++i) {
          if (this->m_bits[i] != ::std::numeric_limits<::std::uint64_t>::max()) {
            return false;
          }
        }
        return this->m_bits.back() == (UINT64_C(1) << (this->m_size % W)) - 1;
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
    ::std::string to_string() const {
      ::std::ostringstream oss;
      oss << *this;
      return oss.str();
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
    friend ::std::istream& operator>>(::std::istream& is, ::tools::dynamic_bitset& self) {
      ::std::string s;
      is >> s;
      self = ::tools::dynamic_bitset(s);
      return is;
    }
    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::dynamic_bitset& self) {
      for (::std::size_t i = self.m_bits.size(); i --> 0;) {
        for (::std::size_t j = i + 1 < self.m_bits.size() ? W : (self.m_size - 1) % W + 1; j --> 0;) {
          os << ((self.m_bits[i] >> j) & 1);
        }
      }
      return os;
    }
    void resize(const ::std::size_t size) {
      this->m_size = size;
      this->m_bits.resize(::tools::ceil(size, W));
      if (size % W > 0) {
        this->m_bits.back() &= (UINT64_C(1) << (size % W)) - 1;
      }
    }
    void shrink_to_fit() {
      this->m_bits.shrink_to_fit();
    }
  private:
    ::std::size_t Find_first(const ::std::size_t offset) const {
      for (::std::size_t i = offset; i < this->m_bits.size(); ++i) {
        if (this->m_bits[i] > 0) {
          return i * W + ::tools::countr_zero(this->m_bits[i]);
        }
      }
      return this->m_size;
    }
  public:
    ::std::size_t Find_first() const {
      return this->Find_first(0);
    }
    ::std::size_t Find_next(const ::std::size_t pos) const {
      assert(pos < this->m_size);

      if (pos % W == W - 1) return this->Find_first((pos + 1) / W);
      if (const auto x = this->m_bits[pos / W] >> (pos % W + 1); x > 0) return pos + ::tools::countr_zero(x) + 1;
      return this->Find_first(pos / W + 1);
    }
  };
}

#endif
