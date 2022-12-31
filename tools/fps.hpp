#ifndef TOOLS_FPS_HPP
#define TOOLS_FPS_HPP

#include <vector>
#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <utility>
#include <cassert>
#include <iterator>
#include <type_traits>
#include "atcoder/convolution.hpp"
#include "tools/convolution.hpp"
#include "tools/pow2.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/less_by_first.hpp"

// Source: https://opt-cp.com/fps-implementation/
// License: CC0
// Author: opt

namespace tools {
  template <typename M>
  class fps {
  private:
    using F = ::tools::fps<M>;
    ::std::vector<M> m_vector;

    // maximum 2^k s.t. x = 1 (mod 2^k)
    static constexpr int pow2_k(const unsigned int x) {
      return (x - 1) & -(x - 1);
    }

    // d <= lpf(M)
    static bool is_leq_lpf_of_M(const int d) {
      if (M::mod() == 1) return true;
      for (int i = 2; i < d; ++i) {
        if (M::mod() % i == 0) return false;
      }
      return true;
    }

  public:
    using reference = M&;
    using const_reference = const M&;
    using iterator = typename ::std::vector<M>::iterator;
    using const_iterator = typename ::std::vector<M>::const_iterator;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using value_type = M;
    using allocator_type = typename ::std::vector<M>::allocator_type;
    using pointer = M*;
    using const_pointer = const M*;
    using reverse_iterator = typename ::std::vector<M>::reverse_iterator;
    using const_reverse_iterator = typename ::std::vector<M>::const_reverse_iterator;

    fps() = default;
    fps(const F&) = default;
    fps(F&&) = default;
    ~fps() = default;
    F& operator=(const F&) = default;
    F& operator=(F&&) = default;

    explicit fps(const size_type n) : m_vector(n) {}
    fps(const size_type n, const_reference value) : m_vector(n, value) {}
    template <class InputIter> fps(const InputIter first, const InputIter last) : m_vector(first, last) {}
    fps(const ::std::initializer_list<M> il) : m_vector(il) {}

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
    void resize(const size_type sz, const M& c) { this->m_vector.resize(sz, c); }
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
    void assign(const size_type n, const M& u) { this->m_vector.assign(n, u); }
    void assign(const ::std::initializer_list<M> il) { this->m_vector.assign(il); }
    void push_back(const M& x) { this->m_vector.push_back(x); }
    void push_back(M&& x) { this->m_vector.push_back(::std::forward<M>(x)); }
    template <class... Args> reference emplace_back(Args&&... args) { return this->m_vector.emplace_back(::std::forward<Args>(args)...); }
    void pop_back() { this->m_vector.pop_back(); }
    iterator insert(const const_iterator position, const M& x) { return this->m_vector.insert(position, x); }
    iterator insert(const const_iterator position, M&& x) { return this->m_vector.insert(position, ::std::forward<M>(x)); }
    iterator insert(const const_iterator position, const size_type n, const M& x) { return this->m_vector.insert(position, n, x); }
    template <class InputIterator> iterator insert(const const_iterator position, const InputIterator first, const InputIterator last) { return this->m_vector.insert(position, first, last); }
    iterator insert(const const_iterator position, const ::std::initializer_list<M> il) { return this->m_vector.insert(position, il); }
    template <class... Args> iterator emplace(const const_iterator position, Args&&... args) { return this->m_vector.emplace(position, ::std::forward<Args>(args)...); }
    iterator erase(const const_iterator position) { return this->m_vector.erase(position); }
    iterator erase(const const_iterator first, const const_iterator last) { return this->m_vector.erase(first, last); }
    void swap(F& x) noexcept { this->m_vector.swap(x.m_vector); }
    void clear() { this->m_vector.clear(); }

    allocator_type get_allocator() const noexcept { return this->m_vector.get_allocator(); }

    friend bool operator==(const F& x, const F& y) { return x.m_vector == y.m_vector; }
    friend bool operator!=(const F& x, const F& y) { return x.m_vector != y.m_vector; }

    friend void swap(F& x, F& y) noexcept { x.m_vector.swap(y.m_vector); }

    F operator+() const {
      return *this;
    }
    F operator-() const {
      F res(*this);
      for (auto& e : res) {
        e = -e;
      }
      return res;
    }
    F& operator*=(const M& g) {
      for (auto& e : *this) {
        e *= g;
      }
      return *this;
    }
    F& operator/=(const M& g) {
      assert(::std::gcd(g.val(), M::mod()) == 1);
      *this *= g.inv();
      return *this;
    }
    F& operator+=(const F& g) {
      const int n = this->size();
      const int m = g.size();
      for (int i = 0; i < ::std::min(n, m); ++i) {
        (*this)[i] += g[i];
      }
      return *this;
    }
    F& operator-=(const F& g) {
      const int n = this->size();
      const int m = g.size();
      for (int i = 0; i < ::std::min(n, m); ++i) {
        (*this)[i] -= g[i];
      }
      return *this;
    }
    F& operator<<=(const int d) {
      if (d < 0) *this >>= -d;

      const int n = this->size();
      this->erase(this->begin(), this->begin() + ::std::min(n, d));
      this->resize(n);
      return *this;
    }
    F& operator>>=(const int d) {
      if (d < 0) *this <<= -d;

      const int n = this->size();
      this->resize(::std::max(0, n - d));
      this->insert(this->begin(), ::std::min(n, d), M::raw(0));
      return *this;
    }
    F& multiply_inplace(const F& g, const int d) {
      assert(d >= 0);
      const int n = this->size();
      F res;
      ::tools::convolution(this->cbegin(), this->cbegin() + ::std::min(d, n), g.cbegin(), g.cbegin() + ::std::min<int>(d, g.size()), ::std::back_inserter(res));
      res.resize(d);
      *this = ::std::move(res);
      return *this;
    }
    F& multiply_inplace(const F& g) { return this->multiply_inplace(g, this->size()); }
    F& operator*=(const F& g) { return this->multiply_inplace(g); }
    F multiply(const F& g, const int d) const { return F(*this).multiply_inplace(g, d); }
    F multiply(const F& g) const { return this->multiply(g, this->size()); }

  private:
    F inv_regular(const int d) const {
      assert(d > 0);
      assert(M::mod() > 1);
      assert(!this->empty());
      assert(::std::gcd((*this)[0].val(), M::mod()) == 1);

      const int n = this->size();
      F res{(*this)[0].inv()};
      for (int m = 1; m < d; m *= 2) {
        F f(this->begin(), this->begin() + ::std::min(n, 2 * m));
        f *= -1;
        F r(res);
        r.multiply_inplace(r, 2 * m);
        r.multiply_inplace(f);
        r += res;
        r += res;
        res = ::std::move(r);
      }
      res.resize(d);
      return res;
    }
    template <typename M_ = M>
    F inv_faster(const int d) const {
      static_assert(::atcoder::internal::is_static_modint<M>::value);
      static_assert(2 <= M::mod() && M::mod() <= 2000000000);
      static_assert(::tools::is_prime(M::mod()));
      assert(d > 0);
      assert(!this->empty());
      assert(::tools::pow2(::tools::ceil_log2(d)) <= pow2_k(M::mod()));
      assert(::std::gcd((*this)[0].val(), M::mod()) == 1);

      const int n = this->size();
      F res{(*this)[0].inv()};
      for (int m = 1; m < d; m *= 2) {
        F f(this->begin(), this->begin() + ::std::min(n, 2 * m));
        F r(res);
        f.resize(2 * m);
        ::atcoder::internal::butterfly(f.m_vector);
        r.resize(2 * m);
        ::atcoder::internal::butterfly(r.m_vector);
        for (int i = 0; i < 2 * m; ++i) {
          f[i] *= r[i];
        }
        ::atcoder::internal::butterfly_inv(f.m_vector);
        f.erase(f.begin(), f.begin() + m);
        f.resize(2 * m);
        ::atcoder::internal::butterfly(f.m_vector);
        for (int i = 0; i < 2 * m; ++i) {
          f[i] *= r[i];
        }
        ::atcoder::internal::butterfly_inv(f.m_vector);
        M iz = M(2 * m).inv();
        iz *= -iz;
        for (int i = 0; i < m; ++i) {
          f[i] *= iz;
        }
        res.insert(res.end(), f.begin(), f.begin() + m);
      }
      res.resize(d);
      return res;
    }

  public:
    F inv(const int d) const {
      assert(d >= 0);
      if (d == 0) return F();
      if (M::mod() == 1) return F(d);
      assert(!this->empty());
      assert(::std::gcd((*this)[0].val(), M::mod()) == 1);

      if constexpr (::atcoder::internal::is_static_modint<M>::value && M::mod() <= 2000000000 && ::tools::is_prime(M::mod())) {
        if (::tools::pow2(::tools::ceil_log2(d)) <= pow2_k(M::mod())) {
          return this->inv_faster(d);
        } else {
          return this->inv_regular(d);
        }
      } else {
        return this->inv_regular(d);
      }
    }
    F inv() const { return this->inv(this->size()); }

    F& divide_inplace(const F& g, const int d) {
      assert(d >= 0);
      const int n = this->size();
      const auto g_inv = g.inv(d);
      F res;
      ::tools::convolution(this->cbegin(), this->cbegin() + ::std::min(d, n), g_inv.cbegin(), g_inv.cend(), ::std::back_inserter(res));
      res.resize(d);
      *this = ::std::move(res);
      return *this;
    }
    F& divide_inplace(const F& g) { return this->divide_inplace(g, this->size()); }
    F& operator/=(const F& g) { return this->divide_inplace(g); }
    F divide(const F& g, const int d) const { return F(*this).divide_inplace(g, d); }
    F divide(const F& g) const { return this->divide(g, this->size()); }

    // sparse
    template <class InputIterator>
    F& multiply_inplace(InputIterator g_begin, const InputIterator g_end) {
      assert(::std::is_sorted(g_begin, g_end, ::tools::less_by_first()));

      const int n = this->size();
      if (g_begin == g_end) {
        ::std::fill(this->begin(), this->end(), M::raw(0));
        return *this;
      }

      const auto [d, c] = *g_begin;
      if (d == 0) {
        ++g_begin;
      } else {
        c = M::raw(0);
      }
      for (int i = n - 1; i >= 0; --i) {
        (*this)[i] *= c;
        for (auto it = g_begin; it != g_end; ++it) {
          const auto& [j, b] = *it;
          if (j > i) break;
          (*this)[i] += (*this)[i - j] * b;
        }
      }
      return *this;
    }
    F& multiply_inplace(const ::std::initializer_list<::std::pair<int, M>> il) { return this->multiply_inplace(il.begin(), il.end()); }
    template <class InputIterator>
    F multiply(const InputIterator g_begin, const InputIterator g_end) const { return F(*this).multiply_inplace(g_begin, g_end); }
    F multiply(const ::std::initializer_list<::std::pair<int, M>> il) const { return this->multiply(il.begin(), il.end()); }

    template <class InputIterator>
    F& divide_inplace(InputIterator g_begin, const InputIterator g_end) {
      assert(g_begin != g_end);
      assert(::std::is_sorted(g_begin, g_end, ::tools::less_by_first()));

      const int n = this->size();
      if (n == 0) return *this;
      if (M::mod() == 1) return *this;

      const auto [d, c] = *g_begin;
      assert(d == 0 && ::std::gcd(c, M::mod()) == 1);
      const M ic = c.inv();
      ++g_begin;
      for (int i = 0; i < n; ++i) {
        for (auto it = g_begin; it != g_end; ++it) {
          const auto& [j, b] = *it;
          if (j > i) break;
          (*this)[i] -= (*this)[i - j] * b;
        }
        (*this)[i] *= ic;
      }
      return *this;
    }
    F& divide_inplace(const ::std::initializer_list<::std::pair<int, M>> il) { return this->divide_inplace(il.begin(), il.end()); }
    template <class InputIterator>
    F divide(const InputIterator g_begin, const InputIterator g_end) const { return F(*this).divide_inplace(g_begin, g_end); }
    F divide(const ::std::initializer_list<::std::pair<int, M>> il) const { return this->divide(il.begin(), il.end()); }

    // multiply and divide (1 + cz^d)
    F& multiply_inplace(const int d, const M c) {
      assert(d > 0);
      const int n = this->size();
      if (c == M(1)) {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] += (*this)[i];
        }
      } else if (c == M(-1)) {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] -= (*this)[i];
        }
      } else {
        for (int i = n - d - 1; i >= 0; --i) {
          (*this)[i + d] += (*this)[i] * c;
        }
      }
      return *this;
    }
    F multiply(const int d, const M c) const { return F(*this).multiply_inplace(d, c); }
    F& divide_inplace(const int d, const M c) {
      assert(d > 0);
      const int n = this->size();
      if (c == M(1)) {
        for (int i = 0; i < n - d; ++i) {
          (*this)[i + d] -= (*this)[i];
        }
      } else if (c == M(-1)) {
        for (int i = 0; i < n - d; ++i) {
          (*this)[i + d] += (*this)[i];
        }
      } else {
        for (int i = 0; i < n - d; ++i) {
          (*this)[i + d] -= (*this)[i] * c;
        }
      }
      return *this;
    }
    F divide(const int d, const M c) const { return F(*this).divide_inplace(d, c); }

    F& integral_inplace() {
      const int n = this->size();
      assert(is_leq_lpf_of_M(n));

      if (n == 0) return *this;
      if (n == 1) return *this = F{0};
      this->insert(this->begin(), 0);
      this->pop_back();
      ::std::vector<M> inv(n);
      inv[1] = M(1);
      int p = M::mod();
      for (int i = 2; i < n; ++i) {
        inv[i] = -inv[p % i] * (p / i);
      }
      for (int i = 2; i < n; ++i) {
        (*this)[i] *= inv[i];
      }
      return *this;
    }
    F integral() const { return F(*this).integral_inplace(); }

    F& derivative_inplace() {
      const int n = this->size();
      if (n == 0) return *this;
      for (int i = 2; i < n; ++i) {
        (*this)[i] *= i;
      }
      this->erase(this->begin());
      this->push_back(0);
      return *this;
    }
    F derivative() const { return F(*this).derivative_inplace(); }

    F& log_inplace(const int d) {
      assert(d >= 0);
      assert(is_leq_lpf_of_M(d));
      this->resize(d);
      if (d == 0) return *this;
      assert((*this)[0] == M(1));

      const F f_inv = this->inv();
      this->derivative_inplace();
      this->multiply_inplace(f_inv);
      this->integral_inplace();
      return *this;
    }
    F& log_inplace() { return this->log_inplace(this->size()); }
    F log(const int d) const { return F(*this).log_inplace(d); }
    F log() const { return this->log(this->size()); }

  private:
    F& exp_inplace_regular(const int d) {
      assert(d >= 0);
      assert(is_leq_lpf_of_M(d));
      assert(this->empty() || (*this)[0] == M::raw(0));

      const int n = this->size();
      F g{1};
      for (int m = 1; m < d; m *= 2) {
        F r(g);
        r.resize(2 * m);
        r.log_inplace();
        r *= -1;
        r += F(this->begin(), this->begin() + ::std::min(n, 2 * m));
        ++r[0];
        r.multiply_inplace(g);
        g = ::std::move(r);
      }
      g.resize(d);
      *this = ::std::move(g);
      return *this;
    }
    template <typename M_ = M>
    F& exp_inplace_faster(const int d) {
      static_assert(::atcoder::internal::is_static_modint<M>::value);
      static_assert(2 <= M::mod() && M::mod() <= 2000000000);
      static_assert(::tools::is_prime(M::mod()));
      assert(d > 0);
      assert(is_leq_lpf_of_M(d));
      assert(::tools::pow2(::tools::ceil_log2(d)) <= pow2_k(M::mod()));
      assert(this->empty() || (*this)[0] == M::raw(0));
 
      F g{1}, g_fft{1, 1};
      this->resize(d);
      (*this)[0] = 1;
      F h_drv(this->derivative());
      for (int m = 2; m < d; m *= 2) {
        // prepare
        F f_fft(this->begin(), this->begin() + m);
        f_fft.resize(2 * m);
        ::atcoder::internal::butterfly(f_fft.m_vector);

        // Step 2.a'
        {
          F g_(m);
          for (int i = 0; i < m; ++i) {
            g_[i] = f_fft[i] * g_fft[i];
          }
          ::atcoder::internal::butterfly_inv(g_.m_vector);
          g_.erase(g_.begin(), g_.begin() + m / 2);
          g_.resize(m);
          ::atcoder::internal::butterfly(g_.m_vector);
          for (int i = 0; i < m; ++i) {
            g_[i] *= g_fft[i];
          }
          ::atcoder::internal::butterfly_inv(g_.m_vector);
          g_.resize(m / 2);
          g_ /= M(-m) * m;
          g.insert(g.end(), g_.begin(), g_.begin() + m / 2);
        }

        // Step 2.b'--d'
        F t(this->begin(), this->begin() + m);
        t.derivative_inplace();
        {
          // Step 2.b'
          F r{h_drv.begin(), h_drv.begin() + m - 1};
          // Step 2.c'
          r.resize(m);
          ::atcoder::internal::butterfly(r.m_vector);
          for (int i = 0; i < m; ++i) {
            r[i] *= f_fft[i];
          }
          ::atcoder::internal::butterfly_inv(r.m_vector);
          r /= -m;
          // Step 2.d'
          t += r;
          t.insert(t.begin(), t.back());
          t.pop_back();
        }

        // Step 2.e'
        if (2 * m < d) {
          t.resize(2 * m);
          ::atcoder::internal::butterfly(t.m_vector);
          g_fft = g;
          g_fft.resize(2*m);
          ::atcoder::internal::butterfly(g_fft.m_vector);
          for (int i = 0; i < 2 * m; ++i) {
            t[i] *= g_fft[i];
          }
          ::atcoder::internal::butterfly_inv(t.m_vector);
          t.resize(m);
          t /= 2 * m;
        } else { // この場合分けをしても数パーセントしか速くならない
          F g1(g.begin() + m / 2, g.end());
          F s1(t.begin() + m / 2, t.end());
          t.resize(m/2);
          g1.resize(m);
          ::atcoder::internal::butterfly(g1.m_vector);
          t.resize(m);
          ::atcoder::internal::butterfly(t.m_vector);
          s1.resize(m);
          ::atcoder::internal::butterfly(s1.m_vector);
          for (int i = 0; i < m; ++i) {
            s1[i] = g_fft[i] * s1[i] + g1[i] * t[i];
          }
          for (int i = 0; i < m; ++i) {
            t[i] *= g_fft[i];
          }
          ::atcoder::internal::butterfly_inv(t.m_vector);
          ::atcoder::internal::butterfly_inv(s1.m_vector);
          for (int i = 0; i < m / 2; ++i) {
            t[i + m / 2] += s1[i];
          }
          t /= m;
        }

        // Step 2.f'
        F v(this->begin() + m, this->begin() + ::std::min<int>(d, 2 * m));
        v.resize(m);
        t.insert(t.begin(), m - 1, 0);
        t.push_back(0);
        t.integral_inplace();
        for (int i = 0; i < m; ++i) {
          v[i] -= t[m + i];
        }

        // Step 2.g'
        v.resize(2 * m);
        ::atcoder::internal::butterfly(v.m_vector);
        for (int i = 0; i < 2 * m; ++i) {
          v[i] *= f_fft[i];
        }
        ::atcoder::internal::butterfly_inv(v.m_vector);
        v.resize(m);
        v /= 2 * m;

        // Step 2.h'
        for (int i = 0; i < ::std::min(d - m, m); ++i) {
          (*this)[m + i] = v[i];
        }
      }
      return *this;
    }

  public:
    F& exp_inplace(const int d) {
      assert(d >= 0);
      assert(is_leq_lpf_of_M(d));
      assert(this->empty() || (*this)[0] == M::raw(0));

      if (d == 0) {
        this->clear();
        return *this;
      }

      if constexpr (::atcoder::internal::is_static_modint<M>::value && M::mod() <= 2000000000 && ::tools::is_prime(M::mod())) {
        if (::tools::pow2(::tools::ceil_log2(d)) <= pow2_k(M::mod())) {
          return this->exp_inplace_faster(d);
        } else {
          return this->exp_inplace_regular(d);
        }
      } else {
        return this->exp_inplace_regular(d);
      }
    }
    F& exp_inplace() { return this->exp_inplace(this->size()); }
    F exp(const int d) const { return F(*this).exp_inplace(d); }
    F exp() const { return this->exp(this->size()); }

  private:
    F& pow_inplace_regular(long long k, const int d, const int l) {
      assert(k > 0);
      assert(d > 0);
      assert(l >= 0);
      assert(d - l * k > 0);

      this->erase(this->begin(), this->begin() + l);
      this->resize(d - l * k);

      F sum(d - l * k);
      for (F p = *this; k > 0; k /= 2, p *= p) {
        if (k & 1) sum += p;
      }

      *this = ::std::move(sum);
      this->insert(this->begin(), l * k, 0);
      return *this;
    }
    F& pow_inplace_faster(const long long k, const int d, const int l) {
      assert(k > 0);
      assert(d > 0);
      assert(l >= 0);
      assert(d - l * k > 0);
      assert(is_leq_lpf_of_M(d - l * k));
      assert(::std::gcd((*this)[l].val(), M::mod()) == 1);

      M c{(*this)[l]};
      this->erase(this->begin(), this->begin() + l);
      *this /= c;
      this->log_inplace(d - l * k);
      *this *= k;
      this->exp_inplace();
      *this *= c.pow(k);
      this->insert(this->begin(), l * k, 0);
      return *this;
    }

  public:
    F& pow_inplace(const long long k, const int d) {
      assert(k >= 0);
      assert(d >= 0);

      const int n = this->size();
      if (d == 0) {
        this->clear();
        return *this;
      }
      if (k == 0) {
        *this = F(d);
        (*this)[0] = M(1);
        return *this;
      }

      int l = 0;
      while (l < n && (*this)[l] == M::raw(0)) ++l;
      if (l == n || l > (d - 1) / k) {
        return *this = F(d);
      }

      if (::std::gcd((*this)[l].val(), M::mod()) == 1 && is_leq_lpf_of_M(d - l * k)) {
        return this->pow_inplace_faster(k, d, l);
      } else {
        return this->pow_inplace_regular(k, d, l);
      }
    }
    F& pow_inplace(const long long k) { return this->pow_inplace(k, this->size()); }
    F pow(const long long k, const int d) const { return F(*this).pow_inplace(k, d); }
    F pow(const long long k) const { return this->pow(k, this->size()); }

    friend F operator*(const F& f, const M& g) { return F(f) *= g; }
    friend F operator*(const M& f, const F& g) { return F(g) *= f; }
    friend F operator/(const F& f, const M& g) { return F(f) /= g; }
    friend F operator+(const F& f, const F& g) { return F(f) += g; }
    friend F operator-(const F& f, const F& g) { return F(f) -= g; }
    friend F operator*(const F& f, const F& g) { return F(f) *= g; }
    friend F operator/(const F& f, const F& g) { return F(f) /= g; }
    friend F operator<<(const F& f, const int d) { return F(f) <<= d; }
    friend F operator>>(const F& f, const int d) { return F(f) >>= d; }
  };
}

#endif
