#ifndef TOOLS_PERMUTATION_HPP
#define TOOLS_PERMUTATION_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

namespace tools {
  template <typename T>
  class permutation {
    ::std::vector<int> m_perm;
    ::std::vector<int> m_inv;

    void verify_consistency() const {
#ifndef NDEBUG
      ::std::vector<bool> unique(this->size(), true);
      for (const auto x : this->m_perm) {
        assert(0 <= x && x < this->size());
        assert(unique[x]);
        unique[x] = false;
      }
#endif
    }

    void make_inv() {
      this->m_inv.resize(this->size());
      for (int i = 0; i < this->size(); ++i) {
        this->m_inv[this->m_perm[i]] = i;
      }
    }

  public:
    class iterator {
      ::std::vector<int>::const_iterator m_it;

    public:
      using reference = T;
      using value_type = T;
      using difference_type = ::std::ptrdiff_t;
      using pointer = const value_type*;
      using iterator_category = ::std::random_access_iterator_tag;

      iterator() = default;
      iterator(const ::std::vector<int>::const_iterator it) : m_it(it) {
      }

      reference operator*() const {
        return *this->m_it;
      }

      iterator& operator++() {
        ++this->m_it;
        return *this;
      }
      iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      iterator& operator--() {
        --this->m_it;
        return *this;
      }
      iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }
      iterator& operator+=(const difference_type n) {
        this->m_it += n;
        return *this;
      }
      iterator& operator-=(const difference_type n) {
        this->m_it -= n;
        return *this;
      }
      friend iterator operator+(const iterator self, const difference_type n) {
        return iterator(self.m_it + n);
      }
      friend iterator operator+(const difference_type n, const iterator self) {
        return self + n;
      }
      friend iterator operator-(const iterator self, const difference_type n) {
        return iterator(self.m_it - n);
      }
      friend difference_type operator-(const iterator lhs, const iterator rhs) {
        return lhs.m_it - rhs.m_it;
      }
      reference operator[](const difference_type n) const {
        return *(*this + n);
      }

      friend bool operator==(const iterator lhs, const iterator rhs) {
        return lhs.m_it == rhs.m_it;
      }
      friend bool operator!=(const iterator lhs, const iterator rhs) {
        return lhs.m_it != rhs.m_it;
      }
      friend bool operator<(const iterator lhs, const iterator rhs) {
        return lhs.m_it < rhs.m_it;
      }
      friend bool operator<=(const iterator lhs, const iterator rhs) {
        return lhs.m_it <= rhs.m_it;
      }
      friend bool operator>(const iterator lhs, const iterator rhs) {
        return lhs.m_it > rhs.m_it;
      }
      friend bool operator>=(const iterator lhs, const iterator rhs) {
        return lhs.m_it >= rhs.m_it;
      }
    };

    permutation() = default;
    explicit permutation(const int n) : m_perm(n), m_inv(n) {
      ::std::iota(this->m_perm.begin(), this->m_perm.end(), 0);
      ::std::iota(this->m_inv.begin(), this->m_inv.end(), 0);
    }
    template <::std::ranges::range R>
    permutation(R&& r) : m_perm(::std::ranges::begin(r), ::std::ranges::end(r)) {
      this->verify_consistency();
      this->make_inv();
    }

    int size() const {
      return this->m_perm.size();
    }
    T operator[](const int i) const {
      assert(0 <= i && i < this->size());
      return this->m_perm[i];
    }
    iterator begin() const {
      return this->m_perm.begin();
    }
    iterator end() const {
      return this->m_perm.end();
    }

    ::tools::permutation<T>& swap_from_left(const int x, const int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());
      this->m_inv[this->m_perm[y]] = x;
      this->m_inv[this->m_perm[x]] = y;
      ::std::swap(this->m_perm[x], this->m_perm[y]);
      return *this;
    }
    ::tools::permutation<T>& swap_from_right(const int x, const int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());
      this->m_perm[this->m_inv[y]] = x;
      this->m_perm[this->m_inv[x]] = y;
      ::std::swap(this->m_inv[x], this->m_inv[y]);
      return *this;
    }

    long long id() const {
      if (this->size() == 0) return 0;

      ::std::vector<int> left(this->size());
      ::std::iota(left.begin(), left.end(), 0);

      ::std::vector<long long> fact(this->size());
      fact[0] = 1;
      for (int i = 1; i < this->size(); ++i) {
        fact[i] = fact[i - 1] * i;
      }

      long long id = 0;
      for (int i = 0; i < this->size(); ++i) {
        auto it = ::std::lower_bound(left.begin(), left.end(), this->m_perm[i]);
        id += ::std::distance(left.begin(), it) * fact[this->size() - 1 - i];
        left.erase(it);
      }

      return id;
    }

    static ::tools::permutation<T> from(const int n, long long id) {
      if (n == 0) return ::tools::permutation<T>(0);

      ::std::vector<int> left(n);
      ::std::iota(left.begin(), left.end(), 0);

      ::std::vector<long long> fact(n);
      fact[0] = 1;
      for (int i = 1; i < n; ++i) {
        fact[i] = fact[i - 1] * i;
      }

      ::std::vector<int> p;
      for (int i = 0; i < n; ++i) {
        const auto it = ::std::next(left.begin(), id / fact[n - i - 1]);
        p.push_back(*it);
        left.erase(it);
        id %= fact[n - i - 1];
      }

      return ::tools::permutation<T>(p);
    }

    ::tools::permutation<T> inv() const {
      return ::tools::permutation<T>(this->m_inv);
    }
    ::tools::permutation<T>& inv_inplace() {
      this->m_perm.swap(this->m_inv);
      return *this;
    }
    T inv(const int i) const {
      assert(0 <= i && i < this->size());
      return this->m_inv[i];
    }

    ::tools::permutation<T>& operator*=(const ::tools::permutation<T>& other) {
      assert(this->size() == other.size());
      for (int i = 0; i < this->size(); ++i) {
        this->m_inv[i] = other.m_perm[this->m_perm[i]];
      }
      this->m_perm.swap(this->m_inv);
      this->make_inv();
      return *this;
    }
    friend ::tools::permutation<T> operator*(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return ::tools::permutation<T>(lhs) *= rhs;
    }

    friend bool operator==(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return lhs.m_perm == rhs.m_perm;
    }
    friend bool operator!=(const ::tools::permutation<T>& lhs, const ::tools::permutation<T>& rhs) {
      return lhs.m_perm != rhs.m_perm;
    }

    friend ::std::ostream& operator<<(::std::ostream& os, const ::tools::permutation<T>& self) {
      os << '(';
      auto it = self.begin();
      const auto end = self.end();
      if (it != end) {
        os << *it;
        for (++it; it != end; ++it) {
          os << ", " << *it;
        }
      }
      return os << ')';
    }
    friend ::std::istream& operator>>(::std::istream& is, ::tools::permutation<T>& self) {
      for (auto& value : self.m_perm) {
        is >> value;
      }
      self.verify_consistency();
      self.make_inv();
      return is;
    }
  };
}

#endif
