#ifndef TOOLS_SEGMENTED_SIEVE_HPP
#define TOOLS_SEGMENTED_SIEVE_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/block_ceil.hpp"
#include "tools/floor_sqrt.hpp"

namespace tools {
  class segmented_sieve {
    std::vector<int> m_small_primes;
    std::vector<std::tuple<int, int, int>> m_small_factors;
    std::vector<long long> m_large_primes;
    std::vector<std::tuple<long long, int, long long, int>> m_large_factors;
    long long m_l;
    long long m_r;

  public:
    class prime_factor_view : public std::ranges::view_interface<prime_factor_view> {
      tools::segmented_sieve const *m_parent;
      long long m_n;

    public:
      class iterator {
        tools::segmented_sieve const *m_parent = nullptr;
        int m_i{};
        int m_j{};

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = long long;
        using reference = long long;
        using pointer = const long long*;
        using iterator_category = std::input_iterator_tag;
        using iterator_concept = std::forward_iterator_tag;

        iterator() = default;
        iterator(tools::segmented_sieve const * const parent, const int i, const int j) : m_parent(parent), m_i(i), m_j(j) {
        }

        reference operator*() const {
          if (this->m_i >= 0) {
            return std::get<0>(this->m_parent->m_small_factors[this->m_i]);
          } else {
            return std::get<0>(this->m_parent->m_large_factors[~this->m_i]);
          }
        }
        iterator& operator++() {
          if (this->m_i >= 0) {
            ++this->m_j;
            if (this->m_j >= std::get<1>(this->m_parent->m_small_factors[this->m_i])) {
              this->m_i /= std::get<2>(this->m_parent->m_small_factors[this->m_i]);
              this->m_j = 0;
            }
          } else {
            ++this->m_j;
            if (this->m_j >= std::get<1>(this->m_parent->m_large_factors[~this->m_i])) {
              this->m_i = ~std::get<3>(this->m_parent->m_large_factors[~this->m_i]);
              this->m_j = 0;
            }
          }
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          return lhs.m_i == rhs.m_i && lhs.m_j == rhs.m_j;
        }
        friend bool operator!=(const iterator lhs, const iterator rhs) {
          return !(lhs == rhs);
        }
      };

      prime_factor_view() = default;
      prime_factor_view(tools::segmented_sieve const * const parent, const long long n) : m_parent(parent), m_n(n) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_n <= this->m_parent->sqrt_r() ? this->m_n : ~(this->m_n - this->m_parent->m_l), 0);
      };
      iterator end() const {
        return iterator(this->m_parent, 1, 0);
      }
    };

    class distinct_prime_factor_view : public std::ranges::view_interface<distinct_prime_factor_view> {
      tools::segmented_sieve const *m_parent;
      long long m_n;

    public:
      class iterator {
        tools::segmented_sieve const *m_parent = nullptr;
        int m_i{};

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = std::tuple<long long, long long, long long>;
        using reference = std::tuple<long long, long long, long long>;
        using pointer = const std::tuple<long long, long long, long long>*;
        using iterator_category = std::input_iterator_tag;
        using iterator_concept = std::forward_iterator_tag;

        iterator() = default;
        iterator(tools::segmented_sieve const * const parent, const int i) : m_parent(parent), m_i(i) {
        }

        reference operator*() const {
          if (this->m_i >= 0) {
            return this->m_parent->m_small_factors[this->m_i];
          } else {
            [[maybe_unused]] const auto& [p, q, pq, next_i] = this->m_parent->m_large_factors[~this->m_i];
            return value_type(p, q, pq);
          }
        }
        iterator& operator++() {
          if (this->m_i >= 0) {
            this->m_i /= std::get<2>(this->m_parent->m_small_factors[this->m_i]);
          } else {
            this->m_i = ~std::get<3>(this->m_parent->m_large_factors[~this->m_i]);
          }
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          return lhs.m_i == rhs.m_i;
        }
        friend bool operator!=(const iterator lhs, const iterator rhs) {
          return !(lhs == rhs);
        }
      };

      distinct_prime_factor_view() = default;
      distinct_prime_factor_view(tools::segmented_sieve const * const parent, const long long n) : m_parent(parent), m_n(n) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_n <= this->m_parent->sqrt_r() ? this->m_n : ~(this->m_n - this->m_parent->m_l));
      };
      iterator end() const {
        return iterator(this->m_parent, 1);
      }
    };

    class prime_view : public std::ranges::view_interface<prime_view> {
      tools::segmented_sieve const *m_parent;
      int m_begin;
      int m_end;

    public:
      class iterator {
        tools::segmented_sieve const *m_parent = nullptr;
        int m_i{};

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = long long;
        using reference = long long;
        using pointer = const long long*;
        using iterator_category = std::input_iterator_tag;
        using iterator_concept = std::forward_iterator_tag;

        iterator() = default;
        iterator(tools::segmented_sieve const * const parent, const int i) : m_parent(parent), m_i(i) {
        }

        reference operator*() const {
          if (this->m_i >= 0) {
            return this->m_parent->m_small_primes[this->m_i];
          } else {
            return this->m_parent->m_large_primes[~this->m_i];
          }
        }
        iterator& operator++() {
          if (this->m_i >= 0) {
            ++this->m_i;
            if (this->m_i >= std::ssize(this->m_parent->m_small_primes)) {
              this->m_i = ~std::distance(this->m_parent->m_large_primes.begin(), std::ranges::upper_bound(this->m_parent->m_large_primes, this->m_parent->sqrt_r()));
            }
          } else {
            --this->m_i;
          }
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          return lhs.m_i == rhs.m_i;
        }
        friend bool operator!=(const iterator lhs, const iterator rhs) {
          return !(lhs == rhs);
        }
      };

      prime_view() = default;
      prime_view(tools::segmented_sieve const * const parent, const long long l, const long long r) :
        m_parent(parent),
        m_begin(
          !parent->m_small_primes.empty() && l <= parent->m_small_primes.back()
            ? std::distance(parent->m_small_primes.begin(), std::ranges::lower_bound(parent->m_small_primes, l))
            : ~std::distance(parent->m_large_primes.begin(), std::ranges::lower_bound(parent->m_large_primes, l))
        ),
        m_end(
          !parent->m_small_primes.empty() && r < parent->m_small_primes.back()
            ? std::distance(parent->m_small_primes.begin(), std::ranges::upper_bound(parent->m_small_primes, r))
            : ~std::distance(parent->m_large_primes.begin(), std::ranges::upper_bound(parent->m_large_primes, r))
        ) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_begin);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_end);
      }
    };

    segmented_sieve() = default;
    segmented_sieve(const long long l, const long long r) : m_small_factors(tools::floor_sqrt(r) + 1), m_large_factors(r - l + 1), m_l(l), m_r(r) {
      assert(1 <= l && l <= r);

      for (int n = 2; n <= this->sqrt_r(); ++n) {
        if (!std::get<0>(this->m_small_factors[n])) {
          this->m_small_primes.push_back(n);
          this->m_small_factors[n] = {n, 1, n};
        }
        for (auto it = this->m_small_primes.begin(); it != this->m_small_primes.end() && *it <= std::get<0>(this->m_small_factors[n]) && n * *it <= this->sqrt_r(); ++it) {
          std::get<0>(this->m_small_factors[n * *it]) = *it;
          if (*it < std::get<0>(this->m_small_factors[n])) {
            std::get<1>(this->m_small_factors[n * *it]) = 1;
            std::get<2>(this->m_small_factors[n * *it]) = *it;
          } else {
            std::get<1>(this->m_small_factors[n * *it]) = std::get<1>(this->m_small_factors[n]) + 1;
            std::get<2>(this->m_small_factors[n * *it]) = std::get<2>(this->m_small_factors[n]) * *it;
          }
        }
      }

      std::vector<long long> rem(r - l + 1);
      for (long long n = l; n <= r; ++n) {
        rem[n - l] = n;
      }
      std::vector<int> last(r - l + 1, -1);

      for (const auto p : this->m_small_primes) {
        for (long long n = tools::block_ceil(l, p); n <= r; n += p) {
          int curr;
          if (last[n - l] >= 0) {
            curr = this->m_large_factors.size();
            this->m_large_factors.emplace_back(p, 0, 1, ~1);
            std::get<3>(this->m_large_factors[last[n - l]]) = curr;
          } else {
            curr = n - l;
            this->m_large_factors[curr] = {p, 0, 1, ~1};
          }
          do {
            rem[n - l] /= p;
            ++std::get<1>(this->m_large_factors[curr]);
            std::get<2>(this->m_large_factors[curr]) *= p;
          } while (rem[n - l] % p == 0);
          last[n - l] = curr;
        }
      }
      for (long long n = l; n <= r; ++n) {
        if (last[n - l] >= 0) {
          if (rem[n - l] > 1) {
            std::get<3>(this->m_large_factors[last[n - l]]) = this->m_large_factors.size();
            this->m_large_factors.emplace_back(rem[n - l], 1, rem[n - l], ~1);
          }
        } else {
          if (n > 1) {
            this->m_large_primes.push_back(n);
            this->m_large_factors[n - l] = {n, 1, n, ~1};
          }
        }
      }
    }

    long long sqrt_r() const {
      return this->m_small_factors.size() - 1;
    }

    long long l() const {
      return this->m_l;
    }

    long long r() const {
      return this->m_r;
    }

    bool is_prime(const long long n) const {
      assert((1 <= n && n <= this->sqrt_r()) || (this->m_l <= n && n <= this->m_r));
      if (n <= this->sqrt_r()) {
        return n >= 2 && std::get<0>(this->m_small_factors[n]) == n;
      } else {
        return std::get<0>(this->m_large_factors[n - this->m_l]) == n;
      }
    }

    prime_factor_view prime_factor_range(const long long n) const {
      assert((1 <= n && n <= this->sqrt_r()) || (this->m_l <= n && n <= this->m_r));
      return prime_factor_view(this, n);
    }

    distinct_prime_factor_view distinct_prime_factor_range(const long long n) const {
      assert((1 <= n && n <= this->sqrt_r()) || (this->m_l <= n && n <= this->m_r));
      return distinct_prime_factor_view(this, n);
    }

    prime_view prime_range(const long long l, const long long r) const {
      #ifndef NDEBUG
      if (this->sqrt_r() + 1 < this->l()) {
        assert((1 <= l && l <= r && r <= this->sqrt_r()) || (this->m_l <= l && l <= r && r <= this->m_r));
      } else {
        assert(1 <= l && l <= r && r <= this->m_r);
      }
      #endif
      return prime_view(this, l, r);
    }

    std::vector<long long> divisors(const long long n) const {
      assert((1 <= n && n <= this->sqrt_r()) || (this->m_l <= n && n <= this->m_r));

      std::vector<long long> D{1};
      for ([[maybe_unused]] const auto& [p, q, pq] : this->distinct_prime_factor_range(n)) {
        const int end = D.size();
        for (long long e = 1, pe = 1; e <= q; ++e) {
          pe *= p;
          for (int i = 0; i < end; ++i) {
            D.push_back(D[i] * pe);
          }
        }
      }

      return D;
    }

    std::vector<long long> sorted_divisors(const long long n) const {
      auto D = this->divisors(n);
      std::ranges::sort(D);
      return D;
    }

    std::pair<std::vector<long long>, std::vector<long long>> divisor_counts() const {
      std::vector<std::pair<int, int>> dp(this->sqrt_r() + 1);
      dp[0] = std::make_pair(0, 0);
      dp[1] = std::make_pair(1, 1);
      for (int i = 2; i <= this->sqrt_r(); ++i) {
        const auto& prev = dp[i / std::get<0>(this->m_small_factors[i])];
        if (std::get<0>(this->m_small_factors[i / std::get<0>(this->m_small_factors[i])]) == std::get<0>(this->m_small_factors[i])) {
          dp[i] = std::make_pair(prev.first + 1, prev.second);
        } else {
          dp[i] = std::make_pair(2, prev.first * prev.second);
        }
      }

      std::vector<long long> small(this->sqrt_r() + 1);
      for (int i = 0; i <= this->sqrt_r(); ++i) {
        small[i] = dp[i].first * dp[i].second;
      }

      std::vector<long long> large(this->m_r - this->m_l + 1);
      for (long long n = this->m_l; n <= this->m_r; ++n) {
        large[n - this->m_l] = 1;
        for ([[maybe_unused]] const auto& [p, q, pq] : this->distinct_prime_factor_range(n)) {
          large[n - this->m_l] *= q + 1;
        }
      }

      return {small, large};
    }
  };
}

#endif
