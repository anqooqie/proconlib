#ifndef TOOLS_VIRTUAL_VECTOR_HPP
#define TOOLS_VIRTUAL_VECTOR_HPP

#include <cstddef>
#include <type_traits>
#include <memory>
#include <iterator>
#include <cassert>
#include <algorithm>

namespace tools {
  template <typename F>
  class virtual_vector {
  public:
    using size_type = std::size_t;

    class iterator {
      const virtual_vector<F> *m_parent;
      size_type m_i;

    public:
      using reference = decltype(std::declval<F>()(std::declval<size_type>()));
      using value_type = std::remove_const_t<std::remove_reference_t<reference>>;
      using difference_type = std::ptrdiff_t;
      using pointer = const value_type*;
      using iterator_category = std::random_access_iterator_tag;

      iterator() = default;
      iterator(const virtual_vector<F> * const parent, const size_type i) : m_parent(parent), m_i(i) {
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

    using const_reference = decltype(std::declval<F>()(std::declval<size_type>()));
    using value_type = std::remove_const_t<std::remove_reference_t<const_reference>>;
    using reference = value_type&;
    using const_iterator = iterator;
    using difference_type = std::ptrdiff_t;
    using allocator_type = std::allocator<value_type>;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  private:
    size_type m_size;
    F m_selector;

  public:
    virtual_vector() = default;
    virtual_vector(const size_type n, const F& selector) : m_size(n), m_selector(selector) {
    }

    iterator begin() noexcept { return iterator(this, 0); }
    const_iterator begin() const noexcept { return const_iterator(this, 0); }
    const_iterator cbegin() const noexcept { return const_iterator(this, 0); }
    iterator end() noexcept { return iterator(this, this->size()); }
    const_iterator end() const noexcept { return const_iterator(this, this->size()); }
    const_iterator cend() const noexcept { return const_iterator(this, this->size()); }
    reverse_iterator rbegin() noexcept { return std::make_reverse_iterator(this->end()); }
    const_reverse_iterator rbegin() const noexcept { return std::make_reverse_iterator(this->end()); }
    const_reverse_iterator crbegin() const noexcept { return std::make_reverse_iterator(this->cend()); }
    reverse_iterator rend() noexcept { return std::make_reverse_iterator(this->begin()); }
    const_reverse_iterator rend() const noexcept { return std::make_reverse_iterator(this->begin()); }
    const_reverse_iterator crend() const noexcept { return std::make_reverse_iterator(this->cbegin()); }

    size_type size() const noexcept { return this->m_size; }
    bool empty() const noexcept { return this->size() == 0; }

    const_reference operator[](const size_type n) const { assert(n < this->size()); return this->m_selector(n); }
    const_reference at(const size_type n) const { return (*this)[n]; }
    const_reference front() const { return *this->begin(); }
    const_reference back() const { return *this->rbegin(); }

    template <typename G>
    friend bool operator==(const virtual_vector<F>& x, const virtual_vector<G>& y) { return std::equal(x.begin(), x.end(), y.begin(), y.end()); }
    template <typename G>
    friend bool operator!=(const virtual_vector<F>& x, const virtual_vector<G>& y) { return !(x == y); }
    template <typename G>
    friend bool operator<(const virtual_vector<F>& x, const virtual_vector<G>& y) { return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }
    template <typename G>
    friend bool operator<=(const virtual_vector<F>& x, const virtual_vector<G>& y) { return !(x > y); }
    template <typename G>
    friend bool operator>(const virtual_vector<F>& x, const virtual_vector<G>& y) { return y < x; }
    template <typename G>
    friend bool operator>=(const virtual_vector<F>& x, const virtual_vector<G>& y) { return !(x < y); }
  };
}

#endif
