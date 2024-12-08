#ifndef TOOLS_DIVISORS_OF_DIVISOR_HPP
#define TOOLS_DIVISORS_OF_DIVISOR_HPP

#include <vector>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <numeric>
#include "tools/ceil.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/cmp_less.hpp"
#include "tools/less_by.hpp"

namespace tools {
  template <typename T>
  class divisors_of_divisor {
    ::std::vector<T> m_divisors;
    ::std::vector<int> m_sorted_divisors;
    ::std::vector<int> m_Q;

  public:
    class divisors_iterable {
      const ::tools::divisors_of_divisor<T> *m_parent;
      int m_s;

    public:
      class iterator {
        const ::tools::divisors_of_divisor<T> *m_parent;
        int m_s;
        int m_t;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = ::std::bidirectional_iterator_tag;

        iterator() = default;
        iterator(const ::tools::divisors_of_divisor<T> * const parent, const int s, const int t) : m_parent(parent), m_s(s), m_t(t) {
        }

        reference operator*() const {
          return this->m_parent->m_divisors[this->m_t];
        }
        pointer operator->() const {
          return &(*(*this));
        }

        iterator& operator++() {
          ++this->m_t;
          for (
            auto it = ::std::next(this->m_parent->m_Q.begin());
            this->m_t < this->m_parent->m_Q.back() && this->m_parent->m_divisors[this->m_s] % this->m_parent->m_divisors[this->m_t] != 0;
            ++it
          ) {
            this->m_t = ::tools::ceil(this->m_t, *it) * *it;
          }
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        iterator& operator--() {
          --this->m_t;
          for (int i = 0, max = 0; this->m_parent->m_divisors[this->m_s] % this->m_parent->m_divisors[this->m_t] != 0; ++i) {
            const auto q = this->m_s % this->m_parent->m_Q[i + 1] / this->m_parent->m_Q[i];
            max += q * this->m_parent->m_Q[i];
            this->m_t = this->m_t / this->m_parent->m_Q[i + 1] * this->m_parent->m_Q[i + 1] + ::std::min(this->m_t % this->m_parent->m_Q[i + 1], max);
          }
          return *this;
        }
        iterator operator--(int) {
          const auto self = *this;
          --*this;
          return self;
        }
        friend bool operator==(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          assert(lhs.m_s == rhs.m_s);
          return lhs.m_t == rhs.m_t;
        }
        friend bool operator!=(const iterator lhs, const iterator rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          assert(lhs.m_s == rhs.m_s);
          return lhs.m_t != rhs.m_t;
        }

        operator typename ::std::vector<T>::const_iterator() const {
          return this->m_parent->m_divisors.cbegin() + this->m_t;
        }
      };

      divisors_iterable() = default;
      divisors_iterable(const ::tools::divisors_of_divisor<T> * const parent, const int s) : m_parent(parent), m_s(s) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_s, 0);
      }
      iterator end() const {
        return iterator(this->m_parent, this->m_s, this->m_parent->m_Q.back());
      }
    };

    divisors_of_divisor() = default;
    divisors_of_divisor(const T n) {
      const auto factors = ::tools::prime_factorization(n);
      this->m_divisors.push_back(1);
      this->m_Q.push_back(1);
      for (int l = 0, r = 0; ::tools::cmp_less(l, factors.size()); l = r) {
        for (; ::tools::cmp_less(r, factors.size()) && factors[l] == factors[r]; ++r);
        const auto& p = factors[l];
        const auto q = r - l;
        const int divisors_size = this->m_divisors.size();
        T pe = 1;
        for (int e = 1; e <= q; ++e) {
          pe *= p;
          for (int i = 0; i < divisors_size; ++i) {
            this->m_divisors.push_back(this->m_divisors[i] * pe);
          }
        }
        this->m_Q.push_back(this->m_Q.back() * (q + 1));
      }

      this->m_sorted_divisors.resize(this->m_divisors.size());
      ::std::iota(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(), 0);
      ::std::sort(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(), ::tools::less_by([&](const auto i) { return this->m_divisors[i]; }));
    }

    typename ::std::vector<T>::const_iterator find(const T x) const {
      if (const auto it = ::std::partition_point(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(), [&](const auto i) { return this->m_divisors[i] < x; }); it != this->m_sorted_divisors.end()) {
        if (this->m_divisors[*it] == x) {
          return this->m_divisors.cbegin() + *it;
        } else {
          return this->m_divisors.cend();
        }
      } else {
        return this->m_divisors.cend();
      }
    }
    bool contains(const T x) const {
      return this->find(x) != this->m_divisors.cend();
    }

    const ::std::vector<T>& divisors() const {
      return this->m_divisors;
    }
    divisors_iterable divisors(const typename ::std::vector<T>::const_iterator it) const {
      assert(it != this->m_divisors.cend());
      return divisors_iterable(this, ::std::distance(this->m_divisors.cbegin(), it));
    }
    divisors_iterable divisors(const T d) const {
      return this->divisors(this->find(d));
    }
  };
}

#endif
