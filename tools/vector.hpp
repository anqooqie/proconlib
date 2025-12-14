#ifndef TOOLS_VECTOR_HPP
#define TOOLS_VECTOR_HPP

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <type_traits>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/abs.hpp"
#include "tools/tuple_hash.hpp"

namespace tools {
  namespace detail {
    namespace vector {
      template <typename T, std::size_t N>
      class members {
      protected:
        constexpr static bool variable_sized = false;
        constexpr static bool has_aliases = false;
        std::array<T, N> m_values;
        members() : m_values() {}
        members(const std::initializer_list<T> il) : m_values(il) {
          assert(il.size() == N);
        }
      };

      template <typename T>
      class members<T, 2> {
      protected:
        constexpr static bool variable_sized = false;
        constexpr static bool has_aliases = true;
        std::array<T*, 2> m_values;
        members() : m_values{&this->x, &this->y} {}
        members(const T& x, const T& y) : m_values{&this->x, &this->y}, x(x), y(y) {}
        members(const std::initializer_list<T> il) : m_values{&this->x, &this->y}, x(il.begin()[0]), y(il.begin()[1]) {
          assert(il.size() == 2);
        }

      public:
        T x;
        T y;
      };

      template <typename T>
      class members<T, 3> {
      protected:
        constexpr static bool variable_sized = false;
        constexpr static bool has_aliases = true;
        std::array<T*, 3> m_values;
        members() : m_values{&this->x, &this->y, &this->z} {}
        members(const T& x, const T& y, const T& z) : m_values{&this->x, &this->y, &this->z}, x(x), y(y), z(z) {}
        members(const std::initializer_list<T> il) : m_values{&this->x, &this->y, &this->z}, x(il.begin()[0]), y(il.begin()[1]), z(il.begin()[2]) {
          assert(il.size() == 3);
        }

      public:
        T x;
        T y;
        T z;
      };

      template <typename T>
      class members<T, 4> {
      protected:
        constexpr static bool variable_sized = false;
        constexpr static bool has_aliases = true;
        std::array<T*, 4> m_values;
        members() : m_values{&this->x, &this->y, &this->z, &this->w} {}
        members(const T& x, const T& y, const T& z, const T& w) : m_values{&this->x, &this->y, &this->z, &this->w}, x(x), y(y), z(z), w(w) {}
        members(const std::initializer_list<T> il) : m_values{&this->x, &this->y, &this->z, &this->w}, x(il.begin()[0]), y(il.begin()[1]), z(il.begin()[2]), w(il.begin()[3]) {
          assert(il.size() == 4);
        }

      public:
        T x;
        T y;
        T z;
        T w;
      };

      template <typename T>
      class members<T, std::numeric_limits<std::size_t>::max()> {
      protected:
        constexpr static bool variable_sized = true;
        constexpr static bool has_aliases = false;
        std::vector<T> m_values;
        members() = default;
        members(const std::size_t n) : m_values(n) {}
        members(const std::size_t n, const T& value) : m_values(n, value) {}
        template <typename InputIter>
        members(const InputIter first, const InputIter last) : m_values(first, last) {}
        members(const std::initializer_list<T> il) : m_values(il) {}
      };
    }
  }

  template <typename T, std::size_t N = std::numeric_limits<std::size_t>::max()>
  class vector : public tools::detail::vector::members<T, N> {
    using Base = tools::detail::vector::members<T, N>;
    using F = std::conditional_t<std::floating_point<T>, T, double>;
    using V = tools::vector<T, N>;
    constexpr static bool variable_sized = Base::variable_sized;
    constexpr static bool has_aliases = Base::has_aliases;

  public:
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using value_type = T;
    class iterator {
      V* m_parent;
      size_type m_i;

    public:
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using reference = T&;
      using pointer = T*;
      using iterator_category = std::random_access_iterator_tag;

      iterator() = default;
      iterator(V * const parent, const size_type i) : m_parent(parent), m_i(i) {}

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
      friend iterator operator+(const iterator& self, const difference_type n) {
        return iterator(self) += n;
      }
      friend iterator operator+(const difference_type n, const iterator& self) {
        return iterator(self) += n;
      }
      friend iterator operator-(const iterator& self, const difference_type n) {
        return iterator(self) -= n;
      }
      friend difference_type operator-(const iterator& lhs, const iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);
      }
      reference operator[](const difference_type n) const {
        return *(*this + n);
      }

      friend bool operator==(const iterator& lhs, const iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i == rhs.m_i;
      }
      friend bool operator!=(const iterator& lhs, const iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i != rhs.m_i;
      }
      friend bool operator<(const iterator& lhs, const iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i < rhs.m_i;
      }
      friend bool operator<=(const iterator& lhs, const iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i <= rhs.m_i;
      }
      friend bool operator>(const iterator& lhs, const iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i > rhs.m_i;
      }
      friend bool operator>=(const iterator& lhs, const iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i >= rhs.m_i;
      }
    };
    class const_iterator {
      const V *m_parent;
      size_type m_i;

    public:
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using reference = const T&;
      using pointer = const T*;
      using iterator_category = std::random_access_iterator_tag;

      const_iterator() = default;
      const_iterator(const V * const parent, const size_type i) : m_parent(parent), m_i(i) {}

      reference operator*() const {
        return (*this->m_parent)[this->m_i];
      }
      pointer operator->() const {
        return &(*(*this));
      }

      const_iterator& operator++() {
        ++this->m_i;
        return *this;
      }
      const_iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      const_iterator& operator--() {
        --this->m_i;
        return *this;
      }
      const_iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }
      const_iterator& operator+=(const difference_type n) {
        this->m_i += n;
        return *this;
      }
      const_iterator& operator-=(const difference_type n) {
        this->m_i -= n;
        return *this;
      }
      friend const_iterator operator+(const const_iterator& self, const difference_type n) {
        return const_iterator(self) += n;
      }
      friend const_iterator operator+(const difference_type n, const const_iterator& self) {
        return const_iterator(self) += n;
      }
      friend const_iterator operator-(const const_iterator& self, const difference_type n) {
        return const_iterator(self) -= n;
      }
      friend difference_type operator-(const const_iterator& lhs, const const_iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return static_cast<difference_type>(lhs.m_i) - static_cast<difference_type>(rhs.m_i);
      }
      reference operator[](const difference_type n) const {
        return *(*this + n);
      }

      friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i == rhs.m_i;
      }
      friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i != rhs.m_i;
      }
      friend bool operator<(const const_iterator& lhs, const const_iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i < rhs.m_i;
      }
      friend bool operator<=(const const_iterator& lhs, const const_iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i <= rhs.m_i;
      }
      friend bool operator>(const const_iterator& lhs, const const_iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i > rhs.m_i;
      }
      friend bool operator>=(const const_iterator& lhs, const const_iterator& rhs) {
        assert(lhs.m_parent == rhs.m_parent);
        return lhs.m_i >= rhs.m_i;
      }
    };
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    vector() = default;
    vector(const V& other) : Base() {
      if constexpr (has_aliases) {
        std::copy(other.begin(), other.end(), this->begin());
      } else {
        this->m_values = other.m_values;
      }
    }
    vector(V&& other) noexcept {
      if constexpr (has_aliases) {
        std::copy(other.begin(), other.end(), this->begin());
      } else {
        this->m_values = std::move(other.m_values);
      }
    }
    ~vector() = default;
    V& operator=(const V& other) {
      if constexpr (has_aliases) {
        std::copy(other.begin(), other.end(), this->begin());
      } else {
        this->m_values = other.m_values;
      }
      return *this;
    }
    V& operator=(V&& other) noexcept {
      if constexpr (has_aliases) {
        std::copy(other.begin(), other.end(), this->begin());
      } else {
        this->m_values = std::move(other.m_values);
      }
      return *this;
    }

    explicit vector(size_type n) requires (variable_sized) : Base(n) {}
    vector(size_type n, const_reference value) requires (variable_sized) : Base(n, value) {}
    template <typename InputIter>
    vector(const InputIter first, const InputIter last) requires (variable_sized) : Base(first, last) {}
    vector(const T& x, const T& y) requires (N == 2) : Base(x, y) {}
    vector(const T& x, const T& y, const T& z) requires (N == 3) : Base(x, y, z) {}
    vector(const T& x, const T& y, const T& z, const T& w) requires (N == 4) : Base(x, y, z, w) {}
    vector(const std::initializer_list<T> il) : Base(il) {}

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

    size_type size() const noexcept { return this->m_values.size(); }
    bool empty() const noexcept { return this->m_values.empty(); }

    reference operator[](const size_type n) {
      if constexpr (has_aliases) {
        return *this->m_values[n];
      } else {
        return this->m_values[n];
      }
    }
    const_reference operator[](const size_type n) const {
      if constexpr (has_aliases) {
        return *this->m_values[n];
      } else {
        return this->m_values[n];
      }
    }
    reference front() { return *this->begin(); }
    const_reference front() const { return *this->begin(); }
    reference back() { return *this->rbegin(); }
    const_reference back() const { return *this->rbegin(); }

    V operator+() const {
      return *this;
    }
    V operator-() const {
      V res = *this;
      for (auto& v : res) v = -v;
      return res;
    }
    V& operator+=(const V& other) {
      assert(this->size() == other.size());
      for (std::size_t i = 0; i < this->size(); ++i) {
        (*this)[i] += other[i];
      }
      return *this;
    }
    friend V operator+(const V& lhs, const V& rhs) {
      return V(lhs) += rhs;
    }
    V& operator-=(const V& other) {
      assert(this->size() == other.size());
      for (std::size_t i = 0; i < this->size(); ++i) {
        (*this)[i] -= other[i];
      }
      return *this;
    }
    friend V operator-(const V& lhs, const V& rhs) {
      return V(lhs) -= rhs;
    }
    V& operator*=(const T& c) {
      for (auto& v : *this) v *= c;
      return *this;
    }
    friend V operator*(const T& lhs, const V& rhs) {
      return V(rhs) *= lhs;
    }
    friend V operator*(const V& lhs, const T& rhs) {
      return V(lhs) *= rhs;
    }
    V& operator/=(const T& c) {
      for (auto& v : *this) v /= c;
      return *this;
    }
    friend V operator/(const V& lhs, const T& rhs) {
      return V(lhs) /= rhs;
    }

    friend bool operator==(const V& lhs, const V& rhs) {
      return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    friend bool operator!=(const V& lhs, const V& rhs) {
      return !(lhs == rhs);
    }

    T inner_product(const V& other) const {
      assert(this->size() == other.size());
      T res{};
      for (std::size_t i = 0; i < this->size(); ++i) {
        res += (*this)[i] * other[i];
      }
      return res;
    }
    T l1_norm() const {
      T res{};
      for (const auto& v : *this) {
        res += tools::abs(v);
      }
      return res;
    }
    T squared_l2_norm() const {
      return this->inner_product(*this);
    }
    F l2_norm() const {
      return std::sqrt(static_cast<F>(this->squared_l2_norm()));
    }
    V normalized() const requires std::floating_point<T> {
      return *this / this->l2_norm();
    }

    friend std::ostream& operator<<(std::ostream& os, const V& self) {
      os << '(';
      std::string delimiter = "";
      for (const auto& v : self) {
        os << delimiter << v;
        delimiter = ", ";
      }
      return os << ')';
    }
    friend std::istream& operator>>(std::istream& is, V& self) {
      for (auto& v : self) {
        is >> v;
      }
      return is;
    }

    T outer_product(const V& other) const requires (N == 2) {
      return this->x * other.y - this->y * other.x;
    }
    V turned90() const requires (N == 2) {
      return V{-this->y, this->x};
    }
    V turned270() const requires (N == 2) {
      return V{this->y, -this->x};
    }

    static const std::array<V, 4>& four_directions() requires (N == 2) {
      static const std::array<V, 4> res = {
        V{T(1), T(0)},
        V{T(0), T(1)},
        V{T(-1), T(0)},
        V{T(0), T(-1)}
      };
      return res;
    }
    static const std::array<V, 8>& eight_directions() requires (N == 2) {
      static const std::array<V, 8> res = {
        V{T(1), T(0)},
        V{T(1), T(1)},
        V{T(0), T(1)},
        V{T(-1), T(1)},
        V{T(-1), T(0)},
        V{T(-1), T(-1)},
        V{T(0), T(-1)},
        V{T(1), T(-1)}
      };
      return res;
    }

    V outer_product(const V& other) const requires (N == 3) {
      return V{this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x};
    }
    std::array<V, 3> orthonormal_basis() const requires (N == 3 && std::floating_point<T>) {
      assert((*this != V{0, 0, 0}));

      std::array<V, 3> v;
      v[0] = *this;
      v[1] = V{0, this->z, -this->y};
      if (v[1] == V{0, 0, 0}) {
        v[1] = V{-this->z, 0, this->x};
      }
      v[1] -= v[0].inner_product(v[1]) / v[0].inner_product(v[0]) * v[0];

      v[0] = v[0].normalized();
      v[1] = v[1].normalized();
      v[2] = v[0].outer_product(v[1]);

      return v;
    }
  };
}

namespace std {
  template <typename T>
  struct hash<tools::vector<T, 2>> {
    using result_type = std::size_t;
    using argument_type = tools::vector<T, 2>;
    result_type operator()(const argument_type& key) const {
      static const tools::tuple_hash<T, T> hasher;
      return hasher(std::make_tuple(key.x, key.y));
    }
  };
  template <typename T>
  struct hash<tools::vector<T, 3>> {
    using result_type = std::size_t;
    using argument_type = tools::vector<T, 3>;
    result_type operator()(const argument_type& key) const {
      static const tools::tuple_hash<T, T, T> hasher;
      return hasher(std::make_tuple(key.x, key.y, key.z));
    }
  };
  template <typename T>
  struct hash<tools::vector<T, 4>> {
    using result_type = std::size_t;
    using argument_type = tools::vector<T, 4>;
    result_type operator()(const argument_type& key) const {
      static const tools::tuple_hash<T, T, T, T> hasher;
      return hasher(std::make_tuple(key.x, key.y, key.z, key.w));
    }
  };
}

#endif
