#ifndef TOOLS_ERATOSTHENES_SIEVE_HPP
#define TOOLS_ERATOSTHENES_SIEVE_HPP

#include <vector>
#include <cstddef>
#include <cassert>

namespace tools {
  template <typename T>
  class eratosthenes_sieve {
    ::std::vector<bool> m_is_prime;

    int n() const {
      return this->m_is_prime.size() - 1;
    }

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
          for (; this->m_p <= parent->n() && !parent->m_is_prime[this->m_p]; ++this->m_p);
        }

        value_type operator*() const {
          return this->m_p;
        }
        iterator& operator++() {
          for (++this->m_p; this->m_p <= this->m_parent->n() && !this->m_parent->m_is_prime[this->m_p]; ++this->m_p);
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
    explicit eratosthenes_sieve(const int n) : m_is_prime(n + 1, true) {
      assert(n >= 1);

      this->m_is_prime[0] = false;
      this->m_is_prime[1] = false;
      for (int i = 4; i <= n; i += 2) this->m_is_prime[i] = false;
      for (int i = 9; i <= n; i += 6) this->m_is_prime[i] = false;
      {
        int i = 25;
        while (true) {
          if (n < i) break;
          this->m_is_prime[i] = false;
          i += 10;
          if (n < i) break;
          this->m_is_prime[i] = false;
          i += 20;
        }
      }

      int i = 7;
      while (true) {
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 7
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 7 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 7 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 7 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 7 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 7 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 7 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 7 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 7 * 1
            j += i * 6;
            if (n < j) break;
          }
        }
        i += 4;
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 11
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 11 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 11 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 11 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 11 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 11 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 11 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 11 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 11 * 7
            j += i * 4;
            if (n < j) break;
          }
        }
        i += 2;
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 13
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 13 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 13 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 13 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 13 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 13 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 13 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 13 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 13 * 11
            j += i + i;
            if (n < j) break;
          }
        }
        i += 4;
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 17
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 17 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 17 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 17 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 17 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 17 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 17 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 17 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 17 * 13
            j += i * 4;
            if (n < j) break;
          }
        }
        i += 2;
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 19
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 19 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 19 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 19 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 19 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 19 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 19 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 19 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 19 * 17
            j += i + i;
            if (n < j) break;
          }
        }
        i += 4;
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 23
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 23 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 23 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 23 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 23 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 23 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 23 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 23 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 23 * 19
            j += i * 4;
            if (n < j) break;
          }
        }
        i += 6;
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 29
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 29 * 29
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 29 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 29 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 29 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 29 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 29 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 29 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 29 * 23
            j += i * 6;
            if (n < j) break;
          }
        }
        i += 2;
        if (n < i * i) break;
        if (this->m_is_prime[i]) { // 1
          int j = i * i;
          while (true) {
            this->m_is_prime[j] = false; // 1 * 1
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 1 * 7
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 1 * 11
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 1 * 13
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 1 * 17
            j += i + i;
            if (n < j) break;
            this->m_is_prime[j] = false; // 1 * 19
            j += i * 4;
            if (n < j) break;
            this->m_is_prime[j] = false; // 1 * 23
            j += i * 6;
            if (n < j) break;
            this->m_is_prime[j] = false; // 1 * 29
            j += i + i;
            if (n < j) break;
          }
        }
        i += 6;
      }
    }

    bool is_prime(const int i) const {
      assert(1 <= i && i <= this->n());
      return this->m_is_prime[i];
    }

    prime_iterable prime_range(const int l, const int r) const {
      assert(1 <= l && l <= r && r <= this->n());
      return prime_iterable(this, l, r);
    }
  };
}

#endif
