#ifndef TOOLS_PERMUTATION_HPP
#define TOOLS_PERMUTATION_HPP

#include <cassert>
#include <concepts>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>
#include "atcoder/fenwicktree.hpp"
#include "atcoder/segtree.hpp"
#include "tools/groups.hpp"
#include "tools/integral.hpp"
#include "tools/mutable_type.hpp"

namespace tools {
  template <tools::integral T>
  class permutation {
    std::vector<int> m_perm;
    std::vector<int> m_inv;

    static std::vector<long long> make_fact(const int n) {
      assert(0 <= n && n <= 20);
      std::vector<long long> fact(n);
      if (n > 0) {
        fact[0] = 1;
        for (int i = 1; i < n; ++i) {
          fact[i] = fact[i - 1] * i;
        }
      }
      return fact;
    }

    void verify_consistency() const {
#ifndef NDEBUG
      std::vector<bool> unique(this->size(), true);
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
      std::vector<int>::const_iterator m_it;

    public:
      using reference = T;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = const value_type*;
      using iterator_category = std::random_access_iterator_tag;

      iterator() = default;
      iterator(const std::vector<int>::const_iterator it) : m_it(it) {
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
    explicit permutation(const int n) : m_perm(std::views::iota(0, n) | std::ranges::to<std::vector>()), m_inv(std::views::iota(0, n) | std::ranges::to<std::vector>()) {
    }
    template <std::ranges::input_range R>
    requires std::convertible_to<std::ranges::range_reference_t<R>, int>
    permutation(R&& r) : m_perm(std::forward<R>(r) | std::ranges::to<std::vector<int>>()) {
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

    auto swap_from_left(this tools::mutable_type auto&& self, const int x, const int y) -> decltype(self) {
      assert(0 <= x && x < self.size());
      assert(0 <= y && y < self.size());
      self.m_inv[self.m_perm[y]] = x;
      self.m_inv[self.m_perm[x]] = y;
      std::swap(self.m_perm[x], self.m_perm[y]);
      return std::forward<decltype(self)>(self);
    }
    auto swap_from_right(this tools::mutable_type auto&& self, const int x, const int y) -> decltype(self) {
      assert(0 <= x && x < self.size());
      assert(0 <= y && y < self.size());
      self.m_perm[self.m_inv[y]] = x;
      self.m_perm[self.m_inv[x]] = y;
      std::swap(self.m_inv[x], self.m_inv[y]);
      return std::forward<decltype(self)>(self);
    }

    long long id() const {
      assert(this->size() <= 20);

      const auto fact = tools::permutation<T>::make_fact(this->size());
      atcoder::fenwick_tree<int> fw(this->size());
      for (int i = 0; i < this->size(); ++i) {
        fw.add(i, 1);
      }

      long long id = 0;
      for (int i = 0; i < this->size(); ++i) {
        id += fw.sum(0, this->m_perm[i]) * fact[this->size() - 1 - i];
        fw.add(this->m_perm[i], -1);
      }

      return id;
    }

    static tools::permutation<T> from(const int n, long long id) {
      assert(0 <= n && n <= 20);
      const auto fact = tools::permutation<T>::make_fact(n);
      assert(0 <= id && id < (n == 0 ? 1 : fact[n - 1] * n));
      atcoder::segtree<int, tools::groups::plus<int>::op, tools::groups::plus<int>::e> seg(std::vector<int>(n, 1));

      std::vector<int> p;
      p.reserve(n);
      for (int i = 0; i < n; ++i) {
        const auto c = id / fact[n - 1 - i];
        id -= c * fact[n - 1 - i];
        p.push_back(seg.max_right(0, [&](const auto sum) { return sum <= c; }));
        seg.set(p.back(), 0);
      }

      return tools::permutation<T>(std::move(p));
    }

    tools::permutation<T> inv() const {
      return tools::permutation<T>(this->m_inv);
    }
    auto inv_inplace(this tools::mutable_type auto&& self) -> decltype(self) {
      self.m_perm.swap(self.m_inv);
      return std::forward<decltype(self)>(self);
    }
    T inv(const int i) const {
      assert(0 <= i && i < this->size());
      return this->m_inv[i];
    }

    auto operator*=(this tools::mutable_type auto&& self, const tools::permutation<T>& other) -> decltype(self) {
      assert(self.size() == other.size());
      for (int i = 0; i < self.size(); ++i) {
        self.m_inv[i] = other.m_perm[self.m_perm[i]];
      }
      self.m_perm.swap(self.m_inv);
      self.make_inv();
      return std::forward<decltype(self)>(self);
    }
    tools::permutation<T> operator*(this auto&& lhs, const tools::permutation<T>& rhs) {
      return tools::permutation<T>(std::forward<decltype(lhs)>(lhs)) *= rhs;
    }

    friend bool operator==(const tools::permutation<T>& lhs, const tools::permutation<T>& rhs) {
      return lhs.m_perm == rhs.m_perm;
    }
    friend bool operator!=(const tools::permutation<T>& lhs, const tools::permutation<T>& rhs) {
      return lhs.m_perm != rhs.m_perm;
    }

    friend std::ostream& operator<<(std::ostream& os, const tools::permutation<T>& self) {
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
    friend std::istream& operator>>(std::istream& is, tools::permutation<T>& self) {
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
