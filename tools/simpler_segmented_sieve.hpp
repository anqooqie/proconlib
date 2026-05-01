#ifndef TOOLS_SIMPLER_SEGMENTED_SIEVE_HPP
#define TOOLS_SIMPLER_SEGMENTED_SIEVE_HPP

#include <algorithm>
#include <atomic>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <limits>
#include <ranges>
#include "tools/block_floor.hpp"
#include "tools/ceil.hpp"
#include "tools/chmax.hpp"
#include "tools/chmin.hpp"
#include "tools/dynamic_bitset.hpp"
#include "tools/floor_sqrt.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  namespace detail::simpler_segmented_sieve {
    template <tools::non_bool_integral T>
    class impl {
      template <bool Large>
      class prime_view : public std::ranges::view_interface<prime_view<Large>> {
        static constexpr std::size_t size_uncached = std::numeric_limits<std::size_t>::max();

        impl<T> const *m_parent;
        T m_l;
        T m_r;
        mutable std::atomic<std::size_t> m_size{size_uncached};

      public:
        class iterator {
          impl<T> const *m_parent = nullptr;
          T m_p{};

        public:
          using difference_type = std::ptrdiff_t;
          using value_type = T;
          using reference = T;
          using pointer = const T*;
          using iterator_category = std::input_iterator_tag;
          using iterator_concept = std::forward_iterator_tag;

          iterator() = default;
          iterator(impl<T> const * const parent, const T p) : m_parent(parent), m_p(p) {
            for (; this->m_p <= (Large ? parent->m_r : parent->m_sqrt_r) && !parent->is_prime_internal<Large, false>(this->m_p); ++this->m_p);
          }

          reference operator*() const {
            return this->m_p;
          }
          iterator& operator++() {
            if (this->m_p >= 7) [[likely]] {
              const T table_index = this->m_parent->sieve<Large>().Find_next((this->m_parent->adjust<Large>(this->m_p) / 30 * 8) | impl<T>::encode(this->m_p % 30));
              this->m_p = (Large ? tools::block_floor(this->m_parent->m_l, 30) : 0) + table_index / 8 * 30 + impl<T>::decode(table_index & 0b111);
            } else {
              // 2 => 3 => 5 => 7
              this->m_p = tools::block_floor(this->m_p - 1, 2) + 3;
            }
            tools::chmin(this->m_p, (Large ? this->m_parent->m_r : this->m_parent->m_sqrt_r) + 1);
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
        prime_view(impl<T> const * const parent, const T l, const T r) : m_parent(parent), m_l(l), m_r(r) {
        }
        prime_view(const prime_view& other) noexcept : m_parent(other.m_parent), m_l(other.m_l), m_r(other.m_r), m_size(other.m_size.load(std::memory_order::relaxed)) {
        }
        prime_view(prime_view&& other) noexcept : m_parent(other.m_parent), m_l(other.m_l), m_r(other.m_r), m_size(other.m_size.load(std::memory_order::relaxed)) {
        }
        prime_view& operator=(const prime_view& other) noexcept {
          this->m_parent = other.m_parent;
          this->m_l = other.m_l;
          this->m_r = other.m_r;
          this->m_size.store(other.m_size.load(std::memory_order::relaxed), std::memory_order::relaxed);
          return *this;
        }
        prime_view& operator=(prime_view&& other) noexcept {
          this->m_parent = other.m_parent;
          this->m_l = other.m_l;
          this->m_r = other.m_r;
          this->m_size.store(other.m_size.load(std::memory_order::relaxed), std::memory_order::relaxed);
          return *this;
        }

        iterator begin() const {
          return iterator(this->m_parent, this->m_l);
        };
        iterator end() const {
          return iterator(this->m_parent, this->m_r + 1);
        }
        std::size_t size() const {
          if (const auto cached = this->m_size.load(std::memory_order::relaxed); cached != size_uncached) return cached;

          std::size_t result = 0;
          if (this->m_l <= 2 && 2 <= this->m_r) ++result;
          if (this->m_l <= 3 && 3 <= this->m_r) ++result;
          if (this->m_l <= 5 && 5 <= this->m_r) ++result;
          if (this->m_r >= 7) {
            auto l = std::max<T>(this->m_l, 7);
            while (l <= this->m_r && !impl<T>::coprime_to_30(l)) ++l;
            if (l <= this->m_r) {
              auto r = this->m_r;
              while (!impl<T>::coprime_to_30(r)) --r;
              result += this->m_parent->sieve<Large>().count(
                this->m_parent->adjust<Large>(l) / 30 * 8 + impl<T>::encode(l % 30),
                this->m_parent->adjust<Large>(r) / 30 * 8 + impl<T>::encode(r % 30) + 1
              );
            }
          }
          this->m_size.store(result, std::memory_order::relaxed);
          return result;
        }
      };

      tools::dynamic_bitset m_small_sieve;
      tools::dynamic_bitset m_large_sieve;
      T m_l;
      T m_r;
      T m_sqrt_r;

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

      template <bool Large>
      tools::dynamic_bitset& sieve() {
        if constexpr (Large) {
          return this->m_large_sieve;
        } else {
          return this->m_small_sieve;
        }
      }
      template <bool Large>
      const tools::dynamic_bitset& sieve() const {
        if constexpr (Large) {
          return this->m_large_sieve;
        } else {
          return this->m_small_sieve;
        }
      }
      template <bool Large>
      T adjust(const T i) const {
        if constexpr (Large) {
          return i - tools::block_floor(this->m_l, 30);
        } else {
          return i;
        }
      }

      template <bool Large, bool AssumeGE7>
      bool is_prime_internal(const T i) const {
        if constexpr (AssumeGE7) {
          assert(i >= 7);
        } else {
          assert(i >= 1);
          if (i < 7) return (UINT32_C(0b0101100) >> i) & 1;
        }
        return coprime_to_30(i) && this->sieve<Large>().test((this->adjust<Large>(i) / 30 * 8) | encode(i % 30));
      }
      template <bool Large>
      void mark_as_composite(const T i) {
        assert(i >= 7);
        assert(coprime_to_30(i));
        this->sieve<Large>().reset((this->adjust<Large>(i) / 30 * 8) | encode(i % 30));
      }

      // [l, r) 内の p の倍数を合成数としてマークする
      template <bool Large>
      void sieve_multiples_of(const T p, const T l, const T r) {
        assert(p >= 7);
        assert(coprime_to_30(p));
        if constexpr (Large) {
          assert(this->m_l <= l && l <= r && r <= this->m_r + 1);
        } else {
          assert(1 <= l && l <= r && r <= this->m_sqrt_r + 1);
        }

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
            this->mark_as_composite<Large>(i);
            i += p * 6;
            if (r <= i) return;
            // fall-through
          case 7:
            this->mark_as_composite<Large>(i);
            i += p * 4;
            if (r <= i) return;
            // fall-through
          case 11:
            this->mark_as_composite<Large>(i);
            i += p * 2;
            if (r <= i) return;
            // fall-through
          case 13:
            this->mark_as_composite<Large>(i);
            i += p * 4;
            if (r <= i) return;
            // fall-through
          case 17:
            this->mark_as_composite<Large>(i);
            i += p * 2;
            if (r <= i) return;
            // fall-through
          case 19:
            this->mark_as_composite<Large>(i);
            i += p * 4;
            if (r <= i) return;
            // fall-through
          case 23:
            this->mark_as_composite<Large>(i);
            i += p * 6;
            if (r <= i) return;
            // fall-through
          case 29:
            this->mark_as_composite<Large>(i);
            i += p * 2;
            if (r <= i) return;
            // fall-through
          }
        }
      }

      template <bool Large>
      void sieve_segment(const T l, const T r) {
        if constexpr (Large) {
          assert(this->m_l <= l && l <= r && r <= this->m_r + 1);
        } else {
          assert(1 <= l && l <= r && r <= this->m_sqrt_r + 1);
        }

        T i = 7;
        while (true) {
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 4;
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 2;
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 4;
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 2;
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 4;
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 6;
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 2;
          if (r <= i * i) break;
          if (this->is_prime_internal<false, true>(i)) {
            this->sieve_multiples_of<Large>(i, l, r);
          }
          i += 6;
        }
      }

    public:
      using small_prime_view = prime_view<false>;
      using large_prime_view = prime_view<true>;

      impl() = default;
      impl(const T l, const T r) :
          m_small_sieve(tools::ceil(tools::floor_sqrt(r) + 1, 30) * 8),
          m_large_sieve(tools::ceil(r - tools::block_floor(l, 30) + 1, 30) * 8),
          m_l(l),
          m_r(r),
          m_sqrt_r(tools::floor_sqrt(r)) {
        assert(1 <= l && l <= r);
        this->m_small_sieve.set();
        this->m_large_sieve.set();

        constexpr auto segment_size = T(1) << 22;
        for (T segment_begin = 1; segment_begin <= this->m_sqrt_r; segment_begin += segment_size) {
          this->sieve_segment<false>(segment_begin, std::min(segment_begin + segment_size, this->m_sqrt_r + 1));
        }
        for (T segment_begin = l; segment_begin <= r; segment_begin += segment_size) {
          this->sieve_segment<true>(segment_begin, std::min(segment_begin + segment_size, r + 1));
        }
      }

      T sqrt_r() const {
        return this->m_sqrt_r;
      }
      T l() const {
        return this->m_l;
      }
      T r() const {
        return this->m_r;
      }

      bool is_prime(const T i) const {
        assert((1 <= i && i <= this->m_sqrt_r) || (this->m_l <= i && i <= this->m_r));
        if (i <= this->m_sqrt_r) {
          return this->is_prime_internal<false, false>(i);
        } else {
          return this->is_prime_internal<true, false>(i);
        }
      }

      small_prime_view small_prime_range(const T l, const T r) const {
        assert(1 <= l && l <= r && r <= this->m_sqrt_r);
        return small_prime_view(this, l, r);
      }
      large_prime_view large_prime_range(const T l, const T r) const {
        assert(this->m_l <= l && l <= r && r <= this->m_r);
        return large_prime_view(this, l, r);
      }
    };
  }

  using simpler_segmented_sieve = tools::detail::simpler_segmented_sieve::impl<long long>;
}

#endif
