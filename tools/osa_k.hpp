#ifndef TOOLS_OSA_K_HPP
#define TOOLS_OSA_K_HPP

#include <vector>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <limits>
#include <utility>
#include <unordered_map>

namespace tools {

  template <typename T>
  class osa_k {
  private:
    ::std::vector<T> m_min_prime_factors;
    ::std::vector<T> m_divisor_counts;

  public:
    class prime_factor_iterable {
    private:
      const ::std::vector<T>& m_min_prime_factors;
      T m_n;

    public:
      class iterator {
      private:
        const ::std::vector<T>& m_min_prime_factors;
        T m_n;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = ::std::input_iterator_tag;

        iterator(const ::std::vector<T>& min_prime_factors, const T& n) :
          m_min_prime_factors(min_prime_factors),
          m_n(n) {
        }

        iterator(const iterator& other) = default;
        ~iterator() = default;
        iterator& operator=(const iterator& other) = default;

        T operator*() const {
          return this->m_min_prime_factors[this->m_n];
        }

        iterator& operator++() {
          this->m_n /= **this;
          return *this;
        }

        iterator operator++(int) {
          const iterator self = *this;
          ++*this;
          return self;
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          return lhs.m_n == rhs.m_n;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      prime_factor_iterable(const ::std::vector<T>& min_prime_factors, const T& n) :
        m_min_prime_factors(min_prime_factors),
        m_n(n) {
      }

      iterator begin() const {
        return iterator(this->m_min_prime_factors, this->m_n);
      };

      iterator end() const {
        return iterator(this->m_min_prime_factors, 1);
      }
    };

    class distinct_prime_factor_iterable {
    private:
      const ::std::vector<T>& m_min_prime_factors;
      T m_n;

    public:
      class iterator {
      private:
        const ::std::vector<T>& m_min_prime_factors;
        T m_n;
        bool m_evaluated;
        ::std::pair<T, T> m_value;
        T m_next_n;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = ::std::pair<T, T>;
        using reference = ::std::pair<T, T>&;
        using pointer = ::std::pair<T, T>*;
        using iterator_category = ::std::input_iterator_tag;

        iterator(const ::std::vector<T>& min_prime_factors, const T& n) :
          m_min_prime_factors(min_prime_factors),
          m_n(n),
          m_evaluated(false) {
        }

        iterator(const iterator& other) = default;
        ~iterator() = default;
        iterator& operator=(const iterator& other) = default;

        iterator& operator++() {
          **this;
          this->m_n = this->m_next_n;
          this->m_evaluated = false;
          return *this;
        }

        iterator operator++(int) {
          **this;
          const iterator self = *this;
          this->m_n = this->m_next_n;
          this->m_evaluated = false;
          return self;
        }

        ::std::pair<T, T> operator*() {
          if (!this->m_evaluated) {
            for (
              this->m_next_n = this->m_n, this->m_value = ::std::make_pair(this->m_min_prime_factors[this->m_n], 0);
              this->m_min_prime_factors[this->m_next_n] == this->m_min_prime_factors[this->m_n];
              this->m_next_n /= this->m_min_prime_factors[this->m_n], ++this->m_value.second
            );
            this->m_evaluated = true;
          }
          return this->m_value;
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          return lhs.m_n == rhs.m_n;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      distinct_prime_factor_iterable(const ::std::vector<T>& min_prime_factors, const T& n) :
        m_min_prime_factors(min_prime_factors),
        m_n(n) {
      }

      iterator begin() const {
        return iterator(this->m_min_prime_factors, this->m_n);
      };

      iterator end() const {
        return iterator(this->m_min_prime_factors, 1);
      }
    };

    class prime_iterable {
    private:
      const ::std::vector<T>& m_min_prime_factors;

    public:
      class iterator {
      private:
        const ::std::vector<T>& m_min_prime_factors;
        T m_n;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = ::std::input_iterator_tag;

        iterator(const ::std::vector<T>& min_prime_factors, const T& n) :
          m_min_prime_factors(min_prime_factors),
          m_n(n) {
        }

        iterator(const iterator& other) = default;
        ~iterator() = default;
        iterator& operator=(const iterator& other) = default;

        iterator& operator++() {
          for (++this->m_n; this->m_n < static_cast<T>(this->m_min_prime_factors.size()) && this->m_min_prime_factors[this->m_n] != this->m_n; ++this->m_n);
          return *this;
        }

        iterator operator++(int) {
          const iterator self = *this;
          ++*this;
          return self;
        }

        T operator*() const {
          return this->m_n;
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          return lhs.m_n == rhs.m_n;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      prime_iterable(const ::std::vector<T>& min_prime_factors) :
        m_min_prime_factors(min_prime_factors) {
      }

      iterator begin() const {
        return iterator(this->m_min_prime_factors, 2);
      };

      iterator end() const {
        return iterator(this->m_min_prime_factors, this->m_min_prime_factors.size());
      }
    };

    osa_k(T N) :
      m_min_prime_factors(::std::max<T>(N, 1) + 1, ::std::numeric_limits<T>::max()),
      m_divisor_counts(::std::max<T>(N, 1) + 1) {
      N = ::std::max<T>(N, 1);

      for (T i = 2; i <= N; ++i) {
        if (this->m_min_prime_factors[i] == ::std::numeric_limits<T>::max()) {
          this->m_min_prime_factors[i] = i;
          for (T j = i * i; j <= N; j += i) {
            if (this->m_min_prime_factors[j] == ::std::numeric_limits<T>::max()) {
              this->m_min_prime_factors[j] = i;
            }
          }
        }
      }

      ::std::vector<::std::pair<T, T>> dp(N + 1);
      dp[0] = ::std::make_pair(0, 0);
      dp[1] = ::std::make_pair(1, 1);
      for (T i = 2; i <= N; ++i) {
        const ::std::pair<T, T>& prev = dp[i / this->m_min_prime_factors[i]];
        if (this->m_min_prime_factors[i / this->m_min_prime_factors[i]] == this->m_min_prime_factors[i]) {
          dp[i] = ::std::make_pair(prev.first + 1, prev.second);
        } else {
          dp[i] = ::std::make_pair(static_cast<T>(2), prev.first * prev.second);
        }
      }

      for (T i = 0; i <= N; ++i) {
        this->m_divisor_counts[i] = dp[i].first * dp[i].second;
      }
    }

    const ::std::vector<T>& divisor_counts() const {
      return this->m_divisor_counts;
    }

    T divisor_count(const T& n) const {
      return this->m_divisor_counts[n];
    }

    prime_factor_iterable prime_factor_range(const T& n) const {
      return prime_factor_iterable(this->m_min_prime_factors, n);
    }

    distinct_prime_factor_iterable distinct_prime_factor_range(const T& n) const {
      return distinct_prime_factor_iterable(this->m_min_prime_factors, n);
    }

    prime_iterable prime_range() const {
      return prime_iterable(this->m_min_prime_factors);
    }

    ::std::vector<T> divisors(const T& n) const {
      ::std::vector<T> result({1});
      for (const ::std::pair<T, T>& pair : this->distinct_prime_factor_range(n)) {
        const T end = result.size();
        for (T i = 1, x = pair.first; i <= pair.second; ++i, x *= pair.first) {
          for (T j = 0; j < end; ++j) {
            result.push_back(result[j] * x);
          }
        }
      }

      ::std::sort(result.begin(), result.end());
      return result;
    }
  };
}

#endif
