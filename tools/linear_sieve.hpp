#ifndef TOOLS_LINEAR_SIEVE_HPP
#define TOOLS_LINEAR_SIEVE_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <tuple>
#include <vector>

namespace tools {
  template <typename T>
  class linear_sieve {
    std::vector<int> m_primes;
    std::vector<int> m_lpf;
    std::vector<int> m_ord;
    std::vector<int> m_pow;

    int N() const {
      return this->m_lpf.size() - 1;
    }

  public:
    class prime_factor_view : public std::ranges::view_interface<prime_factor_view> {
    private:
      tools::linear_sieve<T> const *m_parent;
      int m_n;

    public:
      class iterator {
      private:
        tools::linear_sieve<T> const *m_parent;
        int m_n;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using reference = T;
        using pointer = const T*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::linear_sieve<T> const * const parent, const int n) : m_parent(parent), m_n(n) {
        }

        reference operator*() const {
          return this->m_parent->m_lpf[this->m_n];
        }
        iterator& operator++() {
          this->m_n /= **this;
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          return lhs.m_n == rhs.m_n;
        }
        friend bool operator!=(const iterator lhs, const iterator rhs) {
          return !(lhs == rhs);
        }
      };

      prime_factor_view() = default;
      prime_factor_view(tools::linear_sieve<T> const * const parent, const int n) : m_parent(parent), m_n(n) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_n);
      };
      iterator end() const {
        return iterator(this->m_parent, 1);
      }
    };

    class distinct_prime_factor_view : public std::ranges::view_interface<distinct_prime_factor_view> {
    private:
      tools::linear_sieve<T> const *m_parent;
      int m_n;

    public:
      class iterator {
      private:
        tools::linear_sieve<T> const *m_parent;
        int m_n;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = std::tuple<T, T, T>;
        using reference = std::tuple<T, T, T>;
        using pointer = const std::tuple<T, T, T>*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::linear_sieve<T> const * const parent, const int n) : m_parent(parent), m_n(n) {
        }

        reference operator*() const {
          return value_type(this->m_parent->m_lpf[this->m_n], this->m_parent->m_ord[this->m_n], this->m_parent->m_pow[this->m_n]);
        }
        iterator& operator++() {
          this->m_n /= this->m_parent->m_pow[this->m_n];
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          return lhs.m_n == rhs.m_n;
        }
        friend bool operator!=(const iterator lhs, const iterator rhs) {
          return !(lhs == rhs);
        }
      };

      distinct_prime_factor_view() = default;
      distinct_prime_factor_view(tools::linear_sieve<T> const * const parent, const int n) : m_parent(parent), m_n(n) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_n);
      };
      iterator end() const {
        return iterator(this->m_parent, 1);
      }
    };

    class prime_view : public std::ranges::view_interface<prime_view> {
    private:
      tools::linear_sieve<T> const *m_parent;
      int m_l;
      int m_r;

    public:
      class iterator {
      private:
        tools::linear_sieve<T> const *m_parent;
        int m_i;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using reference = T;
        using pointer = const T*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::linear_sieve<T> const * const parent, const int n) : m_parent(parent), m_i(std::distance(parent->m_primes.begin(), std::lower_bound(parent->m_primes.begin(), parent->m_primes.end(), n))) {
        }

        reference operator*() const {
          return this->m_parent->m_primes[this->m_i];
        }
        iterator& operator++() {
          ++this->m_i;
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
      prime_view(tools::linear_sieve<T> const * const parent, const int l, const int r) : m_parent(parent), m_l(l), m_r(r) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_l);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_r + 1);
      }
    };

    linear_sieve() = default;
    explicit linear_sieve(const int N) : m_lpf(N + 1), m_ord(N + 1), m_pow(N + 1) {
      assert(N >= 1);

      for (int n = 2; n <= N; ++n) {
        if (!this->m_lpf[n]) {
          this->m_primes.push_back(n);
          this->m_lpf[n] = n;
          this->m_ord[n] = 1;
          this->m_pow[n] = n;
        }
        for (auto it = this->m_primes.begin(); it != this->m_primes.end() && *it <= this->m_lpf[n] && n * *it <= N; ++it) {
          this->m_lpf[n * *it] = *it;
          if (*it < this->m_lpf[n]) {
            this->m_ord[n * *it] = 1;
            this->m_pow[n * *it] = *it;
          } else {
            this->m_ord[n * *it] = this->m_ord[n] + 1;
            this->m_pow[n * *it] = this->m_pow[n] * *it;
          }
        }
      }
    }

    bool is_prime(const int n) const {
      assert(1 <= n && n <= this->N());
      return n >= 2 && this->m_lpf[n] == n;
    }

    prime_factor_view prime_factor_range(const int n) const {
      assert(1 <= n && n <= this->N());
      return prime_factor_view(this, n);
    }

    distinct_prime_factor_view distinct_prime_factor_range(const int n) const {
      assert(1 <= n && n <= this->N());
      return distinct_prime_factor_view(this, n);
    }

    prime_view prime_range(const int l, const int r) const {
      assert(1 <= l && l <= r && r <= this->N());
      return prime_view(this, l, r);
    }

    std::vector<T> divisors(const int n) const {
      assert(1 <= n && n <= this->N());

      std::vector<T> D{1};
      for (const auto& [p, q, unused] : this->distinct_prime_factor_range(n)) {
        const int end = D.size();
        for (int e = 1, pe = p; e <= q; ++e, pe *= p) {
          for (int i = 0; i < end; ++i) {
            D.push_back(D[i] * pe);
          }
        }
      }

      return D;
    }

    std::vector<T> sorted_divisors(const int n) const {
      auto D = this->divisors(n);
      std::ranges::sort(D);
      return D;
    }
  };
}

#endif
