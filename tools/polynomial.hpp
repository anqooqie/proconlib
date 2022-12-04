#ifndef TOOLS_POLYNOMIAL_HPP
#define TOOLS_POLYNOMIAL_HPP

#include <vector>
#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <utility>
#include <cassert>
#include <iterator>
#include "tools/fps.hpp"
#include "tools/has_mod.hpp"

namespace tools {
  template <typename F>
  class polynomial {
  private:
    using P = ::tools::polynomial<F>;
    ::std::vector<F> m_vector;

  public:
    using reference = F&;
    using const_reference = const F&;
    using iterator = typename ::std::vector<F>::iterator;
    using const_iterator = typename ::std::vector<F>::const_iterator;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using value_type = F;
    using allocator_type = typename ::std::vector<F>::allocator_type;
    using pointer = F*;
    using const_pointer = const F*;
    using reverse_iterator = typename ::std::vector<F>::reverse_iterator;
    using const_reverse_iterator = typename ::std::vector<F>::const_reverse_iterator;

    polynomial() = default;
    polynomial(const P&) = default;
    polynomial(P&&) = default;
    ~polynomial() = default;
    P& operator=(const P&) = default;
    P& operator=(P&&) = default;

    explicit polynomial(const size_type n) : m_vector(n) {}
    polynomial(const size_type n, const_reference value) : m_vector(n, value) {}
    template <class InputIter> polynomial(const InputIter first, const InputIter last) : m_vector(first, last) {}
    polynomial(const ::std::initializer_list<F> il) : m_vector(il) {}
    polynomial(const ::std::initializer_list<int> il) {
      this->m_vector.reserve(il.size());
      for (const auto x : il) {
        this->m_vector.emplace_back(x);
      }
    }

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
    void resize(const size_type sz, const F& c) { this->m_vector.resize(sz, c); }
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
    void assign(const size_type n, const F& u) { this->m_vector.assign(n, u); }
    void assign(const ::std::initializer_list<F> il) { this->m_vector.assign(il); }
    void assign(const ::std::initializer_list<int> il) {
      this->m_vector.reserve(il.size());
      for (size_type i = 0; i < ::std::min(this->m_vector.size(), il.size()); ++i) {
        this->m_vector[i] = F(il.begin()[i]);
      }
      for (size_type i = this->m_vector.size(); i < il.size(); ++i) {
        this->m_vector.emplace_back(il.begin()[i]);
      }
      this->m_vector.resize(il.size());
    }
    void push_back(const F& x) { this->m_vector.push_back(x); }
    void push_back(F&& x) { this->m_vector.push_back(::std::forward<F>(x)); }
    template <class... Args> reference emplace_back(Args&&... args) { return this->m_vector.emplace_back(::std::forward<Args>(args)...); }
    void pop_back() { this->m_vector.pop_back(); }
    iterator insert(const const_iterator position, const F& x) { return this->m_vector.insert(position, x); }
    iterator insert(const const_iterator position, F&& x) { return this->m_vector.insert(position, ::std::forward<F>(x)); }
    iterator insert(const const_iterator position, const size_type n, const F& x) { return this->m_vector.insert(position, n, x); }
    template <class InputIterator> iterator insert(const const_iterator position, const InputIterator first, const InputIterator last) { return this->m_vector.insert(position, first, last); }
    iterator insert(const const_iterator position, const ::std::initializer_list<F> il) { return this->m_vector.insert(position, il); }
    iterator insert(const const_iterator position, const ::std::initializer_list<int> il) {
      const size_type p = position - this->m_vector.begin();
      const size_type n = this->m_vector.size();
      const size_type m = il.size();
      this->m_vector.reserve(n + m);
      if (n - p >= m) {
        for (size_type i = n - m; i < n; ++i) {
          this->m_vector.push_back(::std::move(this->m_vector[i]));
        }
        ::std::move_backward(this->m_vector.begin() + p, this->m_vector.begin() + (n - m), this->m_vector.begin() + n);
        for (size_type i = 0; i < m; ++i) {
          this->m_vector[p + i] = F(il.begin()[i]);
        }
      } else {
        for (size_type i = n - p; i < m; ++i) {
          this->m_vector.emplace_back(il.begin()[i]);
        }
        for (size_type i = p; i < n; ++i) {
          this->m_vector.push_back(::std::move(this->m_vector[i]));
        }
        for (size_type i = 0; i < n - p; ++i) {
          this->m_vector[p + i] = F(il.begin()[i]);
        }
      }
      return this->m_vector.begin() + p;
    }
    template <class... Args> iterator emplace(const const_iterator position, Args&&... args) { return this->m_vector.emplace(position, ::std::forward<Args>(args)...); }
    iterator erase(const const_iterator position) { return this->m_vector.erase(position); }
    iterator erase(const const_iterator first, const const_iterator last) { return this->m_vector.erase(first, last); }
    void swap(P& x) noexcept { this->m_vector.swap(x.m_vector); }
    void clear() { this->m_vector.clear(); }

    allocator_type get_allocator() const noexcept { return this->m_vector.get_allocator(); }

    friend bool operator==(const P& x, const P& y) {
      const auto n = ::std::min(x.size(), y.size());
      static const auto is_zero = [](const F& e) { return e == F(0); };
      return ::std::equal(x.begin(), x.begin() + n, y.begin(), y.begin() + n) && ::std::all_of(x.begin() + n, x.end(), is_zero) && ::std::all_of(y.begin() + n, y.end(), is_zero);
    }
    friend bool operator!=(const P& x, const P& y) { return !(x == y); }

    friend void swap(P& x, P& y) noexcept { x.m_vector.swap(y.m_vector); }

    P& regularize() {
      while (!this->empty() && this->back() == F(0)) {
        this->pop_back();
      }
      return *this;
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
    P& operator*=(const F& g) {
      for (auto& e : *this) {
        e *= g;
      }
      return *this;
    }
    P& operator/=(const F& g) {
      assert(g != F(0));
      *this *= F(1) / g;
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
      const int n = this->size();
      this->erase(this->begin(), this->begin() + ::std::min(n, d));
      return *this;
    }
    P& operator>>=(const int d) {
      const int n = this->size();
      this->insert(this->begin(), d, F(0));
      return *this;
    }

    P& operator*=(const P& g) {
      if constexpr (::tools::has_mod_v<F>) {
        P res;
        ::tools::convolution(this->cbegin(), this->cend(), g.cbegin(), g.cend(), ::std::back_inserter(res));
        return *this = ::std::move(res);
      } else {
        const int n = this->size();
        const int m = g.size();
        if (n == 0 && m == 0) {
          this->clear();
          return *this;
        }

        P res(n + m - 1, F(0));
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            res[i + j] += (*this)[i] * g[j];
          }
        }
        return *this = ::std::move(res);
      }
    }
    P& operator/=(P g) {
      this->regularize();
      g.regularize();
      const int n = this->size();
      const int m = g.size();

      assert(m > 0);
      if (n < m) {
        this->clear();
        return *this;
      }

      if constexpr (::tools::has_mod_v<F>) {
        ::tools::fps<F> q(this->rbegin(), this->rend());
        q.divide_inplace(::tools::fps<F>(g.rbegin(), g.rend()), n - m + 1);
        this->assign(q.rbegin(), q.rend());
        return *this;
      } else {
        const auto ic = F(1) / g.back();
        P q(n - m + 1);
        for (int i = n - m; i >= 0; --i) {
          q[i] = (*this)[m - 1 + i] * ic;
          for (int j = 0; j < m; ++j) {
            (*this)[j + i] -= g[j] * q[i];
          }
        }
        return *this = ::std::move(q);
      }
    }
    P& operator%=(const P& g) {
      auto q = (*this) / g;
      q *= g;
      q *= F(-1);
      *this += q;
      return this->regularize();
    }

    F eval(const F& a) const {
      F x(1);
      F res(0);
      for (const auto e : *this) {
        res += e * x;
        x *= a;
      }
      return res;
    }

    friend P operator*(const P& f, const F& g) { return P(f) *= g; }
    friend P operator*(const F& f, const P& g) { return P(g) *= f; }
    friend P operator/(const P& f, const F& g) { return P(f) /= g; }
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
