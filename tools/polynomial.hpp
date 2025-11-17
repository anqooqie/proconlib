#ifndef TOOLS_POLYNOMIAL_HPP
#define TOOLS_POLYNOMIAL_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <concepts>
#include <initializer_list>
#include <iterator>
#include <numeric>
#include <type_traits>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/ceil_log2.hpp"
#include "tools/complex.hpp"
#include "tools/fact_mod_cache.hpp"
#include "tools/groups.hpp"
#include "tools/fps.hpp"
#include "tools/integral.hpp"
#include "tools/is_prime.hpp"
#include "tools/modint_compatible.hpp"
#include "tools/monoids.hpp"
#include "tools/pow2.hpp"
#include "tools/pow_mod_cache.hpp"
#include "tools/ring.hpp"
#include "tools/rings.hpp"

namespace tools {
  namespace detail {
    namespace polynomial {
      template <typename T>
      concept can_divide = requires(T a, T b) {
        { a / b } -> ::std::same_as<T>;
      };

      template <typename T>
      concept prime_modint = ::atcoder::internal::is_static_modint<T>::value && ::tools::is_prime(T::mod());
    }
  }

  template <typename X>
  class polynomial {
    using R = ::std::conditional_t<
      ::tools::ring<X>,
        X,
        ::tools::rings::of<
          ::tools::groups::plus<X>,
          ::std::conditional_t<
            ::tools::complex<X> || ::std::floating_point<X> || ::tools::detail::polynomial::prime_modint<X> || ::atcoder::internal::is_dynamic_modint<X>::value,
              ::tools::groups::multiplies<X>,
              ::std::conditional_t<
                ::tools::integral<X> || ::atcoder::internal::is_static_modint<X>::value,
                  ::tools::monoids::multiplies<X>,
                  ::std::conditional_t<
                    ::tools::detail::polynomial::can_divide<X>,
                      ::tools::groups::multiplies<X>,
                      ::tools::monoids::multiplies<X>
                  >
              >
          >
        >
    >;
    using Add = typename R::add;
    using Mul = typename R::mul;
    using T = typename Add::T;
    using P = ::tools::polynomial<X>;

    static constexpr bool IS_MOD_P = ::tools::detail::polynomial::prime_modint<T>
      && ::std::same_as<Add, ::tools::groups::plus<T>>
      && (::std::same_as<Mul, ::tools::monoids::multiplies<T>> || ::std::same_as<Mul, ::tools::groups::multiplies<T>>);
    static constexpr bool IS_MOD_M = ::tools::modint_compatible<T>
      && ::std::same_as<Add, ::tools::groups::plus<T>>
      && (::std::same_as<Mul, ::tools::monoids::multiplies<T>> || ::std::same_as<Mul, ::tools::groups::multiplies<T>>);
    ::std::vector<T> m_vector;

  public:
    using reference = T&;
    using const_reference = const T&;
    using iterator = typename ::std::vector<T>::iterator;
    using const_iterator = typename ::std::vector<T>::const_iterator;
    using size_type = ::std::size_t;
    using difference_type = ::std::ptrdiff_t;
    using value_type = T;
    using allocator_type = typename ::std::vector<T>::allocator_type;
    using pointer = T*;
    using const_pointer = const T*;
    using reverse_iterator = typename ::std::vector<T>::reverse_iterator;
    using const_reverse_iterator = typename ::std::vector<T>::const_reverse_iterator;

    polynomial() = default;
    explicit polynomial(const size_type n) : m_vector(n) {}
    polynomial(const size_type n, const_reference value) : m_vector(n, value) {}
    template <class InputIter> polynomial(const InputIter first, const InputIter last) : m_vector(first, last) {}
    polynomial(const ::std::initializer_list<T> il) : m_vector(il) {}

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
    void resize(const size_type sz, const T& c) { this->m_vector.resize(sz, c); }
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
    void assign(const size_type n, const T& u) { this->m_vector.assign(n, u); }
    void assign(const ::std::initializer_list<T> il) { this->m_vector.assign(il); }
    void push_back(const T& x) { this->m_vector.push_back(x); }
    void push_back(T&& x) { this->m_vector.push_back(::std::forward<T>(x)); }
    template <class... Args> reference emplace_back(Args&&... args) { return this->m_vector.emplace_back(::std::forward<Args>(args)...); }
    void pop_back() { this->m_vector.pop_back(); }
    iterator insert(const const_iterator position, const T& x) { return this->m_vector.insert(position, x); }
    iterator insert(const const_iterator position, T&& x) { return this->m_vector.insert(position, ::std::forward<T>(x)); }
    iterator insert(const const_iterator position, const size_type n, const T& x) { return this->m_vector.insert(position, n, x); }
    template <class InputIterator> iterator insert(const const_iterator position, const InputIterator first, const InputIterator last) { return this->m_vector.insert(position, first, last); }
    iterator insert(const const_iterator position, const ::std::initializer_list<T> il) { return this->m_vector.insert(position, il); }
    template <class... Args> iterator emplace(const const_iterator position, Args&&... args) { return this->m_vector.emplace(position, ::std::forward<Args>(args)...); }
    iterator erase(const const_iterator position) { return this->m_vector.erase(position); }
    iterator erase(const const_iterator first, const const_iterator last) { return this->m_vector.erase(first, last); }
    void swap(P& x) noexcept { this->m_vector.swap(x.m_vector); }
    void clear() { this->m_vector.clear(); }

    allocator_type get_allocator() const noexcept { return this->m_vector.get_allocator(); }

    friend bool operator==(const P& x, const P& y) {
      const auto n = ::std::min(x.size(), y.size());
      static const auto is_zero = [](const T& e) { return e == Add::e(); };
      return ::std::equal(x.begin(), x.begin() + n, y.begin(), y.begin() + n) && ::std::all_of(x.begin() + n, x.end(), is_zero) && ::std::all_of(y.begin() + n, y.end(), is_zero);
    }
    friend bool operator!=(const P& x, const P& y) { return !(x == y); }

    friend void swap(P& x, P& y) noexcept { x.m_vector.swap(y.m_vector); }

    class coefficient_iterator {
    private:
      const ::std::vector<T> *m_vector;
      ::std::size_t m_offset;

    public:
      using difference_type = ::std::ptrdiff_t;
      using value_type = T;
      using reference = const T&;
      using pointer = const T*;
      using iterator_category = ::std::random_access_iterator_tag;

      coefficient_iterator() = default;
      coefficient_iterator(const ::std::vector<T> * const vector, const ::std::size_t offset) :
        m_vector(vector),
        m_offset(offset) {
      }

      const T& operator*() const {
        static const T e = Add::e();
        return this->m_offset < this->m_vector->size() ? (*this->m_vector)[this->m_offset] : e;
      }
      const T* operator->() const {
        return &(*(*this));
      }

      coefficient_iterator& operator++() {
        ++this->m_offset;
        return *this;
      }
      coefficient_iterator operator++(int) {
        const auto self = *this;
        ++*this;
        return self;
      }
      coefficient_iterator& operator--() {
        --this->m_offset;
        return *this;
      }
      coefficient_iterator operator--(int) {
        const auto self = *this;
        --*this;
        return self;
      }
      coefficient_iterator& operator+=(const ::std::ptrdiff_t n) {
        this->m_offset += n;
        return *this;
      }
      coefficient_iterator& operator-=(const ::std::ptrdiff_t n) {
        this->m_offset -= n;
        return *this;
      }
      friend coefficient_iterator operator+(const coefficient_iterator& self, const ::std::ptrdiff_t n) {
        return coefficient_iterator(self.m_vector, self.m_offset + n);
      }
      friend coefficient_iterator operator+(const ::std::ptrdiff_t n, const coefficient_iterator& self) {
        return self + n;
      }
      friend coefficient_iterator operator-(const coefficient_iterator& self, const ::std::ptrdiff_t n) {
        return coefficient_iterator(self.m_vector, self.m_offset - n);
      }
      friend ::std::ptrdiff_t operator-(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return static_cast<::std::ptrdiff_t>(lhs.m_offset) - static_cast<::std::ptrdiff_t>(rhs.m_offset);
      }
      const T& operator[](const ::std::ptrdiff_t n) const {
        return *(*this + n);
      }

      friend bool operator==(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset == rhs.m_offset;
      }
      friend bool operator!=(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset != rhs.m_offset;
      }
      friend bool operator<(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset < rhs.m_offset;
      }
      friend bool operator<=(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset <= rhs.m_offset;
      }
      friend bool operator>(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset > rhs.m_offset;
      }
      friend bool operator>=(const coefficient_iterator& lhs, const coefficient_iterator& rhs) {
        assert(lhs.m_vector == rhs.m_vector);
        return lhs.m_offset >= rhs.m_offset;
      }
    };
    coefficient_iterator pbegin() const {
      return coefficient_iterator(&this->m_vector, 0);
    }

    int deg() const {
      for (size_type i = this->size(); i --> 0;) {
        if ((*this)[i] != Add::e()) return i;
      }
      return -1;
    }
    P& regularize() {
      this->resize(this->deg() + 1);
      return *this;
    }

    P operator+() const {
      return P(this->begin(), ::std::next(this->begin(), this->deg() + 1));
    }
    P operator-() const {
      P res;
      for (auto it = this->begin(), end = ::std::next(this->begin(), this->deg() + 1); it != end; ++it) {
        res.push_back(Add::inv(*it));
      }
      return res;
    }
    P& operator++() {
      if (this->empty()) {
        this->push_back(Mul::e());
      } else {
        (*this)[0] = Add::op((*this)[0], Mul::e());
      }
      return this->regularize();
    }
    P operator++(int) {
      const auto self = *this;
      ++*this;
      return self;
    }
    P& operator--() {
      if (this->empty()) {
        this->push_back(Add::inv(Mul::e()));
      } else {
        (*this)[0] = Add::op((*this)[0], Add::inv(Mul::e()));
      }
      return this->regularize();
    }
    P operator--(int) {
      const auto self = *this;
      --*this;
      return self;
    }
    P& operator*=(const T& g) {
      this->regularize();
      for (auto& e : *this) {
        e = Mul::op(e, g);
      }
      return this->regularize();
    }
    P& operator/=(const T& g) {
      assert(Add::e() == Mul::e() || g != Add::e());
      return *this *= Mul::inv(g);
    }
    P& operator+=(const P& g) {
      const int n = this->deg() + 1;
      const int m = g.deg() + 1;
      this->resize(::std::max(n, m), Add::e());
      for (int i = 0; i < m; ++i) {
        (*this)[i] = Add::op((*this)[i], g[i]);
      }
      return this->regularize();
    }
    P& operator-=(const P& g) {
      const int n = this->deg() + 1;
      const int m = g.deg() + 1;
      this->resize(::std::max(n, m), Add::e());
      for (int i = 0; i < m; ++i) {
        (*this)[i] = Add::op((*this)[i], Add::inv(g[i]));
      }
      return this->regularize();
    }
    P& operator<<=(const int d) {
      if (d < 0) *this >>= -d;

      this->regularize();
      if (!this->empty()) {
        this->insert(this->begin(), d, Add::e());
      }
      return *this;
    }
    P& operator>>=(const int d) {
      if (d < 0) *this <<= -d;

      this->regularize();
      const int n = this->size();
      this->erase(this->begin(), this->begin() + ::std::min(n, d));
      return *this;
    }

    P& operator*=(const P& g) {
      const int n = this->deg() + 1;
      const int m = g.deg() + 1;

      this->m_vector = ::tools::convolution<R>(*this, g);
      return this->regularize();
    }

  private:
    P& divide_inplace_naive(const const_iterator g_begin, const const_iterator g_end) {
      const int n = this->size();
      const int m = ::std::distance(g_begin, g_end);

      assert(0 < m && m <= n);
      assert(Add::e() != Mul::e());
      assert(this->back() != Add::e());
      assert(*::std::prev(g_end) != Add::e());

      const auto ic = Mul::inv(*::std::prev(g_end));
      P q(n - m + 1);
      for (int i = n - m; i >= 0; --i) {
        q[i] = Mul::op((*this)[m - 1 + i], ic);
        auto f_it = this->begin() + i;
        for (auto g_it = g_begin; g_it != g_end; ++g_it, ++f_it) {
          *f_it = Add::op(*f_it, Add::inv(Mul::op(*g_it, q[i])));
        }
      }
      return *this = ::std::move(q);
    }
    P& divide_inplace_faster(const const_iterator g_begin, const const_iterator g_end) {
      const int n = this->size();
      const int m = ::std::distance(g_begin, g_end);

      static_assert(IS_MOD_M);
      assert(0 < m && m <= n);
      assert(Add::e() != Mul::e());
      assert(this->back() != Add::e());
      assert(::std::gcd(::std::prev(g_end)->val(), T::mod()) == 1);

      ::tools::fps<T> q(this->rbegin(), ::std::next(this->rbegin(), n - m + 1));
      q.divide_inplace(::tools::fps<T>(::std::make_reverse_iterator(g_end), ::std::next(::std::make_reverse_iterator(g_end), ::std::min(m, n - m + 1))));
      this->assign(q.rbegin(), q.rend());
      return *this;
    }

  public:
    P& operator/=(const P& g) {
      if (Add::e() == Mul::e()) {
        this->clear();
        return *this;
      }

      this->regularize();

      const int n = this->size();
      const int m = g.deg() + 1;

      assert(m > 0);
      if (n < m) {
        this->clear();
        return *this;
      }

      if constexpr (IS_MOD_M) {
        assert(::std::gcd(g[m - 1].val(), T::mod()) == 1);
        return this->divide_inplace_faster(g.begin(), g.begin() + m);
      } else {
        return this->divide_inplace_naive(g.begin(), g.begin() + m);
      }
    }

  private:
    P& modulo_inplace_naive(const P& g) {
      auto q = (*this) / g;
      q *= g;
      q *= Add::inv(Mul::e());
      *this += q;
      return this->regularize();
    }
    P& modulo_inplace_faster(P g) {
      static_assert(IS_MOD_P);

      g.regularize();
      const auto n = this->size();
      const auto m = g.size();
      assert(m > 1);

      const auto z = ::tools::pow2(::tools::ceil_log2(m - 1));
      assert((T::mod() - 1) % z == 0);

      auto q = (*this) / g;
      for (::std::size_t i = z; i < q.size(); ++i) {
        q[i & (z - 1)] += q[i];
      }
      q.resize(z);
      ::atcoder::internal::butterfly(q.m_vector);

      if (z < m) {
        g[0] += g[m - 1];
      }
      g.resize(z);
      ::atcoder::internal::butterfly(g.m_vector);

      for (::std::size_t i = 0; i < z; ++i) {
        q[i] *= g[i];
      }

      ::atcoder::internal::butterfly_inv(q.m_vector);
      const auto iz = T(z).inv();

      q.resize(m - 1);
      for (::std::size_t i = 0; i < q.size(); ++i) {
        q[i] = -(q[i] * iz);
      }

      for (::std::size_t offset = 0; offset < n; offset += z) {
        for (::std::size_t i = offset; i < ::std::min(offset + m - 1, n); ++i) {
          q[i & (z - 1)] += (*this)[i];
        }
      }

      q.regularize();
      return *this = ::std::move(q);
    }

  public:
    P& operator%=(const P& g) {
      if (Add::e() == Mul::e()) {
        this->clear();
        return *this;
      }

      this->regularize();

      const auto n = this->size();
      const ::std::size_t m = g.deg() + 1;

      assert(m > 0);
      if (n < m) {
        return *this;
      }

      if (m == 1) {
        this->clear();
        return *this;
      }

      if constexpr (IS_MOD_P) {
        const auto lz = ::tools::ceil_log2(m - 1);
        const auto z = ::tools::pow2(lz);
        if (!((T::mod() - 1) & (z - 1)) && lz + m < n) {
          return this->modulo_inplace_faster(g);
        } else {
          return this->modulo_inplace_naive(g);
        }
      } else {
        return this->modulo_inplace_naive(g);
      }
    }

    P& derivative_inplace() {
      this->regularize();
      const int n = this->size();
      if (n == 0) return *this;
      for (int i = 2; i < n; ++i) {
        (*this)[i] *= i;
      }
      this->erase(this->begin());
      return this->regularize();
    }
    P derivative() const {
      return P(this->begin(), ::std::next(this->begin(), this->deg() + 1)).derivative_inplace();
    }

  private:
    P& taylor_shift(const T& c) {
      static_assert(IS_MOD_M);
      assert(::tools::is_prime(T::mod()));

      this->regularize();
      const int n = this->size();
      assert(n < T::mod());

      ::tools::fact_mod_cache<T> cache;
      ::tools::pow_mod_cache<T> pow_c(c);

      P a;
      a.reserve(n);
      for (int i = 0; i < n; ++i) {
        a.push_back((*this)[i] * cache.fact(i));
      }

      P b;
      b.reserve(n);
      for (int i = 0; i < n; ++i) {
        b.push_back(pow_c[n - 1 - i] * cache.fact_inv(n - 1 - i));
      }

      a *= b;

      this->clear();
      this->reserve(n);
      for (int i = 0; i < ::std::min(n, int(a.size()) - (n - 1)); ++i) {
        this->push_back(a[n - 1 + i] * cache.fact_inv(i));
      }
      return *this;
    }
    P& composition_ax_d(const T& a, const int d) {
      assert(d >= 0);

      this->regularize();
      if (this->empty()) return *this;

      if (a == Add::e()) {
        this->resize(1);
        return *this;
      }

      if (d == 0) {
        const auto f_a = (*this)(a);
        if (f_a == Add::e()) {
          this->clear();
        } else {
          this->resize(1);
          (*this)[0] = f_a;
        }
        return *this;
      }

      if (d == 1) {
        if (a == Mul::e()) return *this;

        auto a_i = Mul::e();
        for (auto it = this->begin(); it != this->end(); ++it) {
          *it = Mul::op(*it, a_i);
          a_i = Mul::op(a_i, a);
        }
        return this->regularize();
      }

      P res;
      res.reserve((this->size() - 1) * d + 1);
      auto a_i = Mul::e();
      res.push_back(this->front());
      for (auto it = ::std::next(this->begin()); it != this->end(); ++it) {
        for (int i = 1; i < d; ++i) {
          res.push_back(Add::e());
        }
        res.push_back(Mul::op(*it, a_i));
        a_i = Mul::op(a_i, a);
      }
      res.regularize();
      return *this = ::std::move(res);
    }

  public:
    T operator()(const T& a) const {
      auto x = Mul::e();
      auto res = Add::e();
      for (auto it = this->begin(), end = ::std::next(this->begin(), this->deg() + 1); it != end; ++it) {
        res = Add::op(res, Mul::op(*it, x));
        x = Mul::op(x, a);
      }
      return res;
    }
    P operator()(const P& g) const {
      const int n = this->deg() + 1;
      if (n == 0) return P{};
      const int m = g.deg() + 1;
      if (m == 0) return P{(*this)[0]};
      if (::std::all_of(g.begin(), ::std::next(g.begin(), m - 1), [](const auto& g_i) { return g_i == Add::e(); })) {
        return P(this->begin(), this->begin() + n).composition_ax_d(g.back(), m - 1);
      }

      const auto naive = [&]() {
        assert(n > 0);
        auto g_i = P{Mul::e()};
        auto res = g_i;
        for (int i = 1; i < n; ++i) {
          g_i *= g;
          res += g_i;
        }
        return res;
      };

      if constexpr (IS_MOD_M) {
        if (::tools::is_prime(T::mod()) && n < T::mod()) {
          if (m == 2) {
            return P(this->begin(), this->begin() + n).taylor_shift(g[0]).composition_ax_d(g[1], 1);
          } else if (m == 3) {
            return P(this->begin(), this->begin() + n).taylor_shift(g[0] - g[1] * g[1] / (T(4) * g[2])).composition_ax_d(g[2], 2).taylor_shift(g[1] / (T(2) * g[2]));
          }
        }
        return naive();
      } else {
        return naive();
      }
    }

  private:
    ::std::vector<T> multipoint_evaluation_naive(const ::std::vector<T>& p) const {
      ::std::vector<T> res;
      for (const auto& p_i : p) {
        res.push_back((*this)(p_i));
      }
      return res;
    }
    ::std::vector<T> multipoint_evaluation_faster(const ::std::vector<T>& p) const {
      const int M = p.size();
      assert(M > 0);

      const auto h = ::tools::ceil_log2(M);
      ::std::vector<P> prods(::tools::pow2(h) * 2);
      for (int i = 0; i < M; ++i) {
        prods[::tools::pow2(h) + i] = P{-p[i], T(1)};
      }
      for (int i = M; i < ::tools::pow2(h); ++i) {
        prods[::tools::pow2(h) + i] = P{T(1)};
      }
      for (int i = ::tools::pow2(h) - 1; i > 0; --i) {
        prods[i] = prods[i * 2] * prods[i * 2 + 1];
      }

      ::std::vector<P> mods(::tools::pow2(h) * 2);
      mods[1] = *this % prods[1];
      for (int i = 2; i < ::tools::pow2(h) + M; ++i) {
        mods[i] = mods[i / 2] % prods[i];
      }

      ::std::vector<T> res;
      res.reserve(M);
      for (int i = 0; i < M; ++i) {
        res.push_back(*mods[::tools::pow2(h) + i].pbegin());
      }
      return res;
    }

  public:
    template <typename InputIterator>
    ::std::vector<T> multipoint_evaluation(const InputIterator begin, const InputIterator end) const {
      ::std::vector<T> p(begin, end);
      if (p.empty()) return ::std::vector<T>{};

      if constexpr (IS_MOD_M) {
        return this->multipoint_evaluation_faster(p);
      } else {
        return this->multipoint_evaluation_naive(p);
      }
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
