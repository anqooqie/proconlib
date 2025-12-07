#ifndef TOOLS_ONLINE_IMOS_HPP
#define TOOLS_ONLINE_IMOS_HPP

#include <cassert>
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <vector>
#include "tools/commutative_group.hpp"
#include "tools/commutative_monoid.hpp"
#include "tools/groups.hpp"

namespace tools {
  template <typename X, bool Forward = true>
  class online_imos {
    using M = std::conditional_t<tools::commutative_monoid<X>, X, tools::groups::plus<X>>;
    using T = typename M::T;
    std::vector<T> m_vector;
    std::vector<T> m_diffs;
    int m_processed;

  public:
    class iterator {
      const online_imos<X, Forward> *m_parent;
      std::size_t m_i;

    public:
      using reference = const T&;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = const T*;
      using iterator_category = std::random_access_iterator_tag;

      iterator() = default;
      iterator(const online_imos<X, Forward> * const parent, const std::size_t i) : m_parent(parent), m_i(i) {
      }

      reference operator*() const {
        return (*this->m_parent)[this->m_i];
      }
      pointer operator->() const {
        return &(*(*this));
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
      iterator& operator--() {
        --this->m_i;
        return *this;
      }
      iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }
      iterator& operator+=(const difference_type n) {
        this->m_i += n;
        return *this;
      }
      iterator& operator-=(const difference_type n) {
        this->m_i -= n;
        return *this;
      }
      friend iterator operator+(const iterator self, const difference_type n) {
        return iterator(self.m_parent, self.m_i + n);
      }
      friend iterator operator+(const difference_type n, const iterator self) {
        return self + n;
      }
      friend iterator operator-(const iterator self, const difference_type n) {
        return iterator(self.m_parent, self.m_i - n);
      }
      friend difference_type operator-(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);
      }
      reference operator[](const difference_type n) const {
        return *(*this + n);
      }

      friend bool operator==(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i == rhs.m_i;
      }
      friend bool operator!=(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i != rhs.m_i;
      }
      friend bool operator<(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i < rhs.m_i;
      }
      friend bool operator<=(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i <= rhs.m_i;
      }
      friend bool operator>(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i > rhs.m_i;
      }
      friend bool operator>=(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i >= rhs.m_i;
      }
    };

    online_imos() : online_imos(0) {
    }
    online_imos(const int n) : m_vector(n, M::e()), m_diffs(n + 1, M::e()), m_processed(Forward ? 0 : n) {
    }

    int size() const {
      return this->m_vector.size();
    }
    const T& operator[](const int i) {
      assert(0 <= i && i < this->size());
      if constexpr (Forward) {
        for (; this->m_processed <= i; ++this->m_processed) {
          this->m_vector[this->m_processed] = this->m_processed == 0
            ? this->m_diffs[this->m_processed]
            : M::op(this->m_vector[this->m_processed - 1], this->m_diffs[this->m_processed]);
        }
      } else {
        for (; this->m_processed > i; --this->m_processed) {
          this->m_vector[this->m_processed - 1] = this->m_processed == this->size()
            ? this->m_diffs[this->m_processed]
            : M::op(this->m_diffs[this->m_processed], this->m_vector[this->m_processed]);
        }
      }
      return this->m_vector[i];
    }

    iterator begin() const { return iterator(this, 0); }
    iterator cbegin() const { return this->begin(); }
    iterator end() const { return iterator(this, this->size()); }
    iterator cend() const { return this->end(); }
    std::reverse_iterator<iterator> rbegin() const { return std::make_reverse_iterator(this->end()); }
    std::reverse_iterator<iterator> crbegin() const { return this->rbegin(); }
    std::reverse_iterator<iterator> rend() const { return std::make_reverse_iterator(this->begin()); }
    std::reverse_iterator<iterator> crend() const { return this->rend(); }

    void apply(const int l, const int r, const T& x) {
      assert(0 <= l && l <= r && r <= this->size());
      if constexpr (Forward) {
        assert(this->m_processed <= l);
        this->m_diffs[l] = M::op(x, this->m_diffs[l]);
        if constexpr (tools::commutative_group<M>) {
          this->m_diffs[r] = M::op(M::inv(x), this->m_diffs[r]);
        } else {
          assert(r == this->size());
        }
      } else {
        assert(r <= this->m_processed);
        this->m_diffs[r] = M::op(x, this->m_diffs[r]);
        if constexpr (tools::commutative_group<M>) {
          this->m_diffs[l] = M::op(M::inv(x), this->m_diffs[l]);
        } else {
          assert(l == 0);
        }
      }
    }
    template <typename Y = X> requires (!tools::commutative_monoid<Y>)
    void add(const int l, const int r, const T& x) {
      this->apply(l, r, x);
    }
  };
}

#endif
