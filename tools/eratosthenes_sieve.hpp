#ifndef TOOLS_ERATOSTHENES_SIEVE_HPP
#define TOOLS_ERATOSTHENES_SIEVE_HPP

#include <array>
#include <cstdint>
#include <vector>
#include <cstddef>
#include <iterator>
#include <cassert>
#include <algorithm>

namespace tools {
  template <typename T>
  class eratosthenes_sieve {
    constexpr static ::std::array<::std::uint64_t, 15> init = {
      UINT64_C(0b0010100000100010100010100010000010100000100010100010100010000010),
      UINT64_C(0b1000001010000010001010001010001000001010000010001010001010001000),
      UINT64_C(0b1000100000101000001000101000101000100000101000001000101000101000),
      UINT64_C(0b0010100010000010100000100010100010100010000010100000100010100010),
      UINT64_C(0b1010001010001000001010000010001010001010001000001010000010001010),
      UINT64_C(0b1000101000101000100000101000001000101000101000100000101000001000),
      UINT64_C(0b0000100010100010100010000010100000100010100010100010000010100000),
      UINT64_C(0b1010000010001010001010001000001010000010001010001010001000001010),
      UINT64_C(0b0000101000001000101000101000100000101000001000101000101000100000),
      UINT64_C(0b0010000010100000100010100010100010000010100000100010100010100010),
      UINT64_C(0b1010001000001010000010001010001010001000001010000010001010001010),
      UINT64_C(0b1000101000100000101000001000101000101000100000101000001000101000),
      UINT64_C(0b0010100010100010000010100000100010100010100010000010100000100010),
      UINT64_C(0b0010001010001010001000001010000010001010001010001000001010000010),
      UINT64_C(0b1000001000101000101000100000101000001000101000101000100000101000),
    };
    ::std::vector<::std::uint64_t> m_is_prime;
    int m_n;

  public:
    class prime_iterable {
    private:
      ::tools::eratosthenes_sieve<T> const *m_parent;
      int m_l;
      int m_r;

    public:
      class iterator {
      private:
        ::tools::eratosthenes_sieve<T> const *m_parent;
        int m_p;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(::tools::eratosthenes_sieve<T> const * const parent, const int p) : m_parent(parent), m_p(p) {
          for (; this->m_p <= parent->m_n && !parent->is_prime(this->m_p); ++this->m_p);
        }

        value_type operator*() const {
          return this->m_p;
        }
        iterator& operator++() {
          for (++this->m_p; this->m_p <= this->m_parent->m_n && !this->m_parent->is_prime(this->m_p); ++this->m_p);
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          return lhs.m_p == rhs.m_p;
        }
        friend bool operator!=(const iterator lhs, const iterator rhs) {
          return !(lhs == rhs);
        }
      };

      prime_iterable() = default;
      prime_iterable(::tools::eratosthenes_sieve<T> const * const parent, const int l, const int r) : m_parent(parent), m_l(l), m_r(r) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_l);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_r + 1);
      }
    };

    eratosthenes_sieve() = default;
    explicit eratosthenes_sieve(const int n) : m_n(n) {
      assert(n >= 1);
      this->m_is_prime.reserve((n >> 6) + 1);
      for (int i = 0; i <= n; i += 960) {
        ::std::copy(init.begin(), n < i + 959 ? ::std::next(init.begin(), (n >> 6) % 15 + 1) : init.end(), ::std::back_inserter(this->m_is_prime));
      }
      this->m_is_prime[0] ^= UINT64_C(0b101110);

      int i = 7;
      while (true) {
        if (n < i * i) break;
        if (this->is_prime(i)) { // 7
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 7 * 1
            j += i * 6;
            if (n < j) break;
          }
        }
        i += 4;
        if (n < i * i) break;
        if (this->is_prime(i)) { // 11
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 11 * 7
            j += i * 4;
            if (n < j) break;
          }
        }
        i += 2;
        if (n < i * i) break;
        if (this->is_prime(i)) { // 13
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 13 * 11
            j += i + i;
            if (n < j) break;
          }
        }
        i += 4;
        if (n < i * i) break;
        if (this->is_prime(i)) { // 17
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 17 * 13
            j += i * 4;
            if (n < j) break;
          }
        }
        i += 2;
        if (n < i * i) break;
        if (this->is_prime(i)) { // 19
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 19 * 17
            j += i + i;
            if (n < j) break;
          }
        }
        i += 4;
        if (n < i * i) break;
        if (this->is_prime(i)) { // 23
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 23 * 19
            j += i * 4;
            if (n < j) break;
          }
        }
        i += 6;
        if (n < i * i) break;
        if (this->is_prime(i)) { // 29
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 29 * 23
            j += i * 6;
            if (n < j) break;
          }
        }
        i += 2;
        if (n < i * i) break;
        if (this->is_prime(i)) { // 1
          int j = i * i;
          while (true) {
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j >> 6] &= ~(UINT64_C(1) << (j & 0b111111)); // 1 * 29
            j += i + i;
            if (n < j) break;
          }
        }
        i += 6;
      }
    }

    inline bool is_prime(const int i) const {
      assert(1 <= i && i <= this->m_n);
      return (this->m_is_prime[i >> 6] >> (i & 0b111111)) & 1;
    }

    prime_iterable prime_range(const int l, const int r) const {
      assert(1 <= l && l <= r && r <= this->m_n);
      return prime_iterable(this, l, r);
    }
  };
}

#endif
