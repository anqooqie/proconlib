#ifndef TOOLS_ERATOSTHENES_SIEVE_HPP
#define TOOLS_ERATOSTHENES_SIEVE_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <optional>
#include <ranges>
#include "tools/block_floor.hpp"
#include "tools/ceil.hpp"
#include "tools/chmax.hpp"
#include "tools/chmin.hpp"
#include "tools/dynamic_bitset.hpp"
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral T>
  class eratosthenes_sieve {
    tools::dynamic_bitset m_is_prime;
    T m_n;

    static constexpr bool coprime_to_30(const T i) {
      assert(i >= 0);
      return (UINT32_C(0b100000100010100010100010000010) >> (i % 30)) & 1;
    }
    // (1, 7, 11, 13, 17, 19, 23, 29) => (0, 1, 2, 3, 4, 5, 6, 7)
    static constexpr int encode(const int x) {
      assert(0 <= x && x < 30);
      assert(coprime_to_30(x));
      return ((UINT32_C(0b10000000000101101000100011110000) >> (x ^ 2)) & UINT32_C(0b111)) ^ UINT32_C(0b110);
    }
    // (0, 1, 2, 3, 4, 5, 6, 7) => (1, 7, 11, 13, 17, 19, 23, 29)
    static constexpr int decode(const int y) {
      assert(0 <= y && y < 8);
      return (((UINT32_C(0xEB986530) >> (y << 2)) & UINT32_C(0xF)) << 1) | UINT32_C(1);
    }

    bool is_prime_internal(const T i) const {
      assert(i > 5);
      return coprime_to_30(i) && this->m_is_prime.test(((i / 30) << 3) | encode(i % 30));
    }
    void mark_as_composite(const T i) {
      assert(i > 5);
      assert(coprime_to_30(i));
      this->m_is_prime.reset(((i / 30) << 3) | encode(i % 30));
    }

    // [l, r) の p の倍数を合成数とマークする
    void sieve_multiples_of(const T p, const T l, const T r) {
      assert(p >= 7);
      assert(0 <= l && l <= r && r <= this->m_n + 1);

      // 以下条件を満たす最小の整数 i = kp を求める。
      // 1. l 以上
      // 2. p^2 以上
      // 3. p の倍数
      // 4. 30 と互いに素
      //
      // なお、そのような整数 i が r 以上になってしまう場合、
      // [l, r) に篩うべき整数は存在しないので即時終了する。
      auto k = tools::ceil(l, p);
      tools::chmax(k, p);
      while (!coprime_to_30(k)) ++k;
      if (tools::ceil(r, p) <= k) return;
      auto i = k * p;

      switch (k % 30) {
        while (true) {
        case 1:
          this->mark_as_composite(i);
          i += p * 6;
          if (r <= i) return;
          // fall-through
        case 7:
          this->mark_as_composite(i);
          i += p * 4;
          if (r <= i) return;
          // fall-through
        case 11:
          this->mark_as_composite(i);
          i += p * 2;
          if (r <= i) return;
          // fall-through
        case 13:
          this->mark_as_composite(i);
          i += p * 4;
          if (r <= i) return;
          // fall-through
        case 17:
          this->mark_as_composite(i);
          i += p * 2;
          if (r <= i) return;
          // fall-through
        case 19:
          this->mark_as_composite(i);
          i += p * 4;
          if (r <= i) return;
          // fall-through
        case 23:
          this->mark_as_composite(i);
          i += p * 6;
          if (r <= i) return;
          // fall-through
        case 29:
          this->mark_as_composite(i);
          i += p * 2;
          if (r <= i) return;
          // fall-through
        }
      }
    }

    void sieve_segment(const T l, const T r) {
      assert(0 <= l && l <= r && r <= this->m_n + 1);
      T i = 7;
      while (true) {
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 4;
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 2;
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 4;
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 2;
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 4;
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 6;
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 2;
        if (r <= i * i) break;
        if (this->is_prime_internal(i)) {
          this->sieve_multiples_of(i, l, r);
        }
        i += 6;
      }
    }

  public:
    class prime_view : public std::ranges::view_interface<prime_view> {
      tools::eratosthenes_sieve<T> const *m_parent;
      T m_l;
      T m_r;
      mutable std::optional<std::size_t> m_size;

    public:
      class iterator {
        tools::eratosthenes_sieve<T> const *m_parent;
        T m_p;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using reference = T;
        using pointer = const T*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::eratosthenes_sieve<T> const * const parent, const T p) : m_parent(parent), m_p(p) {
          for (; this->m_p <= parent->m_n && !parent->is_prime(this->m_p); ++this->m_p);
        }

        reference operator*() const {
          return this->m_p;
        }
        iterator& operator++() {
          if (this->m_p >= 7) [[likely]] {
            const T table_index = this->m_parent->m_is_prime.Find_next((this->m_p / 30 * 8) | tools::eratosthenes_sieve<T>::encode(this->m_p % 30));
            this->m_p = table_index / 8 * 30 + tools::eratosthenes_sieve<T>::decode(table_index & 0b111);
          } else {
            // 2 => 3 => 5 => 7
            this->m_p = tools::block_floor(this->m_p - 1, 2) + 3;
          }
          tools::chmin(this->m_p, this->m_parent->m_n + 1);
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

      prime_view() = default;
      prime_view(tools::eratosthenes_sieve<T> const * const parent, const T l, const T r) : m_parent(parent), m_l(l), m_r(r) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_l);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_r + 1);
      }
      std::size_t size() const {
        if (!this->m_size) {
          std::size_t result = 0;
          if (this->m_l <= 2 && 2 <= this->m_r) ++result;
          if (this->m_l <= 3 && 3 <= this->m_r) ++result;
          if (this->m_l <= 5 && 5 <= this->m_r) ++result;
          if (this->m_r >= 7) {
            auto l = std::max<T>(this->m_l, 7);
            while (l <= this->m_r && !tools::eratosthenes_sieve<T>::coprime_to_30(l)) ++l;
            if (l <= this->m_r) {
              auto r = this->m_r;
              while (!tools::eratosthenes_sieve<T>::coprime_to_30(r)) --r;
              result += this->m_parent->m_is_prime.count(
                l / 30 * 8 + tools::eratosthenes_sieve<T>::encode(l % 30),
                r / 30 * 8 + tools::eratosthenes_sieve<T>::encode(r % 30) + 1
              );
            }
          }
          this->m_size = result;
        }
        return *this->m_size;
      }
    };

    eratosthenes_sieve() = default;
    explicit eratosthenes_sieve(const T n) : m_is_prime(tools::ceil(n + 1, 30) * 8), m_n(n) {
      assert(n >= 1);
      this->m_is_prime.set();

      constexpr auto segment_size = T(1) << 22;
      for (T segment_begin = 0; segment_begin <= n; segment_begin += segment_size) {
        this->sieve_segment(segment_begin, std::min(segment_begin + segment_size, n + 1));
      }
    }

    bool is_prime(const T i) const {
      assert(1 <= i && i <= this->m_n);
      if (i <= 5) return (UINT32_C(0b101100) >> i) & 1;
      return this->is_prime_internal(i);
    }

    prime_view prime_range(const T l, const T r) const {
      assert(1 <= l && l <= r && r <= this->m_n);
      return prime_view(this, l, r);
    }
  };
}

#endif
