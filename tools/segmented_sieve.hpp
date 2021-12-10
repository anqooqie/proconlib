#ifndef TOOLS_SEGMENTED_SIEVE_HPP
#define TOOLS_SEGMENTED_SIEVE_HPP

#include <vector>
#include <cassert>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cstddef>
#include <iterator>
#include <utility>
#include "tools/floor_sqrt.hpp"
#include "tools/chmin.hpp"
#include "tools/ceil.hpp"

namespace tools {
  template <typename T>
  class segmented_sieve {
  private:
    ::std::vector<T> m_lpf;
    ::std::vector<::std::vector<T>> m_pf;
    ::std::vector<T> m_aux;
    T m_l;

  public:
    segmented_sieve() = default;
    segmented_sieve(const ::tools::segmented_sieve<T>&) = default;
    segmented_sieve(::tools::segmented_sieve<T>&&) = default;
    ~segmented_sieve() = default;
    ::tools::segmented_sieve<T>& operator=(const ::tools::segmented_sieve<T>&) = default;
    ::tools::segmented_sieve<T>& operator=(::tools::segmented_sieve<T>&&) = default;

    segmented_sieve(const T& k, const T& l, const T& r) {
      assert(l <= r);

      const T lpf_max = ::std::max(::tools::floor_sqrt(r), k);
      this->m_lpf.resize(lpf_max + 1);
      ::std::fill(this->m_lpf.begin(), this->m_lpf.end(), ::std::numeric_limits<T>::max());
      this->m_pf.resize(r - l + 1);
      this->m_aux.resize(r - l + 1);
      ::std::iota(this->m_aux.begin(), this->m_aux.end(), l);
      this->m_l = l;

      for (T p = 2; p <= lpf_max; ++p) {
        if (::tools::chmin(this->m_lpf[p], p)) {
          for (T np = p * p; np <= lpf_max; np += p) {
            ::tools::chmin(this->m_lpf[np], p);
          }
          for (T p_q = p, np_q; (np_q = ::tools::ceil(l, p_q) * p_q) <= r; p_q *= p) {
            for (; np_q <= r; np_q += p_q) {
              if (lpf_max < this->m_aux[np_q - l]) {
                this->m_pf[np_q - l].push_back(p);
                this->m_aux[np_q - l] /= p;
              }
            }
          }
        }
      }

      for (T i = l; i <= r; ++i) {
        if (lpf_max < this->m_aux[i - l]) {
          this->m_pf[i - l].push_back(this->m_aux[i - l]);
          this->m_aux[i - l] = 1;
        }
      }
    }

    segmented_sieve(const T& l, const T& r) :
      segmented_sieve(0, l, r) {
    }

    T lpf_max() const {
      return this->m_lpf.size() - 1;
    }
    T l() const {
      return this->m_l;
    }
    T r() const {
      return this->m_l + this->m_pf.size() - 1;
    }

    class prime_factor_iterable {
    private:
      const ::tools::segmented_sieve<T> *m_parent;
      T m_n;

    public:
      class iterator {
      private:
        const prime_factor_iterable *m_parent;
        bool m_large;
        T m_i;

        T n() const {
          return this->m_parent->m_n;
        }

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(const iterator&) = default;
        iterator(iterator&&) = default;
        ~iterator() = default;
        iterator& operator=(const iterator&) = default;
        iterator& operator=(iterator&&) = default;

        iterator(prime_factor_iterable const * const parent, const bool large, const T& i) :
          m_parent(parent), m_large(large), m_i(i) {
        }

        T operator*() const {
          if (this->m_large) {
            return this->m_parent->m_parent->m_pf[this->n() - this->m_parent->m_parent->l()][this->m_i];
          } else {
            return this->m_parent->m_parent->m_lpf[this->m_i];
          }
        }

        iterator& operator++() {
          if (this->m_large) {
            ++this->m_i;
            if (this->m_i == T(this->m_parent->m_parent->m_pf[this->n() - this->m_parent->m_parent->l()].size())) {
              this->m_large = false;
              this->m_i = this->m_parent->m_parent->m_aux[this->n() - this->m_parent->m_parent->l()];
            }
          } else {
            this->m_i /= this->m_parent->m_parent->m_lpf[this->m_i];
          }
          return *this;
        }

        iterator operator++(int) {
          const iterator self = *this;
          ++*this;
          return self;
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          return lhs.m_large == rhs.m_large && (!lhs.m_large || lhs.n() == rhs.n()) && lhs.m_i == rhs.m_i;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      prime_factor_iterable(::tools::segmented_sieve<T> const * const parent, const T& n) :
        m_parent(parent), m_n(n) {
      }

      iterator begin() const {
        if (this->m_n <= this->m_parent->lpf_max()) {
          return iterator(this, false, this->m_n);
        } else {
          return iterator(this, true, 0);
        }
      }

      iterator end() const {
        return iterator(this, false, 1);
      }
    };

    class distinct_prime_factor_iterable {
    private:
      const ::tools::segmented_sieve<T> *m_parent;
      T m_n;

    public:
      class iterator {
      private:
        const distinct_prime_factor_iterable *m_parent;
        bool m_large;
        T m_i;
        ::std::pair<T, T> m_value;

        T n() const {
          return this->m_parent->m_n;
        }

        void next() {
          const ::std::vector<T>& lpf = this->m_parent->m_parent->m_lpf;
          if (this->m_large) {
            const ::std::vector<T>& pf = this->m_parent->m_parent->m_pf[this->m_parent->m_n - this->m_parent->m_parent->l()];
            this->m_value.first = pf[this->m_i];
            this->m_value.second = 0;
            for (; this->m_i < T(pf.size()) && pf[this->m_i] == this->m_value.first; ++this->m_i) {
              ++this->m_value.second;
            }
            if (this->m_i == T(pf.size())) {
              this->m_large = false;
              this->m_i = this->m_parent->m_parent->m_aux[this->m_parent->m_n - this->m_parent->m_parent->l()];
              for (; lpf[this->m_i] == this->m_value.first; this->m_i /= lpf[this->m_i]) {
                ++this->m_value.second;
              }
            }
          } else {
            if (this->m_i == 1) {
              this->m_value.first = ::std::numeric_limits<T>::max();
              this->m_value.second = 0;
            } else {
              this->m_value.first = lpf[this->m_i];
              this->m_value.second = 0;
              for (; lpf[this->m_i] == this->m_value.first; this->m_i /= lpf[this->m_i]) {
                ++this->m_value.second;
              }
            }
          }
        }

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = ::std::pair<T, T>;
        using reference = ::std::pair<T, T>&;
        using pointer = ::std::pair<T, T>*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(const iterator&) = default;
        iterator(iterator&&) = default;
        ~iterator() = default;
        iterator& operator=(const iterator&) = default;
        iterator& operator=(iterator&&) = default;

        iterator(distinct_prime_factor_iterable const * const parent, const bool large, const T& i) :
          m_parent(parent), m_large(large), m_i(i) {
          this->next();
        }

        ::std::pair<T, T> operator*() const {
          return this->m_value;
        }

        iterator& operator++() {
          this->next();
          return *this;
        }

        iterator operator++(int) {
          const iterator self = *this;
          ++*this;
          return self;
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          return lhs.n() == rhs.n() && lhs.m_value.first == rhs.m_value.first;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      distinct_prime_factor_iterable(::tools::segmented_sieve<T> const * const parent, const T& n) :
        m_parent(parent), m_n(n) {
      }

      iterator begin() const {
        if (this->m_n <= this->m_parent->lpf_max()) {
          return iterator(this, false, this->m_n);
        } else {
          return iterator(this, true, 0);
        }
      }

      iterator end() const {
        return iterator(this, false, 1);
      }
    };

    class prime_iterable {
    private:
      const ::tools::segmented_sieve<T> *m_parent;
      bool m_large;
      T m_lb;
      T m_ub;

    public:
      class iterator {
      private:
        const prime_iterable *m_parent;
        T m_i;

        void next() {
          ++this->m_i;
          if (this->m_parent->m_large) {
            for (; this->m_i <= this->m_parent->m_ub && this->m_parent->m_parent->m_pf[this->m_i - this->m_parent->m_parent->l()][0] != this->m_i; ++this->m_i);
          } else {
            for (; this->m_i <= this->m_parent->m_ub && this->m_parent->m_parent->m_lpf[this->m_i] != this->m_i; ++this->m_i);
          }
        }

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(const iterator&) = default;
        iterator(iterator&&) = default;
        ~iterator() = default;
        iterator& operator=(const iterator&) = default;
        iterator& operator=(iterator&&) = default;

        iterator(prime_iterable const * const parent, const T& i) :
          m_parent(parent), m_i(i) {
          this->next();
        }

        T operator*() const {
          return this->m_i;
        }

        iterator& operator++() {
          this->next();
          return *this;
        }

        iterator operator++(int) {
          const iterator self = *this;
          ++*this;
          return self;
        }

        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          return lhs.m_i == rhs.m_i;
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      prime_iterable(::tools::segmented_sieve<T> const * const parent, const bool large, const T& lb, const T& ub) :
        m_parent(parent), m_large(large), m_lb(lb), m_ub(ub) {
      }

      iterator begin() const {
        return iterator(this, this->m_lb - 1);
      }

      iterator end() const {
        return iterator(this, this->m_ub);
      }
    };

    prime_factor_iterable prime_factor_range(const T& n) const {
      assert((1 <= n && n <= this->lpf_max()) || (this->l() <= n && n <= this->r()));
      return prime_factor_iterable(this, n);
    }

    distinct_prime_factor_iterable distinct_prime_factor_range(const T& n) const {
      assert((1 <= n && n <= this->lpf_max()) || (this->l() <= n && n <= this->r()));
      return distinct_prime_factor_iterable(this, n);
    }

    prime_iterable prime_range(const T& lb, const T& ub) const {
      assert(lb <= ub);
      const bool is_in_small_sieve = 1 <= lb && ub <= this->lpf_max();
      const bool is_in_large_sieve = this->l() <= lb && ub <= this->r();
      assert(is_in_small_sieve || is_in_large_sieve);
      return prime_iterable(this, !is_in_small_sieve, lb, ub);
    }
  };
}

#endif
