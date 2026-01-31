#ifndef TOOLS_SECOND_ORDER_IMOS_HPP
#define TOOLS_SECOND_ORDER_IMOS_HPP

#include <cassert>
#include <compare>
#include <cstddef>
#include <iterator>
#include <vector>
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  class second_order_imos {
    std::vector<T> m_vector;
    std::vector<T> m_diffs2;
    int m_processed;

  public:
    class iterator {
      second_order_imos<T> *m_parent;
      std::size_t m_i;

    public:
      using reference = const T&;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = const T*;
      using iterator_category = std::random_access_iterator_tag;

      iterator() = default;
      iterator(second_order_imos<T> * const parent, const std::size_t i) : m_parent(parent), m_i(i) {
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

      friend std::strong_ordering operator<=>(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i <=> rhs.m_i;
      }
      friend bool operator==(const iterator lhs, const iterator rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i == rhs.m_i;
      }
    };

    second_order_imos() : second_order_imos(0) {
    }
    second_order_imos(const int n) : m_vector(n, 0), m_diffs2(n + 2, 0), m_processed(0) {
    }

    int size() const {
      return this->m_vector.size();
    }
    const T& operator[](const int i) {
      assert(0 <= i && i < this->size());
      auto& j = this->m_processed;
      do {
        if (i < j) break;
        if (j == 0) {
          this->m_vector[j] = this->m_diffs2[j];
          ++j;
          if (i < j) break;
        }
        if (j == 1) {
          this->m_vector[j] = this->m_diffs2[j] + 2 * this->m_vector[j - 1];
          ++j;
          if (i < j) break;
        }
        do {
          this->m_vector[j] = this->m_diffs2[j] + 2 * this->m_vector[j - 1] - this->m_vector[j - 2];
          ++j;
        } while (j <= i);
      } while (false);
      return this->m_vector[i];
    }

    iterator begin() { return iterator(this, 0); }
    iterator end() { return iterator(this, this->size()); }
    std::reverse_iterator<iterator> rbegin() { return std::make_reverse_iterator(this->end()); }
    std::reverse_iterator<iterator> rend() { return std::make_reverse_iterator(this->begin()); }

    void add(const int l, const int r, const T a, const T d) {
      assert(0 <= l && l <= r && r <= this->size());
      assert(this->m_processed <= l);
      this->m_diffs2[l] += a;
      this->m_diffs2[l + 1] += d - a;
      this->m_diffs2[r] -= a + (r - l) * d;
      this->m_diffs2[r + 1] += a + (r - l - 1) * d;
    }
  };
}

#endif
