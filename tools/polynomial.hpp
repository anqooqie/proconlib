#ifndef TOOLS_POLYNOMIAL_HPP
#define TOOLS_POLYNOMIAL_HPP

#include <vector>
#include <cstddef>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <cassert>
#include <iterator>
#include "tools/fps.hpp"
#include "tools/has_mod.hpp"
#include "tools/is_prime.hpp"

namespace tools {
  template <typename R>
  class polynomial {
  private:
    using P = ::tools::polynomial<R>;
    ::std::vector<R> m_vector;

  public:
    using reference = R&;
    using const_reference = const R&;
    using iterator = typename ::std::vector<R>::iterator;
    using const_iterator = typename ::std::vector<R>::const_iterator;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using value_type = R;
    using allocator_type = typename ::std::vector<R>::allocator_type;
    using pointer = R*;
    using const_pointer = const R*;
    using reverse_iterator = typename ::std::vector<R>::reverse_iterator;
    using const_reverse_iterator = typename ::std::vector<R>::const_reverse_iterator;

    polynomial() = default;
    polynomial(const P&) = default;
    polynomial(P&&) = default;
    ~polynomial() = default;
    P& operator=(const P&) = default;
    P& operator=(P&&) = default;

    explicit polynomial(const size_type n) : m_vector(n) {}
    polynomial(const size_type n, const_reference value) : m_vector(n, value) {}
    template <class InputIter> polynomial(const InputIter first, const InputIter last) : m_vector(first, last) {}
    polynomial(const ::std::initializer_list<R> il) : m_vector(il) {}

    iterator begin() noexcept { return this->m_vector.begin(); }
    const_iterator begin() const noexcept { return this->m_vector.begin(); }
    iterator end() noexcept { return this->m_vector.end(); }
    const_iterator end() const noexcept { return this->m_vector.end(); }
    const_iterator cbegin() const noexcept { return this->m_vector.cbegin(); }
    const_iterator cend() const noexcept { return this->m_vector.cend(); }
    reverse_iterator rbegin() noexcept { return this->m_vector.rbegin(); }
    const_reverse_iterator rbegin() const noexcept { return this->m_vector.rbegin(); }
    const_reverse_iterator crbegin() const noexcept { return this->m_vector.crbegin(); }
    reverse_iterator rend() noexcept { return this->m_vector.rend(); }
    const_reverse_iterator rend() const noexcept { return this->m_vector.rend(); }
    const_reverse_iterator crend() const noexcept { return this->m_vector.crend(); }

    size_type size() const noexcept { return this->m_vector.size(); }
    size_type max_size() const noexcept { return this->m_vector.max_size(); }
    void resize(const size_type sz) { this->m_vector.resize(sz); }
    void resize(const size_type sz, const R& c) { this->m_vector.resize(sz, c); }
    size_type capacity() const noexcept { return this->m_vector.capacity(); }
    bool empty() const noexcept { return this->m_vector.empty(); }
    void reserve(const size_type n) { this->m_vector.reserve(n); }
    void shrink_to_fit() { this->m_vector.shrink_to_fit(); }

    reference operator[](const size_type n) { return this->m_vector[n]; }
    const_reference operator[](const size_type n) const { return this->m_vector[n]; }
    reference at(const size_type n) { return this->m_vector.at(n); }
    const_reference at(const size_type n) const { return this->m_vector.at(n); }
    pointer data() noexcept { return this->m_vector.data(); }
    const_pointer data() const noexcept { return this->m_vector.data(); }
    reference front() { return this->m_vector.front(); }
    const_reference front() const { return this->m_vector.front(); }
    reference back() { return this->m_vector.back(); }
    const_reference back() const { return this->m_vector.back(); }

    template <class InputIterator> void assign(const InputIterator first, const InputIterator last) { this->m_vector.assign(first, last); }
    void assign(const size_type n, const R& u) { this->m_vector.assign(n, u); }
    void assign(const ::std::initializer_list<R> il) { this->m_vector.assign(il); }
    void push_back(const R& x) { this->m_vector.push_back(x); }
    void push_back(R&& x) { this->m_vector.push_back(::std::forward<R>(x)); }
    template <class... Args> reference emplace_back(Args&&... args) { return this->m_vector.emplace_back(::std::forward<Args>(args)...); }
    void pop_back() { this->m_vector.pop_back(); }
    iterator insert(const const_iterator position, const R& x) { return this->m_vector.insert(position, x); }
    iterator insert(const const_iterator position, R&& x) { return this->m_vector.insert(position, ::std::forward<R>(x)); }
    iterator insert(const const_iterator position, const size_type n, const R& x) { return this->m_vector.insert(position, n, x); }
    template <class InputIterator> iterator insert(const const_iterator position, const InputIterator first, const InputIterator last) { return this->m_vector.insert(position, first, last); }
    iterator insert(const const_iterator position, const ::std::initializer_list<R> il) { return this->m_vector.insert(position, il); }
    template <class... Args> iterator emplace(const const_iterator position, Args&&... args) { return this->m_vector.emplace(position, ::std::forward<Args>(args)...); }
    iterator erase(const const_iterator position) { return this->m_vector.erase(position); }
    iterator erase(const const_iterator first, const const_iterator last) { return this->m_vector.erase(first, last); }
    void swap(P& x) noexcept { this->m_vector.swap(x.m_vector); }
    void clear() { this->m_vector.clear(); }

    allocator_type get_allocator() const noexcept { return this->m_vector.get_allocator(); }

    friend bool operator==(const P& x, const P& y) {
      const auto n = ::std::min(x.size(), y.size());
      static const auto is_zero = [](const R& e) { return e == R(0); };
      return ::std::equal(x.begin(), x.begin() + n, y.begin(), y.begin() + n) && ::std::all_of(x.begin() + n, x.end(), is_zero) && ::std::all_of(y.begin() + n, y.end(), is_zero);
    }
    friend bool operator!=(const P& x, const P& y) { return !(x == y); }

    friend void swap(P& x, P& y) noexcept { x.m_vector.swap(y.m_vector); }

    int deg() const {
      for (size_type i = this->size(); i --> 0;) {
        if ((*this)[i] != R(0)) return i;
      }
      return -1;
    }

    P operator+() const {
      return *this;
    }
    P operator-() const {
      P res(*this);
      for (auto& e : res) {
        e = -e;
      }
      return res;
    }
    P& operator*=(const R& g) {
      for (auto& e : *this) {
        e *= g;
      }
      return *this;
    }
    P& operator/=(const R& g) {
      assert(R(0) == R(1) || g != R(0));
      *this *= R(1) / g;
      return *this;
    }
    P& operator+=(const P& g) {
      const int n = this->size();
      const int m = g.size();
      this->resize(::std::max(n, m));
      for (int i = 0; i < m; ++i) {
        (*this)[i] += g[i];
      }
      return *this;
    }
    P& operator-=(const P& g) {
      const int n = this->size();
      const int m = g.size();
      this->resize(::std::max(n, m));
      for (int i = 0; i < m; ++i) {
        (*this)[i] -= g[i];
      }
      return *this;
    }
    P& operator<<=(const int d) {
      if (d < 0) *this >>= -d;

      const int n = this->size();
      this->erase(this->begin(), this->begin() + ::std::min(n, d));
      return *this;
    }
    P& operator>>=(const int d) {
      if (d < 0) *this <<= -d;

      this->insert(this->begin(), d, R(0));
      return *this;
    }

    P& operator*=(const P& g) {
      const int n = this->size();
      const int m = g.size();

      if (n == 0 && m == 0) {
        this->clear();
        return *this;
      }
      if (n == 0 || m == 0) {
        ::std::fill(this->begin(), this->end(), R(0));
        this->resize(n + m - 1, R(0));
        return *this;
      }

      P res;
      ::tools::convolution(this->cbegin(), this->cend(), g.cbegin(), g.cend(), ::std::back_inserter(res));
      return *this = ::std::move(res);
    }

  private:
    P& divide_inplace_regular(const P& g) {
      const int n = this->size();
      const int m = g.size();

      assert(0 < m && m <= n);
      assert(this->back() != R(0));
      assert(g.back() != R(0));

      const auto ic = R(1) / g.back();
      P q(n - m + 1);
      for (int i = n - m; i >= 0; --i) {
        q[i] = (*this)[m - 1 + i] * ic;
        for (int j = 0; j < m; ++j) {
          (*this)[j + i] -= g[j] * q[i];
        }
      }
      return *this = ::std::move(q);
    }
    template <typename R_ = R>
    P& divide_inplace_faster(const P& g) {
      const int n = this->size();
      const int m = g.size();

      static_assert(::tools::has_mod_v<R>);
      assert(::tools::is_prime(R::mod()));
      assert(0 < m && m <= n);
      assert(this->back() != R(0));
      assert(g.back() != R(0));

      ::tools::fps<R> q(this->rbegin(), this->rend());
      q.divide_inplace(::tools::fps<R>(g.rbegin(), g.rend()), n - m + 1);
      this->assign(q.rbegin(), q.rend());
      return *this;
    }

  public:
    P& operator/=(P g) {
      if (R(0) == R(1)) {
        this->clear();
        return *this;
      }

      this->resize(this->deg() + 1);
      g.resize(g.deg() + 1);

      const int n = this->size();
      const int m = g.size();

      assert(m > 0);
      if (n < m) {
        this->clear();
        return *this;
      }

      if constexpr (::tools::has_mod_v<R>) {
        assert(::tools::is_prime(R::mod()));
        return this->divide_inplace_faster(g);
      } else {
        return this->divide_inplace_regular(g);
      }
    }
    P& operator%=(const P& g) {
      auto q = (*this) / g;
      q *= g;
      q *= R(-1);
      *this += q;
      this->resize(this->deg() + 1);
      return *this;
    }

    R eval(const R& a) const {
      R x(1);
      R res(0);
      for (const auto e : *this) {
        res += e * x;
        x *= a;
      }
      return res;
    }

    friend P operator*(const P& f, const R& c) { return P(f) *= c; }
    friend P operator*(const R& c, const P& f) { return P(f) *= c; }
    friend P operator/(const P& f, const R& c) { return P(f) /= c; }
    friend P operator+(const P& f, const P& g) { return P(f) += g; }
    friend P operator-(const P& f, const P& g) { return P(f) -= g; }
    friend P operator*(const P& f, const P& g) { return P(f) *= g; }
    friend P operator/(const P& f, const P& g) { return P(f) /= g; }
    friend P operator%(const P& f, const P& g) { return P(f) %= g; }
    friend P operator<<(const P& f, const int d) { return P(f) <<= d; }
    friend P operator>>(const P& f, const int d) { return P(f) >>= d; }
  };
}

#endif
