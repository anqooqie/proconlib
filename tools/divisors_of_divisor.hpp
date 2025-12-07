#ifndef TOOLS_DIVISORS_OF_DIVISOR_HPP
#define TOOLS_DIVISORS_OF_DIVISOR_HPP

#include <vector>
#include <numeric>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <utility>
#include <cassert>
#include "atcoder/modint.hpp"
#include "tools/less_by.hpp"
#include "tools/ceil.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/fps.hpp"

namespace tools {
  template <typename T>
  class divisors_of_divisor {
    std::vector<T> m_divisors;
    std::vector<int> m_sorted_divisors;
    std::vector<int> m_Q;

    template <typename InputIterator>
    void init(const InputIterator begin, const InputIterator end) {
      this->m_divisors.push_back(1);
      this->m_Q.push_back(1);
      for (auto it = begin; it != end; ++it) {
        const T p = it->first;
        const int q = it->second;
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
      std::iota(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(), 0);
      std::sort(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(), tools::less_by([&](const auto i) { return this->m_divisors[i]; }));
    }

  public:
    class divisors_iterable {
      const tools::divisors_of_divisor<T> *m_parent;
      int m_s;

    public:
      class iterator {
        const tools::divisors_of_divisor<T> *m_parent;
        int m_s;
        int m_t;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::bidirectional_iterator_tag;

        iterator() = default;
        iterator(const tools::divisors_of_divisor<T> * const parent, const int s, const int t) : m_parent(parent), m_s(s), m_t(t) {
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
            auto it = std::next(this->m_parent->m_Q.begin());
            this->m_t < this->m_parent->m_Q.back() && this->m_parent->m_divisors[this->m_s] % this->m_parent->m_divisors[this->m_t] != 0;
            ++it
          ) {
            this->m_t = tools::ceil(this->m_t, *it) * *it;
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
            this->m_t = this->m_t / this->m_parent->m_Q[i + 1] * this->m_parent->m_Q[i + 1] + std::min(this->m_t % this->m_parent->m_Q[i + 1], max);
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

        operator typename std::vector<T>::const_iterator() const {
          return this->m_parent->m_divisors.cbegin() + this->m_t;
        }
      };

      divisors_iterable() = default;
      divisors_iterable(const tools::divisors_of_divisor<T> * const parent, const int s) : m_parent(parent), m_s(s) {
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
      const auto factors = tools::prime_factorization(n);
      const int k = factors.size();
      std::vector<std::pair<T, int>> v;
      for (int l = 0, r = 0; l < k; l = r) {
        for (; r < k && factors[l] == factors[r]; ++r);
        v.emplace_back(factors[l], r - l);
      }
      this->init(v.begin(), v.end());
    }
    template <typename InputIterator>
    divisors_of_divisor(const InputIterator begin, const InputIterator end) {
      this->init(begin, end);
    }

    typename std::vector<T>::const_iterator find(const T x) const {
      if (const auto it = std::partition_point(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(), [&](const auto i) { return this->m_divisors[i] < x; }); it != this->m_sorted_divisors.end()) {
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

    const std::vector<T>& divisors() const {
      return this->m_divisors;
    }
    divisors_iterable divisors(const typename std::vector<T>::const_iterator it) const {
      assert(it != this->m_divisors.cend());
      return divisors_iterable(this, std::distance(this->m_divisors.cbegin(), it));
    }
    divisors_iterable divisors(const T d) const {
      return this->divisors(this->find(d));
    }

    int estimated_complexity() const {
      using M = atcoder::modint998244353;
      using F = tools::fps<M>;

      const int k = this->m_Q.size() - 1;
      std::vector<int> q(k);
      for (int i = 0; i < k; ++i) {
        q[i] = this->m_Q[i + 1] / this->m_Q[i] - 1;
      }

      std::vector<int> s(k + 1);
      s[k] = 0;
      for (int i = k - 1; i >= 0; --i) {
        s[i] = s[i + 1] + q[i];
      }

      std::vector<F> f(k, F(s[0] + 1));
      for (int i = 0; i < k; ++i) {
        f[i][0] = M(1);
        if (q[i] + 1 <= s[0]) f[i][q[i] + 1] = M(-q[i] - 2);
        if (q[i] + 2 <= s[0]) f[i][q[i] + 2] = M(q[i] + 1);
      }

      std::vector<F> n(k + 1);
      n[k] = F(s[0] + 1);
      n[k][0] = M(1);
      for (int i = k - 1; i >= 0; --i) {
        n[i] = n[i + 1] * f[i];
      }

      std::vector<F> d(2 * k + 2);
      d[0] = F(s[0] + 1);
      d[0][0] = M(1);
      d[1] = F(s[0] + 1);
      d[1][0] = M(1);
      if (s[0] > 0) d[1][1] = M(-1);
      d[1] = d[1].inv();
      for (int i = 2; i <= 2 * k + 1; ++i) {
        d[i] = d[i - 1] * d[1];
      }

      M answer(0);
      for (int i = 0; i <= k; ++i) {
        answer += M(this->m_Q[i]) * (n[i] * d[2 * (k - i) + 1])[s[i]];
      }
      return answer.val();
    }
  };
}

#endif
